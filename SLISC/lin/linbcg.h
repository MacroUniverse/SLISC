// solving sparse linear equations by the preconditioned biconjugate gradient method
// see Numerical Recipes 3ed page 90
#pragma once
#include "cut.h"
#include "arithmetic.h"

namespace slisc {

struct LinbcgDoub {
	virtual void asolve(VecDoub_I b, VecDoub_O x, const Int itrnsp) = 0;
	virtual void atimes(VecDoub_I x, VecDoub_O r, const Int itrnsp) = 0;
	void solve(VecDoub_I b, VecDoub_IO x, const Int itol, const Doub tol,
		const Int itmax, Int &iter, Doub &err);
	Doub snrm(VecDoub_I sx, const Int itol);
};

inline void LinbcgDoub::solve(VecDoub_I b, VecDoub_IO x, const Int itol, const Doub tol,
	const Int itmax, Int &iter, Doub &err)
{
	Doub ak,akden,bk,bkden=1.0,bknum,bnrm,dxnrm,xnrm,zm1nrm,znrm=NaN;
	const Doub EPS=1.0e-14;
	Int j,n=b.size();
	VecDoub p(n),pp(n),r(n),rr(n),z(n),zz(n);
	iter=0;
	atimes(x,r,0);
	for (j=0;j<n;j++) {
		r[j]=b[j]-r[j];
		rr[j]=r[j];
	}
	//atimes(r,rr,0);
	if (itol == 1) {
		bnrm=snrm(b,itol);
		asolve(r,z,0);
	}
	else if (itol == 2) {
		asolve(b,z,0);
		bnrm=snrm(z,itol);
		asolve(r,z,0);
	}
	else if (itol == 3 || itol == 4) {
		asolve(b,z,0);
		bnrm=snrm(z,itol);
		asolve(r,z,0);
		znrm=snrm(z,itol);
	} else throw("illegal itol in linbcg");
	while (iter < itmax) {
		++iter;
		asolve(rr,zz,1);
		for (bknum=0.0,j=0;j<n;j++) bknum += z[j]*rr[j];
		if (iter == 1) {
			for (j=0;j<n;j++) {
				p[j]=z[j];
				pp[j]=zz[j];
			}
		} else {
			bk=bknum/bkden;
			for (j=0;j<n;j++) {
				p[j]=bk*p[j]+z[j];
				pp[j]=bk*pp[j]+zz[j];
			}
		}
		bkden=bknum;
		atimes(p,z,0);
		for (akden=0.0,j=0;j<n;j++) akden += z[j]*pp[j];
		ak=bknum/akden;
		atimes(pp,zz,1);
		for (j=0;j<n;j++) {
			x[j] += ak*p[j];
			r[j] -= ak*z[j];
			rr[j] -= ak*zz[j];
		}
		asolve(r,z,0);
		if (itol == 1)
			err=snrm(r,itol)/bnrm;
		else if (itol == 2)
			err=snrm(z,itol)/bnrm;
		else if (itol == 3 || itol == 4) {
			zm1nrm=znrm;
			znrm=snrm(z,itol);
			if (abs(zm1nrm-znrm) > EPS*znrm) {
				dxnrm=abs(ak)*snrm(p,itol);
				err=znrm/abs(zm1nrm-znrm)*dxnrm;
			} else {
				err=znrm/bnrm;
				continue;
			}
			xnrm=snrm(x,itol);
			if (err <= 0.5*xnrm) err /= xnrm;
			else {
				err=znrm/bnrm;
				continue;
			}
		}
		if (err <= tol) break;
	}
}

inline Doub LinbcgDoub::snrm(VecDoub_I sx, const Int itol)
{
	Int i,isamax,n=sx.size();
	Doub ans;
	if (itol <= 3) {
		ans = 0.0;
		for (i=0;i<n;i++) ans += sqr(sx[i]);
		return sqrt(ans);
	} else {
		isamax=0;
		for (i=0;i<n;i++) {
			if (abs(sx[i]) > abs(sx[isamax])) isamax=i;
		}
		return abs(sx[isamax]);
	}
}



// BiCG with symmetric matrix and no precondition (only tested for real matrix)
// 2-norm or inf-norm of vector sx
inline Doub snrm(const Doub *sx, Int n, const Int itol)
{
	Int i, isamax;
	Doub ans;
	if (itol <= 3) {
		ans = 0.0;
		for (i=0;i<n;i++) ans += sqr(sx[i]);
		return sqrt(ans);
	} else {
		isamax=0;
		for (i=0;i<n;i++) {
			if (abs(sx[i]) > abs(sx[isamax])) isamax=i;
		}
		return abs(sx[isamax]);
	}
}

inline void lin_eq_bcg_sym(Int_O iter, Doub_O err, VecDoub_IO x, CmatDoub_I A, VecDoub_I b, Int_I itol, Doub_I tol, Int_I itmax,  SvecDoub_IO wsp)
{
	Doub xnrm, dxnrm, bnrm, znrm=NaN, zm1nrm;
	Doub ak, akden, bk, bkden=1., bknum;
	const Doub EPS = 1.0e-14;
	Int j, n=b.size();
	if (wsp.size() < 6*n) SLS_ERR("not enough workspace!");
	SvecDoub p = cut(wsp, 0, n), pp = cut(wsp, n, n), r = cut(wsp, 2*n, n);
	SvecDoub rr = cut(wsp, 3*n, n), z = cut(wsp, 4*n, n), zz = cut(wsp, 5*n, n);
	iter=0;
	mul(r, A, x);
	for (j=0;j<n;j++) {
		r[j]=b[j]-r[j];
		rr[j]=r[j];
	}
	if (itol == 1) {
		bnrm=snrm(b.p(),n,itol);
	}
	else if (itol == 2) {
		bnrm=snrm(b.p(),n,itol);
	}
	else if (itol == 3 || itol == 4) {
		bnrm=snrm(b.p(),n,itol);
		znrm = snrm(r.p(),n,itol);
	}
	else
		SLS_ERR("illegal itol in linbcg_sym");

	while (iter < itmax) {
		++iter;
		for (bknum=0.0,j=0;j<n;j++) bknum += r[j]*rr[j];
		if (iter == 1) {
			for (j=0;j<n;j++) {
				p[j]=r[j];
				pp[j]=rr[j];
			}
		} else {
			bk=bknum/bkden;
			for (j=0;j<n;j++) {
				p[j]=bk*p[j]+r[j];
				pp[j]=bk*pp[j]+rr[j];
			}
		}
		bkden=bknum;
		mul(z, A, p);
		for (akden=0.0,j=0;j<n;j++) akden += z[j]*pp[j];
		ak=bknum/akden;
		mul(zz, A, pp);
		for (j=0;j<n;j++) {
			x[j] += ak*p[j];
			r[j] -= ak*z[j];
			rr[j] -= ak*zz[j];
		}
		
		if (itol == 1)
			err=snrm(r.p(),n,itol)/bnrm;
		else if (itol == 2)
			err=snrm(r.p(),n,itol)/bnrm;
		else if (itol == 3 || itol == 4) {
			zm1nrm=znrm;
			znrm=snrm(r.p(),n,itol);
			if (abs(zm1nrm-znrm) > EPS*znrm) {
				dxnrm=abs(ak)*snrm(p.p(),n,itol);
				err=znrm/abs(zm1nrm-znrm)*dxnrm;
			} else {
				err=znrm/bnrm;
				continue;
			}
			xnrm=snrm(x.p(),n,itol);
			if (err <= 0.5*xnrm) err /= xnrm;
			else {
				err=znrm/bnrm;
				continue;
			}
		}
		if (err <= tol) break;
	}
}


// modified from Matlab function bicgsta() with no preconditioner
// ref https://ww2.mathworks.cn/help/matlab/ref/bicgstab.html?lang=en
// algo ref https://en.wikipedia.org/wiki/Biconjugate_gradient_stabilized_method
// return: [0] Success [1] maxit iterations reached [3] stagnated after two consecutive iterations were the same
// [4] scalar underflow/overflow

inline Int bicgstab_matlab(Doub_O relres, Long_O iter,
	VecDoub_IO x, CmatDoub_I A, VecDoub_I b,  Doub_I tol, Long_I maxit, VecDoub_IO wsp_c)
{
	Doub eps = 2.2e-16;
	Long m = b.size(); Int flag;
	if (wsp_c.size() < 8*m) SLS_ERR("illegal size!");
	const Doub n2b = norm(b);
	if (n2b == 0) {
		copy(x, 0);
		flag = 0;     // a valid solution has been obtained
		relres = iter = 0;
		return flag;
	}
	SvecDoub xmin = cut(wsp_c, 0, m); copy(xmin, x);  // Iterate which has minimal residual so far
	SvecDoub p = cut(wsp_c, m, m), v = cut(wsp_c, 2*m, m), xhalf= cut(wsp_c, 3*m, m),
		s = cut(wsp_c, 4*m, m), t = cut(wsp_c, 5*m, m),	r = cut(wsp_c, 6*m, m);
	mul(r, A, x); sub(r, b, r);
	SvecDoub rt = cut(wsp_c, 7*m, m); copy(rt, r);    // Shadow residual
	flag = 1;
	Long imin = 0;                      // Iteration at which xmin was computed
	const Doub tolb = tol * n2b;        // Relative tolerance
	Doub normr = norm(r), normr_act = normr;  // Norm of residual
	if (normr <= tolb) {                // Initial guess is a good enough solution
		relres = normr / n2b; iter = 0; return 0;
	}
	Doub normrmin = normr;             // Norm of residual from xmin
	Doub rho = 1, omega = 1, alpha;
	Long stag = 0;                     // stagnation of the method
	Long moresteps = 0, maxstagsteps = 3, maxmsteps = min(m/50, min(Long(10), m-maxit)), ii;

	for (ii = 0; ii < maxit; ++ii) {
		Doub rho1 = rho;
		rho = dot(rt, r);
		if (rho == 0. || isinf(rho)) {
			flag = 4; break;
		}
		if (ii == 0)
			copy(p, r);
		else {
			Doub beta = (rho/rho1)*(alpha/omega);
			if (beta == 0 || isinf(beta)) {
				flag = 4; break;
			}
			for (Long i = 0; i < m; ++i)
				p[i] = r[i] + beta * (p[i] - omega * v[i]);
		}
		mul(v, A, p);
		Doub rtv = dot(rt, v);
		if (rtv == 0 || isinf(rtv)) {
			flag = 4; break;
		}
		alpha = rho / rtv;
		if (isinf(alpha)) {
			flag = 4; break;
		}
		
		if (abs(alpha)*norm(p) < eps*norm(x))
			++stag;
		else
			stag = 0;
		
		for (Long i = 0; i < m; ++i) {
			xhalf[i] = x[i] + alpha * p[i];  // form the "half" iterate
			s[i] = r[i] - alpha * v[i];      // residual associated with xhalf
		}
		normr = norm(s);
		normr_act = normr;
		
		// check for convergence
		if (normr <= tolb || stag >= maxstagsteps || moresteps) {
			mul(s, A, xhalf);
			sub(s, b, s);
			normr_act = norm(s);
			if (normr_act <= tolb) {
				copy(x, xhalf);
				flag = 0;
				iter = ii + 0.5;
				break;
			}
			else {
				if (stag >= maxstagsteps && moresteps == 0)
					stag = 0;
				++moresteps;
				if (moresteps >= maxmsteps) {
					SLS_WARN("bicgstab: tooSmallTolerance");
					flag = 3;
					copy(x, xhalf);
					break;
				}
			}
		}
		if (stag >= maxstagsteps) {
			flag = 3; break;
		}
		if (normr_act < normrmin) {        // update minimal norm quantities
			normrmin = normr_act;
			copy(xmin, xhalf);
			imin = ii+1. - 0.5;
		}
		mul(t, A, s);
		Doub tt = norm2(t);
		if (tt == 0 || isinf(tt)) {
			flag = 4; break;
		}
		omega = dot(t, s) / tt;
		if (isinf(omega)) {
			flag = 4; break;
		}
		
		if (abs(omega)*norm(s) < eps*norm(xhalf))
			++stag;
		else
			stag = 0;
		for (Long i = 0; i < m; ++i) {
			x[i] = xhalf[i] + omega * s[i]; // x = (x + alpha * p) + omega * s
			r[i] = s[i] - omega * t[i];
		}
		normr = norm(r);
		normr_act = normr;

		// check for convergence
		if (normr <= tolb || stag >= maxstagsteps || moresteps) {
			mul(r, A, x);
			sub(r, b, r);
			normr_act = norm(r);
			if (normr_act <= tolb) {
				flag = 0; iter = ii+1; break;
			}
			else {
				if (stag >= maxstagsteps && moresteps == 0)
					stag = 0;
				++moresteps;
				if (moresteps >= maxmsteps) {
					SLS_WARN("bicgstab: tooSmallTolerance");
					flag = 3; break;
				}
			}
		}
		if (normr_act < normrmin) { // update minimal norm quantities
			normrmin = normr_act;
			copy(xmin, x);
			imin = ii+1;
		}
		if (stag >= maxstagsteps) {
			flag = 3; break;
		}
	}

	// returned solution is first with minimal residual
	if (flag == 0)
		relres = normr_act / n2b;
	else {
		mul(r, A, xmin);
		sub(r, b, r);
		if (norm(r) <= normr_act) {
			copy(x, xmin);
			iter = imin;
			relres = norm(r) / n2b;
		}
		else {
			iter = ii + 1;
			relres = normr_act / n2b;
		}
	}
	return flag;
}

inline Bool isinf(Comp_I x) { return isinf(x.real()) || isinf(x.imag()); }

inline Int bicgstab_matlab(Doub_O relres, Long_O iter,
	VecComp_IO x, CmatComp_I A, VecComp_I b,  Doub_I tol, Long_I maxit, VecComp_IO wsp_c)
{
	Doub eps = 2.2e-16;
	Long m = b.size(); Int flag;
	if (wsp_c.size() < 8*m) SLS_ERR("illegal size!");
	const Doub n2b = norm(b);
	if (n2b == 0) {
		copy(x, 0);
		flag = 0;     // a valid solution has been obtained
		relres = iter = 0;
		return flag;
	}
	SvecComp xmin = cut(wsp_c, 0, m); copy(xmin, x);  // Iterate which has minimal residual so far
	SvecComp p = cut(wsp_c, m, m), v = cut(wsp_c, 2*m, m), xhalf= cut(wsp_c, 3*m, m),
		s = cut(wsp_c, 4*m, m), t = cut(wsp_c, 5*m, m),	r = cut(wsp_c, 6*m, m);
	mul(r, A, x); sub(r, b, r);
	SvecComp rt = cut(wsp_c, 7*m, m); copy(rt, r);    // Shadow residual
	flag = 1;
	Long imin = 0;                      // Iteration at which xmin was computed
	const Doub tolb = tol * n2b;        // Relative tolerance
	Doub normr = norm(r), normr_act = normr;  // Norm of residual
	if (normr <= tolb) {                // Initial guess is a good enough solution
		relres = normr / n2b; iter = 0; return 0;
	}
	Doub normrmin = normr;             // Norm of residual from xmin
	Comp rho = 1, omega = 1, alpha;
	Long stag = 0;                     // stagnation of the method
	Long moresteps = 0, maxstagsteps = 3, maxmsteps = min(m/50, min(Long(10), m-maxit)), ii;

	for (ii = 0; ii < maxit; ++ii) {
		Comp rho1 = rho;
		rho = dot(rt, r);
		if (rho == 0. || isinf(rho)) {
			flag = 4; break;
		}
		if (ii == 0)
			copy(p, r);
		else {
			Comp beta = (rho/rho1)*(alpha/omega);
			if (beta == 0 || isinf(beta)) {
				flag = 4; break;
			}
			for (Long i = 0; i < m; ++i)
				p[i] = r[i] + beta * (p[i] - omega * v[i]);
		}
		mul(v, A, p);
		Comp rtv = dot(rt, v);
		if (rtv == 0 || isinf(rtv)) {
			flag = 4; break;
		}
		alpha = rho / rtv;
		if (isinf(alpha)) {
			flag = 4; break;
		}
		
		if (abs(alpha)*norm(p) < eps*norm(x))
			++stag;
		else
			stag = 0;
		
		for (Long i = 0; i < m; ++i) {
			xhalf[i] = x[i] + alpha * p[i];  // form the "half" iterate
			s[i] = r[i] - alpha * v[i];      // residual associated with xhalf
		}
		normr = norm(s);
		normr_act = normr;
		
		// check for convergence
		if (normr <= tolb || stag >= maxstagsteps || moresteps) {
			mul(s, A, xhalf);
			sub(s, b, s);
			normr_act = norm(s);
			if (normr_act <= tolb) {
				copy(x, xhalf);
				flag = 0;
				iter = ii + 0.5;
				break;
			}
			else {
				if (stag >= maxstagsteps && moresteps == 0)
					stag = 0;
				++moresteps;
				if (moresteps >= maxmsteps) {
					SLS_WARN("bicgstab: tooSmallTolerance");
					flag = 3;
					copy(x, xhalf);
					break;
				}
			}
		}
		if (stag >= maxstagsteps) {
			flag = 3; break;
		}
		if (normr_act < normrmin) {        // update minimal norm quantities
			normrmin = normr_act;
			copy(xmin, xhalf);
			imin = ii+1. - 0.5;
		}
		mul(t, A, s);
		Doub tt = norm2(t);
		if (tt == 0 || isinf(tt)) {
			flag = 4; break;
		}
		omega = dot(t, s) / tt;
		if (isinf(omega)) {
			flag = 4; break;
		}
		
		if (abs(omega)*norm(s) < eps*norm(xhalf))
			++stag;
		else
			stag = 0;
		for (Long i = 0; i < m; ++i) {
			x[i] = xhalf[i] + omega * s[i]; // x = (x + alpha * p) + omega * s
			r[i] = s[i] - omega * t[i];
		}
		normr = norm(r);
		normr_act = normr;

		// check for convergence
		if (normr <= tolb || stag >= maxstagsteps || moresteps) {
			mul(r, A, x);
			sub(r, b, r);
			normr_act = norm(r);
			if (normr_act <= tolb) {
				flag = 0; iter = ii+1; break;
			}
			else {
				if (stag >= maxstagsteps && moresteps == 0)
					stag = 0;
				++moresteps;
				if (moresteps >= maxmsteps) {
					SLS_WARN("bicgstab: tooSmallTolerance");
					flag = 3; break;
				}
			}
		}
		if (normr_act < normrmin) { // update minimal norm quantities
			normrmin = normr_act;
			copy(xmin, x);
			imin = ii+1;
		}
		if (stag >= maxstagsteps) {
			flag = 3; break;
		}
	}

	// returned solution is first with minimal residual
	if (flag == 0)
		relres = normr_act / n2b;
	else {
		mul(r, A, xmin);
		sub(r, b, r);
		if (norm(r) <= normr_act) {
			copy(x, xmin);
			iter = imin;
			relres = norm(r) / n2b;
		}
		else {
			iter = ii + 1;
			relres = normr_act / n2b;
		}
	}
	return flag;
}


// optimized bicgstab_matlab (less memory)
// return: [0] Success [1] maxit iterations reached [3] stagnated after two consecutive iterations were the same
// [4] scalar underflow/overflow
// all returns other than [0] will not have other outputs
inline Int bicgstab_matlab_optim(Doub_O relres, Long_O iter,
	VecDoub_IO x, CmatDoub &A, VecDoub_I b,  Doub_I tol, Long_I maxit, VecDoub_IO wsp_c)
{
	Doub eps = 2.2e-16;
	Long m = b.size(); Int flag;
	if (wsp_c.size() < 7*m) SLS_ERR("illegal size!");
	const Doub n2b = norm(b);
	if (n2b == 0) {
		copy(x, 0);
		relres = iter = 0;
		return 0;
	}
	SvecDoub p = cut(wsp_c, 0, m), v = cut(wsp_c, m, m), xhalf= cut(wsp_c, 2*m, m),
		s = cut(wsp_c, 3*m, m), t = cut(wsp_c, 4*m, m),	r = cut(wsp_c, 5*m, m);
	mul(r, A, x); sub(r, b, r);
	SvecDoub rt = cut(wsp_c, 6*m, m); copy(rt, r);    // Shadow residual
	flag = 1;
	const Doub tolb = tol * n2b;        // Relative tolerance
	Doub normr = norm(r), normr_act = normr;  // Norm of residual
	if (normr <= tolb) {                // Initial guess is a good enough solution
		relres = normr / n2b; iter = 0; return 0;
	}
	Doub rho = 1, omega = 1, alpha;
	Long stag = 0;                     // stagnation of the method
	Long moresteps = 0, maxstagsteps = 3, maxmsteps = min(m/50, min(Long(10), m-maxit)), ii;

	for (ii = 0; ii < maxit; ++ii) {
		Doub rho1 = rho;
		rho = dot(rt, r);
		if (rho == 0. || isinf(rho)) {
			flag = 4; break;
		}
		if (ii == 0)
			copy(p, r);
		else {
			Doub beta = (rho/rho1)*(alpha/omega);
			if (beta == 0 || isinf(beta)) {
				flag = 4; break;
			}
			for (Long i = 0; i < m; ++i)
				p[i] = r[i] + beta * (p[i] - omega * v[i]);
		}
		mul(v, A, p);
		Doub rtv = dot(rt, v);
		if (rtv == 0 || isinf(rtv)) {
			flag = 4; break;
		}
		alpha = rho / rtv;
		if (isinf(alpha)) {
			flag = 4; break;
		}
		
		if (abs(alpha)*norm(p) < eps*norm(x))
			++stag;
		else
			stag = 0;
		
		for (Long i = 0; i < m; ++i) {
			xhalf[i] = x[i] + alpha * p[i];  // form the "half" iterate
			s[i] = r[i] - alpha * v[i];      // residual associated with xhalf
		}
		normr = norm(s);
		normr_act = normr;
		
		// check convergence
		if (normr <= tolb || stag >= maxstagsteps || moresteps) {
			mul(s, A, xhalf);
			sub(s, b, s);
			normr_act = norm(s);
			if (normr_act <= tolb) {
				copy(x, xhalf);
				flag = 0; iter = ii + 0.5;
				break;
			}
			else {
				if (stag >= maxstagsteps && moresteps == 0)
					stag = 0;
				++moresteps;
				if (moresteps >= maxmsteps) {
					SLS_WARN("bicgstab: tooSmallTolerance");
					flag = 3; break;
				}
			}
		}
		if (stag >= maxstagsteps) {
			flag = 3; break;
		}
		mul(t, A, s);
		Doub tt = norm2(t);
		if (tt == 0 || isinf(tt)) {
			flag = 4; break;
		}
		omega = dot(t, s) / tt;
		if (isinf(omega)) {
			flag = 4; break;
		}
		
		if (abs(omega)*norm(s) < eps*norm(xhalf))
			++stag;
		else
			stag = 0;
		for (Long i = 0; i < m; ++i) {
			x[i] = xhalf[i] + omega * s[i]; // x = (x + alpha * p) + omega * s
			r[i] = s[i] - omega * t[i];
		}
		normr = norm(r);
		normr_act = normr;

		// check convergence
		if (normr <= tolb || stag >= maxstagsteps || moresteps) {
			mul(r, A, x);
			sub(r, b, r);
			normr_act = norm(r);
			if (normr_act <= tolb) {
				flag = 0; iter = ii+1; break;
			}
			else {
				if (stag >= maxstagsteps && moresteps == 0)
					stag = 0;
				++moresteps;
				if (moresteps >= maxmsteps) {
					SLS_WARN("bicgstab: tooSmallTolerance");
					flag = 3; break;
				}
			}
		}
		if (stag >= maxstagsteps) {
			flag = 3; break;
		}
	}

	// returned solution is first with minimal residual
	if (flag == 0)
		relres = normr_act / n2b;
	return flag;
}

inline Int bicgstab_matlab_optim(Doub_O relres, Long_O iter,
	VecComp_IO x, CmatComp &A, VecComp_I b,  Doub_I tol, Long_I maxit, VecComp_IO wsp_c)
{
	Doub eps = 2.2e-16;
	Long m = b.size(); Int flag;
	if (wsp_c.size() < 7*m) SLS_ERR("illegal size!");
	const Doub n2b = norm(b);
	if (n2b == 0) {
		copy(x, 0);
		relres = iter = 0;
		return 0;
	}
	SvecComp p = cut(wsp_c, 0, m), v = cut(wsp_c, m, m), xhalf= cut(wsp_c, 2*m, m),
		s = cut(wsp_c, 3*m, m), t = cut(wsp_c, 4*m, m),	r = cut(wsp_c, 5*m, m);
	mul(r, A, x); sub(r, b, r);
	SvecComp rt = cut(wsp_c, 6*m, m); copy(rt, r);    // Shadow residual
	flag = 1;
	const Doub tolb = tol * n2b;        // Relative tolerance
	Doub normr = norm(r), normr_act = normr;  // Norm of residual
	if (normr <= tolb) {                // Initial guess is a good enough solution
		relres = normr / n2b; iter = 0; return 0;
	}
	Comp rho = 1, omega = 1, alpha;
	Long stag = 0;                     // stagnation of the method
	Long moresteps = 0, maxstagsteps = 3, maxmsteps = min(m/50, min(Long(10), m-maxit)), ii;

	for (ii = 0; ii < maxit; ++ii) {
		Comp rho1 = rho;
		rho = dot(rt, r);
		if (rho == 0. || isinf(rho)) {
			flag = 4; break;
		}
		if (ii == 0)
			copy(p, r);
		else {
			Comp beta = (rho/rho1)*(alpha/omega);
			if (beta == 0 || isinf(beta)) {
				flag = 4; break;
			}
			for (Long i = 0; i < m; ++i)
				p[i] = r[i] + beta * (p[i] - omega * v[i]);
		}
		mul(v, A, p);
		Comp rtv = dot(rt, v);
		if (rtv == 0 || isinf(rtv)) {
			flag = 4; break;
		}
		alpha = rho / rtv;
		if (isinf(alpha)) {
			flag = 4; break;
		}
		
		if (abs(alpha)*norm(p) < eps*norm(x))
			++stag;
		else
			stag = 0;
		
		for (Long i = 0; i < m; ++i) {
			xhalf[i] = x[i] + alpha * p[i];  // form the "half" iterate
			s[i] = r[i] - alpha * v[i];      // residual associated with xhalf
		}
		normr = norm(s);
		normr_act = normr;
		
		// check convergence
		if (normr <= tolb || stag >= maxstagsteps || moresteps) {
			mul(s, A, xhalf);
			sub(s, b, s);
			normr_act = norm(s);
			if (normr_act <= tolb) {
				copy(x, xhalf);
				flag = 0; iter = ii + 0.5;
				break;
			}
			else {
				if (stag >= maxstagsteps && moresteps == 0)
					stag = 0;
				++moresteps;
				if (moresteps >= maxmsteps) {
					SLS_WARN("bicgstab: tooSmallTolerance");
					flag = 3; break;
				}
			}
		}
		if (stag >= maxstagsteps) {
			flag = 3; break;
		}
		mul(t, A, s);
		Doub tt = norm2(t);
		if (tt == 0 || isinf(tt)) {
			flag = 4; break;
		}
		omega = dot(t, s) / tt;
		if (isinf(omega)) {
			flag = 4; break;
		}
		
		if (abs(omega)*norm(s) < eps*norm(xhalf))
			++stag;
		else
			stag = 0;
		for (Long i = 0; i < m; ++i) {
			x[i] = xhalf[i] + omega * s[i]; // x = (x + alpha * p) + omega * s
			r[i] = s[i] - omega * t[i];
		}
		normr = norm(r);
		normr_act = normr;

		// check convergence
		if (normr <= tolb || stag >= maxstagsteps || moresteps) {
			mul(r, A, x);
			sub(r, b, r);
			normr_act = norm(r);
			if (normr_act <= tolb) {
				flag = 0; iter = ii+1; break;
			}
			else {
				if (stag >= maxstagsteps && moresteps == 0)
					stag = 0;
				++moresteps;
				if (moresteps >= maxmsteps) {
					SLS_WARN("bicgstab: tooSmallTolerance");
					flag = 3; break;
				}
			}
		}
		if (stag >= maxstagsteps) {
			flag = 3; break;
		}
	}

	// returned solution is first with minimal residual
	if (flag == 0)
		relres = normr_act / n2b;
	return flag;
}

class CNmatComp;
inline void mul(SvecComp_O, CNmatComp &, SvecComp_I);

inline Int bicgstab_matlab_optim(Doub_O relres, Long_O iter,
	SvecComp_IO x, CNmatComp &A, SvecComp_I b,  Doub_I tol, Long_I maxit, SvecComp_IO wsp_c)
{
	Doub eps = 2.2e-16;
	Long m = b.size(); Int flag;
	if (wsp_c.size() < 7*m) SLS_ERR("illegal size!");
	const Doub n2b = norm(b);
	if (n2b == 0) {
		copy(x, 0);
		relres = iter = 0;
		return 0;
	}
	SvecComp p = cut(wsp_c, 0, m), v = cut(wsp_c, m, m), xhalf= cut(wsp_c, 2*m, m),
		s = cut(wsp_c, 3*m, m), t = cut(wsp_c, 4*m, m),	r = cut(wsp_c, 5*m, m);
	mul(r, A, x); sub(r, b, r);
	SvecComp rt = cut(wsp_c, 6*m, m); copy(rt, r);    // Shadow residual
	flag = 1;
	const Doub tolb = tol * n2b;        // Relative tolerance
	Doub normr = norm(r), normr_act = normr;  // Norm of residual
	if (normr <= tolb) {                // Initial guess is a good enough solution
		relres = normr / n2b; iter = 0; return 0;
	}
	Comp rho = 1, omega = 1, alpha;
	Long stag = 0;                     // stagnation of the method
	Long moresteps = 0, maxstagsteps = 3, maxmsteps = min(m/50, min(Long(10), m-maxit)), ii;

	for (ii = 0; ii < maxit; ++ii) {
		Comp rho1 = rho;
		rho = dot(rt, r);
		if (rho == 0. || isinf(rho)) {
			flag = 4; break;
		}
		if (ii == 0)
			copy(p, r);
		else {
			Comp beta = (rho/rho1)*(alpha/omega);
			if (beta == 0 || isinf(beta)) {
				flag = 4; break;
			}
			for (Long i = 0; i < m; ++i)
				p[i] = r[i] + beta * (p[i] - omega * v[i]);
		}
		mul(v, A, p);
		Comp rtv = dot(rt, v);
		if (rtv == 0 || isinf(rtv)) {
			flag = 4; break;
		}
		alpha = rho / rtv;
		if (isinf(alpha)) {
			flag = 4; break;
		}
		
		if (abs(alpha)*norm(p) < eps*norm(x))
			++stag;
		else
			stag = 0;
		
		for (Long i = 0; i < m; ++i) {
			xhalf[i] = x[i] + alpha * p[i];  // form the "half" iterate
			s[i] = r[i] - alpha * v[i];      // residual associated with xhalf
		}
		normr = norm(s);
		normr_act = normr;
		
		// check convergence
		if (normr <= tolb || stag >= maxstagsteps || moresteps) {
			mul(s, A, xhalf);
			sub(s, b, s);
			normr_act = norm(s);
			if (normr_act <= tolb) {
				copy(x, xhalf);
				flag = 0; iter = ii + 0.5;
				break;
			}
			else {
				if (stag >= maxstagsteps && moresteps == 0)
					stag = 0;
				++moresteps;
				if (moresteps >= maxmsteps) {
					SLS_WARN("bicgstab: tooSmallTolerance");
					flag = 3; break;
				}
			}
		}
		if (stag >= maxstagsteps) {
			flag = 3; break;
		}
		mul(t, A, s);
		Doub tt = norm2(t);
		if (tt == 0 || isinf(tt)) {
			flag = 4; break;
		}
		omega = dot(t, s) / tt;
		if (isinf(omega)) {
			flag = 4; break;
		}
		
		if (abs(omega)*norm(s) < eps*norm(xhalf))
			++stag;
		else
			stag = 0;
		for (Long i = 0; i < m; ++i) {
			x[i] = xhalf[i] + omega * s[i]; // x = (x + alpha * p) + omega * s
			r[i] = s[i] - omega * t[i];
		}
		normr = norm(r);
		normr_act = normr;

		// check convergence
		if (normr <= tolb || stag >= maxstagsteps || moresteps) {
			mul(r, A, x);
			sub(r, b, r);
			normr_act = norm(r);
			if (normr_act <= tolb) {
				flag = 0; iter = ii+1; break;
			}
			else {
				if (stag >= maxstagsteps && moresteps == 0)
					stag = 0;
				++moresteps;
				if (moresteps >= maxmsteps) {
					SLS_WARN("bicgstab: tooSmallTolerance");
					flag = 3; break;
				}
			}
		}
		if (stag >= maxstagsteps) {
			flag = 3; break;
		}
	}

	// returned solution is first with minimal residual
	if (flag == 0)
		relres = normr_act / n2b;
	return flag;
}


}; // namespace slisc
