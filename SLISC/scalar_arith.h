#pragma once
#include "global.h"

namespace slisc {

#include "isodd.inl"
#include "to_num.inl"
#include "mod.inl"
#include "sqr.inl"
#include "abs2.inl"

inline Doub factorial_imp(Doub_I n) {
    if (n == 0. || n == 1.)
        return 1.;
    else
        return n * factorial_imp(n - 1.);
}

inline Doub factorial(Int_I n) {
    if (n > 170)
        SLS_ERR("n too large!");
    return factorial_imp(n);
}

} // namespace slisc
