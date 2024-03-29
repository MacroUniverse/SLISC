// calculate spherical harmonics Y_{lm}(\theta,\phi) and coupled spherical harmonics
#pragma once
#include "../str/unicode.h"
#include "../spec/legendreP.h"
#include "../spec/anglib.h"

namespace slisc {

// same definition with Wolfram Alpha
// see http://littleshi.cn/online/SphHar.html

inline Comp ylm(Long_I l, Long_I m, Doub_I theta, Doub_I phi)
{
	Doub A, ret0;
	Long n;
	Doub th = mod_fl(n, theta, 2 * PI);
	Doub ph;
	if (th > PI) {
		th = 2 * PI - th;
		ph = mod_fl(n, phi + PI, 2 * PI);
	}
	else
		ph = mod_fl(n, phi, 2 * PI);

	if (m >= 0) {
		A = sqrt((2 * l + 1)*factorial(l - m) / (4 * PI * factorial(l + m)));
		ret0 = A * legendre_Plm(l, m, cos(th));
	}
	else {
		A = pow(-1, m) * sqrt((2 * l + 1)*factorial(l + m) / (4 * PI * factorial(l - m)));
		ret0 = A * legendre_Plm(l, -m, cos(th));
	}

	if (m != 0) {
		Comp ret = ret0 * exp(Comp(0., m*ph));
		return ret;
	}
	return ret0;
}

// generalized spherical harmonics
inline Comp yl1l2LM(Long_I l1, Long_I l2, Long_I L, Long_I M,
	Doub_I theta1, Doub_I phi1, Doub_I theta2, Doub_I phi2)
{
	Comp sum = 0.;
	Long Ndim, m1_max;
	cgTableDim(Ndim, m1_max, l1, l2, M);
	for (Long m1 = m1_max + 1 - Ndim; m1 <= m1_max; ++m1) {
		Long m2 = M - m1;
		sum += cleb_Doub(2*l1, 2*m1, 2*l2, 2*m2, 2*L, 2*M) *
			ylm(l1, m1, theta1, phi1) * ylm(l2, m2, theta2, phi2);
	}
	return sum;
}

inline Qcomp ylm(Long_I l, Long_I m, Qdoub_I theta, Qdoub_I phi)
{
	Qdoub A, ret0;
	Long n;
	Qdoub th = mod_fl(n, theta, 2 * PIq);
	Qdoub ph;
	if (th > PIq) {
		th = 2 * PIq - th;
		ph = mod_fl(n, phi + PIq, 2 * PIq);
	}
	else
		ph = mod_fl(n, phi, 2 * PIq);

	if (m >= 0) {
		A = sqrt((2 * l + 1)*factorial(l - m) / (4 * PIq * factorial(l + m)));
		ret0 = A * legendre_Plm(l, m, cos(th));
	}
	else {
		A = pow(-1, m) * sqrt((2 * l + 1)*factorial(l + m) / (4 * PIq * factorial(l - m)));
		ret0 = A * legendre_Plm(l, -m, cos(th));
	}

	if (m != 0) {
		Qcomp ret = ret0 * exp(Qcomp(0., m*ph));
		return ret;
	}
	return ret0;
}

// generalized spherical harmonics
inline Qcomp yl1l2LM(Long_I l1, Long_I l2, Long_I L, Long_I M,
	Qdoub_I theta1, Qdoub_I phi1, Qdoub_I theta2, Qdoub_I phi2)
{
	Qcomp sum = 0.;
	Long Ndim, m1_max;
	cgTableDim(Ndim, m1_max, l1, l2, M);
	for (Long m1 = m1_max + 1 - Ndim; m1 <= m1_max; ++m1) {
		Long m2 = M - m1;
		sum += cleb_Qdoub(2*l1, 2*m1, 2*l2, 2*m2, 2*L, 2*M) *
			ylm(l1, m1, theta1, phi1) * ylm(l2, m2, theta2, phi2);
	}
	return sum;
}


} // namespace slisc
