#ifndef MONAANALYZE_H
#define MONAANALYZE_H
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
This file is a C++ adaptation of Mona's DFA/analyze.c (and external.c)

This is necessary because these print their output directly to stdout, but we need them as string
*/

#include "st_dfa.h"
#include "st_gta.h"

#include <iosfwd>


void mona_dfaAnalyze(std::ostream &str, DFA *dfa, int no_free_vars, char **free_variables, unsigned *offsets, char *types, int treestyle);
void mona_gtaAnalyze(std::ostream &out, GTA *gta, unsigned no_of_free, char **free_var_names, unsigned *free_map);
void mona_gtaTypeAnalyze(std::ostream &out, GTA *a, unsigned num, char *names[], char orders[], unsigned indices[], int *univs[], int trees[]);

int mona_dfaExport(std::ostream &out, DFA *a, int num, char *vars[], char orders[]);
int mona_gtaExport(std::ostream &out, GTA *G, int num, char *vars[], char orders[], SSSet *statespaces, int opt_inhacc) ;

void mona_dfaPrint(std::ostream &out, DFA *a, int no_free_vars, char **free_variables, unsigned *offsets);
void mona_gtaPrint(std::ostream &out, GTA *P, unsigned *offs, unsigned no_offs, char **free_vars, int inherited_acceptance);

void mona_dfaPrintVerbose(std::ostream &out, DFA *a);
void mona_gtaPrintVerbose(std::ostream &out, GTA *P);

void mona_print_bddpaths(std::ostream &out, unsigned p, unsigned q, bdd_manager *bddm, unsigned b, unsigned no_free_vars, unsigned *offsets);

#endif // MONAANALYZE_H
