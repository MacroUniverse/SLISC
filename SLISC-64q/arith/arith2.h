// functions that loop through every element of a container

#pragma once
#include "../arith/scalar_arith.h"
#include "../arith/compare.h"

namespace slisc {

inline void mod_vvs(Llong *v, const Llong *v1, Llong_I s, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		v[i] = mod(v1[i], s);
}

inline void mod_vvs(Doub *v, const Doub *v1, Doub_I s, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		v[i] = mod(v1[i], s);
}

inline void mod_vvs(Qdoub *v, const Qdoub *v1, Qdoub_I s, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		v[i] = mod(v1[i], s);
}

inline void mod_vvs(Int *v, const Int *v1, Int_I s, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		v[i] = mod(v1[i], s);
}


inline void mod(SvecInt_O v, SvecInt_I v1, Int_I s)
{
	assert_same_shape(v, v1);
	mod_vvs(v.p(), v1.p(), s, v.size());
}

inline void mod(SvecLlong_O v, SvecLlong_I v1, Llong_I s)
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

inline void real_vv(Qdoub *v, const Qcomp *v1, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		v[i] = real(v1[i]); 
}

inline void imag_vv(Qdoub *v, const Qcomp *v1, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		v[i] = imag(v1[i]); 
}


inline void real(SvecComp_IO v)
{ real_v(v.p(), v.size()); }

inline void imag(SvecComp_IO v)
{ imag_v(v.p(), v.size()); }


inline void real(SvecDoub_O v, SvecComp_I v1)
{
	assert_same_shape(v, v1);
	real_vv(v.p(), v1.p(), v1.size());
}

inline void imag(SvecDoub_O v, SvecComp_I v1)
{
	assert_same_shape(v, v1);
	imag_vv(v.p(), v1.p(), v1.size());
}

inline void real(SvecQdoub_O v, SvecQcomp_I v1)
{
	assert_same_shape(v, v1);
	real_vv(v.p(), v1.p(), v1.size());
}

inline void imag(SvecQdoub_O v, SvecQcomp_I v1)
{
	assert_same_shape(v, v1);
	imag_vv(v.p(), v1.p(), v1.size());
}


inline void abs_v(Doub *v, Long_I N)
{ // not optimized for real numbers
	for (Long i = 0; i < N; ++i)
		v[i] = abs(v[i]);
}

inline void abs_v(Qdoub *v, Long_I N)
{ // not optimized for real numbers
	for (Long i = 0; i < N; ++i)
		v[i] = abs(v[i]);
}

inline void abs_v(Comp *v, Long_I N)
{ // not optimized for real numbers
	for (Long i = 0; i < N; ++i)
		v[i] = abs(v[i]);
}

inline void abs_v(Qcomp *v, Long_I N)
{ // not optimized for real numbers
	for (Long i = 0; i < N; ++i)
		v[i] = abs(v[i]);
}


inline void abs_vv(Doub *v, const Comp *v1, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		v[i] = abs(v1[i]); 
}

inline void abs_vv(Qdoub *v, const Qcomp *v1, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		v[i] = abs(v1[i]); 
}

inline void abs_vv(Doub *v, const Doub *v1, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		v[i] = abs(v1[i]); 
}

inline void abs_vv(Qdoub *v, const Qdoub *v1, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		v[i] = abs(v1[i]); 
}


inline void abs(SvecDoub_IO v)
{ abs_v(v.p(), v.size()); }

inline void abs(SvecQdoub_IO v)
{ abs_v(v.p(), v.size()); }

inline void abs(SvecComp_IO v)
{ abs_v(v.p(), v.size()); }

inline void abs(SvecQcomp_IO v)
{ abs_v(v.p(), v.size()); }


inline void abs(SvecDoub_O v, SvecDoub_I v1)
{
	assert_same_shape(v, v1);
	abs_vv(v.p(), v1.p(), v1.size());
}

inline void abs(SvecQdoub_O v, SvecQdoub_I v1)
{
	assert_same_shape(v, v1);
	abs_vv(v.p(), v1.p(), v1.size());
}

inline void abs(SvecDoub_O v, SvecComp_I v1)
{
	assert_same_shape(v, v1);
	abs_vv(v.p(), v1.p(), v1.size());
}

inline void abs(SvecQdoub_O v, SvecQcomp_I v1)
{
	assert_same_shape(v, v1);
	abs_vv(v.p(), v1.p(), v1.size());
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


inline void conj(SvecComp_IO v)
{ conj_v(v.p(), v.size()); }

inline void conj(CmatComp_IO v)
{ conj_v(v.p(), v.size()); }

inline void conj(MatComp_IO v)
{ conj_v(v.p(), v.size()); }

inline void conj(DcmatComp_IO v)
{
	for (Long j = 0; j < v.n1(); ++j)
		conj_v(v.p(), v.n0());
}


inline void conj(SvecComp_O v, SvecComp_I v1)
{
	assert_same_shape(v, v1);
	conj_vv(v.p(), v1.p(), v.size());
}


inline void linspace_vss(Doub *v, Doub_I first, Doub_I last, Long N)
{
	Doub delta = (last - first) / (N - 1);
	for (Long i = 0; i < N; ++i)
		v[i] = first + delta * i;
}

inline void linspace_vss(Qdoub *v, Qdoub_I first, Qdoub_I last, Long N)
{
	Qdoub delta = (last - first) / (N - 1);
	for (Long i = 0; i < N; ++i)
		v[i] = first + delta * i;
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

inline void linspace_vss(Comp *v, Comp_I first, Comp_I last, Long N)
{
	Comp delta = (last - first) / (N - 1);
	for (Long i = 0; i < N; ++i)
		v[i] = first + delta * i;
}

inline void linspace_vss(Qcomp *v, Qcomp_I first, Qcomp_I last, Long N)
{
	Qcomp delta = (last - first) / (N - 1);
	for (Long i = 0; i < N; ++i)
		v[i] = first + delta * i;
}


inline void linspace(vecInt_O v, Int_I first, Int_I last)
{ linspace_vss(v.data(), first, last, v.size()); }

inline void linspace(vecLlong_O v, Llong_I first, Llong_I last)
{ linspace_vss(v.data(), first, last, v.size()); }

inline void linspace(vecDoub_O v, Doub_I first, Doub_I last)
{ linspace_vss(v.data(), first, last, v.size()); }

inline void linspace(vecQdoub_O v, Qdoub_I first, Qdoub_I last)
{ linspace_vss(v.data(), first, last, v.size()); }

inline void linspace(SvecInt_O v, Int_I first, Int_I last)
{ linspace_vss(v.p(), first, last, v.size()); }

inline void linspace(SvecLlong_O v, Llong_I first, Llong_I last)
{ linspace_vss(v.p(), first, last, v.size()); }

inline void linspace(SvecDoub_O v, Doub_I first, Doub_I last)
{ linspace_vss(v.p(), first, last, v.size()); }

inline void linspace(SvecQdoub_O v, Qdoub_I first, Qdoub_I last)
{ linspace_vss(v.p(), first, last, v.size()); }

inline void linspace(SvecComp_O v, Comp_I first, Comp_I last)
{ linspace_vss(v.p(), first, last, v.size()); }

inline void linspace(SvecQcomp_O v, Qcomp_I first, Qcomp_I last)
{ linspace_vss(v.p(), first, last, v.size()); }

inline void linspace(MatInt_O v, Int_I first, Int_I last)
{ linspace_vss(v.p(), first, last, v.size()); }

inline void linspace(MatComp_O v, Comp_I first, Comp_I last)
{ linspace_vss(v.p(), first, last, v.size()); }

inline void linspace(Cmat4Int_O v, Int_I first, Int_I last)
{ linspace_vss(v.p(), first, last, v.size()); }



inline void pow_vs(Doub *v, Llong_I s, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		v[i] = pow(v[i], s);
}

inline void pow_vs(Qdoub *v, Llong_I s, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		v[i] = pow(v[i], s);
}

inline void pow_vs(Comp *v, Int_I s, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		v[i] = pow(v[i], s);
}


inline void pow(SvecComp_IO v, Int_I s)
{ pow_vs(v.p(), s, v.size()); }


inline void pow_vvs(Doub *v, const Doub *v1, Int_I s, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		v[i] = pow(v1[i], s);
}

inline void pow_vvs(Qdoub *v, const Qdoub *v1, Int_I s, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		v[i] = pow(v1[i], s);
}

inline void pow_vvs(Doub *v, const Doub *v1, Doub_I s, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		v[i] = pow(v1[i], s);
}

inline void pow_vvs(Qdoub *v, const Qdoub *v1, Qdoub_I s, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		v[i] = pow(v1[i], s);
}

inline void pow_vvs(Comp *v, const Doub *v1, Comp_I s, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		v[i] = pow(v1[i], s);
}

inline void pow_vvs(Qcomp *v, const Qdoub *v1, Qcomp_I s, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		v[i] = pow(v1[i], s);
}

inline void pow_vvs(Comp *v, const Comp *v1, Doub_I s, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		v[i] = pow(v1[i], s);
}

inline void pow_vvs(Qcomp *v, const Qcomp *v1, Qdoub_I s, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		v[i] = pow(v1[i], s);
}

inline void pow_vvs(Comp *v, const Comp *v1, Comp_I s, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		v[i] = pow(v1[i], s);
}

inline void pow_vvs(Qcomp *v, const Qcomp *v1, Qcomp_I s, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		v[i] = pow(v1[i], s);
}


inline void pow(SvecDoub_O v, SvecDoub_I v1, Int_I s)
{
	assert_same_shape(v, v1);
	pow_vvs(v.p(), v1.p(), s, v1.size());
}

inline void pow(SvecQdoub_O v, SvecQdoub_I v1, Int_I s)
{
	assert_same_shape(v, v1);
	pow_vvs(v.p(), v1.p(), s, v1.size());
}

inline void pow(SvecDoub_O v, SvecDoub_I v1, Doub_I s)
{
	assert_same_shape(v, v1);
	pow_vvs(v.p(), v1.p(), s, v1.size());
}

inline void pow(SvecQdoub_O v, SvecQdoub_I v1, Qdoub_I s)
{
	assert_same_shape(v, v1);
	pow_vvs(v.p(), v1.p(), s, v1.size());
}

inline void pow(SvecComp_O v, SvecDoub_I v1, Comp_I s)
{
	assert_same_shape(v, v1);
	pow_vvs(v.p(), v1.p(), s, v1.size());
}

inline void pow(SvecQcomp_O v, SvecQdoub_I v1, Qcomp_I s)
{
	assert_same_shape(v, v1);
	pow_vvs(v.p(), v1.p(), s, v1.size());
}

inline void pow(SvecComp_O v, SvecComp_I v1, Doub_I s)
{
	assert_same_shape(v, v1);
	pow_vvs(v.p(), v1.p(), s, v1.size());
}

inline void pow(SvecQcomp_O v, SvecQcomp_I v1, Qdoub_I s)
{
	assert_same_shape(v, v1);
	pow_vvs(v.p(), v1.p(), s, v1.size());
}

inline void pow(SvecComp_O v, SvecComp_I v1, Comp_I s)
{
	assert_same_shape(v, v1);
	pow_vvs(v.p(), v1.p(), s, v1.size());
}

inline void pow(SvecQcomp_O v, SvecQcomp_I v1, Qcomp_I s)
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

inline Qcomp dot_vv(const Qdoub *v1, const Qcomp *v2, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (N <= 0) SLS_ERR("illegal length!");
#endif
	Qcomp s = v1[0] * v2[0];
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

inline Qdoub dot_vv(const Qdoub *v1, const Qdoub *v2, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (N <= 0) SLS_ERR("illegal length!");
#endif
	Qdoub s = v1[0] * v2[0];
	for (Long i = 1; i < N; ++i) {
		s += v1[i] * v2[i];
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

inline Qcomp dot_vv(const Qcomp *v1, const Qdoub *v2, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (N <= 0) SLS_ERR("illegal length!");
#endif
	Qcomp s = conj(v1[0]) * v2[0];
	for (Long i = 1; i < N; ++i) {
		s += conj(v1[i]) * v2[i];
	}
	return s;
}

inline Qcomp dot_vv(const Qcomp *v1, const Qcomp *v2, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (N <= 0) SLS_ERR("illegal length!");
#endif
	Qcomp s = conj(v1[0]) * v2[0];
	for (Long i = 1; i < N; ++i) {
		s += conj(v1[i]) * v2[i];
	}
	return s;
}


inline Doub dot(SvecDoub_I v1, SvecDoub_I v2)
{
	assert_same_shape(v1, v2);
	return dot_vv(v1.p(), v2.p(), v2.size());
}

inline Comp dot(SvecDoub_I v1, SvecComp_I v2)
{
	assert_same_shape(v1, v2);
	return dot_vv(v1.p(), v2.p(), v2.size());
}

inline Qdoub dot(SvecQdoub_I v1, SvecQdoub_I v2)
{
	assert_same_shape(v1, v2);
	return dot_vv(v1.p(), v2.p(), v2.size());
}

inline Qcomp dot(SvecQdoub_I v1, SvecQcomp_I v2)
{
	assert_same_shape(v1, v2);
	return dot_vv(v1.p(), v2.p(), v2.size());
}

inline Comp dot(SvecComp_I v1, SvecDoub_I v2)
{
	assert_same_shape(v1, v2);
	return dot_vv(v1.p(), v2.p(), v2.size());
}

inline Comp dot(SvecComp_I v1, SvecComp_I v2)
{
	assert_same_shape(v1, v2);
	return dot_vv(v1.p(), v2.p(), v2.size());
}

inline Qcomp dot(SvecQcomp_I v1, SvecQdoub_I v2)
{
	assert_same_shape(v1, v2);
	return dot_vv(v1.p(), v2.p(), v2.size());
}

inline Qcomp dot(SvecQcomp_I v1, SvecQcomp_I v2)
{
	assert_same_shape(v1, v2);
	return dot_vv(v1.p(), v2.p(), v2.size());
}

inline Comp dot(DvecComp_I v1, SvecDoub_I v2)
{
	assert_same_shape(v1, v2);
	Comp sum = 0;
	for (Long i = 0; i < v1.size(); ++i)
		sum += conj(v1[i]) * v2[i];
	return sum;
}

inline Qcomp dot(DvecQcomp_I v1, SvecQdoub_I v2)
{
	assert_same_shape(v1, v2);
	Qcomp sum = 0;
	for (Long i = 0; i < v1.size(); ++i)
		sum += conj(v1[i]) * v2[i];
	return sum;
}

inline Comp dot(Scmat3Comp_I v1, Jcmat3Comp_I v2)
{
	assert_same_shape(v1, v2);
	Comp sum = 0;
	for (Long i = 0; i < v1.n0(); ++i)
		for (Long j = 0; j < v1.n1(); ++j)
			for (Long k = 0; k < v1.n2(); ++k)
				sum += conj(v1(i,j,k)) * v2(i,j,k);
	return sum;
}

inline Qcomp dot(Scmat3Qcomp_I v1, Jcmat3Qcomp_I v2)
{
	assert_same_shape(v1, v2);
	Qcomp sum = 0;
	for (Long i = 0; i < v1.n0(); ++i)
		for (Long j = 0; j < v1.n1(); ++j)
			for (Long k = 0; k < v1.n2(); ++k)
				sum += conj(v1(i,j,k)) * v2(i,j,k);
	return sum;
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

inline void cumsum_vv(Qdoub *v, const Qdoub *v1, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (N <= 0) SLS_ERR("illegal length!");
#endif
	v[0] = v1[0];
	for (Long i = 1; i < N; ++i)
		v[i] = v[i - 1] + v1[i];
}

inline void cumsum_vv(Int *v, const Int *v1, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (N <= 0) SLS_ERR("illegal length!");
#endif
	v[0] = v1[0];
	for (Long i = 1; i < N; ++i)
		v[i] = v[i - 1] + v1[i];
}

inline void cumsum_vv(Llong *v, const Llong *v1, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (N <= 0) SLS_ERR("illegal length!");
#endif
	v[0] = v1[0];
	for (Long i = 1; i < N; ++i)
		v[i] = v[i - 1] + v1[i];
}


inline void cumsum(SvecInt_O v, SvecInt_I v1)
{
	assert_same_shape(v, v1);
	cumsum_vv(v.p(), v1.p(), v1.size());
}

inline void cumsum(SvecLlong_O v, SvecLlong_I v1)
{
	assert_same_shape(v, v1);
	cumsum_vv(v.p(), v1.p(), v1.size());
}

inline void cumsum(SvecDoub_O v, SvecDoub_I v1)
{
	assert_same_shape(v, v1);
	cumsum_vv(v.p(), v1.p(), v1.size());
}

inline void cumsum(SvecQdoub_O v, SvecQdoub_I v1)
{
	assert_same_shape(v, v1);
	cumsum_vv(v.p(), v1.p(), v1.size());
}


} // namespace slisc
