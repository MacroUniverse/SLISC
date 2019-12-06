#pragma once
#include "Vec.h"
#include "Cmat.h"
#include "Svec.h"
#include "Dvec.h"
#include "Scmat.h"
#include "Dcmat.h"

namespace slisc {
inline void slice(SvecDoub &sli, VecDoub_IO v,
    Long_I start, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (start < 0 || start + N > v.size())
        SLS_ERR("index out of bound!");
#endif
    sli.set(v.ptr() + start, N);
}

inline void slice(SvecComp &sli, VecComp_IO v,
    Long_I start, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (start < 0 || start + N > v.size())
        SLS_ERR("index out of bound!");
#endif
    sli.set(v.ptr() + start, N);
}

inline void slice(SvecDoub &sli, SvecDoub_IO v,
    Long_I start, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (start < 0 || start + N > v.size())
        SLS_ERR("index out of bound!");
#endif
    sli.set(v.ptr() + start, N);
}

inline void slice(SvecComp &sli, SvecComp_IO v,
    Long_I start, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (start < 0 || start + N > v.size())
        SLS_ERR("index out of bound!");
#endif
    sli.set(v.ptr() + start, N);
}

inline void slice(DvecDoub &sli, DvecDoub_IO v,
    Long_I start, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (start < 0 || start + N > v.size())
        SLS_ERR("index out of bound!");
#endif
    sli.set(v.ptr() + start, N, v.step());
}

inline void slice(DvecComp &sli, DvecComp_IO v,
    Long_I start, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (start < 0 || start + N > v.size())
        SLS_ERR("index out of bound!");
#endif
    sli.set(v.ptr() + start, N, v.step());
}

inline void slice(DcmatDoub &sli, CmatDoub_IO v,
    Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() ||
			start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    sli.set(&v(start1, start2), N1, N2, v.n1());
}
inline void slice(ScmatDoub &sli, CmatDoub_IO v, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
	sli.set(v.ptr() + v.n1()*start2, v.n1(), N2);
}

inline void slice(DcmatComp &sli, CmatComp_IO v,
    Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() ||
			start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    sli.set(&v(start1, start2), N1, N2, v.n1());
}
inline void slice(ScmatComp &sli, CmatComp_IO v, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
	sli.set(v.ptr() + v.n1()*start2, v.n1(), N2);
}

inline void slice(DcmatDoub &sli, ScmatDoub_IO v,
    Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() ||
			start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    sli.set(&v(start1, start2), N1, N2, v.n1());
}

inline void slice(DcmatComp &sli, ScmatComp_IO v,
    Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() ||
			start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    sli.set(&v(start1, start2), N1, N2, v.n1());
}


inline void slice1(SvecInt_c &sli, CmatInt_I v, Long_I j)
{
	sli.set(v.ptr() + v.n1() * j, v.n1());
}

inline void slice1(SvecInt &sli, CmatInt &v, Long_I j)
{
	sli.set(v.ptr() + v.n1() * j, v.n1());
}

inline void slice1(SvecDoub_c &sli, CmatDoub_I v, Long_I j)
{
	sli.set(v.ptr() + v.n1() * j, v.n1());
}

inline void slice1(SvecDoub &sli, CmatDoub &v, Long_I j)
{
	sli.set(v.ptr() + v.n1() * j, v.n1());
}

inline void slice1(SvecComp_c &sli, CmatComp_I v, Long_I j)
{
	sli.set(v.ptr() + v.n1() * j, v.n1());
}

inline void slice1(SvecComp &sli, CmatComp &v, Long_I j)
{
	sli.set(v.ptr() + v.n1() * j, v.n1());
}

inline void slice1(SvecDoub_c &sli, ScmatDoub_I v, Long_I j)
{
	sli.set(v.ptr() + v.n1() * j, v.n1());
}

inline void slice1(SvecDoub &sli, ScmatDoub &v, Long_I j)
{
	sli.set(v.ptr() + v.n1() * j, v.n1());
}

inline void slice1(SvecComp_c &sli, ScmatComp_I v, Long_I j)
{
	sli.set(v.ptr() + v.n1() * j, v.n1());
}

inline void slice1(SvecComp &sli, ScmatComp &v, Long_I j)
{
	sli.set(v.ptr() + v.n1() * j, v.n1());
}

inline void slice1(DvecInt_c &sli, MatInt_I v, Long_I j)
{
	sli.set(v.ptr() + j, v.n1(), v.n2());
}

inline void slice1(DvecInt &sli, MatInt &v, Long_I j)
{
	sli.set(v.ptr() + j, v.n1(), v.n2());
}


inline void slice2(DvecInt_c &sli, CmatInt_I v, Long_I i)
{
	sli.set(v.ptr() + i, v.n2(), v.n1());
}

inline void slice2(DvecInt &sli, CmatInt &v, Long_I i)
{
	sli.set(v.ptr() + i, v.n2(), v.n1());
}

inline void slice2(DvecLlong_c &sli, CmatLlong_I v, Long_I i)
{
	sli.set(v.ptr() + i, v.n2(), v.n1());
}

inline void slice2(DvecLlong &sli, CmatLlong &v, Long_I i)
{
	sli.set(v.ptr() + i, v.n2(), v.n1());
}

inline void slice2(DvecDoub_c &sli, CmatDoub_I v, Long_I i)
{
	sli.set(v.ptr() + i, v.n2(), v.n1());
}

inline void slice2(DvecDoub &sli, CmatDoub &v, Long_I i)
{
	sli.set(v.ptr() + i, v.n2(), v.n1());
}

inline void slice2(DvecComp_c &sli, CmatComp_I v, Long_I i)
{
	sli.set(v.ptr() + i, v.n2(), v.n1());
}

inline void slice2(DvecComp &sli, CmatComp &v, Long_I i)
{
	sli.set(v.ptr() + i, v.n2(), v.n1());
}

inline void slice2(DvecDoub_c &sli, ScmatDoub_I v, Long_I i)
{
	sli.set(v.ptr() + i, v.n2(), v.n1());
}

inline void slice2(DvecDoub &sli, ScmatDoub &v, Long_I i)
{
	sli.set(v.ptr() + i, v.n2(), v.n1());
}

inline void slice2(DvecComp_c &sli, ScmatComp_I v, Long_I i)
{
	sli.set(v.ptr() + i, v.n2(), v.n1());
}

inline void slice2(DvecComp &sli, ScmatComp &v, Long_I i)
{
	sli.set(v.ptr() + i, v.n2(), v.n1());
}

inline void slice2(SvecInt_c &sli, MatInt_I v, Long_I i)
{
	sli.set(v.ptr() + i*v.n2(), v.n2());
}

inline void slice2(SvecInt &sli, MatInt &v, Long_I i)
{
	sli.set(v.ptr() + i*v.n2(), v.n2());
}

} // namespace slisc
