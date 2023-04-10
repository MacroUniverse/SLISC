// this is a modified version of the original file by SLISC

/*
 * Copyright (c) 2012-2022
 *	Nakata, Maho
 * 	All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 */

#include <mplapack/mplapack_config.h>
#ifndef _MUTILS__FLOAT128_H_
#define _MUTILS__FLOAT128_H_

#define ___MPLAPACK__FLOAT128_ONLY___

#if (defined ___MPLAPACK__FLOAT128_ONLY___ || defined ___MPLAPACK__FLOAT128_IS_LONGDOUBLE___)

// Intel C/C++ compilers currently only supports __float128
// and following workaround works
#if defined(__INTEL_COMPILER)
#define _Float128 __float128
#endif

#if defined ___MPLAPACK_INTERNAL___
#if !defined __MPLAPACK_BUFLEN__
#define __MPLAPACK_BUFLEN__ 1024
#endif
#include <string.h>

#define FLOAT128_FORMAT "%.40e"
#define FLOAT128_SHORT_FORMAT "%.16e"

	inline void printnum(_Float128 rtmp) {
	char buf[__MPLAPACK_BUFLEN__];
	strfromf128(buf, __MPLAPACK_BUFLEN__, FLOAT128_FORMAT, rtmp);
	if (rtmp >= 0.0)
		printf("+%s", buf);
	else
		printf("%s", buf);
}
inline void printnum_short(_Float128 rtmp) {
	char buf[__MPLAPACK_BUFLEN__];
	strfromf128(buf, __MPLAPACK_BUFLEN__, FLOAT128_SHORT_FORMAT, rtmp);
	if (rtmp >= 0.0)
		printf("+%s", buf);
	else
		printf("%s", buf);
}
inline void printnum(std::complex<_Float128> rtmp) {
	char buf[__MPLAPACK_BUFLEN__];
	strfromf128(buf, __MPLAPACK_BUFLEN__, FLOAT128_FORMAT, rtmp.real());
	if (rtmp.real() >= 0.0)
		printf("+%s", buf);
	else
		printf("%s", buf);
	strfromf128(buf, __MPLAPACK_BUFLEN__, FLOAT128_FORMAT, rtmp.imag());
	if (rtmp.imag() >= 0.0)
		printf("+%s", buf);
	else
		printf("%s", buf);
	printf("i");
}
inline void printnum_short(std::complex<_Float128> rtmp) {
	char buf[__MPLAPACK_BUFLEN__];
	strfromf128(buf, __MPLAPACK_BUFLEN__, FLOAT128_SHORT_FORMAT, rtmp.real());
	if (rtmp.real() >= 0.0)
		printf("+%s", buf);
	else
		printf("%s", buf);
	strfromf128(buf, __MPLAPACK_BUFLEN__, FLOAT128_SHORT_FORMAT, rtmp.imag());
	if (rtmp.imag() >= 0.0)
		printf("+%s", buf);
	else
		printf("%s", buf);
	printf("i");
}
inline void sprintnum(char *buf, _Float128 rtmp) {
	char buf1[__MPLAPACK_BUFLEN__];
	buf[0] = '\0';
	if (rtmp >= 0.0)
		strcat(buf, "+");
	strfromf128(buf1, __MPLAPACK_BUFLEN__, FLOAT128_FORMAT, rtmp);
	strcat(buf, buf1);
}
inline void sprintnum_short(char *buf, _Float128 rtmp) {
	char buf1[__MPLAPACK_BUFLEN__];
	buf[0] = '\0';
	if (rtmp >= 0.0)
		strcat(buf, "+");
	strfromf128(buf1, __MPLAPACK_BUFLEN__, FLOAT128_SHORT_FORMAT, rtmp);
	strcat(buf, buf1);
}
inline void sprintnum(char *buf, std::complex<_Float128> rtmp) {
	char buf1[__MPLAPACK_BUFLEN__], buf2[__MPLAPACK_BUFLEN__];
	buf[0] = '\0';
	if (rtmp.real() >= 0.0)
		strcat(buf, "+");
	strfromf128(buf1, __MPLAPACK_BUFLEN__, FLOAT128_FORMAT, rtmp.real());
	strcat(buf, buf1);
	if (rtmp.imag() >= 0.0)
		strcat(buf, "+");
	strfromf128(buf2, __MPLAPACK_BUFLEN__, FLOAT128_FORMAT, rtmp.imag());
	strcat(buf, buf2);
	strcat(buf, "i");
}
inline void sprintnum_short(char *buf, std::complex<_Float128> rtmp) {
	char buf1[__MPLAPACK_BUFLEN__], buf2[__MPLAPACK_BUFLEN__];
	buf[0] = '\0';
	if (rtmp.real() >= 0.0)
		strcat(buf, "+");
	strfromf128(buf1, __MPLAPACK_BUFLEN__, FLOAT128_SHORT_FORMAT, rtmp.real());
	strcat(buf, buf1);
	if (rtmp.imag() >= 0.0)
		strcat(buf, "+");
	strfromf128(buf2, __MPLAPACK_BUFLEN__, FLOAT128_SHORT_FORMAT, rtmp.imag());
	strcat(buf, buf2);
	strcat(buf, "i");
}
#endif

inline _Float128 pow2(const _Float128 &a) { return a * a; }

// when _Float128 == long double, followings are already defined.

#ifdef __cplusplus
extern "C" {
#endif
// #include <complex.h>
#include <complex>
#include <math.h>
#ifdef __cplusplus
}
#endif

// implementation of sign transfer function.
inline _Float128 sign(_Float128 a, _Float128 b) {
	_Float128 mtmp;
	mtmp = std::abs(a);
	if (b < 0.0) {
		mtmp = -mtmp;
	}
	return mtmp;
}

inline _Float128 castREAL__Float128(mplapackint n) {
	_Float128 ret = n;
	return ret;
}

inline mplapackint castINTEGER__Float128(_Float128 a) {
	mplapackint i = a;
	return i;
}

inline long nint(_Float128 a) {
	long i;
	_Float128 tmp;
	a = a + 0.5;
	tmp = floorq(a);
	i = (long)tmp;
	return i;
}
inline double cast2double(_Float128 a) { return (double)a; }

inline _Float128 pi(_Float128 dummy) { return M_PIq; }
#endif // (defined ___MPLAPACK__FLOAT128_ONLY___ || defined ___MPLAPACK__FLOAT128_IS_LONGDOUBLE___)

#if defined ___MPLAPACK_LONGDOUBLE_IS_BINARY128___

#if defined ___MPLAPACK_INTERNAL___
#if !defined __MPLAPACK_BUFLEN__
#define __MPLAPACK_BUFLEN__ 1024
#endif
#include <string.h>

#define FLOAT128_FORMAT "%+.40Le"
#define FLOAT128_SHORT_FORMAT "%+.16Le"

inline void printnum(long double rtmp) {
	printf(FLOAT128_FORMAT, rtmp);
	return;
}
inline void printnum(std::complex<long double> ctmp) {
	printf(FLOAT128_FORMAT FLOAT128_FORMAT "i", ctmp.real(), ctmp.imag());
	return;
}
inline void sprintnum(char *buf, long double rtmp) {
	snprintf(buf, __MPLAPACK_BUFLEN__, FLOAT128_FORMAT, rtmp);
	return;
}
inline void sprintnum(char *buf, std::complex<long double> ctmp) {
	snprintf(buf, __MPLAPACK_BUFLEN__, FLOAT128_FORMAT FLOAT128_FORMAT "i", ctmp.real(), ctmp.imag());
	return;
}
inline void printnum_short(long double rtmp) {
	printf(FLOAT128_SHORT_FORMAT, rtmp);
	return;
}
inline void printnum_short(std::complex<long double> ctmp) {
	printf(FLOAT128_SHORT_FORMAT FLOAT128_SHORT_FORMAT "i", ctmp.real(), ctmp.imag());
	return;
}
inline void sprintnum_short(char *buf, long double rtmp) {
	snprintf(buf, __MPLAPACK_BUFLEN__, FLOAT128_SHORT_FORMAT, rtmp);
	return;
}
inline void sprintnum_short(char *buf, std::complex<long double> ctmp) {
	snprintf(buf, __MPLAPACK_BUFLEN__, FLOAT128_SHORT_FORMAT FLOAT128_SHORT_FORMAT "i", ctmp.real(), ctmp.imag());
	return;
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
#include <math.h>
#include <complex.h>
#include <complex>
#ifdef __cplusplus
}
#endif
typedef long double _Float128;

inline long double pow2(const long double &a) { return a * a; }

// implementation of sign transfer function.
inline long double sign(long double a, long double b) {
	long double mtmp;
	mtmp = std::abs(a);
	if (b < 0.0) {
		mtmp = -mtmp;
	}
	return mtmp;
}

inline long double castREAL__Float128(mplapackint n) {
	long double ret = n;
	return ret;
}

inline mplapackint castINTEGER__Float128(long double a) {
	mplapackint i = a;
	return i;
}

inline long nint(long double a) {
	long i;
	long double tmp;
	a = a + 0.5;
	tmp = floorl(a);
	i = (long)tmp;
	return i;
}

inline double cast2double(long double a) { return (double)a; }
inline long double pi(long double dummy) { return M_PIl; }

#endif //___MPLAPACK_LONGDOUBLE_IS_BINARY128___

#if defined ___MPLAPACK_WANT_LIBQUADMATH___

#ifdef __cplusplus
extern "C" {
#endif
#include <quadmath.h>
#ifdef __cplusplus
}
#endif
typedef __float128 _Float128;

#if defined ___MPLAPACK_INTERNAL___
#if !defined __MPLAPACK_BUFLEN__
#define __MPLAPACK_BUFLEN__ 1024
#endif
#include <string.h>

#define FLOAT128_FORMAT "%+-#*.40Qe"
#define FLOAT128_SHORT_FORMAT "%+-#*.16Qe"

inline void printnum(_Float128 rtmp) {
	int width = 42;
	char buf[__MPLAPACK_BUFLEN__];
	int n = quadmath_snprintf(buf, sizeof buf, FLOAT128_FORMAT, width, rtmp);
	if ((size_t)n < sizeof buf)
		printf("%s", buf);
	return;
}

inline void printnum(std::complex<_Float128> rtmp) {
	int width = 42, n;
	char buf[__MPLAPACK_BUFLEN__], buf2[__MPLAPACK_BUFLEN__];
	n = quadmath_snprintf(buf, sizeof buf, FLOAT128_FORMAT, width, rtmp.real());
	if ((size_t)n < sizeof buf)
		printf("%s", buf);
	n = quadmath_snprintf(buf2, sizeof buf, FLOAT128_FORMAT, width, rtmp.imag());
	if ((size_t)n < sizeof buf2)
		printf("%s", buf2);
	printf("i");
	return;
}

inline void sprintnum(char *buf, _Float128 rtmp) {
	int width = 42;
	quadmath_snprintf(buf, __MPLAPACK_BUFLEN__, FLOAT128_FORMAT, width, rtmp);
	return;
}

inline void sprintnum(char *buf, std::complex<_Float128> rtmp) {
	int width = 42;
	quadmath_snprintf(buf, __MPLAPACK_BUFLEN__, FLOAT128_FORMAT FLOAT128_FORMAT, width, rtmp.real(), rtmp.imag());
	return;
}

inline void printnum_short(_Float128 rtmp) {
	int width = 42;
	char buf[__MPLAPACK_BUFLEN__];
	int n = quadmath_snprintf(buf, sizeof buf, FLOAT128_SHORT_FORMAT, width, rtmp);
	if ((size_t)n < sizeof buf)
		printf("%s", buf);
	return;
}

inline void printnum_short(std::complex<_Float128> rtmp) {
	int width = 42, n;
	char buf[__MPLAPACK_BUFLEN__], buf2[__MPLAPACK_BUFLEN__];
	n = quadmath_snprintf(buf, sizeof buf, FLOAT128_SHORT_FORMAT, width, rtmp.real());
	if ((size_t)n < sizeof buf)
		printf("%s", buf);
	n = quadmath_snprintf(buf2, sizeof buf, FLOAT128_SHORT_FORMAT, width, rtmp.imag());
	if ((size_t)n < sizeof buf2)
		printf("%s", buf2);
	printf("i");
	return;
}

inline void sprintnum_short(char *buf, _Float128 rtmp) {
	int width = 42;
	quadmath_snprintf(buf, __MPLAPACK_BUFLEN__, FLOAT128_SHORT_FORMAT, width, rtmp);
	return;
}

inline void sprintnum_short(char *buf, std::complex<_Float128> rtmp) {
	int width = 42;
	quadmath_snprintf(buf, __MPLAPACK_BUFLEN__, FLOAT128_SHORT_FORMAT FLOAT128_SHORT_FORMAT, width, rtmp.real(), rtmp.imag());
	return;
}

#endif

inline _Float128 pow(const _Float128 &a, const _Float128 &b) { return powq(a, b); }
inline _Float128 pow(const long &a, const long &b) { return powq((_Float128)a, (_Float128)b); }
inline _Float128 pow(const int &a, const long &b) { return powq((_Float128)a, (_Float128)b); }
inline _Float128 pow(const _Float128 &a, const long &b) { return powq(a, (_Float128)b); }
inline _Float128 pow2(const _Float128 &a) { return a * a; }

inline _Float128 sqrt(const _Float128 &a) { return sqrtq(a); }

inline _Float128 sin(_Float128 a) { return sinq(a); }
inline _Float128 sinh(_Float128 a) { return sinhq(a); }
inline _Float128 cos(_Float128 a) { return cosq(a); }
inline _Float128 cosh(_Float128 a) { return coshq(a); }

inline _Float128 atan2(_Float128 a, _Float128 b) { return atan2q(a, b); }

inline _Float128 exp(const _Float128 &a) { return expq(a); }
inline _Float128 log(const _Float128 &a) { return logq(a); }
inline _Float128 log10(const _Float128 &a) { return log10q(a); }
inline _Float128 log2(const _Float128 &a) { return logq(a) / logq(2.0); }

#ifdef __cplusplus
extern "C" {
#endif
#include <complex.h>
#include <complex>
#include <math.h>
#ifdef __cplusplus
}
#endif

inline _Float128 abs(const std::complex<_Float128> &a) {
	_Float128 _Complex b;
	_Float128 c;
	__real__(b) = (a.real());
	__imag__(b) = (a.imag());
	c = cabsq(b);
	return c;
}

inline std::complex<_Float128> sqrt(const std::complex<_Float128> a) {
	_Float128 _Complex b, tmp;
	std::complex<_Float128> c;
	__real__(b) = (a.real());
	__imag__(b) = (a.imag());
	tmp = csqrtq(b);
	c.real(__real__(tmp));
	c.imag(__imag__(tmp));
	return c;
}

inline std::complex<_Float128> sin(const std::complex<_Float128> a) {
	_Float128 _Complex b, tmp;
	std::complex<_Float128> c;
	__real__(b) = (a.real());
	__imag__(b) = (a.imag());
	tmp = csinq(b);
	c.real(__real__(tmp));
	c.imag(__imag__(tmp));
	return c;
}

inline std::complex<_Float128> cos(const std::complex<_Float128> a) {
	_Float128 _Complex b, tmp;
	std::complex<_Float128> c;
	__real__(b) = (a.real());
	__imag__(b) = (a.imag());
	tmp = ccosq(b);
	c.real(__real__(tmp));
	c.imag(__imag__(tmp));
	return c;
}

inline std::complex<_Float128> exp(const std::complex<_Float128> &a) {
	_Float128 _Complex b, tmp;
	std::complex<_Float128> c;
	__real__(b) = (a.real());
	__imag__(b) = (a.imag());
	tmp = cexpq(b);
	c.real(__real__(tmp));
	c.imag(__imag__(tmp));
	return c;
}

inline std::complex<_Float128> log(const std::complex<_Float128> &a) {
	_Float128 _Complex b, tmp;
	std::complex<_Float128> c;
	__real__(b) = (a.real());
	__imag__(b) = (a.imag());
	tmp = clogq(b);
	c.real(__real__(tmp));
	c.imag(__imag__(tmp));
	return c;
}

// implementation of sign transfer function.
inline _Float128 sign(_Float128 a, _Float128 b) {
	_Float128 mtmp;
	mtmp = std::abs(a);
	if (b < 0.0) {
		mtmp = -mtmp;
	}
	return mtmp;
}

inline _Float128 castREAL__Float128(mplapackint n) {
	_Float128 ret = n;
	return ret;
}

inline mplapackint castINTEGER__Float128(_Float128 a) {
	mplapackint i = a;
	return i;
}

inline long nint(_Float128 a) {
	long i;
	_Float128 tmp;
	a = a + 0.5;
	tmp = floorq(a);
	i = (long)tmp;
	return i;
}

inline _Float128 ceil(_Float128 a) { return ceilq(a); }
inline double cast2double(_Float128 a) { return (double)a; }

inline _Float128 pi(_Float128 dummy) { return M_PIq; }

#endif //___MPLAPACK_WANT_LIBQUADMATH___

//Following specialization should be done in the libc/compiler side.
#if !defined ___MPLAPACK__FLOAT128_IS_LONGDOUBLE___  && !defined ___MPLAPACK_LONGDOUBLE_IS_BINARY128___
template <> template <> inline std::complex<_Float128> &std::complex<_Float128>::operator/=(const std::complex<_Float128> &b) {
	_Float128 abr, abi, ratio, den;
	if ((abr = b.real()) < 0.)
		abr = -abr;
	if ((abi = b.imag()) < 0.)
		abi = -abi;
	if (abr <= abi) {
		if (abi == 0) {
			if (this->imag() != 0 || this->real() != 0)
				abi = 1.;
			*this = std::complex<_Float128>(abi / abr, abi / abr);
			return (*this);
		}
		ratio = b.real() / b.imag();
		den = b.imag() * (1.0 + ratio * ratio);
		(*this) = std::complex<_Float128>((this->real() * ratio + this->imag()) / den, (this->imag() * ratio - this->real()) / den);
	} else {
		ratio = b.imag() / b.real();
		den = b.real() * (1.0 + ratio * ratio);
		(*this) = std::complex<_Float128>((this->real() + this->imag() * ratio) / den, (this->imag() - this->real() * ratio) / den);
	}
	return *this;
}
#endif

#endif
