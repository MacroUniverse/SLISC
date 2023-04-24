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
#include "../dense/Dcmat.h"
#include "../dense/Jcmat3.h"

namespace slisc {
inline Bool equals_vs(const Comp *v, Doub_I s, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		if (v[i] != s)
			return false;
	return true;
}


inline Bool equals_vs(const Int *v, Int_I s, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		if (v[i] != s)
			return false;
	return true;
}

inline Bool equals_vs(const Llong *v, Llong_I s, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		if (v[i] != s)
			return false;
	return true;
}

inline Bool equals_vs(const Doub *v, Doub_I s, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		if (v[i] != s)
			return false;
	return true;
}

inline Bool equals_vs(const Comp *v, Comp_I s, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		if (v[i] != s)
			return false;
	return true;
}


inline Bool equals_vv(const Int *v1, const Int *v2, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		if (v1[i] != v2[i])
			return false;
	return true;
}

inline Bool equals_vv(const Char *v1, const Char *v2, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		if (v1[i] != v2[i])
			return false;
	return true;
}

inline Bool equals_vv(const Uchar *v1, const Uchar *v2, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		if (v1[i] != v2[i])
			return false;
	return true;
}

inline Bool equals_vv(const Llong *v1, const Llong *v2, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		if (v1[i] != v2[i])
			return false;
	return true;
}

inline Bool equals_vv(const Doub *v1, const Doub *v2, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		if (v1[i] != v2[i])
			return false;
	return true;
}

inline Bool equals_vv(const Doub *v1, const Comp *v2, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		if (v1[i] != v2[i])
			return false;
	return true;
}

inline Bool equals_vv(const Comp *v1, const Comp *v2, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		if (v1[i] != v2[i])
			return false;
	return true;
}

inline Bool equals_vv(const Comp *v1, const Doub *v2, Long_I N)
{
	for (Long i = 0; i < N; ++i)
		if (v1[i] != v2[i])
			return false;
	return true;
}


inline Bool shape_cmp(vecInt_I v1, vecInt_I v2) {return (Long)v1.size() == (Long)v2.size();}

inline Bool shape_cmp(CmatDoub_I v1, CmatDoub_I v2) {return v1.n0() == v2.n0() && v1.n1() == v2.n1();}


inline Bool shape_cmp(Mat3Doub_I v1, Mat3Comp_I v2) {return v1.n0() == v2.n0() && v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(CmatComp_I v1, CmatComp_I v2) {return v1.n0() == v2.n0() && v1.n1() == v2.n1();}

inline Bool shape_cmp(CmatComp_I v1, CmatInt_I v2) {return v1.n0() == v2.n0() && v1.n1() == v2.n1();}

inline Bool shape_cmp(VecInt_I v1, VecInt_I v2) {return (Long)v1.size() == (Long)v2.size();}

inline Bool shape_cmp(VecInt_I v1, VecLlong_I v2) {return (Long)v1.size() == (Long)v2.size();}

inline Bool shape_cmp(VecLlong_I v1, VecLlong_I v2) {return (Long)v1.size() == (Long)v2.size();}

inline Bool shape_cmp(VecDoub_I v1, VecLlong_I v2) {return (Long)v1.size() == (Long)v2.size();}

inline Bool shape_cmp(vecLlong_I v1, vecLlong_I v2) {return (Long)v1.size() == (Long)v2.size();}

inline Bool shape_cmp(vecLlong_I v1, vecStr_I v2) {return (Long)v1.size() == (Long)v2.size();}

inline Bool shape_cmp(vecStr_I v1, vecStr_I v2) {return (Long)v1.size() == (Long)v2.size();}

inline Bool shape_cmp(vecStr32_I v1, vecStr32_I v2) {return (Long)v1.size() == (Long)v2.size();}

inline Bool shape_cmp(VecDoub_I v1, VecComp_I v2) {return (Long)v1.size() == (Long)v2.size();}

inline Bool shape_cmp(VecDoub_I v1, VecDoub_I v2) {return (Long)v1.size() == (Long)v2.size();}

inline Bool shape_cmp(VecComp_I v1, VecDoub_I v2) {return (Long)v1.size() == (Long)v2.size();}

inline Bool shape_cmp(VecComp_I v1, VecComp_I v2) {return (Long)v1.size() == (Long)v2.size();}

inline Bool shape_cmp(SvecDoub_I v1, VecDoub_I v2) {return (Long)v1.size() == (Long)v2.size();}

inline Bool shape_cmp(SvecDoub_I v1, SvecDoub_I v2) {return (Long)v1.size() == (Long)v2.size();}

inline Bool shape_cmp(SvecDoub_I v1, SvecComp_I v2) {return (Long)v1.size() == (Long)v2.size();}

inline Bool shape_cmp(SvecComp_I v1, VecComp_I v2) {return (Long)v1.size() == (Long)v2.size();}

inline Bool shape_cmp(DvecComp_I v1, SvecDoub_I v2) {return (Long)v1.size() == (Long)v2.size();}

inline Bool shape_cmp(Cmat3Comp_I v1, Jcmat3Comp_I v2) {return v1.n0() == v2.n0() && v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(Cmat3Comp_I v1, Cmat3Doub_I v2) {return v1.n0() == v2.n0() && v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(Cmat3Comp_I v1, Cmat3Comp_I v2) {return v1.n0() == v2.n0() && v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(vecDoub_I v1, vecDoub_I v2) {return (Long)v1.size() == (Long)v2.size();}

inline Bool shape_cmp(VecDoub_I v1, SvecDoub_I v2) {return (Long)v1.size() == (Long)v2.size();}

inline Bool shape_cmp(VecComp_I v1, SvecComp_I v2) {return (Long)v1.size() == (Long)v2.size();}

inline Bool shape_cmp(SvecComp_I v1, VecDoub_I v2) {return (Long)v1.size() == (Long)v2.size();}

inline Bool shape_cmp(SvecComp_I v1, SvecComp_I v2) {return (Long)v1.size() == (Long)v2.size();}

inline Bool shape_cmp(DvecDoub_I v1, SvecDoub_I v2) {return (Long)v1.size() == (Long)v2.size();}

inline Bool shape_cmp(DvecComp_I v1, VecComp_I v2) {return (Long)v1.size() == (Long)v2.size();}

inline Bool shape_cmp(DvecComp_I v1, SvecComp_I v2) {return (Long)v1.size() == (Long)v2.size();}

inline Bool shape_cmp(CmatInt_I v1, CmatInt_I v2) {return v1.n0() == v2.n0() && v1.n1() == v2.n1();}

inline Bool shape_cmp(CmatLlong_I v1, CmatLlong_I v2) {return v1.n0() == v2.n0() && v1.n1() == v2.n1();}

inline Bool shape_cmp(CmatComp_I v1, CmatDoub_I v2) {return v1.n0() == v2.n0() && v1.n1() == v2.n1();}

inline Bool shape_cmp(MatDoub_I v1, MatDoub_I v2) {return v1.n0() == v2.n0() && v1.n1() == v2.n1();}

inline Bool shape_cmp(MatComp_I v1, MatComp_I v2) {return v1.n0() == v2.n0() && v1.n1() == v2.n1();}

inline Bool shape_cmp(ScmatComp_I v1, ScmatDoub_I v2) {return v1.n0() == v2.n0() && v1.n1() == v2.n1();}

inline Bool shape_cmp(ScmatComp_I v1, ScmatComp_I v2) {return v1.n0() == v2.n0() && v1.n1() == v2.n1();}

inline Bool shape_cmp(DcmatComp_I v1, DcmatDoub_I v2) {return v1.n0() == v2.n0() && v1.n1() == v2.n1();}

inline Bool shape_cmp(Mat3Doub_I v1, Mat3Doub_I v2) {return v1.n0() == v2.n0() && v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(Mat3Comp_I v1, Mat3Comp_I v2) {return v1.n0() == v2.n0() && v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(VecComp_I v1, SvecDoub_I v2) {return (Long)v1.size() == (Long)v2.size();}

inline Bool shape_cmp(DcmatComp_I v1, DcmatComp_I v2) {return v1.n0() == v2.n0() && v1.n1() == v2.n1();}

inline Bool shape_cmp(ScmatDoub_I v1, CmatDoub_I v2) {return v1.n0() == v2.n0() && v1.n1() == v2.n1();}

inline Bool shape_cmp(VecChar_I v1, VecChar_I v2) {return (Long)v1.size() == (Long)v2.size();}

inline Bool shape_cmp(VecUchar_I v1, VecUchar_I v2) {return (Long)v1.size() == (Long)v2.size();}

inline Bool shape_cmp(MatLlong_I v1, MatLlong_I v2) {return v1.n0() == v2.n0() && v1.n1() == v2.n1();}

inline Bool shape_cmp(MatDoub_I v1, CmatDoub_I v2) {return v1.n0() == v2.n0() && v1.n1() == v2.n1();}

inline Bool shape_cmp(MatInt_I v1, MatInt_I v2) {return v1.n0() == v2.n0() && v1.n1() == v2.n1();}

inline Bool shape_cmp(CmatDoub_I v1, MatDoub_I v2) {return v1.n0() == v2.n0() && v1.n1() == v2.n1();}

inline Bool shape_cmp(CmatComp_I v1, MatComp_I v2) {return v1.n0() == v2.n0() && v1.n1() == v2.n1();}

inline Bool shape_cmp(Cmat3Llong_I v1, Cmat3Llong_I v2) {return v1.n0() == v2.n0() && v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(Cmat3Doub_I v1, Cmat3Doub_I v2) {return v1.n0() == v2.n0() && v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(DcmatDoub_I v1, CmatDoub_I v2) {return v1.n0() == v2.n0() && v1.n1() == v2.n1();}

inline Bool shape_cmp(Jcmat3Doub_I v1, Cmat3Doub_I v2) {return v1.n0() == v2.n0() && v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(VecInt_I v1, DvecInt_I v2) {return (Long)v1.size() == (Long)v2.size();}

inline Bool shape_cmp(VecLlong_I v1, DvecLlong_I v2) {return (Long)v1.size() == (Long)v2.size();}

inline Bool shape_cmp(DvecLlong_I v1, DvecLlong_I v2) {return (Long)v1.size() == (Long)v2.size();}

inline Bool shape_cmp(VecDoub_I v1, DvecDoub_I v2) {return (Long)v1.size() == (Long)v2.size();}

inline Bool shape_cmp(ScmatDoub_I v1, ScmatDoub_I v2) {return v1.n0() == v2.n0() && v1.n1() == v2.n1();}

inline Bool shape_cmp(CmatDoub_I v1, ScmatDoub_I v2) {return v1.n0() == v2.n0() && v1.n1() == v2.n1();}

inline Bool shape_cmp(CmatComp_I v1, ScmatComp_I v2) {return v1.n0() == v2.n0() && v1.n1() == v2.n1();}

inline Bool shape_cmp(DvecComp_I v1, DvecComp_I v2) {return (Long)v1.size() == (Long)v2.size();}

inline Bool shape_cmp(VecInt_I v1, SvecInt_I v2) {return (Long)v1.size() == (Long)v2.size();}

inline Bool shape_cmp(VecComp_I v1, DvecComp_I v2) {return (Long)v1.size() == (Long)v2.size();}

inline Bool shape_cmp(SvecDoub_I v1, DvecDoub_I v2) {return (Long)v1.size() == (Long)v2.size();}

inline Bool shape_cmp(SvecComp_I v1, SvecDoub_I v2) {return (Long)v1.size() == (Long)v2.size();}

inline Bool shape_cmp(SvecComp_I v1, DvecComp_I v2) {return (Long)v1.size() == (Long)v2.size();}

inline Bool shape_cmp(CmatLlong_I v1, ScmatLlong_I v2) {return v1.n0() == v2.n0() && v1.n1() == v2.n1();}

inline Bool shape_cmp(Cmat3Int_I v1, Cmat3Int_I v2) {return v1.n0() == v2.n0() && v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(McooDoub_I v1, McooDoub_I v2) {return v1.n0() == v2.n0() && v1.n1() == v2.n1();}

inline Bool shape_cmp(McooComp_I v1, McooDoub_I v2) {return v1.n0() == v2.n0() && v1.n1() == v2.n1();}

inline Bool shape_cmp(McooDoub_I v1, ScmatDoub_I v2) {return v1.n0() == v2.n0() && v1.n1() == v2.n1();}

inline Bool shape_cmp(McooComp_I v1, CmatComp_I v2) {return v1.n0() == v2.n0() && v1.n1() == v2.n1();}

inline Bool shape_cmp(CmatInt_I v1, McooInt_I v2) {return v1.n0() == v2.n0() && v1.n1() == v2.n1();}

inline Bool shape_cmp(CmatDoub_I v1, McooDoub_I v2) {return v1.n0() == v2.n0() && v1.n1() == v2.n1();}

inline Bool shape_cmp(CmobdDoub_I v1, McooDoub_I v2) {return v1.n0() == v2.n0() && v1.n1() == v2.n1();}

inline Bool shape_cmp(CmobdInt_I v1, McooInt_I v2) {return v1.n0() == v2.n0() && v1.n1() == v2.n1();}

inline Bool shape_cmp(CmatDoub_I v1, CmobdDoub_I v2) {return v1.n0() == v2.n0() && v1.n1() == v2.n1();}

inline Bool shape_cmp(CmatDoub_I v1, CbandDoub_I v2) {return v1.n0() == v2.n0() && v1.n1() == v2.n1();}

inline Bool shape_cmp(CmatComp_I v1, CbandComp_I v2) {return v1.n0() == v2.n0() && v1.n1() == v2.n1();}

inline Bool shape_cmp(CbandComp_I v1, CmatComp_I v2) {return v1.n0() == v2.n0() && v1.n1() == v2.n1();}

inline Bool shape_cmp(CbandDoub_I v1, CmatDoub_I v2) {return v1.n0() == v2.n0() && v1.n1() == v2.n1();}

inline Bool shape_cmp(CbandComp_I v1, ScmatDoub_I v2) {return v1.n0() == v2.n0() && v1.n1() == v2.n1();}

inline Bool shape_cmp(ScmatDoub_I v1, CbandComp_I v2) {return v1.n0() == v2.n0() && v1.n1() == v2.n1();}

inline Bool shape_cmp(McooDoub_I v1, CbandComp_I v2) {return v1.n0() == v2.n0() && v1.n1() == v2.n1();}

inline Bool shape_cmp(CbandComp_I v1, CbandComp_I v2) {return v1.n0() == v2.n0() && v1.n1() == v2.n1();}

inline Bool shape_cmp(vecStr_I v1, VecInt_I v2) {return (Long)v1.size() == (Long)v2.size();}

inline Bool shape_cmp(vecStr_I v1, vecLlong_I v2) {return (Long)v1.size() == (Long)v2.size();}

inline Bool shape_cmp(DvecInt_I v1, DvecInt_I v2) {return (Long)v1.size() == (Long)v2.size();}

inline Bool shape_cmp(DvecDoub_I v1, DvecDoub_I v2) {return (Long)v1.size() == (Long)v2.size();}

inline Bool shape_cmp(DcmatDoub_I v1, DcmatDoub_I v2) {return v1.n0() == v2.n0() && v1.n1() == v2.n1();}

inline Bool shape_cmp(DcmatInt_I v1, DcmatInt_I v2) {return v1.n0() == v2.n0() && v1.n1() == v2.n1();}

inline Bool shape_cmp(DcmatLlong_I v1, DcmatLlong_I v2) {return v1.n0() == v2.n0() && v1.n1() == v2.n1();}

inline Bool shape_cmp(Jcmat3Doub_I v1, Jcmat3Doub_I v2) {return v1.n0() == v2.n0() && v1.n1() == v2.n1() && v1.n2() == v2.n2();}

inline Bool shape_cmp(Jcmat3Comp_I v1, Jcmat3Comp_I v2) {return v1.n0() == v2.n0() && v1.n1() == v2.n1() && v1.n2() == v2.n2();}


inline void assert_same_shape(vecInt_I v1, vecInt_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(CmatComp_I v1, CmatInt_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(VecInt_I v1, VecInt_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(VecInt_I v1, VecLlong_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(VecLlong_I v1, VecLlong_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(VecDoub_I v1, VecLlong_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(vecLlong_I v1, vecLlong_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(vecLlong_I v1, vecStr_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(vecStr_I v1, vecStr_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(vecStr32_I v1, vecStr32_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(VecDoub_I v1, VecComp_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(VecDoub_I v1, VecDoub_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(CmatComp_I v1, CmatComp_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(VecComp_I v1, VecDoub_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(VecComp_I v1, VecComp_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(SvecDoub_I v1, VecDoub_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(SvecDoub_I v1, SvecDoub_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(SvecDoub_I v1, SvecComp_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(SvecComp_I v1, VecComp_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(DvecComp_I v1, SvecDoub_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(Cmat3Comp_I v1, Jcmat3Comp_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(Cmat3Comp_I v1, Cmat3Doub_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(Cmat3Comp_I v1, Cmat3Comp_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(vecDoub_I v1, vecDoub_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(VecDoub_I v1, SvecDoub_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(VecComp_I v1, SvecComp_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(SvecComp_I v1, VecDoub_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(SvecComp_I v1, SvecComp_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(DvecDoub_I v1, SvecDoub_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(DvecComp_I v1, VecComp_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(DvecComp_I v1, SvecComp_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(CmatInt_I v1, CmatInt_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(CmatLlong_I v1, CmatLlong_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(CmatDoub_I v1, CmatDoub_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(CmatComp_I v1, CmatDoub_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(MatDoub_I v1, MatDoub_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(MatComp_I v1, MatComp_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(ScmatComp_I v1, ScmatDoub_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(ScmatComp_I v1, ScmatComp_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(DcmatComp_I v1, DcmatDoub_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(Mat3Doub_I v1, Mat3Doub_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(Mat3Comp_I v1, Mat3Comp_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(VecComp_I v1, SvecDoub_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(DcmatComp_I v1, DcmatComp_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(ScmatDoub_I v1, CmatDoub_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(DvecComp_I v1, DvecComp_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(VecInt_I v1, DvecInt_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(VecInt_I v1, SvecInt_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(VecComp_I v1, DvecComp_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(SvecDoub_I v1, DvecDoub_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(SvecComp_I v1, SvecDoub_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(SvecComp_I v1, DvecComp_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(CmatLlong_I v1, ScmatLlong_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(CmatDoub_I v1, MatDoub_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(MatDoub_I v1, CmatDoub_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(Cmat3Int_I v1, Cmat3Int_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(Cmat3Llong_I v1, Cmat3Llong_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(Cmat3Doub_I v1, Cmat3Doub_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(McooDoub_I v1, McooDoub_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(McooComp_I v1, McooDoub_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(McooDoub_I v1, ScmatDoub_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(McooComp_I v1, CmatComp_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(CmatInt_I v1, McooInt_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(CmatDoub_I v1, McooDoub_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(CmobdDoub_I v1, McooDoub_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(CmobdInt_I v1, McooInt_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(CmatDoub_I v1, CmobdDoub_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(CmatDoub_I v1, CbandDoub_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(CmatComp_I v1, CbandComp_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(CbandComp_I v1, CmatComp_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(CbandDoub_I v1, CmatDoub_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(CbandComp_I v1, ScmatDoub_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(ScmatDoub_I v1, CbandComp_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(McooDoub_I v1, CbandComp_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(CbandComp_I v1, CbandComp_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(vecStr_I v1, VecInt_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(vecStr_I v1, vecLlong_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(DcmatDoub_I v1, DcmatDoub_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(DcmatInt_I v1, DcmatInt_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(DcmatLlong_I v1, DcmatLlong_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(Jcmat3Doub_I v1, Jcmat3Doub_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(Jcmat3Comp_I v1, Jcmat3Comp_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(DvecInt_I v1, DvecInt_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(DvecLlong_I v1, DvecLlong_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(DvecDoub_I v1, DvecDoub_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(ScmatDoub_I v1, ScmatDoub_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(CmatDoub_I v1, ScmatDoub_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(CmatComp_I v1, ScmatComp_I v2)
{
#ifdef SLS_CHECK_SHAPES
	if (!shape_cmp(v1, v2))
		SLS_ERR("wrong shape!");
#endif
}


inline void assert_same_shape(CmatComp_I v1, CmatInt_I v2, CmatDoub_I v3)
{ assert_same_shape(v1, v2); assert_same_shape(v1, v3); }

inline void assert_same_shape(vecInt_I v1, vecInt_I v2, vecInt_I v3)
{ assert_same_shape(v1, v2); assert_same_shape(v1, v3); }

inline void assert_same_shape(vecLlong_I v1, vecLlong_I v2, vecLlong_I v3)
{ assert_same_shape(v1, v2); assert_same_shape(v1, v3); }

inline void assert_same_shape(VecInt_I v1, VecInt_I v2, VecInt_I v3)
{ assert_same_shape(v1, v2); assert_same_shape(v1, v3); }

inline void assert_same_shape(VecLlong_I v1, VecLlong_I v2, VecLlong_I v3)
{ assert_same_shape(v1, v2); assert_same_shape(v1, v3); }

inline void assert_same_shape(VecDoub_I v1, VecDoub_I v2, VecDoub_I v3)
{ assert_same_shape(v1, v2); assert_same_shape(v1, v3); }

inline void assert_same_shape(VecComp_I v1, VecComp_I v2, VecComp_I v3)
{ assert_same_shape(v1, v2); assert_same_shape(v1, v3); }

inline void assert_same_shape(SvecDoub_I v1, SvecDoub_I v2, SvecDoub_I v3)
{ assert_same_shape(v1, v2); assert_same_shape(v1, v3); }

inline void assert_same_shape(SvecComp_I v1, SvecComp_I v2, SvecComp_I v3)
{ assert_same_shape(v1, v2); assert_same_shape(v1, v3); }

inline void assert_same_shape(SvecComp_I v1, VecComp_I v2, SvecComp_I v3)
{ assert_same_shape(v1, v2); assert_same_shape(v1, v3); }

inline void assert_same_shape(DvecComp_I v1, SvecComp_I v2, DvecComp_I v3)
{ assert_same_shape(v1, v2); assert_same_shape(v1, v3); }

inline void assert_same_shape(CmatInt_I v1, CmatInt_I v2, CmatInt_I v3)
{ assert_same_shape(v1, v2); assert_same_shape(v1, v3); }

inline void assert_same_shape(CmatLlong_I v1, CmatLlong_I v2, CmatLlong_I v3)
{ assert_same_shape(v1, v2); assert_same_shape(v1, v3); }

inline void assert_same_shape(CmatDoub_I v1, CmatDoub_I v2, CmatDoub_I v3)
{ assert_same_shape(v1, v2); assert_same_shape(v1, v3); }

inline void assert_same_shape(CmatComp_I v1, CmatComp_I v2, CmatComp_I v3)
{ assert_same_shape(v1, v2); assert_same_shape(v1, v3); }

inline void assert_same_shape(SvecDoub_I v1, VecDoub_I v2, SvecDoub_I v3)
{ assert_same_shape(v1, v2); assert_same_shape(v1, v3); }


inline Bool operator==(VecChar_I v1, VecChar_I v2)
{
	return shape_cmp(v1, v2) &&
		equals_vv(v1.p(), v2.p(), v2.size());
}

inline Bool operator!=(VecChar_I v1, VecChar_I v2)
{ return !(v1 == v2); }

inline Bool operator==(VecUchar_I v1, VecUchar_I v2)
{
	return shape_cmp(v1, v2) &&
		equals_vv(v1.p(), v2.p(), v2.size());
}

inline Bool operator!=(VecUchar_I v1, VecUchar_I v2)
{ return !(v1 == v2); }

inline Bool operator==(VecInt_I v1, VecInt_I v2)
{
	return shape_cmp(v1, v2) &&
		equals_vv(v1.p(), v2.p(), v2.size());
}

inline Bool operator!=(VecInt_I v1, VecInt_I v2)
{ return !(v1 == v2); }

inline Bool operator==(VecLlong_I v1, VecLlong_I v2)
{
	return shape_cmp(v1, v2) &&
		equals_vv(v1.p(), v2.p(), v2.size());
}

inline Bool operator!=(VecLlong_I v1, VecLlong_I v2)
{ return !(v1 == v2); }

inline Bool operator==(VecDoub_I v1, VecDoub_I v2)
{
	return shape_cmp(v1, v2) &&
		equals_vv(v1.p(), v2.p(), v2.size());
}

inline Bool operator!=(VecDoub_I v1, VecDoub_I v2)
{ return !(v1 == v2); }


inline Bool operator==(VecDoub_I v1, VecComp_I v2)
{
	return shape_cmp(v1, v2) &&
		equals_vv(v1.p(), v2.p(), v2.size());
}

inline Bool operator!=(VecDoub_I v1, VecComp_I v2)
{ return !(v1 == v2); }


inline Bool operator==(VecComp_I v1, VecComp_I v2)
{
	return shape_cmp(v1, v2) &&
		equals_vv(v1.p(), v2.p(), v2.size());
}

inline Bool operator!=(VecComp_I v1, VecComp_I v2)
{ return !(v1 == v2); }


inline Bool operator==(MatLlong_I v1, MatLlong_I v2)
{
	return shape_cmp(v1, v2) &&
		equals_vv(v1.p(), v2.p(), v2.size());
}

inline Bool operator!=(MatLlong_I v1, MatLlong_I v2)
{ return !(v1 == v2); }

inline Bool operator==(MatDoub_I v1, MatDoub_I v2)
{
	return shape_cmp(v1, v2) &&
		equals_vv(v1.p(), v2.p(), v2.size());
}

inline Bool operator!=(MatDoub_I v1, MatDoub_I v2)
{ return !(v1 == v2); }

inline Bool operator==(MatDoub_I v1, CmatDoub_I v2)
{
	if (!shape_cmp(v1, v2))
		return false;
	for (Long i = 0; i < v1.n0(); ++i)
		for (Long j = 0; j < v1.n1(); ++j)
			if (v1(i, j) != v2(i, j))
				return false;
	return true;
}

inline Bool operator!=(MatDoub_I v1, CmatDoub_I v2)
{ return !(v1 == v2); }

inline Bool operator==(MatInt_I v1, MatInt_I v2)
{
	return shape_cmp(v1, v2) &&
		equals_vv(v1.p(), v2.p(), v2.size());
}

inline Bool operator!=(MatInt_I v1, MatInt_I v2)
{ return !(v1 == v2); }

inline Bool operator==(MatComp_I v1, MatComp_I v2)
{
	return shape_cmp(v1, v2) &&
		equals_vv(v1.p(), v2.p(), v2.size());
}

inline Bool operator!=(MatComp_I v1, MatComp_I v2)
{ return !(v1 == v2); }

inline Bool operator==(CmatInt_I v1, CmatInt_I v2)
{
	return shape_cmp(v1, v2) &&
		equals_vv(v1.p(), v2.p(), v2.size());
}

inline Bool operator!=(CmatInt_I v1, CmatInt_I v2)
{ return !(v1 == v2); }

inline Bool operator==(CmatLlong_I v1, CmatLlong_I v2)
{
	return shape_cmp(v1, v2) &&
		equals_vv(v1.p(), v2.p(), v2.size());
}

inline Bool operator!=(CmatLlong_I v1, CmatLlong_I v2)
{ return !(v1 == v2); }

inline Bool operator==(CmatDoub_I v1, CmatDoub_I v2)
{
	return shape_cmp(v1, v2) &&
		equals_vv(v1.p(), v2.p(), v2.size());
}

inline Bool operator!=(CmatDoub_I v1, CmatDoub_I v2)
{ return !(v1 == v2); }


inline Bool operator==(CmatDoub_I v1, MatDoub_I v2)
{
	if (!shape_cmp(v1, v2))
		return false;
	for (Long i = 0; i < v1.n0(); ++i)
		for (Long j = 0; j < v1.n1(); ++j)
			if (v1(i, j) != v2(i, j))
				return false;
	return true;
}

inline Bool operator!=(CmatDoub_I v1, MatDoub_I v2)
{ return !(v1 == v2); }

inline Bool operator==(CmatComp_I v1, MatComp_I v2)
{
	if (!shape_cmp(v1, v2))
		return false;
	for (Long i = 0; i < v1.n0(); ++i)
		for (Long j = 0; j < v1.n1(); ++j)
			if (v1(i, j) != v2(i, j))
				return false;
	return true;
}

inline Bool operator!=(CmatComp_I v1, MatComp_I v2)
{ return !(v1 == v2); }

inline Bool operator==(CmatComp_I v1, CmatComp_I v2)
{
	return shape_cmp(v1, v2) &&
		equals_vv(v1.p(), v2.p(), v2.size());
}

inline Bool operator!=(CmatComp_I v1, CmatComp_I v2)
{ return !(v1 == v2); }


inline Bool operator==(Cmat3Llong_I v1, Cmat3Llong_I v2)
{
	return shape_cmp(v1, v2) &&
		equals_vv(v1.p(), v2.p(), v2.size());
}

inline Bool operator!=(Cmat3Llong_I v1, Cmat3Llong_I v2)
{ return !(v1 == v2); }

inline Bool operator==(Cmat3Doub_I v1, Cmat3Doub_I v2)
{
	return shape_cmp(v1, v2) &&
		equals_vv(v1.p(), v2.p(), v2.size());
}

inline Bool operator!=(Cmat3Doub_I v1, Cmat3Doub_I v2)
{ return !(v1 == v2); }


inline Bool operator==(Cmat3Comp_I v1, Cmat3Comp_I v2)
{
	return shape_cmp(v1, v2) &&
		equals_vv(v1.p(), v2.p(), v2.size());
}

inline Bool operator!=(Cmat3Comp_I v1, Cmat3Comp_I v2)
{ return !(v1 == v2); }


inline Bool operator==(Mat3Doub_I v1, Mat3Doub_I v2)
{
	return shape_cmp(v1, v2) &&
		equals_vv(v1.p(), v2.p(), v2.size());
}

inline Bool operator!=(Mat3Doub_I v1, Mat3Doub_I v2)
{ return !(v1 == v2); }

inline Bool operator==(Mat3Comp_I v1, Mat3Comp_I v2)
{
	return shape_cmp(v1, v2) &&
		equals_vv(v1.p(), v2.p(), v2.size());
}

inline Bool operator!=(Mat3Comp_I v1, Mat3Comp_I v2)
{ return !(v1 == v2); }

inline Bool operator==(DcmatDoub_I v1, CmatDoub_I v2)
{
	if (!shape_cmp(v1, v2))
		return false;
	for (Long i = 0; i < v1.n0(); ++i)
		for (Long j = 0; j < v1.n1(); ++j)
			if (v1(i, j) != v2(i, j))
				return false;
	return true;
}

inline Bool operator!=(DcmatDoub_I v1, CmatDoub_I v2)
{ return !(v1 == v2); }


inline Bool operator==(Jcmat3Doub_I v1, Cmat3Doub_I v2)
{
	if (!shape_cmp(v1, v2))
		return false;
	for (Long i = 0; i < v1.n0(); ++i)
		for (Long j = 0; j < v1.n1(); ++j)
			for (Long k = 0; k < v1.n2(); ++k)
				if (v1(i, j, k) != v2(i, j, k))
					return false;
	return true;
}

inline Bool operator!=(Jcmat3Doub_I v1, Cmat3Doub_I v2)
{ return !(v1 == v2); }


inline Bool operator==(VecInt_I v1, DvecInt_I v2)
{
	if (!shape_cmp(v1, v2))
		return false;
	for (Long i = 0; i < v1.size(); ++i) {
		if (v1[i] != v2[i])
			return false;
	}
	return true;
}

inline Bool operator!=(VecInt_I v1, DvecInt_I v2)
{ return !(v1 == v2); }

inline Bool operator==(VecLlong_I v1, DvecLlong_I v2)
{
	if (!shape_cmp(v1, v2))
		return false;
	for (Long i = 0; i < v1.size(); ++i) {
		if (v1[i] != v2[i])
			return false;
	}
	return true;
}

inline Bool operator!=(VecLlong_I v1, DvecLlong_I v2)
{ return !(v1 == v2); }

inline Bool operator==(DvecLlong_I v1, DvecLlong_I v2)
{
	if (!shape_cmp(v1, v2))
		return false;
	for (Long i = 0; i < v1.size(); ++i) {
		if (v1[i] != v2[i])
			return false;
	}
	return true;
}

inline Bool operator!=(DvecLlong_I v1, DvecLlong_I v2)
{ return !(v1 == v2); }

inline Bool operator==(VecDoub_I v1, DvecDoub_I v2)
{
	if (!shape_cmp(v1, v2))
		return false;
	for (Long i = 0; i < v1.size(); ++i) {
		if (v1[i] != v2[i])
			return false;
	}
	return true;
}

inline Bool operator!=(VecDoub_I v1, DvecDoub_I v2)
{ return !(v1 == v2); }

inline Bool operator==(DvecInt_I v1, DvecInt_I v2)
{
	if (!shape_cmp(v1, v2))
		return false;
	for (Long i = 0; i < v1.size(); ++i) {
		if (v1[i] != v2[i])
			return false;
	}
	return true;
}

inline Bool operator!=(DvecInt_I v1, DvecInt_I v2)
{ return !(v1 == v2); }

inline Bool operator==(DvecDoub_I v1, DvecDoub_I v2)
{
	if (!shape_cmp(v1, v2))
		return false;
	for (Long i = 0; i < v1.size(); ++i) {
		if (v1[i] != v2[i])
			return false;
	}
	return true;
}

inline Bool operator!=(DvecDoub_I v1, DvecDoub_I v2)
{ return !(v1 == v2); }

inline Bool operator==(Cmat3Comp_I v1, Cmat3Doub_I v2)
{
	return shape_cmp(v1, v2) &&
		equals_vv(v1.p(), v2.p(), v2.size());
}

inline Bool operator!=(Cmat3Comp_I v1, Cmat3Doub_I v2)
{ return !(v1 == v2); }


inline Bool operator==(VecBool_I v1, VecBool_I v2)
{
	for (Long i = 0; i < v1.size(); ++i)
		if (v1[i] != v2[i])
			return false;
	return true;
}

inline Bool operator!=(VecBool_I v1, VecBool_I v2)
{ return !(v1 == v2); }

inline Bool operator==(VecInt_I v, Int_I s)
{ return equals_vs(v.p(), s, v.size()); }

inline Bool operator!=(VecInt_I v, Int_I s)
{ return !(v == s); }

inline Bool operator==(VecLlong_I v, Llong_I s)
{ return equals_vs(v.p(), s, v.size()); }

inline Bool operator!=(VecLlong_I v, Llong_I s)
{ return !(v == s); }

inline Bool operator==(VecDoub_I v, Doub_I s)
{ return equals_vs(v.p(), s, v.size()); }

inline Bool operator!=(VecDoub_I v, Doub_I s)
{ return !(v == s); }


inline Bool operator==(VecComp_I v, Comp_I s)
{ return equals_vs(v.p(), s, v.size()); }

inline Bool operator!=(VecComp_I v, Comp_I s)
{ return !(v == s); }


inline Bool operator==(DvecInt_I v, Int_I s)
{
	for (Long i = 0; i < v.size(); ++i)
		if (v[i] != s)
			return false;
	return true;
}

inline Bool operator!=(DvecInt_I v, Int_I s)
{ return !(v == s); }

inline Bool operator==(DvecDoub_I v, Doub_I s)
{
	for (Long i = 0; i < v.size(); ++i)
		if (v[i] != s)
			return false;
	return true;
}

inline Bool operator!=(DvecDoub_I v, Doub_I s)
{ return !(v == s); }


inline Bool operator==(CmatLlong_I v, Llong_I s)
{ return equals_vs(v.p(), s, v.size()); }

inline Bool operator!=(CmatLlong_I v, Llong_I s)
{ return !(v == s); }

inline Bool operator==(CmatDoub_I v, Doub_I s)
{ return equals_vs(v.p(), s, v.size()); }

inline Bool operator!=(CmatDoub_I v, Doub_I s)
{ return !(v == s); }


inline Bool operator==(CmatComp_I v, Comp_I s)
{ return equals_vs(v.p(), s, v.size()); }

inline Bool operator!=(CmatComp_I v, Comp_I s)
{ return !(v == s); }


inline Bool operator==(MatDoub_I v, Doub_I s)
{ return equals_vs(v.p(), s, v.size()); }

inline Bool operator!=(MatDoub_I v, Doub_I s)
{ return !(v == s); }

inline Bool operator==(Mat3Doub_I v, Doub_I s)
{ return equals_vs(v.p(), s, v.size()); }

inline Bool operator!=(Mat3Doub_I v, Doub_I s)
{ return !(v == s); }

inline Bool operator==(Cmat3Doub_I v, Doub_I s)
{ return equals_vs(v.p(), s, v.size()); }

inline Bool operator!=(Cmat3Doub_I v, Doub_I s)
{ return !(v == s); }


} // namespace slisc
