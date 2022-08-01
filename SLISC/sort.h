#pragma once
#include "compare.h"
#include "arithmetic.h"
#include "unicode.h"

namespace slisc {
// sort elements of arr
// adapted from Numerical Recipes 3ed
inline void sort_v(Char *arr, Long_I n)
{
    static const Int M = 7, NSTACK = 64;
    Long i, ir, j, k, jstack = -1, l = 0;
    Char a;
    VecLong istack(NSTACK);
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

// sort elements of arr
// adapted from Numerical Recipes 3ed
inline void sort_v(Int *arr, Long_I n)
{
    static const Int M = 7, NSTACK = 64;
    Long i, ir, j, k, jstack = -1, l = 0;
    Int a;
    VecLong istack(NSTACK);
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

// sort elements of arr
// adapted from Numerical Recipes 3ed
inline void sort_v(Llong *arr, Long_I n)
{
    static const Int M = 7, NSTACK = 64;
    Long i, ir, j, k, jstack = -1, l = 0;
    Llong a;
    VecLong istack(NSTACK);
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

// sort elements of arr
// adapted from Numerical Recipes 3ed
inline void sort_v(Doub *arr, Long_I n)
{
    static const Int M = 7, NSTACK = 64;
    Long i, ir, j, k, jstack = -1, l = 0;
    Doub a;
    VecLong istack(NSTACK);
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

// sort elements of arr
// adapted from Numerical Recipes 3ed
inline void sort_v(Str *arr, Long_I n)
{
    static const Int M = 7, NSTACK = 64;
    Long i, ir, j, k, jstack = -1, l = 0;
    Str a;
    VecLong istack(NSTACK);
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

// sort elements of arr
// adapted from Numerical Recipes 3ed
inline void sort_v(Str32 *arr, Long_I n)
{
    static const Int M = 7, NSTACK = 64;
    Long i, ir, j, k, jstack = -1, l = 0;
    Str32 a;
    VecLong istack(NSTACK);
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


// sort elements of v
inline void sort(VecChar_IO v) { if (v.size() > 1) sort_v(&v[0], v.size()); }

// sort elements of v
inline void sort(VecInt_IO v) { if (v.size() > 1) sort_v(&v[0], v.size()); }

// sort elements of v
inline void sort(VecLlong_IO v) { if (v.size() > 1) sort_v(&v[0], v.size()); }

// sort elements of v
inline void sort(VecDoub_IO v) { if (v.size() > 1) sort_v(&v[0], v.size()); }

// sort elements of v
inline void sort(vecStr_IO v) { if (v.size() > 1) sort_v(&v[0], v.size()); }

// sort elements of v
inline void sort(vecStr32_IO v) { if (v.size() > 1) sort_v(&v[0], v.size()); }


// sort v while making the same change for v1
//  from Numerical Recipes 3ed
inline void sort_vv(Doub *v, Llong *v1, Long_I N)
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

//  from Numerical Recipes 3ed
inline void sort_vv(Int *v, Int *v1, Long_I N)
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
inline void sort_vv(Int *v, Llong *v1, Long_I N)
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
inline void sort_vv(Llong *v, Llong *v1, Long_I N)
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
inline void sort_vv(Llong *v, Str *v1, Long_I N)
{
    const Long M = 7, NSTACK = 64;
    Long i, ir, j, k, jstack = -1, l = 0, n = N;
    Llong a;
    Str b;
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
inline void sort_vv(Str *v, Str *v1, Long_I N)
{
    const Long M = 7, NSTACK = 64;
    Long i, ir, j, k, jstack = -1, l = 0, n = N;
    Str a;
    Str b;
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
inline void sort_vv(Str32 *v, Str32 *v1, Long_I N)
{
    const Long M = 7, NSTACK = 64;
    Long i, ir, j, k, jstack = -1, l = 0, n = N;
    Str32 a;
    Str32 b;
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
inline void sort_vv(Str *v, Llong *v1, Long_I N)
{
    const Long M = 7, NSTACK = 64;
    Long i, ir, j, k, jstack = -1, l = 0, n = N;
    Str a;
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


// sort v while making the same change for v1
inline void sort(VecInt_IO v, VecInt_IO v1)
{
    assert_same_shape(v, v1);
    sort_vv(&v[0], &v1[0], v.size());
}

inline void sort(VecInt_IO v, VecLlong_IO v1)
{
    assert_same_shape(v, v1);
    sort_vv(&v[0], &v1[0], v.size());
}

inline void sort(VecLlong_IO v, VecLlong_IO v1)
{
    assert_same_shape(v, v1);
    sort_vv(&v[0], &v1[0], v.size());
}

inline void sort(VecDoub_IO v, VecLlong_IO v1)
{
    assert_same_shape(v, v1);
    sort_vv(&v[0], &v1[0], v.size());
}

inline void sort(vecLlong_IO v, vecLlong_IO v1)
{
    assert_same_shape(v, v1);
    sort_vv(&v[0], &v1[0], v.size());
}

inline void sort(vecLlong_IO v, vecStr_IO v1)
{
    assert_same_shape(v, v1);
    sort_vv(&v[0], &v1[0], v.size());
}

inline void sort(vecStr_IO v, vecStr_IO v1)
{
    assert_same_shape(v, v1);
    sort_vv(&v[0], &v1[0], v.size());
}

inline void sort(vecStr32_IO v, vecStr32_IO v1)
{
    assert_same_shape(v, v1);
    sort_vv(&v[0], &v1[0], v.size());
}

inline void sort(vecStr_IO v, VecLlong_IO v1)
{
    assert_same_shape(v, v1);
    sort_vv(&v[0], &v1[0], v.size());
}

inline void sort(vecStr_IO v, vecLlong_IO v1)
{
    assert_same_shape(v, v1);
    sort_vv(&v[0], &v1[0], v.size());
}


// case insensitive sorting for string
// result is independent of the input order
inline void sort_case_insens(vecStr_IO v)
{
    sort(v);
    vecStr v_low; to_lower(v_low, v);
    sort(v_low, v); // case insensitive sorting
}

inline void sort_case_insens(vecStr32_IO v)
{
    sort(v);
    vecStr32 v_low; to_lower(v_low, v);
    sort(v_low, v); // case insensitive sorting
}

// case insensitive sorting for string
// result is independent of the input order
inline void sort_case_insens(vecStr_IO v, vecStr_IO v1)
{
    sort(v, v1);
    vecStr v_low; to_lower(v_low, v);
    VecLong order(v.size());
    sort(v_low, order); // case insensitive sorting
    reorder(v, order);
    reorder(v1, order);
}

inline void sort_case_insens(vecStr_IO v, vecLlong_IO v1)
{
    sort(v, v1);
    vecStr v_low; to_lower(v_low, v);
    VecLong order(v.size());
    sort(v_low, order); // case insensitive sorting
    reorder(v, order);
    reorder(v1, order);
}


// swap medium to `a`
template <class T>
void quicksort_3mid(T &a, T &b, T &c) {
    if (a < c) {
        if (b < a) ;
        else if (b > c) swap(a, c);
        else swap(a, b);
    }
    else {
        if (b < c) swap(a, c);
        else if (b > a) ;
        else swap(a, b);
    }
}

// do the same swap for a1, b1, c1
template <class T>
void quicksort_3mid(T &a, T &b, T &c, T &a1, T &b1, T &c1) {
    if (a < c) {
        if (b < a) ;
        else if (b > c) swap(a, c), swap(a1, c1);
        else swap(a, b), swap(a1, b1);
    }
    else {
        if (b < c) swap(a, c), swap(a1, c1);
        else if (b > a) ;
        else swap(a, b), swap(a1, b1);
    }
}

// quick sort (medium of 3 pivot)
template <class T>
void quicksort3(T *v, Long N)
{
	if (N <= 1) return;
    if (N == 2) {
        if (v[0] > v[1]) swap(v[0], v[1]);
        return;
    }
    quicksort_3mid(v[0], v[N/2], v[N-1]); // medium of 3 pivot
    T pivot = v[0];
    Long i = 1, j = N-1;
    while (1) {
        while (i < N && v[i] <= pivot) ++i;
        while (v[j] > pivot) --j;
        if (j <= i || i == N || j < 1)
			break;
		swap(v[i], v[j]);
    }
    swap(v[0], v[i-1]);
    quicksort3(v, i-1);
	quicksort3(v+i, N-i);
}

// also do the same change for v1
template <class T, class T1>
inline void quicksort3(T *v, T1 *v1, Long N)
{
    if (N <= 1) return;
    if (N == 2) {
        if (v[0] > v[1])
            swap(v[0], v[1]), swap(v1[0], v1[1]);
        return;
    }
    quicksort_3mid(v[0], v[N/2], v[N-1], v1[0], v1[N/2], v1[N-1]); // medium of 3 pivot
    T pivot = v[0];
    Long i = 1, j = N-1;
    while (1) {
        while (i < N && v[i] <= pivot) ++i;
        while (v[j] > pivot) --j;
        if (j <= i || i == N || j < 1)
            break;
        swap(v[i], v[j]); swap(v1[i], v1[j]);
    }
    swap(v[0], v[i-1]); swap(v1[0], v1[i-1]);
    quicksort3(v, v1, i-1);
    quicksort3(v+i, v1+i, N-i);
}

// quick sort (1st elm pivot)
template <class T>
void quicksort0(T *v, Long N)
{
	if (N <= 1) return;
	swap(v[0], v[N/2]); // 1st elm pivot
    T pivot = v[0];
    Long i = 1, j = N-1;
    while (1) {
        while (i < N && v[i] <= pivot) ++i;
        while (v[j] > pivot) --j;
        if (j <= i || i == N || j < 1)
			break;
		swap(v[i], v[j]);
    }
    swap(v[0], v[i-1]);
    quicksort0(v, i-1);
	quicksort0(v+i, N-i);
}

// also do the same change for v1
template <class T, class T1>
void quicksort0(T *v, T1 *v1, Long N)
{
    if (N <= 1) return;
    swap(v[0], v[N/2]); swap(v1[0], v1[N/2]); // 1st elm pivot
    T pivot = v[0];
    Long i = 1, j = N-1;
    while (1) {
        while (i < N && v[i] <= pivot) ++i;
        while (v[j] > pivot) --j;
        if (j <= i || i == N || j < 1)
            break;
        swap(v[i], v[j]); swap(v1[i], v1[j]);
    }
    swap(v[0], v[i-1]); swap(v1[0], v1[i-1]);
    quicksort0(v, v1, i-1);
    quicksort0(v+i, v1+i, N-i);
}

// merge sort
// wsp (work space) requires length (N+1)/2
template <class T>
void mergesort(T *v, Long N, T *wsp)
{
    if (N == 1) return;
    Long N1 = N/2, Tsize = sizeof(*v);
    mergesort(v, N1, wsp);
    mergesort(v+N1, N-N1, wsp);
    memcpy(wsp, v, Tsize*N1);
    Long i = 0, j = N1, ind = 0;
    while (i < N1 && j < N) {
        T e = wsp[i], e1 = v[j];
        if (e < e1) {
            v[ind++] = e; ++i;
        }
        else {
            v[ind++] = e1; ++j;
        }
    }
    if (i != N1)
        memcpy(v+ind, wsp+i, Tsize*(N1-i));
}

} // namespace slisc
