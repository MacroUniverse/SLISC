#pragma once
#include "arithmetic.h"
#include "Diag.h"
#include "Mcoo.h"
#include "sort.h"

namespace slisc {
#include "mul_cmat_cmat_diag.inl"
#include "mul_cmat_diag_cmat.inl"
#include "mul_v_coo_v.inl"
#include "mul_sparse_mv.inl"
#include "mul_sparse_mm.inl"
#include "sort_r_Mcoo.inl"
#include "sparse_plus_minus_times_divede_eq_contain_vs.inl"
} // namespace slisc
