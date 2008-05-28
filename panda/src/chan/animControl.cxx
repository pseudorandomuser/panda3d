// Filename: animControl.cxx
// Created by:  drose (19Feb99)
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

#include "animControl.h"
#include "animChannelBase.h"
#include "partBundle.h"
#include "config_chan.h"
#include "dcast.h"

TypeHandle AnimControl::_type_handle;

////////////////////////////////////////////////////////////////////
//     Function: AnimControl::Constructor
//       Access: Public
//  Description:
////////////////////////////////////////////////////////////////////
AnimControl::
AnimControl(PartBundle *part, AnimBundle *anim, int channel_index,
            const BitArray &bound_joints) {
#ifdef DO_MEMORY_USAGE
  MemoryUsage::update_type(this, get_class_type());
#endif

  _part = part;
  _anim = anim;
  _channel_index = channel_index;
  _bound_joints = bound_joints;
  set_frame_rate(_anim->get_base_frame_rate());
  set_num_frames(_anim->get_num_frames());

  _marked_frame = -1;
}

////////////////////////////////////////////////////////////////////
//     Function: AnimControl::Destructor
//       Access: Published, Virtual
//  Description:
////////////////////////////////////////////////////////////////////
AnimControl::
~AnimControl() {
  get_part()->set_control_effect(this, 0.0f);
}

////////////////////////////////////////////////////////////////////
//     Function: AnimControl::get_part
//       Access: Published
//  Description: Returns the PartBundle bound in with this
//               AnimControl.
////////////////////////////////////////////////////////////////////
PartBundle *AnimControl::
get_part() const {
  return DCAST(PartBundle, _part);
}

////////////////////////////////////////////////////////////////////
//     Function: AnimControl::output
//       Access: Published
//  Description:
////////////////////////////////////////////////////////////////////
void AnimControl::
output(ostream &out) const {
  out << "AnimControl(" << get_part()->get_name()
      << ", " << get_anim()->get_name() << ": ";
  AnimInterface::output(out);
  out << ")";
}

////////////////////////////////////////////////////////////////////
//     Function: AnimControl::channel_has_changed
//       Access: Public
//  Description: Returns true if the indicated channel value has
//               changed since the last call to mark_channels().
////////////////////////////////////////////////////////////////////
bool AnimControl::
channel_has_changed(AnimChannelBase *channel, bool frame_blend_flag) const {
  if (_marked_frame < 0) {
    return true;
  }

  int this_frame = get_frame();
  double this_frac = 0.0;
  if (frame_blend_flag) {
    this_frac = get_frac();
  }
  return channel->has_changed(_marked_frame, _marked_frac, 
                              this_frame, this_frac);
}

////////////////////////////////////////////////////////////////////
//     Function: AnimControl::mark_channels
//       Access: Public
//  Description: Marks this point as the point of reference for the
//               next call to channel_has_changed().
////////////////////////////////////////////////////////////////////
void AnimControl::
mark_channels(bool frame_blend_flag) {
  _marked_frame = get_frame();
  _marked_frac = 0.0;
  if (frame_blend_flag) {
    _marked_frac = get_frac();
  }
}

////////////////////////////////////////////////////////////////////
//     Function: AnimControl::animation_activated
//       Access: Protected, Virtual
//  Description: This is provided as a callback method for when the
//               user calls one of the play/loop/pose type methods to
//               start the animation playing.
////////////////////////////////////////////////////////////////////
void AnimControl::
animation_activated() {
  get_part()->control_activated(this);
}
