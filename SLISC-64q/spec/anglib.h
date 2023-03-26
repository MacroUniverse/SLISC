// partly translated from anglib.f90
// as directly as possible! all vars values unchanged.

// anglib.f90: angular momentum coupling coefficients in Fortran 90
// Copyright (C) 1998  Paul Stevenson

#pragma once
#include "../arith/scalar_arith.h"

namespace slisc {

// calc dimension of CG table and max(m1)
// CGtableDim() in MyMatlabLibrary
inline void cgTableDim(Long_O Ndim, Long_O m1_max, Long_I l1, Long_I l2, Long_I M)
{
	if (abs(M) > abs(l1 - l2))
	    Ndim = l1 + l2 - abs(M) + 1;
	else
	    Ndim = 2 * min(l1, l2) + 1;

	if (M >= l1 - l2)
	    m1_max = l1;
	else
	    m1_max = l2 + M;
}

inline Doub binom_Doub(Long_I n, Long_I r) {
	if (n == r || r == 0)
	    return 1;
	else if (r == 1)
	    return (Doub)n;
	else
	    return (Doub)n / Doub(n - r)*binom_Doub(n - 1, r);
}

// clebsch gordan coefficient [j1,m1,j2,m2,j,m] for integer numbers
inline Doub cleb_int_Doub(Long_I j1, Long_I m1, Long_I j2, Long_I m2, Long_I j, Long_I m)
{
	Doub cleb, factor, sum;
	Long par, z, zmin, zmax;

	if (j1 < 0 || j2 < 0 || j < 0 ||
	    abs(m1)>j1 || abs(m2)>j2 || abs(m)>j ||
	    j>j1+j2 || j<abs(j1-j2) || m1+m2!=m) {
	    cleb = 0;
	}
	else if (isodd(j1+j2+j) && ((m1==0 && m2==0 && m==0) || (j1==j2 && m1==m2) || (j1==j && m1==m) || (j2==j && m2==m))) {
	    cleb = 0;
	}
	else {
	    factor = binom_Doub(2*j1, j1 + j2 - j) / binom_Doub(j1 + j2 + j + 1, j1 + j2 - j);
	    factor *= binom_Doub(2*j2, j1 + j2 - j) / binom_Doub(2*j1, j1 - m1);
	    factor /= binom_Doub(2*j2, j2 - m2) * binom_Doub(2*j, j - m);
	    factor = sqrt(factor);

	    zmin = max(Long(0), max(2*j2 + j1 - m1 - (j1 + j2 + j), 2*j1 + j2 + m2 - (j1 + j2 + j)));
	    zmax = min(j1 + j2 - j, min(j1 - m1, j2 + m2));

	    sum = 0;
	    for (z = zmin; z <= zmax; ++z) {
	        par = isodd(z)? -1: 1;
	        sum += par * binom_Doub(j1 + j2 - j, z)*binom_Doub(j1 - j2 + j, j1 - m1 - z)
	            * binom_Doub(-j1 + j2 + j, j2 + m2 - z);
	    }
	    cleb = factor * sum;
	}
	return cleb;
}

// clebsch gordan coefficient [two_j1/2,two_m1/2,two_j2/2,two_m2/2,two_j/2,two_m/2]
inline Doub cleb_Doub(Long_I two_j1, Long_I two_m1, Long_I two_j2, Long_I two_m2, Long_I two_j, Long_I two_m)
{
	Long_I j1 = two_j1, m1 = two_m1, j2 = two_j2, m2 = two_m2, j = two_j, m = two_m;
	Doub cleb, factor, sum;
	Long par, z, zmin, zmax;

	if (2 * (j1 / 2) - j1 != 2 * (abs(m1) / 2) - abs(m1) ||
	    2 * (j2 / 2) - j2 != 2 * (abs(m2) / 2) - abs(m2) ||
	    2 * (j / 2) - j != 2 * (abs(m) / 2) - abs(m) ||
	    j1<0 || j2<0  || j<0 || abs(m1)>j1 || abs(m2)>j2 ||
	    abs(m)>j || j1 + j2<j || abs(j1 - j2)>j || m1 + m2 != m) {
	    cleb = 0;
	}
	else if (!isodd(j1) && !isodd(j2) && !isodd(j) && isodd((j1+j2+j)/2) && ((m1==0 && m2==0 && m==0) ||
		(j1==j2 && m1==m2) || (j1==j && m1==m) || (j2==j && m2==m))) {
	    cleb = 0;
	}
	else {
	    factor = binom_Doub(j1, (j1 + j2 - j) / 2) / binom_Doub((j1 + j2 + j + 2) / 2, (j1 + j2 - j) / 2);
	    factor = factor * binom_Doub(j2, (j1 + j2 - j) / 2) / binom_Doub(j1, (j1 - m1) / 2);
	    factor = factor / binom_Doub(j2, (j2 - m2) / 2) / binom_Doub(j, (j - m) / 2);
	    factor = sqrt(factor);

	    zmin = max(Long(0), max(j2 + (j1 - m1) / 2 - (j1 + j2 + j) / 2, j1 + (j2 + m2) / 2 - (j1 + j2 + j) / 2));
	    zmax = min((j1 + j2 - j) / 2, min((j1 - m1) / 2, (j2 + m2) / 2));

	    sum = 0;
	    for (z = zmin; z <= zmax; ++z) {
	        par = 1;
	            if (2 * (z / 2) - z != 0)
	                par = -1;
	        sum = sum + par * binom_Doub((j1 + j2 - j) / 2, z)*binom_Doub((j1 - j2 + j) / 2, (j1 - m1) / 2 - z)
	            * binom_Doub((-j1 + j2 + j) / 2, (j2 + m2) / 2 - z);
	    }
	    cleb = factor * sum;
	}
	return cleb;
}

// 3j symbol [j1,m1,j2,m2,j,m]
// written by me
inline Doub threej_int_Doub(Long_I j1, Long_I m1, Long_I j2, Long_I m2, Long_I j3, Long_I m3)
{
	Doub coeff = isodd(j1 -j2 -m3) ? -1 : 1;
	return coeff / sqrt(Doub(2*j3+1)) * cleb_int_Doub(j1, m1, j2, m2, j3, -m3);
}

// 3j symbol [j1/2,m1/2,j2/2,m2/2,j/2,m/2]
// written by me
inline Doub threej_Doub(Long_I two_j1, Long_I two_m1, Long_I two_j2, Long_I two_m2, Long_I two_j3, Long_I two_m3)
{
#ifndef NDEBUG
	if (isodd(two_j1 - two_j2 - two_m3)) SLS_ERR("unknown!");
#endif
	Doub coeff = isodd((two_j1 -two_j2 -two_m3)/2) ? -1 : 1;
	return coeff / sqrt(Doub(two_j3+1)) * cleb_Doub(two_j1, two_m1, two_j2, two_m2, two_j3, -two_m3);
}

inline Doub angdelta_Doub(Long_I two_a, Long_I two_b, Long_I two_c)
{
	Doub angdelta, _scr1;
	_scr1 = factorial((two_a + two_b - two_c) / 2);
	_scr1 = _scr1 / factorial((two_a + two_b + two_c) / 2 + 1);
	_scr1 = _scr1 * factorial((two_a - two_b + two_c) / 2);
	_scr1 = _scr1 * factorial((-two_a + two_b + two_c) / 2);
	angdelta = sqrt(_scr1);
	return angdelta;
}

// 6j symbol [two_a/2,two_b/2,two_c/2; two_d/2,two_e/2,two_f/2]
inline Doub sixj_Doub(Long_I two_a, Long_I two_b, Long_I two_c, Long_I two_d, Long_I two_e, Long_I two_f)
{
	Doub sixj;
	Long  nlo, nhi, n;

	Doub outfactors, sum, sumterm;

	sixj = 0;
	if (mod(two_a + two_b, 2) != mod(two_c, 2)) return sixj;
	if(mod(two_c+two_d,2) != mod(two_e,2)) return sixj;
	if(mod(two_a+two_e,2) != mod(two_f,2)) return sixj;
	if(mod(two_b+two_d,2) != mod(two_f,2)) return sixj;
	if(abs(two_a-two_b)>two_c || two_a+two_b<two_c) return sixj;
	if(abs(two_c-two_d)>two_e || two_c+two_d<two_e) return sixj;
	if(abs(two_a-two_e)>two_f || two_a+two_e<two_f) return sixj;
	if(abs(two_b-two_d)>two_f || two_b+two_d<two_f) return sixj;

	outfactors = angdelta_Doub(two_a, two_e, two_f) / angdelta_Doub(two_a, two_b, two_c);
	outfactors = outfactors * angdelta_Doub(two_b, two_d, two_f) * angdelta_Doub(two_c, two_d, two_e);

	nlo = max( (two_a+two_b+two_c)/2, max((two_c+two_d+two_e)/2, max((two_b+two_d+two_f)/2, (two_a+two_e+two_f)/2 )));
	nhi = min( (two_a+two_b+two_d+two_e)/2, min((two_b+two_c+two_e+two_f)/2, (two_a+two_c+two_d+two_f)/2));

	sum = 0;
	for (n = nlo; n <= nhi; ++n) {
	    sumterm = pow(-1,n);
	   sumterm = sumterm * binom_Doub(n+1,n-(two_a+two_b+two_c)/2);
	   sumterm = sumterm * binom_Doub((two_a+two_b-two_c)/2,n-(two_c+two_d+two_e)/2);
	   sumterm = sumterm * binom_Doub((two_a-two_b+two_c)/2,n-(two_b+two_d+two_f)/2);
	   sumterm = sumterm * binom_Doub((two_b-two_a+two_c)/2,n-(two_a+two_e+two_f)/2);
	   sum = sum + sumterm;
	}

	sixj = sum * outfactors;
	return sixj;
}

// 9j symbol [two_a/2,two_b/2,two_c/2; two_d/2,two_e/2,two_f/2; two_g/2,two_h/2,two_i/2]
inline Doub ninej_Doub(Long_I two_a, Long_I two_b, Long_I two_c, Long_I two_d, Long_I two_e, Long_I two_f, Long_I two_g, Long_I two_h, Long_I two_i) {
	Doub ninej, sum;
	Long xlo, xhi, x;

	if(abs(two_a-two_b)>two_c || two_a+two_b<two_c) return 0;
	if(abs(two_d-two_e)>two_f || two_d+two_e<two_f) return 0;
	if(abs(two_g-two_h)>two_i || two_g+two_h<two_i) return 0;
	if(abs(two_a-two_d)>two_g || two_a+two_d<two_g) return 0;
	if(abs(two_b-two_e)>two_h || two_b+two_e<two_h) return 0;
	if(abs(two_c-two_f)>two_i || two_c+two_f<two_i) return 0;
	
	xlo = max(abs(two_b-two_f),max(abs(two_a-two_i),abs(two_h-two_d)));
	xhi = min(two_b + two_f, min(two_a + two_i, two_h + two_d));
	
	sum = 0;
	for (x = xlo; x <= xhi; x += 2) {
	    sum = sum + pow(-1,x)*(x + 1)*sixj_Doub(two_a, two_b, two_c, two_f, two_i, x)*sixj_Doub(two_d, two_e, two_f, two_b, x, two_h)*
	        sixj_Doub(two_g, two_h, two_i, x, two_a, two_d);
	}
	ninej = sum;
	return ninej;
}

// calculate <y_{l1,l2}^{L,M}|y_{l,l}^{0,0}|y_{l1_,l2_}^{L_,M_}>
// implementation using 9j symbol
inline Doub yyy_Doub(Long_I l1, Long_I l2, Long_I L, Long_I M, Long_I l,
	Long_I l1_, Long_I l2_, Long_I L_, Long_I M_)
{
	Doub out = (2 * l + 1) / (4 * PI)*sqrt((2 * l1_ + 1)*(2 * l2_ + 1)*(2 * L_ + 1))*
	    cleb_Doub(l * 2, 0, l1_ * 2, 0, l1 * 2, 0) *
	    cleb_Doub(l * 2, 0, l2_ * 2, 0, l2 * 2, 0) *
	    ninej_Doub(l * 2, l1_ * 2, l1 * 2, l * 2, l2_ * 2, l2 * 2, 0, L_ * 2, L * 2);
	return out;
}

inline Qdoub binom_Qdoub(Long_I n, Long_I r) {
	if (n == r || r == 0)
	    return 1;
	else if (r == 1)
	    return (Qdoub)n;
	else
	    return (Qdoub)n / Qdoub(n - r)*binom_Qdoub(n - 1, r);
}

// clebsch gordan coefficient [j1,m1,j2,m2,j,m] for integer numbers
inline Qdoub cleb_int_Qdoub(Long_I j1, Long_I m1, Long_I j2, Long_I m2, Long_I j, Long_I m)
{
	Qdoub cleb, factor, sum;
	Long par, z, zmin, zmax;

	if (j1 < 0 || j2 < 0 || j < 0 ||
	    abs(m1)>j1 || abs(m2)>j2 || abs(m)>j ||
	    j>j1+j2 || j<abs(j1-j2) || m1+m2!=m) {
	    cleb = 0;
	}
	else if (isodd(j1+j2+j) && ((m1==0 && m2==0 && m==0) || (j1==j2 && m1==m2) || (j1==j && m1==m) || (j2==j && m2==m))) {
	    cleb = 0;
	}
	else {
	    factor = binom_Qdoub(2*j1, j1 + j2 - j) / binom_Qdoub(j1 + j2 + j + 1, j1 + j2 - j);
	    factor *= binom_Qdoub(2*j2, j1 + j2 - j) / binom_Qdoub(2*j1, j1 - m1);
	    factor /= binom_Qdoub(2*j2, j2 - m2) * binom_Qdoub(2*j, j - m);
	    factor = sqrt(factor);

	    zmin = max(Long(0), max(2*j2 + j1 - m1 - (j1 + j2 + j), 2*j1 + j2 + m2 - (j1 + j2 + j)));
	    zmax = min(j1 + j2 - j, min(j1 - m1, j2 + m2));

	    sum = 0;
	    for (z = zmin; z <= zmax; ++z) {
	        par = isodd(z)? -1: 1;
	        sum += par * binom_Qdoub(j1 + j2 - j, z)*binom_Qdoub(j1 - j2 + j, j1 - m1 - z)
	            * binom_Qdoub(-j1 + j2 + j, j2 + m2 - z);
	    }
	    cleb = factor * sum;
	}
	return cleb;
}

// clebsch gordan coefficient [two_j1/2,two_m1/2,two_j2/2,two_m2/2,two_j/2,two_m/2]
inline Qdoub cleb_Qdoub(Long_I two_j1, Long_I two_m1, Long_I two_j2, Long_I two_m2, Long_I two_j, Long_I two_m)
{
	Long_I j1 = two_j1, m1 = two_m1, j2 = two_j2, m2 = two_m2, j = two_j, m = two_m;
	Qdoub cleb, factor, sum;
	Long par, z, zmin, zmax;

	if (2 * (j1 / 2) - j1 != 2 * (abs(m1) / 2) - abs(m1) ||
	    2 * (j2 / 2) - j2 != 2 * (abs(m2) / 2) - abs(m2) ||
	    2 * (j / 2) - j != 2 * (abs(m) / 2) - abs(m) ||
	    j1<0 || j2<0  || j<0 || abs(m1)>j1 || abs(m2)>j2 ||
	    abs(m)>j || j1 + j2<j || abs(j1 - j2)>j || m1 + m2 != m) {
	    cleb = 0;
	}
	else if (!isodd(j1) && !isodd(j2) && !isodd(j) && isodd((j1+j2+j)/2) && ((m1==0 && m2==0 && m==0) ||
		(j1==j2 && m1==m2) || (j1==j && m1==m) || (j2==j && m2==m))) {
	    cleb = 0;
	}
	else {
	    factor = binom_Qdoub(j1, (j1 + j2 - j) / 2) / binom_Qdoub((j1 + j2 + j + 2) / 2, (j1 + j2 - j) / 2);
	    factor = factor * binom_Qdoub(j2, (j1 + j2 - j) / 2) / binom_Qdoub(j1, (j1 - m1) / 2);
	    factor = factor / binom_Qdoub(j2, (j2 - m2) / 2) / binom_Qdoub(j, (j - m) / 2);
	    factor = sqrt(factor);

	    zmin = max(Long(0), max(j2 + (j1 - m1) / 2 - (j1 + j2 + j) / 2, j1 + (j2 + m2) / 2 - (j1 + j2 + j) / 2));
	    zmax = min((j1 + j2 - j) / 2, min((j1 - m1) / 2, (j2 + m2) / 2));

	    sum = 0;
	    for (z = zmin; z <= zmax; ++z) {
	        par = 1;
	            if (2 * (z / 2) - z != 0)
	                par = -1;
	        sum = sum + par * binom_Qdoub((j1 + j2 - j) / 2, z)*binom_Qdoub((j1 - j2 + j) / 2, (j1 - m1) / 2 - z)
	            * binom_Qdoub((-j1 + j2 + j) / 2, (j2 + m2) / 2 - z);
	    }
	    cleb = factor * sum;
	}
	return cleb;
}

// 3j symbol [j1,m1,j2,m2,j,m]
// written by me
inline Qdoub threej_int_Qdoub(Long_I j1, Long_I m1, Long_I j2, Long_I m2, Long_I j3, Long_I m3)
{
	Qdoub coeff = isodd(j1 -j2 -m3) ? -1 : 1;
	return coeff / sqrt(Qdoub(2*j3+1)) * cleb_int_Qdoub(j1, m1, j2, m2, j3, -m3);
}

// 3j symbol [j1/2,m1/2,j2/2,m2/2,j/2,m/2]
// written by me
inline Qdoub threej_Qdoub(Long_I two_j1, Long_I two_m1, Long_I two_j2, Long_I two_m2, Long_I two_j3, Long_I two_m3)
{
#ifndef NDEBUG
	if (isodd(two_j1 - two_j2 - two_m3)) SLS_ERR("unknown!");
#endif
	Qdoub coeff = isodd((two_j1 -two_j2 -two_m3)/2) ? -1 : 1;
	return coeff / sqrt(Qdoub(two_j3+1)) * cleb_Qdoub(two_j1, two_m1, two_j2, two_m2, two_j3, -two_m3);
}

inline Qdoub angdelta_Qdoub(Long_I two_a, Long_I two_b, Long_I two_c)
{
	Qdoub angdelta, _scr1;
	_scr1 = factorial((two_a + two_b - two_c) / 2);
	_scr1 = _scr1 / factorial((two_a + two_b + two_c) / 2 + 1);
	_scr1 = _scr1 * factorial((two_a - two_b + two_c) / 2);
	_scr1 = _scr1 * factorial((-two_a + two_b + two_c) / 2);
	angdelta = sqrt(_scr1);
	return angdelta;
}

// 6j symbol [two_a/2,two_b/2,two_c/2; two_d/2,two_e/2,two_f/2]
inline Qdoub sixj_Qdoub(Long_I two_a, Long_I two_b, Long_I two_c, Long_I two_d, Long_I two_e, Long_I two_f)
{
	Qdoub sixj;
	Long  nlo, nhi, n;

	Qdoub outfactors, sum, sumterm;

	sixj = 0;
	if (mod(two_a + two_b, 2) != mod(two_c, 2)) return sixj;
	if(mod(two_c+two_d,2) != mod(two_e,2)) return sixj;
	if(mod(two_a+two_e,2) != mod(two_f,2)) return sixj;
	if(mod(two_b+two_d,2) != mod(two_f,2)) return sixj;
	if(abs(two_a-two_b)>two_c || two_a+two_b<two_c) return sixj;
	if(abs(two_c-two_d)>two_e || two_c+two_d<two_e) return sixj;
	if(abs(two_a-two_e)>two_f || two_a+two_e<two_f) return sixj;
	if(abs(two_b-two_d)>two_f || two_b+two_d<two_f) return sixj;

	outfactors = angdelta_Qdoub(two_a, two_e, two_f) / angdelta_Qdoub(two_a, two_b, two_c);
	outfactors = outfactors * angdelta_Qdoub(two_b, two_d, two_f) * angdelta_Qdoub(two_c, two_d, two_e);

	nlo = max( (two_a+two_b+two_c)/2, max((two_c+two_d+two_e)/2, max((two_b+two_d+two_f)/2, (two_a+two_e+two_f)/2 )));
	nhi = min( (two_a+two_b+two_d+two_e)/2, min((two_b+two_c+two_e+two_f)/2, (two_a+two_c+two_d+two_f)/2));

	sum = 0;
	for (n = nlo; n <= nhi; ++n) {
	    sumterm = pow(-1,n);
	   sumterm = sumterm * binom_Qdoub(n+1,n-(two_a+two_b+two_c)/2);
	   sumterm = sumterm * binom_Qdoub((two_a+two_b-two_c)/2,n-(two_c+two_d+two_e)/2);
	   sumterm = sumterm * binom_Qdoub((two_a-two_b+two_c)/2,n-(two_b+two_d+two_f)/2);
	   sumterm = sumterm * binom_Qdoub((two_b-two_a+two_c)/2,n-(two_a+two_e+two_f)/2);
	   sum = sum + sumterm;
	}

	sixj = sum * outfactors;
	return sixj;
}

// 9j symbol [two_a/2,two_b/2,two_c/2; two_d/2,two_e/2,two_f/2; two_g/2,two_h/2,two_i/2]
inline Qdoub ninej_Qdoub(Long_I two_a, Long_I two_b, Long_I two_c, Long_I two_d, Long_I two_e, Long_I two_f, Long_I two_g, Long_I two_h, Long_I two_i) {
	Qdoub ninej, sum;
	Long xlo, xhi, x;

	if(abs(two_a-two_b)>two_c || two_a+two_b<two_c) return 0;
	if(abs(two_d-two_e)>two_f || two_d+two_e<two_f) return 0;
	if(abs(two_g-two_h)>two_i || two_g+two_h<two_i) return 0;
	if(abs(two_a-two_d)>two_g || two_a+two_d<two_g) return 0;
	if(abs(two_b-two_e)>two_h || two_b+two_e<two_h) return 0;
	if(abs(two_c-two_f)>two_i || two_c+two_f<two_i) return 0;
	
	xlo = max(abs(two_b-two_f),max(abs(two_a-two_i),abs(two_h-two_d)));
	xhi = min(two_b + two_f, min(two_a + two_i, two_h + two_d));
	
	sum = 0;
	for (x = xlo; x <= xhi; x += 2) {
	    sum = sum + pow(-1,x)*(x + 1)*sixj_Qdoub(two_a, two_b, two_c, two_f, two_i, x)*sixj_Qdoub(two_d, two_e, two_f, two_b, x, two_h)*
	        sixj_Qdoub(two_g, two_h, two_i, x, two_a, two_d);
	}
	ninej = sum;
	return ninej;
}

// calculate <y_{l1,l2}^{L,M}|y_{l,l}^{0,0}|y_{l1_,l2_}^{L_,M_}>
// implementation using 9j symbol
inline Qdoub yyy_Qdoub(Long_I l1, Long_I l2, Long_I L, Long_I M, Long_I l,
	Long_I l1_, Long_I l2_, Long_I L_, Long_I M_)
{
	Qdoub out = (2 * l + 1) / (4 * PI)*sqrt((2 * l1_ + 1)*(2 * l2_ + 1)*(2 * L_ + 1))*
	    cleb_Qdoub(l * 2, 0, l1_ * 2, 0, l1 * 2, 0) *
	    cleb_Qdoub(l * 2, 0, l2_ * 2, 0, l2 * 2, 0) *
	    ninej_Qdoub(l * 2, l1_ * 2, l1 * 2, l * 2, l2_ * 2, l2 * 2, 0, L_ * 2, L * 2);
	return out;
}


// alias
inline Doub cleb_int(Long_I j1, Long_I m1, Long_I j2, Long_I m2, Long_I j, Long_I m)
{ return cleb_int_Doub(j1, m1, j2, m2, j, m); }

inline Doub cleb(Long_I two_j1, Long_I two_m1, Long_I two_j2, Long_I two_m2, Long_I two_j, Long_I two_m)
{ return cleb_Doub(two_j1, two_m1, two_j2, two_m2, two_j, two_m); }

inline Doub threej(Long_I two_j1, Long_I two_m1, Long_I two_j2, Long_I two_m2, Long_I two_j3, Long_I two_m3)
{ return threej_Doub(two_j1, two_m1, two_j2, two_m2, two_j3, two_m3); }

inline Doub threej_int(Long_I j1, Long_I m1, Long_I j2, Long_I m2, Long_I j3, Long_I m3)
{ return threej_int_Doub(j1, m1, j2, m2, j3, m3); }

inline Doub binom(Long_I n, Long_I r) { return binom_Doub(n, r); }

inline Doub sixj(Long_I two_a, Long_I two_b, Long_I two_c, Long_I two_d, Long_I two_e, Long_I two_f)
{ return sixj_Doub(two_a, two_b, two_c, two_d, two_e, two_f); }

inline Doub ninej(Long_I two_a, Long_I two_b, Long_I two_c, Long_I two_d, Long_I two_e,
    Long_I two_f, Long_I two_g, Long_I two_h, Long_I two_i)
{ return ninej_Doub(two_a, two_b, two_c, two_d, two_e, two_f, two_g, two_h, two_i); }

inline Doub yyy(Long_I l1, Long_I l2, Long_I L, Long_I M, Long_I l,
	Long_I l1_, Long_I l2_, Long_I L_, Long_I M_)
{ return yyy_Doub(l1, l2, L, M, l, l1_, l2_, L_, M_); }

} // namespace slisc
