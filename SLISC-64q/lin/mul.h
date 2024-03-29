// functions that loop through every element of a container
#pragma once
#include "../arith/scalar_arith.h"
#include "../arith/copy.h"

namespace slisc {

// matrix-vector multiplication, not optimized
inline void mul(SvecInt_O y, ScmatInt_I a, SvecInt_I x)
{
	Long Nr = a.n0(), Nc = a.n1();
#ifdef SLS_CHECK_SHAPES
	if (Nc != x.size() || y.size() != Nr)
		SLS_ERR("illegal shape!");
#endif
	for (Long i = 0; i < Nr; ++i)
		y[i] = a(i, 0) * x[0];
	for (Long j = 1; j < Nc; ++j) {
		for (Long i = 0; i < Nr; ++i)
			y[i] += a(i, j) * x[j];
	}
}

// y = alpha*A*x + beta*y
// algorithm: y = alpha*(A*x + beta/alpha *y)
inline void mul(SvecInt_IO y, ScmatInt_I a, SvecInt_I x, Int_I alpha, Int_I beta)
{
	Long Nr = a.n0(), Nc = a.n1();
#ifdef SLS_CHECK_SHAPES
	if (Nc != x.size() || y.size() != Nr)
		SLS_ERR("illegal shape!");
#endif
	// y = beta/alpha *y
	if (beta == 0) {
		for (Long i = 0; i < Nr; ++i)
			y[i] = 0;
	}
	else {
		Int b_a = beta/alpha;
		if (b_a != 1) {
			for (Long i = 0; i < Nr; ++i)
				y[i] *= b_a;
		}
	}
	// y += A*x
	for (Long j = 0; j < Nc; ++j) {
		for (Long i = 0; i < Nr; ++i)
			y[i] += a(i, j) * x[j];
	}
	// y *= alpha
	if (alpha != 1) {
		for (Long i = 0; i < Nr; ++i)
			y[i] *= alpha;
	}
}

inline void mul(SvecDoub_O y, ScmatDoub_I a, SvecDoub_I x)
{
	Long Nr = a.n0(), Nc = a.n1();
#ifdef SLS_CHECK_SHAPES
	if (Nc != x.size() || y.size() != Nr)
		SLS_ERR("illegal shape!");
#endif
	for (Long i = 0; i < Nr; ++i)
		y[i] = a(i, 0) * x[0];
	for (Long j = 1; j < Nc; ++j) {
		for (Long i = 0; i < Nr; ++i)
			y[i] += a(i, j) * x[j];
	}
}

// y = alpha*A*x + beta*y
// algorithm: y = alpha*(A*x + beta/alpha *y)
inline void mul(SvecDoub_IO y, ScmatDoub_I a, SvecDoub_I x, Doub_I alpha, Doub_I beta)
{
	Long Nr = a.n0(), Nc = a.n1();
#ifdef SLS_CHECK_SHAPES
	if (Nc != x.size() || y.size() != Nr)
		SLS_ERR("illegal shape!");
#endif
	// y = beta/alpha *y
	if (beta == 0) {
		for (Long i = 0; i < Nr; ++i)
			y[i] = 0;
	}
	else {
		Doub b_a = beta/alpha;
		if (b_a != 1) {
			for (Long i = 0; i < Nr; ++i)
				y[i] *= b_a;
		}
	}
	// y += A*x
	for (Long j = 0; j < Nc; ++j) {
		for (Long i = 0; i < Nr; ++i)
			y[i] += a(i, j) * x[j];
	}
	// y *= alpha
	if (alpha != 1) {
		for (Long i = 0; i < Nr; ++i)
			y[i] *= alpha;
	}
}

inline void mul(SvecComp_O y, ScmatComp_I a, SvecComp_I x)
{
	Long Nr = a.n0(), Nc = a.n1();
#ifdef SLS_CHECK_SHAPES
	if (Nc != x.size() || y.size() != Nr)
		SLS_ERR("illegal shape!");
#endif
	for (Long i = 0; i < Nr; ++i)
		y[i] = a(i, 0) * x[0];
	for (Long j = 1; j < Nc; ++j) {
		for (Long i = 0; i < Nr; ++i)
			y[i] += a(i, j) * x[j];
	}
}

// y = alpha*A*x + beta*y
// algorithm: y = alpha*(A*x + beta/alpha *y)
inline void mul(SvecComp_IO y, ScmatComp_I a, SvecComp_I x, Comp_I alpha, Comp_I beta)
{
	Long Nr = a.n0(), Nc = a.n1();
#ifdef SLS_CHECK_SHAPES
	if (Nc != x.size() || y.size() != Nr)
		SLS_ERR("illegal shape!");
#endif
	// y = beta/alpha *y
	if (beta == 0) {
		for (Long i = 0; i < Nr; ++i)
			y[i] = 0;
	}
	else {
		Comp b_a = beta/alpha;
		if (b_a != 1) {
			for (Long i = 0; i < Nr; ++i)
				y[i] *= b_a;
		}
	}
	// y += A*x
	for (Long j = 0; j < Nc; ++j) {
		for (Long i = 0; i < Nr; ++i)
			y[i] += a(i, j) * x[j];
	}
	// y *= alpha
	if (alpha != 1) {
		for (Long i = 0; i < Nr; ++i)
			y[i] *= alpha;
	}
}

inline void mul(SvecComp_O y, ScmatComp_I a, SvecDoub_I x)
{
	Long Nr = a.n0(), Nc = a.n1();
#ifdef SLS_CHECK_SHAPES
	if (Nc != x.size() || y.size() != Nr)
		SLS_ERR("illegal shape!");
#endif
	for (Long i = 0; i < Nr; ++i)
		y[i] = a(i, 0) * x[0];
	for (Long j = 1; j < Nc; ++j) {
		for (Long i = 0; i < Nr; ++i)
			y[i] += a(i, j) * x[j];
	}
}

// y = alpha*A*x + beta*y
// algorithm: y = alpha*(A*x + beta/alpha *y)
inline void mul(SvecComp_IO y, ScmatComp_I a, SvecDoub_I x, Comp_I alpha, Comp_I beta)
{
	Long Nr = a.n0(), Nc = a.n1();
#ifdef SLS_CHECK_SHAPES
	if (Nc != x.size() || y.size() != Nr)
		SLS_ERR("illegal shape!");
#endif
	// y = beta/alpha *y
	if (beta == 0) {
		for (Long i = 0; i < Nr; ++i)
			y[i] = 0;
	}
	else {
		Comp b_a = beta/alpha;
		if (b_a != 1) {
			for (Long i = 0; i < Nr; ++i)
				y[i] *= b_a;
		}
	}
	// y += A*x
	for (Long j = 0; j < Nc; ++j) {
		for (Long i = 0; i < Nr; ++i)
			y[i] += a(i, j) * x[j];
	}
	// y *= alpha
	if (alpha != 1) {
		for (Long i = 0; i < Nr; ++i)
			y[i] *= alpha;
	}
}

inline void mul(SvecComp_O y, ScmatDoub_I a, SvecComp_I x)
{
	Long Nr = a.n0(), Nc = a.n1();
#ifdef SLS_CHECK_SHAPES
	if (Nc != x.size() || y.size() != Nr)
		SLS_ERR("illegal shape!");
#endif
	for (Long i = 0; i < Nr; ++i)
		y[i] = a(i, 0) * x[0];
	for (Long j = 1; j < Nc; ++j) {
		for (Long i = 0; i < Nr; ++i)
			y[i] += a(i, j) * x[j];
	}
}

// y = alpha*A*x + beta*y
// algorithm: y = alpha*(A*x + beta/alpha *y)
inline void mul(SvecComp_IO y, ScmatDoub_I a, SvecComp_I x, Doub_I alpha, Comp_I beta)
{
	Long Nr = a.n0(), Nc = a.n1();
#ifdef SLS_CHECK_SHAPES
	if (Nc != x.size() || y.size() != Nr)
		SLS_ERR("illegal shape!");
#endif
	// y = beta/alpha *y
	if (beta == 0) {
		for (Long i = 0; i < Nr; ++i)
			y[i] = 0;
	}
	else {
		Comp b_a = beta/alpha;
		if (b_a != 1) {
			for (Long i = 0; i < Nr; ++i)
				y[i] *= b_a;
		}
	}
	// y += A*x
	for (Long j = 0; j < Nc; ++j) {
		for (Long i = 0; i < Nr; ++i)
			y[i] += a(i, j) * x[j];
	}
	// y *= alpha
	if (alpha != 1) {
		for (Long i = 0; i < Nr; ++i)
			y[i] *= alpha;
	}
}

inline void mul(DvecComp_O y, ScmatDoub_I a, DvecComp_I x)
{
	Long Nr = a.n0(), Nc = a.n1();
#ifdef SLS_CHECK_SHAPES
	if (Nc != x.size() || y.size() != Nr)
		SLS_ERR("illegal shape!");
#endif
	for (Long i = 0; i < Nr; ++i)
		y[i] = a(i, 0) * x[0];
	for (Long j = 1; j < Nc; ++j) {
		for (Long i = 0; i < Nr; ++i)
			y[i] += a(i, j) * x[j];
	}
}

// y = alpha*A*x + beta*y
// algorithm: y = alpha*(A*x + beta/alpha *y)
inline void mul(DvecComp_IO y, ScmatDoub_I a, DvecComp_I x, Doub_I alpha, Comp_I beta)
{
	Long Nr = a.n0(), Nc = a.n1();
#ifdef SLS_CHECK_SHAPES
	if (Nc != x.size() || y.size() != Nr)
		SLS_ERR("illegal shape!");
#endif
	// y = beta/alpha *y
	if (beta == 0) {
		for (Long i = 0; i < Nr; ++i)
			y[i] = 0;
	}
	else {
		Comp b_a = beta/alpha;
		if (b_a != 1) {
			for (Long i = 0; i < Nr; ++i)
				y[i] *= b_a;
		}
	}
	// y += A*x
	for (Long j = 0; j < Nc; ++j) {
		for (Long i = 0; i < Nr; ++i)
			y[i] += a(i, j) * x[j];
	}
	// y *= alpha
	if (alpha != 1) {
		for (Long i = 0; i < Nr; ++i)
			y[i] *= alpha;
	}
}

inline void mul(SvecComp_O y, MatComp_I a, SvecDoub_I x)
{
	Long Nr = a.n0(), Nc = a.n1();
#ifdef SLS_CHECK_SHAPES
	if (Nc != x.size() || y.size() != Nr)
		SLS_ERR("illegal shape!");
#endif
	for (Long i = 0; i < Nr; ++i) {
		y[i] = a(i, 0) * x[0];
		for (Long j = 1; j < Nc; ++j)
			y[i] += a(i, j) * x[j];
	}
}

// y = alpha*A*x + beta*y
// algorithm: y = alpha*(A*x + beta/alpha *y)
inline void mul(SvecComp_IO y, MatComp_I a, SvecDoub_I x, Comp_I alpha, Comp_I beta)
{
	Long Nr = a.n0(), Nc = a.n1();
#ifdef SLS_CHECK_SHAPES
	if (Nc != x.size() || y.size() != Nr)
		SLS_ERR("illegal shape!");
#endif
	// y = beta/alpha *y
	if (beta == 0) {
		for (Long i = 0; i < Nr; ++i)
			y[i] = 0;
	}
	else {
		Comp b_a = beta/alpha;
		if (b_a != 1) {
			for (Long i = 0; i < Nr; ++i)
				y[i] *= b_a;
		}
	}
	// y += A*x
	for (Long i = 0; i < Nr; ++i) {
		for (Long j = 0; j < Nc; ++j)
			y[i] += a(i, j) * x[j];
	}
	// y *= alpha
	if (alpha != 1) {
		for (Long i = 0; i < Nr; ++i)
			y[i] *= alpha;
	}
}

inline void mul(SvecQdoub_O y, ScmatQdoub_I a, SvecQdoub_I x)
{
	Long Nr = a.n0(), Nc = a.n1();
#ifdef SLS_CHECK_SHAPES
	if (Nc != x.size() || y.size() != Nr)
		SLS_ERR("illegal shape!");
#endif
	for (Long i = 0; i < Nr; ++i)
		y[i] = a(i, 0) * x[0];
	for (Long j = 1; j < Nc; ++j) {
		for (Long i = 0; i < Nr; ++i)
			y[i] += a(i, j) * x[j];
	}
}

// y = alpha*A*x + beta*y
// algorithm: y = alpha*(A*x + beta/alpha *y)
inline void mul(SvecQdoub_IO y, ScmatQdoub_I a, SvecQdoub_I x, Qdoub_I alpha, Qdoub_I beta)
{
	Long Nr = a.n0(), Nc = a.n1();
#ifdef SLS_CHECK_SHAPES
	if (Nc != x.size() || y.size() != Nr)
		SLS_ERR("illegal shape!");
#endif
	// y = beta/alpha *y
	if (beta == 0) {
		for (Long i = 0; i < Nr; ++i)
			y[i] = 0;
	}
	else {
		Qdoub b_a = beta/alpha;
		if (b_a != 1) {
			for (Long i = 0; i < Nr; ++i)
				y[i] *= b_a;
		}
	}
	// y += A*x
	for (Long j = 0; j < Nc; ++j) {
		for (Long i = 0; i < Nr; ++i)
			y[i] += a(i, j) * x[j];
	}
	// y *= alpha
	if (alpha != 1) {
		for (Long i = 0; i < Nr; ++i)
			y[i] *= alpha;
	}
}

inline void mul(SvecComp_O y, ScmatDoub_I a, DvecComp_I x)
{
	Long Nr = a.n0(), Nc = a.n1();
#ifdef SLS_CHECK_SHAPES
	if (Nc != x.size() || y.size() != Nr)
		SLS_ERR("illegal shape!");
#endif
	for (Long i = 0; i < Nr; ++i)
		y[i] = a(i, 0) * x[0];
	for (Long j = 1; j < Nc; ++j) {
		for (Long i = 0; i < Nr; ++i)
			y[i] += a(i, j) * x[j];
	}
}

// y = alpha*A*x + beta*y
// algorithm: y = alpha*(A*x + beta/alpha *y)
inline void mul(SvecComp_IO y, ScmatDoub_I a, DvecComp_I x, Doub_I alpha, Comp_I beta)
{
	Long Nr = a.n0(), Nc = a.n1();
#ifdef SLS_CHECK_SHAPES
	if (Nc != x.size() || y.size() != Nr)
		SLS_ERR("illegal shape!");
#endif
	// y = beta/alpha *y
	if (beta == 0) {
		for (Long i = 0; i < Nr; ++i)
			y[i] = 0;
	}
	else {
		Comp b_a = beta/alpha;
		if (b_a != 1) {
			for (Long i = 0; i < Nr; ++i)
				y[i] *= b_a;
		}
	}
	// y += A*x
	for (Long j = 0; j < Nc; ++j) {
		for (Long i = 0; i < Nr; ++i)
			y[i] += a(i, j) * x[j];
	}
	// y *= alpha
	if (alpha != 1) {
		for (Long i = 0; i < Nr; ++i)
			y[i] *= alpha;
	}
}

inline void mul(SvecComp_O y, ScmatComp_I a, DvecComp_I x)
{
	Long Nr = a.n0(), Nc = a.n1();
#ifdef SLS_CHECK_SHAPES
	if (Nc != x.size() || y.size() != Nr)
		SLS_ERR("illegal shape!");
#endif
	for (Long i = 0; i < Nr; ++i)
		y[i] = a(i, 0) * x[0];
	for (Long j = 1; j < Nc; ++j) {
		for (Long i = 0; i < Nr; ++i)
			y[i] += a(i, j) * x[j];
	}
}

// y = alpha*A*x + beta*y
// algorithm: y = alpha*(A*x + beta/alpha *y)
inline void mul(SvecComp_IO y, ScmatComp_I a, DvecComp_I x, Comp_I alpha, Comp_I beta)
{
	Long Nr = a.n0(), Nc = a.n1();
#ifdef SLS_CHECK_SHAPES
	if (Nc != x.size() || y.size() != Nr)
		SLS_ERR("illegal shape!");
#endif
	// y = beta/alpha *y
	if (beta == 0) {
		for (Long i = 0; i < Nr; ++i)
			y[i] = 0;
	}
	else {
		Comp b_a = beta/alpha;
		if (b_a != 1) {
			for (Long i = 0; i < Nr; ++i)
				y[i] *= b_a;
		}
	}
	// y += A*x
	for (Long j = 0; j < Nc; ++j) {
		for (Long i = 0; i < Nr; ++i)
			y[i] += a(i, j) * x[j];
	}
	// y *= alpha
	if (alpha != 1) {
		for (Long i = 0; i < Nr; ++i)
			y[i] *= alpha;
	}
}

inline void mul(SvecComp_O y, DcmatDoub_I a, SvecComp_I x)
{
	Long Nr = a.n0(), Nc = a.n1();
#ifdef SLS_CHECK_SHAPES
	if (Nc != x.size() || y.size() != Nr)
		SLS_ERR("illegal shape!");
#endif
	for (Long i = 0; i < Nr; ++i)
		y[i] = a(i, 0) * x[0];
	for (Long j = 1; j < Nc; ++j) {
		for (Long i = 0; i < Nr; ++i)
			y[i] += a(i, j) * x[j];
	}
}

// y = alpha*A*x + beta*y
// algorithm: y = alpha*(A*x + beta/alpha *y)
inline void mul(SvecComp_IO y, DcmatDoub_I a, SvecComp_I x, Doub_I alpha, Comp_I beta)
{
	Long Nr = a.n0(), Nc = a.n1();
#ifdef SLS_CHECK_SHAPES
	if (Nc != x.size() || y.size() != Nr)
		SLS_ERR("illegal shape!");
#endif
	// y = beta/alpha *y
	if (beta == 0) {
		for (Long i = 0; i < Nr; ++i)
			y[i] = 0;
	}
	else {
		Comp b_a = beta/alpha;
		if (b_a != 1) {
			for (Long i = 0; i < Nr; ++i)
				y[i] *= b_a;
		}
	}
	// y += A*x
	for (Long j = 0; j < Nc; ++j) {
		for (Long i = 0; i < Nr; ++i)
			y[i] += a(i, j) * x[j];
	}
	// y *= alpha
	if (alpha != 1) {
		for (Long i = 0; i < Nr; ++i)
			y[i] *= alpha;
	}
}

inline void mul(SvecQcomp_O y, ScmatQdoub_I a, SvecQcomp_I x)
{
	Long Nr = a.n0(), Nc = a.n1();
#ifdef SLS_CHECK_SHAPES
	if (Nc != x.size() || y.size() != Nr)
		SLS_ERR("illegal shape!");
#endif
	for (Long i = 0; i < Nr; ++i)
		y[i] = a(i, 0) * x[0];
	for (Long j = 1; j < Nc; ++j) {
		for (Long i = 0; i < Nr; ++i)
			y[i] += a(i, j) * x[j];
	}
}

// y = alpha*A*x + beta*y
// algorithm: y = alpha*(A*x + beta/alpha *y)
inline void mul(SvecQcomp_IO y, ScmatQdoub_I a, SvecQcomp_I x, Qdoub_I alpha, Qcomp_I beta)
{
	Long Nr = a.n0(), Nc = a.n1();
#ifdef SLS_CHECK_SHAPES
	if (Nc != x.size() || y.size() != Nr)
		SLS_ERR("illegal shape!");
#endif
	// y = beta/alpha *y
	if (beta == 0) {
		for (Long i = 0; i < Nr; ++i)
			y[i] = 0;
	}
	else {
		Qcomp b_a = beta/alpha;
		if (b_a != 1) {
			for (Long i = 0; i < Nr; ++i)
				y[i] *= b_a;
		}
	}
	// y += A*x
	for (Long j = 0; j < Nc; ++j) {
		for (Long i = 0; i < Nr; ++i)
			y[i] += a(i, j) * x[j];
	}
	// y *= alpha
	if (alpha != 1) {
		for (Long i = 0; i < Nr; ++i)
			y[i] *= alpha;
	}
}

inline void mul(SvecQcomp_O y, ScmatQdoub_I a, DvecQcomp_I x)
{
	Long Nr = a.n0(), Nc = a.n1();
#ifdef SLS_CHECK_SHAPES
	if (Nc != x.size() || y.size() != Nr)
		SLS_ERR("illegal shape!");
#endif
	for (Long i = 0; i < Nr; ++i)
		y[i] = a(i, 0) * x[0];
	for (Long j = 1; j < Nc; ++j) {
		for (Long i = 0; i < Nr; ++i)
			y[i] += a(i, j) * x[j];
	}
}

// y = alpha*A*x + beta*y
// algorithm: y = alpha*(A*x + beta/alpha *y)
inline void mul(SvecQcomp_IO y, ScmatQdoub_I a, DvecQcomp_I x, Qdoub_I alpha, Qcomp_I beta)
{
	Long Nr = a.n0(), Nc = a.n1();
#ifdef SLS_CHECK_SHAPES
	if (Nc != x.size() || y.size() != Nr)
		SLS_ERR("illegal shape!");
#endif
	// y = beta/alpha *y
	if (beta == 0) {
		for (Long i = 0; i < Nr; ++i)
			y[i] = 0;
	}
	else {
		Qcomp b_a = beta/alpha;
		if (b_a != 1) {
			for (Long i = 0; i < Nr; ++i)
				y[i] *= b_a;
		}
	}
	// y += A*x
	for (Long j = 0; j < Nc; ++j) {
		for (Long i = 0; i < Nr; ++i)
			y[i] += a(i, j) * x[j];
	}
	// y *= alpha
	if (alpha != 1) {
		for (Long i = 0; i < Nr; ++i)
			y[i] *= alpha;
	}
}

inline void mul(SvecQcomp_O y, ScmatQcomp_I a, SvecQcomp_I x)
{
	Long Nr = a.n0(), Nc = a.n1();
#ifdef SLS_CHECK_SHAPES
	if (Nc != x.size() || y.size() != Nr)
		SLS_ERR("illegal shape!");
#endif
	for (Long i = 0; i < Nr; ++i)
		y[i] = a(i, 0) * x[0];
	for (Long j = 1; j < Nc; ++j) {
		for (Long i = 0; i < Nr; ++i)
			y[i] += a(i, j) * x[j];
	}
}

// y = alpha*A*x + beta*y
// algorithm: y = alpha*(A*x + beta/alpha *y)
inline void mul(SvecQcomp_IO y, ScmatQcomp_I a, SvecQcomp_I x, Qcomp_I alpha, Qcomp_I beta)
{
	Long Nr = a.n0(), Nc = a.n1();
#ifdef SLS_CHECK_SHAPES
	if (Nc != x.size() || y.size() != Nr)
		SLS_ERR("illegal shape!");
#endif
	// y = beta/alpha *y
	if (beta == 0) {
		for (Long i = 0; i < Nr; ++i)
			y[i] = 0;
	}
	else {
		Qcomp b_a = beta/alpha;
		if (b_a != 1) {
			for (Long i = 0; i < Nr; ++i)
				y[i] *= b_a;
		}
	}
	// y += A*x
	for (Long j = 0; j < Nc; ++j) {
		for (Long i = 0; i < Nr; ++i)
			y[i] += a(i, j) * x[j];
	}
	// y *= alpha
	if (alpha != 1) {
		for (Long i = 0; i < Nr; ++i)
			y[i] *= alpha;
	}
}

inline void mul(SvecQcomp_O y, ScmatQcomp_I a, DvecQcomp_I x)
{
	Long Nr = a.n0(), Nc = a.n1();
#ifdef SLS_CHECK_SHAPES
	if (Nc != x.size() || y.size() != Nr)
		SLS_ERR("illegal shape!");
#endif
	for (Long i = 0; i < Nr; ++i)
		y[i] = a(i, 0) * x[0];
	for (Long j = 1; j < Nc; ++j) {
		for (Long i = 0; i < Nr; ++i)
			y[i] += a(i, j) * x[j];
	}
}

// y = alpha*A*x + beta*y
// algorithm: y = alpha*(A*x + beta/alpha *y)
inline void mul(SvecQcomp_IO y, ScmatQcomp_I a, DvecQcomp_I x, Qcomp_I alpha, Qcomp_I beta)
{
	Long Nr = a.n0(), Nc = a.n1();
#ifdef SLS_CHECK_SHAPES
	if (Nc != x.size() || y.size() != Nr)
		SLS_ERR("illegal shape!");
#endif
	// y = beta/alpha *y
	if (beta == 0) {
		for (Long i = 0; i < Nr; ++i)
			y[i] = 0;
	}
	else {
		Qcomp b_a = beta/alpha;
		if (b_a != 1) {
			for (Long i = 0; i < Nr; ++i)
				y[i] *= b_a;
		}
	}
	// y += A*x
	for (Long j = 0; j < Nc; ++j) {
		for (Long i = 0; i < Nr; ++i)
			y[i] += a(i, j) * x[j];
	}
	// y *= alpha
	if (alpha != 1) {
		for (Long i = 0; i < Nr; ++i)
			y[i] *= alpha;
	}
}

inline void mul(SvecQcomp_O y, DcmatQdoub_I a, SvecQcomp_I x)
{
	Long Nr = a.n0(), Nc = a.n1();
#ifdef SLS_CHECK_SHAPES
	if (Nc != x.size() || y.size() != Nr)
		SLS_ERR("illegal shape!");
#endif
	for (Long i = 0; i < Nr; ++i)
		y[i] = a(i, 0) * x[0];
	for (Long j = 1; j < Nc; ++j) {
		for (Long i = 0; i < Nr; ++i)
			y[i] += a(i, j) * x[j];
	}
}

// y = alpha*A*x + beta*y
// algorithm: y = alpha*(A*x + beta/alpha *y)
inline void mul(SvecQcomp_IO y, DcmatQdoub_I a, SvecQcomp_I x, Qdoub_I alpha, Qcomp_I beta)
{
	Long Nr = a.n0(), Nc = a.n1();
#ifdef SLS_CHECK_SHAPES
	if (Nc != x.size() || y.size() != Nr)
		SLS_ERR("illegal shape!");
#endif
	// y = beta/alpha *y
	if (beta == 0) {
		for (Long i = 0; i < Nr; ++i)
			y[i] = 0;
	}
	else {
		Qcomp b_a = beta/alpha;
		if (b_a != 1) {
			for (Long i = 0; i < Nr; ++i)
				y[i] *= b_a;
		}
	}
	// y += A*x
	for (Long j = 0; j < Nc; ++j) {
		for (Long i = 0; i < Nr; ++i)
			y[i] += a(i, j) * x[j];
	}
	// y *= alpha
	if (alpha != 1) {
		for (Long i = 0; i < Nr; ++i)
			y[i] *= alpha;
	}
}

inline void mul(DvecComp_O y, ScmatDoub_I a, SvecComp_I x)
{
	Long Nr = a.n0(), Nc = a.n1();
#ifdef SLS_CHECK_SHAPES
	if (Nc != x.size() || y.size() != Nr)
		SLS_ERR("illegal shape!");
#endif
	for (Long i = 0; i < Nr; ++i)
		y[i] = a(i, 0) * x[0];
	for (Long j = 1; j < Nc; ++j) {
		for (Long i = 0; i < Nr; ++i)
			y[i] += a(i, j) * x[j];
	}
}

// y = alpha*A*x + beta*y
// algorithm: y = alpha*(A*x + beta/alpha *y)
inline void mul(DvecComp_IO y, ScmatDoub_I a, SvecComp_I x, Doub_I alpha, Comp_I beta)
{
	Long Nr = a.n0(), Nc = a.n1();
#ifdef SLS_CHECK_SHAPES
	if (Nc != x.size() || y.size() != Nr)
		SLS_ERR("illegal shape!");
#endif
	// y = beta/alpha *y
	if (beta == 0) {
		for (Long i = 0; i < Nr; ++i)
			y[i] = 0;
	}
	else {
		Comp b_a = beta/alpha;
		if (b_a != 1) {
			for (Long i = 0; i < Nr; ++i)
				y[i] *= b_a;
		}
	}
	// y += A*x
	for (Long j = 0; j < Nc; ++j) {
		for (Long i = 0; i < Nr; ++i)
			y[i] += a(i, j) * x[j];
	}
	// y *= alpha
	if (alpha != 1) {
		for (Long i = 0; i < Nr; ++i)
			y[i] *= alpha;
	}
}

inline void mul(DvecQcomp_O y, ScmatQdoub_I a, SvecQcomp_I x)
{
	Long Nr = a.n0(), Nc = a.n1();
#ifdef SLS_CHECK_SHAPES
	if (Nc != x.size() || y.size() != Nr)
		SLS_ERR("illegal shape!");
#endif
	for (Long i = 0; i < Nr; ++i)
		y[i] = a(i, 0) * x[0];
	for (Long j = 1; j < Nc; ++j) {
		for (Long i = 0; i < Nr; ++i)
			y[i] += a(i, j) * x[j];
	}
}

// y = alpha*A*x + beta*y
// algorithm: y = alpha*(A*x + beta/alpha *y)
inline void mul(DvecQcomp_IO y, ScmatQdoub_I a, SvecQcomp_I x, Qdoub_I alpha, Qcomp_I beta)
{
	Long Nr = a.n0(), Nc = a.n1();
#ifdef SLS_CHECK_SHAPES
	if (Nc != x.size() || y.size() != Nr)
		SLS_ERR("illegal shape!");
#endif
	// y = beta/alpha *y
	if (beta == 0) {
		for (Long i = 0; i < Nr; ++i)
			y[i] = 0;
	}
	else {
		Qcomp b_a = beta/alpha;
		if (b_a != 1) {
			for (Long i = 0; i < Nr; ++i)
				y[i] *= b_a;
		}
	}
	// y += A*x
	for (Long j = 0; j < Nc; ++j) {
		for (Long i = 0; i < Nr; ++i)
			y[i] += a(i, j) * x[j];
	}
	// y *= alpha
	if (alpha != 1) {
		for (Long i = 0; i < Nr; ++i)
			y[i] *= alpha;
	}
}

inline void mul(DvecComp_O y, ScmatComp_I a, SvecComp_I x)
{
	Long Nr = a.n0(), Nc = a.n1();
#ifdef SLS_CHECK_SHAPES
	if (Nc != x.size() || y.size() != Nr)
		SLS_ERR("illegal shape!");
#endif
	for (Long i = 0; i < Nr; ++i)
		y[i] = a(i, 0) * x[0];
	for (Long j = 1; j < Nc; ++j) {
		for (Long i = 0; i < Nr; ++i)
			y[i] += a(i, j) * x[j];
	}
}

// y = alpha*A*x + beta*y
// algorithm: y = alpha*(A*x + beta/alpha *y)
inline void mul(DvecComp_IO y, ScmatComp_I a, SvecComp_I x, Comp_I alpha, Comp_I beta)
{
	Long Nr = a.n0(), Nc = a.n1();
#ifdef SLS_CHECK_SHAPES
	if (Nc != x.size() || y.size() != Nr)
		SLS_ERR("illegal shape!");
#endif
	// y = beta/alpha *y
	if (beta == 0) {
		for (Long i = 0; i < Nr; ++i)
			y[i] = 0;
	}
	else {
		Comp b_a = beta/alpha;
		if (b_a != 1) {
			for (Long i = 0; i < Nr; ++i)
				y[i] *= b_a;
		}
	}
	// y += A*x
	for (Long j = 0; j < Nc; ++j) {
		for (Long i = 0; i < Nr; ++i)
			y[i] += a(i, j) * x[j];
	}
	// y *= alpha
	if (alpha != 1) {
		for (Long i = 0; i < Nr; ++i)
			y[i] *= alpha;
	}
}

inline void mul(DvecQcomp_O y, ScmatQcomp_I a, SvecQcomp_I x)
{
	Long Nr = a.n0(), Nc = a.n1();
#ifdef SLS_CHECK_SHAPES
	if (Nc != x.size() || y.size() != Nr)
		SLS_ERR("illegal shape!");
#endif
	for (Long i = 0; i < Nr; ++i)
		y[i] = a(i, 0) * x[0];
	for (Long j = 1; j < Nc; ++j) {
		for (Long i = 0; i < Nr; ++i)
			y[i] += a(i, j) * x[j];
	}
}

// y = alpha*A*x + beta*y
// algorithm: y = alpha*(A*x + beta/alpha *y)
inline void mul(DvecQcomp_IO y, ScmatQcomp_I a, SvecQcomp_I x, Qcomp_I alpha, Qcomp_I beta)
{
	Long Nr = a.n0(), Nc = a.n1();
#ifdef SLS_CHECK_SHAPES
	if (Nc != x.size() || y.size() != Nr)
		SLS_ERR("illegal shape!");
#endif
	// y = beta/alpha *y
	if (beta == 0) {
		for (Long i = 0; i < Nr; ++i)
			y[i] = 0;
	}
	else {
		Qcomp b_a = beta/alpha;
		if (b_a != 1) {
			for (Long i = 0; i < Nr; ++i)
				y[i] *= b_a;
		}
	}
	// y += A*x
	for (Long j = 0; j < Nc; ++j) {
		for (Long i = 0; i < Nr; ++i)
			y[i] += a(i, j) * x[j];
	}
	// y *= alpha
	if (alpha != 1) {
		for (Long i = 0; i < Nr; ++i)
			y[i] *= alpha;
	}
}

inline void mul(DvecQcomp_O y, ScmatQdoub_I a, DvecQcomp_I x)
{
	Long Nr = a.n0(), Nc = a.n1();
#ifdef SLS_CHECK_SHAPES
	if (Nc != x.size() || y.size() != Nr)
		SLS_ERR("illegal shape!");
#endif
	for (Long i = 0; i < Nr; ++i)
		y[i] = a(i, 0) * x[0];
	for (Long j = 1; j < Nc; ++j) {
		for (Long i = 0; i < Nr; ++i)
			y[i] += a(i, j) * x[j];
	}
}

// y = alpha*A*x + beta*y
// algorithm: y = alpha*(A*x + beta/alpha *y)
inline void mul(DvecQcomp_IO y, ScmatQdoub_I a, DvecQcomp_I x, Qdoub_I alpha, Qcomp_I beta)
{
	Long Nr = a.n0(), Nc = a.n1();
#ifdef SLS_CHECK_SHAPES
	if (Nc != x.size() || y.size() != Nr)
		SLS_ERR("illegal shape!");
#endif
	// y = beta/alpha *y
	if (beta == 0) {
		for (Long i = 0; i < Nr; ++i)
			y[i] = 0;
	}
	else {
		Qcomp b_a = beta/alpha;
		if (b_a != 1) {
			for (Long i = 0; i < Nr; ++i)
				y[i] *= b_a;
		}
	}
	// y += A*x
	for (Long j = 0; j < Nc; ++j) {
		for (Long i = 0; i < Nr; ++i)
			y[i] += a(i, j) * x[j];
	}
	// y *= alpha
	if (alpha != 1) {
		for (Long i = 0; i < Nr; ++i)
			y[i] *= alpha;
	}
}

inline void mul(SvbaseComp_O y, ScmatComp_I a, SvecDoub_I x)
{
	Long Nr = a.n0(), Nc = a.n1();
#ifdef SLS_CHECK_SHAPES
	if (Nc != x.size() || y.size() != Nr)
		SLS_ERR("illegal shape!");
#endif
	for (Long i = 0; i < Nr; ++i)
		y[i] = a(i, 0) * x[0];
	for (Long j = 1; j < Nc; ++j) {
		for (Long i = 0; i < Nr; ++i)
			y[i] += a(i, j) * x[j];
	}
}

// y = alpha*A*x + beta*y
// algorithm: y = alpha*(A*x + beta/alpha *y)
inline void mul(SvbaseComp_IO y, ScmatComp_I a, SvecDoub_I x, Comp_I alpha, Comp_I beta)
{
	Long Nr = a.n0(), Nc = a.n1();
#ifdef SLS_CHECK_SHAPES
	if (Nc != x.size() || y.size() != Nr)
		SLS_ERR("illegal shape!");
#endif
	// y = beta/alpha *y
	if (beta == 0) {
		for (Long i = 0; i < Nr; ++i)
			y[i] = 0;
	}
	else {
		Comp b_a = beta/alpha;
		if (b_a != 1) {
			for (Long i = 0; i < Nr; ++i)
				y[i] *= b_a;
		}
	}
	// y += A*x
	for (Long j = 0; j < Nc; ++j) {
		for (Long i = 0; i < Nr; ++i)
			y[i] += a(i, j) * x[j];
	}
	// y *= alpha
	if (alpha != 1) {
		for (Long i = 0; i < Nr; ++i)
			y[i] *= alpha;
	}
}

inline void mul(SvbaseQcomp_O y, ScmatQcomp_I a, SvecQdoub_I x)
{
	Long Nr = a.n0(), Nc = a.n1();
#ifdef SLS_CHECK_SHAPES
	if (Nc != x.size() || y.size() != Nr)
		SLS_ERR("illegal shape!");
#endif
	for (Long i = 0; i < Nr; ++i)
		y[i] = a(i, 0) * x[0];
	for (Long j = 1; j < Nc; ++j) {
		for (Long i = 0; i < Nr; ++i)
			y[i] += a(i, j) * x[j];
	}
}

// y = alpha*A*x + beta*y
// algorithm: y = alpha*(A*x + beta/alpha *y)
inline void mul(SvbaseQcomp_IO y, ScmatQcomp_I a, SvecQdoub_I x, Qcomp_I alpha, Qcomp_I beta)
{
	Long Nr = a.n0(), Nc = a.n1();
#ifdef SLS_CHECK_SHAPES
	if (Nc != x.size() || y.size() != Nr)
		SLS_ERR("illegal shape!");
#endif
	// y = beta/alpha *y
	if (beta == 0) {
		for (Long i = 0; i < Nr; ++i)
			y[i] = 0;
	}
	else {
		Qcomp b_a = beta/alpha;
		if (b_a != 1) {
			for (Long i = 0; i < Nr; ++i)
				y[i] *= b_a;
		}
	}
	// y += A*x
	for (Long j = 0; j < Nc; ++j) {
		for (Long i = 0; i < Nr; ++i)
			y[i] += a(i, j) * x[j];
	}
	// y *= alpha
	if (alpha != 1) {
		for (Long i = 0; i < Nr; ++i)
			y[i] *= alpha;
	}
}

inline void mul(DvecComp_O y, ScmatComp_I a, SvecDoub_I x)
{
	Long Nr = a.n0(), Nc = a.n1();
#ifdef SLS_CHECK_SHAPES
	if (Nc != x.size() || y.size() != Nr)
		SLS_ERR("illegal shape!");
#endif
	for (Long i = 0; i < Nr; ++i)
		y[i] = a(i, 0) * x[0];
	for (Long j = 1; j < Nc; ++j) {
		for (Long i = 0; i < Nr; ++i)
			y[i] += a(i, j) * x[j];
	}
}

// y = alpha*A*x + beta*y
// algorithm: y = alpha*(A*x + beta/alpha *y)
inline void mul(DvecComp_IO y, ScmatComp_I a, SvecDoub_I x, Comp_I alpha, Comp_I beta)
{
	Long Nr = a.n0(), Nc = a.n1();
#ifdef SLS_CHECK_SHAPES
	if (Nc != x.size() || y.size() != Nr)
		SLS_ERR("illegal shape!");
#endif
	// y = beta/alpha *y
	if (beta == 0) {
		for (Long i = 0; i < Nr; ++i)
			y[i] = 0;
	}
	else {
		Comp b_a = beta/alpha;
		if (b_a != 1) {
			for (Long i = 0; i < Nr; ++i)
				y[i] *= b_a;
		}
	}
	// y += A*x
	for (Long j = 0; j < Nc; ++j) {
		for (Long i = 0; i < Nr; ++i)
			y[i] += a(i, j) * x[j];
	}
	// y *= alpha
	if (alpha != 1) {
		for (Long i = 0; i < Nr; ++i)
			y[i] *= alpha;
	}
}

inline void mul(DvecQcomp_O y, ScmatQcomp_I a, SvecQdoub_I x)
{
	Long Nr = a.n0(), Nc = a.n1();
#ifdef SLS_CHECK_SHAPES
	if (Nc != x.size() || y.size() != Nr)
		SLS_ERR("illegal shape!");
#endif
	for (Long i = 0; i < Nr; ++i)
		y[i] = a(i, 0) * x[0];
	for (Long j = 1; j < Nc; ++j) {
		for (Long i = 0; i < Nr; ++i)
			y[i] += a(i, j) * x[j];
	}
}

// y = alpha*A*x + beta*y
// algorithm: y = alpha*(A*x + beta/alpha *y)
inline void mul(DvecQcomp_IO y, ScmatQcomp_I a, SvecQdoub_I x, Qcomp_I alpha, Qcomp_I beta)
{
	Long Nr = a.n0(), Nc = a.n1();
#ifdef SLS_CHECK_SHAPES
	if (Nc != x.size() || y.size() != Nr)
		SLS_ERR("illegal shape!");
#endif
	// y = beta/alpha *y
	if (beta == 0) {
		for (Long i = 0; i < Nr; ++i)
			y[i] = 0;
	}
	else {
		Qcomp b_a = beta/alpha;
		if (b_a != 1) {
			for (Long i = 0; i < Nr; ++i)
				y[i] *= b_a;
		}
	}
	// y += A*x
	for (Long j = 0; j < Nc; ++j) {
		for (Long i = 0; i < Nr; ++i)
			y[i] += a(i, j) * x[j];
	}
	// y *= alpha
	if (alpha != 1) {
		for (Long i = 0; i < Nr; ++i)
			y[i] *= alpha;
	}
}

inline void mul(SvbaseComp_O y, ScmatComp_I a, SvecComp_I x)
{
	Long Nr = a.n0(), Nc = a.n1();
#ifdef SLS_CHECK_SHAPES
	if (Nc != x.size() || y.size() != Nr)
		SLS_ERR("illegal shape!");
#endif
	for (Long i = 0; i < Nr; ++i)
		y[i] = a(i, 0) * x[0];
	for (Long j = 1; j < Nc; ++j) {
		for (Long i = 0; i < Nr; ++i)
			y[i] += a(i, j) * x[j];
	}
}

// y = alpha*A*x + beta*y
// algorithm: y = alpha*(A*x + beta/alpha *y)
inline void mul(SvbaseComp_IO y, ScmatComp_I a, SvecComp_I x, Comp_I alpha, Comp_I beta)
{
	Long Nr = a.n0(), Nc = a.n1();
#ifdef SLS_CHECK_SHAPES
	if (Nc != x.size() || y.size() != Nr)
		SLS_ERR("illegal shape!");
#endif
	// y = beta/alpha *y
	if (beta == 0) {
		for (Long i = 0; i < Nr; ++i)
			y[i] = 0;
	}
	else {
		Comp b_a = beta/alpha;
		if (b_a != 1) {
			for (Long i = 0; i < Nr; ++i)
				y[i] *= b_a;
		}
	}
	// y += A*x
	for (Long j = 0; j < Nc; ++j) {
		for (Long i = 0; i < Nr; ++i)
			y[i] += a(i, j) * x[j];
	}
	// y *= alpha
	if (alpha != 1) {
		for (Long i = 0; i < Nr; ++i)
			y[i] *= alpha;
	}
}

inline void mul(SvbaseQcomp_O y, ScmatQcomp_I a, SvecQcomp_I x)
{
	Long Nr = a.n0(), Nc = a.n1();
#ifdef SLS_CHECK_SHAPES
	if (Nc != x.size() || y.size() != Nr)
		SLS_ERR("illegal shape!");
#endif
	for (Long i = 0; i < Nr; ++i)
		y[i] = a(i, 0) * x[0];
	for (Long j = 1; j < Nc; ++j) {
		for (Long i = 0; i < Nr; ++i)
			y[i] += a(i, j) * x[j];
	}
}

// y = alpha*A*x + beta*y
// algorithm: y = alpha*(A*x + beta/alpha *y)
inline void mul(SvbaseQcomp_IO y, ScmatQcomp_I a, SvecQcomp_I x, Qcomp_I alpha, Qcomp_I beta)
{
	Long Nr = a.n0(), Nc = a.n1();
#ifdef SLS_CHECK_SHAPES
	if (Nc != x.size() || y.size() != Nr)
		SLS_ERR("illegal shape!");
#endif
	// y = beta/alpha *y
	if (beta == 0) {
		for (Long i = 0; i < Nr; ++i)
			y[i] = 0;
	}
	else {
		Qcomp b_a = beta/alpha;
		if (b_a != 1) {
			for (Long i = 0; i < Nr; ++i)
				y[i] *= b_a;
		}
	}
	// y += A*x
	for (Long j = 0; j < Nc; ++j) {
		for (Long i = 0; i < Nr; ++i)
			y[i] += a(i, j) * x[j];
	}
	// y *= alpha
	if (alpha != 1) {
		for (Long i = 0; i < Nr; ++i)
			y[i] *= alpha;
	}
}


inline void mul(SvecComp_O y, SvecDoub_I x, MatComp_I a)
{
	Long Nr_a = a.n0(), Nc_a = a.n1();
#ifdef SLS_CHECK_SHAPES
	if (x.size() != a.n0() || y.size() != Nc_a)
		SLS_ERR("illegal shape!");
#endif
	vecset(y.p(), 0, Nc_a);
	for (Long j = 0; j < Nc_a; ++j) {
		for (Long i = 0; i < Nr_a; ++i)
			y[j] += x[i] * a(i, j);
	}
}

inline void mul(SvecComp_O y, SvecDoub_I x, CmatComp_I a)
{
	Long Nr_a = a.n0(), Nc_a = a.n1();
#ifdef SLS_CHECK_SHAPES
	if (x.size() != a.n0() || y.size() != Nc_a)
		SLS_ERR("illegal shape!");
#endif
	vecset(y.p(), 0, Nc_a);
	for (Long j = 0; j < Nc_a; ++j) {
		for (Long i = 0; i < Nr_a; ++i)
			y[j] += x[i] * a(i, j);
	}
}


inline void mul(ScmatComp_O y, ScmatComp_I a, MatComp_I x)
{
	Long Nr_a = a.n0(), Nc_a = a.n1(), Nc_x = x.n1();
#ifdef SLS_CHECK_SHAPES
	if (a.n1() != x.n0() || y.n0() != Nr_a || y.n1() != Nc_x)
		SLS_ERR("illegal shape!");
#endif
	vecset(y.p(), 0, Nr_a*Nc_x);
	for (Long i = 0; i < Nr_a; ++i) {
		for (Long j = 0; j < Nc_x; ++j) {
			for (Long k = 0; k < Nc_a; ++k)
				y(i, j) += a(i, k) * x(k, j);
		}
	}
}

inline void mul(ScmatComp_O y, ScmatComp_I a, ScmatComp_I x)
{
	Long Nr_a = a.n0(), Nc_a = a.n1(), Nc_x = x.n1();
#ifdef SLS_CHECK_SHAPES
	if (a.n1() != x.n0() || y.n0() != Nr_a || y.n1() != Nc_x)
		SLS_ERR("illegal shape!");
#endif
	vecset(y.p(), 0, Nr_a*Nc_x);
	for (Long i = 0; i < Nr_a; ++i) {
		for (Long j = 0; j < Nc_x; ++j) {
			for (Long k = 0; k < Nc_a; ++k)
				y(i, j) += a(i, k) * x(k, j);
		}
	}
}

inline void mul(ScmatComp_O y, ScmatComp_I a, ScmatDoub_I x)
{
	Long Nr_a = a.n0(), Nc_a = a.n1(), Nc_x = x.n1();
#ifdef SLS_CHECK_SHAPES
	if (a.n1() != x.n0() || y.n0() != Nr_a || y.n1() != Nc_x)
		SLS_ERR("illegal shape!");
#endif
	vecset(y.p(), 0, Nr_a*Nc_x);
	for (Long i = 0; i < Nr_a; ++i) {
		for (Long j = 0; j < Nc_x; ++j) {
			for (Long k = 0; k < Nc_a; ++k)
				y(i, j) += a(i, k) * x(k, j);
		}
	}
}

inline void mul(ScmatDoub_O y, ScmatDoub_I a, ScmatDoub_I x)
{
	Long Nr_a = a.n0(), Nc_a = a.n1(), Nc_x = x.n1();
#ifdef SLS_CHECK_SHAPES
	if (a.n1() != x.n0() || y.n0() != Nr_a || y.n1() != Nc_x)
		SLS_ERR("illegal shape!");
#endif
	vecset(y.p(), 0, Nr_a*Nc_x);
	for (Long i = 0; i < Nr_a; ++i) {
		for (Long j = 0; j < Nc_x; ++j) {
			for (Long k = 0; k < Nc_a; ++k)
				y(i, j) += a(i, k) * x(k, j);
		}
	}
}

inline void mul(ScmatComp_O y, ScmatDoub_I a, ScmatComp_I x)
{
	Long Nr_a = a.n0(), Nc_a = a.n1(), Nc_x = x.n1();
#ifdef SLS_CHECK_SHAPES
	if (a.n1() != x.n0() || y.n0() != Nr_a || y.n1() != Nc_x)
		SLS_ERR("illegal shape!");
#endif
	vecset(y.p(), 0, Nr_a*Nc_x);
	for (Long i = 0; i < Nr_a; ++i) {
		for (Long j = 0; j < Nc_x; ++j) {
			for (Long k = 0; k < Nc_a; ++k)
				y(i, j) += a(i, k) * x(k, j);
		}
	}
}


// matrix-vector multiplication
// y = alpha*A*x + beta*y
inline void mul_gen(SvecDoub_O y, ScmatDoub_I a, SvecDoub_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPES
	if (x.size() != a.n1() || y.size() != a.n0())
		SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
	cblas_dgemv(CblasColMajor, CblasNoTrans, a.n0(), a.n1(), alpha, a.p(),
		a.n0(), x.p(), 1, beta, y.p(), 1);
#else
	mul(y, a, x, alpha, beta);
#endif
}

// y = alpha*A*x + beta*y
inline void mul_gen(SvecQdoub_O y, ScmatQdoub_I a, SvecQdoub_I x, Qdoub_I alpha = 1, Qdoub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPES
	if (x.size() != a.n1() || y.size() != a.n0())
		SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_MPLAPACK
	Rgemv("N", a.n0(), a.n1(), alpha, (Qdoub*)a.p(), a.n0(), (Qdoub*)x.p(), 1, beta, (Qdoub*)y.p(), 1);
#else
	mul(y, a, x, alpha, beta);
#endif
}

// y = alpha*A*x + beta*y
inline void mul_gen(SvecComp_O y, ScmatDoub_I a, SvecComp_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPES
	if (x.size() != a.n1() || y.size() != a.n0())
		SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
	// do real part
	cblas_dgemv(CblasColMajor, CblasNoTrans, a.n0(), a.n1(), alpha, a.p(),
		a.n0(), (Doub*)x.p(), 2*1, beta, (Doub*)y.p(), 2*1);
	// do imag part
	cblas_dgemv(CblasColMajor, CblasNoTrans, a.n0(), a.n1(), alpha, a.p(),
		a.n0(), (Doub*)x.p()+1, 2*1, beta, (Doub*)y.p()+1, 2*1);
#else
	mul(y, a, x, alpha, beta);
#endif
}

// y = alpha*A*x + beta*y
inline void mul_gen(SvecComp_O y, ScmatDoub_I a, DvecComp_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPES
	if (x.size() != a.n1() || y.size() != a.n0())
		SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
	// do real part
	cblas_dgemv(CblasColMajor, CblasNoTrans, a.n0(), a.n1(), alpha, a.p(),
		a.n0(), (Doub*)x.p(), 2*x.step(), beta, (Doub*)y.p(), 2*1);
	// do imag part
	cblas_dgemv(CblasColMajor, CblasNoTrans, a.n0(), a.n1(), alpha, a.p(),
		a.n0(), (Doub*)x.p()+1, 2*x.step(), beta, (Doub*)y.p()+1, 2*1);
#else
	mul(y, a, x, alpha, beta);
#endif
}

// y = alpha*A*x + beta*y
inline void mul_gen(SvecComp_O y, ScmatComp_I a, SvecComp_I x, Comp_I alpha = 1, Comp_I beta = 0)
{
#ifdef SLS_CHECK_SHAPES
	if (x.size() != a.n1() || y.size() != a.n0())
		SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
	cblas_zgemv(CblasColMajor, CblasNoTrans, a.n0(), a.n1(), &alpha, a.p(),
		a.n0(), x.p(), 1, &beta, y.p(), 1);
#else
	mul(y, a, x, alpha, beta);
#endif
}

// y = alpha*A*x + beta*y
inline void mul_gen(SvecComp_O y, ScmatComp_I a, DvecComp_I x, Comp_I alpha = 1, Comp_I beta = 0)
{
#ifdef SLS_CHECK_SHAPES
	if (x.size() != a.n1() || y.size() != a.n0())
		SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
	cblas_zgemv(CblasColMajor, CblasNoTrans, a.n0(), a.n1(), &alpha, a.p(),
		a.n0(), x.p(), x.step(), &beta, y.p(), 1);
#else
	mul(y, a, x, alpha, beta);
#endif
}

// y = alpha*A*x + beta*y
inline void mul_gen(SvecComp_O y, DcmatDoub_I a, SvecComp_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPES
	if (x.size() != a.n1() || y.size() != a.n0())
		SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
	// do real part
	cblas_dgemv(CblasColMajor, CblasNoTrans, a.n0(), a.n1(), alpha, a.p(),
		a.lda(), (Doub*)x.p(), 2*1, beta, (Doub*)y.p(), 2*1);
	// do imag part
	cblas_dgemv(CblasColMajor, CblasNoTrans, a.n0(), a.n1(), alpha, a.p(),
		a.lda(), (Doub*)x.p()+1, 2*1, beta, (Doub*)y.p()+1, 2*1);
#else
	mul(y, a, x, alpha, beta);
#endif
}

// y = alpha*A*x + beta*y
inline void mul_gen(SvecQcomp_O y, ScmatQdoub_I a, SvecQcomp_I x, Qdoub_I alpha = 1, Qdoub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPES
	if (x.size() != a.n1() || y.size() != a.n0())
		SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_MPLAPACK
	// do real part
	Rgemv("N", a.n0(), a.n1(), alpha, (Qdoub*)a.p(), a.n0(), (Qdoub*)x.p(),
		2*1, beta, (Qdoub*)y.p(), 2*1);
	// do imag part
	Rgemv("N", a.n0(), a.n1(), alpha, (Qdoub*)a.p(), a.n0(), (Qdoub*)x.p()+1,
		2*1, beta, (Qdoub*)y.p()+1, 2*1);
#else
	mul(y, a, x, alpha, beta);
#endif
}

// y = alpha*A*x + beta*y
inline void mul_gen(SvecQcomp_O y, ScmatQdoub_I a, DvecQcomp_I x, Qdoub_I alpha = 1, Qdoub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPES
	if (x.size() != a.n1() || y.size() != a.n0())
		SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_MPLAPACK
	// do real part
	Rgemv("N", a.n0(), a.n1(), alpha, (Qdoub*)a.p(), a.n0(), (Qdoub*)x.p(),
		2*x.step(), beta, (Qdoub*)y.p(), 2*1);
	// do imag part
	Rgemv("N", a.n0(), a.n1(), alpha, (Qdoub*)a.p(), a.n0(), (Qdoub*)x.p()+1,
		2*x.step(), beta, (Qdoub*)y.p()+1, 2*1);
#else
	mul(y, a, x, alpha, beta);
#endif
}

// y = alpha*A*x + beta*y
inline void mul_gen(SvecQcomp_O y, ScmatQcomp_I a, SvecQcomp_I x, Qcomp_I alpha = 1, Qcomp_I beta = 0)
{
#ifdef SLS_CHECK_SHAPES
	if (x.size() != a.n1() || y.size() != a.n0())
		SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_MPLAPACK
	Cgemv("N", a.n0(), a.n1(), alpha, (Qcomp*)a.p(), a.n0(), (Qcomp*)x.p(), 1, beta, (Qcomp*)y.p(), 1);
#else
	mul(y, a, x, alpha, beta);
#endif
}

// y = alpha*A*x + beta*y
inline void mul_gen(SvecQcomp_O y, ScmatQcomp_I a, DvecQcomp_I x, Qcomp_I alpha = 1, Qcomp_I beta = 0)
{
#ifdef SLS_CHECK_SHAPES
	if (x.size() != a.n1() || y.size() != a.n0())
		SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_MPLAPACK
	Cgemv("N", a.n0(), a.n1(), alpha, (Qcomp*)a.p(), a.n0(), (Qcomp*)x.p(), x.step(), beta, (Qcomp*)y.p(), 1);
#else
	mul(y, a, x, alpha, beta);
#endif
}

// y = alpha*A*x + beta*y
inline void mul_gen(SvecQcomp_O y, DcmatQdoub_I a, SvecQcomp_I x, Qdoub_I alpha = 1, Qdoub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPES
	if (x.size() != a.n1() || y.size() != a.n0())
		SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_MPLAPACK
	// do real part
	Rgemv("N", a.n0(), a.n1(), alpha, (Qdoub*)a.p(), a.lda(), (Qdoub*)x.p(),
		2*1, beta, (Qdoub*)y.p(), 2*1);
	// do imag part
	Rgemv("N", a.n0(), a.n1(), alpha, (Qdoub*)a.p(), a.lda(), (Qdoub*)x.p()+1,
		2*1, beta, (Qdoub*)y.p()+1, 2*1);
#else
	mul(y, a, x, alpha, beta);
#endif
}

// y = alpha*A*x + beta*y
inline void mul_gen(DvecComp_O y, ScmatDoub_I a, SvecComp_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPES
	if (x.size() != a.n1() || y.size() != a.n0())
		SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
	// do real part
	cblas_dgemv(CblasColMajor, CblasNoTrans, a.n0(), a.n1(), alpha, a.p(),
		a.n0(), (Doub*)x.p(), 2*1, beta, (Doub*)y.p(), 2*y.step());
	// do imag part
	cblas_dgemv(CblasColMajor, CblasNoTrans, a.n0(), a.n1(), alpha, a.p(),
		a.n0(), (Doub*)x.p()+1, 2*1, beta, (Doub*)y.p()+1, 2*y.step());
#else
	mul(y, a, x, alpha, beta);
#endif
}

// y = alpha*A*x + beta*y
inline void mul_gen(DvecQcomp_O y, ScmatQdoub_I a, SvecQcomp_I x, Qdoub_I alpha = 1, Qdoub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPES
	if (x.size() != a.n1() || y.size() != a.n0())
		SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_MPLAPACK
	// do real part
	Rgemv("N", a.n0(), a.n1(), alpha, (Qdoub*)a.p(), a.n0(), (Qdoub*)x.p(),
		2*1, beta, (Qdoub*)y.p(), 2*y.step());
	// do imag part
	Rgemv("N", a.n0(), a.n1(), alpha, (Qdoub*)a.p(), a.n0(), (Qdoub*)x.p()+1,
		2*1, beta, (Qdoub*)y.p()+1, 2*y.step());
#else
	mul(y, a, x, alpha, beta);
#endif
}

// y = alpha*A*x + beta*y
inline void mul_gen(DvecComp_O y, ScmatComp_I a, SvecComp_I x, Comp_I alpha = 1, Comp_I beta = 0)
{
#ifdef SLS_CHECK_SHAPES
	if (x.size() != a.n1() || y.size() != a.n0())
		SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
	cblas_zgemv(CblasColMajor, CblasNoTrans, a.n0(), a.n1(), &alpha, a.p(),
		a.n0(), x.p(), 1, &beta, y.p(), y.step());
#else
	mul(y, a, x, alpha, beta);
#endif
}

// y = alpha*A*x + beta*y
inline void mul_gen(DvecQcomp_O y, ScmatQcomp_I a, SvecQcomp_I x, Qcomp_I alpha = 1, Qcomp_I beta = 0)
{
#ifdef SLS_CHECK_SHAPES
	if (x.size() != a.n1() || y.size() != a.n0())
		SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_MPLAPACK
	Cgemv("N", a.n0(), a.n1(), alpha, (Qcomp*)a.p(), a.n0(), (Qcomp*)x.p(), 1, beta, (Qcomp*)y.p(), y.step());
#else
	mul(y, a, x, alpha, beta);
#endif
}

// y = alpha*A*x + beta*y
inline void mul_gen(DvecComp_O y, ScmatDoub_I a, DvecComp_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPES
	if (x.size() != a.n1() || y.size() != a.n0())
		SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
	// do real part
	cblas_dgemv(CblasColMajor, CblasNoTrans, a.n0(), a.n1(), alpha, a.p(),
		a.n0(), (Doub*)x.p(), 2*x.step(), beta, (Doub*)y.p(), 2*y.step());
	// do imag part
	cblas_dgemv(CblasColMajor, CblasNoTrans, a.n0(), a.n1(), alpha, a.p(),
		a.n0(), (Doub*)x.p()+1, 2*x.step(), beta, (Doub*)y.p()+1, 2*y.step());
#else
	mul(y, a, x, alpha, beta);
#endif
}

// y = alpha*A*x + beta*y
inline void mul_gen(DvecQcomp_O y, ScmatQdoub_I a, DvecQcomp_I x, Qdoub_I alpha = 1, Qdoub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPES
	if (x.size() != a.n1() || y.size() != a.n0())
		SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_MPLAPACK
	// do real part
	Rgemv("N", a.n0(), a.n1(), alpha, (Qdoub*)a.p(), a.n0(), (Qdoub*)x.p(),
		2*x.step(), beta, (Qdoub*)y.p(), 2*y.step());
	// do imag part
	Rgemv("N", a.n0(), a.n1(), alpha, (Qdoub*)a.p(), a.n0(), (Qdoub*)x.p()+1,
		2*x.step(), beta, (Qdoub*)y.p()+1, 2*y.step());
#else
	mul(y, a, x, alpha, beta);
#endif
}

// y = alpha*A*x + beta*y
inline void mul_gen(SvbaseComp_O y, ScmatComp_I a, SvecComp_I x, Comp_I alpha = 1, Comp_I beta = 0)
{
#ifdef SLS_CHECK_SHAPES
	if (x.size() != a.n1() || y.size() != a.n0())
		SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
	cblas_zgemv(CblasColMajor, CblasNoTrans, a.n0(), a.n1(), &alpha, a.p(),
		a.n0(), x.p(), 1, &beta, y.p(), 1);
#else
	mul(y, a, x, alpha, beta);
#endif
}

// y = alpha*A*x + beta*y
inline void mul_gen(SvbaseQcomp_O y, ScmatQcomp_I a, SvecQcomp_I x, Qcomp_I alpha = 1, Qcomp_I beta = 0)
{
#ifdef SLS_CHECK_SHAPES
	if (x.size() != a.n1() || y.size() != a.n0())
		SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_MPLAPACK
	Cgemv("N", a.n0(), a.n1(), alpha, (Qcomp*)a.p(), a.n0(), (Qcomp*)x.p(), 1, beta, (Qcomp*)y.p(), 1);
#else
	mul(y, a, x, alpha, beta);
#endif
}


// y = alpha*A*x + beta*y (only use upper triangle)
inline void mul_sym(SvecComp_IO &y, ScmatDoub_I a, SvecComp_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPES
	if (x.size() != a.n1() || y.size() != a.n0() || x.size() != y.size())
		SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
	// do real part
	cblas_dsymv(CblasColMajor, CblasUpper, a.n0(), alpha, a.p(),
		a.n0(), (Doub*)x.p(), 2*1, beta, (Doub*)y.p(), 2*1);
	// do imag part
	cblas_dsymv(CblasColMajor, CblasUpper, a.n0(), alpha, a.p(),
		a.n0(), (Doub*)x.p()+1, 2*1, beta, (Doub*)y.p()+1, 2*1);
#else
	SLS_ERR("not implemented!"); // mul() doesn't work (must only use upper triangle)
#endif
}

// y = alpha*A*x + beta*y (only use upper triangle)
inline void mul_sym(SvecQcomp_IO &y, ScmatQdoub_I a, SvecQcomp_I x, Qdoub_I alpha = 1, Qdoub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPES
	if (x.size() != a.n1() || y.size() != a.n0() || x.size() != y.size())
		SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_MPLAPACK
	// do real part
	Rsymv("U", a.n0(), alpha, (Qdoub*)a.p(), a.n0(), (Qdoub*)x.p(), 2*1, beta, (Qdoub*)y.p(), 2*1);
	// do imag part
	Rsymv("U", a.n0(), alpha, (Qdoub*)a.p(), a.n0(), (Qdoub*)x.p()+1, 2*1, beta, (Qdoub*)y.p()+1, 2*1);
#else
	SLS_ERR("not implemented!"); // mul() doesn't work (must only use upper triangle)
#endif
}

// y = alpha*A*x + beta*y (only use upper triangle)
inline void mul_sym(SvecDoub_IO &y, ScmatDoub_I a, SvecDoub_I x, Doub_I alpha = 1, Doub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPES
	if (x.size() != a.n1() || y.size() != a.n0() || x.size() != y.size())
		SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_CBLAS
	cblas_dsymv(CblasColMajor, CblasUpper, a.n0(), alpha, a.p(),
		a.n0(), x.p(), 1, beta, y.p(), 1);
#else
	SLS_ERR("not implemented!"); // mul() doesn't work (must only use upper triangle)
#endif
}

// y = alpha*A*x + beta*y (only use upper triangle)
inline void mul_sym(SvecQdoub_IO &y, ScmatQdoub_I a, SvecQdoub_I x, Qdoub_I alpha = 1, Qdoub_I beta = 0)
{
#ifdef SLS_CHECK_SHAPES
	if (x.size() != a.n1() || y.size() != a.n0() || x.size() != y.size())
		SLS_ERR("wrong shape!");
#endif
#ifdef SLS_USE_MPLAPACK
	Rsymv("U", a.n0(), alpha, (Qdoub*)a.p(), a.n0(), (Qdoub*)x.p(), 1, beta, y.p(), 1);
#else
	SLS_ERR("not implemented!"); // mul() doesn't work (must only use upper triangle)
#endif
}


inline void mul_gen(ScmatDoub_O y, ScmatDoub_I a, ScmatDoub_I x)
{
#ifdef SLS_CHECK_SHAPES
	if (a.n1() != x.n0() || y.n0() != a.n0() || y.n1() != x.n1())
		SLS_ERR("illegal shape!");
#endif
#ifdef SLS_USE_CBLAS
	cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, a.n0(), x.n1(), a.n1(), 1, (Doub*)a.p(), a.n0(), (Doub*)x.p(), a.n1(), 0, (Doub*)y.p(), a.n0());
#else
	mul(y, a, x);
#endif
}

inline void mul_gen(ScmatComp_O y, ScmatComp_I a, ScmatDoub_I x)
{
#ifdef SLS_CHECK_SHAPES
	if (a.n1() != x.n0() || y.n0() != a.n0() || y.n1() != x.n1())
		SLS_ERR("illegal shape!");
#endif
#ifdef SLS_USE_CBLAS
		SLS_WARN("not implemented with cBLAS, using slow version");
		mul(y, a, x);
#else
	mul(y, a, x);
#endif
}

inline void mul_gen(ScmatComp_O y, ScmatDoub_I a, ScmatComp_I x)
{
#ifdef SLS_CHECK_SHAPES
	if (a.n1() != x.n0() || y.n0() != a.n0() || y.n1() != x.n1())
		SLS_ERR("illegal shape!");
#endif
#ifdef SLS_USE_CBLAS
		SLS_WARN("not implemented with cBLAS, using slow version");
		mul(y, a, x);
#else
	mul(y, a, x);
#endif
}


} // namespace slisc
