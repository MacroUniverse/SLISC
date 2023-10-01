#pragma once
#include "../dense/Vec.h"
#include "../dense/Mat.h"
#include "../dense/Cmat.h"
#include "../dense/Cmat3.h"
#include "../dense/Cmat4.h"
#include "../dense/Svec.h"
#include "../dense/Dvec.h"
#include "../dense/Scmat.h"
#include "../dense/Scmat3.h"
#include "../dense/Scmat4.h"
#include "../dense/Dcmat.h"
#include "../dense/Jcmat3.h"

namespace slisc {
inline SvecInt cut(VecInt_IO v, Long_I start, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (start < 0 || start + N > v.size())
		SLS_ERR("index out of bound!");
#endif
	SvecInt sv(&v[start], N);
	return sv;
}

inline SvecIntC cut(VecInt_I v, Long_I start, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (start < 0 || start + N > v.size())
		SLS_ERR("index out of bound!");
#endif
	SvecIntC sv(&v[start], N);
	return sv;
}

inline SvecDoub cut(VecDoub_IO v, Long_I start, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (start < 0 || start + N > v.size())
		SLS_ERR("index out of bound!");
#endif
	SvecDoub sv(&v[start], N);
	return sv;
}

inline SvecDoubC cut(VecDoub_I v, Long_I start, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (start < 0 || start + N > v.size())
		SLS_ERR("index out of bound!");
#endif
	SvecDoubC sv(&v[start], N);
	return sv;
}


inline SvecComp cut(VecComp_IO v, Long_I start, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (start < 0 || start + N > v.size())
		SLS_ERR("index out of bound!");
#endif
	SvecComp sv(&v[start], N);
	return sv;
}

inline SvecCompC cut(VecComp_I v, Long_I start, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (start < 0 || start + N > v.size())
		SLS_ERR("index out of bound!");
#endif
	SvecCompC sv(&v[start], N);
	return sv;
}


inline SvecInt cut(SvecInt_IO v, Long_I start, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (start < 0 || start + N > v.size())
		SLS_ERR("index out of bound!");
#endif
	SvecInt sv(&v[start], N);
	return sv;
}

inline SvecIntC cut(SvecInt_I v, Long_I start, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (start < 0 || start + N > v.size())
		SLS_ERR("index out of bound!");
#endif
	SvecIntC sv(&v[start], N);
	return sv;
}

inline SvecDoub cut(SvecDoub_IO v, Long_I start, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (start < 0 || start + N > v.size())
		SLS_ERR("index out of bound!");
#endif
	SvecDoub sv(&v[start], N);
	return sv;
}

inline SvecDoubC cut(SvecDoub_I v, Long_I start, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (start < 0 || start + N > v.size())
		SLS_ERR("index out of bound!");
#endif
	SvecDoubC sv(&v[start], N);
	return sv;
}


inline SvecComp cut(SvecComp_IO v, Long_I start, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (start < 0 || start + N > v.size())
		SLS_ERR("index out of bound!");
#endif
	SvecComp sv(&v[start], N);
	return sv;
}

inline SvecCompC cut(SvecComp_I v, Long_I start, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (start < 0 || start + N > v.size())
		SLS_ERR("index out of bound!");
#endif
	SvecCompC sv(&v[start], N);
	return sv;
}


inline DcmatInt cut(CmatInt_IO v, Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (start1 < 0 || start1 + N1 > v.n0() ||
			start2 < 0 || start2 + N2 > v.n1())
		SLS_ERR("index out of bound!");
#endif
	DcmatInt sv(&v(start1, start2), N1, N2, v.n0());
	return sv;
}

inline DcmatIntC cut(CmatInt_I v,
	Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (start1 < 0 || start1 + N1 > v.n0() ||
			start2 < 0 || start2 + N2 > v.n1())
		SLS_ERR("index out of bound!");
#endif
	DcmatIntC sv(&v(start1, start2), N1, N2, v.n0());
	return sv;
}
inline ScmatInt cut(CmatInt_IO v, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (start2 < 0 || start2 + N2 > v.n1())
		SLS_ERR("index out of bound!");
#endif
	ScmatInt sv(&v(0, start2), v.n0(), N2);
	return sv;
}

inline ScmatIntC cut(CmatInt_I v, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (start2 < 0 || start2 + N2 > v.n1())
		SLS_ERR("index out of bound!");
#endif
	ScmatIntC sv(&v(0, start2), v.n0(), N2);
	return sv;
}

inline DcmatDoub cut(CmatDoub_IO v, Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (start1 < 0 || start1 + N1 > v.n0() ||
			start2 < 0 || start2 + N2 > v.n1())
		SLS_ERR("index out of bound!");
#endif
	DcmatDoub sv(&v(start1, start2), N1, N2, v.n0());
	return sv;
}

inline DcmatDoubC cut(CmatDoub_I v,
	Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (start1 < 0 || start1 + N1 > v.n0() ||
			start2 < 0 || start2 + N2 > v.n1())
		SLS_ERR("index out of bound!");
#endif
	DcmatDoubC sv(&v(start1, start2), N1, N2, v.n0());
	return sv;
}
inline ScmatDoub cut(CmatDoub_IO v, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (start2 < 0 || start2 + N2 > v.n1())
		SLS_ERR("index out of bound!");
#endif
	ScmatDoub sv(&v(0, start2), v.n0(), N2);
	return sv;
}

inline ScmatDoubC cut(CmatDoub_I v, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (start2 < 0 || start2 + N2 > v.n1())
		SLS_ERR("index out of bound!");
#endif
	ScmatDoubC sv(&v(0, start2), v.n0(), N2);
	return sv;
}


inline DcmatComp cut(CmatComp_IO v, Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (start1 < 0 || start1 + N1 > v.n0() ||
			start2 < 0 || start2 + N2 > v.n1())
		SLS_ERR("index out of bound!");
#endif
	DcmatComp sv(&v(start1, start2), N1, N2, v.n0());
	return sv;
}

inline DcmatCompC cut(CmatComp_I v,
	Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (start1 < 0 || start1 + N1 > v.n0() ||
			start2 < 0 || start2 + N2 > v.n1())
		SLS_ERR("index out of bound!");
#endif
	DcmatCompC sv(&v(start1, start2), N1, N2, v.n0());
	return sv;
}
inline ScmatComp cut(CmatComp_IO v, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (start2 < 0 || start2 + N2 > v.n1())
		SLS_ERR("index out of bound!");
#endif
	ScmatComp sv(&v(0, start2), v.n0(), N2);
	return sv;
}

inline ScmatCompC cut(CmatComp_I v, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (start2 < 0 || start2 + N2 > v.n1())
		SLS_ERR("index out of bound!");
#endif
	ScmatCompC sv(&v(0, start2), v.n0(), N2);
	return sv;
}


inline DcmatInt cut(ScmatInt_IO v, Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (start1 < 0 || start1 + N1 > v.n0() ||
			start2 < 0 || start2 + N2 > v.n1())
		SLS_ERR("index out of bound!");
#endif
	DcmatInt sv(&v(start1, start2), N1, N2, v.n0());
	return sv;
}

inline DcmatIntC cut(ScmatInt_I v,
	Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (start1 < 0 || start1 + N1 > v.n0() ||
			start2 < 0 || start2 + N2 > v.n1())
		SLS_ERR("index out of bound!");
#endif
	DcmatIntC sv(&v(start1, start2), N1, N2, v.n0());
	return sv;
}
inline ScmatInt cut(ScmatInt_IO v, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (start2 < 0 || start2 + N2 > v.n1())
		SLS_ERR("index out of bound!");
#endif
	ScmatInt sv(&v(0, start2), v.n0(), N2);
	return sv;
}

inline ScmatIntC cut(ScmatInt_I v, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (start2 < 0 || start2 + N2 > v.n1())
		SLS_ERR("index out of bound!");
#endif
	ScmatIntC sv(&v(0, start2), v.n0(), N2);
	return sv;
}

inline DcmatDoub cut(ScmatDoub_IO v, Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (start1 < 0 || start1 + N1 > v.n0() ||
			start2 < 0 || start2 + N2 > v.n1())
		SLS_ERR("index out of bound!");
#endif
	DcmatDoub sv(&v(start1, start2), N1, N2, v.n0());
	return sv;
}

inline DcmatDoubC cut(ScmatDoub_I v,
	Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (start1 < 0 || start1 + N1 > v.n0() ||
			start2 < 0 || start2 + N2 > v.n1())
		SLS_ERR("index out of bound!");
#endif
	DcmatDoubC sv(&v(start1, start2), N1, N2, v.n0());
	return sv;
}
inline ScmatDoub cut(ScmatDoub_IO v, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (start2 < 0 || start2 + N2 > v.n1())
		SLS_ERR("index out of bound!");
#endif
	ScmatDoub sv(&v(0, start2), v.n0(), N2);
	return sv;
}

inline ScmatDoubC cut(ScmatDoub_I v, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (start2 < 0 || start2 + N2 > v.n1())
		SLS_ERR("index out of bound!");
#endif
	ScmatDoubC sv(&v(0, start2), v.n0(), N2);
	return sv;
}


inline DcmatComp cut(ScmatComp_IO v, Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (start1 < 0 || start1 + N1 > v.n0() ||
			start2 < 0 || start2 + N2 > v.n1())
		SLS_ERR("index out of bound!");
#endif
	DcmatComp sv(&v(start1, start2), N1, N2, v.n0());
	return sv;
}

inline DcmatCompC cut(ScmatComp_I v,
	Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (start1 < 0 || start1 + N1 > v.n0() ||
			start2 < 0 || start2 + N2 > v.n1())
		SLS_ERR("index out of bound!");
#endif
	DcmatCompC sv(&v(start1, start2), N1, N2, v.n0());
	return sv;
}
inline ScmatComp cut(ScmatComp_IO v, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (start2 < 0 || start2 + N2 > v.n1())
		SLS_ERR("index out of bound!");
#endif
	ScmatComp sv(&v(0, start2), v.n0(), N2);
	return sv;
}

inline ScmatCompC cut(ScmatComp_I v, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (start2 < 0 || start2 + N2 > v.n1())
		SLS_ERR("index out of bound!");
#endif
	ScmatCompC sv(&v(0, start2), v.n0(), N2);
	return sv;
}


inline DcmatLlong cut(CmatLlong_IO v, Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (start1 < 0 || start1 + N1 > v.n0() ||
			start2 < 0 || start2 + N2 > v.n1())
		SLS_ERR("index out of bound!");
#endif
	DcmatLlong sv(&v(start1, start2), N1, N2, v.n0());
	return sv;
}

inline DcmatLlongC cut(CmatLlong_I v,
	Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (start1 < 0 || start1 + N1 > v.n0() ||
			start2 < 0 || start2 + N2 > v.n1())
		SLS_ERR("index out of bound!");
#endif
	DcmatLlongC sv(&v(start1, start2), N1, N2, v.n0());
	return sv;
}
inline ScmatLlong cut(CmatLlong_IO v, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (start2 < 0 || start2 + N2 > v.n1())
		SLS_ERR("index out of bound!");
#endif
	ScmatLlong sv(&v(0, start2), v.n0(), N2);
	return sv;
}

inline ScmatLlongC cut(CmatLlong_I v, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (start2 < 0 || start2 + N2 > v.n1())
		SLS_ERR("index out of bound!");
#endif
	ScmatLlongC sv(&v(0, start2), v.n0(), N2);
	return sv;
}

inline Jcmat3Doub cut(Cmat3Doub_IO v, Long_I start1, Long_I N1, Long_I start2, Long_I N2, Long_I start3, Long_I N3)
{
#ifdef SLS_CHECK_BOUNDS
	if (start1 < 0 || start1 + N1 > v.n0() || start2 < 0 || start2 + N2 > v.n1() || start3 < 0 || start3 + N3 > v.n2())
		SLS_ERR("index out of bound!");
#endif
	Jcmat3Doub sv(&v(start1, start2, start3), N1, N2, N3, 1, v.n0(), v.n0()*v.n1());
	return sv;
}

inline Jcmat3DoubC cut(Cmat3Doub_I v, Long_I start1, Long_I N1, Long_I start2, Long_I N2, Long_I start3, Long_I N3)
{
#ifdef SLS_CHECK_BOUNDS
	if (start1 < 0 || start1 + N1 > v.n0() || start2 < 0 || start2 + N2 > v.n1() || start3 < 0 || start3 + N3 > v.n2())
		SLS_ERR("index out of bound!");
#endif
	Jcmat3DoubC sv(&v(start1, start2, start3), N1, N2, N3, 1, v.n0(), v.n0()*v.n1());
	return sv;
}

inline Jcmat3Comp cut(Cmat3Comp_IO v, Long_I start1, Long_I N1, Long_I start2, Long_I N2, Long_I start3, Long_I N3)
{
#ifdef SLS_CHECK_BOUNDS
	if (start1 < 0 || start1 + N1 > v.n0() || start2 < 0 || start2 + N2 > v.n1() || start3 < 0 || start3 + N3 > v.n2())
		SLS_ERR("index out of bound!");
#endif
	Jcmat3Comp sv(&v(start1, start2, start3), N1, N2, N3, 1, v.n0(), v.n0()*v.n1());
	return sv;
}

inline Jcmat3CompC cut(Cmat3Comp_I v, Long_I start1, Long_I N1, Long_I start2, Long_I N2, Long_I start3, Long_I N3)
{
#ifdef SLS_CHECK_BOUNDS
	if (start1 < 0 || start1 + N1 > v.n0() || start2 < 0 || start2 + N2 > v.n1() || start3 < 0 || start3 + N3 > v.n2())
		SLS_ERR("index out of bound!");
#endif
	Jcmat3CompC sv(&v(start1, start2, start3), N1, N2, N3, 1, v.n0(), v.n0()*v.n1());
	return sv;
}


inline DvecInt cut0(MatInt_IO v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	DvecInt sv(&v(0, j), v.n0(), v.n1());
	return sv;
}

inline DvecIntC cut0(MatInt_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	DvecIntC sv(&v(0, j), v.n0(), v.n1());
	return sv;
}

inline SvecInt cut0(CmatInt_IO v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	SvecInt sv(&v(0, j), v.n0());
	return sv;
}

inline SvecIntC cut0(CmatInt_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	SvecIntC sv(&v(0, j), v.n0());
	return sv;
}

inline SvecLlong cut0(CmatLlong_IO v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	SvecLlong sv(&v(0, j), v.n0());
	return sv;
}

inline SvecLlongC cut0(CmatLlong_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	SvecLlongC sv(&v(0, j), v.n0());
	return sv;
}

inline SvecDoub cut0(CmatDoub_IO v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	SvecDoub sv(&v(0, j), v.n0());
	return sv;
}

inline SvecDoubC cut0(CmatDoub_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	SvecDoubC sv(&v(0, j), v.n0());
	return sv;
}


inline SvecComp cut0(CmatComp_IO v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	SvecComp sv(&v(0, j), v.n0());
	return sv;
}

inline SvecCompC cut0(CmatComp_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	SvecCompC sv(&v(0, j), v.n0());
	return sv;
}


inline SvecInt cut0(ScmatInt_IO v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	SvecInt sv(&v(0, j), v.n0());
	return sv;
}

inline SvecIntC cut0(ScmatInt_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	SvecIntC sv(&v(0, j), v.n0());
	return sv;
}

inline SvecLlong cut0(ScmatLlong_IO v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	SvecLlong sv(&v(0, j), v.n0());
	return sv;
}

inline SvecLlongC cut0(ScmatLlong_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	SvecLlongC sv(&v(0, j), v.n0());
	return sv;
}

inline SvecDoub cut0(ScmatDoub_IO v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	SvecDoub sv(&v(0, j), v.n0());
	return sv;
}

inline SvecDoubC cut0(ScmatDoub_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	SvecDoubC sv(&v(0, j), v.n0());
	return sv;
}


inline SvecComp cut0(ScmatComp_IO v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	SvecComp sv(&v(0, j), v.n0());
	return sv;
}

inline SvecCompC cut0(ScmatComp_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	SvecCompC sv(&v(0, j), v.n0());
	return sv;
}


inline SvecInt cut0(DcmatInt_IO v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	SvecInt sv(&v(0, j), v.n0());
	return sv;
}

inline SvecIntC cut0(DcmatInt_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	SvecIntC sv(&v(0, j), v.n0());
	return sv;
}

inline SvecLlong cut0(DcmatLlong_IO v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	SvecLlong sv(&v(0, j), v.n0());
	return sv;
}

inline SvecLlongC cut0(DcmatLlong_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	SvecLlongC sv(&v(0, j), v.n0());
	return sv;
}

inline SvecDoub cut0(DcmatDoub_IO v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	SvecDoub sv(&v(0, j), v.n0());
	return sv;
}

inline SvecDoubC cut0(DcmatDoub_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	SvecDoubC sv(&v(0, j), v.n0());
	return sv;
}


inline SvecComp cut0(DcmatComp_IO v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	SvecComp sv(&v(0, j), v.n0());
	return sv;
}

inline SvecCompC cut0(DcmatComp_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	SvecCompC sv(&v(0, j), v.n0());
	return sv;
}


inline SvecInt cut0(Cmat3Int_IO v, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1() || k < 0 || k >= v.n2())
		SLS_ERR("index out of bound!");
#endif
	SvecInt sv(&v(0, j, k), v.n0());
	return sv;
}

inline SvecIntC cut0(Cmat3Int_I v, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1() || k < 0 || k >= v.n2())
		SLS_ERR("index out of bound!");
#endif
	SvecIntC sv(&v(0, j, k), v.n0());
	return sv;
}

inline SvecLlong cut0(Cmat3Llong_IO v, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1() || k < 0 || k >= v.n2())
		SLS_ERR("index out of bound!");
#endif
	SvecLlong sv(&v(0, j, k), v.n0());
	return sv;
}

inline SvecLlongC cut0(Cmat3Llong_I v, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1() || k < 0 || k >= v.n2())
		SLS_ERR("index out of bound!");
#endif
	SvecLlongC sv(&v(0, j, k), v.n0());
	return sv;
}

inline SvecDoub cut0(Cmat3Doub_IO v, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1() || k < 0 || k >= v.n2())
		SLS_ERR("index out of bound!");
#endif
	SvecDoub sv(&v(0, j, k), v.n0());
	return sv;
}

inline SvecDoubC cut0(Cmat3Doub_I v, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1() || k < 0 || k >= v.n2())
		SLS_ERR("index out of bound!");
#endif
	SvecDoubC sv(&v(0, j, k), v.n0());
	return sv;
}


inline SvecComp cut0(Cmat3Comp_IO v, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1() || k < 0 || k >= v.n2())
		SLS_ERR("index out of bound!");
#endif
	SvecComp sv(&v(0, j, k), v.n0());
	return sv;
}

inline SvecCompC cut0(Cmat3Comp_I v, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1() || k < 0 || k >= v.n2())
		SLS_ERR("index out of bound!");
#endif
	SvecCompC sv(&v(0, j, k), v.n0());
	return sv;
}


inline SvecInt cut0(Scmat3Int_IO v, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1() || k < 0 || k >= v.n2())
		SLS_ERR("index out of bound!");
#endif
	SvecInt sv(&v(0, j, k), v.n0());
	return sv;
}

inline SvecIntC cut0(Scmat3Int_I v, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1() || k < 0 || k >= v.n2())
		SLS_ERR("index out of bound!");
#endif
	SvecIntC sv(&v(0, j, k), v.n0());
	return sv;
}

inline SvecLlong cut0(Scmat3Llong_IO v, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1() || k < 0 || k >= v.n2())
		SLS_ERR("index out of bound!");
#endif
	SvecLlong sv(&v(0, j, k), v.n0());
	return sv;
}

inline SvecLlongC cut0(Scmat3Llong_I v, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1() || k < 0 || k >= v.n2())
		SLS_ERR("index out of bound!");
#endif
	SvecLlongC sv(&v(0, j, k), v.n0());
	return sv;
}

inline SvecDoub cut0(Scmat3Doub_IO v, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1() || k < 0 || k >= v.n2())
		SLS_ERR("index out of bound!");
#endif
	SvecDoub sv(&v(0, j, k), v.n0());
	return sv;
}

inline SvecDoubC cut0(Scmat3Doub_I v, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1() || k < 0 || k >= v.n2())
		SLS_ERR("index out of bound!");
#endif
	SvecDoubC sv(&v(0, j, k), v.n0());
	return sv;
}


inline SvecComp cut0(Scmat3Comp_IO v, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1() || k < 0 || k >= v.n2())
		SLS_ERR("index out of bound!");
#endif
	SvecComp sv(&v(0, j, k), v.n0());
	return sv;
}

inline SvecCompC cut0(Scmat3Comp_I v, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1() || k < 0 || k >= v.n2())
		SLS_ERR("index out of bound!");
#endif
	SvecCompC sv(&v(0, j, k), v.n0());
	return sv;
}



inline SvecInt cut0(CmatInt_IO v, Long_I i, Long_I N1, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i + N1 > v.n0() || j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	SvecInt sv(&v(i, j), N1);
	return sv;
}

inline SvecIntC cut0(CmatInt_I v, Long_I i, Long_I N1, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i + N1 > v.n0() || j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	SvecIntC sv(&v(i, j), N1);
	return sv;
}

inline SvecLlong cut0(CmatLlong_IO v, Long_I i, Long_I N1, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i + N1 > v.n0() || j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	SvecLlong sv(&v(i, j), N1);
	return sv;
}

inline SvecLlongC cut0(CmatLlong_I v, Long_I i, Long_I N1, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i + N1 > v.n0() || j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	SvecLlongC sv(&v(i, j), N1);
	return sv;
}

inline SvecDoub cut0(CmatDoub_IO v, Long_I i, Long_I N1, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i + N1 > v.n0() || j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	SvecDoub sv(&v(i, j), N1);
	return sv;
}

inline SvecDoubC cut0(CmatDoub_I v, Long_I i, Long_I N1, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i + N1 > v.n0() || j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	SvecDoubC sv(&v(i, j), N1);
	return sv;
}


inline SvecComp cut0(CmatComp_IO v, Long_I i, Long_I N1, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i + N1 > v.n0() || j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	SvecComp sv(&v(i, j), N1);
	return sv;
}

inline SvecCompC cut0(CmatComp_I v, Long_I i, Long_I N1, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i + N1 > v.n0() || j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	SvecCompC sv(&v(i, j), N1);
	return sv;
}


inline SvecComp cut0(Cmat3Comp_IO v, Long_I i, Long_I N1, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i + N1 > v.n0() || j < 0 || j >= v.n1() || k < 0 || k >= v.n2())
		SLS_ERR("index out of bound!");
#endif
	SvecComp sv(&v(i, j, k), N1);
	return sv;
}

inline SvecCompC cut0(Cmat3Comp_I v, Long_I i, Long_I N1, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i + N1 > v.n0() || j < 0 || j >= v.n1() || k < 0 || k >= v.n2())
		SLS_ERR("index out of bound!");
#endif
	SvecCompC sv(&v(i, j, k), N1);
	return sv;
}


inline SvecInt cut0(ScmatInt_IO v, Long_I i, Long_I N1, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i + N1 > v.n0() || j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	SvecInt sv(&v(i, j), N1);
	return sv;
}

inline SvecIntC cut0(ScmatInt_I v, Long_I i, Long_I N1, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i + N1 > v.n0() || j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	SvecIntC sv(&v(i, j), N1);
	return sv;
}

inline SvecLlong cut0(ScmatLlong_IO v, Long_I i, Long_I N1, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i + N1 > v.n0() || j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	SvecLlong sv(&v(i, j), N1);
	return sv;
}

inline SvecLlongC cut0(ScmatLlong_I v, Long_I i, Long_I N1, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i + N1 > v.n0() || j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	SvecLlongC sv(&v(i, j), N1);
	return sv;
}

inline SvecDoub cut0(ScmatDoub_IO v, Long_I i, Long_I N1, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i + N1 > v.n0() || j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	SvecDoub sv(&v(i, j), N1);
	return sv;
}

inline SvecDoubC cut0(ScmatDoub_I v, Long_I i, Long_I N1, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i + N1 > v.n0() || j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	SvecDoubC sv(&v(i, j), N1);
	return sv;
}


inline SvecComp cut0(ScmatComp_IO v, Long_I i, Long_I N1, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i + N1 > v.n0() || j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	SvecComp sv(&v(i, j), N1);
	return sv;
}

inline SvecCompC cut0(ScmatComp_I v, Long_I i, Long_I N1, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i + N1 > v.n0() || j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	SvecCompC sv(&v(i, j), N1);
	return sv;
}


inline SvecComp cut0(Scmat3Comp_IO v, Long_I i, Long_I N1, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i + N1 > v.n0() || j < 0 || j >= v.n1() || k < 0 || k >= v.n2())
		SLS_ERR("index out of bound!");
#endif
	SvecComp sv(&v(i, j, k), N1);
	return sv;
}

inline SvecCompC cut0(Scmat3Comp_I v, Long_I i, Long_I N1, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i + N1 > v.n0() || j < 0 || j >= v.n1() || k < 0 || k >= v.n2())
		SLS_ERR("index out of bound!");
#endif
	SvecCompC sv(&v(i, j, k), N1);
	return sv;
}



inline DvecDoub cut1(CmatDoub_IO v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0())
		SLS_ERR("index out of bound!");
#endif
	DvecDoub sv(&v(i, 0), v.n1(), v.n0());
	return sv;
}

inline DvecDoubC cut1(CmatDoub_I v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0())
		SLS_ERR("index out of bound!");
#endif
	DvecDoubC sv(&v(i, 0), v.n1(), v.n0());
	return sv;
}


inline DvecComp cut1(CmatComp_IO v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0())
		SLS_ERR("index out of bound!");
#endif
	DvecComp sv(&v(i, 0), v.n1(), v.n0());
	return sv;
}

inline DvecCompC cut1(CmatComp_I v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0())
		SLS_ERR("index out of bound!");
#endif
	DvecCompC sv(&v(i, 0), v.n1(), v.n0());
	return sv;
}


inline DvecLlong cut1(CmatLlong_IO v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0())
		SLS_ERR("index out of bound!");
#endif
	DvecLlong sv(&v(i, 0), v.n1(), v.n0());
	return sv;
}

inline DvecLlongC cut1(CmatLlong_I v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0())
		SLS_ERR("index out of bound!");
#endif
	DvecLlongC sv(&v(i, 0), v.n1(), v.n0());
	return sv;
}

inline DvecComp cut1(Cmat3Comp_IO v, Long_I i, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0() || k < 0 || k >= v.n2())
		SLS_ERR("index out of bound!");
#endif
	DvecComp sv(&v(i, 0, k), v.n1(), v.n0());
	return sv;
}

inline DvecCompC cut1(Cmat3Comp_I v, Long_I i, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0() || k < 0 || k >= v.n2())
		SLS_ERR("index out of bound!");
#endif
	DvecCompC sv(&v(i, 0, k), v.n1(), v.n0());
	return sv;
}


inline DvecDoub cut1(ScmatDoub_IO v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0())
		SLS_ERR("index out of bound!");
#endif
	DvecDoub sv(&v(i, 0), v.n1(), v.n0());
	return sv;
}

inline DvecDoubC cut1(ScmatDoub_I v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0())
		SLS_ERR("index out of bound!");
#endif
	DvecDoubC sv(&v(i, 0), v.n1(), v.n0());
	return sv;
}


inline DvecComp cut1(ScmatComp_IO v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0())
		SLS_ERR("index out of bound!");
#endif
	DvecComp sv(&v(i, 0), v.n1(), v.n0());
	return sv;
}

inline DvecCompC cut1(ScmatComp_I v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0())
		SLS_ERR("index out of bound!");
#endif
	DvecCompC sv(&v(i, 0), v.n1(), v.n0());
	return sv;
}


inline DvecLlong cut1(ScmatLlong_IO v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0())
		SLS_ERR("index out of bound!");
#endif
	DvecLlong sv(&v(i, 0), v.n1(), v.n0());
	return sv;
}

inline DvecLlongC cut1(ScmatLlong_I v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0())
		SLS_ERR("index out of bound!");
#endif
	DvecLlongC sv(&v(i, 0), v.n1(), v.n0());
	return sv;
}

inline DvecComp cut1(Scmat3Comp_IO v, Long_I i, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0() || k < 0 || k >= v.n2())
		SLS_ERR("index out of bound!");
#endif
	DvecComp sv(&v(i, 0, k), v.n1(), v.n0());
	return sv;
}

inline DvecCompC cut1(Scmat3Comp_I v, Long_I i, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0() || k < 0 || k >= v.n2())
		SLS_ERR("index out of bound!");
#endif
	DvecCompC sv(&v(i, 0, k), v.n1(), v.n0());
	return sv;
}


inline SvecInt cut1(MatInt_IO v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0())
		SLS_ERR("index out of bound!");
#endif
	SvecInt sv(&v(i, 0), v.n1());
	return sv;
}

inline SvecIntC cut1(MatInt_I v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0())
		SLS_ERR("index out of bound!");
#endif
	SvecIntC sv(&v(i, 0), v.n1());
	return sv;
}

inline DvecInt cut1(ScmatInt_IO v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0())
		SLS_ERR("index out of bound!");
#endif
	DvecInt sv(&v(i, 0), v.n1(), v.n0());
	return sv;
}

inline DvecIntC cut1(ScmatInt_I v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0())
		SLS_ERR("index out of bound!");
#endif
	DvecIntC sv(&v(i, 0), v.n1(), v.n0());
	return sv;
}

inline DvecInt cut1(CmatInt_IO v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0())
		SLS_ERR("index out of bound!");
#endif
	DvecInt sv(&v(i, 0), v.n1(), v.n0());
	return sv;
}

inline DvecIntC cut1(CmatInt_I v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0())
		SLS_ERR("index out of bound!");
#endif
	DvecIntC sv(&v(i, 0), v.n1(), v.n0());
	return sv;
}


inline DvecLlong cut1(CmatLlong_IO v, Long_I i, Long_I j, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0() || j < 0 || j + N2 > v.n1())
		SLS_ERR("out of bound!");
#endif
	DvecLlong sv(&v(i, j), N2, v.n0());
	return sv;
}

inline DvecLlongC cut1(CmatLlong_I v, Long_I i, Long_I j, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0() || j < 0 || j + N2 > v.n1())
		SLS_ERR("out of bound!");
#endif
	DvecLlongC sv(&v(i, j), N2, v.n0());
	return sv;
}

inline DvecComp cut1(CmatComp_IO v, Long_I i, Long_I j, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0() || j < 0 || j + N2 > v.n1())
		SLS_ERR("out of bound!");
#endif
	DvecComp sv(&v(i, j), N2, v.n0());
	return sv;
}

inline DvecCompC cut1(CmatComp_I v, Long_I i, Long_I j, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0() || j < 0 || j + N2 > v.n1())
		SLS_ERR("out of bound!");
#endif
	DvecCompC sv(&v(i, j), N2, v.n0());
	return sv;
}


inline DvecLlong cut1(ScmatLlong_IO v, Long_I i, Long_I j, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0() || j < 0 || j + N2 > v.n1())
		SLS_ERR("out of bound!");
#endif
	DvecLlong sv(&v(i, j), N2, v.n0());
	return sv;
}

inline DvecLlongC cut1(ScmatLlong_I v, Long_I i, Long_I j, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0() || j < 0 || j + N2 > v.n1())
		SLS_ERR("out of bound!");
#endif
	DvecLlongC sv(&v(i, j), N2, v.n0());
	return sv;
}

inline DvecComp cut1(ScmatComp_IO v, Long_I i, Long_I j, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0() || j < 0 || j + N2 > v.n1())
		SLS_ERR("out of bound!");
#endif
	DvecComp sv(&v(i, j), N2, v.n0());
	return sv;
}

inline DvecCompC cut1(ScmatComp_I v, Long_I i, Long_I j, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0() || j < 0 || j + N2 > v.n1())
		SLS_ERR("out of bound!");
#endif
	DvecCompC sv(&v(i, j), N2, v.n0());
	return sv;
}



inline DvecDoub cut2(Cmat3Doub_IO v, Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0() || j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	DvecDoub sv(&v(i, j, 0), v.n2(), v.n0()*v.n1());
	return sv;
}

inline DvecDoubC cut2(Cmat3Doub_I v, Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0() || j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	DvecDoubC sv(&v(i, j, 0), v.n2(), v.n0()*v.n1());
	return sv;
}


inline DvecComp cut2(Cmat3Comp_IO v, Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0() || j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	DvecComp sv(&v(i, j, 0), v.n2(), v.n0()*v.n1());
	return sv;
}

inline DvecCompC cut2(Cmat3Comp_I v, Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0() || j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	DvecCompC sv(&v(i, j, 0), v.n2(), v.n0()*v.n1());
	return sv;
}


inline DvecDoub cut2(Scmat3Doub_IO v, Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0() || j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	DvecDoub sv(&v(i, j, 0), v.n2(), v.n0()*v.n1());
	return sv;
}

inline DvecDoubC cut2(Scmat3Doub_I v, Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0() || j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	DvecDoubC sv(&v(i, j, 0), v.n2(), v.n0()*v.n1());
	return sv;
}


inline DvecComp cut2(Scmat3Comp_IO v, Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0() || j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	DvecComp sv(&v(i, j, 0), v.n2(), v.n0()*v.n1());
	return sv;
}

inline DvecCompC cut2(Scmat3Comp_I v, Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0() || j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	DvecCompC sv(&v(i, j, 0), v.n2(), v.n0()*v.n1());
	return sv;
}



inline ScmatDoub cut01(Cmat3Doub_IO v, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (k < 0 || k >= v.n2())
		SLS_ERR("index out of bound!");
#endif
	ScmatDoub sv(&v(0, 0, k), v.n0(), v.n1());
	return sv;
}

inline ScmatDoubC cut01(Cmat3Doub_I v, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (k < 0 || k >= v.n2())
		SLS_ERR("index out of bound!");
#endif
	ScmatDoubC sv(&v(0, 0, k), v.n0(), v.n1());
	return sv;
}

inline ScmatComp cut01(Cmat3Comp_IO v, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (k < 0 || k >= v.n2())
		SLS_ERR("index out of bound!");
#endif
	ScmatComp sv(&v(0, 0, k), v.n0(), v.n1());
	return sv;
}

inline ScmatCompC cut01(Cmat3Comp_I v, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (k < 0 || k >= v.n2())
		SLS_ERR("index out of bound!");
#endif
	ScmatCompC sv(&v(0, 0, k), v.n0(), v.n1());
	return sv;
}

inline ScmatInt cut01(Cmat3Int_IO v, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (k < 0 || k >= v.n2())
		SLS_ERR("index out of bound!");
#endif
	ScmatInt sv(&v(0, 0, k), v.n0(), v.n1());
	return sv;
}

inline ScmatIntC cut01(Cmat3Int_I v, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (k < 0 || k >= v.n2())
		SLS_ERR("index out of bound!");
#endif
	ScmatIntC sv(&v(0, 0, k), v.n0(), v.n1());
	return sv;
}



inline ScmatInt cut01(Cmat4Int_IO v, Long_I k, Long_I l)
{
#ifdef SLS_CHECK_BOUNDS
	if (k < 0 || k >= v.n2() || l < 0 || l >= v.n3())
		SLS_ERR("index out of bound!");
#endif
	ScmatInt sv(&v(0, 0, k, l), v.n0(), v.n1());
	return sv;
}

inline ScmatIntC cut01(Cmat4Int_I v, Long_I k, Long_I l)
{
#ifdef SLS_CHECK_BOUNDS
	if (k < 0 || k >= v.n2() || l < 0 || l >= v.n3())
		SLS_ERR("index out of bound!");
#endif
	ScmatIntC sv(&v(0, 0, k, l), v.n0(), v.n1());
	return sv;
}

inline ScmatDoub cut01(Cmat4Doub_IO v, Long_I k, Long_I l)
{
#ifdef SLS_CHECK_BOUNDS
	if (k < 0 || k >= v.n2() || l < 0 || l >= v.n3())
		SLS_ERR("index out of bound!");
#endif
	ScmatDoub sv(&v(0, 0, k, l), v.n0(), v.n1());
	return sv;
}

inline ScmatDoubC cut01(Cmat4Doub_I v, Long_I k, Long_I l)
{
#ifdef SLS_CHECK_BOUNDS
	if (k < 0 || k >= v.n2() || l < 0 || l >= v.n3())
		SLS_ERR("index out of bound!");
#endif
	ScmatDoubC sv(&v(0, 0, k, l), v.n0(), v.n1());
	return sv;
}


inline ScmatDoub cut01(Scmat3Doub_IO v, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (k < 0 || k >= v.n2())
		SLS_ERR("index out of bound!");
#endif
	ScmatDoub sv(&v(0, 0, k), v.n0(), v.n1());
	return sv;
}

inline ScmatDoubC cut01(Scmat3Doub_I v, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (k < 0 || k >= v.n2())
		SLS_ERR("index out of bound!");
#endif
	ScmatDoubC sv(&v(0, 0, k), v.n0(), v.n1());
	return sv;
}

inline ScmatComp cut01(Scmat3Comp_IO v, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (k < 0 || k >= v.n2())
		SLS_ERR("index out of bound!");
#endif
	ScmatComp sv(&v(0, 0, k), v.n0(), v.n1());
	return sv;
}

inline ScmatCompC cut01(Scmat3Comp_I v, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (k < 0 || k >= v.n2())
		SLS_ERR("index out of bound!");
#endif
	ScmatCompC sv(&v(0, 0, k), v.n0(), v.n1());
	return sv;
}

inline ScmatInt cut01(Scmat3Int_IO v, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (k < 0 || k >= v.n2())
		SLS_ERR("index out of bound!");
#endif
	ScmatInt sv(&v(0, 0, k), v.n0(), v.n1());
	return sv;
}

inline ScmatIntC cut01(Scmat3Int_I v, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (k < 0 || k >= v.n2())
		SLS_ERR("index out of bound!");
#endif
	ScmatIntC sv(&v(0, 0, k), v.n0(), v.n1());
	return sv;
}



inline ScmatInt cut01(Scmat4Int_IO v, Long_I k, Long_I l)
{
#ifdef SLS_CHECK_BOUNDS
	if (k < 0 || k >= v.n2() || l < 0 || l >= v.n3())
		SLS_ERR("index out of bound!");
#endif
	ScmatInt sv(&v(0, 0, k, l), v.n0(), v.n1());
	return sv;
}

inline ScmatIntC cut01(Scmat4Int_I v, Long_I k, Long_I l)
{
#ifdef SLS_CHECK_BOUNDS
	if (k < 0 || k >= v.n2() || l < 0 || l >= v.n3())
		SLS_ERR("index out of bound!");
#endif
	ScmatIntC sv(&v(0, 0, k, l), v.n0(), v.n1());
	return sv;
}

inline ScmatDoub cut01(Scmat4Doub_IO v, Long_I k, Long_I l)
{
#ifdef SLS_CHECK_BOUNDS
	if (k < 0 || k >= v.n2() || l < 0 || l >= v.n3())
		SLS_ERR("index out of bound!");
#endif
	ScmatDoub sv(&v(0, 0, k, l), v.n0(), v.n1());
	return sv;
}

inline ScmatDoubC cut01(Scmat4Doub_I v, Long_I k, Long_I l)
{
#ifdef SLS_CHECK_BOUNDS
	if (k < 0 || k >= v.n2() || l < 0 || l >= v.n3())
		SLS_ERR("index out of bound!");
#endif
	ScmatDoubC sv(&v(0, 0, k, l), v.n0(), v.n1());
	return sv;
}



inline ScmatDoub cut01(Cmat3Doub_IO v, Long_I j, Long_I N2, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j + N2 > v.n1() || k < 0 || k >= v.n2())
		SLS_ERR("index out of bound!");
#endif
	ScmatDoub sv(&v(0, j, k), v.n0(), N2);
	return sv;
}

inline ScmatDoubC cut01(Cmat3Doub_I v, Long_I j, Long_I N2, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j + N2 > v.n1() || k < 0 || k >= v.n2())
		SLS_ERR("index out of bound!");
#endif
	ScmatDoubC sv(&v(0, j, k), v.n0(), N2);
	return sv;
}


inline ScmatComp cut01(Cmat3Comp_IO v, Long_I j, Long_I N2, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j + N2 > v.n1() || k < 0 || k >= v.n2())
		SLS_ERR("index out of bound!");
#endif
	ScmatComp sv(&v(0, j, k), v.n0(), N2);
	return sv;
}

inline ScmatCompC cut01(Cmat3Comp_I v, Long_I j, Long_I N2, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j + N2 > v.n1() || k < 0 || k >= v.n2())
		SLS_ERR("index out of bound!");
#endif
	ScmatCompC sv(&v(0, j, k), v.n0(), N2);
	return sv;
}


inline ScmatDoub cut01(Scmat3Doub_IO v, Long_I j, Long_I N2, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j + N2 > v.n1() || k < 0 || k >= v.n2())
		SLS_ERR("index out of bound!");
#endif
	ScmatDoub sv(&v(0, j, k), v.n0(), N2);
	return sv;
}

inline ScmatDoubC cut01(Scmat3Doub_I v, Long_I j, Long_I N2, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j + N2 > v.n1() || k < 0 || k >= v.n2())
		SLS_ERR("index out of bound!");
#endif
	ScmatDoubC sv(&v(0, j, k), v.n0(), N2);
	return sv;
}


inline ScmatComp cut01(Scmat3Comp_IO v, Long_I j, Long_I N2, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j + N2 > v.n1() || k < 0 || k >= v.n2())
		SLS_ERR("index out of bound!");
#endif
	ScmatComp sv(&v(0, j, k), v.n0(), N2);
	return sv;
}

inline ScmatCompC cut01(Scmat3Comp_I v, Long_I j, Long_I N2, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j + N2 > v.n1() || k < 0 || k >= v.n2())
		SLS_ERR("index out of bound!");
#endif
	ScmatCompC sv(&v(0, j, k), v.n0(), N2);
	return sv;
}



inline DcmatDoub cut01(Cmat3Doub_IO v, Long_I i, Long_I N1, Long_I j, Long_I N2, Long_I k)
{
	DcmatDoub sv(&v(i, j, k), N1, N2, v.n0());
	return sv;
}

inline DcmatDoubC cut01(Cmat3Doub_I v, Long_I i, Long_I N1, Long_I j, Long_I N2, Long_I k)
{
	DcmatDoubC sv(&v(i, j, k), N1, N2, v.n0());
	return sv;
}


inline DcmatComp cut01(Cmat3Comp_IO v, Long_I i, Long_I N1, Long_I j, Long_I N2, Long_I k)
{
	DcmatComp sv(&v(i, j, k), N1, N2, v.n0());
	return sv;
}

inline DcmatCompC cut01(Cmat3Comp_I v, Long_I i, Long_I N1, Long_I j, Long_I N2, Long_I k)
{
	DcmatCompC sv(&v(i, j, k), N1, N2, v.n0());
	return sv;
}


inline DcmatDoub cut01(Scmat3Doub_IO v, Long_I i, Long_I N1, Long_I j, Long_I N2, Long_I k)
{
	DcmatDoub sv(&v(i, j, k), N1, N2, v.n0());
	return sv;
}

inline DcmatDoubC cut01(Scmat3Doub_I v, Long_I i, Long_I N1, Long_I j, Long_I N2, Long_I k)
{
	DcmatDoubC sv(&v(i, j, k), N1, N2, v.n0());
	return sv;
}


inline DcmatComp cut01(Scmat3Comp_IO v, Long_I i, Long_I N1, Long_I j, Long_I N2, Long_I k)
{
	DcmatComp sv(&v(i, j, k), N1, N2, v.n0());
	return sv;
}

inline DcmatCompC cut01(Scmat3Comp_I v, Long_I i, Long_I N1, Long_I j, Long_I N2, Long_I k)
{
	DcmatCompC sv(&v(i, j, k), N1, N2, v.n0());
	return sv;
}


} // namespace slisc
