// functions that loop through every element of a container
#pragma once
#include "scalar_arith.h"
#include "compare.h"

namespace slisc {
// maximum/minimum element (pointer version)
// max_v(), min_v()
inline Doub max_v(const Doub *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Doub s = v[0];
    for (Long i = 1; i < N; ++i) {
        if (s < v[i])
            s = v[i];
    }
    return s;
}

inline Doub max_v(const Doub *v, Long_I N, Long_I step)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Doub s = v[0];
    for (Long i = step; i < N*step; i += step) {
        if (s < v[i])
            s = v[i];
    }
    return s;
}

inline Doub max_v(Long_O ind, const Doub *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Doub s = v[0];
    for (Long i = 1; i < N; ++i) {
        if (s < v[i]) {
            s = v[i];  ind = i;
        }
    }
    return s;
}

inline Doub max_v(Long_O ind, const Doub *v, Long_I N, Long_I step)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Doub s = v[0];
    for (Long i = step; i < N*step; i += step) {
        if (s < v[i]) {
            s = v[i];  ind = i;
        }
    }
    return s;
}

inline Doub min_v(const Doub *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Doub s = v[0];
    for (Long i = 1; i < N; ++i) {
        if (s > v[i])
            s = v[i];
    }
    return s;
}

inline Doub min_v(const Doub *v, Long_I N, Long_I step)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Doub s = v[0];
    for (Long i = step; i < N*step; i += step) {
        if (s > v[i])
            s = v[i];
    }
    return s;
}

inline Doub min_v(Long_O ind, const Doub *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Doub s = v[0];
    for (Long i = 1; i < N; ++i) {
        if (s > v[i]) {
            s = v[i];  ind = i;
        }
    }
    return s;
}

inline Doub min_v(Long_O ind, const Doub *v, Long_I N, Long_I step)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Doub s = v[0];
    for (Long i = step; i < N*step; i += step) {
        if (s > v[i]) {
            s = v[i];  ind = i;
        }
    }
    return s;
}

inline Int max_v(const Int *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Int s = v[0];
    for (Long i = 1; i < N; ++i) {
        if (s < v[i])
            s = v[i];
    }
    return s;
}

inline Int max_v(const Int *v, Long_I N, Long_I step)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Int s = v[0];
    for (Long i = step; i < N*step; i += step) {
        if (s < v[i])
            s = v[i];
    }
    return s;
}

inline Int max_v(Long_O ind, const Int *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Int s = v[0];
    for (Long i = 1; i < N; ++i) {
        if (s < v[i]) {
            s = v[i];  ind = i;
        }
    }
    return s;
}

inline Int max_v(Long_O ind, const Int *v, Long_I N, Long_I step)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Int s = v[0];
    for (Long i = step; i < N*step; i += step) {
        if (s < v[i]) {
            s = v[i];  ind = i;
        }
    }
    return s;
}

inline Int min_v(const Int *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Int s = v[0];
    for (Long i = 1; i < N; ++i) {
        if (s > v[i])
            s = v[i];
    }
    return s;
}

inline Int min_v(const Int *v, Long_I N, Long_I step)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Int s = v[0];
    for (Long i = step; i < N*step; i += step) {
        if (s > v[i])
            s = v[i];
    }
    return s;
}

inline Int min_v(Long_O ind, const Int *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Int s = v[0];
    for (Long i = 1; i < N; ++i) {
        if (s > v[i]) {
            s = v[i];  ind = i;
        }
    }
    return s;
}

inline Int min_v(Long_O ind, const Int *v, Long_I N, Long_I step)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Int s = v[0];
    for (Long i = step; i < N*step; i += step) {
        if (s > v[i]) {
            s = v[i];  ind = i;
        }
    }
    return s;
}

inline Llong max_v(const Llong *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Llong s = v[0];
    for (Long i = 1; i < N; ++i) {
        if (s < v[i])
            s = v[i];
    }
    return s;
}

inline Llong max_v(const Llong *v, Long_I N, Long_I step)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Llong s = v[0];
    for (Long i = step; i < N*step; i += step) {
        if (s < v[i])
            s = v[i];
    }
    return s;
}

inline Llong max_v(Long_O ind, const Llong *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Llong s = v[0];
    for (Long i = 1; i < N; ++i) {
        if (s < v[i]) {
            s = v[i];  ind = i;
        }
    }
    return s;
}

inline Llong max_v(Long_O ind, const Llong *v, Long_I N, Long_I step)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Llong s = v[0];
    for (Long i = step; i < N*step; i += step) {
        if (s < v[i]) {
            s = v[i];  ind = i;
        }
    }
    return s;
}

inline Llong min_v(const Llong *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Llong s = v[0];
    for (Long i = 1; i < N; ++i) {
        if (s > v[i])
            s = v[i];
    }
    return s;
}

inline Llong min_v(const Llong *v, Long_I N, Long_I step)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Llong s = v[0];
    for (Long i = step; i < N*step; i += step) {
        if (s > v[i])
            s = v[i];
    }
    return s;
}

inline Llong min_v(Long_O ind, const Llong *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Llong s = v[0];
    for (Long i = 1; i < N; ++i) {
        if (s > v[i]) {
            s = v[i];  ind = i;
        }
    }
    return s;
}

inline Llong min_v(Long_O ind, const Llong *v, Long_I N, Long_I step)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Llong s = v[0];
    for (Long i = step; i < N*step; i += step) {
        if (s > v[i]) {
            s = v[i];  ind = i;
        }
    }
    return s;
}


inline Int max(VecInt_I v)
{ return max_v(v.p(), v.size()); }

inline Int max(Long_O ind, VecInt_I v)
{ return max_v(ind, v.p(), v.size()); }

inline Int min(VecInt_I v)
{ return min_v(v.p(), v.size()); }

inline Int min(Long_O ind, VecInt_I v)
{ return min_v(ind, v.p(), v.size()); }

inline Llong max(VecLlong_I v)
{ return max_v(v.p(), v.size()); }

inline Llong max(Long_O ind, VecLlong_I v)
{ return max_v(ind, v.p(), v.size()); }

inline Llong min(VecLlong_I v)
{ return min_v(v.p(), v.size()); }

inline Llong min(Long_O ind, VecLlong_I v)
{ return min_v(ind, v.p(), v.size()); }

inline Doub max(VecDoub_I v)
{ return max_v(v.p(), v.size()); }

inline Doub max(Long_O ind, VecDoub_I v)
{ return max_v(ind, v.p(), v.size()); }

inline Doub min(VecDoub_I v)
{ return min_v(v.p(), v.size()); }

inline Doub min(Long_O ind, VecDoub_I v)
{ return min_v(ind, v.p(), v.size()); }

inline Int max(SvecInt_I v)
{ return max_v(v.p(), v.size()); }

inline Int max(Long_O ind, SvecInt_I v)
{ return max_v(ind, v.p(), v.size()); }

inline Int min(SvecInt_I v)
{ return min_v(v.p(), v.size()); }

inline Int min(Long_O ind, SvecInt_I v)
{ return min_v(ind, v.p(), v.size()); }

inline Llong max(SvecLlong_I v)
{ return max_v(v.p(), v.size()); }

inline Llong max(Long_O ind, SvecLlong_I v)
{ return max_v(ind, v.p(), v.size()); }

inline Llong min(SvecLlong_I v)
{ return min_v(v.p(), v.size()); }

inline Llong min(Long_O ind, SvecLlong_I v)
{ return min_v(ind, v.p(), v.size()); }

inline Doub max(SvecDoub_I v)
{ return max_v(v.p(), v.size()); }

inline Doub max(Long_O ind, SvecDoub_I v)
{ return max_v(ind, v.p(), v.size()); }

inline Doub min(SvecDoub_I v)
{ return min_v(v.p(), v.size()); }

inline Doub min(Long_O ind, SvecDoub_I v)
{ return min_v(ind, v.p(), v.size()); }


inline Doub max_abs_v(const Doub *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Doub s = abs(v[0]), val;
    for (Long i = 1; i < N; ++i) {
        val = abs(v[i]);
        if (s < val)
            s = val;
    }
    return s;
}

inline Doub max_abs_v(const Doub *v, Long_I N, Long_I step)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Doub s = abs(v[0]), val;
    for (Long i = step; i < N*step; i += step) {
        val = abs(v[i]);
        if (s < val)
            s = val;
    }
    return s;
}

inline Doub max_abs_v(const Comp *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Doub s = abs(v[0]), val;
    for (Long i = 1; i < N; ++i) {
        val = abs(v[i]);
        if (s < val)
            s = val;
    }
    return s;
}

inline Doub max_abs_v(const Comp *v, Long_I N, Long_I step)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Doub s = abs(v[0]), val;
    for (Long i = step; i < N*step; i += step) {
        val = abs(v[i]);
        if (s < val)
            s = val;
    }
    return s;
}

inline Int max_abs_v(const Int *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Int s = abs(v[0]), val;
    for (Long i = 1; i < N; ++i) {
        val = abs(v[i]);
        if (s < val)
            s = val;
    }
    return s;
}

inline Int max_abs_v(const Int *v, Long_I N, Long_I step)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Int s = abs(v[0]), val;
    for (Long i = step; i < N*step; i += step) {
        val = abs(v[i]);
        if (s < val)
            s = val;
    }
    return s;
}

inline Qdoub max_abs_v(const Qdoub *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Qdoub s = abs(v[0]), val;
    for (Long i = 1; i < N; ++i) {
        val = abs(v[i]);
        if (s < val)
            s = val;
    }
    return s;
}

inline Qdoub max_abs_v(const Qdoub *v, Long_I N, Long_I step)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Qdoub s = abs(v[0]), val;
    for (Long i = step; i < N*step; i += step) {
        val = abs(v[i]);
        if (s < val)
            s = val;
    }
    return s;
}


inline Doub max_abs(VecDoub_I v)
{
    return max_abs_v(v.p(), v.size());
}

inline Doub max_abs(VecComp_I v)
{
    return max_abs_v(v.p(), v.size());
}

inline Int max_abs(VecInt_I v)
{
    return max_abs_v(v.p(), v.size());
}

inline Qdoub max_abs(VecQdoub_I v)
{
    return max_abs_v(v.p(), v.size());
}

inline Doub max_abs(SvecComp_I v)
{
    return max_abs_v(v.p(), v.size());
}

inline Doub max_abs(DvecDoub_I v)
{
    return max_abs_v(v.p(), v.size(), v.step());
}

inline Doub max_abs(DvecComp_I v)
{
    return max_abs_v(v.p(), v.size(), v.step());
}

inline Doub max_abs(CmatDoub_I v)
{
    return max_abs_v(v.p(), v.size());
}

inline Doub max_abs(CmatComp_I v)
{
    return max_abs_v(v.p(), v.size());
}

inline Doub max_abs(MatComp_I v)
{
    return max_abs_v(v.p(), v.size());
}


// sum of absolute values
inline Llong sum_abs_v(const Int *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Llong s = abs(v[0]);
    for (Long i = 1; i < N; ++i)
        s += abs(v[i]);
    return s;
}

inline Llong sum_abs_v(const Llong *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Llong s = abs(v[0]);
    for (Long i = 1; i < N; ++i)
        s += abs(v[i]);
    return s;
}

inline Doub sum_abs_v(const Doub *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Doub s = abs(v[0]);
    for (Long i = 1; i < N; ++i)
        s += abs(v[i]);
    return s;
}

inline Doub sum_abs_v(const Comp *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Doub s = abs(v[0]);
    for (Long i = 1; i < N; ++i)
        s += abs(v[i]);
    return s;
}


// sum of absolute values
inline Llong sum_abs(VecInt_I v)
{ return sum_abs_v(v.p(), v.size()); }

inline Llong sum_abs(VecLlong_I v)
{ return sum_abs_v(v.p(), v.size()); }

inline Doub sum_abs(VecDoub_I v)
{ return sum_abs_v(v.p(), v.size()); }

inline Doub sum_abs(VecComp_I v)
{ return sum_abs_v(v.p(), v.size()); }

inline Llong sum_abs(SvecInt_I v)
{ return sum_abs_v(v.p(), v.size()); }

inline Llong sum_abs(SvecLlong_I v)
{ return sum_abs_v(v.p(), v.size()); }

inline Doub sum_abs(SvecDoub_I v)
{ return sum_abs_v(v.p(), v.size()); }

inline Doub sum_abs(SvecComp_I v)
{ return sum_abs_v(v.p(), v.size()); }

inline Llong sum_abs(CmatInt_I v)
{ return sum_abs_v(v.p(), v.size()); }

inline Llong sum_abs(CmatLlong_I v)
{ return sum_abs_v(v.p(), v.size()); }

inline Doub sum_abs(CmatDoub_I v)
{ return sum_abs_v(v.p(), v.size()); }

inline Doub sum_abs(CmatComp_I v)
{ return sum_abs_v(v.p(), v.size()); }

inline Llong sum_abs(ScmatInt_I v)
{ return sum_abs_v(v.p(), v.size()); }

inline Llong sum_abs(ScmatLlong_I v)
{ return sum_abs_v(v.p(), v.size()); }

inline Doub sum_abs(ScmatDoub_I v)
{ return sum_abs_v(v.p(), v.size()); }

inline Doub sum_abs(ScmatComp_I v)
{ return sum_abs_v(v.p(), v.size()); }


inline Long sum_abs(VecBool_I v)
{
    Long N = v.size();
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Long s = v[0];
    for (Long i = 1; i < N; ++i)
        s += v[i];
    return s;
}


inline Doub sum_v(const Doub *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Doub s = v[0];
    for (Long i = 1; i < N; ++i)
        s += v[i];
    return s;
}

inline Doub prod_v(const Doub *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Doub s = v[0];
    for (Long i = 1; i < N; ++i)
        s *= v[i];
    return s;
}

inline Llong sum_v(const Int *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Llong s = v[0];
    for (Long i = 1; i < N; ++i)
        s += v[i];
    return s;
}

inline Llong prod_v(const Int *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Llong s = v[0];
    for (Long i = 1; i < N; ++i)
        s *= v[i];
    return s;
}

inline Llong sum_v(const Llong *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Llong s = v[0];
    for (Long i = 1; i < N; ++i)
        s += v[i];
    return s;
}

inline Llong prod_v(const Llong *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Llong s = v[0];
    for (Long i = 1; i < N; ++i)
        s *= v[i];
    return s;
}

inline Comp sum_v(const Comp *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Comp s = v[0];
    for (Long i = 1; i < N; ++i)
        s += v[i];
    return s;
}

inline Comp prod_v(const Comp *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Comp s = v[0];
    for (Long i = 1; i < N; ++i)
        s *= v[i];
    return s;
}


inline Llong sum(VecInt_I v)
{ return sum_v(v.p(), v.size()); }

inline Llong prod(VecInt_I v)
{ return prod_v(v.p(), v.size()); }

inline Llong sum(VecLlong_I v)
{ return sum_v(v.p(), v.size()); }

inline Llong prod(VecLlong_I v)
{ return prod_v(v.p(), v.size()); }

inline Doub sum(VecDoub_I v)
{ return sum_v(v.p(), v.size()); }

inline Doub prod(VecDoub_I v)
{ return prod_v(v.p(), v.size()); }

inline Comp sum(VecComp_I v)
{ return sum_v(v.p(), v.size()); }

inline Comp prod(VecComp_I v)
{ return prod_v(v.p(), v.size()); }

inline Doub sum(CmatDoub_I v)
{ return sum_v(v.p(), v.size()); }

inline Doub prod(CmatDoub_I v)
{ return prod_v(v.p(), v.size()); }

inline Comp sum(CmatComp_I v)
{ return sum_v(v.p(), v.size()); }

inline Comp prod(CmatComp_I v)
{ return prod_v(v.p(), v.size()); }

inline Comp sum(MatComp_I v)
{ return sum_v(v.p(), v.size()); }

inline Comp prod(MatComp_I v)
{ return prod_v(v.p(), v.size()); }

inline Doub sum(SvecDoub_I v)
{ return sum_v(v.p(), v.size()); }

inline Doub prod(SvecDoub_I v)
{ return prod_v(v.p(), v.size()); }


inline Doub norm2(VecDoub_I v)
{
    Long N = v.size();
    Doub s2 = abs2(v[0]);
    for (Long i = 1; i < N; ++i)
        s2 += abs2(v[i]);
    return s2;
}

inline Doub norm2_dif(VecDoub_I v, VecDoub_I v1)
{
    Long N = v.size();
    Doub s2 = abs2(v[0] - v1[0]);
    for (Long i = 1; i < N; ++i)
        s2 += abs2(v[i] - v1[i]);
    return s2;
}
inline Doub norm(VecDoub_I v)
{
    return sqrt(norm2(v));
}

inline Doub norm_dif(VecDoub_I v, VecDoub_I v1)
{
    return sqrt(norm2_dif(v, v1));
}

inline Doub norm2(VecComp_I v)
{
    Long N = v.size();
    Doub s2 = abs2(v[0]);
    for (Long i = 1; i < N; ++i)
        s2 += abs2(v[i]);
    return s2;
}

inline Doub norm2_dif(VecComp_I v, VecComp_I v1)
{
    Long N = v.size();
    Doub s2 = abs2(v[0] - v1[0]);
    for (Long i = 1; i < N; ++i)
        s2 += abs2(v[i] - v1[i]);
    return s2;
}
inline Doub norm(VecComp_I v)
{
    return sqrt(norm2(v));
}

inline Doub norm_dif(VecComp_I v, VecComp_I v1)
{
    return sqrt(norm2_dif(v, v1));
}

inline Doub norm2(SvecDoub_I v)
{
    Long N = v.size();
    Doub s2 = abs2(v[0]);
    for (Long i = 1; i < N; ++i)
        s2 += abs2(v[i]);
    return s2;
}

inline Doub norm2_dif(SvecDoub_I v, SvecDoub_I v1)
{
    Long N = v.size();
    Doub s2 = abs2(v[0] - v1[0]);
    for (Long i = 1; i < N; ++i)
        s2 += abs2(v[i] - v1[i]);
    return s2;
}
inline Doub norm(SvecDoub_I v)
{
    return sqrt(norm2(v));
}

inline Doub norm_dif(SvecDoub_I v, SvecDoub_I v1)
{
    return sqrt(norm2_dif(v, v1));
}

inline Doub norm2(SvecComp_I v)
{
    Long N = v.size();
    Doub s2 = abs2(v[0]);
    for (Long i = 1; i < N; ++i)
        s2 += abs2(v[i]);
    return s2;
}

inline Doub norm2_dif(SvecComp_I v, SvecComp_I v1)
{
    Long N = v.size();
    Doub s2 = abs2(v[0] - v1[0]);
    for (Long i = 1; i < N; ++i)
        s2 += abs2(v[i] - v1[i]);
    return s2;
}
inline Doub norm(SvecComp_I v)
{
    return sqrt(norm2(v));
}

inline Doub norm_dif(SvecComp_I v, SvecComp_I v1)
{
    return sqrt(norm2_dif(v, v1));
}

inline Doub norm2(DvecDoub_I v)
{
    Long N = v.size();
    Doub s2 = abs2(v[0]);
    for (Long i = 1; i < N; ++i)
        s2 += abs2(v[i]);
    return s2;
}

inline Doub norm2_dif(DvecDoub_I v, DvecDoub_I v1)
{
    Long N = v.size();
    Doub s2 = abs2(v[0] - v1[0]);
    for (Long i = 1; i < N; ++i)
        s2 += abs2(v[i] - v1[i]);
    return s2;
}
inline Doub norm(DvecDoub_I v)
{
    return sqrt(norm2(v));
}

inline Doub norm_dif(DvecDoub_I v, DvecDoub_I v1)
{
    return sqrt(norm2_dif(v, v1));
}

inline Doub norm2(CmatDoub_I v)
{
    Long N = v.size();
    Doub s2 = abs2(v[0]);
    for (Long i = 1; i < N; ++i)
        s2 += abs2(v[i]);
    return s2;
}

inline Doub norm2_dif(CmatDoub_I v, CmatDoub_I v1)
{
    Long N = v.size();
    Doub s2 = abs2(v[0] - v1[0]);
    for (Long i = 1; i < N; ++i)
        s2 += abs2(v[i] - v1[i]);
    return s2;
}
inline Doub norm(CmatDoub_I v)
{
    return sqrt(norm2(v));
}

inline Doub norm_dif(CmatDoub_I v, CmatDoub_I v1)
{
    return sqrt(norm2_dif(v, v1));
}

inline Doub norm2(CmatComp_I v)
{
    Long N = v.size();
    Doub s2 = abs2(v[0]);
    for (Long i = 1; i < N; ++i)
        s2 += abs2(v[i]);
    return s2;
}

inline Doub norm2_dif(CmatComp_I v, CmatComp_I v1)
{
    Long N = v.size();
    Doub s2 = abs2(v[0] - v1[0]);
    for (Long i = 1; i < N; ++i)
        s2 += abs2(v[i] - v1[i]);
    return s2;
}
inline Doub norm(CmatComp_I v)
{
    return sqrt(norm2(v));
}

inline Doub norm_dif(CmatComp_I v, CmatComp_I v1)
{
    return sqrt(norm2_dif(v, v1));
}

inline Doub norm2(MatDoub_I v)
{
    Long N = v.size();
    Doub s2 = abs2(v[0]);
    for (Long i = 1; i < N; ++i)
        s2 += abs2(v[i]);
    return s2;
}

inline Doub norm2_dif(MatDoub_I v, MatDoub_I v1)
{
    Long N = v.size();
    Doub s2 = abs2(v[0] - v1[0]);
    for (Long i = 1; i < N; ++i)
        s2 += abs2(v[i] - v1[i]);
    return s2;
}
inline Doub norm(MatDoub_I v)
{
    return sqrt(norm2(v));
}

inline Doub norm_dif(MatDoub_I v, MatDoub_I v1)
{
    return sqrt(norm2_dif(v, v1));
}

inline Doub norm2(MatComp_I v)
{
    Long N = v.size();
    Doub s2 = abs2(v[0]);
    for (Long i = 1; i < N; ++i)
        s2 += abs2(v[i]);
    return s2;
}

inline Doub norm2_dif(MatComp_I v, MatComp_I v1)
{
    Long N = v.size();
    Doub s2 = abs2(v[0] - v1[0]);
    for (Long i = 1; i < N; ++i)
        s2 += abs2(v[i] - v1[i]);
    return s2;
}
inline Doub norm(MatComp_I v)
{
    return sqrt(norm2(v));
}

inline Doub norm_dif(MatComp_I v, MatComp_I v1)
{
    return sqrt(norm2_dif(v, v1));
}

inline Doub norm2(ScmatComp_I v)
{
    Long N = v.size();
    Doub s2 = abs2(v[0]);
    for (Long i = 1; i < N; ++i)
        s2 += abs2(v[i]);
    return s2;
}

inline Doub norm2_dif(ScmatComp_I v, ScmatComp_I v1)
{
    Long N = v.size();
    Doub s2 = abs2(v[0] - v1[0]);
    for (Long i = 1; i < N; ++i)
        s2 += abs2(v[i] - v1[i]);
    return s2;
}
inline Doub norm(ScmatComp_I v)
{
    return sqrt(norm2(v));
}

inline Doub norm_dif(ScmatComp_I v, ScmatComp_I v1)
{
    return sqrt(norm2_dif(v, v1));
}

inline Doub norm2(DcmatComp_I a)
{
    const Comp *p = a.p();
    Long Nr = a.n0(), lda = a.lda();
    Doub s2 = 0;
    for (Long j = 0; j < a.n1(); ++j) {
        for (Long i = 0; i < Nr; ++i)
            s2 += abs2(p[i]);
        p += lda;
    }
    return s2;
}

inline Doub norm2_dif(DcmatComp_I a, DcmatComp_I a1)
{
    const Comp *p = a.p(), *p1 = a1.p();
    Long Nr = a.n0(), lda = a.lda(), lda1 = a1.lda();
    Doub s2 = 0;
    for (Long j = 0; j < a.n1(); ++j) {
        for (Long i = 0; i < Nr; ++i)
            s2 += abs2(p[i] - p1[i]);
        p += lda; p1 += lda1;
    }
    return s2;
}
inline Doub norm(DcmatComp_I v)
{
    return sqrt(norm2(v));
}

inline Doub norm_dif(DcmatComp_I v, DcmatComp_I v1)
{
    return sqrt(norm2_dif(v, v1));
}

inline Doub norm2(Mat3Doub_I v)
{
    Long N = v.size();
    Doub s2 = abs2(v[0]);
    for (Long i = 1; i < N; ++i)
        s2 += abs2(v[i]);
    return s2;
}

inline Doub norm2_dif(Mat3Doub_I v, Mat3Doub_I v1)
{
    Long N = v.size();
    Doub s2 = abs2(v[0] - v1[0]);
    for (Long i = 1; i < N; ++i)
        s2 += abs2(v[i] - v1[i]);
    return s2;
}
inline Doub norm(Mat3Doub_I v)
{
    return sqrt(norm2(v));
}

inline Doub norm_dif(Mat3Doub_I v, Mat3Doub_I v1)
{
    return sqrt(norm2_dif(v, v1));
}

inline Doub norm2(Mat3Comp_I v)
{
    Long N = v.size();
    Doub s2 = abs2(v[0]);
    for (Long i = 1; i < N; ++i)
        s2 += abs2(v[i]);
    return s2;
}

inline Doub norm2_dif(Mat3Comp_I v, Mat3Comp_I v1)
{
    Long N = v.size();
    Doub s2 = abs2(v[0] - v1[0]);
    for (Long i = 1; i < N; ++i)
        s2 += abs2(v[i] - v1[i]);
    return s2;
}
inline Doub norm(Mat3Comp_I v)
{
    return sqrt(norm2(v));
}

inline Doub norm_dif(Mat3Comp_I v, Mat3Comp_I v1)
{
    return sqrt(norm2_dif(v, v1));
}

inline Doub norm2(Cmat3Comp_I v)
{
    Long N = v.size();
    Doub s2 = abs2(v[0]);
    for (Long i = 1; i < N; ++i)
        s2 += abs2(v[i]);
    return s2;
}

inline Doub norm2_dif(Cmat3Comp_I v, Cmat3Comp_I v1)
{
    Long N = v.size();
    Doub s2 = abs2(v[0] - v1[0]);
    for (Long i = 1; i < N; ++i)
        s2 += abs2(v[i] - v1[i]);
    return s2;
}
inline Doub norm(Cmat3Comp_I v)
{
    return sqrt(norm2(v));
}

inline Doub norm_dif(Cmat3Comp_I v, Cmat3Comp_I v1)
{
    return sqrt(norm2_dif(v, v1));
}

inline Doub norm2(DvecComp_I v)
{
    Long N = v.size();
    Doub s2 = abs2(v[0]);
    for (Long i = 1; i < N; ++i)
        s2 += abs2(v[i]);
    return s2;
}

inline Doub norm2_dif(DvecComp_I v, DvecComp_I v1)
{
    Long N = v.size();
    Doub s2 = abs2(v[0] - v1[0]);
    for (Long i = 1; i < N; ++i)
        s2 += abs2(v[i] - v1[i]);
    return s2;
}
inline Doub norm(DvecComp_I v)
{
    return sqrt(norm2(v));
}

inline Doub norm_dif(DvecComp_I v, DvecComp_I v1)
{
    return sqrt(norm2_dif(v, v1));
}

} // namespace slisc
