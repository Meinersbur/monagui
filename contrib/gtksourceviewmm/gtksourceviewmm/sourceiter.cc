// Generated by gtkmmproc -- DO NOT MODIFY!


#include <gtksourceviewmm/sourceiter.h>
#include <gtksourceviewmm/private/sourceiter_p.h>

#include <gtksourceview/gtksourceiter.h>
/* sourceview.hg
 * 
 * Copyright (C) 2004-2005 Jae Jang
 * Copyright (C) 2005-2006 Rob Page
 * Copyright (C) 2005-2006 Dodji Seketeli
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include "sourceiter.h"
#include <glib/gmessages.h>
namespace gtksourceview
{

SearchFlags operator| (SearchFlags lhs, SearchFlags rhs)
{
    return SearchFlags ((unsigned)lhs | (unsigned)rhs) ;
}

SearchFlags operator& (SearchFlags lhs, SearchFlags rhs)
{
    return  (SearchFlags) ((unsigned)lhs & (unsigned)rhs) ;
}

SearchFlags operator^ (SearchFlags lhs, SearchFlags rhs)
{
    return (SearchFlags) ((unsigned)lhs ^ (unsigned)rhs) ;
}

SearchFlags operator- (SearchFlags lhs)
{
    return (SearchFlags) (-(unsigned)lhs) ;
}

SearchFlags operator|= (SearchFlags &lhs, SearchFlags rhs)
{
    lhs = (SearchFlags) ((unsigned)lhs | (unsigned)rhs) ;
    return lhs ;
}

SearchFlags operator&= (SearchFlags &lhs, SearchFlags rhs)
{
    lhs = (SearchFlags) ((unsigned)lhs & (unsigned)rhs) ;
    return lhs ;
}

SearchFlags operator^= (SearchFlags &lhs, SearchFlags rhs)
{
    lhs = (SearchFlags) ((unsigned)lhs ^ (unsigned)rhs) ;
    return lhs ;
}

SourceIter::SourceIter ()
{
}

SourceIter::SourceIter (const Gtk::TextIter &iter) :
    Gtk::TextIter (iter)
{
}

SourceIter::SourceIter (const GtkTextIter* gobject) :
    Gtk::TextIter (gobject)
{
}

SourceIter::SourceIter (const SourceIter &a_iter) :
    Gtk::TextIter (a_iter)
{
    if (a_iter == *this) {return;}
    *this = a_iter ;
}

SourceIter::~SourceIter ()
{
}


bool
SourceIter::forward_search (const Glib::ustring &a_str,
                            SearchFlags a_flags,
                            Gtk::TextIter &a_match_start,
                            Gtk::TextIter &a_match_end,
                            const Gtk::TextIter &a_limit) const
{
    const GtkTextIter *gobject (gobj ()) ;
    g_return_val_if_fail (gobject, FALSE) ;
    g_return_val_if_fail (a_str.c_str (), FALSE) ;

    GtkTextIter match_start, match_end ;
    gboolean res = gtk_source_iter_forward_search (gobject,
                                                   a_str.c_str (),
                                                   (GtkSourceSearchFlags)a_flags,
                                                   &match_start,
                                                   &match_end,
                                                   a_limit.gobj ()) ;
    Gtk::TextIter res_match_start (&match_start) ;
    Gtk::TextIter res_match_end (&match_end) ;
    a_match_start = res_match_start ;
    a_match_end = res_match_end ;
    return res ;
}

bool
SourceIter::backward_search (const Glib::ustring &a_str,
                              SearchFlags a_flags,
                              Gtk::TextIter &a_match_start,
                              Gtk::TextIter &a_match_end,
                              const Gtk::TextIter &a_limit) const
{
    const GtkTextIter *gobject (gobj ()) ;
    g_return_val_if_fail (gobject, FALSE) ;
    g_return_val_if_fail (a_str.c_str (), FALSE) ;

    GtkTextIter match_start, match_end ;
    gboolean res = gtk_source_iter_backward_search (gobject,
                                                    a_str.c_str (),
                                                    (GtkSourceSearchFlags)a_flags,
                                                    &match_start,
                                                    &match_end,
                                                    a_limit.gobj ()) ;
    Gtk::TextIter res_match_start (&match_start) ;
    Gtk::TextIter res_match_end (&match_end) ;
    a_match_start = res_match_start ;
    a_match_end = res_match_end ;
    return res ;
}

}//end namespace gtksourceview


namespace
{
} // anonymous namespace

