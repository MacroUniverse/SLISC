#pragma once
#include "arithmetic.h"
#include "Diag.h"
#include "Mcoo.h"
#include "sort.h"

namespace slisc {
#include "mul_cmat_cmat_diag.inl"
#include "mul_cmat_diag_cmat.inl"
#include "mul_sparse.inl"
#include "sort_r_Mcoo.inl"
} // namespace slisc
