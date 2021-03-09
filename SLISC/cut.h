#pragma once
#include "Vec.h"
#include "Mat.h"
#include "Cmat.h"
#include "Cmat3.h"
#include "Cmat4.h"
#include "Svec.h"
#include "Dvec.h"
#include "Scmat.h"
#include "Dcmat.h"
#include "Jcmat3.h"

namespace slisc {
inline SvecDoub cut(VecDoub_IO v, Long_I start, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (start < 0 || start + N > v.size())
        SLS_ERR("index out of bound!");
#endif
    SvecDoub sli(&v[start], N);
    return sli;
}

inline SvecDoub_c cut(VecDoub_I v, Long_I start, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (start < 0 || start + N > v.size())
        SLS_ERR("index out of bound!");
#endif
    SvecDoub_c sli(&v[start], N);
    return sli;
}

inline SvecComp cut(VecComp_IO v, Long_I start, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (start < 0 || start + N > v.size())
        SLS_ERR("index out of bound!");
#endif
    SvecComp sli(&v[start], N);
    return sli;
}

inline SvecComp_c cut(VecComp_I v, Long_I start, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (start < 0 || start + N > v.size())
        SLS_ERR("index out of bound!");
#endif
    SvecComp_c sli(&v[start], N);
    return sli;
}

inline SvecDoub cut(SvecDoub_IO v, Long_I start, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (start < 0 || start + N > v.size())
        SLS_ERR("index out of bound!");
#endif
    SvecDoub sli(&v[start], N);
    return sli;
}

inline SvecDoub_c cut(SvecDoub_I v, Long_I start, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (start < 0 || start + N > v.size())
        SLS_ERR("index out of bound!");
#endif
    SvecDoub_c sli(&v[start], N);
    return sli;
}

inline SvecComp cut(SvecComp_IO v, Long_I start, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (start < 0 || start + N > v.size())
        SLS_ERR("index out of bound!");
#endif
    SvecComp sli(&v[start], N);
    return sli;
}

inline SvecComp_c cut(SvecComp_I v, Long_I start, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (start < 0 || start + N > v.size())
        SLS_ERR("index out of bound!");
#endif
    SvecComp_c sli(&v[start], N);
    return sli;
}

inline DvecDoub cut(DvecDoub_IO v, Long_I start, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (start < 0 || start + N > v.size())
        SLS_ERR("index out of bound!");
#endif
    DvecDoub sli(&v[start], N, v.step());
    return sli;
}

inline DvecDoub_c cut(DvecDoub_I v, Long_I start, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (start < 0 || start + N > v.size())
        SLS_ERR("index out of bound!");
#endif
    DvecDoub_c sli(&v[start], N, v.step());
    return sli;
}

inline DvecComp cut(DvecComp_IO v, Long_I start, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (start < 0 || start + N > v.size())
        SLS_ERR("index out of bound!");
#endif
    DvecComp sli(&v[start], N, v.step());
    return sli;
}

inline DvecComp_c cut(DvecComp_I v, Long_I start, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (start < 0 || start + N > v.size())
        SLS_ERR("index out of bound!");
#endif
    DvecComp_c sli(&v[start], N, v.step());
    return sli;
}

inline DcmatChar cut(CmatChar_IO v, Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() ||
            start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    DcmatChar sli(&v(start1, start2), N1, N2, v.n1());
    return sli;
}

inline DcmatChar_c cut(CmatChar_I v,
    Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() ||
            start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    DcmatChar_c sli(&v(start1, start2), N1, N2, v.n1());
    return sli;
}
inline ScmatChar cut(CmatChar_IO v, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    ScmatChar sli(&v(0, start2), v.n1(), N2);
    return sli;
}

inline ScmatChar_c cut(CmatChar_I v, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    ScmatChar_c sli(&v(0, start2), v.n1(), N2);
    return sli;
}

inline DcmatInt cut(CmatInt_IO v, Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() ||
            start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    DcmatInt sli(&v(start1, start2), N1, N2, v.n1());
    return sli;
}

inline DcmatInt_c cut(CmatInt_I v,
    Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() ||
            start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    DcmatInt_c sli(&v(start1, start2), N1, N2, v.n1());
    return sli;
}
inline ScmatInt cut(CmatInt_IO v, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    ScmatInt sli(&v(0, start2), v.n1(), N2);
    return sli;
}

inline ScmatInt_c cut(CmatInt_I v, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    ScmatInt_c sli(&v(0, start2), v.n1(), N2);
    return sli;
}

inline DcmatLlong cut(CmatLlong_IO v, Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() ||
            start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    DcmatLlong sli(&v(start1, start2), N1, N2, v.n1());
    return sli;
}

inline DcmatLlong_c cut(CmatLlong_I v,
    Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() ||
            start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    DcmatLlong_c sli(&v(start1, start2), N1, N2, v.n1());
    return sli;
}
inline ScmatLlong cut(CmatLlong_IO v, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    ScmatLlong sli(&v(0, start2), v.n1(), N2);
    return sli;
}

inline ScmatLlong_c cut(CmatLlong_I v, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    ScmatLlong_c sli(&v(0, start2), v.n1(), N2);
    return sli;
}

inline DcmatFloat cut(CmatFloat_IO v, Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() ||
            start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    DcmatFloat sli(&v(start1, start2), N1, N2, v.n1());
    return sli;
}

inline DcmatFloat_c cut(CmatFloat_I v,
    Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() ||
            start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    DcmatFloat_c sli(&v(start1, start2), N1, N2, v.n1());
    return sli;
}
inline ScmatFloat cut(CmatFloat_IO v, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    ScmatFloat sli(&v(0, start2), v.n1(), N2);
    return sli;
}

inline ScmatFloat_c cut(CmatFloat_I v, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    ScmatFloat_c sli(&v(0, start2), v.n1(), N2);
    return sli;
}

inline DcmatDoub cut(CmatDoub_IO v, Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() ||
            start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    DcmatDoub sli(&v(start1, start2), N1, N2, v.n1());
    return sli;
}

inline DcmatDoub_c cut(CmatDoub_I v,
    Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() ||
            start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    DcmatDoub_c sli(&v(start1, start2), N1, N2, v.n1());
    return sli;
}
inline ScmatDoub cut(CmatDoub_IO v, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    ScmatDoub sli(&v(0, start2), v.n1(), N2);
    return sli;
}

inline ScmatDoub_c cut(CmatDoub_I v, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    ScmatDoub_c sli(&v(0, start2), v.n1(), N2);
    return sli;
}

inline DcmatLdoub cut(CmatLdoub_IO v, Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() ||
            start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    DcmatLdoub sli(&v(start1, start2), N1, N2, v.n1());
    return sli;
}

inline DcmatLdoub_c cut(CmatLdoub_I v,
    Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() ||
            start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    DcmatLdoub_c sli(&v(start1, start2), N1, N2, v.n1());
    return sli;
}
inline ScmatLdoub cut(CmatLdoub_IO v, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    ScmatLdoub sli(&v(0, start2), v.n1(), N2);
    return sli;
}

inline ScmatLdoub_c cut(CmatLdoub_I v, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    ScmatLdoub_c sli(&v(0, start2), v.n1(), N2);
    return sli;
}

inline DcmatFcomp cut(CmatFcomp_IO v, Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() ||
            start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    DcmatFcomp sli(&v(start1, start2), N1, N2, v.n1());
    return sli;
}

inline DcmatFcomp_c cut(CmatFcomp_I v,
    Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() ||
            start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    DcmatFcomp_c sli(&v(start1, start2), N1, N2, v.n1());
    return sli;
}
inline ScmatFcomp cut(CmatFcomp_IO v, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    ScmatFcomp sli(&v(0, start2), v.n1(), N2);
    return sli;
}

inline ScmatFcomp_c cut(CmatFcomp_I v, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    ScmatFcomp_c sli(&v(0, start2), v.n1(), N2);
    return sli;
}

inline DcmatComp cut(CmatComp_IO v, Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() ||
            start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    DcmatComp sli(&v(start1, start2), N1, N2, v.n1());
    return sli;
}

inline DcmatComp_c cut(CmatComp_I v,
    Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() ||
            start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    DcmatComp_c sli(&v(start1, start2), N1, N2, v.n1());
    return sli;
}
inline ScmatComp cut(CmatComp_IO v, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    ScmatComp sli(&v(0, start2), v.n1(), N2);
    return sli;
}

inline ScmatComp_c cut(CmatComp_I v, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    ScmatComp_c sli(&v(0, start2), v.n1(), N2);
    return sli;
}

inline DcmatLcomp cut(CmatLcomp_IO v, Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() ||
            start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    DcmatLcomp sli(&v(start1, start2), N1, N2, v.n1());
    return sli;
}

inline DcmatLcomp_c cut(CmatLcomp_I v,
    Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() ||
            start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    DcmatLcomp_c sli(&v(start1, start2), N1, N2, v.n1());
    return sli;
}
inline ScmatLcomp cut(CmatLcomp_IO v, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    ScmatLcomp sli(&v(0, start2), v.n1(), N2);
    return sli;
}

inline ScmatLcomp_c cut(CmatLcomp_I v, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    ScmatLcomp_c sli(&v(0, start2), v.n1(), N2);
    return sli;
}

inline DcmatChar cut(ScmatChar_IO v, Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() ||
            start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    DcmatChar sli(&v(start1, start2), N1, N2, v.n1());
    return sli;
}

inline DcmatChar_c cut(ScmatChar_I v,
    Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() ||
            start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    DcmatChar_c sli(&v(start1, start2), N1, N2, v.n1());
    return sli;
}

inline DcmatInt cut(ScmatInt_IO v, Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() ||
            start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    DcmatInt sli(&v(start1, start2), N1, N2, v.n1());
    return sli;
}

inline DcmatInt_c cut(ScmatInt_I v,
    Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() ||
            start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    DcmatInt_c sli(&v(start1, start2), N1, N2, v.n1());
    return sli;
}

inline DcmatLlong cut(ScmatLlong_IO v, Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() ||
            start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    DcmatLlong sli(&v(start1, start2), N1, N2, v.n1());
    return sli;
}

inline DcmatLlong_c cut(ScmatLlong_I v,
    Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() ||
            start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    DcmatLlong_c sli(&v(start1, start2), N1, N2, v.n1());
    return sli;
}

inline DcmatFloat cut(ScmatFloat_IO v, Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() ||
            start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    DcmatFloat sli(&v(start1, start2), N1, N2, v.n1());
    return sli;
}

inline DcmatFloat_c cut(ScmatFloat_I v,
    Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() ||
            start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    DcmatFloat_c sli(&v(start1, start2), N1, N2, v.n1());
    return sli;
}

inline DcmatDoub cut(ScmatDoub_IO v, Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() ||
            start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    DcmatDoub sli(&v(start1, start2), N1, N2, v.n1());
    return sli;
}

inline DcmatDoub_c cut(ScmatDoub_I v,
    Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() ||
            start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    DcmatDoub_c sli(&v(start1, start2), N1, N2, v.n1());
    return sli;
}

inline DcmatLdoub cut(ScmatLdoub_IO v, Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() ||
            start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    DcmatLdoub sli(&v(start1, start2), N1, N2, v.n1());
    return sli;
}

inline DcmatLdoub_c cut(ScmatLdoub_I v,
    Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() ||
            start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    DcmatLdoub_c sli(&v(start1, start2), N1, N2, v.n1());
    return sli;
}

inline DcmatFcomp cut(ScmatFcomp_IO v, Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() ||
            start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    DcmatFcomp sli(&v(start1, start2), N1, N2, v.n1());
    return sli;
}

inline DcmatFcomp_c cut(ScmatFcomp_I v,
    Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() ||
            start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    DcmatFcomp_c sli(&v(start1, start2), N1, N2, v.n1());
    return sli;
}

inline DcmatComp cut(ScmatComp_IO v, Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() ||
            start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    DcmatComp sli(&v(start1, start2), N1, N2, v.n1());
    return sli;
}

inline DcmatComp_c cut(ScmatComp_I v,
    Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() ||
            start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    DcmatComp_c sli(&v(start1, start2), N1, N2, v.n1());
    return sli;
}

inline DcmatLcomp cut(ScmatLcomp_IO v, Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() ||
            start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    DcmatLcomp sli(&v(start1, start2), N1, N2, v.n1());
    return sli;
}

inline DcmatLcomp_c cut(ScmatLcomp_I v,
    Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() ||
            start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    DcmatLcomp_c sli(&v(start1, start2), N1, N2, v.n1());
    return sli;
}

inline DcmatChar cut(DcmatChar_IO v, Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() ||
            start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    DcmatChar sli(&v(start1, start2), N1, N2, v.lda());
    return sli;
}

inline DcmatChar_c cut(DcmatChar_I v,
    Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() ||
            start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    DcmatChar_c sli(&v(start1, start2), N1, N2, v.lda());
    return sli;
}

inline DcmatInt cut(DcmatInt_IO v, Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() ||
            start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    DcmatInt sli(&v(start1, start2), N1, N2, v.lda());
    return sli;
}

inline DcmatInt_c cut(DcmatInt_I v,
    Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() ||
            start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    DcmatInt_c sli(&v(start1, start2), N1, N2, v.lda());
    return sli;
}

inline DcmatLlong cut(DcmatLlong_IO v, Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() ||
            start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    DcmatLlong sli(&v(start1, start2), N1, N2, v.lda());
    return sli;
}

inline DcmatLlong_c cut(DcmatLlong_I v,
    Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() ||
            start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    DcmatLlong_c sli(&v(start1, start2), N1, N2, v.lda());
    return sli;
}

inline Jcmat3Char cut(Cmat3Char_IO v, Long_I start1, Long_I N1, Long_I start2, Long_I N2, Long_I start3, Long_I N3)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() || start2 < 0 || start2 + N2 > v.n2() || start3 < 0 || start3 + N3 > v.n3())
        SLS_ERR("index out of bound!");
#endif
    Jcmat3Char sli(&v(start1, start2, start3), N1, N2, N3, 1, v.n1(), v.n1()*v.n2());
    return sli;
}

inline Jcmat3Char_c cut(Cmat3Char_I v, Long_I start1, Long_I N1, Long_I start2, Long_I N2, Long_I start3, Long_I N3)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() || start2 < 0 || start2 + N2 > v.n2() || start3 < 0 || start3 + N3 > v.n3())
        SLS_ERR("index out of bound!");
#endif
    Jcmat3Char_c sli(&v(start1, start2, start3), N1, N2, N3, 1, v.n1(), v.n1()*v.n2());
    return sli;
}

inline Jcmat3Int cut(Cmat3Int_IO v, Long_I start1, Long_I N1, Long_I start2, Long_I N2, Long_I start3, Long_I N3)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() || start2 < 0 || start2 + N2 > v.n2() || start3 < 0 || start3 + N3 > v.n3())
        SLS_ERR("index out of bound!");
#endif
    Jcmat3Int sli(&v(start1, start2, start3), N1, N2, N3, 1, v.n1(), v.n1()*v.n2());
    return sli;
}

inline Jcmat3Int_c cut(Cmat3Int_I v, Long_I start1, Long_I N1, Long_I start2, Long_I N2, Long_I start3, Long_I N3)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() || start2 < 0 || start2 + N2 > v.n2() || start3 < 0 || start3 + N3 > v.n3())
        SLS_ERR("index out of bound!");
#endif
    Jcmat3Int_c sli(&v(start1, start2, start3), N1, N2, N3, 1, v.n1(), v.n1()*v.n2());
    return sli;
}

inline Jcmat3Llong cut(Cmat3Llong_IO v, Long_I start1, Long_I N1, Long_I start2, Long_I N2, Long_I start3, Long_I N3)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() || start2 < 0 || start2 + N2 > v.n2() || start3 < 0 || start3 + N3 > v.n3())
        SLS_ERR("index out of bound!");
#endif
    Jcmat3Llong sli(&v(start1, start2, start3), N1, N2, N3, 1, v.n1(), v.n1()*v.n2());
    return sli;
}

inline Jcmat3Llong_c cut(Cmat3Llong_I v, Long_I start1, Long_I N1, Long_I start2, Long_I N2, Long_I start3, Long_I N3)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() || start2 < 0 || start2 + N2 > v.n2() || start3 < 0 || start3 + N3 > v.n3())
        SLS_ERR("index out of bound!");
#endif
    Jcmat3Llong_c sli(&v(start1, start2, start3), N1, N2, N3, 1, v.n1(), v.n1()*v.n2());
    return sli;
}

inline Jcmat3Float cut(Cmat3Float_IO v, Long_I start1, Long_I N1, Long_I start2, Long_I N2, Long_I start3, Long_I N3)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() || start2 < 0 || start2 + N2 > v.n2() || start3 < 0 || start3 + N3 > v.n3())
        SLS_ERR("index out of bound!");
#endif
    Jcmat3Float sli(&v(start1, start2, start3), N1, N2, N3, 1, v.n1(), v.n1()*v.n2());
    return sli;
}

inline Jcmat3Float_c cut(Cmat3Float_I v, Long_I start1, Long_I N1, Long_I start2, Long_I N2, Long_I start3, Long_I N3)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() || start2 < 0 || start2 + N2 > v.n2() || start3 < 0 || start3 + N3 > v.n3())
        SLS_ERR("index out of bound!");
#endif
    Jcmat3Float_c sli(&v(start1, start2, start3), N1, N2, N3, 1, v.n1(), v.n1()*v.n2());
    return sli;
}

inline Jcmat3Doub cut(Cmat3Doub_IO v, Long_I start1, Long_I N1, Long_I start2, Long_I N2, Long_I start3, Long_I N3)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() || start2 < 0 || start2 + N2 > v.n2() || start3 < 0 || start3 + N3 > v.n3())
        SLS_ERR("index out of bound!");
#endif
    Jcmat3Doub sli(&v(start1, start2, start3), N1, N2, N3, 1, v.n1(), v.n1()*v.n2());
    return sli;
}

inline Jcmat3Doub_c cut(Cmat3Doub_I v, Long_I start1, Long_I N1, Long_I start2, Long_I N2, Long_I start3, Long_I N3)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() || start2 < 0 || start2 + N2 > v.n2() || start3 < 0 || start3 + N3 > v.n3())
        SLS_ERR("index out of bound!");
#endif
    Jcmat3Doub_c sli(&v(start1, start2, start3), N1, N2, N3, 1, v.n1(), v.n1()*v.n2());
    return sli;
}

inline Jcmat3Ldoub cut(Cmat3Ldoub_IO v, Long_I start1, Long_I N1, Long_I start2, Long_I N2, Long_I start3, Long_I N3)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() || start2 < 0 || start2 + N2 > v.n2() || start3 < 0 || start3 + N3 > v.n3())
        SLS_ERR("index out of bound!");
#endif
    Jcmat3Ldoub sli(&v(start1, start2, start3), N1, N2, N3, 1, v.n1(), v.n1()*v.n2());
    return sli;
}

inline Jcmat3Ldoub_c cut(Cmat3Ldoub_I v, Long_I start1, Long_I N1, Long_I start2, Long_I N2, Long_I start3, Long_I N3)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() || start2 < 0 || start2 + N2 > v.n2() || start3 < 0 || start3 + N3 > v.n3())
        SLS_ERR("index out of bound!");
#endif
    Jcmat3Ldoub_c sli(&v(start1, start2, start3), N1, N2, N3, 1, v.n1(), v.n1()*v.n2());
    return sli;
}

inline Jcmat3Fcomp cut(Cmat3Fcomp_IO v, Long_I start1, Long_I N1, Long_I start2, Long_I N2, Long_I start3, Long_I N3)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() || start2 < 0 || start2 + N2 > v.n2() || start3 < 0 || start3 + N3 > v.n3())
        SLS_ERR("index out of bound!");
#endif
    Jcmat3Fcomp sli(&v(start1, start2, start3), N1, N2, N3, 1, v.n1(), v.n1()*v.n2());
    return sli;
}

inline Jcmat3Fcomp_c cut(Cmat3Fcomp_I v, Long_I start1, Long_I N1, Long_I start2, Long_I N2, Long_I start3, Long_I N3)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() || start2 < 0 || start2 + N2 > v.n2() || start3 < 0 || start3 + N3 > v.n3())
        SLS_ERR("index out of bound!");
#endif
    Jcmat3Fcomp_c sli(&v(start1, start2, start3), N1, N2, N3, 1, v.n1(), v.n1()*v.n2());
    return sli;
}

inline Jcmat3Comp cut(Cmat3Comp_IO v, Long_I start1, Long_I N1, Long_I start2, Long_I N2, Long_I start3, Long_I N3)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() || start2 < 0 || start2 + N2 > v.n2() || start3 < 0 || start3 + N3 > v.n3())
        SLS_ERR("index out of bound!");
#endif
    Jcmat3Comp sli(&v(start1, start2, start3), N1, N2, N3, 1, v.n1(), v.n1()*v.n2());
    return sli;
}

inline Jcmat3Comp_c cut(Cmat3Comp_I v, Long_I start1, Long_I N1, Long_I start2, Long_I N2, Long_I start3, Long_I N3)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() || start2 < 0 || start2 + N2 > v.n2() || start3 < 0 || start3 + N3 > v.n3())
        SLS_ERR("index out of bound!");
#endif
    Jcmat3Comp_c sli(&v(start1, start2, start3), N1, N2, N3, 1, v.n1(), v.n1()*v.n2());
    return sli;
}

inline Jcmat3Lcomp cut(Cmat3Lcomp_IO v, Long_I start1, Long_I N1, Long_I start2, Long_I N2, Long_I start3, Long_I N3)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() || start2 < 0 || start2 + N2 > v.n2() || start3 < 0 || start3 + N3 > v.n3())
        SLS_ERR("index out of bound!");
#endif
    Jcmat3Lcomp sli(&v(start1, start2, start3), N1, N2, N3, 1, v.n1(), v.n1()*v.n2());
    return sli;
}

inline Jcmat3Lcomp_c cut(Cmat3Lcomp_I v, Long_I start1, Long_I N1, Long_I start2, Long_I N2, Long_I start3, Long_I N3)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() || start2 < 0 || start2 + N2 > v.n2() || start3 < 0 || start3 + N3 > v.n3())
        SLS_ERR("index out of bound!");
#endif
    Jcmat3Lcomp_c sli(&v(start1, start2, start3), N1, N2, N3, 1, v.n1(), v.n1()*v.n2());
    return sli;
}


inline DvecInt cut1(MatInt_IO v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j >= v.n2())
        SLS_ERR("index out of bound!");
#endif
    DvecInt sli(&v(0, j), v.n1(), v.n2());
    return sli;
}

inline DvecInt_c cut1(MatInt_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j >= v.n2())
        SLS_ERR("index out of bound!");
#endif
    DvecInt_c sli(&v(0, j), v.n1(), v.n2());
    return sli;
}

inline DvecDoub cut1(MatDoub_IO v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j >= v.n2())
        SLS_ERR("index out of bound!");
#endif
    DvecDoub sli(&v(0, j), v.n1(), v.n2());
    return sli;
}

inline DvecDoub_c cut1(MatDoub_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j >= v.n2())
        SLS_ERR("index out of bound!");
#endif
    DvecDoub_c sli(&v(0, j), v.n1(), v.n2());
    return sli;
}

inline DvecComp cut1(MatComp_IO v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j >= v.n2())
        SLS_ERR("index out of bound!");
#endif
    DvecComp sli(&v(0, j), v.n1(), v.n2());
    return sli;
}

inline DvecComp_c cut1(MatComp_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j >= v.n2())
        SLS_ERR("index out of bound!");
#endif
    DvecComp_c sli(&v(0, j), v.n1(), v.n2());
    return sli;
}

inline SvecInt cut1(CmatInt_IO v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j >= v.n2())
        SLS_ERR("index out of bound!");
#endif
    SvecInt sli(&v(0, j), v.n1());
    return sli;
}

inline SvecInt_c cut1(CmatInt_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j >= v.n2())
        SLS_ERR("index out of bound!");
#endif
    SvecInt_c sli(&v(0, j), v.n1());
    return sli;
}

inline SvecLlong cut1(CmatLlong_IO v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j >= v.n2())
        SLS_ERR("index out of bound!");
#endif
    SvecLlong sli(&v(0, j), v.n1());
    return sli;
}

inline SvecLlong_c cut1(CmatLlong_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j >= v.n2())
        SLS_ERR("index out of bound!");
#endif
    SvecLlong_c sli(&v(0, j), v.n1());
    return sli;
}

inline SvecDoub cut1(CmatDoub_IO v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j >= v.n2())
        SLS_ERR("index out of bound!");
#endif
    SvecDoub sli(&v(0, j), v.n1());
    return sli;
}

inline SvecDoub_c cut1(CmatDoub_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j >= v.n2())
        SLS_ERR("index out of bound!");
#endif
    SvecDoub_c sli(&v(0, j), v.n1());
    return sli;
}

inline SvecComp cut1(CmatComp_IO v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j >= v.n2())
        SLS_ERR("index out of bound!");
#endif
    SvecComp sli(&v(0, j), v.n1());
    return sli;
}

inline SvecComp_c cut1(CmatComp_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j >= v.n2())
        SLS_ERR("index out of bound!");
#endif
    SvecComp_c sli(&v(0, j), v.n1());
    return sli;
}

inline SvecInt cut1(Cmat3Int_IO v, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j >= v.n2() || k < 0 || k >= v.n3())
        SLS_ERR("index out of bound!");
#endif
    SvecInt sli(&v(0, j, k), v.n1());
    return sli;
}

inline SvecInt_c cut1(Cmat3Int_I v, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j >= v.n2() || k < 0 || k >= v.n3())
        SLS_ERR("index out of bound!");
#endif
    SvecInt_c sli(&v(0, j, k), v.n1());
    return sli;
}

inline SvecDoub cut1(Cmat3Doub_IO v, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j >= v.n2() || k < 0 || k >= v.n3())
        SLS_ERR("index out of bound!");
#endif
    SvecDoub sli(&v(0, j, k), v.n1());
    return sli;
}

inline SvecDoub_c cut1(Cmat3Doub_I v, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j >= v.n2() || k < 0 || k >= v.n3())
        SLS_ERR("index out of bound!");
#endif
    SvecDoub_c sli(&v(0, j, k), v.n1());
    return sli;
}

inline SvecComp cut1(Cmat3Comp_IO v, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j >= v.n2() || k < 0 || k >= v.n3())
        SLS_ERR("index out of bound!");
#endif
    SvecComp sli(&v(0, j, k), v.n1());
    return sli;
}

inline SvecComp_c cut1(Cmat3Comp_I v, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j >= v.n2() || k < 0 || k >= v.n3())
        SLS_ERR("index out of bound!");
#endif
    SvecComp_c sli(&v(0, j, k), v.n1());
    return sli;
}

inline SvecInt cut1(ScmatInt_IO v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j >= v.n2())
        SLS_ERR("index out of bound!");
#endif
    SvecInt sli(&v(0, j), v.n1());
    return sli;
}

inline SvecInt_c cut1(ScmatInt_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j >= v.n2())
        SLS_ERR("index out of bound!");
#endif
    SvecInt_c sli(&v(0, j), v.n1());
    return sli;
}

inline SvecDoub cut1(ScmatDoub_IO v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j >= v.n2())
        SLS_ERR("index out of bound!");
#endif
    SvecDoub sli(&v(0, j), v.n1());
    return sli;
}

inline SvecDoub_c cut1(ScmatDoub_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j >= v.n2())
        SLS_ERR("index out of bound!");
#endif
    SvecDoub_c sli(&v(0, j), v.n1());
    return sli;
}

inline SvecComp cut1(ScmatComp_IO v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j >= v.n2())
        SLS_ERR("index out of bound!");
#endif
    SvecComp sli(&v(0, j), v.n1());
    return sli;
}

inline SvecComp_c cut1(ScmatComp_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j >= v.n2())
        SLS_ERR("index out of bound!");
#endif
    SvecComp_c sli(&v(0, j), v.n1());
    return sli;
}


inline SvecInt cut1(CmatInt_IO v, Long_I i, Long_I N1, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i + N1 > v.n1() || j < 0 || j >= v.n2())
        SLS_ERR("index out of bound!");
#endif
    SvecInt sli(&v(i, j), N1);
    return sli;
}

inline SvecInt_c cut1(CmatInt_I v, Long_I i, Long_I N1, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i + N1 > v.n1() || j < 0 || j >= v.n2())
        SLS_ERR("index out of bound!");
#endif
    SvecInt_c sli(&v(i, j), N1);
    return sli;
}

inline SvecLlong cut1(CmatLlong_IO v, Long_I i, Long_I N1, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i + N1 > v.n1() || j < 0 || j >= v.n2())
        SLS_ERR("index out of bound!");
#endif
    SvecLlong sli(&v(i, j), N1);
    return sli;
}

inline SvecLlong_c cut1(CmatLlong_I v, Long_I i, Long_I N1, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i + N1 > v.n1() || j < 0 || j >= v.n2())
        SLS_ERR("index out of bound!");
#endif
    SvecLlong_c sli(&v(i, j), N1);
    return sli;
}

inline SvecDoub cut1(CmatDoub_IO v, Long_I i, Long_I N1, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i + N1 > v.n1() || j < 0 || j >= v.n2())
        SLS_ERR("index out of bound!");
#endif
    SvecDoub sli(&v(i, j), N1);
    return sli;
}

inline SvecDoub_c cut1(CmatDoub_I v, Long_I i, Long_I N1, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i + N1 > v.n1() || j < 0 || j >= v.n2())
        SLS_ERR("index out of bound!");
#endif
    SvecDoub_c sli(&v(i, j), N1);
    return sli;
}

inline SvecComp cut1(CmatComp_IO v, Long_I i, Long_I N1, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i + N1 > v.n1() || j < 0 || j >= v.n2())
        SLS_ERR("index out of bound!");
#endif
    SvecComp sli(&v(i, j), N1);
    return sli;
}

inline SvecComp_c cut1(CmatComp_I v, Long_I i, Long_I N1, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i + N1 > v.n1() || j < 0 || j >= v.n2())
        SLS_ERR("index out of bound!");
#endif
    SvecComp_c sli(&v(i, j), N1);
    return sli;
}

inline SvecInt cut1(Cmat3Int_IO v, Long_I i, Long_I N1, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i + N1 > v.n1() || j < 0 || j >= v.n2() || k < 0 || k >= v.n3())
        SLS_ERR("index out of bound!");
#endif
    SvecInt sli(&v(i, j, k), N1);
    return sli;
}

inline SvecInt_c cut1(Cmat3Int_I v, Long_I i, Long_I N1, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i + N1 > v.n1() || j < 0 || j >= v.n2() || k < 0 || k >= v.n3())
        SLS_ERR("index out of bound!");
#endif
    SvecInt_c sli(&v(i, j, k), N1);
    return sli;
}

inline SvecLlong cut1(Cmat3Llong_IO v, Long_I i, Long_I N1, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i + N1 > v.n1() || j < 0 || j >= v.n2() || k < 0 || k >= v.n3())
        SLS_ERR("index out of bound!");
#endif
    SvecLlong sli(&v(i, j, k), N1);
    return sli;
}

inline SvecLlong_c cut1(Cmat3Llong_I v, Long_I i, Long_I N1, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i + N1 > v.n1() || j < 0 || j >= v.n2() || k < 0 || k >= v.n3())
        SLS_ERR("index out of bound!");
#endif
    SvecLlong_c sli(&v(i, j, k), N1);
    return sli;
}

inline SvecDoub cut1(Cmat3Doub_IO v, Long_I i, Long_I N1, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i + N1 > v.n1() || j < 0 || j >= v.n2() || k < 0 || k >= v.n3())
        SLS_ERR("index out of bound!");
#endif
    SvecDoub sli(&v(i, j, k), N1);
    return sli;
}

inline SvecDoub_c cut1(Cmat3Doub_I v, Long_I i, Long_I N1, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i + N1 > v.n1() || j < 0 || j >= v.n2() || k < 0 || k >= v.n3())
        SLS_ERR("index out of bound!");
#endif
    SvecDoub_c sli(&v(i, j, k), N1);
    return sli;
}

inline SvecComp cut1(Cmat3Comp_IO v, Long_I i, Long_I N1, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i + N1 > v.n1() || j < 0 || j >= v.n2() || k < 0 || k >= v.n3())
        SLS_ERR("index out of bound!");
#endif
    SvecComp sli(&v(i, j, k), N1);
    return sli;
}

inline SvecComp_c cut1(Cmat3Comp_I v, Long_I i, Long_I N1, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i + N1 > v.n1() || j < 0 || j >= v.n2() || k < 0 || k >= v.n3())
        SLS_ERR("index out of bound!");
#endif
    SvecComp_c sli(&v(i, j, k), N1);
    return sli;
}


inline DvecInt cut2(CmatInt_IO v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1())
        SLS_ERR("index out of bound!");
#endif
    DvecInt sli(&v(i, 0), v.n2(), v.n1());
    return sli;
}

inline DvecInt_c cut2(CmatInt_I v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1())
        SLS_ERR("index out of bound!");
#endif
    DvecInt_c sli(&v(i, 0), v.n2(), v.n1());
    return sli;
}

inline DvecLlong cut2(CmatLlong_IO v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1())
        SLS_ERR("index out of bound!");
#endif
    DvecLlong sli(&v(i, 0), v.n2(), v.n1());
    return sli;
}

inline DvecLlong_c cut2(CmatLlong_I v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1())
        SLS_ERR("index out of bound!");
#endif
    DvecLlong_c sli(&v(i, 0), v.n2(), v.n1());
    return sli;
}

inline DvecDoub cut2(CmatDoub_IO v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1())
        SLS_ERR("index out of bound!");
#endif
    DvecDoub sli(&v(i, 0), v.n2(), v.n1());
    return sli;
}

inline DvecDoub_c cut2(CmatDoub_I v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1())
        SLS_ERR("index out of bound!");
#endif
    DvecDoub_c sli(&v(i, 0), v.n2(), v.n1());
    return sli;
}

inline DvecComp cut2(CmatComp_IO v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1())
        SLS_ERR("index out of bound!");
#endif
    DvecComp sli(&v(i, 0), v.n2(), v.n1());
    return sli;
}

inline DvecComp_c cut2(CmatComp_I v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1())
        SLS_ERR("index out of bound!");
#endif
    DvecComp_c sli(&v(i, 0), v.n2(), v.n1());
    return sli;
}

inline DvecLlong cut2(ScmatLlong_IO v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1())
        SLS_ERR("index out of bound!");
#endif
    DvecLlong sli(&v(i, 0), v.n2(), v.n1());
    return sli;
}

inline DvecLlong_c cut2(ScmatLlong_I v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1())
        SLS_ERR("index out of bound!");
#endif
    DvecLlong_c sli(&v(i, 0), v.n2(), v.n1());
    return sli;
}

inline DvecDoub cut2(ScmatDoub_IO v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1())
        SLS_ERR("index out of bound!");
#endif
    DvecDoub sli(&v(i, 0), v.n2(), v.n1());
    return sli;
}

inline DvecDoub_c cut2(ScmatDoub_I v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1())
        SLS_ERR("index out of bound!");
#endif
    DvecDoub_c sli(&v(i, 0), v.n2(), v.n1());
    return sli;
}

inline DvecComp cut2(ScmatComp_IO v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1())
        SLS_ERR("index out of bound!");
#endif
    DvecComp sli(&v(i, 0), v.n2(), v.n1());
    return sli;
}

inline DvecComp_c cut2(ScmatComp_I v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1())
        SLS_ERR("index out of bound!");
#endif
    DvecComp_c sli(&v(i, 0), v.n2(), v.n1());
    return sli;
}

inline SvecInt cut2(MatInt_IO v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1())
        SLS_ERR("index out of bound!");
#endif
    SvecInt sli(&v(i, 0), v.n2());
    return sli;
}

inline SvecInt_c cut2(MatInt_I v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1())
        SLS_ERR("index out of bound!");
#endif
    SvecInt_c sli(&v(i, 0), v.n2());
    return sli;
}

inline SvecDoub cut2(MatDoub_IO v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1())
        SLS_ERR("index out of bound!");
#endif
    SvecDoub sli(&v(i, 0), v.n2());
    return sli;
}

inline SvecDoub_c cut2(MatDoub_I v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1())
        SLS_ERR("index out of bound!");
#endif
    SvecDoub_c sli(&v(i, 0), v.n2());
    return sli;
}

inline SvecComp cut2(MatComp_IO v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1())
        SLS_ERR("index out of bound!");
#endif
    SvecComp sli(&v(i, 0), v.n2());
    return sli;
}

inline SvecComp_c cut2(MatComp_I v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1())
        SLS_ERR("index out of bound!");
#endif
    SvecComp_c sli(&v(i, 0), v.n2());
    return sli;
}

inline DvecComp cut2(Cmat3Comp_IO v, Long_I i, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1() || k < 0 || k >= v.n3())
        SLS_ERR("index out of bound!");
#endif
    DvecComp sli(&v(i, 0, k), v.n2(), v.n1());
    return sli;
}

inline DvecComp_c cut2(Cmat3Comp_I v, Long_I i, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1() || k < 0 || k >= v.n3())
        SLS_ERR("index out of bound!");
#endif
    DvecComp_c sli(&v(i, 0, k), v.n2(), v.n1());
    return sli;
}


inline DvecInt cut2(CmatInt_IO v, Long_I i, Long_I j, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1() || j < 0 || j + N2 > v.n2())
        SLS_ERR("out of bound!");
#endif
    DvecInt sli(&v(i, j), N2, v.n1());
    return sli;
}

inline DvecInt_c cut2(CmatInt_I v, Long_I i, Long_I j, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1() || j < 0 || j + N2 > v.n2())
        SLS_ERR("out of bound!");
#endif
    DvecInt_c sli(&v(i, j), N2, v.n1());
    return sli;
}

inline DvecLlong cut2(CmatLlong_IO v, Long_I i, Long_I j, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1() || j < 0 || j + N2 > v.n2())
        SLS_ERR("out of bound!");
#endif
    DvecLlong sli(&v(i, j), N2, v.n1());
    return sli;
}

inline DvecLlong_c cut2(CmatLlong_I v, Long_I i, Long_I j, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1() || j < 0 || j + N2 > v.n2())
        SLS_ERR("out of bound!");
#endif
    DvecLlong_c sli(&v(i, j), N2, v.n1());
    return sli;
}

inline DvecDoub cut2(CmatDoub_IO v, Long_I i, Long_I j, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1() || j < 0 || j + N2 > v.n2())
        SLS_ERR("out of bound!");
#endif
    DvecDoub sli(&v(i, j), N2, v.n1());
    return sli;
}

inline DvecDoub_c cut2(CmatDoub_I v, Long_I i, Long_I j, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1() || j < 0 || j + N2 > v.n2())
        SLS_ERR("out of bound!");
#endif
    DvecDoub_c sli(&v(i, j), N2, v.n1());
    return sli;
}

inline DvecComp cut2(CmatComp_IO v, Long_I i, Long_I j, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1() || j < 0 || j + N2 > v.n2())
        SLS_ERR("out of bound!");
#endif
    DvecComp sli(&v(i, j), N2, v.n1());
    return sli;
}

inline DvecComp_c cut2(CmatComp_I v, Long_I i, Long_I j, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1() || j < 0 || j + N2 > v.n2())
        SLS_ERR("out of bound!");
#endif
    DvecComp_c sli(&v(i, j), N2, v.n1());
    return sli;
}

inline DvecInt cut2(Cmat3Int_IO v, Long_I i, Long_I j, Long_I N2, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1() || j < 0 || j + N2 > v.n2() || k < 0 || k >= v.n3())
        SLS_ERR("out of bound!");
#endif
    DvecInt sli(&v(i, j, k), N2, v.n1());
    return sli;
}

inline DvecInt_c cut2(Cmat3Int_I v, Long_I i, Long_I j, Long_I N2, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1() || j < 0 || j + N2 > v.n2() || k < 0 || k >= v.n3())
        SLS_ERR("out of bound!");
#endif
    DvecInt_c sli(&v(i, j, k), N2, v.n1());
    return sli;
}

inline DvecLlong cut2(Cmat3Llong_IO v, Long_I i, Long_I j, Long_I N2, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1() || j < 0 || j + N2 > v.n2() || k < 0 || k >= v.n3())
        SLS_ERR("out of bound!");
#endif
    DvecLlong sli(&v(i, j, k), N2, v.n1());
    return sli;
}

inline DvecLlong_c cut2(Cmat3Llong_I v, Long_I i, Long_I j, Long_I N2, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1() || j < 0 || j + N2 > v.n2() || k < 0 || k >= v.n3())
        SLS_ERR("out of bound!");
#endif
    DvecLlong_c sli(&v(i, j, k), N2, v.n1());
    return sli;
}

inline DvecDoub cut2(Cmat3Doub_IO v, Long_I i, Long_I j, Long_I N2, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1() || j < 0 || j + N2 > v.n2() || k < 0 || k >= v.n3())
        SLS_ERR("out of bound!");
#endif
    DvecDoub sli(&v(i, j, k), N2, v.n1());
    return sli;
}

inline DvecDoub_c cut2(Cmat3Doub_I v, Long_I i, Long_I j, Long_I N2, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1() || j < 0 || j + N2 > v.n2() || k < 0 || k >= v.n3())
        SLS_ERR("out of bound!");
#endif
    DvecDoub_c sli(&v(i, j, k), N2, v.n1());
    return sli;
}

inline DvecComp cut2(Cmat3Comp_IO v, Long_I i, Long_I j, Long_I N2, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1() || j < 0 || j + N2 > v.n2() || k < 0 || k >= v.n3())
        SLS_ERR("out of bound!");
#endif
    DvecComp sli(&v(i, j, k), N2, v.n1());
    return sli;
}

inline DvecComp_c cut2(Cmat3Comp_I v, Long_I i, Long_I j, Long_I N2, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1() || j < 0 || j + N2 > v.n2() || k < 0 || k >= v.n3())
        SLS_ERR("out of bound!");
#endif
    DvecComp_c sli(&v(i, j, k), N2, v.n1());
    return sli;
}


inline DvecDoub cut3(Cmat3Doub_IO v, Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1() || j < 0 || j >= v.n2())
        SLS_ERR("index out of bound!");
#endif
    DvecDoub sli(&v(i, j, 0), v.n3(), v.n1()*v.n2());
    return sli;
}

inline DvecDoub_c cut3(Cmat3Doub_I v, Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1() || j < 0 || j >= v.n2())
        SLS_ERR("index out of bound!");
#endif
    DvecDoub_c sli(&v(i, j, 0), v.n3(), v.n1()*v.n2());
    return sli;
}

inline DvecComp cut3(Cmat3Comp_IO v, Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1() || j < 0 || j >= v.n2())
        SLS_ERR("index out of bound!");
#endif
    DvecComp sli(&v(i, j, 0), v.n3(), v.n1()*v.n2());
    return sli;
}

inline DvecComp_c cut3(Cmat3Comp_I v, Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1() || j < 0 || j >= v.n2())
        SLS_ERR("index out of bound!");
#endif
    DvecComp_c sli(&v(i, j, 0), v.n3(), v.n1()*v.n2());
    return sli;
}


inline ScmatInt cut12(Cmat3Int_IO v, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (k < 0 || k >= v.n3())
        SLS_ERR("index out of bound!");
#endif
    ScmatInt sli(&v(0, 0, k), v.n1(), v.n2());
    return sli;
}

inline ScmatInt_c cut12(Cmat3Int_I v, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (k < 0 || k >= v.n3())
        SLS_ERR("index out of bound!");
#endif
    ScmatInt_c sli(&v(0, 0, k), v.n1(), v.n2());
    return sli;
}

inline ScmatDoub cut12(Cmat3Doub_IO v, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (k < 0 || k >= v.n3())
        SLS_ERR("index out of bound!");
#endif
    ScmatDoub sli(&v(0, 0, k), v.n1(), v.n2());
    return sli;
}

inline ScmatDoub_c cut12(Cmat3Doub_I v, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (k < 0 || k >= v.n3())
        SLS_ERR("index out of bound!");
#endif
    ScmatDoub_c sli(&v(0, 0, k), v.n1(), v.n2());
    return sli;
}

inline ScmatComp cut12(Cmat3Comp_IO v, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (k < 0 || k >= v.n3())
        SLS_ERR("index out of bound!");
#endif
    ScmatComp sli(&v(0, 0, k), v.n1(), v.n2());
    return sli;
}

inline ScmatComp_c cut12(Cmat3Comp_I v, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (k < 0 || k >= v.n3())
        SLS_ERR("index out of bound!");
#endif
    ScmatComp_c sli(&v(0, 0, k), v.n1(), v.n2());
    return sli;
}

inline ScmatDoub cut12(Scmat3Doub_IO v, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (k < 0 || k >= v.n3())
        SLS_ERR("index out of bound!");
#endif
    ScmatDoub sli(&v(0, 0, k), v.n1(), v.n2());
    return sli;
}

inline ScmatDoub_c cut12(Scmat3Doub_I v, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (k < 0 || k >= v.n3())
        SLS_ERR("index out of bound!");
#endif
    ScmatDoub_c sli(&v(0, 0, k), v.n1(), v.n2());
    return sli;
}

inline ScmatComp cut12(Scmat3Comp_IO v, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (k < 0 || k >= v.n3())
        SLS_ERR("index out of bound!");
#endif
    ScmatComp sli(&v(0, 0, k), v.n1(), v.n2());
    return sli;
}

inline ScmatComp_c cut12(Scmat3Comp_I v, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (k < 0 || k >= v.n3())
        SLS_ERR("index out of bound!");
#endif
    ScmatComp_c sli(&v(0, 0, k), v.n1(), v.n2());
    return sli;
}

inline ScmatInt cut12(Cmat4Int_IO v, Long_I k, Long_I l)
{
#ifdef SLS_CHECK_BOUNDS
    if (k < 0 || k >= v.n3() || l < 0 || l >= v.n4())
        SLS_ERR("index out of bound!");
#endif
    ScmatInt sli(&v(0, 0, k, l), v.n1(), v.n2());
    return sli;
}

inline ScmatInt_c cut12(Cmat4Int_I v, Long_I k, Long_I l)
{
#ifdef SLS_CHECK_BOUNDS
    if (k < 0 || k >= v.n3() || l < 0 || l >= v.n4())
        SLS_ERR("index out of bound!");
#endif
    ScmatInt_c sli(&v(0, 0, k, l), v.n1(), v.n2());
    return sli;
}

inline ScmatLlong cut12(Cmat4Llong_IO v, Long_I k, Long_I l)
{
#ifdef SLS_CHECK_BOUNDS
    if (k < 0 || k >= v.n3() || l < 0 || l >= v.n4())
        SLS_ERR("index out of bound!");
#endif
    ScmatLlong sli(&v(0, 0, k, l), v.n1(), v.n2());
    return sli;
}

inline ScmatLlong_c cut12(Cmat4Llong_I v, Long_I k, Long_I l)
{
#ifdef SLS_CHECK_BOUNDS
    if (k < 0 || k >= v.n3() || l < 0 || l >= v.n4())
        SLS_ERR("index out of bound!");
#endif
    ScmatLlong_c sli(&v(0, 0, k, l), v.n1(), v.n2());
    return sli;
}

inline ScmatDoub cut12(Cmat4Doub_IO v, Long_I k, Long_I l)
{
#ifdef SLS_CHECK_BOUNDS
    if (k < 0 || k >= v.n3() || l < 0 || l >= v.n4())
        SLS_ERR("index out of bound!");
#endif
    ScmatDoub sli(&v(0, 0, k, l), v.n1(), v.n2());
    return sli;
}

inline ScmatDoub_c cut12(Cmat4Doub_I v, Long_I k, Long_I l)
{
#ifdef SLS_CHECK_BOUNDS
    if (k < 0 || k >= v.n3() || l < 0 || l >= v.n4())
        SLS_ERR("index out of bound!");
#endif
    ScmatDoub_c sli(&v(0, 0, k, l), v.n1(), v.n2());
    return sli;
}

inline ScmatComp cut12(Cmat4Comp_IO v, Long_I k, Long_I l)
{
#ifdef SLS_CHECK_BOUNDS
    if (k < 0 || k >= v.n3() || l < 0 || l >= v.n4())
        SLS_ERR("index out of bound!");
#endif
    ScmatComp sli(&v(0, 0, k, l), v.n1(), v.n2());
    return sli;
}

inline ScmatComp_c cut12(Cmat4Comp_I v, Long_I k, Long_I l)
{
#ifdef SLS_CHECK_BOUNDS
    if (k < 0 || k >= v.n3() || l < 0 || l >= v.n4())
        SLS_ERR("index out of bound!");
#endif
    ScmatComp_c sli(&v(0, 0, k, l), v.n1(), v.n2());
    return sli;
}


inline ScmatInt cut12(Cmat3Int_IO v, Long_I j, Long_I N2, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j + N2 > v.n2() || k < 0 || k >= v.n3())
        SLS_ERR("index out of bound!");
#endif
    ScmatInt sli(&v(0, j, k), v.n1(), N2);
    return sli;
}

inline ScmatInt_c cut12(Cmat3Int_I v, Long_I j, Long_I N2, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j + N2 > v.n2() || k < 0 || k >= v.n3())
        SLS_ERR("index out of bound!");
#endif
    ScmatInt_c sli(&v(0, j, k), v.n1(), N2);
    return sli;
}

inline ScmatDoub cut12(Cmat3Doub_IO v, Long_I j, Long_I N2, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j + N2 > v.n2() || k < 0 || k >= v.n3())
        SLS_ERR("index out of bound!");
#endif
    ScmatDoub sli(&v(0, j, k), v.n1(), N2);
    return sli;
}

inline ScmatDoub_c cut12(Cmat3Doub_I v, Long_I j, Long_I N2, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j + N2 > v.n2() || k < 0 || k >= v.n3())
        SLS_ERR("index out of bound!");
#endif
    ScmatDoub_c sli(&v(0, j, k), v.n1(), N2);
    return sli;
}

inline ScmatComp cut12(Cmat3Comp_IO v, Long_I j, Long_I N2, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j + N2 > v.n2() || k < 0 || k >= v.n3())
        SLS_ERR("index out of bound!");
#endif
    ScmatComp sli(&v(0, j, k), v.n1(), N2);
    return sli;
}

inline ScmatComp_c cut12(Cmat3Comp_I v, Long_I j, Long_I N2, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j + N2 > v.n2() || k < 0 || k >= v.n3())
        SLS_ERR("index out of bound!");
#endif
    ScmatComp_c sli(&v(0, j, k), v.n1(), N2);
    return sli;
}


inline DcmatInt cut12(Cmat3Int_IO v, Long_I i, Long_I N1, Long_I j, Long_I N2, Long_I k)
{
    DcmatInt sli(&v(i, j, k), N1, N2, v.n1());
    return sli;
}

inline DcmatInt_c cut12(Cmat3Int_I v, Long_I i, Long_I N1, Long_I j, Long_I N2, Long_I k)
{
    DcmatInt_c sli(&v(i, j, k), N1, N2, v.n1());
    return sli;
}

inline DcmatDoub cut12(Cmat3Doub_IO v, Long_I i, Long_I N1, Long_I j, Long_I N2, Long_I k)
{
    DcmatDoub sli(&v(i, j, k), N1, N2, v.n1());
    return sli;
}

inline DcmatDoub_c cut12(Cmat3Doub_I v, Long_I i, Long_I N1, Long_I j, Long_I N2, Long_I k)
{
    DcmatDoub_c sli(&v(i, j, k), N1, N2, v.n1());
    return sli;
}

inline DcmatComp cut12(Cmat3Comp_IO v, Long_I i, Long_I N1, Long_I j, Long_I N2, Long_I k)
{
    DcmatComp sli(&v(i, j, k), N1, N2, v.n1());
    return sli;
}

inline DcmatComp_c cut12(Cmat3Comp_I v, Long_I i, Long_I N1, Long_I j, Long_I N2, Long_I k)
{
    DcmatComp_c sli(&v(i, j, k), N1, N2, v.n1());
    return sli;
}

} // namespace slisc
