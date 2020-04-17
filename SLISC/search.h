#pragma once
#include "arithmetic.h"
#include "slice_arith.h"

namespace slisc {

// see if elm == vec[i], return i
// return -1 if not found
inline Long search(Int_I s, VecInt_I v, Long start = 0)
{
    Long N = size(v);
    for (Long i = start; i < N; ++i) {
        if (s == v[i])
            return i;
    }
    return -1;
}

inline Long search(Llong_I s, VecLlong_I v, Long start = 0)
{
    Long N = size(v);
    for (Long i = start; i < N; ++i) {
        if (s == v[i])
            return i;
    }
    return -1;
}

inline Long search(Char_I s, Str_I v, Long start = 0)
{
    Long N = size(v);
    for (Long i = start; i < N; ++i) {
        if (s == v[i])
            return i;
    }
    return -1;
}

inline Long search(Char32_I s, Str32_I v, Long start = 0)
{
    Long N = size(v);
    for (Long i = start; i < N; ++i) {
        if (s == v[i])
            return i;
    }
    return -1;
}

inline Long search(Str_I s, vecStr_I v, Long start = 0)
{
    Long N = size(v);
    for (Long i = start; i < N; ++i) {
        if (s == v[i])
            return i;
    }
    return -1;
}

inline Long search(Str32_I s, vecStr32_I v, Long start = 0)
{
    Long N = size(v);
    for (Long i = start; i < N; ++i) {
        if (s == v[i])
            return i;
    }
    return -1;
}

inline Long search(Llong_I s, vecLlong_I v, Long start = 0)
{
    Long N = size(v);
    for (Long i = start; i < N; ++i) {
        if (s == v[i])
            return i;
    }
    return -1;
}


// return true, output ind: if v[ind] == s, else return false
// v is in ascending order
// if s < v[0], ind = -1;
// if s > v[N-1], ind = N-1;
// else, v[ind] < s < v[ind+1];
// algorithm: bisection
inline Bool lookup(Long_O ind, VecInt_I v, Int_I s)
{
    Long N = v.size(), ind1 = 0, ind2 = N - 1;
#ifdef SLS_CHECK_SHAPE
    if (N < 1)
        SLS_ERR("empty container!");
#endif
    Long diff = s - v[0];
    if (diff < 0) {
        ind = -1; return false;
    }
    else if (diff == 0) {
        ind = 0; return true;
    }
    diff = v[ind2] - s;
    if (diff < 0) {
        ind = N - 1; return false;
    }
    if (diff == 0) {
        ind = ind2; return true;
    }
    while (true) {
        ind = (ind1 + ind2) / 2;
        Long diff = v[ind] - s;
        if (diff > 0)
            ind2 = ind;
        else if (diff < 0)
            ind1 = ind;
        else
            return true;
        if (ind2 - ind1 == 1) {
            ind = ind1; return false;
        }
    }
}

inline Bool lookup(Long_O ind, VecInt_I v, Int_I s, Long ind1, Long ind2)
{
#ifdef SLS_CHECK_SHAPE
    Long N = ind2 - ind1 + 1;
    if (N < 1)
        SLS_ERR("range error!");
#endif
    Long diff = s - v[0];
    if (diff < 0) {
        ind = -1; return false;
    }
    if (diff == 0) {
        ind = 0; return true;
    }
    diff = v[ind2] - s;
    if (diff < 0) {
        ind = ind2; return false;
    }
    if (diff == 0) {
        ind = ind2; return true;
    }
    while (true) {
        ind = (ind1 + ind2) / 2;
        Long diff = v[ind] - s;
        if (diff > 0)
            ind2 = ind;
        else if (diff < 0)
            ind1 = ind;
        else
            return true;
        if (ind2 - ind1 == 1) {
            ind = ind1; return false;
        }
    }
}

inline Bool lookup(Long_O ind, VecLlong_I v, Llong_I s)
{
    Long N = v.size(), ind1 = 0, ind2 = N - 1;
#ifdef SLS_CHECK_SHAPE
    if (N < 1)
        SLS_ERR("empty container!");
#endif
    Long diff = s - v[0];
    if (diff < 0) {
        ind = -1; return false;
    }
    else if (diff == 0) {
        ind = 0; return true;
    }
    diff = v[ind2] - s;
    if (diff < 0) {
        ind = N - 1; return false;
    }
    if (diff == 0) {
        ind = ind2; return true;
    }
    while (true) {
        ind = (ind1 + ind2) / 2;
        Long diff = v[ind] - s;
        if (diff > 0)
            ind2 = ind;
        else if (diff < 0)
            ind1 = ind;
        else
            return true;
        if (ind2 - ind1 == 1) {
            ind = ind1; return false;
        }
    }
}

inline Bool lookup(Long_O ind, VecLlong_I v, Llong_I s, Long ind1, Long ind2)
{
#ifdef SLS_CHECK_SHAPE
    Long N = ind2 - ind1 + 1;
    if (N < 1)
        SLS_ERR("range error!");
#endif
    Long diff = s - v[0];
    if (diff < 0) {
        ind = -1; return false;
    }
    if (diff == 0) {
        ind = 0; return true;
    }
    diff = v[ind2] - s;
    if (diff < 0) {
        ind = ind2; return false;
    }
    if (diff == 0) {
        ind = ind2; return true;
    }
    while (true) {
        ind = (ind1 + ind2) / 2;
        Long diff = v[ind] - s;
        if (diff > 0)
            ind2 = ind;
        else if (diff < 0)
            ind1 = ind;
        else
            return true;
        if (ind2 - ind1 == 1) {
            ind = ind1; return false;
        }
    }
}

inline Bool lookup(Long_O ind, VecDoub_I v, Doub_I s)
{
    Long N = v.size(), ind1 = 0, ind2 = N - 1;
#ifdef SLS_CHECK_SHAPE
    if (N < 1)
        SLS_ERR("empty container!");
#endif
    Long diff = s - v[0];
    if (diff < 0) {
        ind = -1; return false;
    }
    else if (diff == 0) {
        ind = 0; return true;
    }
    diff = v[ind2] - s;
    if (diff < 0) {
        ind = N - 1; return false;
    }
    if (diff == 0) {
        ind = ind2; return true;
    }
    while (true) {
        ind = (ind1 + ind2) / 2;
        Long diff = v[ind] - s;
        if (diff > 0)
            ind2 = ind;
        else if (diff < 0)
            ind1 = ind;
        else
            return true;
        if (ind2 - ind1 == 1) {
            ind = ind1; return false;
        }
    }
}

inline Bool lookup(Long_O ind, VecDoub_I v, Doub_I s, Long ind1, Long ind2)
{
#ifdef SLS_CHECK_SHAPE
    Long N = ind2 - ind1 + 1;
    if (N < 1)
        SLS_ERR("range error!");
#endif
    Long diff = s - v[0];
    if (diff < 0) {
        ind = -1; return false;
    }
    if (diff == 0) {
        ind = 0; return true;
    }
    diff = v[ind2] - s;
    if (diff < 0) {
        ind = ind2; return false;
    }
    if (diff == 0) {
        ind = ind2; return true;
    }
    while (true) {
        ind = (ind1 + ind2) / 2;
        Long diff = v[ind] - s;
        if (diff > 0)
            ind2 = ind;
        else if (diff < 0)
            ind1 = ind;
        else
            return true;
        if (ind2 - ind1 == 1) {
            ind = ind1; return false;
        }
    }
}

inline Bool lookup(Long_O ind, vecInt_I v, Int_I s)
{
    Long N = v.size(), ind1 = 0, ind2 = N - 1;
#ifdef SLS_CHECK_SHAPE
    if (N < 1)
        SLS_ERR("empty container!");
#endif
    Long diff = s - v[0];
    if (diff < 0) {
        ind = -1; return false;
    }
    else if (diff == 0) {
        ind = 0; return true;
    }
    diff = v[ind2] - s;
    if (diff < 0) {
        ind = N - 1; return false;
    }
    if (diff == 0) {
        ind = ind2; return true;
    }
    while (true) {
        ind = (ind1 + ind2) / 2;
        Long diff = v[ind] - s;
        if (diff > 0)
            ind2 = ind;
        else if (diff < 0)
            ind1 = ind;
        else
            return true;
        if (ind2 - ind1 == 1) {
            ind = ind1; return false;
        }
    }
}

inline Bool lookup(Long_O ind, vecInt_I v, Int_I s, Long ind1, Long ind2)
{
#ifdef SLS_CHECK_SHAPE
    Long N = ind2 - ind1 + 1;
    if (N < 1)
        SLS_ERR("range error!");
#endif
    Long diff = s - v[0];
    if (diff < 0) {
        ind = -1; return false;
    }
    if (diff == 0) {
        ind = 0; return true;
    }
    diff = v[ind2] - s;
    if (diff < 0) {
        ind = ind2; return false;
    }
    if (diff == 0) {
        ind = ind2; return true;
    }
    while (true) {
        ind = (ind1 + ind2) / 2;
        Long diff = v[ind] - s;
        if (diff > 0)
            ind2 = ind;
        else if (diff < 0)
            ind1 = ind;
        else
            return true;
        if (ind2 - ind1 == 1) {
            ind = ind1; return false;
        }
    }
}

inline Bool lookup(Long_O ind, vecLlong_I v, Llong_I s)
{
    Long N = v.size(), ind1 = 0, ind2 = N - 1;
#ifdef SLS_CHECK_SHAPE
    if (N < 1)
        SLS_ERR("empty container!");
#endif
    Long diff = s - v[0];
    if (diff < 0) {
        ind = -1; return false;
    }
    else if (diff == 0) {
        ind = 0; return true;
    }
    diff = v[ind2] - s;
    if (diff < 0) {
        ind = N - 1; return false;
    }
    if (diff == 0) {
        ind = ind2; return true;
    }
    while (true) {
        ind = (ind1 + ind2) / 2;
        Long diff = v[ind] - s;
        if (diff > 0)
            ind2 = ind;
        else if (diff < 0)
            ind1 = ind;
        else
            return true;
        if (ind2 - ind1 == 1) {
            ind = ind1; return false;
        }
    }
}

inline Bool lookup(Long_O ind, vecLlong_I v, Llong_I s, Long ind1, Long ind2)
{
#ifdef SLS_CHECK_SHAPE
    Long N = ind2 - ind1 + 1;
    if (N < 1)
        SLS_ERR("range error!");
#endif
    Long diff = s - v[0];
    if (diff < 0) {
        ind = -1; return false;
    }
    if (diff == 0) {
        ind = 0; return true;
    }
    diff = v[ind2] - s;
    if (diff < 0) {
        ind = ind2; return false;
    }
    if (diff == 0) {
        ind = ind2; return true;
    }
    while (true) {
        ind = (ind1 + ind2) / 2;
        Long diff = v[ind] - s;
        if (diff > 0)
            ind2 = ind;
        else if (diff < 0)
            ind1 = ind;
        else
            return true;
        if (ind2 - ind1 == 1) {
            ind = ind1; return false;
        }
    }
}


// check if v[i] == v[j] for any i and j
// return the index of one of the repeated elements
// return -1 if no reapeat
inline Long find_repeat(vecStr_I v)
{
    Long N = size(v);
    for (Long i = 0; i < N; ++i) {
        for (Long j = i + 1; j < N; ++j) {
            if (v[i] == v[j])
                return i;
        }
    }
    return -1;
}

inline Long find_repeat(vecStr32_I v)
{
    Long N = size(v);
    for (Long i = 0; i < N; ++i) {
        for (Long j = i + 1; j < N; ++j) {
            if (v[i] == v[j])
                return i;
        }
    }
    return -1;
}

inline Long find_repeat(VecChar_I v)
{
    Long N = size(v);
    for (Long i = 0; i < N; ++i) {
        for (Long j = i + 1; j < N; ++j) {
            if (v[i] == v[j])
                return i;
        }
    }
    return -1;
}

inline Long find_repeat(VecInt_I v)
{
    Long N = size(v);
    for (Long i = 0; i < N; ++i) {
        for (Long j = i + 1; j < N; ++j) {
            if (v[i] == v[j])
                return i;
        }
    }
    return -1;
}

inline Long find_repeat(VecLlong_I v)
{
    Long N = size(v);
    for (Long i = 0; i < N; ++i) {
        for (Long j = i + 1; j < N; ++j) {
            if (v[i] == v[j])
                return i;
        }
    }
    return -1;
}

inline Long find_repeat(vecLlong_I v)
{
    Long N = size(v);
    for (Long i = 0; i < N; ++i) {
        for (Long j = i + 1; j < N; ++j) {
            if (v[i] == v[j])
                return i;
        }
    }
    return -1;
}


// search a row from a matrix
// starting from the row `start`
// return the row index, return -1 if not found
inline Long search_row(VecInt_I v, CmatInt_I a, Long_I start = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (v.size() != a.n2())
        SLS_ERR("wrong shape");
#endif
    for (Long i = start; i < a.n1(); ++i) {
        if (v == slice2(a, i))
            return i;
    }
    return -1;
}

inline Long search_row(VecLlong_I v, CmatLlong_I a, Long_I start = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (v.size() != a.n2())
        SLS_ERR("wrong shape");
#endif
    for (Long i = start; i < a.n1(); ++i) {
        if (v == slice2(a, i))
            return i;
    }
    return -1;
}

inline Long search_row(DvecLlong_I v, CmatLlong_I a, Long_I start = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (v.size() != a.n2())
        SLS_ERR("wrong shape");
#endif
    for (Long i = start; i < a.n1(); ++i) {
        if (v == slice2(a, i))
            return i;
    }
    return -1;
}

inline Long search_row(VecDoub_I v, CmatDoub_I a, Long_I start = 0)
{
#ifdef SLS_CHECK_SHAPE
    if (v.size() != a.n2())
        SLS_ERR("wrong shape");
#endif
    for (Long i = start; i < a.n1(); ++i) {
        if (v == slice2(a, i))
            return i;
    }
    return -1;
}

} // namespace slisc
