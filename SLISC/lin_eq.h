#pragma once
#include "compare.h"
#include "band_arith.h"

#ifdef SLS_USE_LAPACKE
namespace slisc {
//not the most accurate, see also ?gerfs
inline void inv_mat(CmatDoub_IO A)
{
#ifdef SLS_CHECK_SHAPE
    if (A.n1() != A.n2())
        SLS_ERR("wrong shape!");
#endif
    Int N = (Int)A.n1();
    VecInt ipiv(N);
    LAPACKE_dgetrf(LAPACK_COL_MAJOR, N, N, A.ptr(), N, ipiv.ptr());
    LAPACKE_dgetri(LAPACK_COL_MAJOR, N, A.ptr(), N, ipiv.ptr());
}

inline void inv_mat(ScmatDoub_IO A)
{
#ifdef SLS_CHECK_SHAPE
    if (A.n1() != A.n2())
        SLS_ERR("wrong shape!");
#endif
    Int N = (Int)A.n1();
    VecInt ipiv(N);
    LAPACKE_dgetrf(LAPACK_COL_MAJOR, N, N, A.ptr(), N, ipiv.ptr());
    LAPACKE_dgetri(LAPACK_COL_MAJOR, N, A.ptr(), N, ipiv.ptr());
}


// solution to linear system with general coefficient matrix A and multiple right-hand sides.
inline void lin_eq(CmatDoub_IO x, CmatDoub_I a)
{
#ifdef SLS_CHECK_SHAPE
	if (a.n1() != a.n2() || a.n2() != x.n1())
		SLS_ERR("wrong shape!");
#endif
	static CmatDoub a1(a.n1(), a.n2());
	static VecInt ipiv(a.n1());
	if (!shape_cmp(a1, a))
		a1.resize(a.n1(), a.n2());
	copy(a1, a);
	if (a.n1() > ipiv.size())
		ipiv.resize(a.n1());
	Int lda = a1.n1();
	Int ldx = x.n1(), nrhs = x.n2();

	Int ret = LAPACKE_dgesv(LAPACK_COL_MAJOR, a1.n1(), nrhs, a1.ptr(), lda, ipiv.ptr(), x.ptr(), ldx);
	if (ret != 0) {
		cout << "LAPACK returned " << ret << endl;
		SLS_ERR("something wrong!");
	}
}

inline void lin_eq(ScmatDoub_IO x, CmatDoub_I a)
{
#ifdef SLS_CHECK_SHAPE
	if (a.n1() != a.n2() || a.n2() != x.n1())
		SLS_ERR("wrong shape!");
#endif
	static CmatDoub a1(a.n1(), a.n2());
	static VecInt ipiv(a.n1());
	if (!shape_cmp(a1, a))
		a1.resize(a.n1(), a.n2());
	copy(a1, a);
	if (a.n1() > ipiv.size())
		ipiv.resize(a.n1());
	Int lda = a1.n1();
	Int ldx = x.n1(), nrhs = x.n2();

	Int ret = LAPACKE_dgesv(LAPACK_COL_MAJOR, a1.n1(), nrhs, a1.ptr(), lda, ipiv.ptr(), x.ptr(), ldx);
	if (ret != 0) {
		cout << "LAPACK returned " << ret << endl;
		SLS_ERR("something wrong!");
	}
}

inline void lin_eq(ScmatDoub_IO x, ScmatDoub_I a)
{
#ifdef SLS_CHECK_SHAPE
	if (a.n1() != a.n2() || a.n2() != x.n1())
		SLS_ERR("wrong shape!");
#endif
	static CmatDoub a1(a.n1(), a.n2());
	static VecInt ipiv(a.n1());
	if (!shape_cmp(a1, a))
		a1.resize(a.n1(), a.n2());
	copy(a1, a);
	if (a.n1() > ipiv.size())
		ipiv.resize(a.n1());
	Int lda = a1.n1();
	Int ldx = x.n1(), nrhs = x.n2();

	Int ret = LAPACKE_dgesv(LAPACK_COL_MAJOR, a1.n1(), nrhs, a1.ptr(), lda, ipiv.ptr(), x.ptr(), ldx);
	if (ret != 0) {
		cout << "LAPACK returned " << ret << endl;
		SLS_ERR("something wrong!");
	}
}

inline void lin_eq(VecDoub_IO x, CmatDoub_I a)
{
#ifdef SLS_CHECK_SHAPE
	if (a.n1() != a.n2() || a.n2() != x.size())
		SLS_ERR("wrong shape!");
#endif
	static CmatDoub a1(a.n1(), a.n2());
	static VecInt ipiv(a.n1());
	if (!shape_cmp(a1, a))
		a1.resize(a.n1(), a.n2());
	copy(a1, a);
	if (a.n1() > ipiv.size())
		ipiv.resize(a.n1());
	Int lda = a1.n1();
	Int ldx = x.size(), nrhs = 1;

	Int ret = LAPACKE_dgesv(LAPACK_COL_MAJOR, a1.n1(), nrhs, a1.ptr(), lda, ipiv.ptr(), x.ptr(), ldx);
	if (ret != 0) {
		cout << "LAPACK returned " << ret << endl;
		SLS_ERR("something wrong!");
	}
}

inline void lin_eq(SvecDoub_IO x, CmatDoub_I a)
{
#ifdef SLS_CHECK_SHAPE
	if (a.n1() != a.n2() || a.n2() != x.size())
		SLS_ERR("wrong shape!");
#endif
	static CmatDoub a1(a.n1(), a.n2());
	static VecInt ipiv(a.n1());
	if (!shape_cmp(a1, a))
		a1.resize(a.n1(), a.n2());
	copy(a1, a);
	if (a.n1() > ipiv.size())
		ipiv.resize(a.n1());
	Int lda = a1.n1();
	Int ldx = x.size(), nrhs = 1;

	Int ret = LAPACKE_dgesv(LAPACK_COL_MAJOR, a1.n1(), nrhs, a1.ptr(), lda, ipiv.ptr(), x.ptr(), ldx);
	if (ret != 0) {
		cout << "LAPACK returned " << ret << endl;
		SLS_ERR("something wrong!");
	}
}

inline void lin_eq(VecComp_IO x, CmatComp_I a)
{
#ifdef SLS_CHECK_SHAPE
	if (a.n1() != a.n2() || a.n2() != x.size())
		SLS_ERR("wrong shape!");
#endif
	static CmatComp a1(a.n1(), a.n2());
	static VecInt ipiv(a.n1());
	if (!shape_cmp(a1, a))
		a1.resize(a.n1(), a.n2());
	copy(a1, a);
	if (a.n1() > ipiv.size())
		ipiv.resize(a.n1());
	Int lda = a1.n1();
	Int ldx = x.size(), nrhs = 1;

	Int ret = LAPACKE_zgesv(LAPACK_COL_MAJOR, a1.n1(), nrhs, (double _Complex*)a1.ptr(), lda, ipiv.ptr(), (double _Complex*)x.ptr(), ldx);
	if (ret != 0) {
		cout << "LAPACK returned " << ret << endl;
		SLS_ERR("something wrong!");
	}
}


// solution to linear system with band coefficient matrix A and multiple right-hand sides.
inline void lin_eq(VecDoub_IO x, CbandDoub_I a)
{
#ifdef SLS_CHECK_SHAPE
	if (a.n1() != a.n2() || a.n2() != x.size())
		SLS_ERR("wrong shape!");
#endif
	static CbandDoub a1(a.n1(), a.n2(), a.nup(), a.nlow(), a.nup() + 2*a.nlow() + 1, a.nlow() + a.nup());
	static VecInt ipiv(a.n1());
	if (a1.lda() < a.nup() + 2*a.nlow() + 1 || a1.n2() != a.n2())
		a1.resize(a.nup() + 2*a.nlow() + 1, a.n2());
	a1.shift(a.nlow() + a.nup()); copy(a1, a);
	if (a.n1() > ipiv.size())
		ipiv.resize(a.n1());

	Int lda = a1.lda();
	Int ldx = x.size(), nrhs = 1;

	Int ret = LAPACKE_dgbsv(LAPACK_COL_MAJOR, a1.n1(), a1.nlow() , a1.nup(), nrhs, a1.ptr(), lda, ipiv.ptr(), x.ptr(), ldx);
	if (ret != 0) {
		cout << "LAPACK returned " << ret << endl;
		SLS_ERR("something wrong!");
	}
}

inline void lin_eq(VecComp_IO x, CbandComp_I a)
{
#ifdef SLS_CHECK_SHAPE
	if (a.n1() != a.n2() || a.n2() != x.size())
		SLS_ERR("wrong shape!");
#endif
	static CbandComp a1(a.n1(), a.n2(), a.nup(), a.nlow(), a.nup() + 2*a.nlow() + 1, a.nlow() + a.nup());
	static VecInt ipiv(a.n1());
	if (a1.lda() < a.nup() + 2*a.nlow() + 1 || a1.n2() != a.n2())
		a1.resize(a.nup() + 2*a.nlow() + 1, a.n2());
	a1.shift(a.nlow() + a.nup()); copy(a1, a);
	if (a.n1() > ipiv.size())
		ipiv.resize(a.n1());

	Int lda = a1.lda();
	Int ldx = x.size(), nrhs = 1;

	Int ret = LAPACKE_zgbsv(LAPACK_COL_MAJOR, a1.n1(), a1.nlow() , a1.nup(), nrhs, (double _Complex*)a1.ptr(), lda, ipiv.ptr(), (double _Complex*)x.ptr(), ldx);
	if (ret != 0) {
		cout << "LAPACK returned " << ret << endl;
		SLS_ERR("something wrong!");
	}
}


// solution to linear system with band coefficient matrix A and multiple right-hand sides.
// matrix will be replaced with LU decomp
// use the following to generate input data
// VecInt ipiv(a.n1());
// @Ta@ a1(a.n1(), a.n2(), a.nup(), a.nlow(), a.nup() + 2*a.nlow() + 1, a.nlow() + a.nup());
// copy(a1, a);
inline void lin_eq(VecDoub_IO x, CbandDoub_IO a1, VecInt_IO ipiv)
{
#ifdef SLS_CHECK_SHAPE
	if (a1.n1() != a1.n2() || a1.n2() != x.size())
		SLS_ERR("wrong shape!");
#endif
	Int lda = a1.lda();
	Int ldx = x.size(), nrhs = 1;
	Int ret = LAPACKE_dgbsv(LAPACK_COL_MAJOR, a1.n1(), a1.nlow() , a1.nup(), nrhs, a1.ptr(), lda, ipiv.ptr(), x.ptr(), ldx);
	if (ret != 0) {
		cout << "LAPACK returned " << ret << endl;
		SLS_ERR("something wrong!");
	}
}

inline void lin_eq(VecComp_IO x, CbandComp_IO a1, VecInt_IO ipiv)
{
#ifdef SLS_CHECK_SHAPE
	if (a1.n1() != a1.n2() || a1.n2() != x.size())
		SLS_ERR("wrong shape!");
#endif
	Int lda = a1.lda();
	Int ldx = x.size(), nrhs = 1;
	Int ret = LAPACKE_zgbsv(LAPACK_COL_MAJOR, a1.n1(), a1.nlow() , a1.nup(), nrhs, (double _Complex*)a1.ptr(), lda, ipiv.ptr(), (double _Complex*)x.ptr(), ldx);
	if (ret != 0) {
		cout << "LAPACK returned " << ret << endl;
		SLS_ERR("something wrong!");
	}
}

inline void lin_eq(ScmatComp_IO x, CbandComp_IO a1, SvecInt_IO ipiv)
{
#ifdef SLS_CHECK_SHAPE
	if (a1.n1() != a1.n2() || a1.n2() != x.n1())
		SLS_ERR("wrong shape!");
#endif
	Int lda = a1.lda();
	Int ldx = x.n1(), nrhs = x.n2();
	Int ret = LAPACKE_zgbsv(LAPACK_COL_MAJOR, a1.n1(), a1.nlow() , a1.nup(), nrhs, (double _Complex*)a1.ptr(), lda, ipiv.ptr(), (double _Complex*)x.ptr(), ldx);
	if (ret != 0) {
		cout << "LAPACK returned " << ret << endl;
		SLS_ERR("something wrong!");
	}
}

} // namespace slisc
#endif
