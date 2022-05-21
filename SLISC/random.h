// generate random numbers

#pragma once
#include "arithmetic.h"
#include <ctime>
#ifdef SLS_USE_QUAD_MATH
#include "quad_math.h"
#endif

#ifndef SLS_RAND_SEED
// default random seed, update every second
#define SLS_RAND_SEED std::time(nullptr)
#endif

namespace slisc
{
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
#endif

// generate random Int in {0,1,2,...,N-1}
inline Int randInt(Int_I N)
{
    return Int(round(N*randDoub() - 0.5));
}

// generate random Long in {0,1,2,...,N-1}
inline Long randLong(Long_I N)
{
    return Long(round(N*randDoub() - 0.5));
}

// generate a random permutation of {0,1,2,...,N-1}
inline void randPerm(VecInt_O perm, Int_I N)
{
#ifdef SLS_CHECK_SHAPES
    if (perm.size() != N)
        SLS_ERR("wrong shape!");
#endif
    VecInt pool(N);
    linspace(pool, 0, N - 1);
    for (Long n = N; n > 0; --n) {
        Long ind = randInt(n);
        perm[n - 1] = pool[ind];
        for (Long j = ind; j < n - 1; ++j)
            pool[j] = pool[j + 1];
    }
}

inline Comp randComp()
{
    return Comp(randDoub(), randDoub());
}

inline void rand(VecLlong_O v, Long_I N)
{
    Long i, Nv = v.size();
    for (i = 0; i < Nv; ++i)
        v[i] = randLong(N);
}

inline void rand(VecDoub_O &v)
{
    Long i, N = v.size();
    for (i = 0; i < N; ++i)
        v[i] = randDoub();
}

inline void rand(VecComp_O &v)
{
    Long i, N = v.size();
    for (i = 0; i < N; ++i)
        v[i] = randComp();
}

inline void rand(SvecLlong_O v, Long_I N)
{
    Long i, Nv = v.size();
    for (i = 0; i < Nv; ++i)
        v[i] = randLong(N);
}

inline void rand(SvecDoub_O &v)
{
    Long i, N = v.size();
    for (i = 0; i < N; ++i)
        v[i] = randDoub();
}

inline void rand(SvecComp_O &v)
{
    Long i, N = v.size();
    for (i = 0; i < N; ++i)
        v[i] = randComp();
}

inline void rand(MatLlong_O v, Long_I N)
{
    Long i, Nv = v.size();
    for (i = 0; i < Nv; ++i)
        v[i] = randLong(N);
}

inline void rand(MatDoub_O &v)
{
    Long i, N = v.size();
    for (i = 0; i < N; ++i)
        v[i] = randDoub();
}

inline void rand(MatComp_O &v)
{
    Long i, N = v.size();
    for (i = 0; i < N; ++i)
        v[i] = randComp();
}

inline void rand(CmatLlong_O v, Long_I N)
{
    Long i, Nv = v.size();
    for (i = 0; i < Nv; ++i)
        v[i] = randLong(N);
}

inline void rand(CmatDoub_O &v)
{
    Long i, N = v.size();
    for (i = 0; i < N; ++i)
        v[i] = randDoub();
}

inline void rand(CmatComp_O &v)
{
    Long i, N = v.size();
    for (i = 0; i < N; ++i)
        v[i] = randComp();
}

inline void rand(Cmat3Llong_O v, Long_I N)
{
    Long i, Nv = v.size();
    for (i = 0; i < Nv; ++i)
        v[i] = randLong(N);
}

inline void rand(Cmat3Doub_O &v)
{
    Long i, N = v.size();
    for (i = 0; i < N; ++i)
        v[i] = randDoub();
}

inline void rand(Cmat3Comp_O &v)
{
    Long i, N = v.size();
    for (i = 0; i < N; ++i)
        v[i] = randComp();
}

inline void rand(ScmatLlong_O v, Long_I N)
{
    Long i, Nv = v.size();
    for (i = 0; i < Nv; ++i)
        v[i] = randLong(N);
}

inline void rand(ScmatDoub_O &v)
{
    Long i, N = v.size();
    for (i = 0; i < N; ++i)
        v[i] = randDoub();
}

inline void rand(ScmatComp_O &v)
{
    Long i, N = v.size();
    for (i = 0; i < N; ++i)
        v[i] = randComp();
}

}
