#pragma once
#include "../arith/arith1.h"
#include "../arith/arith4.h"
#include "../arith/copy.h"
#include "../algo/sort.h"
#include "../sparse/Diag.h"
#include "../sparse/Mcoo.h"
#include "../sparse/Cmobd.h"

namespace slisc {

inline bool operator==(CmobdComp_I a, CmobdComp_I b)
{
	return a.n0() == b.n0() && a.n1() == b.n1() && a.cmat3() == b.cmat3();
}

inline bool operator!=(CmobdComp_I a, CmobdComp_I b) { return !(a == b); }


inline bool operator==(CmobdComp_I a, CmobdDoub_I b)
{
	return a.n0() == b.n0() && a.n1() == b.n1() && a.cmat3() == b.cmat3();
}

inline bool operator!=(CmobdComp_I a, CmobdDoub_I b) { return !(a == b); }


inline bool operator==(CmobdDoub_I a, CmobdDoub_I b)
{
	return a.n0() == b.n0() && a.n1() == b.n1() && a.cmat3() == b.cmat3();
}

inline bool operator!=(CmobdDoub_I a, CmobdDoub_I b) { return !(a == b); }



inline void mul_cmat_cmat_diag(Comp *c, const Doub *a, Long_I Nr, Long_I Nc, const Comp *b)
{
	for (Long i = 0; i < Nc; ++i) {
		times_vvs(c, a, b[i], Nr);
		c += Nr; a += Nr;
	}
}

inline void mul_cmat_diag_cmat(Comp *c, const Doub *a, const Comp *b, Long_I Nr, Long_I Nc)
{
	for (Long i = 0; i < Nc; ++i) {
		times_vvv(c, b, a, Nr);
		c += Nr; b += Nr;
	}
}


inline void mul_cmat_cmat_diag(Doub *c, const Doub *a, Long_I Nr, Long_I Nc, const Doub *b)
{
	for (Long i = 0; i < Nc; ++i) {
		times_vvs(c, a, b[i], Nr);
		c += Nr; a += Nr;
	}
}

inline void mul_cmat_diag_cmat(Doub *c, const Doub *a, const Doub *b, Long_I Nr, Long_I Nc)
{
	for (Long i = 0; i < Nc; ++i) {
		times_vvv(c, b, a, Nr);
		c += Nr; b += Nr;
	}
}

inline void mul_cmat_cmat_diag(Comp *c, const Comp *a, Long_I Nr, Long_I Nc, const Doub *b)
{
	for (Long i = 0; i < Nc; ++i) {
		times_vvs(c, a, b[i], Nr);
		c += Nr; a += Nr;
	}
}

inline void mul_cmat_diag_cmat(Comp *c, const Comp *a, const Doub *b, Long_I Nr, Long_I Nc)
{
	for (Long i = 0; i < Nc; ++i) {
		times_vvv(c, b, a, Nr);
		c += Nr; b += Nr;
	}
}


template <class Ty, class Ta, class Tx>
inline void mul_v_coo_v(Ty *y, const Ta *a_ij, const Long *i, const Long *j, Long_I N1, Long_I Nnz, const Tx *x)
{
	vecset(y, 0, N1);
	for (Long k = 0; k < Nnz; ++k)
		y[i[k]] += a_ij[k] * x[j[k]];
}

template <class Ty, class Ta, class Tx>
inline void mul_v_coo_v(Ty *y, const Ta *a_ij, const Long *i, const Long *j, Long_I N1, Long_I Nnz, const Tx *x, Long_I x_step)
{
	vecset(y, 0, N1);
	for (Long k = 0; k < Nnz; ++k)
		y[i[k]] += a_ij[k] * x[x_step*j[k]];
}

// assuming only one of the two redundant elements are stored
template <class Ty, class Ta, class Tx>
inline void mul_v_cooh_v(Ty *y, const Ta *a_ij, const Long *i, const Long *j, Long_I N1, Long_I Nnz, const Tx *x)
{
	vecset(y, 0, N1);
	for (Long k = 0; k < Nnz; ++k) {
		Long r = i[k], c = j[k];
		if (r == c)
			y[r] += a_ij[k] * x[c];
		else {
			y[r] += a_ij[k] * x[c];
			y[c] += slisc::conj(a_ij[k]) * x[r];
		}
	}
}

template <class Ty, class Tx, class Ta>
inline void mul_v_cmatobd_v(Ty *y, const Tx *x, const Ta *a, Long_I blk_size, Long_I Nblk, Long_I N)
{
	vecset(y, 0, N);
	Long step = blk_size - 1, step2 = blk_size - 2;
	a += blk_size + 1; // move to first element

	// first block
	for (Long j = 0; j < step; ++j) {
		const Tx &s = x[j];
		for (Long i = 0; i < step; ++i) {
			y[i] += (*a) * s;
			++a;
		}
		++a;
	}
	x += step2; y += step2; --a;

	// middle blocks
	for (Long blk = 1; blk < Nblk - 1; ++blk) {
		for (Long j = 0; j < blk_size; ++j) {
			Tx s = x[j];
			for (Long i = 0; i < blk_size; ++i) {
				y[i] += (*a) * s;
				++a;
			}
		}
		x += step; y += step;
	}
	
	// last block
	for (Long j = 0; j < step; ++j) {
		Tx s = x[j];
		for (Long i = 0; i < step; ++i) {
			y[i] += (*a) * s;
			++a;
		}
		++a;
	}
}

template <class Ty, class Tx, class Ta, class Talpha, class Tbeta>
inline void mul_v_cmatobd_v(Ty *y, const Tx *x, const Ta *a, Long_I blk_size, Long_I Nblk, Long_I N,
	Long_I step_y, Long_I step_x, const Talpha &alpha, const Tbeta &beta)
{
	Long step = blk_size - 1, step2 = blk_size - 2;
	Long xstep = step*step_x, ystep = step*step_y;
	Long xstep2 = step2*step_x, ystep2 = step2*step_y;
	Long xblk_size = blk_size*step_x, yblk_size = blk_size*step_y;
	a += blk_size + 1; // move to first element

	if (beta == 0)
		vecset(y, 0, N, step_y);
	else
		times_eq_vs(y, beta, N, step_y);

	// first block
	for (Long j = 0; j < xstep; j+=step_x) {
		const Tx &s = x[j];
		for (Long i = 0; i < ystep; i+=step_y) {
			y[i] += (*a*alpha) * s;
			++a;
		}
		++a;
	}
	x += xstep2; y += ystep2; --a;

	// middle blocks
	for (Long blk = 1; blk < Nblk - 1; ++blk) {
		for (Long j = 0; j < xblk_size; j+=step_x) {
			Tx s = x[j];
			for (Long i = 0; i < yblk_size; i+=step_y) {
				y[i] += (*a*alpha) * s;
				++a;
			}
		}
		x += xstep; y += ystep;
	}
	
	// last block
	for (Long j = 0; j < xstep; j+=step_x) {
		Tx s = x[j];
		for (Long i = 0; i < ystep; i+=step_y) {
			y[i] += (*a*alpha) * s;
			++a;
		}
		++a;
	}
}

inline void mul(SvecComp_O y, CmobdDoub_I a, SvecComp_I x)
{
#ifdef SLS_CHECK_SHAPES
	if (y.size() != a.n0() || x.size() != a.n1())
		SLS_ERR("wrong shape!");
#endif
	mul_v_cmatobd_v(y.p(), x.p(), a.p(), a.nblk0(), a.nblk(), a.n0());
}


inline void mul(SvecInt_O y, CmobdInt_I a, SvecInt_I x)
{
#ifdef SLS_CHECK_SHAPES
	if (y.size() != a.n0() || x.size() != a.n1())
		SLS_ERR("wrong shape!");
#endif
	mul_v_cmatobd_v(y.p(), x.p(), a.p(), a.nblk0(), a.nblk(), a.n0());
}

inline void mul(SvecDoub_O y, CmobdDoub_I a, SvecDoub_I x)
{
#ifdef SLS_CHECK_SHAPES
	if (y.size() != a.n0() || x.size() != a.n1())
		SLS_ERR("wrong shape!");
#endif
	mul_v_cmatobd_v(y.p(), x.p(), a.p(), a.nblk0(), a.nblk(), a.n0());
}


inline void mul(SvecComp_O y, CmobdImag_I a, SvecComp_I x)
{
#ifdef SLS_CHECK_SHAPES
	if (y.size() != a.n0() || x.size() != a.n1())
		SLS_ERR("wrong shape!");
#endif
	mul_v_cmatobd_v(y.p(), x.p(), a.p(), a.nblk0(), a.nblk(), a.n0());
}


template <class Talpha, class Tbeta>
inline void mul(DvecInt_O y, CmobdInt_I a, DvecInt_I x, const Talpha &alpha, const Tbeta &beta)
{
#ifdef SLS_CHECK_SHAPES
	if (y.size() != a.n0() || x.size() != a.n1())
		SLS_ERR("wrong shape!");
#endif
	mul_v_cmatobd_v(y.p(), x.p(), a.p(), a.nblk0(), a.nblk(), a.n0(), y.step(), x.step(), alpha, beta);
}


inline void mul(SvecComp_O y, McooDoub_I a, SvecComp_I x)
{
#ifdef SLS_CHECK_SHAPES
	if (a.n1() != x.size() || a.n0() != y.size())
		SLS_ERR("illegal shape!");
#endif
	mul_v_coo_v(y.p(), a.p(), a.row_p(), a.col_p(), a.n0(), a.nnz(), x.p());
}


inline void mul(SvecDoub_O y, McooDoub_I a, SvecDoub_I x)
{
#ifdef SLS_CHECK_SHAPES
	if (a.n1() != x.size() || a.n0() != y.size())
		SLS_ERR("illegal shape!");
#endif
	mul_v_coo_v(y.p(), a.p(), a.row_p(), a.col_p(), a.n0(), a.nnz(), x.p());
}


inline void mul(SvecComp_O y, McooDoub_I a, DvecComp_I x)
{
#ifdef SLS_CHECK_SHAPES
	if (a.n1() != x.size() || a.n0() != y.size())
		SLS_ERR("illegal shape!");
#endif
	mul_v_coo_v(y.p(), a.p(), a.row_p(), a.col_p(), a.n0(), a.nnz(), x.p(), x.step());
}


inline void mul(ScmatDoub_O y, ScmatDoub_I a, DiagDoub_I x)
{
#ifdef SLS_CHECK_SHAPES
	if (a.n1() != x.n0())
		SLS_ERR("illegal shape!");
	if (y.n0() != a.n0() || y.n1() != x.n1())
		SLS_ERR("illegal shape!");
#endif
	mul_cmat_cmat_diag(y.p(), a.p(), a.n0(), a.n1(), x.p());
}

inline void mul(ScmatComp_O y, ScmatDoub_I a, DiagComp_I x)
{
#ifdef SLS_CHECK_SHAPES
	if (a.n1() != x.n0())
		SLS_ERR("illegal shape!");
	if (y.n0() != a.n0() || y.n1() != x.n1())
		SLS_ERR("illegal shape!");
#endif
	mul_cmat_cmat_diag(y.p(), a.p(), a.n0(), a.n1(), x.p());
}

inline void mul(CmatComp_O y, CmatDoub_I a, DiagComp_I x)
{
#ifdef SLS_CHECK_SHAPES
	if (a.n1() != x.n0())
		SLS_ERR("illegal shape!");
	if (y.n0() != a.n0() || y.n1() != x.n1())
		SLS_ERR("illegal shape!");
#endif
	mul_cmat_cmat_diag(y.p(), a.p(), a.n0(), a.n1(), x.p());
}


inline void mul(CmatComp_O y, CmatComp_I a, DiagDoub_I x)
{
#ifdef SLS_CHECK_SHAPES
	if (a.n1() != x.n0())
		SLS_ERR("illegal shape!");
	if (y.n0() != a.n0() || y.n1() != x.n1())
		SLS_ERR("illegal shape!");
#endif
	mul_cmat_cmat_diag(y.p(), a.p(), a.n0(), a.n1(), x.p());
}


inline void mul(CmatComp_O y, DiagComp_I a, ScmatDoub_I x)
{
#ifdef SLS_CHECK_SHAPES
	if (a.n1() != x.n0())
		SLS_ERR("illegal shape!");
	if (y.n0() != a.n0() || y.n1() != x.n1())
		SLS_ERR("illegal shape!");
#endif
	mul_cmat_diag_cmat(y.p(), a.p(), x.p(), x.n0(), x.n1());
}



// similar to sort_col, for row major
inline void sort_row(McooChar_IO a)
{
	Long Nnz = a.nnz();
	VecLong inds(Nnz), order(Nnz);
	linspace(order, 0, Nnz - 1);
	for (Long i = 0; i < Nnz; ++i)
		inds[i] = a.n1() * a.row(i) + a.col(i);
	sort(inds, order);
	SvecChar sli(a.p(), Nnz);
	reorder(sli, order);
	SvecLong sli1;
	sli1.set(a.row_p(), Nnz);
	reorder(sli1, order);
	sli1.set(a.col_p());
	reorder(sli1, order);
}

inline void sort_row(McooInt_IO a)
{
	Long Nnz = a.nnz();
	VecLong inds(Nnz), order(Nnz);
	linspace(order, 0, Nnz - 1);
	for (Long i = 0; i < Nnz; ++i)
		inds[i] = a.n1() * a.row(i) + a.col(i);
	sort(inds, order);
	SvecInt sli(a.p(), Nnz);
	reorder(sli, order);
	SvecLong sli1;
	sli1.set(a.row_p(), Nnz);
	reorder(sli1, order);
	sli1.set(a.col_p());
	reorder(sli1, order);
}

inline void sort_row(McooLlong_IO a)
{
	Long Nnz = a.nnz();
	VecLong inds(Nnz), order(Nnz);
	linspace(order, 0, Nnz - 1);
	for (Long i = 0; i < Nnz; ++i)
		inds[i] = a.n1() * a.row(i) + a.col(i);
	sort(inds, order);
	SvecLlong sli(a.p(), Nnz);
	reorder(sli, order);
	SvecLong sli1;
	sli1.set(a.row_p(), Nnz);
	reorder(sli1, order);
	sli1.set(a.col_p());
	reorder(sli1, order);
}

inline void sort_row(McooDoub_IO a)
{
	Long Nnz = a.nnz();
	VecLong inds(Nnz), order(Nnz);
	linspace(order, 0, Nnz - 1);
	for (Long i = 0; i < Nnz; ++i)
		inds[i] = a.n1() * a.row(i) + a.col(i);
	sort(inds, order);
	SvecDoub sli(a.p(), Nnz);
	reorder(sli, order);
	SvecLong sli1;
	sli1.set(a.row_p(), Nnz);
	reorder(sli1, order);
	sli1.set(a.col_p());
	reorder(sli1, order);
}


inline void sort_row(McooComp_IO a)
{
	Long Nnz = a.nnz();
	VecLong inds(Nnz), order(Nnz);
	linspace(order, 0, Nnz - 1);
	for (Long i = 0; i < Nnz; ++i)
		inds[i] = a.n1() * a.row(i) + a.col(i);
	sort(inds, order);
	SvecComp sli(a.p(), Nnz);
	reorder(sli, order);
	SvecLong sli1;
	sli1.set(a.row_p(), Nnz);
	reorder(sli1, order);
	sli1.set(a.col_p());
	reorder(sli1, order);
}



// sort_col_dry() sorts elements to column major and combine repeated elements
// the i-th element should be moved (or +=) to desk[i]-th element
// reorder() does the actual sorting given output from sort_col_dry()
// sort_col() in-place sorting
inline Long sort_col_dry(VecLong_O dest, McooChar_I coo)
{
	Long N = coo.nnz();
#ifdef SLS_CHECK_SHAPES
	if (dest.size() != N)
		SLS_ERR("wrong shape!");
#endif
	VecLong ind(N), order(N);
	linspace(order, 0, N-1);
	for (Long i = 0; i < N; ++i)
		ind[i] = coo.row(i) + coo.n0() * coo.col(i);
	sort(ind, order);
	Long k = 0;
	for (Long i = 0; i < N-1; ++i) {
		dest[order[i]] = k;
		if (ind[i+1] != ind[i])
			++k;
	}
	dest[order[N-1]] = k;
	return k + 1;
}

inline void reorder(McooChar_O new_coo, McooChar_I coo, VecLong_I dest, Long_I new_Nnz)
{
	assert(&new_coo != &coo);
	new_coo.resize(new_Nnz);
	vecset(new_coo.p(), 0, new_Nnz);
	for (Long i = 0; i < coo.nnz(); ++i) {
		Long j = dest[i];
		new_coo[j] += coo[i];
		new_coo.row(j) = coo.row(i);
		new_coo.col(j) = coo.col(i);
	}
}

inline void sort_col(McooChar_IO coo)
{
	VecLong dest(coo.nnz());
	Long new_Nnz = sort_col_dry(dest, coo);
	McooChar new_coo(coo.n0(), coo.n1(), new_Nnz);
	reorder(new_coo, coo, dest, new_Nnz);
	coo = move(new_coo);
}

inline void rm_zero(McooChar_IO coo, Char_I thresh = 0)
{
	Long k = 0;
	for (Long i = 0; i < coo.nnz(); ++i) {
		if (abs(coo[i]) <= thresh)
			continue;
		if (k != i) {
			coo[k] = coo[i];
			coo.row(k) = coo.row(i);
			coo.col(k) = coo.col(i);
		}
		++k;
	}
	coo.resize(k);
}

inline Long sort_col_dry(VecLong_O dest, McooInt_I coo)
{
	Long N = coo.nnz();
#ifdef SLS_CHECK_SHAPES
	if (dest.size() != N)
		SLS_ERR("wrong shape!");
#endif
	VecLong ind(N), order(N);
	linspace(order, 0, N-1);
	for (Long i = 0; i < N; ++i)
		ind[i] = coo.row(i) + coo.n0() * coo.col(i);
	sort(ind, order);
	Long k = 0;
	for (Long i = 0; i < N-1; ++i) {
		dest[order[i]] = k;
		if (ind[i+1] != ind[i])
			++k;
	}
	dest[order[N-1]] = k;
	return k + 1;
}

inline void reorder(McooInt_O new_coo, McooInt_I coo, VecLong_I dest, Long_I new_Nnz)
{
	assert(&new_coo != &coo);
	new_coo.resize(new_Nnz);
	vecset(new_coo.p(), 0, new_Nnz);
	for (Long i = 0; i < coo.nnz(); ++i) {
		Long j = dest[i];
		new_coo[j] += coo[i];
		new_coo.row(j) = coo.row(i);
		new_coo.col(j) = coo.col(i);
	}
}

inline void sort_col(McooInt_IO coo)
{
	VecLong dest(coo.nnz());
	Long new_Nnz = sort_col_dry(dest, coo);
	McooInt new_coo(coo.n0(), coo.n1(), new_Nnz);
	reorder(new_coo, coo, dest, new_Nnz);
	coo = move(new_coo);
}

inline void rm_zero(McooInt_IO coo, Int_I thresh = 0)
{
	Long k = 0;
	for (Long i = 0; i < coo.nnz(); ++i) {
		if (abs(coo[i]) <= thresh)
			continue;
		if (k != i) {
			coo[k] = coo[i];
			coo.row(k) = coo.row(i);
			coo.col(k) = coo.col(i);
		}
		++k;
	}
	coo.resize(k);
}

inline Long sort_col_dry(VecLong_O dest, McooLlong_I coo)
{
	Long N = coo.nnz();
#ifdef SLS_CHECK_SHAPES
	if (dest.size() != N)
		SLS_ERR("wrong shape!");
#endif
	VecLong ind(N), order(N);
	linspace(order, 0, N-1);
	for (Long i = 0; i < N; ++i)
		ind[i] = coo.row(i) + coo.n0() * coo.col(i);
	sort(ind, order);
	Long k = 0;
	for (Long i = 0; i < N-1; ++i) {
		dest[order[i]] = k;
		if (ind[i+1] != ind[i])
			++k;
	}
	dest[order[N-1]] = k;
	return k + 1;
}

inline void reorder(McooLlong_O new_coo, McooLlong_I coo, VecLong_I dest, Long_I new_Nnz)
{
	assert(&new_coo != &coo);
	new_coo.resize(new_Nnz);
	vecset(new_coo.p(), 0, new_Nnz);
	for (Long i = 0; i < coo.nnz(); ++i) {
		Long j = dest[i];
		new_coo[j] += coo[i];
		new_coo.row(j) = coo.row(i);
		new_coo.col(j) = coo.col(i);
	}
}

inline void sort_col(McooLlong_IO coo)
{
	VecLong dest(coo.nnz());
	Long new_Nnz = sort_col_dry(dest, coo);
	McooLlong new_coo(coo.n0(), coo.n1(), new_Nnz);
	reorder(new_coo, coo, dest, new_Nnz);
	coo = move(new_coo);
}

inline void rm_zero(McooLlong_IO coo, Llong_I thresh = 0)
{
	Long k = 0;
	for (Long i = 0; i < coo.nnz(); ++i) {
		if (abs(coo[i]) <= thresh)
			continue;
		if (k != i) {
			coo[k] = coo[i];
			coo.row(k) = coo.row(i);
			coo.col(k) = coo.col(i);
		}
		++k;
	}
	coo.resize(k);
}

inline Long sort_col_dry(VecLong_O dest, McooDoub_I coo)
{
	Long N = coo.nnz();
#ifdef SLS_CHECK_SHAPES
	if (dest.size() != N)
		SLS_ERR("wrong shape!");
#endif
	VecLong ind(N), order(N);
	linspace(order, 0, N-1);
	for (Long i = 0; i < N; ++i)
		ind[i] = coo.row(i) + coo.n0() * coo.col(i);
	sort(ind, order);
	Long k = 0;
	for (Long i = 0; i < N-1; ++i) {
		dest[order[i]] = k;
		if (ind[i+1] != ind[i])
			++k;
	}
	dest[order[N-1]] = k;
	return k + 1;
}

inline void reorder(McooDoub_O new_coo, McooDoub_I coo, VecLong_I dest, Long_I new_Nnz)
{
	assert(&new_coo != &coo);
	new_coo.resize(new_Nnz);
	vecset(new_coo.p(), 0, new_Nnz);
	for (Long i = 0; i < coo.nnz(); ++i) {
		Long j = dest[i];
		new_coo[j] += coo[i];
		new_coo.row(j) = coo.row(i);
		new_coo.col(j) = coo.col(i);
	}
}

inline void sort_col(McooDoub_IO coo)
{
	VecLong dest(coo.nnz());
	Long new_Nnz = sort_col_dry(dest, coo);
	McooDoub new_coo(coo.n0(), coo.n1(), new_Nnz);
	reorder(new_coo, coo, dest, new_Nnz);
	coo = move(new_coo);
}

inline void rm_zero(McooDoub_IO coo, Doub_I thresh = 0)
{
	Long k = 0;
	for (Long i = 0; i < coo.nnz(); ++i) {
		if (abs(coo[i]) <= thresh)
			continue;
		if (k != i) {
			coo[k] = coo[i];
			coo.row(k) = coo.row(i);
			coo.col(k) = coo.col(i);
		}
		++k;
	}
	coo.resize(k);
}


inline Long sort_col_dry(VecLong_O dest, McooComp_I coo)
{
	Long N = coo.nnz();
#ifdef SLS_CHECK_SHAPES
	if (dest.size() != N)
		SLS_ERR("wrong shape!");
#endif
	VecLong ind(N), order(N);
	linspace(order, 0, N-1);
	for (Long i = 0; i < N; ++i)
		ind[i] = coo.row(i) + coo.n0() * coo.col(i);
	sort(ind, order);
	Long k = 0;
	for (Long i = 0; i < N-1; ++i) {
		dest[order[i]] = k;
		if (ind[i+1] != ind[i])
			++k;
	}
	dest[order[N-1]] = k;
	return k + 1;
}

inline void reorder(McooComp_O new_coo, McooComp_I coo, VecLong_I dest, Long_I new_Nnz)
{
	assert(&new_coo != &coo);
	new_coo.resize(new_Nnz);
	vecset(new_coo.p(), 0, new_Nnz);
	for (Long i = 0; i < coo.nnz(); ++i) {
		Long j = dest[i];
		new_coo[j] += coo[i];
		new_coo.row(j) = coo.row(i);
		new_coo.col(j) = coo.col(i);
	}
}

inline void sort_col(McooComp_IO coo)
{
	VecLong dest(coo.nnz());
	Long new_Nnz = sort_col_dry(dest, coo);
	McooComp new_coo(coo.n0(), coo.n1(), new_Nnz);
	reorder(new_coo, coo, dest, new_Nnz);
	coo = move(new_coo);
}

inline void rm_zero(McooComp_IO coo, Doub_I thresh = 0)
{
	Long k = 0;
	for (Long i = 0; i < coo.nnz(); ++i) {
		if (abs(coo[i]) <= thresh)
			continue;
		if (k != i) {
			coo[k] = coo[i];
			coo.row(k) = coo.row(i);
			coo.col(k) = coo.col(i);
		}
		++k;
	}
	coo.resize(k);
}



inline void operator+=(McooInt_O coo, McooInt_I coo1)
{
	Long Nnz = coo.nnz();
	coo.resize(Nnz + coo1.nnz());
	for (Long i = 0; i < coo1.nnz(); ++i) {
		Long ii = Nnz+i;
		coo[ii] = coo1[i];
		coo.row(ii) = coo1.row(i);
		coo.col(ii) = coo1.col(i);
	}
}

inline void operator-=(McooInt_O coo, McooInt_I coo1)
{
	Long Nnz = coo.nnz();
	coo.resize(Nnz + coo1.nnz());
	for (Long i = 0; i < coo1.nnz(); ++i) {
		Long ii = Nnz+i;
		coo[ii] = -coo1[i];
		coo.row(ii) = coo1.row(i);
		coo.col(ii) = coo1.col(i);
	}
}

inline void operator+=(McooLlong_O coo, McooLlong_I coo1)
{
	Long Nnz = coo.nnz();
	coo.resize(Nnz + coo1.nnz());
	for (Long i = 0; i < coo1.nnz(); ++i) {
		Long ii = Nnz+i;
		coo[ii] = coo1[i];
		coo.row(ii) = coo1.row(i);
		coo.col(ii) = coo1.col(i);
	}
}

inline void operator-=(McooLlong_O coo, McooLlong_I coo1)
{
	Long Nnz = coo.nnz();
	coo.resize(Nnz + coo1.nnz());
	for (Long i = 0; i < coo1.nnz(); ++i) {
		Long ii = Nnz+i;
		coo[ii] = -coo1[i];
		coo.row(ii) = coo1.row(i);
		coo.col(ii) = coo1.col(i);
	}
}

inline void operator+=(McooDoub_O coo, McooDoub_I coo1)
{
	Long Nnz = coo.nnz();
	coo.resize(Nnz + coo1.nnz());
	for (Long i = 0; i < coo1.nnz(); ++i) {
		Long ii = Nnz+i;
		coo[ii] = coo1[i];
		coo.row(ii) = coo1.row(i);
		coo.col(ii) = coo1.col(i);
	}
}

inline void operator-=(McooDoub_O coo, McooDoub_I coo1)
{
	Long Nnz = coo.nnz();
	coo.resize(Nnz + coo1.nnz());
	for (Long i = 0; i < coo1.nnz(); ++i) {
		Long ii = Nnz+i;
		coo[ii] = -coo1[i];
		coo.row(ii) = coo1.row(i);
		coo.col(ii) = coo1.col(i);
	}
}


inline void operator+=(McooComp_O coo, McooComp_I coo1)
{
	Long Nnz = coo.nnz();
	coo.resize(Nnz + coo1.nnz());
	for (Long i = 0; i < coo1.nnz(); ++i) {
		Long ii = Nnz+i;
		coo[ii] = coo1[i];
		coo.row(ii) = coo1.row(i);
		coo.col(ii) = coo1.col(i);
	}
}

inline void operator-=(McooComp_O coo, McooComp_I coo1)
{
	Long Nnz = coo.nnz();
	coo.resize(Nnz + coo1.nnz());
	for (Long i = 0; i < coo1.nnz(); ++i) {
		Long ii = Nnz+i;
		coo[ii] = -coo1[i];
		coo.row(ii) = coo1.row(i);
		coo.col(ii) = coo1.col(i);
	}
}



inline bool operator==(McooInt_IO coo, McooInt_IO coo1)
{
	sort_col(coo); rm_zero(coo);
	sort_col(coo1); rm_zero(coo1);
	if (coo.nnz() != coo1.nnz())
		return false;
	if (!equals_vv(coo.p(), coo1.p(), coo.nnz()))
		return false;
	if (!equals_vv(coo.row_p(), coo1.row_p(), coo.nnz()))
		return false;
	if (!equals_vv(coo.col_p(), coo1.col_p(), coo.nnz()))
		return false;
	return true;
}

inline bool operator==(McooLlong_IO coo, McooLlong_IO coo1)
{
	sort_col(coo); rm_zero(coo);
	sort_col(coo1); rm_zero(coo1);
	if (coo.nnz() != coo1.nnz())
		return false;
	if (!equals_vv(coo.p(), coo1.p(), coo.nnz()))
		return false;
	if (!equals_vv(coo.row_p(), coo1.row_p(), coo.nnz()))
		return false;
	if (!equals_vv(coo.col_p(), coo1.col_p(), coo.nnz()))
		return false;
	return true;
}

inline bool operator==(McooDoub_IO coo, McooDoub_IO coo1)
{
	sort_col(coo); rm_zero(coo);
	sort_col(coo1); rm_zero(coo1);
	if (coo.nnz() != coo1.nnz())
		return false;
	if (!equals_vv(coo.p(), coo1.p(), coo.nnz()))
		return false;
	if (!equals_vv(coo.row_p(), coo1.row_p(), coo.nnz()))
		return false;
	if (!equals_vv(coo.col_p(), coo1.col_p(), coo.nnz()))
		return false;
	return true;
}


inline bool operator==(McooComp_IO coo, McooComp_IO coo1)
{
	sort_col(coo); rm_zero(coo);
	sort_col(coo1); rm_zero(coo1);
	if (coo.nnz() != coo1.nnz())
		return false;
	if (!equals_vv(coo.p(), coo1.p(), coo.nnz()))
		return false;
	if (!equals_vv(coo.row_p(), coo1.row_p(), coo.nnz()))
		return false;
	if (!equals_vv(coo.col_p(), coo1.col_p(), coo.nnz()))
		return false;
	return true;
}



inline void operator*=(McooDoub_IO v, Doub_I s)
{ times_eq_vs(v.p(), s, v.nnz()); }


inline void operator*=(McooComp_IO v, Doub_I s)
{ times_eq_vs(v.p(), s, v.nnz()); }


inline void operator*=(McooComp_IO v, Imag_I s)
{ times_eq_vs(v.p(), s, v.nnz()); }



inline void operator*=(CmobdDoub_IO v, Doub_I s)
{ v.cmat3() *= s; }


inline void operator*=(CmobdComp_IO v, Doub_I s)
{ v.cmat3() *= s; }


inline void operator*=(CmobdComp_IO v, Comp_I s)
{ v.cmat3() *= s; }



inline void times(CmobdComp_O v1, CmobdDoub_I v2, Imag_I s)
{ times(v1.cmat3(), v2.cmat3(), s); }



inline void times(McooComp_O v, McooDoub_I v1, Imag_I s)
{
	times_vvs(v.p(), v1.p(), s, v1.nnz());
}



// infinity norm (using maximum absolute sum of columns)
inline Doub norm_inf(CmatDoub_I A)
{
	VecDoub abs_sum(A.n1()); copy(abs_sum, 0);
	for (Long j = 0; j < A.n1(); ++j)
		for (Long i = 0; i < A.n0(); ++i)
			abs_sum[j] += abs(A(i, j));
	return max(abs_sum);
}

inline Doub norm_inf(CmatComp_I A)
{
	VecDoub abs_sum(A.n1()); copy(abs_sum, 0);
	for (Long j = 0; j < A.n1(); ++j)
		for (Long i = 0; i < A.n0(); ++i)
			abs_sum[j] += abs(A(i, j));
	return max(abs_sum);
}



// infinity norm (using maximum absolute sum of columns)
inline Int norm_inf(CmobdInt_I A)
{
	Long N0 = A.nblk0(), N1 = N0 - 1, Nblk = A.nblk();
	thread_local static VecInt abs_sum(A.n1());
	copy(abs_sum, 0);
	Long k = 0;
	SvecIntC sli(A.p() + N0 + 1, N1);
	// first block
	for (Long j = 1; j < N0; ++j) {
		abs_sum[k] += sum_abs(sli);
		++k; sli.shift(N0);
	}
	--k;
	// middle blocks
	sli.set(N0); sli.shift(-1);
	for (Long blk = 1; blk < Nblk - 1; ++blk) {
		for (Long j = 0; j < N0; ++j) {
			abs_sum[k] += sum_abs(sli);
			++k; sli.next();
		}
		--k;
	}
	// last block
	sli.set(N1);
	for (Long j = 0; j < N1; ++j) {
		abs_sum[k] += sum_abs(sli);
		++k; sli.shift(N0);
	}
	return max(abs_sum);
}

inline Doub norm_inf(CmobdDoub_I A)
{
	Long N0 = A.nblk0(), N1 = N0 - 1, Nblk = A.nblk();
	thread_local static VecDoub abs_sum(A.n1());
	copy(abs_sum, 0);
	Long k = 0;
	SvecDoubC sli(A.p() + N0 + 1, N1);
	// first block
	for (Long j = 1; j < N0; ++j) {
		abs_sum[k] += sum_abs(sli);
		++k; sli.shift(N0);
	}
	--k;
	// middle blocks
	sli.set(N0); sli.shift(-1);
	for (Long blk = 1; blk < Nblk - 1; ++blk) {
		for (Long j = 0; j < N0; ++j) {
			abs_sum[k] += sum_abs(sli);
			++k; sli.next();
		}
		--k;
	}
	// last block
	sli.set(N1);
	for (Long j = 0; j < N1; ++j) {
		abs_sum[k] += sum_abs(sli);
		++k; sli.shift(N0);
	}
	return max(abs_sum);
}


inline Doub norm_inf(CmobdComp_I A)
{
	Long N0 = A.nblk0(), N1 = N0 - 1, Nblk = A.nblk();
	thread_local static VecDoub abs_sum(A.n1());
	copy(abs_sum, 0);
	Long k = 0;
	SvecCompC sli(A.p() + N0 + 1, N1);
	// first block
	for (Long j = 1; j < N0; ++j) {
		abs_sum[k] += sum_abs(sli);
		++k; sli.shift(N0);
	}
	--k;
	// middle blocks
	sli.set(N0); sli.shift(-1);
	for (Long blk = 1; blk < Nblk - 1; ++blk) {
		for (Long j = 0; j < N0; ++j) {
			abs_sum[k] += sum_abs(sli);
			++k; sli.next();
		}
		--k;
	}
	// last block
	sli.set(N1);
	for (Long j = 0; j < N1; ++j) {
		abs_sum[k] += sum_abs(sli);
		++k; sli.shift(N0);
	}
	return max(abs_sum);
}



// infinity norm (using maximum absolute sum of columns)
inline Doub norm_inf(McooDoub_I A)
{
	VecDoub abs_sum(A.n1()); copy(abs_sum, 0);
	for (Long i = 0; i < A.nnz(); ++i) {
		abs_sum[A.col(i)] += abs(A[i]);
	}
	return max(abs_sum);
}


inline Doub norm_inf(McooComp_I A)
{
	VecDoub abs_sum(A.n1()); copy(abs_sum, 0);
	for (Long i = 0; i < A.nnz(); ++i) {
		abs_sum[A.col(i)] += abs(A[i]);
	}
	return max(abs_sum);
}



} // namespace slisc
