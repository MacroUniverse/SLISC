#pragma once
#include "global.h"
#include "Bit.h"
#include "arf.h"
#include "acb_hypgeom.h"

namespace slisc {

// get a quad precision number from arf_t type
// similar to arf_get_d()
inline void arf_get_q(Qdoub_O v, const arf_t x, arf_rnd_t rnd)
{
	arf_t t;
	mp_srcptr tp;
	mp_size_t tn;

	arf_init(t);
	arf_set_round(t, x, 113, rnd);
	ARF_GET_MPN_READONLY(tp, tn, t);
	if (tn == 1)
		v = (Qdoub)(tp[0]);
	else if (tn == 2)
		v = (Qdoub)(tp[1]) + (Qdoub)(tp[0]) * ldexpq(1,-FLINT_BITS);
	else if (tn == 3)
		v = (Qdoub)(tp[2]) + (Qdoub)(tp[1]) * ldexpq(1,-FLINT_BITS) + (Qdoub)(tp[0]) * ldexpq(1,-2*FLINT_BITS);
	else if (tn == 4)
		v = (Qdoub)(tp[3]) + (Qdoub)(tp[2]) * ldexpq(1,-FLINT_BITS) + (Qdoub)(tp[1]) * ldexpq(1,-2*FLINT_BITS) + (Qdoub)(tp[0]) * ldexpq(1,-3*FLINT_BITS);
	else
		SLS_ERR("not implemented!");

	v = ldexpq(v, ARF_EXP(t) - FLINT_BITS);

	if (ARF_SGNBIT(t))
		v = -v;
	arf_clear(t);
}

// similar to arb_get_str()
inline char * arf_get_str(arf_t x, slong prec)
{
	arb_t y; arb_init(y);
	arb_set_arf(y, x);
	char *p = arb_get_str(y, prec, ARB_STR_MORE);
	arb_clear(y);
	return p;
}

// similar to arf_set_d()
inline void arf_set_q(arf_t x, Qdoub_I q0)
{
	Qdoub q = q0;
	if (sizeof(slong) != 8 || sizeof(short int) != 2)
		SLS_ERR("something wrong!");
// delete 2 bytes sign and exponent, then split into 2 Llong types
	Uchar *p = (Uchar*)&q;
	Bool negative = bitL(p+15, 0);
	unset_bitL(p+15, 0);
    short int pw = *(short int*)(p+14) - 16383;
    p[14] = 0; p[15] = 0;
    long long *pL0 = (long long*)p;
	long long *pL1 = (long long*)(p+7);
	arf_t tmp; arf_init(tmp);
	arb_t t2; arb_init(t2);
	arf_set_si_2exp_si(x, *pL1, pw-56);
	p[7] = 0;
	arf_set_si_2exp_si(tmp, *pL0, pw-112);
	arf_add(x, x, tmp, 123, (arf_rnd_t)ARF_PREC_EXACT);
	if (pw != -16383 && pw != 16384) {
		arf_set_si_2exp_si(tmp, 1, pw);
		arf_add(x, x, tmp, 123, (arf_rnd_t)ARF_PREC_EXACT);
	}
	else
		SLS_ERR("not implemented!");
	if (negative)
		arf_neg(x, x);
	arf_clear(tmp);
}

// similar to arb_set_d()
inline void arb_set_q(arb_t x, Qdoub_I q)
{
	arf_set_q(arb_midref(x), q);
    mag_zero(arb_radref(x));
}

}
