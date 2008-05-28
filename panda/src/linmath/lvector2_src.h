// Filename: lvector2_src.h
// Created by:  drose (08Mar00)
//
////////////////////////////////////////////////////////////////////
//
// PANDA 3D SOFTWARE
// Copyright (c) Carnegie Mellon University.  All rights reserved.
//
// All use of this software is subject to the terms of the revised BSD
// license.  You should have received a copy of this license along
// with this source code in a file named "LICENSE."
//
////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////
//       Class : LVector2
// Description : This is a two-component vector offset.
////////////////////////////////////////////////////////////////////
class EXPCL_PANDA_LINMATH FLOATNAME(LVector2) : public FLOATNAME(LVecBase2) {
PUBLISHED:
  INLINE_LINMATH FLOATNAME(LVector2)();
  INLINE_LINMATH FLOATNAME(LVector2)(const FLOATNAME(LVecBase2) &copy);
  INLINE_LINMATH FLOATNAME(LVector2) &operator = (const FLOATNAME(LVecBase2) &copy);
  INLINE_LINMATH FLOATNAME(LVector2) &operator = (FLOATTYPE fill_value);
  INLINE_LINMATH FLOATNAME(LVector2)(FLOATTYPE fill_value);
  INLINE_LINMATH FLOATNAME(LVector2)(FLOATTYPE x, FLOATTYPE y);

  INLINE_LINMATH static const FLOATNAME(LVector2) &zero();
  INLINE_LINMATH static const FLOATNAME(LVector2) &unit_x();
  INLINE_LINMATH static const FLOATNAME(LVector2) &unit_y();

  INLINE_LINMATH FLOATNAME(LVector2) operator - () const;

  INLINE_LINMATH FLOATNAME(LVecBase2) operator + (const FLOATNAME(LVecBase2) &other) const;
  INLINE_LINMATH FLOATNAME(LVector2) operator + (const FLOATNAME(LVector2) &other) const;

  INLINE_LINMATH FLOATNAME(LVecBase2) operator - (const FLOATNAME(LVecBase2) &other) const;
  INLINE_LINMATH FLOATNAME(LVector2) operator - (const FLOATNAME(LVector2) &other) const;

  INLINE_LINMATH FLOATTYPE length() const;
  INLINE_LINMATH FLOATTYPE length_squared() const;
  INLINE_LINMATH bool normalize();
  INLINE_LINMATH FLOATNAME(LVector2) operator * (FLOATTYPE scalar) const;
  INLINE_LINMATH FLOATNAME(LVector2) operator / (FLOATTYPE scalar) const;

#ifdef HAVE_PYTHON
  INLINE_LINMATH void python_repr(ostream &out, const string &class_name) const;
#endif

public:
  static TypeHandle get_class_type() {
    return _type_handle;
  }
  static void init_type();

private:
  static TypeHandle _type_handle;
};

#include "lvector2_src.I"
