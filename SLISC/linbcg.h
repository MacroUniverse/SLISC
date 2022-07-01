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

void LinbcgDoub::solve(VecDoub_I b, VecDoub_IO x, const Int itol, const Doub tol,
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
Doub LinbcgDoub::snrm(VecDoub_I sx, const Int itol)
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

struct LinbcgQdoub {
	virtual void asolve(VecQdoub_I b, VecQdoub_O x, const Int itrnsp) = 0;
	virtual void atimes(VecQdoub_I x, VecQdoub_O r, const Int itrnsp) = 0;
	void solve(VecQdoub_I b, VecQdoub_IO x, const Int itol, const Qdoub tol,
		const Int itmax, Int &iter, Qdoub &err);
	Qdoub snrm(VecQdoub_I sx, const Int itol);
};

void LinbcgQdoub::solve(VecQdoub_I b, VecQdoub_IO x, const Int itol, const Qdoub tol,
	const Int itmax, Int &iter, Qdoub &err)
{
	Qdoub ak,akden,bk,bkden=1.0,bknum,bnrm,dxnrm,xnrm,zm1nrm,znrm=NaN;
	const Qdoub EPS=1.0e-14;
	Int j,n=b.size();
	VecQdoub p(n),pp(n),r(n),rr(n),z(n),zz(n);
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
Qdoub LinbcgQdoub::snrm(VecQdoub_I sx, const Int itol)
{
	Int i,isamax,n=sx.size();
	Qdoub ans;
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


}; // namespace slisc
