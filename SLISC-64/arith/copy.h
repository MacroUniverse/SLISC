// copy data from one container to another
// includes container shape checking
// all `container = container` should be implemented using `copy()`

#pragma once
#include "../arith/compare.h"
#include "../dense/cut.h"

namespace slisc {
// === pointer interface ===

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


inline void vecset(Imag *v, Imag_I val, Long_I n)
{
	for (Imag *p = v; p < v + n; ++p)
		*p = val;
}

inline void vecset(Imag *v, Imag_I val, Long_I n, Long_I step)
{
	for (Imag *p = v; p < v + n*step; p += step)
		*p = val;
}


inline void vecset(Bool *v, Bool_I val, Long_I n)
{
	for (Bool *p = v; p < v + n; ++p)
		*p = val;
}

inline void vecset(Bool *v, Bool_I val, Long_I n, Long_I step)
{
	for (Bool *p = v; p < v + n*step; p += step)
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


template <class T>
inline void veccpy(T *v, const T *v1, Long_I n)
{
	memcpy(v, v1, sizeof(T)*n);
}

template <class T, class T1>
inline void veccpy(T *v, const T1 *v1, Long_I n)
{
	for (Long i = 0; i < n; ++i) {
		*v = *v1; ++v; ++v1;
	}
}

template <class T, class T1>
inline void veccpy(T *v, const T1 *v1, Long_I step1, Long_I n)
{
	for (T *p = v; p < v + n; ++p) {
		*p = *v1;
		v1 += step1;
	}
}

template <class T, class T1>
inline void veccpy(T *v, Long_I step, const T1 *v1, Long_I n)
{
	for (T *p = v; p < v + n*step; p += step) {
		*p = *v1;
		++v1;
	}
}

template <class T, class T1>
inline void veccpy(T *v, Long_I step, const T1 *v1, Long_I step1, Long_I n)
{
	T *end = v + n * step;
	for (; v < end; v += step) {
		*v = *v1;
		v1 += step1;
	}
}

template <class T, class T1>
inline void matcpy(T *v, Long_I lda, const T1 *v1, Long_I lda1, Long_I Nld, Long_I Nsd)
{
	for (Long j = 0; j < Nsd; ++j) {
		veccpy(v, v1, Nld);
		v += lda; v1 += lda1;
	}
}

// copy from row major matrix to column major matrix, or vise versa
// all matrix elements are contiguous
// if a1 is column major, and a2 is row major, they are N1*N2
// if a1 is row major, and a2 is column major, they are N2*N1
template <class T, class T1>
inline void matcpy_diff_major(T *a2, const T1 *a1, Long_I N2, Long_I N1)
{
	for (Long i2 = 0; i2 < N2; ++i2) {
		Long start = N1 * i2, k2 = i2;
		for (Long k1 = start; k1 < start + N1; ++k1) {
			a2[k2] = a1[k1];
			k2 += N2;
		}
	}
}

// for "dashed" matrix
template <class T, class T1>
inline void matcpy_diff_major(T *a2, const T1 *a1, Long_I N2, Long_I lda2, Long_I N1, Long_I lda1)
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
// scalar to container
inline void copy(vecBool_O v, Bool_I s)
{
	v.assign(v.size(), s);
}

inline void copy(vecInt_O v, Int_I s)
{
	v.assign(v.size(), s);
}

inline void copy(vecLlong_O v, Llong_I s)
{
	v.assign(v.size(), s);
}

inline void copy(SvecChar_O v, Char_I s)
{
	if (v.size() > 0) vecset(v.p(), s, v.size());
}

inline void copy(SvecInt_O v, Int_I s)
{
	if (v.size() > 0) vecset(v.p(), s, v.size());
}

inline void copy(SvecLlong_O v, Llong_I s)
{
	if (v.size() > 0) vecset(v.p(), s, v.size());
}

inline void copy(SvecDoub_O v, Doub_I s)
{
	if (v.size() > 0) vecset(v.p(), s, v.size());
}


inline void copy(SvecComp_O v, Comp_I s)
{
	if (v.size() > 0) vecset(v.p(), s, v.size());
}


inline void copy(DvecInt_O v, Int_I s)
{
	if (v.size() > 0) vecset(v.p(), s, v.size(), v.step());
}

inline void copy(DvecLlong_O v, Llong_I s)
{
	if (v.size() > 0) vecset(v.p(), s, v.size(), v.step());
}

inline void copy(DvecDoub_O v, Doub_I s)
{
	if (v.size() > 0) vecset(v.p(), s, v.size(), v.step());
}


inline void copy(DvecComp_O v, Comp_I s)
{
	if (v.size() > 0) vecset(v.p(), s, v.size(), v.step());
}


inline void copy(vvecBool_O v, Bool_I s)
{
	for (auto &v1 : v) v1.assign(v1.size(), s);
}

inline void copy(vvecInt_O v, Int_I s)
{
	for (auto &v1 : v) v1.assign(v1.size(), s);
}

inline void copy(vvecLlong_O v, Llong_I s)
{
	for (auto &v1 : v) v1.assign(v1.size(), s);
}

inline void copy(ScmatInt_O v, Int_I s)
{
	if (v.size() > 0) vecset(v.p(), s, v.size());
}

inline void copy(ScmatLlong_O v, Llong_I s)
{
	if (v.size() > 0) vecset(v.p(), s, v.size());
}

inline void copy(ScmatDoub_O v, Doub_I s)
{
	if (v.size() > 0) vecset(v.p(), s, v.size());
}


inline void copy(ScmatComp_O v, Comp_I s)
{
	if (v.size() > 0) vecset(v.p(), s, v.size());
}


inline void copy(MatInt_O v, Int_I s)
{
	if (v.size() > 0) vecset(v.p(), s, v.size());
}

inline void copy(MatDoub_O v, Doub_I s)
{
	if (v.size() > 0) vecset(v.p(), s, v.size());
}

inline void copy(Scmat3Int_O v, Int_I s)
{
	if (v.size() > 0) vecset(v.p(), s, v.size());
}

inline void copy(Scmat3Llong_O v, Llong_I s)
{
	if (v.size() > 0) vecset(v.p(), s, v.size());
}

inline void copy(Scmat3Doub_O v, Doub_I s)
{
	if (v.size() > 0) vecset(v.p(), s, v.size());
}


inline void copy(Scmat3Comp_O v, Comp_I s)
{
	if (v.size() > 0) vecset(v.p(), s, v.size());
}


inline void copy(Mat3Doub_O v, Doub_I s)
{
	if (v.size() > 0) vecset(v.p(), s, v.size());
}

inline void copy(Scmat4Doub_O v, Doub_I s)
{
	if (v.size() > 0) vecset(v.p(), s, v.size());
}

inline void copy(Scmat4Qdoub_O v, Qdoub_I s)
{
	if (v.size() > 0) vecset(v.p(), s, v.size());
}

inline void copy(MatComp_O v, Comp_I s)
{
	if (v.size() > 0) vecset(v.p(), s, v.size());
}

inline void copy(DcmatDoub_O v, Doub_I s)
{
	Long N1 = v.n0(), N2 = v.n1();
	for (Long j = 0; j < N2; ++j)
		vecset(&v(0, j), s, N1);
}

inline void copy(VecInt_O v, Int_I s)
{
	if (v.size() > 0) vecset(v.p(), s, v.size());
}

inline void copy(VecLlong_O v, Llong_I s)
{
	if (v.size() > 0) vecset(v.p(), s, v.size());
}

inline void copy(VecDoub_O v, Doub_I s)
{
	if (v.size() > 0) vecset(v.p(), s, v.size());
}

inline void copy(VecComp_O v, Comp_I s)
{
	if (v.size() > 0) vecset(v.p(), s, v.size());
}

inline void copy(CmatInt_O v, Int_I s)
{
	if (v.size() > 0) vecset(v.p(), s, v.size());
}

inline void copy(CmatLlong_O v, Llong_I s)
{
	if (v.size() > 0) vecset(v.p(), s, v.size());
}

inline void copy(CmatDoub_O v, Doub_I s)
{
	if (v.size() > 0) vecset(v.p(), s, v.size());
}

inline void copy(CmatComp_O v, Comp_I s)
{
	if (v.size() > 0) vecset(v.p(), s, v.size());
}

inline void copy(Cmat3Doub_O v, Doub_I s)
{
	if (v.size() > 0) vecset(v.p(), s, v.size());
}

inline void copy(Cmat3Comp_O v, Comp_I s)
{
	if (v.size() > 0) vecset(v.p(), s, v.size());
}

inline void copy(DcmatComp_O v, Comp_I s)
{
	Long N1 = v.n0(), N2 = v.n1();
	for (Long j = 0; j < N2; ++j)
		vecset(&v(0, j), s, N1);
}


// copy value to containers
// clang compiler error: second argument to 'va_arg' is of non-POD type 'slisc::Comp'
// inline void copy(@T@_O v, ...)

// copy initializer list to containers
inline void copy(SvecDoub_O v, const std::initializer_list<Doub> &v1)
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


inline void copy(SvecComp_O v, const std::initializer_list<Comp> &v1)
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


inline void copy(ScmatDoub_O v, const std::initializer_list<Doub> &v1)
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


inline void copy(ScmatComp_O v, const std::initializer_list<Comp> &v1)
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
inline void copy(SvecInt_O v, SvecInt_I v1)
{
	assert_same_shape(v, v1);
	if (!v.size()) return;
	if (v.size()) veccpy(v.p(), v1.p(), v.size());
}

inline void copy(SvecInt_O v, DvecInt_I v1)
{
	assert_same_shape(v, v1);
	if (!v.size()) return;
	if (v.size()) veccpy(v.p(), v1.p(), v1.step(), v1.size());
}

inline void copy(SvecLlong_O v, SvecLlong_I v1)
{
	assert_same_shape(v, v1);
	if (!v.size()) return;
	if (v.size()) veccpy(v.p(), v1.p(), v.size());
}

inline void copy(SvecDoub_O v, SvecDoub_I v1)
{
	assert_same_shape(v, v1);
	if (!v.size()) return;
	if (v.size()) veccpy(v.p(), v1.p(), v.size());
}

inline void copy(SvecDoub_O v, DvecDoub_I v1)
{
	assert_same_shape(v, v1);
	if (!v.size()) return;
	if (v.size()) veccpy(v.p(), v1.p(), v1.step(), v1.size());
}



inline void copy(SvecComp_O v, SvecComp_I v1)
{
	assert_same_shape(v, v1);
	if (!v.size()) return;
	if (v.size()) veccpy(v.p(), v1.p(), v.size());
}

inline void copy(SvecComp_O v, DvecComp_I v1)
{
	assert_same_shape(v, v1);
	if (!v.size()) return;
	if (v.size()) veccpy(v.p(), v1.p(), v1.step(), v1.size());
}

inline void copy(SvecComp_O v, SvecDoub_I v1)
{
	assert_same_shape(v, v1);
	if (!v.size()) return;
	if (v.size()) veccpy(v.p(), v1.p(), v.size());
}




inline void copy(DvecComp_O v, SvecComp_I v1)
{
	assert_same_shape(v, v1);
	if (!v.size()) return;
	if (v.size()) veccpy(v.p(), v.step(), v1.p(), v1.size());
}


inline void copy(ScmatInt_O v, ScmatInt_I v1)
{
	assert_same_shape(v, v1);
	if (!v.size()) return;
	if (v.size()) veccpy(v.p(), v1.p(), v.size());
}

inline void copy(ScmatLlong_O v, ScmatLlong_I v1)
{
	assert_same_shape(v, v1);
	if (!v.size()) return;
	if (v.size()) veccpy(v.p(), v1.p(), v.size());
}

inline void copy(ScmatDoub_O v, ScmatDoub_I v1)
{
	assert_same_shape(v, v1);
	if (!v.size()) return;
	if (v.size()) veccpy(v.p(), v1.p(), v.size());
}

inline void copy(ScmatDoub_O v, MatDoub_I v1)
{
	assert_same_shape(v, v1);
	if (!v.size()) return;
	if (v.size()) matcpy_diff_major(v.p(), v1.p(), v.n0(), v.n1());
}


inline void copy(ScmatComp_O v, ScmatComp_I v1)
{
	assert_same_shape(v, v1);
	if (!v.size()) return;
	if (v.size()) veccpy(v.p(), v1.p(), v.size());
}


inline void copy(MatDoub_O v, MatDoub_I v1)
{
	assert_same_shape(v, v1);
	if (!v.size()) return;
	if (v.size()) veccpy(v.p(), v1.p(), v.size());
}

inline void copy(MatDoub_O v, ScmatDoub_I v1)
{
	assert_same_shape(v, v1);
	if (!v.size()) return;
	if (v.size()) matcpy_diff_major(v.p(), v1.p(), v.n1(), v.n0());
}

inline void copy(Scmat3Int_O v, Scmat3Int_I v1)
{
	assert_same_shape(v, v1);
	if (!v.size()) return;
	if (v.size()) veccpy(v.p(), v1.p(), v.size());
}

inline void copy(Scmat3Llong_O v, Scmat3Llong_I v1)
{
	assert_same_shape(v, v1);
	if (!v.size()) return;
	if (v.size()) veccpy(v.p(), v1.p(), v.size());
}

inline void copy(Scmat3Doub_O v, Scmat3Doub_I v1)
{
	assert_same_shape(v, v1);
	if (!v.size()) return;
	if (v.size()) veccpy(v.p(), v1.p(), v.size());
}


inline void copy(Mat3Doub_O v, Mat3Doub_I v1)
{
	assert_same_shape(v, v1);
	if (!v.size()) return;
	if (v.size()) veccpy(v.p(), v1.p(), v.size());
}

inline void copy(Scmat3Comp_O v, Scmat3Comp_I v1)
{
	assert_same_shape(v, v1);
	if (!v.size()) return;
	if (v.size()) veccpy(v.p(), v1.p(), v.size());
}

inline void copy(Scmat3Comp_O v, Scmat3Doub_I v1)
{
	assert_same_shape(v, v1);
	if (!v.size()) return;
	if (v.size()) veccpy(v.p(), v1.p(), v.size());
}

inline void copy(DcmatDoub_O v, DcmatDoub_I v1)
{
	assert_same_shape(v, v1);
	if (!v.size()) return;
	if (v.size()) matcpy(v.p(), v.lda(), v1.p(), v1.lda(), v.n0(), v.n1());
}

inline void copy(DcmatComp_O v, DcmatComp_I v1)
{
	assert_same_shape(v, v1);
	if (!v.size()) return;
	if (v.size()) matcpy(v.p(), v.lda(), v1.p(), v1.lda(), v.n0(), v.n1());
}

inline void copy(DcmatInt_O v, DcmatInt_I v1)
{
	assert_same_shape(v, v1);
	if (!v.size()) return;
	if (v.size()) matcpy(v.p(), v.lda(), v1.p(), v1.lda(), v.n0(), v.n1());
}

inline void copy(DcmatLlong_O v, DcmatLlong_I v1)
{
	assert_same_shape(v, v1);
	if (!v.size()) return;
	if (v.size()) matcpy(v.p(), v.lda(), v1.p(), v1.lda(), v.n0(), v.n1());
}

inline void copy(Jcmat3Doub_O v, Jcmat3Doub_I v1)
{
	assert_same_shape(v, v1);
	if (!v.size()) return;
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
	if (!v.size()) return;
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
	if (!v.size()) return;
	if (v.size()) veccpy(v.p(), v.step(), v1.p(), v1.step(), v.size());
}

inline void copy(DvecLlong_O v, DvecLlong_I v1)
{
	assert_same_shape(v, v1);
	if (!v.size()) return;
	if (v.size()) veccpy(v.p(), v.step(), v1.p(), v1.step(), v.size());
}

inline void copy(DvecDoub_O v, DvecDoub_I v1)
{
	assert_same_shape(v, v1);
	if (!v.size()) return;
	if (v.size()) veccpy(v.p(), v.step(), v1.p(), v1.step(), v.size());
}


template <class T1, class T2>
inline void copy(vector<vector<T1>> &v1, const vector<vector<T2>> &v2)
{
#ifdef SLS_CHECK_SHAPES
	Long N = v1.size();
	SLS_ASSERT(N == size(v2));
	for (Long i = 0; i < N; ++i)
		SLS_ASSERT(v1[i].size() == v2[i].size());
#endif
	Long j = 0;
	for (auto &v : v1) {
		veccpy(v.data(), v2[j].data(), v.size());
		++j;
	}
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
		SLS_ERR("self copy is forbidden!");
	Long Nnz = v1.nnz();
	v.resize(Nnz);
	veccpy(v.p(), v1.p(), Nnz);
	veccpy(v.row_p(), v1.row_p(), Nnz);
	veccpy(v.col_p(), v1.col_p(), Nnz);
}


inline void copy(McooComp_O v, McooDoub_I v1)
{
#ifdef SLS_CHECK_SHAPES
	assert_same_shape(v, v1);
	if (v.capacity() < v1.nnz())
		SLS_ERR("not enough capacity!");
#endif
	if (v1.nnz() == 0)
		return;
	Long Nnz = v1.nnz();
	v.resize(Nnz);
	veccpy(v.p(), v1.p(), Nnz);
	veccpy(v.row_p(), v1.row_p(), Nnz);
	veccpy(v.col_p(), v1.col_p(), Nnz);
}



// copy dense matrix to Mcoo matrix
// abs(s) < tol is considered 0
inline void copy(McooDoub_O v, ScmatDoub_I v1, Doub_I tol = 0)
{
	assert_same_shape(v, v1);
	if (v.p() == v1.p())
		SLS_ERR("self copy is forbidden!");
	
	for (Long j = 0; j < v1.n1(); ++j) {
		for (Long i = 0; i < v1.n0(); ++i) {
			Doub val = v1(i, j);
			if (abs(val) > tol)
				v.push(val, i, j);
		}
	}
}


inline void copy(McooComp_O v, ScmatComp_I v1, Doub_I tol = 0)
{
	assert_same_shape(v, v1);
	if (v.p() == v1.p())
		SLS_ERR("self copy is forbidden!");
	
	for (Long j = 0; j < v1.n1(); ++j) {
		for (Long i = 0; i < v1.n0(); ++i) {
			Comp val = v1(i, j);
			if (abs(val) > tol)
				v.push(val, i, j);
		}
	}
}



inline void copy(ScmatInt_O lhs, McooInt_I rhs)
{
	assert_same_shape(lhs, rhs);
	copy(lhs, 0);
	for (Long i = 0; i < rhs.nnz(); ++i) {
		lhs(rhs.row(i), rhs.col(i)) += rhs[i];
	}
}

inline void copy(ScmatDoub_O lhs, McooDoub_I rhs)
{
	assert_same_shape(lhs, rhs);
	copy(lhs, 0);
	for (Long i = 0; i < rhs.nnz(); ++i) {
		lhs(rhs.row(i), rhs.col(i)) += rhs[i];
	}
}



inline void copy(CmobdDoub_O lhs, CmobdDoub_I rhs)
{ copy(lhs.cmat3(), rhs.cmat3()); }


inline void copy(CmobdComp_O lhs, CmobdComp_I rhs)
{ copy(lhs.cmat3(), rhs.cmat3()); }


inline void copy(CmobdComp_O lhs, CmobdDoub_I rhs)
{ copy(lhs.cmat3(), rhs.cmat3()); }



inline void copy(CmobdDoub_O lhs, McooDoub_I rhs)
{
	assert_same_shape(lhs, rhs);
	Scmat3Doub &c3 = lhs.cmat3();
	copy(c3, 0);
	for (Long k = 0; k < rhs.nnz(); ++k) {
		Long i = rhs.row(k), j = rhs.col(k);
		lhs.ref(i, j) = rhs[k];
	}
}


inline void copy(CmobdInt_O lhs, McooInt_I rhs)
{
	assert_same_shape(lhs, rhs);
	Scmat3Int &c3 = lhs.cmat3();
	copy(c3, 0);
	for (Long k = 0; k < rhs.nnz(); ++k) {
		Long i = rhs.row(k), j = rhs.col(k);
		lhs.ref(i, j) = rhs[k];
	}
}


// not optimized
inline void copy(ScmatDoub_O lhs, CmobdDoub_I rhs)
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
// void copy(MatCoo<T> &v, const Cmobd<T1> &v1)
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

DcmatDoub band(CbandDoub_IO);
DcmatDoubC band(CbandDoub_I);
inline void copy(CbandDoub_O a, Doub_I s)
{ copy(band(a), s); }


DcmatComp band(CbandComp_IO);
DcmatCompC band(CbandComp_I);
inline void copy(CbandComp_O a, Comp_I s)
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



inline void copy(ScmatDoub_O a, CbandDoub_I b)
{
	assert_same_shape(a, b);
	Long N1 = a.n0(), N2 = a.n1();
	for (Long j = 0; j < N2; ++j) {
		Long k = b.idiag() - j;
		Long i_beg = max(Long(0), j - b.nup()), i_end = min(N1, j + b.nlow() + 1);
		SvecDoub cut_a = cut0(a, j);
		SvecDoubC cut_b = cut0(b.cmat(), j);
		for (Long i = 0; i < i_beg; ++i)
			cut_a[i] = 0;
		for (Long i = i_beg; i < i_end; i++)
			cut_a[i] = cut_b[k + i];
		for (Long i = i_end; i < N1; ++i)
			cut_a[i] = 0;
	}
}


inline void copy(ScmatComp_O a, CbandComp_I b)
{
	assert_same_shape(a, b);
	Long N1 = a.n0(), N2 = a.n1();
	for (Long j = 0; j < N2; ++j) {
		Long k = b.idiag() - j;
		Long i_beg = max(Long(0), j - b.nup()), i_end = min(N1, j + b.nlow() + 1);
		SvecComp cut_a = cut0(a, j);
		SvecCompC cut_b = cut0(b.cmat(), j);
		for (Long i = 0; i < i_beg; ++i)
			cut_a[i] = 0;
		for (Long i = i_beg; i < i_end; i++)
			cut_a[i] = cut_b[k + i];
		for (Long i = i_end; i < N1; ++i)
			cut_a[i] = 0;
	}
}


inline void copy(CbandComp_O b, ScmatComp_I a)
{
	assert_same_shape(a, b);
	Long N1 = a.n0(), N2 = a.n1();
	for (Long j = 0; j < N2; ++j) {
		SvecComp cut_b = cut0(b.cmat(), j);
		SvecCompC cut_a = cut0(a, j);
		Long k = b.idiag() - j;
		Long i_beg = max(Long(0), j - b.nup()), i_end = min(N1, j + b.nlow() + 1);
		for (Long i = i_beg; i < i_end; ++i)
			cut_b[k + i] = cut_a[i];
	}
}


inline void copy(CbandDoub_O b, ScmatDoub_I a)
{
	assert_same_shape(a, b);
	Long N1 = a.n0(), N2 = a.n1();
	for (Long j = 0; j < N2; ++j) {
		SvecDoub cut_b = cut0(b.cmat(), j);
		SvecDoubC cut_a = cut0(a, j);
		Long k = b.idiag() - j;
		Long i_beg = max(Long(0), j - b.nup()), i_end = min(N1, j + b.nlow() + 1);
		for (Long i = i_beg; i < i_end; ++i)
			cut_b[k + i] = cut_a[i];
	}
}



// concatinate std::vector
inline void cat(vecInt_IO v, vecInt_I v1)
{ v.insert(v.end(), v1.begin(), v1.end()); }

inline void cat(vecLlong_IO v, vecLlong_I v1)
{ v.insert(v.end(), v1.begin(), v1.end()); }

inline void cat(vecStr_IO v, vecStr_I v1)
{ v.insert(v.end(), v1.begin(), v1.end()); }

inline void cat(vecStr32_IO v, vecStr32_I v1)
{ v.insert(v.end(), v1.begin(), v1.end()); }


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
