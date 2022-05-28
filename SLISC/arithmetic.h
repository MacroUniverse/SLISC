#pragma once
#include "copy.h"
#include "scalar_arith.h"
#include "cut.h"

namespace slisc {
// return signed size instead of unsigned
inline Long size(vecBool_I v) { return v.size(); }


// sum of absolute values
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


// sum of absolute values
inline Doub sum_abs(VecDoub_I v)
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


inline Doub max(VecDoub_I v)
{ return max_v(v.p(), v.size()); }

inline Doub max(Long_O ind, VecDoub_I v)
{ return max_v(ind, v.p(), v.size()); }

inline Doub min(VecDoub_I v)
{ return min_v(v.p(), v.size()); }

inline Doub min(Long_O ind, VecDoub_I v)
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


inline Doub max_abs(VecComp_I v)
{
    return max_abs_v(v.p(), v.size());
}


inline void mod_vvs(Llong *v, const Llong *v1, Llong_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = mod(v1[i], s);
}

inline void mod_vs(Llong *v, Llong_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = mod(v[i], s);
}

inline void mod_vvs(Doub *v, const Doub *v1, Doub_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = mod(v1[i], s);
}

inline void mod_vs(Doub *v, Doub_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = mod(v[i], s);
}

inline void mod_vvs(VecLlong *v, const VecLlong *v1, Llong_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = mod(v1[i], s);
}

inline void mod_vs(VecLlong *v, Llong_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = mod(v[i], s);
}


inline void mod(VecLlong_O v, Llong_I s)
{ mod_vs(v.p(), s, v.size()); }

inline void mod(VecLlong_O v, VecLlong_I v1, Llong_I s)
{
    assert_same_shape(v, v1);
    mod_vvs(v.p(), v1.p(), s, v.size());
}


inline void real_v(Comp *v, Long_I N)
{
    Doub *pr = (Doub *)v;
    for (Long i = 1; i < 2*N; i += 2)
        pr[i] = 0;
}

inline void imag_v(Comp *v, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = imag(v[i]);
}


inline void real_vv(Doub *v, const Comp *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = real(v1[i]); 
}

inline void imag_vv(Doub *v, const Comp *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = imag(v1[i]); 
}


inline void real(VecComp_IO v)
{ real_v(v.p(), v.size()); }

inline void imag(VecComp_IO v)
{ imag_v(v.p(), v.size()); }


inline void real(VecDoub_O v, VecComp_I v1)
{
    assert_same_shape(v, v1);
    real_vv(v.p(), v1.p(), v1.size());
}

inline void imag(VecDoub_O v, VecComp_I v1)
{
    assert_same_shape(v, v1);
    imag_vv(v.p(), v1.p(), v1.size());
}


inline void abs_v(Doub *v, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = abs(v[i]);
}

inline void abs_v(Comp *v, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = abs(v[i]);
}


inline void abs_vv(Doub *v, const Comp *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = abs(v1[i]); 
}


inline void abs(SvecComp_IO v)
{ abs_v(v.p(), v.size()); }


inline void abs(VecDoub_O v, VecComp_I v1)
{
    assert_same_shape(v, v1);
    abs_vv(v.p(), v1.p(), v1.size());
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


inline Doub sum(CmatDoub_I v)
{ return sum_v(v.p(), v.size()); }

inline Doub prod(CmatDoub_I v)
{ return prod_v(v.p(), v.size()); }


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


inline void resize_cpy(Cmat3Doub_IO v, Long_I N0, Long_I N1, Long_I N2, Doub_I val = 0)
{
    Long N10 = v.n0(), N20 = v.n1(), N30 = v.n2(), Nold = N0*N1;
    Long N = N0 * N1 * N2;
    if (N0 != N10 || N1 != N20 || N2 != N30) {
        if (Nold == 0) {
            v.resize(N0, N1, N2); copy(v, val);
        }
        else if (N == 0)
            v.resize(0, 0, 0);
        else {
            Cmat3Doub v1(N0, N1, N2); copy(v1, val);
            Long N1min = min(N0, N10), N2min = min(N1, N20), N3min = min(N2, N30);
            copy(cut(v1, 0, N1min, 0, N2min, 0, N3min),
                cut(v, 0, N1min, 0, N2min, 0, N3min));
            v << v1;
        }
    }
}


inline void linspace_vss(Doub *v, Doub_I first, Doub_I last, Long N)
{
    Doub delta = (last - first) / (N - 1);
    for (Long i = 0; i < N; ++i)
        v[i] = first + delta * i;
}


inline void linspace(CmatDoub_O v, Doub_I first, Doub_I last)
{ linspace_vss(v.p(), first, last, v.size()); }


inline void flip_v(Doub *v, Long_I N)
{
    for (Long i = 0; i < N / 2; ++i)
        swap(v[i], v[N - i - 1]);
}


inline void flip_vv(Doub *v, const Doub *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[N - i - 1];
}


inline void flip(vecDoub_IO v)
{
    flip_v(&v[0], v.size());
}


inline void flip(VecDoub_O v, VecDoub_I v1)
{
    assert_same_shape(v, v1);
    flip_vv(v.p(), v1.p(), v1.size());
}


inline void reorder(SvecComp_O v, VecLlong_I order)
{
#ifdef SLS_CHECK_SHAPES
    if ((Long)order.size() != (Long)v.size())
        SLS_ERR("wrong shape!");
#endif
    Long N = v.size();
    static VecComp u; u.resize(N);
    if (N > (Long)u.size())
        u.resize(max(N, Long(2*u.size())));
    for (Long i = 0; i < N; ++i)
        u[i] = v[order[i]];
    for (Long i = 0; i < N; ++i)
        v[i] = u[i];
}

inline void reorder(vecStr32_O v, vecLlong_I order)
{
#ifdef SLS_CHECK_SHAPES
    if ((Long)order.size() != (Long)v.size())
        SLS_ERR("wrong shape!");
#endif
    Long N = v.size();
    static vecStr32 u; u.resize(N);
    if (N > (Long)u.size())
        u.resize(max(N, Long(2*u.size())));
    for (Long i = 0; i < N; ++i)
        u[i] = v[order[i]];
    for (Long i = 0; i < N; ++i)
        v[i] = u[i];
}


inline void trans(DcmatDoub_IO v)
{
#ifdef SLS_CHECK_SHAPES
    if (v.n0() != v.n1())
        SLS_ERR("illegal shape!");
#endif
    for (Long i = 0; i < v.n0(); ++i)
        for (Long j = 0; j < i; ++j)
            swap(v(i, j), v(j, i));
}


inline void trans(CmatDoub_O v, CmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    if (v.n0() != v1.n1() || v.n1() != v1.n0())
        SLS_ERR("wrong shape!");
#endif
    for (Long i = 0; i < v.n0(); ++i)
        for (Long j = 0; j < v.n1(); ++j)
            v(i, j) = v1(j, i);
}


inline void conj_v(Comp *v, Long_I N)
{
    Doub *p = (Doub *)v;
    for (Long i = 1; i < 2*N; i += 2)
        p[i] = -p[i];
}


inline void conj_vv(Comp *v, const Comp *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = conj(v1[i]);
}


inline void conj(CmatComp_IO v)
{
    conj_v(v.p(), v.size());
}


inline void conj(CmatComp_O v, CmatComp_I v1)
{
    assert_same_shape(v, v1);
    conj_vv(v.p(), v1.p(), v.size());
}


inline void her(CmatComp_IO v)
{
#ifdef SLS_CHECK_SHAPES
    if (v.n0() != v.n1()) SLS_ERR("illegal shape!");
#endif
    trans(v); conj(v);
}


inline void her(DcmatComp_O v, DcmatComp_I v1)
{ trans(v, v1); conj(v); }


inline void plus_equals_vs(Comp *v, Doub_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] += s;
}

inline void plus_equals_vs(Comp *v, Doub_I s, Long_I N, Long step)
{
    for (Long i = 0; i < N*step; i += step)
        v[i] += s;
}

inline void minus_equals_vs(Comp *v, Doub_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] -= s;
}

inline void minus_equals_vs(Comp *v, Doub_I s, Long_I N, Long step)
{
    for (Long i = 0; i < N*step; i += step)
        v[i] -= s;
}

inline void times_equals_vs(Comp *v, Doub_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] *= s;
}

inline void times_equals_vs(Comp *v, Doub_I s, Long_I N, Long step)
{
    for (Long i = 0; i < N*step; i += step)
        v[i] *= s;
}
inline void divide_equals_vs(Comp *v, Doub_I s, Long_I N)
{
    times_equals_vs(v, (Doub)1/s, N);
}

inline void divide_equals_vs(Comp *v, Doub_I s, Long_I N, Long_I step)
{
    times_equals_vs(v, (Doub)1/s, N, step);
}


inline void operator+=(VecDoub_IO v, Doub_I s)
{ plus_equals_vs(v.p(), s, v.size()); }

inline void operator-=(VecDoub_IO v, Doub_I s)
{ minus_equals_vs(v.p(), s, v.size()); }

inline void operator*=(VecDoub_IO v, Doub_I s)
{ times_equals_vs(v.p(), s, v.size()); }

inline void operator/=(VecDoub_IO v, Doub_I s)
{ divide_equals_vs(v.p(), s, v.size()); }

inline void operator+=(DcmatComp_IO v, Doub_I s)
{
    for (Long j = 0; j < v.n1(); ++j)
        plus_equals_vs(&v(0,j), s, v.n0());
}

inline void operator-=(DcmatComp_IO v, Doub_I s)
{
    for (Long j = 0; j < v.n1(); ++j)
        minus_equals_vs(&v(0,j), s, v.n0());
}

inline void operator*=(DcmatComp_IO v, Doub_I s)
{
    for (Long j = 0; j < v.n1(); ++j)
        times_equals_vs(&v(0,j), s, v.n0());
}

inline void operator/=(DcmatComp_IO v, Doub_I s)
{
    for (Long j = 0; j < v.n1(); ++j)
        divide_equals_vs(&v(0,j), s, v.n0());
}


inline void plus_equals_vv(Comp *v, const Doub *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] += v1[i];
}

inline void minus_equals_vv(Comp *v, const Doub *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] -= v1[i];
}

inline void times_equals_vv(Comp *v, const Doub *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] *= v1[i];
}

inline void divide_equals_vv(Comp *v, const Doub *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] /= v1[i];
}


inline void operator+=(DvecComp_O &v, SvecDoub_I v1)
{
    assert_same_shape(v, v1);
    for (Long i = 0; i < v.size(); ++i)
        v[i] += v1[i];
}

inline void operator-=(DvecComp_O &v, SvecDoub_I v1)
{
    assert_same_shape(v, v1);
    for (Long i = 0; i < v.size(); ++i)
        v[i] -= v1[i];
}

inline void operator*=(DvecComp_O &v, SvecDoub_I v1)
{
    assert_same_shape(v, v1);
    for (Long i = 0; i < v.size(); ++i)
        v[i] *= v1[i];
}

inline void operator/=(DvecComp_O &v, SvecDoub_I v1)
{
    assert_same_shape(v, v1);
    for (Long i = 0; i < v.size(); ++i)
        v[i] /= v1[i];
}


inline void plus_vvs(Comp *v, const Doub *v1, Imag_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] + s;
}

inline void plus_vvs(Comp *v, const Doub *v1, Imag_I s, Long_I N, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 + s;
        v += step1; v1 += step2;
    }
}

inline void minus_vvs(Comp *v, const Doub *v1, Imag_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] - s;
}

inline void minus_vvs(Comp *v, const Doub *v1, Imag_I s, Long_I N, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 - s;
        v += step1; v1 += step2;
    }
}

inline void times_vvs(Comp *v, const Doub *v1, Imag_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] * s;
}

inline void times_vvs(Comp *v, const Doub *v1, Imag_I s, Long_I N, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 * s;
        v += step1; v1 += step2;
    }
}

inline void divide_vvs(Comp *v, const Doub *v1, Imag_I s, Long_I N)
{
    Imag inv_s = 1./s;
    times_vvs(v, v1, inv_s, N);
}

inline void divide_vvs(Comp *v, const Doub *v1, Imag_I s, Long_I N, Long_I step, Long_I step1)
{
    Imag inv_s = 1./s;
    times_vvs(v, v1, inv_s, N, step, step1);
}

inline void plus_vvs(Comp *v, const Comp *v1, Doub_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] + s;
}

inline void plus_vvs(Comp *v, const Comp *v1, Doub_I s, Long_I N, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 + s;
        v += step1; v1 += step2;
    }
}

inline void minus_vvs(Comp *v, const Comp *v1, Doub_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] - s;
}

inline void minus_vvs(Comp *v, const Comp *v1, Doub_I s, Long_I N, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 - s;
        v += step1; v1 += step2;
    }
}

inline void times_vvs(Comp *v, const Comp *v1, Doub_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] * s;
}

inline void times_vvs(Comp *v, const Comp *v1, Doub_I s, Long_I N, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 * s;
        v += step1; v1 += step2;
    }
}

inline void divide_vvs(Comp *v, const Comp *v1, Doub_I s, Long_I N)
{
    Doub inv_s = 1./s;
    times_vvs(v, v1, inv_s, N);
}

inline void divide_vvs(Comp *v, const Comp *v1, Doub_I s, Long_I N, Long_I step, Long_I step1)
{
    Doub inv_s = 1./s;
    times_vvs(v, v1, inv_s, N, step, step1);
}

inline void plus_vvs(Comp *v, const Doub *v1, Comp_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] + s;
}

inline void plus_vvs(Comp *v, const Doub *v1, Comp_I s, Long_I N, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 + s;
        v += step1; v1 += step2;
    }
}

inline void minus_vvs(Comp *v, const Doub *v1, Comp_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] - s;
}

inline void minus_vvs(Comp *v, const Doub *v1, Comp_I s, Long_I N, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 - s;
        v += step1; v1 += step2;
    }
}

inline void times_vvs(Comp *v, const Doub *v1, Comp_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] * s;
}

inline void times_vvs(Comp *v, const Doub *v1, Comp_I s, Long_I N, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 * s;
        v += step1; v1 += step2;
    }
}

inline void divide_vvs(Comp *v, const Doub *v1, Comp_I s, Long_I N)
{
    Comp inv_s = 1./s;
    times_vvs(v, v1, inv_s, N);
}

inline void divide_vvs(Comp *v, const Doub *v1, Comp_I s, Long_I N, Long_I step, Long_I step1)
{
    Comp inv_s = 1./s;
    times_vvs(v, v1, inv_s, N, step, step1);
}

inline void plus_vvs(Doub *v, const Doub *v1, Doub_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] + s;
}

inline void plus_vvs(Doub *v, const Doub *v1, Doub_I s, Long_I N, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 + s;
        v += step1; v1 += step2;
    }
}

inline void minus_vvs(Doub *v, const Doub *v1, Doub_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] - s;
}

inline void minus_vvs(Doub *v, const Doub *v1, Doub_I s, Long_I N, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 - s;
        v += step1; v1 += step2;
    }
}

inline void times_vvs(Doub *v, const Doub *v1, Doub_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] * s;
}

inline void times_vvs(Doub *v, const Doub *v1, Doub_I s, Long_I N, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 * s;
        v += step1; v1 += step2;
    }
}

inline void divide_vvs(Doub *v, const Doub *v1, Doub_I s, Long_I N)
{
    Doub inv_s = 1./s;
    times_vvs(v, v1, inv_s, N);
}

inline void divide_vvs(Doub *v, const Doub *v1, Doub_I s, Long_I N, Long_I step, Long_I step1)
{
    Doub inv_s = 1./s;
    times_vvs(v, v1, inv_s, N, step, step1);
}

inline void plus_vvs(Comp *v, const Comp *v1, Comp_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] + s;
}

inline void plus_vvs(Comp *v, const Comp *v1, Comp_I s, Long_I N, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 + s;
        v += step1; v1 += step2;
    }
}

inline void minus_vvs(Comp *v, const Comp *v1, Comp_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] - s;
}

inline void minus_vvs(Comp *v, const Comp *v1, Comp_I s, Long_I N, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 - s;
        v += step1; v1 += step2;
    }
}

inline void times_vvs(Comp *v, const Comp *v1, Comp_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] * s;
}

inline void times_vvs(Comp *v, const Comp *v1, Comp_I s, Long_I N, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 * s;
        v += step1; v1 += step2;
    }
}

inline void divide_vvs(Comp *v, const Comp *v1, Comp_I s, Long_I N)
{
    Comp inv_s = 1./s;
    times_vvs(v, v1, inv_s, N);
}

inline void divide_vvs(Comp *v, const Comp *v1, Comp_I s, Long_I N, Long_I step, Long_I step1)
{
    Comp inv_s = 1./s;
    times_vvs(v, v1, inv_s, N, step, step1);
}


inline void minus_vsv(Comp *v, const Doub &s, const Comp *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = s - v1[i];
}

inline void minus_vsv(Comp *v, const Doub &s, const Comp *v1, Long_I N, Long_I step, Long_I step1)
{
    for (Long i = 0; i < N; ++i) {
        *v = s - *v1;
        v += step; v1 += step1;
    }
}

inline void divide_vsv(Comp *v, const Doub &s, const Comp *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = s / v1[i];
}

inline void divide_vsv(Comp *v, const Doub &s, const Comp *v1, Long_I N, Long_I step, Long_I step1)
{
    for (Long i = 0; i < N; ++i) {
        *v = s / *v1;
        v += step; v1 += step1;
    }
}

inline void minus_vsv(Comp *v, const Comp &s, const Doub *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = s - v1[i];
}

inline void minus_vsv(Comp *v, const Comp &s, const Doub *v1, Long_I N, Long_I step, Long_I step1)
{
    for (Long i = 0; i < N; ++i) {
        *v = s - *v1;
        v += step; v1 += step1;
    }
}

inline void divide_vsv(Comp *v, const Comp &s, const Doub *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = s / v1[i];
}

inline void divide_vsv(Comp *v, const Comp &s, const Doub *v1, Long_I N, Long_I step, Long_I step1)
{
    for (Long i = 0; i < N; ++i) {
        *v = s / *v1;
        v += step; v1 += step1;
    }
}

inline void minus_vsv(Comp *v, const Doub &s, const Imag *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = s - v1[i];
}

inline void minus_vsv(Comp *v, const Doub &s, const Imag *v1, Long_I N, Long_I step, Long_I step1)
{
    for (Long i = 0; i < N; ++i) {
        *v = s - *v1;
        v += step; v1 += step1;
    }
}

inline void divide_vsv(Comp *v, const Doub &s, const Imag *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = s / v1[i];
}

inline void divide_vsv(Comp *v, const Doub &s, const Imag *v1, Long_I N, Long_I step, Long_I step1)
{
    for (Long i = 0; i < N; ++i) {
        *v = s / *v1;
        v += step; v1 += step1;
    }
}


inline void plus_vvv(Comp *v, const Doub *v1, const Comp *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] + v2[i];
}

inline void plus_vvv(Comp *v, const Doub *v1, const Comp *v2, Long_I N, Long_I step, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 + *v2;
        v += step; v1 += step1; v2 += step2;
    }
}

inline void minus_vvv(Comp *v, const Doub *v1, const Comp *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] - v2[i];
}

inline void minus_vvv(Comp *v, const Doub *v1, const Comp *v2, Long_I N, Long_I step, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 - *v2;
        v += step; v1 += step1; v2 += step2;
    }
}

inline void times_vvv(Comp *v, const Doub *v1, const Comp *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] * v2[i];
}

inline void times_vvv(Comp *v, const Doub *v1, const Comp *v2, Long_I N, Long_I step, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 * *v2;
        v += step; v1 += step1; v2 += step2;
    }
}

inline void divide_vvv(Comp *v, const Doub *v1, const Comp *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] / v2[i];
}

inline void divide_vvv(Comp *v, const Doub *v1, const Comp *v2, Long_I N, Long_I step, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 / *v2;
        v += step; v1 += step1; v2 += step2;
    }
}

inline void plus_vvv(Comp *v, const Comp *v1, const Comp *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] + v2[i];
}

inline void plus_vvv(Comp *v, const Comp *v1, const Comp *v2, Long_I N, Long_I step, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 + *v2;
        v += step; v1 += step1; v2 += step2;
    }
}

inline void minus_vvv(Comp *v, const Comp *v1, const Comp *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] - v2[i];
}

inline void minus_vvv(Comp *v, const Comp *v1, const Comp *v2, Long_I N, Long_I step, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 - *v2;
        v += step; v1 += step1; v2 += step2;
    }
}

inline void times_vvv(Comp *v, const Comp *v1, const Comp *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] * v2[i];
}

inline void times_vvv(Comp *v, const Comp *v1, const Comp *v2, Long_I N, Long_I step, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 * *v2;
        v += step; v1 += step1; v2 += step2;
    }
}

inline void divide_vvv(Comp *v, const Comp *v1, const Comp *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] / v2[i];
}

inline void divide_vvv(Comp *v, const Comp *v1, const Comp *v2, Long_I N, Long_I step, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 / *v2;
        v += step; v1 += step1; v2 += step2;
    }
}

inline void plus_vvv(Comp *v, const Comp *v1, const Doub *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] + v2[i];
}

inline void plus_vvv(Comp *v, const Comp *v1, const Doub *v2, Long_I N, Long_I step, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 + *v2;
        v += step; v1 += step1; v2 += step2;
    }
}

inline void minus_vvv(Comp *v, const Comp *v1, const Doub *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] - v2[i];
}

inline void minus_vvv(Comp *v, const Comp *v1, const Doub *v2, Long_I N, Long_I step, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 - *v2;
        v += step; v1 += step1; v2 += step2;
    }
}

inline void times_vvv(Comp *v, const Comp *v1, const Doub *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] * v2[i];
}

inline void times_vvv(Comp *v, const Comp *v1, const Doub *v2, Long_I N, Long_I step, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 * *v2;
        v += step; v1 += step1; v2 += step2;
    }
}

inline void divide_vvv(Comp *v, const Comp *v1, const Doub *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] / v2[i];
}

inline void divide_vvv(Comp *v, const Comp *v1, const Doub *v2, Long_I N, Long_I step, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 / *v2;
        v += step; v1 += step1; v2 += step2;
    }
}

inline void plus_vvv(Doub *v, const Doub *v1, const Doub *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] + v2[i];
}

inline void plus_vvv(Doub *v, const Doub *v1, const Doub *v2, Long_I N, Long_I step, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 + *v2;
        v += step; v1 += step1; v2 += step2;
    }
}

inline void minus_vvv(Doub *v, const Doub *v1, const Doub *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] - v2[i];
}

inline void minus_vvv(Doub *v, const Doub *v1, const Doub *v2, Long_I N, Long_I step, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 - *v2;
        v += step; v1 += step1; v2 += step2;
    }
}

inline void times_vvv(Doub *v, const Doub *v1, const Doub *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] * v2[i];
}

inline void times_vvv(Doub *v, const Doub *v1, const Doub *v2, Long_I N, Long_I step, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 * *v2;
        v += step; v1 += step1; v2 += step2;
    }
}

inline void divide_vvv(Doub *v, const Doub *v1, const Doub *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] / v2[i];
}

inline void divide_vvv(Doub *v, const Doub *v1, const Doub *v2, Long_I N, Long_I step, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 / *v2;
        v += step; v1 += step1; v2 += step2;
    }
}


inline void plus(VecComp_O v, VecComp_I v1, Doub_I s)
{
    assert_same_shape(v, v1);
    plus_vvs(v.p(), v1.p(), s, v1.size());
}

inline void plus(VecComp_O v, Doub_I s, VecComp_I v1)
{ plus(v, v1, s); }

inline void minus(VecComp_O v, VecComp_I v1, Doub_I s)
{
    assert_same_shape(v, v1);
    minus_vvs(v.p(), v1.p(), s, v1.size());
}

inline void minus(VecComp_O v, Doub_I s, VecComp_I v1)
{
    assert_same_shape(v, v1);
    minus_vsv(v.p(), s, v1.p(), v1.size());
}

inline void times(VecComp_O v, VecComp_I v1, Doub_I s)
{
    assert_same_shape(v, v1);
    times_vvs(v.p(), v1.p(), s, v1.size());
}

inline void times(VecComp_O v, Doub_I s, VecComp_I v1)
{ times(v, v1, s); }

inline void divide(VecComp_O v, VecComp_I v1, Doub_I s)
{
    assert_same_shape(v, v1);
    divide_vvs(v.p(), v1.p(), s, v1.size());
}

inline void divide(VecComp_O v, Doub_I s, VecComp_I v1)
{
    assert_same_shape(v, v1);
    divide_vsv(v.p(), s, v1.p(), v1.size());
}

inline void plus(Cmat3Comp_O v, Cmat3Doub_I v1, Imag_I s)
{
    assert_same_shape(v, v1);
    plus_vvs(v.p(), v1.p(), s, v1.size());
}

inline void plus(Cmat3Comp_O v, Imag_I s, Cmat3Doub_I v1)
{ plus(v, v1, s); }

inline void minus(Cmat3Comp_O v, Cmat3Doub_I v1, Imag_I s)
{
    assert_same_shape(v, v1);
    minus_vvs(v.p(), v1.p(), s, v1.size());
}

inline void minus(Cmat3Comp_O v, Imag_I s, Cmat3Doub_I v1)
{
    assert_same_shape(v, v1);
    minus_vsv(v.p(), s, v1.p(), v1.size());
}

inline void times(Cmat3Comp_O v, Cmat3Doub_I v1, Imag_I s)
{
    assert_same_shape(v, v1);
    times_vvs(v.p(), v1.p(), s, v1.size());
}

inline void times(Cmat3Comp_O v, Imag_I s, Cmat3Doub_I v1)
{ times(v, v1, s); }

inline void divide(Cmat3Comp_O v, Cmat3Doub_I v1, Imag_I s)
{
    assert_same_shape(v, v1);
    divide_vvs(v.p(), v1.p(), s, v1.size());
}

inline void divide(Cmat3Comp_O v, Imag_I s, Cmat3Doub_I v1)
{
    assert_same_shape(v, v1);
    divide_vsv(v.p(), s, v1.p(), v1.size());
}


inline void plus(DvecComp_O v, SvecComp_I v1, DvecComp_I v2)
{
    assert_same_shape(v, v1, v2);
    plus_vvv(v.p(), v1.p(), v2.p(), v.size(), v.step(), 1, v2.step());
}

inline void minus(DvecComp_O v, SvecComp_I v1, DvecComp_I v2)
{
    assert_same_shape(v, v1, v2);
    minus_vvv(v.p(), v1.p(), v2.p(), v.size(), v.step(), 1, v2.step());
}

inline void times(DvecComp_O v, SvecComp_I v1, DvecComp_I v2)
{
    assert_same_shape(v, v1, v2);
    minus_vvv(v.p(), v1.p(), v2.p(), v.size(), v.step(), 1, v2.step());
}

inline void divide(DvecComp_O v, SvecComp_I v1, DvecComp_I v2)
{
    assert_same_shape(v, v1, v2);
    divide_vvv(v.p(), v1.p(), v2.p(), v.size(), v.step(), 1, v2.step());
}


inline void minus_vv(Comp *v, const Doub *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = -v1[i];
}


inline void minus(VecLlong_O v, VecLlong_I v1)
{
    assert_same_shape(v, v1);
    minus_vv(v.p(), v1.p(), v1.size());
}

inline void minus(VecDoub_O v, VecDoub_I v1)
{
    assert_same_shape(v, v1);
    minus_vv(v.p(), v1.p(), v1.size());
}

inline void minus(VecComp_O v, VecDoub_I v1)
{
    assert_same_shape(v, v1);
    minus_vv(v.p(), v1.p(), v1.size());
}

inline void minus(VecComp_O v, VecComp_I v1)
{
    assert_same_shape(v, v1);
    minus_vv(v.p(), v1.p(), v1.size());
}

inline void minus(ScmatDoub_O v, CmatDoub_I v1)
{
    assert_same_shape(v, v1);
    minus_vv(v.p(), v1.p(), v1.size());
}


inline void pow_vs(Doub *v, Llong_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = pow(v[i], s);
}

inline void pow_vs(Comp *v, Int_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = pow(v[i], s);
}


inline void pow(VecComp_IO v, Int_I s)
{ pow_vs(v.p(), s, v.size()); }


inline void pow_vvs(Doub *v, const Doub *v1, Int_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = pow(v1[i], s);
}


inline void pow(VecDoub_O v, VecDoub_I v1, Int_I s)
{
    assert_same_shape(v, v1);
    pow_vvs(v.p(), v1.p(), s, v1.size());
}


inline Comp dot_vv(const Doub *v1, const Comp *v2, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Comp s = v1[0] * v2[0];
    for (Long i = 1; i < N; ++i) {
        s += v1[i] * v2[i];
    }
    return s;
}


inline Comp dot(Cmat3Comp_I v1, Cmat3Doub_I v2)
{
    assert_same_shape(v1, v2);
    return dot_vv(v1.p(), v2.p(), v2.size());
}


inline void cumsum_vv(Doub *v, const Doub *v1, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    v[0] = v1[0];
    for (Long i = 1; i < N; ++i)
        v[i] = v[i - 1] + v1[i];
}


inline void cumsum(VecDoub_O v, VecDoub_I v1)
{
    assert_same_shape(v, v1);
    cumsum_vv(v.p(), v1.p(), v1.size());
}



inline void mul(DvecComp_O y, ScmatDoub_I a, DvecComp_I x)
{
    Long Nr = a.n0(), Nc = a.n1();
#ifdef SLS_CHECK_SHAPES
    if (Nc != x.size() || y.size() != Nr)
        SLS_ERR("illegal shape!");
#endif
    for (Long i = 0; i < Nr; ++i)
        y[i] = a(i, 0) * x[0];
    for (Long j = 1; j < Nc; ++j) {
        for (Long i = 0; i < Nr; ++i)
            y[i] += a(i, j) * x[j];
    }
}

// y = alpha*A*x + beta*y
// algorithm: y = alpha*(A*x + beta/alpha *y)
inline void mul(DvecComp_IO y, ScmatDoub_I a, DvecComp_I x, Doub_I alpha, Comp_I beta)
{
    Long Nr = a.n0(), Nc = a.n1();
#ifdef SLS_CHECK_SHAPES
    if (Nc != x.size() || y.size() != Nr)
        SLS_ERR("illegal shape!");
#endif
    
    // y = beta/alpha *y
    if (beta == 0) {
        for (Long i = 0; i < Nr; ++i)
            y[i] = 0;
    }
    else {
        Comp b_a = beta/alpha;
        if (b_a != 1) {
            for (Long i = 0; i < Nr; ++i)
                y[i] *= b_a;
        }
    }
    
    // y += A*x
    for (Long j = 0; j < Nc; ++j) {
        for (Long i = 0; i < Nr; ++i)
            y[i] += a(i, j) * x[j];
    }

    // y *= alpha
    if (alpha != 1) {
        for (Long i = 0; i < Nr; ++i)
            y[i] *= alpha;
    }
}


inline void mul(VecComp_O &y, VecDoub_I x, MatComp_I a)
{
    Long Nr_a = a.n0(), Nc_a = a.n1();
#ifdef SLS_CHECK_SHAPES
    if (x.size() != a.n0() || y.size() != Nc_a)
        SLS_ERR("illegal shape!");
#endif
    vecset(y.p(), 0, Nc_a);
    for (Long j = 0; j < Nc_a; ++j) {
        for (Long i = 0; i < Nr_a; ++i)
            y[j] += x[i] * a(i, j);
    }
}


inline void mul(CmatComp_O y, CmatComp_I a, CmatDoub_I x)
{
    Long Nr_a = a.n0(), Nc_a = a.n1(), Nc_x = x.n1();
#ifdef SLS_CHECK_SHAPES
    if (a.n1() != x.n0() || y.n0() != Nr_a || y.n1() != Nc_x)
        SLS_ERR("illegal shape!");
#endif
    vecset(y.p(), 0, Nr_a*Nc_x);
    for (Long i = 0; i < Nr_a; ++i) {
        for (Long j = 0; j < Nc_x; ++j) {
            for (Long k = 0; k < Nc_a; ++k)
                y(i, j) += a(i, k) * x(k, j);
        }
    }
}


// matrix-vector multiplication
// y = alpha*A*x + beta*y
inline void mul_gen(VecDoub_O &y, CmatDoub_I a, SvecDoub_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPES
    if (x.size() != a.n1() || y.size() != a.n0())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    cblas_dgemv(CblasColMajor, CblasNoTrans, a.n0(), a.n1(), alpha, a.p(),
        a.n0(), x.p(), 1, beta, y.p(), 1);
#else
    mul(y, a, x, alpha, beta);
#endif
}


// y = alpha*A*x + beta*y
inline void mul_sym(VecComp_IO &y, CmatDoub_I a, VecComp_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPES
    if (x.size() != a.n1() || y.size() != a.n0() || x.size() != y.size())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    // do real part
    cblas_dsymv(CblasColMajor, CblasUpper, a.n0(), alpha, a.p(),
        a.n0(), (Doub*)x.p(), 2*1, beta, (Doub*)y.p(), 2*1);
    // do imag part
    cblas_dsymv(CblasColMajor, CblasUpper, a.n0(), alpha, a.p(),
        a.n0(), (Doub*)x.p()+1, 2*1, beta, (Doub*)y.p()+1, 2*1);
#else
    mul(y, a, x, alpha, beta);
#endif
}


inline void mul_gen(ScmatComp_O y, ScmatDoub_I a, CmatComp_I &x)
{
#ifdef SLS_CHECK_SHAPES
    if (a.n1() != x.n0() || y.n0() != a.n0() || y.n1() != x.n1())
        SLS_ERR("illegal shape!");
#endif
#ifdef SLS_USE_CBLAS
        SLS_WARN("not implemented with cBLAS, using slow version");
        mul(y, a, x);
#else
    mul(y, a, x);
#endif
}


// concatinate std::vector
inline void cat(vecInt_IO v, vecInt_I v1)
{ v.insert(v.end(), v1.begin(), v1.end()); }

inline void cat(vecLong_IO v, vecLong_I v1)
{ v.insert(v.end(), v1.begin(), v1.end()); }

inline void cat(vecStr_IO v, vecStr_I v1)
{ v.insert(v.end(), v1.begin(), v1.end()); }

inline void cat(vecStr32_IO v, vecStr32_I v1)
{ v.insert(v.end(), v1.begin(), v1.end()); }


// get unique elements from a vector
inline void uniq_elm(vecInt_IO v)
{
    Long N = v.size(), n = 0; // already done
    for (Long i = 0; i < N; ++i) {
        Bool repeat = false;
        for (Long j = 0; j < n; ++j) {
            if (v[i] == v[j]) {
                repeat = true; break;
            }
        }
        if (!repeat) {
            v[n] = v[i];
            ++n;
        }
    }
    v.resize(n);
}


// get all unique rows from a matrix
inline void uniq_rows(CmatDoub_O a, CmatDoub_I a1)
{
    Long k = 0;
    a.resize(a1.n0(), a1.n1());
    for (Long i = 0; i < a1.n0(); ++i) {
        // check repeat
        Bool repeat = false;
        DvecDoub_c sli1 = cut1(a1, i);
        for (Long j = 0; j < k; ++j) {
            if (cut1(a, j) == sli1) {
                repeat = true; break;
            }
        }
        if (repeat)
            continue;
        copy(cut1(a, k), sli1);
        ++k;
    }
    resize_cpy(a, k, a1.n1());
}


} // namespace slisc
