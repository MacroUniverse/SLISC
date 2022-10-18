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

// inline void gamma(Areal_O res, Areal_I x) { gamma(res.m_n, x.m_n, arb_prec()); }

} // name slisc
