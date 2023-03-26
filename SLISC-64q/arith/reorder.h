// reorder elements of containers

#pragma once
#include "../arith/copy.h"
#include "../arith/arith2.h"

namespace slisc {

inline void resize_cpy(VecInt_IO v, Long_I N, Int_I val = 0)
{
	Long Nold = v.size();
	if (N != Nold) {
		if (Nold == 0) {
			v.resize(N); copy(v, val);
		}
		else if (N == 0)
			v.resize(0);
		else {
			VecInt v1(N);
			if (N > Nold) {
				veccpy(v1.p(), v.p(), Nold);
				vecset(v1.p() + Nold, val, N - Nold);
			}
			else // N < Nold
				veccpy(v1.p(), v.p(), N);
			v << v1;
		}
	}
}

inline void resize_cpy(VecLlong_IO v, Long_I N, Llong_I val = 0)
{
	Long Nold = v.size();
	if (N != Nold) {
		if (Nold == 0) {
			v.resize(N); copy(v, val);
		}
		else if (N == 0)
			v.resize(0);
		else {
			VecLlong v1(N);
			if (N > Nold) {
				veccpy(v1.p(), v.p(), Nold);
				vecset(v1.p() + Nold, val, N - Nold);
			}
			else // N < Nold
				veccpy(v1.p(), v.p(), N);
			v << v1;
		}
	}
}

inline void resize_cpy(VecDoub_IO v, Long_I N, Doub_I val = 0)
{
	Long Nold = v.size();
	if (N != Nold) {
		if (Nold == 0) {
			v.resize(N); copy(v, val);
		}
		else if (N == 0)
			v.resize(0);
		else {
			VecDoub v1(N);
			if (N > Nold) {
				veccpy(v1.p(), v.p(), Nold);
				vecset(v1.p() + Nold, val, N - Nold);
			}
			else // N < Nold
				veccpy(v1.p(), v.p(), N);
			v << v1;
		}
	}
}

inline void resize_cpy(VecQdoub_IO v, Long_I N, Qdoub_I val = 0)
{
	Long Nold = v.size();
	if (N != Nold) {
		if (Nold == 0) {
			v.resize(N); copy(v, val);
		}
		else if (N == 0)
			v.resize(0);
		else {
			VecQdoub v1(N);
			if (N > Nold) {
				veccpy(v1.p(), v.p(), Nold);
				vecset(v1.p() + Nold, val, N - Nold);
			}
			else // N < Nold
				veccpy(v1.p(), v.p(), N);
			v << v1;
		}
	}
}

inline void resize_cpy(VecComp_IO v, Long_I N, Comp_I val = 0)
{
	Long Nold = v.size();
	if (N != Nold) {
		if (Nold == 0) {
			v.resize(N); copy(v, val);
		}
		else if (N == 0)
			v.resize(0);
		else {
			VecComp v1(N);
			if (N > Nold) {
				veccpy(v1.p(), v.p(), Nold);
				vecset(v1.p() + Nold, val, N - Nold);
			}
			else // N < Nold
				veccpy(v1.p(), v.p(), N);
			v << v1;
		}
	}
}

inline void resize_cpy(VecQcomp_IO v, Long_I N, Qcomp_I val = 0)
{
	Long Nold = v.size();
	if (N != Nold) {
		if (Nold == 0) {
			v.resize(N); copy(v, val);
		}
		else if (N == 0)
			v.resize(0);
		else {
			VecQcomp v1(N);
			if (N > Nold) {
				veccpy(v1.p(), v.p(), Nold);
				vecset(v1.p() + Nold, val, N - Nold);
			}
			else // N < Nold
				veccpy(v1.p(), v.p(), N);
			v << v1;
		}
	}
}

inline void resize_cpy(CmatInt_IO v, Long_I N0, Long_I N1, Int_I val = 0)
{
	Long N10 = v.n0(), N20 = v.n1(), Nold = N0*N1;
	Long N = N0 * N1;
	if (N0 != N10 || N1 != N20) {
		if (Nold == 0) {
			v.resize(N0, N1); copy(v, val);
		}
		else if (N == 0)
			v.resize(0, 0);
		else {
			CmatInt v1(N0, N1); copy(v1, val);
			Long N1min = min(N0, N10), N2min = min(N1, N20);
			copy(cut(v1, 0, N1min, 0, N2min),
				cut(v, 0, N1min, 0, N2min));
			v << v1;
		}
	}
}

inline void resize_cpy(CmatLlong_IO v, Long_I N0, Long_I N1, Llong_I val = 0)
{
	Long N10 = v.n0(), N20 = v.n1(), Nold = N0*N1;
	Long N = N0 * N1;
	if (N0 != N10 || N1 != N20) {
		if (Nold == 0) {
			v.resize(N0, N1); copy(v, val);
		}
		else if (N == 0)
			v.resize(0, 0);
		else {
			CmatLlong v1(N0, N1); copy(v1, val);
			Long N1min = min(N0, N10), N2min = min(N1, N20);
			copy(cut(v1, 0, N1min, 0, N2min),
				cut(v, 0, N1min, 0, N2min));
			v << v1;
		}
	}
}

inline void resize_cpy(CmatDoub_IO v, Long_I N0, Long_I N1, Doub_I val = 0)
{
	Long N10 = v.n0(), N20 = v.n1(), Nold = N0*N1;
	Long N = N0 * N1;
	if (N0 != N10 || N1 != N20) {
		if (Nold == 0) {
			v.resize(N0, N1); copy(v, val);
		}
		else if (N == 0)
			v.resize(0, 0);
		else {
			CmatDoub v1(N0, N1); copy(v1, val);
			Long N1min = min(N0, N10), N2min = min(N1, N20);
			copy(cut(v1, 0, N1min, 0, N2min),
				cut(v, 0, N1min, 0, N2min));
			v << v1;
		}
	}
}

inline void resize_cpy(CmatQdoub_IO v, Long_I N0, Long_I N1, Qdoub_I val = 0)
{
	Long N10 = v.n0(), N20 = v.n1(), Nold = N0*N1;
	Long N = N0 * N1;
	if (N0 != N10 || N1 != N20) {
		if (Nold == 0) {
			v.resize(N0, N1); copy(v, val);
		}
		else if (N == 0)
			v.resize(0, 0);
		else {
			CmatQdoub v1(N0, N1); copy(v1, val);
			Long N1min = min(N0, N10), N2min = min(N1, N20);
			copy(cut(v1, 0, N1min, 0, N2min),
				cut(v, 0, N1min, 0, N2min));
			v << v1;
		}
	}
}

inline void resize_cpy(CmatComp_IO v, Long_I N0, Long_I N1, Comp_I val = 0)
{
	Long N10 = v.n0(), N20 = v.n1(), Nold = N0*N1;
	Long N = N0 * N1;
	if (N0 != N10 || N1 != N20) {
		if (Nold == 0) {
			v.resize(N0, N1); copy(v, val);
		}
		else if (N == 0)
			v.resize(0, 0);
		else {
			CmatComp v1(N0, N1); copy(v1, val);
			Long N1min = min(N0, N10), N2min = min(N1, N20);
			copy(cut(v1, 0, N1min, 0, N2min),
				cut(v, 0, N1min, 0, N2min));
			v << v1;
		}
	}
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

inline void resize_cpy(Cmat3Qdoub_IO v, Long_I N0, Long_I N1, Long_I N2, Qdoub_I val = 0)
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
			Cmat3Qdoub v1(N0, N1, N2); copy(v1, val);
			Long N1min = min(N0, N10), N2min = min(N1, N20), N3min = min(N2, N30);
			copy(cut(v1, 0, N1min, 0, N2min, 0, N3min),
				cut(v, 0, N1min, 0, N2min, 0, N3min));
			v << v1;
		}
	}
}

inline void resize_cpy(Cmat3Comp_IO v, Long_I N0, Long_I N1, Long_I N2, Comp_I val = 0)
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
			Cmat3Comp v1(N0, N1, N2); copy(v1, val);
			Long N1min = min(N0, N10), N2min = min(N1, N20), N3min = min(N2, N30);
			copy(cut(v1, 0, N1min, 0, N2min, 0, N3min),
				cut(v, 0, N1min, 0, N2min, 0, N3min));
			v << v1;
		}
	}
}

inline void resize_cpy(Cmat3Qcomp_IO v, Long_I N0, Long_I N1, Long_I N2, Qcomp_I val = 0)
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
			Cmat3Qcomp v1(N0, N1, N2); copy(v1, val);
			Long N1min = min(N0, N10), N2min = min(N1, N20), N3min = min(N2, N30);
			copy(cut(v1, 0, N1min, 0, N2min, 0, N3min),
				cut(v, 0, N1min, 0, N2min, 0, N3min));
			v << v1;
		}
	}
}


inline void flip_v(Doub *v, Long_I N)
{
	for (Long i = 0; i < N / 2; ++i)
		swap(v[i], v[N - i - 1]);
}

inline void flip_v(Qdoub *v, Long_I N)
{
	for (Long i = 0; i < N / 2; ++i)
		swap(v[i], v[N - i - 1]);
}

inline void flip_v(Int *v, Long_I N)
{
	for (Long i = 0; i < N / 2; ++i)
		swap(v[i], v[N - i - 1]);
}

inline void flip_v(Llong *v, Long_I N)
{
	for (Long i = 0; i < N / 2; ++i)
		swap(v[i], v[N - i - 1]);
}

inline void flip_v(Comp *v, Long_I N)
{
	for (Long i = 0; i < N / 2; ++i)
		swap(v[i], v[N - i - 1]);
}

inline void flip_v(Qcomp *v, Long_I N)
{
	for (Long i = 0; i < N / 2; ++i)
		swap(v[i], v[N - i - 1]);
}

inline void flip_v(Str *v, Long_I N)
{
	for (Long i = 0; i < N / 2; ++i)
		swap(v[i], v[N - i - 1]);
}


inline void flip_vv(Doub *v, const Doub *v1, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		v[i] = v1[N - i - 1];
}

inline void flip_vv(Qdoub *v, const Qdoub *v1, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		v[i] = v1[N - i - 1];
}

inline void flip_vv(Int *v, const Int *v1, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		v[i] = v1[N - i - 1];
}


inline void flip(VecInt_IO v)
{ flip_v(&v[0], v.size()); }

inline void flip(VecLlong_IO v)
{ flip_v(&v[0], v.size()); }

inline void flip(VecDoub_IO v)
{ flip_v(&v[0], v.size()); }

inline void flip(VecQdoub_IO v)
{ flip_v(&v[0], v.size()); }

inline void flip(VecComp_IO v)
{ flip_v(&v[0], v.size()); }

inline void flip(VecQcomp_IO v)
{ flip_v(&v[0], v.size()); }

inline void flip(vecLlong_IO v)
{ flip_v(&v[0], v.size()); }

inline void flip(vecDoub_IO v)
{ flip_v(&v[0], v.size()); }

inline void flip(vecQdoub_IO v)
{ flip_v(&v[0], v.size()); }

inline void flip(vecComp_IO v)
{ flip_v(&v[0], v.size()); }

inline void flip(vecQcomp_IO v)
{ flip_v(&v[0], v.size()); }

inline void flip(vecStr_IO v)
{ flip_v(&v[0], v.size()); }


inline void flip(VecInt_O v, VecInt_I v1)
{
	assert_same_shape(v, v1);
	flip_vv(v.p(), v1.p(), v1.size());
}

inline void flip(VecDoub_O v, VecDoub_I v1)
{
	assert_same_shape(v, v1);
	flip_vv(v.p(), v1.p(), v1.size());
}

inline void flip(VecQdoub_O v, VecQdoub_I v1)
{
	assert_same_shape(v, v1);
	flip_vv(v.p(), v1.p(), v1.size());
}


inline void reorder(VecInt_O v, VecInt_I order)
{
#ifdef SLS_CHECK_SHAPES
	if ((Long)order.size() != (Long)v.size())
		SLS_ERR("wrong shape!");
#endif
	Long N = v.size();
	static VecInt u; u.resize(N);
	if (N > (Long)u.size())
		u.resize(max(N, Long(2*u.size())));
	for (Long i = 0; i < N; ++i)
		u[i] = v[order[i]];
	for (Long i = 0; i < N; ++i)
		v[i] = u[i];
}

inline void reorder(VecLlong_O v, VecLlong_I order)
{
#ifdef SLS_CHECK_SHAPES
	if ((Long)order.size() != (Long)v.size())
		SLS_ERR("wrong shape!");
#endif
	Long N = v.size();
	static VecLlong u; u.resize(N);
	if (N > (Long)u.size())
		u.resize(max(N, Long(2*u.size())));
	for (Long i = 0; i < N; ++i)
		u[i] = v[order[i]];
	for (Long i = 0; i < N; ++i)
		v[i] = u[i];
}

inline void reorder(VecDoub_O v, VecLlong_I order)
{
#ifdef SLS_CHECK_SHAPES
	if ((Long)order.size() != (Long)v.size())
		SLS_ERR("wrong shape!");
#endif
	Long N = v.size();
	static VecDoub u; u.resize(N);
	if (N > (Long)u.size())
		u.resize(max(N, Long(2*u.size())));
	for (Long i = 0; i < N; ++i)
		u[i] = v[order[i]];
	for (Long i = 0; i < N; ++i)
		v[i] = u[i];
}

inline void reorder(VecQdoub_O v, VecLlong_I order)
{
#ifdef SLS_CHECK_SHAPES
	if ((Long)order.size() != (Long)v.size())
		SLS_ERR("wrong shape!");
#endif
	Long N = v.size();
	static VecQdoub u; u.resize(N);
	if (N > (Long)u.size())
		u.resize(max(N, Long(2*u.size())));
	for (Long i = 0; i < N; ++i)
		u[i] = v[order[i]];
	for (Long i = 0; i < N; ++i)
		v[i] = u[i];
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

inline void reorder(SvecQcomp_O v, VecLlong_I order)
{
#ifdef SLS_CHECK_SHAPES
	if ((Long)order.size() != (Long)v.size())
		SLS_ERR("wrong shape!");
#endif
	Long N = v.size();
	static VecQcomp u; u.resize(N);
	if (N > (Long)u.size())
		u.resize(max(N, Long(2*u.size())));
	for (Long i = 0; i < N; ++i)
		u[i] = v[order[i]];
	for (Long i = 0; i < N; ++i)
		v[i] = u[i];
}

inline void reorder(vecStr_O v, vecLlong_I order)
{
#ifdef SLS_CHECK_SHAPES
	if ((Long)order.size() != (Long)v.size())
		SLS_ERR("wrong shape!");
#endif
	Long N = v.size();
	static vecStr u; u.resize(N);
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

inline void reorder(vecStr_O v, VecLlong_I order)
{
#ifdef SLS_CHECK_SHAPES
	if ((Long)order.size() != (Long)v.size())
		SLS_ERR("wrong shape!");
#endif
	Long N = v.size();
	static vecStr u; u.resize(N);
	if (N > (Long)u.size())
		u.resize(max(N, Long(2*u.size())));
	for (Long i = 0; i < N; ++i)
		u[i] = v[order[i]];
	for (Long i = 0; i < N; ++i)
		v[i] = u[i];
}

inline void reorder(vecLlong_O v, VecLlong_I order)
{
#ifdef SLS_CHECK_SHAPES
	if ((Long)order.size() != (Long)v.size())
		SLS_ERR("wrong shape!");
#endif
	Long N = v.size();
	static VecLlong u; u.resize(N);
	if (N > (Long)u.size())
		u.resize(max(N, Long(2*u.size())));
	for (Long i = 0; i < N; ++i)
		u[i] = v[order[i]];
	for (Long i = 0; i < N; ++i)
		v[i] = u[i];
}

inline void reorder(SvecChar_O v, VecLlong_I order)
{
#ifdef SLS_CHECK_SHAPES
	if ((Long)order.size() != (Long)v.size())
		SLS_ERR("wrong shape!");
#endif
	Long N = v.size();
	static VecChar u; u.resize(N);
	if (N > (Long)u.size())
		u.resize(max(N, Long(2*u.size())));
	for (Long i = 0; i < N; ++i)
		u[i] = v[order[i]];
	for (Long i = 0; i < N; ++i)
		v[i] = u[i];
}

inline void reorder(SvecChar_O v, VecInt_I order)
{
#ifdef SLS_CHECK_SHAPES
	if ((Long)order.size() != (Long)v.size())
		SLS_ERR("wrong shape!");
#endif
	Long N = v.size();
	static VecChar u; u.resize(N);
	if (N > (Long)u.size())
		u.resize(max(N, Long(2*u.size())));
	for (Long i = 0; i < N; ++i)
		u[i] = v[order[i]];
	for (Long i = 0; i < N; ++i)
		v[i] = u[i];
}

inline void reorder(SvecLlong_O v, VecLlong_I order)
{
#ifdef SLS_CHECK_SHAPES
	if ((Long)order.size() != (Long)v.size())
		SLS_ERR("wrong shape!");
#endif
	Long N = v.size();
	static VecLlong u; u.resize(N);
	if (N > (Long)u.size())
		u.resize(max(N, Long(2*u.size())));
	for (Long i = 0; i < N; ++i)
		u[i] = v[order[i]];
	for (Long i = 0; i < N; ++i)
		v[i] = u[i];
}

inline void reorder(SvecInt_O v, VecInt_I order)
{
#ifdef SLS_CHECK_SHAPES
	if ((Long)order.size() != (Long)v.size())
		SLS_ERR("wrong shape!");
#endif
	Long N = v.size();
	static VecInt u; u.resize(N);
	if (N > (Long)u.size())
		u.resize(max(N, Long(2*u.size())));
	for (Long i = 0; i < N; ++i)
		u[i] = v[order[i]];
	for (Long i = 0; i < N; ++i)
		v[i] = u[i];
}

inline void reorder(SvecInt_O v, VecLlong_I order)
{
#ifdef SLS_CHECK_SHAPES
	if ((Long)order.size() != (Long)v.size())
		SLS_ERR("wrong shape!");
#endif
	Long N = v.size();
	static VecInt u; u.resize(N);
	if (N > (Long)u.size())
		u.resize(max(N, Long(2*u.size())));
	for (Long i = 0; i < N; ++i)
		u[i] = v[order[i]];
	for (Long i = 0; i < N; ++i)
		v[i] = u[i];
}

inline void reorder(SvecLlong_O v, VecInt_I order)
{
#ifdef SLS_CHECK_SHAPES
	if ((Long)order.size() != (Long)v.size())
		SLS_ERR("wrong shape!");
#endif
	Long N = v.size();
	static VecLlong u; u.resize(N);
	if (N > (Long)u.size())
		u.resize(max(N, Long(2*u.size())));
	for (Long i = 0; i < N; ++i)
		u[i] = v[order[i]];
	for (Long i = 0; i < N; ++i)
		v[i] = u[i];
}

inline void reorder(SvecDoub_O v, VecLlong_I order)
{
#ifdef SLS_CHECK_SHAPES
	if ((Long)order.size() != (Long)v.size())
		SLS_ERR("wrong shape!");
#endif
	Long N = v.size();
	static VecDoub u; u.resize(N);
	if (N > (Long)u.size())
		u.resize(max(N, Long(2*u.size())));
	for (Long i = 0; i < N; ++i)
		u[i] = v[order[i]];
	for (Long i = 0; i < N; ++i)
		v[i] = u[i];
}

inline void reorder(SvecDoub_O v, VecInt_I order)
{
#ifdef SLS_CHECK_SHAPES
	if ((Long)order.size() != (Long)v.size())
		SLS_ERR("wrong shape!");
#endif
	Long N = v.size();
	static VecDoub u; u.resize(N);
	if (N > (Long)u.size())
		u.resize(max(N, Long(2*u.size())));
	for (Long i = 0; i < N; ++i)
		u[i] = v[order[i]];
	for (Long i = 0; i < N; ++i)
		v[i] = u[i];
}

inline void reorder(SvecQdoub_O v, VecLlong_I order)
{
#ifdef SLS_CHECK_SHAPES
	if ((Long)order.size() != (Long)v.size())
		SLS_ERR("wrong shape!");
#endif
	Long N = v.size();
	static VecQdoub u; u.resize(N);
	if (N > (Long)u.size())
		u.resize(max(N, Long(2*u.size())));
	for (Long i = 0; i < N; ++i)
		u[i] = v[order[i]];
	for (Long i = 0; i < N; ++i)
		v[i] = u[i];
}

inline void reorder(SvecQdoub_O v, VecInt_I order)
{
#ifdef SLS_CHECK_SHAPES
	if ((Long)order.size() != (Long)v.size())
		SLS_ERR("wrong shape!");
#endif
	Long N = v.size();
	static VecQdoub u; u.resize(N);
	if (N > (Long)u.size())
		u.resize(max(N, Long(2*u.size())));
	for (Long i = 0; i < N; ++i)
		u[i] = v[order[i]];
	for (Long i = 0; i < N; ++i)
		v[i] = u[i];
}

inline void reorder(SvecComp_O v, VecInt_I order)
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

inline void reorder(SvecQcomp_O v, VecInt_I order)
{
#ifdef SLS_CHECK_SHAPES
	if ((Long)order.size() != (Long)v.size())
		SLS_ERR("wrong shape!");
#endif
	Long N = v.size();
	static VecQcomp u; u.resize(N);
	if (N > (Long)u.size())
		u.resize(max(N, Long(2*u.size())));
	for (Long i = 0; i < N; ++i)
		u[i] = v[order[i]];
	for (Long i = 0; i < N; ++i)
		v[i] = u[i];
}


inline void trans(CmatInt_IO v)
{
#ifdef SLS_CHECK_SHAPES
	if (v.n0() != v.n1())
		SLS_ERR("illegal shape!");
#endif
	for (Long i = 0; i < v.n0(); ++i)
		for (Long j = 0; j < i; ++j)
			swap(v(i, j), v(j, i));
}

inline void trans(CmatDoub_IO v)
{
#ifdef SLS_CHECK_SHAPES
	if (v.n0() != v.n1())
		SLS_ERR("illegal shape!");
#endif
	for (Long i = 0; i < v.n0(); ++i)
		for (Long j = 0; j < i; ++j)
			swap(v(i, j), v(j, i));
}

inline void trans(CmatQdoub_IO v)
{
#ifdef SLS_CHECK_SHAPES
	if (v.n0() != v.n1())
		SLS_ERR("illegal shape!");
#endif
	for (Long i = 0; i < v.n0(); ++i)
		for (Long j = 0; j < i; ++j)
			swap(v(i, j), v(j, i));
}

inline void trans(ScmatDoub_IO v)
{
#ifdef SLS_CHECK_SHAPES
	if (v.n0() != v.n1())
		SLS_ERR("illegal shape!");
#endif
	for (Long i = 0; i < v.n0(); ++i)
		for (Long j = 0; j < i; ++j)
			swap(v(i, j), v(j, i));
}

inline void trans(ScmatQdoub_IO v)
{
#ifdef SLS_CHECK_SHAPES
	if (v.n0() != v.n1())
		SLS_ERR("illegal shape!");
#endif
	for (Long i = 0; i < v.n0(); ++i)
		for (Long j = 0; j < i; ++j)
			swap(v(i, j), v(j, i));
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

inline void trans(DcmatQdoub_IO v)
{
#ifdef SLS_CHECK_SHAPES
	if (v.n0() != v.n1())
		SLS_ERR("illegal shape!");
#endif
	for (Long i = 0; i < v.n0(); ++i)
		for (Long j = 0; j < i; ++j)
			swap(v(i, j), v(j, i));
}

inline void trans(CmatComp_IO v)
{
#ifdef SLS_CHECK_SHAPES
	if (v.n0() != v.n1())
		SLS_ERR("illegal shape!");
#endif
	for (Long i = 0; i < v.n0(); ++i)
		for (Long j = 0; j < i; ++j)
			swap(v(i, j), v(j, i));
}


inline void trans(CmatInt_O v, CmatInt_I v1)
{
#ifdef SLS_CHECK_SHAPES
	if (v.n0() != v1.n1() || v.n1() != v1.n0())
		SLS_ERR("wrong shape!");
#endif
	for (Long i = 0; i < v.n0(); ++i)
		for (Long j = 0; j < v.n1(); ++j)
			v(i, j) = v1(j, i);
}

inline void trans(CmatLlong_O v, CmatLlong_I v1)
{
#ifdef SLS_CHECK_SHAPES
	if (v.n0() != v1.n1() || v.n1() != v1.n0())
		SLS_ERR("wrong shape!");
#endif
	for (Long i = 0; i < v.n0(); ++i)
		for (Long j = 0; j < v.n1(); ++j)
			v(i, j) = v1(j, i);
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

inline void trans(CmatQdoub_O v, CmatQdoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
	if (v.n0() != v1.n1() || v.n1() != v1.n0())
		SLS_ERR("wrong shape!");
#endif
	for (Long i = 0; i < v.n0(); ++i)
		for (Long j = 0; j < v.n1(); ++j)
			v(i, j) = v1(j, i);
}

inline void trans(CmatComp_O v, CmatComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
	if (v.n0() != v1.n1() || v.n1() != v1.n0())
		SLS_ERR("wrong shape!");
#endif
	for (Long i = 0; i < v.n0(); ++i)
		for (Long j = 0; j < v.n1(); ++j)
			v(i, j) = v1(j, i);
}

inline void trans(CmatQcomp_O v, CmatQcomp_I v1)
{
#ifdef SLS_CHECK_SHAPES
	if (v.n0() != v1.n1() || v.n1() != v1.n0())
		SLS_ERR("wrong shape!");
#endif
	for (Long i = 0; i < v.n0(); ++i)
		for (Long j = 0; j < v.n1(); ++j)
			v(i, j) = v1(j, i);
}

inline void trans(MatComp_O v, CmatComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
	if (v.n0() != v1.n1() || v.n1() != v1.n0())
		SLS_ERR("wrong shape!");
#endif
	for (Long i = 0; i < v.n0(); ++i)
		for (Long j = 0; j < v.n1(); ++j)
			v(i, j) = v1(j, i);
}

inline void trans(ScmatDoub_O v, ScmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
	if (v.n0() != v1.n1() || v.n1() != v1.n0())
		SLS_ERR("wrong shape!");
#endif
	for (Long i = 0; i < v.n0(); ++i)
		for (Long j = 0; j < v.n1(); ++j)
			v(i, j) = v1(j, i);
}

inline void trans(ScmatQdoub_O v, ScmatQdoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
	if (v.n0() != v1.n1() || v.n1() != v1.n0())
		SLS_ERR("wrong shape!");
#endif
	for (Long i = 0; i < v.n0(); ++i)
		for (Long j = 0; j < v.n1(); ++j)
			v(i, j) = v1(j, i);
}

inline void trans(ScmatComp_O v, ScmatComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
	if (v.n0() != v1.n1() || v.n1() != v1.n0())
		SLS_ERR("wrong shape!");
#endif
	for (Long i = 0; i < v.n0(); ++i)
		for (Long j = 0; j < v.n1(); ++j)
			v(i, j) = v1(j, i);
}

inline void trans(ScmatQcomp_O v, ScmatQcomp_I v1)
{
#ifdef SLS_CHECK_SHAPES
	if (v.n0() != v1.n1() || v.n1() != v1.n0())
		SLS_ERR("wrong shape!");
#endif
	for (Long i = 0; i < v.n0(); ++i)
		for (Long j = 0; j < v.n1(); ++j)
			v(i, j) = v1(j, i);
}

inline void trans(CmatComp_O v, MatComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
	if (v.n0() != v1.n1() || v.n1() != v1.n0())
		SLS_ERR("wrong shape!");
#endif
	for (Long i = 0; i < v.n0(); ++i)
		for (Long j = 0; j < v.n1(); ++j)
			v(i, j) = v1(j, i);
}

inline void trans(DcmatComp_O v, DcmatComp_I v1)
{
#ifdef SLS_CHECK_SHAPES
	if (v.n0() != v1.n1() || v.n1() != v1.n0())
		SLS_ERR("wrong shape!");
#endif
	for (Long i = 0; i < v.n0(); ++i)
		for (Long j = 0; j < v.n1(); ++j)
			v(i, j) = v1(j, i);
}


inline void her(CmatComp_IO v)
{
#ifdef SLS_CHECK_SHAPES
	if (v.n0() != v.n1()) SLS_ERR("illegal shape!");
#endif
	trans(v); conj(v);
}


inline void her(CmatComp_O v, CmatComp_I v1)
{ trans(v, v1); conj(v); }

inline void her(CmatComp_O v, MatComp_I v1)
{ trans(v, v1); conj(v); }

inline void her(MatComp_O v, CmatComp_I v1)
{ trans(v, v1); conj(v); }

inline void her(DcmatComp_O v, DcmatComp_I v1)
{ trans(v, v1); conj(v); }


// get unique elements from a vector
template <class T>
inline void uniq_elm(vector<T> &v)
{
	Long N = v.size(), n = 0;
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
inline void uniq_rows(CmatInt_O a, CmatInt_I a1)
{
	Long k = 0;
	a.resize(a1.n0(), a1.n1());
	for (Long i = 0; i < a1.n0(); ++i) {
	    // check repeat
	    Bool repeat = false;
	    DvecInt_c s1 = cut1(a1, i);
	    for (Long j = 0; j < k; ++j) {
	        if (cut1(a, j) == s1) {
	            repeat = true; break;
	        }
	    }
	    if (repeat)
	        continue;
	    copy(cut1(a, k), s1);
	    ++k;
	}
	resize_cpy(a, k, a1.n1());
}

inline void uniq_rows(CmatLlong_O a, CmatLlong_I a1)
{
	Long k = 0;
	a.resize(a1.n0(), a1.n1());
	for (Long i = 0; i < a1.n0(); ++i) {
	    // check repeat
	    Bool repeat = false;
	    DvecLlong_c s1 = cut1(a1, i);
	    for (Long j = 0; j < k; ++j) {
	        if (cut1(a, j) == s1) {
	            repeat = true; break;
	        }
	    }
	    if (repeat)
	        continue;
	    copy(cut1(a, k), s1);
	    ++k;
	}
	resize_cpy(a, k, a1.n1());
}

inline void uniq_rows(CmatLlong_O a, ScmatLlong_I a1)
{
	Long k = 0;
	a.resize(a1.n0(), a1.n1());
	for (Long i = 0; i < a1.n0(); ++i) {
	    // check repeat
	    Bool repeat = false;
	    DvecLlong_c s1 = cut1(a1, i);
	    for (Long j = 0; j < k; ++j) {
	        if (cut1(a, j) == s1) {
	            repeat = true; break;
	        }
	    }
	    if (repeat)
	        continue;
	    copy(cut1(a, k), s1);
	    ++k;
	}
	resize_cpy(a, k, a1.n1());
}

inline void uniq_rows(CmatDoub_O a, CmatDoub_I a1)
{
	Long k = 0;
	a.resize(a1.n0(), a1.n1());
	for (Long i = 0; i < a1.n0(); ++i) {
	    // check repeat
	    Bool repeat = false;
	    DvecDoub_c s1 = cut1(a1, i);
	    for (Long j = 0; j < k; ++j) {
	        if (cut1(a, j) == s1) {
	            repeat = true; break;
	        }
	    }
	    if (repeat)
	        continue;
	    copy(cut1(a, k), s1);
	    ++k;
	}
	resize_cpy(a, k, a1.n1());
}

inline void uniq_rows(CmatQdoub_O a, CmatQdoub_I a1)
{
	Long k = 0;
	a.resize(a1.n0(), a1.n1());
	for (Long i = 0; i < a1.n0(); ++i) {
	    // check repeat
	    Bool repeat = false;
	    DvecQdoub_c s1 = cut1(a1, i);
	    for (Long j = 0; j < k; ++j) {
	        if (cut1(a, j) == s1) {
	            repeat = true; break;
	        }
	    }
	    if (repeat)
	        continue;
	    copy(cut1(a, k), s1);
	    ++k;
	}
	resize_cpy(a, k, a1.n1());
}


} // namespace slisc
