// sparse matrix containers
#pragma once
#include "matcoo.h"

#ifndef NDEBUG
// make sure (i,j) element doesn't exist when using MatCoo<T>::push(s,i,j) 
#define SLS_CHECK_COO_REPEAT
#endif

namespace slisc {

// sparse Hermitian / symmetric
// only stores the upper triangle
// nnz() is the actual # of non-zero elem. stored
#include "matcooh_Mcooh.inl"

} // namespace slisc
