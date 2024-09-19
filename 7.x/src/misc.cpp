/*
  misc.cpp: miscellaneous C++ opcode examples

  Copyright (C) 2018 Victor Lazzarini
  This file is part of Csound.

  The Csound Library is free software; you can redistribute it
  and/or modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  Csound is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with Csound; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
  02110-1301 USA
*/

#include <plugin.h>
/**
  Output-only opcode: as expected with zero
  the input argument array, as it will not be
  used.
**/


struct MidiNote : csnd::Plugin<1, 0> {
  int init() {
    outargs[0] = csound->midi_note_num(this);
    return OK;
  }
};


/**
  Input-only opcode showing how
  to manipulate input args via the
  outargs[] array.

  Plugin is instantiated with out args only,
  zero in the in args.

  But we will use the outargs[] array
  as our input data.

**/

struct PrintNum : csnd::Plugin<1, 0> {
  int init() {
    char a[64];
    // input arg 1 is placed in outargs[0]
    snprintf(a, 63, "%f\n", outargs[0]);
    csound->message(std::string(a));
    return OK;
  }
};

#include <modload.h>
void csnd::on_load(Csound *csound) {
  // opcode is registered with 0 inputs and 1 output
  csnd::plugin<MidiNote>(csound, "midinotenum", "i", "", csnd::thread::i);
  // opcode is registered with 1 input and 0 outputs
  csnd::plugin<PrintNum>(csound, "printnum", "", "i", csnd::thread::i);
}
