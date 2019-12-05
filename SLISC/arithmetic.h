#pragma once
#include "copy.h"
#include "scalar_arith.h"
#include "slice_arith.h"

namespace slisc {

inline Long Size(vecStr_I v)
{
	return v.size();
}

inline Long Size(VecInt_I v)
{
	return v.size();
}

inline Long Size(VecLlong_I v)
{
	return v.size();
}

inline Long Size(VecDoub_I v)
{
	return v.size();
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


inline const Int max(VecInt_I v)
{
    return max_v(v.ptr(), v.size());
}

inline const Llong max(VecLlong_I v)
{
    return max_v(v.ptr(), v.size());
}

inline const Doub max(VecDoub_I v)
{
    return max_v(v.ptr(), v.size());
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

inline Llong max_abs_v(const Llong *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Llong s = abs(v[0]), val;
    for (Long i = 1; i < N; ++i) {
        val = abs(v[i]);
        if (s < val)
            s = val;
    }
    return s;
}

inline Llong max_abs_v(const Llong *v, Long_I N, Long_I step)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Llong s = abs(v[0]), val;
    for (Long i = step; i < N*step; i += step) {
        val = abs(v[i]);
        if (s < val)
            s = val;
    }
    return s;
}

inline Float max_abs_v(const Float *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Float s = abs(v[0]), val;
    for (Long i = 1; i < N; ++i) {
        val = abs(v[i]);
        if (s < val)
            s = val;
    }
    return s;
}

inline Float max_abs_v(const Float *v, Long_I N, Long_I step)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Float s = abs(v[0]), val;
    for (Long i = step; i < N*step; i += step) {
        val = abs(v[i]);
        if (s < val)
            s = val;
    }
    return s;
}

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


inline Int max_abs(VecInt_I v)
{
    return max_abs_v(v.ptr(), v.size());
}

inline Llong max_abs(VecLlong_I v)
{
    return max_abs_v(v.ptr(), v.size());
}

inline Float max_abs(VecFloat_I v)
{
    return max_abs_v(v.ptr(), v.size());
}

inline Doub max_abs(VecDoub_I v)
{
    return max_abs_v(v.ptr(), v.size());
}

inline Doub max_abs(VecComp_I v)
{
    return max_abs_v(v.ptr(), v.size());
}

inline Int max_abs(CmatInt_I v)
{
    return max_abs_v(v.ptr(), v.size());
}

inline Llong max_abs(CmatLlong_I v)
{
    return max_abs_v(v.ptr(), v.size());
}

inline Float max_abs(CmatFloat_I v)
{
    return max_abs_v(v.ptr(), v.size());
}

inline Doub max_abs(CmatDoub_I v)
{
    return max_abs_v(v.ptr(), v.size());
}

inline Doub max_abs(CmatComp_I v)
{
    return max_abs_v(v.ptr(), v.size());
}

inline Int max_abs(MatInt_I v)
{
    return max_abs_v(v.ptr(), v.size());
}

inline Llong max_abs(MatLlong_I v)
{
    return max_abs_v(v.ptr(), v.size());
}

inline Float max_abs(MatFloat_I v)
{
    return max_abs_v(v.ptr(), v.size());
}

inline Doub max_abs(MatDoub_I v)
{
    return max_abs_v(v.ptr(), v.size());
}

inline Doub max_abs(MatComp_I v)
{
    return max_abs_v(v.ptr(), v.size());
}


inline void mod_vvs(Char *v, const Char *v1, Char_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = mod(v1[i], s);
}

inline void mod_vs(Char *v, Char_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = mod(v[i], s);
}

inline void mod_vvs(Int *v, const Int *v1, Int_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = mod(v1[i], s);
}

inline void mod_vs(Int *v, Int_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = mod(v[i], s);
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


inline void mod(VecInt_O v, VecInt_I v1, Int_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    mod_vvs(v.ptr(), v1.ptr(), s, v.size());
}

inline void mod(VecInt_O v, Int_I s)
{
    mod_vs(v.ptr(), s, v.size());
}

inline void mod(VecLlong_O v, VecLlong_I v1, Llong_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    mod_vvs(v.ptr(), v1.ptr(), s, v.size());
}

inline void mod(VecLlong_O v, Llong_I s)
{
    mod_vs(v.ptr(), s, v.size());
}


inline Doub norm2(VecDoub_I v)
{
    Long N = v.size();
    Doub s2 = abs2(v[0]);
    for (Long i = 1; i < N; ++i)
        s2 += abs2(v[i]);
    return s2;
}
inline Doub norm(VecDoub_I v)
{
    return sqrt(norm2(v));
}

inline Doub norm2(VecComp_I v)
{
    Long N = v.size();
    Doub s2 = abs2(v[0]);
    for (Long i = 1; i < N; ++i)
        s2 += abs2(v[i]);
    return s2;
}
inline Doub norm(VecComp_I v)
{
    return sqrt(norm2(v));
}

inline Doub norm2(MatDoub_I v)
{
    Long N = v.size();
    Doub s2 = abs2(v[0]);
    for (Long i = 1; i < N; ++i)
        s2 += abs2(v[i]);
    return s2;
}
inline Doub norm(MatDoub_I v)
{
    return sqrt(norm2(v));
}

inline Doub norm2(MatComp_I v)
{
    Long N = v.size();
    Doub s2 = abs2(v[0]);
    for (Long i = 1; i < N; ++i)
        s2 += abs2(v[i]);
    return s2;
}
inline Doub norm(MatComp_I v)
{
    return sqrt(norm2(v));
}

inline Doub norm2(CmatDoub_I v)
{
    Long N = v.size();
    Doub s2 = abs2(v[0]);
    for (Long i = 1; i < N; ++i)
        s2 += abs2(v[i]);
    return s2;
}
inline Doub norm(CmatDoub_I v)
{
    return sqrt(norm2(v));
}

inline Doub norm2(ScmatDoub_I v)
{
    Long N = v.size();
    Doub s2 = abs2(v[0]);
    for (Long i = 1; i < N; ++i)
        s2 += abs2(v[i]);
    return s2;
}
inline Doub norm(ScmatDoub_I v)
{
    return sqrt(norm2(v));
}

inline Doub norm2(Cmat3Doub_I v)
{
    Long N = v.size();
    Doub s2 = abs2(v[0]);
    for (Long i = 1; i < N; ++i)
        s2 += abs2(v[i]);
    return s2;
}
inline Doub norm(Cmat3Doub_I v)
{
    return sqrt(norm2(v));
}

inline Doub norm2(Cmat3Comp_I v)
{
    Long N = v.size();
    Doub s2 = abs2(v[0]);
    for (Long i = 1; i < N; ++i)
        s2 += abs2(v[i]);
    return s2;
}
inline Doub norm(Cmat3Comp_I v)
{
    return sqrt(norm2(v));
}


inline void resize_cpy(VecDoub_IO v, Long_I N)
{
    Long N0 = v.size();
    if (N != N0) {
        if (N0 == 0) {
            v.resize(N); copy(v, 0);
        }
        else if (N == 0)
            v.resize(0);
        else {
            VecDoub v_new(N);
            if (N > N0) {
                veccpy(v_new.ptr(), v.ptr(), N0);
                vecset(v_new.ptr() + N0, 0, N - N0);
            }
            else // N < N0
                veccpy(v_new.ptr(), v.ptr(), N);
            v << v_new;
        }
    }
}

inline void resize_cpy(CmatDoub_IO v, Long_I N1, Long_I N2)
{
    Long N10 = v.n1(), N20 = v.n2(), N0 = N1*N2;
    Long N = N1 * N2;
    if (N1 != N10 || N2 != N20) {
        if (N0 == 0) {
            v.resize(N1, N2); copy(v, 0);
        }
        else if (N == 0)
            v.resize(0, 0);
        else {
            CmatDoub v_new(N1, N2); copy(v_new, 0);
            Long N1min = min(N1, N10), N2min = min(N2, N20);
            DcmatDoub sli; slice(sli, v, 0, N1min, 0, N2min);
            copy(sli, v);
        }
    }
}


inline void linspace_vss(Int *v, Int_I first, Int_I last, Long N)
{
    Int delta = (last - first), Nm1 = N-1;
    for (Long i = 0; i < N; ++i)
        v[i] = first + delta * i / Nm1;
}

inline void linspace_vss(Llong *v, Llong_I first, Llong_I last, Long N)
{
    Llong delta = (last - first), Nm1 = N-1;
    for (Long i = 0; i < N; ++i)
        v[i] = first + delta * i / Nm1;
}

inline void linspace_vss(Doub *v, Doub_I first, Doub_I last, Long N)
{
    Doub delta = (last - first) / (N - 1);
    for (Long i = 0; i < N; ++i)
        v[i] = first + delta * i;
}


inline void linspace(VecInt_O v, Int_I first, Int_I last)
{
    linspace_vss(v.ptr(), first, last, v.size());
}

inline void linspace(VecLlong_O v, Llong_I first, Llong_I last)
{
    linspace_vss(v.ptr(), first, last, v.size());
}

inline void linspace(VecDoub_O v, Doub_I first, Doub_I last)
{
    linspace_vss(v.ptr(), first, last, v.size());
}

inline void linspace(CmatLlong_O v, Llong_I first, Llong_I last)
{
    linspace_vss(v.ptr(), first, last, v.size());
}

inline void linspace(CmatDoub_O v, Doub_I first, Doub_I last)
{
    linspace_vss(v.ptr(), first, last, v.size());
}


inline void reorder(VecInt_O v, VecLlong_I order)
{
    Long N = v.size();
#ifdef SLS_CHECK_SHAPE
    if (order.size() != N)
        SLS_ERR("wrong shape!");
#endif
    static VecInt u(N);
	if (N > u.size())
		u.resize(max(N, 2*u.size()));
    for (Long i = 0; i < N; ++i)
        u[i] = v[order[i]];
    for (Long i = 0; i < N; ++i)
        v[i] = u[i];
}

inline void reorder(VecLlong_O v, VecLlong_I order)
{
    Long N = v.size();
#ifdef SLS_CHECK_SHAPE
    if (order.size() != N)
        SLS_ERR("wrong shape!");
#endif
    static VecLlong u(N);
	if (N > u.size())
		u.resize(max(N, 2*u.size()));
    for (Long i = 0; i < N; ++i)
        u[i] = v[order[i]];
    for (Long i = 0; i < N; ++i)
        v[i] = u[i];
}

inline void reorder(VecDoub_O v, VecLlong_I order)
{
    Long N = v.size();
#ifdef SLS_CHECK_SHAPE
    if (order.size() != N)
        SLS_ERR("wrong shape!");
#endif
    static VecDoub u(N);
	if (N > u.size())
		u.resize(max(N, 2*u.size()));
    for (Long i = 0; i < N; ++i)
        u[i] = v[order[i]];
    for (Long i = 0; i < N; ++i)
        v[i] = u[i];
}

inline void reorder(SvecChar_O v, VecLlong_I order)
{
    Long N = v.size();
#ifdef SLS_CHECK_SHAPE
    if (order.size() != N)
        SLS_ERR("wrong shape!");
#endif
    static VecChar u(N);
	if (N > u.size())
		u.resize(max(N, 2*u.size()));
    for (Long i = 0; i < N; ++i)
        u[i] = v[order[i]];
    for (Long i = 0; i < N; ++i)
        v[i] = u[i];
}

inline void reorder(SvecInt_O v, VecLlong_I order)
{
    Long N = v.size();
#ifdef SLS_CHECK_SHAPE
    if (order.size() != N)
        SLS_ERR("wrong shape!");
#endif
    static VecInt u(N);
	if (N > u.size())
		u.resize(max(N, 2*u.size()));
    for (Long i = 0; i < N; ++i)
        u[i] = v[order[i]];
    for (Long i = 0; i < N; ++i)
        v[i] = u[i];
}

inline void reorder(SvecLlong_O v, VecLlong_I order)
{
    Long N = v.size();
#ifdef SLS_CHECK_SHAPE
    if (order.size() != N)
        SLS_ERR("wrong shape!");
#endif
    static VecLlong u(N);
	if (N > u.size())
		u.resize(max(N, 2*u.size()));
    for (Long i = 0; i < N; ++i)
        u[i] = v[order[i]];
    for (Long i = 0; i < N; ++i)
        v[i] = u[i];
}

inline void reorder(SvecDoub_O v, VecLlong_I order)
{
    Long N = v.size();
#ifdef SLS_CHECK_SHAPE
    if (order.size() != N)
        SLS_ERR("wrong shape!");
#endif
    static VecDoub u(N);
	if (N > u.size())
		u.resize(max(N, 2*u.size()));
    for (Long i = 0; i < N; ++i)
        u[i] = v[order[i]];
    for (Long i = 0; i < N; ++i)
        v[i] = u[i];
}

inline void reorder(SvecComp_O v, VecLlong_I order)
{
    Long N = v.size();
#ifdef SLS_CHECK_SHAPE
    if (order.size() != N)
        SLS_ERR("wrong shape!");
#endif
    static VecComp u(N);
	if (N > u.size())
		u.resize(max(N, 2*u.size()));
    for (Long i = 0; i < N; ++i)
        u[i] = v[order[i]];
    for (Long i = 0; i < N; ++i)
        v[i] = u[i];
}


inline void trans(CmatDoub_IO v)
{
#ifdef SLS_CHECK_SHAPE
    if (v.n1() != v.n2())
        SLS_ERR("illegal shape!");
#endif
    for (Long i = 0; i < v.n1(); ++i)
        for (Long j = 0; j < i; ++j)
            swap(v(i, j), v(j, i));
}

inline void trans(CmatComp_IO v)
{
#ifdef SLS_CHECK_SHAPE
    if (v.n1() != v.n2())
        SLS_ERR("illegal shape!");
#endif
    for (Long i = 0; i < v.n1(); ++i)
        for (Long j = 0; j < i; ++j)
            swap(v(i, j), v(j, i));
}

inline void trans(DcmatDoub_IO v)
{
#ifdef SLS_CHECK_SHAPE
    if (v.n1() != v.n2())
        SLS_ERR("illegal shape!");
#endif
    for (Long i = 0; i < v.n1(); ++i)
        for (Long j = 0; j < i; ++j)
            swap(v(i, j), v(j, i));
}

inline void trans(DcmatComp_IO v)
{
#ifdef SLS_CHECK_SHAPE
    if (v.n1() != v.n2())
        SLS_ERR("illegal shape!");
#endif
    for (Long i = 0; i < v.n1(); ++i)
        for (Long j = 0; j < i; ++j)
            swap(v(i, j), v(j, i));
}


inline void trans(CmatLlong_O v, CmatLlong_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (v.n1() != v1.n2() || v.n2() != v1.n1())
        SLS_ERR("wrong size!");
#endif
    for (Long i = 0; i < v.n1(); ++i)
        for (Long j = 0; j < v.n2(); ++j)
            v(i, j) = v1(j, i);
}

inline void trans(CmatDoub_O v, CmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (v.n1() != v1.n2() || v.n2() != v1.n1())
        SLS_ERR("wrong size!");
#endif
    for (Long i = 0; i < v.n1(); ++i)
        for (Long j = 0; j < v.n2(); ++j)
            v(i, j) = v1(j, i);
}

inline void trans(CmatComp_O v, CmatComp_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (v.n1() != v1.n2() || v.n2() != v1.n1())
        SLS_ERR("wrong size!");
#endif
    for (Long i = 0; i < v.n1(); ++i)
        for (Long j = 0; j < v.n2(); ++j)
            v(i, j) = v1(j, i);
}

inline void trans(DcmatLlong_O v, DcmatLlong_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (v.n1() != v1.n2() || v.n2() != v1.n1())
        SLS_ERR("wrong size!");
#endif
    for (Long i = 0; i < v.n1(); ++i)
        for (Long j = 0; j < v.n2(); ++j)
            v(i, j) = v1(j, i);
}

inline void trans(DcmatDoub_O v, DcmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (v.n1() != v1.n2() || v.n2() != v1.n1())
        SLS_ERR("wrong size!");
#endif
    for (Long i = 0; i < v.n1(); ++i)
        for (Long j = 0; j < v.n2(); ++j)
            v(i, j) = v1(j, i);
}

inline void trans(DcmatComp_O v, DcmatComp_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (v.n1() != v1.n2() || v.n2() != v1.n1())
        SLS_ERR("wrong size!");
#endif
    for (Long i = 0; i < v.n1(); ++i)
        for (Long j = 0; j < v.n2(); ++j)
            v(i, j) = v1(j, i);
}


inline void plus_equals_vs(Char *v, Char_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] += s;
}

inline void minus_equals_vs(Char *v, Char_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] -= s;
}

inline void times_equals_vs(Char *v, Char_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] *= s;
}

inline void times_equals_vs(Char *v, Char_I s, Long_I N, Long step)
{
    for (Long i = 0; i < N*step; i += step)
        v[i] *= s;
}

inline void divide_equals_vs(Char *v, Char_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] /= s;
}

inline void divide_equals_vs(Char *v, Char_I s, Long_I N, Long_I step)
{
    for (Long i = 0; i < N*step; i += step)
        v[i] /= s;
}

inline void plus_equals_vs(Int *v, Int_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] += s;
}

inline void minus_equals_vs(Int *v, Int_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] -= s;
}

inline void times_equals_vs(Int *v, Int_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] *= s;
}

inline void times_equals_vs(Int *v, Int_I s, Long_I N, Long step)
{
    for (Long i = 0; i < N*step; i += step)
        v[i] *= s;
}

inline void divide_equals_vs(Int *v, Int_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] /= s;
}

inline void divide_equals_vs(Int *v, Int_I s, Long_I N, Long_I step)
{
    for (Long i = 0; i < N*step; i += step)
        v[i] /= s;
}

inline void plus_equals_vs(Doub *v, Doub_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] += s;
}

inline void minus_equals_vs(Doub *v, Doub_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] -= s;
}

inline void times_equals_vs(Doub *v, Doub_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] *= s;
}

inline void times_equals_vs(Doub *v, Doub_I s, Long_I N, Long step)
{
    for (Long i = 0; i < N*step; i += step)
        v[i] *= s;
}

inline void divide_equals_vs(Doub *v, Doub_I s, Long_I N)
{
    times_equals_vs(v, 1/s, N);
}

inline void divide_equals_vs(Doub *v, Doub_I s, Long_I N, Long_I step)
{
    times_equals_vs(v, 1/s, N, step);
}

inline void plus_equals_vs(Comp *v, Comp_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] += s;
}

inline void minus_equals_vs(Comp *v, Comp_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] -= s;
}

inline void times_equals_vs(Comp *v, Comp_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] *= s;
}

inline void times_equals_vs(Comp *v, Comp_I s, Long_I N, Long step)
{
    for (Long i = 0; i < N*step; i += step)
        v[i] *= s;
}

inline void divide_equals_vs(Comp *v, Comp_I s, Long_I N)
{
    times_equals_vs(v, 1/s, N);
}

inline void divide_equals_vs(Comp *v, Comp_I s, Long_I N, Long_I step)
{
    times_equals_vs(v, 1/s, N, step);
}


inline void operator+=(VecChar_IO v, Char_I s)
{
    plus_equals_vs(v.ptr(), s, v.size());
}

inline void operator-=(VecChar_IO v, Char_I s)
{
    minus_equals_vs(v.ptr(), s, v.size());
}

inline void operator*=(VecChar_IO v, Char_I s)
{
    times_equals_vs(v.ptr(), s, v.size());
}

inline void operator/=(VecChar_IO v, Char_I s)
{
    divide_equals_vs(v.ptr(), s, v.size());
}

inline void operator+=(VecInt_IO v, Int_I s)
{
    plus_equals_vs(v.ptr(), s, v.size());
}

inline void operator-=(VecInt_IO v, Int_I s)
{
    minus_equals_vs(v.ptr(), s, v.size());
}

inline void operator*=(VecInt_IO v, Int_I s)
{
    times_equals_vs(v.ptr(), s, v.size());
}

inline void operator/=(VecInt_IO v, Int_I s)
{
    divide_equals_vs(v.ptr(), s, v.size());
}

inline void operator+=(VecDoub_IO v, Doub_I s)
{
    plus_equals_vs(v.ptr(), s, v.size());
}

inline void operator-=(VecDoub_IO v, Doub_I s)
{
    minus_equals_vs(v.ptr(), s, v.size());
}

inline void operator*=(VecDoub_IO v, Doub_I s)
{
    times_equals_vs(v.ptr(), s, v.size());
}

inline void operator/=(VecDoub_IO v, Doub_I s)
{
    divide_equals_vs(v.ptr(), s, v.size());
}

inline void operator+=(VecComp_IO v, Comp_I s)
{
    plus_equals_vs(v.ptr(), s, v.size());
}

inline void operator-=(VecComp_IO v, Comp_I s)
{
    minus_equals_vs(v.ptr(), s, v.size());
}

inline void operator*=(VecComp_IO v, Comp_I s)
{
    times_equals_vs(v.ptr(), s, v.size());
}

inline void operator/=(VecComp_IO v, Comp_I s)
{
    divide_equals_vs(v.ptr(), s, v.size());
}

inline void operator+=(CmatChar_IO v, Char_I s)
{
    plus_equals_vs(v.ptr(), s, v.size());
}

inline void operator-=(CmatChar_IO v, Char_I s)
{
    minus_equals_vs(v.ptr(), s, v.size());
}

inline void operator*=(CmatChar_IO v, Char_I s)
{
    times_equals_vs(v.ptr(), s, v.size());
}

inline void operator/=(CmatChar_IO v, Char_I s)
{
    divide_equals_vs(v.ptr(), s, v.size());
}

inline void operator+=(CmatInt_IO v, Int_I s)
{
    plus_equals_vs(v.ptr(), s, v.size());
}

inline void operator-=(CmatInt_IO v, Int_I s)
{
    minus_equals_vs(v.ptr(), s, v.size());
}

inline void operator*=(CmatInt_IO v, Int_I s)
{
    times_equals_vs(v.ptr(), s, v.size());
}

inline void operator/=(CmatInt_IO v, Int_I s)
{
    divide_equals_vs(v.ptr(), s, v.size());
}

inline void operator+=(CmatDoub_IO v, Doub_I s)
{
    plus_equals_vs(v.ptr(), s, v.size());
}

inline void operator-=(CmatDoub_IO v, Doub_I s)
{
    minus_equals_vs(v.ptr(), s, v.size());
}

inline void operator*=(CmatDoub_IO v, Doub_I s)
{
    times_equals_vs(v.ptr(), s, v.size());
}

inline void operator/=(CmatDoub_IO v, Doub_I s)
{
    divide_equals_vs(v.ptr(), s, v.size());
}

inline void operator+=(CmatComp_IO v, Comp_I s)
{
    plus_equals_vs(v.ptr(), s, v.size());
}

inline void operator-=(CmatComp_IO v, Comp_I s)
{
    minus_equals_vs(v.ptr(), s, v.size());
}

inline void operator*=(CmatComp_IO v, Comp_I s)
{
    times_equals_vs(v.ptr(), s, v.size());
}

inline void operator/=(CmatComp_IO v, Comp_I s)
{
    divide_equals_vs(v.ptr(), s, v.size());
}


inline void plus_equals_vv(Char *v, const Char *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] += v1[i];
}

inline void minus_equals_vv(Char *v, const Char *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] -= v1[i];
}

inline void times_equals_vv(Char *v, const Char *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] *= v1[i];
}

inline void divide_equals_vv(Char *v, const Char *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] /= v1[i];
}

inline void plus_equals_vv(Int *v, const Int *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] += v1[i];
}

inline void minus_equals_vv(Int *v, const Int *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] -= v1[i];
}

inline void times_equals_vv(Int *v, const Int *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] *= v1[i];
}

inline void divide_equals_vv(Int *v, const Int *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] /= v1[i];
}

inline void plus_equals_vv(Doub *v, const Doub *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] += v1[i];
}

inline void minus_equals_vv(Doub *v, const Doub *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] -= v1[i];
}

inline void times_equals_vv(Doub *v, const Doub *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] *= v1[i];
}

inline void divide_equals_vv(Doub *v, const Doub *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] /= v1[i];
}

inline void plus_equals_vv(Comp *v, const Comp *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] += v1[i];
}

inline void minus_equals_vv(Comp *v, const Comp *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] -= v1[i];
}

inline void times_equals_vv(Comp *v, const Comp *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] *= v1[i];
}

inline void divide_equals_vv(Comp *v, const Comp *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] /= v1[i];
}


// v += v
inline void operator+=(VecChar_O &v, VecChar_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    plus_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v -= v
inline void operator-=(VecChar_O &v, VecChar_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v *= v
inline void operator*=(VecChar_O &v, VecChar_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    times_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v /= v
inline void operator/=(VecChar_O &v, VecChar_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v += v
inline void operator+=(VecInt_O &v, VecInt_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    plus_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v -= v
inline void operator-=(VecInt_O &v, VecInt_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v *= v
inline void operator*=(VecInt_O &v, VecInt_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    times_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v /= v
inline void operator/=(VecInt_O &v, VecInt_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v += v
inline void operator+=(VecDoub_O &v, VecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    plus_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v -= v
inline void operator-=(VecDoub_O &v, VecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v *= v
inline void operator*=(VecDoub_O &v, VecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    times_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v /= v
inline void operator/=(VecDoub_O &v, VecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v += v
inline void operator+=(VecComp_O &v, VecComp_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    plus_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v -= v
inline void operator-=(VecComp_O &v, VecComp_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v *= v
inline void operator*=(VecComp_O &v, VecComp_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    times_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v /= v
inline void operator/=(VecComp_O &v, VecComp_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v += v
inline void operator+=(MatDoub_O &v, MatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    plus_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v -= v
inline void operator-=(MatDoub_O &v, MatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v *= v
inline void operator*=(MatDoub_O &v, MatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    times_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v /= v
inline void operator/=(MatDoub_O &v, MatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v += v
inline void operator+=(MatComp_O &v, MatComp_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    plus_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v -= v
inline void operator-=(MatComp_O &v, MatComp_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v *= v
inline void operator*=(MatComp_O &v, MatComp_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    times_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v /= v
inline void operator/=(MatComp_O &v, MatComp_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v += v
inline void operator+=(CmatDoub_O &v, CmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    plus_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v -= v
inline void operator-=(CmatDoub_O &v, CmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v *= v
inline void operator*=(CmatDoub_O &v, CmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    times_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v /= v
inline void operator/=(CmatDoub_O &v, CmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v += v
inline void operator+=(CmatComp_O &v, CmatComp_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    plus_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v -= v
inline void operator-=(CmatComp_O &v, CmatComp_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v *= v
inline void operator*=(CmatComp_O &v, CmatComp_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    times_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v /= v
inline void operator/=(CmatComp_O &v, CmatComp_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v += v
inline void operator+=(Cmat3Doub_O &v, Cmat3Doub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    plus_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v -= v
inline void operator-=(Cmat3Doub_O &v, Cmat3Doub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v *= v
inline void operator*=(Cmat3Doub_O &v, Cmat3Doub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    times_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v /= v
inline void operator/=(Cmat3Doub_O &v, Cmat3Doub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v += v
inline void operator+=(Cmat3Comp_O &v, Cmat3Comp_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    plus_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v -= v
inline void operator-=(Cmat3Comp_O &v, Cmat3Comp_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    minus_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v *= v
inline void operator*=(Cmat3Comp_O &v, Cmat3Comp_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    times_equals_vv(v.ptr(), v1.ptr(), v1.size());
}

// v /= v
inline void operator/=(Cmat3Comp_O &v, Cmat3Comp_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    divide_equals_vv(v.ptr(), v1.ptr(), v1.size());
}


inline void plus_vvs(Char *v, const Char *v1, Char_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] + s;
}

inline void minus_vvs(Char *v, const Char *v1, Char_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] - s;
}

inline void times_vvs(Char *v, const Char *v1, Char_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] * s;
}

inline void divide_vvs(Char *v, const Char *v1, Char_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] * s;
}

inline void plus_vvs(Int *v, const Int *v1, Int_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] + s;
}

inline void minus_vvs(Int *v, const Int *v1, Int_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] - s;
}

inline void times_vvs(Int *v, const Int *v1, Int_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] * s;
}

inline void divide_vvs(Int *v, const Int *v1, Int_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] * s;
}

inline void plus_vvs(Llong *v, const Llong *v1, Llong_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] + s;
}

inline void minus_vvs(Llong *v, const Llong *v1, Llong_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] - s;
}

inline void times_vvs(Llong *v, const Llong *v1, Llong_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] * s;
}

inline void divide_vvs(Llong *v, const Llong *v1, Llong_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] * s;
}

inline void plus_vvs(Float *v, const Float *v1, Float_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] + s;
}

inline void minus_vvs(Float *v, const Float *v1, Float_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] - s;
}

inline void times_vvs(Float *v, const Float *v1, Float_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] * s;
}

inline void divide_vvs(Float *v, const Float *v1, Float_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] * s;
}

inline void plus_vvs(Doub *v, const Doub *v1, Doub_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] + s;
}

inline void minus_vvs(Doub *v, const Doub *v1, Doub_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] - s;
}

inline void times_vvs(Doub *v, const Doub *v1, Doub_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] * s;
}

inline void divide_vvs(Doub *v, const Doub *v1, Doub_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] * s;
}

inline void plus_vvs(Comp *v, const Comp *v1, Doub_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] + s;
}

inline void minus_vvs(Comp *v, const Comp *v1, Doub_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] - s;
}

inline void times_vvs(Comp *v, const Comp *v1, Doub_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] * s;
}

inline void divide_vvs(Comp *v, const Comp *v1, Doub_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] * s;
}

inline void plus_vvs(Comp *v, const Doub *v1, Comp_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] + s;
}

inline void minus_vvs(Comp *v, const Doub *v1, Comp_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] - s;
}

inline void times_vvs(Comp *v, const Doub *v1, Comp_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] * s;
}

inline void divide_vvs(Comp *v, const Doub *v1, Comp_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] * s;
}

inline void plus_vvs(Comp *v, const Comp *v1, Comp_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] + s;
}

inline void minus_vvs(Comp *v, const Comp *v1, Comp_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] - s;
}

inline void times_vvs(Comp *v, const Comp *v1, Comp_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] * s;
}

inline void divide_vvs(Comp *v, const Comp *v1, Comp_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] * s;
}


inline void minus_vsv(Char *v, const Char &s, const Char *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = s - v1[i];
}

inline void divide_vsv(Char *v, const Char &s, const Char *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = s / v1[i];
}

inline void minus_vsv(Int *v, const Int &s, const Int *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = s - v1[i];
}

inline void divide_vsv(Int *v, const Int &s, const Int *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = s / v1[i];
}

inline void minus_vsv(Llong *v, const Llong &s, const Llong *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = s - v1[i];
}

inline void divide_vsv(Llong *v, const Llong &s, const Llong *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = s / v1[i];
}

inline void minus_vsv(Float *v, const Float &s, const Float *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = s - v1[i];
}

inline void divide_vsv(Float *v, const Float &s, const Float *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = s / v1[i];
}

inline void minus_vsv(Doub *v, const Doub &s, const Doub *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = s - v1[i];
}

inline void divide_vsv(Doub *v, const Doub &s, const Doub *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = s / v1[i];
}

inline void minus_vsv(Comp *v, const Comp &s, const Doub *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = s - v1[i];
}

inline void divide_vsv(Comp *v, const Comp &s, const Doub *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = s / v1[i];
}

inline void minus_vsv(Comp *v, const Doub &s, const Comp *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = s - v1[i];
}

inline void divide_vsv(Comp *v, const Doub &s, const Comp *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = s / v1[i];
}

inline void minus_vsv(Comp *v, const Comp &s, const Comp *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = s - v1[i];
}

inline void divide_vsv(Comp *v, const Comp &s, const Comp *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = s / v1[i];
}


inline void plus_vvv(Char *v, const Char *v1, const Char *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] + v2[i];
}

inline void minus_vvv(Char *v, const Char *v1, const Char *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] - v2[i];
}

inline void times_vvv(Char *v, const Char *v1, const Char *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] * v2[i];
}

inline void divide_vvv(Char *v, const Char *v1, const Char *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] / v2[i];
}

inline void plus_vvv(Int *v, const Int *v1, const Int *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] + v2[i];
}

inline void minus_vvv(Int *v, const Int *v1, const Int *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] - v2[i];
}

inline void times_vvv(Int *v, const Int *v1, const Int *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] * v2[i];
}

inline void divide_vvv(Int *v, const Int *v1, const Int *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] / v2[i];
}

inline void plus_vvv(Llong *v, const Llong *v1, const Llong *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] + v2[i];
}

inline void minus_vvv(Llong *v, const Llong *v1, const Llong *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] - v2[i];
}

inline void times_vvv(Llong *v, const Llong *v1, const Llong *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] * v2[i];
}

inline void divide_vvv(Llong *v, const Llong *v1, const Llong *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] / v2[i];
}

inline void plus_vvv(Float *v, const Float *v1, const Float *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] + v2[i];
}

inline void minus_vvv(Float *v, const Float *v1, const Float *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] - v2[i];
}

inline void times_vvv(Float *v, const Float *v1, const Float *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] * v2[i];
}

inline void divide_vvv(Float *v, const Float *v1, const Float *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] / v2[i];
}

inline void plus_vvv(Doub *v, const Doub *v1, const Doub *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] + v2[i];
}

inline void minus_vvv(Doub *v, const Doub *v1, const Doub *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] - v2[i];
}

inline void times_vvv(Doub *v, const Doub *v1, const Doub *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] * v2[i];
}

inline void divide_vvv(Doub *v, const Doub *v1, const Doub *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] / v2[i];
}

inline void plus_vvv(Comp *v, const Comp *v1, const Doub *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] + v2[i];
}

inline void minus_vvv(Comp *v, const Comp *v1, const Doub *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] - v2[i];
}

inline void times_vvv(Comp *v, const Comp *v1, const Doub *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] * v2[i];
}

inline void divide_vvv(Comp *v, const Comp *v1, const Doub *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] / v2[i];
}

inline void plus_vvv(Comp *v, const Doub *v1, const Comp *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] + v2[i];
}

inline void minus_vvv(Comp *v, const Doub *v1, const Comp *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] - v2[i];
}

inline void times_vvv(Comp *v, const Doub *v1, const Comp *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] * v2[i];
}

inline void divide_vvv(Comp *v, const Doub *v1, const Comp *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] / v2[i];
}

inline void plus_vvv(Comp *v, const Comp *v1, const Comp *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] + v2[i];
}

inline void minus_vvv(Comp *v, const Comp *v1, const Comp *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] - v2[i];
}

inline void times_vvv(Comp *v, const Comp *v1, const Comp *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] * v2[i];
}

inline void divide_vvv(Comp *v, const Comp *v1, const Comp *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] / v2[i];
}


inline void plus(VecChar_O v, VecChar_I v1, Char_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    plus_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void plus(VecChar_O v, Char_I s, VecChar_I v1)
{
	plus(v, v1, s);
}

inline void minus(VecChar_O v, VecChar_I v1, Char_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    minus_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void minus(VecChar_O v, Char_I s, VecChar_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    minus_vsv(v.ptr(), s, v1.ptr(), v1.size());
}

inline void times(VecChar_O v, VecChar_I v1, Char_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    times_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void times(VecChar_O v, Char_I s, VecChar_I v1)
{
	times(v, v1, s);
}

inline void divide(VecChar_O v, VecChar_I v1, Char_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    divide_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void divide(VecChar_O v, Char_I s, VecChar_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    divide_vsv(v.ptr(), s, v1.ptr(), v1.size());
}

inline void plus(VecInt_O v, VecInt_I v1, Int_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    plus_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void plus(VecInt_O v, Int_I s, VecInt_I v1)
{
	plus(v, v1, s);
}

inline void minus(VecInt_O v, VecInt_I v1, Int_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    minus_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void minus(VecInt_O v, Int_I s, VecInt_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    minus_vsv(v.ptr(), s, v1.ptr(), v1.size());
}

inline void times(VecInt_O v, VecInt_I v1, Int_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    times_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void times(VecInt_O v, Int_I s, VecInt_I v1)
{
	times(v, v1, s);
}

inline void divide(VecInt_O v, VecInt_I v1, Int_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    divide_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void divide(VecInt_O v, Int_I s, VecInt_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    divide_vsv(v.ptr(), s, v1.ptr(), v1.size());
}

inline void plus(VecLlong_O v, VecLlong_I v1, Llong_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    plus_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void plus(VecLlong_O v, Llong_I s, VecLlong_I v1)
{
	plus(v, v1, s);
}

inline void minus(VecLlong_O v, VecLlong_I v1, Llong_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    minus_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void minus(VecLlong_O v, Llong_I s, VecLlong_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    minus_vsv(v.ptr(), s, v1.ptr(), v1.size());
}

inline void times(VecLlong_O v, VecLlong_I v1, Llong_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    times_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void times(VecLlong_O v, Llong_I s, VecLlong_I v1)
{
	times(v, v1, s);
}

inline void divide(VecLlong_O v, VecLlong_I v1, Llong_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    divide_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void divide(VecLlong_O v, Llong_I s, VecLlong_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    divide_vsv(v.ptr(), s, v1.ptr(), v1.size());
}

inline void plus(VecDoub_O v, VecDoub_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    plus_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void plus(VecDoub_O v, Doub_I s, VecDoub_I v1)
{
	plus(v, v1, s);
}

inline void minus(VecDoub_O v, VecDoub_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    minus_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void minus(VecDoub_O v, Doub_I s, VecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    minus_vsv(v.ptr(), s, v1.ptr(), v1.size());
}

inline void times(VecDoub_O v, VecDoub_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    times_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void times(VecDoub_O v, Doub_I s, VecDoub_I v1)
{
	times(v, v1, s);
}

inline void divide(VecDoub_O v, VecDoub_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    divide_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void divide(VecDoub_O v, Doub_I s, VecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    divide_vsv(v.ptr(), s, v1.ptr(), v1.size());
}

inline void plus(VecComp_O v, VecComp_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    plus_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void plus(VecComp_O v, Doub_I s, VecComp_I v1)
{
	plus(v, v1, s);
}

inline void minus(VecComp_O v, VecComp_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    minus_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void minus(VecComp_O v, Doub_I s, VecComp_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    minus_vsv(v.ptr(), s, v1.ptr(), v1.size());
}

inline void times(VecComp_O v, VecComp_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    times_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void times(VecComp_O v, Doub_I s, VecComp_I v1)
{
	times(v, v1, s);
}

inline void divide(VecComp_O v, VecComp_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    divide_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void divide(VecComp_O v, Doub_I s, VecComp_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    divide_vsv(v.ptr(), s, v1.ptr(), v1.size());
}

inline void plus(VecComp_O v, VecDoub_I v1, Comp_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    plus_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void plus(VecComp_O v, Comp_I s, VecDoub_I v1)
{
	plus(v, v1, s);
}

inline void minus(VecComp_O v, VecDoub_I v1, Comp_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    minus_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void minus(VecComp_O v, Comp_I s, VecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    minus_vsv(v.ptr(), s, v1.ptr(), v1.size());
}

inline void times(VecComp_O v, VecDoub_I v1, Comp_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    times_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void times(VecComp_O v, Comp_I s, VecDoub_I v1)
{
	times(v, v1, s);
}

inline void divide(VecComp_O v, VecDoub_I v1, Comp_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    divide_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void divide(VecComp_O v, Comp_I s, VecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    divide_vsv(v.ptr(), s, v1.ptr(), v1.size());
}

inline void plus(VecComp_O v, VecComp_I v1, Comp_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    plus_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void plus(VecComp_O v, Comp_I s, VecComp_I v1)
{
	plus(v, v1, s);
}

inline void minus(VecComp_O v, VecComp_I v1, Comp_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    minus_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void minus(VecComp_O v, Comp_I s, VecComp_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    minus_vsv(v.ptr(), s, v1.ptr(), v1.size());
}

inline void times(VecComp_O v, VecComp_I v1, Comp_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    times_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void times(VecComp_O v, Comp_I s, VecComp_I v1)
{
	times(v, v1, s);
}

inline void divide(VecComp_O v, VecComp_I v1, Comp_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    divide_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void divide(VecComp_O v, Comp_I s, VecComp_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    divide_vsv(v.ptr(), s, v1.ptr(), v1.size());
}

inline void plus(CmatInt_O v, CmatInt_I v1, Int_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    plus_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void plus(CmatInt_O v, Int_I s, CmatInt_I v1)
{
	plus(v, v1, s);
}

inline void minus(CmatInt_O v, CmatInt_I v1, Int_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    minus_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void minus(CmatInt_O v, Int_I s, CmatInt_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    minus_vsv(v.ptr(), s, v1.ptr(), v1.size());
}

inline void times(CmatInt_O v, CmatInt_I v1, Int_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    times_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void times(CmatInt_O v, Int_I s, CmatInt_I v1)
{
	times(v, v1, s);
}

inline void divide(CmatInt_O v, CmatInt_I v1, Int_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    divide_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void divide(CmatInt_O v, Int_I s, CmatInt_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    divide_vsv(v.ptr(), s, v1.ptr(), v1.size());
}

inline void plus(CmatLlong_O v, CmatLlong_I v1, Llong_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    plus_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void plus(CmatLlong_O v, Llong_I s, CmatLlong_I v1)
{
	plus(v, v1, s);
}

inline void minus(CmatLlong_O v, CmatLlong_I v1, Llong_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    minus_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void minus(CmatLlong_O v, Llong_I s, CmatLlong_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    minus_vsv(v.ptr(), s, v1.ptr(), v1.size());
}

inline void times(CmatLlong_O v, CmatLlong_I v1, Llong_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    times_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void times(CmatLlong_O v, Llong_I s, CmatLlong_I v1)
{
	times(v, v1, s);
}

inline void divide(CmatLlong_O v, CmatLlong_I v1, Llong_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    divide_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void divide(CmatLlong_O v, Llong_I s, CmatLlong_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    divide_vsv(v.ptr(), s, v1.ptr(), v1.size());
}

inline void plus(CmatDoub_O v, CmatDoub_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    plus_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void plus(CmatDoub_O v, Doub_I s, CmatDoub_I v1)
{
	plus(v, v1, s);
}

inline void minus(CmatDoub_O v, CmatDoub_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    minus_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void minus(CmatDoub_O v, Doub_I s, CmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    minus_vsv(v.ptr(), s, v1.ptr(), v1.size());
}

inline void times(CmatDoub_O v, CmatDoub_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    times_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void times(CmatDoub_O v, Doub_I s, CmatDoub_I v1)
{
	times(v, v1, s);
}

inline void divide(CmatDoub_O v, CmatDoub_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    divide_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void divide(CmatDoub_O v, Doub_I s, CmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    divide_vsv(v.ptr(), s, v1.ptr(), v1.size());
}

inline void plus(CmatComp_O v, CmatComp_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    plus_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void plus(CmatComp_O v, Doub_I s, CmatComp_I v1)
{
	plus(v, v1, s);
}

inline void minus(CmatComp_O v, CmatComp_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    minus_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void minus(CmatComp_O v, Doub_I s, CmatComp_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    minus_vsv(v.ptr(), s, v1.ptr(), v1.size());
}

inline void times(CmatComp_O v, CmatComp_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    times_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void times(CmatComp_O v, Doub_I s, CmatComp_I v1)
{
	times(v, v1, s);
}

inline void divide(CmatComp_O v, CmatComp_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    divide_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void divide(CmatComp_O v, Doub_I s, CmatComp_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    divide_vsv(v.ptr(), s, v1.ptr(), v1.size());
}

inline void plus(CmatComp_O v, CmatDoub_I v1, Comp_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    plus_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void plus(CmatComp_O v, Comp_I s, CmatDoub_I v1)
{
	plus(v, v1, s);
}

inline void minus(CmatComp_O v, CmatDoub_I v1, Comp_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    minus_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void minus(CmatComp_O v, Comp_I s, CmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    minus_vsv(v.ptr(), s, v1.ptr(), v1.size());
}

inline void times(CmatComp_O v, CmatDoub_I v1, Comp_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    times_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void times(CmatComp_O v, Comp_I s, CmatDoub_I v1)
{
	times(v, v1, s);
}

inline void divide(CmatComp_O v, CmatDoub_I v1, Comp_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    divide_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void divide(CmatComp_O v, Comp_I s, CmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    divide_vsv(v.ptr(), s, v1.ptr(), v1.size());
}

inline void plus(CmatComp_O v, CmatComp_I v1, Comp_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    plus_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void plus(CmatComp_O v, Comp_I s, CmatComp_I v1)
{
	plus(v, v1, s);
}

inline void minus(CmatComp_O v, CmatComp_I v1, Comp_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    minus_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void minus(CmatComp_O v, Comp_I s, CmatComp_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    minus_vsv(v.ptr(), s, v1.ptr(), v1.size());
}

inline void times(CmatComp_O v, CmatComp_I v1, Comp_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    times_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void times(CmatComp_O v, Comp_I s, CmatComp_I v1)
{
	times(v, v1, s);
}

inline void divide(CmatComp_O v, CmatComp_I v1, Comp_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    divide_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void divide(CmatComp_O v, Comp_I s, CmatComp_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    divide_vsv(v.ptr(), s, v1.ptr(), v1.size());
}


inline void pow_vs(Int *v, Int_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = pow(v[i], s);
}

inline void pow_vs(Llong *v, Llong_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = pow(v[i], s);
}

inline void pow_vs(Float *v, Float_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = pow(v[i], s);
}

inline void pow_vs(Doub *v, Int_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = pow(v[i], s);
}

inline void pow_vs(Doub *v, Llong_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = pow(v[i], s);
}

inline void pow_vs(Doub *v, Doub_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = pow(v[i], s);
}

inline void pow_vs(Comp *v, Int_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = pow(v[i], s);
}

inline void pow_vs(Comp *v, Llong_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = pow(v[i], s);
}

inline void pow_vs(Comp *v, Doub_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = pow(v[i], s);
}

inline void pow_vs(Comp *v, Comp_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = pow(v[i], s);
}


inline void pow(VecLlong_IO v, Llong_I s)
{
    pow_vs(v.ptr(), s, v.size());
}

inline void pow(VecDoub_IO v, Int_I s)
{
    pow_vs(v.ptr(), s, v.size());
}

inline void pow(VecDoub_IO v, Doub_I s)
{
    pow_vs(v.ptr(), s, v.size());
}

inline void pow(VecComp_IO v, Int_I s)
{
    pow_vs(v.ptr(), s, v.size());
}

inline void pow(VecComp_IO v, Doub_I s)
{
    pow_vs(v.ptr(), s, v.size());
}

inline void pow(VecComp_IO v, Comp_I s)
{
    pow_vs(v.ptr(), s, v.size());
}


inline void pow_vvs(Int *v, const Int *v1, Int_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = pow(v1[i], s);
}

inline void pow_vvs(Llong *v, const Llong *v1, Llong_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = pow(v1[i], s);
}

inline void pow_vvs(Float *v, const Float *v1, Float_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = pow(v1[i], s);
}

inline void pow_vvs(Doub *v, const Doub *v1, Int_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = pow(v1[i], s);
}

inline void pow_vvs(Doub *v, const Doub *v1, Llong_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = pow(v1[i], s);
}

inline void pow_vvs(Doub *v, const Doub *v1, Doub_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = pow(v1[i], s);
}

inline void pow_vvs(Comp *v, const Comp *v1, Int_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = pow(v1[i], s);
}

inline void pow_vvs(Comp *v, const Comp *v1, Llong_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = pow(v1[i], s);
}

inline void pow_vvs(Comp *v, const Comp *v1, Doub_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = pow(v1[i], s);
}

inline void pow_vvs(Comp *v, const Comp *v1, Comp_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = pow(v1[i], s);
}


inline void pow(VecLlong_O v, VecLlong_I v1, Llong_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    pow_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void pow(VecDoub_O v, VecDoub_I v1, Int_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    pow_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void pow(VecDoub_O v, VecDoub_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    pow_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void pow(VecComp_O v, VecComp_I v1, Int_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    pow_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void pow(VecComp_O v, VecComp_I v1, Doub_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    pow_vvs(v.ptr(), v1.ptr(), s, v1.size());
}

inline void pow(VecComp_O v, VecComp_I v1, Comp_I s)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong size!");
#endif
    pow_vvs(v.ptr(), v1.ptr(), s, v1.size());
}


inline Int dot_vv(const Int *v1, const Int *v2, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
	Int s = v1[0] * v2[0];
    for (Long i = 1; i < N; ++i) {
		s += v1[i] * v2[i];
	}
    return s;
}

inline Llong dot_vv(const Llong *v1, const Llong *v2, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
	Llong s = v1[0] * v2[0];
    for (Long i = 1; i < N; ++i) {
		s += v1[i] * v2[i];
	}
    return s;
}

inline Float dot_vv(const Float *v1, const Float *v2, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
	Float s = v1[0] * v2[0];
    for (Long i = 1; i < N; ++i) {
		s += v1[i] * v2[i];
	}
    return s;
}

inline Doub dot_vv(const Doub *v1, const Int *v2, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
	Doub s = v1[0] * v2[0];
    for (Long i = 1; i < N; ++i) {
		s += v1[i] * v2[i];
	}
    return s;
}

inline Doub dot_vv(const Doub *v1, const Llong *v2, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
	Doub s = v1[0] * v2[0];
    for (Long i = 1; i < N; ++i) {
		s += v1[i] * v2[i];
	}
    return s;
}

inline Doub dot_vv(const Doub *v1, const Doub *v2, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
	Doub s = v1[0] * v2[0];
    for (Long i = 1; i < N; ++i) {
		s += v1[i] * v2[i];
	}
    return s;
}

inline Comp dot_vv(const Comp *v1, const Int *v2, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Comp s = conj(v1[0]) * v2[0];
    for (Long i = 1; i < N; ++i) {
        s += conj(v1[i]) * v2[i];
	}
    return s;
}

inline Comp dot_vv(const Comp *v1, const Llong *v2, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Comp s = conj(v1[0]) * v2[0];
    for (Long i = 1; i < N; ++i) {
        s += conj(v1[i]) * v2[i];
	}
    return s;
}

inline Comp dot_vv(const Comp *v1, const Doub *v2, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Comp s = conj(v1[0]) * v2[0];
    for (Long i = 1; i < N; ++i) {
        s += conj(v1[i]) * v2[i];
	}
    return s;
}

inline Comp dot_vv(const Comp *v1, const Comp *v2, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N <= 0) SLS_ERR("illegal length!");
#endif
    Comp s = conj(v1[0]) * v2[0];
    for (Long i = 1; i < N; ++i) {
        s += conj(v1[i]) * v2[i];
	}
    return s;
}


inline Llong dot(VecLlong_I v1, VecLlong_I v2)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v1, v2))
        SLS_ERR("wrong shape!");
#endif
    return dot_vv(v1.ptr(), v2.ptr(), v2.size());
}

inline Doub dot(VecDoub_I v1, VecDoub_I v2)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v1, v2))
        SLS_ERR("wrong shape!");
#endif
    return dot_vv(v1.ptr(), v2.ptr(), v2.size());
}

inline Comp dot(VecComp_I v1, VecComp_I v2)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v1, v2))
        SLS_ERR("wrong shape!");
#endif
    return dot_vv(v1.ptr(), v2.ptr(), v2.size());
}


inline void mul(VecDoub_O y, CmatDoub_I a, VecDoub_I x)
{
    Long Nr = a.n1(), Nc = a.n2();
#ifdef SLS_CHECK_SHAPE
    if (Nc != x.size() || y.size() != Nr)
        SLS_ERR("illegal shape!");
#endif
    for (Long i = 0; i < Nr; ++i) {
        y[i] = 0;
        for (Long j = 0; j < Nc; ++j)
            y[i] += a(i, j) * x[j];
    }
}

inline void mul(VecComp_O y, CmatComp_I a, VecComp_I x)
{
    Long Nr = a.n1(), Nc = a.n2();
#ifdef SLS_CHECK_SHAPE
    if (Nc != x.size() || y.size() != Nr)
        SLS_ERR("illegal shape!");
#endif
    for (Long i = 0; i < Nr; ++i) {
        y[i] = 0;
        for (Long j = 0; j < Nc; ++j)
            y[i] += a(i, j) * x[j];
    }
}

inline void mul(VecComp_O y, CmatDoub_I a, VecComp_I x)
{
    Long Nr = a.n1(), Nc = a.n2();
#ifdef SLS_CHECK_SHAPE
    if (Nc != x.size() || y.size() != Nr)
        SLS_ERR("illegal shape!");
#endif
    for (Long i = 0; i < Nr; ++i) {
        y[i] = 0;
        for (Long j = 0; j < Nc; ++j)
            y[i] += a(i, j) * x[j];
    }
}

inline void mul(VecComp_O y, MatComp_I a, VecComp_I x)
{
    Long Nr = a.n1(), Nc = a.n2();
#ifdef SLS_CHECK_SHAPE
    if (Nc != x.size() || y.size() != Nr)
        SLS_ERR("illegal shape!");
#endif
    for (Long i = 0; i < Nr; ++i) {
        y[i] = 0;
        for (Long j = 0; j < Nc; ++j)
            y[i] += a(i, j) * x[j];
    }
}


inline void mul(CmatDoub_O y, CmatDoub_I a, CmatDoub_I x)
{
    Long Nr_a = a.n1(), Nc_a = a.n2(), Nc_x = x.n2();
#ifdef SLS_CHECK_SHAPE
    if (a.n2() != x.n1() || y.n1() != Nr_a || y.n2() != Nc_x)
        SLS_ERR("illegal shape!");
#endif
    vecset(y.ptr(), 0, Nr_a*Nc_x);
    for (Long i = 0; i < Nr_a; ++i) {
        for (Long j = 0; j < Nc_x; ++j) {
            for (Long k = 0; k < Nc_a; ++k)
                y(i, j) += a(i, k) * x(k, j);
        }
    }
}

inline void mul(CmatComp_O y, CmatComp_I a, CmatComp_I x)
{
    Long Nr_a = a.n1(), Nc_a = a.n2(), Nc_x = x.n2();
#ifdef SLS_CHECK_SHAPE
    if (a.n2() != x.n1() || y.n1() != Nr_a || y.n2() != Nc_x)
        SLS_ERR("illegal shape!");
#endif
    vecset(y.ptr(), 0, Nr_a*Nc_x);
    for (Long i = 0; i < Nr_a; ++i) {
        for (Long j = 0; j < Nc_x; ++j) {
            for (Long k = 0; k < Nc_a; ++k)
                y(i, j) += a(i, k) * x(k, j);
        }
    }
}


inline void mul_gen(VecDoub_O &y, CmatDoub_I a, VecDoub_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
    lda = a.n1();
    incx = 1;
    CBLAS_LAYOUT layout = CblasColMajor;

    cblas_dgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
        lda, x.ptr(), incx, beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

inline void mul_gen(VecComp_O &y, CmatDoub_I a, VecComp_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), N2 = a.n2(), lda, incx, incy;
    incy =  1;
    lda = a.n1();
    incx = 1;
    CBLAS_LAYOUT layout = CblasColMajor;

    // do real part
    cblas_dgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
        lda, (Doub*)x.ptr(), 2*incx, beta, (Doub*)y.ptr(), 2*incy);
    // do imag part
    cblas_dgemv(layout, CblasNoTrans, N1, N2, alpha, a.ptr(),
        lda, (Doub*)x.ptr()+1, 2*incx, beta, (Doub*)y.ptr()+1, 2*incy);
#else
    mul(y, a, x);
#endif
}


inline void mul_sym(VecDoub_O &y, CmatDoub_I a, VecDoub_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1() || x.size() != y.size())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), lda, incx, incy;
    incy =  1;
    lda = a.n1();
    incx = 1;
    CBLAS_LAYOUT layout = CblasColMajor;

    cblas_dsymv(layout, CblasUpper, N1, alpha, a.ptr(),
        lda, x.ptr(), incx, beta, y.ptr(), incy);
#else
    mul(y, a, x);
#endif
}

inline void mul_sym(VecComp_O &y, CmatDoub_I a, VecComp_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (x.size() != a.n2() || y.size() != a.n1() || x.size() != y.size())
        SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
    Long N1 = a.n1(), lda, incx, incy;
    incy =  1;
    lda = a.n1();
    incx = 1;
    CBLAS_LAYOUT layout = CblasColMajor;

    // do real part
    cblas_dsymv(layout, CblasUpper, N1, alpha, a.ptr(),
        lda, (Doub*)x.ptr(), 2*incx, beta, (Doub*)y.ptr(), 2*incy);
    // do imag part
    cblas_dsymv(layout, CblasUpper, N1, alpha, a.ptr(),
        lda, (Doub*)x.ptr()+1, 2*incx, beta, (Doub*)y.ptr()+1, 2*incy);
#else
    mul(y, a, x);
#endif
}

} // namespace slisc
