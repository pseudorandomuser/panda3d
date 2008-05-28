// Filename: cullHandler.h
// Created by:  drose (23Feb02)
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

#ifndef CULLHANDLER_H
#define CULLHANDLER_H

#include "pandabase.h"
#include "cullableObject.h"
#include "graphicsStateGuardianBase.h"

class CullTraverser;

////////////////////////////////////////////////////////////////////
//       Class : CullHandler
// Description : This defines the abstract interface for an object
//               that receives Geoms identified by the CullTraverser.
//               By itself, it's not a particularly useful class; to
//               use it, derive from it and redefine record_object().
////////////////////////////////////////////////////////////////////
class EXPCL_PANDA_PGRAPH CullHandler {
public:
  CullHandler();
  virtual ~CullHandler();

  virtual void record_object(CullableObject *object, 
                             const CullTraverser *traverser);
  virtual void end_traverse();

  INLINE static void draw(CullableObject *object,
                          GraphicsStateGuardianBase *gsg,
                          bool force, Thread *current_thread);
  static void draw_with_decals(CullableObject *object,
                               GraphicsStateGuardianBase *gsg,
                               bool force, Thread *current_thread);
};

#include "cullHandler.I"

#endif


  
