#include <csdl.h>

typedef struct {
  OPDS h;
  MYFLT *out, *in1, *in2;
} MULT;


int mult_scalar(CSOUND *csound, MULT *p) {
  *p->out = *p->in1 * *p->in2;
  return OK;
}

int mult_vector(CSOUND *csound, MULT *p) {
  MYFLT *out = p->out;
  MYFLT *in1 = p->in1;
  MYFLT *in2 = p->in2;
  uint32_t    offset = p->h.insdshead->ksmps_offset;
  uint32_t    early  = p->h.insdshead->ksmps_no_end;
  uint32_t    n, nsmps = CS_KSMPS;

  if (UNLIKELY(offset)) memset(out, '\0', offset*sizeof(MYFLT));
    if (UNLIKELY(early)) {
      nsmps -= early;
      memset(&out[nsmps], '\0', early*sizeof(MYFLT));
    }
  
  for(n = offset; n < nsmps; n++) 
    out[n] = in1[n] * in2[n];
  
  return OK;
}

static OENTRY localops[] =
  {
   { "mult", sizeof(MULT), 0, 2, "a", "aa",
     NULL, (SUBR) mult_vector },
   { "mult", sizeof(MULT), 0, 2, "k", "kk",
     NULL, (SUBR) mult_scalar },
   { "mult", sizeof(MULT), 0, 1, "i", "ii",
        (SUBR) mult_vector, NULL }
  };

LINKAGE
