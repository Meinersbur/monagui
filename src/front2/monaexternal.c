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
This file is used to rename the symbol "export" in bdd_external.h since it is a keyword in C++
*/

#include "bdd_external.h" // Must be included before monaexternal.h, otherwise monaexternal.h does not recognize that some types have aready been defined
#include "monaexternal.h"


void bdd_export(bdd_manager *bddm, unsigned p, Table *table) {
    export(bddm, p, table);
}
