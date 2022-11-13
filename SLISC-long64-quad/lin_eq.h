#pragma once
#include "compare.h"
#include "band_arith.h"

#ifdef SLS_USE_LAPACKE
namespace slisc {
//not the most accurate, see also ?gerfs
inline void inv_mat(CmatDoub_IO A)
{
#ifdef SLS_CHECK_SHAPES
	if (A.n0() != A.n1())
	    SLS_ERR("wrong shape!");
#endif
	Long N = A.n0();
	VecLong ipiv(N);
	LAPACKE_dgetrf(LAPACK_COL_MAJOR, N, N, A.p(), N, ipiv.p());
	LAPACKE_dgetri(LAPACK_COL_MAJOR, N, A.p(), N, ipiv.p());
}

inline void inv_mat(ScmatDoub_IO A)
{
#ifdef SLS_CHECK_SHAPES
	if (A.n0() != A.n1())
	    SLS_ERR("wrong shape!");
#endif
	Long N = A.n0();
	VecLong ipiv(N);
	LAPACKE_dgetrf(LAPACK_COL_MAJOR, N, N, A.p(), N, ipiv.p());
	LAPACKE_dgetri(LAPACK_COL_MAJOR, N, A.p(), N, ipiv.p());
}


// solution to linear system with general coefficient matrix A and multiple right-hand sides.
// ####### Not Thread Safe ######
inline void lin_eq(CmatDoub_IO x, CmatDoub_I a)
{
#ifdef SLS_CHECK_SHAPES
	if (a.n0() != a.n1() || a.n1() != x.n0())
	    SLS_ERR("wrong shape!");
#endif
	static CmatDoub a1(a.n0(), a.n1());
	static VecLong ipiv(a.n0());
	if (!shape_cmp(a1, a))
	    a1.resize(a.n0(), a.n1());
	copy(a1, a);
	if (a.n0() > ipiv.size())
	    ipiv.resize(a.n0());
	Long lda = a1.n0();
	Long ldx = x.n0(), nrhs = x.n1();

	Long ret = LAPACKE_dgesv(LAPACK_COL_MAJOR, a1.n0(), nrhs, a1.p(), lda, ipiv.p(), x.p(), ldx);
	if (ret != 0) {
	    cout << "LAPACK returned " << ret << endl;
	    SLS_ERR("something wrong!");
	}
}

inline void lin_eq(ScmatDoub_IO x, CmatDoub_I a)
{
#ifdef SLS_CHECK_SHAPES
	if (a.n0() != a.n1() || a.n1() != x.n0())
	    SLS_ERR("wrong shape!");
#endif
	static CmatDoub a1(a.n0(), a.n1());
	static VecLong ipiv(a.n0());
	if (!shape_cmp(a1, a))
	    a1.resize(a.n0(), a.n1());
	copy(a1, a);
	if (a.n0() > ipiv.size())
	    ipiv.resize(a.n0());
	Long lda = a1.n0();
	Long ldx = x.n0(), nrhs = x.n1();

	Long ret = LAPACKE_dgesv(LAPACK_COL_MAJOR, a1.n0(), nrhs, a1.p(), lda, ipiv.p(), x.p(), ldx);
	if (ret != 0) {
	    cout << "LAPACK returned " << ret << endl;
	    SLS_ERR("something wrong!");
	}
}

inline void lin_eq(ScmatDoub_IO x, ScmatDoub_I a)
{
#ifdef SLS_CHECK_SHAPES
	if (a.n0() != a.n1() || a.n1() != x.n0())
	    SLS_ERR("wrong shape!");
#endif
	static CmatDoub a1(a.n0(), a.n1());
	static VecLong ipiv(a.n0());
	if (!shape_cmp(a1, a))
	    a1.resize(a.n0(), a.n1());
	copy(a1, a);
	if (a.n0() > ipiv.size())
	    ipiv.resize(a.n0());
	Long lda = a1.n0();
	Long ldx = x.n0(), nrhs = x.n1();

	Long ret = LAPACKE_dgesv(LAPACK_COL_MAJOR, a1.n0(), nrhs, a1.p(), lda, ipiv.p(), x.p(), ldx);
	if (ret != 0) {
	    cout << "LAPACK returned " << ret << endl;
	    SLS_ERR("something wrong!");
	}
}

inline void lin_eq(VecDoub_IO x, CmatDoub_I a)
{
#ifdef SLS_CHECK_SHAPES
	if (a.n0() != a.n1() || a.n1() != x.size())
	    SLS_ERR("wrong shape!");
#endif
	static CmatDoub a1(a.n0(), a.n1());
	static VecLong ipiv(a.n0());
	if (!shape_cmp(a1, a))
	    a1.resize(a.n0(), a.n1());
	copy(a1, a);
	if (a.n0() > ipiv.size())
	    ipiv.resize(a.n0());
	Long lda = a1.n0();
	Long ldx = x.size(), nrhs = 1;

	Long ret = LAPACKE_dgesv(LAPACK_COL_MAJOR, a1.n0(), nrhs, a1.p(), lda, ipiv.p(), x.p(), ldx);
	if (ret != 0) {
	    cout << "LAPACK returned " << ret << endl;
	    SLS_ERR("something wrong!");
	}
}

inline void lin_eq(SvecDoub_IO x, CmatDoub_I a)
{
#ifdef SLS_CHECK_SHAPES
	if (a.n0() != a.n1() || a.n1() != x.size())
	    SLS_ERR("wrong shape!");
#endif
	static CmatDoub a1(a.n0(), a.n1());
	static VecLong ipiv(a.n0());
	if (!shape_cmp(a1, a))
	    a1.resize(a.n0(), a.n1());
	copy(a1, a);
	if (a.n0() > ipiv.size())
	    ipiv.resize(a.n0());
	Long lda = a1.n0();
	Long ldx = x.size(), nrhs = 1;

	Long ret = LAPACKE_dgesv(LAPACK_COL_MAJOR, a1.n0(), nrhs, a1.p(), lda, ipiv.p(), x.p(), ldx);
	if (ret != 0) {
	    cout << "LAPACK returned " << ret << endl;
	    SLS_ERR("something wrong!");
	}
}

inline void lin_eq(VecComp_IO x, CmatComp_I a)
{
#ifdef SLS_CHECK_SHAPES
	if (a.n0() != a.n1() || a.n1() != x.size())
	    SLS_ERR("wrong shape!");
#endif
	static CmatComp a1(a.n0(), a.n1());
	static VecLong ipiv(a.n0());
	if (!shape_cmp(a1, a))
	    a1.resize(a.n0(), a.n1());
	copy(a1, a);
	if (a.n0() > ipiv.size())
	    ipiv.resize(a.n0());
	Long lda = a1.n0();
	Long ldx = x.size(), nrhs = 1;

	Long ret = LAPACKE_zgesv(LAPACK_COL_MAJOR, a1.n0(), nrhs, (double _Complex*)a1.p(), lda, ipiv.p(), (double _Complex*)x.p(), ldx);
	if (ret != 0) {
	    cout << "LAPACK returned " << ret << endl;
	    SLS_ERR("something wrong!");
	}
}

inline void lin_eq(SvecComp_IO x, ScmatComp_I a)
{
#ifdef SLS_CHECK_SHAPES
	if (a.n0() != a.n1() || a.n1() != x.size())
	    SLS_ERR("wrong shape!");
#endif
	static CmatComp a1(a.n0(), a.n1());
	static VecLong ipiv(a.n0());
	if (!shape_cmp(a1, a))
	    a1.resize(a.n0(), a.n1());
	copy(a1, a);
	if (a.n0() > ipiv.size())
	    ipiv.resize(a.n0());
	Long lda = a1.n0();
	Long ldx = x.size(), nrhs = 1;

	Long ret = LAPACKE_zgesv(LAPACK_COL_MAJOR, a1.n0(), nrhs, (double _Complex*)a1.p(), lda, ipiv.p(), (double _Complex*)x.p(), ldx);
	if (ret != 0) {
	    cout << "LAPACK returned " << ret << endl;
	    SLS_ERR("something wrong!");
	}
}


// solution to linear system with general coefficient matrix A and multiple right-hand sides.
// A will be changed to LU matrix
// ipiv: integer work space of size a.n0()
inline void lin_eq(CmatDoub_IO x, CmatDoub_IO a, SvecLlong_IO ipiv)
{
#ifdef SLS_CHECK_SHAPES
	if (a.n0() != a.n1() || a.n1() != x.n0())
	    SLS_ERR("wrong shape!");
	if (ipiv.size() != a.n0())
	    SLS_ERR("wrong shape!");
#endif
	Long lda = a.n0();
	Long ldx = x.n0(), nrhs = x.n1();

	Long ret = LAPACKE_dgesv(LAPACK_COL_MAJOR, a.n0(), nrhs, a.p(), lda, ipiv.p(), x.p(), ldx);
	if (ret != 0) {
	    cout << "LAPACK returned " << ret << endl;
	    SLS_ERR("something wrong!");
	}
}

inline void lin_eq(ScmatDoub_IO x, CmatDoub_IO a, SvecLlong_IO ipiv)
{
#ifdef SLS_CHECK_SHAPES
	if (a.n0() != a.n1() || a.n1() != x.n0())
	    SLS_ERR("wrong shape!");
	if (ipiv.size() != a.n0())
	    SLS_ERR("wrong shape!");
#endif
	Long lda = a.n0();
	Long ldx = x.n0(), nrhs = x.n1();

	Long ret = LAPACKE_dgesv(LAPACK_COL_MAJOR, a.n0(), nrhs, a.p(), lda, ipiv.p(), x.p(), ldx);
	if (ret != 0) {
	    cout << "LAPACK returned " << ret << endl;
	    SLS_ERR("something wrong!");
	}
}

inline void lin_eq(ScmatDoub_IO x, ScmatDoub_IO a, SvecLlong_IO ipiv)
{
#ifdef SLS_CHECK_SHAPES
	if (a.n0() != a.n1() || a.n1() != x.n0())
	    SLS_ERR("wrong shape!");
	if (ipiv.size() != a.n0())
	    SLS_ERR("wrong shape!");
#endif
	Long lda = a.n0();
	Long ldx = x.n0(), nrhs = x.n1();

	Long ret = LAPACKE_dgesv(LAPACK_COL_MAJOR, a.n0(), nrhs, a.p(), lda, ipiv.p(), x.p(), ldx);
	if (ret != 0) {
	    cout << "LAPACK returned " << ret << endl;
	    SLS_ERR("something wrong!");
	}
}

inline void lin_eq(VecDoub_IO x, CmatDoub_IO a, SvecLlong_IO ipiv)
{
#ifdef SLS_CHECK_SHAPES
	if (a.n0() != a.n1() || a.n1() != x.size())
	    SLS_ERR("wrong shape!");
	if (ipiv.size() != a.n0())
	    SLS_ERR("wrong shape!");
#endif
	Long lda = a.n0();
	Long ldx = x.size(), nrhs = 1;

	Long ret = LAPACKE_dgesv(LAPACK_COL_MAJOR, a.n0(), nrhs, a.p(), lda, ipiv.p(), x.p(), ldx);
	if (ret != 0) {
	    cout << "LAPACK returned " << ret << endl;
	    SLS_ERR("something wrong!");
	}
}

inline void lin_eq(SvecDoub_IO x, CmatDoub_IO a, SvecLlong_IO ipiv)
{
#ifdef SLS_CHECK_SHAPES
	if (a.n0() != a.n1() || a.n1() != x.size())
	    SLS_ERR("wrong shape!");
	if (ipiv.size() != a.n0())
	    SLS_ERR("wrong shape!");
#endif
	Long lda = a.n0();
	Long ldx = x.size(), nrhs = 1;

	Long ret = LAPACKE_dgesv(LAPACK_COL_MAJOR, a.n0(), nrhs, a.p(), lda, ipiv.p(), x.p(), ldx);
	if (ret != 0) {
	    cout << "LAPACK returned " << ret << endl;
	    SLS_ERR("something wrong!");
	}
}

inline void lin_eq(VecComp_IO x, CmatComp_IO a, SvecLlong_IO ipiv)
{
#ifdef SLS_CHECK_SHAPES
	if (a.n0() != a.n1() || a.n1() != x.size())
	    SLS_ERR("wrong shape!");
	if (ipiv.size() != a.n0())
	    SLS_ERR("wrong shape!");
#endif
	Long lda = a.n0();
	Long ldx = x.size(), nrhs = 1;

	Long ret = LAPACKE_zgesv(LAPACK_COL_MAJOR, a.n0(), nrhs, (double _Complex*)a.p(), lda, ipiv.p(), (double _Complex*)x.p(), ldx);
	if (ret != 0) {
	    cout << "LAPACK returned " << ret << endl;
	    SLS_ERR("something wrong!");
	}
}

inline void lin_eq(SvecComp_IO x, ScmatComp_IO a, SvecLlong_IO ipiv)
{
#ifdef SLS_CHECK_SHAPES
	if (a.n0() != a.n1() || a.n1() != x.size())
	    SLS_ERR("wrong shape!");
	if (ipiv.size() != a.n0())
	    SLS_ERR("wrong shape!");
#endif
	Long lda = a.n0();
	Long ldx = x.size(), nrhs = 1;

	Long ret = LAPACKE_zgesv(LAPACK_COL_MAJOR, a.n0(), nrhs, (double _Complex*)a.p(), lda, ipiv.p(), (double _Complex*)x.p(), ldx);
	if (ret != 0) {
	    cout << "LAPACK returned " << ret << endl;
	    SLS_ERR("something wrong!");
	}
}


// solution to linear system with band coefficient matrix A and multiple right-hand sides.
// ####### Not Thread Safe ######
inline void lin_eq(VecDoub_IO x, CbandDoub_I a)
{
#ifdef SLS_CHECK_SHAPES
	if (a.n0() != a.n1() || a.n1() != x.size())
	    SLS_ERR("wrong shape!");
#endif
	static CbandDoub a1(a.n0(), a.n1(), a.nup(), a.nlow(), a.nup() + 2*a.nlow() + 1, a.nlow() + a.nup());
	static VecLong ipiv(a.n0());
	if (a1.lda() < a.nup() + 2*a.nlow() + 1 || a1.n1() != a.n1())
	    a1.resize(a.nup() + 2*a.nlow() + 1, a.n1());
	a1.shift(a.nlow() + a.nup()); copy(a1, a);
	if (a.n0() > ipiv.size())
	    ipiv.resize(a.n0());

	Long lda = a1.lda();
	Long ldx = x.size(), nrhs = 1;

	Long ret = LAPACKE_dgbsv(LAPACK_COL_MAJOR, a1.n0(), a1.nlow() , a1.nup(), nrhs, a1.p(), lda, ipiv.p(), x.p(), ldx);
	if (ret != 0) {
	    cout << "LAPACK returned " << ret << endl;
	    SLS_ERR("something wrong!");
	}
}

inline void lin_eq(VecComp_IO x, CbandComp_I a)
{
#ifdef SLS_CHECK_SHAPES
	if (a.n0() != a.n1() || a.n1() != x.size())
	    SLS_ERR("wrong shape!");
#endif
	static CbandComp a1(a.n0(), a.n1(), a.nup(), a.nlow(), a.nup() + 2*a.nlow() + 1, a.nlow() + a.nup());
	static VecLong ipiv(a.n0());
	if (a1.lda() < a.nup() + 2*a.nlow() + 1 || a1.n1() != a.n1())
	    a1.resize(a.nup() + 2*a.nlow() + 1, a.n1());
	a1.shift(a.nlow() + a.nup()); copy(a1, a);
	if (a.n0() > ipiv.size())
	    ipiv.resize(a.n0());

	Long lda = a1.lda();
	Long ldx = x.size(), nrhs = 1;

	Long ret = LAPACKE_zgbsv(LAPACK_COL_MAJOR, a1.n0(), a1.nlow() , a1.nup(), nrhs, (double _Complex*)a1.p(), lda, ipiv.p(), (double _Complex*)x.p(), ldx);
	if (ret != 0) {
	    cout << "LAPACK returned " << ret << endl;
	    SLS_ERR("something wrong!");
	}
}

inline void lin_eq(SvecComp_IO x, CbandComp_I a)
{
#ifdef SLS_CHECK_SHAPES
	if (a.n0() != a.n1() || a.n1() != x.size())
	    SLS_ERR("wrong shape!");
#endif
	static CbandComp a1(a.n0(), a.n1(), a.nup(), a.nlow(), a.nup() + 2*a.nlow() + 1, a.nlow() + a.nup());
	static VecLong ipiv(a.n0());
	if (a1.lda() < a.nup() + 2*a.nlow() + 1 || a1.n1() != a.n1())
	    a1.resize(a.nup() + 2*a.nlow() + 1, a.n1());
	a1.shift(a.nlow() + a.nup()); copy(a1, a);
	if (a.n0() > ipiv.size())
	    ipiv.resize(a.n0());

	Long lda = a1.lda();
	Long ldx = x.size(), nrhs = 1;

	Long ret = LAPACKE_zgbsv(LAPACK_COL_MAJOR, a1.n0(), a1.nlow() , a1.nup(), nrhs, (double _Complex*)a1.p(), lda, ipiv.p(), (double _Complex*)x.p(), ldx);
	if (ret != 0) {
	    cout << "LAPACK returned " << ret << endl;
	    SLS_ERR("something wrong!");
	}
}


// solution to linear system with band coefficient matrix A and multiple right-hand sides.
// matrix will be replaced with LU decomp
// use the following to generate input data
// VecLong ipiv(a.n0());
// @Ta@ a1(a.n0(), a.n1(), a.nup(), a.nlow(), a.nup() + 2*a.nlow() + 1, a.nlow() + a.nup());
// copy(a1, a);
inline void lin_eq(VecDoub_IO x, CbandDoub_IO a1, VecLlong_IO ipiv)
{
#ifdef SLS_CHECK_SHAPES
	if (a1.n0() != a1.n1() || a1.n1() != x.size())
	    SLS_ERR("wrong shape!");
	if (a1.lda() < a1.nup() + 2*a1.nlow() + 1 || a1.idiag() < a1.nup() + a1.nup())
	    SLS_ERR("wrong shape: lda < nup+2nlow+1 || idiag < nup+nlow !");
#endif
	Long lda = a1.lda();
	Long ldx = x.size(), nrhs = 1;
	Long ret = LAPACKE_dgbsv(LAPACK_COL_MAJOR, a1.n0(), a1.nlow() , a1.nup(), nrhs, a1.p(), lda, ipiv.p(), x.p(), ldx);
	if (ret != 0) {
	    cout << "LAPACK returned " << ret << endl;
	    SLS_ERR("something wrong!");
	}
}

inline void lin_eq(VecComp_IO x, CbandComp_IO a1, VecLlong_IO ipiv)
{
#ifdef SLS_CHECK_SHAPES
	if (a1.n0() != a1.n1() || a1.n1() != x.size())
	    SLS_ERR("wrong shape!");
	if (a1.lda() < a1.nup() + 2*a1.nlow() + 1 || a1.idiag() < a1.nup() + a1.nup())
	    SLS_ERR("wrong shape: lda < nup+2nlow+1 || idiag < nup+nlow !");
#endif
	Long lda = a1.lda();
	Long ldx = x.size(), nrhs = 1;
	Long ret = LAPACKE_zgbsv(LAPACK_COL_MAJOR, a1.n0(), a1.nlow() , a1.nup(), nrhs, (double _Complex*)a1.p(), lda, ipiv.p(), (double _Complex*)x.p(), ldx);
	if (ret != 0) {
	    cout << "LAPACK returned " << ret << endl;
	    SLS_ERR("something wrong!");
	}
}

inline void lin_eq(SvecComp_IO x, CbandComp_IO a1, SvecLlong_IO ipiv)
{
#ifdef SLS_CHECK_SHAPES
	if (a1.n0() != a1.n1() || a1.n1() != x.size())
	    SLS_ERR("wrong shape!");
	if (a1.lda() < a1.nup() + 2*a1.nlow() + 1 || a1.idiag() < a1.nup() + a1.nup())
	    SLS_ERR("wrong shape: lda < nup+2nlow+1 || idiag < nup+nlow !");
#endif
	Long lda = a1.lda();
	Long ldx = x.size(), nrhs = 1;
	Long ret = LAPACKE_zgbsv(LAPACK_COL_MAJOR, a1.n0(), a1.nlow() , a1.nup(), nrhs, (double _Complex*)a1.p(), lda, ipiv.p(), (double _Complex*)x.p(), ldx);
	if (ret != 0) {
	    cout << "LAPACK returned " << ret << endl;
	    SLS_ERR("something wrong!");
	}
}

inline void lin_eq(ScmatComp_IO x, CbandComp_IO a1, SvecLlong_IO ipiv)
{
#ifdef SLS_CHECK_SHAPES
	if (a1.n0() != a1.n1() || a1.n1() != x.n0())
	    SLS_ERR("wrong shape!");
	if (a1.lda() < a1.nup() + 2*a1.nlow() + 1 || a1.idiag() < a1.nup() + a1.nup())
	    SLS_ERR("wrong shape: lda < nup+2nlow+1 || idiag < nup+nlow !");
#endif
	Long lda = a1.lda();
	Long ldx = x.n0(), nrhs = x.n1();
	Long ret = LAPACKE_zgbsv(LAPACK_COL_MAJOR, a1.n0(), a1.nlow() , a1.nup(), nrhs, (double _Complex*)a1.p(), lda, ipiv.p(), (double _Complex*)x.p(), ldx);
	if (ret != 0) {
	    cout << "LAPACK returned " << ret << endl;
	    SLS_ERR("something wrong!");
	}
}

} // namespace slisc
#endif
