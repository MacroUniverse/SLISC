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
inline SvecInt cut(VecInt_IO v, Long_I start, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (start < 0 || start + N > v.size())
	    SLS_ERR("index out of bound!");
#endif
	SvecInt sli(&v[start], N);
	return sli;
}

inline SvecInt_c cut(VecInt_I v, Long_I start, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (start < 0 || start + N > v.size())
	    SLS_ERR("index out of bound!");
#endif
	SvecInt_c sli(&v[start], N);
	return sli;
}

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

inline SvecQdoub cut(VecQdoub_IO v, Long_I start, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (start < 0 || start + N > v.size())
	    SLS_ERR("index out of bound!");
#endif
	SvecQdoub sli(&v[start], N);
	return sli;
}

inline SvecQdoub_c cut(VecQdoub_I v, Long_I start, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (start < 0 || start + N > v.size())
	    SLS_ERR("index out of bound!");
#endif
	SvecQdoub_c sli(&v[start], N);
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

inline SvecQcomp cut(VecQcomp_IO v, Long_I start, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (start < 0 || start + N > v.size())
	    SLS_ERR("index out of bound!");
#endif
	SvecQcomp sli(&v[start], N);
	return sli;
}

inline SvecQcomp_c cut(VecQcomp_I v, Long_I start, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (start < 0 || start + N > v.size())
	    SLS_ERR("index out of bound!");
#endif
	SvecQcomp_c sli(&v[start], N);
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

inline DcmatQdoub cut(CmatQdoub_IO v, Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (start1 < 0 || start1 + N1 > v.n0() ||
	        start2 < 0 || start2 + N2 > v.n1())
	    SLS_ERR("index out of bound!");
#endif
	DcmatQdoub sli(&v(start1, start2), N1, N2, v.n0());
	return sli;
}

inline DcmatQdoub_c cut(CmatQdoub_I v,
	Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (start1 < 0 || start1 + N1 > v.n0() ||
	        start2 < 0 || start2 + N2 > v.n1())
	    SLS_ERR("index out of bound!");
#endif
	DcmatQdoub_c sli(&v(start1, start2), N1, N2, v.n0());
	return sli;
}
inline ScmatQdoub cut(CmatQdoub_IO v, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (start2 < 0 || start2 + N2 > v.n1())
	    SLS_ERR("index out of bound!");
#endif
	ScmatQdoub sli(&v(0, start2), v.n0(), N2);
	return sli;
}

inline ScmatQdoub_c cut(CmatQdoub_I v, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (start2 < 0 || start2 + N2 > v.n1())
	    SLS_ERR("index out of bound!");
#endif
	ScmatQdoub_c sli(&v(0, start2), v.n0(), N2);
	return sli;
}

inline DcmatComp cut(CmatComp_IO v, Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (start1 < 0 || start1 + N1 > v.n0() ||
	        start2 < 0 || start2 + N2 > v.n1())
	    SLS_ERR("index out of bound!");
#endif
	DcmatComp sli(&v(start1, start2), N1, N2, v.n0());
	return sli;
}

inline DcmatComp_c cut(CmatComp_I v,
	Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (start1 < 0 || start1 + N1 > v.n0() ||
	        start2 < 0 || start2 + N2 > v.n1())
	    SLS_ERR("index out of bound!");
#endif
	DcmatComp_c sli(&v(start1, start2), N1, N2, v.n0());
	return sli;
}
inline ScmatComp cut(CmatComp_IO v, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (start2 < 0 || start2 + N2 > v.n1())
	    SLS_ERR("index out of bound!");
#endif
	ScmatComp sli(&v(0, start2), v.n0(), N2);
	return sli;
}

inline ScmatComp_c cut(CmatComp_I v, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (start2 < 0 || start2 + N2 > v.n1())
	    SLS_ERR("index out of bound!");
#endif
	ScmatComp_c sli(&v(0, start2), v.n0(), N2);
	return sli;
}

inline DcmatQcomp cut(CmatQcomp_IO v, Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (start1 < 0 || start1 + N1 > v.n0() ||
	        start2 < 0 || start2 + N2 > v.n1())
	    SLS_ERR("index out of bound!");
#endif
	DcmatQcomp sli(&v(start1, start2), N1, N2, v.n0());
	return sli;
}

inline DcmatQcomp_c cut(CmatQcomp_I v,
	Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (start1 < 0 || start1 + N1 > v.n0() ||
	        start2 < 0 || start2 + N2 > v.n1())
	    SLS_ERR("index out of bound!");
#endif
	DcmatQcomp_c sli(&v(start1, start2), N1, N2, v.n0());
	return sli;
}
inline ScmatQcomp cut(CmatQcomp_IO v, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (start2 < 0 || start2 + N2 > v.n1())
	    SLS_ERR("index out of bound!");
#endif
	ScmatQcomp sli(&v(0, start2), v.n0(), N2);
	return sli;
}

inline ScmatQcomp_c cut(CmatQcomp_I v, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (start2 < 0 || start2 + N2 > v.n1())
	    SLS_ERR("index out of bound!");
#endif
	ScmatQcomp_c sli(&v(0, start2), v.n0(), N2);
	return sli;
}

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

inline DcmatQdoub cut(ScmatQdoub_IO v, Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (start1 < 0 || start1 + N1 > v.n0() ||
	        start2 < 0 || start2 + N2 > v.n1())
	    SLS_ERR("index out of bound!");
#endif
	DcmatQdoub sli(&v(start1, start2), N1, N2, v.n0());
	return sli;
}

inline DcmatQdoub_c cut(ScmatQdoub_I v,
	Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (start1 < 0 || start1 + N1 > v.n0() ||
	        start2 < 0 || start2 + N2 > v.n1())
	    SLS_ERR("index out of bound!");
#endif
	DcmatQdoub_c sli(&v(start1, start2), N1, N2, v.n0());
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

inline SvecQcomp cut(SvecQcomp_IO v, Long_I start, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (start < 0 || start + N > v.size())
	    SLS_ERR("index out of bound!");
#endif
	SvecQcomp sli(&v[start], N);
	return sli;
}

inline SvecQcomp_c cut(SvecQcomp_I v, Long_I start, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (start < 0 || start + N > v.size())
	    SLS_ERR("index out of bound!");
#endif
	SvecQcomp_c sli(&v[start], N);
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

inline DcmatInt cut(CmatInt_IO v, Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (start1 < 0 || start1 + N1 > v.n0() ||
	        start2 < 0 || start2 + N2 > v.n1())
	    SLS_ERR("index out of bound!");
#endif
	DcmatInt sli(&v(start1, start2), N1, N2, v.n0());
	return sli;
}

inline DcmatInt_c cut(CmatInt_I v,
	Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (start1 < 0 || start1 + N1 > v.n0() ||
	        start2 < 0 || start2 + N2 > v.n1())
	    SLS_ERR("index out of bound!");
#endif
	DcmatInt_c sli(&v(start1, start2), N1, N2, v.n0());
	return sli;
}
inline ScmatInt cut(CmatInt_IO v, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (start2 < 0 || start2 + N2 > v.n1())
	    SLS_ERR("index out of bound!");
#endif
	ScmatInt sli(&v(0, start2), v.n0(), N2);
	return sli;
}

inline ScmatInt_c cut(CmatInt_I v, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (start2 < 0 || start2 + N2 > v.n1())
	    SLS_ERR("index out of bound!");
#endif
	ScmatInt_c sli(&v(0, start2), v.n0(), N2);
	return sli;
}

inline DcmatLlong cut(CmatLlong_IO v, Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (start1 < 0 || start1 + N1 > v.n0() ||
	        start2 < 0 || start2 + N2 > v.n1())
	    SLS_ERR("index out of bound!");
#endif
	DcmatLlong sli(&v(start1, start2), N1, N2, v.n0());
	return sli;
}

inline DcmatLlong_c cut(CmatLlong_I v,
	Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (start1 < 0 || start1 + N1 > v.n0() ||
	        start2 < 0 || start2 + N2 > v.n1())
	    SLS_ERR("index out of bound!");
#endif
	DcmatLlong_c sli(&v(start1, start2), N1, N2, v.n0());
	return sli;
}
inline ScmatLlong cut(CmatLlong_IO v, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (start2 < 0 || start2 + N2 > v.n1())
	    SLS_ERR("index out of bound!");
#endif
	ScmatLlong sli(&v(0, start2), v.n0(), N2);
	return sli;
}

inline ScmatLlong_c cut(CmatLlong_I v, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (start2 < 0 || start2 + N2 > v.n1())
	    SLS_ERR("index out of bound!");
#endif
	ScmatLlong_c sli(&v(0, start2), v.n0(), N2);
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

inline Jcmat3Qdoub cut(Cmat3Qdoub_IO v, Long_I start1, Long_I N1, Long_I start2, Long_I N2, Long_I start3, Long_I N3)
{
#ifdef SLS_CHECK_BOUNDS
	if (start1 < 0 || start1 + N1 > v.n0() || start2 < 0 || start2 + N2 > v.n1() || start3 < 0 || start3 + N3 > v.n2())
	    SLS_ERR("index out of bound!");
#endif
	Jcmat3Qdoub sli(&v(start1, start2, start3), N1, N2, N3, 1, v.n0(), v.n0()*v.n1());
	return sli;
}

inline Jcmat3Qdoub_c cut(Cmat3Qdoub_I v, Long_I start1, Long_I N1, Long_I start2, Long_I N2, Long_I start3, Long_I N3)
{
#ifdef SLS_CHECK_BOUNDS
	if (start1 < 0 || start1 + N1 > v.n0() || start2 < 0 || start2 + N2 > v.n1() || start3 < 0 || start3 + N3 > v.n2())
	    SLS_ERR("index out of bound!");
#endif
	Jcmat3Qdoub_c sli(&v(start1, start2, start3), N1, N2, N3, 1, v.n0(), v.n0()*v.n1());
	return sli;
}

inline Jcmat3Comp cut(Cmat3Comp_IO v, Long_I start1, Long_I N1, Long_I start2, Long_I N2, Long_I start3, Long_I N3)
{
#ifdef SLS_CHECK_BOUNDS
	if (start1 < 0 || start1 + N1 > v.n0() || start2 < 0 || start2 + N2 > v.n1() || start3 < 0 || start3 + N3 > v.n2())
	    SLS_ERR("index out of bound!");
#endif
	Jcmat3Comp sli(&v(start1, start2, start3), N1, N2, N3, 1, v.n0(), v.n0()*v.n1());
	return sli;
}

inline Jcmat3Comp_c cut(Cmat3Comp_I v, Long_I start1, Long_I N1, Long_I start2, Long_I N2, Long_I start3, Long_I N3)
{
#ifdef SLS_CHECK_BOUNDS
	if (start1 < 0 || start1 + N1 > v.n0() || start2 < 0 || start2 + N2 > v.n1() || start3 < 0 || start3 + N3 > v.n2())
	    SLS_ERR("index out of bound!");
#endif
	Jcmat3Comp_c sli(&v(start1, start2, start3), N1, N2, N3, 1, v.n0(), v.n0()*v.n1());
	return sli;
}

inline Jcmat3Qcomp cut(Cmat3Qcomp_IO v, Long_I start1, Long_I N1, Long_I start2, Long_I N2, Long_I start3, Long_I N3)
{
#ifdef SLS_CHECK_BOUNDS
	if (start1 < 0 || start1 + N1 > v.n0() || start2 < 0 || start2 + N2 > v.n1() || start3 < 0 || start3 + N3 > v.n2())
	    SLS_ERR("index out of bound!");
#endif
	Jcmat3Qcomp sli(&v(start1, start2, start3), N1, N2, N3, 1, v.n0(), v.n0()*v.n1());
	return sli;
}

inline Jcmat3Qcomp_c cut(Cmat3Qcomp_I v, Long_I start1, Long_I N1, Long_I start2, Long_I N2, Long_I start3, Long_I N3)
{
#ifdef SLS_CHECK_BOUNDS
	if (start1 < 0 || start1 + N1 > v.n0() || start2 < 0 || start2 + N2 > v.n1() || start3 < 0 || start3 + N3 > v.n2())
	    SLS_ERR("index out of bound!");
#endif
	Jcmat3Qcomp_c sli(&v(start1, start2, start3), N1, N2, N3, 1, v.n0(), v.n0()*v.n1());
	return sli;
}


inline DvecInt cut0(MatInt_IO v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
	    SLS_ERR("index out of bound!");
#endif
	DvecInt sli(&v(0, j), v.n0(), v.n1());
	return sli;
}

inline DvecInt_c cut0(MatInt_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
	    SLS_ERR("index out of bound!");
#endif
	DvecInt_c sli(&v(0, j), v.n0(), v.n1());
	return sli;
}

inline SvecInt cut0(CmatInt_IO v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
	    SLS_ERR("index out of bound!");
#endif
	SvecInt sli(&v(0, j), v.n0());
	return sli;
}

inline SvecInt_c cut0(CmatInt_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
	    SLS_ERR("index out of bound!");
#endif
	SvecInt_c sli(&v(0, j), v.n0());
	return sli;
}

inline SvecLlong cut0(CmatLlong_IO v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
	    SLS_ERR("index out of bound!");
#endif
	SvecLlong sli(&v(0, j), v.n0());
	return sli;
}

inline SvecLlong_c cut0(CmatLlong_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
	    SLS_ERR("index out of bound!");
#endif
	SvecLlong_c sli(&v(0, j), v.n0());
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

inline SvecQdoub cut0(CmatQdoub_IO v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
	    SLS_ERR("index out of bound!");
#endif
	SvecQdoub sli(&v(0, j), v.n0());
	return sli;
}

inline SvecQdoub_c cut0(CmatQdoub_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
	    SLS_ERR("index out of bound!");
#endif
	SvecQdoub_c sli(&v(0, j), v.n0());
	return sli;
}

inline SvecQdoub cut0(Cmat3Qdoub_IO v, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1() || k < 0 || k >= v.n2())
	    SLS_ERR("index out of bound!");
#endif
	SvecQdoub sli(&v(0, j, k), v.n0());
	return sli;
}

inline SvecQdoub_c cut0(Cmat3Qdoub_I v, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1() || k < 0 || k >= v.n2())
	    SLS_ERR("index out of bound!");
#endif
	SvecQdoub_c sli(&v(0, j, k), v.n0());
	return sli;
}

inline SvecQcomp cut0(Cmat3Qcomp_IO v, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1() || k < 0 || k >= v.n2())
	    SLS_ERR("index out of bound!");
#endif
	SvecQcomp sli(&v(0, j, k), v.n0());
	return sli;
}

inline SvecQcomp_c cut0(Cmat3Qcomp_I v, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1() || k < 0 || k >= v.n2())
	    SLS_ERR("index out of bound!");
#endif
	SvecQcomp_c sli(&v(0, j, k), v.n0());
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

inline SvecQcomp cut0(CmatQcomp_IO v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
	    SLS_ERR("index out of bound!");
#endif
	SvecQcomp sli(&v(0, j), v.n0());
	return sli;
}

inline SvecQcomp_c cut0(CmatQcomp_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
	    SLS_ERR("index out of bound!");
#endif
	SvecQcomp_c sli(&v(0, j), v.n0());
	return sli;
}

inline SvecInt cut0(ScmatInt_IO v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
	    SLS_ERR("index out of bound!");
#endif
	SvecInt sli(&v(0, j), v.n0());
	return sli;
}

inline SvecInt_c cut0(ScmatInt_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
	    SLS_ERR("index out of bound!");
#endif
	SvecInt_c sli(&v(0, j), v.n0());
	return sli;
}

inline SvecLlong cut0(ScmatLlong_IO v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
	    SLS_ERR("index out of bound!");
#endif
	SvecLlong sli(&v(0, j), v.n0());
	return sli;
}

inline SvecLlong_c cut0(ScmatLlong_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
	    SLS_ERR("index out of bound!");
#endif
	SvecLlong_c sli(&v(0, j), v.n0());
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

inline SvecQdoub cut0(ScmatQdoub_IO v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
	    SLS_ERR("index out of bound!");
#endif
	SvecQdoub sli(&v(0, j), v.n0());
	return sli;
}

inline SvecQdoub_c cut0(ScmatQdoub_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
	    SLS_ERR("index out of bound!");
#endif
	SvecQdoub_c sli(&v(0, j), v.n0());
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

inline SvecQcomp cut0(ScmatQcomp_IO v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
	    SLS_ERR("index out of bound!");
#endif
	SvecQcomp sli(&v(0, j), v.n0());
	return sli;
}

inline SvecQcomp_c cut0(ScmatQcomp_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
	    SLS_ERR("index out of bound!");
#endif
	SvecQcomp_c sli(&v(0, j), v.n0());
	return sli;
}

inline SvecInt cut0(DcmatInt_IO v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
	    SLS_ERR("index out of bound!");
#endif
	SvecInt sli(&v(0, j), v.n0());
	return sli;
}

inline SvecInt_c cut0(DcmatInt_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
	    SLS_ERR("index out of bound!");
#endif
	SvecInt_c sli(&v(0, j), v.n0());
	return sli;
}

inline SvecLlong cut0(DcmatLlong_IO v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
	    SLS_ERR("index out of bound!");
#endif
	SvecLlong sli(&v(0, j), v.n0());
	return sli;
}

inline SvecLlong_c cut0(DcmatLlong_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
	    SLS_ERR("index out of bound!");
#endif
	SvecLlong_c sli(&v(0, j), v.n0());
	return sli;
}

inline SvecDoub cut0(DcmatDoub_IO v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
	    SLS_ERR("index out of bound!");
#endif
	SvecDoub sli(&v(0, j), v.n0());
	return sli;
}

inline SvecDoub_c cut0(DcmatDoub_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
	    SLS_ERR("index out of bound!");
#endif
	SvecDoub_c sli(&v(0, j), v.n0());
	return sli;
}

inline SvecQdoub cut0(DcmatQdoub_IO v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
	    SLS_ERR("index out of bound!");
#endif
	SvecQdoub sli(&v(0, j), v.n0());
	return sli;
}

inline SvecQdoub_c cut0(DcmatQdoub_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
	    SLS_ERR("index out of bound!");
#endif
	SvecQdoub_c sli(&v(0, j), v.n0());
	return sli;
}

inline SvecComp cut0(DcmatComp_IO v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
	    SLS_ERR("index out of bound!");
#endif
	SvecComp sli(&v(0, j), v.n0());
	return sli;
}

inline SvecComp_c cut0(DcmatComp_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
	    SLS_ERR("index out of bound!");
#endif
	SvecComp_c sli(&v(0, j), v.n0());
	return sli;
}

inline SvecQcomp cut0(DcmatQcomp_IO v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
	    SLS_ERR("index out of bound!");
#endif
	SvecQcomp sli(&v(0, j), v.n0());
	return sli;
}

inline SvecQcomp_c cut0(DcmatQcomp_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
	    SLS_ERR("index out of bound!");
#endif
	SvecQcomp_c sli(&v(0, j), v.n0());
	return sli;
}

inline SvecInt cut0(Cmat3Int_IO v, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1() || k < 0 || k >= v.n2())
	    SLS_ERR("index out of bound!");
#endif
	SvecInt sli(&v(0, j, k), v.n0());
	return sli;
}

inline SvecInt_c cut0(Cmat3Int_I v, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1() || k < 0 || k >= v.n2())
	    SLS_ERR("index out of bound!");
#endif
	SvecInt_c sli(&v(0, j, k), v.n0());
	return sli;
}

inline SvecLlong cut0(Cmat3Llong_IO v, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1() || k < 0 || k >= v.n2())
	    SLS_ERR("index out of bound!");
#endif
	SvecLlong sli(&v(0, j, k), v.n0());
	return sli;
}

inline SvecLlong_c cut0(Cmat3Llong_I v, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1() || k < 0 || k >= v.n2())
	    SLS_ERR("index out of bound!");
#endif
	SvecLlong_c sli(&v(0, j, k), v.n0());
	return sli;
}

inline SvecDoub cut0(Cmat3Doub_IO v, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1() || k < 0 || k >= v.n2())
	    SLS_ERR("index out of bound!");
#endif
	SvecDoub sli(&v(0, j, k), v.n0());
	return sli;
}

inline SvecDoub_c cut0(Cmat3Doub_I v, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1() || k < 0 || k >= v.n2())
	    SLS_ERR("index out of bound!");
#endif
	SvecDoub_c sli(&v(0, j, k), v.n0());
	return sli;
}

inline SvecComp cut0(Cmat3Comp_IO v, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1() || k < 0 || k >= v.n2())
	    SLS_ERR("index out of bound!");
#endif
	SvecComp sli(&v(0, j, k), v.n0());
	return sli;
}

inline SvecComp_c cut0(Cmat3Comp_I v, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1() || k < 0 || k >= v.n2())
	    SLS_ERR("index out of bound!");
#endif
	SvecComp_c sli(&v(0, j, k), v.n0());
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


inline SvecInt cut0(ScmatInt_IO v, Long_I i, Long_I N1, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i + N1 > v.n0() || j < 0 || j >= v.n1())
	    SLS_ERR("index out of bound!");
#endif
	SvecInt sli(&v(i, j), N1);
	return sli;
}

inline SvecInt_c cut0(ScmatInt_I v, Long_I i, Long_I N1, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i + N1 > v.n0() || j < 0 || j >= v.n1())
	    SLS_ERR("index out of bound!");
#endif
	SvecInt_c sli(&v(i, j), N1);
	return sli;
}

inline SvecLlong cut0(ScmatLlong_IO v, Long_I i, Long_I N1, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i + N1 > v.n0() || j < 0 || j >= v.n1())
	    SLS_ERR("index out of bound!");
#endif
	SvecLlong sli(&v(i, j), N1);
	return sli;
}

inline SvecLlong_c cut0(ScmatLlong_I v, Long_I i, Long_I N1, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i + N1 > v.n0() || j < 0 || j >= v.n1())
	    SLS_ERR("index out of bound!");
#endif
	SvecLlong_c sli(&v(i, j), N1);
	return sli;
}

inline SvecDoub cut0(CmatDoub_IO v, Long_I i, Long_I N1, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i + N1 > v.n0() || j < 0 || j >= v.n1())
	    SLS_ERR("index out of bound!");
#endif
	SvecDoub sli(&v(i, j), N1);
	return sli;
}

inline SvecDoub_c cut0(CmatDoub_I v, Long_I i, Long_I N1, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i + N1 > v.n0() || j < 0 || j >= v.n1())
	    SLS_ERR("index out of bound!");
#endif
	SvecDoub_c sli(&v(i, j), N1);
	return sli;
}

inline SvecQdoub cut0(CmatQdoub_IO v, Long_I i, Long_I N1, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i + N1 > v.n0() || j < 0 || j >= v.n1())
	    SLS_ERR("index out of bound!");
#endif
	SvecQdoub sli(&v(i, j), N1);
	return sli;
}

inline SvecQdoub_c cut0(CmatQdoub_I v, Long_I i, Long_I N1, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i + N1 > v.n0() || j < 0 || j >= v.n1())
	    SLS_ERR("index out of bound!");
#endif
	SvecQdoub_c sli(&v(i, j), N1);
	return sli;
}

inline SvecComp cut0(CmatComp_IO v, Long_I i, Long_I N1, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i + N1 > v.n0() || j < 0 || j >= v.n1())
	    SLS_ERR("index out of bound!");
#endif
	SvecComp sli(&v(i, j), N1);
	return sli;
}

inline SvecComp_c cut0(CmatComp_I v, Long_I i, Long_I N1, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i + N1 > v.n0() || j < 0 || j >= v.n1())
	    SLS_ERR("index out of bound!");
#endif
	SvecComp_c sli(&v(i, j), N1);
	return sli;
}

inline SvecQcomp cut0(CmatQcomp_IO v, Long_I i, Long_I N1, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i + N1 > v.n0() || j < 0 || j >= v.n1())
	    SLS_ERR("index out of bound!");
#endif
	SvecQcomp sli(&v(i, j), N1);
	return sli;
}

inline SvecQcomp_c cut0(CmatQcomp_I v, Long_I i, Long_I N1, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i + N1 > v.n0() || j < 0 || j >= v.n1())
	    SLS_ERR("index out of bound!");
#endif
	SvecQcomp_c sli(&v(i, j), N1);
	return sli;
}

inline SvecDoub cut0(ScmatDoub_IO v, Long_I i, Long_I N1, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i + N1 > v.n0() || j < 0 || j >= v.n1())
	    SLS_ERR("index out of bound!");
#endif
	SvecDoub sli(&v(i, j), N1);
	return sli;
}

inline SvecDoub_c cut0(ScmatDoub_I v, Long_I i, Long_I N1, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i + N1 > v.n0() || j < 0 || j >= v.n1())
	    SLS_ERR("index out of bound!");
#endif
	SvecDoub_c sli(&v(i, j), N1);
	return sli;
}

inline SvecQdoub cut0(ScmatQdoub_IO v, Long_I i, Long_I N1, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i + N1 > v.n0() || j < 0 || j >= v.n1())
	    SLS_ERR("index out of bound!");
#endif
	SvecQdoub sli(&v(i, j), N1);
	return sli;
}

inline SvecQdoub_c cut0(ScmatQdoub_I v, Long_I i, Long_I N1, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i + N1 > v.n0() || j < 0 || j >= v.n1())
	    SLS_ERR("index out of bound!");
#endif
	SvecQdoub_c sli(&v(i, j), N1);
	return sli;
}

inline SvecComp cut0(Cmat3Comp_IO v, Long_I i, Long_I N1, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i + N1 > v.n0() || j < 0 || j >= v.n1() || k < 0 || k >= v.n2())
	    SLS_ERR("index out of bound!");
#endif
	SvecComp sli(&v(i, j, k), N1);
	return sli;
}

inline SvecComp_c cut0(Cmat3Comp_I v, Long_I i, Long_I N1, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i + N1 > v.n0() || j < 0 || j >= v.n1() || k < 0 || k >= v.n2())
	    SLS_ERR("index out of bound!");
#endif
	SvecComp_c sli(&v(i, j, k), N1);
	return sli;
}

inline SvecQcomp cut0(Cmat3Qcomp_IO v, Long_I i, Long_I N1, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i + N1 > v.n0() || j < 0 || j >= v.n1() || k < 0 || k >= v.n2())
	    SLS_ERR("index out of bound!");
#endif
	SvecQcomp sli(&v(i, j, k), N1);
	return sli;
}

inline SvecQcomp_c cut0(Cmat3Qcomp_I v, Long_I i, Long_I N1, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i + N1 > v.n0() || j < 0 || j >= v.n1() || k < 0 || k >= v.n2())
	    SLS_ERR("index out of bound!");
#endif
	SvecQcomp_c sli(&v(i, j, k), N1);
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

inline SvecQcomp cut0(ScmatQcomp_IO v, Long_I i, Long_I N1, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i + N1 > v.n0() || j < 0 || j >= v.n1())
	    SLS_ERR("index out of bound!");
#endif
	SvecQcomp sli(&v(i, j), N1);
	return sli;
}

inline SvecQcomp_c cut0(ScmatQcomp_I v, Long_I i, Long_I N1, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i + N1 > v.n0() || j < 0 || j >= v.n1())
	    SLS_ERR("index out of bound!");
#endif
	SvecQcomp_c sli(&v(i, j), N1);
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

inline DvecQdoub cut1(CmatQdoub_IO v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0())
	    SLS_ERR("index out of bound!");
#endif
	DvecQdoub sli(&v(i, 0), v.n1(), v.n0());
	return sli;
}

inline DvecQdoub_c cut1(CmatQdoub_I v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0())
	    SLS_ERR("index out of bound!");
#endif
	DvecQdoub_c sli(&v(i, 0), v.n1(), v.n0());
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

inline DvecQcomp cut1(CmatQcomp_IO v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0())
	    SLS_ERR("index out of bound!");
#endif
	DvecQcomp sli(&v(i, 0), v.n1(), v.n0());
	return sli;
}

inline DvecQcomp_c cut1(CmatQcomp_I v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0())
	    SLS_ERR("index out of bound!");
#endif
	DvecQcomp_c sli(&v(i, 0), v.n1(), v.n0());
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

inline DvecQcomp cut1(ScmatQcomp_IO v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0())
	    SLS_ERR("index out of bound!");
#endif
	DvecQcomp sli(&v(i, 0), v.n1(), v.n0());
	return sli;
}

inline DvecQcomp_c cut1(ScmatQcomp_I v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0())
	    SLS_ERR("index out of bound!");
#endif
	DvecQcomp_c sli(&v(i, 0), v.n1(), v.n0());
	return sli;
}

inline SvecInt cut1(MatInt_IO v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0())
	    SLS_ERR("index out of bound!");
#endif
	SvecInt sli(&v(i, 0), v.n1());
	return sli;
}

inline SvecInt_c cut1(MatInt_I v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0())
	    SLS_ERR("index out of bound!");
#endif
	SvecInt_c sli(&v(i, 0), v.n1());
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

inline DvecComp cut1(Cmat3Comp_IO v, Long_I i, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0() || k < 0 || k >= v.n2())
	    SLS_ERR("index out of bound!");
#endif
	DvecComp sli(&v(i, 0, k), v.n1(), v.n0());
	return sli;
}

inline DvecComp_c cut1(Cmat3Comp_I v, Long_I i, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0() || k < 0 || k >= v.n2())
	    SLS_ERR("index out of bound!");
#endif
	DvecComp_c sli(&v(i, 0, k), v.n1(), v.n0());
	return sli;
}

inline DvecQcomp cut1(Cmat3Qcomp_IO v, Long_I i, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0() || k < 0 || k >= v.n2())
	    SLS_ERR("index out of bound!");
#endif
	DvecQcomp sli(&v(i, 0, k), v.n1(), v.n0());
	return sli;
}

inline DvecQcomp_c cut1(Cmat3Qcomp_I v, Long_I i, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0() || k < 0 || k >= v.n2())
	    SLS_ERR("index out of bound!");
#endif
	DvecQcomp_c sli(&v(i, 0, k), v.n1(), v.n0());
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

inline DvecLlong cut1(ScmatLlong_IO v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0())
	    SLS_ERR("index out of bound!");
#endif
	DvecLlong sli(&v(i, 0), v.n1(), v.n0());
	return sli;
}

inline DvecLlong_c cut1(ScmatLlong_I v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0())
	    SLS_ERR("index out of bound!");
#endif
	DvecLlong_c sli(&v(i, 0), v.n1(), v.n0());
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


inline DvecLlong cut1(CmatLlong_IO v, Long_I i, Long_I j, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0() || j < 0 || j + N2 > v.n1())
	    SLS_ERR("out of bound!");
#endif
	DvecLlong sli(&v(i, j), N2, v.n0());
	return sli;
}

inline DvecLlong_c cut1(CmatLlong_I v, Long_I i, Long_I j, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0() || j < 0 || j + N2 > v.n1())
	    SLS_ERR("out of bound!");
#endif
	DvecLlong_c sli(&v(i, j), N2, v.n0());
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

inline DvecQcomp cut1(CmatQcomp_IO v, Long_I i, Long_I j, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0() || j < 0 || j + N2 > v.n1())
	    SLS_ERR("out of bound!");
#endif
	DvecQcomp sli(&v(i, j), N2, v.n0());
	return sli;
}

inline DvecQcomp_c cut1(CmatQcomp_I v, Long_I i, Long_I j, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0() || j < 0 || j + N2 > v.n1())
	    SLS_ERR("out of bound!");
#endif
	DvecQcomp_c sli(&v(i, j), N2, v.n0());
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

inline DvecQdoub cut2(Cmat3Qdoub_IO v, Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0() || j < 0 || j >= v.n1())
	    SLS_ERR("index out of bound!");
#endif
	DvecQdoub sli(&v(i, j, 0), v.n2(), v.n0()*v.n1());
	return sli;
}

inline DvecQdoub_c cut2(Cmat3Qdoub_I v, Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0() || j < 0 || j >= v.n1())
	    SLS_ERR("index out of bound!");
#endif
	DvecQdoub_c sli(&v(i, j, 0), v.n2(), v.n0()*v.n1());
	return sli;
}

inline DvecComp cut2(Cmat3Comp_IO v, Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0() || j < 0 || j >= v.n1())
	    SLS_ERR("index out of bound!");
#endif
	DvecComp sli(&v(i, j, 0), v.n2(), v.n0()*v.n1());
	return sli;
}

inline DvecComp_c cut2(Cmat3Comp_I v, Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0() || j < 0 || j >= v.n1())
	    SLS_ERR("index out of bound!");
#endif
	DvecComp_c sli(&v(i, j, 0), v.n2(), v.n0()*v.n1());
	return sli;
}

inline DvecQcomp cut2(Cmat3Qcomp_IO v, Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0() || j < 0 || j >= v.n1())
	    SLS_ERR("index out of bound!");
#endif
	DvecQcomp sli(&v(i, j, 0), v.n2(), v.n0()*v.n1());
	return sli;
}

inline DvecQcomp_c cut2(Cmat3Qcomp_I v, Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0() || j < 0 || j >= v.n1())
	    SLS_ERR("index out of bound!");
#endif
	DvecQcomp_c sli(&v(i, j, 0), v.n2(), v.n0()*v.n1());
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

inline ScmatQcomp cut01(Cmat3Qcomp_IO v, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (k < 0 || k >= v.n2())
	    SLS_ERR("index out of bound!");
#endif
	ScmatQcomp sli(&v(0, 0, k), v.n0(), v.n1());
	return sli;
}

inline ScmatQcomp_c cut01(Cmat3Qcomp_I v, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (k < 0 || k >= v.n2())
	    SLS_ERR("index out of bound!");
#endif
	ScmatQcomp_c sli(&v(0, 0, k), v.n0(), v.n1());
	return sli;
}

inline ScmatInt cut01(Cmat3Int_IO v, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (k < 0 || k >= v.n2())
	    SLS_ERR("index out of bound!");
#endif
	ScmatInt sli(&v(0, 0, k), v.n0(), v.n1());
	return sli;
}

inline ScmatInt_c cut01(Cmat3Int_I v, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (k < 0 || k >= v.n2())
	    SLS_ERR("index out of bound!");
#endif
	ScmatInt_c sli(&v(0, 0, k), v.n0(), v.n1());
	return sli;
}

inline ScmatDoub cut01(Cmat3Doub_IO v, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (k < 0 || k >= v.n2())
	    SLS_ERR("index out of bound!");
#endif
	ScmatDoub sli(&v(0, 0, k), v.n0(), v.n1());
	return sli;
}

inline ScmatDoub_c cut01(Cmat3Doub_I v, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (k < 0 || k >= v.n2())
	    SLS_ERR("index out of bound!");
#endif
	ScmatDoub_c sli(&v(0, 0, k), v.n0(), v.n1());
	return sli;
}

inline ScmatQdoub cut01(Cmat3Qdoub_IO v, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (k < 0 || k >= v.n2())
	    SLS_ERR("index out of bound!");
#endif
	ScmatQdoub sli(&v(0, 0, k), v.n0(), v.n1());
	return sli;
}

inline ScmatQdoub_c cut01(Cmat3Qdoub_I v, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (k < 0 || k >= v.n2())
	    SLS_ERR("index out of bound!");
#endif
	ScmatQdoub_c sli(&v(0, 0, k), v.n0(), v.n1());
	return sli;
}

inline ScmatComp cut01(Scmat3Comp_IO v, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (k < 0 || k >= v.n2())
	    SLS_ERR("index out of bound!");
#endif
	ScmatComp sli(&v(0, 0, k), v.n0(), v.n1());
	return sli;
}

inline ScmatComp_c cut01(Scmat3Comp_I v, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (k < 0 || k >= v.n2())
	    SLS_ERR("index out of bound!");
#endif
	ScmatComp_c sli(&v(0, 0, k), v.n0(), v.n1());
	return sli;
}

inline ScmatQcomp cut01(Scmat3Qcomp_IO v, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (k < 0 || k >= v.n2())
	    SLS_ERR("index out of bound!");
#endif
	ScmatQcomp sli(&v(0, 0, k), v.n0(), v.n1());
	return sli;
}

inline ScmatQcomp_c cut01(Scmat3Qcomp_I v, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (k < 0 || k >= v.n2())
	    SLS_ERR("index out of bound!");
#endif
	ScmatQcomp_c sli(&v(0, 0, k), v.n0(), v.n1());
	return sli;
}

inline ScmatInt cut01(Cmat4Int_IO v, Long_I k, Long_I l)
{
#ifdef SLS_CHECK_BOUNDS
	if (k < 0 || k >= v.n2() || l < 0 || l >= v.n3())
	    SLS_ERR("index out of bound!");
#endif
	ScmatInt sli(&v(0, 0, k, l), v.n0(), v.n1());
	return sli;
}

inline ScmatInt_c cut01(Cmat4Int_I v, Long_I k, Long_I l)
{
#ifdef SLS_CHECK_BOUNDS
	if (k < 0 || k >= v.n2() || l < 0 || l >= v.n3())
	    SLS_ERR("index out of bound!");
#endif
	ScmatInt_c sli(&v(0, 0, k, l), v.n0(), v.n1());
	return sli;
}

inline ScmatDoub cut01(Cmat4Doub_IO v, Long_I k, Long_I l)
{
#ifdef SLS_CHECK_BOUNDS
	if (k < 0 || k >= v.n2() || l < 0 || l >= v.n3())
	    SLS_ERR("index out of bound!");
#endif
	ScmatDoub sli(&v(0, 0, k, l), v.n0(), v.n1());
	return sli;
}

inline ScmatDoub_c cut01(Cmat4Doub_I v, Long_I k, Long_I l)
{
#ifdef SLS_CHECK_BOUNDS
	if (k < 0 || k >= v.n2() || l < 0 || l >= v.n3())
	    SLS_ERR("index out of bound!");
#endif
	ScmatDoub_c sli(&v(0, 0, k, l), v.n0(), v.n1());
	return sli;
}

inline ScmatQdoub cut01(Cmat4Qdoub_IO v, Long_I k, Long_I l)
{
#ifdef SLS_CHECK_BOUNDS
	if (k < 0 || k >= v.n2() || l < 0 || l >= v.n3())
	    SLS_ERR("index out of bound!");
#endif
	ScmatQdoub sli(&v(0, 0, k, l), v.n0(), v.n1());
	return sli;
}

inline ScmatQdoub_c cut01(Cmat4Qdoub_I v, Long_I k, Long_I l)
{
#ifdef SLS_CHECK_BOUNDS
	if (k < 0 || k >= v.n2() || l < 0 || l >= v.n3())
	    SLS_ERR("index out of bound!");
#endif
	ScmatQdoub_c sli(&v(0, 0, k, l), v.n0(), v.n1());
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

inline ScmatQdoub cut01(Cmat3Qdoub_IO v, Long_I j, Long_I N2, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j + N2 > v.n1() || k < 0 || k >= v.n2())
	    SLS_ERR("index out of bound!");
#endif
	ScmatQdoub sli(&v(0, j, k), v.n0(), N2);
	return sli;
}

inline ScmatQdoub_c cut01(Cmat3Qdoub_I v, Long_I j, Long_I N2, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j + N2 > v.n1() || k < 0 || k >= v.n2())
	    SLS_ERR("index out of bound!");
#endif
	ScmatQdoub_c sli(&v(0, j, k), v.n0(), N2);
	return sli;
}

inline ScmatComp cut01(Cmat3Comp_IO v, Long_I j, Long_I N2, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j + N2 > v.n1() || k < 0 || k >= v.n2())
	    SLS_ERR("index out of bound!");
#endif
	ScmatComp sli(&v(0, j, k), v.n0(), N2);
	return sli;
}

inline ScmatComp_c cut01(Cmat3Comp_I v, Long_I j, Long_I N2, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j + N2 > v.n1() || k < 0 || k >= v.n2())
	    SLS_ERR("index out of bound!");
#endif
	ScmatComp_c sli(&v(0, j, k), v.n0(), N2);
	return sli;
}

inline ScmatQcomp cut01(Cmat3Qcomp_IO v, Long_I j, Long_I N2, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j + N2 > v.n1() || k < 0 || k >= v.n2())
	    SLS_ERR("index out of bound!");
#endif
	ScmatQcomp sli(&v(0, j, k), v.n0(), N2);
	return sli;
}

inline ScmatQcomp_c cut01(Cmat3Qcomp_I v, Long_I j, Long_I N2, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j + N2 > v.n1() || k < 0 || k >= v.n2())
	    SLS_ERR("index out of bound!");
#endif
	ScmatQcomp_c sli(&v(0, j, k), v.n0(), N2);
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

inline DcmatQdoub cut01(Cmat3Qdoub_IO v, Long_I i, Long_I N1, Long_I j, Long_I N2, Long_I k)
{
	DcmatQdoub sli(&v(i, j, k), N1, N2, v.n0());
	return sli;
}

inline DcmatQdoub_c cut01(Cmat3Qdoub_I v, Long_I i, Long_I N1, Long_I j, Long_I N2, Long_I k)
{
	DcmatQdoub_c sli(&v(i, j, k), N1, N2, v.n0());
	return sli;
}

inline DcmatComp cut01(Cmat3Comp_IO v, Long_I i, Long_I N1, Long_I j, Long_I N2, Long_I k)
{
	DcmatComp sli(&v(i, j, k), N1, N2, v.n0());
	return sli;
}

inline DcmatComp_c cut01(Cmat3Comp_I v, Long_I i, Long_I N1, Long_I j, Long_I N2, Long_I k)
{
	DcmatComp_c sli(&v(i, j, k), N1, N2, v.n0());
	return sli;
}

inline DcmatQcomp cut01(Cmat3Qcomp_IO v, Long_I i, Long_I N1, Long_I j, Long_I N2, Long_I k)
{
	DcmatQcomp sli(&v(i, j, k), N1, N2, v.n0());
	return sli;
}

inline DcmatQcomp_c cut01(Cmat3Qcomp_I v, Long_I i, Long_I N1, Long_I j, Long_I N2, Long_I k)
{
	DcmatQcomp_c sli(&v(i, j, k), N1, N2, v.n0());
	return sli;
}

} // namespace slisc
