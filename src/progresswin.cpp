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
The window with a progressbar which shows up when Mona is working
*/

#include "progresswin.h"

#include "app.h"
#include "gtkutils.h"

#include <gtkmm.h>
#include <gtksourceviewmm.h>

#include <boost/lexical_cast.hpp>
#include <boost/make_shared.hpp>

#include <vector>


class ProgressWindowImpl: public virtual Gtk::Window, public virtual ProgressWindow {
public:
    ProgressWindowImpl(BaseObjectType *cobject, const Glib::RefPtr<Gtk::Builder>& glade);
    virtual ~ProgressWindowImpl();

private:
    void reset();
    void appendOutstr(const std::string &str);
    void setProgress(const ustring &phase, double progress, const ustring &info);

    void on_abort_activate();


    Glib::RefPtr<Gtk::Builder> glade;

    Gtk::Label *topmostLabel;
    Gtk::ProgressBar *topmostProgress;

    Gtk::Button *abortBtn;
    Gsv::SourceView *progressOutput;

    double fakeProgress;
};


// ProgressWindow /////////////////////////////////////////////////////////////

ProgressWindowPtr ProgressWindow::create() {
    ProgressWindowImpl *progressWindow = NULL;
    boost::filesystem::path gladefile = app_lookup_datafile("glade", "progress.glade");

    Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create_from_file(gladefile.file_string());
    builder->get_widget_derived("ProgressWindow", progressWindow);
    if (!progressWindow) {
        throw UnexpectedException("Progress Window not loaded");
    }

    ProgressWindowPtr result (progressWindow);
    return result;
}


// ProgressWindowImpl /////////////////////////////////////////////////////////

ProgressWindowImpl::ProgressWindowImpl(BaseObjectType *cobject, const Glib::RefPtr<Gtk::Builder>& glade):
    Gtk::Window(cobject) {
    //ctor
    this->glade = glade;

    getWidgetOrFail(topmostProgress, glade, "ProgressBar");
    getWidgetOrFail(topmostLabel, glade, "ProgressLabel");
    getWidgetOrFail(progressOutput, glade, "ProgressOutput");

    getWidgetOrFail(abortBtn, glade, "AbortBtn");
    abortBtn->signal_clicked().connect(sigc::mem_fun(*this, &ProgressWindowImpl::on_abort_activate));

    fakeProgress = 0;

    reset();
}


ProgressWindowImpl::~ProgressWindowImpl() {
    //dtor
}


void ProgressWindowImpl::appendOutstr(const std::string &str) {
    Glib::RefPtr<Gsv::SourceBuffer> buffer = progressOutput->get_source_buffer();
    buffer->insert(buffer->end(), str);
#ifdef DEBUG
    puts(str.c_str());
#endif
    Gtk::TextIter endIter = buffer->end();
    progressOutput->scroll_to(endIter);
}


void ProgressWindowImpl::setProgress(const ustring &phase, double progress, const ustring &info) {
    ustring lastText = topmostLabel->get_text();
    if (lastText == phase && progress <= 0) {
        // No "real" change
        fakeProgress += (1.0 - fakeProgress) / (5.0 * 1.0 / (1.0 - fakeProgress));
        progress = fakeProgress;
    } else {
        fakeProgress = 0;
    }
    topmostLabel->set_text(phase);
    if (0.0 <= progress && progress <= 1.0) {
        topmostProgress->set_fraction(progress);
    }
    topmostProgress->set_text(info);
}


void ProgressWindowImpl::on_abort_activate() {
    abortBtn->set_sensitive(false);
    signal_abort();
}


void ProgressWindowImpl::reset() {
    GsvSourceLanguagePtr lang;
    Glib::RefPtr<Gsv::SourceBuffer> buffer = Gsv::SourceBuffer::create(lang);
    progressOutput->set_source_buffer(buffer);
    abortBtn->set_sensitive(true);
}
