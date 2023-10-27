// write containers to hdf file
// always use Llong when reading and writing index

#pragma once
#include <H5Cpp.h>
#include "../arith/scalar_arith.h"
#include "../file/file.h"
#include "../util/bit.h"
#include "../prec/quad_math.h"

namespace slisc {

using H5::H5File; using H5::DataSpace;
using H5::PredType; using H5::DataSet;

inline void save(ScmatDoub_I a, Str_I name, H5File &file)
{
	hsize_t dims[2] = {(hsize_t)a.n0(), (hsize_t)a.n1()};
    DataSpace dataspace(2, dims);
    DataSet dataset = file.createDataSet(name, PredType::NATIVE_DOUBLE, dataspace);
    
    hsize_t mem_dims[1] = {2};
    hsize_t col_dims[1] = {(hsize_t)a.n0()};
    hsize_t stride[2] = {1, 1};  // move by 1 row and 1 column
    hsize_t count[2] = {(hsize_t)a.n0(), 1};   // block size
    hsize_t block[2] = {1, 1};   // block dimensions (1x1)
    hsize_t offset_out[1] = {0};
    DataSpace memspace(1, col_dims);

    for (hsize_t j = 0; j < a.n1(); ++j) {
        hsize_t start[2] = {0, j}; // start of block
        dataspace.selectHyperslab(H5S_SELECT_SET, count, start, stride, block);
        memspace.selectHyperslab(H5S_SELECT_SET, col_dims, offset_out);
        dataset.write(&a(0,j), PredType::NATIVE_DOUBLE, memspace, dataspace);
    }
}

} // namespace slisc
