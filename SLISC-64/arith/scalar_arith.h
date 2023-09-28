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


inline Comp to_num(Comp_I x) { return x; }

inline Lcomp to_num(Lcomp_I x) { return x; }



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


inline Llong factorial_ll(int n) {
	if (n > 20)
		SLS_ERR("n too large!");
	Llong ret = 1;
	for (int i = 2; i <= n; ++i)
		ret *= i;
	return ret;
}

inline Doub factorial(int n) {
	if (n > 170)
		SLS_ERR("n too large!");
	Doub ret = 1;
	for (int i = 2; i <= n; ++i)
		ret *= i;
	return ret;
}

#ifdef SLS_USE_QUAD_MATH
inline Qdoub factorialq(Int_I n) {
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
inline const T *ptr(const vector<T> &v)
{
#ifdef SLS_CHECK_BOUNDS
	SLS_ASSERT(v.size());
#endif
	return v.data();
}

template <class T>
inline T *ptr(vector<T> &v)
{
#ifdef SLS_CHECK_BOUNDS
	SLS_ASSERT(v.size());
#endif
	return v.data();
}

// get the size of an std::tuple
// see also `std::tuple_size()`
template <typename... Ts>
constexpr Long size(const std::tuple<Ts...>&) { return (Long)sizeof...(Ts); }

// number of prime numbers smaller than n
// verified with leetcode 204
inline Long nprimes(Long_I N)
{
	if (N <= 2) return 0;
	if (N == 3) return 1;
	Long Nh = N/2;
	vector<bool> isprime(Nh, true); // isprime[i] for (2*i+1)
	for (Long i = 1; sqr(2*i+1) < N; ++i)
		if (isprime[i])
			for (Long p = 2*i+1, j = i+p; j < Nh; j += p)
				isprime[j] = false;
	Long ret = 2;
	for (Long i = 2; i < Nh; ++i)
		if (isprime[i])
			++ret;
	return ret;
}

// get all the prime numbers smaller than n
inline void primes(vecLong_O v, Long_I N)
{
	v.clear();
	if (N <= 2) return;
	v.push_back(2);
	if (N == 3) return;
	Long i, Nh = N/2;
	vector<bool> isprime(Nh, true); // isprime[i] for (2*i+1)
	for (i = 1; sqr(2*i+1) < N; ++i) {
		if (isprime[i]) {
			v.push_back(2*i+1);
			for (Long p = 2*i+1, j = i+p; j < Nh; j += p)
				isprime[j] = false;
		}
	}
	for (; i < Nh; ++i)
		if (isprime[i])
			v.push_back(2*i+1);
}

// extend a list of ordered prime numbers to smaller than N
// v = [2,3,5,7,11....]
inline void primes_ext(vecLong_IO v, Long_I N)
{
	// N_old is even
	Long Nv = v.size(), N_old = v.back()+1;
	assert(Nv >= 5);
	assert(N > N_old);
	Long i = 0, Nb = N/2-N_old/2;
	// isprime[i] for (N_old+2*i+1)
	vector<bool> isprime(Nb, true);
	for (Long i = 1; i < Nv; ++i) {
		Long p = v[i];
		Long n = N_old/p + 1;
		if (!isodd(n)) ++n;
		Long j_beg = (n*p - N_old)/2;
		for (Long j = j_beg; j < Nb; j += p)
			isprime[j] = false;
	}
	if (N_old+1 < sqrt(N))
		for (; sqr(N_old+2*i+1) < N; ++i) {
			if (isprime[i]) {
				v.push_back(N_old+2*i+1);
				for (Long p = N_old+2*i+1, j = i+p; j < Nb; j += p)
					isprime[j] = false;
			}
		}
	for (; i < Nb; ++i)
		if (isprime[i])
			v.push_back(N_old+2*i+1);
}

// get the at least first N prime numbers
inline void primes2(vecLong_O v, Long_I Nprime)
{
	Long N = 2*Nprime;
	primes(v, N);
	while (size(v) < Nprime) {
		N = max(Long(N*1.1), N/size(v)*Nprime);
		primes_ext(v, N);
	}
}

inline Doub sinc(Doub_I x) { return x == 0. ? 1. : sin(x) / x; }


} // namespace slisc
