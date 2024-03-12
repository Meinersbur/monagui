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
Object that stores what to insert when a completion is activated
*/

#include "completionitem.h"


Glib::RefPtr<CompletionItem>CompletionItem::create(const char *insertBeforeCursor, const char *insertAtCursor, const char *insertAfterCursor, const char *tag, const CompletionContext &context, const char *explanation) {
    return Glib::RefPtr<CompletionItem>(new CompletionItem(insertBeforeCursor, insertAtCursor, insertAfterCursor, tag, context, explanation));
}


CompletionItem::~CompletionItem() {
    //dtor
}


CompletionItem::CompletionItem(const char *insertBeforeCursor, const char *insertAtCursor, const char *insertAfterCursor, const char *tag, const CompletionContext &context, const char *explanation)  :
    Glib::ObjectBase(typeid(CompletionItem)),
    SourceCompletionItem(tag, ustring() + insertBeforeCursor + insertAtCursor + insertAfterCursor, Gtk::Stock::APPLY, explanation ? explanation : ustring()) {
    //ctor
    this->insertBeforeCursor = insertBeforeCursor;
    this->insertAtCursor = insertAtCursor;
    this->insertAfterCursor = insertAfterCursor;
    this->tag = tag;
    this->explanation = explanation;
    this->context = &context;
}


bool CompletionItem:: suggestFollow(const std::vector<int> &yyStack) const {
    return context->suggestFollow(yyStack);
}
