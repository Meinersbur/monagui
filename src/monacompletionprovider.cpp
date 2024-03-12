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
Selects the completion items to be shown
*/

#include "monacompletionprovider.h"

#include <boost/foreach.hpp>


class MonaCompletionProviderImpl: public MonaCompletionProvider {
public:
    MonaCompletionProviderImpl(EditorWindow *owner, const char *category, int priority);
    virtual ~MonaCompletionProviderImpl();

private:
    void addCompletion(const Glib::RefPtr<CompletionItem> &completion) ;
    void addCompletion(const char *insertBeforeCursor, const char *insertAtCursor, const char *insertAfterCursor, const char *tag, const CompletionContext &context, const char *explanation);
    void addCompletion(const char *insertBeforeCursor, const char *insertAtCursor, const char *insertAfterCursor, const char *tag, const CompletionContext *context, const char *explanation);
    void addIdentifierCompletion(MonaTypeTag identifierType, const CompletionContext &context);
    void addIdentifierCompletion(MonaTypeTag identifierType, const CompletionContext *context);

    virtual Glib::ustring get_name_vfunc() const;
    virtual void populate_vfunc(const Glib::RefPtr<Gsv::SourceCompletionContext>& context);
    virtual bool match_vfunc(const Glib::RefPtr<const Gsv::SourceCompletionContext>& context) const;
    virtual Gsv::SourceCompletionActivation get_activation_vfunc() const;
    virtual bool get_start_iter_vfunc(const Glib::RefPtr<const Gsv::SourceCompletionContext>& context, const Glib::RefPtr<const Gsv::SourceCompletionProposal>& proposal, Gtk::TextIter &iter);
    virtual bool activate_proposal_vfunc(const Glib::RefPtr<Gsv::SourceCompletionProposal>& proposal, const Gtk::TextIter &iter);
    virtual int get_interactive_delay_vfunc() const;
    virtual int get_priority_vfunc() const;

    EditorWindow *owner;
    const char *category;
    int priority ;

    std::vector<Glib::RefPtr<CompletionItem> > completions;
    std::vector<MonaTypeTag> identifierCompletions;
    std::vector<const CompletionContext *> identifierCompletionContexts;
};


// MonaCompletionProvider /////////////////////////////////////////////////////

MonaCompletionProviderPtr MonaCompletionProvider::create(EditorWindow *owner, const char *category, int priority) {
    MonaCompletionProviderPtr result(new MonaCompletionProviderImpl(owner, category,priority));
    return result;
}


MonaCompletionProvider::MonaCompletionProvider():
    Glib::Object(), Gsv::SourceCompletionProvider() {
    //ctor
}


// MonaCompletionProviderImpl /////////////////////////////////////////////////

MonaCompletionProviderImpl::MonaCompletionProviderImpl(EditorWindow *owner,const char *category,int priority):
    Glib::ObjectBase(typeid(MonaCompletionProviderImpl)), MonaCompletionProvider() {
    //ctor
    this->owner = owner;
    this->category = category;
    this->priority = priority;
}


MonaCompletionProviderImpl::~MonaCompletionProviderImpl() {
    //dtor
}


void MonaCompletionProviderImpl::addCompletion(const Glib::RefPtr< CompletionItem> &completion) {
    completions.push_back(completion);
}


void MonaCompletionProviderImpl::addCompletion(const char *insertBeforeCursor, const char *insertAtCursor, const char *insertAfterCursor, const char *tag, const CompletionContext &context, const char *explanation)  {
    addCompletion(CompletionItem::create(insertBeforeCursor, insertAtCursor, insertAfterCursor, tag, context, explanation));
}


void MonaCompletionProviderImpl::addCompletion(const char *insertBeforeCursor, const char *insertAtCursor, const char *insertAfterCursor, const char *tag, const CompletionContext *context, const char *explanation)  {
    addCompletion(CompletionItem::create(insertBeforeCursor, insertAtCursor, insertAfterCursor, tag, *context, explanation));
}


void MonaCompletionProviderImpl::addIdentifierCompletion(MonaTypeTag identifierType, const CompletionContext &context) {
    identifierCompletions.push_back(identifierType);
    identifierCompletionContexts.push_back(&context);
}


void MonaCompletionProviderImpl::addIdentifierCompletion(MonaTypeTag identifierType, const CompletionContext *context) {
    identifierCompletions.push_back(identifierType);
    identifierCompletionContexts.push_back(context);
}


Glib::ustring MonaCompletionProviderImpl::get_name_vfunc() const {
    return category;
}


void MonaCompletionProviderImpl::populate_vfunc(const Glib::RefPtr<Gsv::SourceCompletionContext>& context) {
    Glib::RefPtr<Gsv::SourceCompletionProvider> provider(this);
    provider->reference();
    std::vector<Glib::RefPtr<Gsv::SourceCompletionProposal> > proposals;

    Gtk::TextIter iter = context->get_iter();

    Glib::RefPtr<Gtk::TextBuffer> buffer = iter.get_buffer();
    int offset = iter.get_offset();

    Gtk::TextBuffer::iterator start = buffer->begin();
    Gtk::TextBuffer::iterator curser = buffer->get_iter_at_offset(offset);
    ustring str = buffer->get_text(start, curser);

    MonaPtr mona = owner->getMonaCursor(iter);
    if (!mona || mona->getCompletionState() < 0) {
        // False means that there was a syntax error before the point where we want to suggest completion
        context->add_proposals(provider, proposals, true);
        return;
    }

    const std::vector<int> &yystack = mona->getCompletionStack();
    assert(!yystack.empty());
#ifdef DEBUG
    fprintf(stderr, "Showing completion for stack: ");
    BOOST_FOREACH(int yyState , yystack) {
        fprintf(stderr, " %d", yyState);
    }
    fprintf(stderr, "\n");
#endif

    BOOST_FOREACH(const Glib::RefPtr<CompletionItem> &item, completions) {
        if (item->suggestFollow(yystack)) {
            proposals.push_back(item);
        }
    }

    if (!identifierCompletions.empty()) {
        MonaPtr monaValid = owner->getMonaValid();
        SymbolTable *symbols = monaValid ? monaValid->getSymboltable() : NULL;
        if (symbols) {
            for (size_t j = 0; j < identifierCompletions.size(); j+=1) {
                MonaTypeTag identifierType = identifierCompletions.at(j);
                const CompletionContext &context = *identifierCompletionContexts.at(j);
                if (!context.suggestFollow(yystack) ) {
                    continue;
                }

                unsigned n = symbols->noIdents;
                for (unsigned i=0; i < n; i+=1) {
                    MonaTypeTag type = symbols->getType(i);
                    if (type != identifierType) {
                        continue;
                    }
                    if (symbols->isLocal(i)) {
                        continue;
                    }

                    ustring name = symbols->getName(i);
                    Glib::RefPtr<Gsv::SourceCompletionItem> proposal = Gsv::SourceCompletionItem::create(name, name + " ", Gtk::Stock::PASTE , "Identifier " + name);
                    proposals.push_back(proposal);
                }
            }
        }
    }

    context->add_proposals(provider, proposals, true);
}


bool MonaCompletionProviderImpl::match_vfunc(const Glib::RefPtr<const Gsv::SourceCompletionContext>& /*context*/) const {
    return true;
}


Gsv::SourceCompletionActivation MonaCompletionProviderImpl::get_activation_vfunc() const {
    return Gsv::SOURCE_COMPLETION_ACTIVATION_INTERACTIVE | Gsv::SOURCE_COMPLETION_ACTIVATION_USER_REQUESTED;
}


bool MonaCompletionProviderImpl::get_start_iter_vfunc(const Glib::RefPtr<const Gsv::SourceCompletionContext>& /*context*/, const Glib::RefPtr<const Gsv::SourceCompletionProposal>& /*proposal*/, Gtk::TextIter &/*iter*/) {
    return false;
}


bool MonaCompletionProviderImpl::activate_proposal_vfunc(const Glib::RefPtr<Gsv::SourceCompletionProposal>& proposal, const Gtk::TextIter &iter) {
    Glib::RefPtr<CompletionItem > item = Glib::RefPtr<CompletionItem>::cast_dynamic(proposal);
    if (item) {
        owner->insertCompletion(item, iter);
        return true;
    }

    // If get_start_iter_vfunc and activate_proposal_vfunc return true, it will replace the string between the two iterators
    // If only activate_proposal_vfunc returns true, it will replace the word around this iter
    // If activate_proposal_vfunc returns false, it assumes that this function did the work already (as we did above)
    return false;
}


int MonaCompletionProviderImpl::get_interactive_delay_vfunc() const {
    return -1;
}


int MonaCompletionProviderImpl::get_priority_vfunc() const {
    return 10;
}
