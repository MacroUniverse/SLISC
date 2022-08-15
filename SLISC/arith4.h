// element-wise +, -, *, /
#pragma once
#include "scalar_arith.h"
#include "compare.h"

namespace slisc {

inline void plus_equals_vs(Int *v, Int_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] += s;
}

inline void plus_equals_vs(Int *v, Int_I s, Long_I N, Long step)
{
    for (Long i = 0; i < N*step; i += step)
        v[i] += s;
}

inline void minus_equals_vs(Int *v, Int_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] -= s;
}

inline void minus_equals_vs(Int *v, Int_I s, Long_I N, Long step)
{
    for (Long i = 0; i < N*step; i += step)
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

inline void plus_equals_vs(Llong *v, Llong_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] += s;
}

inline void plus_equals_vs(Llong *v, Llong_I s, Long_I N, Long step)
{
    for (Long i = 0; i < N*step; i += step)
        v[i] += s;
}

inline void minus_equals_vs(Llong *v, Llong_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] -= s;
}

inline void minus_equals_vs(Llong *v, Llong_I s, Long_I N, Long step)
{
    for (Long i = 0; i < N*step; i += step)
        v[i] -= s;
}

inline void times_equals_vs(Llong *v, Llong_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] *= s;
}

inline void times_equals_vs(Llong *v, Llong_I s, Long_I N, Long step)
{
    for (Long i = 0; i < N*step; i += step)
        v[i] *= s;
}
inline void divide_equals_vs(Llong *v, Llong_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] /= s;
}

inline void divide_equals_vs(Llong *v, Llong_I s, Long_I N, Long_I step)
{
    for (Long i = 0; i < N*step; i += step)
        v[i] /= s;
}

inline void plus_equals_vs(Doub *v, Doub_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] += s;
}

inline void plus_equals_vs(Doub *v, Doub_I s, Long_I N, Long step)
{
    for (Long i = 0; i < N*step; i += step)
        v[i] += s;
}

inline void minus_equals_vs(Doub *v, Doub_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] -= s;
}

inline void minus_equals_vs(Doub *v, Doub_I s, Long_I N, Long step)
{
    for (Long i = 0; i < N*step; i += step)
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
{ times_equals_vs(v, 1./s, N); }

inline void divide_equals_vs(Doub *v, Doub_I s, Long_I N, Long_I step)
{ times_equals_vs(v, 1./s, N, step); }

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
{ times_equals_vs(v, 1./s, N); }

inline void divide_equals_vs(Comp *v, Doub_I s, Long_I N, Long_I step)
{ times_equals_vs(v, 1./s, N, step); }

inline void plus_equals_vs(Comp *v, Comp_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] += s;
}

inline void plus_equals_vs(Comp *v, Comp_I s, Long_I N, Long step)
{
    for (Long i = 0; i < N*step; i += step)
        v[i] += s;
}

inline void minus_equals_vs(Comp *v, Comp_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] -= s;
}

inline void minus_equals_vs(Comp *v, Comp_I s, Long_I N, Long step)
{
    for (Long i = 0; i < N*step; i += step)
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
{ times_equals_vs(v, 1./s, N); }

inline void divide_equals_vs(Comp *v, Comp_I s, Long_I N, Long_I step)
{ times_equals_vs(v, 1./s, N, step); }

inline void plus_equals_vs(Comp *v, Imag_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] += s;
}

inline void plus_equals_vs(Comp *v, Imag_I s, Long_I N, Long step)
{
    for (Long i = 0; i < N*step; i += step)
        v[i] += s;
}

inline void minus_equals_vs(Comp *v, Imag_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] -= s;
}

inline void minus_equals_vs(Comp *v, Imag_I s, Long_I N, Long step)
{
    for (Long i = 0; i < N*step; i += step)
        v[i] -= s;
}

inline void times_equals_vs(Comp *v, Imag_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] *= s;
}

inline void times_equals_vs(Comp *v, Imag_I s, Long_I N, Long step)
{
    for (Long i = 0; i < N*step; i += step)
        v[i] *= s;
}
inline void divide_equals_vs(Comp *v, Imag_I s, Long_I N)
{ times_equals_vs(v, 1./s, N); }

inline void divide_equals_vs(Comp *v, Imag_I s, Long_I N, Long_I step)
{ times_equals_vs(v, 1./s, N, step); }


inline void operator+=(vecInt_IO v, Int_I s)
{ plus_equals_vs(v.data(), s, v.size()); }

inline void operator-=(vecInt_IO v, Int_I s)
{ minus_equals_vs(v.data(), s, v.size()); }

inline void operator*=(vecInt_IO v, Int_I s)
{ times_equals_vs(v.data(), s, v.size()); }

inline void operator/=(vecInt_IO v, Int_I s)
{ divide_equals_vs(v.data(), s, v.size()); }

inline void operator+=(vecLlong_IO v, Llong_I s)
{ plus_equals_vs(v.data(), s, v.size()); }

inline void operator-=(vecLlong_IO v, Llong_I s)
{ minus_equals_vs(v.data(), s, v.size()); }

inline void operator*=(vecLlong_IO v, Llong_I s)
{ times_equals_vs(v.data(), s, v.size()); }

inline void operator/=(vecLlong_IO v, Llong_I s)
{ divide_equals_vs(v.data(), s, v.size()); }

inline void operator+=(VecInt_IO v, Int_I s)
{ plus_equals_vs(v.p(), s, v.size()); }

inline void operator-=(VecInt_IO v, Int_I s)
{ minus_equals_vs(v.p(), s, v.size()); }

inline void operator*=(VecInt_IO v, Int_I s)
{ times_equals_vs(v.p(), s, v.size()); }

inline void operator/=(VecInt_IO v, Int_I s)
{ divide_equals_vs(v.p(), s, v.size()); }

inline void operator+=(VecLlong_IO v, Llong_I s)
{ plus_equals_vs(v.p(), s, v.size()); }

inline void operator-=(VecLlong_IO v, Llong_I s)
{ minus_equals_vs(v.p(), s, v.size()); }

inline void operator*=(VecLlong_IO v, Llong_I s)
{ times_equals_vs(v.p(), s, v.size()); }

inline void operator/=(VecLlong_IO v, Llong_I s)
{ divide_equals_vs(v.p(), s, v.size()); }

inline void operator+=(VecDoub_IO v, Doub_I s)
{ plus_equals_vs(v.p(), s, v.size()); }

inline void operator-=(VecDoub_IO v, Doub_I s)
{ minus_equals_vs(v.p(), s, v.size()); }

inline void operator*=(VecDoub_IO v, Doub_I s)
{ times_equals_vs(v.p(), s, v.size()); }

inline void operator/=(VecDoub_IO v, Doub_I s)
{ divide_equals_vs(v.p(), s, v.size()); }

inline void operator+=(VecComp_IO v, Doub_I s)
{ plus_equals_vs(v.p(), s, v.size()); }

inline void operator-=(VecComp_IO v, Doub_I s)
{ minus_equals_vs(v.p(), s, v.size()); }

inline void operator*=(VecComp_IO v, Doub_I s)
{ times_equals_vs(v.p(), s, v.size()); }

inline void operator/=(VecComp_IO v, Doub_I s)
{ divide_equals_vs(v.p(), s, v.size()); }

inline void operator+=(VecComp_IO v, Comp_I s)
{ plus_equals_vs(v.p(), s, v.size()); }

inline void operator-=(VecComp_IO v, Comp_I s)
{ minus_equals_vs(v.p(), s, v.size()); }

inline void operator*=(VecComp_IO v, Comp_I s)
{ times_equals_vs(v.p(), s, v.size()); }

inline void operator/=(VecComp_IO v, Comp_I s)
{ divide_equals_vs(v.p(), s, v.size()); }

inline void operator+=(SvecDoub_IO v, Doub_I s)
{ plus_equals_vs(v.p(), s, v.size()); }

inline void operator-=(SvecDoub_IO v, Doub_I s)
{ minus_equals_vs(v.p(), s, v.size()); }

inline void operator*=(SvecDoub_IO v, Doub_I s)
{ times_equals_vs(v.p(), s, v.size()); }

inline void operator/=(SvecDoub_IO v, Doub_I s)
{ divide_equals_vs(v.p(), s, v.size()); }

inline void operator+=(DvecComp_IO v, Doub_I s)
{ plus_equals_vs(v.p(), s, v.size(), v.step()); }

inline void operator-=(DvecComp_IO v, Doub_I s)
{ minus_equals_vs(v.p(), s, v.size(), v.step()); }

inline void operator*=(DvecComp_IO v, Doub_I s)
{ times_equals_vs(v.p(), s, v.size(), v.step()); }

inline void operator/=(DvecComp_IO v, Doub_I s)
{ divide_equals_vs(v.p(), s, v.size(), v.step()); }

inline void operator+=(CmatDoub_IO v, Doub_I s)
{ plus_equals_vs(v.p(), s, v.size()); }

inline void operator-=(CmatDoub_IO v, Doub_I s)
{ minus_equals_vs(v.p(), s, v.size()); }

inline void operator*=(CmatDoub_IO v, Doub_I s)
{ times_equals_vs(v.p(), s, v.size()); }

inline void operator/=(CmatDoub_IO v, Doub_I s)
{ divide_equals_vs(v.p(), s, v.size()); }

inline void operator+=(CmatComp_IO v, Doub_I s)
{ plus_equals_vs(v.p(), s, v.size()); }

inline void operator-=(CmatComp_IO v, Doub_I s)
{ minus_equals_vs(v.p(), s, v.size()); }

inline void operator*=(CmatComp_IO v, Doub_I s)
{ times_equals_vs(v.p(), s, v.size()); }

inline void operator/=(CmatComp_IO v, Doub_I s)
{ divide_equals_vs(v.p(), s, v.size()); }

inline void operator+=(CmatComp_IO v, Comp_I s)
{ plus_equals_vs(v.p(), s, v.size()); }

inline void operator-=(CmatComp_IO v, Comp_I s)
{ minus_equals_vs(v.p(), s, v.size()); }

inline void operator*=(CmatComp_IO v, Comp_I s)
{ times_equals_vs(v.p(), s, v.size()); }

inline void operator/=(CmatComp_IO v, Comp_I s)
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

inline void operator+=(DcmatComp_IO v, Comp_I s)
{
    for (Long j = 0; j < v.n1(); ++j)
        plus_equals_vs(&v(0,j), s, v.n0());
}

inline void operator-=(DcmatComp_IO v, Comp_I s)
{
    for (Long j = 0; j < v.n1(); ++j)
        minus_equals_vs(&v(0,j), s, v.n0());
}

inline void operator*=(DcmatComp_IO v, Comp_I s)
{
    for (Long j = 0; j < v.n1(); ++j)
        times_equals_vs(&v(0,j), s, v.n0());
}

inline void operator/=(DcmatComp_IO v, Comp_I s)
{
    for (Long j = 0; j < v.n1(); ++j)
        divide_equals_vs(&v(0,j), s, v.n0());
}

inline void operator+=(SvecComp_IO v, Comp_I s)
{ plus_equals_vs(v.p(), s, v.size()); }

inline void operator-=(SvecComp_IO v, Comp_I s)
{ minus_equals_vs(v.p(), s, v.size()); }

inline void operator*=(SvecComp_IO v, Comp_I s)
{ times_equals_vs(v.p(), s, v.size()); }

inline void operator/=(SvecComp_IO v, Comp_I s)
{ divide_equals_vs(v.p(), s, v.size()); }

inline void operator+=(SvecComp_IO v, Doub_I s)
{ plus_equals_vs(v.p(), s, v.size()); }

inline void operator-=(SvecComp_IO v, Doub_I s)
{ minus_equals_vs(v.p(), s, v.size()); }

inline void operator*=(SvecComp_IO v, Doub_I s)
{ times_equals_vs(v.p(), s, v.size()); }

inline void operator/=(SvecComp_IO v, Doub_I s)
{ divide_equals_vs(v.p(), s, v.size()); }

inline void operator+=(Cmat3Doub_IO v, Doub_I s)
{ plus_equals_vs(v.p(), s, v.size()); }

inline void operator-=(Cmat3Doub_IO v, Doub_I s)
{ minus_equals_vs(v.p(), s, v.size()); }

inline void operator*=(Cmat3Doub_IO v, Doub_I s)
{ times_equals_vs(v.p(), s, v.size()); }

inline void operator/=(Cmat3Doub_IO v, Doub_I s)
{ divide_equals_vs(v.p(), s, v.size()); }

inline void operator+=(Cmat3Comp_IO v, Doub_I s)
{ plus_equals_vs(v.p(), s, v.size()); }

inline void operator-=(Cmat3Comp_IO v, Doub_I s)
{ minus_equals_vs(v.p(), s, v.size()); }

inline void operator*=(Cmat3Comp_IO v, Doub_I s)
{ times_equals_vs(v.p(), s, v.size()); }

inline void operator/=(Cmat3Comp_IO v, Doub_I s)
{ divide_equals_vs(v.p(), s, v.size()); }

inline void operator+=(Cmat3Comp_IO v, Comp_I s)
{ plus_equals_vs(v.p(), s, v.size()); }

inline void operator-=(Cmat3Comp_IO v, Comp_I s)
{ minus_equals_vs(v.p(), s, v.size()); }

inline void operator*=(Cmat3Comp_IO v, Comp_I s)
{ times_equals_vs(v.p(), s, v.size()); }

inline void operator/=(Cmat3Comp_IO v, Comp_I s)
{ divide_equals_vs(v.p(), s, v.size()); }


template <class T>
inline void operator+=(vector<vector<T>> &v, const T &s)
{
    for (auto &v1 : v)
        for (auto &e : v1)
            e += s;
}

template <class T>
inline void operator-=(vector<vector<T>> &v, const T &s)
{
    for (auto &v1 : v)
        for (auto &e : v1)
            e -= s;
}

template <class T>
inline void operator*=(vector<vector<T>> &v, const T &s)
{
    for (auto &v1 : v)
        for (auto &e : v1)
            e *= s;
}

// don't use c++ template for operator/=()

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

inline void plus_equals_vv(Llong *v, const Llong *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] += v1[i];
}

inline void minus_equals_vv(Llong *v, const Llong *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] -= v1[i];
}

inline void times_equals_vv(Llong *v, const Llong *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] *= v1[i];
}

inline void divide_equals_vv(Llong *v, const Llong *v1, Long_I N)
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


inline void operator+=(VecInt_O &v, VecInt_I v1)
{
    assert_same_shape(v, v1);
    plus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator-=(VecInt_O &v, VecInt_I v1)
{
    assert_same_shape(v, v1);
    minus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator*=(VecInt_O &v, VecInt_I v1)
{
    assert_same_shape(v, v1);
    times_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator/=(VecInt_O &v, VecInt_I v1)
{
    assert_same_shape(v, v1);
    divide_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator+=(VecLlong_O &v, VecLlong_I v1)
{
    assert_same_shape(v, v1);
    plus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator-=(VecLlong_O &v, VecLlong_I v1)
{
    assert_same_shape(v, v1);
    minus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator*=(VecLlong_O &v, VecLlong_I v1)
{
    assert_same_shape(v, v1);
    times_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator/=(VecLlong_O &v, VecLlong_I v1)
{
    assert_same_shape(v, v1);
    divide_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator+=(VecDoub_O &v, VecDoub_I v1)
{
    assert_same_shape(v, v1);
    plus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator-=(VecDoub_O &v, VecDoub_I v1)
{
    assert_same_shape(v, v1);
    minus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator*=(VecDoub_O &v, VecDoub_I v1)
{
    assert_same_shape(v, v1);
    times_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator/=(VecDoub_O &v, VecDoub_I v1)
{
    assert_same_shape(v, v1);
    divide_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator+=(VecDoub_O &v, SvecDoub_I v1)
{
    assert_same_shape(v, v1);
    plus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator-=(VecDoub_O &v, SvecDoub_I v1)
{
    assert_same_shape(v, v1);
    minus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator*=(VecDoub_O &v, SvecDoub_I v1)
{
    assert_same_shape(v, v1);
    times_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator/=(VecDoub_O &v, SvecDoub_I v1)
{
    assert_same_shape(v, v1);
    divide_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator+=(VecComp_O &v, VecComp_I v1)
{
    assert_same_shape(v, v1);
    plus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator-=(VecComp_O &v, VecComp_I v1)
{
    assert_same_shape(v, v1);
    minus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator*=(VecComp_O &v, VecComp_I v1)
{
    assert_same_shape(v, v1);
    times_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator/=(VecComp_O &v, VecComp_I v1)
{
    assert_same_shape(v, v1);
    divide_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator+=(VecComp_O &v, VecDoub_I v1)
{
    assert_same_shape(v, v1);
    plus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator-=(VecComp_O &v, VecDoub_I v1)
{
    assert_same_shape(v, v1);
    minus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator*=(VecComp_O &v, VecDoub_I v1)
{
    assert_same_shape(v, v1);
    times_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator/=(VecComp_O &v, VecDoub_I v1)
{
    assert_same_shape(v, v1);
    divide_equals_vv(v.p(), v1.p(), v1.size());
}


inline void operator+=(SvecDoub_O &v, VecDoub_I v1)
{
    assert_same_shape(v, v1);
    plus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator-=(SvecDoub_O &v, VecDoub_I v1)
{
    assert_same_shape(v, v1);
    minus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator*=(SvecDoub_O &v, VecDoub_I v1)
{
    assert_same_shape(v, v1);
    times_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator/=(SvecDoub_O &v, VecDoub_I v1)
{
    assert_same_shape(v, v1);
    divide_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator+=(SvecDoub_O &v, SvecDoub_I v1)
{
    assert_same_shape(v, v1);
    plus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator-=(SvecDoub_O &v, SvecDoub_I v1)
{
    assert_same_shape(v, v1);
    minus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator*=(SvecDoub_O &v, SvecDoub_I v1)
{
    assert_same_shape(v, v1);
    times_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator/=(SvecDoub_O &v, SvecDoub_I v1)
{
    assert_same_shape(v, v1);
    divide_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator+=(SvecComp_O &v, VecDoub_I v1)
{
    assert_same_shape(v, v1);
    plus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator-=(SvecComp_O &v, VecDoub_I v1)
{
    assert_same_shape(v, v1);
    minus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator*=(SvecComp_O &v, VecDoub_I v1)
{
    assert_same_shape(v, v1);
    times_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator/=(SvecComp_O &v, VecDoub_I v1)
{
    assert_same_shape(v, v1);
    divide_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator+=(SvecComp_O &v, SvecComp_I v1)
{
    assert_same_shape(v, v1);
    plus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator-=(SvecComp_O &v, SvecComp_I v1)
{
    assert_same_shape(v, v1);
    minus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator*=(SvecComp_O &v, SvecComp_I v1)
{
    assert_same_shape(v, v1);
    times_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator/=(SvecComp_O &v, SvecComp_I v1)
{
    assert_same_shape(v, v1);
    divide_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator+=(DvecDoub_O &v, SvecDoub_I v1)
{
    assert_same_shape(v, v1);
    for (Long i = 0; i < v.size(); ++i)
        v[i] += v1[i];
}

inline void operator-=(DvecDoub_O &v, SvecDoub_I v1)
{
    assert_same_shape(v, v1);
    for (Long i = 0; i < v.size(); ++i)
        v[i] -= v1[i];
}

inline void operator*=(DvecDoub_O &v, SvecDoub_I v1)
{
    assert_same_shape(v, v1);
    for (Long i = 0; i < v.size(); ++i)
        v[i] *= v1[i];
}

inline void operator/=(DvecDoub_O &v, SvecDoub_I v1)
{
    assert_same_shape(v, v1);
    for (Long i = 0; i < v.size(); ++i)
        v[i] /= v1[i];
}

inline void operator+=(DvecComp_O &v, VecComp_I v1)
{
    assert_same_shape(v, v1);
    for (Long i = 0; i < v.size(); ++i)
        v[i] += v1[i];
}

inline void operator-=(DvecComp_O &v, VecComp_I v1)
{
    assert_same_shape(v, v1);
    for (Long i = 0; i < v.size(); ++i)
        v[i] -= v1[i];
}

inline void operator*=(DvecComp_O &v, VecComp_I v1)
{
    assert_same_shape(v, v1);
    for (Long i = 0; i < v.size(); ++i)
        v[i] *= v1[i];
}

inline void operator/=(DvecComp_O &v, VecComp_I v1)
{
    assert_same_shape(v, v1);
    for (Long i = 0; i < v.size(); ++i)
        v[i] /= v1[i];
}

inline void operator+=(DvecComp_O &v, SvecComp_I v1)
{
    assert_same_shape(v, v1);
    for (Long i = 0; i < v.size(); ++i)
        v[i] += v1[i];
}

inline void operator-=(DvecComp_O &v, SvecComp_I v1)
{
    assert_same_shape(v, v1);
    for (Long i = 0; i < v.size(); ++i)
        v[i] -= v1[i];
}

inline void operator*=(DvecComp_O &v, SvecComp_I v1)
{
    assert_same_shape(v, v1);
    for (Long i = 0; i < v.size(); ++i)
        v[i] *= v1[i];
}

inline void operator/=(DvecComp_O &v, SvecComp_I v1)
{
    assert_same_shape(v, v1);
    for (Long i = 0; i < v.size(); ++i)
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

inline void operator+=(CmatDoub_O &v, CmatDoub_I v1)
{
    assert_same_shape(v, v1);
    plus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator-=(CmatDoub_O &v, CmatDoub_I v1)
{
    assert_same_shape(v, v1);
    minus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator*=(CmatDoub_O &v, CmatDoub_I v1)
{
    assert_same_shape(v, v1);
    times_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator/=(CmatDoub_O &v, CmatDoub_I v1)
{
    assert_same_shape(v, v1);
    divide_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator+=(CmatComp_O &v, CmatDoub_I v1)
{
    assert_same_shape(v, v1);
    plus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator-=(CmatComp_O &v, CmatDoub_I v1)
{
    assert_same_shape(v, v1);
    minus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator*=(CmatComp_O &v, CmatDoub_I v1)
{
    assert_same_shape(v, v1);
    times_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator/=(CmatComp_O &v, CmatDoub_I v1)
{
    assert_same_shape(v, v1);
    divide_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator+=(CmatComp_O &v, CmatComp_I v1)
{
    assert_same_shape(v, v1);
    plus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator-=(CmatComp_O &v, CmatComp_I v1)
{
    assert_same_shape(v, v1);
    minus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator*=(CmatComp_O &v, CmatComp_I v1)
{
    assert_same_shape(v, v1);
    times_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator/=(CmatComp_O &v, CmatComp_I v1)
{
    assert_same_shape(v, v1);
    divide_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator+=(MatDoub_O &v, MatDoub_I v1)
{
    assert_same_shape(v, v1);
    plus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator-=(MatDoub_O &v, MatDoub_I v1)
{
    assert_same_shape(v, v1);
    minus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator*=(MatDoub_O &v, MatDoub_I v1)
{
    assert_same_shape(v, v1);
    times_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator/=(MatDoub_O &v, MatDoub_I v1)
{
    assert_same_shape(v, v1);
    divide_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator+=(MatComp_O &v, MatComp_I v1)
{
    assert_same_shape(v, v1);
    plus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator-=(MatComp_O &v, MatComp_I v1)
{
    assert_same_shape(v, v1);
    minus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator*=(MatComp_O &v, MatComp_I v1)
{
    assert_same_shape(v, v1);
    times_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator/=(MatComp_O &v, MatComp_I v1)
{
    assert_same_shape(v, v1);
    divide_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator+=(ScmatComp_O &v, ScmatDoub_I v1)
{
    assert_same_shape(v, v1);
    plus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator-=(ScmatComp_O &v, ScmatDoub_I v1)
{
    assert_same_shape(v, v1);
    minus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator*=(ScmatComp_O &v, ScmatDoub_I v1)
{
    assert_same_shape(v, v1);
    times_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator/=(ScmatComp_O &v, ScmatDoub_I v1)
{
    assert_same_shape(v, v1);
    divide_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator+=(ScmatComp_O &v, ScmatComp_I v1)
{
    assert_same_shape(v, v1);
    plus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator-=(ScmatComp_O &v, ScmatComp_I v1)
{
    assert_same_shape(v, v1);
    minus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator*=(ScmatComp_O &v, ScmatComp_I v1)
{
    assert_same_shape(v, v1);
    times_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator/=(ScmatComp_O &v, ScmatComp_I v1)
{
    assert_same_shape(v, v1);
    divide_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator+=(DcmatComp_O &v, DcmatDoub_I v1) // slow!
{
    assert_same_shape(v, v1);
    for (Long j = 0; j < v.n1(); ++j)
        for (Long i = 0; i < v.n0(); ++i)
            v(i, j) += v1(i, j);
}

inline void operator-=(DcmatComp_O &v, DcmatDoub_I v1) // slow!
{
    assert_same_shape(v, v1);
    for (Long j = 0; j < v.n1(); ++j)
        for (Long i = 0; i < v.n0(); ++i)
            v(i, j) -= v1(i, j);
}

inline void operator*=(DcmatComp_O &v, DcmatDoub_I v1) // slow!
{
    assert_same_shape(v, v1);
    for (Long j = 0; j < v.n1(); ++j)
        for (Long i = 0; i < v.n0(); ++i)
            v(i, j) *= v1(i, j);
}

inline void operator/=(DcmatComp_O &v, DcmatDoub_I v1) // slow!
{
    assert_same_shape(v, v1);
    for (Long j = 0; j < v.n1(); ++j)
        for (Long i = 0; i < v.n0(); ++i)
            v(i, j) /= v1(i, j);
}

inline void operator+=(Cmat3Comp_O &v, Cmat3Comp_I v1)
{
    assert_same_shape(v, v1);
    plus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator-=(Cmat3Comp_O &v, Cmat3Comp_I v1)
{
    assert_same_shape(v, v1);
    minus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator*=(Cmat3Comp_O &v, Cmat3Comp_I v1)
{
    assert_same_shape(v, v1);
    times_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator/=(Cmat3Comp_O &v, Cmat3Comp_I v1)
{
    assert_same_shape(v, v1);
    divide_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator+=(Mat3Doub_O &v, Mat3Doub_I v1)
{
    assert_same_shape(v, v1);
    plus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator-=(Mat3Doub_O &v, Mat3Doub_I v1)
{
    assert_same_shape(v, v1);
    minus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator*=(Mat3Doub_O &v, Mat3Doub_I v1)
{
    assert_same_shape(v, v1);
    times_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator/=(Mat3Doub_O &v, Mat3Doub_I v1)
{
    assert_same_shape(v, v1);
    divide_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator+=(Mat3Comp_O &v, Mat3Comp_I v1)
{
    assert_same_shape(v, v1);
    plus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator-=(Mat3Comp_O &v, Mat3Comp_I v1)
{
    assert_same_shape(v, v1);
    minus_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator*=(Mat3Comp_O &v, Mat3Comp_I v1)
{
    assert_same_shape(v, v1);
    times_equals_vv(v.p(), v1.p(), v1.size());
}

inline void operator/=(Mat3Comp_O &v, Mat3Comp_I v1)
{
    assert_same_shape(v, v1);
    divide_equals_vv(v.p(), v1.p(), v1.size());
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

inline void plus_vvs(Int *v, const Int *v1, Int_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] + s;
}

inline void plus_vvs(Int *v, const Int *v1, Int_I s, Long_I N, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 + s;
        v += step1; v1 += step2;
    }
}

inline void minus_vvs(Int *v, const Int *v1, Int_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] - s;
}

inline void minus_vvs(Int *v, const Int *v1, Int_I s, Long_I N, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 - s;
        v += step1; v1 += step2;
    }
}

inline void times_vvs(Int *v, const Int *v1, Int_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] * s;
}

inline void times_vvs(Int *v, const Int *v1, Int_I s, Long_I N, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 * s;
        v += step1; v1 += step2;
    }
}

inline void divide_vvs(Int *v, const Int *v1, Int_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] / s;
}

inline void divide_vvs(Int *v, const Int *v1, Int_I s, Long_I N, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 / s;
        v += step1; v1 += step2;
    }
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

inline void plus_vvs(Comp *v, const Doub *v1, Doub_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] + s;
}

inline void plus_vvs(Comp *v, const Doub *v1, Doub_I s, Long_I N, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 + s;
        v += step1; v1 += step2;
    }
}

inline void minus_vvs(Comp *v, const Doub *v1, Doub_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] - s;
}

inline void minus_vvs(Comp *v, const Doub *v1, Doub_I s, Long_I N, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 - s;
        v += step1; v1 += step2;
    }
}

inline void times_vvs(Comp *v, const Doub *v1, Doub_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] * s;
}

inline void times_vvs(Comp *v, const Doub *v1, Doub_I s, Long_I N, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 * s;
        v += step1; v1 += step2;
    }
}

inline void divide_vvs(Comp *v, const Doub *v1, Doub_I s, Long_I N)
{
    Doub inv_s = 1./s;
    times_vvs(v, v1, inv_s, N);
}

inline void divide_vvs(Comp *v, const Doub *v1, Doub_I s, Long_I N, Long_I step, Long_I step1)
{
    Doub inv_s = 1./s;
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

inline void minus_vsv(Int *v, const Int &s, const Int *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = s - v1[i];
}

inline void minus_vsv(Int *v, const Int &s, const Int *v1, Long_I N, Long_I step, Long_I step1)
{
    for (Long i = 0; i < N; ++i) {
        *v = s - *v1;
        v += step; v1 += step1;
    }
}

inline void divide_vsv(Int *v, const Int &s, const Int *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = s / v1[i];
}

inline void divide_vsv(Int *v, const Int &s, const Int *v1, Long_I N, Long_I step, Long_I step1)
{
    for (Long i = 0; i < N; ++i) {
        *v = s / *v1;
        v += step; v1 += step1;
    }
}

inline void minus_vsv(Doub *v, const Doub &s, const Doub *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = s - v1[i];
}

inline void minus_vsv(Doub *v, const Doub &s, const Doub *v1, Long_I N, Long_I step, Long_I step1)
{
    for (Long i = 0; i < N; ++i) {
        *v = s - *v1;
        v += step; v1 += step1;
    }
}

inline void divide_vsv(Doub *v, const Doub &s, const Doub *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = s / v1[i];
}

inline void divide_vsv(Doub *v, const Doub &s, const Doub *v1, Long_I N, Long_I step, Long_I step1)
{
    for (Long i = 0; i < N; ++i) {
        *v = s / *v1;
        v += step; v1 += step1;
    }
}

inline void minus_vsv(Comp *v, const Doub &s, const Doub *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = s - v1[i];
}

inline void minus_vsv(Comp *v, const Doub &s, const Doub *v1, Long_I N, Long_I step, Long_I step1)
{
    for (Long i = 0; i < N; ++i) {
        *v = s - *v1;
        v += step; v1 += step1;
    }
}

inline void divide_vsv(Comp *v, const Doub &s, const Doub *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = s / v1[i];
}

inline void divide_vsv(Comp *v, const Doub &s, const Doub *v1, Long_I N, Long_I step, Long_I step1)
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

inline void minus_vsv(Comp *v, const Comp &s, const Comp *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = s - v1[i];
}

inline void minus_vsv(Comp *v, const Comp &s, const Comp *v1, Long_I N, Long_I step, Long_I step1)
{
    for (Long i = 0; i < N; ++i) {
        *v = s - *v1;
        v += step; v1 += step1;
    }
}

inline void divide_vsv(Comp *v, const Comp &s, const Comp *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = s / v1[i];
}

inline void divide_vsv(Comp *v, const Comp &s, const Comp *v1, Long_I N, Long_I step, Long_I step1)
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

inline void plus_vvv(Int *v, const Int *v1, const Int *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] + v2[i];
}

inline void plus_vvv(Int *v, const Int *v1, const Int *v2, Long_I N, Long_I step, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 + *v2;
        v += step; v1 += step1; v2 += step2;
    }
}

inline void minus_vvv(Int *v, const Int *v1, const Int *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] - v2[i];
}

inline void minus_vvv(Int *v, const Int *v1, const Int *v2, Long_I N, Long_I step, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 - *v2;
        v += step; v1 += step1; v2 += step2;
    }
}

inline void times_vvv(Int *v, const Int *v1, const Int *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] * v2[i];
}

inline void times_vvv(Int *v, const Int *v1, const Int *v2, Long_I N, Long_I step, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 * *v2;
        v += step; v1 += step1; v2 += step2;
    }
}

inline void divide_vvv(Int *v, const Int *v1, const Int *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] / v2[i];
}

inline void divide_vvv(Int *v, const Int *v1, const Int *v2, Long_I N, Long_I step, Long_I step1, Long_I step2)
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


inline void plus(VecInt_O v, VecInt_I v1, Int_I s)
{
    assert_same_shape(v, v1);
    plus_vvs(v.p(), v1.p(), s, v1.size());
}

inline void plus(VecInt_O v, Int_I s, VecInt_I v1)
{ plus(v, v1, s); }

inline void minus(VecInt_O v, VecInt_I v1, Int_I s)
{
    assert_same_shape(v, v1);
    minus_vvs(v.p(), v1.p(), s, v1.size());
}

inline void minus(VecInt_O v, Int_I s, VecInt_I v1)
{
    assert_same_shape(v, v1);
    minus_vsv(v.p(), s, v1.p(), v1.size());
}

inline void times(VecInt_O v, VecInt_I v1, Int_I s)
{
    assert_same_shape(v, v1);
    times_vvs(v.p(), v1.p(), s, v1.size());
}

inline void times(VecInt_O v, Int_I s, VecInt_I v1)
{ times(v, v1, s); }

inline void divide(VecInt_O v, VecInt_I v1, Int_I s)
{
    assert_same_shape(v, v1);
    divide_vvs(v.p(), v1.p(), s, v1.size());
}

inline void divide(VecInt_O v, Int_I s, VecInt_I v1)
{
    assert_same_shape(v, v1);
    divide_vsv(v.p(), s, v1.p(), v1.size());
}

inline void plus(VecDoub_O v, VecDoub_I v1, Doub_I s)
{
    assert_same_shape(v, v1);
    plus_vvs(v.p(), v1.p(), s, v1.size());
}

inline void plus(VecDoub_O v, Doub_I s, VecDoub_I v1)
{ plus(v, v1, s); }

inline void minus(VecDoub_O v, VecDoub_I v1, Doub_I s)
{
    assert_same_shape(v, v1);
    minus_vvs(v.p(), v1.p(), s, v1.size());
}

inline void minus(VecDoub_O v, Doub_I s, VecDoub_I v1)
{
    assert_same_shape(v, v1);
    minus_vsv(v.p(), s, v1.p(), v1.size());
}

inline void times(VecDoub_O v, VecDoub_I v1, Doub_I s)
{
    assert_same_shape(v, v1);
    times_vvs(v.p(), v1.p(), s, v1.size());
}

inline void times(VecDoub_O v, Doub_I s, VecDoub_I v1)
{ times(v, v1, s); }

inline void divide(VecDoub_O v, VecDoub_I v1, Doub_I s)
{
    assert_same_shape(v, v1);
    divide_vvs(v.p(), v1.p(), s, v1.size());
}

inline void divide(VecDoub_O v, Doub_I s, VecDoub_I v1)
{
    assert_same_shape(v, v1);
    divide_vsv(v.p(), s, v1.p(), v1.size());
}

inline void plus(VecComp_O v, SvecDoub_I v1, Doub_I s)
{
    assert_same_shape(v, v1);
    plus_vvs(v.p(), v1.p(), s, v1.size());
}

inline void plus(VecComp_O v, Doub_I s, SvecDoub_I v1)
{ plus(v, v1, s); }

inline void minus(VecComp_O v, SvecDoub_I v1, Doub_I s)
{
    assert_same_shape(v, v1);
    minus_vvs(v.p(), v1.p(), s, v1.size());
}

inline void minus(VecComp_O v, Doub_I s, SvecDoub_I v1)
{
    assert_same_shape(v, v1);
    minus_vsv(v.p(), s, v1.p(), v1.size());
}

inline void times(VecComp_O v, SvecDoub_I v1, Doub_I s)
{
    assert_same_shape(v, v1);
    times_vvs(v.p(), v1.p(), s, v1.size());
}

inline void times(VecComp_O v, Doub_I s, SvecDoub_I v1)
{ times(v, v1, s); }

inline void divide(VecComp_O v, SvecDoub_I v1, Doub_I s)
{
    assert_same_shape(v, v1);
    divide_vvs(v.p(), v1.p(), s, v1.size());
}

inline void divide(VecComp_O v, Doub_I s, SvecDoub_I v1)
{
    assert_same_shape(v, v1);
    divide_vsv(v.p(), s, v1.p(), v1.size());
}

inline void plus(VecComp_O v, SvecDoub_I v1, Imag_I s)
{
    assert_same_shape(v, v1);
    plus_vvs(v.p(), v1.p(), s, v1.size());
}

inline void plus(VecComp_O v, Imag_I s, SvecDoub_I v1)
{ plus(v, v1, s); }

inline void minus(VecComp_O v, SvecDoub_I v1, Imag_I s)
{
    assert_same_shape(v, v1);
    minus_vvs(v.p(), v1.p(), s, v1.size());
}

inline void minus(VecComp_O v, Imag_I s, SvecDoub_I v1)
{
    assert_same_shape(v, v1);
    minus_vsv(v.p(), s, v1.p(), v1.size());
}

inline void times(VecComp_O v, SvecDoub_I v1, Imag_I s)
{
    assert_same_shape(v, v1);
    times_vvs(v.p(), v1.p(), s, v1.size());
}

inline void times(VecComp_O v, Imag_I s, SvecDoub_I v1)
{ times(v, v1, s); }

inline void divide(VecComp_O v, SvecDoub_I v1, Imag_I s)
{
    assert_same_shape(v, v1);
    divide_vvs(v.p(), v1.p(), s, v1.size());
}

inline void divide(VecComp_O v, Imag_I s, SvecDoub_I v1)
{
    assert_same_shape(v, v1);
    divide_vsv(v.p(), s, v1.p(), v1.size());
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

inline void plus(VecComp_O v, VecComp_I v1, Comp_I s)
{
    assert_same_shape(v, v1);
    plus_vvs(v.p(), v1.p(), s, v1.size());
}

inline void plus(VecComp_O v, Comp_I s, VecComp_I v1)
{ plus(v, v1, s); }

inline void minus(VecComp_O v, VecComp_I v1, Comp_I s)
{
    assert_same_shape(v, v1);
    minus_vvs(v.p(), v1.p(), s, v1.size());
}

inline void minus(VecComp_O v, Comp_I s, VecComp_I v1)
{
    assert_same_shape(v, v1);
    minus_vsv(v.p(), s, v1.p(), v1.size());
}

inline void times(VecComp_O v, VecComp_I v1, Comp_I s)
{
    assert_same_shape(v, v1);
    times_vvs(v.p(), v1.p(), s, v1.size());
}

inline void times(VecComp_O v, Comp_I s, VecComp_I v1)
{ times(v, v1, s); }

inline void divide(VecComp_O v, VecComp_I v1, Comp_I s)
{
    assert_same_shape(v, v1);
    divide_vvs(v.p(), v1.p(), s, v1.size());
}

inline void divide(VecComp_O v, Comp_I s, VecComp_I v1)
{
    assert_same_shape(v, v1);
    divide_vsv(v.p(), s, v1.p(), v1.size());
}

inline void plus(SvecComp_O v, SvecComp_I v1, Doub_I s)
{
    assert_same_shape(v, v1);
    plus_vvs(v.p(), v1.p(), s, v1.size());
}

inline void plus(SvecComp_O v, Doub_I s, SvecComp_I v1)
{ plus(v, v1, s); }

inline void minus(SvecComp_O v, SvecComp_I v1, Doub_I s)
{
    assert_same_shape(v, v1);
    minus_vvs(v.p(), v1.p(), s, v1.size());
}

inline void minus(SvecComp_O v, Doub_I s, SvecComp_I v1)
{
    assert_same_shape(v, v1);
    minus_vsv(v.p(), s, v1.p(), v1.size());
}

inline void times(SvecComp_O v, SvecComp_I v1, Doub_I s)
{
    assert_same_shape(v, v1);
    times_vvs(v.p(), v1.p(), s, v1.size());
}

inline void times(SvecComp_O v, Doub_I s, SvecComp_I v1)
{ times(v, v1, s); }

inline void divide(SvecComp_O v, SvecComp_I v1, Doub_I s)
{
    assert_same_shape(v, v1);
    divide_vvs(v.p(), v1.p(), s, v1.size());
}

inline void divide(SvecComp_O v, Doub_I s, SvecComp_I v1)
{
    assert_same_shape(v, v1);
    divide_vsv(v.p(), s, v1.p(), v1.size());
}

inline void plus(DcmatComp_O v, DcmatComp_I v1, Doub_I s)
{
    assert_same_shape(v, v1);
    Comp *p = v.p(); const Comp *p1 = v1.p();
    for (Long j = 0; j < v.n1(); ++j) {
        plus_vvs(p, p1, s, v.n0());
        p += v.lda(); p1 += v1.lda();
    }
}

inline void plus(DcmatComp_O v, Doub_I s, DcmatComp_I v1)
{ plus(v, v1, s); }

inline void minus(DcmatComp_O v, DcmatComp_I v1, Doub_I s)
{
    assert_same_shape(v, v1);
    Comp *p = v.p(); const Comp *p1 = v1.p();
    for (Long j = 0; j < v.n1(); ++j) {
        minus_vvs(p, p1, s, v.n0());
        p += v.lda(); p1 += v1.lda();
    }
}

inline void minus(DcmatComp_O v, Doub_I s, DcmatComp_I v1)
{
    assert_same_shape(v, v1);
    Comp *p = v.p(); const Comp *p1 = v1.p();
    for (Long j = 0; j < v.n1(); ++j) {
        minus_vsv(p, s, p1, v.n0());
        p += v.lda(); p1 += v1.lda();
    }
}

inline void times(DcmatComp_O v, DcmatComp_I v1, Doub_I s)
{
    assert_same_shape(v, v1);
    Comp *p = v.p(); const Comp *p1 = v1.p();
    for (Long j = 0; j < v.n1(); ++j) {
        times_vvs(p, p1, s, v.n0());
        p += v.lda(); p1 += v1.lda();
    }
}

inline void times(DcmatComp_O v, Doub_I s, DcmatComp_I v1)
{ times(v, v1, s); }

inline void divide(DcmatComp_O v, DcmatComp_I v1, Doub_I s)
{
    assert_same_shape(v, v1);
    Comp *p = v.p(); const Comp *p1 = v1.p();
    for (Long j = 0; j < v.n1(); ++j) {
        divide_vvs(p, p1, s, v.n0());
        p += v.lda(); p1 += v1.lda();
    }
}

inline void divide(DcmatComp_O v, const Doub_I s, DcmatComp_I v1)
{
    assert_same_shape(v, v1);
    Comp *p = v.p(); const Comp *p1 = v1.p();
    for (Long j = 0; j < v.n1(); ++j) {
        divide_vsv(p, s, p1, v.n0());
        p += v.lda(); p1 += v1.lda();
    }
}

inline void plus(VecComp_O v, VecDoub_I v1, Comp_I s)
{
    assert_same_shape(v, v1);
    plus_vvs(v.p(), v1.p(), s, v1.size());
}

inline void plus(VecComp_O v, Comp_I s, VecDoub_I v1)
{ plus(v, v1, s); }

inline void minus(VecComp_O v, VecDoub_I v1, Comp_I s)
{
    assert_same_shape(v, v1);
    minus_vvs(v.p(), v1.p(), s, v1.size());
}

inline void minus(VecComp_O v, Comp_I s, VecDoub_I v1)
{
    assert_same_shape(v, v1);
    minus_vsv(v.p(), s, v1.p(), v1.size());
}

inline void times(VecComp_O v, VecDoub_I v1, Comp_I s)
{
    assert_same_shape(v, v1);
    times_vvs(v.p(), v1.p(), s, v1.size());
}

inline void times(VecComp_O v, Comp_I s, VecDoub_I v1)
{ times(v, v1, s); }

inline void divide(VecComp_O v, VecDoub_I v1, Comp_I s)
{
    assert_same_shape(v, v1);
    divide_vvs(v.p(), v1.p(), s, v1.size());
}

inline void divide(VecComp_O v, Comp_I s, VecDoub_I v1)
{
    assert_same_shape(v, v1);
    divide_vsv(v.p(), s, v1.p(), v1.size());
}

inline void plus(SvecComp_O v, VecComp_I v1, Doub_I s)
{
    assert_same_shape(v, v1);
    plus_vvs(v.p(), v1.p(), s, v1.size());
}

inline void plus(SvecComp_O v, Doub_I s, VecComp_I v1)
{ plus(v, v1, s); }

inline void minus(SvecComp_O v, VecComp_I v1, Doub_I s)
{
    assert_same_shape(v, v1);
    minus_vvs(v.p(), v1.p(), s, v1.size());
}

inline void minus(SvecComp_O v, Doub_I s, VecComp_I v1)
{
    assert_same_shape(v, v1);
    minus_vsv(v.p(), s, v1.p(), v1.size());
}

inline void times(SvecComp_O v, VecComp_I v1, Doub_I s)
{
    assert_same_shape(v, v1);
    times_vvs(v.p(), v1.p(), s, v1.size());
}

inline void times(SvecComp_O v, Doub_I s, VecComp_I v1)
{ times(v, v1, s); }

inline void divide(SvecComp_O v, VecComp_I v1, Doub_I s)
{
    assert_same_shape(v, v1);
    divide_vvs(v.p(), v1.p(), s, v1.size());
}

inline void divide(SvecComp_O v, Doub_I s, VecComp_I v1)
{
    assert_same_shape(v, v1);
    divide_vsv(v.p(), s, v1.p(), v1.size());
}

inline void plus(SvecComp_O v, DvecComp_I v1, Doub_I s)
{
    assert_same_shape(v, v1);
    plus_vvs(v.p(), v1.p(), s, v1.size(), 1, v1.step());
}

inline void plus(SvecComp_O v, Doub_I s, DvecComp_I v1)
{ plus(v, v1, s); }

inline void minus(SvecComp_O v, DvecComp_I v1, Doub_I s)
{
    assert_same_shape(v, v1);
    minus_vvs(v.p(), v1.p(), s, v1.size(), 1, v1.step());
}

inline void minus(SvecComp_O v, Doub_I s, DvecComp_I v1)
{
    assert_same_shape(v, v1);
    minus_vsv(v.p(), s, v1.p(), v1.size(), 1, v1.step());
}

inline void times(SvecComp_O v, DvecComp_I v1, Doub_I s)
{
    assert_same_shape(v, v1);
    times_vvs(v.p(), v1.p(), s, v1.size(), 1, v1.step());
}

inline void times(SvecComp_O v, Doub_I s, DvecComp_I v1)
{ times(v, v1, s); }

inline void divide(SvecComp_O v, DvecComp_I v1, Doub_I s)
{
    assert_same_shape(v, v1);
    divide_vvs(v.p(), v1.p(), s, v1.size(), 1, v1.step());
}

inline void divide(SvecComp_O v, Doub_I s, DvecComp_I v1)
{
    assert_same_shape(v, v1);
    divide_vsv(v.p(), s, v1.p(), v1.size(), 1, v1.step());
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


inline void plus(VecInt_O v, VecInt_I v1, VecInt_I v2)
{
    assert_same_shape(v, v1, v2);
    plus_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void minus(VecInt_O v, VecInt_I v1, VecInt_I v2)
{
    assert_same_shape(v, v1, v2);
    minus_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void times(VecInt_O v, VecInt_I v1, VecInt_I v2)
{
    assert_same_shape(v, v1, v2);
    times_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void divide(VecInt_O v, VecInt_I v1, VecInt_I v2)
{
    assert_same_shape(v, v1, v2);
    divide_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void plus(VecDoub_O v, VecDoub_I v1, VecDoub_I v2)
{
    assert_same_shape(v, v1, v2);
    plus_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void minus(VecDoub_O v, VecDoub_I v1, VecDoub_I v2)
{
    assert_same_shape(v, v1, v2);
    minus_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void times(VecDoub_O v, VecDoub_I v1, VecDoub_I v2)
{
    assert_same_shape(v, v1, v2);
    times_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void divide(VecDoub_O v, VecDoub_I v1, VecDoub_I v2)
{
    assert_same_shape(v, v1, v2);
    divide_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void plus(VecComp_O v, VecComp_I v1, VecComp_I v2)
{
    assert_same_shape(v, v1, v2);
    plus_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void minus(VecComp_O v, VecComp_I v1, VecComp_I v2)
{
    assert_same_shape(v, v1, v2);
    minus_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void times(VecComp_O v, VecComp_I v1, VecComp_I v2)
{
    assert_same_shape(v, v1, v2);
    times_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void divide(VecComp_O v, VecComp_I v1, VecComp_I v2)
{
    assert_same_shape(v, v1, v2);
    divide_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void plus(SvecComp_O v, VecComp_I v1, SvecComp_I v2)
{
    assert_same_shape(v, v1, v2);
    plus_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void minus(SvecComp_O v, VecComp_I v1, SvecComp_I v2)
{
    assert_same_shape(v, v1, v2);
    minus_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void times(SvecComp_O v, VecComp_I v1, SvecComp_I v2)
{
    assert_same_shape(v, v1, v2);
    times_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void divide(SvecComp_O v, VecComp_I v1, SvecComp_I v2)
{
    assert_same_shape(v, v1, v2);
    divide_vvv(v.p(), v1.p(), v2.p(), v.size());
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

inline void plus(SvecDoub_O v, VecDoub_I v1, SvecDoub_I v2)
{
    assert_same_shape(v, v1, v2);
    plus_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void minus(SvecDoub_O v, VecDoub_I v1, SvecDoub_I v2)
{
    assert_same_shape(v, v1, v2);
    minus_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void times(SvecDoub_O v, VecDoub_I v1, SvecDoub_I v2)
{
    assert_same_shape(v, v1, v2);
    times_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void divide(SvecDoub_O v, VecDoub_I v1, SvecDoub_I v2)
{
    assert_same_shape(v, v1, v2);
    divide_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void plus(SvecComp_O v, SvecComp_I v1, SvecComp_I v2)
{
    assert_same_shape(v, v1, v2);
    plus_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void minus(SvecComp_O v, SvecComp_I v1, SvecComp_I v2)
{
    assert_same_shape(v, v1, v2);
    minus_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void times(SvecComp_O v, SvecComp_I v1, SvecComp_I v2)
{
    assert_same_shape(v, v1, v2);
    times_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void divide(SvecComp_O v, SvecComp_I v1, SvecComp_I v2)
{
    assert_same_shape(v, v1, v2);
    divide_vvv(v.p(), v1.p(), v2.p(), v.size());
}


inline void minus_vv(Comp *v, const Doub *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = -v1[i];
}

inline void minus_vv(Llong *v, const Llong *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = -v1[i];
}

inline void minus_vv(Doub *v, const Doub *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = -v1[i];
}

inline void minus_vv(Comp *v, const Comp *v1, Long_I N)
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


} // namespace slisc
