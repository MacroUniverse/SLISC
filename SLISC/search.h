#pragma once
#include "arithmetic.h"
#include "slice_arith.h"
#include "string.h"

namespace slisc {

// see if elm == vec[i], return i
// return -1 if not found
inline Long search(Int_I s, VecInt_I v, Long_I start = 0)
{
    Long N = v.size();
    for (Long i = start; i < N; ++i) {
        if (s == v[i])
            return i;
    }
    return -1;
}

inline Long search(Llong_I s, VecLlong_I v, Long_I start = 0)
{
    Long N = v.size();
    for (Long i = start; i < N; ++i) {
        if (s == v[i])
            return i;
    }
    return -1;
}

inline Long search(Char_I s, Str_I v, Long_I start = 0)
{
    Long N = v.size();
    for (Long i = start; i < N; ++i) {
        if (s == v[i])
            return i;
    }
    return -1;
}

inline Long search(Char32_I s, Str32_I v, Long_I start = 0)
{
    Long N = v.size();
    for (Long i = start; i < N; ++i) {
        if (s == v[i])
            return i;
    }
    return -1;
}

inline Long search(Str_I s, vecStr_I v, Long_I start = 0)
{
    Long N = v.size();
    for (Long i = start; i < N; ++i) {
        if (s == v[i])
            return i;
    }
    return -1;
}

inline Long search(Str32_I s, vecStr32_I v, Long_I start = 0)
{
    Long N = v.size();
    for (Long i = start; i < N; ++i) {
        if (s == v[i])
            return i;
    }
    return -1;
}

inline Long search(Llong_I s, vecLlong_I v, Long_I start = 0)
{
    Long N = v.size();
    for (Long i = start; i < N; ++i) {
        if (s == v[i])
            return i;
    }
    return -1;
}


// see if `match_head(s, v[i])`, return i
// see if `match_head(v[i], s)`, return i
// return -1 if not found
inline Long search_head(Str_I s_short, vecStr_I v_long, Long_I start = 0)
{
    Long N = v_long.size();
    for (Long i = start; i < N; ++i) {
        if (match_head(s_short, v_long[i]))
            return i;
    }
    return -1;
}

inline Long search_head(vecStr_I v_short, Str_I s_long, Long_I start = 0)
{
    Long N = v_short.size();
    for (Long i = start; i < N; ++i) {
        if (match_head(v_short[i], s_long))
            return i;
    }
    return -1;
}

inline Long search_head(Str32_I s_short, vecStr32_I v_long, Long_I start = 0)
{
    Long N = v_long.size();
    for (Long i = start; i < N; ++i) {
        if (match_head(s_short, v_long[i]))
            return i;
    }
    return -1;
}

inline Long search_head(vecStr32_I v_short, Str32_I s_long, Long_I start = 0)
{
    Long N = v_short.size();
    for (Long i = start; i < N; ++i) {
        if (match_head(v_short[i], s_long))
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
#ifdef SLS_CHECK_SHAPES
    if (N < 1)
        SLS_ERR("empty container!");
#endif
    Int diff = s - v[0];
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
        Int diff = v[ind] - s;
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
#ifdef SLS_CHECK_SHAPES
    Long N = ind2 - ind1 + 1;
    if (N < 1)
        SLS_ERR("range error!");
#endif
    Int diff = s - v[0];
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
        Int diff = v[ind] - s;
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
#ifdef SLS_CHECK_SHAPES
    if (N < 1)
        SLS_ERR("empty container!");
#endif
    Llong diff = s - v[0];
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
        Llong diff = v[ind] - s;
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
#ifdef SLS_CHECK_SHAPES
    Long N = ind2 - ind1 + 1;
    if (N < 1)
        SLS_ERR("range error!");
#endif
    Llong diff = s - v[0];
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
        Llong diff = v[ind] - s;
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
#ifdef SLS_CHECK_SHAPES
    if (N < 1)
        SLS_ERR("empty container!");
#endif
    Doub diff = s - v[0];
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
        Doub diff = v[ind] - s;
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
#ifdef SLS_CHECK_SHAPES
    Long N = ind2 - ind1 + 1;
    if (N < 1)
        SLS_ERR("range error!");
#endif
    Doub diff = s - v[0];
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
        Doub diff = v[ind] - s;
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
#ifdef SLS_CHECK_SHAPES
    if (N < 1)
        SLS_ERR("empty container!");
#endif
    Int diff = s - v[0];
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
        Int diff = v[ind] - s;
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
#ifdef SLS_CHECK_SHAPES
    Long N = ind2 - ind1 + 1;
    if (N < 1)
        SLS_ERR("range error!");
#endif
    Int diff = s - v[0];
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
        Int diff = v[ind] - s;
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
#ifdef SLS_CHECK_SHAPES
    if (N < 1)
        SLS_ERR("empty container!");
#endif
    Llong diff = s - v[0];
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
        Llong diff = v[ind] - s;
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
#ifdef SLS_CHECK_SHAPES
    Long N = ind2 - ind1 + 1;
    if (N < 1)
        SLS_ERR("range error!");
#endif
    Llong diff = s - v[0];
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
        Llong diff = v[ind] - s;
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


// check if v[i] == v[j] for any i and j > i
// return i >= start
// return -1 if no reapeat
inline Long find_repeat(vecStr_I v, Long_I start = 0)
{
    Long N = v.size();
    for (Long i = start; i < N; ++i) {
        for (Long j = i + 1; j < N; ++j) {
            if (v[i] == v[j])
                return i;
        }
    }
    return -1;
}

inline Long find_repeat(Long_O j, vecStr_I v, Long_I start = 0)
{
    Long N = v.size();
    for (Long i = start; i < N; ++i) {
        for (j = i + 1; j < N; ++j) {
            if (v[i] == v[j])
                return i;
        }
    }
    return -1;
}

inline Long find_repeat(vecStr32_I v, Long_I start = 0)
{
    Long N = v.size();
    for (Long i = start; i < N; ++i) {
        for (Long j = i + 1; j < N; ++j) {
            if (v[i] == v[j])
                return i;
        }
    }
    return -1;
}

inline Long find_repeat(Long_O j, vecStr32_I v, Long_I start = 0)
{
    Long N = v.size();
    for (Long i = start; i < N; ++i) {
        for (j = i + 1; j < N; ++j) {
            if (v[i] == v[j])
                return i;
        }
    }
    return -1;
}

inline Long find_repeat(VecChar_I v, Long_I start = 0)
{
    Long N = v.size();
    for (Long i = start; i < N; ++i) {
        for (Long j = i + 1; j < N; ++j) {
            if (v[i] == v[j])
                return i;
        }
    }
    return -1;
}

inline Long find_repeat(Long_O j, VecChar_I v, Long_I start = 0)
{
    Long N = v.size();
    for (Long i = start; i < N; ++i) {
        for (j = i + 1; j < N; ++j) {
            if (v[i] == v[j])
                return i;
        }
    }
    return -1;
}

inline Long find_repeat(VecInt_I v, Long_I start = 0)
{
    Long N = v.size();
    for (Long i = start; i < N; ++i) {
        for (Long j = i + 1; j < N; ++j) {
            if (v[i] == v[j])
                return i;
        }
    }
    return -1;
}

inline Long find_repeat(Long_O j, VecInt_I v, Long_I start = 0)
{
    Long N = v.size();
    for (Long i = start; i < N; ++i) {
        for (j = i + 1; j < N; ++j) {
            if (v[i] == v[j])
                return i;
        }
    }
    return -1;
}

inline Long find_repeat(VecLlong_I v, Long_I start = 0)
{
    Long N = v.size();
    for (Long i = start; i < N; ++i) {
        for (Long j = i + 1; j < N; ++j) {
            if (v[i] == v[j])
                return i;
        }
    }
    return -1;
}

inline Long find_repeat(Long_O j, VecLlong_I v, Long_I start = 0)
{
    Long N = v.size();
    for (Long i = start; i < N; ++i) {
        for (j = i + 1; j < N; ++j) {
            if (v[i] == v[j])
                return i;
        }
    }
    return -1;
}

inline Long find_repeat(vecLlong_I v, Long_I start = 0)
{
    Long N = v.size();
    for (Long i = start; i < N; ++i) {
        for (Long j = i + 1; j < N; ++j) {
            if (v[i] == v[j])
                return i;
        }
    }
    return -1;
}

inline Long find_repeat(Long_O j, vecLlong_I v, Long_I start = 0)
{
    Long N = v.size();
    for (Long i = start; i < N; ++i) {
        for (j = i + 1; j < N; ++j) {
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
#ifdef SLS_CHECK_SHAPES
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
#ifdef SLS_CHECK_SHAPES
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
#ifdef SLS_CHECK_SHAPES
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
#ifdef SLS_CHECK_SHAPES
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
