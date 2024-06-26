// functions that loop through every element of a container
// and output a scalar

#pragma once
#include "../arith/scalar_arith.h"
#include "../arith/compare.h"

namespace slisc {
// maximum/minimum element (pointer version)
// max_v(), min_v()
inline Doub max_v(const Doub *v, Long_I N, Long_I step = 1)
{
#ifdef SLS_CHECK_BOUNDS
	if (N <= 0) SLS_ERR("illegal length!");
#endif
	const Doub *end = v + N*step, *p = v; v+=step;
	for (; v < end; v+=step) if (*p < *v) p = v;
	return *p;
}

inline Doub max_v(Long_O ind, const Doub *v, Long_I N, Long_I step = 1)
{
#ifdef SLS_CHECK_BOUNDS
	if (N <= 0) SLS_ERR("illegal length!");
#endif
	const Doub *beg = v, *end = v + N, *p = v; v+=step;
	for (; v < end; ++v) if (*p < *v) p = v;
	ind = (p - beg)/step;
	return *p;
}

inline Doub max_dcmat(const Doub *v, Long_I N0, Long_I N1, Long_I step1)
{
#ifdef SLS_CHECK_BOUNDS
	if (N0 <= 0 || N1 <= 0 || step1 < N1) SLS_ERR("illegal length!");
#endif
	const Doub *p = v, *end = v + N1*step1, *beg0 = v, *end0 = v + N0;
	while (1) {
		if (v == end0) {
			beg0 += step1;
			if (beg0 >= end) break;
			v = beg0; end0 += step1;
		}
		if (*p < *v) p = v;
		++v;
	}
	return *p;
}

inline Doub max_dcmat(Long_O i, Long_O j, const Doub *v, Long_I N0, Long_I N1, Long_I step1)
{
#ifdef SLS_CHECK_BOUNDS
	if (N0 <= 0 || N1 <= 0 || step1 < N1) SLS_ERR("illegal length!");
#endif
	const Doub *p = v, *beg = v, *end = v + N1*step1, *beg0 = v, *end0 = v + N0;
	while (1) {
		if (v == end0) {
			beg0 += step1;
			if (beg0 >= end) break;
			v = beg0; end0 += step1;
		}
		if (*p < *v) p = v;
		++v;
	}
	i = (p - beg) % N0; j = (p - beg) / step1;
	return *p;
}


inline Qdoub max_v(const Qdoub *v, Long_I N, Long_I step = 1)
{
#ifdef SLS_CHECK_BOUNDS
	if (N <= 0) SLS_ERR("illegal length!");
#endif
	const Qdoub *end = v + N*step, *p = v; v+=step;
	for (; v < end; v+=step) if (*p < *v) p = v;
	return *p;
}

inline Qdoub max_v(Long_O ind, const Qdoub *v, Long_I N, Long_I step = 1)
{
#ifdef SLS_CHECK_BOUNDS
	if (N <= 0) SLS_ERR("illegal length!");
#endif
	const Qdoub *beg = v, *end = v + N, *p = v; v+=step;
	for (; v < end; ++v) if (*p < *v) p = v;
	ind = (p - beg)/step;
	return *p;
}

inline Qdoub max_dcmat(const Qdoub *v, Long_I N0, Long_I N1, Long_I step1)
{
#ifdef SLS_CHECK_BOUNDS
	if (N0 <= 0 || N1 <= 0 || step1 < N1) SLS_ERR("illegal length!");
#endif
	const Qdoub *p = v, *end = v + N1*step1, *beg0 = v, *end0 = v + N0;
	while (1) {
		if (v == end0) {
			beg0 += step1;
			if (beg0 >= end) break;
			v = beg0; end0 += step1;
		}
		if (*p < *v) p = v;
		++v;
	}
	return *p;
}

inline Qdoub max_dcmat(Long_O i, Long_O j, const Qdoub *v, Long_I N0, Long_I N1, Long_I step1)
{
#ifdef SLS_CHECK_BOUNDS
	if (N0 <= 0 || N1 <= 0 || step1 < N1) SLS_ERR("illegal length!");
#endif
	const Qdoub *p = v, *beg = v, *end = v + N1*step1, *beg0 = v, *end0 = v + N0;
	while (1) {
		if (v == end0) {
			beg0 += step1;
			if (beg0 >= end) break;
			v = beg0; end0 += step1;
		}
		if (*p < *v) p = v;
		++v;
	}
	i = (p - beg) % N0; j = (p - beg) / step1;
	return *p;
}


inline Doub min_v(const Doub *v, Long_I N, Long_I step = 1)
{
#ifdef SLS_CHECK_BOUNDS
	if (N <= 0) SLS_ERR("illegal length!");
#endif
	const Doub *end = v + N*step, *p = v; v+=step;
	for (; v < end; v+=step) if (*p > *v) p = v;
	return *p;
}

inline Doub min_v(Long_O ind, const Doub *v, Long_I N, Long_I step = 1)
{
#ifdef SLS_CHECK_BOUNDS
	if (N <= 0) SLS_ERR("illegal length!");
#endif
	const Doub *beg = v, *end = v + N, *p = v; v+=step;
	for (; v < end; ++v) if (*p > *v) p = v;
	ind = (p - beg)/step;
	return *p;
}

inline Doub min_dcmat(const Doub *v, Long_I N0, Long_I N1, Long_I step1)
{
#ifdef SLS_CHECK_BOUNDS
	if (N0 <= 0 || N1 <= 0 || step1 < N1) SLS_ERR("illegal length!");
#endif
	const Doub *p = v, *end = v + N1*step1, *beg0 = v, *end0 = v + N0;
	while (1) {
		if (v == end0) {
			beg0 += step1;
			if (beg0 >= end) break;
			v = beg0; end0 += step1;
		}
		if (*p > *v) p = v;
		++v;
	}
	return *p;
}

inline Doub min_dcmat(Long_O i, Long_O j, const Doub *v, Long_I N0, Long_I N1, Long_I step1)
{
#ifdef SLS_CHECK_BOUNDS
	if (N0 <= 0 || N1 <= 0 || step1 < N1) SLS_ERR("illegal length!");
#endif
	const Doub *p = v, *beg = v, *end = v + N1*step1, *beg0 = v, *end0 = v + N0;
	while (1) {
		if (v == end0) {
			beg0 += step1;
			if (beg0 >= end) break;
			v = beg0; end0 += step1;
		}
		if (*p > *v) p = v;
		++v;
	}
	i = (p - beg) % N0; j = (p - beg) / step1;
	return *p;
}


inline Qdoub min_v(const Qdoub *v, Long_I N, Long_I step = 1)
{
#ifdef SLS_CHECK_BOUNDS
	if (N <= 0) SLS_ERR("illegal length!");
#endif
	const Qdoub *end = v + N*step, *p = v; v+=step;
	for (; v < end; v+=step) if (*p > *v) p = v;
	return *p;
}

inline Qdoub min_v(Long_O ind, const Qdoub *v, Long_I N, Long_I step = 1)
{
#ifdef SLS_CHECK_BOUNDS
	if (N <= 0) SLS_ERR("illegal length!");
#endif
	const Qdoub *beg = v, *end = v + N, *p = v; v+=step;
	for (; v < end; ++v) if (*p > *v) p = v;
	ind = (p - beg)/step;
	return *p;
}

inline Qdoub min_dcmat(const Qdoub *v, Long_I N0, Long_I N1, Long_I step1)
{
#ifdef SLS_CHECK_BOUNDS
	if (N0 <= 0 || N1 <= 0 || step1 < N1) SLS_ERR("illegal length!");
#endif
	const Qdoub *p = v, *end = v + N1*step1, *beg0 = v, *end0 = v + N0;
	while (1) {
		if (v == end0) {
			beg0 += step1;
			if (beg0 >= end) break;
			v = beg0; end0 += step1;
		}
		if (*p > *v) p = v;
		++v;
	}
	return *p;
}

inline Qdoub min_dcmat(Long_O i, Long_O j, const Qdoub *v, Long_I N0, Long_I N1, Long_I step1)
{
#ifdef SLS_CHECK_BOUNDS
	if (N0 <= 0 || N1 <= 0 || step1 < N1) SLS_ERR("illegal length!");
#endif
	const Qdoub *p = v, *beg = v, *end = v + N1*step1, *beg0 = v, *end0 = v + N0;
	while (1) {
		if (v == end0) {
			beg0 += step1;
			if (beg0 >= end) break;
			v = beg0; end0 += step1;
		}
		if (*p > *v) p = v;
		++v;
	}
	i = (p - beg) % N0; j = (p - beg) / step1;
	return *p;
}


inline Int max_v(const Int *v, Long_I N, Long_I step = 1)
{
#ifdef SLS_CHECK_BOUNDS
	if (N <= 0) SLS_ERR("illegal length!");
#endif
	const Int *end = v + N*step, *p = v; v+=step;
	for (; v < end; v+=step) if (*p < *v) p = v;
	return *p;
}

inline Int max_v(Long_O ind, const Int *v, Long_I N, Long_I step = 1)
{
#ifdef SLS_CHECK_BOUNDS
	if (N <= 0) SLS_ERR("illegal length!");
#endif
	const Int *beg = v, *end = v + N, *p = v; v+=step;
	for (; v < end; ++v) if (*p < *v) p = v;
	ind = (p - beg)/step;
	return *p;
}

inline Int max_dcmat(const Int *v, Long_I N0, Long_I N1, Long_I step1)
{
#ifdef SLS_CHECK_BOUNDS
	if (N0 <= 0 || N1 <= 0 || step1 < N1) SLS_ERR("illegal length!");
#endif
	const Int *p = v, *end = v + N1*step1, *beg0 = v, *end0 = v + N0;
	while (1) {
		if (v == end0) {
			beg0 += step1;
			if (beg0 >= end) break;
			v = beg0; end0 += step1;
		}
		if (*p < *v) p = v;
		++v;
	}
	return *p;
}

inline Int max_dcmat(Long_O i, Long_O j, const Int *v, Long_I N0, Long_I N1, Long_I step1)
{
#ifdef SLS_CHECK_BOUNDS
	if (N0 <= 0 || N1 <= 0 || step1 < N1) SLS_ERR("illegal length!");
#endif
	const Int *p = v, *beg = v, *end = v + N1*step1, *beg0 = v, *end0 = v + N0;
	while (1) {
		if (v == end0) {
			beg0 += step1;
			if (beg0 >= end) break;
			v = beg0; end0 += step1;
		}
		if (*p < *v) p = v;
		++v;
	}
	i = (p - beg) % N0; j = (p - beg) / step1;
	return *p;
}


inline Int min_v(const Int *v, Long_I N, Long_I step = 1)
{
#ifdef SLS_CHECK_BOUNDS
	if (N <= 0) SLS_ERR("illegal length!");
#endif
	const Int *end = v + N*step, *p = v; v+=step;
	for (; v < end; v+=step) if (*p > *v) p = v;
	return *p;
}

inline Int min_v(Long_O ind, const Int *v, Long_I N, Long_I step = 1)
{
#ifdef SLS_CHECK_BOUNDS
	if (N <= 0) SLS_ERR("illegal length!");
#endif
	const Int *beg = v, *end = v + N, *p = v; v+=step;
	for (; v < end; ++v) if (*p > *v) p = v;
	ind = (p - beg)/step;
	return *p;
}

inline Int min_dcmat(const Int *v, Long_I N0, Long_I N1, Long_I step1)
{
#ifdef SLS_CHECK_BOUNDS
	if (N0 <= 0 || N1 <= 0 || step1 < N1) SLS_ERR("illegal length!");
#endif
	const Int *p = v, *end = v + N1*step1, *beg0 = v, *end0 = v + N0;
	while (1) {
		if (v == end0) {
			beg0 += step1;
			if (beg0 >= end) break;
			v = beg0; end0 += step1;
		}
		if (*p > *v) p = v;
		++v;
	}
	return *p;
}

inline Int min_dcmat(Long_O i, Long_O j, const Int *v, Long_I N0, Long_I N1, Long_I step1)
{
#ifdef SLS_CHECK_BOUNDS
	if (N0 <= 0 || N1 <= 0 || step1 < N1) SLS_ERR("illegal length!");
#endif
	const Int *p = v, *beg = v, *end = v + N1*step1, *beg0 = v, *end0 = v + N0;
	while (1) {
		if (v == end0) {
			beg0 += step1;
			if (beg0 >= end) break;
			v = beg0; end0 += step1;
		}
		if (*p > *v) p = v;
		++v;
	}
	i = (p - beg) % N0; j = (p - beg) / step1;
	return *p;
}


inline Llong max_v(const Llong *v, Long_I N, Long_I step = 1)
{
#ifdef SLS_CHECK_BOUNDS
	if (N <= 0) SLS_ERR("illegal length!");
#endif
	const Llong *end = v + N*step, *p = v; v+=step;
	for (; v < end; v+=step) if (*p < *v) p = v;
	return *p;
}

inline Llong max_v(Long_O ind, const Llong *v, Long_I N, Long_I step = 1)
{
#ifdef SLS_CHECK_BOUNDS
	if (N <= 0) SLS_ERR("illegal length!");
#endif
	const Llong *beg = v, *end = v + N, *p = v; v+=step;
	for (; v < end; ++v) if (*p < *v) p = v;
	ind = (p - beg)/step;
	return *p;
}

inline Llong max_dcmat(const Llong *v, Long_I N0, Long_I N1, Long_I step1)
{
#ifdef SLS_CHECK_BOUNDS
	if (N0 <= 0 || N1 <= 0 || step1 < N1) SLS_ERR("illegal length!");
#endif
	const Llong *p = v, *end = v + N1*step1, *beg0 = v, *end0 = v + N0;
	while (1) {
		if (v == end0) {
			beg0 += step1;
			if (beg0 >= end) break;
			v = beg0; end0 += step1;
		}
		if (*p < *v) p = v;
		++v;
	}
	return *p;
}

inline Llong max_dcmat(Long_O i, Long_O j, const Llong *v, Long_I N0, Long_I N1, Long_I step1)
{
#ifdef SLS_CHECK_BOUNDS
	if (N0 <= 0 || N1 <= 0 || step1 < N1) SLS_ERR("illegal length!");
#endif
	const Llong *p = v, *beg = v, *end = v + N1*step1, *beg0 = v, *end0 = v + N0;
	while (1) {
		if (v == end0) {
			beg0 += step1;
			if (beg0 >= end) break;
			v = beg0; end0 += step1;
		}
		if (*p < *v) p = v;
		++v;
	}
	i = (p - beg) % N0; j = (p - beg) / step1;
	return *p;
}


inline Llong min_v(const Llong *v, Long_I N, Long_I step = 1)
{
#ifdef SLS_CHECK_BOUNDS
	if (N <= 0) SLS_ERR("illegal length!");
#endif
	const Llong *end = v + N*step, *p = v; v+=step;
	for (; v < end; v+=step) if (*p > *v) p = v;
	return *p;
}

inline Llong min_v(Long_O ind, const Llong *v, Long_I N, Long_I step = 1)
{
#ifdef SLS_CHECK_BOUNDS
	if (N <= 0) SLS_ERR("illegal length!");
#endif
	const Llong *beg = v, *end = v + N, *p = v; v+=step;
	for (; v < end; ++v) if (*p > *v) p = v;
	ind = (p - beg)/step;
	return *p;
}

inline Llong min_dcmat(const Llong *v, Long_I N0, Long_I N1, Long_I step1)
{
#ifdef SLS_CHECK_BOUNDS
	if (N0 <= 0 || N1 <= 0 || step1 < N1) SLS_ERR("illegal length!");
#endif
	const Llong *p = v, *end = v + N1*step1, *beg0 = v, *end0 = v + N0;
	while (1) {
		if (v == end0) {
			beg0 += step1;
			if (beg0 >= end) break;
			v = beg0; end0 += step1;
		}
		if (*p > *v) p = v;
		++v;
	}
	return *p;
}

inline Llong min_dcmat(Long_O i, Long_O j, const Llong *v, Long_I N0, Long_I N1, Long_I step1)
{
#ifdef SLS_CHECK_BOUNDS
	if (N0 <= 0 || N1 <= 0 || step1 < N1) SLS_ERR("illegal length!");
#endif
	const Llong *p = v, *beg = v, *end = v + N1*step1, *beg0 = v, *end0 = v + N0;
	while (1) {
		if (v == end0) {
			beg0 += step1;
			if (beg0 >= end) break;
			v = beg0; end0 += step1;
		}
		if (*p > *v) p = v;
		++v;
	}
	i = (p - beg) % N0; j = (p - beg) / step1;
	return *p;
}



inline Int max(vecInt_I v) { return max_v(v.data(), v.size()); }

inline Int max(Long_O ind, vecInt_I v) { return max_v(ind, v.data(), v.size()); }

inline Int min(vecInt_I v) { return min_v(v.data(), v.size()); }

inline Int min(Long_O ind, vecInt_I v) { return min_v(ind, v.data(), v.size()); }

inline Llong max(vecLlong_I v) { return max_v(v.data(), v.size()); }

inline Llong max(Long_O ind, vecLlong_I v) { return max_v(ind, v.data(), v.size()); }

inline Llong min(vecLlong_I v) { return min_v(v.data(), v.size()); }

inline Llong min(Long_O ind, vecLlong_I v) { return min_v(ind, v.data(), v.size()); }

inline Int max(SvbaseInt_I v) { return max_v(v.p(), v.size()); }

inline Int max(Long_O ind, SvbaseInt_I v) { return max_v(ind, v.p(), v.size()); }

inline Int min(SvbaseInt_I v) { return min_v(v.p(), v.size()); }

inline Int min(Long_O ind, SvbaseInt_I v) { return min_v(ind, v.p(), v.size()); }

inline Llong max(SvbaseLlong_I v) { return max_v(v.p(), v.size()); }

inline Llong max(Long_O ind, SvbaseLlong_I v) { return max_v(ind, v.p(), v.size()); }

inline Llong min(SvbaseLlong_I v) { return min_v(v.p(), v.size()); }

inline Llong min(Long_O ind, SvbaseLlong_I v) { return min_v(ind, v.p(), v.size()); }

inline Doub max(SvbaseDoub_I v) { return max_v(v.p(), v.size()); }

inline Doub max(Long_O ind, SvbaseDoub_I v) { return max_v(ind, v.p(), v.size()); }

inline Doub min(SvbaseDoub_I v) { return min_v(v.p(), v.size()); }

inline Doub min(Long_O ind, SvbaseDoub_I v) { return min_v(ind, v.p(), v.size()); }

inline Qdoub max(SvbaseQdoub_I v) { return max_v(v.p(), v.size()); }

inline Qdoub max(Long_O ind, SvbaseQdoub_I v) { return max_v(ind, v.p(), v.size()); }

inline Qdoub min(SvbaseQdoub_I v) { return min_v(v.p(), v.size()); }

inline Qdoub min(Long_O ind, SvbaseQdoub_I v) { return min_v(ind, v.p(), v.size()); }

inline Int max(vvecInt_I v) {
	Int s = numeric_limits<Int>::min(), s1;
	for (auto &v1 : v) { s1 = max(v1); if (s < s1) s = s1; }
	return s;
}

inline Int max(Long_O ind, vvecInt_I v) {
	Long ind1;
	Int s = numeric_limits<Int>::min(), s1;
	for (auto &v1 : v) { s1 = max(ind1, v1); if (s < s1) s = s1, ind = ind1; }
	return s;
}

inline Int min(vvecInt_I v) {
	Int s = numeric_limits<Int>::max(), s1;
	for (auto &v1 : v) { s1 = min(v1); if (s1 < s) s = s1; }
	return s;
}

inline Int min(Long_O ind, vvecInt_I v) {
	Long ind1;
	Int s = numeric_limits<Int>::max(), s1;
	for (auto &v1 : v) { s1 = min(ind1, v1); if (s1 < s) s = s1, ind = ind1; }
	return s;
}

inline Llong max(vvecLlong_I v) {
	Llong s = numeric_limits<Llong>::min(), s1;
	for (auto &v1 : v) { s1 = max(v1); if (s < s1) s = s1; }
	return s;
}

inline Llong max(Long_O ind, vvecLlong_I v) {
	Long ind1;
	Llong s = numeric_limits<Llong>::min(), s1;
	for (auto &v1 : v) { s1 = max(ind1, v1); if (s < s1) s = s1, ind = ind1; }
	return s;
}

inline Llong min(vvecLlong_I v) {
	Llong s = numeric_limits<Llong>::max(), s1;
	for (auto &v1 : v) { s1 = min(v1); if (s1 < s) s = s1; }
	return s;
}

inline Llong min(Long_O ind, vvecLlong_I v) {
	Long ind1;
	Llong s = numeric_limits<Llong>::max(), s1;
	for (auto &v1 : v) { s1 = min(ind1, v1); if (s1 < s) s = s1, ind = ind1; }
	return s;
}

inline Llong max(DcmatLlong_I v) { return max_dcmat(v.p(), v.n0(), v.n1(), v.lda()); }

inline Llong max2(Long_O i, Long_O j, DcmatLlong_I v) { return max_dcmat(i, j, v.p(), v.n0(), v.n1(), v.lda()); }

inline Llong min(DcmatLlong_I v) { return min_dcmat(v.p(), v.n0(), v.n1(), v.lda()); }

inline Llong min2(Long_O i, Long_O j, DcmatLlong_I v) { return min_dcmat(i, j, v.p(), v.n0(), v.n1(), v.lda()); }

inline Doub max(DcmatDoub_I v) { return max_dcmat(v.p(), v.n0(), v.n1(), v.lda()); }

inline Doub max2(Long_O i, Long_O j, DcmatDoub_I v) { return max_dcmat(i, j, v.p(), v.n0(), v.n1(), v.lda()); }

inline Doub min(DcmatDoub_I v) { return min_dcmat(v.p(), v.n0(), v.n1(), v.lda()); }

inline Doub min2(Long_O i, Long_O j, DcmatDoub_I v) { return min_dcmat(i, j, v.p(), v.n0(), v.n1(), v.lda()); }

inline Qdoub max(DcmatQdoub_I v) { return max_dcmat(v.p(), v.n0(), v.n1(), v.lda()); }

inline Qdoub max2(Long_O i, Long_O j, DcmatQdoub_I v) { return max_dcmat(i, j, v.p(), v.n0(), v.n1(), v.lda()); }

inline Qdoub min(DcmatQdoub_I v) { return min_dcmat(v.p(), v.n0(), v.n1(), v.lda()); }

inline Qdoub min2(Long_O i, Long_O j, DcmatQdoub_I v) { return min_dcmat(i, j, v.p(), v.n0(), v.n1(), v.lda()); }

inline Doub max(VecDoub_I v) { return max_v(v.p(), v.size()); }

inline Doub max(Long_O ind, VecDoub_I v) { return max_v(ind, v.p(), v.size()); }

inline Doub min(VecDoub_I v) { return min_v(v.p(), v.size()); }

inline Doub min(Long_O ind, VecDoub_I v) { return min_v(ind, v.p(), v.size()); }

inline Qdoub max(VecQdoub_I v) { return max_v(v.p(), v.size()); }

inline Qdoub max(Long_O ind, VecQdoub_I v) { return max_v(ind, v.p(), v.size()); }

inline Qdoub min(VecQdoub_I v) { return min_v(v.p(), v.size()); }

inline Qdoub min(Long_O ind, VecQdoub_I v) { return min_v(ind, v.p(), v.size()); }

inline Int max(SvecInt_I v) { return max_v(v.p(), v.size()); }

inline Int max(Long_O ind, SvecInt_I v) { return max_v(ind, v.p(), v.size()); }

inline Int min(SvecInt_I v) { return min_v(v.p(), v.size()); }

inline Int min(Long_O ind, SvecInt_I v) { return min_v(ind, v.p(), v.size()); }

inline Doub max(SvecDoub_I v) { return max_v(v.p(), v.size()); }

inline Doub max(Long_O ind, SvecDoub_I v) { return max_v(ind, v.p(), v.size()); }

inline Doub min(SvecDoub_I v) { return min_v(v.p(), v.size()); }

inline Doub min(Long_O ind, SvecDoub_I v) { return min_v(ind, v.p(), v.size()); }

inline Qdoub max(SvecQdoub_I v) { return max_v(v.p(), v.size()); }

inline Qdoub max(Long_O ind, SvecQdoub_I v) { return max_v(ind, v.p(), v.size()); }

inline Qdoub min(SvecQdoub_I v) { return min_v(v.p(), v.size()); }

inline Qdoub min(Long_O ind, SvecQdoub_I v) { return min_v(ind, v.p(), v.size()); }



template <class T>
inline T min(const vector<vector<T>> &v)
{
	T s = numeric_limits<T>::max();
	for (auto &v1 : v)
		for (auto &e : v1)
			if (e < s) s = e;
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

inline Doub max_abs_v(Long_O ind, const Doub *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (N <= 0) SLS_ERR("illegal length!");
#endif
	Doub s = abs(v[0]), val;
	ind = 0;
	for (Long i = 1; i < N; ++i) {
		val = abs(v[i]);
		if (s < val) {
			s = val;
			ind = i;
		}
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

inline Doub max_abs_dcmat(const Doub *v, Long_I N0, Long_I N1, Long_I step1)
{
#ifdef SLS_CHECK_BOUNDS
	if (N0 <= 0 || N1 <= 0 || step1 < N1) SLS_ERR("illegal length!");
#endif
	const Doub *end = v + N1*step1, *beg0 = v, *end0 = v + N0;
	Doub s = abs(*v); ++v;
	while (1) {
		if (v == end0) {
			beg0 += step1;
			if (beg0 >= end) break;
			v = beg0; end0 += step1;
		}
		const Doub &t = abs(*v);
		if (s < t) s = abs(t);
		++v;
	}
	return s;
}

inline Doub max_abs_dcmat(Long_O i, Long_O j, const Doub *v, Long_I N0, Long_I N1, Long_I step1)
{
#ifdef SLS_CHECK_BOUNDS
	if (N0 <= 0 || N1 <= 0 || step1 < N1) SLS_ERR("illegal length!");
#endif
	const Doub *p = v, *beg = v, *end = v + N1*step1, *beg0 = v, *end0 = v + N0;
	Doub s = abs(*v); ++v;
	while (1) {
		if (v == end0) {
			beg0 += step1;
			if (beg0 >= end) break;
			v = beg0; end0 += step1;
		}
		const Doub &t = abs(*v);
		if (s < t) s = abs(t), p = v;
		++v;
	}
	i = (p - beg) % N0; j = (p - beg) / step1;
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

inline Qdoub max_abs_v(Long_O ind, const Qdoub *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (N <= 0) SLS_ERR("illegal length!");
#endif
	Qdoub s = abs(v[0]), val;
	ind = 0;
	for (Long i = 1; i < N; ++i) {
		val = abs(v[i]);
		if (s < val) {
			s = val;
			ind = i;
		}
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

inline Qdoub max_abs_dcmat(const Qdoub *v, Long_I N0, Long_I N1, Long_I step1)
{
#ifdef SLS_CHECK_BOUNDS
	if (N0 <= 0 || N1 <= 0 || step1 < N1) SLS_ERR("illegal length!");
#endif
	const Qdoub *end = v + N1*step1, *beg0 = v, *end0 = v + N0;
	Qdoub s = abs(*v); ++v;
	while (1) {
		if (v == end0) {
			beg0 += step1;
			if (beg0 >= end) break;
			v = beg0; end0 += step1;
		}
		const Qdoub &t = abs(*v);
		if (s < t) s = abs(t);
		++v;
	}
	return s;
}

inline Qdoub max_abs_dcmat(Long_O i, Long_O j, const Qdoub *v, Long_I N0, Long_I N1, Long_I step1)
{
#ifdef SLS_CHECK_BOUNDS
	if (N0 <= 0 || N1 <= 0 || step1 < N1) SLS_ERR("illegal length!");
#endif
	const Qdoub *p = v, *beg = v, *end = v + N1*step1, *beg0 = v, *end0 = v + N0;
	Qdoub s = abs(*v); ++v;
	while (1) {
		if (v == end0) {
			beg0 += step1;
			if (beg0 >= end) break;
			v = beg0; end0 += step1;
		}
		const Qdoub &t = abs(*v);
		if (s < t) s = abs(t), p = v;
		++v;
	}
	i = (p - beg) % N0; j = (p - beg) / step1;
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

inline Int max_abs_v(Long_O ind, const Int *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (N <= 0) SLS_ERR("illegal length!");
#endif
	Int s = abs(v[0]), val;
	ind = 0;
	for (Long i = 1; i < N; ++i) {
		val = abs(v[i]);
		if (s < val) {
			s = val;
			ind = i;
		}
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

inline Int max_abs_dcmat(const Int *v, Long_I N0, Long_I N1, Long_I step1)
{
#ifdef SLS_CHECK_BOUNDS
	if (N0 <= 0 || N1 <= 0 || step1 < N1) SLS_ERR("illegal length!");
#endif
	const Int *end = v + N1*step1, *beg0 = v, *end0 = v + N0;
	Int s = abs(*v); ++v;
	while (1) {
		if (v == end0) {
			beg0 += step1;
			if (beg0 >= end) break;
			v = beg0; end0 += step1;
		}
		const Int &t = abs(*v);
		if (s < t) s = abs(t);
		++v;
	}
	return s;
}

inline Int max_abs_dcmat(Long_O i, Long_O j, const Int *v, Long_I N0, Long_I N1, Long_I step1)
{
#ifdef SLS_CHECK_BOUNDS
	if (N0 <= 0 || N1 <= 0 || step1 < N1) SLS_ERR("illegal length!");
#endif
	const Int *p = v, *beg = v, *end = v + N1*step1, *beg0 = v, *end0 = v + N0;
	Int s = abs(*v); ++v;
	while (1) {
		if (v == end0) {
			beg0 += step1;
			if (beg0 >= end) break;
			v = beg0; end0 += step1;
		}
		const Int &t = abs(*v);
		if (s < t) s = abs(t), p = v;
		++v;
	}
	i = (p - beg) % N0; j = (p - beg) / step1;
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

inline Doub max_abs_v(Long_O ind, const Comp *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (N <= 0) SLS_ERR("illegal length!");
#endif
	Doub s = abs(v[0]), val;
	ind = 0;
	for (Long i = 1; i < N; ++i) {
		val = abs(v[i]);
		if (s < val) {
			s = val;
			ind = i;
		}
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

inline Doub max_abs_dcmat(const Comp *v, Long_I N0, Long_I N1, Long_I step1)
{
#ifdef SLS_CHECK_BOUNDS
	if (N0 <= 0 || N1 <= 0 || step1 < N1) SLS_ERR("illegal length!");
#endif
	const Comp *end = v + N1*step1, *beg0 = v, *end0 = v + N0;
	Doub s = abs(*v); ++v;
	while (1) {
		if (v == end0) {
			beg0 += step1;
			if (beg0 >= end) break;
			v = beg0; end0 += step1;
		}
		const Doub &t = abs(*v);
		if (s < t) s = abs(t);
		++v;
	}
	return s;
}

inline Doub max_abs_dcmat(Long_O i, Long_O j, const Comp *v, Long_I N0, Long_I N1, Long_I step1)
{
#ifdef SLS_CHECK_BOUNDS
	if (N0 <= 0 || N1 <= 0 || step1 < N1) SLS_ERR("illegal length!");
#endif
	const Comp *p = v, *beg = v, *end = v + N1*step1, *beg0 = v, *end0 = v + N0;
	Doub s = abs(*v); ++v;
	while (1) {
		if (v == end0) {
			beg0 += step1;
			if (beg0 >= end) break;
			v = beg0; end0 += step1;
		}
		const Doub &t = abs(*v);
		if (s < t) s = abs(t), p = v;
		++v;
	}
	i = (p - beg) % N0; j = (p - beg) / step1;
	return s;
}

inline Qdoub max_abs_v(const Qcomp *v, Long_I N)
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

inline Qdoub max_abs_v(Long_O ind, const Qcomp *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (N <= 0) SLS_ERR("illegal length!");
#endif
	Qdoub s = abs(v[0]), val;
	ind = 0;
	for (Long i = 1; i < N; ++i) {
		val = abs(v[i]);
		if (s < val) {
			s = val;
			ind = i;
		}
	}
	return s;
}

inline Qdoub max_abs_v(const Qcomp *v, Long_I N, Long_I step)
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

inline Qdoub max_abs_dcmat(const Qcomp *v, Long_I N0, Long_I N1, Long_I step1)
{
#ifdef SLS_CHECK_BOUNDS
	if (N0 <= 0 || N1 <= 0 || step1 < N1) SLS_ERR("illegal length!");
#endif
	const Qcomp *end = v + N1*step1, *beg0 = v, *end0 = v + N0;
	Qdoub s = abs(*v); ++v;
	while (1) {
		if (v == end0) {
			beg0 += step1;
			if (beg0 >= end) break;
			v = beg0; end0 += step1;
		}
		const Qdoub &t = abs(*v);
		if (s < t) s = abs(t);
		++v;
	}
	return s;
}

inline Qdoub max_abs_dcmat(Long_O i, Long_O j, const Qcomp *v, Long_I N0, Long_I N1, Long_I step1)
{
#ifdef SLS_CHECK_BOUNDS
	if (N0 <= 0 || N1 <= 0 || step1 < N1) SLS_ERR("illegal length!");
#endif
	const Qcomp *p = v, *beg = v, *end = v + N1*step1, *beg0 = v, *end0 = v + N0;
	Qdoub s = abs(*v); ++v;
	while (1) {
		if (v == end0) {
			beg0 += step1;
			if (beg0 >= end) break;
			v = beg0; end0 += step1;
		}
		const Qdoub &t = abs(*v);
		if (s < t) s = abs(t), p = v;
		++v;
	}
	i = (p - beg) % N0; j = (p - beg) / step1;
	return s;
}


inline Doub max_abs(SvbaseDoub_I v) { return max_abs_v(v.p(), v.size()); }
inline Doub max_abs(Long_O ind, SvbaseDoub_I v) { return max_abs_v(ind, v.p(), v.size()); }

inline Doub max_abs_par(Long_O ind, SvbaseDoub_I v) {
	const Doub *p = v.p();
	Doub s, m = abs(p[0]);
	ind = 0;
#pragma omp parallel for reduction(max:m)
	for (Long i = 1; i < v.size(); ++i) {
		s = abs(p[i]);
		if (m < s) {
			m = s; ind = i;
		}
	}
	return m;
}

inline Qdoub max_abs(SvbaseQdoub_I v) { return max_abs_v(v.p(), v.size()); }
inline Qdoub max_abs(Long_O ind, SvbaseQdoub_I v) { return max_abs_v(ind, v.p(), v.size()); }

inline Qdoub max_abs_par(Long_O ind, SvbaseQdoub_I v) {
	const Qdoub *p = v.p();
	Qdoub s, m = abs(p[0]);
	ind = 0;
#pragma omp parallel for reduction(max:m)
	for (Long i = 1; i < v.size(); ++i) {
		s = abs(p[i]);
		if (m < s) {
			m = s; ind = i;
		}
	}
	return m;
}

inline Int max_abs(SvbaseInt_I v) { return max_abs_v(v.p(), v.size()); }
inline Int max_abs(Long_O ind, SvbaseInt_I v) { return max_abs_v(ind, v.p(), v.size()); }

inline Int max_abs_par(Long_O ind, SvbaseInt_I v) {
	const Int *p = v.p();
	Int s, m = abs(p[0]);
	ind = 0;
#pragma omp parallel for reduction(max:m)
	for (Long i = 1; i < v.size(); ++i) {
		s = abs(p[i]);
		if (m < s) {
			m = s; ind = i;
		}
	}
	return m;
}

inline Doub max_abs(SvbaseComp_I v) { return max_abs_v(v.p(), v.size()); }
inline Doub max_abs(Long_O ind, SvbaseComp_I v) { return max_abs_v(ind, v.p(), v.size()); }

inline Doub max_abs_par(Long_O ind, SvbaseComp_I v) {
	const Comp *p = v.p();
	Doub s, m = abs(p[0]);
	ind = 0;
#pragma omp parallel for reduction(max:m)
	for (Long i = 1; i < v.size(); ++i) {
		s = abs(p[i]);
		if (m < s) {
			m = s; ind = i;
		}
	}
	return m;
}

inline Qdoub max_abs(SvbaseQcomp_I v) { return max_abs_v(v.p(), v.size()); }
inline Qdoub max_abs(Long_O ind, SvbaseQcomp_I v) { return max_abs_v(ind, v.p(), v.size()); }

inline Qdoub max_abs_par(Long_O ind, SvbaseQcomp_I v) {
	const Qcomp *p = v.p();
	Qdoub s, m = abs(p[0]);
	ind = 0;
#pragma omp parallel for reduction(max:m)
	for (Long i = 1; i < v.size(); ++i) {
		s = abs(p[i]);
		if (m < s) {
			m = s; ind = i;
		}
	}
	return m;
}

inline Doub max_abs(DvecDoub_I v) { return max_abs_v(v.p(), v.size(), v.step()); }

inline Qdoub max_abs(DvecQdoub_I v) { return max_abs_v(v.p(), v.size(), v.step()); }

inline Doub max_abs(DvecComp_I v) { return max_abs_v(v.p(), v.size(), v.step()); }

inline Qdoub max_abs(DvecQcomp_I v) { return max_abs_v(v.p(), v.size(), v.step()); }

inline Doub max_abs(MatComp_I v) { return max_abs_v(v.p(), v.size()); }
inline Doub max_abs(Long_O ind, MatComp_I v) { return max_abs_v(ind, v.p(), v.size()); }

inline Doub max_abs_par(Long_O ind, MatComp_I v) {
	const Comp *p = v.p();
	Doub s, m = abs(p[0]);
	ind = 0;
#pragma omp parallel for reduction(max:m)
	for (Long i = 1; i < v.size(); ++i) {
		s = abs(p[i]);
		if (m < s) {
			m = s; ind = i;
		}
	}
	return m;
}

inline Doub max_abs(DcmatDoub_I v) { return max_abs_dcmat(v.p(), v.n0(), v.n1(), v.lda()); }
inline Doub max_abs(Long_O i, Long_O j, DcmatDoub_I v) { return max_abs_dcmat(i, j, v.p(), v.n0(), v.n1(), v.lda()); }

inline Doub max_abs_par(DcmatDoub_I a) {
	Long Nr = a.n0();
	Doub m2 = 0;
#pragma omp parallel for reduction(max:m2)
	for (Long j = 0; j < a.n1(); ++j) {
		const Doub *p = &a(0, j);
		Doub s, m = abs(p[0]);
		for (Long i = 1; i < Nr; ++i) {
			s = abs(p[i]);
			if (m < s) m = s;
		}
		if (m > m2) m2 = m;
	}
	return m2;
}

inline Doub max_abs_par(Long_O ind0, Long_O ind1, DcmatDoub_I a) {
	Long Nr = a.n0();
	Doub m2 = 0;
#pragma omp parallel for reduction(max:m2)
	for (Long j = 0; j < a.n1(); ++j) {
		const Doub *p = &a(0, j);
		Doub s, m = abs(p[0]);
		ind0 = 0, ind1 = j;
		for (Long i = 1; i < Nr; ++i) {
			s = abs(p[i]);
			if (m < s) {
				m = s; ind0 = i; ind1 = j;
			}
		}
		if (m > m2) m2 = m;
	}
	return m2;
}

inline Qdoub max_abs(DcmatQdoub_I v) { return max_abs_dcmat(v.p(), v.n0(), v.n1(), v.lda()); }
inline Qdoub max_abs(Long_O i, Long_O j, DcmatQdoub_I v) { return max_abs_dcmat(i, j, v.p(), v.n0(), v.n1(), v.lda()); }

inline Qdoub max_abs_par(DcmatQdoub_I a) {
	Long Nr = a.n0();
	Qdoub m2 = 0;
#pragma omp parallel for reduction(max:m2)
	for (Long j = 0; j < a.n1(); ++j) {
		const Qdoub *p = &a(0, j);
		Qdoub s, m = abs(p[0]);
		for (Long i = 1; i < Nr; ++i) {
			s = abs(p[i]);
			if (m < s) m = s;
		}
		if (m > m2) m2 = m;
	}
	return m2;
}

inline Qdoub max_abs_par(Long_O ind0, Long_O ind1, DcmatQdoub_I a) {
	Long Nr = a.n0();
	Qdoub m2 = 0;
#pragma omp parallel for reduction(max:m2)
	for (Long j = 0; j < a.n1(); ++j) {
		const Qdoub *p = &a(0, j);
		Qdoub s, m = abs(p[0]);
		ind0 = 0, ind1 = j;
		for (Long i = 1; i < Nr; ++i) {
			s = abs(p[i]);
			if (m < s) {
				m = s; ind0 = i; ind1 = j;
			}
		}
		if (m > m2) m2 = m;
	}
	return m2;
}

inline Doub max_abs(DcmatComp_I v) { return max_abs_dcmat(v.p(), v.n0(), v.n1(), v.lda()); }
inline Doub max_abs(Long_O i, Long_O j, DcmatComp_I v) { return max_abs_dcmat(i, j, v.p(), v.n0(), v.n1(), v.lda()); }

inline Doub max_abs_par(DcmatComp_I a) {
	Long Nr = a.n0();
	Doub m2 = 0;
#pragma omp parallel for reduction(max:m2)
	for (Long j = 0; j < a.n1(); ++j) {
		const Comp *p = &a(0, j);
		Doub s, m = abs(p[0]);
		for (Long i = 1; i < Nr; ++i) {
			s = abs(p[i]);
			if (m < s) m = s;
		}
		if (m > m2) m2 = m;
	}
	return m2;
}

inline Doub max_abs_par(Long_O ind0, Long_O ind1, DcmatComp_I a) {
	Long Nr = a.n0();
	Doub m2 = 0;
#pragma omp parallel for reduction(max:m2)
	for (Long j = 0; j < a.n1(); ++j) {
		const Comp *p = &a(0, j);
		Doub s, m = abs(p[0]);
		ind0 = 0, ind1 = j;
		for (Long i = 1; i < Nr; ++i) {
			s = abs(p[i]);
			if (m < s) {
				m = s; ind0 = i; ind1 = j;
			}
		}
		if (m > m2) m2 = m;
	}
	return m2;
}

inline Qdoub max_abs(DcmatQcomp_I v) { return max_abs_dcmat(v.p(), v.n0(), v.n1(), v.lda()); }
inline Qdoub max_abs(Long_O i, Long_O j, DcmatQcomp_I v) { return max_abs_dcmat(i, j, v.p(), v.n0(), v.n1(), v.lda()); }

inline Qdoub max_abs_par(DcmatQcomp_I a) {
	Long Nr = a.n0();
	Qdoub m2 = 0;
#pragma omp parallel for reduction(max:m2)
	for (Long j = 0; j < a.n1(); ++j) {
		const Qcomp *p = &a(0, j);
		Qdoub s, m = abs(p[0]);
		for (Long i = 1; i < Nr; ++i) {
			s = abs(p[i]);
			if (m < s) m = s;
		}
		if (m > m2) m2 = m;
	}
	return m2;
}

inline Qdoub max_abs_par(Long_O ind0, Long_O ind1, DcmatQcomp_I a) {
	Long Nr = a.n0();
	Qdoub m2 = 0;
#pragma omp parallel for reduction(max:m2)
	for (Long j = 0; j < a.n1(); ++j) {
		const Qcomp *p = &a(0, j);
		Qdoub s, m = abs(p[0]);
		ind0 = 0, ind1 = j;
		for (Long i = 1; i < Nr; ++i) {
			s = abs(p[i]);
			if (m < s) {
				m = s; ind0 = i; ind1 = j;
			}
		}
		if (m > m2) m2 = m;
	}
	return m2;
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

inline Qdoub sum_abs_v(const Qdoub *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (N <= 0) SLS_ERR("illegal length!");
#endif
	Qdoub s = abs(v[0]);
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

inline Qdoub sum_abs_v(const Qcomp *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (N <= 0) SLS_ERR("illegal length!");
#endif
	Qdoub s = abs(v[0]);
	for (Long i = 1; i < N; ++i)
		s += abs(v[i]);
	return s;
}


// sum of absolute values
inline Llong sum_abs(SvbaseInt_I v)
{ return sum_abs_v(v.p(), v.size()); }

inline Llong sum_abs(SvbaseLlong_I v)
{ return sum_abs_v(v.p(), v.size()); }

inline Doub sum_abs(SvbaseDoub_I v)
{ return sum_abs_v(v.p(), v.size()); }

inline Qdoub sum_abs(SvbaseQdoub_I v)
{ return sum_abs_v(v.p(), v.size()); }

inline Doub sum_abs(SvbaseComp_I v)
{ return sum_abs_v(v.p(), v.size()); }

inline Qdoub sum_abs(SvbaseQcomp_I v)
{ return sum_abs_v(v.p(), v.size()); }

inline Llong sum_abs(SvecInt_I v)
{ return sum_abs_v(v.p(), v.size()); }

inline Doub sum_abs(SvecDoub_I v)
{ return sum_abs_v(v.p(), v.size()); }

inline Qdoub sum_abs(SvecQdoub_I v)
{ return sum_abs_v(v.p(), v.size()); }

inline Doub sum_abs(SvecComp_I v)
{ return sum_abs_v(v.p(), v.size()); }

inline Qdoub sum_abs(SvecQcomp_I v)
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

inline Qdoub sum_v(const Qdoub *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (N <= 0) SLS_ERR("illegal length!");
#endif
	Qdoub s = v[0];
	for (Long i = 1; i < N; ++i)
		s += v[i];
	return s;
}

inline Qdoub prod_v(const Qdoub *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (N <= 0) SLS_ERR("illegal length!");
#endif
	Qdoub s = v[0];
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

inline Qcomp sum_v(const Qcomp *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (N <= 0) SLS_ERR("illegal length!");
#endif
	Qcomp s = v[0];
	for (Long i = 1; i < N; ++i)
		s += v[i];
	return s;
}

inline Qcomp prod_v(const Qcomp *v, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (N <= 0) SLS_ERR("illegal length!");
#endif
	Qcomp s = v[0];
	for (Long i = 1; i < N; ++i)
		s *= v[i];
	return s;
}


inline Llong sum(vecInt_I v) { return sum_v(v.data(), v.size()); }

inline Llong prod(vecInt_I v) { return prod_v(v.data(), v.size()); }

inline Llong sum(vecLlong_I v) { return sum_v(v.data(), v.size()); }

inline Llong prod(vecLlong_I v) { return prod_v(v.data(), v.size()); }

inline Doub sum(vecDoub_I v) { return sum_v(v.data(), v.size()); }

inline Doub prod(vecDoub_I v) { return prod_v(v.data(), v.size()); }

inline Qdoub sum(vecQdoub_I v) { return sum_v(v.data(), v.size()); }

inline Qdoub prod(vecQdoub_I v) { return prod_v(v.data(), v.size()); }

inline Llong sum(SvbaseInt_I v) { return sum_v(v.p(), v.size()); }

inline Llong prod(SvbaseInt_I v) { return prod_v(v.p(), v.size()); }

inline Llong sum(SvbaseLlong_I v) { return sum_v(v.p(), v.size()); }

inline Llong prod(SvbaseLlong_I v) { return prod_v(v.p(), v.size()); }

inline Doub sum(SvbaseDoub_I v) { return sum_v(v.p(), v.size()); }

inline Doub prod(SvbaseDoub_I v) { return prod_v(v.p(), v.size()); }

inline Qdoub sum(SvbaseQdoub_I v) { return sum_v(v.p(), v.size()); }

inline Qdoub prod(SvbaseQdoub_I v) { return prod_v(v.p(), v.size()); }

inline Comp sum(SvbaseComp_I v) { return sum_v(v.p(), v.size()); }

inline Comp prod(SvbaseComp_I v) { return prod_v(v.p(), v.size()); }

inline Qcomp sum(SvbaseQcomp_I v) { return sum_v(v.p(), v.size()); }

inline Qcomp prod(SvbaseQcomp_I v) { return prod_v(v.p(), v.size()); }

inline Comp sum(MatComp_I v) { return sum_v(v.p(), v.size()); }

inline Comp prod(MatComp_I v) { return prod_v(v.p(), v.size()); }


inline Doub norm2(SvbaseDoub_I v)
{
	Long N = v.size();
	Doub s2 = abs2(v[0]);
	for (Long i = 1; i < N; ++i)
		s2 += abs2(v[i]);
	return s2;
}

inline Doub norm2_dif(SvbaseDoub_I v, SvbaseDoub_I v1)
{
	Long N = v.size();
	Doub s2 = abs2(v[0] - v1[0]);
	for (Long i = 1; i < N; ++i)
		s2 += abs2(v[i] - v1[i]);
	return s2;
}

inline Doub norm2_par(SvbaseDoub_I v)
{
	Long N = v.size();
	Doub sum = 0;
#pragma omp parallel for reduction(+:sum)
	for (Long i = 0; i < N; ++i)
		sum += abs2(v[i]);
	return sum;
}

inline Doub norm_par(SvbaseDoub_I v)
{
	return sqrt(norm2_par(v));
}
inline Doub norm(SvbaseDoub_I v)
{
	return sqrt(norm2(v));
}

inline Doub norm_dif(SvbaseDoub_I v, SvbaseDoub_I v1)
{
	return sqrt(norm2_dif(v, v1));
}

inline Qdoub norm2(SvbaseQdoub_I v)
{
	Long N = v.size();
	Qdoub s2 = abs2(v[0]);
	for (Long i = 1; i < N; ++i)
		s2 += abs2(v[i]);
	return s2;
}

inline Qdoub norm2_dif(SvbaseQdoub_I v, SvbaseQdoub_I v1)
{
	Long N = v.size();
	Qdoub s2 = abs2(v[0] - v1[0]);
	for (Long i = 1; i < N; ++i)
		s2 += abs2(v[i] - v1[i]);
	return s2;
}

inline Qdoub norm2_par(SvbaseQdoub_I v)
{
	Long N = v.size();
	Doub sum = 0;
#pragma omp parallel for reduction(+:sum)
	for (Long i = 0; i < N; ++i)
		sum += abs2(v[i]);
	return sum;
}

inline Qdoub norm_par(SvbaseQdoub_I v)
{
	return sqrt(norm2_par(v));
}
inline Qdoub norm(SvbaseQdoub_I v)
{
	return sqrt(norm2(v));
}

inline Qdoub norm_dif(SvbaseQdoub_I v, SvbaseQdoub_I v1)
{
	return sqrt(norm2_dif(v, v1));
}

inline Doub norm2(SvbaseComp_I v)
{
	Long N = v.size();
	Doub s2 = abs2(v[0]);
	for (Long i = 1; i < N; ++i)
		s2 += abs2(v[i]);
	return s2;
}

inline Doub norm2_dif(SvbaseComp_I v, SvbaseComp_I v1)
{
	Long N = v.size();
	Doub s2 = abs2(v[0] - v1[0]);
	for (Long i = 1; i < N; ++i)
		s2 += abs2(v[i] - v1[i]);
	return s2;
}

inline Doub norm2_par(SvbaseComp_I v)
{
	Long N = v.size();
	Doub sum = 0;
#pragma omp parallel for reduction(+:sum)
	for (Long i = 0; i < N; ++i)
		sum += abs2(v[i]);
	return sum;
}

inline Doub norm_par(SvbaseComp_I v)
{
	return sqrt(norm2_par(v));
}
inline Doub norm(SvbaseComp_I v)
{
	return sqrt(norm2(v));
}

inline Doub norm_dif(SvbaseComp_I v, SvbaseComp_I v1)
{
	return sqrt(norm2_dif(v, v1));
}

inline Qdoub norm2(SvbaseQcomp_I v)
{
	Long N = v.size();
	Qdoub s2 = abs2(v[0]);
	for (Long i = 1; i < N; ++i)
		s2 += abs2(v[i]);
	return s2;
}

inline Qdoub norm2_dif(SvbaseQcomp_I v, SvbaseQcomp_I v1)
{
	Long N = v.size();
	Qdoub s2 = abs2(v[0] - v1[0]);
	for (Long i = 1; i < N; ++i)
		s2 += abs2(v[i] - v1[i]);
	return s2;
}

inline Qdoub norm2_par(SvbaseQcomp_I v)
{
	Long N = v.size();
	Doub sum = 0;
#pragma omp parallel for reduction(+:sum)
	for (Long i = 0; i < N; ++i)
		sum += abs2(v[i]);
	return sum;
}

inline Qdoub norm_par(SvbaseQcomp_I v)
{
	return sqrt(norm2_par(v));
}
inline Qdoub norm(SvbaseQcomp_I v)
{
	return sqrt(norm2(v));
}

inline Qdoub norm_dif(SvbaseQcomp_I v, SvbaseQcomp_I v1)
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

inline Doub norm2_par(DvecDoub_I v)
{
	Long N = v.size();
	Doub sum = 0;
#pragma omp parallel for reduction(+:sum)
	for (Long i = 0; i < N; ++i)
		sum += abs2(v[i]);
	return sum;
}

inline Doub norm_par(DvecDoub_I v)
{
	return sqrt(norm2_par(v));
}
inline Doub norm(DvecDoub_I v)
{
	return sqrt(norm2(v));
}

inline Doub norm_dif(DvecDoub_I v, DvecDoub_I v1)
{
	return sqrt(norm2_dif(v, v1));
}

inline Qdoub norm2(DvecQdoub_I v)
{
	Long N = v.size();
	Qdoub s2 = abs2(v[0]);
	for (Long i = 1; i < N; ++i)
		s2 += abs2(v[i]);
	return s2;
}

inline Qdoub norm2_dif(DvecQdoub_I v, DvecQdoub_I v1)
{
	Long N = v.size();
	Qdoub s2 = abs2(v[0] - v1[0]);
	for (Long i = 1; i < N; ++i)
		s2 += abs2(v[i] - v1[i]);
	return s2;
}

inline Qdoub norm2_par(DvecQdoub_I v)
{
	Long N = v.size();
	Doub sum = 0;
#pragma omp parallel for reduction(+:sum)
	for (Long i = 0; i < N; ++i)
		sum += abs2(v[i]);
	return sum;
}

inline Qdoub norm_par(DvecQdoub_I v)
{
	return sqrt(norm2_par(v));
}
inline Qdoub norm(DvecQdoub_I v)
{
	return sqrt(norm2(v));
}

inline Qdoub norm_dif(DvecQdoub_I v, DvecQdoub_I v1)
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

inline Doub norm2_par(DvecComp_I v)
{
	Long N = v.size();
	Doub sum = 0;
#pragma omp parallel for reduction(+:sum)
	for (Long i = 0; i < N; ++i)
		sum += abs2(v[i]);
	return sum;
}

inline Doub norm_par(DvecComp_I v)
{
	return sqrt(norm2_par(v));
}
inline Doub norm(DvecComp_I v)
{
	return sqrt(norm2(v));
}

inline Doub norm_dif(DvecComp_I v, DvecComp_I v1)
{
	return sqrt(norm2_dif(v, v1));
}

inline Qdoub norm2(DvecQcomp_I v)
{
	Long N = v.size();
	Qdoub s2 = abs2(v[0]);
	for (Long i = 1; i < N; ++i)
		s2 += abs2(v[i]);
	return s2;
}

inline Qdoub norm2_dif(DvecQcomp_I v, DvecQcomp_I v1)
{
	Long N = v.size();
	Qdoub s2 = abs2(v[0] - v1[0]);
	for (Long i = 1; i < N; ++i)
		s2 += abs2(v[i] - v1[i]);
	return s2;
}

inline Qdoub norm2_par(DvecQcomp_I v)
{
	Long N = v.size();
	Doub sum = 0;
#pragma omp parallel for reduction(+:sum)
	for (Long i = 0; i < N; ++i)
		sum += abs2(v[i]);
	return sum;
}

inline Qdoub norm_par(DvecQcomp_I v)
{
	return sqrt(norm2_par(v));
}
inline Qdoub norm(DvecQcomp_I v)
{
	return sqrt(norm2(v));
}

inline Qdoub norm_dif(DvecQcomp_I v, DvecQcomp_I v1)
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

inline Doub norm2_par(MatDoub_I v)
{
	Long N = v.size();
	Doub sum = 0;
#pragma omp parallel for reduction(+:sum)
	for (Long i = 0; i < N; ++i)
		sum += abs2(v[i]);
	return sum;
}

inline Doub norm_par(MatDoub_I v)
{
	return sqrt(norm2_par(v));
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

inline Doub norm2_par(MatComp_I v)
{
	Long N = v.size();
	Doub sum = 0;
#pragma omp parallel for reduction(+:sum)
	for (Long i = 0; i < N; ++i)
		sum += abs2(v[i]);
	return sum;
}

inline Doub norm_par(MatComp_I v)
{
	return sqrt(norm2_par(v));
}
inline Doub norm(MatComp_I v)
{
	return sqrt(norm2(v));
}

inline Doub norm_dif(MatComp_I v, MatComp_I v1)
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

inline Doub norm2_par(DcmatComp_I a)
{
	Long Nr = a.n0();
	Doub s2 = 0;
#pragma omp parallel for reduction(+:s2)
	for (Long j = 0; j < a.n1(); ++j) {
		const Comp *p = &a(0, j);
		Doub s = 0;
		for (Long i = 0; i < Nr; ++i)
			s += abs2(p[i]);
		s2 += s;
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

inline Qdoub norm2(DcmatQcomp_I a)
{
	const Qcomp *p = a.p();
	Long Nr = a.n0(), lda = a.lda();
	Qdoub s2 = 0;
	for (Long j = 0; j < a.n1(); ++j) {
		for (Long i = 0; i < Nr; ++i)
			s2 += abs2(p[i]);
		p += lda;
	}
	return s2;
}

inline Qdoub norm2_par(DcmatQcomp_I a)
{
	Long Nr = a.n0();
	Qdoub s2 = 0;
#pragma omp parallel for reduction(+:s2)
	for (Long j = 0; j < a.n1(); ++j) {
		const Qcomp *p = &a(0, j);
		Qdoub s = 0;
		for (Long i = 0; i < Nr; ++i)
			s += abs2(p[i]);
		s2 += s;
	}
	return s2;
}

inline Qdoub norm2_dif(DcmatQcomp_I a, DcmatQcomp_I a1)
{
	const Qcomp *p = a.p(), *p1 = a1.p();
	Long Nr = a.n0(), lda = a.lda(), lda1 = a1.lda();
	Qdoub s2 = 0;
	for (Long j = 0; j < a.n1(); ++j) {
		for (Long i = 0; i < Nr; ++i)
			s2 += abs2(p[i] - p1[i]);
		p += lda; p1 += lda1;
	}
	return s2;
}
inline Qdoub norm(DcmatQcomp_I v)
{
	return sqrt(norm2(v));
}

inline Qdoub norm_dif(DcmatQcomp_I v, DcmatQcomp_I v1)
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

inline Doub norm2_par(Mat3Doub_I v)
{
	Long N = v.size();
	Doub sum = 0;
#pragma omp parallel for reduction(+:sum)
	for (Long i = 0; i < N; ++i)
		sum += abs2(v[i]);
	return sum;
}

inline Doub norm_par(Mat3Doub_I v)
{
	return sqrt(norm2_par(v));
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

inline Doub norm2_par(Mat3Comp_I v)
{
	Long N = v.size();
	Doub sum = 0;
#pragma omp parallel for reduction(+:sum)
	for (Long i = 0; i < N; ++i)
		sum += abs2(v[i]);
	return sum;
}

inline Doub norm_par(Mat3Comp_I v)
{
	return sqrt(norm2_par(v));
}
inline Doub norm(Mat3Comp_I v)
{
	return sqrt(norm2(v));
}

inline Doub norm_dif(Mat3Comp_I v, Mat3Comp_I v1)
{
	return sqrt(norm2_dif(v, v1));
}


} // namespace slisc
