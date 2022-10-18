// see also coulomb.h and hypergeom.h etc
// if this file gets too large, consider splitting
#pragma once
#include <gmp.h>
#include <flint.h>
#include "compare.h"
#include "scalar_arith.h"
#include "arb_extension.h"

namespace slisc {

#define SLS_ARB_ITER_MAX 50;

// TODO: figure out the behavior when radius of x is not zero

// inline void gamma(arb_t res, arb_t x, slong prec_goal)
// {
// 	slong prec = prec_goal;
// 	Long i;
// 	for (i = 0; i < 50; ++i) {
// 		arb_gamma(res, x, prec);
// 		if (arb_rel_accuracy_bits(res) >= prec_goal)
// 			break;
// 		prec *= 2;
// 	}
// 	if (i == 50)
// 		SLS_ERR("arb_gamma error too large : " + num2str(arb_rel_accuracy_bits(res)/3.3219) + " digits");
// }

// inline void gamma(Areal_O z, Areal_I x)
// { arb_gamma(z.m_n, x.m_n, arb_prec()); }

// inline void gamma(Areal_O res, Areal_I x) { gamma(res.m_n, x.m_n, arb_prec()); }

} // name slisc
