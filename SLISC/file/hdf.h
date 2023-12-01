// write containers to hdf file
// always use Llong when reading and writing index

#pragma once
#include "../config.h"
#ifdef SLS_USE_HDF
#include <H5Cpp.h>
#include "../arith/scalar_arith.h"
#include "../file/file.h"
#include "../util/bit.h"
#include "../prec/quad_math.h"

namespace slisc {

using H5::H5File; using H5::DataSpace;
using H5::PredType; using H5::DataSet;

inline void save(SvecDoub_I v, Str_I name, H5File &file)
{
	hsize_t N = v.size();
	hsize_t dims[1] = {N};
	DataSpace dataspace(1, dims);
	DataSet dataset = file.createDataSet("dataset_name", PredType::NATIVE_DOUBLE, dataspace);
	if (N > 0)
		dataset.write(&v[0], PredType::NATIVE_DOUBLE);
}

inline void save(ScmatDoub_I a, Str_I name, H5File &file)
{
	hsize_t N0 = a.n0(), N1 = a.n1();
	hsize_t dims[2] = {N0, N1};
    DataSpace dataspace(2, dims);
    DataSet dataset = file.createDataSet(name, PredType::NATIVE_DOUBLE, dataspace);
	if (N0*N1 == 0) return;
	
	// for row major, we can write the dataset in 1 command
	// column major needs to use Hyperslab if we don't want to convert to row major first
    hsize_t col_dims[1] = {N0};
    hsize_t stride[2] = {1, 1};  // move by 1 row and 1 column
    hsize_t count[2] = {N0, 1};  // block size
    hsize_t block[2] = {1, 1};   // block dimensions (1x1)
    hsize_t offset_out[1] = {0};
    DataSpace memspace(1, col_dims);

    for (hsize_t j = 0; j < N1; ++j) {
        hsize_t start[2] = {0, j}; // start of block
        dataspace.selectHyperslab(H5S_SELECT_SET, count, start, stride, block);
        memspace.selectHyperslab(H5S_SELECT_SET, col_dims, offset_out);
        dataset.write(&a(0,j), PredType::NATIVE_DOUBLE, memspace, dataspace);
    }
}

inline void save(Scmat3Doub_I a, Str_I name, H5File &file)
{
	hsize_t N0 = a.n0(), N1 = a.n1(), N2 = a.n2();
	hsize_t dims[3] = {N0, N1, N2};
    DataSpace dataspace(3, dims);
    DataSet dataset = file.createDataSet(name, PredType::NATIVE_DOUBLE, dataspace);
	if (N0*N1*N2 == 0) return;
    
    hsize_t col_dims[1] = {N0};
    hsize_t stride[3] = {1, 1, 1};  // move by 1 row and 1 column
    hsize_t count[3] = {N0, 1, 1};  // block size
    hsize_t block[3] = {1, 1, 1};   // block dimensions (1x1x1)
    hsize_t offset_out[1] = {0};
    DataSpace memspace(1, col_dims);

	for (hsize_t k = 0; k < N2; ++k) {
		for (hsize_t j = 0; j < N1; ++j) {
			hsize_t start[3] = {0, j, k}; // start of block
			dataspace.selectHyperslab(H5S_SELECT_SET, count, start, stride, block);
			memspace.selectHyperslab(H5S_SELECT_SET, col_dims, offset_out);
			dataset.write(&a(0,j,k), PredType::NATIVE_DOUBLE, memspace, dataspace);
		}
	}
}

} // namespace slisc
#endif
