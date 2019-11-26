// COO sparse matrix
#pragma once
#include "sort.h"
#include "svector.h"

namespace slisc {

inline void linspace(VecLlong_O v, Llong_I first, Llong_I last);
#include "matcoo_Mcoo.inl"
} // namespace slisc
