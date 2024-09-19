/*
  mult.cpp: simple multiplying opcodes

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

struct Mult : csnd::Plugin<1, 2> {
  
  int init() {
    outargs[0] = inargs[0]*inargs[1];
    return OK;
  }

  int kperf() {
    outargs[0] = inargs[0]*inargs[1];
    return OK;
  }
  
  int aperf() {
    for(int i=offset; i < nsmps; i++)
      outargs(0)[i] = inargs(0)[i] * inargs(1)[i];	 
    return OK;
  }
  
};

struct Tprint : csnd::InPlug<1> {
  int init() {
    csound->message(args.str_data(0).data);
    return OK;
  }
};

#include <modload.h>

/* The mult opcode is overloaded for
   a, k, and i inputs. For these cases, it is
   recommended to append an identifier extension .
   to the name for debugging purposes (not strictly required).
   For the user, the extension is not used and all 
   overloads are called "mult"
*/   
void csnd::on_load(Csound *csound) {
  csnd::plugin<Mult>(csound, "mult.aa", "a", "aa", csnd::thread::a);
  csnd::plugin<Mult>(csound, "mult.kk", "k", "kk", csnd::thread::k);
  csnd::plugin<Mult>(csound, "mult.ii", "i", "ii", csnd::thread::i);
  csnd::plugin<Mult>(csound, "mult.aa", "a", "aa", csnd::thread::a);
  csnd::plugin<Tprint>(csound, "tprint", "", "S", csnd::thread::i);
}

