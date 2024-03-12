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
Interface between Mona and MonaGUI
*/

#include "monacall.h"
#include "utils.h"
#include "teestream.h"
#include "statusmsg.h"
#include "replacecout.h"
#include "front2/ast.h"
#include "front2/untyped.h"
#include "front2/monaanalyze.h"
#include "front2/monaexternal.h"
#include "front2/env.h"
#include "front2/predlib.h"
#include "front2/offsets.h"
#include "front2/code.h"
#include "front2/st_dfa.h"
#include "front2/st_gta.h"
#include "front2/timer.h"
#include "front2/lib.h"
#include "front2/printline.h"
#include "front2/checkabort.h"
#include "front2/scanner_h.h"
#include "front2/parser_h.h"

#include <glibmm.h>
#include <giomm.h>

#include <boost/filesystem.hpp>
#include <boost/make_shared.hpp>
#include <boost/scoped_ptr.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/filesystem/fstream.hpp>

#include <vector>
#include <iostream>
#include <sstream>
#include <unistd.h>


// Used by other compilation units; need to save them for ScopedMonaContext
#define SYMBOLTABLE_HASH_SIZE 1019
extern Ident lastPosVar;
extern Ident allPosVar;
SymbolTable symbolTable(0);
CodeTable *codeTable = NULL;
Guide guide;
PredicateLib predicateLib;
Options options;
Offsets offsets;
AutLib lib;
bool regenerate;
int numTypes;
MonaUntypedAST *untypedAST;
extern Guide_Declaration *guide_declaration;

// Used by parser/lexed
extern Deque<FileSource *> source;
extern Deque<const char *> fileNames;
extern int filenumber;

// Import automata lookups
extern BddNode *table;
extern bdd_manager *import_bddm;

extern Timer timer_restrict;
extern Timer timer_negation;
extern Timer timer_product;
extern Timer timer_right_quotient;
extern Timer timer_project;
extern Timer timer_minimization;
extern Timer timer_copy;
extern Timer timer_replace_indices;

extern unsigned num_minimizations;
extern unsigned num_projections;
extern unsigned num_products;
extern unsigned num_copies;
extern unsigned num_replaces;
extern unsigned num_right_quotients;
extern unsigned num_negations;
extern unsigned num_restricts;

extern bool inDefault;
extern bool predMacroEncountered;
extern bool anyUniverses;
extern bool default1;
extern bool default2;

bool errorExit = false; // Flag means that the current computation should be aborted


/**
 Class managing all invocations to Mona
 Mona has lots of static (not member of an object) intermediates, so use only one instance of this actively!
*/
class MonaImpl: public Mona, boost::noncopyable, public boost::enable_shared_from_this<MonaImpl>  {
public:
    MonaImpl(const ustring &input, const boost::filesystem::path &filename);
    MonaImpl();
    virtual ~MonaImpl();
    void addLexError(const char *s, const char *filename, int offset, int line, int column);
    void addYaccError(const char *s, const char *filename, int first_offset, int first_line, int first_column, int last_offset, int last_line, int last_column);
    void addTypeError(String str, Pos &p);
    void addCodeError(String str, Pos &p);

private:
    class ScopedMonaContext;

    void init();

    void run(bool doParse, bool doCheckAst, bool doCodeGeneration, bool doOptimization, bool doWork);
    void runThreaded(bool doParse, bool doCheckAst, bool doCodeGeneration, bool doOptimization, bool doWork);
    void importDfa(const Glib::RefPtr<Gio::File>& file, std::vector<std::pair<std::string, int> > &variables);
    void importGta(const Glib::RefPtr<Gio::File>& file, std::vector<std::pair<std::string, int> > &variables);

    void abort();

    void worker();
    void thread_worker();
    void doWork();

// The actual phases
    bool doParse();
    void doCheckAst();
    void doCodeGeneration();
    void doOptimize();
    void doMakeVariableLists();
    void doConstructAutomaton();
    void doConstructUnrestrictedAutomaton();

    int getCompletionOffset();
    void setCompletionOffset(int offset);
    int getCompletionState();
    const std::vector<int>& getCompletionStack();
    int getPrevDeclarationOffset();
    int getNextDeclarationOffset();

    bool successfulParse();
    bool successfulCheckAst();
    bool successfulCodegen();
    bool isCodegenerationCompleted();

    bool isTree();
    bool isLinear();

    void addStatusMsg(const StatusMsg &smsg);
    void addMessage(const ustring &msg);

    int getFormulaCount();
    ustring getFormulaName(int i);

    void getOutput(ustring &str);
    void dumpAst(std::ostream &out, int i);
    void dumpAssertions(std::ostream &out) ;
    void dumpPredicatesAndMacros(std::ostream &out);
    void dumpRestrictions(std::ostream &out);
    void dumpSymboltable(std::ostream &out);
    void dumpCode(std::ostream &out, int i);
    void dumpStatistics(std::ostream &out);
    void dumpTime(std::ostream &out);
    ustring getAnalysis(int i);
    ustring getWholeAutomaton(int i, bool unrestricted);
    ustring getExternalWholeAutomaton(int i, bool unrestricted);

    SymbolTable *getSymboltable();

    // Save and restore global fields
    void saveGlobals() ;
    void restoreGlobals(bool revive = true);

    // Progress report
    MonaPhase getProgressPhase();
    double getCodeProgress(int &automataInMemory);


    DFA *getDfaByIndex(int i, bool unrestricted);
    GTA *getGtaByIndex(int i, bool unrestricted);

    void writeParseFile();
    void deleteParsefile();


    Glib::Thread *thread;

    // Properties from ctor
    ustring input;
    boost::filesystem::path filename;
    boost::filesystem::path parse_file; // temporary for parsing

    // Phases statuses
    int completionOffset;
    int completionState;
    std::vector<int> completionStack;
    YYLTYPE completionPrevDeclaration;
    YYLTYPE completionNextDeclaration;
    bool parseOk;

    bool checkAstOk;
    bool codeGenOk;

    MonaAST *ast;
    VarCode formulaCode;
    Deque<VarCode> verifyCode;

    IdentList sign;
    IdentList freeVars;
    char **vnames;
    char *types ;
    Deque<char *> *verifytitlelist; // = ast->verifytitlelist.copy()
    unsigned *offs;
    SSSet *statespaces;
    int **univs;
    int *trees;

    DFA *dfa;
    Deque<DFA *> dfalist;
    GTA *gta;
    Deque<GTA *> gtalist;

    DFA *dfa2;
    GTA *gta2;
    Deque<DFA *> *dfalist2;
    Deque<GTA *> *gtalist2;

    // saved globals
    int contextCounter;
    SymbolTable *_symboltable;
    Ident _lastPosVar;
    Ident _allPosVar;
    CodeTable *_codeTable;
    Guide *_guide;
    PredicateLib *_predicateLib;
    Options _options;
    Offsets *_offsets;
    AutLib *_lib;
    bool _regenerate;
    int _numTypes;
    MonaUntypedAST *_untypedAST;
    Guide_Declaration *_guide_declaration;
    gtaType *_treetypes ;
    int _num_types ;
    int _gta_in_mem;
    int _max_gta_in_mem;
    int _dfa_in_mem;
    int _max_dfa_in_mem;

    Deque<FileSource *> *_source;
    Deque<const char *> *_fileNames;
    int _filenumber;

    BddNode *_table;
    bdd_manager *_import_bddm;

    Timer _timer_restrict;
    Timer _timer_negation;
    Timer _timer_product;
    Timer _timer_right_quotient;
    Timer _timer_project;
    Timer _timer_minimization;
    Timer _timer_copy;
    Timer _timer_replace_indices;

    unsigned _num_minimizations;
    unsigned _num_projections;
    unsigned _num_products;
    unsigned _num_copies;
    unsigned _num_replaces;
    unsigned _num_right_quotients;
    unsigned _num_negations;
    unsigned _num_restricts;

    bool _inDefault;
    bool _predMacroEncountered;
    bool _anyUniverses;
    bool _default1;
    bool _default2;

    bool _errorExit;

    bool toBeDestroyed;
#if DEBUG
    int myNr;
#endif

    // So the worker(_thread) knows which phases is should execute
    bool thread_doParse;
    bool thread_doCheckAst;
    bool thread_doCodeGeneration;
    bool thread_doOptimization;
    bool thread_doWork;

    // The pahses which have already been executed
    bool didParse;
    bool didCheckAst;
    bool didCodeGeneration;
    bool didOptimization;
    bool didWork; // All of them

    bool workError;
    MonaPhase currentPhase;
    MonaPhase completedPhase;

    // Measuring the execution time of the phases
    Timer timerParser;
    Timer timerCheckAst;
    Timer timerCode;
    Timer timerOptimize;
    Timer timerMakeVariableList;
    Timer timerContructAutomaton;

    // For grabbing Mona's cout output
    teestream *outredirect;
    std::stringstream outcpy;
};


/**
RAII class that manages the global fields used by Mona,
i.e. it sets the global fields to the ones to the MonaImpl instance and saves them when leaving the scope
also, ut uses a Mutex to ensure no other MonaImpl overwrites the global fields
*/
class MonaImpl::ScopedMonaContext : boost::noncopyable {
public:
    ScopedMonaContext(MonaImpl *owner);
    ~ScopedMonaContext();

private:
    MonaImpl *owner;
};


static Glib::StaticMutex mona_global_lock = GLIBMM_STATIC_MUTEX_INIT ; // Only one thread at a time may use mona functions, since many structures are static
static boost::shared_ptr<MonaImpl> g_global_mona; // The instance of mona which is currently running


// To be called from extern
void lex_yyerror(const char *s, const char *filename, int offset, int line, int column) {
    assert(g_global_mona);
    if (!g_global_mona) {
        fprintf(stderr, "%s\n", s);
        return;
    }

    g_global_mona->addLexError(s, filename, offset, line, column);
}


// To be called from extern
void yacc_yyerror(const char *s, const char *filename, int first_offset, int first_line, int first_column, int last_offset, int last_line, int last_column) {
    assert(g_global_mona);
    if (!g_global_mona) {
        fprintf(stderr, "%s\n", s);
        return;
    }

    g_global_mona->addYaccError(s, filename, first_offset, first_line, first_column, last_offset, last_line, last_column);
}


// To be called from external
void TypeError(String str, Pos &p) {
#ifdef DEBUG
    p.printsource();
    std::cerr << str << std::endl;
#endif

    assert(g_global_mona);
    if (!g_global_mona) {
        std::cerr << str << std::endl;
        return;
    }

    g_global_mona->addTypeError(str, p);
    throw TypeException(str, p);
}


// To be called from extern
void codeError(String &str, Pos &p) {
#ifdef DEBUG
    p.printsource();
    std::cerr << str << std::endl;
#endif

    assert(g_global_mona);
    if (!g_global_mona) {
        std::cerr << str << std::endl;
        return;
    }

    g_global_mona->addCodeError(str, p);
}


// Mona ///////////////////////////////////////////////////////////////////////

MonaPtr Mona::Create(const ustring &input, const boost::filesystem::path &filename) {
    boost::shared_ptr<MonaImpl> instance = boost::make_shared<MonaImpl>(input, filename);
    return instance;
}


MonaPtr Mona::Create() {
    boost::shared_ptr<MonaImpl> instance = boost::make_shared<MonaImpl>();
    return instance;
}


// MonaImpl::ScopedMonaContext //////////////////////////////////////////////////////

MonaImpl::ScopedMonaContext::ScopedMonaContext(MonaImpl *owner) {
    assert(owner);
    this->owner = owner;
    assert(owner->contextCounter >= 0);
    if (owner->contextCounter == 0) {
        mona_global_lock.lock();
        owner->restoreGlobals();
    }
    owner->contextCounter += 1;
}


MonaImpl::ScopedMonaContext::~ScopedMonaContext() {
    if (!owner) {
        return;
    }
    assert(owner->contextCounter > 0);
    owner->contextCounter -= 1;
    if (owner->contextCounter == 0) {
        owner->saveGlobals();
        mona_global_lock.unlock();
    }
}


// MonaImpl ///////////////////////////////////////////////////////////////////

MonaImpl::MonaImpl(const ustring &input, const boost::filesystem::path &filename):
    input(input), filename(filename),  _symboltable(0) {
    // ctor
    init();
}


/**
  Use this constructor if there is no file to be processed,
  but some functions need to be executed in a clean Mona context,
  at the moment, this is the case only for importDfa and importGta
*/
MonaImpl::MonaImpl():
    _symboltable(0) {
    // ctor
    init();
}


#ifdef DEBUG
static int monaNr = 0;
static int monaNum = 0;
#endif

void MonaImpl::init() {
    thread = NULL;
    toBeDestroyed = false;
#ifdef DEBUG
    myNr = monaNr;
    monaNum += 1;
    monaNr += 1;
    fprintf(stderr, "Created MONA %d (of now %d)\n", myNr, monaNum);
    print_stacktrace();
#endif

    untypedAST = NULL;
    parseOk = false;
    checkAstOk = false;
    codeGenOk =  false;
    ast = NULL;
    vnames = NULL;
    types = NULL;
    verifytitlelist = NULL;
    offs = NULL;
    statespaces = NULL;
    univs = NULL;
    trees = NULL;
    dfa = NULL;
    gta = NULL;
    dfa2 = NULL;
    gta2 = NULL;
    dfalist2 = NULL;
    gtalist2 = NULL;

    contextCounter = 0;
    _symboltable = NULL;
    _lastPosVar = 0;
    _allPosVar = 0;
    _codeTable = NULL;
    _guide = NULL;
    _predicateLib = NULL;
    _offsets = NULL;
    _lib = NULL;
    _regenerate = false;
    _numTypes = 0;
    _untypedAST = NULL;
    _guide_declaration = NULL;
    _treetypes= NULL ;
    _num_types = 0;
    _gta_in_mem = 0;
    _max_gta_in_mem = 0;
    _dfa_in_mem = 0;
    _max_dfa_in_mem = 0;

    _source = NULL;
    _fileNames = NULL;
    _filenumber = 0;

    _table = NULL;
    _import_bddm = NULL;

    _num_minimizations=0;
    _num_projections=0;
    _num_products=0;
    _num_copies=0;
    _num_replaces=0;
    _num_right_quotients=0;
    _num_negations=0;
    _num_restricts=0;

    _inDefault = false;
    _predMacroEncountered = false;
    _anyUniverses = false;
    _default1 = false;
    _default2 = false;

    _errorExit = false;

    completionOffset = -1;
    completionState = -2;
    completionPrevDeclaration.filename = NULL;
    completionNextDeclaration.filename = NULL;
    workError = false;
    didParse = false;
    didCheckAst = false;
    didCodeGeneration = false;
    didOptimization = false;
    didWork = false;
    currentPhase = phaseInit;
    completedPhase = phaseInit;

    outredirect = new teestream(outstr, outcpy);

    // Default options for MonaGUI are a bit different than for Mona
    _options.statistics = true;
    _options.intermediate = true;
    _options.printProgress = false; // Handled differently in MonaGUI
    _options.time = true;
}


MonaImpl::~MonaImpl() {
    // dtor
    Glib::Mutex::Lock lock(mona_global_lock);
    restoreGlobals(false);

    delete untypedAST;

    if (dfa2 && dfa2 != dfa) {
        dfaFree(dfa2);
        dfa2 = NULL;
        for (Deque<DFA *>::iterator i = dfalist2->begin(); i != dfalist2->end(); i++) {
            dfaFree(*i);
        }
        delete dfalist2;
        dfalist2 = NULL;
    }
    if (dfa) {
        dfaFree(dfa);
        dfa = NULL;
    }
    for (Deque<DFA *>::iterator i = dfalist.begin(); i != dfalist.end(); i++) {
        dfaFree(*i);
    }
    dfalist.reset();

    if (gta2 && gta2 != gta) {
        gtaFree(gta2);
        gta2 = NULL;
        for (Deque<GTA *>::iterator i = gtalist2->begin(); i != gtalist2->end(); i++) {
            gtaFree(*i);
        }
        delete gtalist2;
        gtalist2 = NULL;
    }
    if (gta) {
        gtaFree(gta);
        gta = NULL;
    }
    for (Deque<GTA *>::iterator i = gtalist.begin(); i != gtalist.end(); i++) {
        gtaFree(*i);
    }
    gtalist.reset();
    freeGuide();

    delete verifytitlelist;
    verifytitlelist = NULL;

    if (ast) {
        int numVars = ast->globals.size();
        for (int ix = 0; ix < numVars; ix++) {
            if (univs) {
                delete[] univs[ix];
                univs[ix] = NULL;
            }
            if (statespaces) {
                mem_free(statespaces[ix]);
                statespaces[ix] = NULL;
            }
        }
        delete ast;
        ast = NULL;
    }

    delete[] statespaces;
    statespaces = NULL;
    delete[] vnames;
    vnames = NULL;
    delete[] offs;
    offs = NULL;
    delete[] types;
    types = NULL;
    delete[] univs;
    univs = NULL;

    if (trees) {
        delete[] trees;
        trees = NULL;
        freeTreetypes();
    }

    for (Deque<FileSource *>::iterator i = source.begin(); i != source.end(); i++) {
        delete *i;
    }
    source.reset();
    filenumber = 0;

    formulaCode.remove();

    delete codeTable;
    codeTable = NULL;

    delete outredirect;
    outredirect = NULL;

    // Use fewer memory when Mona is not active
    symbolTable.~SymbolTable();
    zero(symbolTable);
    new (&symbolTable) SymbolTable(0);

#ifdef DEBUG
    monaNum -= 1;
    fprintf(stderr, "Destroyed MONA %d (of now %d)\n", myNr, monaNum);
    print_stacktrace();
#endif
}


void MonaImpl::run(bool doParse, bool doCheckAst, bool doCodeGeneration, bool doOptimization, bool doWork) {
    thread_doParse = doParse;
    thread_doCheckAst = doCheckAst;
    thread_doCodeGeneration = doCodeGeneration;
    thread_doOptimization = doOptimization;
    thread_doWork = doWork;
    options.optimize = thread_doOptimization;
    worker();
}


void MonaImpl::runThreaded(bool doParse, bool doCheckAst, bool doCodeGeneration, bool doOptimization, bool doWork) {
    assert(!thread);
    thread_doParse = doParse;
    thread_doCheckAst = doCheckAst;
    thread_doCodeGeneration = doCodeGeneration;
    thread_doOptimization = doOptimization;
    thread_doWork = doWork;
    options.optimize = thread_doOptimization;
    thread = Glib::Thread::create(sigc::mem_fun0(this, &MonaImpl::thread_worker), true);
}


void MonaImpl::addStatusMsg(const StatusMsg &smsg) {
    messages.push_back(smsg);
}


void MonaImpl::addMessage(const ustring &msg) {
    StatusMsg statmsg(msg);
    addStatusMsg(statmsg);
}


void MonaImpl::addLexError(const char *s, const char *filename, int offset, int line, int column) {
    StatusMsg msg(s);
    if (!filename) {
        filename = "";
    }
    msg.filename = filename;
    msg.pos = offset;
    msg.line = line;
    msg.column = column;
    msg.length = 0;
    addStatusMsg(msg);
}


void MonaImpl::addYaccError(const char *s, const char *filename, int first_offset, int /*first_line*/, int /*first_column*/, int last_offset, int last_line, int last_column) {
    StatusMsg msg(s);
    if (!filename) {
        filename = "";
    }
    msg.filename = filename;
    msg.pos = last_offset;
    msg.line = last_line;
    msg.column = last_column;
    msg.length = first_offset - last_offset;
    assert(msg.length <= 0);
    addStatusMsg(msg);
}


void MonaImpl::addTypeError(String str, Pos &p) {
    ustring ustr(str);
    StatusMsg msg(ustr);
    if (p.fileName) {
        msg.filename = p.fileName;
    } else {
        msg.filename = "";
    }
    msg.pos = p.last_offset;
    msg.line = p.line;
    msg.column = p.col;
    msg.length = p.first_offset - p.last_offset;
    assert(msg.length <= 0);
    addStatusMsg(msg);
}


void MonaImpl::addCodeError(String str, Pos &p) {
    ustring ustr(str);
    StatusMsg msg(ustr);
    if (p.fileName) {
        msg.filename = p.fileName;
    } else {
        msg.filename = "";
    }
    msg.pos = p.last_offset;
    msg.line = p.line;
    msg.column = p.col;
    msg.length = p.first_offset - p.last_offset;
    assert(msg.length <= 0);
    addStatusMsg(msg);
}


void MonaImpl::worker() {
    ScopedMonaContext monaScope(this);

    try {
        doWork();
    } catch(...) {
#ifdef DEBUG
        printf("Exception in worker thread");
#endif
        workError = true;
    }

    thread = NULL;
    if (errorExit) {
        // user abort
        addMessage("Run aborted");
        errorExit = false;
        workError = true;
        run_fail();
    } else if (workError) {
        addMessage("Run unsuccessful");
        run_fail();
    } else {
        run_successful();
    }
}


void MonaImpl::thread_worker() {
    thread->set_priority(Glib::THREAD_PRIORITY_LOW);
    worker();
}


void MonaImpl::doWork() {
    if (workError) {
        // Already failed before, it still won't work
        return;
    }

    ScopedRedirect redirect(std::cout, *outredirect);

    if (!didParse && thread_doParse) {
        // Builds untypedAST
        currentPhase = phaseParse;
        std::cout << "\n== PARSING ==" << std::endl;
#ifdef DEBUG
        yydebug = 1;
#endif
        timerParser.start();
        bool haveAST = doParse();
        timerParser.stop();

        if (!haveAST) {
            workError = true;
            return;
        }

        didParse = true;
        completedPhase = phaseParse;
    }

    checkAbort();

    if (didParse && !didCheckAst && thread_doCheckAst) {
        // Requires untypedAST
        // Builds this->ast
        currentPhase = phaseCheckAst;
        std::cout << "\n== TYPE CHECKING ==" << std::endl;
        timerCheckAst.start();

        doCheckAst();

        timerCheckAst.stop();
        didCheckAst = true;
        completedPhase = phaseCheckAst;
    }

    checkAbort();

    if (didCheckAst && !didCodeGeneration && thread_doCodeGeneration) {
        // Requires this->ast
        // Builds this->formulaCode, this->verifyCode, codeTable, symboltable
        currentPhase = phaseCode;
        std::cout << "\n== CODE GENERATION ==" << std::endl;
        timerCode.start();

        doCodeGeneration();

        didCodeGeneration = true;
        timerCode.stop();
        completedPhase = phaseCode;
    }

    checkAbort();

    if (didCodeGeneration && !didOptimization && thread_doOptimization) {
        currentPhase = phaseOptimize;
        timerOptimize.start();
        std::cout << "\n== OPTIMIZATION ==" << std::endl;

        doOptimize();

        completedPhase = phaseOptimize;
        timerOptimize.stop();
        didOptimization = true;
    }

    checkAbort();

    if (didCodeGeneration && !didWork && thread_doWork) {
        // Requires: this->ast, symbolTable
        currentPhase = phaseMakeVariableList;
        std::cout << "\n== MAKE VARIABLE LIST ==" << std::endl;
        timerMakeVariableList.start();
        doMakeVariableLists();
        timerMakeVariableList.stop();
        completedPhase = phaseMakeVariableList;

        checkAbort();

        // This is the main work, may take a long time
        // Requires: this->formulaCode, codeTable?, ast?
        currentPhase = phaseConstructAutomaton;
        std::cout << "\n== AUTOMATA CONSTRUCTION ==" << std::endl;
        timerContructAutomaton.start();
        doConstructAutomaton();

        checkAbort();

        // optional
        std::cout << "\n== AUTOMATA CONSTRUCTION (unrestricted) ==" << std::endl;
        doConstructUnrestrictedAutomaton();
        completedPhase = phaseConstructAutomaton;
        timerContructAutomaton.stop();

        didWork = true;
        std::cout << "\n== FINISHED ==" << std::endl;
        work_done();
    }
}


void MonaImpl::writeParseFile() {
    assert(parse_file.file_string().empty());

    int num = 0;
    while (true) {
        num += 1;
        parse_file = boost::filesystem::path("/tmp/monagui"); // TODO: not portable
        parse_file  /= boost::lexical_cast<std::string>(num);
        if (boost::filesystem::exists(parse_file)) {
            continue;
        }
        boost::filesystem::create_directories(parse_file);
        break;
    }

    parse_file /= filename.filename();
    boost::filesystem::ofstream tempfilestream(parse_file);

    tempfilestream << input;
    tempfilestream.flush();
    tempfilestream.close();
}


void MonaImpl::deleteParsefile() {
    Glib::RefPtr<Gio::File> parsefile = Gio::File::create_for_path(parse_file.file_string()); //TODO: create_for_path possibly leaks memory
    Glib::RefPtr<Gio::File> parsedir = parsefile->get_parent();
    Glib::RefPtr<Gio::File> tmpworkpdir = parsedir->get_parent();
    parsefile->remove();
    if (!parsedir->enumerate_children()->next_file()) {
        parsedir->remove();
    }
    if (!tmpworkpdir->enumerate_children()->next_file()) {
        tmpworkpdir->remove();
    }
    parse_file.clear();
}


bool MonaImpl::doParse() {
    monagui_reset_lexer();
    writeParseFile(); //TODO: RAII

    const char *filename = parse_file.file_string().c_str();
    if (completionOffset >= 0) {
        g_yyHookCompletion = true;
        g_yyCompletionLoc.filename = filename;
        g_yyCompletionLoc.first_offset = completionOffset;
        g_yyCompletionLoc.last_offset = completionOffset;
        g_yyCompletionState = -2;
        g_yyPrevDeclaration.filename = NULL;
        g_yyNextDeclaration.filename = NULL;
        g_yyPrevDeclaration.first_offset = -1;
        g_yyPrevDeclaration.last_offset = -1;
        g_yyNextDeclaration.first_offset = -1;
        g_yyNextDeclaration.last_offset = -1;
        g_yyAfterCompletion = false;
    } else {
        g_yyHookCompletion = false;
    }

    loadFile(filename);
    int retval = yyparse(); // Parse!
    parseOk = !retval;

    if (completionOffset >= 0) {
        completionState = g_yyCompletionState;
        completionStack = g_yyCompletionStack;
        completionPrevDeclaration = g_yyPrevDeclaration;
        completionNextDeclaration = g_yyNextDeclaration;
    }

    deleteParsefile();
    return parseOk;
}


int MonaImpl::getCompletionOffset() {
    return completionOffset;
}


void MonaImpl::setCompletionOffset(int offset) {
    completionOffset = offset;
}


int MonaImpl::getCompletionState() {
    return completionState;
}


const std::vector<int>& MonaImpl::getCompletionStack() {
    return completionStack;
}


int MonaImpl::getPrevDeclarationOffset()  {
    if (completionPrevDeclaration.filename == NULL) {
        return -1;
    }
    return completionPrevDeclaration.first_offset;
}


int MonaImpl::getNextDeclarationOffset()  {
    if (completionNextDeclaration.filename == NULL) {
        return -1;
    }
    return completionNextDeclaration.first_offset;
}


bool MonaImpl::successfulParse() {
    return this->parseOk;
}


bool MonaImpl::successfulCheckAst() {
    return this->checkAstOk;
}


bool MonaImpl::successfulCodegen() {
    return this->codeGenOk;
}


void MonaImpl::doCheckAst() {
    assert(!ast);
    ast = untypedAST->typeCheck();
    lastPosVar = ast->lastPosVar;
    allPosVar = ast->allPosVar;
    checkAstOk = true;
}


void MonaImpl::doCodeGeneration() {
    // Generate code
    assert(!codeTable);
    codeTable = new CodeTable();
    formulaCode = ast->formula->makeCode();
    VarCode assertionCode = ast->assertion->makeCode();
    /* #warning NEW: 'VERIFY' */
    verifyCode.reset();
    for (Deque<ASTForm *>::iterator i = ast->verifyformlist.begin(); i != ast->verifyformlist.end(); i++) {
        verifyCode.push_back((*i)->makeCode());
    }

    // Implicitly assert restrictions for all global variables
    for (IdentList::iterator i = ast->globals.begin(); i != ast->globals.end(); i++) {
        assertionCode = andList(assertionCode, getRestriction(*i, NULL));
    }

    // Restrict assertion if not trivial
    if (assertionCode.code->kind != cTrue)  {
        assertionCode = codeTable->insert(new Code_Restrict(assertionCode, assertionCode.code->pos));
    }

    // Add assertion to main formula and to all verify formulas
    for (Deque<VarCode>::iterator i = verifyCode.begin(); i != verifyCode.end(); i++) {
        assertionCode.code->refs++;
        *i = andList(*i, VarCode(copy(assertionCode.vars), assertionCode.code));
    }
    formulaCode = andList(formulaCode, assertionCode);

    codeGenOk = true;
}


void MonaImpl::doOptimize() {
    // Reduce
    formulaCode.reduceAll(&verifyCode);
}


void MonaImpl::doMakeVariableLists() {
    // Make variable lists
    verifytitlelist = ast->verifytitlelist.copy();
    if (lastPosVar != -1) {
        ast->globals.remove(lastPosVar);
    }
    if (allPosVar != -1) {
        ast->globals.remove(allPosVar);
    }
    ast->globals.sort(); // sort by id (= index)
    int numVars = ast->globals.size();
    int ix = 0;
    vnames = new char*[numVars];
    offs = new unsigned[numVars];
    types = new char[numVars];
    univs = new int*[numVars];
    trees = new int[numVars];
    statespaces = new SSSet[numVars];
    IdentList::iterator id;
    for (id = ast->globals.begin(); id != ast->globals.end(); id++, ix++) {
        statespaces[ix] = stateSpaces(*id);
        vnames[ix] = symbolTable.lookupSymbol(*id);
        offs[ix] = offsets.off(*id);
        sign.push_back(ix);
        freeVars.push_back(*id);
        switch (symbolTable.lookupType(*id)) {
        case VarnameTree:
            trees[ix] = 1;
            break;
        default:
            trees[ix] = 0;
        }
        IdentList *uu = symbolTable.lookupUnivs(*id);
        if (uu) {
            unsigned j;
            univs[ix] = new int[uu->size()+1];
            for (j = 0; j < uu->size(); j++) {
                univs[ix][j] = symbolTable.lookupUnivNumber(uu->get(j));
            }
            univs[ix][j] = -1;
        } else {
            univs[ix] = 0;
        }
        switch (symbolTable.lookupType(*id)) {
        case Varname0:
            types[ix] = 0;
            break;
        case Varname1:
            types[ix] = 1;
            break;
        default:
            types[ix] = 2;
            break;
        }
    }
}


void MonaImpl::doConstructAutomaton() {
    dfa = 0;
    gta = 0;

    // Initialize
    bdd_init();
    codeTable->init_print_progress();

    if (options.mode != TREE) {
        // Generate DFAs
        dfa = formulaCode.DFATranslate();
        if (lastPosVar != -1) {
            dfa = st_dfa_lastpos(dfa, lastPosVar);
        }
        if (allPosVar != -1) {
            dfa = st_dfa_allpos(dfa, allPosVar);
        }
        for (Deque<VarCode>::iterator i = verifyCode.begin();
                i != verifyCode.end(); i++) {
            DFA *d = (*i).DFATranslate();
            if (lastPosVar != -1) {
                d = st_dfa_lastpos(d, lastPosVar);
            }
            if (allPosVar != -1) {
                d = st_dfa_allpos(d, allPosVar);
            }
            dfalist.push_back(d);
        }
    } else {
        // Generate GTAs
        gta = formulaCode.GTATranslate();
        if (allPosVar != -1) {
            gta = st_gta_allpos(gta, allPosVar);
        }
        for (Deque<VarCode>::iterator i = verifyCode.begin();
                i != verifyCode.end(); i++) {
            GTA *g = (*i).GTATranslate();
            if (allPosVar != -1) {
                g = st_gta_allpos(g, allPosVar);
            }
            gtalist.push_back(g);
        }
    }
}


/**
    Create unristricted automata (without "don't care") dfa2,gta2,... from normal automata dfa, gta, ...
*/
void MonaImpl::doConstructUnrestrictedAutomaton() {
    // Unrestrict automata
    if (options.mode != TREE) {
        DFA *t = dfaCopy(dfa);
        dfaUnrestrict(t);
        dfa2 = dfaMinimize(t);
        dfaFree(t);
        dfalist2 = new Deque<DFA *>;
        for (Deque<DFA *>::iterator i = dfalist.begin(); i != dfalist.end(); i++) {
            t = dfaCopy(*i);
            dfaUnrestrict(t);
            dfalist2->push_back(dfaMinimize(t));
            dfaFree(t);
        }
    } else {
        GTA *t = gtaCopy(gta);
        gtaUnrestrict(t);
        gta2 = gtaMinimize(t);
        gtaFree(t);
        gtalist2 = new Deque<GTA *>;
        for (Deque<GTA *>::iterator i = gtalist.begin(); i != gtalist.end(); i++) {
            t = gtaCopy(*i);
            gtaUnrestrict(t);
            gtalist2->push_back(gtaMinimize(t));
            gtaFree(t);
        }
    }
}


DFA *MonaImpl::getDfaByIndex(int i, bool unrestricted) {
    assert(i >= -1);

    if (i == -1) {
        return unrestricted ? this->dfa2 : this->dfa;
    } else {
        if (unrestricted) {
            return dfalist2->get(i);
        } else {
            return dfalist.get(i);
        }
    }
}


GTA *MonaImpl::getGtaByIndex(int i, bool unrestricted) {
    assert(i >= -1);

    if (i == -1) {
        return unrestricted ? this->gta2 : this->gta;
    } else {
        if (unrestricted) {
            return gtalist2->get(i);
        } else {
            return gtalist.get(i);
        }
    }
}


ustring MonaImpl::getWholeAutomaton(int i, bool unrestricted) {
    ScopedMonaContext monaScope(this);
    int numVars = ast->globals.size();
    std::ostringstream out;

    if (isLinear()) {
        DFA *printDfa = getDfaByIndex(i, unrestricted);
        mona_dfaPrint(out, printDfa, numVars, vnames, offs);
    } else {
        GTA *printGta = getGtaByIndex(i, unrestricted);
        mona_gtaPrint(out, printGta, offs, numVars, vnames, options.inheritedAcceptance);
    }

    return out.str();
}


ustring MonaImpl::getExternalWholeAutomaton(int i, bool unrestricted) {
    ScopedMonaContext monaScope(this);

    int numVars = ast->globals.size();
    std::ostringstream out;

    if (options.mode != TREE) {
        DFA *exportDfa = getDfaByIndex(i, unrestricted);
        DFA *t = dfaCopy(exportDfa);
        st_dfa_replace_indices(t, &sign, &freeVars, false, true);
        mona_dfaExport(out, t, numVars, vnames, types);
        dfaFree(t);
    } else {
        GTA *exportGta = getGtaByIndex(i, unrestricted);
        GTA *t = gtaCopy(exportGta);
        st_gta_replace_indices(t, &sign, &freeVars, false, true);
        mona_gtaExport(out, t, numVars, vnames, types, statespaces, options.inheritedAcceptance);
        gtaFree(t);
    }
    return out.str();
}


bool MonaImpl::isTree() {
    return !isLinear();
}


bool MonaImpl::isLinear() {
    ScopedMonaContext reserveMona(this);
    return options.mode != TREE;
}


int MonaImpl::getFormulaCount() {
    unsigned result = verifytitlelist->size();
    assert(ast == NULL || result == ast->verifyformlist.size());
    assert(gtalist.empty() || result == gtalist.size());
    return result;
}


ustring MonaImpl::getFormulaName(int i) {
    if (i == -1) {
        return ustring();
    } else {
        return verifytitlelist->get(i);
    }
}


void MonaImpl::getOutput(ustring &str) {
    str = outcpy.str();
}


void MonaImpl::dumpAst(std::ostream &out, int i) {
    assert(i >= -1);
    assert(ast);
    ScopedMonaContext monaScope(this);

    ScopedRedirect redirectCout(std::cout, out);
    ASTForm *formulaToDump;
    if (i == -1) {
        formulaToDump = ast->formula;
    } else {
        formulaToDump = ast->verifyformlist.get(i);
    }
    formulaToDump->dump();
}


void MonaImpl::dumpAssertions(std::ostream &out) {
    assert(ast);
    ScopedMonaContext monaScope(this);

    ScopedRedirect redirectCout(std::cout, out);
    out << "\nAssertions:\n";
    {
        ScopedRedirect redirectCout(std::cout, out);
        ast->assertion->dump();
    }
    out << "\n";

    //TODO: This does not really belong to dumpAssertions
    if (lastPosVar != -1) {
        out << "\nLastPos variable: " << symbolTable.lookupSymbol(lastPosVar) << "\n";
    }
    if (allPosVar != -1) {
        out << "\nAllPos variable: "  << symbolTable.lookupSymbol(allPosVar) << "\n";
    }
}


void MonaImpl::dumpPredicatesAndMacros(std::ostream &out) {
    assert(didCodeGeneration);
    ScopedMonaContext monaScope(this);

    // Dump ASTs for predicates and macros
    PredLibEntry *pred = predicateLib.first();
    while (pred != NULL) {
        if (pred->isMacro) {
            out << "\nMacro '";
        } else {
            out << "\nPredicate '";
        }
        out << symbolTable.lookupSymbol(pred->name) << "':\n";
        {
            ScopedRedirect redirectCout(std::cout, out);
            (pred->ast)->dump();
        }
        out << "\n";
        pred = predicateLib.next();
    }
}


void MonaImpl::dumpRestrictions(std::ostream &out) {
    ScopedMonaContext monaScope(this);

    // Dump restrictions
    if (symbolTable.defaultRestriction1) {
        out << "\nDefault first-order restriction (" << symbolTable.lookupSymbol(symbolTable.defaultIdent1) << "):\n";
        {
            ScopedRedirect redirectCout(std::cout, out);
            symbolTable.defaultRestriction1->dump();
        }
        out << "\n";
    }
    if (symbolTable.defaultRestriction2) {
        std::        cout << "\nDefault second-order restriction (" << symbolTable.lookupSymbol(symbolTable.defaultIdent2) << "):\n";
        {
            ScopedRedirect redirectCout(std::cout, out);
            symbolTable.defaultRestriction2->dump();
        }
        out << "\n";
    }

    Ident id;
    for (id = 0; id < (Ident) symbolTable.noIdents; id++) {
        Ident t;
        ASTForm *f = symbolTable.getRestriction(id, &t);
        if (f) {
            out << "\nRestriction for #" << id << " (" << symbolTable.lookupSymbol(id) << "):";
            if (t != -1) {
                out << " default\n";
            } else {
                out << "\n";
                {
                    ScopedRedirect redirectCout(std::cout, out);
                    f->dump();
                }
                out << "\n";
            }
        }
    }
}


void MonaImpl::dumpSymboltable(std::ostream &out) {
    ScopedMonaContext monaScope(this);
    ScopedRedirect redirectCout(std::cout, out);
    symbolTable.dump();
}


void MonaImpl::dumpCode(std::ostream &out, int i) {
    assert(i >= -1);
    assert(didCodeGeneration);
    ScopedMonaContext monaScope(this);

    VarCode *codeToDump ;
    if (i == -1) {
        codeToDump = &formulaCode;
    } else {
        codeToDump = &verifyCode.get(i);
    }
    {
        ScopedRedirect redirectCout(std::cout, out);
        codeToDump->dump();
    }
}


void MonaImpl::dumpStatistics(std::ostream &out) {
    ScopedMonaContext monaScope(this);
    ScopedRedirect redirectCout(std::cout, out);
    print_statistics();
    if (codeTable) {
        codeTable->print_statistics();
        codeTable->print_statistics2();
    }
}


void  MonaImpl::dumpTime(std::ostream &out) {
    if (didParse) {
        out << "Parsing: " << timerParser << "\n";
    }

    if (didCheckAst) {
        out << "Type check: " << timerCheckAst << "\n";
    }

    if (didCodeGeneration) {
        out << "Code generation: " << timerCode << "\n";
    }

    if (didOptimization) {
        out << "Optimization: " << timerOptimize << "\n";
    }

    if (didWork) {
        out << "Variable list: "<< timerMakeVariableList << "\n";
        out << "Automata construction: "<< timerContructAutomaton << "\n";
    }
}


ustring MonaImpl::getAnalysis(int i) {
    ScopedMonaContext monaScope(this);
    assert(i >= -1);
    int numVars = ast->globals.size();
    std::ostringstream out;

    if (options.mode != TREE) {
        DFA *analysisDfa = getDfaByIndex(i, false);
        if (analysisDfa) {
            mona_dfaAnalyze(out, analysisDfa, numVars, vnames, offs, types, options.treemodeOutput);
        } else {
            out << "Automaton not available";
        }
    } else {
        GTA *analysisGta = getGtaByIndex(i, false);

        if (analysisGta) {
            if (numTypes == 0 || options.treemodeOutput) {
                mona_gtaAnalyze(out, analysisGta, numVars, vnames, offs);
            } else {
                mona_gtaTypeAnalyze(out, analysisGta, numVars, vnames, types, offs, univs, trees);
            }
        } else {
            out << "Automaton not available";
        }
    }

    return out.str();
}


bool MonaImpl::isCodegenerationCompleted()  {
    return didCodeGeneration;
}


SymbolTable *MonaImpl::getSymboltable() {
    assert(didCheckAst);
    return _symboltable;
}


MonaPhase MonaImpl::getProgressPhase() {
    return currentPhase;
}


double MonaImpl::getCodeProgress(int &automataInMemory) {
    // WARNING: Called asynchronously! Beware of race conditions
    CodeTable *codetable = NULL;
    automataInMemory = 0;
    if (g_global_mona.get() == this) {
        codetable = codeTable; // Local copy to avoid race conditions
        automataInMemory = dfa_in_mem + gta_in_mem;
    } else {
        codetable = _codeTable;
        automataInMemory = _dfa_in_mem + _gta_in_mem;
    }

    if (!codetable) {
        return 0;
    }
    if (codetable->total_nodes <= 0) {
        return 0;
    }
    double part = (double)codetable->makes / (double)codetable->total_nodes;
    return part;
}


void MonaImpl::importDfa(const Glib::RefPtr<Gio::File>& file, std::vector<std::pair<std::string, int> > &variables) {
    ScopedMonaContext monaScope(this);

    std::string pfile = file->get_path();
    char **fileVars; // null terminated array of names in index order
    int *fileOrders; // corresponding array of orders
    DFA *dfa = dfaImport(const_cast<char *>(pfile.c_str()), &fileVars, &fileOrders);
    assert(dfa);

    for (int i = 0; fileVars[i]; i++) {
        std::string name(fileVars[i]);
        int order = fileOrders[i];
        std::pair<std::string, int> pair(name, order);
        variables.push_back(pair);
    }

    for (int i = 0; fileVars[i]; i++) {
        mem_free(fileVars[i]);
    }
    mem_free(fileVars);
    mem_free(fileOrders);
}


void MonaImpl::importGta(const Glib::RefPtr<Gio::File>& file, std::vector<std::pair<std::string, int> > &variables) {
    ScopedMonaContext monaScope(this);
    std::string pfile = file->get_path();

    char **fileVars; // null terminated array of names in index order
    int *fileOrders; // corresponding array of orders
    SSSet *fileSS; // corresponding array of state-space sets

    GTA *gta = gtaImport(const_cast<char *>(pfile.c_str()),  &fileVars, &fileOrders, &fileSS, false);
    assert(gta);

    for (int i = 0; fileVars[i]; i++) {
        std::string name(fileVars[i]);
        int order = fileOrders[i];
        std::pair<std::string, int> pair(name, order);
        variables.push_back(pair);
    }

    for (int i = 0; fileVars[i]; i++) {
        mem_free(fileVars[i]);
        mem_free(fileSS[i]);
    }
    mem_free(fileVars);
    mem_free(fileOrders);
    mem_free(fileSS);
}


void MonaImpl::abort() {
    // Warning: this is called concurrently from another thread
    // Beware of race conditions
    if (g_global_mona.get() == this) {
        errorExit = true;
    }
}


void MonaImpl::saveGlobals() {
    if (toBeDestroyed) {
        return;
    }

#ifdef DEBUG
    fprintf(stderr, "saveGlobals\n");
    print_stacktrace();
#endif
    assert(g_global_mona.get() == this);

    //freeSavedGlobals();

    // Why so complicated? Why not just assigning it?
    // It turns out that (at least for SymbolTable) nothing has been implemented properly: ctor, dtor, copy ctor, operator=
    // For instance, ctor requires that its underlying memory has been zeroed
    // We rescue the data between calls and restore it when needed again; this way, SymbolTable has no way of noticing that is has been stored somewhere else in the meanwhile.
    // (Bugfixing SymbolTable would also be possible, we try to do as few modifications to Mona itself as possible)
    assert(!_symboltable);
    _symboltable = cpymalloc(symbolTable);
    zero(symbolTable);
    new (&symbolTable) SymbolTable(0); // To ensure that this field remains valid

    _lastPosVar = lastPosVar;

    _allPosVar = allPosVar;

    _codeTable = codeTable;

    assert(!_guide);
    _guide = cpymalloc(guide);

    assert(!_predicateLib);
    _predicateLib = cpymalloc(predicateLib);
    zero(predicateLib);
    new (&predicateLib) PredicateLib();

    _options = options;
    new (&options) Options();

    assert(!_offsets);
    _offsets = cpymalloc(offsets);
    zero(offsets);
    new (&offsets) Offsets();

    assert(!_lib);
    _lib = cpymalloc(lib);
    zero(lib);
    new (&lib) AutLib();

    _regenerate = regenerate;

    _numTypes = numTypes;

    _untypedAST = untypedAST;

    _guide_declaration = guide_declaration;

    _treetypes = treetypes ;

    _num_types = num_types ;

    _gta_in_mem = gta_in_mem;
    _max_gta_in_mem = max_gta_in_mem;
    _dfa_in_mem = dfa_in_mem;
    _max_dfa_in_mem = max_dfa_in_mem;

    assert(!_source);
    _source = cpymalloc(source);
    zero(source);
    new (&source) Deque<FileSource *>();

    assert(!_fileNames);
    _fileNames = cpymalloc(fileNames);
    zero(fileNames);
    new (&fileNames) Deque<const char *>();

    _filenumber = filenumber;
    filenumber = 0;

    _table = table;
    _import_bddm = import_bddm;

    _timer_restrict = timer_restrict;
    _timer_negation = timer_negation;
    _timer_product = timer_product;
    _timer_right_quotient = timer_right_quotient;
    _timer_project = timer_project;
    _timer_minimization = timer_minimization;
    _timer_copy = timer_copy;
    _timer_replace_indices = timer_replace_indices;

    _num_minimizations = num_minimizations;
    _num_projections = num_projections;
    _num_products = num_products;
    _num_copies = num_copies;
    _num_replaces = num_replaces;
    _num_right_quotients = num_right_quotients;
    _num_negations = num_negations;
    _num_restricts = num_restricts;

    _inDefault = inDefault;
    _predMacroEncountered = predMacroEncountered;
    _anyUniverses = anyUniverses;
    _default1 = default1;
    _default2 = default2;

    _errorExit = errorExit;

    g_global_mona.reset();
}


void MonaImpl::restoreGlobals(bool revive) {
#ifdef DEBUG
    fprintf(stderr, "restoreGlobals\n");
    print_stacktrace();
#endif

    assert(!g_global_mona);
    if (revive) {
        // This action here is not possible in dtor
        g_global_mona = shared_from_this();
    }

    symbolTable.~SymbolTable();
    if (_symboltable) {
        cpyfree(symbolTable, _symboltable);
    } else {
        zero(symbolTable); // SymbolTable's ctor depends on it
        new (&symbolTable) SymbolTable(SYMBOLTABLE_HASH_SIZE);
    }

    lastPosVar = _lastPosVar;

    allPosVar = _allPosVar;

    codeTable = _codeTable;

    guide.~Guide();
    if (_guide) {
        cpyfree(guide, _guide);
    } else {
        zero(guide);
        new (&guide) Guide();
    }

    predicateLib.~PredicateLib();
    if (_predicateLib) {
        cpyfree(predicateLib, _predicateLib);
    } else {
        zero(predicateLib);
        new (&predicateLib) PredicateLib();
    }

    options.~Options();
    options = _options;

    offsets.~Offsets();
    if (_offsets) {
        cpyfree(offsets, _offsets);
    } else {
        zero(offsets);
        new (&offsets) Offsets();
    }

    lib.~AutLib();
    if (_lib) {
        cpyfree(lib, _lib);
    } else {
        zero(lib);
        new (&lib) AutLib();
    }

    regenerate = _regenerate;

    numTypes = _numTypes;

    untypedAST = _untypedAST;

    guide_declaration = _guide_declaration;

    treetypes = _treetypes ;

    num_types = _num_types;

    gta_in_mem = _gta_in_mem;
    max_gta_in_mem = _max_gta_in_mem;
    dfa_in_mem = _dfa_in_mem;
    max_dfa_in_mem = _max_dfa_in_mem;

    for (unsigned i = 0; i < source.size(); i+=1) {
        FileSource *item = source.get(i);
        delete item;
        source.set(i, NULL);
    }
    source.reset();
    source.~Deque<FileSource *>();
    if (_source) {
        cpyfree(source, _source);
    } else {
        zero(source);
        new (&source) Deque<FileSource *>();
    }

    fileNames.~Deque<const char *>();
    if (_fileNames) {
        cpyfree(fileNames, _fileNames);
    } else {
        zero(fileNames);
        new (&fileNames) Deque<const char *>();
    }

    filenumber = _filenumber;
    _filenumber = 0;

    table = _table;
    import_bddm = _import_bddm;

    timer_restrict = _timer_restrict;
    timer_negation = _timer_negation;
    timer_product = _timer_product;
    timer_right_quotient = _timer_right_quotient;
    timer_project = _timer_project;
    timer_minimization = _timer_minimization;
    timer_copy = _timer_copy;
    timer_replace_indices = _timer_replace_indices;

    num_minimizations = _num_minimizations;
    num_projections = _num_projections;
    num_products = _num_products;
    num_copies = _num_copies;
    num_replaces = _num_replaces;
    num_right_quotients = _num_right_quotients;
    num_negations = _num_negations;
    num_restricts = _num_restricts;

    inDefault = _inDefault;
    predMacroEncountered = _predMacroEncountered;
    anyUniverses = _anyUniverses;
    default1 = _default1;
    default2 = _default2;

    errorExit = _errorExit;
}
