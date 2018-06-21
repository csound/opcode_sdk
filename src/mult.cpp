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

#include <modload.h>
void csnd::on_load(Csound *csound) {
  csnd::plugin<Mult>(csound, "mult", "k", "kk", csnd::thread::k);
  csnd::plugin<Mult>(csound, "mult", "i", "ii", csnd::thread::i);
  csnd::plugin<Mult>(csound, "mult", "a", "aa", csnd::thread::a);
}

