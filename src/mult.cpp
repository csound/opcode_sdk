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

