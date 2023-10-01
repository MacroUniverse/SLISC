// compare containers

#pragma once
#include "../dense/Vec.h"
#include "../dense/Mat.h"
#include "../dense/Mat3.h"
#include "../dense/Cmat.h"
#include "../dense/Cmat3.h"
#include "../dense/Cmat4.h"
#include "../sparse/Cband.h"
#include "../sparse/Mcoo.h"
#include "../sparse/Cmobd.h"
#include "../dense/Svec.h"
#include "../dense/Dvec.h"
#include "../dense/Scmat.h"
#include "../dense/Scmat3.h"
#include "../dense/Scmat4.h"
#include "../dense/Dcmat.h"
#include "../dense/Jcmat3.h"

namespace slisc {
inline bool equals_vs(const Comp *v, Doub_I s, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		if (v[i] != s)
			return false;
	return true;
}


inline bool equals_vs(const Int *v, Int_I s, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		if (v[i] != s)
			return false;
	return true;
}

inline bool equals_vs(const Llong *v, Llong_I s, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		if (v[i] != s)
			return false;
	return true;
}

inline bool equals_vs(const Doub *v, Doub_I s, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		if (v[i] != s)
			return false;
	return true;
}

inline bool equals_vs(const Comp *v, Comp_I s, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		if (v[i] != s)
			return false;
	return true;
}


inline bool equals_vv(const Int *v1, const Int *v2, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		if (v1[i] != v2[i])
			return false;
	return true;
}

inline bool equals_vv(const Char *v1, const Char *v2, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		if (v1[i] != v2[i])
			return false;
	return true;
}

inline bool equals_vv(const Uchar *v1, const Uchar *v2, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		if (v1[i] != v2[i])
			return false;
	return true;
}

inline bool equals_vv(const Llong *v1, const Llong *v2, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		if (v1[i] != v2[i])
			return false;
	return true;
}

inline bool equals_vv(const Doub *v1, const Doub *v2, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		if (v1[i] != v2[i])
			return false;
	return true;
}

inline bool equals_vv(const Doub *v1, const Comp *v2, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		if (v1[i] != v2[i])
			return false;
	return true;
}

inline bool equals_vv(const Comp *v1, const Comp *v2, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		if (v1[i] != v2[i])
			return false;
	return true;
}

inline bool equals_vv(const Comp *v1, const Doub *v2, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		if (v1[i] != v2[i])
			return false;
	return true;
}


template <class T1, class T2>
bool shape_cmp1(const T1 &v1, const T2 &v2) {return (Long)v1.size() == (Long)v2.size();}

template <class T1, class T2>
bool shape_cmp2(const T1 &v1, const T2 &v2) {return v1.n0() == v2.n0() && v1.n1() == v2.n1();}

template <class T1, class T2>
bool shape_cmp3(const T1 &v1, const T2 &v2) {return v1.n0() == v2.n0() && v1.n1() == v2.n1() && v1.n2() == v2.n2();}

template <class T1, class T2>
bool shape_cmp4(const T1 &v1, const T2 &v2) {return v1.n0() == v2.n0() && v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();}

template <class T1, class T2>
void assert_same_shape1(const T1 &v1, const T2 &v2) {
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp1(v1, v2)) SLS_ERR("wrong shape!");
#endif
}

template <class T1, class T2>
void assert_same_shape2(const T1 &v1, const T2 &v2) {
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp2(v1, v2)) SLS_ERR("wrong shape!");
#endif
}

template <class T1, class T2>
void assert_same_shape3(const T1 &v1, const T2 &v2) {
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp3(v1, v2)) SLS_ERR("wrong shape!");
#endif
}

template <class T1, class T2>
void assert_same_shape4(const T1 &v1, const T2 &v2) {
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp4(v1, v2)) SLS_ERR("wrong shape!");
#endif
}

template <class T1, class T2, class T3>
void assert_same_shape1(const T1 &v1, const T2 &v2, const T3 &v3) {
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp1(v1, v2) || !shape_cmp1(v1, v3)) SLS_ERR("wrong shape!");
#endif
}

template <class T1, class T2, class T3>
void assert_same_shape2(const T1 &v1, const T2 &v2, const T3 &v3) {
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp2(v1, v2) || !shape_cmp2(v1, v3)) SLS_ERR("wrong shape!");
#endif
}

template <class T1, class T2, class T3>
void assert_same_shape3(const T1 &v1, const T2 &v2, const T3 &v3) {
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp3(v1, v2) || !shape_cmp3(v1, v3)) SLS_ERR("wrong shape!");
#endif
}

template <class T1, class T2, class T3>
void assert_same_shape4(const T1 &v1, const T2 &v2, const T3 &v3) {
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp4(v1, v2) || !shape_cmp4(v1, v3)) SLS_ERR("wrong shape!");
#endif
}



inline bool operator==(SvecChar_I v1, SvecChar_I v2)
{
	return shape_cmp1(v1, v2) &&
		equals_vv(v1.p(), v2.p(), v2.size());
}

inline bool operator!=(SvecChar_I v1, SvecChar_I v2)
{ return !(v1 == v2); }

inline bool operator==(SvecUchar_I v1, SvecUchar_I v2)
{
	return shape_cmp1(v1, v2) &&
		equals_vv(v1.p(), v2.p(), v2.size());
}

inline bool operator!=(SvecUchar_I v1, SvecUchar_I v2)
{ return !(v1 == v2); }

inline bool operator==(SvecInt_I v1, SvecInt_I v2)
{
	return shape_cmp1(v1, v2) &&
		equals_vv(v1.p(), v2.p(), v2.size());
}

inline bool operator!=(SvecInt_I v1, SvecInt_I v2)
{ return !(v1 == v2); }

inline bool operator==(SvecLlong_I v1, SvecLlong_I v2)
{
	return shape_cmp1(v1, v2) &&
		equals_vv(v1.p(), v2.p(), v2.size());
}

inline bool operator!=(SvecLlong_I v1, SvecLlong_I v2)
{ return !(v1 == v2); }

inline bool operator==(SvecDoub_I v1, SvecDoub_I v2)
{
	return shape_cmp1(v1, v2) &&
		equals_vv(v1.p(), v2.p(), v2.size());
}

inline bool operator!=(SvecDoub_I v1, SvecDoub_I v2)
{ return !(v1 == v2); }


inline bool operator==(SvecDoub_I v1, SvecComp_I v2)
{
	return shape_cmp1(v1, v2) &&
		equals_vv(v1.p(), v2.p(), v2.size());
}

inline bool operator!=(SvecDoub_I v1, SvecComp_I v2)
{ return !(v1 == v2); }


inline bool operator==(SvecComp_I v1, SvecComp_I v2)
{
	return shape_cmp1(v1, v2) &&
		equals_vv(v1.p(), v2.p(), v2.size());
}

inline bool operator!=(SvecComp_I v1, SvecComp_I v2)
{ return !(v1 == v2); }


inline bool operator==(MatLlong_I v1, MatLlong_I v2)
{
	return shape_cmp2(v1, v2) &&
		equals_vv(v1.p(), v2.p(), v2.size());
}

inline bool operator!=(MatLlong_I v1, MatLlong_I v2)
{ return !(v1 == v2); }

inline bool operator==(MatDoub_I v1, MatDoub_I v2)
{
	return shape_cmp2(v1, v2) &&
		equals_vv(v1.p(), v2.p(), v2.size());
}

inline bool operator!=(MatDoub_I v1, MatDoub_I v2)
{ return !(v1 == v2); }

inline bool operator==(MatDoub_I v1, ScmatDoub_I v2)
{
	if (!shape_cmp2(v1, v2))
		return false;
	for (Long i = 0; i < v1.n0(); ++i)
		for (Long j = 0; j < v1.n1(); ++j)
			if (v1(i, j) != v2(i, j))
				return false;
	return true;
}

inline bool operator!=(MatDoub_I v1, ScmatDoub_I v2)
{ return !(v1 == v2); }

inline bool operator==(MatInt_I v1, MatInt_I v2)
{
	return shape_cmp2(v1, v2) &&
		equals_vv(v1.p(), v2.p(), v2.size());
}

inline bool operator!=(MatInt_I v1, MatInt_I v2)
{ return !(v1 == v2); }

inline bool operator==(MatComp_I v1, MatComp_I v2)
{
	return shape_cmp2(v1, v2) &&
		equals_vv(v1.p(), v2.p(), v2.size());
}

inline bool operator!=(MatComp_I v1, MatComp_I v2)
{ return !(v1 == v2); }

inline bool operator==(CmatInt_I v1, ScmatInt_I v2)
{
	return shape_cmp2(v1, v2) &&
		equals_vv(v1.p(), v2.p(), v2.size());
}

inline bool operator!=(CmatInt_I v1, ScmatInt_I v2)
{ return !(v1 == v2); }

inline bool operator==(CmatLlong_I v1, ScmatLlong_I v2)
{
	return shape_cmp2(v1, v2) &&
		equals_vv(v1.p(), v2.p(), v2.size());
}

inline bool operator!=(CmatLlong_I v1, ScmatLlong_I v2)
{ return !(v1 == v2); }

inline bool operator==(CmatDoub_I v1, ScmatDoub_I v2)
{
	return shape_cmp2(v1, v2) &&
		equals_vv(v1.p(), v2.p(), v2.size());
}

inline bool operator!=(CmatDoub_I v1, ScmatDoub_I v2)
{ return !(v1 == v2); }


inline bool operator==(CmatComp_I v1, ScmatComp_I v2)
{
	return shape_cmp2(v1, v2) &&
		equals_vv(v1.p(), v2.p(), v2.size());
}

inline bool operator!=(CmatComp_I v1, ScmatComp_I v2)
{ return !(v1 == v2); }


inline bool operator==(Cmat3Llong_I v1, Scmat3Llong_I v2)
{
	return shape_cmp3(v1, v2) &&
		equals_vv(v1.p(), v2.p(), v2.size());
}

inline bool operator!=(Cmat3Llong_I v1, Scmat3Llong_I v2)
{ return !(v1 == v2); }

inline bool operator==(Cmat3Doub_I v1, Scmat3Doub_I v2)
{
	return shape_cmp3(v1, v2) &&
		equals_vv(v1.p(), v2.p(), v2.size());
}

inline bool operator!=(Cmat3Doub_I v1, Scmat3Doub_I v2)
{ return !(v1 == v2); }


inline bool operator==(Cmat3Comp_I v1, Scmat3Comp_I v2)
{
	return shape_cmp3(v1, v2) &&
		equals_vv(v1.p(), v2.p(), v2.size());
}

inline bool operator!=(Cmat3Comp_I v1, Scmat3Comp_I v2)
{ return !(v1 == v2); }


inline bool operator==(ScmatInt_I v1, ScmatInt_I v2)
{
	return shape_cmp2(v1, v2) &&
		equals_vv(v1.p(), v2.p(), v2.size());
}

inline bool operator!=(ScmatInt_I v1, ScmatInt_I v2)
{ return !(v1 == v2); }

inline bool operator==(ScmatLlong_I v1, ScmatLlong_I v2)
{
	return shape_cmp2(v1, v2) &&
		equals_vv(v1.p(), v2.p(), v2.size());
}

inline bool operator!=(ScmatLlong_I v1, ScmatLlong_I v2)
{ return !(v1 == v2); }

inline bool operator==(ScmatDoub_I v1, ScmatDoub_I v2)
{
	return shape_cmp2(v1, v2) &&
		equals_vv(v1.p(), v2.p(), v2.size());
}

inline bool operator!=(ScmatDoub_I v1, ScmatDoub_I v2)
{ return !(v1 == v2); }


inline bool operator==(ScmatComp_I v1, ScmatComp_I v2)
{
	return shape_cmp2(v1, v2) &&
		equals_vv(v1.p(), v2.p(), v2.size());
}

inline bool operator!=(ScmatComp_I v1, ScmatComp_I v2)
{ return !(v1 == v2); }


inline bool operator==(Scmat3Llong_I v1, Scmat3Llong_I v2)
{
	return shape_cmp3(v1, v2) &&
		equals_vv(v1.p(), v2.p(), v2.size());
}

inline bool operator!=(Scmat3Llong_I v1, Scmat3Llong_I v2)
{ return !(v1 == v2); }

inline bool operator==(Scmat3Doub_I v1, Scmat3Doub_I v2)
{
	return shape_cmp3(v1, v2) &&
		equals_vv(v1.p(), v2.p(), v2.size());
}

inline bool operator!=(Scmat3Doub_I v1, Scmat3Doub_I v2)
{ return !(v1 == v2); }


inline bool operator==(Scmat3Comp_I v1, Scmat3Comp_I v2)
{
	return shape_cmp3(v1, v2) &&
		equals_vv(v1.p(), v2.p(), v2.size());
}

inline bool operator!=(Scmat3Comp_I v1, Scmat3Comp_I v2)
{ return !(v1 == v2); }


inline bool operator==(ScmatDoub_I v1, MatDoub_I v2)
{
	if (!shape_cmp2(v1, v2))
		return false;
	for (Long i = 0; i < v1.n0(); ++i)
		for (Long j = 0; j < v1.n1(); ++j)
			if (v1(i, j) != v2(i, j))
				return false;
	return true;
}

inline bool operator!=(ScmatDoub_I v1, MatDoub_I v2)
{ return !(v1 == v2); }

inline bool operator==(ScmatComp_I v1, MatComp_I v2)
{
	if (!shape_cmp2(v1, v2))
		return false;
	for (Long i = 0; i < v1.n0(); ++i)
		for (Long j = 0; j < v1.n1(); ++j)
			if (v1(i, j) != v2(i, j))
				return false;
	return true;
}

inline bool operator!=(ScmatComp_I v1, MatComp_I v2)
{ return !(v1 == v2); }

inline bool operator==(Mat3Doub_I v1, Mat3Doub_I v2)
{
	return shape_cmp3(v1, v2) &&
		equals_vv(v1.p(), v2.p(), v2.size());
}

inline bool operator!=(Mat3Doub_I v1, Mat3Doub_I v2)
{ return !(v1 == v2); }

inline bool operator==(Mat3Comp_I v1, Mat3Comp_I v2)
{
	return shape_cmp3(v1, v2) &&
		equals_vv(v1.p(), v2.p(), v2.size());
}

inline bool operator!=(Mat3Comp_I v1, Mat3Comp_I v2)
{ return !(v1 == v2); }

inline bool operator==(DcmatDoub_I v1, ScmatDoub_I v2)
{
	if (!shape_cmp2(v1, v2))
		return false;
	for (Long i = 0; i < v1.n0(); ++i)
		for (Long j = 0; j < v1.n1(); ++j)
			if (v1(i, j) != v2(i, j))
				return false;
	return true;
}

inline bool operator!=(DcmatDoub_I v1, ScmatDoub_I v2)
{ return !(v1 == v2); }


inline bool operator==(Jcmat3Doub_I v1, Scmat3Doub_I v2)
{
	if (!shape_cmp3(v1, v2))
		return false;
	for (Long i = 0; i < v1.n0(); ++i)
		for (Long j = 0; j < v1.n1(); ++j)
			for (Long k = 0; k < v1.n2(); ++k)
				if (v1(i, j, k) != v2(i, j, k))
					return false;
	return true;
}

inline bool operator!=(Jcmat3Doub_I v1, Scmat3Doub_I v2)
{ return !(v1 == v2); }


inline bool operator==(SvecInt_I v1, DvecInt_I v2)
{
	if (!shape_cmp1(v1, v2))
		return false;
	for (Long i = 0; i < v1.size(); ++i) {
		if (v1[i] != v2[i])
			return false;
	}
	return true;
}

inline bool operator!=(SvecInt_I v1, DvecInt_I v2)
{ return !(v1 == v2); }

inline bool operator==(SvecLlong_I v1, DvecLlong_I v2)
{
	if (!shape_cmp1(v1, v2))
		return false;
	for (Long i = 0; i < v1.size(); ++i) {
		if (v1[i] != v2[i])
			return false;
	}
	return true;
}

inline bool operator!=(SvecLlong_I v1, DvecLlong_I v2)
{ return !(v1 == v2); }

inline bool operator==(SvecDoub_I v1, DvecDoub_I v2)
{
	if (!shape_cmp1(v1, v2))
		return false;
	for (Long i = 0; i < v1.size(); ++i) {
		if (v1[i] != v2[i])
			return false;
	}
	return true;
}

inline bool operator!=(SvecDoub_I v1, DvecDoub_I v2)
{ return !(v1 == v2); }

inline bool operator==(DvecLlong_I v1, DvecLlong_I v2)
{
	if (!shape_cmp1(v1, v2))
		return false;
	for (Long i = 0; i < v1.size(); ++i) {
		if (v1[i] != v2[i])
			return false;
	}
	return true;
}

inline bool operator!=(DvecLlong_I v1, DvecLlong_I v2)
{ return !(v1 == v2); }

inline bool operator==(DvecInt_I v1, DvecInt_I v2)
{
	if (!shape_cmp1(v1, v2))
		return false;
	for (Long i = 0; i < v1.size(); ++i) {
		if (v1[i] != v2[i])
			return false;
	}
	return true;
}

inline bool operator!=(DvecInt_I v1, DvecInt_I v2)
{ return !(v1 == v2); }

inline bool operator==(DvecDoub_I v1, DvecDoub_I v2)
{
	if (!shape_cmp1(v1, v2))
		return false;
	for (Long i = 0; i < v1.size(); ++i) {
		if (v1[i] != v2[i])
			return false;
	}
	return true;
}

inline bool operator!=(DvecDoub_I v1, DvecDoub_I v2)
{ return !(v1 == v2); }

inline bool operator==(Cmat3Comp_I v1, Cmat3Comp_I v2)
{
	return shape_cmp3(v1, v2) &&
		equals_vv(v1.p(), v2.p(), v2.size());
}

inline bool operator!=(Cmat3Comp_I v1, Cmat3Comp_I v2)
{ return !(v1 == v2); }

inline bool operator==(Cmat3Comp_I v1, Cmat3Doub_I v2)
{
	return shape_cmp3(v1, v2) &&
		equals_vv(v1.p(), v2.p(), v2.size());
}

inline bool operator!=(Cmat3Comp_I v1, Cmat3Doub_I v2)
{ return !(v1 == v2); }

inline bool operator==(Cmat3Doub_I v1, Cmat3Doub_I v2)
{
	return shape_cmp3(v1, v2) &&
		equals_vv(v1.p(), v2.p(), v2.size());
}

inline bool operator!=(Cmat3Doub_I v1, Cmat3Doub_I v2)
{ return !(v1 == v2); }


inline bool operator==(VecBool_I v1, VecBool_I v2)
{
	for (Long i = 0; i < v1.size(); ++i)
		if (v1[i] != v2[i])
			return false;
	return true;
}

inline bool operator!=(VecBool_I v1, VecBool_I v2)
{ return !(v1 == v2); }

inline bool operator==(SvecInt_I v, Int_I s)
{ return equals_vs(v.p(), s, v.size()); }

inline bool operator!=(SvecInt_I v, Int_I s)
{ return !(v == s); }

inline bool operator==(SvecLlong_I v, Llong_I s)
{ return equals_vs(v.p(), s, v.size()); }

inline bool operator!=(SvecLlong_I v, Llong_I s)
{ return !(v == s); }

inline bool operator==(SvecDoub_I v, Doub_I s)
{ return equals_vs(v.p(), s, v.size()); }

inline bool operator!=(SvecDoub_I v, Doub_I s)
{ return !(v == s); }


inline bool operator==(SvecComp_I v, Comp_I s)
{ return equals_vs(v.p(), s, v.size()); }

inline bool operator!=(SvecComp_I v, Comp_I s)
{ return !(v == s); }


inline bool operator==(DvecInt_I v, Int_I s)
{
	for (Long i = 0; i < v.size(); ++i)
		if (v[i] != s)
			return false;
	return true;
}

inline bool operator!=(DvecInt_I v, Int_I s)
{ return !(v == s); }

inline bool operator==(DvecDoub_I v, Doub_I s)
{
	for (Long i = 0; i < v.size(); ++i)
		if (v[i] != s)
			return false;
	return true;
}

inline bool operator!=(DvecDoub_I v, Doub_I s)
{ return !(v == s); }


} // namespace slisc
