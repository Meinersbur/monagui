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
Extract completion information from previously generated tables
*/

#include "completiontable.h"
#include "activetable.h"

#include <boost/foreach.hpp>

#include <assert.h>
#include <stdio.h>


const int yyActiveSymbols_length = sizeof(yyActiveSymbols)/sizeof(yyActiveSymbols[0]);
const int yyActiveTokens_length = sizeof(yyActiveTokens)/sizeof(yyActiveTokens[0]);


static inline int compareActiveSymbol(int yyState, int yyRule, int yyRuleSym, int mid) {
    int state = yyActiveSymbols[mid][0];
    if (state == yyState) {
        int rule = yyActiveSymbols[mid][1];
        if (rule == yyRule) {
            int symbol = yyActiveSymbols[mid][2];
            return yyRuleSym - symbol;
        } else {
            return yyRule - rule;
        }
    } else {
        return yyState - state;
    }
}


bool isActiveSymbol(int yyState, int yyRule, int yyRuleSym) {
    // binary search in yyActiveSymbols
    int left = 0;  // inclusive
    int right = yyActiveSymbols_length; // exclusive
    int mid =(2 * yyActiveSymbols_length * (2 * yyState + 1) / (2 * YYSTATE_COUNT)) / 2; // First guess

    while (true) {
        assert(left <= mid && mid <= right);
        int cmp = compareActiveSymbol(yyState, yyRule, yyRuleSym, mid);
        if (cmp > 0) {
            // Symbol is more right
            left = mid + 1;
        } else if (cmp < 0) {
            // Symbol s more left
            right = mid;
        } else {
            // Exact match
            return true;
        }

        if (left >= right) {
            // Nothing more to search
            return false;
        }

        mid = (left + right) / 2;
    }
}


bool isActiveSymbol(const std::vector<int> &stack, int yyRule, int yyRuleSym) {
    if (stack.empty()) {
        assert(!"At least state 0 should be on the stack");
        return false;
    }

    int top = stack.back();
    if (isActiveSymbol(top, yyRule, yyRuleSym)) {
        return true;
    }

    // Look for reductions
    int start = yyReductionsByFrom_jumptable[top - YYSTATE_FIRST];
    int end = yyReductionsByFrom_jumptable[top - YYSTATE_FIRST + 1];
    for (int i = start; i < end; i+=1 ) {
        int yyReductionRule = yyReductionsByFrom[i][0];
        int yyAfterGoto = yyReductionsByFrom[i][1];
        int yyTopAfterReduction = yyReductionsByFrom[i][2];
        int yyRuleLength = yyr2[yyReductionRule];
        if (stack.at(stack.size()-1 - yyRuleLength) != yyTopAfterReduction) {
            continue; // Rule not applicable
        }
        std::vector<int> stackAfterReduction(stack);
        assert(stackAfterReduction.size() > yyRuleLength);
        for (int i = yyRuleLength-1; i>=0; i-=1 ) {
            stackAfterReduction.pop_back();
        }
        stackAfterReduction.push_back(yyAfterGoto);
        bool isActive = isActiveSymbol(stackAfterReduction, yyRule, yyRuleSym);
        if (isActive) {
            return true;
        }
    }

    return false;
}


static inline int compareActiveToken(int yyState, int yyToken, int mid) {
    int state = yyActiveTokens[mid][0];
    if (state == yyState) {
        int token = yyActiveTokens[mid][1];
        return yyToken - token;
    } else {
        return yyState - state;
    }
}


bool isActiveToken(int yyState, int yyToken) {
    // binary search in yyActiveSymbols
    int left = 0;  // inclusive
    int right = yyActiveTokens_length; // exclusive
    int mid = (2 * yyActiveTokens_length * (2 * yyState + 1) / (2 * YYSTATE_COUNT)) / 2; // First guess

    while (true) {
        assert(left <= mid && mid <= right);
        int cmp = compareActiveToken(yyState, yyToken, mid);
        if (cmp > 0) {
            // Symbol is more right
            left = mid + 1;
        } else if (cmp < 0) {
            // Symbol s more left
            right = mid;
        } else {
            // Exact match
            return true;
        }

        if (left >= right) {
            // Nothing more to search
            return false;
        }

        mid = (left + right) / 2;
    }
}


bool isActiveToken(const std::vector<int> &stack, int yyToken) {
#ifdef DEBUG
    fprintf(stderr, "Stack is:");
    BOOST_FOREACH (int yyState, stack) {
        fprintf(stderr, " %d", yyState);
    }
    fprintf(stderr, "\n");
#endif
    if (stack.empty()) {
        assert(!"At least state 0 should be on the stack");
        return false;
    }

    int top = stack.back();
    if (isActiveToken(top, yyToken)) {
        return true;
    }

    // Look for reductions
    int start = yyReductionsByFrom_jumptable[top - YYSTATE_FIRST];
    int end = yyReductionsByFrom_jumptable[top - YYSTATE_FIRST + 1];
    for (int i = start; i < end; i+=1) {
        int yyReductionRule = yyReductionsByFrom[i][0];
        int yyAfterGoto = yyReductionsByFrom[i][1];
        int yyTopAfterReduction = yyReductionsByFrom[i][2];
        int yyRuleLength = yyr2[yyReductionRule];
        if (stack.at(stack.size()-1 - yyRuleLength) != yyTopAfterReduction) {
            continue; // Rule not applicable
        }
        std::vector<int> stackAfterReduction(stack);
        assert(stackAfterReduction.size() > yyRuleLength);
        for (int i = yyRuleLength-1; i>=0; i-=1 ) {
            stackAfterReduction.pop_back();
        }
        stackAfterReduction.push_back(yyAfterGoto);
        bool isActive = isActiveToken(stackAfterReduction, yyToken);
        if (isActive) {
            return true;
        }
    }

    return false;
}


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


int findRuleIndex(int yySearchNt, const char *prod) {
    int prodlen = strlen(prod);
    char prodCpy[prodlen+1];
    strcpy(prodCpy, prod);
    int nSymbol = 0;
    char *tname[prodlen];// pessimistic

    int startPos = 0;
    int pos = 0;
    while (pos < prodlen) {
        if (prodCpy[pos] == ' ') {
            prodCpy[pos] = '\0';
            tname[nSymbol] = &prodCpy[startPos];
            nSymbol += 1;
            pos += 1;
            startPos = pos;
            continue;
        }

        pos += 1;
    }
    if (startPos < prodlen) {
        tname[nSymbol] = &prodCpy[startPos];
        nSymbol += 1;
    }

    int yySymbol[nSymbol];
    for (int i = 0; i < nSymbol; i++) {
        yySymbol[i] = findYytnameIndex(tname[i]);
    }

    for (int yyRule = YYRULE_FIRST; yyRule <= YYRULE_LAST; yyRule += 1) {
        int yyRuleLength = yyr2[yyRule];
        int yyNt = yyr1[yyRule];

        if (yyRuleLength != nSymbol) {
            continue;
        }

        if (yyNt != yySearchNt) {
            continue;
        }

        bool match = true;
        for (int yySym = 0; yySym < yyRuleLength; yySym += 1) {
            int yyToken = yyrhs[yyprhs[yyRule] + yySym];
            if (yyToken != yySymbol[yySym]) {
                match = false;
                break;
            }
        }
        if (match) {
            return yyRule;
        }
    }
    assert(false);
    return -1;

    int yyNt = yySearchNt;
    int i = 0;
    int yyRule = 0;
    int symIdx = 0;
    bool match = true;
    while (true) {
        int sym = yyrhs[i];

        if (sym == -1) {
            // End of rule
            if (match && nSymbol == yyr2[yyRule]) {
                // Found our rule
                break;
            }

            // Next rule
            yyRule += 1;
            if (yyRule > YYRULE_LAST) {
                // No more rules
                match = false;
                break;
            }

            i+=1;
            symIdx = 0;
            match = true;
            continue;
        }

        if (yyr1[yyRule] != yyNt) {
            // Wrong lhs
            i+=1;
            match = false;
            symIdx += 1;
            continue;
        }

        if (!match) {
            // Some previous symbol did not match
            i+=1;
            symIdx += 1;
            continue;
        }

        if (sym != yySymbol[symIdx]) {
            // rule does not match
            match = false;
            i+=1;
            symIdx += 1;
            continue;
        }

        // Symbol matches up to here
        i+= 1;
        symIdx += 1;
    }

    assert(match && "Rule does not exist");
    return match ? yyRule:-1;
}
