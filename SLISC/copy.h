// copy data from one container to another
// includes container shape checking
// all `container = container` should be implemented using copy
#pragma once

#include "meta.h"
#include "vector.h"
#include "matcoo.h"

namespace slisc {
//  === pointer interface ===

template<class T, class T1, SLS_IF(is_promo<T, T1>())>
inline void vecset(T *v, const T1 &val, Long_I n)
{
    T val0 = (T)val;
    for (T *p = v; p < v + n; ++p)
        *p = val0;
}

template<class T, class T1, SLS_IF(is_promo<T, T1>())>
inline void vecset(T *v, const T1 &val, Long_I n, Long_I step)
{
    T val0 = (T)val;
    for (T *p = v; p < v + n*step; p += step)
        *p = val0;
}

template<class T>
inline void veccpy(T *v, const T *v1, Long_I n)
{
    memcpy(v, v1, n * sizeof(T));
}

template<class T, class T1, SLS_IF(is_promo<T,T1>())>
inline void veccpy(T *v, const T1 *v1, Long_I n)
{
    for (Long i = 0; i < n; ++i)
        v[i] = v1[i];
}

template<class T, class T1, SLS_IF(is_promo<T, T1>())>
inline void veccpy(T *v, const T1 *v1, Long_I step1, Long_I n)
{
    for (T *p = v; p < v + n; ++p) {
        *p = *v1;
        v1 += step1;
    }
}

template<class T, class T1, SLS_IF(is_promo<T, T1>())>
inline void veccpy(T *v, Long_I step, const T1 *v1, Long_I n)
{
    for (T *p = v; p < v + n*step; p += step) {
        *p = *v1;
        ++v1;
    }
}

template<class T, class T1, SLS_IF(is_promo<T, T1>())>
inline void veccpy(T *v, Long_I step, const T1 *v1, Long_I step1, Long_I n)
{
    T *end = v + n * step;
    for (; v < end; v += step) {
        *v = *v1;
        v1 += step1;
    }
}

template<class T, class T1, SLS_IF(is_promo<T, T1>())>
inline void matcpy(T *v, Long_I lda, const T1 *v1, Long_I lda1, Long_I Nr, Long_I Nc)
{
    for (Long j = 0; j < Nr; ++j) {
        veccpy(v, v1, Nc);
        v += lda; v1 += lda1;
    }
}

// copy dense matrix with different majors
// if a1 is row major and a2 is column major, N1 is number of columns, N2 is number of rows
// if a1 is column major and a2 is row major, N1 is number of rows, N2 is number of columns
template<class T, class T1, SLS_IF(is_promo<T, T1>())>
inline void matcpy_2_major(T *a2, const T1 *a1, Long_I N2, Long_I N1)
{
    for (Long i2 = 0; i2 < N2; ++i2) {
        Long start = N1 * i2, k2 = i2;
        for (Long k1 = start; k1 < start + N1; ++k1) {
            a2[k2] = a1[k1];
            k2 += N2;
        }
    }
}

// copy stride matrix with different majors
// lda1 is leading dimension of a1, lda2 is leading dimension of a2
// if a1 is row major and a2 is column major, N1 is number of columns, N2 is number of rows
// if a1 is column major and a2 is row major, N1 is number of rows, N2 is number of columns
template<class T, class T1, SLS_IF(is_promo<T, T1>())>
inline void matcpy_2_major(T *a2, const T1 *a1, Long_I N2, Long_I lda2, Long_I N1, Long_I lda1)
{
    for (Long i2 = 0; i2 < N2; ++i2) {
        Long start = lda1 * i2, k2 = i2;
        for (Long k1 = start; k1 < start + N1; ++k1) {
            a2[k2] = a1[k1];
            k2 += lda2;
        }
    }
}

// === container interface ===
// must use pointer version
#include "copy_contain.inl"

// for sparse containers
#include "copy_Mcoo_Mcoo.inl"

template <class T, class T1, SLS_IF(is_promo<T, T1>())>
void copy(MatCoo<T> &v, const CmatObd<T1> &v1)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
    if (v.capacity() < v1.nnz())
        SLS_ERR("not enough capacity!");
#endif
    if (v1.nnz() == 0)
        return;
    Long N0 = v1.n0(), N1 = N0 - 1;
    Long N = v1.n1();
    Long k = 0;
    for (Long blk = 0; blk < v1.nblk(); ++blk) {
        for (Long j = 0; j < N0; ++j) {
            for (Long i = 0; i < N0; ++i) {
                Long shift = blk * N1 - 1;
                Long ii = shift + i, jj = shift + j;
                if (!((i == N1 && j == N1) || ii < 0 || jj < 0 || ii == N || jj == N))
                    v.push(v1(k), ii, jj);
                ++k;
            }
        }
    }
}

} // namespace slisc
