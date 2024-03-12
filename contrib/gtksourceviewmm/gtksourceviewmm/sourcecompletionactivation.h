// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GTKSOURCEVIEWMM_SOURCECOMPLETIONACTIVATION_H
#define _GTKSOURCEVIEWMM_SOURCECOMPLETIONACTIVATION_H


#include <glibmm.h>

/* sourcecompletionactivation.h
 *
 * Copyright (C) 2010 Krzesimir Nowak
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


namespace Gsv
{
// TODO: need docs. krnowak
/** @addtogroup gtksourceviewmmEnums gtksourceviewmm Enums and Flags */

/** An enum type specifying something bla bla bla, probably type of activation.
 *
 * @newin{2,10}
 * @ingroup gtksourceviewmmEnums
 * @par Bitwise operators:
 * <tt>%SourceCompletionActivation operator|(SourceCompletionActivation, SourceCompletionActivation)</tt><br>
 * <tt>%SourceCompletionActivation operator&(SourceCompletionActivation, SourceCompletionActivation)</tt><br>
 * <tt>%SourceCompletionActivation operator^(SourceCompletionActivation, SourceCompletionActivation)</tt><br>
 * <tt>%SourceCompletionActivation operator~(SourceCompletionActivation)</tt><br>
 * <tt>%SourceCompletionActivation& operator|=(SourceCompletionActivation&, SourceCompletionActivation)</tt><br>
 * <tt>%SourceCompletionActivation& operator&=(SourceCompletionActivation&, SourceCompletionActivation)</tt><br>
 * <tt>%SourceCompletionActivation& operator^=(SourceCompletionActivation&, SourceCompletionActivation)</tt><br>
 */
enum SourceCompletionActivation
{
  SOURCE_COMPLETION_ACTIVATION_NONE = 0x0,
  SOURCE_COMPLETION_ACTIVATION_INTERACTIVE = 1 << 0,
  SOURCE_COMPLETION_ACTIVATION_USER_REQUESTED = 1 << 1
};

/** @ingroup gtksourceviewmmEnums */
inline SourceCompletionActivation operator|(SourceCompletionActivation lhs, SourceCompletionActivation rhs)
  { return static_cast<SourceCompletionActivation>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup gtksourceviewmmEnums */
inline SourceCompletionActivation operator&(SourceCompletionActivation lhs, SourceCompletionActivation rhs)
  { return static_cast<SourceCompletionActivation>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup gtksourceviewmmEnums */
inline SourceCompletionActivation operator^(SourceCompletionActivation lhs, SourceCompletionActivation rhs)
  { return static_cast<SourceCompletionActivation>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup gtksourceviewmmEnums */
inline SourceCompletionActivation operator~(SourceCompletionActivation flags)
  { return static_cast<SourceCompletionActivation>(~static_cast<unsigned>(flags)); }

/** @ingroup gtksourceviewmmEnums */
inline SourceCompletionActivation& operator|=(SourceCompletionActivation& lhs, SourceCompletionActivation rhs)
  { return (lhs = static_cast<SourceCompletionActivation>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup gtksourceviewmmEnums */
inline SourceCompletionActivation& operator&=(SourceCompletionActivation& lhs, SourceCompletionActivation rhs)
  { return (lhs = static_cast<SourceCompletionActivation>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup gtksourceviewmmEnums */
inline SourceCompletionActivation& operator^=(SourceCompletionActivation& lhs, SourceCompletionActivation rhs)
  { return (lhs = static_cast<SourceCompletionActivation>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }

} // namespace Gsv


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gsv::SourceCompletionActivation> : public Glib::Value_Flags<Gsv::SourceCompletionActivation>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gsv
{

 /** @var SourceCompletionActivation SOURCE_COMPLETION_ACTIVATION_NONE
  * None.
  */
 /** @var SourceCompletionActivation SOURCE_COMPLETION_ACTIVATION_INTERACTIVE
  * Interactive activation.
  */
 /** @var SourceCompletionActivation SOURCE_COMPLETION_ACTIVATION_USER_REQUESTED
  * User requested activation.
  *
  * For example through a keyboard accelerator from the view.
  */

} // namespace Gsv


#endif /* _GTKSOURCEVIEWMM_SOURCECOMPLETIONACTIVATION_H */
