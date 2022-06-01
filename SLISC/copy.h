// copy data from one container to another
// includes container shape checking
// all `container = container` should be implemented using copy
#pragma once
#include "compare.h"
#include "cut.h"

namespace slisc {
//  === pointer interface ===

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


inline void matcpy(Comp *v, Long_I lda, const Doub *v1, Long_I lda1, Long_I Nld, Long_I Nsd)
{
    for (Long j = 0; j < Nsd; ++j) {
        veccpy(v, v1, Nld);
        v += lda; v1 += lda1;
    }
}

inline void matcpy(Int *v, Long_I lda, const Int *v1, Long_I lda1, Long_I Nld, Long_I Nsd)
{
    for (Long j = 0; j < Nsd; ++j) {
        veccpy(v, v1, Nld);
        v += lda; v1 += lda1;
    }
}

inline void matcpy(Llong *v, Long_I lda, const Llong *v1, Long_I lda1, Long_I Nld, Long_I Nsd)
{
    for (Long j = 0; j < Nsd; ++j) {
        veccpy(v, v1, Nld);
        v += lda; v1 += lda1;
    }
}

inline void matcpy(Doub *v, Long_I lda, const Doub *v1, Long_I lda1, Long_I Nld, Long_I Nsd)
{
    for (Long j = 0; j < Nsd; ++j) {
        veccpy(v, v1, Nld);
        v += lda; v1 += lda1;
    }
}

inline void matcpy(Comp *v, Long_I lda, const Comp *v1, Long_I lda1, Long_I Nld, Long_I Nsd)
{
    for (Long j = 0; j < Nsd; ++j) {
        veccpy(v, v1, Nld);
        v += lda; v1 += lda1;
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


// copy dense matrix with different majors
// lda1 is leading dimension of a1, lda2 is leading dimension of a2
// if a1 is row major and a2 is column major, N1 is number of columns, N2 is number of rows
// if a1 is column major and a2 is row major, N1 is number of rows, N2 is number of columns
// #include "matcpy_diff_major.inl"

// === container interface ===
// must use pointer version
// scalar to container
inline void copy(DvecComp_O v, Comp_I s)
{
    vecset(v.p(), s, v.size(), v.step());
}

inline void copy(CmatDoub_O v, Doub_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(CmatComp_O v, Comp_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(MatInt_O v, Int_I s)
{
    vecset(v.p(), s, v.size());
}


inline void copy(MatDoub_O v, Doub_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(Mat3Doub_O v, Doub_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(Cmat3Doub_O v, Doub_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(MatComp_O v, Comp_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(VecInt_O v, Int_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(VecLlong_O v, Llong_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(VecDoub_O v, Doub_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(VecComp_O v, Comp_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(CmatInt_O v, Int_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(CmatLlong_O v, Llong_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(Cmat3Comp_O v, Comp_I s)
{
    vecset(v.p(), s, v.size());
}

inline void copy(DcmatComp_O v, Comp_I s)
{
    Long N1 = v.n0(), N2 = v.n1();
    for (Long j = 0; j < N2; ++j)
        vecset(&v(0, j), s, N1);
}

inline void copy(DcmatDoub_O v, Doub_I s)
{
    Long N1 = v.n0(), N2 = v.n1();
    for (Long j = 0; j < N2; ++j)
        vecset(&v(0, j), s, N1);
}

inline void copy(Cmat3Int_O v, Int_I s)
{
    vecset(v.p(), s, v.size());
}


// assign value to containers
inline void assign(VecDoub_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Doub);
    va_end(args);
}

inline void assign2(VecDoub_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Doub);
    va_end(args);
}


inline void assign(VecComp_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Comp);
    va_end(args);
}

inline void assign2(VecComp_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Comp);
    va_end(args);
}

inline void assign(CmatDoub_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Doub);
    va_end(args);
}

inline void assign2(CmatDoub_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Doub);
    va_end(args);
}


inline void assign(SvecDoub_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Doub);
    va_end(args);
}

inline void assign2(SvecDoub_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Doub);
    va_end(args);
}

inline void assign(ScmatDoub_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Doub);
    va_end(args);
}

inline void assign2(ScmatDoub_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Doub);
    va_end(args);
}

inline void assign(ScmatComp_O v, ...)
{
    va_list args;
    va_start(args, v);
    Long N = v.size();
    for (Long i = 0; i < N; ++i)
        v[i] = va_arg(args, Comp);
    va_end(args);
}

inline void assign2(ScmatComp_IO v, Long_I ind, Long_I N, ...)
{
    va_list args;
    va_start(args, N);
    for (Long i = ind; i < ind+N; ++i)
        v[i] = va_arg(args, Comp);
    va_end(args);
}


// assign initializer list to containers
inline void assign(VecDoub_O v, const std::initializer_list<Doub> &v1)
{
    const Doub *p1 = v1.begin();
    Long N = v1.size();
#ifdef SLS_CHECK_SHAPES
    if (v.size() != N)
        SLS_ERR("wrong shape!");
#endif
    for (Long i = 0; i < N; ++i)
        v[i] = p1[i];
}

inline void assign(VecComp_O v, const std::initializer_list<Comp> &v1)
{
    const Comp *p1 = v1.begin();
    Long N = v1.size();
#ifdef SLS_CHECK_SHAPES
    if (v.size() != N)
        SLS_ERR("wrong shape!");
#endif
    for (Long i = 0; i < N; ++i)
        v[i] = p1[i];
}

inline void assign(CmatDoub_O v, const std::initializer_list<Doub> &v1)
{
    const Doub *p1 = v1.begin();
    Long N = v1.size();
#ifdef SLS_CHECK_SHAPES
    if (v.size() != N)
        SLS_ERR("wrong shape!");
#endif
    for (Long i = 0; i < N; ++i)
        v[i] = p1[i];
}

inline void assign(SvecDoub_O v, const std::initializer_list<Doub> &v1)
{
    const Doub *p1 = v1.begin();
    Long N = v1.size();
#ifdef SLS_CHECK_SHAPES
    if (v.size() != N)
        SLS_ERR("wrong shape!");
#endif
    for (Long i = 0; i < N; ++i)
        v[i] = p1[i];
}

inline void assign(ScmatDoub_O v, const std::initializer_list<Doub> &v1)
{
    const Doub *p1 = v1.begin();
    Long N = v1.size();
#ifdef SLS_CHECK_SHAPES
    if (v.size() != N)
        SLS_ERR("wrong shape!");
#endif
    for (Long i = 0; i < N; ++i)
        v[i] = p1[i];
}

inline void assign(ScmatComp_O v, const std::initializer_list<Comp> &v1)
{
    const Comp *p1 = v1.begin();
    Long N = v1.size();
#ifdef SLS_CHECK_SHAPES
    if (v.size() != N)
        SLS_ERR("wrong shape!");
#endif
    for (Long i = 0; i < N; ++i)
        v[i] = p1[i];
}


// container to container
inline void copy(VecInt_O v, VecInt_I v1)
{
    assert_same_shape(v, v1);
    if (v.size() == 0)
        return;
    veccpy(v.p(), v1.p(), v.size());
}

inline void copy(VecInt_O v, DvecInt_I v1)
{
    assert_same_shape(v, v1);
    if (v.size() == 0)
        return;
    veccpy(v.p(), v1.p(), v1.step(), v1.size());
}

inline void copy(VecInt_O v, SvecInt_I v1)
{
    assert_same_shape(v, v1);
    if (v.size() == 0)
        return;
    veccpy(v.p(), v1.p(), v.size());
}

inline void copy(VecLlong_O v, VecLlong_I v1)
{
    assert_same_shape(v, v1);
    if (v.size() == 0)
        return;
    veccpy(v.p(), v1.p(), v.size());
}

inline void copy(VecDoub_O v, VecDoub_I v1)
{
    assert_same_shape(v, v1);
    if (v.size() == 0)
        return;
    veccpy(v.p(), v1.p(), v.size());
}

inline void copy(VecComp_O v, VecComp_I v1)
{
    assert_same_shape(v, v1);
    if (v.size() == 0)
        return;
    veccpy(v.p(), v1.p(), v.size());
}


inline void copy(SvecDoub_O v, SvecDoub_I v1)
{
    assert_same_shape(v, v1);
    if (v.size() == 0)
        return;
    veccpy(v.p(), v1.p(), v.size());
}

inline void copy(DvecComp_O v, VecComp_I v1)
{
    assert_same_shape(v, v1);
    if (v.size() == 0)
        return;
    veccpy(v.p(), v.step(), v1.p(), v1.size());
}

inline void copy(MatDoub_O v, MatDoub_I v1)
{
    assert_same_shape(v, v1);
    if (v.size() == 0)
        return;
    veccpy(v.p(), v1.p(), v.size());
}

inline void copy(CmatInt_O v, CmatInt_I v1)
{
    assert_same_shape(v, v1);
    if (v.size() == 0)
        return;
    veccpy(v.p(), v1.p(), v.size());
}

inline void copy(CmatLlong_O v, CmatLlong_I v1)
{
    assert_same_shape(v, v1);
    if (v.size() == 0)
        return;
    veccpy(v.p(), v1.p(), v.size());
}

inline void copy(CmatDoub_O v, CmatDoub_I v1)
{
    assert_same_shape(v, v1);
    if (v.size() == 0)
        return;
    veccpy(v.p(), v1.p(), v.size());
}

inline void copy(CmatDoub_O v, MatDoub_I v1)
{
    assert_same_shape(v, v1);
    if (v.size() == 0)
        return;
    matcpy_diff_major(v.p(), v1.p(), v.n0(), v.n1());
}

inline void copy(MatDoub_O v, CmatDoub_I v1)
{
    assert_same_shape(v, v1);
    if (v.size() == 0)
        return;
    matcpy_diff_major(v.p(), v1.p(), v.n1(), v.n0());
}

inline void copy(Cmat3Int_O v, Cmat3Int_I v1)
{
    assert_same_shape(v, v1);
    if (v.size() == 0)
        return;
    veccpy(v.p(), v1.p(), v.size());
}

inline void copy(Cmat3Llong_O v, Cmat3Llong_I v1)
{
    assert_same_shape(v, v1);
    if (v.size() == 0)
        return;
    veccpy(v.p(), v1.p(), v.size());
}

inline void copy(Cmat3Doub_O v, Cmat3Doub_I v1)
{
    assert_same_shape(v, v1);
    if (v.size() == 0)
        return;
    veccpy(v.p(), v1.p(), v.size());
}

inline void copy(Mat3Doub_O v, Mat3Doub_I v1)
{
    assert_same_shape(v, v1);
    if (v.size() == 0)
        return;
    veccpy(v.p(), v1.p(), v.size());
}

inline void copy(CmatComp_O v, CmatComp_I v1)
{
    assert_same_shape(v, v1);
    if (v.size() == 0)
        return;
    veccpy(v.p(), v1.p(), v.size());
}

inline void copy(SvecComp_O v, SvecComp_I v1)
{
    assert_same_shape(v, v1);
    if (v.size() == 0)
        return;
    veccpy(v.p(), v1.p(), v.size());
}

inline void copy(DcmatInt_O v, DcmatInt_I v1)
{
    assert_same_shape(v, v1);
    if (v.size() == 0)
        return;
    matcpy(v.p(), v.lda(), v1.p(), v1.lda(), v.n0(), v.n1());
}

inline void copy(DcmatLlong_O v, DcmatLlong_I v1)
{
    assert_same_shape(v, v1);
    if (v.size() == 0)
        return;
    matcpy(v.p(), v.lda(), v1.p(), v1.lda(), v.n0(), v.n1());
}

inline void copy(DcmatDoub_O v, DcmatDoub_I v1)
{
    assert_same_shape(v, v1);
    if (v.size() == 0)
        return;
    matcpy(v.p(), v.lda(), v1.p(), v1.lda(), v.n0(), v.n1());
}

inline void copy(DcmatComp_O v, DcmatComp_I v1)
{
    assert_same_shape(v, v1);
    if (v.size() == 0)
        return;
    matcpy(v.p(), v.lda(), v1.p(), v1.lda(), v.n0(), v.n1());
}

inline void copy(Jcmat3Doub_O v, Jcmat3Doub_I v1)
{
    assert_same_shape(v, v1);
    if (v.size() == 0)
        return;
    // slow
    if (v1.size() != 0)
    for (Long k = 0; k < v.n2(); ++k)
        for (Long j = 0; j < v.n1(); ++j)
            for (Long i = 0; i < v.n0(); ++i)
                v(i, j, k) = v1(i, j, k);
}

inline void copy(Jcmat3Comp_O v, Jcmat3Comp_I v1)
{
    assert_same_shape(v, v1);
    if (v.size() == 0)
        return;
    // slow
    if (v1.size() != 0)
    for (Long k = 0; k < v.n2(); ++k)
        for (Long j = 0; j < v.n1(); ++j)
            for (Long i = 0; i < v.n0(); ++i)
                v(i, j, k) = v1(i, j, k);
}

inline void copy(DvecInt_O v, DvecInt_I v1)
{
    assert_same_shape(v, v1);
    if (v.size() == 0)
        return;
    veccpy(v.p(), v.step(), v1.p(), v1.step(), v.size());
}

inline void copy(DvecLlong_O v, DvecLlong_I v1)
{
    assert_same_shape(v, v1);
    if (v.size() == 0)
        return;
    veccpy(v.p(), v.step(), v1.p(), v1.step(), v.size());
}

inline void copy(DvecDoub_O v, DvecDoub_I v1)
{
    assert_same_shape(v, v1);
    if (v.size() == 0)
        return;
    veccpy(v.p(), v.step(), v1.p(), v1.step(), v.size());
}

inline void copy(ScmatDoub_O v, CmatDoub_I v1)
{
    assert_same_shape(v, v1);
    if (v.size() == 0)
        return;
    veccpy(v.p(), v1.p(), v.size());
}

inline void copy(CmatDoub_O v, ScmatDoub_I v1)
{
    assert_same_shape(v, v1);
    if (v.size() == 0)
        return;
    veccpy(v.p(), v1.p(), v.size());
}

inline void copy(CmatComp_O v, ScmatComp_I v1)
{
    assert_same_shape(v, v1);
    if (v.size() == 0)
        return;
    veccpy(v.p(), v1.p(), v.size());
}


// for sparse containers
inline void copy(McooDoub_O v, McooDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
    assert_same_shape(v, v1);
    if (v.capacity() < v1.nnz())
        SLS_ERR("not enough capacity!");
#endif
    if (v1.nnz() == 0)
        return;
    if (v.p() == v1.p())
        SLS_ERR("self assignment is forbidden!");
    Long Nnz = v1.nnz();
    v.resize(Nnz);
    veccpy(v.p(), v1.p(), Nnz);
    veccpy(v.row_p(), v1.row_p(), Nnz);
    veccpy(v.col_p(), v1.col_p(), Nnz);
}


// copy dense matrix to Mcoo matrix
// abs(s) < tol is considered 0
inline void copy(McooComp_O v, CmatComp_I v1, Doub_I tol = 0)
{
    assert_same_shape(v, v1);
    for (Long j = 0; j < v1.n1(); ++j) {
        for (Long i = 0; i < v1.n0(); ++i) {
            Comp val = v1(i, j);
            if (abs(val) > tol)
                v.push(val, i, j);
        }
    }
}


inline void copy(CmatDoub_O lhs, McooDoub_I rhs)
{
    assert_same_shape(lhs, rhs);
    copy(lhs, 0);
    for (Long i = 0; i < rhs.nnz(); ++i) {
        lhs(rhs.row(i), rhs.col(i)) = rhs[i];
    }
}


inline void copy(CmobdDoub_O lhs, CmobdDoub_I rhs)
{ copy(lhs.cmat3(), rhs.cmat3()); }


inline void copy(CmobdDoub_O lhs, McooDoub_I rhs)
{
    assert_same_shape(lhs, rhs);
    Cmat3Doub &c3 = lhs.cmat3();
    copy(c3, 0);
    for (Long k = 0; k < rhs.nnz(); ++k) {
        Long i = rhs.row(k), j = rhs.col(k);
        lhs.ref(i, j) = rhs[k];
    }
}

inline void copy(CmobdInt_O lhs, McooInt_I rhs)
{
    assert_same_shape(lhs, rhs);
    Cmat3Int &c3 = lhs.cmat3();
    copy(c3, 0);
    for (Long k = 0; k < rhs.nnz(); ++k) {
        Long i = rhs.row(k), j = rhs.col(k);
        lhs.ref(i, j) = rhs[k];
    }
}


// not optimized
inline void copy(CmatDoub_O lhs, CmobdDoub_I rhs)
{
    assert_same_shape(lhs, rhs);
    for (Long j = 0; j < lhs.n1(); ++j)
        for (Long i = 0; i < lhs.n0(); ++i)
            lhs(i, j) = rhs(i, j);
}


// inline void cooh2dense(@Tmat@_O lhs, @McoohTs@_I rhs)
// {
// #ifdef SLS_CHECK_SHAPES
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
//             lhs(c, r) = conj(rhs(i));
//         }
//     }
// }

// from MatCoo and MatCooH to dense matrix
// #include "matrix_coo2dense.inl"

// template <class T, class T1, SLS_IF(is_promo<T, T1>())>
// void copy(MatCoo<T> &v, const CmatObd<T1> &v1)
// {
// #ifdef SLS_CHECK_SHAPES
//     if (!shape_cmp(v, v1))
//         SLS_ERR("wrong shape!");
//     if (v.capacity() < v1.nnz())
//         SLS_ERR("not enough capacity!");
// #endif
//     if (v1.nnz() == 0)
//         return;
//     Long N0 = v1.n0(), N1 = N0 - 1;
//     Long N = v1.n0();
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

DcmatComp band(CbandComp_IO);
DcmatComp_c band(CbandComp_I);
inline void copy(CbandComp_O a, Comp_I s)
{ copy(band(a), s); }

DcmatDoub band(CbandDoub_IO);
DcmatDoub_c band(CbandDoub_I);
inline void copy(CbandDoub_O a, Doub_I s)
{ copy(band(a), s); }


inline void copy(CbandDoub_O a, CbandDoub_I b)
{
#ifdef SLS_CHECK_SHAPES
    if (a.idiag() < b.nup() || a.lda() - a.idiag() - 1 < b.nlow())
        SLS_ERR("wrong shape!");
#endif
    a.reshape(b.n0(), b.nup(), b.nlow());
    copy(band(a), band(b));
}

inline void copy(CbandComp_O a, CbandComp_I b)
{
#ifdef SLS_CHECK_SHAPES
    if (a.idiag() < b.nup() || a.lda() - a.idiag() - 1 < b.nlow())
        SLS_ERR("wrong shape!");
#endif
    a.reshape(b.n0(), b.nup(), b.nlow());
    copy(band(a), band(b));
}


inline void copy(CmatDoub_O a, CbandDoub_I b)
{
    assert_same_shape(a, b);
    Long N1 = a.n0(), N2 = a.n1();
    for (Long j = 0; j < N2; ++j) {
        Long k = b.idiag() - j;
        Long i_beg = max(Long(0), j - b.nup()), i_end = min(N1, j + b.nlow() + 1);
        SvecDoub cut_a = cut0(a, j);
        SvecDoub_c cut_b = cut0(b.cmat(), j);
        for (Long i = 0; i < i_beg; ++i)
            cut_a[i] = 0;
        for (Long i = i_beg; i < i_end; i++)
            cut_a[i] = cut_b[k + i];
        for (Long i = i_end; i < N1; ++i)
            cut_a[i] = 0;
    }
}

inline void copy(CmatComp_O a, CbandComp_I b)
{
    assert_same_shape(a, b);
    Long N1 = a.n0(), N2 = a.n1();
    for (Long j = 0; j < N2; ++j) {
        Long k = b.idiag() - j;
        Long i_beg = max(Long(0), j - b.nup()), i_end = min(N1, j + b.nlow() + 1);
        SvecComp cut_a = cut0(a, j);
        SvecComp_c cut_b = cut0(b.cmat(), j);
        for (Long i = 0; i < i_beg; ++i)
            cut_a[i] = 0;
        for (Long i = i_beg; i < i_end; i++)
            cut_a[i] = cut_b[k + i];
        for (Long i = i_end; i < N1; ++i)
            cut_a[i] = 0;
    }
}

inline void copy(CbandComp_O b, CmatComp_I a)
{
    assert_same_shape(a, b);
    Long N1 = a.n0(), N2 = a.n1();
    for (Long j = 0; j < N2; ++j) {
        SvecComp cut_b = cut0(b.cmat(), j);
        SvecComp_c cut_a = cut0(a, j);
        Long k = b.idiag() - j;
        Long i_beg = max(Long(0), j - b.nup()), i_end = min(N1, j + b.nlow() + 1);
        for (Long i = i_beg; i < i_end; ++i)
            cut_b[k + i] = cut_a[i];
    }
}

inline void copy(CbandDoub_O b, CmatDoub_I a)
{
    assert_same_shape(a, b);
    Long N1 = a.n0(), N2 = a.n1();
    for (Long j = 0; j < N2; ++j) {
        SvecDoub cut_b = cut0(b.cmat(), j);
        SvecDoub_c cut_a = cut0(a, j);
        Long k = b.idiag() - j;
        Long i_beg = max(Long(0), j - b.nup()), i_end = min(N1, j + b.nlow() + 1);
        for (Long i = i_beg; i < i_end; ++i)
            cut_b[k + i] = cut_a[i];
    }
}


// void copy(Matrix<T> &b, const Matrix<T> &a, Long_I Nup, Long_I Nlow)
// {
//     Long N1 = a.n0(), N2 = a.n1();
//     for (Long i = 0; i < N1; i++) {
//         Long k = Nlow - i;
//         for (Long j = max(Long(0), i - Nlow); j < MIN(N2, i + Nup + 1); j++) {
//             b(i, k + j) = a(i, j);
//         }
//     }
// }

// template <class T, SLS_IF0(is_scalar<T>())>
// void copy(Matrix<T> &a, const Matrix<T> &b, Long_I Nup, Long_I Nlow)
// {
//     Long N1 = a.n0(), N2 = a.n1();
//     for (Long i = 0; i < N1; i++) {
//         Long k = Nlow - i;
//         for (Long j = max(Long(0), i - Nlow); j < MIN(N2, i + Nup + 1); j++) {
//             a(i, j) = b(i, k + j);
//         }
//     }
// }

} // namespace slisc
