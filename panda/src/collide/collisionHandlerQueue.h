// Filename: collisionHandlerQueue.h
// Created by:  drose (16Mar02)
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

#ifndef COLLISIONHANDLERQUEUE_H
#define COLLISIONHANDLERQUEUE_H

#include "pandabase.h"

#include "collisionHandler.h"
#include "collisionEntry.h"

////////////////////////////////////////////////////////////////////
//       Class : CollisionHandlerQueue
// Description : A special kind of CollisionHandler that does nothing
//               except remember the CollisionEntries detected the
//               last pass.  This set of CollisionEntries may then be
//               queried by the calling function.  It's primarily
//               useful when a simple intersection test is being made,
//               e.g. for picking from the window.
////////////////////////////////////////////////////////////////////
class EXPCL_PANDA_COLLIDE CollisionHandlerQueue : public CollisionHandler {
PUBLISHED:
  CollisionHandlerQueue();

public:
  virtual void begin_group();
  virtual void add_entry(CollisionEntry *entry);

PUBLISHED:
  void sort_entries();
  void clear_entries();

  int get_num_entries() const;
  CollisionEntry *get_entry(int n) const;

  void output(ostream &out) const;
  void write(ostream &out, int indent_level = 0) const;

private:
  typedef pvector< PT(CollisionEntry) > Entries;
  Entries _entries;

public:
  static TypeHandle get_class_type() {
    return _type_handle;
  }
  static void init_type() {
    CollisionHandler::init_type();
    register_type(_type_handle, "CollisionHandlerQueue",
                  CollisionHandler::get_class_type());
  }
  virtual TypeHandle get_type() const {
    return get_class_type();
  }
  virtual TypeHandle force_init_type() {init_type(); return get_class_type();}

private:
  static TypeHandle _type_handle;
};

INLINE ostream &operator << (ostream &out, const CollisionHandlerQueue &chq) {
  chq.output(out);
  return out;
}

#endif



