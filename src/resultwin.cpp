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
Window showing the result of a Mona run
*/

#include "resultwin.h"
#include "monacall.h"
#include "formulaecolumns.h"
#include "gtkutils.h"
#include "app.h"

#include <gtksourceviewmm.h>
#include <gtkmm.h>

#include <fstream>


class ResultWindowImpl: public ResultWindow {
public:
    ResultWindowImpl(BaseObjectType *cobject, const Glib::RefPtr<Gtk::Builder>& glade);
    virtual ~ResultWindowImpl();

    void init(boost::shared_ptr<ResultWindowImpl> self);
    void set_mona(MonaPtr mona, const boost::filesystem::path &sourcePath);

private:
    void UpdateUi();
    Glib::RefPtr<Gtk::Action> connectAction(const ustring &actionName, void (ResultWindowImpl::*_A_func)());
    Glib::RefPtr<Gtk::ToggleAction> connectToggleAction(const ustring &actionName, void (ResultWindowImpl::*_A_func)())  ;

    Glib::RefPtr<Gsv::SourceBuffer> sourceBuffer();
    int getSelectedFormulaIndex();

    void formulae_row_activated(const Gtk::TreeModel::Path &path, Gtk::TreeViewColumn *column) ;
    void formulae_selection_changed();
#ifdef GTKMM3
    void analysisNotebook_switch_page(Widget *page, int page_num);
#else
    void analysisNotebook_switch_page(GtkNotebookPage *page, int page_num);
#endif
    void on_close_activate();
    void on_unrestricted_toggle();
    void on_exportAutomaton_activate();
    void on_hide_activate();


    Glib::RefPtr<Gtk::Builder> glade;
    boost::shared_ptr<ResultWindowImpl> self; // To avoid getting freed before hisind the window

    // Where to get all the information from
    MonaPtr mona;

    Gtk::TreeView *formulaeView;
    Gtk::Notebook *analysisNotebook;

    FormulaeColumns formulaeViewColumns;
    Glib::RefPtr<Gtk::ListStore> formulaeViewStore;

    Gsv::SourceView *analysisView;
    Gsv::SourceView *automatonView;
    Gsv::SourceView *dumpView;
    Gsv::SourceView *statisticsView;
    Gsv::SourceView *outputView;

    Gtk::Widget *analysisPage;
    Gtk::Widget *automatonPage;
    Gtk::Widget *statisticsPage;
    Gtk::Widget *dumpPage;
    Gtk::Widget *outputPage;

    Glib::RefPtr<Gtk::ToggleAction> unrestrictedAction;
    Gtk::ToggleButton *unrestrictedBtn;

    boost::filesystem::path sourcePath;
    bool goingToBeDestroyed;

    int formerSelectedFormula;
    int formerSelectedAnalysisTab;
    Widget *formerSelectedAnalysisPage;
    bool formerUnrestricted;

    bool statisticsDone;
    bool outputDone;
};


// ResultWindow ///////////////////////////////////////////////////////////////

ResultWindowPtr ResultWindow::create(MonaPtr mona, const boost::filesystem::path &sourcePath) {
    ResultWindowPtr result = ResultWindow::create();
    boost::shared_ptr<ResultWindowImpl> impl = boost::dynamic_pointer_cast<ResultWindowImpl>(result);
    impl->set_mona(mona, sourcePath);
    return result;
}


ResultWindowPtr ResultWindow::create() {
    boost::filesystem::path gladefile = app_lookup_datafile("glade", "result.glade");
    Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create_from_file(gladefile.file_string()); //TODO: Something in here leaks memory (NOTE that "ResultWindowImpl" deltes itself when hiding, maybe the Gtk::Action's are still there)
    assert(builder);

    return createFromBuilder(builder, "ResultWindow");
}


ResultWindowPtr ResultWindow::createFromBuilder(const Glib::RefPtr<Gtk::Builder>& builder, const Glib::ustring &name) {
    ResultWindowImpl *impl = NULL;
    builder->get_widget_derived(name, impl);
    assert(impl);

    boost::shared_ptr<ResultWindowImpl> result(impl);
    if (impl) {
        impl->init(result);
    }
    return result;
}


ResultWindow::ResultWindow(BaseObjectType *cobject, const Glib::RefPtr<Gtk::Builder>& /*glade*/):
    Gtk::Window(cobject) {
}


// ResultWindowImpl ///////////////////////////////////////////////////////////

#ifdef DEBUG
static int countResultWindows = 0;
#endif

ResultWindowImpl::ResultWindowImpl(BaseObjectType *cobject, const Glib::RefPtr<Gtk::Builder>& glade):
    ResultWindow(cobject, glade) {
    //ctor
    this->glade = glade;

#ifdef DEBUG
    countResultWindows++;
    fprintf(stderr, "Resultwindows++: %d\n", countResultWindows);
#endif
}


void ResultWindowImpl::init(boost::shared_ptr<ResultWindowImpl> self) {
    this->self = self;
    goingToBeDestroyed = false;

    getWidgetOrFail(analysisView, glade, "SourceView");
    getWidgetOrFail(automatonView, glade, "AutomatonView");
    getWidgetOrFail(dumpView, glade, "DumpView");
    getWidgetOrFail(statisticsView, glade, "StatisticsView");
    statisticsDone = false;
    getWidgetOrFail(outputView, glade, "OutputView");
    outputDone = false;

    getWidgetOrFail(analysisPage, glade, "AnalysisPage");
    getWidgetOrFail(automatonPage, glade, "AutomatonPage");
    getWidgetOrFail(statisticsPage, glade, "StatisticsPage");
    getWidgetOrFail(dumpPage, glade, "DumpPage");
    getWidgetOrFail(outputPage, glade, "OutputPage");

    this->unrestrictedAction = Glib::RefPtr<Gtk::ToggleAction>::cast_dynamic(glade->get_object("unrestricted"));
    assert(this->unrestrictedAction);

    getWidgetOrFail(formulaeView, glade, "FormulaeView");
    this->formulaeViewStore = Glib::RefPtr<Gtk::ListStore>::cast_dynamic(glade->get_object("FormulaeStore"));
    assert(this->formulaeViewStore);
    getWidgetOrFail(analysisNotebook, glade, "AnalysisNotebook");

    formerSelectedFormula = -2;
    formerSelectedAnalysisTab = -2;
    formerUnrestricted = false;

    Gtk::Button *closeBtn = NULL;
    getWidgetOrFail(closeBtn, glade, "CloseBtn");
    closeBtn->signal_clicked().connect( sigc::mem_fun(*this, &ResultWindowImpl::on_close_activate)) ;

    unrestrictedBtn = NULL;
    getWidgetOrFail(unrestrictedBtn, glade, "UnrestrictedBtn");
    unrestrictedBtn->signal_clicked().connect(sigc::mem_fun(*this, &ResultWindowImpl::on_unrestricted_toggle));

    Gtk::Button *exportBtn = NULL;
    getWidgetOrFail(exportBtn, glade, "ExportBtn");
    exportBtn->signal_clicked().connect(sigc::mem_fun(*this, &ResultWindowImpl::on_exportAutomaton_activate));

    connectAction("close", &ResultWindowImpl::on_close_activate);
    connectAction("exportAutomaton", &ResultWindowImpl::on_exportAutomaton_activate);
    connectToggleAction("unrestricted", &ResultWindowImpl::on_unrestricted_toggle);
    signal_hide().connect(sigc::mem_fun(*this, &ResultWindowImpl::on_hide_activate));

    this->formulaeView->signal_row_activated().connect(sigc::mem_fun2 ( *this, &ResultWindowImpl::formulae_row_activated));
    Glib::RefPtr<Gtk::TreeSelection> formulaSelection = this->formulaeView->get_selection();
    formulaSelection->signal_changed().connect(sigc::mem_fun(*this, &ResultWindowImpl::formulae_selection_changed));

    analysisNotebook->signal_switch_page().connect(sigc::mem_fun2(*this, &ResultWindowImpl::analysisNotebook_switch_page));
}


ResultWindowImpl::~ResultWindowImpl() {
    //dtor
#ifdef DEBUG
    countResultWindows--;
    fprintf(stderr, "Resultwindows--: %d\n", countResultWindows);
#endif
}


Glib::RefPtr<Gtk::ToggleAction> ResultWindowImpl::connectToggleAction(const ustring &actionName, void (ResultWindowImpl::*_A_func)()) {
    Glib::RefPtr<Gtk::ToggleAction> action = Glib::RefPtr<Gtk::ToggleAction>::cast_dynamic(glade->get_object(actionName));
    if (action) {
        action->signal_toggled().connect(sigc::mem_fun(*this, _A_func));
    } else {
        fprintf(stderr, "Warning: No toggleaction named '%s'", actionName.raw().c_str());
    }
    return action;
}


Glib::RefPtr<Gtk::Action> ResultWindowImpl::connectAction(const ustring &actionName, void (ResultWindowImpl::*_A_func)()) {
    Glib::RefPtr<Gtk::Action> action = Glib::RefPtr<Gtk::Action>::cast_dynamic(glade->get_object(actionName));
    if (action) {
        action->signal_activate().connect(sigc::mem_fun(*this, _A_func));
    } else {
        fprintf(stderr, "Warning: No action named '%s'", actionName.raw().c_str());
    }
    return action;
}


void ResultWindowImpl::on_unrestricted_toggle() {
    UpdateUi();
}


void ResultWindowImpl::set_mona(MonaPtr mona, const boost::filesystem::path &sourcePath) {
    this->mona = mona;
    this->sourcePath = sourcePath;

    formulaeViewStore->clear();

    Gtk::TreeModel::Row mainRow = *(formulaeViewStore->append());
    mainRow[formulaeViewColumns.nameColumn] = "Main Formula";
    mainRow[formulaeViewColumns.indexColumn] = -1;

    int n = mona->getFormulaCount();
    for (int i = 0; i < n; i++) {
        Gtk::TreeModel::Row newRow = *(formulaeViewStore->append());
        newRow[formulaeViewColumns.nameColumn] = mona->getFormulaName(i);
        newRow[formulaeViewColumns.indexColumn] = i;
    }

    formerSelectedFormula = -2; // To invalidate current view
    formulaeView->get_selection()->select(mainRow);

    UpdateUi();
}


void ResultWindowImpl::formulae_selection_changed() {
    UpdateUi();
}


int ResultWindowImpl::getSelectedFormulaIndex() {
    Glib::RefPtr<Gtk::TreeSelection> formulaSelection = this->formulaeView->get_selection();
    Gtk::TreeModel::Row row = *formulaSelection->get_selected();
    int selectedFormula = row[formulaeViewColumns.indexColumn];
    assert(selectedFormula >= -1);
    return selectedFormula;
}


void ResultWindowImpl::UpdateUi() {
    if (goingToBeDestroyed) {
        // This should not happen. However, I have no idea why there are still messages pending after the idle event
        return;
    }

    int selectedFormula = getSelectedFormulaIndex();
    assert(selectedFormula >= -1);
    int selectedAnalysisTab =  analysisNotebook->get_current_page();
    assert(selectedAnalysisTab >= 0);
    Widget *selectedAnalysisPage = this->analysisNotebook->get_nth_page(selectedAnalysisTab);
    assert(selectedAnalysisPage);
    assert(unrestrictedBtn);
    bool unrestricted = unrestrictedBtn->get_active();

    if (selectedFormula != formerSelectedFormula
            || selectedAnalysisTab != formerSelectedAnalysisTab
            || selectedAnalysisPage != formerSelectedAnalysisPage
            || formerUnrestricted != unrestricted) {
        formerSelectedFormula = -2;
        formerSelectedAnalysisTab = -2;
        formerSelectedAnalysisPage = NULL;

        if (selectedAnalysisPage == analysisPage) {
            ustring analysisText = mona->getAnalysis(selectedFormula);

            GsvSourceLanguagePtr lang;
            Glib::RefPtr<Gsv::SourceBuffer> sourceBuffer = Gsv::SourceBuffer::create(lang);
            sourceBuffer->set_text(analysisText);
            this->analysisView->set_buffer(sourceBuffer);
        } else if (selectedAnalysisPage == automatonPage) {
            ustring externalAutomatonText = mona->getWholeAutomaton(selectedFormula, unrestricted);
            GsvSourceLanguagePtr lang;
            Glib::RefPtr<Gsv::SourceBuffer> sourceBuffer = Gsv::SourceBuffer::create(lang);
            sourceBuffer->set_text(externalAutomatonText);
            automatonView->set_buffer(sourceBuffer);
        } else  if (selectedAnalysisPage == statisticsPage) {
            if (!statisticsDone) {
                std::ostringstream str;
                str << "All formulas cumulated:\n";
                mona->dumpStatistics(str);
                str << "\n== Evaluation times (All formulas) ==\n";
                mona->dumpTime(str);
                GsvSourceLanguagePtr lang;
                Glib::RefPtr<Gsv::SourceBuffer> sourceBuffer = Gsv::SourceBuffer::create(lang);
                sourceBuffer->set_text(str.str());
                statisticsView->set_buffer(sourceBuffer);
                statisticsDone = true;
            }
        } else if (selectedAnalysisPage == dumpPage) {
            std::ostringstream str;
            str << "Abstract syntax tree:\n";
            mona->dumpAst(str,selectedFormula);
            str << "\n";
            mona->dumpAssertions(str);
            mona->dumpPredicatesAndMacros(str);
            mona->dumpRestrictions(str);
            mona->dumpSymboltable(str);
            str << "\nCode:\n";
            mona->dumpCode(str, selectedFormula);
            GsvSourceLanguagePtr lang;
            Glib::RefPtr<Gsv::SourceBuffer> sourceBuffer = Gsv::SourceBuffer::create(lang);
            sourceBuffer->set_text(str.str());
            dumpView->set_buffer(sourceBuffer);
        } else if (selectedAnalysisPage == outputPage) {
            if (!outputDone) {
                ustring str;
                mona->getOutput(str);

                GsvSourceLanguagePtr lang;
                Glib::RefPtr<Gsv::SourceBuffer> sourceBuffer = Gsv::SourceBuffer::create(lang);
                sourceBuffer->set_text(str);
                outputView->set_buffer(sourceBuffer);
                outputDone = true;
            }
        } else {
            assert(!"Unknown Tab");
        }

        formerSelectedFormula = selectedFormula;
        formerSelectedAnalysisTab = selectedAnalysisTab;
        formerSelectedAnalysisPage = selectedAnalysisPage;
        formerUnrestricted = unrestricted;
    }
}


void ResultWindowImpl::formulae_row_activated(const Gtk::TreeModel::Path &/*path*/, Gtk::TreeViewColumn */*column*/) {
}


#ifdef GTKMM3
void ResultWindowImpl::analysisNotebook_switch_page(Widget */*page*/, int /*page_num*/)
#else
void ResultWindowImpl::analysisNotebook_switch_page(GtkNotebookPage */*page*/, int /*page_num*/)
#endif
{
    UpdateUi();
}


Glib::RefPtr<Gsv::SourceBuffer> ResultWindowImpl::sourceBuffer() {
    Glib::RefPtr<Gsv::SourceBuffer> result = analysisView->get_source_buffer();
    assert(result);
    return result;
}


void ResultWindowImpl::on_close_activate() {
    this->hide();
}


void ResultWindowImpl::on_exportAutomaton_activate() {
    bool isTree = mona->isTree();
    ustring title = isTree ? "Save guided tree automaton (GTA) to" : "Save linear automaton (DFA) to";
    Gtk::FileChooserDialog dialog(title, Gtk::FILE_CHOOSER_ACTION_SAVE);
    dialog.set_transient_for(*this);
    dialog.set_do_overwrite_confirmation(true);

    dialog.add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
    dialog.add_button(Gtk::Stock::SAVE_AS, Gtk::RESPONSE_OK);


    Glib::RefPtr< Gtk::FileFilter >filter_dfa = createFileFilter();
    filter_dfa->set_name("Linear automaton (DFA) external format");
    filter_dfa->add_pattern("*.dfa");

    Glib::RefPtr< Gtk::FileFilter >filter_gta = createFileFilter();
    filter_gta->set_name("Guided tree automaton (GTA) external format");
    filter_gta->add_pattern("*.gta");

    if (!isTree) {
        dialog.add_filter(*(filter_dfa.operator->()));
    } else {
        dialog.add_filter(*(filter_gta.operator->()));
    }

    ustring baseName = "";
    if (! sourcePath.has_filename() ) {
        baseName = sourcePath.stem();
    }
    ustring formulaName = "main";
    if (formerSelectedFormula >= 0) {
        formulaName = mona->getFormulaName(formerSelectedFormula);
    }
    ustring extension = isTree ? "gta": "dfa";
    ustring suggestedFile = baseName + "_" + formulaName + "." + extension;
    if (sourcePath.has_parent_path()) {
        boost::filesystem::path suggestedPath = sourcePath.parent_path();
        suggestedPath /=  suggestedFile;
        suggestedFile = suggestedPath.string();
    }
    dialog.set_current_name(suggestedFile);
    dialog.set_filename(suggestedFile);

    int result = dialog.run();
    switch(result) {
    case(Gtk::RESPONSE_OK): {
        ustring exportText ;
#ifdef GTKMM3
        Glib::RefPtr<const Gtk::FileFilter>  selectedFilter =   dialog.get_filter();
#else
        const Gtk::FileFilter *selectedFilter =  dialog.get_filter();
#endif
        if (selectedFilter == filter_dfa.operator->() || selectedFilter == filter_gta.operator->()) {
            exportText = mona->getExternalWholeAutomaton(formerSelectedFormula, formerUnrestricted);
        } else {
            throw UnexpectedException("Don't know how to handle filter");
        }

        std::string filename = dialog.get_filename();

        std::ofstream fileOut(filename.c_str() , std::ios_base::out | std::ios_base::trunc);
        fileOut << exportText;
        fileOut.close();
        break;
    }
    default: // Cancel
        break;
    }
}


void ResultWindowImpl::on_hide_activate() {
    // Close this window entirely when hidden
    if (!goingToBeDestroyed) {
        goingToBeDestroyed = true;

        sigc::slot<bool, boost::shared_ptr<ResultWindowImpl> > sl =  sigc::ptr_fun(&idle_resetRef<ResultWindowImpl>);
        sigc::slot<bool> slb = sigc::bind(sl, self);
        Glib::signal_idle().connect(slb);

        self.reset(); // Delete circular pointer; There is one left to call the slot. After it has been called, no more pointers are left and this object is going to be destroyed
    }
}
