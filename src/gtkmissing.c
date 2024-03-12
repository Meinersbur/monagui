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
This gtk_style_get function has been copied from GTK+ 2.16 source. GTK+ 2.14 
doesn't have them, but they are required by gtksourceview.
We insert dummy function for them which simply return default values. They will
be linked into the executable such that the gtksourceview library can use them.
*/

#include "guiconfig.h"
#if !HAVE_GTK_STYLE_GET

#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <gobject/gvaluecollector.h>
#include <gtk/gtkgc.h>
#include <gtk/gtkoptionmenu.h>
#include <gtk/gtkrc.h>
#include <gtk/gtkspinbutton.h>
#include <gtk/gtkstyle.h>
#include <gtk/gtkwidget.h>
#include <gtk/gtkiconfactory.h>
#include <gtk/gtksettings.h>

void
gtk_style_get_valist (GtkStyle    *style,
                      GType        widget_type,
                      const gchar *first_property_name,
                      va_list      var_args) {
    const char *property_name;
    GtkWidgetClass *klass;

    g_return_if_fail (GTK_IS_STYLE (style));

    klass = g_type_class_ref (widget_type);

    property_name = first_property_name;
    while (property_name) {
        //GParamSpec *pspec;
        //GtkRcPropertyParser parser;
        GValue my_value = {0, };
        GValue *peek_value = &my_value;
        gchar *error;

#ifdef DEBUG
        fprintf(stderr, "MK: requesting style property %s \n", property_name);
#endif
        if (strcmp(property_name, "image-spacing" )==0) {
            // 2
            g_value_init (peek_value, G_TYPE_INT );
            g_value_set_int(peek_value, 2);
            G_VALUE_LCOPY (peek_value, var_args, 0, &error);
            g_value_unset(peek_value);
        } else if (strcmp(property_name, "gtk-button-images" )==0) {
            // false
            g_value_init (peek_value, G_TYPE_BOOLEAN);
            g_value_set_boolean(peek_value, 0);
            G_VALUE_LCOPY (peek_value, var_args, 0, &error);
            g_value_unset(peek_value);
        } else     if (strcmp(property_name, "horizontal-separator" )==0) {
            // 2
            g_value_init (peek_value, G_TYPE_INT );
            g_value_set_int(peek_value, 2);
            G_VALUE_LCOPY (peek_value, var_args, 0, &error);
            g_value_unset(peek_value);
        } else {
#ifdef DEBUG
            fprintf(stderr, "Style property %s not supported\n", property_name);
#endif
            error = 1;
        }

        //peek_value = _gtk_style_peek_property_value (style, widget_type, pspec, parser);
        if (error) {
            g_warning ("%s: %s", G_STRLOC, error);
            g_free (error);
            break;
        }

        property_name = va_arg (var_args, gchar *);
    }

    g_type_class_unref (klass);
}

void
gtk_style_get (GtkStyle    *style,
               GType        widget_type,
               const gchar *first_property_name,
               ...) {
    va_list var_args;

    va_start (var_args, first_property_name);
    gtk_style_get_valist (style, widget_type, first_property_name, var_args);
    va_end (var_args);
}

#endif
