#ifndef MONACALL_H
#define MONACALL_H
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

#include "global.h"
#include "statusmsg.h"
#include "dispatchstream.h"
#include "front2/symboltable.h"

#include <glibmm.h>
#include <giomm.h>

#include <boost/filesystem.hpp>


enum MonaPhase {
    phaseNdef, // Between some phases
    phaseInit, // Before parsing
    phaseParse,
    phaseCheckAst,
    phaseCode,
    phaseOptimize,
    phaseMakeVariableList,
    phaseConstructAutomaton
};


class Mona;
typedef boost::shared_ptr<Mona> MonaPtr;

class Mona {
public:
    static MonaPtr Create(const ustring &input, const boost::filesystem::path &filename);
    static MonaPtr Create();
    virtual ~Mona() {}

    virtual void run(bool doParse, bool doCheckAst, bool doCodeGeneration, bool doOptimization, bool doWork) = 0;
    virtual void runThreaded(bool doParse, bool doCheckAst, bool doCodeGeneration, bool doOptimization, bool doWork) = 0;
    virtual void importDfa(const Glib::RefPtr<Gio::File>& file, std::vector<std::pair<std::string, int> > &variables) = 0;
    virtual void importGta(const Glib::RefPtr<Gio::File>& file, std::vector<std::pair<std::string, int> > &variables) = 0;

    virtual void abort() = 0;

    std::vector<StatusMsg> messages; //TODO getter
    Glib::Dispatcher work_done; // When all phases have been executed successfully
    Glib::Dispatcher run_successful; // When the selected phases have been executed successully
    Glib::Dispatcher run_fail;

    DispatchStream outstr;

    virtual int getCompletionOffset() = 0;
    virtual void setCompletionOffset(int offset) = 0;
    virtual int getCompletionState() = 0;
    virtual const std::vector<int>& getCompletionStack() = 0;
    virtual int getPrevDeclarationOffset() = 0;
    virtual int getNextDeclarationOffset() = 0;

    virtual bool successfulParse() = 0;
    virtual bool successfulCheckAst() = 0;
    virtual bool successfulCodegen() = 0;

    virtual bool isTree() = 0;
    virtual bool isLinear() = 0;

    virtual int getFormulaCount() = 0;
    virtual ustring getFormulaName(int i) = 0;

    virtual void getOutput(ustring &str) = 0;
    virtual void dumpAst(std::ostream &out, int i) = 0;
    virtual void dumpAssertions(std::ostream &out) = 0 ;
    virtual void dumpPredicatesAndMacros(std::ostream &out) = 0;
    virtual void dumpRestrictions(std::ostream &out) = 0;
    virtual void dumpSymboltable(std::ostream &out) = 0;
    virtual void dumpCode(std::ostream &out, int i) = 0;
    virtual void dumpStatistics(std::ostream &out) = 0;
    virtual void dumpTime(std::ostream &out) = 0;
    virtual ustring getAnalysis(int i) = 0;
    virtual ustring getWholeAutomaton(int i, bool unrestricted) = 0;
    virtual ustring getExternalWholeAutomaton(int i, bool unrestricted) = 0;

    virtual bool isCodegenerationCompleted() = 0;
    virtual SymbolTable *getSymboltable() = 0;

    // Progress report
    virtual MonaPhase getProgressPhase() = 0;
    virtual double getCodeProgress(int &automataInMemory) = 0;
};

#endif // MONACALL_H
