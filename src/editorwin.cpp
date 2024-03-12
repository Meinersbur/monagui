/*
 * MonaGUI
 * Copyright 2011 Michael Kruse
 *
 * This file is part of MonaGUI.
 *
 * MonaGUI is free software: you can redistribute it and/or modify it under the
 * terms of the GNU General Public License as published by the Free Software
 * Foundation, version 2 of the license.
 *
 * MonaGUI is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * MonaGUI. If not, see http://www.gnu.org/licenses/.
 */
/**
The main editor window
*/

#include "editorwin.h"

#include "app.h"
#include "resultwin.h"
#include "progresswin.h"
#include "newdialog.h"
#include "aboutdialog.h"
#include "monacall.h"
#include "gtkutils.h"
#include "monacompletionprovider.h"
#include "errorviewcolumns.h"
#include "utils.h"

#include <gtksourceviewmm.h>

#include <boost/filesystem/fstream.hpp>
#include <boost/foreach.hpp>
#include <boost/lexical_cast.hpp>


class EditorWindowImpl : public EditorWindow {
public:
    EditorWindowImpl(BaseObjectType *cobject, const Glib::RefPtr<Gtk::Builder>& glade);
    virtual ~EditorWindowImpl();

private:
    void init_ui();
    void init_actions();
    void init_completion();
    void init_sourceview();
    void init_errorview();
    void init_dialogs();

    // Document handling
    void save();
    void user_createNew(bool treeMode, bool finite, bool tutorial);
    void resetSourceBuffer();
    void getTemplateDocument(bool treeMode, bool finite, bool tutorial, /*out*/ ustring &result);

    void insertTextAtCursor(const ustring &str);
    void insertAtPreviousDeclaration(const ustring &str);
    void insertCompletion(const Glib::RefPtr<CompletionItem >&item);
    void insertCompletion(const Glib::RefPtr<CompletionItem >&item, const Gtk::TextIter &position);

    // UI
    void UpdateTitle();
    void UpdateProgress();
    void linkCompletionAction(Glib::RefPtr<Gtk::Action> action, const CompletionItem *item);
    void linkCompletionAction(const char *actionName, const CompletionItem *item);
    Glib::RefPtr<Gtk::Action> connectAction(ustring actionName, void (EditorWindowImpl::*_A_func)());
    Glib::RefPtr<Gsv::SourceBuffer> sourceBuffer();

    // ErrorView
    void clearErrorMessages();
    void addError(ustring msg) ;
    void addError(ustring msg, int line, int column);
    void appendMonaStatusMessages();

    // Managing Instances of Mona
    MonaPtr getMonaCursor();
    MonaPtr getMonaCursor(const Gtk::TextIter &position);
    MonaPtr getMonaParsed();
    MonaPtr getMonaValid(); // getMonaParsed, or -- if it has errors -- getMonaLast
    MonaPtr getMonaLast();
    void requireMona(bool reqCompletion,bool reqParsed, bool reqLastValid) ;
    void requireMona(bool reqCompletion,const Gtk::TextIter &position, bool reqParsed, bool reqLastValid) ;
    void runMona(bool optimized);
    void mona_instantiate(const ustring &input, const boost::filesystem::path &filename);
    void mona_cleanup();
    void finetune_decl(Gtk::TextIter &orig_iter);

    // events
    void on_work_done();
    void on_run_fail();
    void on_mona_outstr();
    bool on_progress_timeout();

    void on_progress_abort();

    void on_sourcebuffer_changed();
    void on_errorview_row_activated(const Gtk::TreeModel::Path &path, Gtk::TreeViewColumn *column);

    void on_quit_activate();
    void on_new_activate();
    void on_open_activate();
    void on_save_activate();
    void on_saveas_activate();
    void on_cut_activate();
    void on_copy_activate();
    void on_paste_activate();
    void on_delete_activate();
    void on_about_activate();
    void on_run_activate();
    void on_runopt_activate();
    void on_undo_activate();
    void on_redo_activate();
    void on_import_activate();
    void on_showcompletion_activate();
    void on_insertVar0_activate();
    void on_insertVar1_activate();
    void on_insertVar2_activate();

    // UI elements
    GtkBuilderPtr glade;
    GsvSourceLanguageManagerPtr language_manager;
    GsvSourceLanguagePtr lang;
    MonaCompletionProviderPtr monaCompletionProvider;
    MonaCompletionProviderPtr monaCompletionHeaderProvider;
    ErrorViewColumns errorViewColumns;
    Glib::RefPtr<Gtk::ListStore> errorViewStore;
    Glib::RefPtr<Glib::TimeoutSource> timeout_source;

    // Dialogs and subwindows
    AboutDialogPtr aboutDialog;
    NewDialogPtr newDialog;
    ProgressWindowPtr progressWin;

    // Main menu & Toolbar
    GtkUIManagerPtr uiManager;
    Gtk::ToolItem declLabel;
    Gtk::Label declLabelLabel;

    // Instances from glade file
    Gsv::SourceView *sourceView; // Gtkmm managed

    // Analysis information on current document
    MonaPtr monaRun;
    MonaPtr monaCursor; // For information up to cursor position; Notably completion suggestions
    MonaPtr monaParsed; // For information from last complete parse; Notably list of declared identifiers
    bool monaLastObsolete;
    MonaPtr monaLast; // Last successful complete parse, may be out of data

    // Document properties
    boost::filesystem::path filename; // Filename incl. full path; "" if file not saved yet

    // Code completion
    std::vector<std::pair<Glib::RefPtr<Gtk::Action>, const CompletionItem *> > completionActions;
    Glib::RefPtr<CompletionItem> completionVar0Declaration;
    Glib::RefPtr<CompletionItem> completionVar1Declaration;
    Glib::RefPtr<CompletionItem> completionVar2Declaration;
};


// EditorWindow ///////////////////////////////////////////////////////////////

EditorWindowPtr EditorWindow::create() {
    boost::filesystem::path gladefile = app_lookup_datafile("glade", "editor.glade");

    Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create_from_file(gladefile.file_string());
    EditorWindowPtr result = EditorWindow::createFromBuilder(builder, "EditorWindow");
    return result;
}


EditorWindowPtr EditorWindow::createFromBuilder(const Glib::RefPtr<Gtk::Builder>& builder, const Glib::ustring &name) {
    EditorWindowImpl *impl = NULL;
    builder->get_widget_derived(name, impl);
    EditorWindowPtr result(impl);
    return result;
}


EditorWindow::EditorWindow(BaseObjectType *cobject, const Glib::RefPtr<Gtk::Builder>& /*glade*/):
    Gtk::Window(cobject) {
}


// EditorWindowImpl ///////////////////////////////////////////////////////////

EditorWindowImpl::EditorWindowImpl(BaseObjectType *cobject, const Glib::RefPtr<Gtk::Builder>& glade):
    EditorWindow(cobject, glade) {
    // ctor
    this->glade = glade;

    init_ui();
    init_sourceview();
    init_errorview();
    init_actions();
    init_dialogs();
    init_completion();

    // Update GUI
    show_all_children();
    UpdateTitle();

    monaLastObsolete = true;
    requireMona(true, true, true);
}


EditorWindowImpl::~EditorWindowImpl() {
    // dtor
}


Glib::RefPtr<Gtk::Action> EditorWindowImpl::connectAction(ustring actionName, void (EditorWindowImpl::*_A_func)()) {
    Glib::RefPtr<Gtk::Action> action = Glib::RefPtr<Gtk::Action>::cast_dynamic(glade->get_object(actionName));
    if (action) {
        action->signal_activate().connect(sigc::mem_fun(*this, _A_func));
    } else {
        fprintf(stderr, "Warning: No action named '%s'", actionName.raw().c_str());
    }
    return action;
}


Glib::RefPtr<Gsv::SourceBuffer> EditorWindowImpl::sourceBuffer() {
    Glib::RefPtr<Gsv::SourceBuffer> result = sourceView->get_source_buffer();
    assert(result);
    return result;
}


void EditorWindowImpl::init_ui() {
    const Glib::RefPtr<Gtk::Builder>& glade = this->glade;


    Gtk::VBox *vbox =NULL;
    getWidgetOrFail(vbox, glade, "UIContainer");

    Glib::RefPtr<Gtk::ActionGroup> actionGroup = Glib::RefPtr<Gtk::ActionGroup>::cast_dynamic( glade->get_object("Actions"));
    if (!actionGroup) {
        throw UnexpectedException("ActionGroup not found");
    }

    ustring ui_info = "<ui>"
                      "  <menubar name='MenuBar'>"
                      "    <menu action='FileMenu'>"
                      "      <menuitem action='new' />"
                      "      <menuitem action='open'/>"
                      "      <menuitem action='import'/>"
                      "      <menuitem action='save'/>"
                      "      <menuitem action='saveas'/>"
                      "      <separator/>"
                      "      <menuitem action='quit'/>"
                      "    </menu>"
                      "    <menu action='EditMenu'>"
                      "      <menuitem action='undo'/>"
                      "      <menuitem action='redo'/>"
                      "      <separator/>"
                      "      <menuitem action='cut'/>"
                      "      <menuitem action='copy'/>"
                      "      <menuitem action='paste'/>"
                      "      <menuitem action='delete'/>"
                      "    </menu>"
                      "    <menu action='MonaMenu'>"
                      "      <menuitem action='run'/>"
                      "      <menuitem action='runopt'/>"
                      "      <separator/>"
                      "      <menuitem action='showcompletion'/>"
                      "    </menu>"
                      "    <menu action='HelpMenu'>"
                      "      <menuitem action='about'/>"
                      "    </menu>"
                      "  </menubar>"
                      "  <toolbar name='ToolBar'>"
                      "    <toolitem action='new'/>"
                      "    <toolitem action='open'/>"
                      "    <toolitem action='import'/>"
                      "    <toolitem action='save'/>"
                      "    <toolitem action='saveas'/>"
                      "    <separator/>"
                      "    <toolitem action='undo'/>"
                      "    <toolitem action='cut'/>"
                      "    <toolitem action='copy'/>"
                      "    <toolitem action='paste'/>"
                      "    <separator/>"
                      "    <toolitem action='showcompletion'/>"
                      "    <toolitem action='run'/>"
                      "    <toolitem action='runopt'/>"
                      "  </toolbar>"
                      "  <toolbar name='DeclBar'>"
                      "  <placeholder action='declLabel' />"
                      "    <toolitem action='insertVar0'/>"
                      "    <toolitem action='insertVar1'/>"
                      "    <toolitem action='insertVar2'/>"
                      "  </toolbar>"
                      "</ui>";
    uiManager = Gtk::UIManager::create();
    assert(uiManager);

    uiManager->insert_action_group(actionGroup);
    this->add_accel_group(uiManager->get_accel_group());

    std::auto_ptr<Glib::Error> ex;
    uiManager->add_ui_from_string(ui_info);

    Gtk::Widget *pMenubar = uiManager->get_widget("/MenuBar");
    assert(pMenubar);
    if (pMenubar) {
        vbox->pack_start(*pMenubar, Gtk::PACK_SHRINK);
    }

    Gtk::Widget *pToolbar = uiManager->get_widget("/ToolBar");
    assert(pToolbar);
    if(pToolbar)    {
        vbox->pack_start(*pToolbar, Gtk::PACK_SHRINK);
    }

    Gtk::Widget *pDeclBar = uiManager->get_widget("/DeclBar");
    assert(pDeclBar);
    if(pDeclBar)    {
        // Manual tuning
        Gtk::Toolbar *myToolbar = dynamic_cast<Gtk::Toolbar *>(pDeclBar);
        if (myToolbar)  {
            myToolbar->set_toolbar_style(Gtk::TOOLBAR_TEXT);
            declLabelLabel.set_label("Declare variable:  ");
            declLabel.add(declLabelLabel);
            myToolbar->prepend(declLabel);
        }

        vbox->pack_start(*pDeclBar, Gtk::PACK_SHRINK);
        vbox->reorder_child(*pDeclBar, 2);
    }
}


void EditorWindowImpl::init_actions() {
    //TODO: Apply Gtk stock item label for translation
    connectAction("quit", &EditorWindowImpl::on_quit_activate);
    connectAction("new", &EditorWindowImpl::on_new_activate);
    connectAction("open", &EditorWindowImpl::on_open_activate);
    connectAction("save", &EditorWindowImpl::on_save_activate);
    connectAction("saveas", &EditorWindowImpl::on_saveas_activate);
    connectAction("cut", &EditorWindowImpl::on_cut_activate);
    connectAction("copy", &EditorWindowImpl::on_copy_activate);
    connectAction("paste", &EditorWindowImpl::on_paste_activate);
    connectAction("delete", &EditorWindowImpl::on_delete_activate);
    connectAction("about", &EditorWindowImpl::on_about_activate);
    connectAction("run", &EditorWindowImpl::on_run_activate);
    connectAction("runopt", &EditorWindowImpl::on_runopt_activate);
    connectAction("undo", &EditorWindowImpl::on_undo_activate);
    connectAction("redo", &EditorWindowImpl::on_redo_activate);

    connectAction("insertVar0", &EditorWindowImpl::on_insertVar0_activate);
    connectAction("insertVar1", &EditorWindowImpl::on_insertVar1_activate);
    connectAction("insertVar2", &EditorWindowImpl::on_insertVar2_activate);

    connectAction("import", &EditorWindowImpl::on_import_activate);
    connectAction("showcompletion", &EditorWindowImpl::on_showcompletion_activate);
}


void EditorWindowImpl::init_completion() {
    // SourceCompletion
    Glib::RefPtr<Gsv::SourceCompletion> completion = SourceView_getCompletion(sourceView);// sourceView->get_completion();
    assert(completion);
    completion->block_interactive();
    Glib::RefPtr<Gsv::SourceCompletionContext> context = completion->create_context();

    /* Keywords */
    MonaCompletionProviderPtr monaCompletionKeywords = MonaCompletionProvider::create(this, "Other keywords", 5);
    monaCompletionKeywords->addCompletion("-> ", "", "", "->", new TokenContext("tokARROW"), NULL);
    monaCompletionKeywords->addCompletion("...", "", "", "...", new TokenContext("tokINTERVAL"), NULL);
    monaCompletionKeywords->addCompletion("[", "", "", "[", new TokenContext("tokLBRACKET"), NULL);
    monaCompletionKeywords->addCompletion("]", "", "", "]", new TokenContext("tokRBRACKET"), NULL);
    monaCompletionKeywords->addCompletion("(", "", "", "(", new TokenContext("tokLPAREN"), NULL);
    monaCompletionKeywords->addCompletion(")", "", "", ")", new TokenContext("tokRPAREN"), NULL);
    monaCompletionKeywords->addCompletion(", ", "", "", ",", new TokenContext("tokCOMMA"), NULL);
    monaCompletionKeywords->addCompletion("assert ", "", "", "assert", new TokenContext("tokASSERT"), NULL);
    monaCompletionKeywords->addCompletion("universe ", "", "", "universe", new TokenContext("tokUNIVERSE"), NULL);
    monaCompletionKeywords->addCompletion("let0 ", "", "", "let0", new TokenContext("tokLET0"), NULL);
    monaCompletionKeywords->addCompletion("let1", "", "", "let1", new TokenContext("tokLET1"), NULL);
    monaCompletionKeywords->addCompletion("let2", "", "", "let2", new TokenContext("tokLET2"), NULL);
    monaCompletionKeywords->addCompletion("guide ", "", "", "guide", new TokenContext("tokGUIDE"), NULL);
    monaCompletionKeywords->addCompletion("const ", "", "", "const", new TokenContext("tokCONST"), NULL);
    monaCompletionKeywords->addCompletion("pred ", "", "", "pred", new TokenContext("tokPRED"), NULL);
    monaCompletionKeywords->addCompletion("macro ", "", "", "macro", new TokenContext("tokMACRO"), NULL);
    monaCompletionKeywords->addCompletion("root ", "", "", "root", new TokenContext("tokUNIVROOT"), NULL);
    monaCompletionKeywords->addCompletion("tree ", "", "", "tree", new TokenContext("tokTREE"), NULL);
    monaCompletionKeywords->addCompletion("where", "", "", "where", new TokenContext("tokWHERE"), NULL);
    monaCompletionKeywords->addCompletion("defaultwhere1 ", "", "", "defaultwhere1", new TokenContext("tokDEFAULT1"), NULL);
    monaCompletionKeywords->addCompletion("defaultwhere2 ", "", "", "defaultwhere2", new TokenContext("tokDEFAULT2"), NULL);
    monaCompletionKeywords->addCompletion("include ", "", "", "include", new TokenContext("tokINCLUDE"), NULL);
    monaCompletionKeywords->addCompletion("import ", "", "", "import", new TokenContext("tokIMPORT"), NULL);
    monaCompletionKeywords->addCompletion("export ", "", "", "export", new TokenContext("tokEXPORT"), NULL);
    monaCompletionKeywords->addCompletion("prefix ", "", "", "prefix", new TokenContext("tokPREFIX"), NULL);
    monaCompletionKeywords->addCompletion("in_state_space ", "", "", "in_state_space", new TokenContext("tokINSTATESPACE"), NULL);
    monaCompletionKeywords->addCompletion("execute ", "", "", "execute", new TokenContext("tokEXECUTE"), NULL);
    monaCompletionKeywords->addCompletion("lastpos ", "", "", "lastpos", new TokenContext("tokLASTPOS"), NULL);
    monaCompletionKeywords->addCompletion("allpos ", "", "", "", new TokenContext("tokALLPOS"), NULL);
    monaCompletionKeywords->addCompletion("type ", "", "", "type", new TokenContext("tokTYPE"), NULL);
    monaCompletionKeywords->addCompletion("sometype ", "", "", "sometype", new TokenContext("tokSOMETYPE"), NULL);
    monaCompletionKeywords->addCompletion("variant ", "", "", "variant", new TokenContext("tokVARIANT"), NULL);
    monaCompletionKeywords->addCompletion("succ ", "", "", "succ", new TokenContext("tokSUCC"), NULL);
    monaCompletionKeywords->addCompletion("const_tree ", "", "", "const_tree", new TokenContext("tokCONSTTREE"), NULL);
    monaCompletionKeywords->addCompletion("tree_root ", "", "", "tree_root", new TokenContext("tokTREEROOT"), NULL);
    monaCompletionKeywords->addCompletion("restrict ", "", "", "restrict", new TokenContext("tokRESTRICT"), NULL);
    monaCompletionKeywords->addCompletion("verify ", "", "", "verify", new TokenContext("tokVERIFY"), NULL);
    assertSuccess(completion->add_provider(monaCompletionKeywords));

    MonaCompletionProviderPtr monaCompletionStringProvider = MonaCompletionProvider::create(this, "String", 9);
    monaCompletionStringProvider->addCompletion("\"", "", "\" ", "\"...\"", new TokenContext("tokSTRING"), "String literal");
    assertSuccess(completion->add_provider(monaCompletionStringProvider));

    /* Operators */
    MonaCompletionProviderPtr monaCompletionOperators = MonaCompletionProvider::create(this, "Operators", 5);
    monaCompletionOperators->addCompletion(".0 ", "", "", ".0", new TokenContext("tokDOT"), "Left successor (tree mode)");
    monaCompletionOperators->addCompletion(".1 ", "", "", ".1", new TokenContext("tokDOT"), "Right successor (tree mode)");
    monaCompletionOperators->addCompletion("^ ", "", "", "^", new TokenContext("tokUP"), "Predecessor (tree mode)");
    monaCompletionOperators->addCompletion("* ", "", "", "*", new TokenContext("tokSTAR"), NULL);
    monaCompletionOperators->addCompletion("/ ", "", "", "/", new TokenContext("tokSLASH"), NULL);
    monaCompletionOperators->addCompletion("% ", "", "", "%", new TokenContext("tokMODULO"), NULL);
    monaCompletionOperators->addCompletion("+ ", "", "", "+", new TokenContext("tokPLUS"), NULL);
    monaCompletionOperators->addCompletion("- ", "", "", "-", new TokenContext("tokMINUS"), NULL);
    monaCompletionOperators->addCompletion("\\ ", "", "", "\\", new TokenContext("tokSETMINUS"), NULL);
    monaCompletionOperators->addCompletion("inter ", "", "", "inter", new TokenContext("tokINTER"), NULL);
    monaCompletionOperators->addCompletion("union ", "", "", "union", new TokenContext("tokUNION"), NULL);
    monaCompletionOperators->addCompletion("max ", "", "", "max", new TokenContext("tokMAX"), NULL);
    monaCompletionOperators->addCompletion("min  ", "", "", "min ", new TokenContext("tokMIN"), NULL);
    monaCompletionOperators->addCompletion("= ", "", "", "=", new TokenContext("tokEQUAL"), NULL);
    monaCompletionOperators->addCompletion("~=", "", "", "~=", new TokenContext("tokNOTEQUAL"), NULL);
    monaCompletionOperators->addCompletion("> ", "", "", ">", new TokenContext("tokGREATER"), NULL);
    monaCompletionOperators->addCompletion(">= ", "", "", ">=", new TokenContext("tokGREATEREQ"), NULL);
    monaCompletionOperators->addCompletion("< ", "", "", "<", new TokenContext("tokLESS"), NULL);
    monaCompletionOperators->addCompletion("<= ", "", "", "<=", new TokenContext("tokLESSEQ"), NULL);
    monaCompletionOperators->addCompletion("in ", "", "", "in", new TokenContext("tokIN"), NULL);
    monaCompletionOperators->addCompletion("notin ", "", "", "notin", new TokenContext("tokNOTIN"), NULL);
    monaCompletionOperators->addCompletion("sub ", "", "", "sub", new TokenContext("tokSUB"), NULL);
    monaCompletionOperators->addCompletion("~ ", "", "", "~", new TokenContext("tokNOT"), NULL);
    monaCompletionOperators->addCompletion("& ", "", "", "&", new TokenContext("tokAND"), NULL);
    monaCompletionOperators->addCompletion("| ", "", "", "|", new TokenContext("tokOR"), NULL);
    monaCompletionOperators->addCompletion("=> ", "", "", "=>", new TokenContext("tokIMPL"), NULL);
    monaCompletionOperators->addCompletion("<=> ", "", "", "<=>", new TokenContext("tokBIIMPL"), NULL);
    monaCompletionOperators->addCompletion(": ", "", "", ":", new TokenContext("tokCOLON"), NULL);
    assertSuccess(completion->add_provider(monaCompletionOperators));

    /* Declarations */
    monaCompletionProvider = MonaCompletionProvider::create(this, "Variable declarations", 10);
    completionVar0Declaration = CompletionItem::create("var0 ", "⍰", ";\n", "var0 ⍰;", declExpected, "Declaration of a boolean variable");
    monaCompletionProvider->addCompletion(completionVar0Declaration);
    completionVar1Declaration = CompletionItem::create("var1 ", "⍰", ";\n", "var1 ⍰;", declExpected, "Declaration of a variable containing an integer");
    monaCompletionProvider->addCompletion(completionVar1Declaration);
    completionVar2Declaration = CompletionItem::create("var2 ", "⍰", ";\n", "var2 ⍰;", declExpected, "Declaration of a variable containing a set");
    monaCompletionProvider->addCompletion(completionVar2Declaration);
    assertSuccess(completion->add_provider(monaCompletionProvider));

    /* Declare that something must be always valid */
    MonaCompletionProviderPtr monaCompletionBooleanExpression = MonaCompletionProvider::create(this, "Boolean expressions", 10);
    monaCompletionBooleanExpression->addCompletion("ex0 ⍰: ", "⍰", ";\n", "ex0", declExpected, "Expression must be true for ⍰=false or ⍰=true");
    monaCompletionBooleanExpression->addCompletion("ex1 ⍰: ", "⍰", ";\n", "ex1", declExpected, "Expression must be true for at least one integer/node");
    monaCompletionBooleanExpression->addCompletion("ex2 ⍰: ", "⍰", ";\n", "ex2", declExpected, "Expression must be true for at least one set");
    monaCompletionBooleanExpression->addCompletion("all0 ⍰: ", "⍰", ";\n", "all0", declExpected, "Expression must be true for ⍰=false and ⍰=true");
    monaCompletionBooleanExpression->addCompletion("all1 ⍰: ", "⍰", ";\n", "all1", declExpected, "Expression must be true for all integers/nodes");
    monaCompletionBooleanExpression->addCompletion("all2 ⍰: ", "⍰", ";\n", "all2", declExpected, "Expression must be true for all sets");
    monaCompletionBooleanExpression->addCompletion("", "⍰", " sub ⍰;\n", "sub (subset)", declExpected, "First set must be a subset of second set");
    monaCompletionBooleanExpression->addCompletion("", "⍰", " in ⍰;\n", "in", declExpected, "Element must be contained in set");
    monaCompletionBooleanExpression->addCompletion("", "⍰", " notin ⍰;\n", "notin", declExpected, "Set may not contain integer/node");
    monaCompletionBooleanExpression->addCompletion("", "⍰", " < ⍰;\n", "<", declExpected, "First expression must be smaller than second argument.");
    monaCompletionBooleanExpression->addCompletion("", "⍰", " <= ⍰;\n", "<=", declExpected, "First expression must be smaller or equal to second argument.");
    monaCompletionBooleanExpression->addCompletion("", "⍰", " >= ⍰;\n", ">=", declExpected, NULL);
    monaCompletionBooleanExpression->addCompletion("", "⍰", " > ⍰;\n", ">", declExpected, NULL);
    monaCompletionBooleanExpression->addCompletion("", "⍰", " = ⍰;\n", "=", declExpected, NULL);
    monaCompletionBooleanExpression->addCompletion("", "⍰", " ~= ⍰;\n", "~=", declExpected, NULL);
    monaCompletionBooleanExpression->addCompletion("", "⍰", " => ⍰;\n", "=> (implication)", declExpected, NULL);
    monaCompletionBooleanExpression->addCompletion("", "⍰", " <=> ⍰;\n", "<=> (equivalence)", declExpected, NULL);
    monaCompletionBooleanExpression->addCompletion("", "⍰", " & ⍰;\n", "&", declExpected, "Both expressions must be true");
    monaCompletionBooleanExpression->addCompletion("", "⍰", " | ⍰;\n", "|", declExpected, NULL);
    monaCompletionBooleanExpression->addCompletion("~", "⍰", ";\n", "~", declExpected, "Expression must be wrong.");

    /* Return a boolean value */
    monaCompletionBooleanExpression->addCompletion("", "⍰", " sub ⍰", "sub", boolExpContextsPredOrMoreOrParen[8], NULL);
    monaCompletionBooleanExpression->addCompletion("(", "⍰", " sub ⍰)", "sub", boolExpContextsPredLessThan[8], NULL);
    monaCompletionBooleanExpression->addCompletion("ex0 ⍰: ", "⍰", "", "ex0", boolExpContextsPredOrMoreOrParen[14], "Is it true for ⍰=false or ⍰=true?");
    monaCompletionBooleanExpression->addCompletion("(ex0 ⍰: ", "⍰", ")", "ex0", boolExpContextsPredLessThan[14], "Is it true for ⍰=false or ⍰=true?");
    monaCompletionBooleanExpression->addCompletion("ex1 ⍰: ", "⍰", "", "ex1",  boolExpContextsPredOrMoreOrParen[14], "Is it true for at least one integer/node?");
    monaCompletionBooleanExpression->addCompletion("(ex1 ⍰: ", "⍰", ")", "ex1",  boolExpContextsPredLessThan[14], "Is it true for at least one integer/node?");
    monaCompletionBooleanExpression->addCompletion("ex2 ⍰: ", "⍰", "", "ex2",  boolExpContextsPredOrMoreOrParen[14], "Is it true for at least one set?");
    monaCompletionBooleanExpression->addCompletion("(ex2 ⍰: ", "⍰", ")", "ex2",  boolExpContextsPredLessThan[14], "Is it true for at least one set?");
    monaCompletionBooleanExpression->addCompletion("all0 ⍰: ", "⍰", "", "all0",  boolExpContextsPredOrMoreOrParen[14], "Is it true for ⍰=false and ⍰=true?");
    monaCompletionBooleanExpression->addCompletion("(all0 ⍰: ", "⍰", ")", "all0",  boolExpContextsPredLessThan[14], "Is it true for ⍰=false and ⍰=true?");
    monaCompletionBooleanExpression->addCompletion("all1 ⍰: ", "⍰", "", "all1",  boolExpContextsPredOrMoreOrParen[14], "Is it true for all integers/nodes?");
    monaCompletionBooleanExpression->addCompletion("(all1 ⍰: ", "⍰", ")", "all1",  boolExpContextsPredLessThan[14], "Is it true for all integers/nodes?");
    monaCompletionBooleanExpression->addCompletion("all2 ⍰: ", "⍰", "", "all2",  boolExpContextsPredOrMoreOrParen[14], "Is it true for all sets?");
    monaCompletionBooleanExpression->addCompletion("(all2 ⍰: ", "⍰", ")", "all2",  boolExpContextsPredLessThan[14], "Is it true for all sets?");
    monaCompletionBooleanExpression->addCompletion("", "⍰", " in ⍰", "in", boolExpContextsPredOrMoreOrParen[8], NULL);
    monaCompletionBooleanExpression->addCompletion("(", "⍰", " in ⍰)", "in", boolExpContextsPredLessThan[8], NULL);
    monaCompletionBooleanExpression->addCompletion("", "⍰", " notin ⍰", "notin", boolExpContextsPredOrMoreOrParen[8], NULL);
    monaCompletionBooleanExpression->addCompletion("(", "⍰", " notin ⍰)", "notin", boolExpContextsPredLessThan[8], NULL);
    monaCompletionBooleanExpression->addCompletion("", "⍰", " < ⍰", "<", boolExpContextsPredOrMoreOrParen[7], NULL);
    monaCompletionBooleanExpression->addCompletion("(", "⍰", " < ⍰)", "<",  boolExpContextsPredLessThan[7], NULL);
    monaCompletionBooleanExpression->addCompletion("", "⍰", " <= ⍰", "<=", boolExpContextsPredOrMoreOrParen[7], NULL);
    monaCompletionBooleanExpression->addCompletion("(", "⍰", " <= ⍰)", "<=",  boolExpContextsPredLessThan[7], NULL);
    monaCompletionBooleanExpression->addCompletion("", "⍰", " >= ⍰", ">=", boolExpContextsPredOrMoreOrParen[7], NULL);
    monaCompletionBooleanExpression->addCompletion("(", "⍰", " >= ⍰)", ">=",  boolExpContextsPredLessThan[7], NULL);
    monaCompletionBooleanExpression->addCompletion("", "⍰", " > ⍰", ">", boolExpContextsPredOrMoreOrParen[7], NULL);
    monaCompletionBooleanExpression->addCompletion("(", "⍰", " > ⍰)", ">",  boolExpContextsPredLessThan[7], NULL);
    monaCompletionBooleanExpression->addCompletion("", "⍰", " = ⍰", "=", boolExpContextsPredOrMoreOrParen[7], NULL);
    monaCompletionBooleanExpression->addCompletion("(", "⍰", " = ⍰)", "=",  boolExpContextsPredLessThan[7], NULL);
    monaCompletionBooleanExpression->addCompletion("", "⍰", " ~= ⍰", "~=", boolExpContextsPredOrMoreOrParen[7], NULL);
    monaCompletionBooleanExpression->addCompletion("(", "⍰", " ~= ⍰)", "~=",  boolExpContextsPredLessThan[7], NULL);
    monaCompletionBooleanExpression->addCompletion("", "⍰", " => ⍰", "=> (implication)", boolExpContextsPredOrMoreOrParen[12], NULL);
    monaCompletionBooleanExpression->addCompletion("(", "⍰", " => ⍰)", "=> (implication)", boolExpContextsPredLessThan[12], NULL);
    monaCompletionBooleanExpression->addCompletion("", "⍰", " <=> ⍰", "<=> (equivalence)", boolExpContextsPredOrMoreOrParen[13], NULL);
    monaCompletionBooleanExpression->addCompletion("(", "⍰", " <=> ⍰)", "<=> (equivalence)", boolExpContextsPredLessThan[13], NULL);
    monaCompletionBooleanExpression->addCompletion("", "⍰", " & ⍰", "&", boolExpContextsPredOrMoreOrParen[10], "Is it true for both expressions?");
    monaCompletionBooleanExpression->addCompletion("(", "⍰", " & ⍰)", "&", boolExpContextsPredLessThan[10], "Is it true for both expressions?");
    monaCompletionBooleanExpression->addCompletion("", "⍰", " | ⍰", "|", boolExpContextsPredOrMoreOrParen[11], NULL);
    monaCompletionBooleanExpression->addCompletion("(", "⍰", " | ⍰)", "|",  boolExpContextsPredLessThan[11], NULL);
    monaCompletionBooleanExpression->addCompletion("~", "⍰", "", "|",  boolExpContextsPredOrMoreOrParen[9], NULL);
    monaCompletionBooleanExpression->addCompletion("(~", "⍰", ")", "|",  boolExpContextsPredLessThan[9], NULL);
    monaCompletionBooleanExpression->addCompletion("true ", "", "", "true", boolExpExpected, NULL);
    monaCompletionBooleanExpression->addCompletion("false ", "", "", "false", boolExpExpected, NULL);
    assertSuccess(completion->add_provider(monaCompletionBooleanExpression));

    /* Integer/node expressions */
    MonaCompletionProviderPtr monaCompletionIntegerExpression = MonaCompletionProvider::create(this, "Integer/node expressions", 10);
    monaCompletionIntegerExpression->addCompletion("", "⍰", " * ⍰", "*", intExpContextsPredOrMoreOrParen[1], "Multiplication");
    monaCompletionIntegerExpression->addCompletion("(", "⍰", " * ⍰)", "*", intExpContextsPredLessThan[1], "Multiplication");
    monaCompletionIntegerExpression->addCompletion("", "⍰", " / ⍰", "/", intExpContextsPredOrMoreOrParen[1], "Division");
    monaCompletionIntegerExpression->addCompletion("(", "⍰", " / ⍰)", "/", intExpContextsPredLessThan[1], "Division");
    monaCompletionIntegerExpression->addCompletion("", "⍰", " + ⍰ % ⍰", "+ %", intExpContextsPredOrMoreOrParen[1], NULL);
    monaCompletionIntegerExpression->addCompletion("(", "⍰", " + ⍰ % ⍰)", "+ %", intExpContextsPredLessThan[1], NULL);
    monaCompletionIntegerExpression->addCompletion("", "⍰", " - ⍰ % ⍰", "- %", intExpContextsPredOrMoreOrParen[1], NULL);
    monaCompletionIntegerExpression->addCompletion("(", "⍰", " - ⍰ % ⍰)", "- %", intExpContextsPredLessThan[1], NULL);
    monaCompletionIntegerExpression->addCompletion("", "⍰", " + ⍰", "+", intExpContextsPredOrMoreOrParen[2], NULL);
    monaCompletionIntegerExpression->addCompletion("(", "⍰", " + ⍰)", "+", intExpContextsPredLessThan[2], NULL);
    monaCompletionIntegerExpression->addCompletion("", "⍰", " - ⍰", "-", intExpContextsPredOrMoreOrParen[2], NULL);
    monaCompletionIntegerExpression->addCompletion("(", "⍰", " - ⍰)", "-", intExpContextsPredLessThan[2], NULL);
    monaCompletionIntegerExpression->addCompletion("", "⍰", ".0", ".0", intExpExpected, "Left successor (tree mode)");
    monaCompletionIntegerExpression->addCompletion("", "⍰", ".1", ".1", intExpExpected, "Right successor (tree mode)");
    monaCompletionIntegerExpression->addCompletion("", "⍰", "^", "^", intExpExpected, "Predecessor (tree mode)");
    assertSuccess(completion->add_provider(monaCompletionIntegerExpression));

    /* Set expressions */
    MonaCompletionProviderPtr monaCompletionSetExpression = MonaCompletionProvider::create(this, "Set expressions", 10);
    monaCompletionIntegerExpression->addCompletion("", "⍰", " \\ ⍰", "⍰ \\ ⍰", setExpContextsPredOrMoreOrParen[3], "Set substraction");
    monaCompletionIntegerExpression->addCompletion("(", "⍰", " \\ ⍰)", "⍰ \\ ⍰", setExpContextsPredLessThan[3], "Set substraction");
    monaCompletionIntegerExpression->addCompletion("", "⍰", " inter ⍰", "⍰ inter ⍰", setExpContextsPredOrMoreOrParen[4], NULL);
    monaCompletionIntegerExpression->addCompletion("(", "⍰", " inter ⍰)", "⍰ inter ⍰", setExpContextsPredLessThan[4], NULL);
    monaCompletionIntegerExpression->addCompletion("", "⍰", " union ⍰", "⍰ union ⍰", setExpContextsPredOrMoreOrParen[5], NULL);
    monaCompletionIntegerExpression->addCompletion("(", "⍰", " union ⍰)", "⍰ union ⍰", setExpContextsPredLessThan[5], NULL);
    monaCompletionIntegerExpression->addCompletion("empty ", "", "", "empty", setExpExpected, NULL);
    monaCompletionIntegerExpression->addCompletion("{ ", "⍰", " }", "{ ... }", setExpExpected, NULL);
    assertSuccess(completion->add_provider(monaCompletionSetExpression));

    /* Variable names */
    MonaCompletionProviderPtr monaCompletionVar0nameProvider = MonaCompletionProvider::create(this, "Boolean variables", 9);
    monaCompletionVar0nameProvider->addIdentifierCompletion(Varname0, boolExpExpected);
    assertSuccess(completion->add_provider(monaCompletionVar0nameProvider));

    MonaCompletionProviderPtr monaCompletionVar1nameProvider = MonaCompletionProvider::create(this, "Integer/node variables", 9);
    monaCompletionVar1nameProvider->addIdentifierCompletion(Varname1, intExpExpected);
    assertSuccess(completion->add_provider(monaCompletionVar1nameProvider));

    MonaCompletionProviderPtr monaCompletionVar2nameProvider = MonaCompletionProvider::create(this, "Set variables", 9);
    monaCompletionVar2nameProvider->addIdentifierCompletion(Varname2, setExpExpected);
    assertSuccess(completion->add_provider(monaCompletionVar2nameProvider));

    monaCompletionHeaderProvider = MonaCompletionProvider::create(this, "Document type declaration", 11);
    monaCompletionHeaderProvider->addCompletion("ws1s;\n", "", "", "ws1s", headerExpected, "Weak monadic Second-order theory of 1 Successor (string mode)");
    monaCompletionHeaderProvider->addCompletion("ws2s;\n", "", "", "ws2s", headerExpected, "Weak monadic Second-order theory of 2 Successors (tree mode)");
    monaCompletionHeaderProvider->addCompletion("m2l-str;\n", "", "", "m2l-str", headerExpected, "Monadic Second-order Logic on Strings");
    monaCompletionHeaderProvider->addCompletion("m2l-tree;\n", "", "", "m2l-str", headerExpected, "Monadic Second-order Logic on Trees");
    assertSuccess(completion->add_provider(monaCompletionHeaderProvider));
}


void EditorWindowImpl::init_sourceview() {
    sourceView = NULL;
    getWidgetOrFail(sourceView, glade, "SourceView");

    // init LanguageManager
    language_manager = Gsv::SourceLanguageManager::get_default();
    Glib::StringArrayHandle oldSearchPath = language_manager->get_search_path();
    std::vector<std::string> newSearchPath = oldSearchPath;
    boost::filesystem::path langspecdir = app_lookup_datafile("language-specs", "");
    newSearchPath.push_back(langspecdir.directory_string());
    language_manager->set_search_path(newSearchPath);
    lang = get_language_from_mime_type(language_manager, "text/x-mona");

    sourceView->set_mark_category_priority("StatusMsg", 100);
    resetSourceBuffer();
    GsvSourceBufferPtr buffer = sourceBuffer();
#if DEBUG
    buffer->set_text("var2 P,Q;\nP\\Q = {0,4} union {1,2};\n\npred even(var1 p) = \n  ex2 Q: p in Q\n    & (all1 q:\n        (0 < q & q <= p) =>\n            (q in Q => q - 1 notin Q)\n          & (q notin Q => q - 1 in Q))\n    & 0 in Q; \n\nvar1 x;\nvar0 A;\n\nA & even(x) & x notin P;");
    //buffer->set_text("ws2s;\n\nguide d0->(a,b), a->(a,a), b->(b,b);\nuniverse ua:0, ub:1;\n\nvar2 [ua] A;\nvar2 [ub] B;\n\nex1 [ua] p1,p2,p3,p4,p5: \n  p1<p2 & p2<p3 & p3<p4 & p4<p5 &\n  A = {p1,p2,p3,p4,p5};\n\nex1 [ub] p1,p2,p3,p4,p5,p6,p7: \n  p1<p2 & p2<p3 & p3<p4 & p4<p5 & p5<p6 & p6<p7 &\n  B = {p1,p2,p3,p4,p5,p6,p7};");
#endif
}


void EditorWindowImpl::init_errorview() {
    Gtk::TreeView *errorView = NULL;
    glade->get_widget("ErrorView", errorView);
    assert(errorView);
    errorViewStore = Glib::RefPtr<Gtk::ListStore>::cast_dynamic(glade->get_object("ErrorViewStore"));
    assert(errorViewStore);
    errorView->signal_row_activated().connect(sigc::mem_fun(this, &EditorWindowImpl::on_errorview_row_activated));
}


void EditorWindowImpl::init_dialogs() {
    newDialog = NewDialog::create();
    newDialog->set_transient_for(*this);

    aboutDialog = AboutDialog::create();
    aboutDialog->set_transient_for(*this);

    progressWin = ProgressWindow::create();
    progressWin->signal_abort.connect(sigc::mem_fun(*this, &EditorWindowImpl::on_progress_abort));
}


void EditorWindowImpl::UpdateTitle() {
    ustring appname = PACKAGE_STRING;
    ustring hyphen = " - ";
    if (!filename.has_filename()) {
        this->set_title("Unsaved" + hyphen + appname);
    } else {
        this->set_title(filename.stem() + hyphen + appname);
    }
}


void EditorWindowImpl::insertTextAtCursor(const ustring &str) {
    Glib::RefPtr<Gsv::SourceBuffer> buffer = this->sourceBuffer();
    buffer->insert_interactive_at_cursor(str);
}


void EditorWindowImpl::insertCompletion(const Glib::RefPtr<CompletionItem> &item) {
    Gtk::TextIter iter = sourceBuffer()->get_iter_at_mark(sourceBuffer()->get_insert());
    insertCompletion(item, iter);
}


void EditorWindowImpl::insertCompletion(const Glib::RefPtr<CompletionItem> &item, const Gtk::TextIter &position) {
    Glib::RefPtr<Gsv::SourceBuffer> buffer = sourceBuffer();
    Gtk::TextIter startPosition = position;
    Gtk::TextIter cursor = position;

    // Track back to find beginning of word
    bool oneBack = cursor.backward_char(); // Move to character to the left of cursor position (an iterator is the position between two characters, get_char() returns the right of it)
    while (true) {
        gunichar ch = cursor.get_char();
        if (!g_unichar_isalnum(ch) && ch != '_') {
            break;
        }

        if (!cursor.backward_char()) {
            break;
        }
    }
    if (oneBack) {
        cursor.forward_char();
    }

    int cursorOffset = cursor.get_offset();
    ustring insertBeforeCursor = item->getInsertBeforeCursor();
    ustring insertAtCursor = item->getInsertAtCursor();
    ustring insertAfterCursor = item->getInsertAfterCursor();
    ustring insertAll = insertBeforeCursor + insertAtCursor + insertAfterCursor;
    cursor = buffer->erase(cursor, startPosition);
    cursor = buffer->insert_interactive(cursor, insertAll).first;

    Gtk::TextIter selectionStart = buffer->get_iter_at_offset(cursorOffset + insertBeforeCursor.size());
    Gtk::TextIter selectionEnd = buffer->get_iter_at_offset(cursorOffset + insertBeforeCursor.size() + insertAtCursor.size());

    buffer->select_range(selectionStart, selectionEnd);
}


void EditorWindowImpl::linkCompletionAction(Glib::RefPtr<Gtk::Action> action, const CompletionItem *item) {
    completionActions.push_back(std::pair<Glib::RefPtr<Gtk::Action>, const CompletionItem *>(action, item));
}


void EditorWindowImpl::clearErrorMessages() {
    errorViewStore->clear();
    sourceBuffer()->remove_source_marks(sourceBuffer()->begin(), sourceBuffer()->end(), "StatusMsg");
}


void EditorWindowImpl::addError(ustring msg) {
    Gtk::TreeModel::Row newRow = *(errorViewStore->append());
    newRow[errorViewColumns.typeColumn] = "Error";
    newRow[errorViewColumns.msgColumn] = msg;
}


void EditorWindowImpl::addError(ustring msg, int line, int column) {
    Gtk::TreeModel::Row newRow = *(errorViewStore->append());
    newRow[errorViewColumns.typeColumn] = "Error";
    newRow[errorViewColumns.lineColumn] = line;
    newRow[errorViewColumns.columnColumn] = column;
    newRow[errorViewColumns.msgColumn] = msg;
}


void EditorWindowImpl::on_quit_activate() {
    this->hide();
}


void EditorWindowImpl::getTemplateDocument(bool treeMode, bool finite, bool tutorial, /*out*/ ustring &result) {
    result = "";
    if (!treeMode) {
        if (!finite) {
            if (!tutorial) {
                result = "ws1s;\n\n";
            } else {
                boost::filesystem::path filename(app_lookup_datafile("templates", "ws1s_tutorial.mona"));
                std::ifstream stream(filename.file_string().c_str());
                read_all_lines(stream, result);
                stream.close();
            }
        } else {
            result = "m2l-str;\n\n";
        }
    } else {
        if (!finite) {
            result = "ws2s;\n\n";
        } else {
            result = "m2l-tree;\n\n";
        }
    }
}


void EditorWindowImpl::resetSourceBuffer() {
    GsvSourceBufferPtr buffer = Gsv::SourceBuffer::create(lang);
    buffer->set_language(lang);
    Glib::RefPtr<Gsv::SourceStyleSchemeManager> style_manager = Gsv::SourceStyleSchemeManager::get_default();
    Glib::RefPtr<Gsv::SourceStyleScheme> editor_style = style_manager->get_scheme("kate");
    buffer->set_style_scheme(editor_style);
    buffer->set_highlight_syntax(true);
    buffer->signal_changed().connect(sigc::mem_fun(this, &EditorWindowImpl::on_sourcebuffer_changed));
    sourceView->set_buffer(buffer);
    on_sourcebuffer_changed();
}


void EditorWindowImpl::user_createNew(bool treeMode, bool finite, bool tutorial) {
    // Need a template for all six combinations
    ustring templateDoc;
    getTemplateDocument(treeMode, finite, tutorial, templateDoc);
    GsvSourceBufferPtr buffer = sourceBuffer();
    buffer->set_text(templateDoc);
}


void EditorWindowImpl::on_new_activate() {
    int response = newDialog->run();
    newDialog->hide();

    switch(response) {
    case Gtk::RESPONSE_OK: {
        bool treeMode = newDialog->get_TreeMode();
        bool finite = newDialog->get_Finite();
        bool tutorial = newDialog->get_Tutorial();
        user_createNew(treeMode, finite, tutorial);
    }
    break;
    case Gtk::RESPONSE_DELETE_EVENT:
    case Gtk::RESPONSE_CANCEL: {
        // Do nothing
    }
    break;
    default:
        assert(!"Unknown response code");
    }
}


void EditorWindowImpl::on_open_activate() {
    Gtk::FileChooserDialog dialog(*this, "Open Mona file", Gtk::FILE_CHOOSER_ACTION_OPEN);

    dialog.add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
    dialog.add_button(Gtk::Stock::OPEN, Gtk::RESPONSE_OK);

    GtkFileFilterPtr filter_mona = createFileFilter();
    filter_mona->set_name("Mona files");
    filter_mona->add_pattern("*.mona");
    gtk_dialogAddFileFilter(dialog, filter_mona);

    GtkFileFilterPtr filter_any = createFileFilter();
    filter_any->set_name("All files");
    filter_any->add_pattern("*");
    gtk_dialogAddFileFilter(dialog, filter_any);

    dialog.set_transient_for(*this);

    int result = dialog.run();

    switch (result) {
    case Gtk::RESPONSE_OK: {
        ustring str_filename = dialog.get_filename();
        this->filename = boost::filesystem::path(str_filename);

        boost::filesystem::ifstream file;
        file.open(filename, std::ios_base::in);
        ustring contents;
        read_all_lines(file, contents);
        file.close();
        sourceBuffer()->set_text(contents);

        UpdateTitle();
    }
    break;
    case Gtk::RESPONSE_DELETE_EVENT:
    case Gtk::RESPONSE_CANCEL:
        // Do nothing
        break;

    default:
        assert(!"Unexpected dialog return code");
    }
}


void EditorWindowImpl::on_save_activate() {
    if (filename.has_filename()) {
        save();
    } else {
        on_saveas_activate();
    }
}


void EditorWindowImpl::save() {
    assert(filename.has_filename());
    if (boost::filesystem::exists(filename)) {
        boost::filesystem::remove_all(filename);
    }

    boost::filesystem::ofstream file;
    file.open(filename, std::ios_base::trunc | std::ios_base::out);
    file << sourceBuffer()->get_text();
    file.close();
}


void EditorWindowImpl::on_saveas_activate() {
    Gtk::FileChooserDialog dialog(*this, "Save Mona file...", Gtk::FILE_CHOOSER_ACTION_SAVE );

    dialog.add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
    dialog.add_button(Gtk::Stock::SAVE_AS, Gtk::RESPONSE_OK);

    GtkFileFilterPtr filter_mona = createFileFilter();
    filter_mona->set_name("Mona files");
    filter_mona->add_pattern("*.mona");
    gtk_dialogAddFileFilter(dialog, filter_mona);

    GtkFileFilterPtr filter_any = createFileFilter();
    filter_any->set_name("All files");
    filter_any->add_pattern("*");
    gtk_dialogAddFileFilter(dialog, filter_any);

    dialog.set_transient_for(*this);
    dialog.set_filename(filename.file_string());

    int result = dialog.run();
    dialog.hide();

    switch (result) {
    case Gtk::RESPONSE_OK: {
        ustring str_filename = dialog.get_filename();
        this->filename = boost::filesystem::path(str_filename);
        save();

        UpdateTitle();
    }
    break;
    case Gtk::RESPONSE_DELETE_EVENT:
    case Gtk::RESPONSE_CANCEL:
        // Do nothing
        break;

    default:
        assert(!"Unexpected dialog return code");
    }
}


void EditorWindowImpl::on_cut_activate() {
    Glib::RefPtr<Gsv::SourceBuffer> sbuffer = sourceView->get_source_buffer();
    assert(sbuffer);

    Glib::RefPtr<Gtk::Clipboard> clipboard = Gtk::Clipboard::get();
    assert(clipboard);

    sbuffer->cut_clipboard(clipboard);
    sourceView->grab_focus();
}


void EditorWindowImpl::on_copy_activate() {
    Glib::RefPtr<Gtk::TextBuffer> buffer;
    Glib::RefPtr<Gsv::SourceBuffer> sbuffer;
    Glib::RefPtr<Gtk::Clipboard> clipboard;

    sbuffer = sourceView->get_source_buffer();
    assert(sbuffer);
    buffer = sbuffer;

    clipboard = Gtk::Clipboard::get();
    assert(clipboard);

    buffer->copy_clipboard(clipboard);
    sourceView->grab_focus();
}


void EditorWindowImpl::on_paste_activate() {
    Glib::RefPtr<Gsv::SourceBuffer> sbuffer = sourceView->get_source_buffer();
    assert(sbuffer);

    Glib::RefPtr<Gtk::Clipboard> clipboard = Gtk::Clipboard::get();
    assert(clipboard);

    sbuffer->paste_clipboard(clipboard);
    sourceView->grab_focus();
}


void EditorWindowImpl::on_delete_activate() {
    Glib::RefPtr<Gsv::SourceBuffer> sbuffer = sourceView->get_source_buffer();
    assert(sbuffer);
    Glib::RefPtr<Gtk::TextBuffer> buffer = sbuffer;

    Glib::RefPtr<Gtk::Clipboard> clipboard = Gtk::Clipboard::get();
    assert(clipboard);

    sbuffer->erase_selection();
    sourceView->scroll_to(sbuffer->get_insert(), 0.02); //  0.02 == GEDIT_VIEW_SCROLL_MARGIN
}


void EditorWindowImpl::on_about_activate() {
    aboutDialog->run();
    aboutDialog->hide();
}


void EditorWindowImpl::on_run_activate() {
    runMona(false);
}


void EditorWindowImpl::on_runopt_activate() {
    runMona(true);
}


void EditorWindowImpl::appendMonaStatusMessages() {
    if (!monaRun) {
        assert(false);
        return;
    }

    int i = 0;
    BOOST_FOREACH(const StatusMsg &smsg, monaRun->messages) {
        Gtk::TreeModel::Row newRow = *(errorViewStore->append());
        newRow[errorViewColumns.typeColumn] = "Error";
        newRow[errorViewColumns.offsetColumn] = smsg.pos;
        newRow[errorViewColumns.lineColumn] = smsg.line;
        newRow[errorViewColumns.columnColumn] = smsg.column;
        newRow[errorViewColumns.msgColumn] = smsg.msg;
        int id = i;
        i += 1;
        newRow[errorViewColumns.idColumn] = id;

        if (smsg.pos >= 0) {
            Gtk::TextIter iterStart = sourceBuffer()->get_iter_at_offset(smsg.pos);
            sourceBuffer()->create_source_mark(ustring() + "StatusMsg_" + boost::lexical_cast<string>(id) + "_Start", "StatusMsg", iterStart);
            iterStart.forward_chars(smsg.length);
            Gtk::TextIter iterEnd = iterStart;
            sourceBuffer()->create_source_mark(ustring() + "StatusMsg_" + boost::lexical_cast<string>(id) + "_End", "StatusMsg", iterEnd);
        }
    }
}


void EditorWindowImpl::on_run_fail() {
#ifdef DEBUG
    fprintf(stderr, "Mona failed\n");
#endif
    appendMonaStatusMessages();
    mona_cleanup();
}


void EditorWindowImpl::on_work_done() {
#ifdef DEBUG
    fprintf(stderr, "Mona succeeded\n");
#endif
    if (!monaRun) {
        assert(false);
        return;
    }

    appendMonaStatusMessages();
    ResultWindowPtr resultWin = ResultWindow::create(monaRun, filename);
    resultWin->show();
    mona_cleanup();
}


void EditorWindowImpl::on_undo_activate() {
    Glib::RefPtr<Gsv::SourceBuffer> sbuffer = sourceView->get_source_buffer();
    assert(sbuffer);

    sbuffer->undo();
}


void EditorWindowImpl::on_redo_activate() {
    Glib::RefPtr<Gsv::SourceBuffer> sbuffer = sourceView->get_source_buffer();
    assert(sbuffer);

    sbuffer->redo();
}


void EditorWindowImpl::finetune_decl(Gtk::TextIter &orig_iter) {
    Gtk::TextIter iter = orig_iter;

// Search for newline backwards
    bool backwarded = false;
    while (true) {
        if (iter.starts_line()) {
            // Already a good position
            orig_iter = iter;
            return;
        }

        gunichar c = iter.get_char();
        if (c != ' ' && c != '\t') {
            // Not whitespace, illegal to insert a declaration here
            if (backwarded) {
                iter.forward_char();
            }
            break;
        }

        if (!iter.backward_char()) {
            // Begin of text
            break;
        }
        backwarded = true;
    }

    iter = orig_iter;

    // Search for newline forward
    while (true) {
        if (iter.starts_line()) {
            // good position
            orig_iter = iter;
            return;
        }

        gunichar c = iter.get_char();
        if (c != ' ' && c != '\t' && c != '\n' && c != '\r') {
            // Something else starts here
            // Do not modify input as we have nothing better
            return;
        }

        if (!iter.forward_char()) {
            // End of text
            return;
        }
    }
}

void EditorWindowImpl::on_insertVar0_activate() {
    MonaPtr mona = getMonaCursor();
    if (!mona) {
        return;
    }

    int offset = mona->getPrevDeclarationOffset();
    if (offset < 0) {
        offset = 0; // Insert before everything
    }

    // Fine-tune location, preferably at begin of line
    Gtk::TextIter iter = sourceBuffer()->get_iter_at_offset(offset);
    finetune_decl(iter);
#ifdef DEBUG
    fprintf(stderr, "Insert at offset: %d, (Line %d, column %d)\n", offset, iter.get_line(), iter.get_line_offset());
#endif

    insertCompletion(completionVar0Declaration, iter);
}


void EditorWindowImpl::on_insertVar1_activate() {
    MonaPtr mona = getMonaCursor();
    if (!mona) {
        return;
    }

    int offset = mona->getPrevDeclarationOffset();
    if (offset < 0) {
        offset = 0; // Insert before everything
    }

    Gtk::TextIter iter = sourceBuffer()->get_iter_at_offset(offset);
    finetune_decl(iter);
    insertCompletion(completionVar1Declaration, iter);
}


void EditorWindowImpl::on_insertVar2_activate() {
    MonaPtr mona = getMonaCursor();
    if (!mona) {
        return;
    }

    int offset = mona->getPrevDeclarationOffset();
    if (offset < 0) {
        offset = 0; // Insert before everything
    }

    Gtk::TextIter iter = sourceBuffer()->get_iter_at_offset(offset);
    finetune_decl(iter);
    insertCompletion(completionVar2Declaration, iter);
}


void EditorWindowImpl::on_sourcebuffer_changed() {
    monaCursor.reset();
    monaParsed.reset();
    monaLastObsolete = true;
}


void EditorWindowImpl::requireMona(bool reqCompletion,  bool reqParsed, bool reqLastValid) {
    Gtk::TextIter iter = sourceBuffer()->get_iter_at_mark(sourceBuffer()->get_insert());
    requireMona(reqCompletion, iter, reqParsed, reqLastValid);
}


void EditorWindowImpl::requireMona(bool reqCompletion, const Gtk::TextIter &iter, bool reqParsed, bool reqLastValid) {
    // Check whether the Mona calls we already have are still valid
    int offset = iter.get_offset();

    bool hasMonaCursor = false;
    if (monaCursor) {
        int monaCursorOffset = monaCursor->getCompletionOffset();
        if (monaCursorOffset == offset) {
            hasMonaCursor = true;
        }
    }

    bool updateCompletion = reqCompletion && !hasMonaCursor;
    bool updateParsed = reqParsed && !monaParsed;
    bool updateValid = reqLastValid && (!monaLast || monaLastObsolete);

#ifdef DEBUG
    fprintf(stderr, "Running mona for Offset %d (Line %d Column %d)\n",iter.get_offset(), iter.get_line(), iter.get_line_offset());
#endif

    if (!updateCompletion && !updateParsed && !updateValid) {
        return;    // Nothing to do
    }

    MonaPtr mona = monaCursor;
    if (!mona || updateCompletion) {
        mona = Mona::Create(sourceBuffer()->get_text(), "completion.mona");
        mona->setCompletionOffset(offset);
    }

    if (updateCompletion && !updateParsed && !updateValid) {
        // Invoke Lex & Bison parser only
        mona->run(true, false, false, false, false);
    } else {
        // Also get symbol table
        mona->run(true, true, false, false, false);
    }
    monaCursor = mona;

    if (mona->successfulCheckAst()) {
        monaParsed = mona;
        monaLast = mona;
        monaLastObsolete = false;
    }
}


MonaPtr EditorWindowImpl::getMonaCursor() {
    requireMona(true, false, false);

    if (monaCursor->getCompletionState() >= 0) {
        return monaCursor;
    } else {
        return MonaPtr();
    }
}


MonaPtr EditorWindowImpl::getMonaCursor(const Gtk::TextIter &position) {
    requireMona(true, position, false, false);

    if (monaCursor->getCompletionState() >= 0) {
        return monaCursor;
    } else {
        return MonaPtr();
    }
}


MonaPtr EditorWindowImpl::getMonaParsed() {
    requireMona(false, true, true);
    return monaParsed;
}


MonaPtr EditorWindowImpl::getMonaValid() {
    requireMona(false, false, true);
    return monaLast;
}


MonaPtr EditorWindowImpl::getMonaLast() {
    if (monaLast) {
        return monaLast;
    } else {
        return getMonaParsed();
    }
}


void EditorWindowImpl::on_errorview_row_activated(const Gtk::TreeModel::Path &path, Gtk::TreeViewColumn */*column*/) {
    Gtk::TreeIter iter = errorViewStore->get_iter(path);
    assert(iter);

    const Gtk::TreeRow &row = *iter;
    assert(row);
    int id = row[errorViewColumns.idColumn];
    assert(id >= 0);

    Glib::RefPtr<Gsv::SourceBuffer> buffer = sourceBuffer();
    Glib::RefPtr<Gtk::TextMark> markStart = buffer->get_mark(ustring() + "StatusMsg_" + boost::lexical_cast<string>(id) + "_Start");
    Glib::RefPtr<Gtk::TextMark> markEnd = buffer->get_mark(ustring() + "StatusMsg_" + boost::lexical_cast<string>(id) + "_End");
    if (!markStart) {
        return;
    }

    if (!markEnd) {
        markEnd = markStart;
    }

    Gtk::TextIter iterStart = buffer->get_iter_at_mark(markStart);
    Gtk::TextIter iterEnd = buffer->get_iter_at_mark(markEnd);
    buffer->select_range(iterStart, iterEnd);
}


void EditorWindowImpl::on_mona_outstr() {
    UpdateProgress();
}


bool EditorWindowImpl::on_progress_timeout() {
    UpdateProgress();
    return true;
}


void EditorWindowImpl::mona_instantiate(const ustring &input, const boost::filesystem::path &filename) {
    assert(!monaRun);
    monaRun = Mona::Create(input, filename);

    // Show progress
    progressWin->show();

    // Connect events
    monaRun->work_done.connect(sigc::mem_fun(*this, &EditorWindowImpl::on_work_done));
    monaRun->run_fail.connect(sigc::mem_fun(*this, &EditorWindowImpl::on_run_fail));
    monaRun->outstr.signal_sync.connect(sigc::mem_fun(*this, &EditorWindowImpl::on_mona_outstr));

    assert(!timeout_source);
    timeout_source = Glib::TimeoutSource::create(1000);
    timeout_source->connect(sigc::mem_fun(*this, &EditorWindowImpl::on_progress_timeout));
    timeout_source->attach();
}


void EditorWindowImpl::mona_cleanup() {
    if (!monaRun) {
        // Nothing to do
        return;
    }

    timeout_source.reset();
    progressWin->hide();
    monaRun.reset();
}


void EditorWindowImpl::UpdateProgress() {
    if (!monaRun) {
        return;
    }

    assert(progressWin);

    MonaPhase phase = monaRun->getProgressPhase();
    switch(phase) {
    case phaseInit:  {
        progressWin->setProgress("Initialising... (Phase 0 of 6)", 0, "");
    }
    break;
    case phaseParse: {
        progressWin->setProgress("Parsing... (Phase 1 of 6)", 0, "");
    }
    break;
    case phaseCheckAst: {
        progressWin->setProgress("Type check... (Phase 2 of 6)", 0, "");
    }
    break;
    case phaseCode: {
        int automataInMem;
        double fraction = monaRun->getCodeProgress(automataInMem);
        progressWin->setProgress("Code generation... (Phase 3 of 6)", fraction, boost::lexical_cast<ustring>(automataInMem) + " automata in memory");
    }
    break;
    case phaseOptimize: {
        progressWin->setProgress("Optimization... (Phase 4 of 6)", 0, "");
    }
    break;
    case phaseMakeVariableList: {
        progressWin->setProgress("Make variable list... (Phase 5 of 6)", 0, "");
    }
    break;
    case phaseConstructAutomaton: {
        progressWin->setProgress("Automata construction... (Phase 6 of 6)", 0, "");
    }
    break;
    default: {
        progressWin->setProgress("???", 0, "");
    }
    break;
    }

    progressWin->appendOutstr(monaRun->outstr.pop());
}


void EditorWindowImpl::insertAtPreviousDeclaration(const ustring &str) {
    int offset = -1;

    monaCursor = getMonaCursor();
    if (monaCursor) {
        offset = monaCursor->getPrevDeclarationOffset();
    }

    Glib::RefPtr<Gsv::SourceBuffer> buffer = this->sourceBuffer();
    if (offset >= 0) {
        Gtk::TextIter iter = buffer->get_iter_at_offset(offset);
        buffer->insert(iter, str);
    } else {
        buffer-> insert_at_cursor(str);
    }
}


void EditorWindowImpl::on_import_activate() {
    MonaPtr monaValid = getMonaValid();

    Gtk::FileChooserDialog dialog("Import automaton", Gtk::FILE_CHOOSER_ACTION_OPEN);
    dialog.set_transient_for(*this);
    dialog.add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
    dialog.add_button(Gtk::Stock::OPEN, Gtk::RESPONSE_OK);

    Glib::RefPtr<Gtk::FileFilter> filter_dfa = createFileFilter();
    filter_dfa->set_name("Linear automaton (DFA)");
    filter_dfa->add_pattern("*.dfa");
    if (!monaValid || monaValid->isLinear()) {
        gtk_dialogAddFileFilter(dialog, filter_dfa);
    }

    Glib::RefPtr<Gtk::FileFilter> filter_gta = createFileFilter();
    filter_gta->set_name("Guided tree automaton (GTA)");
    filter_gta->add_pattern("*.gta");
    if (!monaValid || monaValid->isTree()) {
        gtk_dialogAddFileFilter(dialog, filter_gta);
    }

    int result = dialog.run();
    dialog.hide();

    switch (result) {
    case Gtk::RESPONSE_OK: {
        ustring filename = dialog.get_filename();
        Glib::RefPtr<Gio::File> file = Gio::File::create_for_path(filename);

        MonaPtr monaImport = Mona::Create();
        assert(monaImport);

        std::vector<std::pair<std::string, int> > variables;

        const Gtk::FileFilter *selectedFilter = dialog.get_filter();
        if (selectedFilter == filter_dfa.operator->()) {
            monaImport->importDfa(file, variables);
        } else if (selectedFilter == filter_gta.operator->()) {
            monaImport->importGta(file, variables);
        } else {
            throw UnexpectedException("Unknown filter selected");
        }

        typedef std::pair<std::string, int> pairtype;
        std::stringstream ss;
        BOOST_FOREACH(const pairtype &var, variables) {
            ss << "var" << var.second << " " << var.first << ";\n";
        }

        ss << "import(\"" << filename << "\"";
        BOOST_FOREACH(const pairtype &var, variables) {
            ss << ", " << var.first << " -> " << var.first;
        }
        ss << ")";

        insertAtPreviousDeclaration(ss.str());
    }
    break;
    case Gtk::RESPONSE_DELETE_EVENT:
    case Gtk::RESPONSE_CANCEL: {
        // Do nothing
    } break;

    default:
        assert(!"Unexpected dialog return code");
    }
}


void EditorWindowImpl::runMona(bool optimized) {
    if (monaRun) {
        // Mona already evaluating
        fprintf(stderr, "ERR: Mona still active\n");
        return;
    }

    clearErrorMessages();
    progressWin->reset();
    ustring text = sourceBuffer()->get_text();
    ustring msg;

    boost::filesystem::path parse_filename = this->filename;
    if (!parse_filename.has_filename()) {
        parse_filename = boost::filesystem::path("unnamed.mona");
    }

    mona_instantiate(text, parse_filename);
    assert(monaRun);
    monaRun->runThreaded(true, true, true, optimized, true);
}


void EditorWindowImpl::on_showcompletion_activate() {
    SourceView_show_completion(sourceView);
}


void EditorWindowImpl::on_progress_abort() {
    if (monaRun) {
        monaRun->abort();
    }
}

