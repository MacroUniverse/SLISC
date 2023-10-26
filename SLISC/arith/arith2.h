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


inline void mod_vvs(Int *v, const Int *v1, Int_I s, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		v[i] = mod(v1[i], s);
}


inline void mod(SvbaseInt_O v, SvbaseInt_I v1, Int_I s)
{
	assert_same_shape1(v, v1);
	mod_vvs(v.p(), v1.p(), s, v.size());
}

inline void mod(SvbaseLlong_O v, SvbaseLlong_I v1, Llong_I s)
{
	assert_same_shape1(v, v1);
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



inline void real(SvbaseComp_IO v)
{ real_v(v.p(), v.size()); }

inline void imag(SvbaseComp_IO v)
{ imag_v(v.p(), v.size()); }


inline void real(SvbaseDoub_O v, SvbaseComp_I v1)
{
	assert_same_shape1(v, v1);
	real_vv(v.p(), v1.p(), v1.size());
}

inline void imag(SvbaseDoub_O v, SvbaseComp_I v1)
{
	assert_same_shape1(v, v1);
	imag_vv(v.p(), v1.p(), v1.size());
}



inline void abs_v(Doub *v, Long_I N)
{ // not optimized for real numbers
	for (Long i = 0; i < N; ++i)
		v[i] = abs(v[i]);
}


inline void abs_v(Comp *v, Long_I N)
{ // not optimized for real numbers
	for (Long i = 0; i < N; ++i)
		v[i] = abs(v[i]);
}


inline void abs_vv(Doub *v, const Comp *v1, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		v[i] = abs(v1[i]); 
}


inline void abs_vv(Doub *v, const Doub *v1, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		v[i] = abs(v1[i]); 
}


inline void abs(SvbaseDoub_IO v)
{ abs_v(v.p(), v.size()); }


inline void abs(SvbaseComp_IO v)
{ abs_v(v.p(), v.size()); }



inline void abs(SvbaseDoub_O v, SvbaseDoub_I v1)
{
	assert_same_shape1(v, v1);
	abs_vv(v.p(), v1.p(), v1.size());
}


inline void abs(SvbaseDoub_O v, SvbaseComp_I v1)
{
	assert_same_shape1(v, v1);
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


inline void conj(SvbaseComp_IO v)
{ conj_v(v.p(), v.size()); }

inline void conj(ScmatComp_IO v)
{ conj_v(v.p(), v.size()); }

inline void conj(MatComp_IO v)
{ conj_v(v.p(), v.size()); }

inline void conj(DcmatComp_IO v)
{
	for (Long j = 0; j < v.n1(); ++j)
		conj_v(v.p(), v.n0());
}


inline void conj(SvbaseComp_O v, SvbaseComp_I v1)
{
	assert_same_shape1(v, v1);
	conj_vv(v.p(), v1.p(), v.size());
}


inline void linspace_vss(Doub *v, Doub_I first, Doub_I last, Long N)
{
	Doub delta = (last - first) / (N - 1);
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


inline void linspace(vecInt_O v, Int_I first, Int_I last)
{ linspace_vss(v.data(), first, last, v.size()); }

inline void linspace(vecLlong_O v, Llong_I first, Llong_I last)
{ linspace_vss(v.data(), first, last, v.size()); }

inline void linspace(vecDoub_O v, Doub_I first, Doub_I last)
{ linspace_vss(v.data(), first, last, v.size()); }


inline void linspace(SvbaseInt_O v, Int_I first, Int_I last)
{ linspace_vss(v.p(), first, last, v.size()); }

inline void linspace(SvbaseLlong_O v, Llong_I first, Llong_I last)
{ linspace_vss(v.p(), first, last, v.size()); }

inline void linspace(SvbaseDoub_O v, Doub_I first, Doub_I last)
{ linspace_vss(v.p(), first, last, v.size()); }


inline void linspace(SvbaseComp_O v, Comp_I first, Comp_I last)
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


inline void pow_vs(Comp *v, Int_I s, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		v[i] = pow(v[i], s);
}


inline void pow(SvbaseComp_IO v, Int_I s)
{ pow_vs(v.p(), s, v.size()); }


inline void pow_vvs(Doub *v, const Doub *v1, Int_I s, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		v[i] = pow(v1[i], s);
}


inline void pow_vvs(Doub *v, const Doub *v1, Doub_I s, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		v[i] = pow(v1[i], s);
}

inline void pow_vvs(Comp *v, const Doub *v1, Comp_I s, Long_I N)
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


inline void pow(SvbaseDoub_O v, SvbaseDoub_I v1, Int_I s)
{
	assert_same_shape1(v, v1);
	pow_vvs(v.p(), v1.p(), s, v1.size());
}


inline void pow(SvbaseDoub_O v, SvbaseDoub_I v1, Doub_I s)
{
	assert_same_shape1(v, v1);
	pow_vvs(v.p(), v1.p(), s, v1.size());
}


inline void pow(SvbaseComp_O v, SvbaseDoub_I v1, Comp_I s)
{
	assert_same_shape1(v, v1);
	pow_vvs(v.p(), v1.p(), s, v1.size());
}


inline void pow(SvbaseComp_O v, SvbaseComp_I v1, Doub_I s)
{
	assert_same_shape1(v, v1);
	pow_vvs(v.p(), v1.p(), s, v1.size());
}


inline void pow(SvbaseComp_O v, SvbaseComp_I v1, Comp_I s)
{
	assert_same_shape1(v, v1);
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


inline Doub dot(SvbaseDoub_I v1, SvbaseDoub_I v2)
{
	assert_same_shape1(v1, v2);
	return dot_vv(v1.p(), v2.p(), v2.size());
}

inline Comp dot(SvbaseDoub_I v1, SvbaseComp_I v2)
{
	assert_same_shape1(v1, v2);
	return dot_vv(v1.p(), v2.p(), v2.size());
}



inline Comp dot(SvbaseComp_I v1, SvbaseDoub_I v2)
{
	assert_same_shape1(v1, v2);
	return dot_vv(v1.p(), v2.p(), v2.size());
}

inline Comp dot(SvbaseComp_I v1, SvbaseComp_I v2)
{
	assert_same_shape1(v1, v2);
	return dot_vv(v1.p(), v2.p(), v2.size());
}



inline Comp dot(DvecComp_I v1, SvbaseDoub_I v2)
{
	assert_same_shape1(v1, v2);
	Comp sum = 0;
	for (Long i = 0; i < v1.size(); ++i)
		sum += conj(v1[i]) * v2[i];
	return sum;
}


inline Comp dot(Scmat3Comp_I v1, Jcmat3Comp_I v2)
{
	assert_same_shape3(v1, v2);
	Comp sum = 0;
	for (Long i = 0; i < v1.n0(); ++i)
		for (Long j = 0; j < v1.n1(); ++j)
			for (Long k = 0; k < v1.n2(); ++k)
				sum += conj(v1(i,j,k)) * v2(i,j,k);
	return sum;
}


inline Doub dot_real(SvbaseComp_I v1, SvbaseComp_I v2)
{
	assert_same_shape1(v1, v2);
	Doub sum = 0; Long N = v1.size();
	for (Long i = 0; i < N; ++i) {
		auto &c1 = v1[i], &c2 = v2[i];
		sum += c1.real()*c2.real() + c1.imag()*c2.imag();
	}
	return sum;
}

inline Doub dot_real_par(SvbaseComp_I v1, SvbaseComp_I v2)
{
	assert_same_shape1(v1, v2);
	Doub sum = 0; Long N = v1.size();
#pragma omp parallel for reduction(+:sum)
	for (Long i = 0; i < N; ++i) {
		auto &c1 = v1[i], &c2 = v2[i];
		sum += c1.real()*c2.real() + c1.imag()*c2.imag();
	}
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


inline void cumsum(SvbaseInt_O v, SvbaseInt_I v1)
{
	assert_same_shape1(v, v1);
	cumsum_vv(v.p(), v1.p(), v1.size());
}

inline void cumsum(SvbaseLlong_O v, SvbaseLlong_I v1)
{
	assert_same_shape1(v, v1);
	cumsum_vv(v.p(), v1.p(), v1.size());
}

inline void cumsum(SvbaseDoub_O v, SvbaseDoub_I v1)
{
	assert_same_shape1(v, v1);
	cumsum_vv(v.p(), v1.p(), v1.size());
}



} // namespace slisc
