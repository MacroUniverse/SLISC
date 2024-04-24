// basic scalar arithmetic

#pragma once
#include "../arith/fp_arith.h"
#include "../arith/complex_arith.h"
#include "../arith/Imag.h"

namespace slisc {

// max, min with mixed types
inline Llong max(const Int &x, const Llong &y) { return x < y ? y : x; }
inline Llong max(const Llong &x, const Int &y) { return x < y ? y : x; }
inline Llong min(const Int &x, const Llong &y) { return x < y ? x : y; }
inline Llong min(const Llong &x, const Int &y) { return x < y ? x : y; }


constexpr Char sign(Char_I s)
{ return s > 0 ? 1 : (s < 0 ? -1 : 0); }

constexpr Int sign(Int_I s)
{ return s > 0 ? 1 : (s < 0 ? -1 : 0); }

constexpr Llong sign(Llong_I s)
{ return s > 0LL ? 1LL : (s < 0LL ? -1LL : 0LL); }

constexpr Float sign(Float_I s)
{ return s > 0.F ? 1.F : (s < 0.F ? -1.F : 0.F); }

constexpr Doub sign(Doub_I s)
{ return s > 0. ? 1. : (s < 0. ? -1. : 0.); }

constexpr Ldoub sign(Ldoub_I s)
{ return s > 0.L ? 1.L : (s < 0.L ? -1.L : 0.L); }

constexpr Qdoub sign(Qdoub_I s)
{ return s > 0.Q ? 1.Q : (s < 0.Q ? -1.Q : 0.Q); }


inline Char sign(Char_I a, Char_I b)
{ return b >= 0 ? (a >= 0 ? a : -a) : (a >= 0 ? -a : a); }

inline Int sign(Int_I a, Int_I b)
{ return b >= 0 ? (a >= 0 ? a : -a) : (a >= 0 ? -a : a); }

inline Llong sign(Llong_I a, Llong_I b)
{ return b >= 0 ? (a >= 0 ? a : -a) : (a >= 0 ? -a : a); }

inline Float sign(Float_I a, Float_I b)
{ return b >= 0 ? (a >= 0 ? a : -a) : (a >= 0 ? -a : a); }

inline Doub sign(Doub_I a, Doub_I b)
{ return b >= 0 ? (a >= 0 ? a : -a) : (a >= 0 ? -a : a); }

inline Ldoub sign(Ldoub_I a, Ldoub_I b)
{ return b >= 0 ? (a >= 0 ? a : -a) : (a >= 0 ? -a : a); }

inline Qdoub sign(Qdoub_I a, Qdoub_I b)
{ return b >= 0 ? (a >= 0 ? a : -a) : (a >= 0 ? -a : a); }


inline bool isodd(Char_I n) { return n & 1; }

inline bool isodd(Int_I n) { return n & 1; }

inline bool isodd(Uint_I n) { return n & 1; }

inline bool isodd(Llong_I n) { return n & 1; }

inline bool isodd(Ullong_I n) { return n & 1; }


inline bool ispow2(Char_I n) { return (n & (n-1)) == 0; }

inline bool ispow2(Int_I n) { return (n & (n-1)) == 0; }

inline bool ispow2(Llong_I n) { return (n & (n-1)) == 0; }


inline Int to_num(Char_I x) { return (Int)x; }

inline Int to_num(Int_I x) { return x; }

inline Llong to_num(Llong_I x) { return x; }

inline Doub to_num(Doub_I x) { return x; }

inline Ldoub to_num(Ldoub_I x) { return x; }

inline Qdoub to_num(Qdoub_I x) { return x; }

inline Comp to_num(Comp_I x) { return x; }

inline Lcomp to_num(Lcomp_I x) { return x; }

inline Qcomp to_num(Qcomp_I x) { return x; }


// check number of decimal digits of an integer
template<typename T>
int digits(const T &n) {
	static_assert(std::is_integral<T>::value, "T must be an integral type " SLS_WHERE);
	int count = 0;
	do { count++; n /= 10; } while (n != 0);
	return count;
}

// modulus
// all mod variants satisfies "s = div(s,d)*d + mod(s,d)"
// however, "div" can have different truncation:
// 1. c++ operator "/" truncates towards 0, so "s = (s/d)*d + s%d", and s%d = s%abs(d)
// 2. "mod_fl()" div truncates towards negative direction
// 3. "mod_eu()" is equivalent to "mod_fl(s,abs(d))"
// d = 0 is undefined.
// when s,d > 0, all variants return the same result
// result of all variants differ by +-d
// see https://en.wikipedia.org/wiki/Modulo_operation
inline Int mod(Int_I i, Int_I n) { return i % n; }

inline Int mod_fl(Int_I i, Int_I n) { return (i % n + n) % n; }

inline Int mod_eu(Int_I i, Int_I n)
{
	Int ret = i % n;
	return ret < 0 ? ret + abs(n) : ret;
}

inline Llong mod(Llong_I i, Int_I n) { return i % n; }

inline Llong mod_fl(Llong_I i, Int_I n) { return (i % n + n) % n; }

inline Llong mod_eu(Llong_I i, Int_I n)
{
	Llong ret = i % n;
	return ret < 0 ? ret + abs(n) : ret;
}

inline Llong mod(Int_I i, Llong_I n) { return i % n; }

inline Llong mod_fl(Int_I i, Llong_I n) { return (i % n + n) % n; }

inline Llong mod_eu(Int_I i, Llong_I n)
{
	Llong ret = i % n;
	return ret < 0 ? ret + abs(n) : ret;
}

inline Llong mod(Llong_I i, Llong_I n) { return i % n; }

inline Llong mod_fl(Llong_I i, Llong_I n) { return (i % n + n) % n; }

inline Llong mod_eu(Llong_I i, Llong_I n)
{
	Llong ret = i % n;
	return ret < 0 ? ret + abs(n) : ret;
}

inline Float mod(Float_I s, Float_I d)
{ return s - round(s/d) * d; }

// floating point version of "%", s = n * d + return
inline Float mod(Long_O n, Float_I s, Float_I d)
{
	n = round(s/d);
	return s - n * d;
}

inline Float mod_fl(Float_I s, Float_I d)
{ return s - floor(s/d) * d; }

// s = n * d + return
inline Float mod_fl(Long_O n, Float_I s, Float_I d)
{
	n = floor(s/d);
	return s - n * d;
}

inline Float mod_eu(Float_I s, Float_I d)
{
	Long n = s/d;
	Float r = s - n*d;
	return r < 0 ? r + abs(d) : r;
}

// s = n * d + return
inline Float mod_eu(Long_O n, Float_I s, Float_I d)
{
	n = s/d;
	Float r = s - n*d;
	if (r < 0) {
		r += abs(d);
		n -= sign(d);
	}
	return r;
}

inline Doub mod(Doub_I s, Doub_I d)
{ return s - round(s/d) * d; }

// floating point version of "%", s = n * d + return
inline Doub mod(Long_O n, Doub_I s, Doub_I d)
{
	n = round(s/d);
	return s - n * d;
}

inline Doub mod_fl(Doub_I s, Doub_I d)
{ return s - floor(s/d) * d; }

// s = n * d + return
inline Doub mod_fl(Long_O n, Doub_I s, Doub_I d)
{
	n = floor(s/d);
	return s - n * d;
}

inline Doub mod_eu(Doub_I s, Doub_I d)
{
	Long n = s/d;
	Doub r = s - n*d;
	return r < 0 ? r + abs(d) : r;
}

// s = n * d + return
inline Doub mod_eu(Long_O n, Doub_I s, Doub_I d)
{
	n = s/d;
	Doub r = s - n*d;
	if (r < 0) {
		r += abs(d);
		n -= sign(d);
	}
	return r;
}

inline Qdoub mod(Qdoub_I s, Qdoub_I d)
{ return s - round(s/d) * d; }

// floating point version of "%", s = n * d + return
inline Qdoub mod(Long_O n, Qdoub_I s, Qdoub_I d)
{
	n = round(s/d);
	return s - n * d;
}

inline Qdoub mod_fl(Qdoub_I s, Qdoub_I d)
{ return s - floor(s/d) * d; }

// s = n * d + return
inline Qdoub mod_fl(Long_O n, Qdoub_I s, Qdoub_I d)
{
	n = floor(s/d);
	return s - n * d;
}

inline Qdoub mod_eu(Qdoub_I s, Qdoub_I d)
{
	Long n = s/d;
	Qdoub r = s - n*d;
	return r < 0 ? r + abs(d) : r;
}

// s = n * d + return
inline Qdoub mod_eu(Long_O n, Qdoub_I s, Qdoub_I d)
{
	n = s/d;
	Qdoub r = s - n*d;
	if (r < 0) {
		r += abs(d);
		n -= sign(d);
	}
	return r;
}


template <class T>
inline T sqr(const T &x) { return x * x; }

template <class T>
inline T cube(const T &x) { return x*x*x; }

// b^n that output an integer 
inline Int pow(Int b, Uint n) {
	Int r = 1;
	while (n > 0) {
		if (n & 1) // odd
			r *= b;
		b *= b; n >>= 1;
	}
	return r;
}

inline Llong pow(Llong b, Uint n) {
	Llong r = 1;
	while (n > 0) {
		if (n & 1) // odd
			r *= b;
		b *= b; n >>= 1;
	}
	return r;
}


inline Int abs2(Int_I a) { return a * a; }

inline Llong abs2(Llong_I a) { return a * a; }

inline Doub abs2(Doub_I a) { return a * a; }

inline Doub abs2(Comp_I a) { return sqr(real(a)) + sqr(imag(a)); }


inline Float conj(Float_I r) { return r; }

inline Doub conj(Doub_I r) { return r; }

inline Ldoub conj(Ldoub_I r) { return r; }

inline Qdoub conj(Qdoub_I r) { return r; }


inline Doub factorial(int n) {
	if (n > 170)
		SLS_ERR("n too large!");
	Doub ret = 1;
	for (int i = 2; i <= n; ++i)
		ret *= i;
	return ret;
}

inline Llong factorial_ll(int n) {
	if (n > 20)
		SLS_ERR("n too large!");
	Llong ret = 1;
	for (int i = 2; i <= n; ++i)
		ret *= i;
	return ret;
}

#ifdef SLS_USE_QUAD_MATH
inline Qdoub factoria_lq(Int_I n) {
	if (n > 1754)
		SLS_ERR("n too large!");
	Qdoub ret = 1;
	for (Int i = 2; i <= n; ++i)
		ret *= i;
	return ret;
}
#endif

// common api for STL and SLISC
template <class T> inline Long size(const vector<T> &v) { return (Long)v.size(); }

template <class T> inline Long size(const set<T> &v) { return (Long)v.size(); }

template <class T> inline Long size(const unordered_set<T> &v) { return (Long)v.size(); }

template <class T> inline Long size(const deque<T> &v) { return (Long)v.size(); }

template <class T> inline Long size(const stack<T> &v) { return (Long)v.size(); }

template <class T> inline Long size(const std::basic_string<T> &v) { return (Long)v.size(); }


template <class T, class U> inline Long size(const map<T,U> &v) { return (Long)v.size(); }

template <class T, class U> inline Long size(const unordered_map<T,U> &v) { return (Long)v.size(); }


template <class T>
inline T *ptr(vector<T> &v)
{
	// using `const vector<T> &` doesn't allow element modification!
	// there is no "lower level const" for `std::vector`
#ifdef SLS_CHECK_BOUNDS
	SLS_ASSERT(v.size());
#endif
	return v.data();
}

template <class T>
inline const T *cptr(const vector<T> &v)
{
#ifdef SLS_CHECK_BOUNDS
	SLS_ASSERT(v.size());
#endif
	return v.data();
}

// get the size of an std::tuple
// see also `std::tuple_size<tuple>`
template <typename... Ts>
constexpr Long size(const std::tuple<Ts...>&) { return (Long)sizeof...(Ts); }

inline Doub sinc(Doub_I x) { return x == 0. ? 1. : sin(x) / x; }


} // namespace slisc
