#ifndef PARSER_H
#define PARSER_H
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
Supplementary parser definitions
*/

#include "scanner_h.h"

#include <vector>


extern int yydebug;
int yyparse(void);

/**
implement somewhere in your application
*/
void yacc_yyerror(const char *s, const char *filename, int first_offset, int first_line, int first_column, int last_offset, int last_line, int last_column);

void yyValidNextTokens(std::vector<const char *> &result, int state);

int findYytnameIndex(const char *tname);
int findRuleIndex(int yyNt, const char *prod);

extern bool g_yyHookCompletion ;
extern YYLTYPE g_yyCompletionLoc;
extern int g_yyCompletionState;
extern std::vector<int> g_yyCompletionStack;
extern YYLTYPE g_yyPrevDeclaration;
extern YYLTYPE g_yyNextDeclaration;
extern bool g_yyAfterCompletion;

#endif // PARSER_H
