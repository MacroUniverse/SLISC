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
inline Bool equals_to_vs(const Int *v, Int_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        if (v[i] != s)
            return false;
    return true;
}

inline Bool equals_to_vs(const Llong *v, Llong_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        if (v[i] != s)
            return false;
    return true;
}

inline Bool equals_to_vs(const Doub *v, Doub_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        if (v[i] != s)
            return false;
    return true;
}

#ifdef SLS_USE_QUAD_MATH
inline Bool equals_to_vs(const Qdoub *v, Qdoub_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        if (v[i] != s)
            return false;
    return true;
}
#endif

inline Bool equals_to_vs(const Comp *v, Comp_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        if (v[i] != s)
            return false;
    return true;
}

#ifdef SLS_USE_QUAD_MATH
inline Bool equals_to_vs(const Qcomp *v, Qcomp_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        if (v[i] != s)
            return false;
    return true;
}
#endif



inline Bool equals_to_vv(const Char *v1, const Char *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        if (v1[i] != v2[i])
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

inline Bool equals_to_vv(const Doub *v1, const Llong *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        if (v1[i] != v2[i])
            return false;
    return true;
}

inline Bool equals_to_vv(const Doub *v1, const Doub *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        if (v1[i] != v2[i])
            return false;
    return true;
}

inline Bool equals_to_vv(const Doub *v1, const Comp *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        if (v1[i] != v2[i])
            return false;
    return true;
}

#ifdef SLS_USE_QUAD_MATH
inline Bool equals_to_vv(const Qdoub *v1, const Qdoub *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        if (v1[i] != v2[i])
            return false;
    return true;
}
#endif

inline Bool equals_to_vv(const Comp *v1, const Doub *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        if (v1[i] != v2[i])
            return false;
    return true;
}

inline Bool equals_to_vv(const Comp *v1, const Comp *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        if (v1[i] != v2[i])
            return false;
    return true;
}

#ifdef SLS_USE_QUAD_MATH
inline Bool equals_to_vv(const Qcomp *v1, const Qcomp *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        if (v1[i] != v2[i])
            return false;
    return true;
}
#endif



template <class T1, class T2>
inline Bool shape_cmp11(const T1 &v1, const T2 &v2)
{
    return (Long)v1.size() == (Long)v2.size();
}

template <class T1, class T2>
inline void assert_same_shape11(const T1 &v1, const T2 &v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp11(v1, v2))
        SLS_ERR("wrong shape!");
#endif
}

template <class T1, class T2, class T3>
inline void assert_same_shape111(const T1 &v1, const T2 &v2, const T3 &v3)
{
    assert_same_shape11(v1, v2);
    assert_same_shape11(v1, v3);
}

template <class T1, class T2>
inline Bool shape_cmp22(const T1 &v1, const T2 &v2)
{
    return v1.n0() == v2.n0() && v1.n1() == v2.n1();
}

template <class T1, class T2>
inline void assert_same_shape22(const T1 &v1, const T2 &v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp22(v1, v2))
        SLS_ERR("wrong shape!");
#endif
}

template <class T1, class T2, class T3>
inline void assert_same_shape222(const T1 &v1, const T2 &v2, const T3 &v3)
{
    assert_same_shape22(v1, v2);
    assert_same_shape22(v1, v3);
}

template <class T1, class T2>
inline Bool shape_cmp33(const T1 &v1, const T2 &v2)
{
    return v1.n0() == v2.n0() && v1.n1() == v2.n1() && v1.n2() == v2.n2();
}

template <class T1, class T2>
inline void assert_same_shape33(const T1 &v1, const T2 &v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp33(v1, v2))
        SLS_ERR("wrong shape!");
#endif
}

template <class T1, class T2, class T3>
inline void assert_same_shape333(const T1 &v1, const T2 &v2, const T3 &v3)
{
    assert_same_shape33(v1, v2);
    assert_same_shape33(v1, v3);
}

template <class T1, class T2>
inline Bool shape_cmp44(const T1 &v1, const T2 &v2)
{
    return v1.n0() == v2.n0() && v1.n1() == v2.n1() && v1.n2() == v2.n2() && v1.n3() == v2.n3();
}

template <class T1, class T2>
inline void assert_same_shape44(const T1 &v1, const T2 &v2)
{
#ifdef SLS_CHECK_SHAPES
    if (!shape_cmp44(v1, v2))
        SLS_ERR("wrong shape!");
#endif
}

template <class T1, class T2, class T3>
inline void assert_same_shape444(const T1 &v1, const T2 &v2, const T3 &v3)
{
    assert_same_shape44(v1, v2);
    assert_same_shape44(v1, v3);
}



inline Bool operator==(VecChar_I v1, VecChar_I v2)
{
    return shape_cmp11(v1, v2) &&
        equals_to_vv(v1.p(), v2.p(), v2.size());
}

inline Bool operator!=(VecChar_I v1, VecChar_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(VecInt_I v1, VecInt_I v2)
{
    return shape_cmp11(v1, v2) &&
        equals_to_vv(v1.p(), v2.p(), v2.size());
}

inline Bool operator!=(VecInt_I v1, VecInt_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(VecInt_I v1, DvecInt_I v2)
{
    if (!shape_cmp11(v1, v2))
        return false;
    for (Long i = 0; i < v1.size(); ++i) {
        if (v1[i] != v2[i])
            return false;
    }
    return true;
}

inline Bool operator!=(VecInt_I v1, DvecInt_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(VecLlong_I v1, DvecLlong_I v2)
{
    if (!shape_cmp11(v1, v2))
        return false;
    for (Long i = 0; i < v1.size(); ++i) {
        if (v1[i] != v2[i])
            return false;
    }
    return true;
}

inline Bool operator!=(VecLlong_I v1, DvecLlong_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(VecLlong_I v1, VecLlong_I v2)
{
    return shape_cmp11(v1, v2) &&
        equals_to_vv(v1.p(), v2.p(), v2.size());
}

inline Bool operator!=(VecLlong_I v1, VecLlong_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(VecDoub_I v1, DvecDoub_I v2)
{
    if (!shape_cmp11(v1, v2))
        return false;
    for (Long i = 0; i < v1.size(); ++i) {
        if (v1[i] != v2[i])
            return false;
    }
    return true;
}

inline Bool operator!=(VecDoub_I v1, DvecDoub_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(VecDoub_I v1, VecDoub_I v2)
{
    return shape_cmp11(v1, v2) &&
        equals_to_vv(v1.p(), v2.p(), v2.size());
}

inline Bool operator!=(VecDoub_I v1, VecDoub_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(VecDoub_I v1, VecComp_I v2)
{
    return shape_cmp11(v1, v2) &&
        equals_to_vv(v1.p(), v2.p(), v2.size());
}

inline Bool operator!=(VecDoub_I v1, VecComp_I v2)
{
    return !(v1 == v2);
}

#ifdef SLS_USE_QUAD_MATH
inline Bool operator==(VecQdoub_I v1, VecQdoub_I v2)
{
    return shape_cmp11(v1, v2) &&
        equals_to_vv(v1.p(), v2.p(), v2.size());
}

inline Bool operator!=(VecQdoub_I v1, VecQdoub_I v2)
{
    return !(v1 == v2);
}
#endif

inline Bool operator==(VecComp_I v1, VecComp_I v2)
{
    return shape_cmp11(v1, v2) &&
        equals_to_vv(v1.p(), v2.p(), v2.size());
}

inline Bool operator!=(VecComp_I v1, VecComp_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(SvecChar_I v1, SvecChar_I v2)
{
    return shape_cmp11(v1, v2) &&
        equals_to_vv(v1.p(), v2.p(), v2.size());
}

inline Bool operator!=(SvecChar_I v1, SvecChar_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(SvecInt_I v1, SvecInt_I v2)
{
    return shape_cmp11(v1, v2) &&
        equals_to_vv(v1.p(), v2.p(), v2.size());
}

inline Bool operator!=(SvecInt_I v1, SvecInt_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(SvecInt_I v1, DvecInt_I v2)
{
    if (!shape_cmp11(v1, v2))
        return false;
    for (Long i = 0; i < v1.size(); ++i) {
        if (v1[i] != v2[i])
            return false;
    }
    return true;
}

inline Bool operator!=(SvecInt_I v1, DvecInt_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(SvecLlong_I v1, DvecLlong_I v2)
{
    if (!shape_cmp11(v1, v2))
        return false;
    for (Long i = 0; i < v1.size(); ++i) {
        if (v1[i] != v2[i])
            return false;
    }
    return true;
}

inline Bool operator!=(SvecLlong_I v1, DvecLlong_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(SvecLlong_I v1, SvecLlong_I v2)
{
    return shape_cmp11(v1, v2) &&
        equals_to_vv(v1.p(), v2.p(), v2.size());
}

inline Bool operator!=(SvecLlong_I v1, SvecLlong_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(SvecDoub_I v1, DvecDoub_I v2)
{
    if (!shape_cmp11(v1, v2))
        return false;
    for (Long i = 0; i < v1.size(); ++i) {
        if (v1[i] != v2[i])
            return false;
    }
    return true;
}

inline Bool operator!=(SvecDoub_I v1, DvecDoub_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(SvecDoub_I v1, SvecDoub_I v2)
{
    return shape_cmp11(v1, v2) &&
        equals_to_vv(v1.p(), v2.p(), v2.size());
}

inline Bool operator!=(SvecDoub_I v1, SvecDoub_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(SvecDoub_I v1, SvecComp_I v2)
{
    return shape_cmp11(v1, v2) &&
        equals_to_vv(v1.p(), v2.p(), v2.size());
}

inline Bool operator!=(SvecDoub_I v1, SvecComp_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(SvecComp_I v1, SvecComp_I v2)
{
    return shape_cmp11(v1, v2) &&
        equals_to_vv(v1.p(), v2.p(), v2.size());
}

inline Bool operator!=(SvecComp_I v1, SvecComp_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(MatInt_I v1, MatInt_I v2)
{
    return shape_cmp22(v1, v2) &&
        equals_to_vv(v1.p(), v2.p(), v2.size());
}

inline Bool operator!=(MatInt_I v1, MatInt_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(MatLlong_I v1, MatLlong_I v2)
{
    return shape_cmp22(v1, v2) &&
        equals_to_vv(v1.p(), v2.p(), v2.size());
}

inline Bool operator!=(MatLlong_I v1, MatLlong_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(MatDoub_I v1, MatDoub_I v2)
{
    return shape_cmp22(v1, v2) &&
        equals_to_vv(v1.p(), v2.p(), v2.size());
}

inline Bool operator!=(MatDoub_I v1, MatDoub_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(MatComp_I v1, MatComp_I v2)
{
    return shape_cmp22(v1, v2) &&
        equals_to_vv(v1.p(), v2.p(), v2.size());
}

inline Bool operator!=(MatComp_I v1, MatComp_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(CmatInt_I v1, CmatInt_I v2)
{
    return shape_cmp22(v1, v2) &&
        equals_to_vv(v1.p(), v2.p(), v2.size());
}

inline Bool operator!=(CmatInt_I v1, CmatInt_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(CmatDoub_I v1, CmatDoub_I v2)
{
    return shape_cmp22(v1, v2) &&
        equals_to_vv(v1.p(), v2.p(), v2.size());
}

inline Bool operator!=(CmatDoub_I v1, CmatDoub_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(CmatComp_I v1, CmatComp_I v2)
{
    return shape_cmp22(v1, v2) &&
        equals_to_vv(v1.p(), v2.p(), v2.size());
}

inline Bool operator!=(CmatComp_I v1, CmatComp_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(CmatComp_I v1, MatComp_I v2)
{
    if (!shape_cmp22(v1, v2))
        return false;
    for (Long i = 0; i < v1.n0(); ++i)
        for (Long j = 0; j < v1.n1(); ++j)
            if (v1(i, j) != v2(i, j))
                return false;
    return true;
}

inline Bool operator!=(CmatComp_I v1, MatComp_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(MatDoub_I v1, CmatDoub_I v2)
{
    if (!shape_cmp22(v1, v2))
        return false;
    for (Long i = 0; i < v1.n0(); ++i)
        for (Long j = 0; j < v1.n1(); ++j)
            if (v1(i, j) != v2(i, j))
                return false;
    return true;
}

inline Bool operator!=(MatDoub_I v1, CmatDoub_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(CmatDoub_I v1, MatDoub_I v2)
{
    if (!shape_cmp22(v1, v2))
        return false;
    for (Long i = 0; i < v1.n0(); ++i)
        for (Long j = 0; j < v1.n1(); ++j)
            if (v1(i, j) != v2(i, j))
                return false;
    return true;
}

inline Bool operator!=(CmatDoub_I v1, MatDoub_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(Cmat3Doub_I v1, Cmat3Doub_I v2)
{
    return shape_cmp33(v1, v2) &&
        equals_to_vv(v1.p(), v2.p(), v2.size());
}

inline Bool operator!=(Cmat3Doub_I v1, Cmat3Doub_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(CmobdComp_I v1, CmobdDoub_I v2)
{
    if (!shape_cmp22(v1, v2))
        return false;
    for (Long i = 0; i < v1.n0(); ++i)
        for (Long j = 0; j < v1.n1(); ++j)
            if (v1(i, j) != v2(i, j))
                return false;
    return true;
}

inline Bool operator!=(CmobdComp_I v1, CmobdDoub_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(Mat3Doub_I v1, Mat3Doub_I v2)
{
    return shape_cmp33(v1, v2) &&
        equals_to_vv(v1.p(), v2.p(), v2.size());
}

inline Bool operator!=(Mat3Doub_I v1, Mat3Doub_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(DvecInt_I v1, DvecInt_I v2)
{
    if (!shape_cmp11(v1, v2))
        return false;
    for (Long i = 0; i < v1.size(); ++i) {
        if (v1[i] != v2[i])
            return false;
    }
    return true;
}

inline Bool operator!=(DvecInt_I v1, DvecInt_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(DvecLong_I v1, DvecLong_I v2)
{
    if (!shape_cmp11(v1, v2))
        return false;
    for (Long i = 0; i < v1.size(); ++i) {
        if (v1[i] != v2[i])
            return false;
    }
    return true;
}

inline Bool operator!=(DvecLong_I v1, DvecLong_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(DvecDoub_I v1, DvecDoub_I v2)
{
    if (!shape_cmp11(v1, v2))
        return false;
    for (Long i = 0; i < v1.size(); ++i) {
        if (v1[i] != v2[i])
            return false;
    }
    return true;
}

inline Bool operator!=(DvecDoub_I v1, DvecDoub_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(DcmatDoub_I v1, CmatDoub_I v2)
{
    if (!shape_cmp22(v1, v2))
        return false;
    for (Long i = 0; i < v1.n0(); ++i)
        for (Long j = 0; j < v1.n1(); ++j)
            if (v1(i, j) != v2(i, j))
                return false;
    return true;
}

inline Bool operator!=(DcmatDoub_I v1, CmatDoub_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(Jcmat3Doub_I v1, Cmat3Doub_I v2)
{
    if (!shape_cmp33(v1, v2))
        return false;
    for (Long i = 0; i < v1.n0(); ++i)
        for (Long j = 0; j < v1.n1(); ++j)
            for (Long k = 0; k < v1.n2(); ++k)
                if (v1(i, j, k) != v2(i, j, k))
                    return false;
    return true;
}

inline Bool operator!=(Jcmat3Doub_I v1, Cmat3Doub_I v2)
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

inline Bool operator==(VecInt_I v, Int_I s)
{
    return equals_to_vs(v.p(), s, v.size());
}

inline Bool operator!=(VecInt_I v, Int_I s)
{
    return !(v == s);
}

inline Bool operator==(VecLlong_I v, Llong_I s)
{
    return equals_to_vs(v.p(), s, v.size());
}

inline Bool operator!=(VecLlong_I v, Llong_I s)
{
    return !(v == s);
}

inline Bool operator==(VecDoub_I v, Doub_I s)
{
    return equals_to_vs(v.p(), s, v.size());
}

inline Bool operator!=(VecDoub_I v, Doub_I s)
{
    return !(v == s);
}

inline Bool operator==(VecComp_I v, Comp_I s)
{
    return equals_to_vs(v.p(), s, v.size());
}

inline Bool operator!=(VecComp_I v, Comp_I s)
{
    return !(v == s);
}

inline Bool operator==(DvecInt_I v, Int_I s)
{
    for (Long i = 0; i < v.size(); ++i)
        if (v[i] != s)
            return false;
    return true;
}

inline Bool operator!=(DvecInt_I v, Int_I s)
{
    return !(v == s);
}

inline Bool operator==(DvecLlong_I v, Llong_I s)
{
    for (Long i = 0; i < v.size(); ++i)
        if (v[i] != s)
            return false;
    return true;
}

inline Bool operator!=(DvecLlong_I v, Llong_I s)
{
    return !(v == s);
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

inline Bool operator==(MatInt_I v, Int_I s)
{
    return equals_to_vs(v.p(), s, v.size());
}

inline Bool operator!=(MatInt_I v, Int_I s)
{
    return !(v == s);
}

inline Bool operator==(MatLlong_I v, Llong_I s)
{
    return equals_to_vs(v.p(), s, v.size());
}

inline Bool operator!=(MatLlong_I v, Llong_I s)
{
    return !(v == s);
}

inline Bool operator==(MatDoub_I v, Doub_I s)
{
    return equals_to_vs(v.p(), s, v.size());
}

inline Bool operator!=(MatDoub_I v, Doub_I s)
{
    return !(v == s);
}

inline Bool operator==(MatComp_I v, Comp_I s)
{
    return equals_to_vs(v.p(), s, v.size());
}

inline Bool operator!=(MatComp_I v, Comp_I s)
{
    return !(v == s);
}

inline Bool operator==(Mat3Doub_I v, Doub_I s)
{
    return equals_to_vs(v.p(), s, v.size());
}

inline Bool operator!=(Mat3Doub_I v, Doub_I s)
{
    return !(v == s);
}

inline Bool operator==(CmatDoub_I v, Doub_I s)
{
    return equals_to_vs(v.p(), s, v.size());
}

inline Bool operator!=(CmatDoub_I v, Doub_I s)
{
    return !(v == s);
}

inline Bool operator==(CmatComp_I v, Comp_I s)
{
    return equals_to_vs(v.p(), s, v.size());
}

inline Bool operator!=(CmatComp_I v, Comp_I s)
{
    return !(v == s);
}

inline Bool operator==(Cmat3Doub_I v, Doub_I s)
{
    return equals_to_vs(v.p(), s, v.size());
}

inline Bool operator!=(Cmat3Doub_I v, Doub_I s)
{
    return !(v == s);
}

inline Bool operator==(Cmat3Comp_I v, Comp_I s)
{
    return equals_to_vs(v.p(), s, v.size());
}

inline Bool operator!=(Cmat3Comp_I v, Comp_I s)
{
    return !(v == s);
}


} // namespace slisc
