/***************************************************************************

 NBalance.mcc - New Balance MUI Custom Class
 Copyright (C) 2008-2021 NList Open Source Team

 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.

 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.

 NBalance class Support Site:  http://www.sf.net/projects/nlist-classes

 $Id$

***************************************************************************/

#if !defined(__AROS__) && (defined(__VBCC__) || defined(NO_INLINE_STDARG))
#if defined(_M68000) || defined(__M68000) || defined(__mc68000)

#include <exec/types.h>

/* FIX V45 breakage... */
#if INCLUDE_VERSION < 45
#define MY_CONST_STRPTR CONST_STRPTR
#else
#define MY_CONST_STRPTR CONST STRPTR
#endif

#include <proto/intuition.h>

APTR NewObject( struct IClass *classPtr, CONST_STRPTR classID, Tag tag1, ... )
{ return NewObjectA(classPtr, classID, (struct TagItem *)&tag1); }
ULONG SetAttrs( APTR object, ULONG tag1, ... )
{ return SetAttrsA(object, (struct TagItem *)&tag1); }
VOID SetWindowPointer( struct Window *win, Tag tag1, ... )
{ SetWindowPointerA(win, (struct TagItem *)&tag1); }

#include <proto/graphics.h>

LONG ObtainBestPen( struct ColorMap *cm, ULONG r, ULONG g, ULONG b, Tag tag1Type, ... )
{ return ObtainBestPenA(cm, r, g, b, (CONST struct TagItem *)&tag1Type); }

#else
  #error "VARGS stubs are only save on m68k systems!"
#endif
#endif
