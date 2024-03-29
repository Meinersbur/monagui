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
This file is a workaround to place code behind the parser.cpp generated by bison
We need the internal tables and some preprocessor definitions to extract some information.
It generates the files activetable.{h,cpp} that contain information required by code completion.
*/

// the parser.cpp is also compiled and linked separately into the main executable. To avoid naming conflicts, we rename the included non-static identifiers
#define yylloc xxlloc
#define check_bits xxcheck_bits
#define yySetLocation xxSetLocation
#define yyerror xxerror
#define g_yyHookCompletion g_xxHookCompletion
#define g_yyCompletionLoc g_xxCompletionLoc
#define g_yyCompletionState g_xxCompletionState
#define g_yyCompletionStack g_xxCompletionStack
#define g_yyPrevDeclaration g_xxPrevDeclaration
#define g_yyNextDeclaration g_xxNextDeclaration
#define g_yyAfterCompletion g_xxAfterCompletion
#define yyUpdateCompletionState xxUpdateCompletionState
#define yydebug xxdebug
#define yychar xxchar
#define yylval xxlval
#define yynerrs xxnerrs
#define yyparse xxparse

#include "parser.cpp"

#undef yylloc
#undef check_bits
#undef yyerror
#undef g_yyHookCompletion
#undef g_yyCompletionLoc
#undef g_yyCompletionState
#undef g_yyCompletionStack
#undef yyUpdateCompletionState
#undef yydebug
#undef yychar
#undef yylval
#undef yynerrs
#undef yyparse

#include "predlib.h"
#include "offsets.h"
#include "lib.h"

#include <boost/foreach.hpp>
#include <boost/unordered_set.hpp>
#include <boost/lexical_cast.hpp>

#include <set>
#include <fstream>


// Needed:
// - tokens that are excepted next (tokName, keywords, ...)
//   - yypact[yystate]
// - To which reductions they may lead (header, declaration, ...)
//   - yyrule
//   - yypact[yystate] = yyn (rule number)
//   - yyrline (line in parser.ypp where rule has been defined)
// - Positions in these productions ($1, $2, ...)
// - What kind of identifier (var0, var1, ...) it is
//   - Only manually possible

// Terminology:
// - symbol          yytype[0,1,2,3..YYNTOKENS-1,YYNTOKENS,YYNTOKENS+1...YYNTOKENS+YYNNTS]
// - rule/reduction  yyrule[0,1..YYNRULES]
// - state           yystate[0,1..YYNSTATES-1] 0=start state
//
// A reduce action is related to three states, in order they are visited
// - When in the _yyReduceActionState_ and the right lookahead symbol follows, the reduction rule is executed
// - yyr2[yyRule] items are popped from the stack
// - The topmost state on the stack is now _yyTopOnStackAfterPop_; Note there can be more than one such state per rule and yyReduceActionState
// - The next state is now _yyGotoState_ (Uniquely determinded by yyGetGoto(yyTopOnStackAfterPop, yyr1[yyRule]))

// Tables:
// - yytname[yytype] -> description
//   (yytype=0 $end, yytype=1 error, yytype=2 undefined, yytype>=3 terminals, yytype=YYNTOKENS $accept, yytype>YYNTOKENS nonterminals)

// - YYTRANSLATE(yychar) -> yytype
//    (yylex() id to bison symbol id)

// - yydefact[yystate] -> yyn
//    (default reductions, yyn=0 error)

// - yydefgoto[yytype - YYNTOKENS] -> yystate
//    (default goto table)

// - yyr1[yyrule] -> yytype (>=YYNTOKENS)
//    (reduction to its nonterminal LHS, yyn=0 error, yyn<=NRULES)

// - yyr2[yyrule] -> n
//     (length of symbols in production RHS)

// - yypact[yystate] -> x
//    (indirect reduce table)
//    == YYPACT_NINF, reduce yydefact[yystate]
//    otherwise, do yytable[x + yytype]

// - yytable[yypact[yystate] + yytype] -> x
//     (action table, yystate=current state, yytype=lookahead symbol)
//     > 0, shift to x=yystate
//     < 0, reduce x=|yyn|
//     = 0, reduce yydefact[yystate]
//     = YYTABLE_NINF, explicit syntax error

// - yycheck[yypact[yystate] + yytype] ->
//    (guard for action table)
//    == yytype, do yytable[yypact[yystate] + yytype]
//    otherwise, do yydefact[yystate]

// - yycheck[yypgoto[yytype - YYNTOKENS] + yystate] ->
//    (guard for goto table)
//    == yystate, do yypgoto[yytype - YYNTOKENS]
//    otherwise, do yydefgoto[yytype - YYNTOKENS]

// - yypgoto[yytype - YYNTOKENS] -> x
//    (goto table)
//    do yystate = x + yystate

// - yyrhs[yyprhs[yyrule] + yyi] -> yytype
//    (right hand symbols, separated by -1)

// - yyrline[yyrule] -> line number in parser.ypp


#define YYTOKEN_FIRST 0 // "$end"
#define YYTOKEN_LEX_FIRST 3 // "tokALL0"
#define YYTOKEN_LEX_LAST (YYNTOKENS-2) // "tokSTRING"
#define YYTOKEN_LAST (YYNTOKENS-1) // "LOW"
#define YYTOKEN_COUNT (YYTOKEN_LAST-YYTOKEN_FIRST+1)
#define YYTOKEN_LEX_COUNT (YYTOKEN_LEX_LAST-YYTOKEN_LEX_FIRST+1)

#define YYNT_FIRST YYNTOKENS // "$accept"
#define YYNT_BISON_FIRST (YYNTOKENS+1) // "start"
#define YYNT_LAST (YYNTOKENS+YYNNTS-1) // "optstring"
#define YYNT_COUNT (YYNT_LAST-YYNT_FIRST+1)

#define YYSTATE_FIRST 0
#define YYSTATE_LAST (YYNSTATES-1)
#define YYSTATE_COUNT (YYSTATE_LAST-YYSTATE_FIRST+1)

#define YYRULE_FIRST 0 // Rule 0 is "$accept : <start-symbol> $end" to augment grammar
#define YYRULE_LAST YYNRULES
#define YYRULE_COUNT (YYRULE_LAST-YYRULE_FIRST+1)

#define YYRULE_MAXLENGTH 10


// Symbols (a symbol here is a n-th token/nonterminal in a rule) that may follow (shifted) at state
static boost::unordered_set<int> symbolActiveAt[YYRULE_COUNT][YYRULE_MAXLENGTH];
static std::set<int64_t> symbolActive[YYSTATE_COUNT];

// Tokens (including nonterminals) that may follow (shifted) at state
static std::set<int> activeTokens[YYSTATE_COUNT];

// Shift predecessors
static boost::unordered_set<int> yyShiftPred[YYSTATE_COUNT];

// Nonterminals that can be "shifted" here after a reduction
static boost::unordered_set<int> yyReachableGotos[YYSTATE_COUNT];

// When a reduction is executed, this tells us <from> which states it can be executed using which <yyRule> and will end up in which <yyTo> state
static boost::unordered_set<int64_t> yyReductions;
static boost::unordered_set<int64_t> yyReductionsByFrom[YYSTATE_COUNT];
static boost::unordered_set<int64_t> yyReductionsByAfterGoto[YYSTATE_COUNT];
static boost::unordered_set<int> yyGotoStateToBaseState[YYSTATE_COUNT];

static int nActiveSymbol = 0;
static int mActiveSymbol = 0;


int findYytnameIndex(const char *tname) {
    for (unsigned i= 0; i < sizeof(yytname)/sizeof(yytname[0]); i+=1) {
        const char *tableStr = yytname[i];
        if (strcmp(tableStr, tname) == 0) {
            return i;
        }
    }
    assert(false && "Cannot find token");
    return -1;
}


static int yyGetGoto(int yyState, int yyNnt) {
    assert(yyState >= YYSTATE_FIRST);
    assert(yyState <= YYSTATE_LAST);
    assert(yyNnt >= YYNT_FIRST);
    assert(yyNnt <= YYNT_LAST);

    // First:
    int pgoto = yypgoto[yyNnt - YYNTOKENS] + yyState;
    if (0 <= pgoto && pgoto <= YYLAST) {
        // index is in valid range

        int check = yycheck[pgoto];
        if (check == yyState) {
            // Index check passed, goto state is in yytable
            int yyFollowState = yytable[pgoto];
            assert(yyFollowState >= YYSTATE_FIRST);
            assert(yyFollowState <= YYSTATE_LAST);
            return yyFollowState;
        } else {
            // Index check failed, use default goto table entry for this state
            // Return default for this state
        }
    } else {
        // Value is out of valid range
        // Return default for this state
    }

    int defaultGoto = yydefgoto[yyNnt - YYNTOKENS];
    assert(defaultGoto >= YYSTATE_FIRST);
    assert(defaultGoto <= YYSTATE_LAST);
    return defaultGoto;
}


// Get the action from bison's tables
// Params:
//   state: 0..YYNSTATES, parser's current state
//   lookahead: 0..YYNTOKENS-1, next token in token stream, bison's token type identifier
// Return value: x
//   x > 0: Push lookahead and state to stack and switch to state x ("Shift x")
//   x < 0: Pop yyr2[-x] symbols from stack, switch state to goto[top state from stack, yyr1[-x]] ("Reduce x")
//   YYTABLE_NINF: Syntax error
static int yyGetAction(int state, int lookahead) {
    assert(state >= 0);
    assert(state < YYNSTATES);
    assert(lookahead >= 0);
    assert(lookahead < YYNTOKENS && "Only terminals here");

    // First: check yypact whether action is independant of the lookahead
    int pact = yypact[state];
    if (YYPACT_NINF < pact && pact <= YYLAST) {
        // Action depending on lookahead symbol
        // pact points to the first item of the relevant segment in yytable
        int idx = pact + lookahead;

        // Check whether idx is within array bounds of yycheck and yytable
        if (0 <= idx && idx < YYLAST) {
            // Second: check yycheck for validity of the entry in yytable
            int check = yycheck[idx];
            if (check == lookahead) {
                // Third: yytable entry is valid
                int table = yytable[idx];
                if (table == 0) {
                    // State 0 is the (augmented) start state to which we never return
                    // Instead, use the default action
                    //   goto DEFAULTACTION;
                } else if (table == YYTABLE_NINF)  {
                    return YYTABLE_NINF; // Just to make it explict
                } else if (table > 0) {
                    // Shift action; to make choice explicit
                    return table;
                } else {
                    assert (table < 0);
                    // Non-default reduce action; just to make it explicit
                    assert(table != - yydefact[state]);
                    return table;
                }
            } else {
                // Nothing special for this lookahead symbol, use default (reduce) action from yydefact table
                // goto DEFAULTACTION;
            }
        } else {
            // Index not in range; we assume an invalid action
            return YYTABLE_NINF;
        }
    } else {
        assert(pact == YYPACT_NINF);
        // Action not dependant on lookahead symbol
        // Will be the reduction from yydefact table
    }

    //  DEFAULTACTION:
    int rule = yydefact[state];
    if (rule == 0) {
        // Error
        return YYTABLE_NINF;
    } else {
        // Reduce rule
        return -rule;
    }
}


static int findRuleProduction(int yyRule) {
    return yyprhs[yyRule];

    int prod = 0;
    int atRule = 1;
    while (atRule != yyRule) {
        if (yyrhs[prod] == -1) {
            atRule += 1;
        }
        prod += 1;
    }
#ifdef DEBUG
    for (int i = prod; i < prod + yyr2[yyRule]; i+=1) {
        assert(yyrhs[i] != -1);
    }
#endif
    return prod;
}


static int findTokenOfSymbol(int yyRule, int yySym) {
    int prod = findRuleProduction(yyRule);
    assert(yySym < yyr2[yyRule]);
    return yyrhs[prod + yySym];
}


static int maxRuleLength() {
    int result = -1;
    for (int yyrule = 0; yyrule <= YYNRULES; yyrule++) {
        int n = yyr2[yyrule];
        if (n > result) {
            result = n;
        }
    }
    return result;
}


static bool addActiveToken(int atState, int yyToken) {
    return activeTokens[atState - YYSTATE_FIRST].insert(yyToken).second;
}


static bool addActiveSymbol(int atState, int yyRule, int yyRuleSym) {
    assert(YYSTATE_FIRST <= atState && atState <= YYSTATE_LAST);
    assert(YYRULE_FIRST <= yyRule && yyRule <= YYRULE_LAST);
    assert(maxRuleLength() <= YYRULE_MAXLENGTH);

    bool succ1 = symbolActive[atState - YYSTATE_FIRST].insert(yyRuleSym | ((int64_t)yyRule << 32)).second;
    bool succ2 = symbolActiveAt[yyRule - YYRULE_FIRST][yyRuleSym].insert(atState).second;
    assert(succ1 == succ2);
    if (succ1 || succ2) {
        addActiveToken(atState, findTokenOfSymbol(yyRule, yyRuleSym));
    }

    return succ1 || succ2;
}


static void buildReversedEdges() {
    int n = 0;
    int m = 0;

    for (int yyState = YYSTATE_FIRST; yyState <= YYSTATE_LAST; yyState++) {
        for (int yyToken = YYTOKEN_LEX_FIRST; yyToken <= YYTOKEN_LEX_LAST; yyToken++) {
            int action = yyGetAction(yyState, yyToken);
            if (action == YYTABLE_NINF) {
                continue;
            }

            if (action > 0) {
                int yyShiftToState = action;
                bool success = yyShiftPred[yyShiftToState - YYSTATE_FIRST].insert(yyState).second;
                n += 1;
                if (success) {
                    m+= 1;
                }
            } else {
                assert(action < 0);
            }
        }
    }

#ifdef DEBUG
    fprintf(stderr, "Number of reversed shift edged: %d/%d\n", m, n);
#endif
}


static int64_t encodeReduction(int yyRule,
                               int yyReduceActionState,
                               int yyTopOnStackAfterPop,
                               int yyAfterGoto) {
    assert(YYRULE_FIRST <= yyRule && yyRule <= YYRULE_LAST);
    assert(YYSTATE_FIRST <= yyReduceActionState && yyReduceActionState <= YYSTATE_LAST);
    assert(YYSTATE_FIRST <= yyTopOnStackAfterPop && yyTopOnStackAfterPop <= YYSTATE_LAST);
    assert(YYSTATE_FIRST <= yyAfterGoto && yyAfterGoto <= YYSTATE_LAST);

    return ((int64_t)yyRule << 48) | ((int64_t)yyReduceActionState << 32) | ((int64_t)yyTopOnStackAfterPop << 16) | ((int64_t)yyAfterGoto << 0) ;
}


static int16_t decodeReductionRule(int64_t red) {
    return (int16_t) (red >> 48);
}


static int16_t decodeReductionReduceActionState(int64_t red) {
    return (int16_t) (red >> 32);
}


static int16_t decodeReductionTopOnStackAfterPop(int64_t red) {
    return (int16_t) (red >> 16);
}


static int16_t decodeReductionAfterGoto(int64_t red) {
    return (int16_t) (red >> 0);
}


static void buildGotoReverseEdged() {
    int n = 0;
    int m = 0;
    for (int yyExpectNonterminalState = YYSTATE_FIRST; yyExpectNonterminalState <= YYSTATE_LAST; yyExpectNonterminalState++) {
        BOOST_FOREACH(int yyNt, yyReachableGotos[yyExpectNonterminalState]) {
            int yyGotoState = yyGetGoto(yyExpectNonterminalState, yyNt);
            int success = yyGotoStateToBaseState[yyGotoState].insert(yyExpectNonterminalState).second;
            n += 1;
            if (success) {
                m += 1;
            }
        }
    }
#ifdef DEBUG
    fprintf(stderr, "Number of reversed goto edges: %d/%d\n", m, n);
#endif
}


static bool reverseMarkActive(int yyReduceActionState, int yyState, int yyRule, int yySym) {
    bool changed = false;
    if (yySym < 0) {
        return changed;
    }

    int yyNt = yyr1[yyRule];
    int yyRuleLength = yyr2[yyRule];

    if (yySym < yyRuleLength) {
        addActiveSymbol(yyState, yyRule, yySym);
    }

    if (yySym == 0) {
        int yyGotoState = yyGetGoto(yyState, yyNt);
        yyReachableGotos[yyState - YYSTATE_FIRST].insert(yyNt);

        int64_t dest = encodeReduction(yyRule, yyReduceActionState, yyState, yyGotoState);

        yyReductionsByFrom[yyReduceActionState - YYSTATE_FIRST].insert(dest);
        assert(YYSTATE_FIRST <= yyGotoState && yyGotoState <= YYSTATE_LAST);
        changed = yyReductionsByAfterGoto[yyGotoState - YYSTATE_FIRST].insert(dest).second || changed;
    } else {
        // Shift predecessors
        int i = 0;
        BOOST_FOREACH(int yyPredState, yyShiftPred[yyState - YYSTATE_FIRST]) {
            changed = reverseMarkActive(yyReduceActionState, yyPredState, yyRule, yySym -1) || changed;
            i += 1;
        }

        // Goto predecessors
        std::vector<int64_t> cpyReductionsForAfterGoto(yyReductionsByAfterGoto[yyState - YYSTATE_FIRST].begin(), yyReductionsByAfterGoto[yyState - YYSTATE_FIRST].end()); // Make a copy because the set can be modified in this loop
        BOOST_FOREACH(int64_t red, cpyReductionsForAfterGoto)  {
            int yyTop = decodeReductionTopOnStackAfterPop(red);
            int yyAfterGoto = decodeReductionAfterGoto(red);
            assert(yyAfterGoto == yyState);
            changed = reverseMarkActive(yyReduceActionState, yyTop, yyRule, yySym - 1) || changed;
            i += 1;
        }
    }

    return changed;
}


static bool markActiveAccordingAction(int yyState, int action) {
    if (action == YYTABLE_NINF) {
        return false;
    }

    if (action > 0) {
        return false;
    } else {
        assert(action < 0);
        int yyRule = -action;
        int yyRuleLength = yyr2[yyRule];
        return reverseMarkActive(yyState, yyState, yyRule, yyRuleLength);
    }
}


static bool markActive(int it) {
    bool changed = false;

    for (int yyState = YYSTATE_FIRST; yyState <= YYSTATE_LAST; yyState+=1) {
        fprintf(stderr, "Iteration %d, State %d\n", it, yyState);

        int pact = yypact[yyState];
        if (!(YYPACT_NINF < pact && pact <= YYLAST)) {
            // Same action for all lookahead tokens
            int action = yyGetAction(yyState, YYTOKEN_LEX_FIRST);
            changed = markActiveAccordingAction(yyState, action) || changed;
        } else {
            bool actionDone[YYRULE_COUNT];
            memset(&actionDone,0, sizeof(actionDone));

            for (int yyToken = YYTOKEN_FIRST; yyToken <= YYTOKEN_LAST; yyToken+=1) {
                int action = yyGetAction(yyState, yyToken);
                if (action == YYTABLE_NINF) {
                    continue;
                }

                if (action > 0) {
                } else {
                    assert(action < 0);
                    int yyRule = -action ;
                    if (actionDone[yyRule - YYRULE_FIRST]) {
                        continue;
                    }
                    actionDone[yyRule - YYRULE_FIRST] = true;
                }

                changed = markActiveAccordingAction(yyState, action) || changed;
            }
        }
    }
#ifdef DEBUG
    fprintf(stderr, "Number of active production symbols: %d/%d\n", mActiveSymbol, nActiveSymbol);
#endif
    return changed;
}


static void markActiveUntilStable() {
    int n = 0;
    while (true) {
        n += 1;
        bool changed = markActive(n);
#ifdef DEBUG
        fprintf(stderr, "Found %d reductions yet\n", (int)yyReductions.size());
#endif
        if (!changed) {
            break;
        }
    }
#ifdef DEBUG
    // With the given parser, no more than 3 iterations are required, the forth only confirms that there are no more changes
    fprintf(stderr, "Number of markActive loops: %d\n", n);
#endif
}


static void yyFindActiveSymbols() {
    assert(YYTOKEN_FIRST == findYytnameIndex("$end"));
    assert(YYTOKEN_LEX_FIRST == findYytnameIndex("tokALL0"));
    assert(YYTOKEN_LEX_LAST == findYytnameIndex("tokSTRING"));
    assert(YYTOKEN_LAST+1 == YYNT_FIRST);
    assert(YYNT_FIRST == findYytnameIndex("$accept"));
    assert(YYNT_BISON_FIRST == findYytnameIndex("start"));
    assert(YYNT_LAST == findYytnameIndex("optstring"));

    // Phase I: Reverse edges
    // For every state construct a list of shift actions that jump to this state
    buildReversedEdges();

    // Phase II
    buildGotoReverseEdged();

    // Phase III: Simulate parser
    // From every reduction, go backwards and find all states that could be on the stack
    // When the stack is full enough to pop the rule's number of symbols off the stack, mark the states
    // on the stack with the number of the the rule's symbol.
    markActiveUntilStable();
}


static std::string buildLR0Item(int yyRule, int yySym, const char *dotSign) {
    int prod = findRuleProduction(yyRule);
    std::string result;
    for (int i = prod; i < prod + yyr2[yyRule]; i+=1) {
        if (i - prod == yySym) {
            if (result.empty()) {
                result = dotSign;
            } else  {
                result += std::string() + " " + dotSign;
            }
        }

        std::string token = yytname[yyrhs[i]];
        if (result.empty()) {
            result = token;
        } else {
            result += std::string() + " " + token;
        }
    }
    return result;
}


static std::string buildLR0Item(int yyRule, int yySym) {
    return buildLR0Item(yyRule, yySym, "&bull;");
}


static std::string buildProduction(int yyRule) {
    std::string result = yytname[yyr1[yyRule]];
    result = result + " -> " + buildLR0Item(yyRule, -1);
    return result;
}


/**
Writes the LR(0) state machine of the bison generated parser to a graphviz file.
Only useful to see whether the parser reconstruction really works as expected
*/
static void writeDot() {
    std::ofstream out("parser.dot", std::ios_base::out | std::ios_base::trunc);
    out << "digraph {\n";
    out << "rankdir=LR;\n";

    int nStates = std::min(65, YYSTATE_LAST+1);
    for (int yyState = YYSTATE_FIRST; yyState <nStates; yyState+=1) {
        std::string label = " <<table border=\"0\" cellborder=\"0\" cellpadding=\"3\" bgcolor=\"white\"><tr><td bgcolor=\"black\" align=\"center\" colspan=\"2\"><font color=\"white\">State #";
        label += boost::lexical_cast<std::string>(yyState);
        label += "</font></td></tr>";

        BOOST_FOREACH(int64_t rulesym, symbolActive[yyState] ) {
            int rule = (int)(rulesym>>32);
            int sym = (int)(rulesym );
            std::string item  = buildLR0Item(rule, sym);
            label += std::string() + "<tr><td align=\"left\" port=\"r3\">&#40;" +  boost::lexical_cast<std::string>(rule) + "&#41; " + yytname[yyr1[rule]] + " -&gt; " + item + "</td></tr>"    ;
        }

        label += "</table>>";
        out << "  s" << yyState << " [style=filled penwidth=1 fillcolor=white shape=Mrecord label=" << label << "];\n";
    }

    out << "\n";

    for (int yyState = YYSTATE_FIRST; yyState < nStates; yyState+=1) {
        std::string hasEdge[YYSTATE_COUNT];

        for (int yyToken = YYTOKEN_FIRST; yyToken <= YYTOKEN_LAST; yyToken+=1)  {
            int action = yyGetAction(yyState, yyToken);
            if (action == YYPACT_NINF) {
                continue;
            }

            if (action > 0)      {
                if (!hasEdge[action-YYSTATE_FIRST].empty()) {
                    hasEdge[action-YYSTATE_FIRST] += std::string() + "\\n" + yytname[yyToken];
                } else {
                    hasEdge[action-YYSTATE_FIRST] = yytname[yyToken];
                }
            }
        }

        for (int yyToState = YYSTATE_FIRST; yyToState < nStates; yyToState+=1) {
            if (hasEdge[yyToState-YYSTATE_FIRST].empty()) {
                continue;
            }

            out << "  s" << yyState << " -> s" << yyToState  << " [label=\""  << hasEdge[yyToState-YYSTATE_FIRST] << "\"];\n";
        }
    }

    out << "\n";

    for (int yyState = YYSTATE_FIRST; yyState < nStates; yyState+=1) {
        std::string hasEdge[YYSTATE_COUNT];
        std::string nts;
        BOOST_FOREACH (int yyNt, yyReachableGotos[yyState]) {
            int yyGotoState = yyGetGoto(yyState, yyNt);

            if (hasEdge[yyGotoState-YYSTATE_FIRST].empty()) {
                hasEdge[yyGotoState-YYSTATE_FIRST] = yytname[yyNt];
            } else {
                hasEdge[yyGotoState-YYSTATE_FIRST] += std::string() + "\\n" + yytname[yyNt];
            }
        }

        for (int yyGotoState = YYSTATE_FIRST; yyGotoState < nStates; yyGotoState+=1) {
            if (!hasEdge[yyGotoState-YYSTATE_FIRST].empty()) {
                out << "  s" << yyState << " -> s" << yyGotoState << " [shape=ellipse,fontcolor=blue,color=blue,label=\""<<  hasEdge[yyGotoState-YYSTATE_FIRST] << "\"];\n";
            }
        }
    }

    out << "\n";

    for (int yyState = YYSTATE_FIRST; yyState < nStates; yyState+=1) {
        std::string nts[YYNT_COUNT];

        for (int yyToken = YYTOKEN_FIRST; yyToken <= YYTOKEN_LAST; yyToken += 1)  {
            int action = yyGetAction(yyState, yyToken);
            if (action == YYPACT_NINF) {
                continue;
            }

            if (action < 0)      {
                int yyNt = yyr1[-action];
                assert(yyNt <= YYNT_LAST);

                if (nts[yyNt- YYNT_FIRST]   .empty()) {
                    nts[yyNt- YYNT_FIRST] =  yytname[yyToken];
                } else {
                    nts[yyNt- YYNT_FIRST] += std::string() + ", " +  yytname[yyToken];
                }
            }
        }

        std::string com;
        for (int yyNt = YYNT_BISON_FIRST; yyNt <= YYNT_LAST; yyNt+=1 ) {
            if (nts[yyNt - YYNT_FIRST].empty()) {
                continue;
            }

            if (com.empty()) {
                com = std::string() + yytname[yyNt] ;//+ " [" +nts[yyNt - YYNT_FIRST] + "]";
            } else {
                com += std::string() + "\\n" +  yytname[yyNt];
            }
        }
        if (!com.empty()) {
            out << "  r" << yyState << " [shape=none,fontcolor=red,label=\"" << com << "\"];\n";
            out << "  s" << yyState << " -> r" << yyState << " [color=red];\n";
        }
    }

    out << "\n";

    // Reduction start and destination
    BOOST_FOREACH(int64_t red, yyReductions) {
        int yyReduceActionState = decodeReductionReduceActionState(red);
        int yyAfterGoto = decodeReductionAfterGoto(red);
        if (yyReduceActionState >= nStates) {
            continue;
        }
        if (yyAfterGoto >= nStates) {
            continue;
        }

        out << "  r" << yyReduceActionState << " -> s" << yyAfterGoto << " [color=gray]\n";
    }

    out <<"}\n";
    out.close();
}


// Only required by linker, never executed ////////////////////////////////////

void yacc_yyerror(const char */*s*/, const char */*filename*/, int /*first_offset*/, int /*first_line*/, int /*first_column*/, int /*last_offset*/, int /*last_line*/, int /*last_column*/) {
// dummy
}


void lex_yyerror(const char */*s*/, const char */*filename*/, int /*offset*/, int /*line*/, int /*column*/) {
    // dummy
}


void TypeError(String /*str*/, Pos &/*p*/) {
    // dummy
}


void codeError(String &/*str*/, Pos &/*p*/) {
    // dummy
}


bool isActiveSymbol(const std::vector<int> &/*stack*/, int /*yyRule*/, int /*yyRuleSym*/) {
    // dummy
    return false;
}


bool isActiveToken(const std::vector<int> &/*stack*/, int /*yyToken*/) {
    // dummy
    return false;
}


extern Ident lastPosVar;
extern Ident allPosVar;
SymbolTable symbolTable(0); // TODO:  call destructor before first use of MonaImpl (do the same as in MonaImpl::freeSavedGlobals)
CodeTable *codeTable;
Guide guide;
PredicateLib predicateLib; // TODO:  call destructor before first use of MonaImpl
Options options;
Offsets offsets; // TODO: call destructor before first use of MonaImpl
AutLib lib; // TODO:  call destructor before first use of MonaImpl
bool regenerate;
int numTypes;
MonaUntypedAST *untypedAST;
extern Guide_Declaration *guide_declaration;
bool errorExit;


// main ///////////////////////////////////////////////////////////////////////

int main(int /*argc*/, char */*argv*/[]) {
    yyFindActiveSymbols();
#ifdef DEBUG
    writeDot();
#endif

    const char *headerfilename = "activetable.h";
    std::ofstream header(headerfilename);
    std::ofstream out("activetable.cpp");

    {
        header << "#ifndef ACTIVETABLE_H\n";
        header << "#define ACTIVETABLE_H\n";
        header << "/* This file has been generated */\n\n";
        out << "/* This file has been generated */\n\n";
        header << "#include <stdint.h>\n";
        header << "\n";
        header << "#define YYSTATE_FIRST " << YYSTATE_FIRST << "\n";
        header << "#define YYSTATE_LAST " << YYSTATE_LAST << "\n";
        header << "#define YYSTATE_COUNT (YYSTATE_LAST - YYSTATE_FIRST + 1)\n";
        header << "\n";
        header << "#define YYRULE_FIRST " << YYRULE_FIRST << "\n";
        header << "#define YYRULE_LAST " << YYRULE_LAST << "\n";
        header << "#define YYRULE_COUNT (YYRULE_LAST - YYRULE_FIRST + 1)\n";
        out << "#include \"" << headerfilename << "\"\n";
    }

    out << "\n";
    header << "\n";

    {
        int count = 0;
        for (int yyState = YYSTATE_FIRST; yyState <= YYSTATE_LAST; yyState+=1) {
            count += symbolActive[yyState - YYSTATE_FIRST].size();
        }
        header << "extern const int16_t yyActiveSymbols[" << count << "][3];\n";
        out << "const int16_t yyActiveSymbols[" << count << "][3] = {\n";
        out << "   /* state, rule, symbol */\n";
        bool isFirst = true;
        for (int yyState = YYSTATE_FIRST; yyState <= YYSTATE_LAST; yyState+=1) {
            bool isFirstSym = true;
            BOOST_FOREACH(int64_t sym, symbolActive[yyState - YYSTATE_FIRST]) {
                if (!isFirst) {
                    out << ",\n";
                }
                if (isFirstSym) {
                    out << "   /* State " << yyState << " */\n";
                }
                isFirst = false;
                isFirstSym = false;

                int yyRule = (int) (sym >> 32);
                int yySymbol = (int)sym;
                out << "    { " << yyState << ", " << yyRule << ", " << yySymbol << " } /* " << buildLR0Item(yyRule, yySymbol, ".") << " */";
            }
        }
        out << "\n  };\n";
    }

    out << "\n";

    {
        int count = 0;
        for (int yyState = YYSTATE_FIRST; yyState <= YYSTATE_LAST; yyState+=1) {
            count += activeTokens[yyState - YYSTATE_FIRST].size();
        }
        header << "extern const int16_t yyActiveTokens["<< count << "][2];\n";
        out << "const int16_t yyActiveTokens[" << count << "][2] = {\n";
        bool isFirst = true;
        for (int yyState = YYSTATE_FIRST; yyState <= YYSTATE_LAST; yyState+=1) {
            BOOST_FOREACH(int yyToken, activeTokens[yyState - YYSTATE_FIRST]) {
                if (!isFirst) {
                    out << ",\n";
                }
                isFirst = false;

                out << "    { " << yyState << ", " << yyToken << " }";
            }
        }
        out << "\n  };\n";
    }

    out << "\n";

    {
        int count = 0;
        for (int yyState = YYSTATE_FIRST; yyState <= YYSTATE_LAST; yyState+=1) {
            count += yyReductionsByFrom[yyState - YYSTATE_FIRST].size();
        }
        header << "extern const int16_t yyReductionsByFrom["<< count <<"][3];\n";
        out << "const int16_t yyReductionsByFrom["<< count <<"][3] = {\n";
        int countCheck = 0;
        bool isFirst = true;
        std::vector<int> jumptable;
        jumptable.push_back(0);
        for (int yyState = YYSTATE_FIRST; yyState <= YYSTATE_LAST; yyState+=1) {
            out << "\n  /* State " << yyState << " */";
            typedef std::pair< int, std::pair<int, int > > intPairType;
            std::set <intPairType> set;
            BOOST_FOREACH(int64_t red, yyReductionsByFrom[yyState - YYSTATE_FIRST]) {
                int yyTop = decodeReductionTopOnStackAfterPop(red);
                int yyReduceActionState = decodeReductionReduceActionState(red);
                assert(yyReduceActionState == yyState);
                int yyReductionRule = decodeReductionRule(red);
                int yyAfterGoto = decodeReductionAfterGoto(red);
                set.insert(intPairType(yyReductionRule, std::pair<int,int>(yyAfterGoto, yyTop))).second;
            }

            BOOST_FOREACH(const intPairType &red, set) {
                if (!isFirst) {
                    out << ",\n";
                }
                isFirst = false;

                int yyReductionRule = red.first;
                int yyAfterGoto = red.second.first;
                int yyTopAfterReduction = red.second.second;
                out << "    { " << yyReductionRule << ", " << yyAfterGoto << ", " << yyTopAfterReduction << " } /* " << buildProduction(yyReductionRule) << " */";
                countCheck += 1;
            }
            jumptable.push_back(countCheck);
        }
        assert(count == countCheck);
        out << "\n  };\n";

        int jumpCount = jumptable.size();
        header << "extern const int16_t yyReductionsByFrom_jumptable["<< jumpCount <<"];\n";
        out << "const int16_t yyReductionsByFrom_jumptable[" << jumpCount << "] = {\n    ";
        isFirst = true;
        BOOST_FOREACH(int yyFrom, jumptable) {
            if (!isFirst) {
                out << ", ";
            }
            isFirst = false;

            out << yyFrom;
        }
        out << "\n  };\n";
    }

    out << "\n";

    {
        header << "extern const int16_t yyr2["<< YYRULE_COUNT <<"];\n";
        out << "const int16_t yyr2[" << YYRULE_COUNT << "] = {\n    ";
        bool isFirst = true;
        for (int yyRule = YYRULE_FIRST; yyRule <= YYRULE_LAST; yyRule += 1) {
            if (!isFirst) {
                out << ", ";
            }
            isFirst = false;

            out << boost::lexical_cast<std::string>((int)yyr2[yyRule]);
        }
        out << "\n  };\n";
    }

    out << "\n";

    {
        int count = sizeof(yytname)/sizeof(yytname[0]);
        header << "extern const char *yytname[" << count << "];\n";
        out << "const char *yytname[" << count << "] = {\n";
        bool isFirst = true;
        for (int i= 0; i < count-1; i+=1) {
            if (!isFirst) {
                out << ",\n";
            }
            isFirst = false;

            out << "    \"" << yytname[i] << "\"";
        }
        out << ",\n    0";
        out << "\n  };\n";
    }

    out << "\n";

    {
        int count = sizeof (yyrhs)/sizeof(yyrhs[0]);
        header << "extern const int8_t yyrhs[" << count << "];\n";
        out << "const int8_t yyrhs[" << count << "] = {\n  ";
        bool isFirst = true;
        for (int i = 0; i < count; i += 1) {
            if (!isFirst) {
                out << ", ";
            }
            isFirst = false;

            out << boost::lexical_cast<std::string>((int)yyrhs[i]);
        }
        out << "\n  };\n";
    }

    out << "\n";

    {
        int count = sizeof(yyr1)/sizeof(yyr1[0]);
        header << "extern const uint8_t yyr1[" << count << "];\n";
        out << "const uint8_t yyr1[" << count << "] = {\n    ";
        bool isFirst = true;
        for (int yyRule = 0; yyRule < count; yyRule += 1) {
            if (!isFirst) {
                out << ", ";
            }
            isFirst = false;

            out << boost::lexical_cast<std::string>((int)yyr1[yyRule]);
        }
        out << "\n  };\n";
    }

    out << "\n";

    {
        int count = sizeof(yyprhs)/sizeof(yyprhs[0]);
        header << "extern const uint16_t yyprhs[" << count << "];\n";
        out << "const uint16_t yyprhs[" << count << "] = {\n    ";
        bool isFirst = true;
        for (int i = 0; i < count; i += 1) {
            if (!isFirst) {
                out << ", ";
            }
            isFirst = false;

            out << boost::lexical_cast<std::string>((int)yyprhs[i]);
        }
        out << "\n  };\n";
    }

    header << "\n";
    header << "#endif /* ACTIVETABLE_H */\n";
}
