#pragma once
#include "../dense/Vec.h"
#include "../dense/Svec.h"
#include "../dense/Dvec.h"
#include "../arith/arith1.h"
#ifdef SLS_USE_GSL
#include <gsl/gsl_interp.h>
#include <gsl/gsl_spline.h>
#endif

namespace slisc {

// evaluate Lgendre interpolation polynomial
inline Doub legendre_interp_poly(VecDoub_I x, Long_I ind, Doub_I x_q)
{
	Doub x_ind = x[ind], prod = 1;
	for (Long i = 0; i < ind; ++i)
	    prod *= (x_q - x[i])/(x_ind - x[i]);
	for (Long i = ind + 1; i < x.size(); ++i)
	    prod *= (x_q - x[i])/(x_ind - x[i]);
	return prod;
}

inline Doub legendre_interp_poly(VecQdoub_I x, Long_I ind, Doub_I x_q)
{
	Doub x_ind = x[ind], prod = 1;
	for (Long i = 0; i < ind; ++i)
	    prod *= (x_q - x[i])/(x_ind - x[i]);
	for (Long i = ind + 1; i < x.size(); ++i)
	    prod *= (x_q - x[i])/(x_ind - x[i]);
	return prod;
}

inline Doub legendre_interp_poly(SvecDoub_I x, Long_I ind, Doub_I x_q)
{
	Doub x_ind = x[ind], prod = 1;
	for (Long i = 0; i < ind; ++i)
	    prod *= (x_q - x[i])/(x_ind - x[i]);
	for (Long i = ind + 1; i < x.size(); ++i)
	    prod *= (x_q - x[i])/(x_ind - x[i]);
	return prod;
}

inline Doub legendre_interp_poly(SvecQdoub_I x, Long_I ind, Doub_I x_q)
{
	Doub x_ind = x[ind], prod = 1;
	for (Long i = 0; i < ind; ++i)
	    prod *= (x_q - x[i])/(x_ind - x[i]);
	for (Long i = ind + 1; i < x.size(); ++i)
	    prod *= (x_q - x[i])/(x_ind - x[i]);
	return prod;
}


#ifdef SLS_USE_GSL
struct poly_interp1
{
	gsl_interp_accel *m_acc;
	gsl_spline *m_spline;

// real polynomial interpolation using gsl
	poly_interp1(VecDoub_I x, VecDoub_I y)
	{
	    if (x.size() != y.size())
	        SLS_ERR("x, y not the same length!");
	    m_acc = gsl_interp_accel_alloc();
	    m_spline = gsl_spline_alloc(gsl_interp_polynomial, x.size());
	    gsl_spline_init(m_spline, x.p(), y.p(), x.size());
	}

	poly_interp1(SvecDoub_I x, SvecDoub_I y)
	{
	    if (x.size() != y.size())
	        SLS_ERR("x, y not the same length!");
	    m_acc = gsl_interp_accel_alloc();
	    m_spline = gsl_spline_alloc(gsl_interp_polynomial, x.size());
	    gsl_spline_init(m_spline, x.p(), y.p(), x.size());
	}

	poly_interp1(DvecDoub_I x, DvecDoub_I y)
	{
	    if (x.size() != y.size())
	        SLS_ERR("x, y not the same length!");
	    m_acc = gsl_interp_accel_alloc();
	    m_spline = gsl_spline_alloc(gsl_interp_polynomial, x.size());
	    gsl_spline_init(m_spline, x.p(), y.p(), x.size());
	}


	// evaluate
	Doub operator()(Doub_I x)
	{
	    return gsl_spline_eval(m_spline, x, m_acc);
	}

	// evaluate derivative
	Doub der(Doub_I x)
	{
	    return gsl_spline_eval_deriv(m_spline, x, m_acc);
	}

	// evaluate second derivative
	Doub der2(Doub_I x)
	{
	    return gsl_spline_eval_deriv2(m_spline, x, m_acc);
	}

	~poly_interp1()
	{
	    gsl_spline_free(m_spline);
	    gsl_interp_accel_free(m_acc);
	}
};
#endif

#ifdef SLS_USE_GSL
struct poly_comp_interp1
{
	gsl_interp_accel *m_acc1, *m_acc2;
	gsl_spline *m_spline1, *m_spline2;
	vecDoub y_real, y_imag;

// complex valued polynomial interpolation using gsl
	poly_comp_interp1(VecDoub_I x, VecComp_I y)
	{
	    Long N = x.size();
	    if (N != y.size())
	        SLS_ERR("x, y not the same length!");
	    m_acc1 = gsl_interp_accel_alloc();
	    m_acc2 = gsl_interp_accel_alloc();
	    m_spline1 = gsl_spline_alloc(gsl_interp_polynomial, N);
	    m_spline2 = gsl_spline_alloc(gsl_interp_polynomial, N);
	    y_real.resize(N); y_imag.resize(N);
	    for (Long i = 0; i < N; ++i) {
	        y_real[i] = real(y[i]);
	        y_imag[i] = imag(y[i]);
	    }
	    gsl_spline_init(m_spline1, x.p(), y_real.data(), N);
	    gsl_spline_init(m_spline2, x.p(), y_imag.data(), N);
	}

	poly_comp_interp1(SvecDoub_I x, SvecComp_I y)
	{
	    Long N = x.size();
	    if (N != y.size())
	        SLS_ERR("x, y not the same length!");
	    m_acc1 = gsl_interp_accel_alloc();
	    m_acc2 = gsl_interp_accel_alloc();
	    m_spline1 = gsl_spline_alloc(gsl_interp_polynomial, N);
	    m_spline2 = gsl_spline_alloc(gsl_interp_polynomial, N);
	    y_real.resize(N); y_imag.resize(N);
	    for (Long i = 0; i < N; ++i) {
	        y_real[i] = real(y[i]);
	        y_imag[i] = imag(y[i]);
	    }
	    gsl_spline_init(m_spline1, x.p(), y_real.data(), N);
	    gsl_spline_init(m_spline2, x.p(), y_imag.data(), N);
	}

	poly_comp_interp1(DvecDoub_I x, DvecComp_I y)
	{
	    Long N = x.size();
	    if (N != y.size())
	        SLS_ERR("x, y not the same length!");
	    m_acc1 = gsl_interp_accel_alloc();
	    m_acc2 = gsl_interp_accel_alloc();
	    m_spline1 = gsl_spline_alloc(gsl_interp_polynomial, N);
	    m_spline2 = gsl_spline_alloc(gsl_interp_polynomial, N);
	    y_real.resize(N); y_imag.resize(N);
	    for (Long i = 0; i < N; ++i) {
	        y_real[i] = real(y[i]);
	        y_imag[i] = imag(y[i]);
	    }
	    gsl_spline_init(m_spline1, x.p(), y_real.data(), N);
	    gsl_spline_init(m_spline2, x.p(), y_imag.data(), N);
	}


	Comp operator()(Doub_I x)
	{
	    return Comp(gsl_spline_eval(m_spline1, x, m_acc1),
	            gsl_spline_eval(m_spline2, x, m_acc2));
	}

	Comp der(Doub_I x)
	{
	    return Comp(gsl_spline_eval_deriv(m_spline1, x, m_acc1),
	            gsl_spline_eval_deriv(m_spline2, x, m_acc2));
	}

	Comp der2(Doub_I x)
	{
	    return Comp(gsl_spline_eval_deriv2(m_spline1, x, m_acc1),
	            gsl_spline_eval_deriv2(m_spline2, x, m_acc2));
	}

	~poly_comp_interp1()
	{
	    gsl_spline_free(m_spline1);
	    gsl_spline_free(m_spline2);
	    gsl_interp_accel_free(m_acc1);
	    gsl_interp_accel_free(m_acc2);
	}
};
#endif

// adapted from numerical recipes 3ed
// save() for scalar
struct Base_interp_Doub
{
	Long n, mm, jsav, cor, dj;
	const Doub *xx, *yy;
	Base_interp_Doub(VecDoub_I x, const Doub *y, Long m)
	    : n(x.size()), mm(m), jsav(0), cor(0), xx(&x[0]), yy(y) {
	    dj = min(1,(Long)pow((Doub)n,(Doub)0.25));
	}

	Base_interp_Doub(const Doub *x, Long_I Nx, const Doub *y,  Long m)
	    : n(Nx), mm(m), jsav(0), cor(0), xx(x), yy(y) {
	    dj = min(1,(Long)pow((Doub)n,(Doub)0.25));
	}

	Doub interp(Doub x) {
	    Long jlo = cor ? hunt(x) : locate(x);
	    return rawinterp(jlo,x);
	}

	void interp(VecDoub &v, const VecDoub &v1) {
	    v.resize(v1.size());
	    for (Long i = 0; i < v1.size(); ++i) {
	        v[i] = interp(v1[i]);
	    }
	}

	inline Long locate(Doub_I x);
	inline Long hunt(Doub_I x);
	
	Doub virtual rawinterp(Long jlo, Doub x) = 0;
};

struct Poly_interp_Doub : Base_interp_Doub
{
	Doub dy;
	Poly_interp_Doub(VecDoub_I xv, VecDoub_I yv, Long m)
	    : Base_interp_Doub(xv,&yv[0],m), dy(0.) {}
	inline Doub rawinterp(Long jl, Doub x);
};

struct Rat_interp_Doub : Base_interp_Doub
{
	Doub dy;
	Rat_interp_Doub(VecDoub_I xv, VecDoub_I yv, Long m)
	    : Base_interp_Doub(xv,&yv[0],m), dy(0.) {}
	inline Doub rawinterp(Long jl, Doub x);
};

struct Spline_interp_Doub : Base_interp_Doub
{
	VecDoub y2;
	
	Spline_interp_Doub(VecDoub_I xv, VecDoub_I yv, Doub yp1=1.e99, Doub ypn=1.e99)
	: Base_interp_Doub(xv,&yv[0],2), y2(xv.size())
	{sety2(&xv[0],&yv[0],yp1,ypn);}

	Spline_interp_Doub(VecDoub_I xv, const Doub *yv, Doub yp1=1.e99, Doub ypn=1.e99)
	: Base_interp_Doub(xv,yv,2), y2(xv.size())
	{sety2(&xv[0],yv,yp1,ypn);}

	Spline_interp_Doub(const Doub *xv, Long_I Nxv, const Doub *yv, Doub yp1=1.e99, Doub ypn=1.e99)
	: Base_interp_Doub(xv,Nxv,yv,2), y2(Nxv)
	{sety2(xv,yv,yp1,ypn);}

	inline void sety2(const Doub *xv, const Doub *yv, Doub_I yp1, Doub_I ypn);
	inline Doub rawinterp(Long jl, Doub xv);
};

struct BaryRat_interp_Doub : Base_interp_Doub
{
	VecDoub w;
	Long d;
	inline BaryRat_interp_Doub(VecDoub_I xv, VecDoub_I yv, Long dd);
	inline Doub rawinterp(Long jl, Doub x);
	inline Doub interp(Doub x);
};

// Base_interp_Doub implementation

inline Long Base_interp_Doub::locate(Doub_I x)
{
	Long ju, jm, jl;
	if (n < 2 || mm < 2 || mm > n) throw("locate size error");
	Bool ascnd = (xx[n - 1] >= xx[0]);
	jl = 0;
	ju = n - 1;
	while (ju - jl > 1) {
	    jm = (ju + jl) >> 1;
	    if ((x >= xx[jm]) == ascnd)
	        jl = jm;
	    else
	        ju = jm;
	}
	cor = abs(jl - jsav) > dj ? 0 : 1;
	jsav = jl;
	return max(0, min(n - mm, jl - ((mm - 2) >> 1)));
}

inline Long Base_interp_Doub::hunt(Doub_I x)
{
	Long jl = jsav, jm, ju, inc = 1;
	if (n < 2 || mm < 2 || mm > n) throw("hunt size error");
	Bool ascnd = (xx[n - 1] >= xx[0]);
	if (jl < 0 || jl > n - 1) {
	    jl = 0;
	    ju = n - 1;
	}
	else {
	    if ((x >= xx[jl]) == ascnd) {
	        for (;;) {
	            ju = jl + inc;
	            if (ju >= n - 1) { ju = n - 1; break; }
	            else if ((x < xx[ju]) == ascnd) break;
	            else {
	                jl = ju;
	                inc += inc;
	            }
	        }
	    }
	    else {
	        ju = jl;
	        for (;;) {
	            jl = jl - inc;
	            if (jl <= 0) { jl = 0; break; }
	            else if ((x >= xx[jl]) == ascnd) break;
	            else {
	                ju = jl;
	                inc += inc;
	            }
	        }
	    }
	}
	while (ju - jl > 1) {
	    jm = (ju + jl) >> 1;
	    if ((x >= xx[jm]) == ascnd)
	        jl = jm;
	    else
	        ju = jm;
	}
	cor = abs(jl - jsav) > dj ? 0 : 1;
	jsav = jl;
	return max(0, min(n - mm, jl - ((mm - 2) >> 1)));
}

// Poly_interp implementation

inline Doub Poly_interp_Doub::rawinterp(Long jl, Doub x)
{
	Long i, m, ns = 0;
	Doub y, den, dif, dift, ho, hp, w;
	const Doub *xa = &xx[jl], *ya = &yy[jl];
	VecDoub c(mm), d(mm);
	dif = abs(x - xa[0]);
	for (i = 0; i<mm; i++) {
	    if ((dift = abs(x - xa[i])) < dif) {
	        ns = i;
	        dif = dift;
	    }
	    c[i] = ya[i];
	    d[i] = ya[i];
	}
	y = ya[ns--];
	for (m = 1; m<mm; m++) {
	    for (i = 0; i<mm - m; i++) {
	        ho = xa[i] - x;
	        hp = xa[i + m] - x;
	        w = c[i + 1] - d[i];
	        if ((den = ho - hp) == 0.0) throw("Poly_interp_Doub error");
	        den = w / den;
	        d[i] = hp * den;
	        c[i] = ho * den;
	    }
	    y += (dy = (2 * (ns + 1) < (mm - m) ? c[ns + 1] : d[ns--]));
	}
	return y;
}

// Rat_interp implementation

inline Doub Rat_interp_Doub::rawinterp(Long jl, Doub x)
{
	const Doub TINY = 1.0e-99;
	Long m, i, ns = 0;
	Doub y, w, t, hh, h, dd;
	const Doub *xa = &xx[jl], *ya = &yy[jl];
	VecDoub c(mm), d(mm);
	hh = abs(x - xa[0]);
	for (i = 0; i<mm; i++) {
	    h = abs(x - xa[i]);
	    if (h == 0.0) {
	        dy = 0.0;
	        return ya[i];
	    }
	    else if (h < hh) {
	        ns = i;
	        hh = h;
	    }
	    c[i] = ya[i];
	    d[i] = ya[i] + TINY;
	}
	y = ya[ns--];
	for (m = 1; m<mm; m++) {
	    for (i = 0; i<mm - m; i++) {
	        w = c[i + 1] - d[i];
	        h = xa[i + m] - x;
	        t = (xa[i] - x)*d[i] / h;
	        dd = t - c[i + 1];
	        if (dd == 0.0) throw("Error in routine ratint");
	        dd = w / dd;
	        d[i] = c[i + 1] * dd;
	        c[i] = t * dd;
	    }
	    y += (dy = (2 * (ns + 1) < (mm - m) ? c[ns + 1] : d[ns--]));
	}
	return y;
}

// Spline_interp implementation

inline void Spline_interp_Doub::sety2(const Doub *xv, const Doub *yv, Doub_I yp1, Doub_I ypn)
{
	Long i, k;
	Doub p, qn, sig, un;
	Long n = y2.size();
	VecDoub u(n - 1);
	if (yp1 > 0.99e99)
	    y2[0] = u[0] = 0.0;
	else {
	    y2[0] = -0.5;
	    u[0] = (3.0 / (xv[1] - xv[0]))*((yv[1] - yv[0]) / (xv[1] - xv[0]) - yp1);
	}
	for (i = 1; i<n - 1; i++) {
	    sig = (xv[i] - xv[i - 1]) / (xv[i + 1] - xv[i - 1]);
	    p = sig * y2[i - 1] + 2.0;
	    y2[i] = (sig - 1.0) / p;
	    u[i] = (yv[i + 1] - yv[i]) / (xv[i + 1] - xv[i]) - (yv[i] - yv[i - 1]) / (xv[i] - xv[i - 1]);
	    u[i] = (6.0*u[i] / (xv[i + 1] - xv[i - 1]) - sig * u[i - 1]) / p;
	}
	if (ypn > 0.99e99)
	    qn = un = 0.0;
	else {
	    qn = 0.5;
	    un = (3.0 / (xv[n - 1] - xv[n - 2]))*(ypn - (yv[n - 1] - yv[n - 2]) / (xv[n - 1] - xv[n - 2]));
	}
	y2[n - 1] = (un - qn * u[n - 2]) / (qn*y2[n - 2] + 1.0);
	for (k = n - 2; k >= 0; k--)
	    y2[k] = y2[k] * y2[k + 1] + u[k];
}

inline Doub Spline_interp_Doub::rawinterp(Long jl, Doub x)
{
	Long klo = jl, khi = jl + 1;
	Doub y, h, b, a;
	h = xx[khi] - xx[klo];
	if (h == 0.0) throw("Bad input to routine splint");
	a = (xx[khi] - x) / h;
	b = (x - xx[klo]) / h;
	y = a * yy[klo] + b * yy[khi] + ((a*a*a - a)*y2[klo]
	    + (b*b*b - b)*y2[khi])*(h*h) / 6.0;
	return y;
}

// BarryRat_interp implementation

inline BaryRat_interp_Doub::BaryRat_interp_Doub(VecDoub_I xv, VecDoub_I yv, Long dd)
	: Base_interp_Doub(xv, &yv[0], xv.size()), w(n), d(dd)
{
	if (n <= d) throw("d too large for number of points in BaryRat_interp_Doub");
	for (Long k = 0; k<n; k++) {
	    Long imin = max(k - d, 0);
	    Long imax = k >= n - d ? n - d - 1 : k;
	    Doub temp = imin & 1 ? -1.0 : 1.0;
	    Doub sum = 0.0;
	    for (Long i = imin; i <= imax; i++) {
	        Long jmax = min(i + d, n - 1);
	        Doub term = 1.0;
	        for (Long j = i; j <= jmax; j++) {
	            if (j == k) continue;
	            term *= (xx[k] - xx[j]);
	        }
	        term = temp / term;
	        temp = -temp;
	        sum += term;
	    }
	    w[k] = sum;
	}
}

inline Doub BaryRat_interp_Doub::rawinterp(Long jl, Doub x)
{
	Doub num = 0, den = 0;
	for (Long i = 0; i<n; i++) {
	    Doub h = x - xx[i];
	    if (h == 0.0) {
	        return yy[i];
	    }
	    else {
	        Doub temp = w[i] / h;
	        num += temp * yy[i];
	        den += temp;
	    }
	}
	return num / den;
}

inline Doub BaryRat_interp_Doub::interp(Doub x) {
	return rawinterp(1, x);
}

struct Base_interp_Qdoub
{
	Long n, mm, jsav, cor, dj;
	const Qdoub *xx, *yy;
	Base_interp_Qdoub(VecQdoub_I x, const Qdoub *y, Long m)
	    : n(x.size()), mm(m), jsav(0), cor(0), xx(&x[0]), yy(y) {
	    dj = min(1,(Long)pow((Qdoub)n,(Qdoub)0.25));
	}

	Base_interp_Qdoub(const Qdoub *x, Long_I Nx, const Qdoub *y,  Long m)
	    : n(Nx), mm(m), jsav(0), cor(0), xx(x), yy(y) {
	    dj = min(1,(Long)pow((Qdoub)n,(Qdoub)0.25));
	}

	Qdoub interp(Qdoub x) {
	    Long jlo = cor ? hunt(x) : locate(x);
	    return rawinterp(jlo,x);
	}

	void interp(VecQdoub &v, const VecQdoub &v1) {
	    v.resize(v1.size());
	    for (Long i = 0; i < v1.size(); ++i) {
	        v[i] = interp(v1[i]);
	    }
	}

	inline Long locate(Qdoub_I x);
	inline Long hunt(Qdoub_I x);
	
	Qdoub virtual rawinterp(Long jlo, Qdoub x) = 0;
};

struct Poly_interp_Qdoub : Base_interp_Qdoub
{
	Qdoub dy;
	Poly_interp_Qdoub(VecQdoub_I xv, VecQdoub_I yv, Long m)
	    : Base_interp_Qdoub(xv,&yv[0],m), dy(0.) {}
	inline Qdoub rawinterp(Long jl, Qdoub x);
};

struct Rat_interp_Qdoub : Base_interp_Qdoub
{
	Qdoub dy;
	Rat_interp_Qdoub(VecQdoub_I xv, VecQdoub_I yv, Long m)
	    : Base_interp_Qdoub(xv,&yv[0],m), dy(0.) {}
	inline Qdoub rawinterp(Long jl, Qdoub x);
};

struct Spline_interp_Qdoub : Base_interp_Qdoub
{
	VecQdoub y2;
	
	Spline_interp_Qdoub(VecQdoub_I xv, VecQdoub_I yv, Qdoub yp1=1.e99, Qdoub ypn=1.e99)
	: Base_interp_Qdoub(xv,&yv[0],2), y2(xv.size())
	{sety2(&xv[0],&yv[0],yp1,ypn);}

	Spline_interp_Qdoub(VecQdoub_I xv, const Qdoub *yv, Qdoub yp1=1.e99, Qdoub ypn=1.e99)
	: Base_interp_Qdoub(xv,yv,2), y2(xv.size())
	{sety2(&xv[0],yv,yp1,ypn);}

	Spline_interp_Qdoub(const Qdoub *xv, Long_I Nxv, const Qdoub *yv, Qdoub yp1=1.e99, Qdoub ypn=1.e99)
	: Base_interp_Qdoub(xv,Nxv,yv,2), y2(Nxv)
	{sety2(xv,yv,yp1,ypn);}

	inline void sety2(const Qdoub *xv, const Qdoub *yv, Qdoub_I yp1, Qdoub_I ypn);
	inline Qdoub rawinterp(Long jl, Qdoub xv);
};

struct BaryRat_interp_Qdoub : Base_interp_Qdoub
{
	VecQdoub w;
	Long d;
	inline BaryRat_interp_Qdoub(VecQdoub_I xv, VecQdoub_I yv, Long dd);
	inline Qdoub rawinterp(Long jl, Qdoub x);
	inline Qdoub interp(Qdoub x);
};

// Base_interp_Qdoub implementation

inline Long Base_interp_Qdoub::locate(Qdoub_I x)
{
	Long ju, jm, jl;
	if (n < 2 || mm < 2 || mm > n) throw("locate size error");
	Bool ascnd = (xx[n - 1] >= xx[0]);
	jl = 0;
	ju = n - 1;
	while (ju - jl > 1) {
	    jm = (ju + jl) >> 1;
	    if ((x >= xx[jm]) == ascnd)
	        jl = jm;
	    else
	        ju = jm;
	}
	cor = abs(jl - jsav) > dj ? 0 : 1;
	jsav = jl;
	return max(0, min(n - mm, jl - ((mm - 2) >> 1)));
}

inline Long Base_interp_Qdoub::hunt(Qdoub_I x)
{
	Long jl = jsav, jm, ju, inc = 1;
	if (n < 2 || mm < 2 || mm > n) throw("hunt size error");
	Bool ascnd = (xx[n - 1] >= xx[0]);
	if (jl < 0 || jl > n - 1) {
	    jl = 0;
	    ju = n - 1;
	}
	else {
	    if ((x >= xx[jl]) == ascnd) {
	        for (;;) {
	            ju = jl + inc;
	            if (ju >= n - 1) { ju = n - 1; break; }
	            else if ((x < xx[ju]) == ascnd) break;
	            else {
	                jl = ju;
	                inc += inc;
	            }
	        }
	    }
	    else {
	        ju = jl;
	        for (;;) {
	            jl = jl - inc;
	            if (jl <= 0) { jl = 0; break; }
	            else if ((x >= xx[jl]) == ascnd) break;
	            else {
	                ju = jl;
	                inc += inc;
	            }
	        }
	    }
	}
	while (ju - jl > 1) {
	    jm = (ju + jl) >> 1;
	    if ((x >= xx[jm]) == ascnd)
	        jl = jm;
	    else
	        ju = jm;
	}
	cor = abs(jl - jsav) > dj ? 0 : 1;
	jsav = jl;
	return max(0, min(n - mm, jl - ((mm - 2) >> 1)));
}

// Poly_interp implementation

inline Qdoub Poly_interp_Qdoub::rawinterp(Long jl, Qdoub x)
{
	Long i, m, ns = 0;
	Qdoub y, den, dif, dift, ho, hp, w;
	const Qdoub *xa = &xx[jl], *ya = &yy[jl];
	VecQdoub c(mm), d(mm);
	dif = abs(x - xa[0]);
	for (i = 0; i<mm; i++) {
	    if ((dift = abs(x - xa[i])) < dif) {
	        ns = i;
	        dif = dift;
	    }
	    c[i] = ya[i];
	    d[i] = ya[i];
	}
	y = ya[ns--];
	for (m = 1; m<mm; m++) {
	    for (i = 0; i<mm - m; i++) {
	        ho = xa[i] - x;
	        hp = xa[i + m] - x;
	        w = c[i + 1] - d[i];
	        if ((den = ho - hp) == 0.0) throw("Poly_interp_Qdoub error");
	        den = w / den;
	        d[i] = hp * den;
	        c[i] = ho * den;
	    }
	    y += (dy = (2 * (ns + 1) < (mm - m) ? c[ns + 1] : d[ns--]));
	}
	return y;
}

// Rat_interp implementation

inline Qdoub Rat_interp_Qdoub::rawinterp(Long jl, Qdoub x)
{
	const Qdoub TINY = 1.0e-99;
	Long m, i, ns = 0;
	Qdoub y, w, t, hh, h, dd;
	const Qdoub *xa = &xx[jl], *ya = &yy[jl];
	VecQdoub c(mm), d(mm);
	hh = abs(x - xa[0]);
	for (i = 0; i<mm; i++) {
	    h = abs(x - xa[i]);
	    if (h == 0.0) {
	        dy = 0.0;
	        return ya[i];
	    }
	    else if (h < hh) {
	        ns = i;
	        hh = h;
	    }
	    c[i] = ya[i];
	    d[i] = ya[i] + TINY;
	}
	y = ya[ns--];
	for (m = 1; m<mm; m++) {
	    for (i = 0; i<mm - m; i++) {
	        w = c[i + 1] - d[i];
	        h = xa[i + m] - x;
	        t = (xa[i] - x)*d[i] / h;
	        dd = t - c[i + 1];
	        if (dd == 0.0) throw("Error in routine ratint");
	        dd = w / dd;
	        d[i] = c[i + 1] * dd;
	        c[i] = t * dd;
	    }
	    y += (dy = (2 * (ns + 1) < (mm - m) ? c[ns + 1] : d[ns--]));
	}
	return y;
}

// Spline_interp implementation

inline void Spline_interp_Qdoub::sety2(const Qdoub *xv, const Qdoub *yv, Qdoub_I yp1, Qdoub_I ypn)
{
	Long i, k;
	Qdoub p, qn, sig, un;
	Long n = y2.size();
	VecQdoub u(n - 1);
	if (yp1 > 0.99e99)
	    y2[0] = u[0] = 0.0;
	else {
	    y2[0] = -0.5;
	    u[0] = (3.0 / (xv[1] - xv[0]))*((yv[1] - yv[0]) / (xv[1] - xv[0]) - yp1);
	}
	for (i = 1; i<n - 1; i++) {
	    sig = (xv[i] - xv[i - 1]) / (xv[i + 1] - xv[i - 1]);
	    p = sig * y2[i - 1] + 2.0;
	    y2[i] = (sig - 1.0) / p;
	    u[i] = (yv[i + 1] - yv[i]) / (xv[i + 1] - xv[i]) - (yv[i] - yv[i - 1]) / (xv[i] - xv[i - 1]);
	    u[i] = (6.0*u[i] / (xv[i + 1] - xv[i - 1]) - sig * u[i - 1]) / p;
	}
	if (ypn > 0.99e99)
	    qn = un = 0.0;
	else {
	    qn = 0.5;
	    un = (3.0 / (xv[n - 1] - xv[n - 2]))*(ypn - (yv[n - 1] - yv[n - 2]) / (xv[n - 1] - xv[n - 2]));
	}
	y2[n - 1] = (un - qn * u[n - 2]) / (qn*y2[n - 2] + 1.0);
	for (k = n - 2; k >= 0; k--)
	    y2[k] = y2[k] * y2[k + 1] + u[k];
}

inline Qdoub Spline_interp_Qdoub::rawinterp(Long jl, Qdoub x)
{
	Long klo = jl, khi = jl + 1;
	Qdoub y, h, b, a;
	h = xx[khi] - xx[klo];
	if (h == 0.0) throw("Bad input to routine splint");
	a = (xx[khi] - x) / h;
	b = (x - xx[klo]) / h;
	y = a * yy[klo] + b * yy[khi] + ((a*a*a - a)*y2[klo]
	    + (b*b*b - b)*y2[khi])*(h*h) / 6.0;
	return y;
}

// BarryRat_interp implementation

inline BaryRat_interp_Qdoub::BaryRat_interp_Qdoub(VecQdoub_I xv, VecQdoub_I yv, Long dd)
	: Base_interp_Qdoub(xv, &yv[0], xv.size()), w(n), d(dd)
{
	if (n <= d) throw("d too large for number of points in BaryRat_interp_Qdoub");
	for (Long k = 0; k<n; k++) {
	    Long imin = max(k - d, 0);
	    Long imax = k >= n - d ? n - d - 1 : k;
	    Qdoub temp = imin & 1 ? -1.0 : 1.0;
	    Qdoub sum = 0.0;
	    for (Long i = imin; i <= imax; i++) {
	        Long jmax = min(i + d, n - 1);
	        Qdoub term = 1.0;
	        for (Long j = i; j <= jmax; j++) {
	            if (j == k) continue;
	            term *= (xx[k] - xx[j]);
	        }
	        term = temp / term;
	        temp = -temp;
	        sum += term;
	    }
	    w[k] = sum;
	}
}

inline Qdoub BaryRat_interp_Qdoub::rawinterp(Long jl, Qdoub x)
{
	Qdoub num = 0, den = 0;
	for (Long i = 0; i<n; i++) {
	    Qdoub h = x - xx[i];
	    if (h == 0.0) {
	        return yy[i];
	    }
	    else {
	        Qdoub temp = w[i] / h;
	        num += temp * yy[i];
	        den += temp;
	    }
	}
	return num / den;
}

inline Qdoub BaryRat_interp_Qdoub::interp(Qdoub x) {
	return rawinterp(1, x);
}


} // namespace slisc
