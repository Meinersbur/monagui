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
Replacements for Mona functions that print into a stream instead to stdout
*/

#include "monaanalyze.h"
#include "monaexternal.h"

extern "C" {
#include "../Mem/mem.h"
}

#include <boost/format.hpp>


static void mona_printTypePositions(std::ostream &out, Tree *tree, unsigned index, int *first, int begin, int all, char path[], int type);
static Tree *mona_printTreeRoot(std::ostream &out, Tree *tree, unsigned index, int type, char *path);


static void print_example(std::ostream &out, char *example, char *name, int no_free_vars, char **free_variables, unsigned *offsets, char *types, int treestyle) {
    int i, j;
    int length;

    length = strlen(example)/(no_free_vars+1);

    if (treestyle) {
        out << "Free variables are: ";
        for (i = 0; i < no_free_vars; i++)      {
            out << free_variables[i];
            out <<  (no_free_vars-1 ? "" : ", ");
        }

        out << "\n\nA " << name << " of least length (" << length - 1 << ") is:\nBooleans:\n" ;
        for (i = 0; i < no_free_vars; i++) {
            out << example[i*length];
        }

        out << "\nUniverse:\n";
        for (i = 1; i < length; i++) {
            out << '(';
            for (j = 0; j < no_free_vars; j++) {
                out << example[j*length+i];
            }
            out << ',';
        }
        out << "()";
        for (i = 1; i < length; i++) {
            out << ",())";
        }
        out << '\n';

    } else {
        out <<  "A " << name << " of least length (" << (length-1) << ") is:\n";
        for (i = 0; i < no_free_vars; i++) {
            out <<  boost::format("%-15s %c ") % free_variables[i] % example[i*length] ;
            for (j = 0; j < length-1; j++) {
                out << example[i*length+1+j];
            }
            out << '\n';
        }
        out << '\n';

        for (i = 0; i < no_free_vars; i++)
            switch (types[i]) {
            case 0:
                out <<  free_variables[i] << " = " <<( example[i*length] == '1' ? "true" : "false") << "\n";
                break;
            case 1: {
                int j = 0;
                while (example[i*length+j+1] == '0' && j < length) {
                    j++;
                }
                out << free_variables[i] << " = " << j << "\n";
            }
            break;
            case 2: {
                int j, t = 0;
                out << free_variables[i] << " = {";
                for (j = 0; j < length; j++)
                    if (example[i*length+j+1] == '1') {
                        if (t++ != 0) {
                            out << ',';
                        }
                        out << j;
                    }
                out << "}\n";
            }
            break;
            }
    }

    mem_free(example);
}


void mona_dfaAnalyze(std::ostream &out, DFA *dfa, int no_free_vars, char **free_variables, unsigned *offsets, char *types, int treestyle) {
    char *counterexample, *satisfyingexample;

    counterexample = dfaMakeExample(dfa, -1, no_free_vars, offsets);
    satisfyingexample = dfaMakeExample(dfa, 1, no_free_vars, offsets);

    if (!counterexample && satisfyingexample) {
        out << "Formula is valid\n";
    } else if (!satisfyingexample) {
        out << "Formula is unsatisfiable\n";
    }

    if (counterexample) {
        if (!satisfyingexample) {
            out << "\n";
        }
        print_example(out, counterexample, "counter-example",  no_free_vars, free_variables, offsets, types, treestyle);
    }
    if (satisfyingexample) {
        if (no_free_vars) {
            out << "\n";
        }
        print_example(out, satisfyingexample, "satisfying example", no_free_vars, free_variables, offsets, types, treestyle);
    }
}

// from external.c
int mona_dfaExport(std::ostream &out, DFA *a, int num, char *vars[], char orders[]) {
    Table *table = tableInit();
    int i;

    /* remove all marks in a->bddm */
    bdd_prepare_apply1(a->bddm);

    /* build table of tuples (idx,lo,hi) */
    for (i = 0; i < a->ns; i++) {
        bdd_export(a->bddm, a->q[i], table);
    }

    /* renumber lo/hi pointers to new table ordering */
    for (i = 0; i < table->noelems; i++) {
        if (table->elms[i].idx != -1) {
            table->elms[i].lo = bdd_mark(a->bddm, table->elms[i].lo) - 1;
            table->elms[i].hi = bdd_mark(a->bddm, table->elms[i].hi) - 1;
        }
    }

    /* write to file */
    out <<  "MONA DFA\n"     ;
    out << "number of variables: " << num << "\n"   ;
    out <<   "variables:";

    for (i = 0; i < num; i++) {
        out << " " << vars[i];
    }
    out << "\n"  ;

    out << "orders:";
    for (i = 0; i < num; i++) {
        out << " " <<  (unsigned) orders[i];
    }
    out << "\n";

    out << "states: " <<  a->ns << "\n";
    out << "initial: " <<     a->s << "\n";
    out << "bdd nodes: " << table->noelems << "\n";

    out << "final:";
    for (i = 0; i < a->ns; i++) {
        out << " " << a->f[i];
    }
    out << "\n";

    out << "behaviour:";
    for (i = 0; i < a->ns; i++) {
        out << " " << bdd_mark(a->bddm, a->q[i]) - 1;
    }
    out << "\n";

    out << "bdd:\n";
    for (i = 0; i < table->noelems; i++) {
        out << " " << table->elms[i].idx << " " << table->elms[i].lo << " " << table->elms[i].hi << "\n";
    }
    out << "end\n";

    tableFree(table);
    return 1;
}


int mona_gtaExport(std::ostream &out, GTA *G, int num, char *vars[],
                   char orders[], SSSet *statespaces, int opt_inhacc) {
    unsigned i, j, k, l, r;
    boolean ***inherited = NULL;
    Table **tables = (Table **) mem_alloc(sizeof(Table *)*guide.numSs);
    if (opt_inhacc) {
        inherited = gtaCalcInheritedAcceptance(G);
    }

    for (i = 0; i < guide.numSs; i++) {
        tables[i] = tableInit();
    }

    /* remove all marks G->bddm */
    for (i = 0; i < guide.numSs; i++) {
        bdd_prepare_apply1(G->ss[i].bddm);
    }

    /* build table of tuples (idx,lo,hi) */
    for (i = 0; i < guide.numSs; i++)
        for (l = 0; l < G->ss[guide.muLeft[i]].size; l++)
            for (r = 0; r < G->ss[guide.muRight[i]].size; r++)
                bdd_export(G->ss[i].bddm,
                           BDD_ROOT(G->ss[i].bddm, BEH(G->ss[i], l, r)),
                           tables[i]);

    for (i = 0; i < guide.numSs; i++) {
        for (j = 0; j < tables[i]->noelems; j++) {
            if (tables[i]->elms[j].idx != -1) {
                tables[i]->elms[j].lo = bdd_mark(G->ss[i].bddm, tables[i]->elms[j].lo)-1;
                tables[i]->elms[j].hi = bdd_mark(G->ss[i].bddm, tables[i]->elms[j].hi)-1;
            }
        }
    }

    out << "MONA GTA\n"   ;
    out <<  "number of variables: " << num << " \n";
    out <<       "state spaces: " << guide.numSs << "\n";
    out <<  "universes: " << guide.numUnivs << "\n";
    out <<     "state space sizes:";
    for (i = 0; i < guide.numSs; i++) {
        out << " " << G->ss[i].size;
    }
    out << "\n";

    out << "final:";
    for (i = 0; i < G->ss[0].size; i++) {
        out << " " << G->final[i];
    }
    out << "\n";

    out << "guide;\n";
    for (i = 0; i < guide.numSs; i++) {
        out << " " << guide.ssName[i] << " " << guide.muLeft[i] << " " << guide.muRight[i] << "\n";
    }

    out << "types: " << num_types << "\n";
    for (i = 0; i < num_types; i++) {
        out << " type: "  << treetypes[i].name     << "\n";
        out << "  variants: " << treetypes[i].numVariants << "\n";
        for (j = 0; j < treetypes[i].numVariants; j++) {
            out << "  variant: " << treetypes[i].variantName[j] << " " <<  (treetypes[i].variantPos[j][0] ?
                    treetypes[i].variantPos[j] : "-"   ) << "\n";
            out <<   "  components: " << treetypes[i].numComponents[j] << "\n";
            for (k = 0; k < treetypes[i].numComponents[j]; k++)    {
                out <<  "   " << treetypes[i].componentName[j][k] << " " <<   (treetypes[i].componentPos[j][k][0] ?
                        treetypes[i].componentPos[j][k] : "-") << " " <<  treetypes[i].componentType[j][k] << "\n";
            }
        }
    }
    out << "universes:\n";
    for (i = 0; i < guide.numUnivs; i++) {
        out << " " << guide.univName[i] << " " << guide.univPos[i] << "\n";
    }
    out << "variable orders and state spaces:\n";
    for (i = 0; i < num; i++) {
        out << " " << vars[i] << " " << (unsigned) orders[i];
        for (j = 0; j < guide.numSs; j++)
            if (statespaces[i][j]) {
                out << " " << j;
            }
        out << "\n";
    }

    for (i = 0; i < guide.numSs; i++) {
        out << "\n";
        out << "state space " << i << ":\n"  ;
        out << " initial state: " << G->ss[i].initial << "\n";
        out <<  " bdd nodes: " << tables[i]->noelems;
        if (inherited) {
            out << "\n";
            out <<     " inherited-acceptance:";
            for (j = 0; j < G->ss[i].size; j++)  {
                out << "\n";
                out << "  " << inherited[i][j][-1] << " " << inherited[i][j][0] << " " << inherited[i][j][1];
            }
        }
        out << "\n";
        out <<  " behaviour:\n"   ;
        out << " ";
        for (l = 0; l < G->ss[guide.muLeft[i]].size; l++) {
            for (r = 0; r < G->ss[guide.muRight[i]].size; r++)         {
                out << " " << (bdd_mark(G->ss[i].bddm,  BDD_ROOT(G->ss[i].bddm,  BEH(G->ss[i], l, r)))-1);
            }
            out << "\n";
            out << " ";
        }
        out << "bdd:\n";
        for (j = 0; j < tables[i]->noelems; j++) {
            out << "  " <<  tables[i]->elms[j].idx << " " <<  tables[i]->elms[j].lo << " " << tables[i]->elms[j].hi << "\n";
        }
    }
    out << "\n";
    out << "end\n";

    for (i = 0; i < guide.numSs; i++) {
        tableFree(tables[i]);
    }
    mem_free(tables);
    if (opt_inhacc) {
        gtaFreeInheritedAcceptance(inherited);
    }
    return 1;
}


static void mona_print_one_path(std::ostream &out, unsigned p, unsigned q, bdd_manager *bddm, unsigned no_free_vars, unsigned *offsets) {
    trace_descr tp,tp_run;
    unsigned j;

    tp = find_one_path(bddm, p, q);
    for (j = 0; j < no_free_vars; j++) {
        tp_run = tp;
        for (; tp_run && (tp_run->index != offsets[j]); tp_run = tp_run->next);

        if (tp_run) {
            if (tp_run->value) {
                out << "1";
            } else {
                out <<"0";
            }
        } else {
            out << "X";
        }
    };
    kill_trace(tp);
}


static void mona_print_tree(std::ostream &out, Tree *t, unsigned no, unsigned *free_map) {
    invariant(t);

    if (t->empty) {
        out << "()";
    } else {
        out << "(";
        mona_print_one_path(out, bdd_roots(t->bddm)[t->behavior_handle], /* the BDD node */
                            t->state,   /* the leaf (state to be reached) */
                            t->bddm,   /* the BDD manager */
                            no,
                            free_map);
        out << ",";
        mona_print_tree(out, t->left,no,free_map);
        out << ",";
        mona_print_tree(out, t->right,no,free_map);
        out << ")";
    }
}


static void mona_print_universes(std::ostream &out, Tree *example, int no_of_free, unsigned *free_map) {
    if (guide.ssUniv[example->d] >= 0) {
        out << "Universe "     <<  guide.univName[guide.ssUniv[example->d]] << ":\n";
        mona_print_tree(out, example, no_of_free, free_map);
        out << "\n";
    } else {
        mona_print_universes(out, example->left, no_of_free, free_map);
        mona_print_universes(out, example->right, no_of_free, free_map);
    }
}


void mona_gtaAnalyze(std::ostream &out, GTA *gta, unsigned no_of_free, char **free_var_names, unsigned *free_map) {
    unsigned i;
    Tree *counterexample, *satisfyingexample;

    counterexample = gtaMakeExample(gta, -1);
    satisfyingexample = gtaMakeExample(gta, 1);

    if (!counterexample && satisfyingexample) {
        out <<   "Formula is valid\n";
    } else if (!satisfyingexample) {
        out << "Formula is unsatisfiable\n";
    }

    if (counterexample) {
        if (!satisfyingexample) {
            out << "\n";
        }
        out << "Free variables are: ";
        for (i = 0; i < no_of_free; i++) {
            out << free_var_names[i] << (i == no_of_free -1 ? "": ", ");
        }
        out << "\n";
        out << "\n";

        out << "A counter-example is:\n";
        if (!counterexample->empty) {
            out << "Booleans:\n";
            mona_print_one_path(out, BDD_ROOT(counterexample->bddm, counterexample->behavior_handle),
                                counterexample->state,
                                counterexample->bddm,
                                no_of_free,
                                free_map);
            out << "\n";
        }
        mona_print_universes(out, counterexample, no_of_free, free_map);
    }

    if (satisfyingexample) {
        if (!counterexample) {
            out << "\n";
            out <<  "Free variables are: ";

            for (i = 0; i < no_of_free; i++) {
                out << free_var_names[i]<< (i == no_of_free -1 ? "": ", ") ;
            }
            out << "\n";
        }

        out << "\n";
        out << "A satisfying example is:\n";
        if (!satisfyingexample->empty) {
            out << "Booleans:\n";
            mona_print_one_path(out, BDD_ROOT(satisfyingexample->bddm,
                                              satisfyingexample->behavior_handle),
                                satisfyingexample->state,
                                satisfyingexample->bddm,
                                no_of_free,
                                free_map);
            out << "\n";
        }
        mona_print_universes(out, satisfyingexample, no_of_free, free_map);
    }

    gtaFreeTrees();
}


static void mona_printTypePosComps(std::ostream &out, Tree *tree, int num, int idx, unsigned index,
                                   int *first, int begin, int all, char path[],
                                   int type, int variant) {
    if (tree && !tree->empty) {
        if (num > 1) {
            mona_printTypePosComps(out, tree->left, (num+1)/2, idx, index, first, begin, all, path, type, variant);
            mona_printTypePosComps(out, tree->right, num/2, idx+(num+1)/2, index, first, begin, all, path, type, variant);
        } else if (num == 1) {
            char *component = treetypes[type].componentName[variant][idx];
            char *newpath = (char *) mem_alloc(strlen(path)+strlen(component)+2);
            sprintf(newpath, "%s%s%s", path, begin ? "" : ".", component);
            mona_printTypePositions(out, tree, index, first, 0, all, newpath, treetypes[type].componentType[variant][idx]);
            mem_free(newpath);
        }
    }
}


static void mona_printTypePosVariants(std::ostream &out, Tree *tree, int num, int idx, unsigned index, int *first, int begin, int all, char path[], int type) {
    if (tree && !tree->empty) {
        if (num > 1) {
            mona_printTypePosVariants(out, tree->left, (num+1)/2, idx, index, first, begin, all, path, type);
            mona_printTypePosVariants(out, tree->right, num/2, idx+(num+1)/2, index, first, begin, all, path, type);
        } else {
            int n = treetypes[type].numComponents[idx];
            char *variant = treetypes[type].variantName[idx];
            char *newpath = (char *) mem_alloc(strlen(path)+strlen(variant)+2);
            sprintf(newpath, "%s%s%s", path, begin ? "" : ".", variant);
            mona_printTypePosComps(out, tree->left, (n+1)/2, 0, index, first, 0, all, newpath, type, idx);
            mona_printTypePosComps(out, tree->right, n/2, (n+1)/2, index, first, 0, all, newpath, type, idx);
            mem_free(newpath);
        }
    }
}


static void mona_printTypePositions(std::ostream &out, Tree *tree, unsigned index, int *first, int begin, int all, char path[], int type) {
    if (tree && !tree->empty) {
        trace_descr t, p;
        t = p = find_one_path(tree->bddm, bdd_roots(tree->bddm)[tree->behavior_handle], tree->state);
        while (t && (t->index != index)) {
            t = t->next;
        }
        if (t && t->value) { /* read a 1? */
            if (!*first) {
                out << ",";
            }
            out << path;
            *first = 0;
        }
        kill_trace(p);
        if (all || *first) {
            mona_printTypePosVariants(out, tree, treetypes[type].numVariants, 0, index, first, begin, all, path, type);
        }
    }
}


static Tree *mona_findNode(Tree *tree, char *pos, int i) {
    while (tree && pos[i]) {
        switch (pos[i]) {
        case '0':
            tree = tree->left;
            break;
        case '1':
            tree = tree->right;
            break;
        }
        i++;
    }
    return tree;
}


static Tree *mona_printTreeRootComps(std::ostream &out, Tree *tree, int num, int idx, unsigned index, char path[], int type, int variant) {
    Tree *res = 0;
    if (tree && !tree->empty) {
        if (num > 1) {
            res = mona_printTreeRootComps(out, tree->left, (num+1)/2, idx, index, path, type, variant);
            if (!res) {
                res = mona_printTreeRootComps(out, tree->right, num/2, idx+(num+1)/2, index, path, type, variant);
            }
        } else if (num == 1) {
            char *component = treetypes[type].componentName[variant][idx];
            char *newpath = (char *) mem_alloc(strlen(path)+strlen(component)+2);
            sprintf(newpath, "%s%s.", path, component);
            res = mona_printTreeRoot(out, tree, index, treetypes[type].componentType[variant][idx], newpath);
            mem_free(newpath);
        }
    }
    return res;
}


static Tree *mona_printTreeRootVariants(std::ostream &out, Tree *tree, int num, int idx, unsigned index, char path[], int type) {
    Tree *res = 0;
    if (tree && !tree->empty) {
        if (num > 1) {
            res = mona_printTreeRootVariants(out, tree->left, (num+1)/2, idx, index, path, type);
            if (!res) {
                res = mona_printTreeRootVariants(out, tree->right, num/2, idx+(num+1)/2, index, path, type);
            }
        } else {
            int n = treetypes[type].numComponents[idx];
            char *variant = treetypes[type].variantName[idx];
            char *newpath = (char *) mem_alloc(strlen(path)+strlen(variant)+2);
            sprintf(newpath, "%s%s.", path, variant);
            res = mona_printTreeRootComps(out, tree->left, (n+1)/2, 0, index, newpath, type, idx);
            if (!res) {
                res = mona_printTreeRootComps(out, tree->right, n/2, (n+1)/2, index, newpath, type, idx);
            }
            mem_free(newpath);
        }
    }
    return res;
}


static Tree *mona_printTreeRoot(std::ostream &out, Tree *tree, unsigned index, int type, char *path) {
    Tree *res = 0;
    if (tree && !tree->empty) {
        trace_descr t, p =
            find_one_path(tree->bddm,
                          bdd_roots(tree->bddm)[tree->behavior_handle],
                          tree->state);
        t = p;
        while (t && (t->index != index)) {
            t = t->next;
        }
        if (t && t->value) { /* read a 1? */
            out << path;
            res = tree;
        }
        kill_trace(p);
        if (!res) {
            res = mona_printTreeRootVariants(out, tree, treetypes[type].numVariants, 0, index, path, type);
        }
    }
    return res;
}


static int mona_findVariant(Tree *tree, int num, int idx, Tree **node, unsigned index) {
    /* find the (unique) leaf node with a 1 */
    int v = -1;
    if (tree && !tree->empty) {
        if (num > 1) { /* search the variant-tree */
            v = mona_findVariant(tree->left, (num+1)/2, idx, node, index);
            if (v == -1) {
                v = mona_findVariant(tree->right, num/2, idx+(num+1)/2, node, index);
            }
        } else {
            trace_descr t, p =
                find_one_path(tree->bddm,
                              bdd_roots(tree->bddm)[tree->behavior_handle],
                              tree->state);
            t = p;
            while (t && (t->index != index)) {
                t = t->next;
            }
            if (t && t->value) { /* read a 1? */
                v = idx;    /* found the variant */
            }
            kill_trace(p);
            *node = tree; /* remember the node */
        }
    }
    return v;
}


static Tree *mona_findComponent(Tree *tree, int num, int c) {
    /* find the c'th leaf node in tree with num leaves */
    while (num > 1) {
        if (tree->empty) {
            return 0;
        }
        if (c < (num+1)/2) {
            tree = tree->left;
            num = (num+1)/2;
        } else {
            tree = tree->right;
            c = c - (num+1)/2;
            num = num/2;
        }
    }
    return tree;
}


static void mona_printTypedTree(std::ostream &out, int type, Tree *tree, unsigned index) {
    int v, c;
    Tree *node;
    int numComp;
    if (!tree) {
        out << "?";
        return;
    }
    invariant(type != -1);
    invariant(guide.ssUniv[tree->d] >= 0);
    v = mona_findVariant(tree, treetypes[type].numVariants, 0, &node, index);
    if (v == -1) {
        out << "?";
        return;
    }
    printf(treetypes[type].variantName[v]);
    numComp = treetypes[type].numComponents[v];
    if (numComp > 0) {
        out << "(";
        if (numComp > 1) {
            for (c = 0; c < numComp; c++) {
                if (c != 0) {
                    out << ",";
                }
                mona_printTypedTree(out, treetypes[type].componentType[v][c], mona_findComponent(node, numComp, c), index);
            }
        } else { /* only one component, dummy on right */
            mona_printTypedTree(out, treetypes[type].componentType[v][0], node->left, index);
        }
        out << ")";
    }
}

static void mona_printTypeExample(std::ostream &out, Tree *example, unsigned num, char *names[], char orders[], unsigned indices[], int *univs[], int trees[]) {
    trace_descr bools;
    int i;

    bools = find_one_path(example->bddm, BDD_ROOT(example->bddm, example->behavior_handle), example->state);
    for (i = 0; i < num; i++) {
        out << " " << names[i] << " = ";
        switch (orders[i]) {
        case 0: { /* Boolean variable */
            trace_descr t = bools;
            while (t && (t->index != indices[i])) {
                t = t->next;
            }
            if (t && t->value) {
                out << "true\n";
            } else {
                out << "false\n";
            }
            break;
        }
        case 1: { /* first-order variable */
            int j, first = 1, any = 0;
            for (j = 0; univs[i][j] != -1; j++) {
                int u = univs[i][j];
                Tree *t = mona_findNode(example, guide.univPos[u], 0);
                if (t) {
                    char *univname = guide.univName[u];
                    char *path = (char *) mem_alloc(strlen(univname)+2);
                    sprintf(path, "%s:", univname);
                    mona_printTypePositions(out, t, indices[i], &first, 1, 0, path, guide.ssType[t->d]);
                    if (!first) {
                        any = 1;
                    }
                    mem_free(path);
                }
            }
            if (!any) {
                out << "?";
            }
            out << "\n";
            break;
        }
        case 2: { /* second-order variable */
            if (trees[i]) { /* print as typed tree */
                int j, any = 0;
                for (j = 0; univs[i][j] != -1 && !any; j++) {
                    int u = univs[i][j];
                    Tree *t = mona_findNode(example, guide.univPos[u], 0);
                    if (t) {
                        char *univname = guide.univName[u];
                        char *path = (char *) mem_alloc(strlen(univname)+2);
                        sprintf(path, "%s:", univname);
                        t = mona_printTreeRoot(out, t, indices[i], guide.ssType[t->d], path);
                        mem_free(path);
                        if (t) {
                            mona_printTypedTree(out, guide.ssType[t->d], t, indices[i]);
                            any = 1;
                        }
                    }
                }
                if (!any) {
                    out << "?";
                }
                out << "\n";
            } else { /* print as set of positions */
                int j, first = 1;
                out << "{";
                for (j = 0; univs[i][j] != -1; j++) {
                    int u = univs[i][j];
                    Tree *t = mona_findNode(example, guide.univPos[u], 0);
                    if (t) {
                        char *univname = guide.univName[u];
                        char *path = (char *) mem_alloc(strlen(univname)+2);
                        sprintf(path, "%s:", univname);
                        mona_printTypePositions(out, t, indices[i], &first, 1, 1, path, guide.ssType[t->d]);
                        mem_free(path);
                    }
                }
                out << "}\n";
            }
            break;
        }
        }
    }
    kill_trace(bools);
}


void mona_gtaTypeAnalyze(std::ostream &out, GTA *a, unsigned num, char *names[], char orders[], unsigned indices[], int *univs[], int trees[]) {
    Tree *counterexample, *satisfyingexample;

    counterexample = gtaMakeExample(a, -1);
    satisfyingexample = gtaMakeExample(a, 1);

    if (!counterexample && satisfyingexample) {
        out << "Formula is valid\n";
    } else if (!satisfyingexample) {
        out << "Formula is unsatisfiable\n";
    }

    if (counterexample) {
        out << "A counter-example is:\n";
        mona_printTypeExample(out, counterexample, num, names, orders, indices, univs, trees);
    }
    if (satisfyingexample) {
        if (counterexample) {
            out << "\n";
        }

        out << "A satisfying example is:\n";
        mona_printTypeExample(out, satisfyingexample, num, names, orders,   indices, univs, trees);
    }
    gtaFreeTrees();
}



static void mona_dfaPrintVitals(std::ostream &out, DFA *a) {
    unsigned i = bdd_size(a->bddm);

    out << "\n";
    out << "Automaton has " << a->ns << " state" << (a->ns==1 ? "" : "s") << " and " << i << " BDD-node" << (i==1 ? "" : "s") << "\n";
}


void mona_dfaPrint(std::ostream &out, DFA *a, int no_free_vars, char **free_variables, unsigned *offsets) {
    paths state_paths, pp;
    trace_descr tp;
    int i, j, any = 0;

    out << "DFA for formula with free variables: ";

    for (i = 0; i < no_free_vars; i++) {
        out <<     free_variables[i] << " ";
    }
    out << "\n";


    out << "Initial state: " << a-> s << "\n";
    out << "Accepting states: ";
    for (i = 0; i < a->ns; i++)
        if (a->f[i] == 1) {
            out << i << " ";
        }
    out << "\n";

    out << "Rejecting states: ";
    for (i = 0; i < a->ns; i++)
        if (a->f[i] == -1) {
            out << i  << " ";
        }
    out << "\n";

    for (i = 0; i < a->ns; i++)
        if (a->f[i] == 0) {
            any = 1;
            break;
        }
    if (any) {
        out << "Don't-care states: ";
        for (i = 0; i < a->ns; i++)
            if (a->f[i] == 0) {
                out << i << " ";
            }
        out << "\n";
    }


    mona_dfaPrintVitals(out, a);

    out << "Transitions:\n";

    for (i = 0; i < a->ns; i++) {
        state_paths = pp = make_paths(a->bddm, a->q[i]);

        while (pp) {
            out << "State " << i << ": ";

            for (j = 0; j < no_free_vars; j++) {
                for (tp = pp->trace; tp && (tp->index != offsets[j]); tp = tp->next);

                if (tp) {
                    if (tp->value) {
                        out << "1";
                    } else {
                        out << "0";
                    }
                } else {
                    out << "X";
                }
            }

            out << " -> state " << pp->to << "\n";

            pp = pp->next;
        }

        kill_paths(state_paths);
    }
}


void mona_gtaPrint(std::ostream &out, GTA *P, unsigned *offs, unsigned no_offs, char **free_vars, int inherited_acceptance) {
    unsigned lp, rp, p, any = 0;
    boolean ***inheritedAcceptance = 0;

    if (inherited_acceptance) {
        inheritedAcceptance = gtaCalcInheritedAcceptance(P);
    }

    out << "GTA for formula with free variables: ";
    for (p = 0; p < no_offs; p++) {
        out <<   free_vars[p]     << " ";
    }
    out << "\n";

    out << "Accepting states: ";
    for (p = 0; p < P->ss[0].size; p++)
        if (P->final[p] == 1) {
            out << p << " ";
        }
    out << "\n";

    out << "Rejecting states: ";
    for (p = 0; p < P->ss[0].size; p++)
        if (P->final[p] == -1) {
            out << p << " ";
        }
    for (p = 0; p < P->ss[0].size; p++)
        if (P->final[p] == 0) {
            any = 1;
            break;
        }
    out << "\n";

    if (any) {

        out << "Don't-care states: ";
        for (p = 0; p < P->ss[0].size; p++)
            if (P->final[p] == 0) {
                out << p << " ";
            }
        out << "\n";
    }


    for (p = 0; p < guide.numSs; p++) {
        out << "\n";
        out << "State space "<< p<< " '" << guide.ssName[p] << "' (size " << P->ss[p].size << "):\n";
        out << "Initial state: " << P->ss[p].initial << "\n";
        out << "Transitions:\n";
        for (lp = 0; lp < P->ss[guide.muLeft[p]].size; lp++) {
            for (rp = 0; rp < P->ss[guide.muRight[p]].size; rp++)
                mona_print_bddpaths(out, lp, rp, P->ss[p].bddm, BDD_ROOT(P->ss[p].bddm, BEH(P->ss[p], lp, rp)), no_offs, offs);
        }
        if (inherited_acceptance) {
            int s, k;
            out << "Inherited-acceptance:\n";
            for (k = 1; k <= 7; k++) {
                for (s = 0; s < P->ss[p].size; s++)
                    if (inheritedAcceptance[p][s][-1] +
                            inheritedAcceptance[p][s][0]*2 +
                            inheritedAcceptance[p][s][1]*4 == k) {
                        break;
                    }
                if (s < P->ss[p].size) {
                    char *kind[] = {
                        "reject", "don't care", "don't care or reject",
                        "accept", "accept or reject", "accept or don't care",
                        "anything"
                    };
                    out << "States leading to " << kind[k-1] << ": ";
                    for (s = 0; s < P->ss[p].size; s++)
                        if (inheritedAcceptance[p][s][-1] +
                                inheritedAcceptance[p][s][0]*2 +
                                inheritedAcceptance[p][s][1]*4 == k) {
                            out << s << " ";
                        }
                    out << "\n";
                }
            }
        }
    }
    if (inherited_acceptance) {
        gtaFreeInheritedAcceptance(inheritedAcceptance);
    }
}


void mona_dfaPrintVerbose(std::ostream &out, DFA *a) {
    paths state_paths, pp;
    trace_descr tp;
    int i;

    out << "Resulting DFA:\n";

    out << "Initial state: " << a->s << "\n";
    out << "Accepting states: ";
    for (i = 0; i < a->ns; i++)
        if (a->f[i] == 1) {
            out << i << " ";
        }

    out << "\n";

    out << "Rejecting states: ";
    for (i = 0; i < a->ns; i++)
        if (a->f[i] == -1) {
            out << i << " ";
        }

    out << "\n";

    out << "Don't-care states: ";
    for (i = 0; i < a->ns; i++)
        if (a->f[i] == 0) {
            out << i << " ";
        }

    out  << "\n";

    out << "Transitions:\n";

    for (i = 0; i < a->ns; i++) {
        state_paths = pp = make_paths(a->bddm, a->q[i]);

        while (pp) {
            out << "State " << i << ": ";

            for (tp = pp->trace; tp; tp = tp->next) {
                out << "@" << tp->index << "=" << (tp->value ? '1' : '0');
                if (tp->next) {
                    out << ", ";
                }
            }

            out <<  " -> state " << pp->to << "\n";
            pp = pp->next;
        }

        kill_paths(state_paths);
    }
    out << std::endl;
}


static void mona_print_bddpaths_verbose(std::ostream &out, unsigned p, unsigned q, bdd_manager *bddm, unsigned b) {
    paths state_paths, pp;
    trace_descr tp;

    state_paths = pp = make_paths(bddm, b);

    while (pp) {
        out << "(" << p << "," << q << ",";

        for (tp = pp->trace; tp; tp = tp->next) {
            out << "#" << tp->index << "=" << (tp->value ? '1' : '0');
            if (tp->next) {
                out << ", ";
            }
        }

        out << ") -> " << pp->to << "\n";
        pp = pp->next;
    }

    kill_paths(state_paths);
}


void mona_gtaPrintVerbose(std::ostream &out, GTA *P) {
    unsigned lp,rp,p,a = 0;

    out << "Resulting GTA:\n" ;
    out << "Accepting states: ";
    for (p = 0; p < P->ss[0].size; p++)
        if (P->final[p] == 1) {
            out << p << " ";
        }
    out << "\nRejecting states: ";
    for (p = 0; p < P->ss[0].size; p++)
        if (P->final[p] == -1) {
            out << p << " ";
        }
    out << "\nDon't-care states: ";
    for (p = 0; p < P->ss[0].size; p++)
        if (P->final[p] == 0) {
            a = 1;
            break;
        }
    if (a) {
        for (p = 0; p < P->ss[0].size; p++)
            if (P->final[p] == 0) {
                out << p << " ";
            }
        out << "\n";
    }

    for(p = 0; p < guide.numSs; p++) {
        out << "\nState space " << p << " '" << guide.ssName[p] << "' (size " << P->ss[p].size << "):\n";
        out << "Initial state: " << P->ss[p].initial << "\n";
        out << "Transitions:\n";

#ifdef DUMP_RAW
        for(lp = 0; lp < P->ss[guide.muLeft[p]].size; lp++)
            for(rp = 0; rp < P->ss[guide.muRight[p]].size; rp++) {
                out << "(" << lp << "," << rp << ") node: " << BDD_ROOT(P->ss[p].bddm, BEH(P->ss[p], lp, rp)) << "\n";
            }
        out << "BDD nodes:\n";
        bddDump(P->ss[p].bddm);
#else
        for(lp = 0; lp < P->ss[guide.muLeft[p]].size; lp++)
            for(rp = 0; rp < P->ss[guide.muRight[p]].size; rp++)
                mona_print_bddpaths_verbose(out, lp, rp, P->ss[p].bddm,
                                            BDD_ROOT(P->ss[p].bddm, BEH(P->ss[p], lp, rp)));
#endif
    }
    out << std::endl;
}


void mona_print_bddpaths(std::ostream &out, unsigned p, unsigned q, bdd_manager *bddm, unsigned b, unsigned no_free_vars, unsigned *offsets) {
    paths state_paths, pp;
    trace_descr tp;
    int j;

    state_paths = pp = make_paths(bddm, b);

    while (pp) {
        out << "(" << p << "," << q << ",";
        for (j = 0; j < no_free_vars; j++) {
            for (tp = pp->trace; tp && (tp->index != offsets[j]); tp = tp->next);

            if (tp) {
                if (tp->value)
                    out << "1";
                else
                    out << "0";
            } else
                out << "X";
        }

        out << ") -> " << pp->to << "\n";
        pp = pp->next;
    }

    kill_paths(state_paths);
}
