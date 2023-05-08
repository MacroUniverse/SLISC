// floating point arithmetics
#pragma once
#include "../util/bit.h"

namespace slisc {

// Floating Point Exceptions for Microsoft compilers
// no exception for integer overflow
inline void msvc_turn_on_fp_except()
{
#if defined(SLS_FP_EXCEPT) && defined(SLS_USE_MSVC)
	unsigned cw; _controlfp_s(&cw, 0, 0);
	// also: EM_INEXACT, EM_UNDERFLOW
	cw &= ~(EM_INVALID | EM_OVERFLOW | EM_ZERODIVIDE | EM_DENORMAL);
	unsigned cw1; _controlfp_s(&cw1, cw, MCW_EM);
#endif
}

// break a double into different parts
// d = man * 2^exp2 (exact)
// sign info if included in `man`
// return NULL (normal) or "-Inf", "+Inf", "qNaN", "sNaN", "+0", "-0", "sub" (subnormal);
// assume little endian
// see also std::frexp() and std::fpclassify()
// ref: https://wuli.wiki/online/FltCpp.html
inline const char *fp_info(Bool_O neg, Llong_O man, Int_O exp2, Doub x)
{
	// split the bits:
	// 1 bit sign
	// neg = bitL(&x, 8, 1, true);
	neg = std::signbit(x); // +0 and -0 are also signed
	// 11 bits exp
	int16_t b2;
	memcpy(&b2, (char*)&x+6, 2); 
	exp2 = (b2 >> 4);
	// 52 bit mantissa
	memcpy(&man, &x, 8);
	man &= 0xFFFFFFFFFFFFF; // 52 bits 1
	
	// interpret
	exp2 -= 1023;
	const char *flag;
	if (exp2 == 1024) { // Inf or nan
		if (man == 0) // inf
			flag = neg ? "-Inf" : "+Inf";
		else if (man & 0x8000000000000)
			flag = "qNaN"; // quiet NaN
		else
			flag = "sNaN"; // signaling NaN
		return flag;
	}
	if (exp2 == -1023) {
		if (man == 0)
			flag = neg ? "-0" : "+0";
		else exp2 = -1022 - 52;
			flag = "sub"; // subnormal
		return flag;
	}
	exp2 -= 1023 + 52;
	man |= 0x10000000000000; // set the 53-th bit
	return NULL; // normal
}

// get ULP of double (unit of last place)
// "-Inf", "+Inf", "qNaN", "sNaN", "+0", "-0", "sub"
inline double ulp(Doub_I x, Ullong_I n = 1) {
	bool neg; Llong man; Int exp2;
	const char *flag = fp_info(neg, man, exp2, x);
	if (flag == NULL || strcmp(flag, "sub")) // normal
		return ldexp(1, exp2+52);
	else if (strcmp(flag, "+0") || strcmp(flag, "-0"))
		return numeric_limits<Doub>::denorm_min();
	else // (strcmp(flag, "-Inf") || strcmp(flag, "+Inf") || strcmp(flag, "qNaN") || strcmp(flag, "sNaN"))
		SLS_ERR("can't get ulp for: " + to_string(x));
}

// set the exp of a double (from -1023 to 1024)
// sign will be kept
inline Doub double_set_exp(Doub x, int16_t exp)
{
	bool neg = (x < 0);
	exp += 1023;
	int16_t b2;
	memcpy(&b2, (char*)&x+6, 2);
	b2 &= (int16_t)0xF;
	b2 |= (exp << 4);
	memcpy((char*)&x+6, &b2, 2);
	if (neg) x = -x;
	return x;
}

} // namespace slisc
