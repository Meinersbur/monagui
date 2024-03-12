#ifndef COMPLETIONCONTEXT_H
#define COMPLETIONCONTEXT_H
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
Stores information about when a completion is applicable
*/

#include "global.h"

#include <vector>


// Abstract superclass
class CompletionContext {
public:
    virtual ~CompletionContext() {}

    virtual bool suggestFollow(const std::vector<int> &yyStack) const = 0;
};


// Every location where a specific token (like a string literal) may occur
class TokenContext: public CompletionContext {
public:
    TokenContext(const char *yyTname);

    bool suggestFollow(const std::vector<int> &yyStack) const;
    
private:
    const char *yyTname;
    int yyToken;
};


// Represents a location within a production
class ProductionSymbolContext: public CompletionContext {
public:
    ProductionSymbolContext(const char *nonterminal, const char *production, int symbolNum);

    bool suggestFollow(const std::vector<int> &yyStack) const;

private:
    const char *nonterminal;
    const char *production;

    int yyNt;
    int yyRule;
    int yySymIdx;
};


// To store context literals
typedef struct { const ProductionSymbolContext *symbols; int count; }  ProductionSymbolListItem;

// A logical OR of context (i.e. at least one of many contexts)
class AggregateContext: public CompletionContext {
public:
    AggregateContext();
    AggregateContext(const CompletionContext &context);
    AggregateContext(const CompletionContext &c1, const CompletionContext &c2);
    AggregateContext(ProductionSymbolContext const *const cList[]);
    AggregateContext(ProductionSymbolContext const cList[], int count);
    AggregateContext(const ProductionSymbolListItem cList[], int firstIndex, int lastIndex);

    bool suggestFollow(const std::vector<int> &yyStack) const;

private:
    std::vector<const CompletionContext *> subcontexts;
};


// Context that allow the inherited context within parenthesis
class ParenContext: public CompletionContext {
public:
    ParenContext(const CompletionContext &inherit);

    bool suggestFollow(const std::vector<int> &yyStack) const;
private:
    const CompletionContext *inherited;
};


// context literals

extern const TokenContext declExpected;
extern const TokenContext headerExpected;
    
extern const TokenContext boolExpExpected;
extern const TokenContext intExpExpected;
extern const TokenContext setExpExpected;

// operators with the first argument being a boolean (var0) value at the given precedence level
extern const AggregateContext boolExpContextsPredOrMoreOrParen[17];
extern const AggregateContext boolExpContextsPredLessThan[17];

// operators with the first argument being an integer/node (var1) value at the given precedence level
extern const AggregateContext intExpContextsPredOrMoreOrParen[17];
extern const AggregateContext intExpContextsPredLessThan[17];

// operators with the first argument being a set (var2) value at the given precedence level
extern const AggregateContext setExpContextsPredOrMoreOrParen[17];
extern const AggregateContext setExpContextsPredLessThan[17];


#endif // COMPLETIONCONTEXT_H
