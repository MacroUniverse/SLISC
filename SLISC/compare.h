#pragma once
#include "Vec.h"
#include "Mat.h"
#include "Mat3.h"
#include "Cmat.h"
#include "Cmat3.h"
#include "Cmat4.h"
#include "Cband.h"
#include "Mcoo.h"
#include "Cmobd.h"
#include "Svec.h"
#include "Dvec.h"
#include "Scmat.h"
#include "Scmat3.h"
#include "Dcmat.h"
#include "Jcmat3.h"

namespace slisc {
inline Bool equals_to_vs(const Comp *v, Comp_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        if (v[i] != s)
            return false;
    return true;
}


inline Bool equals_to_vv(const Int *v1, const Int *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        if (v1[i] != v2[i])
            return false;
    return true;
}

inline Bool equals_to_vv(const Llong *v1, const Llong *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        if (v1[i] != v2[i])
            return false;
    return true;
}


inline Bool shape_cmp(CmatDoub_I v1, CmatDoub_I v2) {return (Long)v1.n0() == (Long)v2.n0() && (Long)v1.n1() == (Long)v2.n1();}

inline Bool shape_cmp(CmatComp_I v1, CmatInt_I v2) {return (Long)v1.n0() == (Long)v2.n0() && (Long)v1.n1() == (Long)v2.n1();}

inline Bool shape_cmp(VecLlong_I v1, VecLlong_I v2) {return (Long)v1.size() == (Long)v2.size();}

inline Bool shape_cmp(VecDoub_I v1, VecComp_I v2) {return (Long)v1.size() == (Long)v2.size();}

inline Bool shape_cmp(VecDoub_I v1, VecDoub_I v2) {return (Long)v1.size() == (Long)v2.size();}

inline Bool shape_cmp(CmatComp_I v1, CmatComp_I v2) {return (Long)v1.n0() == (Long)v2.n0() && (Long)v1.n1() == (Long)v2.n1();}

inline Bool shape_cmp(DvecComp_I v1, SvecDoub_I v2) {return (Long)v1.size() == (Long)v2.size();}

inline Bool shape_cmp(VecComp_I v1, VecComp_I v2) {return (Long)v1.size() == (Long)v2.size();}

inline Bool shape_cmp(VecComp_I v1, VecDoub_I v2) {return (Long)v1.size() == (Long)v2.size();}

inline Bool shape_cmp(ScmatDoub_I v1, CmatDoub_I v2) {return (Long)v1.n0() == (Long)v2.n0() && (Long)v1.n1() == (Long)v2.n1();}

inline Bool shape_cmp(Cmat3Comp_I v1, Cmat3Doub_I v2) {return (Long)v1.n0() == (Long)v2.n0() && (Long)v1.n1() == (Long)v2.n1() && (Long)v1.n2() == (Long)v2.n2();}

inline Bool shape_cmp(CbandComp_I v1, CbandComp_I v2) {return (Long)v1.n0() == (Long)v2.n0() && (Long)v1.n1() == (Long)v2.n1();}

inline Bool shape_cmp(MatLlong_I v1, MatLlong_I v2) {return (Long)v1.n0() == (Long)v2.n0() && (Long)v1.n1() == (Long)v2.n1();}

inline Bool shape_cmp(CmatComp_I v1, CmatDoub_I v2) {return (Long)v1.n0() == (Long)v2.n0() && (Long)v1.n1() == (Long)v2.n1();}

inline Bool shape_cmp(DvecComp_I v1, SvecComp_I v2) {return (Long)v1.size() == (Long)v2.size();}

inline Bool shape_cmp(DvecComp_I v1, DvecComp_I v2) {return (Long)v1.size() == (Long)v2.size();}

inline Bool shape_cmp(VecDoub_I v1, SvecDoub_I v2) {return (Long)v1.size() == (Long)v2.size();}

inline Bool shape_cmp(McooComp_I v1, CmatComp_I v2) {return (Long)v1.n0() == (Long)v2.n0() && (Long)v1.n1() == (Long)v2.n1();}

inline Bool shape_cmp(CmatDoub_I v1, McooDoub_I v2) {return (Long)v1.n0() == (Long)v2.n0() && (Long)v1.n1() == (Long)v2.n1();}

inline Bool shape_cmp(CmobdDoub_I v1, McooDoub_I v2) {return (Long)v1.n0() == (Long)v2.n0() && (Long)v1.n1() == (Long)v2.n1();}

inline Bool shape_cmp(CmatDoub_I v1, CmobdDoub_I v2) {return (Long)v1.n0() == (Long)v2.n0() && (Long)v1.n1() == (Long)v2.n1();}

inline Bool shape_cmp(CmatDoub_I v1, CbandDoub_I v2) {return (Long)v1.n0() == (Long)v2.n0() && (Long)v1.n1() == (Long)v2.n1();}

inline Bool shape_cmp(CbandDoub_I v1, CmatDoub_I v2) {return (Long)v1.n0() == (Long)v2.n0() && (Long)v1.n1() == (Long)v2.n1();}

inline Bool shape_cmp(SvecDoub_I v1, VecDoub_I v2) {return (Long)v1.size() == (Long)v2.size();}

inline Bool shape_cmp(SvecDoub_I v1, SvecDoub_I v2) {return (Long)v1.size() == (Long)v2.size();}

inline Bool shape_cmp(VecChar_I v1, VecLlong_I v2) {return (Long)v1.size() == (Long)v2.size();}

inline Bool shape_cmp(VecInt_I v1, VecInt_I v2) {return (Long)v1.size() == (Long)v2.size();}

inline Bool shape_cmp(VecInt_I v1, VecLlong_I v2) {return (Long)v1.size() == (Long)v2.size();}

inline Bool shape_cmp(VecDoub_I v1, VecLlong_I v2) {return (Long)v1.size() == (Long)v2.size();}

inline Bool shape_cmp(vecLlong_I v1, vecLlong_I v2) {return (Long)v1.size() == (Long)v2.size();}

inline Bool shape_cmp(vecLlong_I v1, VecLlong_I v2) {return (Long)v1.size() == (Long)v2.size();}

inline Bool shape_cmp(vecLlong_I v1, vecStr_I v2) {return (Long)v1.size() == (Long)v2.size();}

inline Bool shape_cmp(vecStr_I v1, VecLlong_I v2) {return (Long)v1.size() == (Long)v2.size();}

inline Bool shape_cmp(vecStr_I v1, vecLlong_I v2) {return (Long)v1.size() == (Long)v2.size();}

inline Bool shape_cmp(vecStr_I v1, vecStr_I v2) {return (Long)v1.size() == (Long)v2.size();}

inline Bool shape_cmp(vecStr32_I v1, VecLlong_I v2) {return (Long)v1.size() == (Long)v2.size();}

inline Bool shape_cmp(vecStr32_I v1, vecLlong_I v2) {return (Long)v1.size() == (Long)v2.size();}

inline Bool shape_cmp(vecStr32_I v1, vecStr32_I v2) {return (Long)v1.size() == (Long)v2.size();}


inline void assert_same_shape(CmatComp_I v1, CmatInt_I v2)
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

inline void assert_same_shape(DvecComp_I v1, SvecDoub_I v2)
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

inline void assert_same_shape(VecComp_I v1, VecDoub_I v2)
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

inline void assert_same_shape(Cmat3Comp_I v1, Cmat3Doub_I v2)
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

inline void assert_same_shape(CmatComp_I v1, CmatDoub_I v2)
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

inline void assert_same_shape(DvecComp_I v1, DvecComp_I v2)
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

inline void assert_same_shape(McooComp_I v1, CmatComp_I v2)
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

inline void assert_same_shape(CbandDoub_I v1, CmatDoub_I v2)
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

inline void assert_same_shape(VecChar_I v1, VecLlong_I v2)
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

inline void assert_same_shape(vecLlong_I v1, VecLlong_I v2)
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

inline void assert_same_shape(vecStr_I v1, VecLlong_I v2)
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

inline void assert_same_shape(vecStr_I v1, vecStr_I v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v1, v2))
        SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(vecStr32_I v1, VecLlong_I v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp(v1, v2))
        SLS_ERR("wrong shape!");
#endif
}

inline void assert_same_shape(vecStr32_I v1, vecLlong_I v2)
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


inline void assert_same_shape(CmatComp_I v1, CmatInt_I v2, CmatDoub_I v3)
{ assert_same_shape(v1, v2); assert_same_shape(v1, v3); }

inline void assert_same_shape(DvecComp_I v1, SvecComp_I v2, DvecComp_I v3)
{ assert_same_shape(v1, v2); assert_same_shape(v1, v3); }


inline Bool operator==(MatLlong_I v1, MatLlong_I v2)
{
    return shape_cmp(v1, v2) &&
        equals_to_vv(v1.p(), v2.p(), v2.size());
}

inline Bool operator!=(MatLlong_I v1, MatLlong_I v2)
{
    return !(v1 == v2);
}


inline Bool operator==(VecBool_I v1, VecBool_I v2)
{
    for (Long i = 0; i < v1.size(); ++i)
        if (v1[i] != v2[i])
            return false;
    return true;
}

inline Bool operator!=(VecBool_I v1, VecBool_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(DvecDoub_I v, Doub_I s)
{
    for (Long i = 0; i < v.size(); ++i)
        if (v[i] != s)
            return false;
    return true;
}

inline Bool operator!=(DvecDoub_I v, Doub_I s)
{
    return !(v == s);
}

} // namespace slisc
