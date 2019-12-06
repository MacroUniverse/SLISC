// copy data from one container to another
// includes container shape checking
// all `container = container` should be implemented using copy
#pragma once
#include "compare.h"

namespace slisc {
//  === pointer interface ===

inline void vecset(Char *v, Char_I val, Long_I n)
{
    for (Char *p = v; p < v + n; ++p)
        *p = val;
}

inline void vecset(Char *v, Char_I val, Long_I n, Long_I step)
{
    for (Char *p = v; p < v + n*step; p += step)
        *p = val;
}

inline void vecset(Int *v, Int_I val, Long_I n)
{
    for (Int *p = v; p < v + n; ++p)
        *p = val;
}

inline void vecset(Int *v, Int_I val, Long_I n, Long_I step)
{
    for (Int *p = v; p < v + n*step; p += step)
        *p = val;
}

inline void vecset(Llong *v, Llong_I val, Long_I n)
{
    for (Llong *p = v; p < v + n; ++p)
        *p = val;
}

inline void vecset(Llong *v, Llong_I val, Long_I n, Long_I step)
{
    for (Llong *p = v; p < v + n*step; p += step)
        *p = val;
}

inline void vecset(Float *v, Float_I val, Long_I n)
{
    for (Float *p = v; p < v + n; ++p)
        *p = val;
}

inline void vecset(Float *v, Float_I val, Long_I n, Long_I step)
{
    for (Float *p = v; p < v + n*step; p += step)
        *p = val;
}

inline void vecset(Doub *v, Doub_I val, Long_I n)
{
    for (Doub *p = v; p < v + n; ++p)
        *p = val;
}

inline void vecset(Doub *v, Doub_I val, Long_I n, Long_I step)
{
    for (Doub *p = v; p < v + n*step; p += step)
        *p = val;
}

inline void vecset(Comp *v, Comp_I val, Long_I n)
{
    for (Comp *p = v; p < v + n; ++p)
        *p = val;
}

inline void vecset(Comp *v, Comp_I val, Long_I n, Long_I step)
{
    for (Comp *p = v; p < v + n*step; p += step)
        *p = val;
}


inline void veccpy(Char *v, const Char *v1, Long_I n)
{
    for (Long i = 0; i < n; ++i)
        v[i] = v1[i];
}

inline void veccpy(Char *v, const Char *v1, Long_I step1, Long_I n)
{
    for (Char *p = v; p < v + n; ++p) {
        *p = *v1;
        v1 += step1;
    }
}

inline void veccpy(Char *v, Long_I step, const Char *v1, Long_I n)
{
    for (Char *p = v; p < v + n*step; p += step) {
        *p = *v1;
        ++v1;
    }
}

inline void veccpy(Char *v, Long_I step, const Char *v1, Long_I step1, Long_I n)
{
    Char *end = v + n * step;
    for (; v < end; v += step) {
        *v = *v1;
        v1 += step1;
    }
}

inline void veccpy(Int *v, const Int *v1, Long_I n)
{
    for (Long i = 0; i < n; ++i)
        v[i] = v1[i];
}

inline void veccpy(Int *v, const Int *v1, Long_I step1, Long_I n)
{
    for (Int *p = v; p < v + n; ++p) {
        *p = *v1;
        v1 += step1;
    }
}

inline void veccpy(Int *v, Long_I step, const Int *v1, Long_I n)
{
    for (Int *p = v; p < v + n*step; p += step) {
        *p = *v1;
        ++v1;
    }
}

inline void veccpy(Int *v, Long_I step, const Int *v1, Long_I step1, Long_I n)
{
    Int *end = v + n * step;
    for (; v < end; v += step) {
        *v = *v1;
        v1 += step1;
    }
}

inline void veccpy(Llong *v, const Llong *v1, Long_I n)
{
    for (Long i = 0; i < n; ++i)
        v[i] = v1[i];
}

inline void veccpy(Llong *v, const Llong *v1, Long_I step1, Long_I n)
{
    for (Llong *p = v; p < v + n; ++p) {
        *p = *v1;
        v1 += step1;
    }
}

inline void veccpy(Llong *v, Long_I step, const Llong *v1, Long_I n)
{
    for (Llong *p = v; p < v + n*step; p += step) {
        *p = *v1;
        ++v1;
    }
}

inline void veccpy(Llong *v, Long_I step, const Llong *v1, Long_I step1, Long_I n)
{
    Llong *end = v + n * step;
    for (; v < end; v += step) {
        *v = *v1;
        v1 += step1;
    }
}

inline void veccpy(Doub *v, const Llong *v1, Long_I n)
{
    for (Long i = 0; i < n; ++i)
        v[i] = v1[i];
}

inline void veccpy(Doub *v, const Llong *v1, Long_I step1, Long_I n)
{
    for (Doub *p = v; p < v + n; ++p) {
        *p = *v1;
        v1 += step1;
    }
}

inline void veccpy(Doub *v, Long_I step, const Llong *v1, Long_I n)
{
    for (Doub *p = v; p < v + n*step; p += step) {
        *p = *v1;
        ++v1;
    }
}

inline void veccpy(Doub *v, Long_I step, const Llong *v1, Long_I step1, Long_I n)
{
    Doub *end = v + n * step;
    for (; v < end; v += step) {
        *v = *v1;
        v1 += step1;
    }
}

inline void veccpy(Float *v, const Float *v1, Long_I n)
{
    for (Long i = 0; i < n; ++i)
        v[i] = v1[i];
}

inline void veccpy(Float *v, const Float *v1, Long_I step1, Long_I n)
{
    for (Float *p = v; p < v + n; ++p) {
        *p = *v1;
        v1 += step1;
    }
}

inline void veccpy(Float *v, Long_I step, const Float *v1, Long_I n)
{
    for (Float *p = v; p < v + n*step; p += step) {
        *p = *v1;
        ++v1;
    }
}

inline void veccpy(Float *v, Long_I step, const Float *v1, Long_I step1, Long_I n)
{
    Float *end = v + n * step;
    for (; v < end; v += step) {
        *v = *v1;
        v1 += step1;
    }
}

inline void veccpy(Doub *v, const Float *v1, Long_I n)
{
    for (Long i = 0; i < n; ++i)
        v[i] = v1[i];
}

inline void veccpy(Doub *v, const Float *v1, Long_I step1, Long_I n)
{
    for (Doub *p = v; p < v + n; ++p) {
        *p = *v1;
        v1 += step1;
    }
}

inline void veccpy(Doub *v, Long_I step, const Float *v1, Long_I n)
{
    for (Doub *p = v; p < v + n*step; p += step) {
        *p = *v1;
        ++v1;
    }
}

inline void veccpy(Doub *v, Long_I step, const Float *v1, Long_I step1, Long_I n)
{
    Doub *end = v + n * step;
    for (; v < end; v += step) {
        *v = *v1;
        v1 += step1;
    }
}

inline void veccpy(Doub *v, const Doub *v1, Long_I n)
{
    for (Long i = 0; i < n; ++i)
        v[i] = v1[i];
}

inline void veccpy(Doub *v, const Doub *v1, Long_I step1, Long_I n)
{
    for (Doub *p = v; p < v + n; ++p) {
        *p = *v1;
        v1 += step1;
    }
}

inline void veccpy(Doub *v, Long_I step, const Doub *v1, Long_I n)
{
    for (Doub *p = v; p < v + n*step; p += step) {
        *p = *v1;
        ++v1;
    }
}

inline void veccpy(Doub *v, Long_I step, const Doub *v1, Long_I step1, Long_I n)
{
    Doub *end = v + n * step;
    for (; v < end; v += step) {
        *v = *v1;
        v1 += step1;
    }
}

inline void veccpy(Comp *v, const Doub *v1, Long_I n)
{
    for (Long i = 0; i < n; ++i)
        v[i] = v1[i];
}

inline void veccpy(Comp *v, const Doub *v1, Long_I step1, Long_I n)
{
    for (Comp *p = v; p < v + n; ++p) {
        *p = *v1;
        v1 += step1;
    }
}

inline void veccpy(Comp *v, Long_I step, const Doub *v1, Long_I n)
{
    for (Comp *p = v; p < v + n*step; p += step) {
        *p = *v1;
        ++v1;
    }
}

inline void veccpy(Comp *v, Long_I step, const Doub *v1, Long_I step1, Long_I n)
{
    Comp *end = v + n * step;
    for (; v < end; v += step) {
        *v = *v1;
        v1 += step1;
    }
}

inline void veccpy(Comp *v, const Llong *v1, Long_I n)
{
    for (Long i = 0; i < n; ++i)
        v[i] = v1[i];
}

inline void veccpy(Comp *v, const Llong *v1, Long_I step1, Long_I n)
{
    for (Comp *p = v; p < v + n; ++p) {
        *p = *v1;
        v1 += step1;
    }
}

inline void veccpy(Comp *v, Long_I step, const Llong *v1, Long_I n)
{
    for (Comp *p = v; p < v + n*step; p += step) {
        *p = *v1;
        ++v1;
    }
}

inline void veccpy(Comp *v, Long_I step, const Llong *v1, Long_I step1, Long_I n)
{
    Comp *end = v + n * step;
    for (; v < end; v += step) {
        *v = *v1;
        v1 += step1;
    }
}

inline void veccpy(Comp *v, const Comp *v1, Long_I n)
{
    for (Long i = 0; i < n; ++i)
        v[i] = v1[i];
}

inline void veccpy(Comp *v, const Comp *v1, Long_I step1, Long_I n)
{
    for (Comp *p = v; p < v + n; ++p) {
        *p = *v1;
        v1 += step1;
    }
}

inline void veccpy(Comp *v, Long_I step, const Comp *v1, Long_I n)
{
    for (Comp *p = v; p < v + n*step; p += step) {
        *p = *v1;
        ++v1;
    }
}

inline void veccpy(Comp *v, Long_I step, const Comp *v1, Long_I step1, Long_I n)
{
    Comp *end = v + n * step;
    for (; v < end; v += step) {
        *v = *v1;
        v1 += step1;
    }
}


inline void matcpy(Int *v, Long_I lda, const Int *v1, Long_I lda1, Long_I Nr, Long_I Nc)
{
    for (Long j = 0; j < Nr; ++j) {
        veccpy(v, v1, Nc);
        v += lda; v1 += lda1;
    }
}

inline void matcpy(Llong *v, Long_I lda, const Llong *v1, Long_I lda1, Long_I Nr, Long_I Nc)
{
    for (Long j = 0; j < Nr; ++j) {
        veccpy(v, v1, Nc);
        v += lda; v1 += lda1;
    }
}

inline void matcpy(Doub *v, Long_I lda, const Doub *v1, Long_I lda1, Long_I Nr, Long_I Nc)
{
    for (Long j = 0; j < Nr; ++j) {
        veccpy(v, v1, Nc);
        v += lda; v1 += lda1;
    }
}

inline void matcpy(Comp *v, Long_I lda, const Comp *v1, Long_I lda1, Long_I Nr, Long_I Nc)
{
    for (Long j = 0; j < Nr; ++j) {
        veccpy(v, v1, Nc);
        v += lda; v1 += lda1;
    }
}


inline void matcpy_diff_major(Llong *a2, const Llong *a1, Long_I N2, Long_I N1)
{
    for (Long i2 = 0; i2 < N2; ++i2) {
        Long start = N1 * i2, k2 = i2;
        for (Long k1 = start; k1 < start + N1; ++k1) {
            a2[k2] = a1[k1];
            k2 += N2;
        }
    }
}

inline void matcpy_diff_major(Llong *a2, const Llong *a1, Long_I N2, Long_I lda2, Long_I N1, Long_I lda1)
{
    for (Long i2 = 0; i2 < N2; ++i2) {
        Long start = lda1 * i2, k2 = i2;
        for (Long k1 = start; k1 < start + N1; ++k1) {
            a2[k2] = a1[k1];
            k2 += lda2;
        }
    }
}

inline void matcpy_diff_major(Doub *a2, const Doub *a1, Long_I N2, Long_I N1)
{
    for (Long i2 = 0; i2 < N2; ++i2) {
        Long start = N1 * i2, k2 = i2;
        for (Long k1 = start; k1 < start + N1; ++k1) {
            a2[k2] = a1[k1];
            k2 += N2;
        }
    }
}

inline void matcpy_diff_major(Doub *a2, const Doub *a1, Long_I N2, Long_I lda2, Long_I N1, Long_I lda1)
{
    for (Long i2 = 0; i2 < N2; ++i2) {
        Long start = lda1 * i2, k2 = i2;
        for (Long k1 = start; k1 < start + N1; ++k1) {
            a2[k2] = a1[k1];
            k2 += lda2;
        }
    }
}

inline void matcpy_diff_major(Comp *a2, const Comp *a1, Long_I N2, Long_I N1)
{
    for (Long i2 = 0; i2 < N2; ++i2) {
        Long start = N1 * i2, k2 = i2;
        for (Long k1 = start; k1 < start + N1; ++k1) {
            a2[k2] = a1[k1];
            k2 += N2;
        }
    }
}

inline void matcpy_diff_major(Comp *a2, const Comp *a1, Long_I N2, Long_I lda2, Long_I N1, Long_I lda1)
{
    for (Long i2 = 0; i2 < N2; ++i2) {
        Long start = lda1 * i2, k2 = i2;
        for (Long k1 = start; k1 < start + N1; ++k1) {
            a2[k2] = a1[k1];
            k2 += lda2;
        }
    }
}


// copy dense matrix with different majors
// lda1 is leading dimension of a1, lda2 is leading dimension of a2
// if a1 is row major and a2 is column major, N1 is number of columns, N2 is number of rows
// if a1 is column major and a2 is row major, N1 is number of rows, N2 is number of columns
// #include "matcpy_diff_major.inl"

// === container interface ===
// must use pointer version


// scalar to container
inline void copy(VecInt_O v, Int_I s)
{
    vecset(v.ptr(), s, v.size());
}

inline void copy(VecLlong_O v, Llong_I s)
{
    vecset(v.ptr(), s, v.size());
}

inline void copy(VecDoub_O v, Doub_I s)
{
    vecset(v.ptr(), s, v.size());
}

inline void copy(VecComp_O v, Comp_I s)
{
    vecset(v.ptr(), s, v.size());
}

inline void copy(SvecLlong_O v, Llong_I s)
{
    vecset(v.ptr(), s, v.size());
}

inline void copy(SvecDoub_O v, Doub_I s)
{
    vecset(v.ptr(), s, v.size());
}

inline void copy(SvecComp_O v, Comp_I s)
{
    vecset(v.ptr(), s, v.size());
}

inline void copy(MatInt_O v, Int_I s)
{
    vecset(v.ptr(), s, v.size());
}

inline void copy(MatDoub_O v, Doub_I s)
{
    vecset(v.ptr(), s, v.size());
}

inline void copy(CmatInt_O v, Int_I s)
{
    vecset(v.ptr(), s, v.size());
}

inline void copy(CmatLlong_O v, Llong_I s)
{
    vecset(v.ptr(), s, v.size());
}

inline void copy(CmatDoub_O v, Doub_I s)
{
    vecset(v.ptr(), s, v.size());
}

inline void copy(CmatComp_O v, Comp_I s)
{
    vecset(v.ptr(), s, v.size());
}


// container to container
inline void copy(VecChar_O v, VecChar_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v1.ptr(), v.size());
}

inline void copy(VecInt_O v, VecInt_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v1.ptr(), v.size());
}

inline void copy(VecInt_O v, SvecInt_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v1.ptr(), v.size());
}

inline void copy(VecInt_O v, DvecInt_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v1.ptr(), v1.step(), v1.size());
}

inline void copy(VecLlong_O v, VecLlong_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v1.ptr(), v.size());
}

inline void copy(VecDoub_O v, VecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v1.ptr(), v.size());
}

inline void copy(VecComp_O v, VecComp_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v1.ptr(), v.size());
}

inline void copy(MatLlong_O v, MatLlong_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v1.ptr(), v.size());
}

inline void copy(MatDoub_O v, MatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v1.ptr(), v.size());
}

inline void copy(MatComp_O v, MatComp_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v1.ptr(), v.size());
}

inline void copy(CmatLlong_O v, CmatLlong_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v1.ptr(), v.size());
}

inline void copy(CmatDoub_O v, CmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v1.ptr(), v.size());
}

inline void copy(CmatComp_O v, CmatComp_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v1.ptr(), v.size());
}

inline void copy(MatDoub_O v, CmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    matcpy_diff_major(v.ptr(), v1.ptr(), v.n2(), v.n1());
}

inline void copy(CmatDoub_O v, MatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    matcpy_diff_major(v.ptr(), v1.ptr(), v.n1(), v.n2());
}

inline void copy(DvecInt_O v, DvecInt_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v.step(), v1.ptr(), v1.step(), v.size());
}

inline void copy(DvecDoub_O v, DvecDoub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    veccpy(v.ptr(), v.step(), v1.ptr(), v1.step(), v.size());
}

inline void copy(DcmatInt_O v, CmatInt_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    matcpy(v.ptr(), v.lda(), v1.ptr(), v.n1(), v.n1(), v.n2());
}

inline void copy(DcmatDoub_O v, CmatDoub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    if (v.size() == 0)
        return;
    matcpy(v.ptr(), v.lda(), v1.ptr(), v.n1(), v.n1(), v.n2());
}


// for sparse containers
inline void copy(McooDoub_O v, McooDoub_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
    if (v.capacity() < v1.nnz())
        SLS_ERR("not enough capacity!");
#endif
    if (v1.nnz() == 0)
        return;
    if (v.ptr() == v1.ptr())
        SLS_ERR("self assignment is forbidden!");
    Long Nnz = v1.nnz();
    v.resize(Nnz);
    veccpy(v.ptr(), v1.ptr(), Nnz);
    veccpy(v.row_ptr(), v1.row_ptr(), Nnz);
    veccpy(v.col_ptr(), v1.col_ptr(), Nnz);
}

inline void copy(McooComp_O v, McooComp_I v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
    if (v.capacity() < v1.nnz())
        SLS_ERR("not enough capacity!");
#endif
    if (v1.nnz() == 0)
        return;
    if (v.ptr() == v1.ptr())
        SLS_ERR("self assignment is forbidden!");
    Long Nnz = v1.nnz();
    v.resize(Nnz);
    veccpy(v.ptr(), v1.ptr(), Nnz);
    veccpy(v.row_ptr(), v1.row_ptr(), Nnz);
    veccpy(v.col_ptr(), v1.col_ptr(), Nnz);
}


inline void copy(CmatDoub_O lhs, McooDoub_I rhs)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(lhs, rhs))
        SLS_ERR("wrong shape!");
#endif
    copy(lhs, 0);
    for (Long i = 0; i < rhs.nnz(); ++i) {
        lhs(rhs.row(i), rhs.col(i)) = rhs[i];
    }
}

// inline void cooh2dense(CmatDoub_O lhs, McoohDoub_I rhs)
// {
// #ifdef SLS_CHECK_SHAPE
//     if (!shape_cmp(lhs, rhs))
//         SLS_ERR("wrong shape!");
// #endif
//     copy(lhs, 0);
//     for (Long i = 0; i < rhs.nnz(); ++i) {
//         Long r = rhs.row(i), c = rhs.col(i);
//         if (r == c)
//             lhs(r, r) = rhs(i);
//         else {
//             lhs(r, c) = rhs(i);
//             lhs(c, r) = CONJ(rhs(i));
//         }
//     }
// }

inline void copy(CmatComp_O lhs, McooComp_I rhs)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(lhs, rhs))
        SLS_ERR("wrong shape!");
#endif
    copy(lhs, 0);
    for (Long i = 0; i < rhs.nnz(); ++i) {
        lhs(rhs.row(i), rhs.col(i)) = rhs[i];
    }
}

// inline void cooh2dense(CmatComp_O lhs, McoohComp_I rhs)
// {
// #ifdef SLS_CHECK_SHAPE
//     if (!shape_cmp(lhs, rhs))
//         SLS_ERR("wrong shape!");
// #endif
//     copy(lhs, 0);
//     for (Long i = 0; i < rhs.nnz(); ++i) {
//         Long r = rhs.row(i), c = rhs.col(i);
//         if (r == c)
//             lhs(r, r) = rhs(i);
//         else {
//             lhs(r, c) = rhs(i);
//             lhs(c, r) = CONJ(rhs(i));
//         }
//     }
// }


// from MatCoo and MatCooH to dense matrix
// #include "matrix_coo2dense.inl"

// template <class T, class T1, SLS_IF(is_promo<T, T1>())>
// void copy(MatCoo<T> &v, const CmatObd<T1> &v1)
// {
// #ifdef SLS_CHECK_SHAPE
//     if (!shape_cmp(v, v1))
//         SLS_ERR("wrong shape!");
//     if (v.capacity() < v1.nnz())
//         SLS_ERR("not enough capacity!");
// #endif
//     if (v1.nnz() == 0)
//         return;
//     Long N0 = v1.n0(), N1 = N0 - 1;
//     Long N = v1.n1();
//     Long k = 0;
//     for (Long blk = 0; blk < v1.nblk(); ++blk) {
//         for (Long j = 0; j < N0; ++j) {
//             for (Long i = 0; i < N0; ++i) {
//                 Long shift = blk * N1 - 1;
//                 Long ii = shift + i, jj = shift + j;
//                 if (!((i == N1 && j == N1) || ii < 0 || jj < 0 || ii == N || jj == N))
//                     v.push(v1(k), ii, jj);
//                 ++k;
//             }
//         }
//     }
// }

} // namespace slisc
