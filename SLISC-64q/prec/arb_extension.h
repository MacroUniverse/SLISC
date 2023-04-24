// support for float128 type
// c++ wrapper for fmpz_t, arf_t, and arb_t

#pragma once
#include "../util/bit.h"
#include "arf.h"
#include "acb_hypgeom.h"

namespace slisc {

// __ARB_VERSION might not be defined in older versions
#if !defined(__ARB_VERSION) || (__ARB_VERSION == 2 && __ARB_VERSION_MINOR <= 21)
// similar to arb_get_str()
inline char *arf_get_str(const arf_t x, slong prec)
{
	arb_t y; arb_init(y);
	arb_set_arf(y, x);
	char *p = arb_get_str(y, prec, ARB_STR_MORE);
	arb_clear(y);
	return p;
}
#endif

inline int arf_set_str(arf_t res, const char * inp, slong prec)
{
	arb_t y; arb_init(y);
	if (arb_set_str(y, inp, prec)) {
		arb_clear(y);
		return 1;
	}
	arf_set(res, &y->mid);
	arb_clear(y);
	return 0;
}

#ifdef SLS_USE_QUAD_MATH
// get a quad precision number from arf_t type
// similar to arf_get_d()
inline Qdoub arf_get_q(const arf_t x, arf_rnd_t rnd)
{
	Qdoub v;
	arf_t t;
	// mp_limb_t is the type of a limb, with FLINT_BITS bits
	// typedef const mp_limb_t *mp_srcptr;
	mp_srcptr tp; // pointer to least significant limb
	mp_size_t tn; // # of limbs

	arf_init(t);
	arf_set_round(t, x, 113, rnd);
	ARF_GET_MPN_READONLY(tp, tn, t);
	if (tn == 1)
		// FLINT_BITS is # of bits in each limb, i.e. sizeof(mp_limb_t)*8
		v = Qdoub(tp[0])*ldexpq(1,-FLINT_BITS);
	else if (tn == 2)
		v = Qdoub(tp[1])*ldexpq(1,-FLINT_BITS) +
			Qdoub(tp[0])*ldexpq(1,-2*FLINT_BITS);
	else if (tn == 3)
		v = Qdoub(tp[2])*ldexpq(1,-FLINT_BITS) +
			Qdoub(tp[1])*ldexpq(1,-2*FLINT_BITS) +
			Qdoub(tp[0])*ldexpq(1,-3*FLINT_BITS);
	else if (tn == 4)
		v = Qdoub(tp[3])*ldexpq(1,-FLINT_BITS) +
			Qdoub(tp[2])*ldexpq(1,-2*FLINT_BITS) +
			Qdoub(tp[1])*ldexpq(1,-3*FLINT_BITS) +
			Qdoub(tp[0])*ldexpq(1,-4*FLINT_BITS);
	else
		SLS_ERR("not implemented!");

	v = ldexpq(v, ARF_EXP(t));

	if (ARF_SGNBIT(t)) // 1 for negative
		v = -v;
	arf_clear(t);
	return v;
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

struct Bint
{
	fmpz_t m_n;
	// constructors
	Bint() {
		// printf("Bint: default init called.\n");
		fmpz_init(m_n);
	}
	Bint(Llong_I val)
	{
		// printf("Bint: Llong init called.\n");
		fmpz_init(m_n); fmpz_set_si(m_n, val);
	}
	Bint(Doub_I val)
	{
		// printf("Bint: Doub init called.\n");
		fmpz_init(m_n); fmpz_set_d(m_n, val);
	}
	Bint(Str_I str, Int_I base = 10)
	{
		// printf("Bint: Str init called.\n");
		fmpz_init(m_n); fmpz_set_str(m_n, str.c_str(), base);
	}
	Bint(const Bint &x) // copy constructor
	{
		// printf("Bint: copy constructor called.\n");
		fmpz_init(m_n); fmpz_set(m_n, x.m_n);
	}
	// Bint(Bint&& x) // move constructor
	// {
	// 	printf("Bint: move constructor called.\n");
	// 	fmpz_clear(m_n);
	// 	m_n = x.m_n; x.m_n = NULL;
	// }
	Bint &operator=(const Bint &rhs) // copy assignment
	{
		// printf("Bint: copy assignment called.\n");
		fmpz_set(m_n, rhs.m_n); return *this;
	}
	Bint &operator=(Llong_I rhs) { fmpz_set_si(m_n, rhs); return *this; }
	Bint &operator=(Doub_I rhs) { fmpz_set_d(m_n, rhs); return *this; }
	Bint &operator=(Str_I rhs) { fmpz_set_str(m_n, rhs.c_str(), 10); return *this; }
	~Bint() {
		// printf("Bint: destructor called.\n");
		fmpz_clear(m_n);
	}
};

typedef const Bint &Bint_I;
typedef Bint &Bint_O, &Bint_IO;

inline Str to_string(Bint_I x)
{
	char *s; s = fmpz_get_str(NULL, 10, x.m_n);
	Str str(s); free(s);
	return str;
}

inline std::ostream &operator<<(std::ostream &os, Bint_I x) {
	cout << to_string(x) << endl;
	return os;
}

// compare
inline Bool operator==(Bint_I x, Bint_I y)
{ return fmpz_equal(x.m_n, y.m_n); }

inline Bool operator==(Bint_I x, Llong_I y)
{ return fmpz_equal_si(x.m_n, y); }

inline Bool operator==(Llong_I y, Bint_I x)
{ return fmpz_equal_si(x.m_n, y); }

inline Bool operator==(Bint_I x, Str_I y)
{ Bint yy(y); return x == yy; }

inline Bool operator==(Str_I y, Bint_I x)
{ Bint yy(y); return x == yy; }

inline Bool operator!=(Bint_I x, Bint_I y)
{ return !(x == y); }

inline Bool operator!=(Bint_I x, Llong_I y)
{ return !(x == y); }

inline Bool operator!=(Llong_I y, Bint_I x)
{ return !(x == y); }

inline Bool operator!=(Bint_I x, Str_I y)
{ return !(x == y); }

inline Bool operator<(Bint_I x, Bint_I y)
{ return fmpz_cmp(x.m_n, y.m_n) < 0; }

inline Bool operator<(Bint_I x, Llong_I y)
{ return fmpz_cmp_si(x.m_n, y) < 0; }

inline Bool operator<(Llong_I y, Bint_I x)
{ return fmpz_cmp_si(x.m_n, y) > 0; }

inline Bool operator>(Bint_I x, Bint_I y)
{ return fmpz_cmp(x.m_n, y.m_n) > 0; }

inline Bool operator>(Bint_I x, Llong_I y)
{ return fmpz_cmp_si(x.m_n, y) > 0; }

inline Bool operator>(Llong_I y, Bint_I x)
{ return fmpz_cmp_si(x.m_n, y) < 0; }

inline Bool isodd(Bint_I x)
{ return fmpz_is_odd(x.m_n); }

// arithmetic

inline void neg(Bint_O x, Bint_I y)
{ fmpz_neg(x.m_n, y.m_n); }

inline void neg(Bint_IO x) { neg(x, x); }

inline void add(Bint_O z, Bint_I x, Bint_I y)
{ fmpz_add(z.m_n, x.m_n, y.m_n); }

inline void operator+=(Bint_IO y, Bint_I x)
{ add(y, y, x); }

inline void add(Bint_O z, Bint_I x, Llong_I y)
{
	if (y > 0)
		fmpz_add_ui(z.m_n, x.m_n, y);
	else if (y < 0)
		fmpz_sub_ui(z.m_n, x.m_n, -y);
}

inline void operator+=(Bint_IO y, Llong_I x) { add(y, y, x); }

inline void add(Bint_O z, Llong_I y, Bint_I x)
{ add(z, x, y); }

inline void sub(Bint_O z, Bint_I x, Bint_I y)
{ fmpz_sub(z.m_n, x.m_n, y.m_n); }

inline void sub(Bint_IO y, Bint_I x) { sub(y, y, x); }

inline void sub(Bint_O z, Bint_I x, Llong_I y)
{
	if (y > 0)
		fmpz_sub_ui(z.m_n, x.m_n, y);
	else if (y < 0)
		fmpz_add_ui(z.m_n, x.m_n, -y);
}

inline void operator-=(Bint_IO y, Llong_I x) { sub(y, y, x); }

inline void sub(Bint_O z, Llong_I y, Bint_I x)
{ sub(z, x, y); neg(z); }

inline void mul(Bint_O z, Bint_I x, Bint_I y)
{ fmpz_mul(z.m_n, x.m_n, y.m_n); }

inline void operator*=(Bint_IO y, Bint_I x) { mul(y, y, x); }

inline void mul(Bint_O z, Bint_I x, Llong_I y)
{ fmpz_mul_si(z.m_n, x.m_n, y); }

inline void mul(Bint_O z, Llong_I y, Bint_I x)
{ fmpz_mul_si(z.m_n, x.m_n, y); }

inline void div(Bint_O z, Bint_I x, Bint_I y)
{ fmpz_tdiv_q(z.m_n, x.m_n, y.m_n); }

inline void operator/=(Bint_IO y, Bint_I x)
{ div(y, x, x); }

inline void div(Bint_O z, Bint_I x, Llong_I y)
{ fmpz_tdiv_q_si(z.m_n, x.m_n, y); }

inline void mod(Bint_O z, Bint_I x, Bint_I y)
{ fmpz_mod(z.m_n, x.m_n, y.m_n); } // always positive

inline void abs(Bint_O y, Bint_I x)
{ fmpz_abs(y.m_n, x.m_n); }

inline void pow(Bint_O z, Bint_I x, Llong_I y)
{ assert(y >= 0); fmpz_pow_ui(z.m_n, x.m_n, y); }


// TODO: using static variable is not thread-safe, need to think about the precision machenism
inline Llong arb_prec(Llong_I new_prec = -1)
{
	static Llong prec = 128;
	if (new_prec > 1)
		prec = new_prec;
	return prec;
}

// arb_prec() in decimal
inline Doub arb_digits(Doub_I new_digit = -1)
{
	const Doub log2_10 = 3.32192809489;
	return arb_prec(ceil(new_digit * log2_10)) / log2_10;
}

// arf_t: arbitrary precision floating point numbers
// https://arblib.org/arf.html
struct Breal {
	arf_t m_n;
	// constructors
	Breal() { arf_init(m_n); }
	Breal(Doub_I val) { arf_init(m_n); arf_set_d(m_n, val); }
	Breal(Str_I str)
	{
		arf_init(m_n); arf_set_str(m_n, str.c_str(), arb_prec());
	}
	Breal(const Breal &x) // copy constructor
	{
		arf_init(m_n); arf_set(m_n, x.m_n);
	}
	Breal &operator=(const Breal &rhs) // copy assignment
	{
		arf_set(m_n, rhs.m_n); return *this;
	}
	Breal &operator=(Llong_I rhs) { arf_set_si(m_n, rhs); return *this; }
	Breal &operator=(Doub_I rhs) { arf_set_d(m_n, rhs); return *this; }
	Breal &operator=(Str_I rhs) { arf_set_str(m_n, rhs.c_str(), 10); return *this; }
	~Breal() { arf_clear(m_n); }
};

typedef const Breal &Breal_I;
typedef Breal &Breal_O, &Breal_IO;

inline Str to_string(Breal_I x, Llong_I digits = 10)
{
	char * s = arf_get_str(x.m_n, digits);
	Str str(s); free(s);
	rm_float_zeros(s);
	return str;
}

inline std::ostream &operator<<(std::ostream &os, Breal_I x) {
	cout << to_string(x) << endl;
	return os;
}

inline void clear(Breal_O x) { arf_clear(x.m_n); }

inline Bool operator==(Breal_I x, Breal_I y)
{ return arf_equal(x.m_n, y.m_n); }

inline Bool operator!=(Breal_I x, Breal_I y)
{ return !(x == y); }

inline void add(Breal_O z, Breal_I x, Breal_I y)
{ arf_add(z.m_n, x.m_n, y.m_n, arb_prec(), ARF_RND_NEAR); }

inline void sub(Breal_O z, Breal_I x, Breal_I y)
{ arf_sub(z.m_n, x.m_n, y.m_n, arb_prec(), ARF_RND_NEAR); }

inline void mul(Breal_O z, Breal_I x, Breal_I y)
{ arf_mul(z.m_n, x.m_n, y.m_n, arb_prec(), ARF_RND_NEAR); }

inline void div(Breal_O z, Breal_I x, Breal_I y)
{ arf_div(z.m_n, x.m_n, y.m_n, arb_prec(), ARF_RND_NEAR); }

inline void sqrt(Breal_O y, Breal_I x)
{ arf_sqrt(y.m_n, x.m_n, arb_prec(), ARF_RND_NEAR); }

struct Areal {
	arb_t m_n;
	// constructors
	Areal() { arb_init(m_n); }
	Areal(arb_t val) { arb_init(m_n); arb_set(m_n, val); }
	Areal(arf_t val) { arb_init(m_n); arb_set_arf(m_n, val); }
	Areal(Breal_I val) { arb_init(m_n); arb_set_arf(m_n, val.m_n); }
	Areal(Doub_I val) {	arb_init(m_n); arb_set_d(m_n, val);	}
	// e.g. for arb_prec(30), Areal("1.23") will be [1.229999999999999999999999999999621 +/- 1.58e-30]
	Areal(Str_I str) { arb_init(m_n); arb_set_str(m_n, str.c_str(), arb_prec()); }
	Areal(const Areal &x) { arb_set(m_n, x.m_n); } // copy constructor
	Areal &operator=(const Areal &rhs) // copy assignment
	{ arb_set(m_n, rhs.m_n); return *this; }
	Areal &operator=(Doub_I rhs) { arb_set_d(m_n, rhs); return *this; }
	Areal &operator=(Str_I rhs) { arb_set_str(m_n, rhs.c_str(), arb_prec()); return *this; }
	~Areal() { arb_clear(m_n); }
};

typedef const Areal &Areal_I;
typedef Areal &Areal_O, &Areal_IO;

inline void clear(Areal_O x) { arb_clear(x.m_n); }

// return ARF_PREC_EXACT i.e. std::numeric_limits<slong>::max() if radius is 0
// defined as the difference between the top bit in the midpoint and the position of the top bit in the radius, minus one
inline Llong get_prec(Areal_I x) { return arb_rel_accuracy_bits(x.m_n); }

inline Doub get_digits(Areal_I x) { return get_prec(x) / 3.32192809489; }

inline Str to_string(Areal_I x, Llong_I digits = -1)
{
	char *s = arb_get_str(x.m_n, digits < 0 ? get_digits(x)+5 : digits, ARB_STR_MORE);
	Str str(s); free(s);
	return str;
}

inline std::ostream &operator<<(std::ostream &os, Areal_I x) {
	cout << to_string(x) << endl;
	return os;
}

inline void print_rad(Areal_I x) { mag_print(arb_radref(x.m_n)); }

inline void set_rad(Areal_IO x, Doub_I r) { mag_set_d(arb_radref(x.m_n), r); };

inline void set_rad(Areal_IO x, ulong man, Bint_I exp) // set to `man * 2^exp`
{ arb_radref(x.m_n)->man = man; fmpz_add_si(&arb_radref(x.m_n)->exp, exp.m_n, MAG_BITS); };

inline void swap(Areal_IO x, Areal_IO y) { arb_swap(x.m_n, y.m_n); }

// constants

inline void arb_pi(Areal_O z) { arb_const_pi(z.m_n, arb_prec()); }

inline void arb_e(Areal_O z) { arb_const_e(z.m_n, arb_prec()); }

inline void arb_sqrt_pi(Areal_O z) { arb_const_sqrt_pi(z.m_n, arb_prec()); }

inline void arb_log2(Areal_O z) { arb_const_log2(z.m_n, arb_prec()); }

inline void arb_log10(Areal_O z) { arb_const_log10(z.m_n, arb_prec()); }

// + - * /
inline void add(Areal_O z, Areal_I x, Areal_I y)
{ arb_add(z.m_n, x.m_n, y.m_n, arb_prec()); }

inline void add(Areal_O z, Areal_I x, Llong_I y)
{ arb_add_si(z.m_n, x.m_n, y, arb_prec()); }

inline void sub(Areal_O z, Areal_I x, Areal_I y)
{ arb_sub(z.m_n, x.m_n, y.m_n, arb_prec()); }

inline void sub(Areal_O z, Areal_I x, Llong_I y)
{ arb_sub_si(z.m_n, x.m_n, y, arb_prec()); }

inline void mul(Areal_O z, Areal_I x, Areal_I y)
{ arb_mul(z.m_n, x.m_n, y.m_n, arb_prec()); }

inline void mul(Areal_O z, Areal_I x, Llong_I y)
{ arb_mul_si(z.m_n, x.m_n, y, arb_prec()); }

inline void div(Areal_O z, Areal_I x, Areal_I y)
{ arb_div(z.m_n, x.m_n, y.m_n, arb_prec()); }

inline void div(Areal_O z, Areal_I x, Llong_I y)
{ arb_div_si(z.m_n, x.m_n, y, arb_prec()); }

// z += x*y
inline void addmul(Areal_IO z, Areal_I x, Areal_I y)
{ arb_addmul(z.m_n, x.m_n, y.m_n, arb_prec()); }

inline void submul(Areal_IO z, Areal_I x, Areal_I y)
{ arb_submul(z.m_n, x.m_n, y.m_n, arb_prec()); }

inline void sqr(Areal_O y, Areal_I x)
{ arb_sqr(y.m_n, x.m_n, arb_prec()); }

inline void pow(Areal_O z, Areal_I x, Areal_I y)
{ arb_pow(z.m_n, x.m_n, y.m_n, arb_prec()); }

inline void inv(Areal_O z, Areal_I x)
{ arb_inv(z.m_n, x.m_n, arb_prec()); }

// basic fun
inline void sqrt(Areal_O y, Areal_I x)
{ arb_sqrt(y.m_n, x.m_n, arb_prec()); }

inline void log(Areal_O y, Areal_I x)
{ arb_log(y.m_n, x.m_n, arb_prec()); }

inline void exp(Areal_O y, Areal_I x)
{ arb_exp(y.m_n, x.m_n, arb_prec()); }

inline void sin(Areal_O y, Areal_I x)
{ arb_sin(y.m_n, x.m_n, arb_prec()); }

inline void cos(Areal_O y, Areal_I x)
{ arb_cos(y.m_n, x.m_n, arb_prec()); }

inline void sin_cos(Areal_O s, Areal_O c, Areal_I x)
{ arb_sin_cos(s.m_n, c.m_n, x.m_n, arb_prec()); }

inline void tan(Areal_O y, Areal_I x)
{ arb_tan(y.m_n, x.m_n, arb_prec()); }

inline void cot(Areal_O y, Areal_I x)
{ arb_cot(y.m_n, x.m_n, arb_prec()); }

inline void atan(Areal_O y, Areal_I x)
{ arb_atan(y.m_n, x.m_n, arb_prec()); }

inline void atan2(Areal_O z, Areal_I y, Areal_I x)
{ arb_atan2(z.m_n, y.m_n, x.m_n, arb_prec()); }

inline void asin(Areal_O y, Areal_I x)
{ arb_asin(y.m_n, x.m_n, arb_prec()); }

inline void acos(Areal_O y, Areal_I x)
{ arb_acos(y.m_n, x.m_n, arb_prec()); }

// y = x * 2^e
inline void ldexp(Areal_O y, Areal_I x, Bint_I e)
{ arb_mul_2exp_fmpz(y.m_n, x.m_n, e.m_n); }

// special fun
inline void gamma(Areal_O z, Areal_I x)
{ arb_gamma(z.m_n, x.m_n, arb_prec()); }

inline void digamma(Areal_O z, Areal_I x)
{ arb_digamma(z.m_n, x.m_n, arb_prec()); }


struct Acomp {
	acb_t m_n;
	// constructors
	Acomp() { acb_init(m_n); }
	Acomp(acb_t val) { acb_init(m_n); acb_set(m_n, val); }
	// Acomp(arf_t val, arf_t val) { acb_init(m_n); acb_set_arf(m_n, val); }
	Acomp(Areal_I val) { acb_init(m_n); acb_set_arb(m_n, val.m_n); }
	// Acomp(Breal_I val, Breal_I val) { acb_init(m_n); acb_set_arf(m_n, val.m_n); }
	// Acomp(Doub_I val, Doub_I val) {	acb_init(m_n); acb_set_d(m_n, val);	}
	// e.g. for acb_prec(30), Acomp("1.23") will be [1.229999999999999999999999999999621 +/- 1.58e-30]
	// Acomp(Str_I str) { acb_init(m_n); acb_set_str(m_n, str.c_str(), acb_prec()); }
	Acomp(const Acomp &x) { acb_set(m_n, x.m_n); } // copy constructor
	Acomp &operator=(const Acomp &rhs) // copy assignment
	{ acb_set(m_n, rhs.m_n); return *this; }
	// Acomp &operator=(Comp_I rhs) { acb_set_d_d(m_n, rhs.real(), rhs.imag()); return *this; }
	// Acomp &operator=(Str_I rhs) { acb_set_str(m_n, rhs.c_str(), acb_prec()); return *this; }
	~Acomp() { acb_clear(m_n); }
};

typedef const Acomp &Acomp_I;
typedef Acomp &Acomp_O, &Acomp_IO;

inline void clear(Acomp_O x) { acb_clear(x.m_n); }

} // namespace slisc
