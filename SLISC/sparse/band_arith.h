#pragma once
#include "../arith/arithmetic.h"
#include "../dense/cut.h"
#include "../sparse/Cband.h"

namespace slisc {

// conversion between full matrix and band diagonal matrix
// Nup and Nlow are the number of upper diagonals and lower diagonals
// ref: cBLAS gbmv() routine
// https://software.intel.com/en-us/node/834918#DAEC7CD0-620A-4696-9612-C295F8211646

// cut the non-zero band
inline DcmatDoub band(CbandDoub_IO a)
{
	return DcmatDoub(&a.cmat()[a.idiag() - a.nup()], a.nup() + a.nlow() + 1, a.n1(), a.lda());
}

inline DcmatDoub_c band(CbandDoub_I a)
{
	return DcmatDoub_c(&a.cmat()[a.idiag() - a.nup()], a.nup() + a.nlow() + 1, a.n1(), a.lda());
}


inline DcmatComp band(CbandComp_IO a)
{
	return DcmatComp(&a.cmat()[a.idiag() - a.nup()], a.nup() + a.nlow() + 1, a.n1(), a.lda());
}

inline DcmatComp_c band(CbandComp_I a)
{
	return DcmatComp_c(&a.cmat()[a.idiag() - a.nup()], a.nup() + a.nlow() + 1, a.n1(), a.lda());
}



// detect band width of dense matrix
// a(i,j) < tol is considered 0
inline void nband(Long_O Nup, Long_O Nlow, CmatDoub_I a, Doub_I tol = 0)
{
	Bool found = false;
	// check upper diagonals
	for (Long k = a.n1() - 1; k > 0 && !found; --k) {
	    Long i = 0;
	    for (Long j = k; j < a.n1() && !found; ++j) {
	        if (i > a.n0()) break;
	        if (abs(a(i, j)) > tol)  {
	            Nup = k; found = true;
	        }
	        ++i;
	    }
	}
	if (!found)
	    Nup = 0;
	
	// check lower diagonals
	found = false;
	for (Long k = a.n0() - 1; k > 0  && !found; --k) {
	    Long j = 0;
	    for (Long i = k; i < a.n0() && !found; ++i) {
	        if (j > a.n1()) break;
	        if (abs(a(i, j)) > tol) {
	            Nlow = k; found = true;
	        }
	        ++j;
	    }
	}
	if (!found)
	    Nlow = 0;
}


inline void nband(Long_O Nup, Long_O Nlow, CmatComp_I a, Doub_I tol = 0)
{
	Bool found = false;
	// check upper diagonals
	for (Long k = a.n1() - 1; k > 0 && !found; --k) {
	    Long i = 0;
	    for (Long j = k; j < a.n1() && !found; ++j) {
	        if (i > a.n0()) break;
	        if (abs(a(i, j)) > tol)  {
	            Nup = k; found = true;
	        }
	        ++i;
	    }
	}
	if (!found)
	    Nup = 0;
	
	// check lower diagonals
	found = false;
	for (Long k = a.n0() - 1; k > 0  && !found; --k) {
	    Long j = 0;
	    for (Long i = k; i < a.n0() && !found; ++i) {
	        if (j > a.n1()) break;
	        if (abs(a(i, j)) > tol) {
	            Nlow = k; found = true;
	        }
	        ++j;
	    }
	}
	if (!found)
	    Nlow = 0;
}

inline void nband(Long_O Nup, Long_O Nlow, ScmatDoub_I a, Doub_I tol = 0)
{
	Bool found = false;
	// check upper diagonals
	for (Long k = a.n1() - 1; k > 0 && !found; --k) {
	    Long i = 0;
	    for (Long j = k; j < a.n1() && !found; ++j) {
	        if (i > a.n0()) break;
	        if (abs(a(i, j)) > tol)  {
	            Nup = k; found = true;
	        }
	        ++i;
	    }
	}
	if (!found)
	    Nup = 0;
	
	// check lower diagonals
	found = false;
	for (Long k = a.n0() - 1; k > 0  && !found; --k) {
	    Long j = 0;
	    for (Long i = k; i < a.n0() && !found; ++i) {
	        if (j > a.n1()) break;
	        if (abs(a(i, j)) > tol) {
	            Nlow = k; found = true;
	        }
	        ++j;
	    }
	}
	if (!found)
	    Nlow = 0;
}


inline void nband(Long_O Nup, Long_O Nlow, ScmatComp_I a, Doub_I tol = 0)
{
	Bool found = false;
	// check upper diagonals
	for (Long k = a.n1() - 1; k > 0 && !found; --k) {
	    Long i = 0;
	    for (Long j = k; j < a.n1() && !found; ++j) {
	        if (i > a.n0()) break;
	        if (abs(a(i, j)) > tol)  {
	            Nup = k; found = true;
	        }
	        ++i;
	    }
	}
	if (!found)
	    Nup = 0;
	
	// check lower diagonals
	found = false;
	for (Long k = a.n0() - 1; k > 0  && !found; --k) {
	    Long j = 0;
	    for (Long i = k; i < a.n0() && !found; ++i) {
	        if (j > a.n1()) break;
	        if (abs(a(i, j)) > tol) {
	            Nlow = k; found = true;
	        }
	        ++j;
	    }
	}
	if (!found)
	    Nlow = 0;
}



inline void nband(Long_O Nup, Long_O Nlow, McooDoub_I a, Doub_I tol = 0)
{
	Nup = 0; Nlow = 0;
	for (Long k = 0; k < a.nnz(); ++k) {
	    if (tol > 0 && abs(a[k]) < tol)
	        continue;
	    Long i = a.row(k), j = a.col(k);
	    Long n = j - i;
	    if (n > Nup)
	        Nup = n;
	    else if (-n > Nlow)
	        Nlow = -n;
	}
}

// set real part of band matrix to constant
inline void copy_real(CbandComp_O b, Doub_I s)
{
	Long N0 = b.n0(), N1 = b.n1();
	for (Long j = 0; j < N1; ++j) {
	    SvecComp cut_b = cut0(b.cmat(), j);
	    Long k = b.idiag() - j;
	    Long i_beg = max(Long(0), j - b.nup()), i_end = min(N0, j + b.nlow() + 1);
	    for (Long i = i_beg; i < i_end; ++i)
	        cut_b[k + i].real(s);
	}
}

// set real part of band matrix diagonal to constant
inline void copy_diag_real(CbandComp_O b, Doub_I s)
{
	Long lda = 2*b.lda(), N = min(b.n0(), b.n1());
	Doub *p_diag = (Doub *)&b.cmat()(b.idiag(), 0);
	Doub *p_end = p_diag + lda * N;
	for (; p_diag < p_end; p_diag += lda)
	    *p_diag = s;
}

// copy double dense matrix to imag part of band matrix
inline void copy_imag(CbandComp_O b, ScmatDoub_I a)
{
	assert_same_shape(a, b);
	Long N0 = a.n0(), N1 = a.n1();
	for (Long j = 0; j < N1; ++j) {
	    SvecComp cut_b = cut0(b.cmat(), j);
	    SvecDoub_c cut_a = cut0(a, j);
	    Long k = b.idiag() - j;
	    Long i_beg = max(Long(0), j - b.nup()), i_end = min(N0, j + b.nlow() + 1);
	    for (Long i = i_beg; i < i_end; ++i)
	        cut_b[k + i].imag(cut_a[i]);
	}
}

// construct Crank-Nicolson coefficient matrix from hamiltonian
// b = 1/2 + I*dt*a/4
inline void cn_band_mat(CbandComp_O b, ScmatDoub_I a, Doub_I dt, Bool_I imag_time)
{
	assert_same_shape(a, b);
	Long N0 = a.n0(), N1 = a.n1();
	Doub dt4 = 0.25*dt;
	for (Long j = 0; j < N1; ++j) {
	    SvecComp cut_b = cut0(b.cmat(), j);
	    SvecDoub_c cut_a = cut0(a, j);
	    Long k = b.idiag() - j;
	    Long i_beg = max(Long(0), j - b.nup()), i_end = min(N0, j + b.nlow() + 1);
	    if (!imag_time) {
	        for (Long i = i_beg; i < i_end; ++i) {
	            if (i == j)
	                cut_b[k + i] = Comp(0.5, dt4 * cut_a[i]);
	            else
	                cut_b[k + i] = Comp(0, dt4 * cut_a[i]);
	        }
	    }
	    else {
	        for (Long i = i_beg; i < i_end; ++i) {
	            if (i == j)
	                cut_b[k + i] = 0.5 + dt4 * cut_a[i];
	            else
	                cut_b[k + i] = dt4 * cut_a[i];
	        }
	    }
	}
}

// construct Crank-Nicolson coefficient matrix from hamiltonian
// B = 1/2 + I*dt*A/4
inline void cn_band_mat(CbandComp_O b, McooDoub_I a, Doub_I dt, Bool_I imag_time, Bool_I append = false)
{
	assert_same_shape(a, b);
	Doub dt4 = 0.25*dt;
	if (!append) {
	    copy(b, 0);
	    copy(cut1(b.cmat(), b.idiag()), 0.5);
	}
	if (!imag_time)
	    for (Long k = 0; k < a.nnz(); ++k) 
	        imag_r(b.ref(a.row(k), a.col(k))) += dt4*a[k];
	else
	    for (Long k = 0; k < a.nnz(); ++k) 
	        real_r(b.ref(a.row(k), a.col(k))) += dt4*a[k];
}

// construct Crank-Nicolson coefficient matrix from hamiltonian
// l = 0 is ignored!!!!!!!!!!!
// b = 1/2 + I*dt*(\sum_l coeff[l] a[l])/4 for !imag_time
// b = 1/2 +   dt*(\sum_l coeff[l] a[l])/4 for  imag_time
inline void cn_band_mat(CbandComp_O b, SvecDoub_I coeff, const vector<McooDoub> &a, Doub_I dt, Bool_I imag_time, Bool_I append)
{
#ifdef SLS_CHECK_SHAPES
	for (Long l = 0; l < (Long)a.size(); ++l)
	    assert_same_shape(a[l], b);
	if (coeff.size() != (Long)a.size())
	    SLS_ERR("wrong shape!");
#endif
	if (!append) {
	    copy(b, 0);
	    copy(cut1(b.cmat(), b.idiag()), 0.5);
	}
	if (!imag_time) {
	    for (Long l = 1; l < coeff.size(); ++l) {
	        const McooDoub &a1 = a[l]; Doub c = 0.25*dt*coeff[l];
	        for (Long k = 0; k < a1.nnz(); ++k)
	            imag_r(b.ref(a1.row(k), a1.col(k))) += c*a1[k];
	    }
	}
	else {
	    for (Long l = 1; l < coeff.size(); ++l) {
	        const McooDoub &a1 = a[l]; Doub c = 0.25*dt*coeff[l];
	        for (Long k = 0; k < a1.nnz(); ++k)
	            real_r(b.ref(a1.row(k), a1.col(k))) += c*a1[k];
	    }
	}
}



inline void times(CbandComp_O v, CbandComp_I v1, Doub_I s)
{
	assert_same_shape(v, v1);
	times(band(v), band(v1), s);
}




// matrix-vector multiplication for band matrix
#ifdef SLS_USE_CBLAS
inline void mul(VecDoub_O y, CbandDoub_I a, VecDoub_I x)
{
	Long incx = 1;
	Long incy = 1;
	Doub alpha = 1, beta = 0;
	cblas_dgbmv(CblasColMajor, CblasNoTrans, a.n0(), a.n1(), a.nlow(), a.nup(),
	    alpha, a.p() + a.idiag() - a.nup(), a.lda(), x.p(), incx, beta, y.p(), incy);
}


inline void mul(VecComp_O y, CbandDoub_I a, VecComp_I x)
{
	Long incx = 1;
	Long incy = 1;
	Doub alpha = 1, beta = 0;
	// real part
	cblas_dgbmv(CblasColMajor, CblasNoTrans, a.n0(), a.n1(), a.nlow(), a.nup(),
	    alpha, a.p() + a.idiag() - a.nup(), a.lda(), (Doub*)x.p(), incx*2, beta, (Doub*)y.p(), incy*2);
	// imag part
	cblas_dgbmv(CblasColMajor, CblasNoTrans, a.n0(), a.n1(), a.nlow(), a.nup(),
	    alpha, a.p() + a.idiag() - a.nup(), a.lda(), (Doub*)x.p()+1, incx*2, beta, (Doub*)y.p()+1, incy*2);
}


inline void mul(VecComp_O y, CbandComp_I a, VecComp_I x)
{
	Long incx = 1;
	Long incy = 1;
	Comp alpha(1, 0), beta(0, 0);
	cblas_zgbmv(CblasColMajor, CblasNoTrans, a.n0(), a.n1(), a.nlow(), a.nup(),
	    &alpha, a.p() + a.idiag() - a.nup(), a.lda(), x.p(), incx, &beta, y.p(), incy);
}


inline void mul(VecComp_O y, CbandComp_I a, SvecComp_I x)
{
	Long incx = 1;
	Long incy = 1;
	Comp alpha(1, 0), beta(0, 0);
	cblas_zgbmv(CblasColMajor, CblasNoTrans, a.n0(), a.n1(), a.nlow(), a.nup(),
	    &alpha, a.p() + a.idiag() - a.nup(), a.lda(), x.p(), incx, &beta, y.p(), incy);
}


inline void mul(SvecComp_O y, CbandDoub_I a, SvecComp_I x)
{
	Long incx = 1;
	Long incy = 1;
	Doub alpha = 1, beta = 0;
	// real part
	cblas_dgbmv(CblasColMajor, CblasNoTrans, a.n0(), a.n1(), a.nlow(), a.nup(),
	    alpha, a.p() + a.idiag() - a.nup(), a.lda(), (Doub*)x.p(), incx*2, beta, (Doub*)y.p(), incy*2);
	// imag part
	cblas_dgbmv(CblasColMajor, CblasNoTrans, a.n0(), a.n1(), a.nlow(), a.nup(),
	    alpha, a.p() + a.idiag() - a.nup(), a.lda(), (Doub*)x.p()+1, incx*2, beta, (Doub*)y.p()+1, incy*2);
}


#endif

} // namespace slisc
