#pragma once
#include "../arith/arith1.h"
#include "../arith/arith2.h"
#include "../arith/arith4.h"
#include "../arith/reorder.h"
#include "../arith/copy.h"
#include "../lin/mul.h"
#include "../dense/cut.h"

namespace slisc {

// concatinate std::vector
inline void cat(vecInt_IO v, vecInt_I v1)
{ v.insert(v.end(), v1.begin(), v1.end()); }

inline void cat(vecLlong_IO v, vecLlong_I v1)
{ v.insert(v.end(), v1.begin(), v1.end()); }

inline void cat(vecStr_IO v, vecStr_I v1)
{ v.insert(v.end(), v1.begin(), v1.end()); }

inline void cat(vecStr32_IO v, vecStr32_I v1)
{ v.insert(v.end(), v1.begin(), v1.end()); }


// get unique elements from a vector
template <class T>
inline void uniq_elm(vector<T> &v)
{
	Long N = v.size(), n = 0;
	for (Long i = 0; i < N; ++i) {
	    Bool repeat = false;
	    for (Long j = 0; j < n; ++j) {
	        if (v[i] == v[j]) {
	            repeat = true; break;
	        }
	    }
	    if (!repeat) {
	        v[n] = v[i];
	        ++n;
	    }
	}
	v.resize(n);
}

// get all unique rows from a matrix
inline void uniq_rows(CmatInt_O a, CmatInt_I a1)
{
	Long k = 0;
	a.resize(a1.n0(), a1.n1());
	for (Long i = 0; i < a1.n0(); ++i) {
	    // check repeat
	    Bool repeat = false;
	    DvecInt_c s1 = cut1(a1, i);
	    for (Long j = 0; j < k; ++j) {
	        if (cut1(a, j) == s1) {
	            repeat = true; break;
	        }
	    }
	    if (repeat)
	        continue;
	    copy(cut1(a, k), s1);
	    ++k;
	}
	resize_cpy(a, k, a1.n1());
}

inline void uniq_rows(CmatLlong_O a, CmatLlong_I a1)
{
	Long k = 0;
	a.resize(a1.n0(), a1.n1());
	for (Long i = 0; i < a1.n0(); ++i) {
	    // check repeat
	    Bool repeat = false;
	    DvecLlong_c s1 = cut1(a1, i);
	    for (Long j = 0; j < k; ++j) {
	        if (cut1(a, j) == s1) {
	            repeat = true; break;
	        }
	    }
	    if (repeat)
	        continue;
	    copy(cut1(a, k), s1);
	    ++k;
	}
	resize_cpy(a, k, a1.n1());
}

inline void uniq_rows(CmatLlong_O a, ScmatLlong_I a1)
{
	Long k = 0;
	a.resize(a1.n0(), a1.n1());
	for (Long i = 0; i < a1.n0(); ++i) {
	    // check repeat
	    Bool repeat = false;
	    DvecLlong_c s1 = cut1(a1, i);
	    for (Long j = 0; j < k; ++j) {
	        if (cut1(a, j) == s1) {
	            repeat = true; break;
	        }
	    }
	    if (repeat)
	        continue;
	    copy(cut1(a, k), s1);
	    ++k;
	}
	resize_cpy(a, k, a1.n1());
}

inline void uniq_rows(CmatDoub_O a, CmatDoub_I a1)
{
	Long k = 0;
	a.resize(a1.n0(), a1.n1());
	for (Long i = 0; i < a1.n0(); ++i) {
	    // check repeat
	    Bool repeat = false;
	    DvecDoub_c s1 = cut1(a1, i);
	    for (Long j = 0; j < k; ++j) {
	        if (cut1(a, j) == s1) {
	            repeat = true; break;
	        }
	    }
	    if (repeat)
	        continue;
	    copy(cut1(a, k), s1);
	    ++k;
	}
	resize_cpy(a, k, a1.n1());
}



} // namespace slisc
