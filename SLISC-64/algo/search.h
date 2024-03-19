#pragma once
#include "../arith/arith1.h"
#include "../dense/cut.h"
#include "../str/str.h"

namespace slisc {

// return `i` for first `s == v[i]`, starting from `start`
// return -1 if not found
template <class T>
inline Long search(const T &s, const T *v, Long_I N, Long_I start = 0)
{
	for (Long i = start; i < N; ++i)
		if (s == v[i])
			return i;
	return -1;
}

// for complex classes
template <class T>
inline Long search(const T &s, const vector<T> &v, Long_I start = 0)
{ return search(s, v.data(), size(v), start); }

// see if elm == vec[i], return i
// return -1 if not found
inline Long search(Int_I s, SvecInt_I v, Long_I start = 0)
{
	Long N = v.size();
	for (Long i = start; i < N; ++i) {
		if (s == v[i])
			return i;
	}
	return -1;
}

inline Long search(Int_I s, vecInt_I v, Long_I start = 0)
{
	Long N = v.size();
	for (Long i = start; i < N; ++i) {
		if (s == v[i])
			return i;
	}
	return -1;
}

inline Long search(Llong_I s, SvecLlong_I v, Long_I start = 0)
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


// return true, output ind: if v[ind] == s, else return false
// v must be ascending order (v[i] <= v[i+1])
// if s < v[0], ind = -1;
// if s > v[N-1], ind = N-1;
// else, v[ind] < s < v[ind+1];
// algorithm: bisection
inline bool lookup(Long_O ind, SvecInt_I v, Int_I s)
{
	Long N = v.size(), ind1 = 0, ind2 = N - 1;
#ifdef SLS_CHECK_SHAPES
	if (N < 1) SLS_ERR("empty container!");
#endif
	if (s < v[0]) { ind = -1; return false; }
	if (s == v[0]) { ind = 0; return true; }
	if (v[ind2] < s) { ind = N - 1; return false; }
	if (s == v[ind2]) { ind = ind2; return true; }
	while (1) { // N >= 2 from here
		if (ind2 - ind1 == 1) { ind = ind1; return false; }
		ind = (ind1 + ind2) / 2;
		if (s < v[ind]) ind2 = ind;
		else if (v[ind] < s) ind1 = ind;
		else return true;
	}
}

inline bool lookup(Long_O ind, SvecInt_I v, Int_I s, Long ind1, Long ind2)
{
#ifdef SLS_CHECK_SHAPES
	Long N = ind2 - ind1 + 1;
	if (N < 1) SLS_ERR("range error!");
#endif
	if (s < v[0]) { ind = -1; return false; }
	if (s == v[0]) { ind = 0; return true; }
	if (v[ind2] < s) { ind = ind2; return false; }
	if (s == v[ind2]) { ind = ind2; return true; }
	while (1) { // N >= 2 from here
		if (ind2 - ind1 == 1) { ind = ind1; return false; }
		ind = (ind1 + ind2) / 2;
		if (s < v[ind]) ind2 = ind;
		else if (v[ind] < s) ind1 = ind;
		else return true;
	}
}

inline bool lookup(Long_O ind, SvecLlong_I v, Llong_I s)
{
	Long N = v.size(), ind1 = 0, ind2 = N - 1;
#ifdef SLS_CHECK_SHAPES
	if (N < 1) SLS_ERR("empty container!");
#endif
	if (s < v[0]) { ind = -1; return false; }
	if (s == v[0]) { ind = 0; return true; }
	if (v[ind2] < s) { ind = N - 1; return false; }
	if (s == v[ind2]) { ind = ind2; return true; }
	while (1) { // N >= 2 from here
		if (ind2 - ind1 == 1) { ind = ind1; return false; }
		ind = (ind1 + ind2) / 2;
		if (s < v[ind]) ind2 = ind;
		else if (v[ind] < s) ind1 = ind;
		else return true;
	}
}

inline bool lookup(Long_O ind, SvecLlong_I v, Llong_I s, Long ind1, Long ind2)
{
#ifdef SLS_CHECK_SHAPES
	Long N = ind2 - ind1 + 1;
	if (N < 1) SLS_ERR("range error!");
#endif
	if (s < v[0]) { ind = -1; return false; }
	if (s == v[0]) { ind = 0; return true; }
	if (v[ind2] < s) { ind = ind2; return false; }
	if (s == v[ind2]) { ind = ind2; return true; }
	while (1) { // N >= 2 from here
		if (ind2 - ind1 == 1) { ind = ind1; return false; }
		ind = (ind1 + ind2) / 2;
		if (s < v[ind]) ind2 = ind;
		else if (v[ind] < s) ind1 = ind;
		else return true;
	}
}

inline bool lookup(Long_O ind, SvecDoub_I v, Doub_I s)
{
	Long N = v.size(), ind1 = 0, ind2 = N - 1;
#ifdef SLS_CHECK_SHAPES
	if (N < 1) SLS_ERR("empty container!");
#endif
	if (s < v[0]) { ind = -1; return false; }
	if (s == v[0]) { ind = 0; return true; }
	if (v[ind2] < s) { ind = N - 1; return false; }
	if (s == v[ind2]) { ind = ind2; return true; }
	while (1) { // N >= 2 from here
		if (ind2 - ind1 == 1) { ind = ind1; return false; }
		ind = (ind1 + ind2) / 2;
		if (s < v[ind]) ind2 = ind;
		else if (v[ind] < s) ind1 = ind;
		else return true;
	}
}

inline bool lookup(Long_O ind, SvecDoub_I v, Doub_I s, Long ind1, Long ind2)
{
#ifdef SLS_CHECK_SHAPES
	Long N = ind2 - ind1 + 1;
	if (N < 1) SLS_ERR("range error!");
#endif
	if (s < v[0]) { ind = -1; return false; }
	if (s == v[0]) { ind = 0; return true; }
	if (v[ind2] < s) { ind = ind2; return false; }
	if (s == v[ind2]) { ind = ind2; return true; }
	while (1) { // N >= 2 from here
		if (ind2 - ind1 == 1) { ind = ind1; return false; }
		ind = (ind1 + ind2) / 2;
		if (s < v[ind]) ind2 = ind;
		else if (v[ind] < s) ind1 = ind;
		else return true;
	}
}


inline bool lookup(Long_O ind, vecInt_I v, Int_I s)
{
	Long N = v.size(), ind1 = 0, ind2 = N - 1;
#ifdef SLS_CHECK_SHAPES
	if (N < 1) SLS_ERR("empty container!");
#endif
	if (s < v[0]) { ind = -1; return false; }
	if (s == v[0]) { ind = 0; return true; }
	if (v[ind2] < s) { ind = N - 1; return false; }
	if (s == v[ind2]) { ind = ind2; return true; }
	while (1) { // N >= 2 from here
		if (ind2 - ind1 == 1) { ind = ind1; return false; }
		ind = (ind1 + ind2) / 2;
		if (s < v[ind]) ind2 = ind;
		else if (v[ind] < s) ind1 = ind;
		else return true;
	}
}

inline bool lookup(Long_O ind, vecInt_I v, Int_I s, Long ind1, Long ind2)
{
#ifdef SLS_CHECK_SHAPES
	Long N = ind2 - ind1 + 1;
	if (N < 1) SLS_ERR("range error!");
#endif
	if (s < v[0]) { ind = -1; return false; }
	if (s == v[0]) { ind = 0; return true; }
	if (v[ind2] < s) { ind = ind2; return false; }
	if (s == v[ind2]) { ind = ind2; return true; }
	while (1) { // N >= 2 from here
		if (ind2 - ind1 == 1) { ind = ind1; return false; }
		ind = (ind1 + ind2) / 2;
		if (s < v[ind]) ind2 = ind;
		else if (v[ind] < s) ind1 = ind;
		else return true;
	}
}

inline bool lookup(Long_O ind, vecLlong_I v, Llong_I s)
{
	Long N = v.size(), ind1 = 0, ind2 = N - 1;
#ifdef SLS_CHECK_SHAPES
	if (N < 1) SLS_ERR("empty container!");
#endif
	if (s < v[0]) { ind = -1; return false; }
	if (s == v[0]) { ind = 0; return true; }
	if (v[ind2] < s) { ind = N - 1; return false; }
	if (s == v[ind2]) { ind = ind2; return true; }
	while (1) { // N >= 2 from here
		if (ind2 - ind1 == 1) { ind = ind1; return false; }
		ind = (ind1 + ind2) / 2;
		if (s < v[ind]) ind2 = ind;
		else if (v[ind] < s) ind1 = ind;
		else return true;
	}
}

inline bool lookup(Long_O ind, vecLlong_I v, Llong_I s, Long ind1, Long ind2)
{
#ifdef SLS_CHECK_SHAPES
	Long N = ind2 - ind1 + 1;
	if (N < 1) SLS_ERR("range error!");
#endif
	if (s < v[0]) { ind = -1; return false; }
	if (s == v[0]) { ind = 0; return true; }
	if (v[ind2] < s) { ind = ind2; return false; }
	if (s == v[ind2]) { ind = ind2; return true; }
	while (1) { // N >= 2 from here
		if (ind2 - ind1 == 1) { ind = ind1; return false; }
		ind = (ind1 + ind2) / 2;
		if (s < v[ind]) ind2 = ind;
		else if (v[ind] < s) ind1 = ind;
		else return true;
	}
}

inline bool lookup(Long_O ind, vecStr_I v, Str_I s)
{
	Long N = v.size(), ind1 = 0, ind2 = N - 1;
#ifdef SLS_CHECK_SHAPES
	if (N < 1) SLS_ERR("empty container!");
#endif
	if (s < v[0]) { ind = -1; return false; }
	if (s == v[0]) { ind = 0; return true; }
	if (v[ind2] < s) { ind = N - 1; return false; }
	if (s == v[ind2]) { ind = ind2; return true; }
	while (1) { // N >= 2 from here
		if (ind2 - ind1 == 1) { ind = ind1; return false; }
		ind = (ind1 + ind2) / 2;
		if (s < v[ind]) ind2 = ind;
		else if (v[ind] < s) ind1 = ind;
		else return true;
	}
}

inline bool lookup(Long_O ind, vecStr_I v, Str_I s, Long ind1, Long ind2)
{
#ifdef SLS_CHECK_SHAPES
	Long N = ind2 - ind1 + 1;
	if (N < 1) SLS_ERR("range error!");
#endif
	if (s < v[0]) { ind = -1; return false; }
	if (s == v[0]) { ind = 0; return true; }
	if (v[ind2] < s) { ind = ind2; return false; }
	if (s == v[ind2]) { ind = ind2; return true; }
	while (1) { // N >= 2 from here
		if (ind2 - ind1 == 1) { ind = ind1; return false; }
		ind = (ind1 + ind2) / 2;
		if (s < v[ind]) ind2 = ind;
		else if (v[ind] < s) ind1 = ind;
		else return true;
	}
}

inline bool lookup(Long_O ind, vecStr32_I v, Str32_I s)
{
	Long N = v.size(), ind1 = 0, ind2 = N - 1;
#ifdef SLS_CHECK_SHAPES
	if (N < 1) SLS_ERR("empty container!");
#endif
	if (s < v[0]) { ind = -1; return false; }
	if (s == v[0]) { ind = 0; return true; }
	if (v[ind2] < s) { ind = N - 1; return false; }
	if (s == v[ind2]) { ind = ind2; return true; }
	while (1) { // N >= 2 from here
		if (ind2 - ind1 == 1) { ind = ind1; return false; }
		ind = (ind1 + ind2) / 2;
		if (s < v[ind]) ind2 = ind;
		else if (v[ind] < s) ind1 = ind;
		else return true;
	}
}

inline bool lookup(Long_O ind, vecStr32_I v, Str32_I s, Long ind1, Long ind2)
{
#ifdef SLS_CHECK_SHAPES
	Long N = ind2 - ind1 + 1;
	if (N < 1) SLS_ERR("range error!");
#endif
	if (s < v[0]) { ind = -1; return false; }
	if (s == v[0]) { ind = 0; return true; }
	if (v[ind2] < s) { ind = ind2; return false; }
	if (s == v[ind2]) { ind = ind2; return true; }
	while (1) { // N >= 2 from here
		if (ind2 - ind1 == 1) { ind = ind1; return false; }
		ind = (ind1 + ind2) / 2;
		if (s < v[ind]) ind2 = ind;
		else if (v[ind] < s) ind1 = ind;
		else return true;
	}
}


// determin overlap region of 1D r grid
// the overlapping region must have the same values (within machine err)
// return the # of overlap values (including 0)
// x1[ind1:ind1+N-1] == x2[ind2:ind2+N-1]
// TODO: slow, should use bisection
inline Long grid_overlap(Long_O ind1, Long_O ind2, VecDoub_I x1, VecDoub_I x2)
{
	Doub tol = max(max(-x1[0], x1.end()),
					max(-x2[0], x2.end()))*1e-14;
	ind1 = ind2 = 0;
	// no overlap
	if (x2[0]-x1.end() > tol || x1[0]-x2.end() > tol)
		return 0;
	// determine ind1, ind2
	if (abs(x1[0] - x2[0]) < tol)
		;
	else if (x1[0] < x2[0]) {
		for (Long i = 1; i < x1.size(); ++i)
			if (abs(x1[i]-x2[0]) < tol)
				ind1 = i;
		if (ind1 == 0)
			SLS_ERR("grid_overlap(): grids incompatible (1)");
	}
	else { // x2[0] < x1[0]
		for (Long i = 0; i < x2.size(); ++i)
			if (abs(x2[i]-x1[0]) < tol)
				ind2 = i;
		if (ind2 == 0)
			SLS_ERR("grid_overlap(): grids incompatible (2)");
	}
	// # of overlapped grid
	Long N = min(x1.size()-ind1, x2.size()-ind2);
	for (Long i = 0; i < N; ++i)
		if (abs(x1[ind1+i]-x2[ind2+i]) > tol)
			SLS_ERR("grid_overlap(): grids incompatible (3)");
	return N;
}

// check if v[i] == v[j] for any i and j > i
// return i >= start
// return -1 if no reapeat
template <class T>
inline Long find_repeat(const T &v, Long_I start = 0)
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

// same, also output j
template <class T>
inline Long find_repeat(Long_O j, const T &v, Long_I start = 0)
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
inline Long search_row(SvecInt_I v, ScmatInt_I a, Long_I start = 0)
{
#ifdef SLS_CHECK_SHAPES
	if (v.size() != a.n1())
		SLS_ERR("wrong shape");
#endif
	for (Long i = start; i < a.n0(); ++i) {
		if (v == cut1(a, i))
			return i;
	}
	return -1;
}

inline Long search_row(SvecLlong_I v, ScmatLlong_I a, Long_I start = 0)
{
#ifdef SLS_CHECK_SHAPES
	if (v.size() != a.n1())
		SLS_ERR("wrong shape");
#endif
	for (Long i = start; i < a.n0(); ++i) {
		if (v == cut1(a, i))
			return i;
	}
	return -1;
}

inline Long search_row(SvecDoub_I v, ScmatDoub_I a, Long_I start = 0)
{
#ifdef SLS_CHECK_SHAPES
	if (v.size() != a.n1())
		SLS_ERR("wrong shape");
#endif
	for (Long i = start; i < a.n0(); ++i) {
		if (v == cut1(a, i))
			return i;
	}
	return -1;
}


inline Long search_row(DvecLlong_I v, ScmatLlong_I a, Long_I start = 0)
{
#ifdef SLS_CHECK_SHAPES
	if (v.size() != a.n1())
		SLS_ERR("wrong shape");
#endif
	for (Long i = start; i < a.n0(); ++i) {
		if (v == cut1(a, i))
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


} // namespace slisc
