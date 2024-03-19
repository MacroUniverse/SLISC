// generate random numbers

#pragma once
#include "../arith/arith2.h"
#include "../util/STL_util.h"
#include <ctime>

#ifndef SLS_RAND_SEED
	#ifdef NDEBUG
		// default random seed, update every second
		#define SLS_RAND_SEED std::time(nullptr)
	#else
		// stable seed for debug
		#define SLS_RAND_SEED 0
	#endif
#endif

namespace slisc {

namespace internal
{
	// Algorithm from Numerical Recipes 3ed
	// empty construcotr uses "std:time()" as seed, avoid calling it twice in the same second.
	// it is best if the whole program uses only one object, which is currently in randDoub() function.
	class Ran
	{
	private:
		Ullong u, v, w;
		Uint int32() { return (Uint)int64(); }
		Ullong int64() {
			u = u * 2862933555777941757LL + 7046029254386353087LL;
			v ^= v >> 17; v ^= v << 31; v ^= v >> 8;
			w = 4294957665U * (w & 0xffffffff) + (w >> 32);
			Ullong x = u ^ (u << 21); x ^= x >> 35; x ^= x << 4;
			return (x + v) ^ w;
		}
	public:
		Ran(Ullong j = SLS_RAND_SEED) :
			v(4101842887655102017LL), w(1) {
			u = j ^ v; int64();
			v = u; int64();
			w = v; int64();
		}
		Doub doub() { return 5.42101086242752217E-20 * int64(); }
#ifdef SLS_USE_QUAD_MATH
		Qdoub qdoub() {
			// random int128 = int64()*2^64 + int64()
			Qdoub q = int64()*18446744073709551616.0Q + int64();
			q *= 2.9387358770557187699218413430556142e-39Q; // q *= 2^-128
			return q;
		}
#endif
	};
}

// generate random Doub in [0, 1]
inline Doub randDoub()
{
	static internal::Ran rand_gen;
	return rand_gen.doub();
}

#ifdef SLS_USE_QUAD_MATH
// generate random Qdoub in [0, 1]
inline Qdoub randQdoub()
{
	static internal::Ran rand_gen;
	return rand_gen.qdoub();
}

inline Qcomp randQcomp()
{
	static internal::Ran rand_gen;
	return Qcomp(rand_gen.qdoub(), rand_gen.qdoub());
}
#endif

// generate random Int in {0,1,2,...,N-1}
inline Int randInt(Int_I N)
{
	return Int(round(N*randDoub() - 0.5));
}

inline Long randLlong(Llong_I N)
{
	return round(N*randDoub() - 0.5);
}

inline Long randLong(Long_I N)
{
	return round(N*randDoub() - 0.5);
}

// generate a random permutation of {0,1,2,...,N-1}
inline void randPerm(vecInt_O v)
{
	Long N = v.size(), N_1 = N - 1;
	linspace(v, 0, N_1);
	for (Long i = 0; i < N_1; ++i) {
		Int ind = randInt(N-i) + i;
		if (ind != i)
			swap(v[i], v[ind]);
	}
}

inline void randPerm(vecLlong_O v)
{
	Long N = v.size(), N_1 = N - 1;
	linspace(v, 0, N_1);
	for (Long i = 0; i < N_1; ++i) {
		Llong ind = randLlong(N-i) + i;
		if (ind != i)
			swap(v[i], v[ind]);
	}
}

inline void randPerm(VecInt_O v)
{
	Long N = v.size(), N_1 = N - 1;
	linspace(v, 0, N_1);
	for (Long i = 0; i < N_1; ++i) {
		Int ind = randInt(N-i) + i;
		if (ind != i)
			swap(v[i], v[ind]);
	}
}

inline void randPerm(VecLlong_O v)
{
	Long N = v.size(), N_1 = N - 1;
	linspace(v, 0, N_1);
	for (Long i = 0; i < N_1; ++i) {
		Llong ind = randLlong(N-i) + i;
		if (ind != i)
			swap(v[i], v[ind]);
	}
}


inline Comp randComp()
{
	return Comp(randDoub(), randDoub());
}

inline void rand(vecInt_O v)
{
	Long i, N = v.size();
	for (i = 0; i < N; ++i)
		v[i] = randInt(N);
}

inline void rand(vecLlong_O v)
{
	Long i, N = v.size();
	for (i = 0; i < N; ++i)
		v[i] = randLong(N);
}

inline void rand(VecInt_O v)
{
	Long i, N = v.size();
	for (i = 0; i < N; ++i)
		v[i] = randInt(N);
}

inline void rand(VecLlong_O v)
{
	Long i, N = v.size();
	for (i = 0; i < N; ++i)
		v[i] = randLong(N);
}

inline void rand(VecDoub_O v)
{
	Long i, N = v.size();
	for (i = 0; i < N; ++i)
		v[i] = randDoub();
}


inline void rand(VecComp_O v)
{
	Long i, N = v.size();
	for (i = 0; i < N; ++i)
		v[i] = randComp();
}


inline void rand(SvecLlong_O v)
{
	Long i, N = v.size();
	for (i = 0; i < N; ++i)
		v[i] = randLong(N);
}

inline void rand(SvecDoub_O v)
{
	Long i, N = v.size();
	for (i = 0; i < N; ++i)
		v[i] = randDoub();
}

inline void rand(SvecComp_O v)
{
	Long i, N = v.size();
	for (i = 0; i < N; ++i)
		v[i] = randComp();
}

inline void rand(MatLlong_O v)
{
	Long i, N = v.size();
	for (i = 0; i < N; ++i)
		v[i] = randLong(N);
}

inline void rand(MatDoub_O v)
{
	Long i, N = v.size();
	for (i = 0; i < N; ++i)
		v[i] = randDoub();
}

inline void rand(MatComp_O v)
{
	Long i, N = v.size();
	for (i = 0; i < N; ++i)
		v[i] = randComp();
}

inline void rand(CmatLlong_O v)
{
	Long i, N = v.size();
	for (i = 0; i < N; ++i)
		v[i] = randLong(N);
}

inline void rand(CmatDoub_O v)
{
	Long i, N = v.size();
	for (i = 0; i < N; ++i)
		v[i] = randDoub();
}


inline void rand(CmatComp_O v)
{
	Long i, N = v.size();
	for (i = 0; i < N; ++i)
		v[i] = randComp();
}


inline void rand(Str_O v)
{
	Long i, N = v.size();
	for (i = 0; i < N; ++i)
		v[i] = randInt(26) + 'a';
}

inline void rand(Cmat3Llong_O v)
{
	Long i, N = v.size();
	for (i = 0; i < N; ++i)
		v[i] = randLong(N);
}

inline void rand(Cmat3Doub_O v)
{
	Long i, N = v.size();
	for (i = 0; i < N; ++i)
		v[i] = randDoub();
}

inline void rand(Cmat3Comp_O v)
{
	Long i, N = v.size();
	for (i = 0; i < N; ++i)
		v[i] = randComp();
}

inline void rand(ScmatLlong_O v)
{
	Long i, N = v.size();
	for (i = 0; i < N; ++i)
		v[i] = randLong(N);
}

inline void rand(ScmatDoub_O v)
{
	Long i, N = v.size();
	for (i = 0; i < N; ++i)
		v[i] = randDoub();
}

inline void rand(ScmatComp_O v)
{
	Long i, N = v.size();
	for (i = 0; i < N; ++i)
		v[i] = randComp();
}


// get n-th element from iterator
// for iterator supporting only ++
template<class T>
inline typename T::iterator rand_iter(T &s)
{
	return iter_ind(s, randLong(s.size()));
}

// generate 6 digit random hex string
inline Str rand_hex6() {
    stringstream ss;
    ss << std::hex << std::setfill('0') << std::setw(6) << randInt(16777216);
    return ss.str();
}

} // namespace slisc
