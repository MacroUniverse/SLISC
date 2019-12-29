#pragma once
#include "compare.h"

namespace slisc {
// sort first m elements of arr, quicksort algorithm
inline void sort_v(Char *arr, Long_I N, Long_I m = -1)
{
    static const Int M = 7, NSTACK = 64;
    Long i, ir, j, k, jstack = -1, l = 0, n = N;
    Char a;
    VecLong istack(NSTACK);
    if (m>0) n = min(m, n);
    ir = n - 1;
    for (;;) {
        if (ir - l < M) {
            for (j = l + 1; j <= ir; j++) {
                a = arr[j];
                for (i = j - 1; i >= l; i--) {
                    if (arr[i] <= a) break;
                    arr[i + 1] = arr[i];
                }
                arr[i + 1] = a;
            }
            if (jstack < 0) break;
            ir = istack[jstack--];
            l = istack[jstack--];
        }
        else {
            k = (l + ir) >> 1;
            swap(arr[k], arr[l + 1]);
            if (arr[l] > arr[ir]) {
                swap(arr[l], arr[ir]);
            }
            if (arr[l + 1] > arr[ir]) {
                swap(arr[l + 1], arr[ir]);
            }
            if (arr[l] > arr[l + 1]) {
                swap(arr[l], arr[l + 1]);
            }
            i = l + 1;
            j = ir;
            a = arr[l + 1];
            for (;;) {
                do i++; while (arr[i] < a);
                do j--; while (arr[j] > a);
                if (j < i) break;
                swap(arr[i], arr[j]);
            }
            arr[l + 1] = arr[j];
            arr[j] = a;
            jstack += 2;
            if (jstack >= NSTACK) throw("NSTACK too small in sort.");
            if (ir - i + 1 >= j - l) {
                istack[jstack] = ir;
                istack[jstack - 1] = i;
                ir = j - 1;
            }
            else {
                istack[jstack] = j - 1;
                istack[jstack - 1] = l;
                l = i;
            }
        }
    }
}

// sort first m elements of arr, quicksort algorithm
inline void sort_v(Int *arr, Long_I N, Long_I m = -1)
{
    static const Int M = 7, NSTACK = 64;
    Long i, ir, j, k, jstack = -1, l = 0, n = N;
    Int a;
    VecLong istack(NSTACK);
    if (m>0) n = min(m, n);
    ir = n - 1;
    for (;;) {
        if (ir - l < M) {
            for (j = l + 1; j <= ir; j++) {
                a = arr[j];
                for (i = j - 1; i >= l; i--) {
                    if (arr[i] <= a) break;
                    arr[i + 1] = arr[i];
                }
                arr[i + 1] = a;
            }
            if (jstack < 0) break;
            ir = istack[jstack--];
            l = istack[jstack--];
        }
        else {
            k = (l + ir) >> 1;
            swap(arr[k], arr[l + 1]);
            if (arr[l] > arr[ir]) {
                swap(arr[l], arr[ir]);
            }
            if (arr[l + 1] > arr[ir]) {
                swap(arr[l + 1], arr[ir]);
            }
            if (arr[l] > arr[l + 1]) {
                swap(arr[l], arr[l + 1]);
            }
            i = l + 1;
            j = ir;
            a = arr[l + 1];
            for (;;) {
                do i++; while (arr[i] < a);
                do j--; while (arr[j] > a);
                if (j < i) break;
                swap(arr[i], arr[j]);
            }
            arr[l + 1] = arr[j];
            arr[j] = a;
            jstack += 2;
            if (jstack >= NSTACK) throw("NSTACK too small in sort.");
            if (ir - i + 1 >= j - l) {
                istack[jstack] = ir;
                istack[jstack - 1] = i;
                ir = j - 1;
            }
            else {
                istack[jstack] = j - 1;
                istack[jstack - 1] = l;
                l = i;
            }
        }
    }
}

// sort first m elements of arr, quicksort algorithm
inline void sort_v(Llong *arr, Long_I N, Long_I m = -1)
{
    static const Int M = 7, NSTACK = 64;
    Long i, ir, j, k, jstack = -1, l = 0, n = N;
    Llong a;
    VecLong istack(NSTACK);
    if (m>0) n = min(m, n);
    ir = n - 1;
    for (;;) {
        if (ir - l < M) {
            for (j = l + 1; j <= ir; j++) {
                a = arr[j];
                for (i = j - 1; i >= l; i--) {
                    if (arr[i] <= a) break;
                    arr[i + 1] = arr[i];
                }
                arr[i + 1] = a;
            }
            if (jstack < 0) break;
            ir = istack[jstack--];
            l = istack[jstack--];
        }
        else {
            k = (l + ir) >> 1;
            swap(arr[k], arr[l + 1]);
            if (arr[l] > arr[ir]) {
                swap(arr[l], arr[ir]);
            }
            if (arr[l + 1] > arr[ir]) {
                swap(arr[l + 1], arr[ir]);
            }
            if (arr[l] > arr[l + 1]) {
                swap(arr[l], arr[l + 1]);
            }
            i = l + 1;
            j = ir;
            a = arr[l + 1];
            for (;;) {
                do i++; while (arr[i] < a);
                do j--; while (arr[j] > a);
                if (j < i) break;
                swap(arr[i], arr[j]);
            }
            arr[l + 1] = arr[j];
            arr[j] = a;
            jstack += 2;
            if (jstack >= NSTACK) throw("NSTACK too small in sort.");
            if (ir - i + 1 >= j - l) {
                istack[jstack] = ir;
                istack[jstack - 1] = i;
                ir = j - 1;
            }
            else {
                istack[jstack] = j - 1;
                istack[jstack - 1] = l;
                l = i;
            }
        }
    }
}

// sort first m elements of arr, quicksort algorithm
inline void sort_v(Doub *arr, Long_I N, Long_I m = -1)
{
    static const Int M = 7, NSTACK = 64;
    Long i, ir, j, k, jstack = -1, l = 0, n = N;
    Doub a;
    VecLong istack(NSTACK);
    if (m>0) n = min(m, n);
    ir = n - 1;
    for (;;) {
        if (ir - l < M) {
            for (j = l + 1; j <= ir; j++) {
                a = arr[j];
                for (i = j - 1; i >= l; i--) {
                    if (arr[i] <= a) break;
                    arr[i + 1] = arr[i];
                }
                arr[i + 1] = a;
            }
            if (jstack < 0) break;
            ir = istack[jstack--];
            l = istack[jstack--];
        }
        else {
            k = (l + ir) >> 1;
            swap(arr[k], arr[l + 1]);
            if (arr[l] > arr[ir]) {
                swap(arr[l], arr[ir]);
            }
            if (arr[l + 1] > arr[ir]) {
                swap(arr[l + 1], arr[ir]);
            }
            if (arr[l] > arr[l + 1]) {
                swap(arr[l], arr[l + 1]);
            }
            i = l + 1;
            j = ir;
            a = arr[l + 1];
            for (;;) {
                do i++; while (arr[i] < a);
                do j--; while (arr[j] > a);
                if (j < i) break;
                swap(arr[i], arr[j]);
            }
            arr[l + 1] = arr[j];
            arr[j] = a;
            jstack += 2;
            if (jstack >= NSTACK) throw("NSTACK too small in sort.");
            if (ir - i + 1 >= j - l) {
                istack[jstack] = ir;
                istack[jstack - 1] = i;
                ir = j - 1;
            }
            else {
                istack[jstack] = j - 1;
                istack[jstack - 1] = l;
                l = i;
            }
        }
    }
}


// sort first m elements of v
inline void sort(VecChar_IO v, Long_I m = -1)
{
    sort_v(v.ptr(), v.size(), m);
}

// sort first m elements of v
inline void sort(VecInt_IO v, Long_I m = -1)
{
    sort_v(v.ptr(), v.size(), m);
}

// sort first m elements of v
inline void sort(VecLlong_IO v, Long_I m = -1)
{
    sort_v(v.ptr(), v.size(), m);
}

// sort first m elements of v
inline void sort(VecDoub_IO v, Long_I m = -1)
{
    sort_v(v.ptr(), v.size(), m);
}


//  from Numerical Recipes 3ed
inline void sort2_vv(Char *v, Llong *v1, Long_I N)
{
    const Long M = 7, NSTACK = 64;
    Long i, ir, j, k, jstack = -1, l = 0, n = N;
    Char a;
    Llong b;
    VecLong istack(NSTACK);
    ir = n - 1;
    for (;;) {
        if (ir - l < M) {
            for (j = l + 1; j <= ir; j++) {
                a = v[j];
                b = v1[j];
                for (i = j - 1; i >= l; i--) {
                    if (v[i] <= a) break;
                    v[i + 1] = v[i];
                    v1[i + 1] = v1[i];
                }
                v[i + 1] = a;
                v1[i + 1] = b;
            }
            if (jstack < 0) break;
            ir = istack[jstack--];
            l = istack[jstack--];
        }
        else {
            k = (l + ir) >> 1;
            swap(v[k], v[l + 1]);
            swap(v1[k], v1[l + 1]);
            if (v[l] > v[ir]) {
                swap(v[l], v[ir]);
                swap(v1[l], v1[ir]);
            }
            if (v[l + 1] > v[ir]) {
                swap(v[l + 1], v[ir]);
                swap(v1[l + 1], v1[ir]);
            }
            if (v[l] > v[l + 1]) {
                swap(v[l], v[l + 1]);
                swap(v1[l], v1[l + 1]);
            }
            i = l + 1;
            j = ir;
            a = v[l + 1];
            b = v1[l + 1];
            for (;;) {
                do i++; while (v[i] < a);
                do j--; while (v[j] > a);
                if (j < i) break;
                swap(v[i], v[j]);
                swap(v1[i], v1[j]);
            }
            v[l + 1] = v[j];
            v[j] = a;
            v1[l + 1] = v1[j];
            v1[j] = b;
            jstack += 2;
            if (jstack >= NSTACK) throw("NSTACK too small in sort2.");
            if (ir - i + 1 >= j - l) {
                istack[jstack] = ir;
                istack[jstack - 1] = i;
                ir = j - 1;
            }
            else {
                istack[jstack] = j - 1;
                istack[jstack - 1] = l;
                l = i;
            }
        }
    }
}

//  from Numerical Recipes 3ed
inline void sort2_vv(Int *v, Int *v1, Long_I N)
{
    const Long M = 7, NSTACK = 64;
    Long i, ir, j, k, jstack = -1, l = 0, n = N;
    Int a;
    Int b;
    VecLong istack(NSTACK);
    ir = n - 1;
    for (;;) {
        if (ir - l < M) {
            for (j = l + 1; j <= ir; j++) {
                a = v[j];
                b = v1[j];
                for (i = j - 1; i >= l; i--) {
                    if (v[i] <= a) break;
                    v[i + 1] = v[i];
                    v1[i + 1] = v1[i];
                }
                v[i + 1] = a;
                v1[i + 1] = b;
            }
            if (jstack < 0) break;
            ir = istack[jstack--];
            l = istack[jstack--];
        }
        else {
            k = (l + ir) >> 1;
            swap(v[k], v[l + 1]);
            swap(v1[k], v1[l + 1]);
            if (v[l] > v[ir]) {
                swap(v[l], v[ir]);
                swap(v1[l], v1[ir]);
            }
            if (v[l + 1] > v[ir]) {
                swap(v[l + 1], v[ir]);
                swap(v1[l + 1], v1[ir]);
            }
            if (v[l] > v[l + 1]) {
                swap(v[l], v[l + 1]);
                swap(v1[l], v1[l + 1]);
            }
            i = l + 1;
            j = ir;
            a = v[l + 1];
            b = v1[l + 1];
            for (;;) {
                do i++; while (v[i] < a);
                do j--; while (v[j] > a);
                if (j < i) break;
                swap(v[i], v[j]);
                swap(v1[i], v1[j]);
            }
            v[l + 1] = v[j];
            v[j] = a;
            v1[l + 1] = v1[j];
            v1[j] = b;
            jstack += 2;
            if (jstack >= NSTACK) throw("NSTACK too small in sort2.");
            if (ir - i + 1 >= j - l) {
                istack[jstack] = ir;
                istack[jstack - 1] = i;
                ir = j - 1;
            }
            else {
                istack[jstack] = j - 1;
                istack[jstack - 1] = l;
                l = i;
            }
        }
    }
}

//  from Numerical Recipes 3ed
inline void sort2_vv(Int *v, Llong *v1, Long_I N)
{
    const Long M = 7, NSTACK = 64;
    Long i, ir, j, k, jstack = -1, l = 0, n = N;
    Int a;
    Llong b;
    VecLong istack(NSTACK);
    ir = n - 1;
    for (;;) {
        if (ir - l < M) {
            for (j = l + 1; j <= ir; j++) {
                a = v[j];
                b = v1[j];
                for (i = j - 1; i >= l; i--) {
                    if (v[i] <= a) break;
                    v[i + 1] = v[i];
                    v1[i + 1] = v1[i];
                }
                v[i + 1] = a;
                v1[i + 1] = b;
            }
            if (jstack < 0) break;
            ir = istack[jstack--];
            l = istack[jstack--];
        }
        else {
            k = (l + ir) >> 1;
            swap(v[k], v[l + 1]);
            swap(v1[k], v1[l + 1]);
            if (v[l] > v[ir]) {
                swap(v[l], v[ir]);
                swap(v1[l], v1[ir]);
            }
            if (v[l + 1] > v[ir]) {
                swap(v[l + 1], v[ir]);
                swap(v1[l + 1], v1[ir]);
            }
            if (v[l] > v[l + 1]) {
                swap(v[l], v[l + 1]);
                swap(v1[l], v1[l + 1]);
            }
            i = l + 1;
            j = ir;
            a = v[l + 1];
            b = v1[l + 1];
            for (;;) {
                do i++; while (v[i] < a);
                do j--; while (v[j] > a);
                if (j < i) break;
                swap(v[i], v[j]);
                swap(v1[i], v1[j]);
            }
            v[l + 1] = v[j];
            v[j] = a;
            v1[l + 1] = v1[j];
            v1[j] = b;
            jstack += 2;
            if (jstack >= NSTACK) throw("NSTACK too small in sort2.");
            if (ir - i + 1 >= j - l) {
                istack[jstack] = ir;
                istack[jstack - 1] = i;
                ir = j - 1;
            }
            else {
                istack[jstack] = j - 1;
                istack[jstack - 1] = l;
                l = i;
            }
        }
    }
}

//  from Numerical Recipes 3ed
inline void sort2_vv(Llong *v, Llong *v1, Long_I N)
{
    const Long M = 7, NSTACK = 64;
    Long i, ir, j, k, jstack = -1, l = 0, n = N;
    Llong a;
    Llong b;
    VecLong istack(NSTACK);
    ir = n - 1;
    for (;;) {
        if (ir - l < M) {
            for (j = l + 1; j <= ir; j++) {
                a = v[j];
                b = v1[j];
                for (i = j - 1; i >= l; i--) {
                    if (v[i] <= a) break;
                    v[i + 1] = v[i];
                    v1[i + 1] = v1[i];
                }
                v[i + 1] = a;
                v1[i + 1] = b;
            }
            if (jstack < 0) break;
            ir = istack[jstack--];
            l = istack[jstack--];
        }
        else {
            k = (l + ir) >> 1;
            swap(v[k], v[l + 1]);
            swap(v1[k], v1[l + 1]);
            if (v[l] > v[ir]) {
                swap(v[l], v[ir]);
                swap(v1[l], v1[ir]);
            }
            if (v[l + 1] > v[ir]) {
                swap(v[l + 1], v[ir]);
                swap(v1[l + 1], v1[ir]);
            }
            if (v[l] > v[l + 1]) {
                swap(v[l], v[l + 1]);
                swap(v1[l], v1[l + 1]);
            }
            i = l + 1;
            j = ir;
            a = v[l + 1];
            b = v1[l + 1];
            for (;;) {
                do i++; while (v[i] < a);
                do j--; while (v[j] > a);
                if (j < i) break;
                swap(v[i], v[j]);
                swap(v1[i], v1[j]);
            }
            v[l + 1] = v[j];
            v[j] = a;
            v1[l + 1] = v1[j];
            v1[j] = b;
            jstack += 2;
            if (jstack >= NSTACK) throw("NSTACK too small in sort2.");
            if (ir - i + 1 >= j - l) {
                istack[jstack] = ir;
                istack[jstack - 1] = i;
                ir = j - 1;
            }
            else {
                istack[jstack] = j - 1;
                istack[jstack - 1] = l;
                l = i;
            }
        }
    }
}

//  from Numerical Recipes 3ed
inline void sort2_vv(Doub *v, Llong *v1, Long_I N)
{
    const Long M = 7, NSTACK = 64;
    Long i, ir, j, k, jstack = -1, l = 0, n = N;
    Doub a;
    Llong b;
    VecLong istack(NSTACK);
    ir = n - 1;
    for (;;) {
        if (ir - l < M) {
            for (j = l + 1; j <= ir; j++) {
                a = v[j];
                b = v1[j];
                for (i = j - 1; i >= l; i--) {
                    if (v[i] <= a) break;
                    v[i + 1] = v[i];
                    v1[i + 1] = v1[i];
                }
                v[i + 1] = a;
                v1[i + 1] = b;
            }
            if (jstack < 0) break;
            ir = istack[jstack--];
            l = istack[jstack--];
        }
        else {
            k = (l + ir) >> 1;
            swap(v[k], v[l + 1]);
            swap(v1[k], v1[l + 1]);
            if (v[l] > v[ir]) {
                swap(v[l], v[ir]);
                swap(v1[l], v1[ir]);
            }
            if (v[l + 1] > v[ir]) {
                swap(v[l + 1], v[ir]);
                swap(v1[l + 1], v1[ir]);
            }
            if (v[l] > v[l + 1]) {
                swap(v[l], v[l + 1]);
                swap(v1[l], v1[l + 1]);
            }
            i = l + 1;
            j = ir;
            a = v[l + 1];
            b = v1[l + 1];
            for (;;) {
                do i++; while (v[i] < a);
                do j--; while (v[j] > a);
                if (j < i) break;
                swap(v[i], v[j]);
                swap(v1[i], v1[j]);
            }
            v[l + 1] = v[j];
            v[j] = a;
            v1[l + 1] = v1[j];
            v1[j] = b;
            jstack += 2;
            if (jstack >= NSTACK) throw("NSTACK too small in sort2.");
            if (ir - i + 1 >= j - l) {
                istack[jstack] = ir;
                istack[jstack - 1] = i;
                ir = j - 1;
            }
            else {
                istack[jstack] = j - 1;
                istack[jstack - 1] = l;
                l = i;
            }
        }
    }
}


inline void sort2(VecChar_IO v, VecLlong_IO v1)
{
#ifdef SLS_CHECK_BOUNDS
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    sort2_vv(v.ptr(), v1.ptr(), v.size());
}

inline void sort2(VecInt_IO v, VecInt_IO v1)
{
#ifdef SLS_CHECK_BOUNDS
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    sort2_vv(v.ptr(), v1.ptr(), v.size());
}

inline void sort2(VecInt_IO v, VecLlong_IO v1)
{
#ifdef SLS_CHECK_BOUNDS
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    sort2_vv(v.ptr(), v1.ptr(), v.size());
}

inline void sort2(VecLlong_IO v, VecLlong_IO v1)
{
#ifdef SLS_CHECK_BOUNDS
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    sort2_vv(v.ptr(), v1.ptr(), v.size());
}

inline void sort2(VecDoub_IO v, VecLlong_IO v1)
{
#ifdef SLS_CHECK_BOUNDS
    if (!shape_cmp(v, v1))
        SLS_ERR("wrong shape!");
#endif
    sort2_vv(v.ptr(), v1.ptr(), v.size());
}

inline void sort2(vecLlong_IO v, vecLlong_IO v1)
{
#ifdef SLS_CHECK_BOUNDS
    if (v.size() != v1.size())
        SLS_ERR("wrong shape!");
#endif
    sort2_vv(v.data(), v1.data(), (Long)v.size());
}

} // namespace slisc
