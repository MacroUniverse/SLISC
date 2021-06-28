#pragma once
#include "arithmetic.h"
#include "Diag.h"
#include "Mcoo.h"
#include "Cmobd.h"
#include "sort.h"

namespace slisc {
inline void mul_cmat_cmat_diag(Doub *c, const Doub *a, Long_I Nr, Long_I Nc, const Doub *b)
{
    for (Long i = 0; i < Nc; ++i) {
        times_vvs(c, a, b[i], Nr);
        c += Nr; a += Nr;
    }
}

inline void mul_cmat_cmat_diag(Comp *c, const Comp *a, Long_I Nr, Long_I Nc, const Doub *b)
{
    for (Long i = 0; i < Nc; ++i) {
        times_vvs(c, a, b[i], Nr);
        c += Nr; a += Nr;
    }
}

inline void mul_cmat_cmat_diag(Comp *c, const Doub *a, Long_I Nr, Long_I Nc, const Comp *b)
{
    for (Long i = 0; i < Nc; ++i) {
        times_vvs(c, a, b[i], Nr);
        c += Nr; a += Nr;
    }
}

inline void mul_cmat_cmat_diag(Comp *c, const Comp *a, Long_I Nr, Long_I Nc, const Comp *b)
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

inline void mul_cmat_diag_cmat(Comp *c, const Doub *a, const Comp *b, Long_I Nr, Long_I Nc)
{
    for (Long i = 0; i < Nc; ++i) {
        times_vvv(c, b, a, Nr);
        c += Nr; b += Nr;
    }
}

inline void mul_cmat_diag_cmat(Comp *c, const Comp *a, const Doub *b, Long_I Nr, Long_I Nc)
{
    for (Long i = 0; i < Nc; ++i) {
        times_vvv(c, b, a, Nr);
        c += Nr; b += Nr;
    }
}

inline void mul_cmat_diag_cmat(Comp *c, const Comp *a, const Comp *b, Long_I Nr, Long_I Nc)
{
    for (Long i = 0; i < Nc; ++i) {
        times_vvv(c, b, a, Nr);
        c += Nr; b += Nr;
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


inline void mul(VecInt_O y, CmobdInt_I a, VecInt_I x)
{
#ifdef SLS_CHECK_SHAPES
    if (y.size() != a.n0() || x.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
    mul_v_cmatobd_v(y.p(), x.p(), a.p(), a.nblk0(), a.nblk(), a.n0());
}

inline void mul(VecDoub_O y, CmobdDoub_I a, VecDoub_I x)
{
#ifdef SLS_CHECK_SHAPES
    if (y.size() != a.n0() || x.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
    mul_v_cmatobd_v(y.p(), x.p(), a.p(), a.nblk0(), a.nblk(), a.n0());
}

inline void mul(VecComp_O y, CmobdComp_I a, VecComp_I x)
{
#ifdef SLS_CHECK_SHAPES
    if (y.size() != a.n0() || x.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
    mul_v_cmatobd_v(y.p(), x.p(), a.p(), a.nblk0(), a.nblk(), a.n0());
}

inline void mul(VecComp_O y, CmobdDoub_I a, VecComp_I x)
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

inline void mul(SvecComp_O y, CmobdDoub_I a, SvecComp_I x)
{
#ifdef SLS_CHECK_SHAPES
    if (y.size() != a.n0() || x.size() != a.n1())
        SLS_ERR("wrong shape!");
#endif
    mul_v_cmatobd_v(y.p(), x.p(), a.p(), a.nblk0(), a.nblk(), a.n0());
}


inline void mul(VecDoub_O y, McooDoub_I a, VecDoub_I x)
{
#ifdef SLS_CHECK_SHAPES
    if (a.n1() != x.size() || a.n0() != y.size())
        SLS_ERR("illegal shape!");
#endif
    mul_v_coo_v(y.p(), a.p(), a.row_p(), a.col_p(), a.n0(), a.nnz(), x.p());
}

inline void mul(VecComp_O y, McooComp_I a, VecComp_I x)
{
#ifdef SLS_CHECK_SHAPES
    if (a.n1() != x.size() || a.n0() != y.size())
        SLS_ERR("illegal shape!");
#endif
    mul_v_coo_v(y.p(), a.p(), a.row_p(), a.col_p(), a.n0(), a.nnz(), x.p());
}

inline void mul(SvecComp_O y, McooDoub_I a, SvecComp_I x)
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

inline void mul(CmatComp_O y, CmatComp_I a, DiagComp_I x)
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

inline void mul(CmatDoub_O y, DiagDoub_I a, CmatDoub_I x)
{
#ifdef SLS_CHECK_SHAPES
    if (a.n1() != x.n0())
        SLS_ERR("illegal shape!");
    if (y.n0() != a.n0() || y.n1() != x.n1())
        SLS_ERR("illegal shape!");
#endif
    mul_cmat_diag_cmat(y.p(), a.p(), x.p(), x.n0(), x.n1());
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

inline void mul(CmatComp_O y, DiagComp_I a, CmatComp_I x)
{
#ifdef SLS_CHECK_SHAPES
    if (a.n1() != x.n0())
        SLS_ERR("illegal shape!");
    if (y.n0() != a.n0() || y.n1() != x.n1())
        SLS_ERR("illegal shape!");
#endif
    mul_cmat_diag_cmat(y.p(), a.p(), x.p(), x.n0(), x.n1());
}

inline void mul(CmatComp_O y, DiagDoub_I a, CmatComp_I x)
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


inline void operator*=(McooDoub_IO v, Doub_I s)
{
    times_equals_vs(v.p(), s, v.nnz());
}

inline void operator*=(McooComp_IO v, Doub_I s)
{
    times_equals_vs(v.p(), s, v.nnz());
}

inline void operator*=(McooComp_IO v, Imag_I s)
{
    times_equals_vs(v.p(), s, v.nnz());
}

inline void operator*=(McooComp_IO v, Comp_I s)
{
    times_equals_vs(v.p(), s, v.nnz());
}


inline void operator*=(CmobdDoub_IO v, Doub_I s)
{
    v.cmat3() *= s;
}

inline void operator*=(CmobdComp_IO v, Doub_I s)
{
    v.cmat3() *= s;
}

inline void operator*=(CmobdComp_IO v, Comp_I s)
{
    v.cmat3() *= s;
}


inline void times(CmobdComp_O v, CmobdDoub_I v1, Imag_I s)
{
    times(v.cmat3(), v1.cmat3(), s);
}


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
