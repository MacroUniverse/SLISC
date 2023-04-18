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
#include "../dense/Dcmat.h"
#include "../dense/Jcmat3.h"

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

inline SvecIntC cut(VecInt_I v, Long_I start, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (start < 0 || start + N > v.size())
		SLS_ERR("index out of bound!");
#endif
	SvecIntC sli(&v[start], N);
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

inline SvecDoubC cut(VecDoub_I v, Long_I start, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (start < 0 || start + N > v.size())
		SLS_ERR("index out of bound!");
#endif
	SvecDoubC sli(&v[start], N);
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

inline SvecCompC cut(VecComp_I v, Long_I start, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (start < 0 || start + N > v.size())
		SLS_ERR("index out of bound!");
#endif
	SvecCompC sli(&v[start], N);
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

inline DcmatDoubC cut(CmatDoub_I v,
	Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (start1 < 0 || start1 + N1 > v.n0() ||
			start2 < 0 || start2 + N2 > v.n1())
		SLS_ERR("index out of bound!");
#endif
	DcmatDoubC sli(&v(start1, start2), N1, N2, v.n0());
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

inline ScmatDoubC cut(CmatDoub_I v, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (start2 < 0 || start2 + N2 > v.n1())
		SLS_ERR("index out of bound!");
#endif
	ScmatDoubC sli(&v(0, start2), v.n0(), N2);
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

inline DcmatCompC cut(CmatComp_I v,
	Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (start1 < 0 || start1 + N1 > v.n0() ||
			start2 < 0 || start2 + N2 > v.n1())
		SLS_ERR("index out of bound!");
#endif
	DcmatCompC sli(&v(start1, start2), N1, N2, v.n0());
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

inline ScmatCompC cut(CmatComp_I v, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (start2 < 0 || start2 + N2 > v.n1())
		SLS_ERR("index out of bound!");
#endif
	ScmatCompC sli(&v(0, start2), v.n0(), N2);
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

inline DcmatDoubC cut(ScmatDoub_I v,
	Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (start1 < 0 || start1 + N1 > v.n0() ||
			start2 < 0 || start2 + N2 > v.n1())
		SLS_ERR("index out of bound!");
#endif
	DcmatDoubC sli(&v(start1, start2), N1, N2, v.n0());
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

inline DcmatIntC cut(CmatInt_I v,
	Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (start1 < 0 || start1 + N1 > v.n0() ||
			start2 < 0 || start2 + N2 > v.n1())
		SLS_ERR("index out of bound!");
#endif
	DcmatIntC sli(&v(start1, start2), N1, N2, v.n0());
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

inline ScmatIntC cut(CmatInt_I v, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (start2 < 0 || start2 + N2 > v.n1())
		SLS_ERR("index out of bound!");
#endif
	ScmatIntC sli(&v(0, start2), v.n0(), N2);
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

inline DcmatLlongC cut(CmatLlong_I v,
	Long_I start1, Long_I N1, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (start1 < 0 || start1 + N1 > v.n0() ||
			start2 < 0 || start2 + N2 > v.n1())
		SLS_ERR("index out of bound!");
#endif
	DcmatLlongC sli(&v(start1, start2), N1, N2, v.n0());
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

inline ScmatLlongC cut(CmatLlong_I v, Long_I start2, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (start2 < 0 || start2 + N2 > v.n1())
		SLS_ERR("index out of bound!");
#endif
	ScmatLlongC sli(&v(0, start2), v.n0(), N2);
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

inline Jcmat3DoubC cut(Cmat3Doub_I v, Long_I start1, Long_I N1, Long_I start2, Long_I N2, Long_I start3, Long_I N3)
{
#ifdef SLS_CHECK_BOUNDS
	if (start1 < 0 || start1 + N1 > v.n0() || start2 < 0 || start2 + N2 > v.n1() || start3 < 0 || start3 + N3 > v.n2())
		SLS_ERR("index out of bound!");
#endif
	Jcmat3DoubC sli(&v(start1, start2, start3), N1, N2, N3, 1, v.n0(), v.n0()*v.n1());
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

inline Jcmat3CompC cut(Cmat3Comp_I v, Long_I start1, Long_I N1, Long_I start2, Long_I N2, Long_I start3, Long_I N3)
{
#ifdef SLS_CHECK_BOUNDS
	if (start1 < 0 || start1 + N1 > v.n0() || start2 < 0 || start2 + N2 > v.n1() || start3 < 0 || start3 + N3 > v.n2())
		SLS_ERR("index out of bound!");
#endif
	Jcmat3CompC sli(&v(start1, start2, start3), N1, N2, N3, 1, v.n0(), v.n0()*v.n1());
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

inline SvecDoubC cut(SvecDoub_I v, Long_I start, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (start < 0 || start + N > v.size())
		SLS_ERR("index out of bound!");
#endif
	SvecDoubC sli(&v[start], N);
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

inline SvecCompC cut(SvecComp_I v, Long_I start, Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (start < 0 || start + N > v.size())
		SLS_ERR("index out of bound!");
#endif
	SvecCompC sli(&v[start], N);
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

inline DvecIntC cut0(MatInt_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	DvecIntC sli(&v(0, j), v.n0(), v.n1());
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

inline SvecIntC cut0(CmatInt_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	SvecIntC sli(&v(0, j), v.n0());
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

inline SvecLlongC cut0(CmatLlong_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	SvecLlongC sli(&v(0, j), v.n0());
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

inline SvecDoubC cut0(CmatDoub_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	SvecDoubC sli(&v(0, j), v.n0());
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

inline SvecCompC cut0(CmatComp_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	SvecCompC sli(&v(0, j), v.n0());
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

inline SvecIntC cut0(ScmatInt_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	SvecIntC sli(&v(0, j), v.n0());
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

inline SvecLlongC cut0(ScmatLlong_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	SvecLlongC sli(&v(0, j), v.n0());
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

inline SvecDoubC cut0(ScmatDoub_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	SvecDoubC sli(&v(0, j), v.n0());
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

inline SvecCompC cut0(ScmatComp_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	SvecCompC sli(&v(0, j), v.n0());
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

inline SvecIntC cut0(DcmatInt_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	SvecIntC sli(&v(0, j), v.n0());
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

inline SvecLlongC cut0(DcmatLlong_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	SvecLlongC sli(&v(0, j), v.n0());
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

inline SvecDoubC cut0(DcmatDoub_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	SvecDoubC sli(&v(0, j), v.n0());
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

inline SvecCompC cut0(DcmatComp_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	SvecCompC sli(&v(0, j), v.n0());
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

inline SvecIntC cut0(Cmat3Int_I v, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1() || k < 0 || k >= v.n2())
		SLS_ERR("index out of bound!");
#endif
	SvecIntC sli(&v(0, j, k), v.n0());
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

inline SvecLlongC cut0(Cmat3Llong_I v, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1() || k < 0 || k >= v.n2())
		SLS_ERR("index out of bound!");
#endif
	SvecLlongC sli(&v(0, j, k), v.n0());
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

inline SvecDoubC cut0(Cmat3Doub_I v, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1() || k < 0 || k >= v.n2())
		SLS_ERR("index out of bound!");
#endif
	SvecDoubC sli(&v(0, j, k), v.n0());
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

inline SvecCompC cut0(Cmat3Comp_I v, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1() || k < 0 || k >= v.n2())
		SLS_ERR("index out of bound!");
#endif
	SvecCompC sli(&v(0, j, k), v.n0());
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

inline DvecDoubC cut0(MatDoub_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	DvecDoubC sli(&v(0, j), v.n0(), v.n1());
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

inline DvecCompC cut0(MatComp_I v, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	DvecCompC sli(&v(0, j), v.n0(), v.n1());
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

inline SvecIntC cut0(ScmatInt_I v, Long_I i, Long_I N1, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i + N1 > v.n0() || j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	SvecIntC sli(&v(i, j), N1);
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

inline SvecLlongC cut0(ScmatLlong_I v, Long_I i, Long_I N1, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i + N1 > v.n0() || j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	SvecLlongC sli(&v(i, j), N1);
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

inline SvecDoubC cut0(CmatDoub_I v, Long_I i, Long_I N1, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i + N1 > v.n0() || j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	SvecDoubC sli(&v(i, j), N1);
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

inline SvecCompC cut0(CmatComp_I v, Long_I i, Long_I N1, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i + N1 > v.n0() || j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	SvecCompC sli(&v(i, j), N1);
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

inline SvecDoubC cut0(ScmatDoub_I v, Long_I i, Long_I N1, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i + N1 > v.n0() || j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	SvecDoubC sli(&v(i, j), N1);
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

inline SvecCompC cut0(Cmat3Comp_I v, Long_I i, Long_I N1, Long_I j, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i + N1 > v.n0() || j < 0 || j >= v.n1() || k < 0 || k >= v.n2())
		SLS_ERR("index out of bound!");
#endif
	SvecCompC sli(&v(i, j, k), N1);
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

inline SvecCompC cut0(ScmatComp_I v, Long_I i, Long_I N1, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i + N1 > v.n0() || j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	SvecCompC sli(&v(i, j), N1);
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

inline DvecDoubC cut1(CmatDoub_I v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0())
		SLS_ERR("index out of bound!");
#endif
	DvecDoubC sli(&v(i, 0), v.n1(), v.n0());
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

inline DvecCompC cut1(CmatComp_I v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0())
		SLS_ERR("index out of bound!");
#endif
	DvecCompC sli(&v(i, 0), v.n1(), v.n0());
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

inline DvecCompC cut1(ScmatComp_I v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0())
		SLS_ERR("index out of bound!");
#endif
	DvecCompC sli(&v(i, 0), v.n1(), v.n0());
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

inline SvecIntC cut1(MatInt_I v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0())
		SLS_ERR("index out of bound!");
#endif
	SvecIntC sli(&v(i, 0), v.n1());
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

inline DvecLlongC cut1(CmatLlong_I v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0())
		SLS_ERR("index out of bound!");
#endif
	DvecLlongC sli(&v(i, 0), v.n1(), v.n0());
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

inline DvecCompC cut1(Cmat3Comp_I v, Long_I i, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0() || k < 0 || k >= v.n2())
		SLS_ERR("index out of bound!");
#endif
	DvecCompC sli(&v(i, 0, k), v.n1(), v.n0());
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

inline DvecIntC cut1(CmatInt_I v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0())
		SLS_ERR("index out of bound!");
#endif
	DvecIntC sli(&v(i, 0), v.n1(), v.n0());
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

inline DvecLlongC cut1(ScmatLlong_I v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0())
		SLS_ERR("index out of bound!");
#endif
	DvecLlongC sli(&v(i, 0), v.n1(), v.n0());
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

inline SvecDoubC cut1(MatDoub_I v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0())
		SLS_ERR("index out of bound!");
#endif
	SvecDoubC sli(&v(i, 0), v.n1());
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

inline SvecCompC cut1(MatComp_I v, Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0())
		SLS_ERR("index out of bound!");
#endif
	SvecCompC sli(&v(i, 0), v.n1());
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

inline DvecLlongC cut1(CmatLlong_I v, Long_I i, Long_I j, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0() || j < 0 || j + N2 > v.n1())
		SLS_ERR("out of bound!");
#endif
	DvecLlongC sli(&v(i, j), N2, v.n0());
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

inline DvecCompC cut1(CmatComp_I v, Long_I i, Long_I j, Long_I N2)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0() || j < 0 || j + N2 > v.n1())
		SLS_ERR("out of bound!");
#endif
	DvecCompC sli(&v(i, j), N2, v.n0());
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

inline DvecDoubC cut2(Cmat3Doub_I v, Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0() || j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	DvecDoubC sli(&v(i, j, 0), v.n2(), v.n0()*v.n1());
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

inline DvecCompC cut2(Cmat3Comp_I v, Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= v.n0() || j < 0 || j >= v.n1())
		SLS_ERR("index out of bound!");
#endif
	DvecCompC sli(&v(i, j, 0), v.n2(), v.n0()*v.n1());
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

inline ScmatCompC cut01(Cmat3Comp_I v, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (k < 0 || k >= v.n2())
		SLS_ERR("index out of bound!");
#endif
	ScmatCompC sli(&v(0, 0, k), v.n0(), v.n1());
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

inline ScmatIntC cut01(Cmat3Int_I v, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (k < 0 || k >= v.n2())
		SLS_ERR("index out of bound!");
#endif
	ScmatIntC sli(&v(0, 0, k), v.n0(), v.n1());
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

inline ScmatDoubC cut01(Cmat3Doub_I v, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (k < 0 || k >= v.n2())
		SLS_ERR("index out of bound!");
#endif
	ScmatDoubC sli(&v(0, 0, k), v.n0(), v.n1());
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

inline ScmatCompC cut01(Scmat3Comp_I v, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (k < 0 || k >= v.n2())
		SLS_ERR("index out of bound!");
#endif
	ScmatCompC sli(&v(0, 0, k), v.n0(), v.n1());
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

inline ScmatIntC cut01(Cmat4Int_I v, Long_I k, Long_I l)
{
#ifdef SLS_CHECK_BOUNDS
	if (k < 0 || k >= v.n2() || l < 0 || l >= v.n3())
		SLS_ERR("index out of bound!");
#endif
	ScmatIntC sli(&v(0, 0, k, l), v.n0(), v.n1());
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

inline ScmatDoubC cut01(Cmat4Doub_I v, Long_I k, Long_I l)
{
#ifdef SLS_CHECK_BOUNDS
	if (k < 0 || k >= v.n2() || l < 0 || l >= v.n3())
		SLS_ERR("index out of bound!");
#endif
	ScmatDoubC sli(&v(0, 0, k, l), v.n0(), v.n1());
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

inline ScmatDoubC cut01(Cmat3Doub_I v, Long_I j, Long_I N2, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j + N2 > v.n1() || k < 0 || k >= v.n2())
		SLS_ERR("index out of bound!");
#endif
	ScmatDoubC sli(&v(0, j, k), v.n0(), N2);
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

inline ScmatCompC cut01(Cmat3Comp_I v, Long_I j, Long_I N2, Long_I k)
{
#ifdef SLS_CHECK_BOUNDS
	if (j < 0 || j + N2 > v.n1() || k < 0 || k >= v.n2())
		SLS_ERR("index out of bound!");
#endif
	ScmatCompC sli(&v(0, j, k), v.n0(), N2);
	return sli;
}



inline DcmatDoub cut01(Cmat3Doub_IO v, Long_I i, Long_I N1, Long_I j, Long_I N2, Long_I k)
{
	DcmatDoub sli(&v(i, j, k), N1, N2, v.n0());
	return sli;
}

inline DcmatDoubC cut01(Cmat3Doub_I v, Long_I i, Long_I N1, Long_I j, Long_I N2, Long_I k)
{
	DcmatDoubC sli(&v(i, j, k), N1, N2, v.n0());
	return sli;
}


inline DcmatComp cut01(Cmat3Comp_IO v, Long_I i, Long_I N1, Long_I j, Long_I N2, Long_I k)
{
	DcmatComp sli(&v(i, j, k), N1, N2, v.n0());
	return sli;
}

inline DcmatCompC cut01(Cmat3Comp_I v, Long_I i, Long_I N1, Long_I j, Long_I N2, Long_I k)
{
	DcmatCompC sli(&v(i, j, k), N1, N2, v.n0());
	return sli;
}


} // namespace slisc
