// element-wise +, -, *, /
#pragma once
#include "scalar_arith.h"
#include "compare.h"

namespace slisc {

inline void add_eq_vs(Int *v, Int_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] += s;
}

inline void add_eq_vs(Int *v, Int_I s, Long_I N, Long step)
{
    for (Long i = 0; i < N*step; i += step)
        v[i] += s;
}

inline void sub_eq_vs(Int *v, Int_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] -= s;
}

inline void sub_eq_vs(Int *v, Int_I s, Long_I N, Long step)
{
    for (Long i = 0; i < N*step; i += step)
        v[i] -= s;
}

inline void mul_eq_vs(Int *v, Int_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] *= s;
}

inline void mul_eq_vs(Int *v, Int_I s, Long_I N, Long step)
{
    for (Long i = 0; i < N*step; i += step)
        v[i] *= s;
}
inline void div_eq_vs(Int *v, Int_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] /= s;
}

inline void div_eq_vs(Int *v, Int_I s, Long_I N, Long_I step)
{
    for (Long i = 0; i < N*step; i += step)
        v[i] /= s;
}

inline void add_eq_vs(Llong *v, Llong_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] += s;
}

inline void add_eq_vs(Llong *v, Llong_I s, Long_I N, Long step)
{
    for (Long i = 0; i < N*step; i += step)
        v[i] += s;
}

inline void sub_eq_vs(Llong *v, Llong_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] -= s;
}

inline void sub_eq_vs(Llong *v, Llong_I s, Long_I N, Long step)
{
    for (Long i = 0; i < N*step; i += step)
        v[i] -= s;
}

inline void mul_eq_vs(Llong *v, Llong_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] *= s;
}

inline void mul_eq_vs(Llong *v, Llong_I s, Long_I N, Long step)
{
    for (Long i = 0; i < N*step; i += step)
        v[i] *= s;
}
inline void div_eq_vs(Llong *v, Llong_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] /= s;
}

inline void div_eq_vs(Llong *v, Llong_I s, Long_I N, Long_I step)
{
    for (Long i = 0; i < N*step; i += step)
        v[i] /= s;
}

inline void add_eq_vs(Doub *v, Doub_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] += s;
}

inline void add_eq_vs(Doub *v, Doub_I s, Long_I N, Long step)
{
    for (Long i = 0; i < N*step; i += step)
        v[i] += s;
}

inline void sub_eq_vs(Doub *v, Doub_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] -= s;
}

inline void sub_eq_vs(Doub *v, Doub_I s, Long_I N, Long step)
{
    for (Long i = 0; i < N*step; i += step)
        v[i] -= s;
}

inline void mul_eq_vs(Doub *v, Doub_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] *= s;
}

inline void mul_eq_vs(Doub *v, Doub_I s, Long_I N, Long step)
{
    for (Long i = 0; i < N*step; i += step)
        v[i] *= s;
}
inline void div_eq_vs(Doub *v, Doub_I s, Long_I N)
{ mul_eq_vs(v, 1./s, N); }

inline void div_eq_vs(Doub *v, Doub_I s, Long_I N, Long_I step)
{ mul_eq_vs(v, 1./s, N, step); }

inline void add_eq_vs(Comp *v, Doub_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] += s;
}

inline void add_eq_vs(Comp *v, Doub_I s, Long_I N, Long step)
{
    for (Long i = 0; i < N*step; i += step)
        v[i] += s;
}

inline void sub_eq_vs(Comp *v, Doub_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] -= s;
}

inline void sub_eq_vs(Comp *v, Doub_I s, Long_I N, Long step)
{
    for (Long i = 0; i < N*step; i += step)
        v[i] -= s;
}

inline void mul_eq_vs(Comp *v, Doub_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] *= s;
}

inline void mul_eq_vs(Comp *v, Doub_I s, Long_I N, Long step)
{
    for (Long i = 0; i < N*step; i += step)
        v[i] *= s;
}
inline void div_eq_vs(Comp *v, Doub_I s, Long_I N)
{ mul_eq_vs(v, 1./s, N); }

inline void div_eq_vs(Comp *v, Doub_I s, Long_I N, Long_I step)
{ mul_eq_vs(v, 1./s, N, step); }

inline void add_eq_vs(Comp *v, Comp_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] += s;
}

inline void add_eq_vs(Comp *v, Comp_I s, Long_I N, Long step)
{
    for (Long i = 0; i < N*step; i += step)
        v[i] += s;
}

inline void sub_eq_vs(Comp *v, Comp_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] -= s;
}

inline void sub_eq_vs(Comp *v, Comp_I s, Long_I N, Long step)
{
    for (Long i = 0; i < N*step; i += step)
        v[i] -= s;
}

inline void mul_eq_vs(Comp *v, Comp_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] *= s;
}

inline void mul_eq_vs(Comp *v, Comp_I s, Long_I N, Long step)
{
    for (Long i = 0; i < N*step; i += step)
        v[i] *= s;
}
inline void div_eq_vs(Comp *v, Comp_I s, Long_I N)
{ mul_eq_vs(v, 1./s, N); }

inline void div_eq_vs(Comp *v, Comp_I s, Long_I N, Long_I step)
{ mul_eq_vs(v, 1./s, N, step); }

inline void add_eq_vs(Comp *v, Imag_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] += s;
}

inline void add_eq_vs(Comp *v, Imag_I s, Long_I N, Long step)
{
    for (Long i = 0; i < N*step; i += step)
        v[i] += s;
}

inline void sub_eq_vs(Comp *v, Imag_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] -= s;
}

inline void sub_eq_vs(Comp *v, Imag_I s, Long_I N, Long step)
{
    for (Long i = 0; i < N*step; i += step)
        v[i] -= s;
}

inline void mul_eq_vs(Comp *v, Imag_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] *= s;
}

inline void mul_eq_vs(Comp *v, Imag_I s, Long_I N, Long step)
{
    for (Long i = 0; i < N*step; i += step)
        v[i] *= s;
}
inline void div_eq_vs(Comp *v, Imag_I s, Long_I N)
{ mul_eq_vs(v, 1./s, N); }

inline void div_eq_vs(Comp *v, Imag_I s, Long_I N, Long_I step)
{ mul_eq_vs(v, 1./s, N, step); }


inline void operator+=(vecInt_IO v, Int_I s)
{ add_eq_vs(v.data(), s, v.size()); }

inline void operator-=(vecInt_IO v, Int_I s)
{ sub_eq_vs(v.data(), s, v.size()); }

inline void operator*=(vecInt_IO v, Int_I s)
{ mul_eq_vs(v.data(), s, v.size()); }

inline void operator/=(vecInt_IO v, Int_I s)
{ div_eq_vs(v.data(), s, v.size()); }

inline void operator+=(vecLlong_IO v, Llong_I s)
{ add_eq_vs(v.data(), s, v.size()); }

inline void operator-=(vecLlong_IO v, Llong_I s)
{ sub_eq_vs(v.data(), s, v.size()); }

inline void operator*=(vecLlong_IO v, Llong_I s)
{ mul_eq_vs(v.data(), s, v.size()); }

inline void operator/=(vecLlong_IO v, Llong_I s)
{ div_eq_vs(v.data(), s, v.size()); }

inline void operator+=(VecInt_IO v, Int_I s)
{ add_eq_vs(v.p(), s, v.size()); }

inline void operator-=(VecInt_IO v, Int_I s)
{ sub_eq_vs(v.p(), s, v.size()); }

inline void operator*=(VecInt_IO v, Int_I s)
{ mul_eq_vs(v.p(), s, v.size()); }

inline void operator/=(VecInt_IO v, Int_I s)
{ div_eq_vs(v.p(), s, v.size()); }

inline void operator+=(VecLlong_IO v, Llong_I s)
{ add_eq_vs(v.p(), s, v.size()); }

inline void operator-=(VecLlong_IO v, Llong_I s)
{ sub_eq_vs(v.p(), s, v.size()); }

inline void operator*=(VecLlong_IO v, Llong_I s)
{ mul_eq_vs(v.p(), s, v.size()); }

inline void operator/=(VecLlong_IO v, Llong_I s)
{ div_eq_vs(v.p(), s, v.size()); }

inline void operator+=(VecDoub_IO v, Doub_I s)
{ add_eq_vs(v.p(), s, v.size()); }

inline void operator-=(VecDoub_IO v, Doub_I s)
{ sub_eq_vs(v.p(), s, v.size()); }

inline void operator*=(VecDoub_IO v, Doub_I s)
{ mul_eq_vs(v.p(), s, v.size()); }

inline void operator/=(VecDoub_IO v, Doub_I s)
{ div_eq_vs(v.p(), s, v.size()); }

inline void operator+=(VecComp_IO v, Doub_I s)
{ add_eq_vs(v.p(), s, v.size()); }

inline void operator-=(VecComp_IO v, Doub_I s)
{ sub_eq_vs(v.p(), s, v.size()); }

inline void operator*=(VecComp_IO v, Doub_I s)
{ mul_eq_vs(v.p(), s, v.size()); }

inline void operator/=(VecComp_IO v, Doub_I s)
{ div_eq_vs(v.p(), s, v.size()); }

inline void operator+=(VecComp_IO v, Comp_I s)
{ add_eq_vs(v.p(), s, v.size()); }

inline void operator-=(VecComp_IO v, Comp_I s)
{ sub_eq_vs(v.p(), s, v.size()); }

inline void operator*=(VecComp_IO v, Comp_I s)
{ mul_eq_vs(v.p(), s, v.size()); }

inline void operator/=(VecComp_IO v, Comp_I s)
{ div_eq_vs(v.p(), s, v.size()); }

inline void operator+=(SvecDoub_IO v, Doub_I s)
{ add_eq_vs(v.p(), s, v.size()); }

inline void operator-=(SvecDoub_IO v, Doub_I s)
{ sub_eq_vs(v.p(), s, v.size()); }

inline void operator*=(SvecDoub_IO v, Doub_I s)
{ mul_eq_vs(v.p(), s, v.size()); }

inline void operator/=(SvecDoub_IO v, Doub_I s)
{ div_eq_vs(v.p(), s, v.size()); }

inline void operator+=(DvecComp_IO v, Doub_I s)
{ add_eq_vs(v.p(), s, v.size(), v.step()); }

inline void operator-=(DvecComp_IO v, Doub_I s)
{ sub_eq_vs(v.p(), s, v.size(), v.step()); }

inline void operator*=(DvecComp_IO v, Doub_I s)
{ mul_eq_vs(v.p(), s, v.size(), v.step()); }

inline void operator/=(DvecComp_IO v, Doub_I s)
{ div_eq_vs(v.p(), s, v.size(), v.step()); }

inline void operator+=(CmatDoub_IO v, Doub_I s)
{ add_eq_vs(v.p(), s, v.size()); }

inline void operator-=(CmatDoub_IO v, Doub_I s)
{ sub_eq_vs(v.p(), s, v.size()); }

inline void operator*=(CmatDoub_IO v, Doub_I s)
{ mul_eq_vs(v.p(), s, v.size()); }

inline void operator/=(CmatDoub_IO v, Doub_I s)
{ div_eq_vs(v.p(), s, v.size()); }

inline void operator+=(CmatComp_IO v, Doub_I s)
{ add_eq_vs(v.p(), s, v.size()); }

inline void operator-=(CmatComp_IO v, Doub_I s)
{ sub_eq_vs(v.p(), s, v.size()); }

inline void operator*=(CmatComp_IO v, Doub_I s)
{ mul_eq_vs(v.p(), s, v.size()); }

inline void operator/=(CmatComp_IO v, Doub_I s)
{ div_eq_vs(v.p(), s, v.size()); }

inline void operator+=(CmatComp_IO v, Comp_I s)
{ add_eq_vs(v.p(), s, v.size()); }

inline void operator-=(CmatComp_IO v, Comp_I s)
{ sub_eq_vs(v.p(), s, v.size()); }

inline void operator*=(CmatComp_IO v, Comp_I s)
{ mul_eq_vs(v.p(), s, v.size()); }

inline void operator/=(CmatComp_IO v, Comp_I s)
{ div_eq_vs(v.p(), s, v.size()); }

inline void operator+=(DcmatComp_IO v, Doub_I s)
{
    for (Long j = 0; j < v.n1(); ++j)
        add_eq_vs(&v(0,j), s, v.n0());
}

inline void operator-=(DcmatComp_IO v, Doub_I s)
{
    for (Long j = 0; j < v.n1(); ++j)
        sub_eq_vs(&v(0,j), s, v.n0());
}

inline void operator*=(DcmatComp_IO v, Doub_I s)
{
    for (Long j = 0; j < v.n1(); ++j)
        mul_eq_vs(&v(0,j), s, v.n0());
}

inline void operator/=(DcmatComp_IO v, Doub_I s)
{
    for (Long j = 0; j < v.n1(); ++j)
        div_eq_vs(&v(0,j), s, v.n0());
}

inline void operator+=(DcmatComp_IO v, Comp_I s)
{
    for (Long j = 0; j < v.n1(); ++j)
        add_eq_vs(&v(0,j), s, v.n0());
}

inline void operator-=(DcmatComp_IO v, Comp_I s)
{
    for (Long j = 0; j < v.n1(); ++j)
        sub_eq_vs(&v(0,j), s, v.n0());
}

inline void operator*=(DcmatComp_IO v, Comp_I s)
{
    for (Long j = 0; j < v.n1(); ++j)
        mul_eq_vs(&v(0,j), s, v.n0());
}

inline void operator/=(DcmatComp_IO v, Comp_I s)
{
    for (Long j = 0; j < v.n1(); ++j)
        div_eq_vs(&v(0,j), s, v.n0());
}

inline void operator+=(SvecComp_IO v, Comp_I s)
{ add_eq_vs(v.p(), s, v.size()); }

inline void operator-=(SvecComp_IO v, Comp_I s)
{ sub_eq_vs(v.p(), s, v.size()); }

inline void operator*=(SvecComp_IO v, Comp_I s)
{ mul_eq_vs(v.p(), s, v.size()); }

inline void operator/=(SvecComp_IO v, Comp_I s)
{ div_eq_vs(v.p(), s, v.size()); }

inline void operator+=(SvecComp_IO v, Doub_I s)
{ add_eq_vs(v.p(), s, v.size()); }

inline void operator-=(SvecComp_IO v, Doub_I s)
{ sub_eq_vs(v.p(), s, v.size()); }

inline void operator*=(SvecComp_IO v, Doub_I s)
{ mul_eq_vs(v.p(), s, v.size()); }

inline void operator/=(SvecComp_IO v, Doub_I s)
{ div_eq_vs(v.p(), s, v.size()); }

inline void operator+=(Cmat3Doub_IO v, Doub_I s)
{ add_eq_vs(v.p(), s, v.size()); }

inline void operator-=(Cmat3Doub_IO v, Doub_I s)
{ sub_eq_vs(v.p(), s, v.size()); }

inline void operator*=(Cmat3Doub_IO v, Doub_I s)
{ mul_eq_vs(v.p(), s, v.size()); }

inline void operator/=(Cmat3Doub_IO v, Doub_I s)
{ div_eq_vs(v.p(), s, v.size()); }

inline void operator+=(Cmat3Comp_IO v, Doub_I s)
{ add_eq_vs(v.p(), s, v.size()); }

inline void operator-=(Cmat3Comp_IO v, Doub_I s)
{ sub_eq_vs(v.p(), s, v.size()); }

inline void operator*=(Cmat3Comp_IO v, Doub_I s)
{ mul_eq_vs(v.p(), s, v.size()); }

inline void operator/=(Cmat3Comp_IO v, Doub_I s)
{ div_eq_vs(v.p(), s, v.size()); }

inline void operator+=(Cmat3Comp_IO v, Comp_I s)
{ add_eq_vs(v.p(), s, v.size()); }

inline void operator-=(Cmat3Comp_IO v, Comp_I s)
{ sub_eq_vs(v.p(), s, v.size()); }

inline void operator*=(Cmat3Comp_IO v, Comp_I s)
{ mul_eq_vs(v.p(), s, v.size()); }

inline void operator/=(Cmat3Comp_IO v, Comp_I s)
{ div_eq_vs(v.p(), s, v.size()); }


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

inline void add_eq_vv(Comp *v, const Doub *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] += v1[i];
}

inline void sub_eq_vv(Comp *v, const Doub *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] -= v1[i];
}

inline void mul_eq_vv(Comp *v, const Doub *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] *= v1[i];
}

inline void div_eq_vv(Comp *v, const Doub *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] /= v1[i];
}

inline void add_eq_vv(Int *v, const Int *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] += v1[i];
}

inline void sub_eq_vv(Int *v, const Int *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] -= v1[i];
}

inline void mul_eq_vv(Int *v, const Int *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] *= v1[i];
}

inline void div_eq_vv(Int *v, const Int *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] /= v1[i];
}

inline void add_eq_vv(Llong *v, const Llong *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] += v1[i];
}

inline void sub_eq_vv(Llong *v, const Llong *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] -= v1[i];
}

inline void mul_eq_vv(Llong *v, const Llong *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] *= v1[i];
}

inline void div_eq_vv(Llong *v, const Llong *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] /= v1[i];
}

inline void add_eq_vv(Doub *v, const Doub *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] += v1[i];
}

inline void sub_eq_vv(Doub *v, const Doub *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] -= v1[i];
}

inline void mul_eq_vv(Doub *v, const Doub *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] *= v1[i];
}

inline void div_eq_vv(Doub *v, const Doub *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] /= v1[i];
}

inline void add_eq_vv(Comp *v, const Comp *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] += v1[i];
}

inline void sub_eq_vv(Comp *v, const Comp *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] -= v1[i];
}

inline void mul_eq_vv(Comp *v, const Comp *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] *= v1[i];
}

inline void div_eq_vv(Comp *v, const Comp *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] /= v1[i];
}


inline void operator+=(VecInt_O &v, VecInt_I v1)
{
    assert_same_shape(v, v1);
    add_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator-=(VecInt_O &v, VecInt_I v1)
{
    assert_same_shape(v, v1);
    sub_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator*=(VecInt_O &v, VecInt_I v1)
{
    assert_same_shape(v, v1);
    mul_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator/=(VecInt_O &v, VecInt_I v1)
{
    assert_same_shape(v, v1);
    div_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator+=(VecLlong_O &v, VecLlong_I v1)
{
    assert_same_shape(v, v1);
    add_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator-=(VecLlong_O &v, VecLlong_I v1)
{
    assert_same_shape(v, v1);
    sub_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator*=(VecLlong_O &v, VecLlong_I v1)
{
    assert_same_shape(v, v1);
    mul_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator/=(VecLlong_O &v, VecLlong_I v1)
{
    assert_same_shape(v, v1);
    div_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator+=(VecDoub_O &v, VecDoub_I v1)
{
    assert_same_shape(v, v1);
    add_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator-=(VecDoub_O &v, VecDoub_I v1)
{
    assert_same_shape(v, v1);
    sub_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator*=(VecDoub_O &v, VecDoub_I v1)
{
    assert_same_shape(v, v1);
    mul_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator/=(VecDoub_O &v, VecDoub_I v1)
{
    assert_same_shape(v, v1);
    div_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator+=(VecDoub_O &v, SvecDoub_I v1)
{
    assert_same_shape(v, v1);
    add_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator-=(VecDoub_O &v, SvecDoub_I v1)
{
    assert_same_shape(v, v1);
    sub_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator*=(VecDoub_O &v, SvecDoub_I v1)
{
    assert_same_shape(v, v1);
    mul_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator/=(VecDoub_O &v, SvecDoub_I v1)
{
    assert_same_shape(v, v1);
    div_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator+=(VecComp_O &v, VecComp_I v1)
{
    assert_same_shape(v, v1);
    add_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator-=(VecComp_O &v, VecComp_I v1)
{
    assert_same_shape(v, v1);
    sub_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator*=(VecComp_O &v, VecComp_I v1)
{
    assert_same_shape(v, v1);
    mul_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator/=(VecComp_O &v, VecComp_I v1)
{
    assert_same_shape(v, v1);
    div_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator+=(VecComp_O &v, SvecComp_I v1)
{
    assert_same_shape(v, v1);
    add_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator-=(VecComp_O &v, SvecComp_I v1)
{
    assert_same_shape(v, v1);
    sub_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator*=(VecComp_O &v, SvecComp_I v1)
{
    assert_same_shape(v, v1);
    mul_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator/=(VecComp_O &v, SvecComp_I v1)
{
    assert_same_shape(v, v1);
    div_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator+=(VecComp_O &v, VecDoub_I v1)
{
    assert_same_shape(v, v1);
    add_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator-=(VecComp_O &v, VecDoub_I v1)
{
    assert_same_shape(v, v1);
    sub_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator*=(VecComp_O &v, VecDoub_I v1)
{
    assert_same_shape(v, v1);
    mul_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator/=(VecComp_O &v, VecDoub_I v1)
{
    assert_same_shape(v, v1);
    div_eq_vv(v.p(), v1.p(), v1.size());
}


inline void operator+=(SvecDoub_O &v, VecDoub_I v1)
{
    assert_same_shape(v, v1);
    add_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator-=(SvecDoub_O &v, VecDoub_I v1)
{
    assert_same_shape(v, v1);
    sub_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator*=(SvecDoub_O &v, VecDoub_I v1)
{
    assert_same_shape(v, v1);
    mul_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator/=(SvecDoub_O &v, VecDoub_I v1)
{
    assert_same_shape(v, v1);
    div_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator+=(SvecDoub_O &v, SvecDoub_I v1)
{
    assert_same_shape(v, v1);
    add_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator-=(SvecDoub_O &v, SvecDoub_I v1)
{
    assert_same_shape(v, v1);
    sub_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator*=(SvecDoub_O &v, SvecDoub_I v1)
{
    assert_same_shape(v, v1);
    mul_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator/=(SvecDoub_O &v, SvecDoub_I v1)
{
    assert_same_shape(v, v1);
    div_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator+=(SvecComp_O &v, VecDoub_I v1)
{
    assert_same_shape(v, v1);
    add_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator-=(SvecComp_O &v, VecDoub_I v1)
{
    assert_same_shape(v, v1);
    sub_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator*=(SvecComp_O &v, VecDoub_I v1)
{
    assert_same_shape(v, v1);
    mul_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator/=(SvecComp_O &v, VecDoub_I v1)
{
    assert_same_shape(v, v1);
    div_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator+=(SvecComp_O &v, SvecComp_I v1)
{
    assert_same_shape(v, v1);
    add_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator-=(SvecComp_O &v, SvecComp_I v1)
{
    assert_same_shape(v, v1);
    sub_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator*=(SvecComp_O &v, SvecComp_I v1)
{
    assert_same_shape(v, v1);
    mul_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator/=(SvecComp_O &v, SvecComp_I v1)
{
    assert_same_shape(v, v1);
    div_eq_vv(v.p(), v1.p(), v1.size());
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
    add_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator-=(CmatDoub_O &v, CmatDoub_I v1)
{
    assert_same_shape(v, v1);
    sub_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator*=(CmatDoub_O &v, CmatDoub_I v1)
{
    assert_same_shape(v, v1);
    mul_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator/=(CmatDoub_O &v, CmatDoub_I v1)
{
    assert_same_shape(v, v1);
    div_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator+=(CmatComp_O &v, CmatDoub_I v1)
{
    assert_same_shape(v, v1);
    add_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator-=(CmatComp_O &v, CmatDoub_I v1)
{
    assert_same_shape(v, v1);
    sub_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator*=(CmatComp_O &v, CmatDoub_I v1)
{
    assert_same_shape(v, v1);
    mul_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator/=(CmatComp_O &v, CmatDoub_I v1)
{
    assert_same_shape(v, v1);
    div_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator+=(CmatComp_O &v, CmatComp_I v1)
{
    assert_same_shape(v, v1);
    add_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator-=(CmatComp_O &v, CmatComp_I v1)
{
    assert_same_shape(v, v1);
    sub_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator*=(CmatComp_O &v, CmatComp_I v1)
{
    assert_same_shape(v, v1);
    mul_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator/=(CmatComp_O &v, CmatComp_I v1)
{
    assert_same_shape(v, v1);
    div_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator+=(MatDoub_O &v, MatDoub_I v1)
{
    assert_same_shape(v, v1);
    add_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator-=(MatDoub_O &v, MatDoub_I v1)
{
    assert_same_shape(v, v1);
    sub_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator*=(MatDoub_O &v, MatDoub_I v1)
{
    assert_same_shape(v, v1);
    mul_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator/=(MatDoub_O &v, MatDoub_I v1)
{
    assert_same_shape(v, v1);
    div_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator+=(MatComp_O &v, MatComp_I v1)
{
    assert_same_shape(v, v1);
    add_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator-=(MatComp_O &v, MatComp_I v1)
{
    assert_same_shape(v, v1);
    sub_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator*=(MatComp_O &v, MatComp_I v1)
{
    assert_same_shape(v, v1);
    mul_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator/=(MatComp_O &v, MatComp_I v1)
{
    assert_same_shape(v, v1);
    div_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator+=(ScmatComp_O &v, ScmatDoub_I v1)
{
    assert_same_shape(v, v1);
    add_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator-=(ScmatComp_O &v, ScmatDoub_I v1)
{
    assert_same_shape(v, v1);
    sub_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator*=(ScmatComp_O &v, ScmatDoub_I v1)
{
    assert_same_shape(v, v1);
    mul_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator/=(ScmatComp_O &v, ScmatDoub_I v1)
{
    assert_same_shape(v, v1);
    div_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator+=(ScmatComp_O &v, ScmatComp_I v1)
{
    assert_same_shape(v, v1);
    add_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator-=(ScmatComp_O &v, ScmatComp_I v1)
{
    assert_same_shape(v, v1);
    sub_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator*=(ScmatComp_O &v, ScmatComp_I v1)
{
    assert_same_shape(v, v1);
    mul_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator/=(ScmatComp_O &v, ScmatComp_I v1)
{
    assert_same_shape(v, v1);
    div_eq_vv(v.p(), v1.p(), v1.size());
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
    add_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator-=(Cmat3Comp_O &v, Cmat3Comp_I v1)
{
    assert_same_shape(v, v1);
    sub_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator*=(Cmat3Comp_O &v, Cmat3Comp_I v1)
{
    assert_same_shape(v, v1);
    mul_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator/=(Cmat3Comp_O &v, Cmat3Comp_I v1)
{
    assert_same_shape(v, v1);
    div_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator+=(Mat3Doub_O &v, Mat3Doub_I v1)
{
    assert_same_shape(v, v1);
    add_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator-=(Mat3Doub_O &v, Mat3Doub_I v1)
{
    assert_same_shape(v, v1);
    sub_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator*=(Mat3Doub_O &v, Mat3Doub_I v1)
{
    assert_same_shape(v, v1);
    mul_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator/=(Mat3Doub_O &v, Mat3Doub_I v1)
{
    assert_same_shape(v, v1);
    div_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator+=(Mat3Comp_O &v, Mat3Comp_I v1)
{
    assert_same_shape(v, v1);
    add_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator-=(Mat3Comp_O &v, Mat3Comp_I v1)
{
    assert_same_shape(v, v1);
    sub_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator*=(Mat3Comp_O &v, Mat3Comp_I v1)
{
    assert_same_shape(v, v1);
    mul_eq_vv(v.p(), v1.p(), v1.size());
}

inline void operator/=(Mat3Comp_O &v, Mat3Comp_I v1)
{
    assert_same_shape(v, v1);
    div_eq_vv(v.p(), v1.p(), v1.size());
}


inline void add_vvs(Comp *v, const Doub *v1, Imag_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] + s;
}

inline void add_vvs(Comp *v, const Doub *v1, Imag_I s, Long_I N, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 + s;
        v += step1; v1 += step2;
    }
}

inline void sub_vvs(Comp *v, const Doub *v1, Imag_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] - s;
}

inline void sub_vvs(Comp *v, const Doub *v1, Imag_I s, Long_I N, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 - s;
        v += step1; v1 += step2;
    }
}

inline void mul_vvs(Comp *v, const Doub *v1, Imag_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] * s;
}

inline void mul_vvs(Comp *v, const Doub *v1, Imag_I s, Long_I N, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 * s;
        v += step1; v1 += step2;
    }
}

inline void div_vvs(Comp *v, const Doub *v1, Imag_I s, Long_I N)
{
    Imag inv_s = 1./s;
    mul_vvs(v, v1, inv_s, N);
}

inline void div_vvs(Comp *v, const Doub *v1, Imag_I s, Long_I N, Long_I step, Long_I step1)
{
    Imag inv_s = 1./s;
    mul_vvs(v, v1, inv_s, N, step, step1);
}

inline void add_vvs(Int *v, const Int *v1, Int_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] + s;
}

inline void add_vvs(Int *v, const Int *v1, Int_I s, Long_I N, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 + s;
        v += step1; v1 += step2;
    }
}

inline void sub_vvs(Int *v, const Int *v1, Int_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] - s;
}

inline void sub_vvs(Int *v, const Int *v1, Int_I s, Long_I N, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 - s;
        v += step1; v1 += step2;
    }
}

inline void mul_vvs(Int *v, const Int *v1, Int_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] * s;
}

inline void mul_vvs(Int *v, const Int *v1, Int_I s, Long_I N, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 * s;
        v += step1; v1 += step2;
    }
}

inline void div_vvs(Int *v, const Int *v1, Int_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] / s;
}

inline void div_vvs(Int *v, const Int *v1, Int_I s, Long_I N, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 / s;
        v += step1; v1 += step2;
    }
}

inline void add_vvs(Doub *v, const Doub *v1, Doub_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] + s;
}

inline void add_vvs(Doub *v, const Doub *v1, Doub_I s, Long_I N, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 + s;
        v += step1; v1 += step2;
    }
}

inline void sub_vvs(Doub *v, const Doub *v1, Doub_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] - s;
}

inline void sub_vvs(Doub *v, const Doub *v1, Doub_I s, Long_I N, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 - s;
        v += step1; v1 += step2;
    }
}

inline void mul_vvs(Doub *v, const Doub *v1, Doub_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] * s;
}

inline void mul_vvs(Doub *v, const Doub *v1, Doub_I s, Long_I N, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 * s;
        v += step1; v1 += step2;
    }
}

inline void div_vvs(Doub *v, const Doub *v1, Doub_I s, Long_I N)
{
    Doub inv_s = 1./s;
    mul_vvs(v, v1, inv_s, N);
}

inline void div_vvs(Doub *v, const Doub *v1, Doub_I s, Long_I N, Long_I step, Long_I step1)
{
    Doub inv_s = 1./s;
    mul_vvs(v, v1, inv_s, N, step, step1);
}

inline void add_vvs(Comp *v, const Doub *v1, Doub_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] + s;
}

inline void add_vvs(Comp *v, const Doub *v1, Doub_I s, Long_I N, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 + s;
        v += step1; v1 += step2;
    }
}

inline void sub_vvs(Comp *v, const Doub *v1, Doub_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] - s;
}

inline void sub_vvs(Comp *v, const Doub *v1, Doub_I s, Long_I N, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 - s;
        v += step1; v1 += step2;
    }
}

inline void mul_vvs(Comp *v, const Doub *v1, Doub_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] * s;
}

inline void mul_vvs(Comp *v, const Doub *v1, Doub_I s, Long_I N, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 * s;
        v += step1; v1 += step2;
    }
}

inline void div_vvs(Comp *v, const Doub *v1, Doub_I s, Long_I N)
{
    Doub inv_s = 1./s;
    mul_vvs(v, v1, inv_s, N);
}

inline void div_vvs(Comp *v, const Doub *v1, Doub_I s, Long_I N, Long_I step, Long_I step1)
{
    Doub inv_s = 1./s;
    mul_vvs(v, v1, inv_s, N, step, step1);
}

inline void add_vvs(Comp *v, const Comp *v1, Doub_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] + s;
}

inline void add_vvs(Comp *v, const Comp *v1, Doub_I s, Long_I N, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 + s;
        v += step1; v1 += step2;
    }
}

inline void sub_vvs(Comp *v, const Comp *v1, Doub_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] - s;
}

inline void sub_vvs(Comp *v, const Comp *v1, Doub_I s, Long_I N, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 - s;
        v += step1; v1 += step2;
    }
}

inline void mul_vvs(Comp *v, const Comp *v1, Doub_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] * s;
}

inline void mul_vvs(Comp *v, const Comp *v1, Doub_I s, Long_I N, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 * s;
        v += step1; v1 += step2;
    }
}

inline void div_vvs(Comp *v, const Comp *v1, Doub_I s, Long_I N)
{
    Doub inv_s = 1./s;
    mul_vvs(v, v1, inv_s, N);
}

inline void div_vvs(Comp *v, const Comp *v1, Doub_I s, Long_I N, Long_I step, Long_I step1)
{
    Doub inv_s = 1./s;
    mul_vvs(v, v1, inv_s, N, step, step1);
}

inline void add_vvs(Comp *v, const Comp *v1, Comp_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] + s;
}

inline void add_vvs(Comp *v, const Comp *v1, Comp_I s, Long_I N, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 + s;
        v += step1; v1 += step2;
    }
}

inline void sub_vvs(Comp *v, const Comp *v1, Comp_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] - s;
}

inline void sub_vvs(Comp *v, const Comp *v1, Comp_I s, Long_I N, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 - s;
        v += step1; v1 += step2;
    }
}

inline void mul_vvs(Comp *v, const Comp *v1, Comp_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] * s;
}

inline void mul_vvs(Comp *v, const Comp *v1, Comp_I s, Long_I N, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 * s;
        v += step1; v1 += step2;
    }
}

inline void div_vvs(Comp *v, const Comp *v1, Comp_I s, Long_I N)
{
    Comp inv_s = 1./s;
    mul_vvs(v, v1, inv_s, N);
}

inline void div_vvs(Comp *v, const Comp *v1, Comp_I s, Long_I N, Long_I step, Long_I step1)
{
    Comp inv_s = 1./s;
    mul_vvs(v, v1, inv_s, N, step, step1);
}

inline void add_vvs(Comp *v, const Doub *v1, Comp_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] + s;
}

inline void add_vvs(Comp *v, const Doub *v1, Comp_I s, Long_I N, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 + s;
        v += step1; v1 += step2;
    }
}

inline void sub_vvs(Comp *v, const Doub *v1, Comp_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] - s;
}

inline void sub_vvs(Comp *v, const Doub *v1, Comp_I s, Long_I N, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 - s;
        v += step1; v1 += step2;
    }
}

inline void mul_vvs(Comp *v, const Doub *v1, Comp_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] * s;
}

inline void mul_vvs(Comp *v, const Doub *v1, Comp_I s, Long_I N, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 * s;
        v += step1; v1 += step2;
    }
}

inline void div_vvs(Comp *v, const Doub *v1, Comp_I s, Long_I N)
{
    Comp inv_s = 1./s;
    mul_vvs(v, v1, inv_s, N);
}

inline void div_vvs(Comp *v, const Doub *v1, Comp_I s, Long_I N, Long_I step, Long_I step1)
{
    Comp inv_s = 1./s;
    mul_vvs(v, v1, inv_s, N, step, step1);
}


inline void sub_vsv(Comp *v, const Doub &s, const Comp *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = s - v1[i];
}

inline void sub_vsv(Comp *v, const Doub &s, const Comp *v1, Long_I N, Long_I step, Long_I step1)
{
    for (Long i = 0; i < N; ++i) {
        *v = s - *v1;
        v += step; v1 += step1;
    }
}

inline void div_vsv(Comp *v, const Doub &s, const Comp *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = s / v1[i];
}

inline void div_vsv(Comp *v, const Doub &s, const Comp *v1, Long_I N, Long_I step, Long_I step1)
{
    for (Long i = 0; i < N; ++i) {
        *v = s / *v1;
        v += step; v1 += step1;
    }
}

inline void sub_vsv(Int *v, const Int &s, const Int *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = s - v1[i];
}

inline void sub_vsv(Int *v, const Int &s, const Int *v1, Long_I N, Long_I step, Long_I step1)
{
    for (Long i = 0; i < N; ++i) {
        *v = s - *v1;
        v += step; v1 += step1;
    }
}

inline void div_vsv(Int *v, const Int &s, const Int *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = s / v1[i];
}

inline void div_vsv(Int *v, const Int &s, const Int *v1, Long_I N, Long_I step, Long_I step1)
{
    for (Long i = 0; i < N; ++i) {
        *v = s / *v1;
        v += step; v1 += step1;
    }
}

inline void sub_vsv(Doub *v, const Doub &s, const Doub *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = s - v1[i];
}

inline void sub_vsv(Doub *v, const Doub &s, const Doub *v1, Long_I N, Long_I step, Long_I step1)
{
    for (Long i = 0; i < N; ++i) {
        *v = s - *v1;
        v += step; v1 += step1;
    }
}

inline void div_vsv(Doub *v, const Doub &s, const Doub *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = s / v1[i];
}

inline void div_vsv(Doub *v, const Doub &s, const Doub *v1, Long_I N, Long_I step, Long_I step1)
{
    for (Long i = 0; i < N; ++i) {
        *v = s / *v1;
        v += step; v1 += step1;
    }
}

inline void sub_vsv(Comp *v, const Doub &s, const Doub *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = s - v1[i];
}

inline void sub_vsv(Comp *v, const Doub &s, const Doub *v1, Long_I N, Long_I step, Long_I step1)
{
    for (Long i = 0; i < N; ++i) {
        *v = s - *v1;
        v += step; v1 += step1;
    }
}

inline void div_vsv(Comp *v, const Doub &s, const Doub *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = s / v1[i];
}

inline void div_vsv(Comp *v, const Doub &s, const Doub *v1, Long_I N, Long_I step, Long_I step1)
{
    for (Long i = 0; i < N; ++i) {
        *v = s / *v1;
        v += step; v1 += step1;
    }
}

inline void sub_vsv(Comp *v, const Doub &s, const Imag *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = s - v1[i];
}

inline void sub_vsv(Comp *v, const Doub &s, const Imag *v1, Long_I N, Long_I step, Long_I step1)
{
    for (Long i = 0; i < N; ++i) {
        *v = s - *v1;
        v += step; v1 += step1;
    }
}

inline void div_vsv(Comp *v, const Doub &s, const Imag *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = s / v1[i];
}

inline void div_vsv(Comp *v, const Doub &s, const Imag *v1, Long_I N, Long_I step, Long_I step1)
{
    for (Long i = 0; i < N; ++i) {
        *v = s / *v1;
        v += step; v1 += step1;
    }
}

inline void sub_vsv(Comp *v, const Comp &s, const Doub *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = s - v1[i];
}

inline void sub_vsv(Comp *v, const Comp &s, const Doub *v1, Long_I N, Long_I step, Long_I step1)
{
    for (Long i = 0; i < N; ++i) {
        *v = s - *v1;
        v += step; v1 += step1;
    }
}

inline void div_vsv(Comp *v, const Comp &s, const Doub *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = s / v1[i];
}

inline void div_vsv(Comp *v, const Comp &s, const Doub *v1, Long_I N, Long_I step, Long_I step1)
{
    for (Long i = 0; i < N; ++i) {
        *v = s / *v1;
        v += step; v1 += step1;
    }
}

inline void sub_vsv(Comp *v, const Comp &s, const Comp *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = s - v1[i];
}

inline void sub_vsv(Comp *v, const Comp &s, const Comp *v1, Long_I N, Long_I step, Long_I step1)
{
    for (Long i = 0; i < N; ++i) {
        *v = s - *v1;
        v += step; v1 += step1;
    }
}

inline void div_vsv(Comp *v, const Comp &s, const Comp *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = s / v1[i];
}

inline void div_vsv(Comp *v, const Comp &s, const Comp *v1, Long_I N, Long_I step, Long_I step1)
{
    for (Long i = 0; i < N; ++i) {
        *v = s / *v1;
        v += step; v1 += step1;
    }
}


inline void add_vvv(Comp *v, const Doub *v1, const Comp *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] + v2[i];
}

inline void add_vvv(Comp *v, const Doub *v1, const Comp *v2, Long_I N, Long_I step, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 + *v2;
        v += step; v1 += step1; v2 += step2;
    }
}

inline void sub_vvv(Comp *v, const Doub *v1, const Comp *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] - v2[i];
}

inline void sub_vvv(Comp *v, const Doub *v1, const Comp *v2, Long_I N, Long_I step, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 - *v2;
        v += step; v1 += step1; v2 += step2;
    }
}

inline void mul_vvv(Comp *v, const Doub *v1, const Comp *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] * v2[i];
}

inline void mul_vvv(Comp *v, const Doub *v1, const Comp *v2, Long_I N, Long_I step, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 * *v2;
        v += step; v1 += step1; v2 += step2;
    }
}

inline void div_vvv(Comp *v, const Doub *v1, const Comp *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] / v2[i];
}

inline void div_vvv(Comp *v, const Doub *v1, const Comp *v2, Long_I N, Long_I step, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 / *v2;
        v += step; v1 += step1; v2 += step2;
    }
}

inline void add_vvv(Int *v, const Int *v1, const Int *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] + v2[i];
}

inline void add_vvv(Int *v, const Int *v1, const Int *v2, Long_I N, Long_I step, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 + *v2;
        v += step; v1 += step1; v2 += step2;
    }
}

inline void sub_vvv(Int *v, const Int *v1, const Int *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] - v2[i];
}

inline void sub_vvv(Int *v, const Int *v1, const Int *v2, Long_I N, Long_I step, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 - *v2;
        v += step; v1 += step1; v2 += step2;
    }
}

inline void mul_vvv(Int *v, const Int *v1, const Int *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] * v2[i];
}

inline void mul_vvv(Int *v, const Int *v1, const Int *v2, Long_I N, Long_I step, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 * *v2;
        v += step; v1 += step1; v2 += step2;
    }
}

inline void div_vvv(Int *v, const Int *v1, const Int *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] / v2[i];
}

inline void div_vvv(Int *v, const Int *v1, const Int *v2, Long_I N, Long_I step, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 / *v2;
        v += step; v1 += step1; v2 += step2;
    }
}

inline void add_vvv(Doub *v, const Doub *v1, const Doub *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] + v2[i];
}

inline void add_vvv(Doub *v, const Doub *v1, const Doub *v2, Long_I N, Long_I step, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 + *v2;
        v += step; v1 += step1; v2 += step2;
    }
}

inline void sub_vvv(Doub *v, const Doub *v1, const Doub *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] - v2[i];
}

inline void sub_vvv(Doub *v, const Doub *v1, const Doub *v2, Long_I N, Long_I step, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 - *v2;
        v += step; v1 += step1; v2 += step2;
    }
}

inline void mul_vvv(Doub *v, const Doub *v1, const Doub *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] * v2[i];
}

inline void mul_vvv(Doub *v, const Doub *v1, const Doub *v2, Long_I N, Long_I step, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 * *v2;
        v += step; v1 += step1; v2 += step2;
    }
}

inline void div_vvv(Doub *v, const Doub *v1, const Doub *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] / v2[i];
}

inline void div_vvv(Doub *v, const Doub *v1, const Doub *v2, Long_I N, Long_I step, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 / *v2;
        v += step; v1 += step1; v2 += step2;
    }
}

inline void add_vvv(Comp *v, const Comp *v1, const Comp *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] + v2[i];
}

inline void add_vvv(Comp *v, const Comp *v1, const Comp *v2, Long_I N, Long_I step, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 + *v2;
        v += step; v1 += step1; v2 += step2;
    }
}

inline void sub_vvv(Comp *v, const Comp *v1, const Comp *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] - v2[i];
}

inline void sub_vvv(Comp *v, const Comp *v1, const Comp *v2, Long_I N, Long_I step, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 - *v2;
        v += step; v1 += step1; v2 += step2;
    }
}

inline void mul_vvv(Comp *v, const Comp *v1, const Comp *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] * v2[i];
}

inline void mul_vvv(Comp *v, const Comp *v1, const Comp *v2, Long_I N, Long_I step, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 * *v2;
        v += step; v1 += step1; v2 += step2;
    }
}

inline void div_vvv(Comp *v, const Comp *v1, const Comp *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] / v2[i];
}

inline void div_vvv(Comp *v, const Comp *v1, const Comp *v2, Long_I N, Long_I step, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 / *v2;
        v += step; v1 += step1; v2 += step2;
    }
}

inline void add_vvv(Comp *v, const Comp *v1, const Doub *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] + v2[i];
}

inline void add_vvv(Comp *v, const Comp *v1, const Doub *v2, Long_I N, Long_I step, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 + *v2;
        v += step; v1 += step1; v2 += step2;
    }
}

inline void sub_vvv(Comp *v, const Comp *v1, const Doub *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] - v2[i];
}

inline void sub_vvv(Comp *v, const Comp *v1, const Doub *v2, Long_I N, Long_I step, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 - *v2;
        v += step; v1 += step1; v2 += step2;
    }
}

inline void mul_vvv(Comp *v, const Comp *v1, const Doub *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] * v2[i];
}

inline void mul_vvv(Comp *v, const Comp *v1, const Doub *v2, Long_I N, Long_I step, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 * *v2;
        v += step; v1 += step1; v2 += step2;
    }
}

inline void div_vvv(Comp *v, const Comp *v1, const Doub *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = v1[i] / v2[i];
}

inline void div_vvv(Comp *v, const Comp *v1, const Doub *v2, Long_I N, Long_I step, Long_I step1, Long_I step2)
{
    for (Long i = 0; i < N; ++i) {
        *v = *v1 / *v2;
        v += step; v1 += step1; v2 += step2;
    }
}


inline void add(VecInt_O v, VecInt_I v1, Int_I s)
{
    assert_same_shape(v, v1);
    add_vvs(v.p(), v1.p(), s, v1.size());
}

inline void add(VecInt_O v, Int_I s, VecInt_I v1)
{ add(v, v1, s); }

inline void sub(VecInt_O v, VecInt_I v1, Int_I s)
{
    assert_same_shape(v, v1);
    sub_vvs(v.p(), v1.p(), s, v1.size());
}

inline void sub(VecInt_O v, Int_I s, VecInt_I v1)
{
    assert_same_shape(v, v1);
    sub_vsv(v.p(), s, v1.p(), v1.size());
}

inline void mul(VecInt_O v, VecInt_I v1, Int_I s)
{
    assert_same_shape(v, v1);
    mul_vvs(v.p(), v1.p(), s, v1.size());
}

inline void mul(VecInt_O v, Int_I s, VecInt_I v1)
{ mul(v, v1, s); }

inline void div(VecInt_O v, VecInt_I v1, Int_I s)
{
    assert_same_shape(v, v1);
    div_vvs(v.p(), v1.p(), s, v1.size());
}

inline void div(VecInt_O v, Int_I s, VecInt_I v1)
{
    assert_same_shape(v, v1);
    div_vsv(v.p(), s, v1.p(), v1.size());
}

inline void add(VecDoub_O v, VecDoub_I v1, Doub_I s)
{
    assert_same_shape(v, v1);
    add_vvs(v.p(), v1.p(), s, v1.size());
}

inline void add(VecDoub_O v, Doub_I s, VecDoub_I v1)
{ add(v, v1, s); }

inline void sub(VecDoub_O v, VecDoub_I v1, Doub_I s)
{
    assert_same_shape(v, v1);
    sub_vvs(v.p(), v1.p(), s, v1.size());
}

inline void sub(VecDoub_O v, Doub_I s, VecDoub_I v1)
{
    assert_same_shape(v, v1);
    sub_vsv(v.p(), s, v1.p(), v1.size());
}

inline void mul(VecDoub_O v, VecDoub_I v1, Doub_I s)
{
    assert_same_shape(v, v1);
    mul_vvs(v.p(), v1.p(), s, v1.size());
}

inline void mul(VecDoub_O v, Doub_I s, VecDoub_I v1)
{ mul(v, v1, s); }

inline void div(VecDoub_O v, VecDoub_I v1, Doub_I s)
{
    assert_same_shape(v, v1);
    div_vvs(v.p(), v1.p(), s, v1.size());
}

inline void div(VecDoub_O v, Doub_I s, VecDoub_I v1)
{
    assert_same_shape(v, v1);
    div_vsv(v.p(), s, v1.p(), v1.size());
}

inline void add(VecComp_O v, SvecDoub_I v1, Doub_I s)
{
    assert_same_shape(v, v1);
    add_vvs(v.p(), v1.p(), s, v1.size());
}

inline void add(VecComp_O v, Doub_I s, SvecDoub_I v1)
{ add(v, v1, s); }

inline void sub(VecComp_O v, SvecDoub_I v1, Doub_I s)
{
    assert_same_shape(v, v1);
    sub_vvs(v.p(), v1.p(), s, v1.size());
}

inline void sub(VecComp_O v, Doub_I s, SvecDoub_I v1)
{
    assert_same_shape(v, v1);
    sub_vsv(v.p(), s, v1.p(), v1.size());
}

inline void mul(VecComp_O v, SvecDoub_I v1, Doub_I s)
{
    assert_same_shape(v, v1);
    mul_vvs(v.p(), v1.p(), s, v1.size());
}

inline void mul(VecComp_O v, Doub_I s, SvecDoub_I v1)
{ mul(v, v1, s); }

inline void div(VecComp_O v, SvecDoub_I v1, Doub_I s)
{
    assert_same_shape(v, v1);
    div_vvs(v.p(), v1.p(), s, v1.size());
}

inline void div(VecComp_O v, Doub_I s, SvecDoub_I v1)
{
    assert_same_shape(v, v1);
    div_vsv(v.p(), s, v1.p(), v1.size());
}

inline void add(VecComp_O v, SvecDoub_I v1, Imag_I s)
{
    assert_same_shape(v, v1);
    add_vvs(v.p(), v1.p(), s, v1.size());
}

inline void add(VecComp_O v, Imag_I s, SvecDoub_I v1)
{ add(v, v1, s); }

inline void sub(VecComp_O v, SvecDoub_I v1, Imag_I s)
{
    assert_same_shape(v, v1);
    sub_vvs(v.p(), v1.p(), s, v1.size());
}

inline void sub(VecComp_O v, Imag_I s, SvecDoub_I v1)
{
    assert_same_shape(v, v1);
    sub_vsv(v.p(), s, v1.p(), v1.size());
}

inline void mul(VecComp_O v, SvecDoub_I v1, Imag_I s)
{
    assert_same_shape(v, v1);
    mul_vvs(v.p(), v1.p(), s, v1.size());
}

inline void mul(VecComp_O v, Imag_I s, SvecDoub_I v1)
{ mul(v, v1, s); }

inline void div(VecComp_O v, SvecDoub_I v1, Imag_I s)
{
    assert_same_shape(v, v1);
    div_vvs(v.p(), v1.p(), s, v1.size());
}

inline void div(VecComp_O v, Imag_I s, SvecDoub_I v1)
{
    assert_same_shape(v, v1);
    div_vsv(v.p(), s, v1.p(), v1.size());
}

inline void add(VecComp_O v, VecComp_I v1, Doub_I s)
{
    assert_same_shape(v, v1);
    add_vvs(v.p(), v1.p(), s, v1.size());
}

inline void add(VecComp_O v, Doub_I s, VecComp_I v1)
{ add(v, v1, s); }

inline void sub(VecComp_O v, VecComp_I v1, Doub_I s)
{
    assert_same_shape(v, v1);
    sub_vvs(v.p(), v1.p(), s, v1.size());
}

inline void sub(VecComp_O v, Doub_I s, VecComp_I v1)
{
    assert_same_shape(v, v1);
    sub_vsv(v.p(), s, v1.p(), v1.size());
}

inline void mul(VecComp_O v, VecComp_I v1, Doub_I s)
{
    assert_same_shape(v, v1);
    mul_vvs(v.p(), v1.p(), s, v1.size());
}

inline void mul(VecComp_O v, Doub_I s, VecComp_I v1)
{ mul(v, v1, s); }

inline void div(VecComp_O v, VecComp_I v1, Doub_I s)
{
    assert_same_shape(v, v1);
    div_vvs(v.p(), v1.p(), s, v1.size());
}

inline void div(VecComp_O v, Doub_I s, VecComp_I v1)
{
    assert_same_shape(v, v1);
    div_vsv(v.p(), s, v1.p(), v1.size());
}

inline void add(VecComp_O v, VecComp_I v1, Comp_I s)
{
    assert_same_shape(v, v1);
    add_vvs(v.p(), v1.p(), s, v1.size());
}

inline void add(VecComp_O v, Comp_I s, VecComp_I v1)
{ add(v, v1, s); }

inline void sub(VecComp_O v, VecComp_I v1, Comp_I s)
{
    assert_same_shape(v, v1);
    sub_vvs(v.p(), v1.p(), s, v1.size());
}

inline void sub(VecComp_O v, Comp_I s, VecComp_I v1)
{
    assert_same_shape(v, v1);
    sub_vsv(v.p(), s, v1.p(), v1.size());
}

inline void mul(VecComp_O v, VecComp_I v1, Comp_I s)
{
    assert_same_shape(v, v1);
    mul_vvs(v.p(), v1.p(), s, v1.size());
}

inline void mul(VecComp_O v, Comp_I s, VecComp_I v1)
{ mul(v, v1, s); }

inline void div(VecComp_O v, VecComp_I v1, Comp_I s)
{
    assert_same_shape(v, v1);
    div_vvs(v.p(), v1.p(), s, v1.size());
}

inline void div(VecComp_O v, Comp_I s, VecComp_I v1)
{
    assert_same_shape(v, v1);
    div_vsv(v.p(), s, v1.p(), v1.size());
}

inline void add(SvecComp_O v, SvecComp_I v1, Doub_I s)
{
    assert_same_shape(v, v1);
    add_vvs(v.p(), v1.p(), s, v1.size());
}

inline void add(SvecComp_O v, Doub_I s, SvecComp_I v1)
{ add(v, v1, s); }

inline void sub(SvecComp_O v, SvecComp_I v1, Doub_I s)
{
    assert_same_shape(v, v1);
    sub_vvs(v.p(), v1.p(), s, v1.size());
}

inline void sub(SvecComp_O v, Doub_I s, SvecComp_I v1)
{
    assert_same_shape(v, v1);
    sub_vsv(v.p(), s, v1.p(), v1.size());
}

inline void mul(SvecComp_O v, SvecComp_I v1, Doub_I s)
{
    assert_same_shape(v, v1);
    mul_vvs(v.p(), v1.p(), s, v1.size());
}

inline void mul(SvecComp_O v, Doub_I s, SvecComp_I v1)
{ mul(v, v1, s); }

inline void div(SvecComp_O v, SvecComp_I v1, Doub_I s)
{
    assert_same_shape(v, v1);
    div_vvs(v.p(), v1.p(), s, v1.size());
}

inline void div(SvecComp_O v, Doub_I s, SvecComp_I v1)
{
    assert_same_shape(v, v1);
    div_vsv(v.p(), s, v1.p(), v1.size());
}

inline void add(DcmatComp_O v, DcmatComp_I v1, Doub_I s)
{
    assert_same_shape(v, v1);
    Comp *p = v.p(); const Comp *p1 = v1.p();
    for (Long j = 0; j < v.n1(); ++j) {
        add_vvs(p, p1, s, v.n0());
        p += v.lda(); p1 += v1.lda();
    }
}

inline void add(DcmatComp_O v, Doub_I s, DcmatComp_I v1)
{ add(v, v1, s); }

inline void sub(DcmatComp_O v, DcmatComp_I v1, Doub_I s)
{
    assert_same_shape(v, v1);
    Comp *p = v.p(); const Comp *p1 = v1.p();
    for (Long j = 0; j < v.n1(); ++j) {
        sub_vvs(p, p1, s, v.n0());
        p += v.lda(); p1 += v1.lda();
    }
}

inline void sub(DcmatComp_O v, Doub_I s, DcmatComp_I v1)
{
    assert_same_shape(v, v1);
    Comp *p = v.p(); const Comp *p1 = v1.p();
    for (Long j = 0; j < v.n1(); ++j) {
        sub_vsv(p, s, p1, v.n0());
        p += v.lda(); p1 += v1.lda();
    }
}

inline void mul(DcmatComp_O v, DcmatComp_I v1, Doub_I s)
{
    assert_same_shape(v, v1);
    Comp *p = v.p(); const Comp *p1 = v1.p();
    for (Long j = 0; j < v.n1(); ++j) {
        mul_vvs(p, p1, s, v.n0());
        p += v.lda(); p1 += v1.lda();
    }
}

inline void mul(DcmatComp_O v, Doub_I s, DcmatComp_I v1)
{ mul(v, v1, s); }

inline void div(DcmatComp_O v, DcmatComp_I v1, Doub_I s)
{
    assert_same_shape(v, v1);
    Comp *p = v.p(); const Comp *p1 = v1.p();
    for (Long j = 0; j < v.n1(); ++j) {
        div_vvs(p, p1, s, v.n0());
        p += v.lda(); p1 += v1.lda();
    }
}

inline void div(DcmatComp_O v, const Doub_I s, DcmatComp_I v1)
{
    assert_same_shape(v, v1);
    Comp *p = v.p(); const Comp *p1 = v1.p();
    for (Long j = 0; j < v.n1(); ++j) {
        div_vsv(p, s, p1, v.n0());
        p += v.lda(); p1 += v1.lda();
    }
}

inline void add(VecComp_O v, VecDoub_I v1, Comp_I s)
{
    assert_same_shape(v, v1);
    add_vvs(v.p(), v1.p(), s, v1.size());
}

inline void add(VecComp_O v, Comp_I s, VecDoub_I v1)
{ add(v, v1, s); }

inline void sub(VecComp_O v, VecDoub_I v1, Comp_I s)
{
    assert_same_shape(v, v1);
    sub_vvs(v.p(), v1.p(), s, v1.size());
}

inline void sub(VecComp_O v, Comp_I s, VecDoub_I v1)
{
    assert_same_shape(v, v1);
    sub_vsv(v.p(), s, v1.p(), v1.size());
}

inline void mul(VecComp_O v, VecDoub_I v1, Comp_I s)
{
    assert_same_shape(v, v1);
    mul_vvs(v.p(), v1.p(), s, v1.size());
}

inline void mul(VecComp_O v, Comp_I s, VecDoub_I v1)
{ mul(v, v1, s); }

inline void div(VecComp_O v, VecDoub_I v1, Comp_I s)
{
    assert_same_shape(v, v1);
    div_vvs(v.p(), v1.p(), s, v1.size());
}

inline void div(VecComp_O v, Comp_I s, VecDoub_I v1)
{
    assert_same_shape(v, v1);
    div_vsv(v.p(), s, v1.p(), v1.size());
}

inline void add(SvecComp_O v, VecComp_I v1, Doub_I s)
{
    assert_same_shape(v, v1);
    add_vvs(v.p(), v1.p(), s, v1.size());
}

inline void add(SvecComp_O v, Doub_I s, VecComp_I v1)
{ add(v, v1, s); }

inline void sub(SvecComp_O v, VecComp_I v1, Doub_I s)
{
    assert_same_shape(v, v1);
    sub_vvs(v.p(), v1.p(), s, v1.size());
}

inline void sub(SvecComp_O v, Doub_I s, VecComp_I v1)
{
    assert_same_shape(v, v1);
    sub_vsv(v.p(), s, v1.p(), v1.size());
}

inline void mul(SvecComp_O v, VecComp_I v1, Doub_I s)
{
    assert_same_shape(v, v1);
    mul_vvs(v.p(), v1.p(), s, v1.size());
}

inline void mul(SvecComp_O v, Doub_I s, VecComp_I v1)
{ mul(v, v1, s); }

inline void div(SvecComp_O v, VecComp_I v1, Doub_I s)
{
    assert_same_shape(v, v1);
    div_vvs(v.p(), v1.p(), s, v1.size());
}

inline void div(SvecComp_O v, Doub_I s, VecComp_I v1)
{
    assert_same_shape(v, v1);
    div_vsv(v.p(), s, v1.p(), v1.size());
}

inline void add(SvecComp_O v, DvecComp_I v1, Doub_I s)
{
    assert_same_shape(v, v1);
    add_vvs(v.p(), v1.p(), s, v1.size(), 1, v1.step());
}

inline void add(SvecComp_O v, Doub_I s, DvecComp_I v1)
{ add(v, v1, s); }

inline void sub(SvecComp_O v, DvecComp_I v1, Doub_I s)
{
    assert_same_shape(v, v1);
    sub_vvs(v.p(), v1.p(), s, v1.size(), 1, v1.step());
}

inline void sub(SvecComp_O v, Doub_I s, DvecComp_I v1)
{
    assert_same_shape(v, v1);
    sub_vsv(v.p(), s, v1.p(), v1.size(), 1, v1.step());
}

inline void mul(SvecComp_O v, DvecComp_I v1, Doub_I s)
{
    assert_same_shape(v, v1);
    mul_vvs(v.p(), v1.p(), s, v1.size(), 1, v1.step());
}

inline void mul(SvecComp_O v, Doub_I s, DvecComp_I v1)
{ mul(v, v1, s); }

inline void div(SvecComp_O v, DvecComp_I v1, Doub_I s)
{
    assert_same_shape(v, v1);
    div_vvs(v.p(), v1.p(), s, v1.size(), 1, v1.step());
}

inline void div(SvecComp_O v, Doub_I s, DvecComp_I v1)
{
    assert_same_shape(v, v1);
    div_vsv(v.p(), s, v1.p(), v1.size(), 1, v1.step());
}

inline void add(Cmat3Comp_O v, Cmat3Doub_I v1, Imag_I s)
{
    assert_same_shape(v, v1);
    add_vvs(v.p(), v1.p(), s, v1.size());
}

inline void add(Cmat3Comp_O v, Imag_I s, Cmat3Doub_I v1)
{ add(v, v1, s); }

inline void sub(Cmat3Comp_O v, Cmat3Doub_I v1, Imag_I s)
{
    assert_same_shape(v, v1);
    sub_vvs(v.p(), v1.p(), s, v1.size());
}

inline void sub(Cmat3Comp_O v, Imag_I s, Cmat3Doub_I v1)
{
    assert_same_shape(v, v1);
    sub_vsv(v.p(), s, v1.p(), v1.size());
}

inline void mul(Cmat3Comp_O v, Cmat3Doub_I v1, Imag_I s)
{
    assert_same_shape(v, v1);
    mul_vvs(v.p(), v1.p(), s, v1.size());
}

inline void mul(Cmat3Comp_O v, Imag_I s, Cmat3Doub_I v1)
{ mul(v, v1, s); }

inline void div(Cmat3Comp_O v, Cmat3Doub_I v1, Imag_I s)
{
    assert_same_shape(v, v1);
    div_vvs(v.p(), v1.p(), s, v1.size());
}

inline void div(Cmat3Comp_O v, Imag_I s, Cmat3Doub_I v1)
{
    assert_same_shape(v, v1);
    div_vsv(v.p(), s, v1.p(), v1.size());
}


inline void add(VecInt_O v, VecInt_I v1, VecInt_I v2)
{
    assert_same_shape(v, v1, v2);
    add_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void sub(VecInt_O v, VecInt_I v1, VecInt_I v2)
{
    assert_same_shape(v, v1, v2);
    sub_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void mul(VecInt_O v, VecInt_I v1, VecInt_I v2)
{
    assert_same_shape(v, v1, v2);
    mul_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void div(VecInt_O v, VecInt_I v1, VecInt_I v2)
{
    assert_same_shape(v, v1, v2);
    div_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void add(VecDoub_O v, VecDoub_I v1, VecDoub_I v2)
{
    assert_same_shape(v, v1, v2);
    add_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void sub(VecDoub_O v, VecDoub_I v1, VecDoub_I v2)
{
    assert_same_shape(v, v1, v2);
    sub_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void mul(VecDoub_O v, VecDoub_I v1, VecDoub_I v2)
{
    assert_same_shape(v, v1, v2);
    mul_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void div(VecDoub_O v, VecDoub_I v1, VecDoub_I v2)
{
    assert_same_shape(v, v1, v2);
    div_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void add(VecComp_O v, VecComp_I v1, VecComp_I v2)
{
    assert_same_shape(v, v1, v2);
    add_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void sub(VecComp_O v, VecComp_I v1, VecComp_I v2)
{
    assert_same_shape(v, v1, v2);
    sub_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void mul(VecComp_O v, VecComp_I v1, VecComp_I v2)
{
    assert_same_shape(v, v1, v2);
    mul_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void div(VecComp_O v, VecComp_I v1, VecComp_I v2)
{
    assert_same_shape(v, v1, v2);
    div_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void add(SvecComp_O v, VecComp_I v1, SvecComp_I v2)
{
    assert_same_shape(v, v1, v2);
    add_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void sub(SvecComp_O v, VecComp_I v1, SvecComp_I v2)
{
    assert_same_shape(v, v1, v2);
    sub_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void mul(SvecComp_O v, VecComp_I v1, SvecComp_I v2)
{
    assert_same_shape(v, v1, v2);
    mul_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void div(SvecComp_O v, VecComp_I v1, SvecComp_I v2)
{
    assert_same_shape(v, v1, v2);
    div_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void add(DvecComp_O v, SvecComp_I v1, DvecComp_I v2)
{
    assert_same_shape(v, v1, v2);
    add_vvv(v.p(), v1.p(), v2.p(), v.size(), v.step(), 1, v2.step());
}

inline void sub(DvecComp_O v, SvecComp_I v1, DvecComp_I v2)
{
    assert_same_shape(v, v1, v2);
    sub_vvv(v.p(), v1.p(), v2.p(), v.size(), v.step(), 1, v2.step());
}

inline void mul(DvecComp_O v, SvecComp_I v1, DvecComp_I v2)
{
    assert_same_shape(v, v1, v2);
    sub_vvv(v.p(), v1.p(), v2.p(), v.size(), v.step(), 1, v2.step());
}

inline void div(DvecComp_O v, SvecComp_I v1, DvecComp_I v2)
{
    assert_same_shape(v, v1, v2);
    div_vvv(v.p(), v1.p(), v2.p(), v.size(), v.step(), 1, v2.step());
}

inline void add(SvecDoub_O v, VecDoub_I v1, SvecDoub_I v2)
{
    assert_same_shape(v, v1, v2);
    add_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void sub(SvecDoub_O v, VecDoub_I v1, SvecDoub_I v2)
{
    assert_same_shape(v, v1, v2);
    sub_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void mul(SvecDoub_O v, VecDoub_I v1, SvecDoub_I v2)
{
    assert_same_shape(v, v1, v2);
    mul_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void div(SvecDoub_O v, VecDoub_I v1, SvecDoub_I v2)
{
    assert_same_shape(v, v1, v2);
    div_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void add(SvecComp_O v, SvecComp_I v1, SvecComp_I v2)
{
    assert_same_shape(v, v1, v2);
    add_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void sub(SvecComp_O v, SvecComp_I v1, SvecComp_I v2)
{
    assert_same_shape(v, v1, v2);
    sub_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void mul(SvecComp_O v, SvecComp_I v1, SvecComp_I v2)
{
    assert_same_shape(v, v1, v2);
    mul_vvv(v.p(), v1.p(), v2.p(), v.size());
}

inline void div(SvecComp_O v, SvecComp_I v1, SvecComp_I v2)
{
    assert_same_shape(v, v1, v2);
    div_vvv(v.p(), v1.p(), v2.p(), v.size());
}


inline void sub_vv(Comp *v, const Doub *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = -v1[i];
}

inline void sub_vv(Llong *v, const Llong *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = -v1[i];
}

inline void sub_vv(Doub *v, const Doub *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = -v1[i];
}

inline void sub_vv(Comp *v, const Comp *v1, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        v[i] = -v1[i];
}


inline void sub(VecLlong_O v, VecLlong_I v1)
{
    assert_same_shape(v, v1);
    sub_vv(v.p(), v1.p(), v1.size());
}

inline void sub(VecDoub_O v, VecDoub_I v1)
{
    assert_same_shape(v, v1);
    sub_vv(v.p(), v1.p(), v1.size());
}

inline void sub(VecComp_O v, VecDoub_I v1)
{
    assert_same_shape(v, v1);
    sub_vv(v.p(), v1.p(), v1.size());
}

inline void sub(VecComp_O v, VecComp_I v1)
{
    assert_same_shape(v, v1);
    sub_vv(v.p(), v1.p(), v1.size());
}

inline void sub(ScmatDoub_O v, CmatDoub_I v1)
{
    assert_same_shape(v, v1);
    sub_vv(v.p(), v1.p(), v1.size());
}


} // namespace slisc
