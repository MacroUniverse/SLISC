#include "Vec.h"
#include "Mat.h"
#include "Cmat.h"
#include "Svec.h"
#include "Dcmat.h"
#include "copy.h"
#include "slice_arith.h"

namespace slisc {
#include "resize_cpy.inl"
#include "linspace_vss.inl"
#include "linspace.inl"
#include "reorder.inl"
#include "trans.inl"
#include "trans2.inl"
#include "mul_mv.inl"
#include "mul_gen.inl"
#include "mul_sym.inl"
} // namespace slisc
