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
inline SvecDoub slice(VecDoub_IO v, Long_I start, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (start < 0 || start + N > v.size())
        SLS_ERR("index out of bound!");
#endif
    SvecDoub sli(v.ptr() + start, N);
	return sli;
}

inline SvecDoub_c slice(VecDoub_I v, Long_I start, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (start < 0 || start + N > v.size())
        SLS_ERR("index out of bound!");
#endif
    SvecDoub_c sli(v.ptr() + start, N);
	return sli;
}

inline SvecComp slice(VecComp_IO v, Long_I start, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (start < 0 || start + N > v.size())
        SLS_ERR("index out of bound!");
#endif
    SvecComp sli(v.ptr() + start, N);
	return sli;
}

inline SvecComp_c slice(VecComp_I v, Long_I start, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (start < 0 || start + N > v.size())
        SLS_ERR("index out of bound!");
#endif
    SvecComp_c sli(v.ptr() + start, N);
	return sli;
}

inline SvecDoub slice(SvecDoub_IO v, Long_I start, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (start < 0 || start + N > v.size())
        SLS_ERR("index out of bound!");
#endif
    SvecDoub sli(v.ptr() + start, N);
	return sli;
}

inline SvecDoub_c slice(SvecDoub_I v, Long_I start, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (start < 0 || start + N > v.size())
        SLS_ERR("index out of bound!");
#endif
    SvecDoub_c sli(v.ptr() + start, N);
	return sli;
}

inline SvecComp slice(SvecComp_IO v, Long_I start, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (start < 0 || start + N > v.size())
        SLS_ERR("index out of bound!");
#endif
    SvecComp sli(v.ptr() + start, N);
	return sli;
}

inline SvecComp_c slice(SvecComp_I v, Long_I start, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (start < 0 || start + N > v.size())
        SLS_ERR("index out of bound!");
#endif
    SvecComp_c sli(v.ptr() + start, N);
	return sli;
}

inline DvecDoub slice(DvecDoub_IO v, Long_I start, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (start < 0 || start + N > v.size())
        SLS_ERR("index out of bound!");
#endif
    DvecDoub sli(v.ptr() + start, N, v.step());
	return sli;
}

inline DvecDoub_c slice(DvecDoub_I v, Long_I start, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (start < 0 || start + N > v.size())
        SLS_ERR("index out of bound!");
#endif
    DvecDoub_c sli(v.ptr() + start, N, v.step());
	return sli;
}

inline DvecComp slice(DvecComp_IO v, Long_I start, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (start < 0 || start + N > v.size())
        SLS_ERR("index out of bound!");
#endif
    DvecComp sli(v.ptr() + start, N, v.step());
	return sli;
}

inline DvecComp_c slice(DvecComp_I v, Long_I start, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (start < 0 || start + N > v.size())
        SLS_ERR("index out of bound!");
#endif
    DvecComp_c sli(v.ptr() + start, N, v.step());
	return sli;
}

inline DcmatLlong slice(CmatLlong_IO v,
	Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() ||
			start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    DcmatLlong sli(&v(start1, start2), N1, N2, v.n1());
	return sli;
}

inline DcmatLlong_c slice(CmatLlong_I v,
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
inline ScmatLlong slice(CmatLlong_IO v, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
	ScmatLlong sli(v.ptr() + v.n1()*start2, v.n1(), N2);
	return sli;
}

inline ScmatLlong_c slice(CmatLlong_I v, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
	ScmatLlong_c sli(v.ptr() + v.n1()*start2, v.n1(), N2);
	return sli;
}

inline DcmatDoub slice(CmatDoub_IO v,
	Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() ||
			start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    DcmatDoub sli(&v(start1, start2), N1, N2, v.n1());
	return sli;
}

inline DcmatDoub_c slice(CmatDoub_I v,
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
inline ScmatDoub slice(CmatDoub_IO v, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
	ScmatDoub sli(v.ptr() + v.n1()*start2, v.n1(), N2);
	return sli;
}

inline ScmatDoub_c slice(CmatDoub_I v, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
	ScmatDoub_c sli(v.ptr() + v.n1()*start2, v.n1(), N2);
	return sli;
}

inline DcmatComp slice(CmatComp_IO v,
	Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() ||
			start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    DcmatComp sli(&v(start1, start2), N1, N2, v.n1());
	return sli;
}

inline DcmatComp_c slice(CmatComp_I v,
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
inline ScmatComp slice(CmatComp_IO v, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
	ScmatComp sli(v.ptr() + v.n1()*start2, v.n1(), N2);
	return sli;
}

inline ScmatComp_c slice(CmatComp_I v, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
	ScmatComp_c sli(v.ptr() + v.n1()*start2, v.n1(), N2);
	return sli;
}

inline DcmatDoub slice(ScmatDoub_IO v,
	Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() ||
			start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    DcmatDoub sli(&v(start1, start2), N1, N2, v.n1());
	return sli;
}

inline DcmatDoub_c slice(ScmatDoub_I v,
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

inline DcmatComp slice(ScmatComp_IO v,
	Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() ||
			start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    DcmatComp sli(&v(start1, start2), N1, N2, v.n1());
	return sli;
}

inline DcmatComp_c slice(ScmatComp_I v,
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

inline DcmatInt slice(DcmatInt_IO v,
	Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() ||
			start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    DcmatInt sli(&v(start1, start2), N1, N2, v.lda());
	return sli;
}

inline DcmatInt_c slice(DcmatInt_I v,
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

inline DcmatInt slice(CmatInt_IO v,
	Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() ||
			start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
    DcmatInt sli(&v(start1, start2), N1, N2, v.n1());
	return sli;
}

inline DcmatInt_c slice(CmatInt_I v,
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
inline ScmatInt slice(CmatInt_IO v, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
	ScmatInt sli(v.ptr() + v.n1()*start2, v.n1(), N2);
	return sli;
}

inline ScmatInt_c slice(CmatInt_I v, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (start2 < 0 || start2 + N2 > v.n2())
        SLS_ERR("index out of bound!");
#endif
	ScmatInt_c sli(v.ptr() + v.n1()*start2, v.n1(), N2);
	return sli;
}

inline Jcmat3Int slice(Cmat3Int_IO v, Long_I start1, Long_I N1, Long_I start2, Long_I N2, Long_I start3, Long_I N3)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() || start2 < 0 || start2 + N2 > v.n2() || start3 < 0 || start3 + N3 > v.n3())
        SLS_ERR("index out of bound!");
#endif
	Jcmat3Int sli(&v(start1, start2, start3), N1, N2, N3, 1, v.n1(), v.n1()*v.n2());
	return sli;
}

inline Jcmat3Int_c slice(Cmat3Int_I v, Long_I start1, Long_I N1, Long_I start2, Long_I N2, Long_I start3, Long_I N3)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() || start2 < 0 || start2 + N2 > v.n2() || start3 < 0 || start3 + N3 > v.n3())
        SLS_ERR("index out of bound!");
#endif
	Jcmat3Int_c sli(&v(start1, start2, start3), N1, N2, N3, 1, v.n1(), v.n1()*v.n2());
	return sli;
}

inline Jcmat3Doub slice(Cmat3Doub_IO v, Long_I start1, Long_I N1, Long_I start2, Long_I N2, Long_I start3, Long_I N3)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() || start2 < 0 || start2 + N2 > v.n2() || start3 < 0 || start3 + N3 > v.n3())
        SLS_ERR("index out of bound!");
#endif
	Jcmat3Doub sli(&v(start1, start2, start3), N1, N2, N3, 1, v.n1(), v.n1()*v.n2());
	return sli;
}

inline Jcmat3Doub_c slice(Cmat3Doub_I v, Long_I start1, Long_I N1, Long_I start2, Long_I N2, Long_I start3, Long_I N3)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() || start2 < 0 || start2 + N2 > v.n2() || start3 < 0 || start3 + N3 > v.n3())
        SLS_ERR("index out of bound!");
#endif
	Jcmat3Doub_c sli(&v(start1, start2, start3), N1, N2, N3, 1, v.n1(), v.n1()*v.n2());
	return sli;
}

inline Jcmat3Comp slice(Cmat3Comp_IO v, Long_I start1, Long_I N1, Long_I start2, Long_I N2, Long_I start3, Long_I N3)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() || start2 < 0 || start2 + N2 > v.n2() || start3 < 0 || start3 + N3 > v.n3())
        SLS_ERR("index out of bound!");
#endif
	Jcmat3Comp sli(&v(start1, start2, start3), N1, N2, N3, 1, v.n1(), v.n1()*v.n2());
	return sli;
}

inline Jcmat3Comp_c slice(Cmat3Comp_I v, Long_I start1, Long_I N1, Long_I start2, Long_I N2, Long_I start3, Long_I N3)
{
#ifdef SLS_CHECK_BOUNDS
    if (start1 < 0 || start1 + N1 > v.n1() || start2 < 0 || start2 + N2 > v.n2() || start3 < 0 || start3 + N3 > v.n3())
        SLS_ERR("index out of bound!");
#endif
	Jcmat3Comp_c sli(&v(start1, start2, start3), N1, N2, N3, 1, v.n1(), v.n1()*v.n2());
	return sli;
}


inline DvecInt slice1(MatInt_IO v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j >= v.n2())
        SLS_ERR("index out of bound!");
#endif
	DvecInt sli(v.ptr() + j, v.n1(), v.n2());
	return sli;
}

inline DvecInt_c slice1(MatInt_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j >= v.n2())
        SLS_ERR("index out of bound!");
#endif
	DvecInt_c sli(v.ptr() + j, v.n1(), v.n2());
	return sli;
}

inline DvecDoub slice1(MatDoub_IO v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j >= v.n2())
        SLS_ERR("index out of bound!");
#endif
	DvecDoub sli(v.ptr() + j, v.n1(), v.n2());
	return sli;
}

inline DvecDoub_c slice1(MatDoub_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j >= v.n2())
        SLS_ERR("index out of bound!");
#endif
	DvecDoub_c sli(v.ptr() + j, v.n1(), v.n2());
	return sli;
}

inline DvecComp slice1(MatComp_IO v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j >= v.n2())
        SLS_ERR("index out of bound!");
#endif
	DvecComp sli(v.ptr() + j, v.n1(), v.n2());
	return sli;
}

inline DvecComp_c slice1(MatComp_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j >= v.n2())
        SLS_ERR("index out of bound!");
#endif
	DvecComp_c sli(v.ptr() + j, v.n1(), v.n2());
	return sli;
}

inline SvecInt slice1(CmatInt_IO v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j >= v.n2())
        SLS_ERR("index out of bound!");
#endif
	SvecInt sli(v.ptr() + v.n1() * j, v.n1());
	return sli;
}

inline SvecInt_c slice1(CmatInt_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j >= v.n2())
        SLS_ERR("index out of bound!");
#endif
	SvecInt_c sli(v.ptr() + v.n1() * j, v.n1());
	return sli;
}

inline SvecLlong slice1(CmatLlong_IO v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j >= v.n2())
        SLS_ERR("index out of bound!");
#endif
	SvecLlong sli(v.ptr() + v.n1() * j, v.n1());
	return sli;
}

inline SvecLlong_c slice1(CmatLlong_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j >= v.n2())
        SLS_ERR("index out of bound!");
#endif
	SvecLlong_c sli(v.ptr() + v.n1() * j, v.n1());
	return sli;
}

inline SvecDoub slice1(CmatDoub_IO v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j >= v.n2())
        SLS_ERR("index out of bound!");
#endif
	SvecDoub sli(v.ptr() + v.n1() * j, v.n1());
	return sli;
}

inline SvecDoub_c slice1(CmatDoub_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j >= v.n2())
        SLS_ERR("index out of bound!");
#endif
	SvecDoub_c sli(v.ptr() + v.n1() * j, v.n1());
	return sli;
}

inline SvecComp slice1(CmatComp_IO v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j >= v.n2())
        SLS_ERR("index out of bound!");
#endif
	SvecComp sli(v.ptr() + v.n1() * j, v.n1());
	return sli;
}

inline SvecComp_c slice1(CmatComp_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j >= v.n2())
        SLS_ERR("index out of bound!");
#endif
	SvecComp_c sli(v.ptr() + v.n1() * j, v.n1());
	return sli;
}

inline SvecInt slice1(Cmat3Int_IO v, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j >= v.n2() || k < 0 || k >= v.n3())
        SLS_ERR("index out of bound!");
#endif
	SvecInt sli(v.ptr() + v.n1()*j + v.n1()*v.n2()*k, v.n1());
	return sli;
}

inline SvecInt_c slice1(Cmat3Int_I v, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j >= v.n2() || k < 0 || k >= v.n3())
        SLS_ERR("index out of bound!");
#endif
	SvecInt_c sli(v.ptr() + v.n1()*j + v.n1()*v.n2()*k, v.n1());
	return sli;
}

inline SvecDoub slice1(Cmat3Doub_IO v, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j >= v.n2() || k < 0 || k >= v.n3())
        SLS_ERR("index out of bound!");
#endif
	SvecDoub sli(v.ptr() + v.n1()*j + v.n1()*v.n2()*k, v.n1());
	return sli;
}

inline SvecDoub_c slice1(Cmat3Doub_I v, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j >= v.n2() || k < 0 || k >= v.n3())
        SLS_ERR("index out of bound!");
#endif
	SvecDoub_c sli(v.ptr() + v.n1()*j + v.n1()*v.n2()*k, v.n1());
	return sli;
}

inline SvecComp slice1(Cmat3Comp_IO v, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j >= v.n2() || k < 0 || k >= v.n3())
        SLS_ERR("index out of bound!");
#endif
	SvecComp sli(v.ptr() + v.n1()*j + v.n1()*v.n2()*k, v.n1());
	return sli;
}

inline SvecComp_c slice1(Cmat3Comp_I v, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j >= v.n2() || k < 0 || k >= v.n3())
        SLS_ERR("index out of bound!");
#endif
	SvecComp_c sli(v.ptr() + v.n1()*j + v.n1()*v.n2()*k, v.n1());
	return sli;
}

inline SvecDoub slice1(ScmatDoub_IO v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j >= v.n2())
        SLS_ERR("index out of bound!");
#endif
	SvecDoub sli(v.ptr() + v.n1() * j, v.n1());
	return sli;
}

inline SvecDoub_c slice1(ScmatDoub_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j >= v.n2())
        SLS_ERR("index out of bound!");
#endif
	SvecDoub_c sli(v.ptr() + v.n1() * j, v.n1());
	return sli;
}

inline SvecComp slice1(ScmatComp_IO v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j >= v.n2())
        SLS_ERR("index out of bound!");
#endif
	SvecComp sli(v.ptr() + v.n1() * j, v.n1());
	return sli;
}

inline SvecComp_c slice1(ScmatComp_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j >= v.n2())
        SLS_ERR("index out of bound!");
#endif
	SvecComp_c sli(v.ptr() + v.n1() * j, v.n1());
	return sli;
}


inline SvecInt slice1(CmatInt_IO v, Long_I i, Long_I N1, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i + N1 > v.n1() || j < 0 || j >= v.n2())
        SLS_ERR("index out of bound!");
#endif
	SvecInt sli(&v(i, j), N1);
	return sli;
}

inline SvecInt_c slice1(CmatInt_I v, Long_I i, Long_I N1, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i + N1 > v.n1() || j < 0 || j >= v.n2())
        SLS_ERR("index out of bound!");
#endif
	SvecInt_c sli(&v(i, j), N1);
	return sli;
}

inline SvecLlong slice1(CmatLlong_IO v, Long_I i, Long_I N1, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i + N1 > v.n1() || j < 0 || j >= v.n2())
        SLS_ERR("index out of bound!");
#endif
	SvecLlong sli(&v(i, j), N1);
	return sli;
}

inline SvecLlong_c slice1(CmatLlong_I v, Long_I i, Long_I N1, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i + N1 > v.n1() || j < 0 || j >= v.n2())
        SLS_ERR("index out of bound!");
#endif
	SvecLlong_c sli(&v(i, j), N1);
	return sli;
}

inline SvecDoub slice1(CmatDoub_IO v, Long_I i, Long_I N1, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i + N1 > v.n1() || j < 0 || j >= v.n2())
        SLS_ERR("index out of bound!");
#endif
	SvecDoub sli(&v(i, j), N1);
	return sli;
}

inline SvecDoub_c slice1(CmatDoub_I v, Long_I i, Long_I N1, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i + N1 > v.n1() || j < 0 || j >= v.n2())
        SLS_ERR("index out of bound!");
#endif
	SvecDoub_c sli(&v(i, j), N1);
	return sli;
}

inline SvecComp slice1(CmatComp_IO v, Long_I i, Long_I N1, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i + N1 > v.n1() || j < 0 || j >= v.n2())
        SLS_ERR("index out of bound!");
#endif
	SvecComp sli(&v(i, j), N1);
	return sli;
}

inline SvecComp_c slice1(CmatComp_I v, Long_I i, Long_I N1, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i + N1 > v.n1() || j < 0 || j >= v.n2())
        SLS_ERR("index out of bound!");
#endif
	SvecComp_c sli(&v(i, j), N1);
	return sli;
}

inline SvecInt slice1(Cmat3Int_IO v, Long_I i, Long_I N1, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i + N1 > v.n1() || j < 0 || j >= v.n2() || k < 0 || k >= v.n3())
        SLS_ERR("index out of bound!");
#endif
	SvecInt sli(&v(i, j, k), N1);
	return sli;
}

inline SvecInt_c slice1(Cmat3Int_I v, Long_I i, Long_I N1, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i + N1 > v.n1() || j < 0 || j >= v.n2() || k < 0 || k >= v.n3())
        SLS_ERR("index out of bound!");
#endif
	SvecInt_c sli(&v(i, j, k), N1);
	return sli;
}

inline SvecLlong slice1(Cmat3Llong_IO v, Long_I i, Long_I N1, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i + N1 > v.n1() || j < 0 || j >= v.n2() || k < 0 || k >= v.n3())
        SLS_ERR("index out of bound!");
#endif
	SvecLlong sli(&v(i, j, k), N1);
	return sli;
}

inline SvecLlong_c slice1(Cmat3Llong_I v, Long_I i, Long_I N1, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i + N1 > v.n1() || j < 0 || j >= v.n2() || k < 0 || k >= v.n3())
        SLS_ERR("index out of bound!");
#endif
	SvecLlong_c sli(&v(i, j, k), N1);
	return sli;
}

inline SvecDoub slice1(Cmat3Doub_IO v, Long_I i, Long_I N1, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i + N1 > v.n1() || j < 0 || j >= v.n2() || k < 0 || k >= v.n3())
        SLS_ERR("index out of bound!");
#endif
	SvecDoub sli(&v(i, j, k), N1);
	return sli;
}

inline SvecDoub_c slice1(Cmat3Doub_I v, Long_I i, Long_I N1, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i + N1 > v.n1() || j < 0 || j >= v.n2() || k < 0 || k >= v.n3())
        SLS_ERR("index out of bound!");
#endif
	SvecDoub_c sli(&v(i, j, k), N1);
	return sli;
}

inline SvecComp slice1(Cmat3Comp_IO v, Long_I i, Long_I N1, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i + N1 > v.n1() || j < 0 || j >= v.n2() || k < 0 || k >= v.n3())
        SLS_ERR("index out of bound!");
#endif
	SvecComp sli(&v(i, j, k), N1);
	return sli;
}

inline SvecComp_c slice1(Cmat3Comp_I v, Long_I i, Long_I N1, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i + N1 > v.n1() || j < 0 || j >= v.n2() || k < 0 || k >= v.n3())
        SLS_ERR("index out of bound!");
#endif
	SvecComp_c sli(&v(i, j, k), N1);
	return sli;
}


inline DvecInt slice2(CmatInt_IO v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1())
        SLS_ERR("index out of bound!");
#endif
	DvecInt sli(v.ptr() + i, v.n2(), v.n1());
	return sli;
}

inline DvecInt_c slice2(CmatInt_I v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1())
        SLS_ERR("index out of bound!");
#endif
	DvecInt_c sli(v.ptr() + i, v.n2(), v.n1());
	return sli;
}

inline DvecLlong slice2(CmatLlong_IO v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1())
        SLS_ERR("index out of bound!");
#endif
	DvecLlong sli(v.ptr() + i, v.n2(), v.n1());
	return sli;
}

inline DvecLlong_c slice2(CmatLlong_I v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1())
        SLS_ERR("index out of bound!");
#endif
	DvecLlong_c sli(v.ptr() + i, v.n2(), v.n1());
	return sli;
}

inline DvecDoub slice2(CmatDoub_IO v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1())
        SLS_ERR("index out of bound!");
#endif
	DvecDoub sli(v.ptr() + i, v.n2(), v.n1());
	return sli;
}

inline DvecDoub_c slice2(CmatDoub_I v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1())
        SLS_ERR("index out of bound!");
#endif
	DvecDoub_c sli(v.ptr() + i, v.n2(), v.n1());
	return sli;
}

inline DvecComp slice2(CmatComp_IO v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1())
        SLS_ERR("index out of bound!");
#endif
	DvecComp sli(v.ptr() + i, v.n2(), v.n1());
	return sli;
}

inline DvecComp_c slice2(CmatComp_I v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1())
        SLS_ERR("index out of bound!");
#endif
	DvecComp_c sli(v.ptr() + i, v.n2(), v.n1());
	return sli;
}

inline DvecLlong slice2(ScmatLlong_IO v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1())
        SLS_ERR("index out of bound!");
#endif
	DvecLlong sli(v.ptr() + i, v.n2(), v.n1());
	return sli;
}

inline DvecLlong_c slice2(ScmatLlong_I v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1())
        SLS_ERR("index out of bound!");
#endif
	DvecLlong_c sli(v.ptr() + i, v.n2(), v.n1());
	return sli;
}

inline DvecDoub slice2(ScmatDoub_IO v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1())
        SLS_ERR("index out of bound!");
#endif
	DvecDoub sli(v.ptr() + i, v.n2(), v.n1());
	return sli;
}

inline DvecDoub_c slice2(ScmatDoub_I v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1())
        SLS_ERR("index out of bound!");
#endif
	DvecDoub_c sli(v.ptr() + i, v.n2(), v.n1());
	return sli;
}

inline DvecComp slice2(ScmatComp_IO v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1())
        SLS_ERR("index out of bound!");
#endif
	DvecComp sli(v.ptr() + i, v.n2(), v.n1());
	return sli;
}

inline DvecComp_c slice2(ScmatComp_I v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1())
        SLS_ERR("index out of bound!");
#endif
	DvecComp_c sli(v.ptr() + i, v.n2(), v.n1());
	return sli;
}

inline SvecInt slice2(MatInt_IO v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1())
        SLS_ERR("index out of bound!");
#endif
	SvecInt sli(v.ptr() + i*v.n2(), v.n2());
	return sli;
}

inline SvecInt_c slice2(MatInt_I v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1())
        SLS_ERR("index out of bound!");
#endif
	SvecInt_c sli(v.ptr() + i*v.n2(), v.n2());
	return sli;
}

inline SvecDoub slice2(MatDoub_IO v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1())
        SLS_ERR("index out of bound!");
#endif
	SvecDoub sli(v.ptr() + i*v.n2(), v.n2());
	return sli;
}

inline SvecDoub_c slice2(MatDoub_I v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1())
        SLS_ERR("index out of bound!");
#endif
	SvecDoub_c sli(v.ptr() + i*v.n2(), v.n2());
	return sli;
}

inline SvecComp slice2(MatComp_IO v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1())
        SLS_ERR("index out of bound!");
#endif
	SvecComp sli(v.ptr() + i*v.n2(), v.n2());
	return sli;
}

inline SvecComp_c slice2(MatComp_I v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1())
        SLS_ERR("index out of bound!");
#endif
	SvecComp_c sli(v.ptr() + i*v.n2(), v.n2());
	return sli;
}

inline DvecComp slice2(Cmat3Comp_IO v, Long_I i, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1() || k < 0 || k >= v.n3())
        SLS_ERR("index out of bound!");
#endif
	DvecComp sli(v.ptr() + i + v.n1()*v.n2()*k, v.n2(), v.n1());
	return sli;
}

inline DvecComp_c slice2(Cmat3Comp_I v, Long_I i, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1() || k < 0 || k >= v.n3())
        SLS_ERR("index out of bound!");
#endif
	DvecComp_c sli(v.ptr() + i + v.n1()*v.n2()*k, v.n2(), v.n1());
	return sli;
}


inline DvecInt slice2(CmatInt_IO v, Long_I i, Long_I j, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1() || j < 0 || j + N2 > v.n2())
        SLS_ERR("out of bound!");
#endif
    DvecInt sli(&v(i, j), N2, v.n1());
	return sli;
}

inline DvecInt_c slice2(CmatInt_I v, Long_I i, Long_I j, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1() || j < 0 || j + N2 > v.n2())
        SLS_ERR("out of bound!");
#endif
    DvecInt_c sli(&v(i, j), N2, v.n1());
	return sli;
}

inline DvecLlong slice2(CmatLlong_IO v, Long_I i, Long_I j, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1() || j < 0 || j + N2 > v.n2())
        SLS_ERR("out of bound!");
#endif
    DvecLlong sli(&v(i, j), N2, v.n1());
	return sli;
}

inline DvecLlong_c slice2(CmatLlong_I v, Long_I i, Long_I j, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1() || j < 0 || j + N2 > v.n2())
        SLS_ERR("out of bound!");
#endif
    DvecLlong_c sli(&v(i, j), N2, v.n1());
	return sli;
}

inline DvecDoub slice2(CmatDoub_IO v, Long_I i, Long_I j, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1() || j < 0 || j + N2 > v.n2())
        SLS_ERR("out of bound!");
#endif
    DvecDoub sli(&v(i, j), N2, v.n1());
	return sli;
}

inline DvecDoub_c slice2(CmatDoub_I v, Long_I i, Long_I j, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1() || j < 0 || j + N2 > v.n2())
        SLS_ERR("out of bound!");
#endif
    DvecDoub_c sli(&v(i, j), N2, v.n1());
	return sli;
}

inline DvecComp slice2(CmatComp_IO v, Long_I i, Long_I j, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1() || j < 0 || j + N2 > v.n2())
        SLS_ERR("out of bound!");
#endif
    DvecComp sli(&v(i, j), N2, v.n1());
	return sli;
}

inline DvecComp_c slice2(CmatComp_I v, Long_I i, Long_I j, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1() || j < 0 || j + N2 > v.n2())
        SLS_ERR("out of bound!");
#endif
    DvecComp_c sli(&v(i, j), N2, v.n1());
	return sli;
}

inline DvecInt slice2(Cmat3Int_IO v, Long_I i, Long_I j, Long_I N2, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1() || j < 0 || j + N2 > v.n2() || k < 0 || k >= v.n3())
        SLS_ERR("out of bound!");
#endif
    DvecInt sli(&v(i, j, k), N2, v.n1());
	return sli;
}

inline DvecInt_c slice2(Cmat3Int_I v, Long_I i, Long_I j, Long_I N2, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1() || j < 0 || j + N2 > v.n2() || k < 0 || k >= v.n3())
        SLS_ERR("out of bound!");
#endif
    DvecInt_c sli(&v(i, j, k), N2, v.n1());
	return sli;
}

inline DvecLlong slice2(Cmat3Llong_IO v, Long_I i, Long_I j, Long_I N2, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1() || j < 0 || j + N2 > v.n2() || k < 0 || k >= v.n3())
        SLS_ERR("out of bound!");
#endif
    DvecLlong sli(&v(i, j, k), N2, v.n1());
	return sli;
}

inline DvecLlong_c slice2(Cmat3Llong_I v, Long_I i, Long_I j, Long_I N2, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1() || j < 0 || j + N2 > v.n2() || k < 0 || k >= v.n3())
        SLS_ERR("out of bound!");
#endif
    DvecLlong_c sli(&v(i, j, k), N2, v.n1());
	return sli;
}

inline DvecDoub slice2(Cmat3Doub_IO v, Long_I i, Long_I j, Long_I N2, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1() || j < 0 || j + N2 > v.n2() || k < 0 || k >= v.n3())
        SLS_ERR("out of bound!");
#endif
    DvecDoub sli(&v(i, j, k), N2, v.n1());
	return sli;
}

inline DvecDoub_c slice2(Cmat3Doub_I v, Long_I i, Long_I j, Long_I N2, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1() || j < 0 || j + N2 > v.n2() || k < 0 || k >= v.n3())
        SLS_ERR("out of bound!");
#endif
    DvecDoub_c sli(&v(i, j, k), N2, v.n1());
	return sli;
}

inline DvecComp slice2(Cmat3Comp_IO v, Long_I i, Long_I j, Long_I N2, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1() || j < 0 || j + N2 > v.n2() || k < 0 || k >= v.n3())
        SLS_ERR("out of bound!");
#endif
    DvecComp sli(&v(i, j, k), N2, v.n1());
	return sli;
}

inline DvecComp_c slice2(Cmat3Comp_I v, Long_I i, Long_I j, Long_I N2, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1() || j < 0 || j + N2 > v.n2() || k < 0 || k >= v.n3())
        SLS_ERR("out of bound!");
#endif
    DvecComp_c sli(&v(i, j, k), N2, v.n1());
	return sli;
}


inline DvecDoub slice3(Cmat3Doub_IO v, Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1() || j < 0 || j >= v.n2())
        SLS_ERR("index out of bound!");
#endif
	DvecDoub sli(&v(i, j, 0), v.n3(), v.n1()*v.n2());
	return sli;
}

inline DvecDoub_c slice3(Cmat3Doub_I v, Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1() || j < 0 || j >= v.n2())
        SLS_ERR("index out of bound!");
#endif
	DvecDoub_c sli(&v(i, j, 0), v.n3(), v.n1()*v.n2());
	return sli;
}

inline DvecComp slice3(Cmat3Comp_IO v, Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1() || j < 0 || j >= v.n2())
        SLS_ERR("index out of bound!");
#endif
	DvecComp sli(&v(i, j, 0), v.n3(), v.n1()*v.n2());
	return sli;
}

inline DvecComp_c slice3(Cmat3Comp_I v, Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= v.n1() || j < 0 || j >= v.n2())
        SLS_ERR("index out of bound!");
#endif
	DvecComp_c sli(&v(i, j, 0), v.n3(), v.n1()*v.n2());
	return sli;
}


inline ScmatInt slice12(Cmat3Int_IO v, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (k < 0 || k >= v.n3())
        SLS_ERR("index out of bound!");
#endif
	ScmatInt sli(v.ptr() + v.n1()*v.n2()*k, v.n1(), v.n2());
	return sli;
}

inline ScmatInt_c slice12(Cmat3Int_I v, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (k < 0 || k >= v.n3())
        SLS_ERR("index out of bound!");
#endif
	ScmatInt_c sli(v.ptr() + v.n1()*v.n2()*k, v.n1(), v.n2());
	return sli;
}

inline ScmatDoub slice12(Cmat3Doub_IO v, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (k < 0 || k >= v.n3())
        SLS_ERR("index out of bound!");
#endif
	ScmatDoub sli(v.ptr() + v.n1()*v.n2()*k, v.n1(), v.n2());
	return sli;
}

inline ScmatDoub_c slice12(Cmat3Doub_I v, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (k < 0 || k >= v.n3())
        SLS_ERR("index out of bound!");
#endif
	ScmatDoub_c sli(v.ptr() + v.n1()*v.n2()*k, v.n1(), v.n2());
	return sli;
}

inline ScmatComp slice12(Cmat3Comp_IO v, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (k < 0 || k >= v.n3())
        SLS_ERR("index out of bound!");
#endif
	ScmatComp sli(v.ptr() + v.n1()*v.n2()*k, v.n1(), v.n2());
	return sli;
}

inline ScmatComp_c slice12(Cmat3Comp_I v, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (k < 0 || k >= v.n3())
        SLS_ERR("index out of bound!");
#endif
	ScmatComp_c sli(v.ptr() + v.n1()*v.n2()*k, v.n1(), v.n2());
	return sli;
}

inline ScmatInt slice12(Cmat4Int_IO v, Long_I k, Long_I l)
{
#ifdef SLS_CHECK_BOUNDS
    if (k < 0 || k >= v.n3() || l < 0 || l >= v.n4())
        SLS_ERR("index out of bound!");
#endif
	Long N1N2 = v.n1() * v.n2();
	ScmatInt sli(v.ptr() + N1N2*k + N1N2*v.n3()*l, v.n1(), v.n2());
	return sli;
}

inline ScmatInt_c slice12(Cmat4Int_I v, Long_I k, Long_I l)
{
#ifdef SLS_CHECK_BOUNDS
    if (k < 0 || k >= v.n3() || l < 0 || l >= v.n4())
        SLS_ERR("index out of bound!");
#endif
	Long N1N2 = v.n1() * v.n2();
	ScmatInt_c sli(v.ptr() + N1N2*k + N1N2*v.n3()*l, v.n1(), v.n2());
	return sli;
}

inline ScmatLlong slice12(Cmat4Llong_IO v, Long_I k, Long_I l)
{
#ifdef SLS_CHECK_BOUNDS
    if (k < 0 || k >= v.n3() || l < 0 || l >= v.n4())
        SLS_ERR("index out of bound!");
#endif
	Long N1N2 = v.n1() * v.n2();
	ScmatLlong sli(v.ptr() + N1N2*k + N1N2*v.n3()*l, v.n1(), v.n2());
	return sli;
}

inline ScmatLlong_c slice12(Cmat4Llong_I v, Long_I k, Long_I l)
{
#ifdef SLS_CHECK_BOUNDS
    if (k < 0 || k >= v.n3() || l < 0 || l >= v.n4())
        SLS_ERR("index out of bound!");
#endif
	Long N1N2 = v.n1() * v.n2();
	ScmatLlong_c sli(v.ptr() + N1N2*k + N1N2*v.n3()*l, v.n1(), v.n2());
	return sli;
}

inline ScmatDoub slice12(Cmat4Doub_IO v, Long_I k, Long_I l)
{
#ifdef SLS_CHECK_BOUNDS
    if (k < 0 || k >= v.n3() || l < 0 || l >= v.n4())
        SLS_ERR("index out of bound!");
#endif
	Long N1N2 = v.n1() * v.n2();
	ScmatDoub sli(v.ptr() + N1N2*k + N1N2*v.n3()*l, v.n1(), v.n2());
	return sli;
}

inline ScmatDoub_c slice12(Cmat4Doub_I v, Long_I k, Long_I l)
{
#ifdef SLS_CHECK_BOUNDS
    if (k < 0 || k >= v.n3() || l < 0 || l >= v.n4())
        SLS_ERR("index out of bound!");
#endif
	Long N1N2 = v.n1() * v.n2();
	ScmatDoub_c sli(v.ptr() + N1N2*k + N1N2*v.n3()*l, v.n1(), v.n2());
	return sli;
}

inline ScmatComp slice12(Cmat4Comp_IO v, Long_I k, Long_I l)
{
#ifdef SLS_CHECK_BOUNDS
    if (k < 0 || k >= v.n3() || l < 0 || l >= v.n4())
        SLS_ERR("index out of bound!");
#endif
	Long N1N2 = v.n1() * v.n2();
	ScmatComp sli(v.ptr() + N1N2*k + N1N2*v.n3()*l, v.n1(), v.n2());
	return sli;
}

inline ScmatComp_c slice12(Cmat4Comp_I v, Long_I k, Long_I l)
{
#ifdef SLS_CHECK_BOUNDS
    if (k < 0 || k >= v.n3() || l < 0 || l >= v.n4())
        SLS_ERR("index out of bound!");
#endif
	Long N1N2 = v.n1() * v.n2();
	ScmatComp_c sli(v.ptr() + N1N2*k + N1N2*v.n3()*l, v.n1(), v.n2());
	return sli;
}


inline ScmatInt slice12(Cmat3Int_IO v, Long_I j, Long_I N2, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j + N2 > v.n2() || k < 0 || k >= v.n3())
        SLS_ERR("index out of bound!");
#endif
    ScmatInt sli(&v(0, j, k), v.n1(), N2);
	return sli;
}

inline ScmatInt_c slice12(Cmat3Int_I v, Long_I j, Long_I N2, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j + N2 > v.n2() || k < 0 || k >= v.n3())
        SLS_ERR("index out of bound!");
#endif
    ScmatInt_c sli(&v(0, j, k), v.n1(), N2);
	return sli;
}

inline ScmatDoub slice12(Cmat3Doub_IO v, Long_I j, Long_I N2, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j + N2 > v.n2() || k < 0 || k >= v.n3())
        SLS_ERR("index out of bound!");
#endif
    ScmatDoub sli(&v(0, j, k), v.n1(), N2);
	return sli;
}

inline ScmatDoub_c slice12(Cmat3Doub_I v, Long_I j, Long_I N2, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j + N2 > v.n2() || k < 0 || k >= v.n3())
        SLS_ERR("index out of bound!");
#endif
    ScmatDoub_c sli(&v(0, j, k), v.n1(), N2);
	return sli;
}

inline ScmatComp slice12(Cmat3Comp_IO v, Long_I j, Long_I N2, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j + N2 > v.n2() || k < 0 || k >= v.n3())
        SLS_ERR("index out of bound!");
#endif
    ScmatComp sli(&v(0, j, k), v.n1(), N2);
	return sli;
}

inline ScmatComp_c slice12(Cmat3Comp_I v, Long_I j, Long_I N2, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
    if (j < 0 || j + N2 > v.n2() || k < 0 || k >= v.n3())
        SLS_ERR("index out of bound!");
#endif
    ScmatComp_c sli(&v(0, j, k), v.n1(), N2);
	return sli;
}


inline DcmatInt slice12(Cmat3Int_IO v, Long_I i, Long_I N1, Long_I j, Long_I N2, Long_I k)
{
    DcmatInt sli(&v(i, j, k), N1, N2, v.n1());
	return sli;
}

inline DcmatInt_c slice12(Cmat3Int_I v, Long_I i, Long_I N1, Long_I j, Long_I N2, Long_I k)
{
    DcmatInt_c sli(&v(i, j, k), N1, N2, v.n1());
	return sli;
}

inline DcmatDoub slice12(Cmat3Doub_IO v, Long_I i, Long_I N1, Long_I j, Long_I N2, Long_I k)
{
    DcmatDoub sli(&v(i, j, k), N1, N2, v.n1());
	return sli;
}

inline DcmatDoub_c slice12(Cmat3Doub_I v, Long_I i, Long_I N1, Long_I j, Long_I N2, Long_I k)
{
    DcmatDoub_c sli(&v(i, j, k), N1, N2, v.n1());
	return sli;
}

inline DcmatComp slice12(Cmat3Comp_IO v, Long_I i, Long_I N1, Long_I j, Long_I N2, Long_I k)
{
    DcmatComp sli(&v(i, j, k), N1, N2, v.n1());
	return sli;
}

inline DcmatComp_c slice12(Cmat3Comp_I v, Long_I i, Long_I N1, Long_I j, Long_I N2, Long_I k)
{
    DcmatComp_c sli(&v(i, j, k), N1, N2, v.n1());
	return sli;
}

} // namespace slisc
