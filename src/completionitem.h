#ifndef COMPLETIONITEM_H
#define COMPLETIONITEM_H
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

#include "global.h"
#include "completioncontext.h"

#include <gtksourceviewmm.h>

#include <boost/array.hpp>
#include <vector>


class CompletionItem : public Gsv::SourceCompletionItem {
public:
    static Glib::RefPtr<CompletionItem> create(const char *insertBeforeCursor, const char *insertAtCursor, const char *insertAfterCursor, const char *tag, const CompletionContext &context, const char *explanation);

    CompletionItem(const char *insertBeforeCursor, const char *insertAtCursor, const char *insertAfterCursor, const char *tag, const CompletionContext &context, const char *explanation);
    virtual ~CompletionItem();

    bool suggestFollow(const std::vector<int> &yyStack) const;

    const char *getInsertBeforeCursor() const { return insertBeforeCursor; }
    const char *getInsertAtCursor() const { return insertAtCursor; }
    const char *getInsertAfterCursor() const { return insertAfterCursor; }
    const char *getTag() const { return tag; }
    const char *getExplanation() const { return explanation; }

private:
    const char *insertBeforeCursor;
    const char *insertAtCursor;
    const char *insertAfterCursor;
    const char *tag;
    const char *explanation;
    const CompletionContext *context;
};


#endif // COMPLETIONITEM_H
