#pragma once
#include "../str/unicode.h"
#include "../algo/heap.h"
#include "../arith/reorder.h"

namespace slisc {

// === STL extension ===
// order of equal elements is not guaranteed to be preserved
// if begin == end, std::sort will do nothing
template <class T> // ascending
inline void sort(vector<T> &v) { sort(v.begin(), v.end()); }

template <class T> // descending
inline void sortd(vector<T> &v) { sort(v.begin(), v.end(), std::greater<T>()); }

// pointer interface
template <class T> // ascending
inline void sort_v(T *v, Long_I n) { std::sort(v, v+n); }

template <class T> // descending
inline void sortd_v(T *v, Long_I n) { std::sort(v, v+n, std::greater<T>()); }

// sort elements of v
inline void sort(VecChar_IO v) { if (size(v) > 1) sort_v(&v[0], size(v)); }
inline void sortd(VecChar_IO v) { if (size(v) > 1) sortd_v(&v[0], size(v)); }

// sort elements of v
inline void sort(VecInt_IO v) { if (size(v) > 1) sort_v(&v[0], size(v)); }
inline void sortd(VecInt_IO v) { if (size(v) > 1) sortd_v(&v[0], size(v)); }

// sort elements of v
inline void sort(VecLlong_IO v) { if (size(v) > 1) sort_v(&v[0], size(v)); }
inline void sortd(VecLlong_IO v) { if (size(v) > 1) sortd_v(&v[0], size(v)); }

// sort elements of v
inline void sort(VecDoub_IO v) { if (size(v) > 1) sort_v(&v[0], size(v)); }
inline void sortd(VecDoub_IO v) { if (size(v) > 1) sortd_v(&v[0], size(v)); }



// quicksort (mature version)
// no recursion, use insertion sort for short array
// same interface with std::sort, also supports sorting 2 arrays
// ref: Numerical Recipes 3ed
template <class Tit>
inline void sort_NR3_v(Tit v, Long_I n)
{
	typename std::iterator_traits<Tit>::value_type e;
	Long i, ir, j, k, jstack = -1, l = 0;
	Long istack[64];
	ir = n - 1;
	while(1) {
		if (ir - l < 7) { // use insertion sort for short array
			for (j = l+1; j <= ir; j++) {
				e = v[j];
				for (i = j - 1; i >= l; i--) {
					if (!(e < v[i])) break;
					v[i+1] = v[i];
				}
				v[i+1] = e;
			}
			if (jstack < 0) break;
			ir = istack[jstack--];
			l = istack[jstack--];
		}
		else {
			// medium of 3
			k = (l + ir) >> 1;
			swap(v[k], v[l+1]);
			if (v[ir] < v[l]) {
				swap(v[l], v[ir]);
			}
			if (v[ir] < v[l+1]) {
				swap(v[l+1], v[ir]);
			}
			if (v[l+1] < v[l]) {
				swap(v[l], v[l+1]);
			}
			i = l+1;
			j = ir;
			e = v[l+1];
			while (1) {
				do i++; while (v[i] < e);
				do j--; while (e < v[j]);
				if (j < i) break;
				swap(v[i], v[j]);
			}
			v[l+1] = v[j];
			v[j] = e;
			jstack += 2;
			if (jstack >= 64) throw("NSTACK too small in sort.");
			if (ir - i + 1 >= j - l) {
				istack[jstack] = ir;
				istack[jstack-1] = i;
				ir = j - 1;
			}
			else {
				istack[jstack] = j - 1;
				istack[jstack-1] = l;
				l = i;
			}
		}
	}
}

template <class Tit>
inline void sortd_NR3_v(Tit v, Long_I n)
{
	typename std::iterator_traits<Tit>::value_type e;
	Long i, ir, j, k, jstack = -1, l = 0;
	Long istack[64];
	ir = n - 1;
	while(1) {
		if (ir - l < 7) { // use insertion sort for short array
			for (j = l+1; j <= ir; j++) {
				e = v[j];
				for (i = j - 1; i >= l; i--) {
					if (!(v[i] < e)) break;
					v[i+1] = v[i];
				}
				v[i+1] = e;
			}
			if (jstack < 0) break;
			ir = istack[jstack--];
			l = istack[jstack--];
		}
		else {
			// medium of 3
			k = (l + ir) >> 1;
			swap(v[k], v[l+1]);
			if (v[l] < v[ir]) {
				swap(v[l], v[ir]);
			}
			if (v[l+1] < v[ir]) {
				swap(v[l+1], v[ir]);
			}
			if (v[l] < v[l+1]) {
				swap(v[l], v[l+1]);
			}
			i = l+1;
			j = ir;
			e = v[l+1];
			while (1) {
				do i++; while (e < v[i]);
				do j--; while (v[j] < e);
				if (j < i) break;
				swap(v[i], v[j]);
			}
			v[l+1] = v[j];
			v[j] = e;
			jstack += 2;
			if (jstack >= 64) throw("NSTACK too small in sort.");
			if (ir - i + 1 >= j - l) {
				istack[jstack] = ir;
				istack[jstack-1] = i;
				ir = j - 1;
			}
			else {
				istack[jstack] = j - 1;
				istack[jstack-1] = l;
				l = i;
			}
		}
	}
}

template <class Tit, class Tcomp>
inline void sort_NR3_v(Tit v, Long_I n, Tcomp comp)
{
	typename std::iterator_traits<Tit>::value_type e;
	Long i, ir, j, k, jstack = -1, l = 0;
	Long istack[64];
	ir = n - 1;
	while(1) {
		if (ir - l < 7) { // use insertion sort for short array
			for (j = l+1; j <= ir; j++) {
				e = v[j];
				for (i = j - 1; i >= l; i--) {
					if (!comp(e, v[i])) break;
					v[i+1] = v[i];
				}
				v[i+1] = e;
			}
			if (jstack < 0) break;
			ir = istack[jstack--];
			l = istack[jstack--];
		}
		else {
			// medium of 3
			k = (l + ir) >> 1;
			swap(v[k], v[l+1]);
			if (comp(v[ir], v[l])) {
				swap(v[l], v[ir]);
			}
			if (comp(v[ir], v[l+1])) {
				swap(v[l+1], v[ir]);
			}
			if (comp(v[l+1], v[l])) {
				swap(v[l], v[l+1]);
			}
			i = l+1;
			j = ir;
			e = v[l+1];
			while (1) {
				do i++; while (comp(v[i], e));
				do j--; while (comp(e, v[j]));
				if (j < i) break;
				swap(v[i], v[j]);
			}
			v[l+1] = v[j];
			v[j] = e;
			jstack += 2;
			if (jstack >= 64) throw("NSTACK too small in sort.");
			if (ir - i + 1 >= j - l) {
				istack[jstack] = ir;
				istack[jstack-1] = i;
				ir = j - 1;
			}
			else {
				istack[jstack] = j - 1;
				istack[jstack-1] = l;
				l = i;
			}
		}
	}
}

template <class Tit, class Tit1>
inline void sort_vv(Tit v, Tit1 v1, Long_I n)
{
	typename std::iterator_traits<Tit>::value_type e;
	typename std::iterator_traits<Tit1>::value_type e1;
	Long i, ir, j, k, jstack = -1, l = 0;
	Long istack[64];
	ir = n - 1;
	while(1) {
		if (ir - l < 7) { // use insertion sort for short array
			for (j = l+1; j <= ir; j++) {
				e = v[j];
				e1 = v1[j];
				for (i = j - 1; i >= l; i--) {
					if (!(e < v[i])) break;
					v[i+1] = v[i];
					v1[i+1] = v1[i];
				}
				v[i+1] = e;
				v1[i+1] = e1;
			}
			if (jstack < 0) break;
			ir = istack[jstack--];
			l = istack[jstack--];
		}
		else {
			// medium of 3
			k = (l + ir) >> 1;
			swap(v[k], v[l+1]);
			swap(v1[k], v1[l+1]);
			if (v[ir] < v[l]) {
				swap(v[l], v[ir]);
				swap(v1[l], v1[ir]);
			}
			if (v[ir] < v[l+1]) {
				swap(v[l+1], v[ir]);
				swap(v1[l+1], v1[ir]);
			}
			if (v[l+1] < v[l]) {
				swap(v[l], v[l+1]);
				swap(v1[l], v1[l+1]);
			}
			i = l+1;
			j = ir;
			e = v[l+1];
			e1 = v1[l+1];
			while (1) {
				do i++; while (v[i] < e);
				do j--; while (e < v[j]);
				if (j < i) break;
				swap(v[i], v[j]);
				swap(v1[i], v1[j]);
			}
			v[l+1] = v[j];
			v[j] = e;
			v1[l+1] = v1[j];
			v1[j] = e1;
			jstack += 2;
			if (jstack >= 64) throw("NSTACK too small in sort.");
			if (ir - i + 1 >= j - l) {
				istack[jstack] = ir;
				istack[jstack-1] = i;
				ir = j - 1;
			}
			else {
				istack[jstack] = j - 1;
				istack[jstack-1] = l;
				l = i;
			}
		}
	}
}

template <class Tit, class Tit1>
inline void sortd_vv(Tit v, Tit1 v1, Long_I n)
{
	typename std::iterator_traits<Tit>::value_type e;
	typename std::iterator_traits<Tit1>::value_type e1;
	Long i, ir, j, k, jstack = -1, l = 0;
	Long istack[64];
	ir = n - 1;
	while(1) {
		if (ir - l < 7) { // use insertion sort for short array
			for (j = l+1; j <= ir; j++) {
				e = v[j];
				e1 = v1[j];
				for (i = j - 1; i >= l; i--) {
					if (!(v[i] < e)) break;
					v[i+1] = v[i];
					v1[i+1] = v1[i];
				}
				v[i+1] = e;
				v1[i+1] = e1;
			}
			if (jstack < 0) break;
			ir = istack[jstack--];
			l = istack[jstack--];
		}
		else {
			// medium of 3
			k = (l + ir) >> 1;
			swap(v[k], v[l+1]);
			swap(v1[k], v1[l+1]);
			if (v[l] < v[ir]) {
				swap(v[l], v[ir]);
				swap(v1[l], v1[ir]);
			}
			if (v[l+1] < v[ir]) {
				swap(v[l+1], v[ir]);
				swap(v1[l+1], v1[ir]);
			}
			if (v[l] < v[l+1]) {
				swap(v[l], v[l+1]);
				swap(v1[l], v1[l+1]);
			}
			i = l+1;
			j = ir;
			e = v[l+1];
			e1 = v1[l+1];
			while (1) {
				do i++; while (e < v[i]);
				do j--; while (v[j] < e);
				if (j < i) break;
				swap(v[i], v[j]);
				swap(v1[i], v1[j]);
			}
			v[l+1] = v[j];
			v[j] = e;
			v1[l+1] = v1[j];
			v1[j] = e1;
			jstack += 2;
			if (jstack >= 64) throw("NSTACK too small in sort.");
			if (ir - i + 1 >= j - l) {
				istack[jstack] = ir;
				istack[jstack-1] = i;
				ir = j - 1;
			}
			else {
				istack[jstack] = j - 1;
				istack[jstack-1] = l;
				l = i;
			}
		}
	}
}

template <class Tit, class Tit1, class Tcomp>
inline void sort_vv(Tit v, Tit1 v1, Long_I n, Tcomp comp)
{
	typename std::iterator_traits<Tit>::value_type e;
	typename std::iterator_traits<Tit1>::value_type e1;
	Long i, ir, j, k, jstack = -1, l = 0;
	Long istack[64];
	ir = n - 1;
	while(1) {
		if (ir - l < 7) { // use insertion sort for short array
			for (j = l+1; j <= ir; j++) {
				e = v[j];
				e1 = v1[j];
				for (i = j - 1; i >= l; i--) {
					if (!comp(e, v[i])) break;
					v[i+1] = v[i];
					v1[i+1] = v1[i];
				}
				v[i+1] = e;
				v1[i+1] = e1;
			}
			if (jstack < 0) break;
			ir = istack[jstack--];
			l = istack[jstack--];
		}
		else {
			// medium of 3
			k = (l + ir) >> 1;
			swap(v[k], v[l+1]);
			swap(v1[k], v1[l+1]);
			if (comp(v[ir], v[l])) {
				swap(v[l], v[ir]);
				swap(v1[l], v1[ir]);
			}
			if (comp(v[ir], v[l+1])) {
				swap(v[l+1], v[ir]);
				swap(v1[l+1], v1[ir]);
			}
			if (comp(v[l+1], v[l])) {
				swap(v[l], v[l+1]);
				swap(v1[l], v1[l+1]);
			}
			i = l+1;
			j = ir;
			e = v[l+1];
			e1 = v1[l+1];
			while (1) {
				do i++; while (comp(v[i], e));
				do j--; while (comp(e, v[j]));
				if (j < i) break;
				swap(v[i], v[j]);
				swap(v1[i], v1[j]);
			}
			v[l+1] = v[j];
			v[j] = e;
			v1[l+1] = v1[j];
			v1[j] = e1;
			jstack += 2;
			if (jstack >= 64) throw("NSTACK too small in sort.");
			if (ir - i + 1 >= j - l) {
				istack[jstack] = ir;
				istack[jstack-1] = i;
				ir = j - 1;
			}
			else {
				istack[jstack] = j - 1;
				istack[jstack-1] = l;
				l = i;
			}
		}
	}
}


// sort v while making the same change for v1
inline void sort(VecInt_IO v, VecInt_IO v1)
{
	assert_same_shape1(v, v1);
	if (size(v) > 1)
		sort_vv(&v[0], &v1[0], size(v));
}

inline void sortd(VecInt_IO v, VecInt_IO v1)
{
	assert_same_shape1(v, v1);
	if (size(v) > 1)
		sortd_vv(&v[0], &v1[0], size(v));
}

inline void sort(VecInt_IO v, VecLlong_IO v1)
{
	assert_same_shape1(v, v1);
	if (size(v) > 1)
		sort_vv(&v[0], &v1[0], size(v));
}

inline void sortd(VecInt_IO v, VecLlong_IO v1)
{
	assert_same_shape1(v, v1);
	if (size(v) > 1)
		sortd_vv(&v[0], &v1[0], size(v));
}

inline void sort(VecLlong_IO v, VecLlong_IO v1)
{
	assert_same_shape1(v, v1);
	if (size(v) > 1)
		sort_vv(&v[0], &v1[0], size(v));
}

inline void sortd(VecLlong_IO v, VecLlong_IO v1)
{
	assert_same_shape1(v, v1);
	if (size(v) > 1)
		sortd_vv(&v[0], &v1[0], size(v));
}

inline void sort(VecDoub_IO v, VecLlong_IO v1)
{
	assert_same_shape1(v, v1);
	if (size(v) > 1)
		sort_vv(&v[0], &v1[0], size(v));
}

inline void sortd(VecDoub_IO v, VecLlong_IO v1)
{
	assert_same_shape1(v, v1);
	if (size(v) > 1)
		sortd_vv(&v[0], &v1[0], size(v));
}

inline void sort(vecLlong_IO v, vecLlong_IO v1)
{
	assert_same_shape1(v, v1);
	if (size(v) > 1)
		sort_vv(&v[0], &v1[0], size(v));
}

inline void sortd(vecLlong_IO v, vecLlong_IO v1)
{
	assert_same_shape1(v, v1);
	if (size(v) > 1)
		sortd_vv(&v[0], &v1[0], size(v));
}

inline void sort(vecLlong_IO v, vecStr_IO v1)
{
	assert_same_shape1(v, v1);
	if (size(v) > 1)
		sort_vv(&v[0], &v1[0], size(v));
}

inline void sortd(vecLlong_IO v, vecStr_IO v1)
{
	assert_same_shape1(v, v1);
	if (size(v) > 1)
		sortd_vv(&v[0], &v1[0], size(v));
}


// case insensitive sorting for string
inline bool compare_case_insens_less(Str_I a, Str_I b) {
    return std::lexicographical_compare(
        a.begin(), a.end(), b.begin(), b.end(),
        [](char c1, char c2) { return std::tolower(c1) < std::tolower(c2); }
    );
}

inline bool compare_case_insens_greater(Str_I a, Str_I b) {
    return !compare_case_insens_less(a, b);
}

inline void sort_case_insens(vecStr_IO v)
{ sort(v.begin(), v.end(), compare_case_insens_less); }

inline void sortd_case_insens(vecStr_IO v)
{ sort(v.begin(), v.end(), compare_case_insens_greater); }

template <class Tit>
inline void sort_case_insens(vecStr_IO v, Tit v1)
{ sort(v.begin(), v1, size(v), compare_case_insens_less); }

template <class Tit>
inline void sortd_case_insens(vecStr_IO v, Tit v1)
{ sort(v.begin(), v1, size(v), compare_case_insens_greater); }

inline bool compare_case_insens_less32(Str32_I a, Str32_I b) {
    return std::lexicographical_compare(
        a.begin(), a.end(), b.begin(), b.end(),
        [](char c1, char c2) { return std::tolower(c1) < std::tolower(c2); }
    );
}

inline bool compare_case_insens_greater32(Str32_I a, Str32_I b) {
    return !compare_case_insens_less32(a, b);
}

inline void sort_case_insens(vecStr32_IO v)
{ sort(v.begin(), v.end(), compare_case_insens_less32); }

inline void sortd_case_insens(vecStr32_IO v)
{ sort(v.begin(), v.end(), compare_case_insens_greater32); }

template <class Tit>
inline void sort_case_insens(vecStr32_IO v, Tit v1)
{ sort(v.begin(), v1, size(v), compare_case_insens_less32); }

template <class Tit>
inline void sortd_case_insens(vecStr32_IO v, Tit v1)
{ sort(v.begin(), v1, size(v), compare_case_insens_greater32); }


// === my version of quicksort ===
// swap medium to `a`
template <class T>
void quicksort_3mid(T &a, T &b, T &c) {
	if (a < c) {
		if (b < a);
		else if (b > c) swap(a, c);
		else swap(a, b);
	}
	else {
		if (b < c) swap(a, c);
		else if (b > a);
		else swap(a, b);
	}
}

// do the same swap for a1, b1, c1
template <class T>
void quicksort_3mid(T &a, T &b, T &c, T &a1, T &b1, T &c1) {
	if (a < c) {
		if (b < a);
		else if (b > c) swap(a, c), swap(a1, c1);
		else swap(a, b), swap(a1, b1);
	}
	else {
		if (b < c) swap(a, c), swap(a1, c1);
		else if (b > a);
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
		if (j <= i) break;
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
		if (j <= i) break;
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

// === merge sort ===
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

// find smallest Nmin elements
// return in ascending order
// algo: one pass, with priority queue, optimal for small Nmin
template <class T>
inline void minN(vector<T> &vals, vector<Long> &inds, const T *v, Long_I N, Long_I Nmin)
{
#ifdef SLS_CHECK_SHAPES
	if (N < Nmin)
		SLS_ERR("wrong shape!");
#endif
	typedef pair<T,Long> P; // (val, ind)
	vals.resize(Nmin); inds.resize(Nmin);
	priority_queue<P> q;
	for (Long i = 0; i < Nmin; ++i)
		q.push(P(v[i], i));
	for (Long i = Nmin; i < N; ++i) {
		const T &val = v[i];
		if (val < q.top().first) {
			q.pop();
			q.push(P(val, i));
		}
	}
	for (Long i = 0; i < Nmin; ++i) {
		Long j = Nmin-i-1;
		vals[j] = q.top().first;
		inds[j] = q.top().second;
		q.pop();
	}
}

// find largest Nmax elements
// return in descending order
// algo: one pass, with priority queue, optimal for small Nmax
template <class T>
inline void maxN(vector<T> &vals, vector<Long> &inds, const T *v, Long_I N, Long_I Nmax)
{
#ifdef SLS_CHECK_SHAPES
	if (N < Nmax)
		SLS_ERR("wrong shape!");
#endif
	typedef pair<T,Long> P; // (val, ind)
	vals.resize(Nmax); inds.resize(Nmax);
	priority_queue<P, vector<P>, std::greater<P>> q;
	for (Long i = 0; i < Nmax; ++i)
		q.push(P(v[i], i));
	for (Long i = Nmax; i < N; ++i) {
		const T &val = v[i];
		if (val > q.top().first) {
			q.pop();
			q.push(P(val, i));
		}
	}
	for (Long i = 0; i < Nmax; ++i) {
		Long j = Nmax-i-1;
		vals[j] = q.top().first;
		inds[j] = q.top().second;
		q.pop();
	}
}

// find largest Nmax elements
// and put to the end of vector with ascending order
// algo: heap sort (used in Python std lib), optimal for large Nmax
template <class T>
inline void maxN_heap(T *v, Long_I N, Long_I Nmax)
{
	// make max heap
	for (Long i = N / 2 - 1; i >= 0; --i)
		heapify(v, N, i);
	// sort loop
	Long Nmin = N - Nmax;
	for (Long i = N - 1; i >= Nmin; --i) {
		swap(v[0], v[i]);
		heapify(v, i, 0);
	}
}

// find largest Nmax elements
// and put to the end of vector with ascending order
// algo: quick sort (1st elm pivot)
template <class T>
inline void maxN_quick0(T *v, Long_I N, Long_I Nmax)
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
	if (N-i+1 < Nmax)
		maxN_quick0(v, i-1, Nmax);
	maxN_quick0(v+i, N-i, Nmax);
}

// find largest Nmax elements
// and put to the end of vector with ascending order
// algo: quick sort (medium of 3)
template <class T>
inline void maxN_quick3(T *v, Long_I N, Long_I Nmax)
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
	if (N-i+1 < Nmax)
		maxN_quick3(v, i-1, Nmax);
	maxN_quick3(v+i, N-i, Nmax);
}

template <class Tv, class To>
inline Long reorder_inplace_helper(Tv &v, const To &order, Long_I i, Long_I j)
{
	Long k = order[j];
	if (k >= i)
		return k;

	return reorder_inplace_helper(v, order, i, k);	
}

template <class Tv, class To>
inline void reorder_inplace(Tv &v, const To &order)
{
	Long N = size(v);
	for (Long i = 0; i < N; ++i) {
		Long j = order[i];
		if (j > i) {
			swap(v[i], v[j]);
		}
		else if (j < i) {
			// return k >= i
			Long k = reorder_inplace_helper(v, order, i, j);
			if (k > i)
				swap(v[i], v[k]);
		}
	}
}

} // namespace slisc
