// element-wise +, -, *, /

#pragma once
#include "../arith/scalar_arith.h"
#include "../arith/compare.h"

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

inline void times_eq_vs(Int *v, Int_I s, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		v[i] *= s;
}

inline void times_eq_vs(Int *v, Int_I s, Long_I N, Long step)
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

inline void times_eq_vs(Llong *v, Llong_I s, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		v[i] *= s;
}

inline void times_eq_vs(Llong *v, Llong_I s, Long_I N, Long step)
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

inline void times_eq_vs(Doub *v, Doub_I s, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		v[i] *= s;
}

inline void times_eq_vs(Doub *v, Doub_I s, Long_I N, Long step)
{
	for (Long i = 0; i < N*step; i += step)
		v[i] *= s;
}
inline void div_eq_vs(Doub *v, Doub_I s, Long_I N)
{ times_eq_vs(v, 1./s, N); }

inline void div_eq_vs(Doub *v, Doub_I s, Long_I N, Long_I step)
{ times_eq_vs(v, 1./s, N, step); }


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

inline void times_eq_vs(Comp *v, Doub_I s, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		v[i] *= s;
}

inline void times_eq_vs(Comp *v, Doub_I s, Long_I N, Long step)
{
	for (Long i = 0; i < N*step; i += step)
		v[i] *= s;
}
inline void div_eq_vs(Comp *v, Doub_I s, Long_I N)
{ times_eq_vs(v, 1./s, N); }

inline void div_eq_vs(Comp *v, Doub_I s, Long_I N, Long_I step)
{ times_eq_vs(v, 1./s, N, step); }


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

inline void times_eq_vs(Comp *v, Comp_I s, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		v[i] *= s;
}

inline void times_eq_vs(Comp *v, Comp_I s, Long_I N, Long step)
{
	for (Long i = 0; i < N*step; i += step)
		v[i] *= s;
}
inline void div_eq_vs(Comp *v, Comp_I s, Long_I N)
{ times_eq_vs(v, 1./s, N); }

inline void div_eq_vs(Comp *v, Comp_I s, Long_I N, Long_I step)
{ times_eq_vs(v, 1./s, N, step); }


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

inline void times_eq_vs(Comp *v, Imag_I s, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		v[i] *= s;
}

inline void times_eq_vs(Comp *v, Imag_I s, Long_I N, Long step)
{
	for (Long i = 0; i < N*step; i += step)
		v[i] *= s;
}
inline void div_eq_vs(Comp *v, Imag_I s, Long_I N)
{ times_eq_vs(v, 1./s, N); }

inline void div_eq_vs(Comp *v, Imag_I s, Long_I N, Long_I step)
{ times_eq_vs(v, 1./s, N, step); }


inline void operator+=(vecInt_IO v, Int_I s)
{ add_eq_vs(&v[0], s, v.size()); }

inline void operator-=(vecInt_IO v, Int_I s)
{ sub_eq_vs(&v[0], s, v.size()); }

inline void operator*=(vecInt_IO v, Int_I s)
{ times_eq_vs(&v[0], s, v.size()); }

inline void operator/=(vecInt_IO v, Int_I s)
{ div_eq_vs(&v[0], s, v.size()); }

inline void operator+=(vecLlong_IO v, Llong_I s)
{ add_eq_vs(&v[0], s, v.size()); }

inline void operator-=(vecLlong_IO v, Llong_I s)
{ sub_eq_vs(&v[0], s, v.size()); }

inline void operator*=(vecLlong_IO v, Llong_I s)
{ times_eq_vs(&v[0], s, v.size()); }

inline void operator/=(vecLlong_IO v, Llong_I s)
{ div_eq_vs(&v[0], s, v.size()); }

inline void operator+=(vecDoub_IO v, Doub_I s)
{ add_eq_vs(&v[0], s, v.size()); }

inline void operator-=(vecDoub_IO v, Doub_I s)
{ sub_eq_vs(&v[0], s, v.size()); }

inline void operator*=(vecDoub_IO v, Doub_I s)
{ times_eq_vs(&v[0], s, v.size()); }

inline void operator/=(vecDoub_IO v, Doub_I s)
{ div_eq_vs(&v[0], s, v.size()); }


inline void operator+=(vecComp_IO v, Doub_I s)
{ add_eq_vs(&v[0], s, v.size()); }

inline void operator-=(vecComp_IO v, Doub_I s)
{ sub_eq_vs(&v[0], s, v.size()); }

inline void operator*=(vecComp_IO v, Doub_I s)
{ times_eq_vs(&v[0], s, v.size()); }

inline void operator/=(vecComp_IO v, Doub_I s)
{ div_eq_vs(&v[0], s, v.size()); }


inline void operator+=(vecComp_IO v, Comp_I s)
{ add_eq_vs(&v[0], s, v.size()); }

inline void operator-=(vecComp_IO v, Comp_I s)
{ sub_eq_vs(&v[0], s, v.size()); }

inline void operator*=(vecComp_IO v, Comp_I s)
{ times_eq_vs(&v[0], s, v.size()); }

inline void operator/=(vecComp_IO v, Comp_I s)
{ div_eq_vs(&v[0], s, v.size()); }

inline void operator+=(SvbaseInt_IO v, Int_I s)
{ add_eq_vs(&v[0], s, v.size()); }

inline void operator-=(SvbaseInt_IO v, Int_I s)
{ sub_eq_vs(&v[0], s, v.size()); }

inline void operator*=(SvbaseInt_IO v, Int_I s)
{ times_eq_vs(&v[0], s, v.size()); }

inline void operator/=(SvbaseInt_IO v, Int_I s)
{ div_eq_vs(&v[0], s, v.size()); }

inline void operator+=(SvbaseLlong_IO v, Llong_I s)
{ add_eq_vs(&v[0], s, v.size()); }

inline void operator-=(SvbaseLlong_IO v, Llong_I s)
{ sub_eq_vs(&v[0], s, v.size()); }

inline void operator*=(SvbaseLlong_IO v, Llong_I s)
{ times_eq_vs(&v[0], s, v.size()); }

inline void operator/=(SvbaseLlong_IO v, Llong_I s)
{ div_eq_vs(&v[0], s, v.size()); }

inline void operator+=(SvbaseDoub_IO v, Doub_I s)
{ add_eq_vs(&v[0], s, v.size()); }

inline void operator-=(SvbaseDoub_IO v, Doub_I s)
{ sub_eq_vs(&v[0], s, v.size()); }

inline void operator*=(SvbaseDoub_IO v, Doub_I s)
{ times_eq_vs(&v[0], s, v.size()); }

inline void operator/=(SvbaseDoub_IO v, Doub_I s)
{ div_eq_vs(&v[0], s, v.size()); }


inline void operator+=(SvbaseComp_IO v, Doub_I s)
{ add_eq_vs(&v[0], s, v.size()); }

inline void operator-=(SvbaseComp_IO v, Doub_I s)
{ sub_eq_vs(&v[0], s, v.size()); }

inline void operator*=(SvbaseComp_IO v, Doub_I s)
{ times_eq_vs(&v[0], s, v.size()); }

inline void operator/=(SvbaseComp_IO v, Doub_I s)
{ div_eq_vs(&v[0], s, v.size()); }

inline void operator+=(SvbaseComp_IO v, Comp_I s)
{ add_eq_vs(&v[0], s, v.size()); }

inline void operator-=(SvbaseComp_IO v, Comp_I s)
{ sub_eq_vs(&v[0], s, v.size()); }

inline void operator*=(SvbaseComp_IO v, Comp_I s)
{ times_eq_vs(&v[0], s, v.size()); }

inline void operator/=(SvbaseComp_IO v, Comp_I s)
{ div_eq_vs(&v[0], s, v.size()); }


inline void operator+=(DvecComp_IO v, Doub_I s)
{ add_eq_vs(v.p(), s, v.size(), v.step()); }

inline void operator-=(DvecComp_IO v, Doub_I s)
{ sub_eq_vs(v.p(), s, v.size(), v.step()); }

inline void operator*=(DvecComp_IO v, Doub_I s)
{ times_eq_vs(v.p(), s, v.size(), v.step()); }

inline void operator/=(DvecComp_IO v, Doub_I s)
{ div_eq_vs(v.p(), s, v.size(), v.step()); }


inline void operator+=(DcmatDoub_IO v, Doub_I s)
{
	for (Long j = 0; j < v.n1(); ++j)
		add_eq_vs(&v(0,j), s, v.n0());
}

inline void operator-=(DcmatDoub_IO v, Doub_I s)
{
	for (Long j = 0; j < v.n1(); ++j)
		sub_eq_vs(&v(0,j), s, v.n0());
}

inline void operator*=(DcmatDoub_IO v, Doub_I s)
{
	for (Long j = 0; j < v.n1(); ++j)
		times_eq_vs(&v(0,j), s, v.n0());
}

inline void operator/=(DcmatDoub_IO v, Doub_I s)
{
	for (Long j = 0; j < v.n1(); ++j)
		div_eq_vs(&v(0,j), s, v.n0());
}


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
		times_eq_vs(&v(0,j), s, v.n0());
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
		times_eq_vs(&v(0,j), s, v.n0());
}

inline void operator/=(DcmatComp_IO v, Comp_I s)
{
	for (Long j = 0; j < v.n1(); ++j)
		div_eq_vs(&v(0,j), s, v.n0());
}


inline void operator+=(vvecInt_IO v, Int_I s)
{ for (auto &e : v) e += s; }

inline void operator-=(vvecInt_IO v, Int_I s)
{ for (auto &e : v) e -= s; }

inline void operator*=(vvecInt_IO v, Int_I s)
{ for (auto &e : v) e *= s; }

inline void operator/=(vvecInt_IO v, Int_I s)
{ for (auto &e : v) e /= s; }

inline void operator+=(vvecLlong_IO v, Llong_I s)
{ for (auto &e : v) e += s; }

inline void operator-=(vvecLlong_IO v, Llong_I s)
{ for (auto &e : v) e -= s; }

inline void operator*=(vvecLlong_IO v, Llong_I s)
{ for (auto &e : v) e *= s; }

inline void operator/=(vvecLlong_IO v, Llong_I s)
{ for (auto &e : v) e /= s; }

inline void operator+=(vvecDoub_IO v, Doub_I s)
{ for (auto &e : v) e += s; }

inline void operator-=(vvecDoub_IO v, Doub_I s)
{ for (auto &e : v) e -= s; }

inline void operator*=(vvecDoub_IO v, Doub_I s)
{ for (auto &e : v) e *= s; }

inline void operator/=(vvecDoub_IO v, Doub_I s)
{ for (auto &e : v) e /= s; }

inline void operator+=(Cmat3Doub_IO v, Doub_I s)
{ add_eq_vs(&v[0], s, v.size()); }

inline void operator-=(Cmat3Doub_IO v, Doub_I s)
{ sub_eq_vs(&v[0], s, v.size()); }

inline void operator*=(Cmat3Doub_IO v, Doub_I s)
{ times_eq_vs(&v[0], s, v.size()); }

inline void operator/=(Cmat3Doub_IO v, Doub_I s)
{ div_eq_vs(&v[0], s, v.size()); }

inline void operator+=(Cmat3Comp_IO v, Doub_I s)
{ add_eq_vs(&v[0], s, v.size()); }

inline void operator-=(Cmat3Comp_IO v, Doub_I s)
{ sub_eq_vs(&v[0], s, v.size()); }

inline void operator*=(Cmat3Comp_IO v, Doub_I s)
{ times_eq_vs(&v[0], s, v.size()); }

inline void operator/=(Cmat3Comp_IO v, Doub_I s)
{ div_eq_vs(&v[0], s, v.size()); }

inline void operator+=(Cmat3Comp_IO v, Comp_I s)
{ add_eq_vs(&v[0], s, v.size()); }

inline void operator-=(Cmat3Comp_IO v, Comp_I s)
{ sub_eq_vs(&v[0], s, v.size()); }

inline void operator*=(Cmat3Comp_IO v, Comp_I s)
{ times_eq_vs(&v[0], s, v.size()); }

inline void operator/=(Cmat3Comp_IO v, Comp_I s)
{ div_eq_vs(&v[0], s, v.size()); }


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

inline void times_eq_vv(Int *v, const Int *v1, Long_I N)
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

inline void times_eq_vv(Llong *v, const Llong *v1, Long_I N)
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

inline void times_eq_vv(Doub *v, const Doub *v1, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		v[i] *= v1[i];
}

inline void div_eq_vv(Doub *v, const Doub *v1, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		v[i] /= v1[i];
}

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

inline void times_eq_vv(Comp *v, const Doub *v1, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		v[i] *= v1[i];
}

inline void div_eq_vv(Comp *v, const Doub *v1, Long_I N)
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

inline void times_eq_vv(Comp *v, const Comp *v1, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		v[i] *= v1[i];
}

inline void div_eq_vv(Comp *v, const Comp *v1, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		v[i] /= v1[i];
}

inline void add_eq_vv(Comp *v, const Imag *v1, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		v[i] += v1[i];
}

inline void sub_eq_vv(Comp *v, const Imag *v1, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		v[i] -= v1[i];
}

inline void times_eq_vv(Comp *v, const Imag *v1, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		v[i] *= v1[i];
}

inline void div_eq_vv(Comp *v, const Imag *v1, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		v[i] /= v1[i];
}


inline void operator+=(vecInt_O v, vecInt_I v1)
{
	assert_same_shape1(v, v1);
	add_eq_vv(&v[0], &v1[0], v1.size());
}

inline void operator-=(vecInt_O v, vecInt_I v1)
{
	assert_same_shape1(v, v1);
	sub_eq_vv(&v[0], &v1[0], v1.size());
}

inline void operator*=(vecInt_O v, vecInt_I v1)
{
	assert_same_shape1(v, v1);
	times_eq_vv(&v[0], &v1[0], v1.size());
}

inline void operator/=(vecInt_O v, vecInt_I v1)
{
	assert_same_shape1(v, v1);
	div_eq_vv(&v[0], &v1[0], v1.size());
}

inline void operator+=(vecLlong_O v, vecLlong_I v1)
{
	assert_same_shape1(v, v1);
	add_eq_vv(&v[0], &v1[0], v1.size());
}

inline void operator-=(vecLlong_O v, vecLlong_I v1)
{
	assert_same_shape1(v, v1);
	sub_eq_vv(&v[0], &v1[0], v1.size());
}

inline void operator*=(vecLlong_O v, vecLlong_I v1)
{
	assert_same_shape1(v, v1);
	times_eq_vv(&v[0], &v1[0], v1.size());
}

inline void operator/=(vecLlong_O v, vecLlong_I v1)
{
	assert_same_shape1(v, v1);
	div_eq_vv(&v[0], &v1[0], v1.size());
}

inline void operator+=(vecDoub_O v, vecDoub_I v1)
{
	assert_same_shape1(v, v1);
	add_eq_vv(&v[0], &v1[0], v1.size());
}

inline void operator-=(vecDoub_O v, vecDoub_I v1)
{
	assert_same_shape1(v, v1);
	sub_eq_vv(&v[0], &v1[0], v1.size());
}

inline void operator*=(vecDoub_O v, vecDoub_I v1)
{
	assert_same_shape1(v, v1);
	times_eq_vv(&v[0], &v1[0], v1.size());
}

inline void operator/=(vecDoub_O v, vecDoub_I v1)
{
	assert_same_shape1(v, v1);
	div_eq_vv(&v[0], &v1[0], v1.size());
}


inline void operator+=(SvbaseInt_O v, SvbaseInt_I v1)
{
	assert_same_shape1(v, v1);
	add_eq_vv(&v[0], &v1[0], v1.size());
}

inline void operator-=(SvbaseInt_O v, SvbaseInt_I v1)
{
	assert_same_shape1(v, v1);
	sub_eq_vv(&v[0], &v1[0], v1.size());
}

inline void operator*=(SvbaseInt_O v, SvbaseInt_I v1)
{
	assert_same_shape1(v, v1);
	times_eq_vv(&v[0], &v1[0], v1.size());
}

inline void operator/=(SvbaseInt_O v, SvbaseInt_I v1)
{
	assert_same_shape1(v, v1);
	div_eq_vv(&v[0], &v1[0], v1.size());
}

inline void operator+=(SvbaseLlong_O v, SvbaseLlong_I v1)
{
	assert_same_shape1(v, v1);
	add_eq_vv(&v[0], &v1[0], v1.size());
}

inline void operator-=(SvbaseLlong_O v, SvbaseLlong_I v1)
{
	assert_same_shape1(v, v1);
	sub_eq_vv(&v[0], &v1[0], v1.size());
}

inline void operator*=(SvbaseLlong_O v, SvbaseLlong_I v1)
{
	assert_same_shape1(v, v1);
	times_eq_vv(&v[0], &v1[0], v1.size());
}

inline void operator/=(SvbaseLlong_O v, SvbaseLlong_I v1)
{
	assert_same_shape1(v, v1);
	div_eq_vv(&v[0], &v1[0], v1.size());
}

inline void operator+=(SvbaseDoub_O v, SvbaseDoub_I v1)
{
	assert_same_shape1(v, v1);
	add_eq_vv(&v[0], &v1[0], v1.size());
}

inline void operator-=(SvbaseDoub_O v, SvbaseDoub_I v1)
{
	assert_same_shape1(v, v1);
	sub_eq_vv(&v[0], &v1[0], v1.size());
}

inline void operator*=(SvbaseDoub_O v, SvbaseDoub_I v1)
{
	assert_same_shape1(v, v1);
	times_eq_vv(&v[0], &v1[0], v1.size());
}

inline void operator/=(SvbaseDoub_O v, SvbaseDoub_I v1)
{
	assert_same_shape1(v, v1);
	div_eq_vv(&v[0], &v1[0], v1.size());
}


inline void operator+=(SvbaseComp_O v, SvbaseDoub_I v1)
{
	assert_same_shape1(v, v1);
	add_eq_vv(&v[0], &v1[0], v1.size());
}

inline void operator-=(SvbaseComp_O v, SvbaseDoub_I v1)
{
	assert_same_shape1(v, v1);
	sub_eq_vv(&v[0], &v1[0], v1.size());
}

inline void operator*=(SvbaseComp_O v, SvbaseDoub_I v1)
{
	assert_same_shape1(v, v1);
	times_eq_vv(&v[0], &v1[0], v1.size());
}

inline void operator/=(SvbaseComp_O v, SvbaseDoub_I v1)
{
	assert_same_shape1(v, v1);
	div_eq_vv(&v[0], &v1[0], v1.size());
}

inline void operator+=(SvbaseComp_O v, SvbaseComp_I v1)
{
	assert_same_shape1(v, v1);
	add_eq_vv(&v[0], &v1[0], v1.size());
}

inline void operator-=(SvbaseComp_O v, SvbaseComp_I v1)
{
	assert_same_shape1(v, v1);
	sub_eq_vv(&v[0], &v1[0], v1.size());
}

inline void operator*=(SvbaseComp_O v, SvbaseComp_I v1)
{
	assert_same_shape1(v, v1);
	times_eq_vv(&v[0], &v1[0], v1.size());
}

inline void operator/=(SvbaseComp_O v, SvbaseComp_I v1)
{
	assert_same_shape1(v, v1);
	div_eq_vv(&v[0], &v1[0], v1.size());
}



inline void operator+=(DvecDoub_O v, SvbaseDoub_I v1)
{
	assert_same_shape1(v, v1);
	for (Long i = 0; i < v.size(); ++i)
		v[i] += v1[i];
}

inline void operator-=(DvecDoub_O v, SvbaseDoub_I v1)
{
	assert_same_shape1(v, v1);
	for (Long i = 0; i < v.size(); ++i)
		v[i] -= v1[i];
}

inline void operator*=(DvecDoub_O v, SvbaseDoub_I v1)
{
	assert_same_shape1(v, v1);
	for (Long i = 0; i < v.size(); ++i)
		v[i] *= v1[i];
}

inline void operator/=(DvecDoub_O v, SvbaseDoub_I v1)
{
	assert_same_shape1(v, v1);
	for (Long i = 0; i < v.size(); ++i)
		v[i] /= v1[i];
}


inline void operator+=(DvecComp_O v, SvbaseComp_I v1)
{
	assert_same_shape1(v, v1);
	for (Long i = 0; i < v.size(); ++i)
		v[i] += v1[i];
}

inline void operator-=(DvecComp_O v, SvbaseComp_I v1)
{
	assert_same_shape1(v, v1);
	for (Long i = 0; i < v.size(); ++i)
		v[i] -= v1[i];
}

inline void operator*=(DvecComp_O v, SvbaseComp_I v1)
{
	assert_same_shape1(v, v1);
	for (Long i = 0; i < v.size(); ++i)
		v[i] *= v1[i];
}

inline void operator/=(DvecComp_O v, SvbaseComp_I v1)
{
	assert_same_shape1(v, v1);
	for (Long i = 0; i < v.size(); ++i)
		v[i] /= v1[i];
}


inline void operator+=(DvecComp_O v, SvbaseDoub_I v1)
{
	assert_same_shape1(v, v1);
	for (Long i = 0; i < v.size(); ++i)
		v[i] += v1[i];
}

inline void operator-=(DvecComp_O v, SvbaseDoub_I v1)
{
	assert_same_shape1(v, v1);
	for (Long i = 0; i < v.size(); ++i)
		v[i] -= v1[i];
}

inline void operator*=(DvecComp_O v, SvbaseDoub_I v1)
{
	assert_same_shape1(v, v1);
	for (Long i = 0; i < v.size(); ++i)
		v[i] *= v1[i];
}

inline void operator/=(DvecComp_O v, SvbaseDoub_I v1)
{
	assert_same_shape1(v, v1);
	for (Long i = 0; i < v.size(); ++i)
		v[i] /= v1[i];
}


inline void operator+=(DvecComp_O v, DvecComp_I v1)
{
	assert_same_shape1(v, v1);
	for (Long i = 0; i < v.size(); ++i)
		v[i] += v1[i];
}

inline void operator-=(DvecComp_O v, DvecComp_I v1)
{
	assert_same_shape1(v, v1);
	for (Long i = 0; i < v.size(); ++i)
		v[i] -= v1[i];
}

inline void operator*=(DvecComp_O v, DvecComp_I v1)
{
	assert_same_shape1(v, v1);
	for (Long i = 0; i < v.size(); ++i)
		v[i] *= v1[i];
}

inline void operator/=(DvecComp_O v, DvecComp_I v1)
{
	assert_same_shape1(v, v1);
	for (Long i = 0; i < v.size(); ++i)
		v[i] /= v1[i];
}


inline void operator+=(MatDoub_O v, MatDoub_I v1)
{
	assert_same_shape1(v, v1);
	add_eq_vv(&v[0], &v1[0], v1.size());
}

inline void operator-=(MatDoub_O v, MatDoub_I v1)
{
	assert_same_shape1(v, v1);
	sub_eq_vv(&v[0], &v1[0], v1.size());
}

inline void operator*=(MatDoub_O v, MatDoub_I v1)
{
	assert_same_shape1(v, v1);
	times_eq_vv(&v[0], &v1[0], v1.size());
}

inline void operator/=(MatDoub_O v, MatDoub_I v1)
{
	assert_same_shape1(v, v1);
	div_eq_vv(&v[0], &v1[0], v1.size());
}

inline void operator+=(MatComp_O v, MatComp_I v1)
{
	assert_same_shape1(v, v1);
	add_eq_vv(&v[0], &v1[0], v1.size());
}

inline void operator-=(MatComp_O v, MatComp_I v1)
{
	assert_same_shape1(v, v1);
	sub_eq_vv(&v[0], &v1[0], v1.size());
}

inline void operator*=(MatComp_O v, MatComp_I v1)
{
	assert_same_shape1(v, v1);
	times_eq_vv(&v[0], &v1[0], v1.size());
}

inline void operator/=(MatComp_O v, MatComp_I v1)
{
	assert_same_shape1(v, v1);
	div_eq_vv(&v[0], &v1[0], v1.size());
}

inline void operator+=(DcmatComp_O v, DcmatDoub_I v1) // slow!
{
	assert_same_shape2(v, v1);
	for (Long j = 0; j < v.n1(); ++j)
		for (Long i = 0; i < v.n0(); ++i)
			v(i, j) += v1(i, j);
}

inline void operator-=(DcmatComp_O v, DcmatDoub_I v1) // slow!
{
	assert_same_shape2(v, v1);
	for (Long j = 0; j < v.n1(); ++j)
		for (Long i = 0; i < v.n0(); ++i)
			v(i, j) -= v1(i, j);
}

inline void operator*=(DcmatComp_O v, DcmatDoub_I v1) // slow!
{
	assert_same_shape2(v, v1);
	for (Long j = 0; j < v.n1(); ++j)
		for (Long i = 0; i < v.n0(); ++i)
			v(i, j) *= v1(i, j);
}

inline void operator/=(DcmatComp_O v, DcmatDoub_I v1) // slow!
{
	assert_same_shape2(v, v1);
	for (Long j = 0; j < v.n1(); ++j)
		for (Long i = 0; i < v.n0(); ++i)
			v(i, j) /= v1(i, j);
}


inline void operator+=(Mat3Doub_O v, Mat3Doub_I v1)
{
	assert_same_shape1(v, v1);
	add_eq_vv(&v[0], &v1[0], v1.size());
}

inline void operator-=(Mat3Doub_O v, Mat3Doub_I v1)
{
	assert_same_shape1(v, v1);
	sub_eq_vv(&v[0], &v1[0], v1.size());
}

inline void operator*=(Mat3Doub_O v, Mat3Doub_I v1)
{
	assert_same_shape1(v, v1);
	times_eq_vv(&v[0], &v1[0], v1.size());
}

inline void operator/=(Mat3Doub_O v, Mat3Doub_I v1)
{
	assert_same_shape1(v, v1);
	div_eq_vv(&v[0], &v1[0], v1.size());
}

inline void operator+=(Mat3Comp_O v, Mat3Comp_I v1)
{
	assert_same_shape1(v, v1);
	add_eq_vv(&v[0], &v1[0], v1.size());
}

inline void operator-=(Mat3Comp_O v, Mat3Comp_I v1)
{
	assert_same_shape1(v, v1);
	sub_eq_vv(&v[0], &v1[0], v1.size());
}

inline void operator*=(Mat3Comp_O v, Mat3Comp_I v1)
{
	assert_same_shape1(v, v1);
	times_eq_vv(&v[0], &v1[0], v1.size());
}

inline void operator/=(Mat3Comp_O v, Mat3Comp_I v1)
{
	assert_same_shape1(v, v1);
	div_eq_vv(&v[0], &v1[0], v1.size());
}


inline void times_eq_par(SvbaseComp_O v, Doub_I s)
{
	Long N = v.size();
#pragma omp parallel for
	for (Long i = 0; i < N; ++i)
		v[i] *= s;
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

inline void add_vvs(Llong *v, const Llong *v1, Llong_I s, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		v[i] = v1[i] + s;
}

inline void add_vvs(Llong *v, const Llong *v1, Llong_I s, Long_I N, Long_I step1, Long_I step2)
{
	for (Long i = 0; i < N; ++i) {
		*v = *v1 + s;
		v += step1; v1 += step2;
	}
}

inline void sub_vvs(Llong *v, const Llong *v1, Llong_I s, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		v[i] = v1[i] - s;
}

inline void sub_vvs(Llong *v, const Llong *v1, Llong_I s, Long_I N, Long_I step1, Long_I step2)
{
	for (Long i = 0; i < N; ++i) {
		*v = *v1 - s;
		v += step1; v1 += step2;
	}
}

inline void times_vvs(Llong *v, const Llong *v1, Llong_I s, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		v[i] = v1[i] * s;
}

inline void times_vvs(Llong *v, const Llong *v1, Llong_I s, Long_I N, Long_I step1, Long_I step2)
{
	for (Long i = 0; i < N; ++i) {
		*v = *v1 * s;
		v += step1; v1 += step2;
	}
}

inline void div_vvs(Llong *v, const Llong *v1, Llong_I s, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		v[i] = v1[i] / s;
}

inline void div_vvs(Llong *v, const Llong *v1, Llong_I s, Long_I N, Long_I step1, Long_I step2)
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

inline void div_vvs(Doub *v, const Doub *v1, Doub_I s, Long_I N)
{
	Doub inv_s = 1./s;
	times_vvs(v, v1, inv_s, N);
}

inline void div_vvs(Doub *v, const Doub *v1, Doub_I s, Long_I N, Long_I step, Long_I step1)
{
	Doub inv_s = 1./s;
	times_vvs(v, v1, inv_s, N, step, step1);
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

inline void div_vvs(Comp *v, const Doub *v1, Comp_I s, Long_I N)
{
	Comp inv_s = 1./s;
	times_vvs(v, v1, inv_s, N);
}

inline void div_vvs(Comp *v, const Doub *v1, Comp_I s, Long_I N, Long_I step, Long_I step1)
{
	Comp inv_s = 1./s;
	times_vvs(v, v1, inv_s, N, step, step1);
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

inline void div_vvs(Comp *v, const Comp *v1, Doub_I s, Long_I N)
{
	Doub inv_s = 1./s;
	times_vvs(v, v1, inv_s, N);
}

inline void div_vvs(Comp *v, const Comp *v1, Doub_I s, Long_I N, Long_I step, Long_I step1)
{
	Doub inv_s = 1./s;
	times_vvs(v, v1, inv_s, N, step, step1);
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

inline void div_vvs(Comp *v, const Comp *v1, Comp_I s, Long_I N)
{
	Comp inv_s = 1./s;
	times_vvs(v, v1, inv_s, N);
}

inline void div_vvs(Comp *v, const Comp *v1, Comp_I s, Long_I N, Long_I step, Long_I step1)
{
	Comp inv_s = 1./s;
	times_vvs(v, v1, inv_s, N, step, step1);
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

inline void div_vvs(Comp *v, const Doub *v1, Imag_I s, Long_I N)
{
	Imag inv_s = 1./s;
	times_vvs(v, v1, inv_s, N);
}

inline void div_vvs(Comp *v, const Doub *v1, Imag_I s, Long_I N, Long_I step, Long_I step1)
{
	Imag inv_s = 1./s;
	times_vvs(v, v1, inv_s, N, step, step1);
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

inline void sub_vsv(Llong *v, const Llong &s, const Llong *v1, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		v[i] = s - v1[i];
}

inline void sub_vsv(Llong *v, const Llong &s, const Llong *v1, Long_I N, Long_I step, Long_I step1)
{
	for (Long i = 0; i < N; ++i) {
		*v = s - *v1;
		v += step; v1 += step1;
	}
}

inline void div_vsv(Llong *v, const Llong &s, const Llong *v1, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		v[i] = s / v1[i];
}

inline void div_vsv(Llong *v, const Llong &s, const Llong *v1, Long_I N, Long_I step, Long_I step1)
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

inline void add_vvv(Llong *v, const Llong *v1, const Llong *v2, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		v[i] = v1[i] + v2[i];
}

inline void add_vvv(Llong *v, const Llong *v1, const Llong *v2, Long_I N, Long_I step, Long_I step1, Long_I step2)
{
	for (Long i = 0; i < N; ++i) {
		*v = *v1 + *v2;
		v += step; v1 += step1; v2 += step2;
	}
}

inline void sub_vvv(Llong *v, const Llong *v1, const Llong *v2, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		v[i] = v1[i] - v2[i];
}

inline void sub_vvv(Llong *v, const Llong *v1, const Llong *v2, Long_I N, Long_I step, Long_I step1, Long_I step2)
{
	for (Long i = 0; i < N; ++i) {
		*v = *v1 - *v2;
		v += step; v1 += step1; v2 += step2;
	}
}

inline void times_vvv(Llong *v, const Llong *v1, const Llong *v2, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		v[i] = v1[i] * v2[i];
}

inline void times_vvv(Llong *v, const Llong *v1, const Llong *v2, Long_I N, Long_I step, Long_I step1, Long_I step2)
{
	for (Long i = 0; i < N; ++i) {
		*v = *v1 * *v2;
		v += step; v1 += step1; v2 += step2;
	}
}

inline void div_vvv(Llong *v, const Llong *v1, const Llong *v2, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		v[i] = v1[i] / v2[i];
}

inline void div_vvv(Llong *v, const Llong *v1, const Llong *v2, Long_I N, Long_I step, Long_I step1, Long_I step2)
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


inline void add_vvv(Comp *v, const Doub *v1, const Imag *v2, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		v[i] = v1[i] + v2[i];
}

inline void add_vvv(Comp *v, const Doub *v1, const Imag *v2, Long_I N, Long_I step, Long_I step1, Long_I step2)
{
	for (Long i = 0; i < N; ++i) {
		*v = *v1 + *v2;
		v += step; v1 += step1; v2 += step2;
	}
}

inline void sub_vvv(Comp *v, const Doub *v1, const Imag *v2, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		v[i] = v1[i] - v2[i];
}

inline void sub_vvv(Comp *v, const Doub *v1, const Imag *v2, Long_I N, Long_I step, Long_I step1, Long_I step2)
{
	for (Long i = 0; i < N; ++i) {
		*v = *v1 - *v2;
		v += step; v1 += step1; v2 += step2;
	}
}

inline void times_vvv(Comp *v, const Doub *v1, const Imag *v2, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		v[i] = v1[i] * v2[i];
}

inline void times_vvv(Comp *v, const Doub *v1, const Imag *v2, Long_I N, Long_I step, Long_I step1, Long_I step2)
{
	for (Long i = 0; i < N; ++i) {
		*v = *v1 * *v2;
		v += step; v1 += step1; v2 += step2;
	}
}

inline void div_vvv(Comp *v, const Doub *v1, const Imag *v2, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		v[i] = v1[i] / v2[i];
}

inline void div_vvv(Comp *v, const Doub *v1, const Imag *v2, Long_I N, Long_I step, Long_I step1, Long_I step2)
{
	for (Long i = 0; i < N; ++i) {
		*v = *v1 / *v2;
		v += step; v1 += step1; v2 += step2;
	}
}



inline void add(vecInt_O v, vecInt_I v1, Int_I s)
{
	assert_same_shape1(v, v1);
	add_vvs(&v[0], &v1[0], s, v1.size());
}

inline void add(vecInt_O v, Int_I s, vecInt_I v1)
{ add(v, v1, s); }

inline void sub(vecInt_O v, vecInt_I v1, Int_I s)
{
	assert_same_shape1(v, v1);
	sub_vvs(&v[0], &v1[0], s, v1.size());
}

inline void sub(vecInt_O v, Int_I s, vecInt_I v1)
{
	assert_same_shape1(v, v1);
	sub_vsv(&v[0], s, &v1[0], v1.size());
}

inline void times(vecInt_O v, vecInt_I v1, Int_I s)
{
	assert_same_shape1(v, v1);
	times_vvs(&v[0], &v1[0], s, v1.size());
}

inline void times(vecInt_O v, Int_I s, vecInt_I v1)
{ times(v, v1, s); }

inline void div(vecInt_O v, vecInt_I v1, Int_I s)
{
	assert_same_shape1(v, v1);
	div_vvs(&v[0], &v1[0], s, v1.size());
}

inline void div(vecInt_O v, Int_I s, vecInt_I v1)
{
	assert_same_shape1(v, v1);
	div_vsv(&v[0], s, &v1[0], v1.size());
}

inline void add(vecLlong_O v, vecLlong_I v1, Llong_I s)
{
	assert_same_shape1(v, v1);
	add_vvs(&v[0], &v1[0], s, v1.size());
}

inline void add(vecLlong_O v, Llong_I s, vecLlong_I v1)
{ add(v, v1, s); }

inline void sub(vecLlong_O v, vecLlong_I v1, Llong_I s)
{
	assert_same_shape1(v, v1);
	sub_vvs(&v[0], &v1[0], s, v1.size());
}

inline void sub(vecLlong_O v, Llong_I s, vecLlong_I v1)
{
	assert_same_shape1(v, v1);
	sub_vsv(&v[0], s, &v1[0], v1.size());
}

inline void times(vecLlong_O v, vecLlong_I v1, Llong_I s)
{
	assert_same_shape1(v, v1);
	times_vvs(&v[0], &v1[0], s, v1.size());
}

inline void times(vecLlong_O v, Llong_I s, vecLlong_I v1)
{ times(v, v1, s); }

inline void div(vecLlong_O v, vecLlong_I v1, Llong_I s)
{
	assert_same_shape1(v, v1);
	div_vvs(&v[0], &v1[0], s, v1.size());
}

inline void div(vecLlong_O v, Llong_I s, vecLlong_I v1)
{
	assert_same_shape1(v, v1);
	div_vsv(&v[0], s, &v1[0], v1.size());
}

inline void add(SvbaseInt_O v, SvbaseInt_I v1, Int_I s)
{
	assert_same_shape1(v, v1);
	add_vvs(&v[0], &v1[0], s, v1.size());
}

inline void add(SvbaseInt_O v, Int_I s, SvbaseInt_I v1)
{ add(v, v1, s); }

inline void sub(SvbaseInt_O v, SvbaseInt_I v1, Int_I s)
{
	assert_same_shape1(v, v1);
	sub_vvs(&v[0], &v1[0], s, v1.size());
}

inline void sub(SvbaseInt_O v, Int_I s, SvbaseInt_I v1)
{
	assert_same_shape1(v, v1);
	sub_vsv(&v[0], s, &v1[0], v1.size());
}

inline void times(SvbaseInt_O v, SvbaseInt_I v1, Int_I s)
{
	assert_same_shape1(v, v1);
	times_vvs(&v[0], &v1[0], s, v1.size());
}

inline void times(SvbaseInt_O v, Int_I s, SvbaseInt_I v1)
{ times(v, v1, s); }

inline void div(SvbaseInt_O v, SvbaseInt_I v1, Int_I s)
{
	assert_same_shape1(v, v1);
	div_vvs(&v[0], &v1[0], s, v1.size());
}

inline void div(SvbaseInt_O v, Int_I s, SvbaseInt_I v1)
{
	assert_same_shape1(v, v1);
	div_vsv(&v[0], s, &v1[0], v1.size());
}

inline void add(SvbaseLlong_O v, SvbaseLlong_I v1, Llong_I s)
{
	assert_same_shape1(v, v1);
	add_vvs(&v[0], &v1[0], s, v1.size());
}

inline void add(SvbaseLlong_O v, Llong_I s, SvbaseLlong_I v1)
{ add(v, v1, s); }

inline void sub(SvbaseLlong_O v, SvbaseLlong_I v1, Llong_I s)
{
	assert_same_shape1(v, v1);
	sub_vvs(&v[0], &v1[0], s, v1.size());
}

inline void sub(SvbaseLlong_O v, Llong_I s, SvbaseLlong_I v1)
{
	assert_same_shape1(v, v1);
	sub_vsv(&v[0], s, &v1[0], v1.size());
}

inline void times(SvbaseLlong_O v, SvbaseLlong_I v1, Llong_I s)
{
	assert_same_shape1(v, v1);
	times_vvs(&v[0], &v1[0], s, v1.size());
}

inline void times(SvbaseLlong_O v, Llong_I s, SvbaseLlong_I v1)
{ times(v, v1, s); }

inline void div(SvbaseLlong_O v, SvbaseLlong_I v1, Llong_I s)
{
	assert_same_shape1(v, v1);
	div_vvs(&v[0], &v1[0], s, v1.size());
}

inline void div(SvbaseLlong_O v, Llong_I s, SvbaseLlong_I v1)
{
	assert_same_shape1(v, v1);
	div_vsv(&v[0], s, &v1[0], v1.size());
}

inline void add(SvbaseDoub_O v, SvbaseDoub_I v1, Doub_I s)
{
	assert_same_shape1(v, v1);
	add_vvs(&v[0], &v1[0], s, v1.size());
}

inline void add(SvbaseDoub_O v, Doub_I s, SvbaseDoub_I v1)
{ add(v, v1, s); }

inline void sub(SvbaseDoub_O v, SvbaseDoub_I v1, Doub_I s)
{
	assert_same_shape1(v, v1);
	sub_vvs(&v[0], &v1[0], s, v1.size());
}

inline void sub(SvbaseDoub_O v, Doub_I s, SvbaseDoub_I v1)
{
	assert_same_shape1(v, v1);
	sub_vsv(&v[0], s, &v1[0], v1.size());
}

inline void times(SvbaseDoub_O v, SvbaseDoub_I v1, Doub_I s)
{
	assert_same_shape1(v, v1);
	times_vvs(&v[0], &v1[0], s, v1.size());
}

inline void times(SvbaseDoub_O v, Doub_I s, SvbaseDoub_I v1)
{ times(v, v1, s); }

inline void div(SvbaseDoub_O v, SvbaseDoub_I v1, Doub_I s)
{
	assert_same_shape1(v, v1);
	div_vvs(&v[0], &v1[0], s, v1.size());
}

inline void div(SvbaseDoub_O v, Doub_I s, SvbaseDoub_I v1)
{
	assert_same_shape1(v, v1);
	div_vsv(&v[0], s, &v1[0], v1.size());
}


inline void add(SvbaseComp_O v, SvbaseDoub_I v1, Doub_I s)
{
	assert_same_shape1(v, v1);
	add_vvs(&v[0], &v1[0], s, v1.size());
}

inline void add(SvbaseComp_O v, Doub_I s, SvbaseDoub_I v1)
{ add(v, v1, s); }

inline void sub(SvbaseComp_O v, SvbaseDoub_I v1, Doub_I s)
{
	assert_same_shape1(v, v1);
	sub_vvs(&v[0], &v1[0], s, v1.size());
}

inline void sub(SvbaseComp_O v, Doub_I s, SvbaseDoub_I v1)
{
	assert_same_shape1(v, v1);
	sub_vsv(&v[0], s, &v1[0], v1.size());
}

inline void times(SvbaseComp_O v, SvbaseDoub_I v1, Doub_I s)
{
	assert_same_shape1(v, v1);
	times_vvs(&v[0], &v1[0], s, v1.size());
}

inline void times(SvbaseComp_O v, Doub_I s, SvbaseDoub_I v1)
{ times(v, v1, s); }

inline void div(SvbaseComp_O v, SvbaseDoub_I v1, Doub_I s)
{
	assert_same_shape1(v, v1);
	div_vvs(&v[0], &v1[0], s, v1.size());
}

inline void div(SvbaseComp_O v, Doub_I s, SvbaseDoub_I v1)
{
	assert_same_shape1(v, v1);
	div_vsv(&v[0], s, &v1[0], v1.size());
}

inline void add(SvbaseComp_O v, SvbaseDoub_I v1, Comp_I s)
{
	assert_same_shape1(v, v1);
	add_vvs(&v[0], &v1[0], s, v1.size());
}

inline void add(SvbaseComp_O v, Comp_I s, SvbaseDoub_I v1)
{ add(v, v1, s); }

inline void sub(SvbaseComp_O v, SvbaseDoub_I v1, Comp_I s)
{
	assert_same_shape1(v, v1);
	sub_vvs(&v[0], &v1[0], s, v1.size());
}

inline void sub(SvbaseComp_O v, Comp_I s, SvbaseDoub_I v1)
{
	assert_same_shape1(v, v1);
	sub_vsv(&v[0], s, &v1[0], v1.size());
}

inline void times(SvbaseComp_O v, SvbaseDoub_I v1, Comp_I s)
{
	assert_same_shape1(v, v1);
	times_vvs(&v[0], &v1[0], s, v1.size());
}

inline void times(SvbaseComp_O v, Comp_I s, SvbaseDoub_I v1)
{ times(v, v1, s); }

inline void div(SvbaseComp_O v, SvbaseDoub_I v1, Comp_I s)
{
	assert_same_shape1(v, v1);
	div_vvs(&v[0], &v1[0], s, v1.size());
}

inline void div(SvbaseComp_O v, Comp_I s, SvbaseDoub_I v1)
{
	assert_same_shape1(v, v1);
	div_vsv(&v[0], s, &v1[0], v1.size());
}

inline void add(SvbaseComp_O v, SvbaseDoub_I v1, Imag_I s)
{
	assert_same_shape1(v, v1);
	add_vvs(&v[0], &v1[0], s, v1.size());
}

inline void add(SvbaseComp_O v, Imag_I s, SvbaseDoub_I v1)
{ add(v, v1, s); }

inline void sub(SvbaseComp_O v, SvbaseDoub_I v1, Imag_I s)
{
	assert_same_shape1(v, v1);
	sub_vvs(&v[0], &v1[0], s, v1.size());
}

inline void sub(SvbaseComp_O v, Imag_I s, SvbaseDoub_I v1)
{
	assert_same_shape1(v, v1);
	sub_vsv(&v[0], s, &v1[0], v1.size());
}

inline void times(SvbaseComp_O v, SvbaseDoub_I v1, Imag_I s)
{
	assert_same_shape1(v, v1);
	times_vvs(&v[0], &v1[0], s, v1.size());
}

inline void times(SvbaseComp_O v, Imag_I s, SvbaseDoub_I v1)
{ times(v, v1, s); }

inline void div(SvbaseComp_O v, SvbaseDoub_I v1, Imag_I s)
{
	assert_same_shape1(v, v1);
	div_vvs(&v[0], &v1[0], s, v1.size());
}

inline void div(SvbaseComp_O v, Imag_I s, SvbaseDoub_I v1)
{
	assert_same_shape1(v, v1);
	div_vsv(&v[0], s, &v1[0], v1.size());
}

inline void add(SvbaseComp_O v, SvbaseComp_I v1, Doub_I s)
{
	assert_same_shape1(v, v1);
	add_vvs(&v[0], &v1[0], s, v1.size());
}

inline void add(SvbaseComp_O v, Doub_I s, SvbaseComp_I v1)
{ add(v, v1, s); }

inline void sub(SvbaseComp_O v, SvbaseComp_I v1, Doub_I s)
{
	assert_same_shape1(v, v1);
	sub_vvs(&v[0], &v1[0], s, v1.size());
}

inline void sub(SvbaseComp_O v, Doub_I s, SvbaseComp_I v1)
{
	assert_same_shape1(v, v1);
	sub_vsv(&v[0], s, &v1[0], v1.size());
}

inline void times(SvbaseComp_O v, SvbaseComp_I v1, Doub_I s)
{
	assert_same_shape1(v, v1);
	times_vvs(&v[0], &v1[0], s, v1.size());
}

inline void times(SvbaseComp_O v, Doub_I s, SvbaseComp_I v1)
{ times(v, v1, s); }

inline void div(SvbaseComp_O v, SvbaseComp_I v1, Doub_I s)
{
	assert_same_shape1(v, v1);
	div_vvs(&v[0], &v1[0], s, v1.size());
}

inline void div(SvbaseComp_O v, Doub_I s, SvbaseComp_I v1)
{
	assert_same_shape1(v, v1);
	div_vsv(&v[0], s, &v1[0], v1.size());
}

inline void add(SvbaseComp_O v, SvbaseComp_I v1, Comp_I s)
{
	assert_same_shape1(v, v1);
	add_vvs(&v[0], &v1[0], s, v1.size());
}

inline void add(SvbaseComp_O v, Comp_I s, SvbaseComp_I v1)
{ add(v, v1, s); }

inline void sub(SvbaseComp_O v, SvbaseComp_I v1, Comp_I s)
{
	assert_same_shape1(v, v1);
	sub_vvs(&v[0], &v1[0], s, v1.size());
}

inline void sub(SvbaseComp_O v, Comp_I s, SvbaseComp_I v1)
{
	assert_same_shape1(v, v1);
	sub_vsv(&v[0], s, &v1[0], v1.size());
}

inline void times(SvbaseComp_O v, SvbaseComp_I v1, Comp_I s)
{
	assert_same_shape1(v, v1);
	times_vvs(&v[0], &v1[0], s, v1.size());
}

inline void times(SvbaseComp_O v, Comp_I s, SvbaseComp_I v1)
{ times(v, v1, s); }

inline void div(SvbaseComp_O v, SvbaseComp_I v1, Comp_I s)
{
	assert_same_shape1(v, v1);
	div_vvs(&v[0], &v1[0], s, v1.size());
}

inline void div(SvbaseComp_O v, Comp_I s, SvbaseComp_I v1)
{
	assert_same_shape1(v, v1);
	div_vsv(&v[0], s, &v1[0], v1.size());
}





inline void add(DvecComp_O v, SvbaseComp_I v1, Doub_I s)
{
	assert_same_shape1(v, v1);
	add_vvs(&v[0], &v1[0], s, v1.size(), v.step(), 1);
}

inline void add(DvecComp_O v, Doub_I s, SvbaseComp_I v1)
{ add(v, v1, s); }

inline void sub(DvecComp_O v, SvbaseComp_I v1, Doub_I s)
{
	assert_same_shape1(v, v1);
	sub_vvs(&v[0], &v1[0], s, v1.size(), v.step(), 1);
}

inline void sub(DvecComp_O v, Doub_I s, SvbaseComp_I v1)
{
	assert_same_shape1(v, v1);
	sub_vsv(&v[0], s, &v1[0], v1.size(), v.step(), 1);
}

inline void times(DvecComp_O v, SvbaseComp_I v1, Doub_I s)
{
	assert_same_shape1(v, v1);
	times_vvs(&v[0], &v1[0], s, v1.size(), v.step(), 1);
}

inline void times(DvecComp_O v, Doub_I s, SvbaseComp_I v1)
{ times(v, v1, s); }

inline void div(DvecComp_O v, SvbaseComp_I v1, Doub_I s)
{
	assert_same_shape1(v, v1);
	div_vvs(&v[0], &v1[0], s, v1.size(), v.step(), 1);
}

inline void div(DvecComp_O v, Doub_I s, SvbaseComp_I v1)
{
	assert_same_shape1(v, v1);
	div_vsv(&v[0], s, &v1[0], v1.size(), v.step(), 1);
}

inline void add(DvecComp_O v, DvecComp_I v1, Doub_I s)
{
	assert_same_shape1(v, v1);
	add_vvs(&v[0], &v1[0], s, v1.size(), v.step(), v1.step());
}

inline void add(DvecComp_O v, Doub_I s, DvecComp_I v1)
{ add(v, v1, s); }

inline void sub(DvecComp_O v, DvecComp_I v1, Doub_I s)
{
	assert_same_shape1(v, v1);
	sub_vvs(&v[0], &v1[0], s, v1.size(), v.step(), v1.step());
}

inline void sub(DvecComp_O v, Doub_I s, DvecComp_I v1)
{
	assert_same_shape1(v, v1);
	sub_vsv(&v[0], s, &v1[0], v1.size(), v.step(), v1.step());
}

inline void times(DvecComp_O v, DvecComp_I v1, Doub_I s)
{
	assert_same_shape1(v, v1);
	times_vvs(&v[0], &v1[0], s, v1.size(), v.step(), v1.step());
}

inline void times(DvecComp_O v, Doub_I s, DvecComp_I v1)
{ times(v, v1, s); }

inline void div(DvecComp_O v, DvecComp_I v1, Doub_I s)
{
	assert_same_shape1(v, v1);
	div_vvs(&v[0], &v1[0], s, v1.size(), v.step(), v1.step());
}

inline void div(DvecComp_O v, Doub_I s, DvecComp_I v1)
{
	assert_same_shape1(v, v1);
	div_vsv(&v[0], s, &v1[0], v1.size(), v.step(), v1.step());
}


inline void add(DvecComp_O v, DvecComp_I v1, Comp_I s)
{
	assert_same_shape1(v, v1);
	add_vvs(&v[0], &v1[0], s, v1.size(), v.step(), v1.step());
}

inline void add(DvecComp_O v, Comp_I s, DvecComp_I v1)
{ add(v, v1, s); }

inline void sub(DvecComp_O v, DvecComp_I v1, Comp_I s)
{
	assert_same_shape1(v, v1);
	sub_vvs(&v[0], &v1[0], s, v1.size(), v.step(), v1.step());
}

inline void sub(DvecComp_O v, Comp_I s, DvecComp_I v1)
{
	assert_same_shape1(v, v1);
	sub_vsv(&v[0], s, &v1[0], v1.size(), v.step(), v1.step());
}

inline void times(DvecComp_O v, DvecComp_I v1, Comp_I s)
{
	assert_same_shape1(v, v1);
	times_vvs(&v[0], &v1[0], s, v1.size(), v.step(), v1.step());
}

inline void times(DvecComp_O v, Comp_I s, DvecComp_I v1)
{ times(v, v1, s); }

inline void div(DvecComp_O v, DvecComp_I v1, Comp_I s)
{
	assert_same_shape1(v, v1);
	div_vvs(&v[0], &v1[0], s, v1.size(), v.step(), v1.step());
}

inline void div(DvecComp_O v, Comp_I s, DvecComp_I v1)
{
	assert_same_shape1(v, v1);
	div_vsv(&v[0], s, &v1[0], v1.size(), v.step(), v1.step());
}


inline void add(DcmatComp_O v, DcmatComp_I v1, Doub_I s)
{
	assert_same_shape2(v, v1);
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
	assert_same_shape2(v, v1);
	Comp *p = v.p(); const Comp *p1 = v1.p();
	for (Long j = 0; j < v.n1(); ++j) {
		sub_vvs(p, p1, s, v.n0());
		p += v.lda(); p1 += v1.lda();
	}
}

inline void sub(DcmatComp_O v, Doub_I s, DcmatComp_I v1)
{
	assert_same_shape2(v, v1);
	Comp *p = v.p(); const Comp *p1 = v1.p();
	for (Long j = 0; j < v.n1(); ++j) {
		sub_vsv(p, s, p1, v.n0());
		p += v.lda(); p1 += v1.lda();
	}
}

inline void times(DcmatComp_O v, DcmatComp_I v1, Doub_I s)
{
	assert_same_shape2(v, v1);
	Comp *p = v.p(); const Comp *p1 = v1.p();
	for (Long j = 0; j < v.n1(); ++j) {
		times_vvs(p, p1, s, v.n0());
		p += v.lda(); p1 += v1.lda();
	}
}

inline void times(DcmatComp_O v, Doub_I s, DcmatComp_I v1)
{ times(v, v1, s); }

inline void div(DcmatComp_O v, DcmatComp_I v1, Doub_I s)
{
	assert_same_shape2(v, v1);
	Comp *p = v.p(); const Comp *p1 = v1.p();
	for (Long j = 0; j < v.n1(); ++j) {
		div_vvs(p, p1, s, v.n0());
		p += v.lda(); p1 += v1.lda();
	}
}

inline void div(DcmatComp_O v, Doub_I s, DcmatComp_I v1)
{
	assert_same_shape2(v, v1);
	Comp *p = v.p(); const Comp *p1 = v1.p();
	for (Long j = 0; j < v.n1(); ++j) {
		div_vsv(p, s, p1, v.n0());
		p += v.lda(); p1 += v1.lda();
	}
}


inline void add(SvecComp_O v, SvbaseComp_I v1, Doub_I s)
{
	assert_same_shape1(v, v1);
	add_vvs(&v[0], &v1[0], s, v1.size());
}

inline void add(SvecComp_O v, Doub_I s, SvbaseComp_I v1)
{ add(v, v1, s); }

inline void sub(SvecComp_O v, SvbaseComp_I v1, Doub_I s)
{
	assert_same_shape1(v, v1);
	sub_vvs(&v[0], &v1[0], s, v1.size());
}

inline void sub(SvecComp_O v, Doub_I s, SvbaseComp_I v1)
{
	assert_same_shape1(v, v1);
	sub_vsv(&v[0], s, &v1[0], v1.size());
}

inline void times(SvecComp_O v, SvbaseComp_I v1, Doub_I s)
{
	assert_same_shape1(v, v1);
	times_vvs(&v[0], &v1[0], s, v1.size());
}

inline void times(SvecComp_O v, Doub_I s, SvbaseComp_I v1)
{ times(v, v1, s); }

inline void div(SvecComp_O v, SvbaseComp_I v1, Doub_I s)
{
	assert_same_shape1(v, v1);
	div_vvs(&v[0], &v1[0], s, v1.size());
}

inline void div(SvecComp_O v, Doub_I s, SvbaseComp_I v1)
{
	assert_same_shape1(v, v1);
	div_vsv(&v[0], s, &v1[0], v1.size());
}

inline void add(SvecComp_O v, DvecComp_I v1, Doub_I s)
{
	assert_same_shape1(v, v1);
	add_vvs(&v[0], &v1[0], s, v1.size(), 1, v1.step());
}

inline void add(SvecComp_O v, Doub_I s, DvecComp_I v1)
{ add(v, v1, s); }

inline void sub(SvecComp_O v, DvecComp_I v1, Doub_I s)
{
	assert_same_shape1(v, v1);
	sub_vvs(&v[0], &v1[0], s, v1.size(), 1, v1.step());
}

inline void sub(SvecComp_O v, Doub_I s, DvecComp_I v1)
{
	assert_same_shape1(v, v1);
	sub_vsv(&v[0], s, &v1[0], v1.size(), 1, v1.step());
}

inline void times(SvecComp_O v, DvecComp_I v1, Doub_I s)
{
	assert_same_shape1(v, v1);
	times_vvs(&v[0], &v1[0], s, v1.size(), 1, v1.step());
}

inline void times(SvecComp_O v, Doub_I s, DvecComp_I v1)
{ times(v, v1, s); }

inline void div(SvecComp_O v, DvecComp_I v1, Doub_I s)
{
	assert_same_shape1(v, v1);
	div_vvs(&v[0], &v1[0], s, v1.size(), 1, v1.step());
}

inline void div(SvecComp_O v, Doub_I s, DvecComp_I v1)
{
	assert_same_shape1(v, v1);
	div_vsv(&v[0], s, &v1[0], v1.size(), 1, v1.step());
}


inline void times_par(SvbaseComp_O v, SvbaseComp_I v1, Doub_I s)
{
	assert_same_shape1(v, v1);
	Long N = v.size();
#pragma omp parallel for
	for (Long i = 0; i < N; ++i)
		v[i] = v1[i] * s;
}

inline void times_par(SvbaseComp_O v, SvbaseComp_I v1, Comp_I s)
{
	assert_same_shape1(v, v1);
	Long N = v.size();
#pragma omp parallel for
	for (Long i = 0; i < N; ++i)
		v[i] = v1[i] * s;
}

inline void times_par(SvbaseComp_O v, DvecComp_I v1, Doub_I s)
{
	assert_same_shape1(v, v1);
	Long N = v.size();
#pragma omp parallel for
	for (Long i = 0; i < N; ++i)
		v[i] = v1[i] * s;
}

inline void times_par(DvecComp_O v, DvecComp_I v1, Doub_I s)
{
	assert_same_shape1(v, v1);
	Long N = v.size();
#pragma omp parallel for
	for (Long i = 0; i < N; ++i)
		v[i] = v1[i] * s;
}

inline void times_par(DvecComp_O v, DvecComp_I v1, Comp_I s)
{
	assert_same_shape1(v, v1);
	Long N = v.size();
#pragma omp parallel for
	for (Long i = 0; i < N; ++i)
		v[i] = v1[i] * s;
}


inline void add(vecInt_O v, vecInt_I v1, vecInt_I v2)
{
	assert_same_shape1(v, v1, v2);
	add_vvv(&v[0], &v1[0], &v2[0], v.size());
}

inline void sub(vecInt_O v, vecInt_I v1, vecInt_I v2)
{
	assert_same_shape1(v, v1, v2);
	sub_vvv(&v[0], &v1[0], &v2[0], v.size());
}

inline void times(vecInt_O v, vecInt_I v1, vecInt_I v2)
{
	assert_same_shape1(v, v1, v2);
	times_vvv(&v[0], &v1[0], &v2[0], v.size());
}

inline void div(vecInt_O v, vecInt_I v1, vecInt_I v2)
{
	assert_same_shape1(v, v1, v2);
	div_vvv(&v[0], &v1[0], &v2[0], v.size());
}

inline void add(vecLlong_O v, vecLlong_I v1, vecLlong_I v2)
{
	assert_same_shape1(v, v1, v2);
	add_vvv(&v[0], &v1[0], &v2[0], v.size());
}

inline void sub(vecLlong_O v, vecLlong_I v1, vecLlong_I v2)
{
	assert_same_shape1(v, v1, v2);
	sub_vvv(&v[0], &v1[0], &v2[0], v.size());
}

inline void times(vecLlong_O v, vecLlong_I v1, vecLlong_I v2)
{
	assert_same_shape1(v, v1, v2);
	times_vvv(&v[0], &v1[0], &v2[0], v.size());
}

inline void div(vecLlong_O v, vecLlong_I v1, vecLlong_I v2)
{
	assert_same_shape1(v, v1, v2);
	div_vvv(&v[0], &v1[0], &v2[0], v.size());
}

inline void add(SvbaseInt_O v, SvbaseInt_I v1, SvbaseInt_I v2)
{
	assert_same_shape1(v, v1, v2);
	add_vvv(&v[0], &v1[0], &v2[0], v.size());
}

inline void sub(SvbaseInt_O v, SvbaseInt_I v1, SvbaseInt_I v2)
{
	assert_same_shape1(v, v1, v2);
	sub_vvv(&v[0], &v1[0], &v2[0], v.size());
}

inline void times(SvbaseInt_O v, SvbaseInt_I v1, SvbaseInt_I v2)
{
	assert_same_shape1(v, v1, v2);
	times_vvv(&v[0], &v1[0], &v2[0], v.size());
}

inline void div(SvbaseInt_O v, SvbaseInt_I v1, SvbaseInt_I v2)
{
	assert_same_shape1(v, v1, v2);
	div_vvv(&v[0], &v1[0], &v2[0], v.size());
}

inline void add(SvbaseLlong_O v, SvbaseLlong_I v1, SvbaseLlong_I v2)
{
	assert_same_shape1(v, v1, v2);
	add_vvv(&v[0], &v1[0], &v2[0], v.size());
}

inline void sub(SvbaseLlong_O v, SvbaseLlong_I v1, SvbaseLlong_I v2)
{
	assert_same_shape1(v, v1, v2);
	sub_vvv(&v[0], &v1[0], &v2[0], v.size());
}

inline void times(SvbaseLlong_O v, SvbaseLlong_I v1, SvbaseLlong_I v2)
{
	assert_same_shape1(v, v1, v2);
	times_vvv(&v[0], &v1[0], &v2[0], v.size());
}

inline void div(SvbaseLlong_O v, SvbaseLlong_I v1, SvbaseLlong_I v2)
{
	assert_same_shape1(v, v1, v2);
	div_vvv(&v[0], &v1[0], &v2[0], v.size());
}

inline void add(SvbaseDoub_O v, SvbaseDoub_I v1, SvbaseDoub_I v2)
{
	assert_same_shape1(v, v1, v2);
	add_vvv(&v[0], &v1[0], &v2[0], v.size());
}

inline void sub(SvbaseDoub_O v, SvbaseDoub_I v1, SvbaseDoub_I v2)
{
	assert_same_shape1(v, v1, v2);
	sub_vvv(&v[0], &v1[0], &v2[0], v.size());
}

inline void times(SvbaseDoub_O v, SvbaseDoub_I v1, SvbaseDoub_I v2)
{
	assert_same_shape1(v, v1, v2);
	times_vvv(&v[0], &v1[0], &v2[0], v.size());
}

inline void div(SvbaseDoub_O v, SvbaseDoub_I v1, SvbaseDoub_I v2)
{
	assert_same_shape1(v, v1, v2);
	div_vvv(&v[0], &v1[0], &v2[0], v.size());
}


inline void add(SvbaseComp_O v, SvbaseComp_I v1, SvbaseComp_I v2)
{
	assert_same_shape1(v, v1, v2);
	add_vvv(&v[0], &v1[0], &v2[0], v.size());
}

inline void sub(SvbaseComp_O v, SvbaseComp_I v1, SvbaseComp_I v2)
{
	assert_same_shape1(v, v1, v2);
	sub_vvv(&v[0], &v1[0], &v2[0], v.size());
}

inline void times(SvbaseComp_O v, SvbaseComp_I v1, SvbaseComp_I v2)
{
	assert_same_shape1(v, v1, v2);
	times_vvv(&v[0], &v1[0], &v2[0], v.size());
}

inline void div(SvbaseComp_O v, SvbaseComp_I v1, SvbaseComp_I v2)
{
	assert_same_shape1(v, v1, v2);
	div_vvv(&v[0], &v1[0], &v2[0], v.size());
}


inline void add(DvecComp_O v, SvbaseComp_I v1, DvecComp_I v2)
{
	assert_same_shape1(v, v1, v2);
	add_vvv(v.p(), v1.p(), v2.p(), v.size(), v.step(), 1, v2.step());
}

inline void sub(DvecComp_O v, SvbaseComp_I v1, DvecComp_I v2)
{
	assert_same_shape1(v, v1, v2);
	sub_vvv(v.p(), v1.p(), v2.p(), v.size(), v.step(), 1, v2.step());
}

inline void times(DvecComp_O v, SvbaseComp_I v1, DvecComp_I v2)
{
	assert_same_shape1(v, v1, v2);
	sub_vvv(v.p(), v1.p(), v2.p(), v.size(), v.step(), 1, v2.step());
}

inline void div(DvecComp_O v, SvbaseComp_I v1, DvecComp_I v2)
{
	assert_same_shape1(v, v1, v2);
	div_vvv(v.p(), v1.p(), v2.p(), v.size(), v.step(), 1, v2.step());
}



inline void neg_vv(Doub *v, const Doub *v1, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		v[i] = -v1[i];
}


inline void neg_vv(Comp *v, const Doub *v1, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		v[i] = -v1[i];
}


inline void neg_vv(Llong *v, const Llong *v1, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		v[i] = -v1[i];
}

inline void neg_vv(Comp *v, const Comp *v1, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		v[i] = -v1[i];
}


inline void neg(SvbaseLlong_O v, SvbaseLlong_I v1)
{
	assert_same_shape1(v, v1);
	neg_vv(v.p(), v1.p(), v1.size());
}

inline void neg(SvbaseDoub_O v, SvbaseDoub_I v1)
{
	assert_same_shape1(v, v1);
	neg_vv(v.p(), v1.p(), v1.size());
}


inline void neg(SvbaseComp_O v, SvbaseDoub_I v1)
{
	assert_same_shape1(v, v1);
	neg_vv(v.p(), v1.p(), v1.size());
}

inline void neg(SvbaseComp_O v, SvbaseComp_I v1)
{
	assert_same_shape1(v, v1);
	neg_vv(v.p(), v1.p(), v1.size());
}




} // namespace slisc
