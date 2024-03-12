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

#include "completioncontext.h"

#include "front2/completiontable.h"

#include <boost/foreach.hpp>


const TokenContext declExpected("declaration");
const TokenContext headerExpected("header");

const TokenContext boolExpExpected("tokTRUE");
const TokenContext intExpExpected("tokINT");
const TokenContext setExpExpected("tokEMPTY");

static const ProductionSymbolContext anyExpContexts[] = {
    ProductionSymbolContext("exp", "name tokLPAREN exp_list tokRPAREN", 2), // Call
    ProductionSymbolContext("non_empty_exp_list", "exp tokCOMMA non_empty_exp_list", 2),
    ProductionSymbolContext("exp", "tokEXPORT tokLPAREN tokSTRING tokCOMMA exp tokRPAREN", 4),
    ProductionSymbolContext("exp", "tokEMPTY tokLPAREN exp tokRPAREN", 3),
    ProductionSymbolContext("exp", "tokPREFIX tokLPAREN exp tokRPAREN", 2),
    ProductionSymbolContext("exp", "tokINSTATESPACE tokLPAREN exp tokCOMMA name_list tokRPAREN", 2),
    ProductionSymbolContext("exp", "tokVARIANT tokLPAREN exp tokCOMMA exp tokCOMMA name tokCOMMA name tokRPAREN", 2),
    ProductionSymbolContext("exp", "tokVARIANT tokLPAREN exp tokCOMMA exp tokCOMMA name tokCOMMA name tokRPAREN", 4),
    ProductionSymbolContext("exp", "tokSUCC tokLPAREN exp tokCOMMA name tokCOMMA name tokCOMMA name tokRPAREN", 2),
    ProductionSymbolContext("exp", "tokTREE tokLPAREN exp tokRPAREN", 2),
    ProductionSymbolContext("exp", "tokTYPE tokLPAREN exp tokCOMMA name tokRPAREN", 2),
    ProductionSymbolContext("exp", "tokSOMETYPE tokLPAREN exp tokRPAREN", 2),
    ProductionSymbolContext("exp", "tokCONSTTREE tokLPAREN exp tokCOMMA name tokCOLON constnode tokRPAREN", 2),
    ProductionSymbolContext("exp", "tokTREEROOT tokLPAREN exp tokRPAREN", 2),
    ProductionSymbolContext("exp", "tokRESTRICT tokLPAREN exp tokRPAREN", 2),
    ProductionSymbolContext("exp", "tokUNIVROOT tokLPAREN name tokRPAREN", 2),
    ProductionSymbolContext("exp", "tokUNIVROOT tokLPAREN exp tokCOMMA universe tokRPAREN", 3),
};

static const AggregateContext anyExpExpected(anyExpContexts, lengthof(anyExpContexts));

// Precedence Numbering according to MONA documentation
static const ProductionSymbolContext boolExpContextsPred1[] = {  };
static const ProductionSymbolContext boolExpContextsPred2[] = {  };
static const ProductionSymbolContext boolExpContextsPred3[] = {  };
static const ProductionSymbolContext boolExpContextsPred4[] = {  };
static const ProductionSymbolContext boolExpContextsPred5[] = {  };
static const ProductionSymbolContext boolExpContextsPred6[] = {  };
static const ProductionSymbolContext boolExpContextsPred7[] = {  };
static const ProductionSymbolContext boolExpContextsPred8[] = { ProductionSymbolContext("exp", "exp tokEQUAL exp", 2), ProductionSymbolContext("exp", "exp tokNOTEQUAL exp", 2) };
static const ProductionSymbolContext boolExpContextsPred9[] = {  };
static const ProductionSymbolContext boolExpContextsPred10[] = { ProductionSymbolContext("exp", "tokNOT exp", 1) };
static const ProductionSymbolContext boolExpContextsPred11[] = { ProductionSymbolContext("exp", "exp tokAND exp", 2) };
static const ProductionSymbolContext boolExpContextsPred12[] = { ProductionSymbolContext("exp", "exp tokOR exp", 2) };
static const ProductionSymbolContext boolExpContextsPred13[] = { ProductionSymbolContext("exp", "exp tokIMPL exp", 2) };
static const ProductionSymbolContext boolExpContextsPred14[] = { ProductionSymbolContext("exp", "exp tokBIIMPL exp", 2) }; // %right tokBIIMPL
static const ProductionSymbolContext boolExpContextsPred15[] = { ProductionSymbolContext("exp", "tokEX0 name_where_list tokCOLON exp", 3), ProductionSymbolContext("exp", "tokEX1 universe name_where_list tokCOLON exp", 4), ProductionSymbolContext("exp", "tokEX2 universe name_where_list tokCOLON exp", 4), ProductionSymbolContext("exp", "tokALL0 name_where_list tokCOLON exp", 3), ProductionSymbolContext("exp", "tokALL1 universe name_where_list tokCOLON exp", 4), ProductionSymbolContext("exp", "tokALL2 universe name_where_list tokCOLON exp", 4) }; // %nonassoc tokCOLON
static const ProductionSymbolContext boolExpContextsPred16[] = { ProductionSymbolContext("exp", "tokLET0 defs tokIN exp", 3), ProductionSymbolContext("exp", "tokLET1 defs tokIN exp", 3), ProductionSymbolContext("exp", "tokLET2 defs tokIN exp", 3) }; // %nonassoc LOW
static const ProductionSymbolContext boolExpContexts[] = { };

static const ProductionSymbolListItem boolExpContextsPredAsc[] = {
    { boolExpContextsPred1, lengthof(boolExpContextsPred1) },
    { boolExpContextsPred2, lengthof(boolExpContextsPred2) },
    { boolExpContextsPred3, lengthof(boolExpContextsPred3) },
    { boolExpContextsPred4, lengthof(boolExpContextsPred4) },
    { boolExpContextsPred5, lengthof(boolExpContextsPred5) },
    { boolExpContextsPred6, lengthof(boolExpContextsPred6) },
    { boolExpContextsPred7, lengthof(boolExpContextsPred7) },
    { boolExpContextsPred8, lengthof(boolExpContextsPred8) },
    { boolExpContextsPred9, lengthof(boolExpContextsPred9) },
    { boolExpContextsPred10, lengthof(boolExpContextsPred10) },
    { boolExpContextsPred11, lengthof(boolExpContextsPred11) },
    { boolExpContextsPred12, lengthof(boolExpContextsPred12) },
    { boolExpContextsPred13, lengthof(boolExpContextsPred13) },
    { boolExpContextsPred14, lengthof(boolExpContextsPred14) },
    { boolExpContextsPred15, lengthof(boolExpContextsPred15) },
    { boolExpContextsPred16, lengthof(boolExpContextsPred16) }
};

const AggregateContext boolExpContextsPredOrMore[] = {
    AggregateContext(boolExpContextsPredAsc, 0,15),
    AggregateContext(boolExpContextsPredAsc, 1,15),
    AggregateContext(boolExpContextsPredAsc, 2,15),
    AggregateContext(boolExpContextsPredAsc, 3,15),
    AggregateContext(boolExpContextsPredAsc, 4,15),
    AggregateContext(boolExpContextsPredAsc, 5,15),
    AggregateContext(boolExpContextsPredAsc, 6,15),
    AggregateContext(boolExpContextsPredAsc, 7,15),
    AggregateContext(boolExpContextsPredAsc, 8,15),
    AggregateContext(boolExpContextsPredAsc, 9,15),
    AggregateContext(boolExpContextsPredAsc, 10,15),
    AggregateContext(boolExpContextsPredAsc, 11,15),
    AggregateContext(boolExpContextsPredAsc, 12,15),
    AggregateContext(boolExpContextsPredAsc, 13,15),
    AggregateContext(boolExpContextsPredAsc, 14,15),
    AggregateContext(boolExpContextsPredAsc, 15,15),
    AggregateContext(boolExpContextsPredAsc, 16,15) // empty
};

static const ParenContext boolExpParen(boolExpContextsPredOrMore[0]);

const AggregateContext boolExpContextsPredOrMoreOrParen[17] = {
    AggregateContext(boolExpParen, boolExpContextsPredOrMore[0]),
    AggregateContext(boolExpParen, boolExpContextsPredOrMore[1]),
    AggregateContext(boolExpParen, boolExpContextsPredOrMore[2]),
    AggregateContext(boolExpParen, boolExpContextsPredOrMore[3]),
    AggregateContext(boolExpParen, boolExpContextsPredOrMore[4]),
    AggregateContext(boolExpParen, boolExpContextsPredOrMore[5]),
    AggregateContext(boolExpParen, boolExpContextsPredOrMore[6]),
    AggregateContext(boolExpParen, boolExpContextsPredOrMore[7]),
    AggregateContext(boolExpParen, boolExpContextsPredOrMore[8]),
    AggregateContext(boolExpParen, boolExpContextsPredOrMore[9]),
    AggregateContext(boolExpParen, boolExpContextsPredOrMore[10]),
    AggregateContext(boolExpParen, boolExpContextsPredOrMore[11]),
    AggregateContext(boolExpParen, boolExpContextsPredOrMore[12]),
    AggregateContext(boolExpParen, boolExpContextsPredOrMore[13]),
    AggregateContext(boolExpParen, boolExpContextsPredOrMore[14]),
    AggregateContext(boolExpParen, boolExpContextsPredOrMore[15]),
    AggregateContext(boolExpParen, boolExpContextsPredOrMore[16])
};

const AggregateContext boolExpContextsPredLessThan[17] = {
    AggregateContext(boolExpContextsPredAsc, 0, -1), // empty
    AggregateContext(boolExpContextsPredAsc, 0, 0),
    AggregateContext(boolExpContextsPredAsc, 0, 1),
    AggregateContext(boolExpContextsPredAsc, 0, 2),
    AggregateContext(boolExpContextsPredAsc, 0, 3),
    AggregateContext(boolExpContextsPredAsc, 0, 4),
    AggregateContext(boolExpContextsPredAsc, 0, 5),
    AggregateContext(boolExpContextsPredAsc, 0, 6),
    AggregateContext(boolExpContextsPredAsc, 0, 7),
    AggregateContext(boolExpContextsPredAsc, 0, 8),
    AggregateContext(boolExpContextsPredAsc, 0, 9),
    AggregateContext(boolExpContextsPredAsc, 0, 10),
    AggregateContext(boolExpContextsPredAsc, 0, 11),
    AggregateContext(boolExpContextsPredAsc, 0, 12),
    AggregateContext(boolExpContextsPredAsc, 0, 13),
    AggregateContext(boolExpContextsPredAsc, 0, 14),
    AggregateContext(boolExpContextsPredAsc, 0, 15)
};

static const ProductionSymbolContext intExpContextsPred1[] = { ProductionSymbolContext("arith_exp", "tokMINUS arith_exp", 1) };
static const ProductionSymbolContext intExpContextsPred2[] = { ProductionSymbolContext("exp", "exp tokPLUS arith_exp tokMODULO exp", 4), ProductionSymbolContext("exp", "exp tokMINUS arith_exp tokMODULO exp", 4), ProductionSymbolContext("exp", "exp tokSTAR arith_exp", 2), ProductionSymbolContext("exp", "exp tokSLASH arith_exp", 2),ProductionSymbolContext("arith_exp", "arith_exp tokSTAR arith_exp", 2), ProductionSymbolContext("arith_exp", "arith_exp tokSLASH arith_exp", 2) };
static const ProductionSymbolContext intExpContextsPred3[] = { ProductionSymbolContext("exp", "exp tokPLUS arith_exp", 2), ProductionSymbolContext("exp", "exp tokMINUS arith_exp", 2), ProductionSymbolContext("arith_exp", "arith_exp tokPLUS arith_exp", 2), ProductionSymbolContext("arith_exp", "arith_exp tokMINUS arith_exp", 2) };
static const ProductionSymbolContext intExpContextsPred4[] = {  };
static const ProductionSymbolContext intExpContextsPred5[] = {  };
static const ProductionSymbolContext intExpContextsPred6[] = {  };
static const ProductionSymbolContext intExpContextsPred7[] = {  };
static const ProductionSymbolContext intExpContextsPred8[] = { ProductionSymbolContext("exp", "exp tokEQUAL exp", 2), ProductionSymbolContext("exp", "exp tokNOTEQUAL exp", 2), ProductionSymbolContext("exp", "exp tokLESS exp", 2), ProductionSymbolContext("exp", "exp tokLESSEQ exp", 2), ProductionSymbolContext("exp", "exp tokGREATEREQ exp", 2), ProductionSymbolContext("exp", "exp tokGREATER exp", 2) };
static const ProductionSymbolContext intExpContextsPred9[] = {  };
static const ProductionSymbolContext intExpContextsPred10[] = {  };
static const ProductionSymbolContext intExpContextsPred11[] = {  };
static const ProductionSymbolContext intExpContextsPred12[] = {  };
static const ProductionSymbolContext intExpContextsPred13[] = {  };
static const ProductionSymbolContext intExpContextsPred14[] = {  };
static const ProductionSymbolContext intExpContextsPred15[] = {  };
static const ProductionSymbolContext intExpContextsPred16[] = { ProductionSymbolContext("exp", "tokLET0 defs tokIN exp", 3), ProductionSymbolContext("exp", "tokLET1 defs tokIN exp", 3), ProductionSymbolContext("exp", "tokLET2 defs tokIN exp", 3) }; // %nonassoc LOW
static const ProductionSymbolContext intExpContexts[] = {  };

static const ProductionSymbolListItem intExpContextsPredAsc[] = {
    { intExpContextsPred1, lengthof(intExpContextsPred1) },
    { intExpContextsPred2, lengthof(intExpContextsPred2) },
    { intExpContextsPred3, lengthof(intExpContextsPred3) },
    { intExpContextsPred4, lengthof(intExpContextsPred4) },
    { intExpContextsPred5, lengthof(intExpContextsPred5) },
    { intExpContextsPred6, lengthof(intExpContextsPred6) },
    { intExpContextsPred7, lengthof(intExpContextsPred7) },
    { intExpContextsPred8, lengthof(intExpContextsPred8) },
    { intExpContextsPred9, lengthof(intExpContextsPred9) },
    { intExpContextsPred10, lengthof(intExpContextsPred10) },
    { intExpContextsPred11, lengthof(intExpContextsPred11) },
    { intExpContextsPred12, lengthof(intExpContextsPred12) },
    { intExpContextsPred13, lengthof(intExpContextsPred13) },
    { intExpContextsPred14, lengthof(intExpContextsPred14) },
    { intExpContextsPred15, lengthof(intExpContextsPred15) },
    { intExpContextsPred16, lengthof(intExpContextsPred16) }
};

const AggregateContext intExpContextsPredOrMore[] = {
    AggregateContext(intExpContextsPredAsc, 0,15),
    AggregateContext(intExpContextsPredAsc, 1,15),
    AggregateContext(intExpContextsPredAsc, 2,15),
    AggregateContext(intExpContextsPredAsc, 3,15),
    AggregateContext(intExpContextsPredAsc, 4,15),
    AggregateContext(intExpContextsPredAsc, 5,15),
    AggregateContext(intExpContextsPredAsc, 6,15),
    AggregateContext(intExpContextsPredAsc, 7,15),
    AggregateContext(intExpContextsPredAsc, 8,15),
    AggregateContext(intExpContextsPredAsc, 9,15),
    AggregateContext(intExpContextsPredAsc, 10,15),
    AggregateContext(intExpContextsPredAsc, 11,15),
    AggregateContext(intExpContextsPredAsc, 12,15),
    AggregateContext(intExpContextsPredAsc, 13,15),
    AggregateContext(intExpContextsPredAsc, 14,15),
    AggregateContext(intExpContextsPredAsc, 15,15),
    AggregateContext(intExpContextsPredAsc, 16,15) // empty
};

static const ParenContext intExpParen(intExpContextsPredOrMore[0]);

const AggregateContext intExpContextsPredOrMoreOrParen[17] = {
    AggregateContext(intExpParen, intExpContextsPredOrMore[0]),
    AggregateContext(intExpParen, intExpContextsPredOrMore[1]),
    AggregateContext(intExpParen, intExpContextsPredOrMore[2]),
    AggregateContext(intExpParen, intExpContextsPredOrMore[3]),
    AggregateContext(intExpParen, intExpContextsPredOrMore[4]),
    AggregateContext(intExpParen, intExpContextsPredOrMore[5]),
    AggregateContext(intExpParen, intExpContextsPredOrMore[6]),
    AggregateContext(intExpParen, intExpContextsPredOrMore[7]),
    AggregateContext(intExpParen, intExpContextsPredOrMore[8]),
    AggregateContext(intExpParen, intExpContextsPredOrMore[9]),
    AggregateContext(intExpParen, intExpContextsPredOrMore[10]),
    AggregateContext(intExpParen, intExpContextsPredOrMore[11]),
    AggregateContext(intExpParen, intExpContextsPredOrMore[12]),
    AggregateContext(intExpParen, intExpContextsPredOrMore[13]),
    AggregateContext(intExpParen, intExpContextsPredOrMore[14]),
    AggregateContext(intExpParen, intExpContextsPredOrMore[15]),
    AggregateContext(intExpParen, intExpContextsPredOrMore[16])
};

const AggregateContext intExpContextsPredLessThan[17] = {
    AggregateContext(intExpContextsPredAsc, 0, -1), // empty
    AggregateContext(intExpContextsPredAsc, 0, 0),
    AggregateContext(intExpContextsPredAsc, 0, 1),
    AggregateContext(intExpContextsPredAsc, 0, 2),
    AggregateContext(intExpContextsPredAsc, 0, 3),
    AggregateContext(intExpContextsPredAsc, 0, 4),
    AggregateContext(intExpContextsPredAsc, 0, 5),
    AggregateContext(intExpContextsPredAsc, 0, 6),
    AggregateContext(intExpContextsPredAsc, 0, 7),
    AggregateContext(intExpContextsPredAsc, 0, 8),
    AggregateContext(intExpContextsPredAsc, 0, 9),
    AggregateContext(intExpContextsPredAsc, 0, 10),
    AggregateContext(intExpContextsPredAsc, 0, 11),
    AggregateContext(intExpContextsPredAsc, 0, 12),
    AggregateContext(intExpContextsPredAsc, 0, 13),
    AggregateContext(intExpContextsPredAsc, 0, 14),
    AggregateContext(intExpContextsPredAsc, 0, 15)
};

static const ProductionSymbolContext setExpContextsPred1[] = {  };
static const ProductionSymbolContext setExpContextsPred2[] = {  };
static const ProductionSymbolContext setExpContextsPred3[] = {  };
static const ProductionSymbolContext setExpContextsPred4[] = { ProductionSymbolContext("exp", "exp tokSETMINUS exp", 2) };
static const ProductionSymbolContext setExpContextsPred5[] = { ProductionSymbolContext("exp", "exp tokINTER exp", 2) };
static const ProductionSymbolContext setExpContextsPred6[] = { ProductionSymbolContext("exp", "exp tokUNION exp", 2) };
static const ProductionSymbolContext setExpContextsPred7[] = { ProductionSymbolContext("exp", "tokMIN exp", 1), ProductionSymbolContext("exp", "tokMAX exp", 1) };
static const ProductionSymbolContext setExpContextsPred8[] = { ProductionSymbolContext("exp", "exp tokEQUAL exp", 2), ProductionSymbolContext("exp", "exp tokNOTEQUAL exp", 2) };
static const ProductionSymbolContext setExpContextsPred9[] = { ProductionSymbolContext("exp", "exp tokSUB exp", 2), ProductionSymbolContext("exp", "exp tokIN exp", 2), ProductionSymbolContext("exp", "exp tokNOTIN exp", 2) };
static const ProductionSymbolContext setExpContextsPred10[] = {  };
static const ProductionSymbolContext setExpContextsPred11[] = {  };
static const ProductionSymbolContext setExpContextsPred12[] = {  };
static const ProductionSymbolContext setExpContextsPred13[] = {  };
static const ProductionSymbolContext setExpContextsPred14[] = {  };
static const ProductionSymbolContext setExpContextsPred15[] = {  };
static const ProductionSymbolContext setExpContextsPred16[] = { ProductionSymbolContext("exp", "tokLET0 defs tokIN exp", 3), ProductionSymbolContext("exp", "tokLET1 defs tokIN exp", 3), ProductionSymbolContext("exp", "tokLET2 defs tokIN exp", 3) }; // %nonassoc LOW

static const ProductionSymbolListItem setExpContextsPredAsc[] = {
    { setExpContextsPred1, lengthof(setExpContextsPred1) },
    { setExpContextsPred2, lengthof(setExpContextsPred2) },
    { setExpContextsPred3, lengthof(setExpContextsPred3) },
    { setExpContextsPred4, lengthof(setExpContextsPred4) },
    { setExpContextsPred5, lengthof(setExpContextsPred5) },
    { setExpContextsPred6, lengthof(setExpContextsPred6) },
    { setExpContextsPred7, lengthof(setExpContextsPred7) },
    { setExpContextsPred8, lengthof(setExpContextsPred8) },
    { setExpContextsPred9, lengthof(setExpContextsPred9) },
    { setExpContextsPred10, lengthof(setExpContextsPred10) },
    { setExpContextsPred11, lengthof(setExpContextsPred11) },
    { setExpContextsPred12, lengthof(setExpContextsPred12) },
    { setExpContextsPred13, lengthof(setExpContextsPred13) },
    { setExpContextsPred14, lengthof(setExpContextsPred14) },
    { setExpContextsPred15, lengthof(setExpContextsPred15) },
    { setExpContextsPred16, lengthof(setExpContextsPred16) }
};

const AggregateContext setExpContextsPredOrMore[] = {
    AggregateContext(setExpContextsPredAsc, 0,15),
    AggregateContext(setExpContextsPredAsc, 1,15),
    AggregateContext(setExpContextsPredAsc, 2,15),
    AggregateContext(setExpContextsPredAsc, 3,15),
    AggregateContext(setExpContextsPredAsc, 4,15),
    AggregateContext(setExpContextsPredAsc, 5,15),
    AggregateContext(setExpContextsPredAsc, 6,15),
    AggregateContext(setExpContextsPredAsc, 7,15),
    AggregateContext(setExpContextsPredAsc, 8,15),
    AggregateContext(setExpContextsPredAsc, 9,15),
    AggregateContext(setExpContextsPredAsc, 10,15),
    AggregateContext(setExpContextsPredAsc, 11,15),
    AggregateContext(setExpContextsPredAsc, 12,15),
    AggregateContext(setExpContextsPredAsc, 13,15),
    AggregateContext(setExpContextsPredAsc, 14,15),
    AggregateContext(setExpContextsPredAsc, 15,15),
    AggregateContext(setExpContextsPredAsc, 16,15) // empty
};

static const ParenContext setExpParen(setExpContextsPredOrMore[0]);

const AggregateContext setExpContextsPredOrMoreOrParen[17] = {
    AggregateContext(setExpParen, setExpContextsPredOrMore[0]),
    AggregateContext(setExpParen, setExpContextsPredOrMore[1]),
    AggregateContext(setExpParen, setExpContextsPredOrMore[2]),
    AggregateContext(setExpParen, setExpContextsPredOrMore[3]),
    AggregateContext(setExpParen, setExpContextsPredOrMore[4]),
    AggregateContext(setExpParen, setExpContextsPredOrMore[5]),
    AggregateContext(setExpParen, setExpContextsPredOrMore[6]),
    AggregateContext(setExpParen, setExpContextsPredOrMore[7]),
    AggregateContext(setExpParen, setExpContextsPredOrMore[8]),
    AggregateContext(setExpParen, setExpContextsPredOrMore[9]),
    AggregateContext(setExpParen, setExpContextsPredOrMore[10]),
    AggregateContext(setExpParen, setExpContextsPredOrMore[11]),
    AggregateContext(setExpParen, setExpContextsPredOrMore[12]),
    AggregateContext(setExpParen, setExpContextsPredOrMore[13]),
    AggregateContext(setExpParen, setExpContextsPredOrMore[14]),
    AggregateContext(setExpParen, setExpContextsPredOrMore[15]),
    AggregateContext(setExpParen, setExpContextsPredOrMore[16])
};

const AggregateContext setExpContextsPredLessThan[17] = {
    AggregateContext(setExpContextsPredAsc, 0, -1), // empty
    AggregateContext(setExpContextsPredAsc, 0, 0),
    AggregateContext(setExpContextsPredAsc, 0, 1),
    AggregateContext(setExpContextsPredAsc, 0, 2),
    AggregateContext(setExpContextsPredAsc, 0, 3),
    AggregateContext(setExpContextsPredAsc, 0, 4),
    AggregateContext(setExpContextsPredAsc, 0, 5),
    AggregateContext(setExpContextsPredAsc, 0, 6),
    AggregateContext(setExpContextsPredAsc, 0, 7),
    AggregateContext(setExpContextsPredAsc, 0, 8),
    AggregateContext(setExpContextsPredAsc, 0, 9),
    AggregateContext(setExpContextsPredAsc, 0, 10),
    AggregateContext(setExpContextsPredAsc, 0, 11),
    AggregateContext(setExpContextsPredAsc, 0, 12),
    AggregateContext(setExpContextsPredAsc, 0, 13),
    AggregateContext(setExpContextsPredAsc, 0, 14),
    AggregateContext(setExpContextsPredAsc, 0, 15)
};

// Within parenthesis, precedence can be ignored
static const ProductionSymbolContext parenContexts[] = {
    ProductionSymbolContext ("exp", "tokLPAREN exp tokRPAREN", 1),
    ProductionSymbolContext ("arith_exp", "tokLPAREN arith_exp tokRPAREN", 1)
};

static AggregateContext parenContext(parenContexts, lengthof(parenContexts));


// TokenContext /////////////////////////////////////////////////////////////////////////

TokenContext::TokenContext(const char *yyTname)  {
    this->yyTname = yyTname;
    this->yyToken = findYytnameIndex(yyTname);
}


bool TokenContext::suggestFollow(const std::vector<int> &yyStack) const {
    return isActiveToken(yyStack, yyToken);
}


// ProductionSymbolContext ///////////////////////////////////////////////////////////

ProductionSymbolContext::ProductionSymbolContext(const char *nonterminal, const char *production, int symbolNum) {
    this->nonterminal = nonterminal;
    this->production = production;

    this->yyNt = findYytnameIndex(nonterminal);
    this->yyRule = findRuleIndex(yyNt, production);
    this->yySymIdx = symbolNum;
}


bool ProductionSymbolContext::suggestFollow(const std::vector<int> &yyStack) const {
    return isActiveSymbol(yyStack, yyRule, yySymIdx);
}


// AggregateContext ///////////////////////////////////////////////////////////

AggregateContext::AggregateContext(const CompletionContext &c1) {
    const AggregateContext *ac1 = dynamic_cast<const AggregateContext *>(&c1);
    if (ac1) {
        subcontexts.insert(subcontexts.end(), ac1->subcontexts.begin(), ac1->subcontexts.end());
    } else {
        subcontexts.push_back(&c1);
    }
}


AggregateContext::AggregateContext(const CompletionContext &c1, const CompletionContext &c2) {
    const AggregateContext *ac1 = dynamic_cast<const AggregateContext *>(&c1);
    if (ac1) {
        subcontexts.insert(subcontexts.end(), ac1->subcontexts.begin(), ac1->subcontexts.end());
    } else {
        subcontexts.push_back(&c1);
    }

    const AggregateContext *ac2 = dynamic_cast<const AggregateContext *>(&c2);
    if (ac2) {
        subcontexts.insert(subcontexts.end(), ac2->subcontexts.begin(), ac2->subcontexts.end());
    } else {
        subcontexts.push_back(&c2);
    }
}


AggregateContext::AggregateContext(ProductionSymbolContext const *const cList[]) {
    int i = 0;
    while (cList[i] != 0)  {
        subcontexts.push_back(cList[i]);
        i+=1;
    }
}


AggregateContext::AggregateContext(ProductionSymbolContext const cList[], int count ) {
    for (int i = 0; i < count ; i+= 1) {
        subcontexts.push_back(&cList[i]);
    }
}


AggregateContext::AggregateContext(const ProductionSymbolListItem cList[], int firstIndex, int lastIndex) {
    for (int i = firstIndex; i <= lastIndex; i+=1) {
        int count = cList[i].count;
        for (int j = 0; j < count; j +=1)  {
            subcontexts.push_back(&cList[i].symbols[j]);
        }
    }
}    


bool AggregateContext::suggestFollow(const std::vector<int> &yyStack) const {
    BOOST_FOREACH(const CompletionContext *context, this->subcontexts) {
        assert(context);
        if (context->suggestFollow(yyStack)) {
            return true;
        }
    }
    return false;
}


// ParenContext /////////////////////////////////////////////////////////////////////////

ParenContext::ParenContext(const CompletionContext &inherit) {
    this->inherited = &inherit;
}


bool ParenContext::suggestFollow(const std::vector<int> &yyStack) const {
    if (parenContext.suggestFollow(yyStack)) {
        // Means the top state is after shifting an opening parenthesis
        assert(yyStack.size() >= 2);
        std::vector<int> stackCopy (yyStack);
        stackCopy.pop_back();
        return inherited->suggestFollow(stackCopy);
    }
    return false;
}

