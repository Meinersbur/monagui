#ifndef MONACOMPLETIONPROVIDER_H
#define MONACOMPLETIONPROVIDER_H
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
Selects the complition items to be shown
*/

#include "global.h"
#include "editorwin.h"
#include "completionitem.h"

#include <gtksourceviewmm.h>


class  MonaCompletionProvider;
typedef Glib::RefPtr<MonaCompletionProvider> MonaCompletionProviderPtr;

class MonaCompletionProvider: public Glib::Object, public Gsv::SourceCompletionProvider {
public:
    static MonaCompletionProviderPtr create(EditorWindow *owner, const char *category, int priority);
    virtual ~MonaCompletionProvider() {}

    virtual void addCompletion(const Glib::RefPtr<CompletionItem> &completion) = 0;
    virtual void addCompletion(const char *insertBeforeCursor, const char *insertAtCursor, const char *insertAfterCursor, const char *tag, const CompletionContext &context, const char *explanation) = 0;
    virtual void addCompletion(const char *insertBeforeCursor, const char *insertAtCursor, const char *insertAfterCursor, const char *tag, const CompletionContext *context, const char *explanation) = 0;
    virtual void addIdentifierCompletion(MonaTypeTag identifierType, const CompletionContext &context) = 0;
    virtual void addIdentifierCompletion(MonaTypeTag identifierType, const CompletionContext *context) = 0;

protected:
    MonaCompletionProvider();
};

#endif // MONACOMPLETIONPROVIDER_H
