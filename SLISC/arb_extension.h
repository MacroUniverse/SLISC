#pragma once
#include "global.h"
#include "Bit.h"
#include "arf.h"
#include "acb_hypgeom.h"

namespace slisc {

// similar to arb_get_str()
inline char * arf_get_str(arf_t x, slong prec)
{
	arb_t y; arb_init(y);
	arb_set_arf(y, x);
	char *p = arb_get_str(y, prec, ARB_STR_MORE);
	arb_clear(y);
	return p;
}

#ifdef SLS_USE_QUAD_MATH
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
#endif

// c++ wrapper for fmpz_t
// ref: http://flintlib.org/sphinx/fmpz.html
struct BigInt
{
	fmpz_t m_n;
	// constructors
	BigInt() {
		// printf("BigInt: default init called.\n");
		fmpz_init(m_n);
	}
	BigInt(Llong_I val)
	{
		// printf("BigInt: Llong init called.\n");
		fmpz_init(m_n); fmpz_set_si(m_n, val);
	}
	BigInt(Doub_I val)
	{
		// printf("BigInt: Doub init called.\n");
		fmpz_init(m_n); fmpz_set_d(m_n, val);
	}
	BigInt(Str_I str, Int_I base = 10)
	{
		// printf("BigInt: Str init called.\n");
		fmpz_init(m_n); fmpz_set_str(m_n, str.c_str(), base);
	}
	BigInt(const BigInt &x) // copy constructor
	{
		// printf("BigInt: copy constructor called.\n");
		fmpz_set(m_n, x.m_n);
	}
	// BigInt(BigInt&& x) // move constructor
	// {
	// 	printf("BigInt: move constructor called.\n");
	// 	fmpz_clear(m_n);
	// 	m_n = x.m_n; x.m_n = NULL;
	// }
	BigInt &operator=(const BigInt &rhs) // copy assignment
	{
		// printf("BigInt: copy assignment called.\n");
		fmpz_set(m_n, rhs.m_n); return *this;
	}
	BigInt &operator=(Llong_I rhs) { fmpz_set_si(m_n, rhs); return *this; }
	BigInt &operator=(Doub_I rhs) { fmpz_set_d(m_n, rhs); return *this; }
	BigInt &operator=(Str_I rhs) { fmpz_set_str(m_n, rhs.c_str(), 10); return *this; }
	

	~BigInt() {
		// printf("BigInt: destructor called.\n");
		fmpz_clear(m_n);
	}
};

typedef const BigInt &BigInt_I;
typedef BigInt &BigInt_O, &BigInt_IO;

inline Str to_string(const BigInt &x)
{
	char *s; s = fmpz_get_str(NULL, 10, x.m_n);
	Str str(s); free(s);
	return str;
}

// compare
inline Bool operator==(BigInt_I x, BigInt_I y)
{ return fmpz_equal(x.m_n, y.m_n); }

inline Bool operator==(BigInt_I x, Llong_I y)
{ return fmpz_equal_si(x.m_n, y); }

inline Bool operator==(Llong_I y, BigInt_I x)
{ return fmpz_equal_si(x.m_n, y); }

inline Bool operator==(BigInt_I x, Str_I y)
{ BigInt yy(y); return x == yy; }

inline Bool operator==(Str_I y, BigInt_I x)
{ BigInt yy(y); return x == yy; }

inline Bool operator!=(BigInt_I x, BigInt_I y)
{ return !(x == y); }

inline Bool operator!=(BigInt_I x, Llong_I y)
{ return !(x == y); }

inline Bool operator!=(Llong_I y, BigInt_I x)
{ return !(x == y); }

inline Bool operator!=(BigInt_I x, Str_I y)
{ return !(x == y); }

inline Bool operator<(BigInt_I x, BigInt_I y)
{ return fmpz_cmp(x.m_n, y.m_n) < 0; }

inline Bool operator<(BigInt_I x, Llong_I y)
{ return fmpz_cmp_si(x.m_n, y) < 0; }

inline Bool operator<(Llong_I y, BigInt_I x)
{ return fmpz_cmp_si(x.m_n, y) > 0; }

inline Bool operator>(BigInt_I x, BigInt_I y)
{ return fmpz_cmp(x.m_n, y.m_n) > 0; }

inline Bool operator>(BigInt_I x, Llong_I y)
{ return fmpz_cmp_si(x.m_n, y) > 0; }

inline Bool operator>(Llong_I y, BigInt_I x)
{ return fmpz_cmp_si(x.m_n, y) < 0; }

inline Bool is_odd(BigInt_I x)
{ return fmpz_is_odd(x.m_n); }

// arithmetic

inline void neg(BigInt_O x, BigInt_I y)
{ fmpz_neg(x.m_n, y.m_n); }

inline void neg(BigInt_IO x) { neg(x, x); }

inline void add(BigInt_O z, BigInt_I x, BigInt_I y)
{ fmpz_add(z.m_n, x.m_n, y.m_n); }

inline void operator+=(BigInt_IO y, BigInt_I x)
{ add(y, y, x); }

inline void add(BigInt_O z, BigInt_I x, Llong_I y)
{
	if (y > 0)
		fmpz_add_ui(z.m_n, x.m_n, y);
	else if (y < 0)
		fmpz_sub_ui(z.m_n, x.m_n, -y);
}

inline void operator+=(BigInt_IO y, Llong_I x) { add(y, y, x); }

inline void add(BigInt_O z, Llong_I y, BigInt_I x)
{ add(z, x, y); }

inline void sub(BigInt_O z, BigInt_I x, BigInt_I y)
{ fmpz_sub(z.m_n, x.m_n, y.m_n); }

inline void sub(BigInt_IO y, BigInt_I x) { sub(y, y, x); }

inline void sub(BigInt_O z, BigInt_I x, Llong_I y)
{
	if (y > 0)
		fmpz_sub_ui(z.m_n, x.m_n, y);
	else if (y < 0)
		fmpz_add_ui(z.m_n, x.m_n, -y);
}

inline void operator-=(BigInt_IO y, Llong_I x) { sub(y, y, x); }

inline void sub(BigInt_O z, Llong_I y, BigInt_I x)
{ sub(z, x, y); neg(z); }

inline void mul(BigInt_O z, BigInt_I x, BigInt_I y)
{ fmpz_mul(z.m_n, x.m_n, y.m_n); }

inline void operator*=(BigInt_IO y, BigInt_I x) { mul(y, y, x); }

inline void mul(BigInt_O z, BigInt_I x, Llong_I y)
{ fmpz_mul_si(z.m_n, x.m_n, y); }

inline void mul(BigInt_O z, Llong_I y, BigInt_I x)
{ fmpz_mul_si(z.m_n, x.m_n, y); }

inline void div(BigInt_O z, BigInt_I x, BigInt_I y)
{ fmpz_tdiv_q(z.m_n, x.m_n, y.m_n); }

inline void operator/=(BigInt_IO y, BigInt_I x)
{ div(y, x, x); }

inline void div(BigInt_O z, BigInt_I x, Llong_I y)
{ fmpz_tdiv_q_si(z.m_n, x.m_n, y); }

inline void mod(BigInt_O z, BigInt_I x, BigInt_I y)
{ fmpz_mod(z.m_n, x.m_n, y.m_n); } // always positive

inline void abs(BigInt_O y, BigInt_I x)
{ fmpz_abs(y.m_n, x.m_n); }

inline void pow(BigInt_O z, BigInt_I x, Llong_I y)
{ assert(y >= 0); fmpz_pow_ui(z.m_n, x.m_n, y); }

} // namespace slisc
