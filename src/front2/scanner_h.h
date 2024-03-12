#ifndef SCANNER_H
#define SCANNER_H
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
Supplementary scanner definitions
*/

#define YYDEBUG 1

#ifndef YYLTYPE_IS_DECLARED
typedef struct YYLTYPE {
  int first_offset;
  int last_offset;
  int first_line;
  int first_column;
  int last_line;
  int last_column;
  const char *filename;
} YYLTYPE;
#define YYLTYPE_IS_DECLARED 1
#define YYLTYPE_IS_TRIVIAL 1
#endif

void monagui_reset_lexer();

void loadFile(const char *s);
int yylex_real();

/**
implement somewhere in your application
*/
extern void lex_yyerror(const char *s, const char *filename, int offset, int line, int column);

#endif // SCANNER_H
