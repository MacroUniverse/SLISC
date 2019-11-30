#include "Vec.h"
#include "Mat.h"
#include "Cmat.h"
#include "Dcmat.h"
#include "copy.h"
#include "slice_arith.h"

namespace slisc {
#include "resize_cpy.inl"
#include "linspace_vss.inl"
#include "linspace.inl"
#include "reorder.inl"
#include "mul_mv.inl"
#include "mul_gen.inl"
} // namespace slisc
