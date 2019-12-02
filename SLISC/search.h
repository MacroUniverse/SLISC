#pragma once
#include "arithmetic.h"
#include "slice_arith.h"

namespace slisc {

// see if elm == vec[i], return i
// return -1 if not found
#include "search.inl"

// search a row from a matrix
// starting from the row `start`
// return the row index, return -1 if not found
#include "search_row.inl"

// check if v[i] == v[j] for any i and j
// return the index of one of the repeated elements
// return -1 if no reapeat
#include "find_repeat.inl"

// return 0, output ind: if v[ind] == s
// return -1: if s is not found and s < v[0]
// return 1: if s is not found and v[end] < s
// return -2: if s is not found and v[0] < s < v[end], output ind so that v[ind] < s < v[ind+1]
// return -3: if s is not found because v.size() == 0
// operator-(v[i], s) must be implemented and only need to return the correct sign or 0
#include "lookupIntv.inl"
} // namespace slisc
