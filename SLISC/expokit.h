#pragma once
#include "global.h"
#ifdef SLS_USE_CBLAS
#include "sparse_arith.h"
#include "arithmetic.h"

namespace slisc {

// matrix / vector multiplication

inline void expokit_mul(Comp *y, McooDoub_I a, Comp *x)
{ mul_v_coo_v(y, a.p(), a.row_p(), a.col_p(), a.n0(), a.nnz(), x); }

inline void expokit_mul(Comp *y, McooComp_I a, Comp *x)
{ mul_v_coo_v(y, a.p(), a.row_p(), a.col_p(), a.n0(), a.nnz(), x); }


inline void expokit_mul(Comp *y, CmobdDoub_I a, Comp *x)
{ mul_v_cmatobd_v(y, x, a.p(), a.n0(), a.nblk(), a.n0()); }

inline void expokit_mul(Comp *y, CmobdComp_I a, Comp *x)
{ mul_v_cmatobd_v(y, x, a.p(), a.n0(), a.nblk(), a.n0()); }


// not optimized for symmetric or Hermitian matrix
inline void expokit_mul(Comp *y, CmatDoub_I a, Comp *x)
{
	SvecComp vx(x, a.n1()); SvecComp vy(y, a.n0());
	mul_gen(vy, a, vx);
}

inline void expokit_mul(Comp *y, CmatComp_I a, Comp *x)
{
	SvecComp vx(x, a.n1()); SvecComp vy(y, a.n0());
	mul_gen(vy, a, vx);
}

inline void expokit_mul(Doub *y, CmatDoub_I a, Doub *x)
{
	SvecDoub vx(x, a.n1()); SvecDoub vy(y, a.n0());
	mul_gen(vy, a, vx);
}


// ======== translation details ============
// variables that subtracted 1 comparing to F77 version
// arguments: iexph
// internal variables: i, j, k, icoef, ih2, ip, iq, iput, iget, ifree, iused

inline void ZGPADM(Int_I ideg, Int_I m, Doub_I t, const Comp *H, Int_I ldh, Comp *wsp, Int_I lwsp,
	Int *ipiv, Int_O iexph, Int_O ns, Int_O iflag)
{
	Int i, j, k, icoef, mm, ih2, iodd, iused, ifree, iq, ip, iput, iget;
	Doub hnorm;
	Comp cp, cq, scale, scale2, temp;
	const Comp zero = 0., one = 1.;

	mm = m*m;
	iflag = 0;
	if (ldh < m) iflag = -1;
	if (lwsp < 4 * mm + ideg + 1) iflag = -2;
	if (iflag != 0)
	    SLS_ERR("bad sizes (in input of ZGPADM): iflag = " + num2str(iflag));

	icoef = 0;
	ih2 = icoef + ideg + 1;
	ip = ih2 + mm;
	iq = ip + mm;
	ifree = iq + mm;

	for (i = 0; i < m; ++i) {
	    wsp[i] = zero;
	}
	for (j = 0; j < m; ++j) {
	    for (i = 0; i < m; ++i) {
	        wsp[i] = wsp[i] + abs(H[i + ldh*j]);
	    }
	}

	hnorm = 0.;
	for (i = 0; i < m; ++i) {
	    hnorm = max(hnorm, real(wsp[i]));
	}

	hnorm = abs(t*hnorm);
	if (hnorm == 0.)
	    SLS_ERR("Error - null H in input of ZGPADM.");
	ns = max(0, Int(log(hnorm) / log(2.)) + 2);
	scale = Comp(t / pow(2, ns), 0.);
	scale2 = scale*scale;

	i = ideg;
	j = 2 * ideg;
	wsp[icoef] = one;
	for (k = 0; k < ideg; ++k) {
	    wsp[icoef + k + 1] = (wsp[icoef + k] * Doub(i - k)) / Doub((k + 1)*(j - k));
	}

	cblas_zgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, m, m, m, &scale2, H, ldh,
	    H, ldh, &zero, wsp + ih2, m);

	cp = wsp[icoef + ideg - 1];
	cq = wsp[icoef + ideg];
	for (j = 0; j < m; ++j) {
	    for (i = 0; i < m; ++i) {
	        wsp[ip + j*m + i] = zero;
	        wsp[iq + j*m + i] = zero;
	    }
	    wsp[ip + j*(m + 1)] = cp;
	    wsp[iq + j*(m + 1)] = cq;
	}

	iodd = 1;
	k = ideg - 2;

	/*100*/
	do {
	    iused = iodd*(iq - ip) + ip;
	    cblas_zgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, m, m, m, &one, wsp + iused, m,
	        wsp + ih2, m, &zero, wsp + ifree, m);
	    for (j = 0; j < m; ++j)
	        wsp[ifree + j*(m + 1)] = wsp[ifree + j*(m + 1)] + wsp[icoef + k];

	    ip = ifree + iodd*(ip - ifree);
	    iq = iodd*(ifree - iq) + iq;
	    ifree = iused;
	    iodd = 1 - iodd;
	    --k;
	} while (k + 1 > 0);


	if (iodd != 0) {
	    cblas_zgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, m, m, m, &scale, wsp + iq, m,
	        H, ldh, &zero, wsp + ifree, m);
	    iq = ifree;
	}
	else {
	    cblas_zgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, m, m, m, &scale, wsp + ip, m,
	        H, ldh, &zero, wsp + ifree, m);
	    ip = ifree;
	}
	temp = -one;
	cblas_zaxpy(mm, &temp, wsp + ip, 1, wsp + iq, 1);
	iflag = LAPACKE_zgesv(LAPACK_COL_MAJOR, m, m, (double _Complex*)(wsp + iq), m, ipiv,
	    (double _Complex*)(wsp + ip), m);
	if (iflag != 0)
	    SLS_ERR("Problem in ZGESV (within ZGPADM): iflag = " + num2str(iflag));
	cblas_zdscal(mm, 2., wsp + ip, 1);
	for (j = 0; j < m; ++j)
	    wsp[ip + j*(m + 1)] = wsp[ip + j*(m + 1)] + one;

	iput = ip;
	if (ns == 0 && iodd != 0) {
	    cblas_zdscal(mm, -1., wsp + ip, 1);
	}
	else {
	    iodd = 1;
	    for (k = 0; k < ns; ++k) {
	        iget = iodd*(ip - iq) + iq;
	        iput = ip + iodd*(iq - ip);
	        cblas_zgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, m, m, m, &one, wsp + iget, m,
	            wsp + iget, m, &zero, wsp + iput, m);
	        iodd = 1 - iodd;
	    }
	}

	iexph = iput;
}

// translate as directly as possible for now:
// * any variable values should not change
// * all pointer indexing (including +, -) is subtracted by 1 in place

inline void ZNCHBV(Int_I m, Doub_I t, const Comp *H, Int_I ldh, Comp *y, Comp *wsp)
{
	SLS_ERR("the translated ZNCHBV is not complete yet, do it now!");
	const Comp zero = 0.;
	const Int ndeg = 7;
	Int i, j, k, ip, ih, iy, iz;
	Doub alpha0;
	Comp alpha[ndeg], theta[ndeg];
	Comp tmpc;
	  
	ih = 1;
	iy = ih + m*m;
	iz = iy + m;


	alpha0 = 0.183216998528140087e-11;
	alpha[0] = Comp(0.557503973136501826e+02, -0.204295038779771857e+03);
	alpha[1] = Comp(-0.938666838877006739e+02, 0.912874896775456363e+02);
	alpha[2] = Comp(0.469965415550370835e+02, -0.116167609985818103e+02);
	alpha[3] = Comp(-0.961424200626061065e+01, -0.264195613880262669e+01);
	alpha[4] = Comp(0.752722063978321642e+00, 0.670367365566377770e+00);
	alpha[5] = Comp(-0.188781253158648576e-01, -0.343696176445802414e-01);
	alpha[6] = Comp(0.143086431411801849e-03, 0.287221133228814096e-03);

	theta[0] = Comp(-0.562314417475317895e+01, 0.119406921611247440e+01);
	theta[1] = Comp(-0.508934679728216110e+01, 0.358882439228376881e+01);
	theta[2] = Comp(-0.399337136365302569e+01, 0.600483209099604664e+01);
	theta[3] = Comp(-0.226978543095856366e+01, 0.846173881758693369e+01);
	theta[4] = Comp(0.208756929753827868e+00, 0.109912615662209418e+02);
	theta[5] = Comp(0.370327340957595652e+01, 0.136563731924991884e+02);
	theta[6] = Comp(0.889777151877331107e+01, 0.166309842834712071e+02);

	for (ip = 1; ip <= ndeg; ++ip) {
	    theta[ndeg + ip - 1] = conj(theta[ip - 1]);
	    alpha[ndeg + ip - 1] = conj(alpha[ip - 1]);
	}

	for (j = 1; j <= m; ++j) {
	    wsp[iz + j - 2] = y[j - 1];
	    y[j - 1] = y[j - 1] * alpha0;
	}

	for (ip = 1; ip <= 2 * ndeg; ++ip) {
	    alpha[ip - 1] = 0.5*alpha[ip - 1];
	    for (j = 1; j <= m; ++j) {
	        wsp[iy + j - 2] = wsp[iz + j - 2];
	        for (i = 1; i <= min(j + 1, m); ++i) {
	            wsp[ih + (j - 1)*m + i - 2] = -t*H[i + ldh*(j-1) - 1];
	        }
	        wsp[ih + (j - 1)*m + j - 2] = wsp[ih + (j - 1)*m + j - 2] - theta[ip - 1];
	        for (k = i; k <= m; ++k) {
	            wsp[ih + (j - 1)*m + k - 2] = zero;
	        }
	    }
	    for (j = 1; j <= m; ++j) {

	    }
	    for (i = 1; i <= m - 1; ++i) {
	        if (abs(wsp[ih + (i - 1)*m + i - 2]) < abs(wsp[ih + (i - 1)*m + i - 1])) {
	            cblas_zswap(m - i + 1, wsp + ih + (i - 1)*m + i - 2, m,
	                wsp + ih + (i - 1)*m + i - 1, m);
	            cblas_zswap(1, wsp + iy + i - 2, 1, wsp + iy + i - 1, 1);
	        }

	        tmpc = wsp[ih + (i - 1)*m + i - 1] / wsp[ih + (i - 1)*m + i - 2];
	        Comp temp = -tmpc;
	        cblas_zaxpy(m - i, &temp, wsp + ih + i*m + i - 2, m, wsp + ih + i*m + i - 1, m);
	        wsp[iy + i - 1] = wsp[iy + i - 1] - tmpc*wsp[iy + i - 2];
	    }

	    for (i = m; i >= 1; --i) {
	        tmpc = wsp[iy + i - 2];
	        for (j = i + 1; j <= m; ++j) {
	            tmpc = tmpc - wsp[ih + (j - 1)*m + i - 2]*wsp[iy + j - 2];
	        }
	        wsp[iy + i - 2] = tmpc / wsp[ih + (i - 1)*m + i - 2];
	    }
	    for (j = 1; j <= m; ++j) {
	        y[j - 1] = y[j - 1] + alpha[ip - 1]*wsp[iy + j - 2];
	    }
	}
}

// ======== translation details ============
// variables that subtracted 1 comparing to F77 version
// internal variables: i, j, ifree, ih, j1v, iv, iexph
// `T` can be any user defined matrix class
// expokit_mul(Comp *y, const T &mat, Comp *x) must be defined to perform matrix-vector multiplication (y = mat * x)

// ======== modifications ==================
// modified so that w is both input and output vector

inline void ZGEXPV(Int_I n, Int_I m, Doub_I t, Comp *w, Doub tol, Doub_I anorm,
	Comp *wsp, Int_I lwsp, Int *iwsp, Int_I liwsp, CmobdDoub_I mat, Int_I itrace, Int_O iflag)
{
#ifndef NDEBUG
	if (sum_abs_v(w, n) < 1e-100)
	    SLS_ERR("zero vector is not allowed!");
#endif
	const Int mxstep = 500, mxreject = 0, ideg = 6;
	Doub delta = 1.2, gamma = 0.9;


	const Comp zero = 0., one = 1.;

	Int i, j, k1, mh, mx, ih, j1v, ns, ifree, lfree, iexph,
	    ireject, ibrkflag, mbrkdwn, nmult, nreject, nexph, nscale,
	    nstep;
	Doub sgn, t_out, tbrkdwn, step_min, step_max, err_loc,
	    s_error, x_error, t_now, t_new, t_step, t_old,
	    xm, beta, break_tol, p1, p2, p3, eps, rndoff,
	    vnorm, avnorm=0, hj1j, hump, sqr1;
	Comp hij;
	iflag = 0;
	if (lwsp < n*(m + 2) + 5 * sqr(m + 2) + ideg + 1)
	    iflag = -1;
	if (liwsp < m + 2)
	    iflag = -2;
	if (m >= n || m <= 0)
	    iflag = -3;
	if (iflag != 0)
	    SLS_ERR("bad sizes (in input of ZGEXPV): iflag = " + num2str(iflag));

	k1 = 2;
	mh = m + 2;
	const Int iv = 0;
	ih = iv + n*(m + 1) + n;
	ifree = ih + mh*mh;
	lfree = lwsp - ifree;

	ibrkflag = 0;
	mbrkdwn = m;
	nmult = 0;
	nreject = 0;
	nexph = 0;
	nscale = 0;

	t_out = abs(t);
	tbrkdwn = 0.;
	step_min = t_out;
	step_max = 0.;
	nstep = 0;
	s_error = 0.;
	x_error = 0.;
	t_now = 0.;
	t_new = 0.;

	p1 = 4. / 3.;
	do {
	    p2 = p1 - 1.;
	    p3 = p2 + p2 + p2;
	    eps = abs(p3 - 1.);
	} while (eps == 0.);

	if (tol <= eps) tol = sqrt(eps);
	rndoff = eps*anorm;

	break_tol = 1.0e-7;

	sgn = sign(1., t);
	beta = cblas_dznrm2(n, w, 1);
	vnorm = beta;
	hump = beta;

	sqr1 = sqrt(0.1);
	xm = 1. / Doub(m);
	p2 = tol*pow((m + 1) / 2.72, m + 1)*sqrt(2.*3.14*(m + 1));
	t_new = (1. / anorm)*pow(p2 / (4.*beta*anorm), xm);
	p1 = pow(10., round(log10(t_new) - sqr1) - 1);
	t_new = trunc(t_new / p1 + 0.55) * p1;

	do {
	    if (t_now >= t_out)
	        break;

	    nstep = nstep + 1;
	    t_step = min(t_out - t_now, t_new);
	    p1 = 1. / beta;
	    for (i = 0; i < n; ++i)
	        wsp[iv + i] = p1*w[i];

	    for (i = 0; i < mh*mh; ++i)
	        wsp[ih + i] = zero;

	    j1v = iv + n;
	    Bool break_flag = false;
	    for (j = 0; j < m; ++j) {
	        nmult = nmult + 1;
	        expokit_mul(wsp + j1v, mat, wsp + j1v - n);
	        for (i = 0; i < j + 1; ++i) {
	            cblas_zdotc_sub(n, wsp + iv + i*n, 1, wsp + j1v, 1, &hij);
	            Comp temp = -hij;
	            cblas_zaxpy(n, &temp, wsp + iv + i*n, 1, wsp + j1v, 1);
	            wsp[ih + j*mh + i] = hij;
	        }
	        hj1j = cblas_dznrm2(n, wsp + j1v, 1);

	        if (hj1j <= break_tol) {
	            // std::cout << "happy breakdown: mbrkdwn = " << j + 1 << "h = " << hj1j << std::endl;
	            k1 = 0;
	            ibrkflag = 1;
	            mbrkdwn = j + 1;
	            tbrkdwn = t_now;
	            t_step = t_out - t_now;
	            break_flag = true;
	            break;
	        }
	        wsp[ih + j*mh + j + 1] = Comp(hj1j);
	        cblas_zdscal(n, 1. / hj1j, wsp + j1v, 1);
	        j1v += n;
	    }

	    if (!break_flag) {
	        nmult = nmult + 1;
	        expokit_mul(wsp + j1v, mat, wsp + j1v - n);
	        avnorm = cblas_dznrm2(n, wsp + j1v, 1);
	    }

	    wsp[ih + m*mh + m + 1] = one;
	    ireject = 0;

	    while (true) {
	        nexph = nexph + 1;
	        mx = mbrkdwn + k1;
	        if (ideg != 0) {
	            ZGPADM(ideg, mx, sgn*t_step, wsp + ih, mh,
	                wsp + ifree, lfree, iwsp, iexph, ns, iflag);
	            iexph += ifree;
	            nscale = nscale + ns;
	        }
	        else {
	            iexph = ifree;
	            for (i = 0; i < mx; ++i)
	                wsp[iexph + i] = zero;
	            wsp[iexph] = one;
	            ZNCHBV(mx, sgn*t_step, wsp + ih, mh, wsp + iexph, wsp + ifree + mx);
	        }

	        if (k1 == 0) {
	            err_loc = tol;
	        }
	        else {
	            p1 = abs(wsp[iexph + m])   * beta;
	            p2 = abs(wsp[iexph + m + 1]) * beta * avnorm;
	            if (p1 > 10.*p2) {
	                err_loc = p2;
	                xm = 1. / Doub(m);
	            }
	            else if (p1 > p2) {
	                err_loc = (p1*p2) / (p1 - p2);
	                xm = 1. / Doub(m);
	            }
	            else {
	                err_loc = p1;
	                xm = 1. / Doub(m - 1);
	            }
	        }

	        if ((k1 != 0) && (err_loc > delta*t_step*tol) &&
	            (mxreject == 0 || ireject < mxreject)) {
	            t_old = t_step;
	            t_step = gamma * t_step * pow(t_step*tol / err_loc, xm);
	            p1 = pow(10., round(log10(t_step) - sqr1) - 1);
	            t_step = trunc(t_step / p1 + 0.55) * p1;
	            if (itrace != 0) {
	                std::cout << "t_step = " << t_old << std::endl;
	                std::cout << "err_loc = " << err_loc << std::endl;
	                std::cout << "err_required =" << delta*t_old*tol << std::endl;
	                std::cout << "stepsize rejected, stepping down to:" << t_step << std::endl;
	            }
	            ireject = ireject + 1;
	            nreject = nreject + 1;
	            if (mxreject != 0 && ireject > mxreject) {
	                std::cout << "Failure in ZGEXPV: ---" << std::endl;
	                std::cout << "The requested tolerance is too high." << std::endl;
	                std::cout << "Rerun with a smaller value." << std::endl;
	                iflag = 2;
	                return;
	            }
	            continue;
	        }
	        break;
	    }

	    mx = mbrkdwn + max(0, k1 - 1);
	    hij = Comp(beta);
	    cblas_zgemv(CblasColMajor, CblasNoTrans, n, mx, &hij, wsp + iv, n, wsp + iexph, 1, &zero, w, 1);
	    beta = cblas_dznrm2(n, w, 1);
	    hump = max(hump, beta);

	    if (err_loc == 0)
	        t_new = p1 = 1e300;
	    else {
	        t_new = gamma * t_step * pow(t_step*tol / err_loc, xm);
	        p1 = pow(10., round(log10(t_new) - sqr1) - 1);
	        t_new = trunc(t_new / p1 + 0.55) * p1;
	    }

	    err_loc = max(err_loc, rndoff);

	    t_now = t_now + t_step;

	    if (itrace != 0) {
	        std::cout << "integration " << nstep << "---------------------------------" << std::endl;
	        std::cout << "scale-square = " << ns << std::endl;
	        std::cout << "step_size = " << t_step << std::endl;
	        std::cout << "err_loc   = " << err_loc << std::endl;
	        std::cout << "next_step = " << t_new << std::endl;
	    }

	    step_min = min(step_min, t_step);
	    step_max = max(step_max, t_step);
	    s_error = s_error + err_loc;
	    x_error = max(x_error, err_loc);

	} while (mxstep == 0 || nstep < mxstep);

	iflag = 1;

	iwsp[0] = nmult;
	iwsp[1] = nexph;
	iwsp[2] = nscale;
	iwsp[3] = nstep;
	iwsp[4] = nreject;
	iwsp[5] = ibrkflag;
	iwsp[6] = mbrkdwn;

	wsp[0] = Comp(step_min);
	wsp[1] = Comp(step_max);
	wsp[2] = Comp(0.);
	wsp[3] = Comp(0.);
	wsp[4] = Comp(x_error);
	wsp[5] = Comp(s_error);
	wsp[6] = Comp(tbrkdwn);
	wsp[7] = Comp(sgn*t_now);
	wsp[8] = Comp(hump / vnorm);
	wsp[9] = Comp(beta / vnorm);
}

inline void ZGEXPV(Int_I n, Int_I m, Doub_I t, Comp *w, Doub tol, Doub_I anorm,
	Comp *wsp, Int_I lwsp, Int *iwsp, Int_I liwsp, CmobdComp_I mat, Int_I itrace, Int_O iflag)
{
#ifndef NDEBUG
	if (sum_abs_v(w, n) < 1e-100)
	    SLS_ERR("zero vector is not allowed!");
#endif
	const Int mxstep = 500, mxreject = 0, ideg = 6;
	Doub delta = 1.2, gamma = 0.9;


	const Comp zero = 0., one = 1.;

	Int i, j, k1, mh, mx, ih, j1v, ns, ifree, lfree, iexph,
	    ireject, ibrkflag, mbrkdwn, nmult, nreject, nexph, nscale,
	    nstep;
	Doub sgn, t_out, tbrkdwn, step_min, step_max, err_loc,
	    s_error, x_error, t_now, t_new, t_step, t_old,
	    xm, beta, break_tol, p1, p2, p3, eps, rndoff,
	    vnorm, avnorm=0, hj1j, hump, sqr1;
	Comp hij;
	iflag = 0;
	if (lwsp < n*(m + 2) + 5 * sqr(m + 2) + ideg + 1)
	    iflag = -1;
	if (liwsp < m + 2)
	    iflag = -2;
	if (m >= n || m <= 0)
	    iflag = -3;
	if (iflag != 0)
	    SLS_ERR("bad sizes (in input of ZGEXPV): iflag = " + num2str(iflag));

	k1 = 2;
	mh = m + 2;
	const Int iv = 0;
	ih = iv + n*(m + 1) + n;
	ifree = ih + mh*mh;
	lfree = lwsp - ifree;

	ibrkflag = 0;
	mbrkdwn = m;
	nmult = 0;
	nreject = 0;
	nexph = 0;
	nscale = 0;

	t_out = abs(t);
	tbrkdwn = 0.;
	step_min = t_out;
	step_max = 0.;
	nstep = 0;
	s_error = 0.;
	x_error = 0.;
	t_now = 0.;
	t_new = 0.;

	p1 = 4. / 3.;
	do {
	    p2 = p1 - 1.;
	    p3 = p2 + p2 + p2;
	    eps = abs(p3 - 1.);
	} while (eps == 0.);

	if (tol <= eps) tol = sqrt(eps);
	rndoff = eps*anorm;

	break_tol = 1.0e-7;

	sgn = sign(1., t);
	beta = cblas_dznrm2(n, w, 1);
	vnorm = beta;
	hump = beta;

	sqr1 = sqrt(0.1);
	xm = 1. / Doub(m);
	p2 = tol*pow((m + 1) / 2.72, m + 1)*sqrt(2.*3.14*(m + 1));
	t_new = (1. / anorm)*pow(p2 / (4.*beta*anorm), xm);
	p1 = pow(10., round(log10(t_new) - sqr1) - 1);
	t_new = trunc(t_new / p1 + 0.55) * p1;

	do {
	    if (t_now >= t_out)
	        break;

	    nstep = nstep + 1;
	    t_step = min(t_out - t_now, t_new);
	    p1 = 1. / beta;
	    for (i = 0; i < n; ++i)
	        wsp[iv + i] = p1*w[i];

	    for (i = 0; i < mh*mh; ++i)
	        wsp[ih + i] = zero;

	    j1v = iv + n;
	    Bool break_flag = false;
	    for (j = 0; j < m; ++j) {
	        nmult = nmult + 1;
	        expokit_mul(wsp + j1v, mat, wsp + j1v - n);
	        for (i = 0; i < j + 1; ++i) {
	            cblas_zdotc_sub(n, wsp + iv + i*n, 1, wsp + j1v, 1, &hij);
	            Comp temp = -hij;
	            cblas_zaxpy(n, &temp, wsp + iv + i*n, 1, wsp + j1v, 1);
	            wsp[ih + j*mh + i] = hij;
	        }
	        hj1j = cblas_dznrm2(n, wsp + j1v, 1);

	        if (hj1j <= break_tol) {
	            // std::cout << "happy breakdown: mbrkdwn = " << j + 1 << "h = " << hj1j << std::endl;
	            k1 = 0;
	            ibrkflag = 1;
	            mbrkdwn = j + 1;
	            tbrkdwn = t_now;
	            t_step = t_out - t_now;
	            break_flag = true;
	            break;
	        }
	        wsp[ih + j*mh + j + 1] = Comp(hj1j);
	        cblas_zdscal(n, 1. / hj1j, wsp + j1v, 1);
	        j1v += n;
	    }

	    if (!break_flag) {
	        nmult = nmult + 1;
	        expokit_mul(wsp + j1v, mat, wsp + j1v - n);
	        avnorm = cblas_dznrm2(n, wsp + j1v, 1);
	    }

	    wsp[ih + m*mh + m + 1] = one;
	    ireject = 0;

	    while (true) {
	        nexph = nexph + 1;
	        mx = mbrkdwn + k1;
	        if (ideg != 0) {
	            ZGPADM(ideg, mx, sgn*t_step, wsp + ih, mh,
	                wsp + ifree, lfree, iwsp, iexph, ns, iflag);
	            iexph += ifree;
	            nscale = nscale + ns;
	        }
	        else {
	            iexph = ifree;
	            for (i = 0; i < mx; ++i)
	                wsp[iexph + i] = zero;
	            wsp[iexph] = one;
	            ZNCHBV(mx, sgn*t_step, wsp + ih, mh, wsp + iexph, wsp + ifree + mx);
	        }

	        if (k1 == 0) {
	            err_loc = tol;
	        }
	        else {
	            p1 = abs(wsp[iexph + m])   * beta;
	            p2 = abs(wsp[iexph + m + 1]) * beta * avnorm;
	            if (p1 > 10.*p2) {
	                err_loc = p2;
	                xm = 1. / Doub(m);
	            }
	            else if (p1 > p2) {
	                err_loc = (p1*p2) / (p1 - p2);
	                xm = 1. / Doub(m);
	            }
	            else {
	                err_loc = p1;
	                xm = 1. / Doub(m - 1);
	            }
	        }

	        if ((k1 != 0) && (err_loc > delta*t_step*tol) &&
	            (mxreject == 0 || ireject < mxreject)) {
	            t_old = t_step;
	            t_step = gamma * t_step * pow(t_step*tol / err_loc, xm);
	            p1 = pow(10., round(log10(t_step) - sqr1) - 1);
	            t_step = trunc(t_step / p1 + 0.55) * p1;
	            if (itrace != 0) {
	                std::cout << "t_step = " << t_old << std::endl;
	                std::cout << "err_loc = " << err_loc << std::endl;
	                std::cout << "err_required =" << delta*t_old*tol << std::endl;
	                std::cout << "stepsize rejected, stepping down to:" << t_step << std::endl;
	            }
	            ireject = ireject + 1;
	            nreject = nreject + 1;
	            if (mxreject != 0 && ireject > mxreject) {
	                std::cout << "Failure in ZGEXPV: ---" << std::endl;
	                std::cout << "The requested tolerance is too high." << std::endl;
	                std::cout << "Rerun with a smaller value." << std::endl;
	                iflag = 2;
	                return;
	            }
	            continue;
	        }
	        break;
	    }

	    mx = mbrkdwn + max(0, k1 - 1);
	    hij = Comp(beta);
	    cblas_zgemv(CblasColMajor, CblasNoTrans, n, mx, &hij, wsp + iv, n, wsp + iexph, 1, &zero, w, 1);
	    beta = cblas_dznrm2(n, w, 1);
	    hump = max(hump, beta);

	    if (err_loc == 0)
	        t_new = p1 = 1e300;
	    else {
	        t_new = gamma * t_step * pow(t_step*tol / err_loc, xm);
	        p1 = pow(10., round(log10(t_new) - sqr1) - 1);
	        t_new = trunc(t_new / p1 + 0.55) * p1;
	    }

	    err_loc = max(err_loc, rndoff);

	    t_now = t_now + t_step;

	    if (itrace != 0) {
	        std::cout << "integration " << nstep << "---------------------------------" << std::endl;
	        std::cout << "scale-square = " << ns << std::endl;
	        std::cout << "step_size = " << t_step << std::endl;
	        std::cout << "err_loc   = " << err_loc << std::endl;
	        std::cout << "next_step = " << t_new << std::endl;
	    }

	    step_min = min(step_min, t_step);
	    step_max = max(step_max, t_step);
	    s_error = s_error + err_loc;
	    x_error = max(x_error, err_loc);

	} while (mxstep == 0 || nstep < mxstep);

	iflag = 1;

	iwsp[0] = nmult;
	iwsp[1] = nexph;
	iwsp[2] = nscale;
	iwsp[3] = nstep;
	iwsp[4] = nreject;
	iwsp[5] = ibrkflag;
	iwsp[6] = mbrkdwn;

	wsp[0] = Comp(step_min);
	wsp[1] = Comp(step_max);
	wsp[2] = Comp(0.);
	wsp[3] = Comp(0.);
	wsp[4] = Comp(x_error);
	wsp[5] = Comp(s_error);
	wsp[6] = Comp(tbrkdwn);
	wsp[7] = Comp(sgn*t_now);
	wsp[8] = Comp(hump / vnorm);
	wsp[9] = Comp(beta / vnorm);
}

inline void ZGEXPV(Int_I n, Int_I m, Doub_I t, Comp *w, Doub tol, Doub_I anorm,
	Comp *wsp, Int_I lwsp, Int *iwsp, Int_I liwsp, McooDoub_I mat, Int_I itrace, Int_O iflag)
{
#ifndef NDEBUG
	if (sum_abs_v(w, n) < 1e-100)
	    SLS_ERR("zero vector is not allowed!");
#endif
	const Int mxstep = 500, mxreject = 0, ideg = 6;
	Doub delta = 1.2, gamma = 0.9;


	const Comp zero = 0., one = 1.;

	Int i, j, k1, mh, mx, ih, j1v, ns, ifree, lfree, iexph,
	    ireject, ibrkflag, mbrkdwn, nmult, nreject, nexph, nscale,
	    nstep;
	Doub sgn, t_out, tbrkdwn, step_min, step_max, err_loc,
	    s_error, x_error, t_now, t_new, t_step, t_old,
	    xm, beta, break_tol, p1, p2, p3, eps, rndoff,
	    vnorm, avnorm=0, hj1j, hump, sqr1;
	Comp hij;
	iflag = 0;
	if (lwsp < n*(m + 2) + 5 * sqr(m + 2) + ideg + 1)
	    iflag = -1;
	if (liwsp < m + 2)
	    iflag = -2;
	if (m >= n || m <= 0)
	    iflag = -3;
	if (iflag != 0)
	    SLS_ERR("bad sizes (in input of ZGEXPV): iflag = " + num2str(iflag));

	k1 = 2;
	mh = m + 2;
	const Int iv = 0;
	ih = iv + n*(m + 1) + n;
	ifree = ih + mh*mh;
	lfree = lwsp - ifree;

	ibrkflag = 0;
	mbrkdwn = m;
	nmult = 0;
	nreject = 0;
	nexph = 0;
	nscale = 0;

	t_out = abs(t);
	tbrkdwn = 0.;
	step_min = t_out;
	step_max = 0.;
	nstep = 0;
	s_error = 0.;
	x_error = 0.;
	t_now = 0.;
	t_new = 0.;

	p1 = 4. / 3.;
	do {
	    p2 = p1 - 1.;
	    p3 = p2 + p2 + p2;
	    eps = abs(p3 - 1.);
	} while (eps == 0.);

	if (tol <= eps) tol = sqrt(eps);
	rndoff = eps*anorm;

	break_tol = 1.0e-7;

	sgn = sign(1., t);
	beta = cblas_dznrm2(n, w, 1);
	vnorm = beta;
	hump = beta;

	sqr1 = sqrt(0.1);
	xm = 1. / Doub(m);
	p2 = tol*pow((m + 1) / 2.72, m + 1)*sqrt(2.*3.14*(m + 1));
	t_new = (1. / anorm)*pow(p2 / (4.*beta*anorm), xm);
	p1 = pow(10., round(log10(t_new) - sqr1) - 1);
	t_new = trunc(t_new / p1 + 0.55) * p1;

	do {
	    if (t_now >= t_out)
	        break;

	    nstep = nstep + 1;
	    t_step = min(t_out - t_now, t_new);
	    p1 = 1. / beta;
	    for (i = 0; i < n; ++i)
	        wsp[iv + i] = p1*w[i];

	    for (i = 0; i < mh*mh; ++i)
	        wsp[ih + i] = zero;

	    j1v = iv + n;
	    Bool break_flag = false;
	    for (j = 0; j < m; ++j) {
	        nmult = nmult + 1;
	        expokit_mul(wsp + j1v, mat, wsp + j1v - n);
	        for (i = 0; i < j + 1; ++i) {
	            cblas_zdotc_sub(n, wsp + iv + i*n, 1, wsp + j1v, 1, &hij);
	            Comp temp = -hij;
	            cblas_zaxpy(n, &temp, wsp + iv + i*n, 1, wsp + j1v, 1);
	            wsp[ih + j*mh + i] = hij;
	        }
	        hj1j = cblas_dznrm2(n, wsp + j1v, 1);

	        if (hj1j <= break_tol) {
	            // std::cout << "happy breakdown: mbrkdwn = " << j + 1 << "h = " << hj1j << std::endl;
	            k1 = 0;
	            ibrkflag = 1;
	            mbrkdwn = j + 1;
	            tbrkdwn = t_now;
	            t_step = t_out - t_now;
	            break_flag = true;
	            break;
	        }
	        wsp[ih + j*mh + j + 1] = Comp(hj1j);
	        cblas_zdscal(n, 1. / hj1j, wsp + j1v, 1);
	        j1v += n;
	    }

	    if (!break_flag) {
	        nmult = nmult + 1;
	        expokit_mul(wsp + j1v, mat, wsp + j1v - n);
	        avnorm = cblas_dznrm2(n, wsp + j1v, 1);
	    }

	    wsp[ih + m*mh + m + 1] = one;
	    ireject = 0;

	    while (true) {
	        nexph = nexph + 1;
	        mx = mbrkdwn + k1;
	        if (ideg != 0) {
	            ZGPADM(ideg, mx, sgn*t_step, wsp + ih, mh,
	                wsp + ifree, lfree, iwsp, iexph, ns, iflag);
	            iexph += ifree;
	            nscale = nscale + ns;
	        }
	        else {
	            iexph = ifree;
	            for (i = 0; i < mx; ++i)
	                wsp[iexph + i] = zero;
	            wsp[iexph] = one;
	            ZNCHBV(mx, sgn*t_step, wsp + ih, mh, wsp + iexph, wsp + ifree + mx);
	        }

	        if (k1 == 0) {
	            err_loc = tol;
	        }
	        else {
	            p1 = abs(wsp[iexph + m])   * beta;
	            p2 = abs(wsp[iexph + m + 1]) * beta * avnorm;
	            if (p1 > 10.*p2) {
	                err_loc = p2;
	                xm = 1. / Doub(m);
	            }
	            else if (p1 > p2) {
	                err_loc = (p1*p2) / (p1 - p2);
	                xm = 1. / Doub(m);
	            }
	            else {
	                err_loc = p1;
	                xm = 1. / Doub(m - 1);
	            }
	        }

	        if ((k1 != 0) && (err_loc > delta*t_step*tol) &&
	            (mxreject == 0 || ireject < mxreject)) {
	            t_old = t_step;
	            t_step = gamma * t_step * pow(t_step*tol / err_loc, xm);
	            p1 = pow(10., round(log10(t_step) - sqr1) - 1);
	            t_step = trunc(t_step / p1 + 0.55) * p1;
	            if (itrace != 0) {
	                std::cout << "t_step = " << t_old << std::endl;
	                std::cout << "err_loc = " << err_loc << std::endl;
	                std::cout << "err_required =" << delta*t_old*tol << std::endl;
	                std::cout << "stepsize rejected, stepping down to:" << t_step << std::endl;
	            }
	            ireject = ireject + 1;
	            nreject = nreject + 1;
	            if (mxreject != 0 && ireject > mxreject) {
	                std::cout << "Failure in ZGEXPV: ---" << std::endl;
	                std::cout << "The requested tolerance is too high." << std::endl;
	                std::cout << "Rerun with a smaller value." << std::endl;
	                iflag = 2;
	                return;
	            }
	            continue;
	        }
	        break;
	    }

	    mx = mbrkdwn + max(0, k1 - 1);
	    hij = Comp(beta);
	    cblas_zgemv(CblasColMajor, CblasNoTrans, n, mx, &hij, wsp + iv, n, wsp + iexph, 1, &zero, w, 1);
	    beta = cblas_dznrm2(n, w, 1);
	    hump = max(hump, beta);

	    if (err_loc == 0)
	        t_new = p1 = 1e300;
	    else {
	        t_new = gamma * t_step * pow(t_step*tol / err_loc, xm);
	        p1 = pow(10., round(log10(t_new) - sqr1) - 1);
	        t_new = trunc(t_new / p1 + 0.55) * p1;
	    }

	    err_loc = max(err_loc, rndoff);

	    t_now = t_now + t_step;

	    if (itrace != 0) {
	        std::cout << "integration " << nstep << "---------------------------------" << std::endl;
	        std::cout << "scale-square = " << ns << std::endl;
	        std::cout << "step_size = " << t_step << std::endl;
	        std::cout << "err_loc   = " << err_loc << std::endl;
	        std::cout << "next_step = " << t_new << std::endl;
	    }

	    step_min = min(step_min, t_step);
	    step_max = max(step_max, t_step);
	    s_error = s_error + err_loc;
	    x_error = max(x_error, err_loc);

	} while (mxstep == 0 || nstep < mxstep);

	iflag = 1;

	iwsp[0] = nmult;
	iwsp[1] = nexph;
	iwsp[2] = nscale;
	iwsp[3] = nstep;
	iwsp[4] = nreject;
	iwsp[5] = ibrkflag;
	iwsp[6] = mbrkdwn;

	wsp[0] = Comp(step_min);
	wsp[1] = Comp(step_max);
	wsp[2] = Comp(0.);
	wsp[3] = Comp(0.);
	wsp[4] = Comp(x_error);
	wsp[5] = Comp(s_error);
	wsp[6] = Comp(tbrkdwn);
	wsp[7] = Comp(sgn*t_now);
	wsp[8] = Comp(hump / vnorm);
	wsp[9] = Comp(beta / vnorm);
}

inline void ZGEXPV(Int_I n, Int_I m, Doub_I t, Comp *w, Doub tol, Doub_I anorm,
	Comp *wsp, Int_I lwsp, Int *iwsp, Int_I liwsp, McooComp_I mat, Int_I itrace, Int_O iflag)
{
#ifndef NDEBUG
	if (sum_abs_v(w, n) < 1e-100)
	    SLS_ERR("zero vector is not allowed!");
#endif
	const Int mxstep = 500, mxreject = 0, ideg = 6;
	Doub delta = 1.2, gamma = 0.9;


	const Comp zero = 0., one = 1.;

	Int i, j, k1, mh, mx, ih, j1v, ns, ifree, lfree, iexph,
	    ireject, ibrkflag, mbrkdwn, nmult, nreject, nexph, nscale,
	    nstep;
	Doub sgn, t_out, tbrkdwn, step_min, step_max, err_loc,
	    s_error, x_error, t_now, t_new, t_step, t_old,
	    xm, beta, break_tol, p1, p2, p3, eps, rndoff,
	    vnorm, avnorm=0, hj1j, hump, sqr1;
	Comp hij;
	iflag = 0;
	if (lwsp < n*(m + 2) + 5 * sqr(m + 2) + ideg + 1)
	    iflag = -1;
	if (liwsp < m + 2)
	    iflag = -2;
	if (m >= n || m <= 0)
	    iflag = -3;
	if (iflag != 0)
	    SLS_ERR("bad sizes (in input of ZGEXPV): iflag = " + num2str(iflag));

	k1 = 2;
	mh = m + 2;
	const Int iv = 0;
	ih = iv + n*(m + 1) + n;
	ifree = ih + mh*mh;
	lfree = lwsp - ifree;

	ibrkflag = 0;
	mbrkdwn = m;
	nmult = 0;
	nreject = 0;
	nexph = 0;
	nscale = 0;

	t_out = abs(t);
	tbrkdwn = 0.;
	step_min = t_out;
	step_max = 0.;
	nstep = 0;
	s_error = 0.;
	x_error = 0.;
	t_now = 0.;
	t_new = 0.;

	p1 = 4. / 3.;
	do {
	    p2 = p1 - 1.;
	    p3 = p2 + p2 + p2;
	    eps = abs(p3 - 1.);
	} while (eps == 0.);

	if (tol <= eps) tol = sqrt(eps);
	rndoff = eps*anorm;

	break_tol = 1.0e-7;

	sgn = sign(1., t);
	beta = cblas_dznrm2(n, w, 1);
	vnorm = beta;
	hump = beta;

	sqr1 = sqrt(0.1);
	xm = 1. / Doub(m);
	p2 = tol*pow((m + 1) / 2.72, m + 1)*sqrt(2.*3.14*(m + 1));
	t_new = (1. / anorm)*pow(p2 / (4.*beta*anorm), xm);
	p1 = pow(10., round(log10(t_new) - sqr1) - 1);
	t_new = trunc(t_new / p1 + 0.55) * p1;

	do {
	    if (t_now >= t_out)
	        break;

	    nstep = nstep + 1;
	    t_step = min(t_out - t_now, t_new);
	    p1 = 1. / beta;
	    for (i = 0; i < n; ++i)
	        wsp[iv + i] = p1*w[i];

	    for (i = 0; i < mh*mh; ++i)
	        wsp[ih + i] = zero;

	    j1v = iv + n;
	    Bool break_flag = false;
	    for (j = 0; j < m; ++j) {
	        nmult = nmult + 1;
	        expokit_mul(wsp + j1v, mat, wsp + j1v - n);
	        for (i = 0; i < j + 1; ++i) {
	            cblas_zdotc_sub(n, wsp + iv + i*n, 1, wsp + j1v, 1, &hij);
	            Comp temp = -hij;
	            cblas_zaxpy(n, &temp, wsp + iv + i*n, 1, wsp + j1v, 1);
	            wsp[ih + j*mh + i] = hij;
	        }
	        hj1j = cblas_dznrm2(n, wsp + j1v, 1);

	        if (hj1j <= break_tol) {
	            // std::cout << "happy breakdown: mbrkdwn = " << j + 1 << "h = " << hj1j << std::endl;
	            k1 = 0;
	            ibrkflag = 1;
	            mbrkdwn = j + 1;
	            tbrkdwn = t_now;
	            t_step = t_out - t_now;
	            break_flag = true;
	            break;
	        }
	        wsp[ih + j*mh + j + 1] = Comp(hj1j);
	        cblas_zdscal(n, 1. / hj1j, wsp + j1v, 1);
	        j1v += n;
	    }

	    if (!break_flag) {
	        nmult = nmult + 1;
	        expokit_mul(wsp + j1v, mat, wsp + j1v - n);
	        avnorm = cblas_dznrm2(n, wsp + j1v, 1);
	    }

	    wsp[ih + m*mh + m + 1] = one;
	    ireject = 0;

	    while (true) {
	        nexph = nexph + 1;
	        mx = mbrkdwn + k1;
	        if (ideg != 0) {
	            ZGPADM(ideg, mx, sgn*t_step, wsp + ih, mh,
	                wsp + ifree, lfree, iwsp, iexph, ns, iflag);
	            iexph += ifree;
	            nscale = nscale + ns;
	        }
	        else {
	            iexph = ifree;
	            for (i = 0; i < mx; ++i)
	                wsp[iexph + i] = zero;
	            wsp[iexph] = one;
	            ZNCHBV(mx, sgn*t_step, wsp + ih, mh, wsp + iexph, wsp + ifree + mx);
	        }

	        if (k1 == 0) {
	            err_loc = tol;
	        }
	        else {
	            p1 = abs(wsp[iexph + m])   * beta;
	            p2 = abs(wsp[iexph + m + 1]) * beta * avnorm;
	            if (p1 > 10.*p2) {
	                err_loc = p2;
	                xm = 1. / Doub(m);
	            }
	            else if (p1 > p2) {
	                err_loc = (p1*p2) / (p1 - p2);
	                xm = 1. / Doub(m);
	            }
	            else {
	                err_loc = p1;
	                xm = 1. / Doub(m - 1);
	            }
	        }

	        if ((k1 != 0) && (err_loc > delta*t_step*tol) &&
	            (mxreject == 0 || ireject < mxreject)) {
	            t_old = t_step;
	            t_step = gamma * t_step * pow(t_step*tol / err_loc, xm);
	            p1 = pow(10., round(log10(t_step) - sqr1) - 1);
	            t_step = trunc(t_step / p1 + 0.55) * p1;
	            if (itrace != 0) {
	                std::cout << "t_step = " << t_old << std::endl;
	                std::cout << "err_loc = " << err_loc << std::endl;
	                std::cout << "err_required =" << delta*t_old*tol << std::endl;
	                std::cout << "stepsize rejected, stepping down to:" << t_step << std::endl;
	            }
	            ireject = ireject + 1;
	            nreject = nreject + 1;
	            if (mxreject != 0 && ireject > mxreject) {
	                std::cout << "Failure in ZGEXPV: ---" << std::endl;
	                std::cout << "The requested tolerance is too high." << std::endl;
	                std::cout << "Rerun with a smaller value." << std::endl;
	                iflag = 2;
	                return;
	            }
	            continue;
	        }
	        break;
	    }

	    mx = mbrkdwn + max(0, k1 - 1);
	    hij = Comp(beta);
	    cblas_zgemv(CblasColMajor, CblasNoTrans, n, mx, &hij, wsp + iv, n, wsp + iexph, 1, &zero, w, 1);
	    beta = cblas_dznrm2(n, w, 1);
	    hump = max(hump, beta);

	    if (err_loc == 0)
	        t_new = p1 = 1e300;
	    else {
	        t_new = gamma * t_step * pow(t_step*tol / err_loc, xm);
	        p1 = pow(10., round(log10(t_new) - sqr1) - 1);
	        t_new = trunc(t_new / p1 + 0.55) * p1;
	    }

	    err_loc = max(err_loc, rndoff);

	    t_now = t_now + t_step;

	    if (itrace != 0) {
	        std::cout << "integration " << nstep << "---------------------------------" << std::endl;
	        std::cout << "scale-square = " << ns << std::endl;
	        std::cout << "step_size = " << t_step << std::endl;
	        std::cout << "err_loc   = " << err_loc << std::endl;
	        std::cout << "next_step = " << t_new << std::endl;
	    }

	    step_min = min(step_min, t_step);
	    step_max = max(step_max, t_step);
	    s_error = s_error + err_loc;
	    x_error = max(x_error, err_loc);

	} while (mxstep == 0 || nstep < mxstep);

	iflag = 1;

	iwsp[0] = nmult;
	iwsp[1] = nexph;
	iwsp[2] = nscale;
	iwsp[3] = nstep;
	iwsp[4] = nreject;
	iwsp[5] = ibrkflag;
	iwsp[6] = mbrkdwn;

	wsp[0] = Comp(step_min);
	wsp[1] = Comp(step_max);
	wsp[2] = Comp(0.);
	wsp[3] = Comp(0.);
	wsp[4] = Comp(x_error);
	wsp[5] = Comp(s_error);
	wsp[6] = Comp(tbrkdwn);
	wsp[7] = Comp(sgn*t_now);
	wsp[8] = Comp(hump / vnorm);
	wsp[9] = Comp(beta / vnorm);
}

inline void ZGEXPV(Int_I n, Int_I m, Doub_I t, Comp *w, Doub tol, Doub_I anorm,
	Comp *wsp, Int_I lwsp, Int *iwsp, Int_I liwsp, CmatDoub_I mat, Int_I itrace, Int_O iflag)
{
#ifndef NDEBUG
	if (sum_abs_v(w, n) < 1e-100)
	    SLS_ERR("zero vector is not allowed!");
#endif
	const Int mxstep = 500, mxreject = 0, ideg = 6;
	Doub delta = 1.2, gamma = 0.9;


	const Comp zero = 0., one = 1.;

	Int i, j, k1, mh, mx, ih, j1v, ns, ifree, lfree, iexph,
	    ireject, ibrkflag, mbrkdwn, nmult, nreject, nexph, nscale,
	    nstep;
	Doub sgn, t_out, tbrkdwn, step_min, step_max, err_loc,
	    s_error, x_error, t_now, t_new, t_step, t_old,
	    xm, beta, break_tol, p1, p2, p3, eps, rndoff,
	    vnorm, avnorm=0, hj1j, hump, sqr1;
	Comp hij;
	iflag = 0;
	if (lwsp < n*(m + 2) + 5 * sqr(m + 2) + ideg + 1)
	    iflag = -1;
	if (liwsp < m + 2)
	    iflag = -2;
	if (m >= n || m <= 0)
	    iflag = -3;
	if (iflag != 0)
	    SLS_ERR("bad sizes (in input of ZGEXPV): iflag = " + num2str(iflag));

	k1 = 2;
	mh = m + 2;
	const Int iv = 0;
	ih = iv + n*(m + 1) + n;
	ifree = ih + mh*mh;
	lfree = lwsp - ifree;

	ibrkflag = 0;
	mbrkdwn = m;
	nmult = 0;
	nreject = 0;
	nexph = 0;
	nscale = 0;

	t_out = abs(t);
	tbrkdwn = 0.;
	step_min = t_out;
	step_max = 0.;
	nstep = 0;
	s_error = 0.;
	x_error = 0.;
	t_now = 0.;
	t_new = 0.;

	p1 = 4. / 3.;
	do {
	    p2 = p1 - 1.;
	    p3 = p2 + p2 + p2;
	    eps = abs(p3 - 1.);
	} while (eps == 0.);

	if (tol <= eps) tol = sqrt(eps);
	rndoff = eps*anorm;

	break_tol = 1.0e-7;

	sgn = sign(1., t);
	beta = cblas_dznrm2(n, w, 1);
	vnorm = beta;
	hump = beta;

	sqr1 = sqrt(0.1);
	xm = 1. / Doub(m);
	p2 = tol*pow((m + 1) / 2.72, m + 1)*sqrt(2.*3.14*(m + 1));
	t_new = (1. / anorm)*pow(p2 / (4.*beta*anorm), xm);
	p1 = pow(10., round(log10(t_new) - sqr1) - 1);
	t_new = trunc(t_new / p1 + 0.55) * p1;

	do {
	    if (t_now >= t_out)
	        break;

	    nstep = nstep + 1;
	    t_step = min(t_out - t_now, t_new);
	    p1 = 1. / beta;
	    for (i = 0; i < n; ++i)
	        wsp[iv + i] = p1*w[i];

	    for (i = 0; i < mh*mh; ++i)
	        wsp[ih + i] = zero;

	    j1v = iv + n;
	    Bool break_flag = false;
	    for (j = 0; j < m; ++j) {
	        nmult = nmult + 1;
	        expokit_mul(wsp + j1v, mat, wsp + j1v - n);
	        for (i = 0; i < j + 1; ++i) {
	            cblas_zdotc_sub(n, wsp + iv + i*n, 1, wsp + j1v, 1, &hij);
	            Comp temp = -hij;
	            cblas_zaxpy(n, &temp, wsp + iv + i*n, 1, wsp + j1v, 1);
	            wsp[ih + j*mh + i] = hij;
	        }
	        hj1j = cblas_dznrm2(n, wsp + j1v, 1);

	        if (hj1j <= break_tol) {
	            // std::cout << "happy breakdown: mbrkdwn = " << j + 1 << "h = " << hj1j << std::endl;
	            k1 = 0;
	            ibrkflag = 1;
	            mbrkdwn = j + 1;
	            tbrkdwn = t_now;
	            t_step = t_out - t_now;
	            break_flag = true;
	            break;
	        }
	        wsp[ih + j*mh + j + 1] = Comp(hj1j);
	        cblas_zdscal(n, 1. / hj1j, wsp + j1v, 1);
	        j1v += n;
	    }

	    if (!break_flag) {
	        nmult = nmult + 1;
	        expokit_mul(wsp + j1v, mat, wsp + j1v - n);
	        avnorm = cblas_dznrm2(n, wsp + j1v, 1);
	    }

	    wsp[ih + m*mh + m + 1] = one;
	    ireject = 0;

	    while (true) {
	        nexph = nexph + 1;
	        mx = mbrkdwn + k1;
	        if (ideg != 0) {
	            ZGPADM(ideg, mx, sgn*t_step, wsp + ih, mh,
	                wsp + ifree, lfree, iwsp, iexph, ns, iflag);
	            iexph += ifree;
	            nscale = nscale + ns;
	        }
	        else {
	            iexph = ifree;
	            for (i = 0; i < mx; ++i)
	                wsp[iexph + i] = zero;
	            wsp[iexph] = one;
	            ZNCHBV(mx, sgn*t_step, wsp + ih, mh, wsp + iexph, wsp + ifree + mx);
	        }

	        if (k1 == 0) {
	            err_loc = tol;
	        }
	        else {
	            p1 = abs(wsp[iexph + m])   * beta;
	            p2 = abs(wsp[iexph + m + 1]) * beta * avnorm;
	            if (p1 > 10.*p2) {
	                err_loc = p2;
	                xm = 1. / Doub(m);
	            }
	            else if (p1 > p2) {
	                err_loc = (p1*p2) / (p1 - p2);
	                xm = 1. / Doub(m);
	            }
	            else {
	                err_loc = p1;
	                xm = 1. / Doub(m - 1);
	            }
	        }

	        if ((k1 != 0) && (err_loc > delta*t_step*tol) &&
	            (mxreject == 0 || ireject < mxreject)) {
	            t_old = t_step;
	            t_step = gamma * t_step * pow(t_step*tol / err_loc, xm);
	            p1 = pow(10., round(log10(t_step) - sqr1) - 1);
	            t_step = trunc(t_step / p1 + 0.55) * p1;
	            if (itrace != 0) {
	                std::cout << "t_step = " << t_old << std::endl;
	                std::cout << "err_loc = " << err_loc << std::endl;
	                std::cout << "err_required =" << delta*t_old*tol << std::endl;
	                std::cout << "stepsize rejected, stepping down to:" << t_step << std::endl;
	            }
	            ireject = ireject + 1;
	            nreject = nreject + 1;
	            if (mxreject != 0 && ireject > mxreject) {
	                std::cout << "Failure in ZGEXPV: ---" << std::endl;
	                std::cout << "The requested tolerance is too high." << std::endl;
	                std::cout << "Rerun with a smaller value." << std::endl;
	                iflag = 2;
	                return;
	            }
	            continue;
	        }
	        break;
	    }

	    mx = mbrkdwn + max(0, k1 - 1);
	    hij = Comp(beta);
	    cblas_zgemv(CblasColMajor, CblasNoTrans, n, mx, &hij, wsp + iv, n, wsp + iexph, 1, &zero, w, 1);
	    beta = cblas_dznrm2(n, w, 1);
	    hump = max(hump, beta);

	    if (err_loc == 0)
	        t_new = p1 = 1e300;
	    else {
	        t_new = gamma * t_step * pow(t_step*tol / err_loc, xm);
	        p1 = pow(10., round(log10(t_new) - sqr1) - 1);
	        t_new = trunc(t_new / p1 + 0.55) * p1;
	    }

	    err_loc = max(err_loc, rndoff);

	    t_now = t_now + t_step;

	    if (itrace != 0) {
	        std::cout << "integration " << nstep << "---------------------------------" << std::endl;
	        std::cout << "scale-square = " << ns << std::endl;
	        std::cout << "step_size = " << t_step << std::endl;
	        std::cout << "err_loc   = " << err_loc << std::endl;
	        std::cout << "next_step = " << t_new << std::endl;
	    }

	    step_min = min(step_min, t_step);
	    step_max = max(step_max, t_step);
	    s_error = s_error + err_loc;
	    x_error = max(x_error, err_loc);

	} while (mxstep == 0 || nstep < mxstep);

	iflag = 1;

	iwsp[0] = nmult;
	iwsp[1] = nexph;
	iwsp[2] = nscale;
	iwsp[3] = nstep;
	iwsp[4] = nreject;
	iwsp[5] = ibrkflag;
	iwsp[6] = mbrkdwn;

	wsp[0] = Comp(step_min);
	wsp[1] = Comp(step_max);
	wsp[2] = Comp(0.);
	wsp[3] = Comp(0.);
	wsp[4] = Comp(x_error);
	wsp[5] = Comp(s_error);
	wsp[6] = Comp(tbrkdwn);
	wsp[7] = Comp(sgn*t_now);
	wsp[8] = Comp(hump / vnorm);
	wsp[9] = Comp(beta / vnorm);
}

inline void ZGEXPV(Int_I n, Int_I m, Doub_I t, Comp *w, Doub tol, Doub_I anorm,
	Comp *wsp, Int_I lwsp, Int *iwsp, Int_I liwsp, CmatComp_I mat, Int_I itrace, Int_O iflag)
{
#ifndef NDEBUG
	if (sum_abs_v(w, n) < 1e-100)
	    SLS_ERR("zero vector is not allowed!");
#endif
	const Int mxstep = 500, mxreject = 0, ideg = 6;
	Doub delta = 1.2, gamma = 0.9;


	const Comp zero = 0., one = 1.;

	Int i, j, k1, mh, mx, ih, j1v, ns, ifree, lfree, iexph,
	    ireject, ibrkflag, mbrkdwn, nmult, nreject, nexph, nscale,
	    nstep;
	Doub sgn, t_out, tbrkdwn, step_min, step_max, err_loc,
	    s_error, x_error, t_now, t_new, t_step, t_old,
	    xm, beta, break_tol, p1, p2, p3, eps, rndoff,
	    vnorm, avnorm=0, hj1j, hump, sqr1;
	Comp hij;
	iflag = 0;
	if (lwsp < n*(m + 2) + 5 * sqr(m + 2) + ideg + 1)
	    iflag = -1;
	if (liwsp < m + 2)
	    iflag = -2;
	if (m >= n || m <= 0)
	    iflag = -3;
	if (iflag != 0)
	    SLS_ERR("bad sizes (in input of ZGEXPV): iflag = " + num2str(iflag));

	k1 = 2;
	mh = m + 2;
	const Int iv = 0;
	ih = iv + n*(m + 1) + n;
	ifree = ih + mh*mh;
	lfree = lwsp - ifree;

	ibrkflag = 0;
	mbrkdwn = m;
	nmult = 0;
	nreject = 0;
	nexph = 0;
	nscale = 0;

	t_out = abs(t);
	tbrkdwn = 0.;
	step_min = t_out;
	step_max = 0.;
	nstep = 0;
	s_error = 0.;
	x_error = 0.;
	t_now = 0.;
	t_new = 0.;

	p1 = 4. / 3.;
	do {
	    p2 = p1 - 1.;
	    p3 = p2 + p2 + p2;
	    eps = abs(p3 - 1.);
	} while (eps == 0.);

	if (tol <= eps) tol = sqrt(eps);
	rndoff = eps*anorm;

	break_tol = 1.0e-7;

	sgn = sign(1., t);
	beta = cblas_dznrm2(n, w, 1);
	vnorm = beta;
	hump = beta;

	sqr1 = sqrt(0.1);
	xm = 1. / Doub(m);
	p2 = tol*pow((m + 1) / 2.72, m + 1)*sqrt(2.*3.14*(m + 1));
	t_new = (1. / anorm)*pow(p2 / (4.*beta*anorm), xm);
	p1 = pow(10., round(log10(t_new) - sqr1) - 1);
	t_new = trunc(t_new / p1 + 0.55) * p1;

	do {
	    if (t_now >= t_out)
	        break;

	    nstep = nstep + 1;
	    t_step = min(t_out - t_now, t_new);
	    p1 = 1. / beta;
	    for (i = 0; i < n; ++i)
	        wsp[iv + i] = p1*w[i];

	    for (i = 0; i < mh*mh; ++i)
	        wsp[ih + i] = zero;

	    j1v = iv + n;
	    Bool break_flag = false;
	    for (j = 0; j < m; ++j) {
	        nmult = nmult + 1;
	        expokit_mul(wsp + j1v, mat, wsp + j1v - n);
	        for (i = 0; i < j + 1; ++i) {
	            cblas_zdotc_sub(n, wsp + iv + i*n, 1, wsp + j1v, 1, &hij);
	            Comp temp = -hij;
	            cblas_zaxpy(n, &temp, wsp + iv + i*n, 1, wsp + j1v, 1);
	            wsp[ih + j*mh + i] = hij;
	        }
	        hj1j = cblas_dznrm2(n, wsp + j1v, 1);

	        if (hj1j <= break_tol) {
	            // std::cout << "happy breakdown: mbrkdwn = " << j + 1 << "h = " << hj1j << std::endl;
	            k1 = 0;
	            ibrkflag = 1;
	            mbrkdwn = j + 1;
	            tbrkdwn = t_now;
	            t_step = t_out - t_now;
	            break_flag = true;
	            break;
	        }
	        wsp[ih + j*mh + j + 1] = Comp(hj1j);
	        cblas_zdscal(n, 1. / hj1j, wsp + j1v, 1);
	        j1v += n;
	    }

	    if (!break_flag) {
	        nmult = nmult + 1;
	        expokit_mul(wsp + j1v, mat, wsp + j1v - n);
	        avnorm = cblas_dznrm2(n, wsp + j1v, 1);
	    }

	    wsp[ih + m*mh + m + 1] = one;
	    ireject = 0;

	    while (true) {
	        nexph = nexph + 1;
	        mx = mbrkdwn + k1;
	        if (ideg != 0) {
	            ZGPADM(ideg, mx, sgn*t_step, wsp + ih, mh,
	                wsp + ifree, lfree, iwsp, iexph, ns, iflag);
	            iexph += ifree;
	            nscale = nscale + ns;
	        }
	        else {
	            iexph = ifree;
	            for (i = 0; i < mx; ++i)
	                wsp[iexph + i] = zero;
	            wsp[iexph] = one;
	            ZNCHBV(mx, sgn*t_step, wsp + ih, mh, wsp + iexph, wsp + ifree + mx);
	        }

	        if (k1 == 0) {
	            err_loc = tol;
	        }
	        else {
	            p1 = abs(wsp[iexph + m])   * beta;
	            p2 = abs(wsp[iexph + m + 1]) * beta * avnorm;
	            if (p1 > 10.*p2) {
	                err_loc = p2;
	                xm = 1. / Doub(m);
	            }
	            else if (p1 > p2) {
	                err_loc = (p1*p2) / (p1 - p2);
	                xm = 1. / Doub(m);
	            }
	            else {
	                err_loc = p1;
	                xm = 1. / Doub(m - 1);
	            }
	        }

	        if ((k1 != 0) && (err_loc > delta*t_step*tol) &&
	            (mxreject == 0 || ireject < mxreject)) {
	            t_old = t_step;
	            t_step = gamma * t_step * pow(t_step*tol / err_loc, xm);
	            p1 = pow(10., round(log10(t_step) - sqr1) - 1);
	            t_step = trunc(t_step / p1 + 0.55) * p1;
	            if (itrace != 0) {
	                std::cout << "t_step = " << t_old << std::endl;
	                std::cout << "err_loc = " << err_loc << std::endl;
	                std::cout << "err_required =" << delta*t_old*tol << std::endl;
	                std::cout << "stepsize rejected, stepping down to:" << t_step << std::endl;
	            }
	            ireject = ireject + 1;
	            nreject = nreject + 1;
	            if (mxreject != 0 && ireject > mxreject) {
	                std::cout << "Failure in ZGEXPV: ---" << std::endl;
	                std::cout << "The requested tolerance is too high." << std::endl;
	                std::cout << "Rerun with a smaller value." << std::endl;
	                iflag = 2;
	                return;
	            }
	            continue;
	        }
	        break;
	    }

	    mx = mbrkdwn + max(0, k1 - 1);
	    hij = Comp(beta);
	    cblas_zgemv(CblasColMajor, CblasNoTrans, n, mx, &hij, wsp + iv, n, wsp + iexph, 1, &zero, w, 1);
	    beta = cblas_dznrm2(n, w, 1);
	    hump = max(hump, beta);

	    if (err_loc == 0)
	        t_new = p1 = 1e300;
	    else {
	        t_new = gamma * t_step * pow(t_step*tol / err_loc, xm);
	        p1 = pow(10., round(log10(t_new) - sqr1) - 1);
	        t_new = trunc(t_new / p1 + 0.55) * p1;
	    }

	    err_loc = max(err_loc, rndoff);

	    t_now = t_now + t_step;

	    if (itrace != 0) {
	        std::cout << "integration " << nstep << "---------------------------------" << std::endl;
	        std::cout << "scale-square = " << ns << std::endl;
	        std::cout << "step_size = " << t_step << std::endl;
	        std::cout << "err_loc   = " << err_loc << std::endl;
	        std::cout << "next_step = " << t_new << std::endl;
	    }

	    step_min = min(step_min, t_step);
	    step_max = max(step_max, t_step);
	    s_error = s_error + err_loc;
	    x_error = max(x_error, err_loc);

	} while (mxstep == 0 || nstep < mxstep);

	iflag = 1;

	iwsp[0] = nmult;
	iwsp[1] = nexph;
	iwsp[2] = nscale;
	iwsp[3] = nstep;
	iwsp[4] = nreject;
	iwsp[5] = ibrkflag;
	iwsp[6] = mbrkdwn;

	wsp[0] = Comp(step_min);
	wsp[1] = Comp(step_max);
	wsp[2] = Comp(0.);
	wsp[3] = Comp(0.);
	wsp[4] = Comp(x_error);
	wsp[5] = Comp(s_error);
	wsp[6] = Comp(tbrkdwn);
	wsp[7] = Comp(sgn*t_now);
	wsp[8] = Comp(hump / vnorm);
	wsp[9] = Comp(beta / vnorm);
}


// ======== translation details ============
// variables that subtracted 1 comparing to F77 version
// internal variables: i, j, ifree, ih, j1v, iv, iexph
// `T` can be any user defined matrix class
// expokit_mul(Comp *y, const T &mat, Comp *x) must be defined to perform matrix-vector multiplication (y = mat * x)

// ======== modifications ==================
// modified so that w is both input and output vector

inline void ZHEXPV(Int_I n, Int_I m, Doub_I t, Comp *w, Doub tol, Doub_I anorm,
	        Comp *wsp, Int_I lwsp, Int *iwsp, Int_I liwsp, CmobdDoub_I mat, Int_I itrace, Int_O iflag )
{
#ifndef NDEBUG
	if (sum_abs_v(w, n) < 1e-100)
	    SLS_ERR("zero vector is not allowed!");
#endif
	const Int mxstep = 500, mxreject = 0, ideg = 6;
	Doub delta = 1.2, gamma = 0.9;

	const Comp zero = 0., one = 1.;

	Int i, j, k1, mh, mx, ih, j1v, ns, ifree, lfree, iexph,
	    ireject, ibrkflag, mbrkdwn, nmult, nreject, nexph, nscale,
	    nstep;
	Doub sgn, t_out, tbrkdwn, step_min, step_max, err_loc,
	    s_error, x_error, t_now, t_new, t_step, t_old,
	    xm, beta, break_tol, p1, p2, p3, eps, rndoff,
	    vnorm, avnorm=0, hj1j, hump, sqr1;
	Comp hjj, temp;

	iflag = 0;
	if ( lwsp < n*(m+2)+5*sqr(m+2)+ideg+2 )
	    iflag = -1;
	if (liwsp < m + 2)
	    iflag = -2;
	if (m >= n || m <= 0)
	    iflag = -3;
	if (iflag != 0)
	    SLS_ERR("bad sizes (in input of DHEXPV): iflag = " + num2str(iflag));

	k1 = 2;
	mh = m + 2;
	const Int iv = 0;
	ih = iv + n * (m + 1) + n;
	ifree = ih + mh * mh;
	lfree = lwsp - ifree - 1;

	ibrkflag = 0;
	mbrkdwn = m;
	nmult = 0;
	nreject = 0;
	nexph = 0;
	nscale = 0;

	t_out = abs(t);
	tbrkdwn = 0.;
	step_min = t_out;
	step_max = 0.;
	nstep = 0;
	s_error = 0.;
	x_error = 0.;
	t_now = 0.;
	t_new = 0.;

	p1 = 4. / 3.;
	do {
	    /*1*/  p2 = p1 - 1.;
	    p3 = p2 + p2 + p2;
	    eps = abs(p3 - 1.);
	} while (eps == 0.);

	if (tol <= eps) tol = sqrt(eps);
	rndoff = eps * anorm;

	break_tol = 1e-7;

	sgn = sign(1., t);
	beta = cblas_dznrm2(n, w, 1);
	vnorm = beta;
	hump = beta;

	sqr1 = sqrt(0.1);
	xm = 1. / Doub(m);
	p2 = tol * (pow((m + 1) / 2.72, m + 1))*sqrt(2.*3.14*(m + 1));
	t_new = (1. / anorm)*pow((p2 / (4.*beta*anorm)), xm);
	p1 = pow(10., round(log10(t_new) - sqr1) - 1);
	t_new = trunc(t_new / p1 + 0.55) * p1;


	/*100*/ do {
	    if (t_now >= t_out)
	        break;

	    nstep = nstep + 1;
	    t_step = min(t_out - t_now, t_new);
	    beta = cblas_dznrm2(n, w, 1);
	    p1 = 1. / beta;
	    for (i = 0; i < n; ++i) {
	        wsp[iv + i] = p1 * w[i];
	    }
	    for (i = 0; i < mh * mh; ++i) {
	        wsp[ih + i] = zero;
	    }

	    j1v = iv + n;
	    Bool break_flag = false;
	    for (j = 0; j < m; ++j) {
	        nmult = nmult + 1;
	        expokit_mul(wsp + j1v, mat, wsp + j1v - n);
	        if (j > 0) {
	            temp = -wsp[ih + j*mh + j - 1];
	            cblas_zaxpy(n, &temp, wsp + j1v - 2 * n, 1, wsp + j1v, 1);
	        }
	            
	        cblas_zdotc_sub(n, wsp + j1v - n, 1, wsp + j1v, 1, &hjj);
	        temp = -hjj;
	        cblas_zaxpy(n, &temp, wsp + j1v - n, 1, wsp + j1v, 1);
	        hj1j = cblas_dznrm2(n, wsp + j1v, 1);
	        wsp[ih + j*(mh + 1)] = hjj;

	        if (hj1j <= break_tol) {
	            // std::cout << "happy breakdown: mbrkdwn =" << j + 1 << " h = " << hj1j << std::endl;
	            k1 = 0;
	            ibrkflag = 1;
	            mbrkdwn = j + 1;
	            tbrkdwn = t_now;
	            t_step = t_out - t_now;
	            break_flag = true;
	            break;
	        }
	        wsp[ih + j*mh + j + 1] = Comp(hj1j);
	        wsp[ih + (j + 1) * mh + j] = Comp(hj1j);
	        cblas_zdscal(n, 1. / hj1j, wsp + j1v, 1);
	        j1v += n;
	    }

	    if (!break_flag) {
	        nmult = nmult + 1;
	        expokit_mul(wsp + j1v, mat, wsp + j1v - n);
	        avnorm = cblas_dznrm2(n, wsp + j1v, 1);
	    }

	    wsp[ih + m * mh + m - 1] = zero;
	    wsp[ih + m * mh + m] = one;

	    ireject = 0;

	    while (true) {
	        nexph = nexph + 1;
	        mx = mbrkdwn + k1;
	        if (ideg != 0) {
	            ZGPADM(ideg, mx, sgn*t_step, wsp + ih, mh,
	                wsp + ifree, lfree, iwsp, iexph, ns, iflag);
	            iexph += ifree;
	            nscale = nscale + ns;
	        }
	        else {
	            iexph = ifree;
	            for (i = 0; i < mx; ++i) {
	                wsp[iexph + i] = zero;
	            }
	            wsp[iexph] = one;
	            ZNCHBV(mx, sgn*t_step, wsp + ih, mh, wsp + iexph, wsp + ifree + mx);
	        }

	        /*402*/

	        if (k1 == 0) {
	            err_loc = tol;
	        }
	        else {
	            p1 = abs(wsp[iexph + m])   * beta;
	            p2 = abs(wsp[iexph + m + 1]) * beta * avnorm;
	            if (p1 > 10. * p2) {
	                err_loc = p2;
	                xm = 1. / Doub(m);
	            }
	            else if (p1 > p2) {
	                err_loc = (p1*p2) / (p1 - p2);
	                xm = 1. / Doub(m);
	            }
	            else {
	                err_loc = p1;
	                xm = 1. / Doub(m - 1);
	            }
	        }

	        if ((k1 != 0) && (err_loc > delta*t_step*tol) &&
	            (mxreject == 0 || ireject < mxreject)) {
	            t_old = t_step;
	            t_step = gamma * t_step * pow(t_step*tol / err_loc, xm);
	            p1 = pow(10., round(log10(t_step) - sqr1) - 1);
	            t_step = trunc(t_step / p1 + 0.55) * p1;
	            if (itrace != 0) {
	                std::cout << "t_step =" << t_old << std::endl;
	                std::cout << "err_loc =" << err_loc << std::endl;
	                std::cout << "err_required =" << delta * t_old*tol << std::endl;
	                std::cout << "stepsize rejected, stepping down to:" << t_step << std::endl;
	            }
	            ireject = ireject + 1;
	            nreject = nreject + 1;
	            if (mxreject != 0 && ireject > mxreject) {
	                std::cout << "Failure in ZHEXPV: ---" << std::endl;
	                std::cout << "The requested tolerance is too high." << std::endl;
	                std::cout << "Rerun with a smaller value." << std::endl;
	                iflag = 2;
	                return;
	            }
	            continue;
	        }
	        break;
	    }

	    mx = mbrkdwn + max(0, k1 - 1);
	    hjj = Comp(beta);
	    cblas_zgemv(CblasColMajor, CblasNoTrans, n, mx, &hjj,
	        wsp + iv, n, wsp + iexph, 1, &zero, w, 1);
	    beta = cblas_dznrm2(n, w, 1);
	    hump = max(hump, beta);

	    // prevent dividing by zero
	    if (err_loc == 0)
	        t_new = p1 = 1e300;
	    else {
	        t_new = gamma * t_step * pow(t_step*tol / err_loc, xm);
	        p1 = pow(10., round(log10(t_new) - sqr1) - 1);
	        t_new = trunc(t_new / p1 + 0.55) * p1;
	    }

	    err_loc = max(err_loc, rndoff);

	    t_now = t_now + t_step;

	    if (itrace != 0) {
	        std::cout << "integration" << nstep << "---------------------------------" << std::endl;
	        std::cout << "scale-square =" << ns << std::endl;
	        std::cout << "step_size = " << t_step << std::endl;
	        std::cout << "err_loc   =" << err_loc << std::endl;
	        std::cout << "next_step =" << t_new << std::endl;
	    }

	    step_min = min(step_min, t_step);
	    step_max = max(step_max, t_step);
	    s_error = s_error + err_loc;
	    x_error = max(x_error, err_loc);

	} while (mxstep == 0 || nstep < mxstep);

	iflag = 1;

	/*500*/

	iwsp[0] = nmult;
	iwsp[1] = nexph;
	iwsp[2] = nscale;
	iwsp[3] = nstep;
	iwsp[4] = nreject;
	iwsp[5] = ibrkflag;
	iwsp[6] = mbrkdwn;

	wsp[0] = Comp(step_min);
	wsp[1] = Comp(step_max);
	wsp[2] = Comp(0.);
	wsp[3] = Comp(0.);
	wsp[4] = Comp(x_error);
	wsp[5] = Comp(s_error);
	wsp[6] = Comp(tbrkdwn);
	wsp[7] = Comp(sgn*t_now);
	wsp[8] = Comp(hump / vnorm);
	wsp[9] = Comp(beta / vnorm);
}

inline void ZHEXPV(Int_I n, Int_I m, Doub_I t, Comp *w, Doub tol, Doub_I anorm,
	        Comp *wsp, Int_I lwsp, Int *iwsp, Int_I liwsp, CmobdComp_I mat, Int_I itrace, Int_O iflag )
{
#ifndef NDEBUG
	if (sum_abs_v(w, n) < 1e-100)
	    SLS_ERR("zero vector is not allowed!");
#endif
	const Int mxstep = 500, mxreject = 0, ideg = 6;
	Doub delta = 1.2, gamma = 0.9;

	const Comp zero = 0., one = 1.;

	Int i, j, k1, mh, mx, ih, j1v, ns, ifree, lfree, iexph,
	    ireject, ibrkflag, mbrkdwn, nmult, nreject, nexph, nscale,
	    nstep;
	Doub sgn, t_out, tbrkdwn, step_min, step_max, err_loc,
	    s_error, x_error, t_now, t_new, t_step, t_old,
	    xm, beta, break_tol, p1, p2, p3, eps, rndoff,
	    vnorm, avnorm=0, hj1j, hump, sqr1;
	Comp hjj, temp;

	iflag = 0;
	if ( lwsp < n*(m+2)+5*sqr(m+2)+ideg+2 )
	    iflag = -1;
	if (liwsp < m + 2)
	    iflag = -2;
	if (m >= n || m <= 0)
	    iflag = -3;
	if (iflag != 0)
	    SLS_ERR("bad sizes (in input of DHEXPV): iflag = " + num2str(iflag));

	k1 = 2;
	mh = m + 2;
	const Int iv = 0;
	ih = iv + n * (m + 1) + n;
	ifree = ih + mh * mh;
	lfree = lwsp - ifree - 1;

	ibrkflag = 0;
	mbrkdwn = m;
	nmult = 0;
	nreject = 0;
	nexph = 0;
	nscale = 0;

	t_out = abs(t);
	tbrkdwn = 0.;
	step_min = t_out;
	step_max = 0.;
	nstep = 0;
	s_error = 0.;
	x_error = 0.;
	t_now = 0.;
	t_new = 0.;

	p1 = 4. / 3.;
	do {
	    /*1*/  p2 = p1 - 1.;
	    p3 = p2 + p2 + p2;
	    eps = abs(p3 - 1.);
	} while (eps == 0.);

	if (tol <= eps) tol = sqrt(eps);
	rndoff = eps * anorm;

	break_tol = 1e-7;

	sgn = sign(1., t);
	beta = cblas_dznrm2(n, w, 1);
	vnorm = beta;
	hump = beta;

	sqr1 = sqrt(0.1);
	xm = 1. / Doub(m);
	p2 = tol * (pow((m + 1) / 2.72, m + 1))*sqrt(2.*3.14*(m + 1));
	t_new = (1. / anorm)*pow((p2 / (4.*beta*anorm)), xm);
	p1 = pow(10., round(log10(t_new) - sqr1) - 1);
	t_new = trunc(t_new / p1 + 0.55) * p1;


	/*100*/ do {
	    if (t_now >= t_out)
	        break;

	    nstep = nstep + 1;
	    t_step = min(t_out - t_now, t_new);
	    beta = cblas_dznrm2(n, w, 1);
	    p1 = 1. / beta;
	    for (i = 0; i < n; ++i) {
	        wsp[iv + i] = p1 * w[i];
	    }
	    for (i = 0; i < mh * mh; ++i) {
	        wsp[ih + i] = zero;
	    }

	    j1v = iv + n;
	    Bool break_flag = false;
	    for (j = 0; j < m; ++j) {
	        nmult = nmult + 1;
	        expokit_mul(wsp + j1v, mat, wsp + j1v - n);
	        if (j > 0) {
	            temp = -wsp[ih + j*mh + j - 1];
	            cblas_zaxpy(n, &temp, wsp + j1v - 2 * n, 1, wsp + j1v, 1);
	        }
	            
	        cblas_zdotc_sub(n, wsp + j1v - n, 1, wsp + j1v, 1, &hjj);
	        temp = -hjj;
	        cblas_zaxpy(n, &temp, wsp + j1v - n, 1, wsp + j1v, 1);
	        hj1j = cblas_dznrm2(n, wsp + j1v, 1);
	        wsp[ih + j*(mh + 1)] = hjj;

	        if (hj1j <= break_tol) {
	            // std::cout << "happy breakdown: mbrkdwn =" << j + 1 << " h = " << hj1j << std::endl;
	            k1 = 0;
	            ibrkflag = 1;
	            mbrkdwn = j + 1;
	            tbrkdwn = t_now;
	            t_step = t_out - t_now;
	            break_flag = true;
	            break;
	        }
	        wsp[ih + j*mh + j + 1] = Comp(hj1j);
	        wsp[ih + (j + 1) * mh + j] = Comp(hj1j);
	        cblas_zdscal(n, 1. / hj1j, wsp + j1v, 1);
	        j1v += n;
	    }

	    if (!break_flag) {
	        nmult = nmult + 1;
	        expokit_mul(wsp + j1v, mat, wsp + j1v - n);
	        avnorm = cblas_dznrm2(n, wsp + j1v, 1);
	    }

	    wsp[ih + m * mh + m - 1] = zero;
	    wsp[ih + m * mh + m] = one;

	    ireject = 0;

	    while (true) {
	        nexph = nexph + 1;
	        mx = mbrkdwn + k1;
	        if (ideg != 0) {
	            ZGPADM(ideg, mx, sgn*t_step, wsp + ih, mh,
	                wsp + ifree, lfree, iwsp, iexph, ns, iflag);
	            iexph += ifree;
	            nscale = nscale + ns;
	        }
	        else {
	            iexph = ifree;
	            for (i = 0; i < mx; ++i) {
	                wsp[iexph + i] = zero;
	            }
	            wsp[iexph] = one;
	            ZNCHBV(mx, sgn*t_step, wsp + ih, mh, wsp + iexph, wsp + ifree + mx);
	        }

	        /*402*/

	        if (k1 == 0) {
	            err_loc = tol;
	        }
	        else {
	            p1 = abs(wsp[iexph + m])   * beta;
	            p2 = abs(wsp[iexph + m + 1]) * beta * avnorm;
	            if (p1 > 10. * p2) {
	                err_loc = p2;
	                xm = 1. / Doub(m);
	            }
	            else if (p1 > p2) {
	                err_loc = (p1*p2) / (p1 - p2);
	                xm = 1. / Doub(m);
	            }
	            else {
	                err_loc = p1;
	                xm = 1. / Doub(m - 1);
	            }
	        }

	        if ((k1 != 0) && (err_loc > delta*t_step*tol) &&
	            (mxreject == 0 || ireject < mxreject)) {
	            t_old = t_step;
	            t_step = gamma * t_step * pow(t_step*tol / err_loc, xm);
	            p1 = pow(10., round(log10(t_step) - sqr1) - 1);
	            t_step = trunc(t_step / p1 + 0.55) * p1;
	            if (itrace != 0) {
	                std::cout << "t_step =" << t_old << std::endl;
	                std::cout << "err_loc =" << err_loc << std::endl;
	                std::cout << "err_required =" << delta * t_old*tol << std::endl;
	                std::cout << "stepsize rejected, stepping down to:" << t_step << std::endl;
	            }
	            ireject = ireject + 1;
	            nreject = nreject + 1;
	            if (mxreject != 0 && ireject > mxreject) {
	                std::cout << "Failure in ZHEXPV: ---" << std::endl;
	                std::cout << "The requested tolerance is too high." << std::endl;
	                std::cout << "Rerun with a smaller value." << std::endl;
	                iflag = 2;
	                return;
	            }
	            continue;
	        }
	        break;
	    }

	    mx = mbrkdwn + max(0, k1 - 1);
	    hjj = Comp(beta);
	    cblas_zgemv(CblasColMajor, CblasNoTrans, n, mx, &hjj,
	        wsp + iv, n, wsp + iexph, 1, &zero, w, 1);
	    beta = cblas_dznrm2(n, w, 1);
	    hump = max(hump, beta);

	    // prevent dividing by zero
	    if (err_loc == 0)
	        t_new = p1 = 1e300;
	    else {
	        t_new = gamma * t_step * pow(t_step*tol / err_loc, xm);
	        p1 = pow(10., round(log10(t_new) - sqr1) - 1);
	        t_new = trunc(t_new / p1 + 0.55) * p1;
	    }

	    err_loc = max(err_loc, rndoff);

	    t_now = t_now + t_step;

	    if (itrace != 0) {
	        std::cout << "integration" << nstep << "---------------------------------" << std::endl;
	        std::cout << "scale-square =" << ns << std::endl;
	        std::cout << "step_size = " << t_step << std::endl;
	        std::cout << "err_loc   =" << err_loc << std::endl;
	        std::cout << "next_step =" << t_new << std::endl;
	    }

	    step_min = min(step_min, t_step);
	    step_max = max(step_max, t_step);
	    s_error = s_error + err_loc;
	    x_error = max(x_error, err_loc);

	} while (mxstep == 0 || nstep < mxstep);

	iflag = 1;

	/*500*/

	iwsp[0] = nmult;
	iwsp[1] = nexph;
	iwsp[2] = nscale;
	iwsp[3] = nstep;
	iwsp[4] = nreject;
	iwsp[5] = ibrkflag;
	iwsp[6] = mbrkdwn;

	wsp[0] = Comp(step_min);
	wsp[1] = Comp(step_max);
	wsp[2] = Comp(0.);
	wsp[3] = Comp(0.);
	wsp[4] = Comp(x_error);
	wsp[5] = Comp(s_error);
	wsp[6] = Comp(tbrkdwn);
	wsp[7] = Comp(sgn*t_now);
	wsp[8] = Comp(hump / vnorm);
	wsp[9] = Comp(beta / vnorm);
}

inline void ZHEXPV(Int_I n, Int_I m, Doub_I t, Comp *w, Doub tol, Doub_I anorm,
	        Comp *wsp, Int_I lwsp, Int *iwsp, Int_I liwsp, McooDoub_I mat, Int_I itrace, Int_O iflag )
{
#ifndef NDEBUG
	if (sum_abs_v(w, n) < 1e-100)
	    SLS_ERR("zero vector is not allowed!");
#endif
	const Int mxstep = 500, mxreject = 0, ideg = 6;
	Doub delta = 1.2, gamma = 0.9;

	const Comp zero = 0., one = 1.;

	Int i, j, k1, mh, mx, ih, j1v, ns, ifree, lfree, iexph,
	    ireject, ibrkflag, mbrkdwn, nmult, nreject, nexph, nscale,
	    nstep;
	Doub sgn, t_out, tbrkdwn, step_min, step_max, err_loc,
	    s_error, x_error, t_now, t_new, t_step, t_old,
	    xm, beta, break_tol, p1, p2, p3, eps, rndoff,
	    vnorm, avnorm=0, hj1j, hump, sqr1;
	Comp hjj, temp;

	iflag = 0;
	if ( lwsp < n*(m+2)+5*sqr(m+2)+ideg+2 )
	    iflag = -1;
	if (liwsp < m + 2)
	    iflag = -2;
	if (m >= n || m <= 0)
	    iflag = -3;
	if (iflag != 0)
	    SLS_ERR("bad sizes (in input of DHEXPV): iflag = " + num2str(iflag));

	k1 = 2;
	mh = m + 2;
	const Int iv = 0;
	ih = iv + n * (m + 1) + n;
	ifree = ih + mh * mh;
	lfree = lwsp - ifree - 1;

	ibrkflag = 0;
	mbrkdwn = m;
	nmult = 0;
	nreject = 0;
	nexph = 0;
	nscale = 0;

	t_out = abs(t);
	tbrkdwn = 0.;
	step_min = t_out;
	step_max = 0.;
	nstep = 0;
	s_error = 0.;
	x_error = 0.;
	t_now = 0.;
	t_new = 0.;

	p1 = 4. / 3.;
	do {
	    /*1*/  p2 = p1 - 1.;
	    p3 = p2 + p2 + p2;
	    eps = abs(p3 - 1.);
	} while (eps == 0.);

	if (tol <= eps) tol = sqrt(eps);
	rndoff = eps * anorm;

	break_tol = 1e-7;

	sgn = sign(1., t);
	beta = cblas_dznrm2(n, w, 1);
	vnorm = beta;
	hump = beta;

	sqr1 = sqrt(0.1);
	xm = 1. / Doub(m);
	p2 = tol * (pow((m + 1) / 2.72, m + 1))*sqrt(2.*3.14*(m + 1));
	t_new = (1. / anorm)*pow((p2 / (4.*beta*anorm)), xm);
	p1 = pow(10., round(log10(t_new) - sqr1) - 1);
	t_new = trunc(t_new / p1 + 0.55) * p1;


	/*100*/ do {
	    if (t_now >= t_out)
	        break;

	    nstep = nstep + 1;
	    t_step = min(t_out - t_now, t_new);
	    beta = cblas_dznrm2(n, w, 1);
	    p1 = 1. / beta;
	    for (i = 0; i < n; ++i) {
	        wsp[iv + i] = p1 * w[i];
	    }
	    for (i = 0; i < mh * mh; ++i) {
	        wsp[ih + i] = zero;
	    }

	    j1v = iv + n;
	    Bool break_flag = false;
	    for (j = 0; j < m; ++j) {
	        nmult = nmult + 1;
	        expokit_mul(wsp + j1v, mat, wsp + j1v - n);
	        if (j > 0) {
	            temp = -wsp[ih + j*mh + j - 1];
	            cblas_zaxpy(n, &temp, wsp + j1v - 2 * n, 1, wsp + j1v, 1);
	        }
	            
	        cblas_zdotc_sub(n, wsp + j1v - n, 1, wsp + j1v, 1, &hjj);
	        temp = -hjj;
	        cblas_zaxpy(n, &temp, wsp + j1v - n, 1, wsp + j1v, 1);
	        hj1j = cblas_dznrm2(n, wsp + j1v, 1);
	        wsp[ih + j*(mh + 1)] = hjj;

	        if (hj1j <= break_tol) {
	            // std::cout << "happy breakdown: mbrkdwn =" << j + 1 << " h = " << hj1j << std::endl;
	            k1 = 0;
	            ibrkflag = 1;
	            mbrkdwn = j + 1;
	            tbrkdwn = t_now;
	            t_step = t_out - t_now;
	            break_flag = true;
	            break;
	        }
	        wsp[ih + j*mh + j + 1] = Comp(hj1j);
	        wsp[ih + (j + 1) * mh + j] = Comp(hj1j);
	        cblas_zdscal(n, 1. / hj1j, wsp + j1v, 1);
	        j1v += n;
	    }

	    if (!break_flag) {
	        nmult = nmult + 1;
	        expokit_mul(wsp + j1v, mat, wsp + j1v - n);
	        avnorm = cblas_dznrm2(n, wsp + j1v, 1);
	    }

	    wsp[ih + m * mh + m - 1] = zero;
	    wsp[ih + m * mh + m] = one;

	    ireject = 0;

	    while (true) {
	        nexph = nexph + 1;
	        mx = mbrkdwn + k1;
	        if (ideg != 0) {
	            ZGPADM(ideg, mx, sgn*t_step, wsp + ih, mh,
	                wsp + ifree, lfree, iwsp, iexph, ns, iflag);
	            iexph += ifree;
	            nscale = nscale + ns;
	        }
	        else {
	            iexph = ifree;
	            for (i = 0; i < mx; ++i) {
	                wsp[iexph + i] = zero;
	            }
	            wsp[iexph] = one;
	            ZNCHBV(mx, sgn*t_step, wsp + ih, mh, wsp + iexph, wsp + ifree + mx);
	        }

	        /*402*/

	        if (k1 == 0) {
	            err_loc = tol;
	        }
	        else {
	            p1 = abs(wsp[iexph + m])   * beta;
	            p2 = abs(wsp[iexph + m + 1]) * beta * avnorm;
	            if (p1 > 10. * p2) {
	                err_loc = p2;
	                xm = 1. / Doub(m);
	            }
	            else if (p1 > p2) {
	                err_loc = (p1*p2) / (p1 - p2);
	                xm = 1. / Doub(m);
	            }
	            else {
	                err_loc = p1;
	                xm = 1. / Doub(m - 1);
	            }
	        }

	        if ((k1 != 0) && (err_loc > delta*t_step*tol) &&
	            (mxreject == 0 || ireject < mxreject)) {
	            t_old = t_step;
	            t_step = gamma * t_step * pow(t_step*tol / err_loc, xm);
	            p1 = pow(10., round(log10(t_step) - sqr1) - 1);
	            t_step = trunc(t_step / p1 + 0.55) * p1;
	            if (itrace != 0) {
	                std::cout << "t_step =" << t_old << std::endl;
	                std::cout << "err_loc =" << err_loc << std::endl;
	                std::cout << "err_required =" << delta * t_old*tol << std::endl;
	                std::cout << "stepsize rejected, stepping down to:" << t_step << std::endl;
	            }
	            ireject = ireject + 1;
	            nreject = nreject + 1;
	            if (mxreject != 0 && ireject > mxreject) {
	                std::cout << "Failure in ZHEXPV: ---" << std::endl;
	                std::cout << "The requested tolerance is too high." << std::endl;
	                std::cout << "Rerun with a smaller value." << std::endl;
	                iflag = 2;
	                return;
	            }
	            continue;
	        }
	        break;
	    }

	    mx = mbrkdwn + max(0, k1 - 1);
	    hjj = Comp(beta);
	    cblas_zgemv(CblasColMajor, CblasNoTrans, n, mx, &hjj,
	        wsp + iv, n, wsp + iexph, 1, &zero, w, 1);
	    beta = cblas_dznrm2(n, w, 1);
	    hump = max(hump, beta);

	    // prevent dividing by zero
	    if (err_loc == 0)
	        t_new = p1 = 1e300;
	    else {
	        t_new = gamma * t_step * pow(t_step*tol / err_loc, xm);
	        p1 = pow(10., round(log10(t_new) - sqr1) - 1);
	        t_new = trunc(t_new / p1 + 0.55) * p1;
	    }

	    err_loc = max(err_loc, rndoff);

	    t_now = t_now + t_step;

	    if (itrace != 0) {
	        std::cout << "integration" << nstep << "---------------------------------" << std::endl;
	        std::cout << "scale-square =" << ns << std::endl;
	        std::cout << "step_size = " << t_step << std::endl;
	        std::cout << "err_loc   =" << err_loc << std::endl;
	        std::cout << "next_step =" << t_new << std::endl;
	    }

	    step_min = min(step_min, t_step);
	    step_max = max(step_max, t_step);
	    s_error = s_error + err_loc;
	    x_error = max(x_error, err_loc);

	} while (mxstep == 0 || nstep < mxstep);

	iflag = 1;

	/*500*/

	iwsp[0] = nmult;
	iwsp[1] = nexph;
	iwsp[2] = nscale;
	iwsp[3] = nstep;
	iwsp[4] = nreject;
	iwsp[5] = ibrkflag;
	iwsp[6] = mbrkdwn;

	wsp[0] = Comp(step_min);
	wsp[1] = Comp(step_max);
	wsp[2] = Comp(0.);
	wsp[3] = Comp(0.);
	wsp[4] = Comp(x_error);
	wsp[5] = Comp(s_error);
	wsp[6] = Comp(tbrkdwn);
	wsp[7] = Comp(sgn*t_now);
	wsp[8] = Comp(hump / vnorm);
	wsp[9] = Comp(beta / vnorm);
}

inline void ZHEXPV(Int_I n, Int_I m, Doub_I t, Comp *w, Doub tol, Doub_I anorm,
	        Comp *wsp, Int_I lwsp, Int *iwsp, Int_I liwsp, McooComp_I mat, Int_I itrace, Int_O iflag )
{
#ifndef NDEBUG
	if (sum_abs_v(w, n) < 1e-100)
	    SLS_ERR("zero vector is not allowed!");
#endif
	const Int mxstep = 500, mxreject = 0, ideg = 6;
	Doub delta = 1.2, gamma = 0.9;

	const Comp zero = 0., one = 1.;

	Int i, j, k1, mh, mx, ih, j1v, ns, ifree, lfree, iexph,
	    ireject, ibrkflag, mbrkdwn, nmult, nreject, nexph, nscale,
	    nstep;
	Doub sgn, t_out, tbrkdwn, step_min, step_max, err_loc,
	    s_error, x_error, t_now, t_new, t_step, t_old,
	    xm, beta, break_tol, p1, p2, p3, eps, rndoff,
	    vnorm, avnorm=0, hj1j, hump, sqr1;
	Comp hjj, temp;

	iflag = 0;
	if ( lwsp < n*(m+2)+5*sqr(m+2)+ideg+2 )
	    iflag = -1;
	if (liwsp < m + 2)
	    iflag = -2;
	if (m >= n || m <= 0)
	    iflag = -3;
	if (iflag != 0)
	    SLS_ERR("bad sizes (in input of DHEXPV): iflag = " + num2str(iflag));

	k1 = 2;
	mh = m + 2;
	const Int iv = 0;
	ih = iv + n * (m + 1) + n;
	ifree = ih + mh * mh;
	lfree = lwsp - ifree - 1;

	ibrkflag = 0;
	mbrkdwn = m;
	nmult = 0;
	nreject = 0;
	nexph = 0;
	nscale = 0;

	t_out = abs(t);
	tbrkdwn = 0.;
	step_min = t_out;
	step_max = 0.;
	nstep = 0;
	s_error = 0.;
	x_error = 0.;
	t_now = 0.;
	t_new = 0.;

	p1 = 4. / 3.;
	do {
	    /*1*/  p2 = p1 - 1.;
	    p3 = p2 + p2 + p2;
	    eps = abs(p3 - 1.);
	} while (eps == 0.);

	if (tol <= eps) tol = sqrt(eps);
	rndoff = eps * anorm;

	break_tol = 1e-7;

	sgn = sign(1., t);
	beta = cblas_dznrm2(n, w, 1);
	vnorm = beta;
	hump = beta;

	sqr1 = sqrt(0.1);
	xm = 1. / Doub(m);
	p2 = tol * (pow((m + 1) / 2.72, m + 1))*sqrt(2.*3.14*(m + 1));
	t_new = (1. / anorm)*pow((p2 / (4.*beta*anorm)), xm);
	p1 = pow(10., round(log10(t_new) - sqr1) - 1);
	t_new = trunc(t_new / p1 + 0.55) * p1;


	/*100*/ do {
	    if (t_now >= t_out)
	        break;

	    nstep = nstep + 1;
	    t_step = min(t_out - t_now, t_new);
	    beta = cblas_dznrm2(n, w, 1);
	    p1 = 1. / beta;
	    for (i = 0; i < n; ++i) {
	        wsp[iv + i] = p1 * w[i];
	    }
	    for (i = 0; i < mh * mh; ++i) {
	        wsp[ih + i] = zero;
	    }

	    j1v = iv + n;
	    Bool break_flag = false;
	    for (j = 0; j < m; ++j) {
	        nmult = nmult + 1;
	        expokit_mul(wsp + j1v, mat, wsp + j1v - n);
	        if (j > 0) {
	            temp = -wsp[ih + j*mh + j - 1];
	            cblas_zaxpy(n, &temp, wsp + j1v - 2 * n, 1, wsp + j1v, 1);
	        }
	            
	        cblas_zdotc_sub(n, wsp + j1v - n, 1, wsp + j1v, 1, &hjj);
	        temp = -hjj;
	        cblas_zaxpy(n, &temp, wsp + j1v - n, 1, wsp + j1v, 1);
	        hj1j = cblas_dznrm2(n, wsp + j1v, 1);
	        wsp[ih + j*(mh + 1)] = hjj;

	        if (hj1j <= break_tol) {
	            // std::cout << "happy breakdown: mbrkdwn =" << j + 1 << " h = " << hj1j << std::endl;
	            k1 = 0;
	            ibrkflag = 1;
	            mbrkdwn = j + 1;
	            tbrkdwn = t_now;
	            t_step = t_out - t_now;
	            break_flag = true;
	            break;
	        }
	        wsp[ih + j*mh + j + 1] = Comp(hj1j);
	        wsp[ih + (j + 1) * mh + j] = Comp(hj1j);
	        cblas_zdscal(n, 1. / hj1j, wsp + j1v, 1);
	        j1v += n;
	    }

	    if (!break_flag) {
	        nmult = nmult + 1;
	        expokit_mul(wsp + j1v, mat, wsp + j1v - n);
	        avnorm = cblas_dznrm2(n, wsp + j1v, 1);
	    }

	    wsp[ih + m * mh + m - 1] = zero;
	    wsp[ih + m * mh + m] = one;

	    ireject = 0;

	    while (true) {
	        nexph = nexph + 1;
	        mx = mbrkdwn + k1;
	        if (ideg != 0) {
	            ZGPADM(ideg, mx, sgn*t_step, wsp + ih, mh,
	                wsp + ifree, lfree, iwsp, iexph, ns, iflag);
	            iexph += ifree;
	            nscale = nscale + ns;
	        }
	        else {
	            iexph = ifree;
	            for (i = 0; i < mx; ++i) {
	                wsp[iexph + i] = zero;
	            }
	            wsp[iexph] = one;
	            ZNCHBV(mx, sgn*t_step, wsp + ih, mh, wsp + iexph, wsp + ifree + mx);
	        }

	        /*402*/

	        if (k1 == 0) {
	            err_loc = tol;
	        }
	        else {
	            p1 = abs(wsp[iexph + m])   * beta;
	            p2 = abs(wsp[iexph + m + 1]) * beta * avnorm;
	            if (p1 > 10. * p2) {
	                err_loc = p2;
	                xm = 1. / Doub(m);
	            }
	            else if (p1 > p2) {
	                err_loc = (p1*p2) / (p1 - p2);
	                xm = 1. / Doub(m);
	            }
	            else {
	                err_loc = p1;
	                xm = 1. / Doub(m - 1);
	            }
	        }

	        if ((k1 != 0) && (err_loc > delta*t_step*tol) &&
	            (mxreject == 0 || ireject < mxreject)) {
	            t_old = t_step;
	            t_step = gamma * t_step * pow(t_step*tol / err_loc, xm);
	            p1 = pow(10., round(log10(t_step) - sqr1) - 1);
	            t_step = trunc(t_step / p1 + 0.55) * p1;
	            if (itrace != 0) {
	                std::cout << "t_step =" << t_old << std::endl;
	                std::cout << "err_loc =" << err_loc << std::endl;
	                std::cout << "err_required =" << delta * t_old*tol << std::endl;
	                std::cout << "stepsize rejected, stepping down to:" << t_step << std::endl;
	            }
	            ireject = ireject + 1;
	            nreject = nreject + 1;
	            if (mxreject != 0 && ireject > mxreject) {
	                std::cout << "Failure in ZHEXPV: ---" << std::endl;
	                std::cout << "The requested tolerance is too high." << std::endl;
	                std::cout << "Rerun with a smaller value." << std::endl;
	                iflag = 2;
	                return;
	            }
	            continue;
	        }
	        break;
	    }

	    mx = mbrkdwn + max(0, k1 - 1);
	    hjj = Comp(beta);
	    cblas_zgemv(CblasColMajor, CblasNoTrans, n, mx, &hjj,
	        wsp + iv, n, wsp + iexph, 1, &zero, w, 1);
	    beta = cblas_dznrm2(n, w, 1);
	    hump = max(hump, beta);

	    // prevent dividing by zero
	    if (err_loc == 0)
	        t_new = p1 = 1e300;
	    else {
	        t_new = gamma * t_step * pow(t_step*tol / err_loc, xm);
	        p1 = pow(10., round(log10(t_new) - sqr1) - 1);
	        t_new = trunc(t_new / p1 + 0.55) * p1;
	    }

	    err_loc = max(err_loc, rndoff);

	    t_now = t_now + t_step;

	    if (itrace != 0) {
	        std::cout << "integration" << nstep << "---------------------------------" << std::endl;
	        std::cout << "scale-square =" << ns << std::endl;
	        std::cout << "step_size = " << t_step << std::endl;
	        std::cout << "err_loc   =" << err_loc << std::endl;
	        std::cout << "next_step =" << t_new << std::endl;
	    }

	    step_min = min(step_min, t_step);
	    step_max = max(step_max, t_step);
	    s_error = s_error + err_loc;
	    x_error = max(x_error, err_loc);

	} while (mxstep == 0 || nstep < mxstep);

	iflag = 1;

	/*500*/

	iwsp[0] = nmult;
	iwsp[1] = nexph;
	iwsp[2] = nscale;
	iwsp[3] = nstep;
	iwsp[4] = nreject;
	iwsp[5] = ibrkflag;
	iwsp[6] = mbrkdwn;

	wsp[0] = Comp(step_min);
	wsp[1] = Comp(step_max);
	wsp[2] = Comp(0.);
	wsp[3] = Comp(0.);
	wsp[4] = Comp(x_error);
	wsp[5] = Comp(s_error);
	wsp[6] = Comp(tbrkdwn);
	wsp[7] = Comp(sgn*t_now);
	wsp[8] = Comp(hump / vnorm);
	wsp[9] = Comp(beta / vnorm);
}

inline void ZHEXPV(Int_I n, Int_I m, Doub_I t, Comp *w, Doub tol, Doub_I anorm,
	        Comp *wsp, Int_I lwsp, Int *iwsp, Int_I liwsp, CmatDoub_I mat, Int_I itrace, Int_O iflag )
{
#ifndef NDEBUG
	if (sum_abs_v(w, n) < 1e-100)
	    SLS_ERR("zero vector is not allowed!");
#endif
	const Int mxstep = 500, mxreject = 0, ideg = 6;
	Doub delta = 1.2, gamma = 0.9;

	const Comp zero = 0., one = 1.;

	Int i, j, k1, mh, mx, ih, j1v, ns, ifree, lfree, iexph,
	    ireject, ibrkflag, mbrkdwn, nmult, nreject, nexph, nscale,
	    nstep;
	Doub sgn, t_out, tbrkdwn, step_min, step_max, err_loc,
	    s_error, x_error, t_now, t_new, t_step, t_old,
	    xm, beta, break_tol, p1, p2, p3, eps, rndoff,
	    vnorm, avnorm=0, hj1j, hump, sqr1;
	Comp hjj, temp;

	iflag = 0;
	if ( lwsp < n*(m+2)+5*sqr(m+2)+ideg+2 )
	    iflag = -1;
	if (liwsp < m + 2)
	    iflag = -2;
	if (m >= n || m <= 0)
	    iflag = -3;
	if (iflag != 0)
	    SLS_ERR("bad sizes (in input of DHEXPV): iflag = " + num2str(iflag));

	k1 = 2;
	mh = m + 2;
	const Int iv = 0;
	ih = iv + n * (m + 1) + n;
	ifree = ih + mh * mh;
	lfree = lwsp - ifree - 1;

	ibrkflag = 0;
	mbrkdwn = m;
	nmult = 0;
	nreject = 0;
	nexph = 0;
	nscale = 0;

	t_out = abs(t);
	tbrkdwn = 0.;
	step_min = t_out;
	step_max = 0.;
	nstep = 0;
	s_error = 0.;
	x_error = 0.;
	t_now = 0.;
	t_new = 0.;

	p1 = 4. / 3.;
	do {
	    /*1*/  p2 = p1 - 1.;
	    p3 = p2 + p2 + p2;
	    eps = abs(p3 - 1.);
	} while (eps == 0.);

	if (tol <= eps) tol = sqrt(eps);
	rndoff = eps * anorm;

	break_tol = 1e-7;

	sgn = sign(1., t);
	beta = cblas_dznrm2(n, w, 1);
	vnorm = beta;
	hump = beta;

	sqr1 = sqrt(0.1);
	xm = 1. / Doub(m);
	p2 = tol * (pow((m + 1) / 2.72, m + 1))*sqrt(2.*3.14*(m + 1));
	t_new = (1. / anorm)*pow((p2 / (4.*beta*anorm)), xm);
	p1 = pow(10., round(log10(t_new) - sqr1) - 1);
	t_new = trunc(t_new / p1 + 0.55) * p1;


	/*100*/ do {
	    if (t_now >= t_out)
	        break;

	    nstep = nstep + 1;
	    t_step = min(t_out - t_now, t_new);
	    beta = cblas_dznrm2(n, w, 1);
	    p1 = 1. / beta;
	    for (i = 0; i < n; ++i) {
	        wsp[iv + i] = p1 * w[i];
	    }
	    for (i = 0; i < mh * mh; ++i) {
	        wsp[ih + i] = zero;
	    }

	    j1v = iv + n;
	    Bool break_flag = false;
	    for (j = 0; j < m; ++j) {
	        nmult = nmult + 1;
	        expokit_mul(wsp + j1v, mat, wsp + j1v - n);
	        if (j > 0) {
	            temp = -wsp[ih + j*mh + j - 1];
	            cblas_zaxpy(n, &temp, wsp + j1v - 2 * n, 1, wsp + j1v, 1);
	        }
	            
	        cblas_zdotc_sub(n, wsp + j1v - n, 1, wsp + j1v, 1, &hjj);
	        temp = -hjj;
	        cblas_zaxpy(n, &temp, wsp + j1v - n, 1, wsp + j1v, 1);
	        hj1j = cblas_dznrm2(n, wsp + j1v, 1);
	        wsp[ih + j*(mh + 1)] = hjj;

	        if (hj1j <= break_tol) {
	            // std::cout << "happy breakdown: mbrkdwn =" << j + 1 << " h = " << hj1j << std::endl;
	            k1 = 0;
	            ibrkflag = 1;
	            mbrkdwn = j + 1;
	            tbrkdwn = t_now;
	            t_step = t_out - t_now;
	            break_flag = true;
	            break;
	        }
	        wsp[ih + j*mh + j + 1] = Comp(hj1j);
	        wsp[ih + (j + 1) * mh + j] = Comp(hj1j);
	        cblas_zdscal(n, 1. / hj1j, wsp + j1v, 1);
	        j1v += n;
	    }

	    if (!break_flag) {
	        nmult = nmult + 1;
	        expokit_mul(wsp + j1v, mat, wsp + j1v - n);
	        avnorm = cblas_dznrm2(n, wsp + j1v, 1);
	    }

	    wsp[ih + m * mh + m - 1] = zero;
	    wsp[ih + m * mh + m] = one;

	    ireject = 0;

	    while (true) {
	        nexph = nexph + 1;
	        mx = mbrkdwn + k1;
	        if (ideg != 0) {
	            ZGPADM(ideg, mx, sgn*t_step, wsp + ih, mh,
	                wsp + ifree, lfree, iwsp, iexph, ns, iflag);
	            iexph += ifree;
	            nscale = nscale + ns;
	        }
	        else {
	            iexph = ifree;
	            for (i = 0; i < mx; ++i) {
	                wsp[iexph + i] = zero;
	            }
	            wsp[iexph] = one;
	            ZNCHBV(mx, sgn*t_step, wsp + ih, mh, wsp + iexph, wsp + ifree + mx);
	        }

	        /*402*/

	        if (k1 == 0) {
	            err_loc = tol;
	        }
	        else {
	            p1 = abs(wsp[iexph + m])   * beta;
	            p2 = abs(wsp[iexph + m + 1]) * beta * avnorm;
	            if (p1 > 10. * p2) {
	                err_loc = p2;
	                xm = 1. / Doub(m);
	            }
	            else if (p1 > p2) {
	                err_loc = (p1*p2) / (p1 - p2);
	                xm = 1. / Doub(m);
	            }
	            else {
	                err_loc = p1;
	                xm = 1. / Doub(m - 1);
	            }
	        }

	        if ((k1 != 0) && (err_loc > delta*t_step*tol) &&
	            (mxreject == 0 || ireject < mxreject)) {
	            t_old = t_step;
	            t_step = gamma * t_step * pow(t_step*tol / err_loc, xm);
	            p1 = pow(10., round(log10(t_step) - sqr1) - 1);
	            t_step = trunc(t_step / p1 + 0.55) * p1;
	            if (itrace != 0) {
	                std::cout << "t_step =" << t_old << std::endl;
	                std::cout << "err_loc =" << err_loc << std::endl;
	                std::cout << "err_required =" << delta * t_old*tol << std::endl;
	                std::cout << "stepsize rejected, stepping down to:" << t_step << std::endl;
	            }
	            ireject = ireject + 1;
	            nreject = nreject + 1;
	            if (mxreject != 0 && ireject > mxreject) {
	                std::cout << "Failure in ZHEXPV: ---" << std::endl;
	                std::cout << "The requested tolerance is too high." << std::endl;
	                std::cout << "Rerun with a smaller value." << std::endl;
	                iflag = 2;
	                return;
	            }
	            continue;
	        }
	        break;
	    }

	    mx = mbrkdwn + max(0, k1 - 1);
	    hjj = Comp(beta);
	    cblas_zgemv(CblasColMajor, CblasNoTrans, n, mx, &hjj,
	        wsp + iv, n, wsp + iexph, 1, &zero, w, 1);
	    beta = cblas_dznrm2(n, w, 1);
	    hump = max(hump, beta);

	    // prevent dividing by zero
	    if (err_loc == 0)
	        t_new = p1 = 1e300;
	    else {
	        t_new = gamma * t_step * pow(t_step*tol / err_loc, xm);
	        p1 = pow(10., round(log10(t_new) - sqr1) - 1);
	        t_new = trunc(t_new / p1 + 0.55) * p1;
	    }

	    err_loc = max(err_loc, rndoff);

	    t_now = t_now + t_step;

	    if (itrace != 0) {
	        std::cout << "integration" << nstep << "---------------------------------" << std::endl;
	        std::cout << "scale-square =" << ns << std::endl;
	        std::cout << "step_size = " << t_step << std::endl;
	        std::cout << "err_loc   =" << err_loc << std::endl;
	        std::cout << "next_step =" << t_new << std::endl;
	    }

	    step_min = min(step_min, t_step);
	    step_max = max(step_max, t_step);
	    s_error = s_error + err_loc;
	    x_error = max(x_error, err_loc);

	} while (mxstep == 0 || nstep < mxstep);

	iflag = 1;

	/*500*/

	iwsp[0] = nmult;
	iwsp[1] = nexph;
	iwsp[2] = nscale;
	iwsp[3] = nstep;
	iwsp[4] = nreject;
	iwsp[5] = ibrkflag;
	iwsp[6] = mbrkdwn;

	wsp[0] = Comp(step_min);
	wsp[1] = Comp(step_max);
	wsp[2] = Comp(0.);
	wsp[3] = Comp(0.);
	wsp[4] = Comp(x_error);
	wsp[5] = Comp(s_error);
	wsp[6] = Comp(tbrkdwn);
	wsp[7] = Comp(sgn*t_now);
	wsp[8] = Comp(hump / vnorm);
	wsp[9] = Comp(beta / vnorm);
}

inline void ZHEXPV(Int_I n, Int_I m, Doub_I t, Comp *w, Doub tol, Doub_I anorm,
	        Comp *wsp, Int_I lwsp, Int *iwsp, Int_I liwsp, CmatComp_I mat, Int_I itrace, Int_O iflag )
{
#ifndef NDEBUG
	if (sum_abs_v(w, n) < 1e-100)
	    SLS_ERR("zero vector is not allowed!");
#endif
	const Int mxstep = 500, mxreject = 0, ideg = 6;
	Doub delta = 1.2, gamma = 0.9;

	const Comp zero = 0., one = 1.;

	Int i, j, k1, mh, mx, ih, j1v, ns, ifree, lfree, iexph,
	    ireject, ibrkflag, mbrkdwn, nmult, nreject, nexph, nscale,
	    nstep;
	Doub sgn, t_out, tbrkdwn, step_min, step_max, err_loc,
	    s_error, x_error, t_now, t_new, t_step, t_old,
	    xm, beta, break_tol, p1, p2, p3, eps, rndoff,
	    vnorm, avnorm=0, hj1j, hump, sqr1;
	Comp hjj, temp;

	iflag = 0;
	if ( lwsp < n*(m+2)+5*sqr(m+2)+ideg+2 )
	    iflag = -1;
	if (liwsp < m + 2)
	    iflag = -2;
	if (m >= n || m <= 0)
	    iflag = -3;
	if (iflag != 0)
	    SLS_ERR("bad sizes (in input of DHEXPV): iflag = " + num2str(iflag));

	k1 = 2;
	mh = m + 2;
	const Int iv = 0;
	ih = iv + n * (m + 1) + n;
	ifree = ih + mh * mh;
	lfree = lwsp - ifree - 1;

	ibrkflag = 0;
	mbrkdwn = m;
	nmult = 0;
	nreject = 0;
	nexph = 0;
	nscale = 0;

	t_out = abs(t);
	tbrkdwn = 0.;
	step_min = t_out;
	step_max = 0.;
	nstep = 0;
	s_error = 0.;
	x_error = 0.;
	t_now = 0.;
	t_new = 0.;

	p1 = 4. / 3.;
	do {
	    /*1*/  p2 = p1 - 1.;
	    p3 = p2 + p2 + p2;
	    eps = abs(p3 - 1.);
	} while (eps == 0.);

	if (tol <= eps) tol = sqrt(eps);
	rndoff = eps * anorm;

	break_tol = 1e-7;

	sgn = sign(1., t);
	beta = cblas_dznrm2(n, w, 1);
	vnorm = beta;
	hump = beta;

	sqr1 = sqrt(0.1);
	xm = 1. / Doub(m);
	p2 = tol * (pow((m + 1) / 2.72, m + 1))*sqrt(2.*3.14*(m + 1));
	t_new = (1. / anorm)*pow((p2 / (4.*beta*anorm)), xm);
	p1 = pow(10., round(log10(t_new) - sqr1) - 1);
	t_new = trunc(t_new / p1 + 0.55) * p1;


	/*100*/ do {
	    if (t_now >= t_out)
	        break;

	    nstep = nstep + 1;
	    t_step = min(t_out - t_now, t_new);
	    beta = cblas_dznrm2(n, w, 1);
	    p1 = 1. / beta;
	    for (i = 0; i < n; ++i) {
	        wsp[iv + i] = p1 * w[i];
	    }
	    for (i = 0; i < mh * mh; ++i) {
	        wsp[ih + i] = zero;
	    }

	    j1v = iv + n;
	    Bool break_flag = false;
	    for (j = 0; j < m; ++j) {
	        nmult = nmult + 1;
	        expokit_mul(wsp + j1v, mat, wsp + j1v - n);
	        if (j > 0) {
	            temp = -wsp[ih + j*mh + j - 1];
	            cblas_zaxpy(n, &temp, wsp + j1v - 2 * n, 1, wsp + j1v, 1);
	        }
	            
	        cblas_zdotc_sub(n, wsp + j1v - n, 1, wsp + j1v, 1, &hjj);
	        temp = -hjj;
	        cblas_zaxpy(n, &temp, wsp + j1v - n, 1, wsp + j1v, 1);
	        hj1j = cblas_dznrm2(n, wsp + j1v, 1);
	        wsp[ih + j*(mh + 1)] = hjj;

	        if (hj1j <= break_tol) {
	            // std::cout << "happy breakdown: mbrkdwn =" << j + 1 << " h = " << hj1j << std::endl;
	            k1 = 0;
	            ibrkflag = 1;
	            mbrkdwn = j + 1;
	            tbrkdwn = t_now;
	            t_step = t_out - t_now;
	            break_flag = true;
	            break;
	        }
	        wsp[ih + j*mh + j + 1] = Comp(hj1j);
	        wsp[ih + (j + 1) * mh + j] = Comp(hj1j);
	        cblas_zdscal(n, 1. / hj1j, wsp + j1v, 1);
	        j1v += n;
	    }

	    if (!break_flag) {
	        nmult = nmult + 1;
	        expokit_mul(wsp + j1v, mat, wsp + j1v - n);
	        avnorm = cblas_dznrm2(n, wsp + j1v, 1);
	    }

	    wsp[ih + m * mh + m - 1] = zero;
	    wsp[ih + m * mh + m] = one;

	    ireject = 0;

	    while (true) {
	        nexph = nexph + 1;
	        mx = mbrkdwn + k1;
	        if (ideg != 0) {
	            ZGPADM(ideg, mx, sgn*t_step, wsp + ih, mh,
	                wsp + ifree, lfree, iwsp, iexph, ns, iflag);
	            iexph += ifree;
	            nscale = nscale + ns;
	        }
	        else {
	            iexph = ifree;
	            for (i = 0; i < mx; ++i) {
	                wsp[iexph + i] = zero;
	            }
	            wsp[iexph] = one;
	            ZNCHBV(mx, sgn*t_step, wsp + ih, mh, wsp + iexph, wsp + ifree + mx);
	        }

	        /*402*/

	        if (k1 == 0) {
	            err_loc = tol;
	        }
	        else {
	            p1 = abs(wsp[iexph + m])   * beta;
	            p2 = abs(wsp[iexph + m + 1]) * beta * avnorm;
	            if (p1 > 10. * p2) {
	                err_loc = p2;
	                xm = 1. / Doub(m);
	            }
	            else if (p1 > p2) {
	                err_loc = (p1*p2) / (p1 - p2);
	                xm = 1. / Doub(m);
	            }
	            else {
	                err_loc = p1;
	                xm = 1. / Doub(m - 1);
	            }
	        }

	        if ((k1 != 0) && (err_loc > delta*t_step*tol) &&
	            (mxreject == 0 || ireject < mxreject)) {
	            t_old = t_step;
	            t_step = gamma * t_step * pow(t_step*tol / err_loc, xm);
	            p1 = pow(10., round(log10(t_step) - sqr1) - 1);
	            t_step = trunc(t_step / p1 + 0.55) * p1;
	            if (itrace != 0) {
	                std::cout << "t_step =" << t_old << std::endl;
	                std::cout << "err_loc =" << err_loc << std::endl;
	                std::cout << "err_required =" << delta * t_old*tol << std::endl;
	                std::cout << "stepsize rejected, stepping down to:" << t_step << std::endl;
	            }
	            ireject = ireject + 1;
	            nreject = nreject + 1;
	            if (mxreject != 0 && ireject > mxreject) {
	                std::cout << "Failure in ZHEXPV: ---" << std::endl;
	                std::cout << "The requested tolerance is too high." << std::endl;
	                std::cout << "Rerun with a smaller value." << std::endl;
	                iflag = 2;
	                return;
	            }
	            continue;
	        }
	        break;
	    }

	    mx = mbrkdwn + max(0, k1 - 1);
	    hjj = Comp(beta);
	    cblas_zgemv(CblasColMajor, CblasNoTrans, n, mx, &hjj,
	        wsp + iv, n, wsp + iexph, 1, &zero, w, 1);
	    beta = cblas_dznrm2(n, w, 1);
	    hump = max(hump, beta);

	    // prevent dividing by zero
	    if (err_loc == 0)
	        t_new = p1 = 1e300;
	    else {
	        t_new = gamma * t_step * pow(t_step*tol / err_loc, xm);
	        p1 = pow(10., round(log10(t_new) - sqr1) - 1);
	        t_new = trunc(t_new / p1 + 0.55) * p1;
	    }

	    err_loc = max(err_loc, rndoff);

	    t_now = t_now + t_step;

	    if (itrace != 0) {
	        std::cout << "integration" << nstep << "---------------------------------" << std::endl;
	        std::cout << "scale-square =" << ns << std::endl;
	        std::cout << "step_size = " << t_step << std::endl;
	        std::cout << "err_loc   =" << err_loc << std::endl;
	        std::cout << "next_step =" << t_new << std::endl;
	    }

	    step_min = min(step_min, t_step);
	    step_max = max(step_max, t_step);
	    s_error = s_error + err_loc;
	    x_error = max(x_error, err_loc);

	} while (mxstep == 0 || nstep < mxstep);

	iflag = 1;

	/*500*/

	iwsp[0] = nmult;
	iwsp[1] = nexph;
	iwsp[2] = nscale;
	iwsp[3] = nstep;
	iwsp[4] = nreject;
	iwsp[5] = ibrkflag;
	iwsp[6] = mbrkdwn;

	wsp[0] = Comp(step_min);
	wsp[1] = Comp(step_max);
	wsp[2] = Comp(0.);
	wsp[3] = Comp(0.);
	wsp[4] = Comp(x_error);
	wsp[5] = Comp(s_error);
	wsp[6] = Comp(tbrkdwn);
	wsp[7] = Comp(sgn*t_now);
	wsp[8] = Comp(hump / vnorm);
	wsp[9] = Comp(beta / vnorm);
}


// expv()
// this function is extremely slow when used in a loop! due to dynamic memory allocation
// use ZGEXPV() for MatCoo<>, ZHEXPV() for MatCooH<>
// v cannot be empty!

inline void expv(SvecComp_IO v, CmobdDoub_I mat, Doub_I t, Int_I Nkrylov, Doub_I mat_norm, SvecComp_IO wsp_c, SvecInt_IO wsp_i, Doub_I tol = 0, Bool_I her = false)
{
#ifdef SLS_CHECK_SHAPES
	if (mat.n0() != mat.n1() || mat.n1() != v.size())
	    SLS_ERR("wrong shape!");
	if (wsp_c.size() < max(Long(10), mat.n0()*(Nkrylov + 2) + 5 * sqr(Nkrylov + 2) + 8))
	    SLS_ERR("wrong shape!");
	if (wsp_i.size() < max(Nkrylov + 2, 7))
	    SLS_ERR("wrong shape!");
#endif
	Int iflag;
	if (!her)
	    ZGEXPV((Int)v.size(), Nkrylov, t, v.p(),
	        tol, mat_norm, wsp_c.p(), (Int)wsp_c.size(),
	        wsp_i.p(), (Int)wsp_i.size(), mat, 0, iflag);
	else
	    ZHEXPV((Int)v.size(), Nkrylov, t, v.p(),
	        tol, mat_norm, wsp_c.p(), (Int)wsp_c.size(),
	        wsp_i.p(), (Int)wsp_i.size(), mat, 0, iflag);
}

inline void expv(SvecComp_IO v, CmobdDoub_I mat, Doub_I t, Int_I Nkrylov, Doub_I mat_norm, Doub_I tol = 0, Bool_I her = false)
{
	VecComp wsp_c(max(Long(10), mat.n0()*(Nkrylov + 2) + 5 * sqr(Nkrylov + 2) + 8));
	VecInt wsp_i(max(Nkrylov + 2, 7));
	SvecComp s_wsp_c(wsp_c.p(), wsp_c.size());
	SvecInt s_wsp_i(wsp_i.p(), wsp_i.size());
	expv(v, mat, t, Nkrylov, mat_norm, s_wsp_c, s_wsp_i, tol, her);
}

inline void expv(VecComp_IO v, McooDoub_I mat, Doub_I t, Int_I Nkrylov, Doub_I mat_norm, SvecComp_IO wsp_c, SvecInt_IO wsp_i, Doub_I tol = 0, Bool_I her = false)
{
#ifdef SLS_CHECK_SHAPES
	if (mat.n0() != mat.n1() || mat.n1() != v.size())
	    SLS_ERR("wrong shape!");
	if (wsp_c.size() < max(Long(10), mat.n0()*(Nkrylov + 2) + 5 * sqr(Nkrylov + 2) + 8))
	    SLS_ERR("wrong shape!");
	if (wsp_i.size() < max(Nkrylov + 2, 7))
	    SLS_ERR("wrong shape!");
#endif
	Int iflag;
	if (!her)
	    ZGEXPV((Int)v.size(), Nkrylov, t, v.p(),
	        tol, mat_norm, wsp_c.p(), (Int)wsp_c.size(),
	        wsp_i.p(), (Int)wsp_i.size(), mat, 0, iflag);
	else
	    ZHEXPV((Int)v.size(), Nkrylov, t, v.p(),
	        tol, mat_norm, wsp_c.p(), (Int)wsp_c.size(),
	        wsp_i.p(), (Int)wsp_i.size(), mat, 0, iflag);
}

inline void expv(VecComp_IO v, McooDoub_I mat, Doub_I t, Int_I Nkrylov, Doub_I mat_norm, Doub_I tol = 0, Bool_I her = false)
{
	VecComp wsp_c(max(Long(10), mat.n0()*(Nkrylov + 2) + 5 * sqr(Nkrylov + 2) + 8));
	VecInt wsp_i(max(Nkrylov + 2, 7));
	SvecComp s_wsp_c(wsp_c.p(), wsp_c.size());
	SvecInt s_wsp_i(wsp_i.p(), wsp_i.size());
	expv(v, mat, t, Nkrylov, mat_norm, s_wsp_c, s_wsp_i, tol, her);
}

inline void expv(SvecComp_IO v, McooComp_I mat, Doub_I t, Int_I Nkrylov, Doub_I mat_norm, SvecComp_IO wsp_c, SvecInt_IO wsp_i, Doub_I tol = 0, Bool_I her = false)
{
#ifdef SLS_CHECK_SHAPES
	if (mat.n0() != mat.n1() || mat.n1() != v.size())
	    SLS_ERR("wrong shape!");
	if (wsp_c.size() < max(Long(10), mat.n0()*(Nkrylov + 2) + 5 * sqr(Nkrylov + 2) + 8))
	    SLS_ERR("wrong shape!");
	if (wsp_i.size() < max(Nkrylov + 2, 7))
	    SLS_ERR("wrong shape!");
#endif
	Int iflag;
	if (!her)
	    ZGEXPV((Int)v.size(), Nkrylov, t, v.p(),
	        tol, mat_norm, wsp_c.p(), (Int)wsp_c.size(),
	        wsp_i.p(), (Int)wsp_i.size(), mat, 0, iflag);
	else
	    ZHEXPV((Int)v.size(), Nkrylov, t, v.p(),
	        tol, mat_norm, wsp_c.p(), (Int)wsp_c.size(),
	        wsp_i.p(), (Int)wsp_i.size(), mat, 0, iflag);
}

inline void expv(SvecComp_IO v, McooComp_I mat, Doub_I t, Int_I Nkrylov, Doub_I mat_norm, Doub_I tol = 0, Bool_I her = false)
{
	VecComp wsp_c(max(Long(10), mat.n0()*(Nkrylov + 2) + 5 * sqr(Nkrylov + 2) + 8));
	VecInt wsp_i(max(Nkrylov + 2, 7));
	SvecComp s_wsp_c(wsp_c.p(), wsp_c.size());
	SvecInt s_wsp_i(wsp_i.p(), wsp_i.size());
	expv(v, mat, t, Nkrylov, mat_norm, s_wsp_c, s_wsp_i, tol, her);
}

inline void expv(VecComp_IO v, McooComp_I mat, Doub_I t, Int_I Nkrylov, Doub_I mat_norm, SvecComp_IO wsp_c, SvecInt_IO wsp_i, Doub_I tol = 0, Bool_I her = false)
{
#ifdef SLS_CHECK_SHAPES
	if (mat.n0() != mat.n1() || mat.n1() != v.size())
	    SLS_ERR("wrong shape!");
	if (wsp_c.size() < max(Long(10), mat.n0()*(Nkrylov + 2) + 5 * sqr(Nkrylov + 2) + 8))
	    SLS_ERR("wrong shape!");
	if (wsp_i.size() < max(Nkrylov + 2, 7))
	    SLS_ERR("wrong shape!");
#endif
	Int iflag;
	if (!her)
	    ZGEXPV((Int)v.size(), Nkrylov, t, v.p(),
	        tol, mat_norm, wsp_c.p(), (Int)wsp_c.size(),
	        wsp_i.p(), (Int)wsp_i.size(), mat, 0, iflag);
	else
	    ZHEXPV((Int)v.size(), Nkrylov, t, v.p(),
	        tol, mat_norm, wsp_c.p(), (Int)wsp_c.size(),
	        wsp_i.p(), (Int)wsp_i.size(), mat, 0, iflag);
}

inline void expv(VecComp_IO v, McooComp_I mat, Doub_I t, Int_I Nkrylov, Doub_I mat_norm, Doub_I tol = 0, Bool_I her = false)
{
	VecComp wsp_c(max(Long(10), mat.n0()*(Nkrylov + 2) + 5 * sqr(Nkrylov + 2) + 8));
	VecInt wsp_i(max(Nkrylov + 2, 7));
	SvecComp s_wsp_c(wsp_c.p(), wsp_c.size());
	SvecInt s_wsp_i(wsp_i.p(), wsp_i.size());
	expv(v, mat, t, Nkrylov, mat_norm, s_wsp_c, s_wsp_i, tol, her);
}

inline void expv(SvecComp_IO v, CmobdComp_I mat, Doub_I t, Int_I Nkrylov, Doub_I mat_norm, SvecComp_IO wsp_c, SvecInt_IO wsp_i, Doub_I tol = 0, Bool_I her = false)
{
#ifdef SLS_CHECK_SHAPES
	if (mat.n0() != mat.n1() || mat.n1() != v.size())
	    SLS_ERR("wrong shape!");
	if (wsp_c.size() < max(Long(10), mat.n0()*(Nkrylov + 2) + 5 * sqr(Nkrylov + 2) + 8))
	    SLS_ERR("wrong shape!");
	if (wsp_i.size() < max(Nkrylov + 2, 7))
	    SLS_ERR("wrong shape!");
#endif
	Int iflag;
	if (!her)
	    ZGEXPV((Int)v.size(), Nkrylov, t, v.p(),
	        tol, mat_norm, wsp_c.p(), (Int)wsp_c.size(),
	        wsp_i.p(), (Int)wsp_i.size(), mat, 0, iflag);
	else
	    ZHEXPV((Int)v.size(), Nkrylov, t, v.p(),
	        tol, mat_norm, wsp_c.p(), (Int)wsp_c.size(),
	        wsp_i.p(), (Int)wsp_i.size(), mat, 0, iflag);
}

inline void expv(SvecComp_IO v, CmobdComp_I mat, Doub_I t, Int_I Nkrylov, Doub_I mat_norm, Doub_I tol = 0, Bool_I her = false)
{
	VecComp wsp_c(max(Long(10), mat.n0()*(Nkrylov + 2) + 5 * sqr(Nkrylov + 2) + 8));
	VecInt wsp_i(max(Nkrylov + 2, 7));
	SvecComp s_wsp_c(wsp_c.p(), wsp_c.size());
	SvecInt s_wsp_i(wsp_i.p(), wsp_i.size());
	expv(v, mat, t, Nkrylov, mat_norm, s_wsp_c, s_wsp_i, tol, her);
}

inline void expv(VecComp_IO v, CmatDoub_I mat, Doub_I t, Int_I Nkrylov, Doub_I mat_norm, SvecComp_IO wsp_c, SvecInt_IO wsp_i, Doub_I tol = 0, Bool_I her = false)
{
#ifdef SLS_CHECK_SHAPES
	if (mat.n0() != mat.n1() || mat.n1() != v.size())
	    SLS_ERR("wrong shape!");
	if (wsp_c.size() < max(Long(10), mat.n0()*(Nkrylov + 2) + 5 * sqr(Nkrylov + 2) + 8))
	    SLS_ERR("wrong shape!");
	if (wsp_i.size() < max(Nkrylov + 2, 7))
	    SLS_ERR("wrong shape!");
#endif
	Int iflag;
	if (!her)
	    ZGEXPV((Int)v.size(), Nkrylov, t, v.p(),
	        tol, mat_norm, wsp_c.p(), (Int)wsp_c.size(),
	        wsp_i.p(), (Int)wsp_i.size(), mat, 0, iflag);
	else
	    ZHEXPV((Int)v.size(), Nkrylov, t, v.p(),
	        tol, mat_norm, wsp_c.p(), (Int)wsp_c.size(),
	        wsp_i.p(), (Int)wsp_i.size(), mat, 0, iflag);
}

inline void expv(VecComp_IO v, CmatDoub_I mat, Doub_I t, Int_I Nkrylov, Doub_I mat_norm, Doub_I tol = 0, Bool_I her = false)
{
	VecComp wsp_c(max(Long(10), mat.n0()*(Nkrylov + 2) + 5 * sqr(Nkrylov + 2) + 8));
	VecInt wsp_i(max(Nkrylov + 2, 7));
	SvecComp s_wsp_c(wsp_c.p(), wsp_c.size());
	SvecInt s_wsp_i(wsp_i.p(), wsp_i.size());
	expv(v, mat, t, Nkrylov, mat_norm, s_wsp_c, s_wsp_i, tol, her);
}

inline void expv(VecComp_IO v, CmatComp_I mat, Doub_I t, Int_I Nkrylov, Doub_I mat_norm, SvecComp_IO wsp_c, SvecInt_IO wsp_i, Doub_I tol = 0, Bool_I her = false)
{
#ifdef SLS_CHECK_SHAPES
	if (mat.n0() != mat.n1() || mat.n1() != v.size())
	    SLS_ERR("wrong shape!");
	if (wsp_c.size() < max(Long(10), mat.n0()*(Nkrylov + 2) + 5 * sqr(Nkrylov + 2) + 8))
	    SLS_ERR("wrong shape!");
	if (wsp_i.size() < max(Nkrylov + 2, 7))
	    SLS_ERR("wrong shape!");
#endif
	Int iflag;
	if (!her)
	    ZGEXPV((Int)v.size(), Nkrylov, t, v.p(),
	        tol, mat_norm, wsp_c.p(), (Int)wsp_c.size(),
	        wsp_i.p(), (Int)wsp_i.size(), mat, 0, iflag);
	else
	    ZHEXPV((Int)v.size(), Nkrylov, t, v.p(),
	        tol, mat_norm, wsp_c.p(), (Int)wsp_c.size(),
	        wsp_i.p(), (Int)wsp_i.size(), mat, 0, iflag);
}

inline void expv(VecComp_IO v, CmatComp_I mat, Doub_I t, Int_I Nkrylov, Doub_I mat_norm, Doub_I tol = 0, Bool_I her = false)
{
	VecComp wsp_c(max(Long(10), mat.n0()*(Nkrylov + 2) + 5 * sqr(Nkrylov + 2) + 8));
	VecInt wsp_i(max(Nkrylov + 2, 7));
	SvecComp s_wsp_c(wsp_c.p(), wsp_c.size());
	SvecInt s_wsp_i(wsp_i.p(), wsp_i.size());
	expv(v, mat, t, Nkrylov, mat_norm, s_wsp_c, s_wsp_i, tol, her);
}


} // namespace slisc

#endif
