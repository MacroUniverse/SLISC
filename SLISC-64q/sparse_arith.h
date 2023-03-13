#pragma once
#include "arithmetic.h"
#include "Diag.h"
#include "Mcoo.h"
#include "Cmobd.h"
#include "copy.h"
#include "sort.h"
#include "disp.h"

namespace slisc {

inline Bool operator==(CmobdComp_I a, CmobdComp_I b)
{
	return a.n0() == b.n0() && a.n1() == b.n1() && a.cmat3() == b.cmat3();
}

inline Bool operator!=(CmobdComp_I a, CmobdComp_I b) { return !(a == b); }

inline Bool operator==(CmobdQcomp_I a, CmobdQcomp_I b)
{
	return a.n0() == b.n0() && a.n1() == b.n1() && a.cmat3() == b.cmat3();
}

inline Bool operator!=(CmobdQcomp_I a, CmobdQcomp_I b) { return !(a == b); }

inline Bool operator==(CmobdComp_I a, CmobdDoub_I b)
{
	return a.n0() == b.n0() && a.n1() == b.n1() && a.cmat3() == b.cmat3();
}

inline Bool operator!=(CmobdComp_I a, CmobdDoub_I b) { return !(a == b); }

inline Bool operator==(CmobdQcomp_I a, CmobdQdoub_I b)
{
	return a.n0() == b.n0() && a.n1() == b.n1() && a.cmat3() == b.cmat3();
}

inline Bool operator!=(CmobdQcomp_I a, CmobdQdoub_I b) { return !(a == b); }

inline Bool operator==(CmobdDoub_I a, CmobdDoub_I b)
{
	return a.n0() == b.n0() && a.n1() == b.n1() && a.cmat3() == b.cmat3();
}

inline Bool operator!=(CmobdDoub_I a, CmobdDoub_I b) { return !(a == b); }

inline Bool operator==(CmobdQdoub_I a, CmobdQdoub_I b)
{
	return a.n0() == b.n0() && a.n1() == b.n1() && a.cmat3() == b.cmat3();
}

inline Bool operator!=(CmobdQdoub_I a, CmobdQdoub_I b) { return !(a == b); }


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

inline void mul_cmat_cmat_diag(Qcomp *c, const Qdoub *a, Long_I Nr, Long_I Nc, const Qcomp *b)
{
	for (Long i = 0; i < Nc; ++i) {
		times_vvs(c, a, b[i], Nr);
		c += Nr; a += Nr;
	}
}

inline void mul_cmat_diag_cmat(Qcomp *c, const Qdoub *a, const Qcomp *b, Long_I Nr, Long_I Nc)
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

inline void mul_cmat_cmat_diag(Qcomp *c, const Qcomp *a, Long_I Nr, Long_I Nc, const Qdoub *b)
{
	for (Long i = 0; i < Nc; ++i) {
		times_vvs(c, a, b[i], Nr);
		c += Nr; a += Nr;
	}
}

inline void mul_cmat_diag_cmat(Qcomp *c, const Qcomp *a, const Qdoub *b, Long_I Nr, Long_I Nc)
{
	for (Long i = 0; i < Nc; ++i) {
		times_vvv(c, b, a, Nr);
		c += Nr; b += Nr;
	}
}


inline void mul_v_coo_v(Comp *y, const Doub *a_ij, const Long *i, const Long *j, Long_I N1, Long_I Nnz, const Comp *x)
{
	vecset(y, 0, N1);
	for (Long k = 0; k < Nnz; ++k)
		y[i[k]] += a_ij[k] * x[j[k]];
}

inline void mul_v_cooh_v(Comp *y, const Doub *a_ij, const Long *i, const Long *j, Long_I N1, Long_I Nnz, const Comp *x)
{
	vecset(y, 0, N1);
	for (Long k = 0; k < Nnz; ++k) {
		Long r = i[k], c = j[k];
		if (r == c)
			y[r] += a_ij[k] * x[c];
		else {
			y[r] += a_ij[k] * x[c];
			y[c] += a_ij[k] * x[r];
		}
	}
}

inline void mul_v_coo_v(Qcomp *y, const Qdoub *a_ij, const Long *i, const Long *j, Long_I N1, Long_I Nnz, const Qcomp *x)
{
	vecset(y, 0, N1);
	for (Long k = 0; k < Nnz; ++k)
		y[i[k]] += a_ij[k] * x[j[k]];
}

inline void mul_v_cooh_v(Qcomp *y, const Qdoub *a_ij, const Long *i, const Long *j, Long_I N1, Long_I Nnz, const Qcomp *x)
{
	vecset(y, 0, N1);
	for (Long k = 0; k < Nnz; ++k) {
		Long r = i[k], c = j[k];
		if (r == c)
			y[r] += a_ij[k] * x[c];
		else {
			y[r] += a_ij[k] * x[c];
			y[c] += a_ij[k] * x[r];
		}
	}
}

inline void mul_v_coo_v(Comp *y, const Comp *a_ij, const Long *i, const Long *j, Long_I N1, Long_I Nnz, const Comp *x)
{
	vecset(y, 0, N1);
	for (Long k = 0; k < Nnz; ++k)
		y[i[k]] += a_ij[k] * x[j[k]];
}

inline void mul_v_cooh_v(Comp *y, const Comp *a_ij, const Long *i, const Long *j, Long_I N1, Long_I Nnz, const Comp *x)
{
	vecset(y, 0, N1);
	for (Long k = 0; k < Nnz; ++k) {
		Long r = i[k], c = j[k];
		if (r == c)
			y[r] += a_ij[k] * x[c];
		else {
			y[r] += a_ij[k] * x[c];
			y[c] += conj(a_ij[k]) * x[r];
		}
	}
}

inline void mul_v_coo_v(Doub *y, const Doub *a_ij, const Long *i, const Long *j, Long_I N1, Long_I Nnz, const Doub *x)
{
	vecset(y, 0, N1);
	for (Long k = 0; k < Nnz; ++k)
		y[i[k]] += a_ij[k] * x[j[k]];
}

inline void mul_v_cooh_v(Doub *y, const Doub *a_ij, const Long *i, const Long *j, Long_I N1, Long_I Nnz, const Doub *x)
{
	vecset(y, 0, N1);
	for (Long k = 0; k < Nnz; ++k) {
		Long r = i[k], c = j[k];
		if (r == c)
			y[r] += a_ij[k] * x[c];
		else {
			y[r] += a_ij[k] * x[c];
			y[c] += a_ij[k] * x[r];
		}
	}
}

inline void mul_v_coo_v(Qdoub *y, const Qdoub *a_ij, const Long *i, const Long *j, Long_I N1, Long_I Nnz, const Qdoub *x)
{
	vecset(y, 0, N1);
	for (Long k = 0; k < Nnz; ++k)
		y[i[k]] += a_ij[k] * x[j[k]];
}

inline void mul_v_cooh_v(Qdoub *y, const Qdoub *a_ij, const Long *i, const Long *j, Long_I N1, Long_I Nnz, const Qdoub *x)
{
	vecset(y, 0, N1);
	for (Long k = 0; k < Nnz; ++k) {
		Long r = i[k], c = j[k];
		if (r == c)
			y[r] += a_ij[k] * x[c];
		else {
			y[r] += a_ij[k] * x[c];
			y[c] += a_ij[k] * x[r];
		}
	}
}


inline void mul_v_cmatobd_v(Comp *y, const Comp *x, const Doub *a, Long_I blk_size, Long_I Nblk, Long_I N)
{
	vecset(y, 0, N);
	Long step = blk_size - 1, step2 = blk_size - 2;
	a += blk_size + 1; // move to first element

	// first block
	for (Long j = 0; j < step; ++j) {
		Comp s = x[j];
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
			Comp s = x[j];
			for (Long i = 0; i < blk_size; ++i) {
				y[i] += (*a) * s;
				++a;
			}
		}
		x += step; y += step;
	}
	
	// last block
	for (Long j = 0; j < step; ++j) {
		Comp s = x[j];
		for (Long i = 0; i < step; ++i) {
			y[i] += (*a) * s;
			++a;
		}
		++a;
	}
}

inline void mul_v_cmatobd_v(Qcomp *y, const Qcomp *x, const Qdoub *a, Long_I blk_size, Long_I Nblk, Long_I N)
{
	vecset(y, 0, N);
	Long step = blk_size - 1, step2 = blk_size - 2;
	a += blk_size + 1; // move to first element

	// first block
	for (Long j = 0; j < step; ++j) {
		Qcomp s = x[j];
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
			Qcomp s = x[j];
			for (Long i = 0; i < blk_size; ++i) {
				y[i] += (*a) * s;
				++a;
			}
		}
		x += step; y += step;
	}
	
	// last block
	for (Long j = 0; j < step; ++j) {
		Qcomp s = x[j];
		for (Long i = 0; i < step; ++i) {
			y[i] += (*a) * s;
			++a;
		}
		++a;
	}
}

inline void mul_v_cmatobd_v(Comp *y, const Doub *x, const Comp *a, Long_I blk_size, Long_I Nblk, Long_I N)
{
	vecset(y, 0, N);
	Long step = blk_size - 1, step2 = blk_size - 2;
	a += blk_size + 1; // move to first element

	// first block
	for (Long j = 0; j < step; ++j) {
		Doub s = x[j];
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
			Doub s = x[j];
			for (Long i = 0; i < blk_size; ++i) {
				y[i] += (*a) * s;
				++a;
			}
		}
		x += step; y += step;
	}
	
	// last block
	for (Long j = 0; j < step; ++j) {
		Doub s = x[j];
		for (Long i = 0; i < step; ++i) {
			y[i] += (*a) * s;
			++a;
		}
		++a;
	}
}

inline void mul_v_cmatobd_v(Comp *y, const Comp *x, const Comp *a, Long_I blk_size, Long_I Nblk, Long_I N)
{
	vecset(y, 0, N);
	Long step = blk_size - 1, step2 = blk_size - 2;
	a += blk_size + 1; // move to first element

	// first block
	for (Long j = 0; j < step; ++j) {
		Comp s = x[j];
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
			Comp s = x[j];
			for (Long i = 0; i < blk_size; ++i) {
				y[i] += (*a) * s;
				++a;
			}
		}
		x += step; y += step;
	}
	
	// last block
	for (Long j = 0; j < step; ++j) {
		Comp s = x[j];
		for (Long i = 0; i < step; ++i) {
			y[i] += (*a) * s;
			++a;
		}
		++a;
	}
}

inline void mul_v_cmatobd_v(Int *y, const Int *x, const Int *a, Long_I blk_size, Long_I Nblk, Long_I N)
{
	vecset(y, 0, N);
	Long step = blk_size - 1, step2 = blk_size - 2;
	a += blk_size + 1; // move to first element

	// first block
	for (Long j = 0; j < step; ++j) {
		Int s = x[j];
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
			Int s = x[j];
			for (Long i = 0; i < blk_size; ++i) {
				y[i] += (*a) * s;
				++a;
			}
		}
		x += step; y += step;
	}
	
	// last block
	for (Long j = 0; j < step; ++j) {
		Int s = x[j];
		for (Long i = 0; i < step; ++i) {
			y[i] += (*a) * s;
			++a;
		}
		++a;
	}
}

inline void mul_v_cmatobd_v(Doub *y, const Doub *x, const Doub *a, Long_I blk_size, Long_I Nblk, Long_I N)
{
	vecset(y, 0, N);
	Long step = blk_size - 1, step2 = blk_size - 2;
	a += blk_size + 1; // move to first element

	// first block
	for (Long j = 0; j < step; ++j) {
		Doub s = x[j];
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
			Doub s = x[j];
			for (Long i = 0; i < blk_size; ++i) {
				y[i] += (*a) * s;
				++a;
			}
		}
		x += step; y += step;
	}
	
	// last block
	for (Long j = 0; j < step; ++j) {
		Doub s = x[j];
		for (Long i = 0; i < step; ++i) {
			y[i] += (*a) * s;
			++a;
		}
		++a;
	}
}

inline void mul_v_cmatobd_v(Qdoub *y, const Qdoub *x, const Qdoub *a, Long_I blk_size, Long_I Nblk, Long_I N)
{
	vecset(y, 0, N);
	Long step = blk_size - 1, step2 = blk_size - 2;
	a += blk_size + 1; // move to first element

	// first block
	for (Long j = 0; j < step; ++j) {
		Qdoub s = x[j];
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
			Qdoub s = x[j];
			for (Long i = 0; i < blk_size; ++i) {
				y[i] += (*a) * s;
				++a;
			}
		}
		x += step; y += step;
	}
	
	// last block
	for (Long j = 0; j < step; ++j) {
		Qdoub s = x[j];
		for (Long i = 0; i < step; ++i) {
			y[i] += (*a) * s;
			++a;
		}
		++a;
	}
}


inline void mul(VecComp_O y, CmobdDoub_I a, VecComp_I x)
{
#ifdef SLS_CHECK_SHAPES
	if (y.size() != a.n0() || x.size() != a.n1())
		SLS_ERR("wrong shape!");
#endif
	mul_v_cmatobd_v(y.p(), x.p(), a.p(), a.nblk0(), a.nblk(), a.n0());
}

inline void mul(VecQcomp_O y, CmobdQdoub_I a, VecQcomp_I x)
{
#ifdef SLS_CHECK_SHAPES
	if (y.size() != a.n0() || x.size() != a.n1())
		SLS_ERR("wrong shape!");
#endif
	mul_v_cmatobd_v(y.p(), x.p(), a.p(), a.nblk0(), a.nblk(), a.n0());
}

inline void mul(VecComp_O y, CmobdDoub_I a, SvecComp_I x)
{
#ifdef SLS_CHECK_SHAPES
	if (y.size() != a.n0() || x.size() != a.n1())
		SLS_ERR("wrong shape!");
#endif
	mul_v_cmatobd_v(y.p(), x.p(), a.p(), a.nblk0(), a.nblk(), a.n0());
}

inline void mul(VecQcomp_O y, CmobdQdoub_I a, SvecQcomp_I x)
{
#ifdef SLS_CHECK_SHAPES
	if (y.size() != a.n0() || x.size() != a.n1())
		SLS_ERR("wrong shape!");
#endif
	mul_v_cmatobd_v(y.p(), x.p(), a.p(), a.nblk0(), a.nblk(), a.n0());
}

inline void mul(VecInt_O y, CmobdInt_I a, VecInt_I x)
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

inline void mul(SvecQdoub_O y, CmobdQdoub_I a, SvecQdoub_I x)
{
#ifdef SLS_CHECK_SHAPES
	if (y.size() != a.n0() || x.size() != a.n1())
		SLS_ERR("wrong shape!");
#endif
	mul_v_cmatobd_v(y.p(), x.p(), a.p(), a.nblk0(), a.nblk(), a.n0());
}

inline void mul(SvecComp_O y, CmobdDoub_I a, SvecComp_I x)
{
#ifdef SLS_CHECK_SHAPES
	if (y.size() != a.n0() || x.size() != a.n1())
		SLS_ERR("wrong shape!");
#endif
	mul_v_cmatobd_v(y.p(), x.p(), a.p(), a.nblk0(), a.nblk(), a.n0());
}

inline void mul(SvecQcomp_O y, CmobdQdoub_I a, SvecQcomp_I x)
{
#ifdef SLS_CHECK_SHAPES
	if (y.size() != a.n0() || x.size() != a.n1())
		SLS_ERR("wrong shape!");
#endif
	mul_v_cmatobd_v(y.p(), x.p(), a.p(), a.nblk0(), a.nblk(), a.n0());
}


inline void mul(SvecComp_O y, McooDoub_I a, SvecComp_I x)
{
#ifdef SLS_CHECK_SHAPES
	if (a.n1() != x.size() || a.n0() != y.size())
		SLS_ERR("illegal shape!");
#endif
	mul_v_coo_v(y.p(), a.p(), a.row_p(), a.col_p(), a.n0(), a.nnz(), x.p());
}

inline void mul(SvecQcomp_O y, McooQdoub_I a, SvecQcomp_I x)
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

inline void mul(SvecQdoub_O y, McooQdoub_I a, SvecQdoub_I x)
{
#ifdef SLS_CHECK_SHAPES
	if (a.n1() != x.size() || a.n0() != y.size())
		SLS_ERR("illegal shape!");
#endif
	mul_v_coo_v(y.p(), a.p(), a.row_p(), a.col_p(), a.n0(), a.nnz(), x.p());
}

inline void mul(VecDoub_O y, McooDoub_I a, VecDoub_I x)
{
#ifdef SLS_CHECK_SHAPES
	if (a.n1() != x.size() || a.n0() != y.size())
		SLS_ERR("illegal shape!");
#endif
	mul_v_coo_v(y.p(), a.p(), a.row_p(), a.col_p(), a.n0(), a.nnz(), x.p());
}

inline void mul(VecQdoub_O y, McooQdoub_I a, VecQdoub_I x)
{
#ifdef SLS_CHECK_SHAPES
	if (a.n1() != x.size() || a.n0() != y.size())
		SLS_ERR("illegal shape!");
#endif
	mul_v_coo_v(y.p(), a.p(), a.row_p(), a.col_p(), a.n0(), a.nnz(), x.p());
}

inline void mul(VecDoub_O y, McooDoub_I a, SvecDoub_I x)
{
#ifdef SLS_CHECK_SHAPES
	if (a.n1() != x.size() || a.n0() != y.size())
		SLS_ERR("illegal shape!");
#endif
	mul_v_coo_v(y.p(), a.p(), a.row_p(), a.col_p(), a.n0(), a.nnz(), x.p());
}

inline void mul(VecQdoub_O y, McooQdoub_I a, SvecQdoub_I x)
{
#ifdef SLS_CHECK_SHAPES
	if (a.n1() != x.size() || a.n0() != y.size())
		SLS_ERR("illegal shape!");
#endif
	mul_v_coo_v(y.p(), a.p(), a.row_p(), a.col_p(), a.n0(), a.nnz(), x.p());
}

inline void mul(VecComp_O y, McooDoub_I a, SvecComp_I x)
{
#ifdef SLS_CHECK_SHAPES
	if (a.n1() != x.size() || a.n0() != y.size())
		SLS_ERR("illegal shape!");
#endif
	mul_v_coo_v(y.p(), a.p(), a.row_p(), a.col_p(), a.n0(), a.nnz(), x.p());
}

inline void mul(VecQcomp_O y, McooQdoub_I a, SvecQcomp_I x)
{
#ifdef SLS_CHECK_SHAPES
	if (a.n1() != x.size() || a.n0() != y.size())
		SLS_ERR("illegal shape!");
#endif
	mul_v_coo_v(y.p(), a.p(), a.row_p(), a.col_p(), a.n0(), a.nnz(), x.p());
}


inline void mul(CmatDoub_O y, CmatDoub_I a, DiagDoub_I x)
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

inline void mul(CmatQcomp_O y, CmatQdoub_I a, DiagQcomp_I x)
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

inline void mul(CmatQcomp_O y, CmatQcomp_I a, DiagQdoub_I x)
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

inline void mul(CmatQcomp_O y, DiagQcomp_I a, ScmatQdoub_I x)
{
#ifdef SLS_CHECK_SHAPES
	if (a.n1() != x.n0())
		SLS_ERR("illegal shape!");
	if (y.n0() != a.n0() || y.n1() != x.n1())
		SLS_ERR("illegal shape!");
#endif
	mul_cmat_diag_cmat(y.p(), a.p(), x.p(), x.n0(), x.n1());
}


inline void sort_r(McooChar_IO a)
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

inline void sort_r(McooInt_IO a)
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

inline void sort_r(McooLlong_IO a)
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

inline void sort_r(McooDoub_IO a)
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

inline void sort_r(McooQdoub_IO a)
{
	Long Nnz = a.nnz();
	VecLong inds(Nnz), order(Nnz);
	linspace(order, 0, Nnz - 1);
	for (Long i = 0; i < Nnz; ++i)
		inds[i] = a.n1() * a.row(i) + a.col(i);
	sort(inds, order);
	SvecQdoub sli(a.p(), Nnz);
	reorder(sli, order);
	SvecLong sli1;
	sli1.set(a.row_p(), Nnz);
	reorder(sli1, order);
	sli1.set(a.col_p());
	reorder(sli1, order);
}

inline void sort_r(McooComp_IO a)
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

inline void sort_r(McooQcomp_IO a)
{
	Long Nnz = a.nnz();
	VecLong inds(Nnz), order(Nnz);
	linspace(order, 0, Nnz - 1);
	for (Long i = 0; i < Nnz; ++i)
		inds[i] = a.n1() * a.row(i) + a.col(i);
	sort(inds, order);
	SvecQcomp sli(a.p(), Nnz);
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
	coo << new_coo;
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
	coo << new_coo;
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
	coo << new_coo;
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
	coo << new_coo;
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

inline Long sort_col_dry(VecLong_O dest, McooQdoub_I coo)
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

inline void reorder(McooQdoub_O new_coo, McooQdoub_I coo, VecLong_I dest, Long_I new_Nnz)
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

inline void sort_col(McooQdoub_IO coo)
{
	VecLong dest(coo.nnz());
	Long new_Nnz = sort_col_dry(dest, coo);
	McooQdoub new_coo(coo.n0(), coo.n1(), new_Nnz);
	reorder(new_coo, coo, dest, new_Nnz);
	coo << new_coo;
}

inline void rm_zero(McooQdoub_IO coo, Qdoub_I thresh = 0)
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
	coo << new_coo;
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

inline Long sort_col_dry(VecLong_O dest, McooQcomp_I coo)
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

inline void reorder(McooQcomp_O new_coo, McooQcomp_I coo, VecLong_I dest, Long_I new_Nnz)
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

inline void sort_col(McooQcomp_IO coo)
{
	VecLong dest(coo.nnz());
	Long new_Nnz = sort_col_dry(dest, coo);
	McooQcomp new_coo(coo.n0(), coo.n1(), new_Nnz);
	reorder(new_coo, coo, dest, new_Nnz);
	coo << new_coo;
}

inline void rm_zero(McooQcomp_IO coo, Qdoub_I thresh = 0)
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

inline void operator+=(McooQdoub_O coo, McooQdoub_I coo1)
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

inline void operator-=(McooQdoub_O coo, McooQdoub_I coo1)
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

inline void operator+=(McooQcomp_O coo, McooQcomp_I coo1)
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

inline void operator-=(McooQcomp_O coo, McooQcomp_I coo1)
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


inline Bool operator==(McooInt_IO coo, McooInt_IO coo1)
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

inline Bool operator==(McooLlong_IO coo, McooLlong_IO coo1)
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

inline Bool operator==(McooDoub_IO coo, McooDoub_IO coo1)
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

inline Bool operator==(McooQdoub_IO coo, McooQdoub_IO coo1)
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

inline Bool operator==(McooComp_IO coo, McooComp_IO coo1)
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

inline Bool operator==(McooQcomp_IO coo, McooQcomp_IO coo1)
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

inline void operator*=(McooQdoub_IO v, Qdoub_I s)
{ times_eq_vs(v.p(), s, v.nnz()); }

inline void operator*=(McooComp_IO v, Doub_I s)
{ times_eq_vs(v.p(), s, v.nnz()); }

inline void operator*=(McooQcomp_IO v, Qdoub_I s)
{ times_eq_vs(v.p(), s, v.nnz()); }

inline void operator*=(McooComp_IO v, Imag_I s)
{ times_eq_vs(v.p(), s, v.nnz()); }

inline void operator*=(McooQcomp_IO v, Qimag_I s)
{ times_eq_vs(v.p(), s, v.nnz()); }


inline void operator*=(CmobdDoub_IO v, Doub_I s)
{ v.cmat3() *= s; }

inline void operator*=(CmobdQdoub_IO v, Qdoub_I s)
{ v.cmat3() *= s; }

inline void operator*=(CmobdComp_IO v, Doub_I s)
{ v.cmat3() *= s; }

inline void operator*=(CmobdQcomp_IO v, Qdoub_I s)
{ v.cmat3() *= s; }

inline void operator*=(CmobdComp_IO v, Comp_I s)
{ v.cmat3() *= s; }

inline void operator*=(CmobdQcomp_IO v, Qcomp_I s)
{ v.cmat3() *= s; }


inline void times(CmobdComp_O v1, CmobdDoub_I v2, Imag_I s)
{ times(v1.cmat3(), v2.cmat3(), s); }

inline void times(CmobdQcomp_O v1, CmobdQdoub_I v2, Qimag_I s)
{ times(v1.cmat3(), v2.cmat3(), s); }


inline void times(McooComp_O v, McooDoub_I v1, Imag_I s)
{
	times_vvs(v.p(), v1.p(), s, v1.nnz());
}

inline void times(McooQcomp_O v, McooQdoub_I v1, Qimag_I s)
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

inline Qdoub norm_inf(CmatQcomp_I A)
{
	VecQdoub abs_sum(A.n1()); copy(abs_sum, 0);
	for (Long j = 0; j < A.n1(); ++j)
		for (Long i = 0; i < A.n0(); ++i)
			abs_sum[j] += abs(A(i, j));
	return max(abs_sum);
}


// infinity norm (using maximum absolute sum of columns)
inline Int norm_inf(CmobdInt_I A)
{
	Long N0 = A.nblk0(), N1 = N0 - 1, Nblk = A.nblk();
	VecInt abs_sum(A.n1()); copy(abs_sum, 0);
	Long k = 0;
	SvecInt_c sli(A.p() + N0 + 1, N1);
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
	VecDoub abs_sum(A.n1()); copy(abs_sum, 0);
	Long k = 0;
	SvecDoub_c sli(A.p() + N0 + 1, N1);
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

inline Qdoub norm_inf(CmobdQdoub_I A)
{
	Long N0 = A.nblk0(), N1 = N0 - 1, Nblk = A.nblk();
	VecQdoub abs_sum(A.n1()); copy(abs_sum, 0);
	Long k = 0;
	SvecQdoub_c sli(A.p() + N0 + 1, N1);
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
	VecDoub abs_sum(A.n1()); copy(abs_sum, 0);
	Long k = 0;
	SvecComp_c sli(A.p() + N0 + 1, N1);
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

inline Qdoub norm_inf(CmobdQcomp_I A)
{
	Long N0 = A.nblk0(), N1 = N0 - 1, Nblk = A.nblk();
	VecQdoub abs_sum(A.n1()); copy(abs_sum, 0);
	Long k = 0;
	SvecQcomp_c sli(A.p() + N0 + 1, N1);
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

inline Qdoub norm_inf(McooQdoub_I A)
{
	VecQdoub abs_sum(A.n1()); copy(abs_sum, 0);
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

inline Qdoub norm_inf(McooQcomp_I A)
{
	VecQdoub abs_sum(A.n1()); copy(abs_sum, 0);
	for (Long i = 0; i < A.nnz(); ++i) {
		abs_sum[A.col(i)] += abs(A[i]);
	}
	return max(abs_sum);
}


} // namespace slisc