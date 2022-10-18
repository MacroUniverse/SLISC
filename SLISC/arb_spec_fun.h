// see also coulomb.h and hypergeom.h etc
// if this file gets too large, consider splitting
#pragma once
#include <gmp.h>
#include <flint.h>
#include "arb_extension.h"

namespace slisc {

#define SLS_ARB_ITER_MAX 50;

inline void gamma(Areal_O res, Areal_I x)
{
	SLS_WARN("not tested!");
	slong prec_goal = arb_prec(), prec = prec_goal;
	Long i;
	for (i = 0; i < SLS_ARB_ITER_MAX; ++i) {
		arb_gamma(res.m_n, x.m_n, prec);
		if (arb_rel_accuracy_bits(res.m_n) >= prec_goal)
			break;
		prec *= 2;
	}
	if (i == SLS_ARB_ITER_MAX)
		SLS_ERR("arb_gamma error too large : " + num2str(arb_rel_accuracy_bits(res)/3.3219) + " digits");
}

} // name slisc
