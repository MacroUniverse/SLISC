#pragma once
#include "Vec.h"
#include "Mat.h"
#include "Cmat.h"
#include "Cmat3.h"
#include "Cmat4.h"
#include "Svec.h"
#include "Dvec.h"
#include "Scmat.h"
#include "Scmat3.h"
#include "Dcmat.h"
#include "Jcmat3.h"

namespace slisc {
inline DcmatDoub cut(ScmatDoub_IO v, Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n0() ||
            start2 < 0 || start2 + N2 > v.n1())
        SLS_ERR("index out of bound!");
#endif
    DcmatDoub sli(&v(start1, start2), N1, N2, v.n0());
    return sli;
}

inline DcmatDoub_c cut(ScmatDoub_I v,
    Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n0() ||
            start2 < 0 || start2 + N2 > v.n1())
        SLS_ERR("index out of bound!");
#endif
    DcmatDoub_c sli(&v(start1, start2), N1, N2, v.n0());
    return sli;
}

inline Jcmat3Doub cut(Cmat3Doub_IO v, Long_I start1, Long_I N1, Long_I start2, Long_I N2, Long_I start3, Long_I N3)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n0() || start2 < 0 || start2 + N2 > v.n1() || start3 < 0 || start3 + N3 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    Jcmat3Doub sli(&v(start1, start2, start3), N1, N2, N3, 1, v.n0(), v.n0()*v.n1());
    return sli;
}

inline Jcmat3Doub_c cut(Cmat3Doub_I v, Long_I start1, Long_I N1, Long_I start2, Long_I N2, Long_I start3, Long_I N3)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n0() || start2 < 0 || start2 + N2 > v.n1() || start3 < 0 || start3 + N3 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    Jcmat3Doub_c sli(&v(start1, start2, start3), N1, N2, N3, 1, v.n0(), v.n0()*v.n1());
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

inline DcmatDoub cut(CmatDoub_IO v, Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n0() ||
            start2 < 0 || start2 + N2 > v.n1())
        SLS_ERR("index out of bound!");
#endif
    DcmatDoub sli(&v(start1, start2), N1, N2, v.n0());
    return sli;
}

inline DcmatDoub_c cut(CmatDoub_I v,
    Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n0() ||
            start2 < 0 || start2 + N2 > v.n1())
        SLS_ERR("index out of bound!");
#endif
    DcmatDoub_c sli(&v(start1, start2), N1, N2, v.n0());
    return sli;
}
inline ScmatDoub cut(CmatDoub_IO v, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start2 < 0 || start2 + N2 > v.n1())
        SLS_ERR("index out of bound!");
#endif
    ScmatDoub sli(&v(0, start2), v.n0(), N2);
    return sli;
}

inline ScmatDoub_c cut(CmatDoub_I v, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start2 < 0 || start2 + N2 > v.n1())
        SLS_ERR("index out of bound!");
#endif
    ScmatDoub_c sli(&v(0, start2), v.n0(), N2);
    return sli;
}


inline SvecComp cut0(CmatComp_IO v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j >= v.n1())
        SLS_ERR("index out of bound!");
#endif
    SvecComp sli(&v(0, j), v.n0());
    return sli;
}

inline SvecComp_c cut0(CmatComp_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j >= v.n1())
        SLS_ERR("index out of bound!");
#endif
    SvecComp_c sli(&v(0, j), v.n0());
    return sli;
}

inline SvecDoub cut0(ScmatDoub_IO v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j >= v.n1())
        SLS_ERR("index out of bound!");
#endif
    SvecDoub sli(&v(0, j), v.n0());
    return sli;
}

inline SvecDoub_c cut0(ScmatDoub_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j >= v.n1())
        SLS_ERR("index out of bound!");
#endif
    SvecDoub_c sli(&v(0, j), v.n0());
    return sli;
}

inline SvecDoub cut0(CmatDoub_IO v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j >= v.n1())
        SLS_ERR("index out of bound!");
#endif
    SvecDoub sli(&v(0, j), v.n0());
    return sli;
}

inline SvecDoub_c cut0(CmatDoub_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j >= v.n1())
        SLS_ERR("index out of bound!");
#endif
    SvecDoub_c sli(&v(0, j), v.n0());
    return sli;
}

inline DvecDoub cut0(MatDoub_IO v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j >= v.n1())
        SLS_ERR("index out of bound!");
#endif
    DvecDoub sli(&v(0, j), v.n0(), v.n1());
    return sli;
}

inline DvecDoub_c cut0(MatDoub_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j >= v.n1())
        SLS_ERR("index out of bound!");
#endif
    DvecDoub_c sli(&v(0, j), v.n0(), v.n1());
    return sli;
}

inline DvecComp cut0(MatComp_IO v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j >= v.n1())
        SLS_ERR("index out of bound!");
#endif
    DvecComp sli(&v(0, j), v.n0(), v.n1());
    return sli;
}

inline DvecComp_c cut0(MatComp_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j >= v.n1())
        SLS_ERR("index out of bound!");
#endif
    DvecComp_c sli(&v(0, j), v.n0(), v.n1());
    return sli;
}

inline SvecComp cut0(ScmatComp_IO v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j >= v.n1())
        SLS_ERR("index out of bound!");
#endif
    SvecComp sli(&v(0, j), v.n0());
    return sli;
}

inline SvecComp_c cut0(ScmatComp_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j >= v.n1())
        SLS_ERR("index out of bound!");
#endif
    SvecComp_c sli(&v(0, j), v.n0());
    return sli;
}


inline SvecComp cut0(ScmatComp_IO v, Long_I i, Long_I N1, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i + N1 > v.n0() || j < 0 || j >= v.n1())
        SLS_ERR("index out of bound!");
#endif
    SvecComp sli(&v(i, j), N1);
    return sli;
}

inline SvecComp_c cut0(ScmatComp_I v, Long_I i, Long_I N1, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i + N1 > v.n0() || j < 0 || j >= v.n1())
        SLS_ERR("index out of bound!");
#endif
    SvecComp_c sli(&v(i, j), N1);
    return sli;
}


inline DvecComp cut1(CmatComp_IO v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n0())
        SLS_ERR("index out of bound!");
#endif
    DvecComp sli(&v(i, 0), v.n1(), v.n0());
    return sli;
}

inline DvecComp_c cut1(CmatComp_I v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n0())
        SLS_ERR("index out of bound!");
#endif
    DvecComp_c sli(&v(i, 0), v.n1(), v.n0());
    return sli;
}

inline DvecComp cut1(ScmatComp_IO v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n0())
        SLS_ERR("index out of bound!");
#endif
    DvecComp sli(&v(i, 0), v.n1(), v.n0());
    return sli;
}

inline DvecComp_c cut1(ScmatComp_I v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n0())
        SLS_ERR("index out of bound!");
#endif
    DvecComp_c sli(&v(i, 0), v.n1(), v.n0());
    return sli;
}

inline DvecDoub cut1(CmatDoub_IO v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n0())
        SLS_ERR("index out of bound!");
#endif
    DvecDoub sli(&v(i, 0), v.n1(), v.n0());
    return sli;
}

inline DvecDoub_c cut1(CmatDoub_I v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n0())
        SLS_ERR("index out of bound!");
#endif
    DvecDoub_c sli(&v(i, 0), v.n1(), v.n0());
    return sli;
}

inline SvecDoub cut1(MatDoub_IO v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n0())
        SLS_ERR("index out of bound!");
#endif
    SvecDoub sli(&v(i, 0), v.n1());
    return sli;
}

inline SvecDoub_c cut1(MatDoub_I v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n0())
        SLS_ERR("index out of bound!");
#endif
    SvecDoub_c sli(&v(i, 0), v.n1());
    return sli;
}

inline SvecComp cut1(MatComp_IO v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n0())
        SLS_ERR("index out of bound!");
#endif
    SvecComp sli(&v(i, 0), v.n1());
    return sli;
}

inline SvecComp_c cut1(MatComp_I v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n0())
        SLS_ERR("index out of bound!");
#endif
    SvecComp_c sli(&v(i, 0), v.n1());
    return sli;
}

inline DvecInt cut1(CmatInt_IO v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n0())
        SLS_ERR("index out of bound!");
#endif
    DvecInt sli(&v(i, 0), v.n1(), v.n0());
    return sli;
}

inline DvecInt_c cut1(CmatInt_I v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n0())
        SLS_ERR("index out of bound!");
#endif
    DvecInt_c sli(&v(i, 0), v.n1(), v.n0());
    return sli;
}

inline DvecLlong cut1(CmatLlong_IO v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n0())
        SLS_ERR("index out of bound!");
#endif
    DvecLlong sli(&v(i, 0), v.n1(), v.n0());
    return sli;
}

inline DvecLlong_c cut1(CmatLlong_I v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n0())
        SLS_ERR("index out of bound!");
#endif
    DvecLlong_c sli(&v(i, 0), v.n1(), v.n0());
    return sli;
}


inline DvecComp cut1(CmatComp_IO v, Long_I i, Long_I j, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n0() || j < 0 || j + N2 > v.n1())
        SLS_ERR("out of bound!");
#endif
    DvecComp sli(&v(i, j), N2, v.n0());
    return sli;
}

inline DvecComp_c cut1(CmatComp_I v, Long_I i, Long_I j, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n0() || j < 0 || j + N2 > v.n1())
        SLS_ERR("out of bound!");
#endif
    DvecComp_c sli(&v(i, j), N2, v.n0());
    return sli;
}


inline DvecDoub cut2(Cmat3Doub_IO v, Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n0() || j < 0 || j >= v.n1())
        SLS_ERR("index out of bound!");
#endif
    DvecDoub sli(&v(i, j, 0), v.n2(), v.n0()*v.n1());
    return sli;
}

inline DvecDoub_c cut2(Cmat3Doub_I v, Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n0() || j < 0 || j >= v.n1())
        SLS_ERR("index out of bound!");
#endif
    DvecDoub_c sli(&v(i, j, 0), v.n2(), v.n0()*v.n1());
    return sli;
}


inline ScmatComp cut01(Cmat3Comp_IO v, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (k < 0 || k >= v.n2())
        SLS_ERR("index out of bound!");
#endif
    ScmatComp sli(&v(0, 0, k), v.n0(), v.n1());
    return sli;
}

inline ScmatComp_c cut01(Cmat3Comp_I v, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (k < 0 || k >= v.n2())
        SLS_ERR("index out of bound!");
#endif
    ScmatComp_c sli(&v(0, 0, k), v.n0(), v.n1());
    return sli;
}


inline ScmatDoub cut01(Cmat3Doub_IO v, Long_I j, Long_I N2, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j + N2 > v.n1() || k < 0 || k >= v.n2())
        SLS_ERR("index out of bound!");
#endif
    ScmatDoub sli(&v(0, j, k), v.n0(), N2);
    return sli;
}

inline ScmatDoub_c cut01(Cmat3Doub_I v, Long_I j, Long_I N2, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j + N2 > v.n1() || k < 0 || k >= v.n2())
        SLS_ERR("index out of bound!");
#endif
    ScmatDoub_c sli(&v(0, j, k), v.n0(), N2);
    return sli;
}


inline DcmatDoub cut01(Cmat3Doub_IO v, Long_I i, Long_I N1, Long_I j, Long_I N2, Long_I k)
{
    DcmatDoub sli(&v(i, j, k), N1, N2, v.n0());
    return sli;
}

inline DcmatDoub_c cut01(Cmat3Doub_I v, Long_I i, Long_I N1, Long_I j, Long_I N2, Long_I k)
{
    DcmatDoub_c sli(&v(i, j, k), N1, N2, v.n0());
    return sli;
}

} // namespace slisc
