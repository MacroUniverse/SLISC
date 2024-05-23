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

inline void save(Doub_I s, Str_I name, H5File &file)
{
	hsize_t dims[1] = {1};
	DataSpace dataspace(1, dims);
	DataSet dataset = file.createDataSet(name, PredType::NATIVE_DOUBLE, dataspace);
	dataset.write(&s, PredType::NATIVE_DOUBLE);
}

inline void load(Doub_O s, Str_I name, H5File &file)
{
	DataSet dataset = file.openDataSet(name);
	DataSpace dataspace = dataset.getSpace();
	hsize_t dims[1];
	dataspace.getSimpleExtentDims(dims, NULL);
	dataset.read(&s, PredType::NATIVE_DOUBLE);
}

inline void save(SvecDoub_I v, Str_I name, H5File &file)
{
	hsize_t N = v.size();
	hsize_t dims[1] = {N};
	DataSpace dataspace(1, dims);
	DataSet dataset = file.createDataSet(name, PredType::NATIVE_DOUBLE, dataspace);
	if (N > 0)
		dataset.write(&v[0], PredType::NATIVE_DOUBLE);
}

inline void load(VecDoub_O v, Str_I name, H5File &file)
{
	DataSet dataset = file.openDataSet(name);
	DataSpace dataspace = dataset.getSpace();
	hsize_t dims[1];
	dataspace.getSimpleExtentDims(dims, NULL);
	hsize_t N = dims[0];
	v.resize(N);
	if (N > 0)
		dataset.read(v.p(), PredType::NATIVE_DOUBLE);
}

inline void save(SvecComp_I v, Str_I name, H5File &file)
{
	hsize_t N = 2*v.size();
	hsize_t dims[1] = {N};
	DataSpace dataspace(1, dims);
	DataSet dataset = file.createDataSet(name, PredType::NATIVE_DOUBLE, dataspace);
	if (N > 0)
		dataset.write((const Doub *)&v[0], PredType::NATIVE_DOUBLE);
}

inline bool is_complex(H5File &dataset)
{
	Str label = "SLS_Comp";
	Attribute attribute = dataset.openAttribute(label);
	H5std_string labelValue;
	attribute.read(attribute.getStrType(), labelValue);
	retrun labelValue == label;
}

inline void load(VecComp_O v, Str_I name, H5File &file)
{
	DataSet dataset = file.openDataSet(name);
	SLS_ASSERT(is_complex(dataset));
	DataSpace dataspace = dataset.getSpace();
	hsize_t dims[1];
	dataspace.getSimpleExtentDims(dims, NULL);
	hsize_t N = dims[0];
	v.resize(N/2);
	if (N > 0)
		dataset.read((const Doub *)v.p(), PredType::NATIVE_DOUBLE);
}

inline void save(ScmatDoub_I a, Str_I name, H5File &file)
{
	hsize_t N0 = a.n0(), N1 = a.n1();
	hsize_t dims[2] = {N0, N1};
	DataSpace dataspace(2, dims);
	DataSet dataset = file.createDataSet(name, PredType::NATIVE_DOUBLE, dataspace);
	if (N0*N1 == 0) return;

	hsize_t col_dims[1] = {N0};
	hsize_t stride[2] = {1, 1}; // move by 1 row and 1 column
	hsize_t count[2] = {N0, 1}; // block size
	hsize_t block[2] = {1, 1};  // block dimensions (1x1)
	hsize_t offset_out[1] = {0};
	DataSpace memspace(1, col_dims); // where in the memory, relative to the address in `dataset.write()`

	for (hsize_t j = 0; j < N1; ++j) {
		hsize_t start[2] = {0, j}; // start of block
		dataspace.selectHyperslab(H5S_SELECT_SET, count, start, stride, block);
		memspace.selectHyperslab(H5S_SELECT_SET, col_dims, offset_out);
		dataset.write(&a(0,j), PredType::NATIVE_DOUBLE, memspace, dataspace);
	}
}

inline void load(CmatDoub_O a, Str_I name, H5File &file)
{
	DataSet dataset = file.openDataSet(name);
	DataSpace dataspace = dataset.getSpace();
	hsize_t dims_out[2];
	dataspace.getSimpleExtentDims(dims_out, NULL);
	hsize_t N0 = dims_out[0];
	hsize_t N1 = dims_out[1];
	a.resize(N0, N1);
	hsize_t col_dims[1] = {N0};
	DataSpace memspace(1, col_dims);

	hsize_t stride[2] = {1, 1};
	hsize_t count[2] = {N0, 1};
	hsize_t block[2] = {1, 1};
	hsize_t offset_out[1] = {0};

	for (hsize_t j = 0; j < N1; ++j) {
		hsize_t start[2] = {0, j};
		dataspace.selectHyperslab(H5S_SELECT_SET, count, start, stride, block);
		memspace.selectHyperslab(H5S_SELECT_SET, col_dims, offset_out);
		dataset.read(&a(0, j), PredType::NATIVE_DOUBLE, memspace, dataspace);
	}
}

inline void save(ScmatComp_I a, Str_I name, H5File &file)
{
	hsize_t N0 = 2*a.n0(), N1 = a.n1();
	hsize_t dims[2] = {N0, N1};
	DataSpace dataspace(2, dims);
	DataSet dataset = file.createDataSet(name, PredType::NATIVE_DOUBLE, dataspace);
	if (N0*N1 == 0) return;

	hsize_t col_dims[1] = {N0};
	hsize_t stride[2] = {1, 1}; // move by 1 row and 1 column
	hsize_t count[2] = {N0, 1}; // block size
	hsize_t block[2] = {1, 1};  // block dimensions (1x1)
	hsize_t offset_out[1] = {0};
	DataSpace memspace(1, col_dims); // where in the memory, relative to the address in `dataset.write()`

	DataSpace attr_dataspace(H5S_SCALAR);
	const H5std_string ATTR_NAME("SLS_Comp");
	const H5std_string ATTR_DATA("every 2 double in a column is a complex");
	H5::Attribute attribute = dataset.createAttribute(ATTR_NAME, H5::StrType(PredType::C_S1, ATTR_DATA.size()), attr_dataspace);
	attribute.write(H5::StrType(PredType::C_S1, ATTR_DATA.size()), ATTR_DATA);

	for (hsize_t j = 0; j < N1; ++j) {
		hsize_t start[2] = {0, j}; // start of block
		dataspace.selectHyperslab(H5S_SELECT_SET, count, start, stride, block);
		memspace.selectHyperslab(H5S_SELECT_SET, col_dims, offset_out);
		dataset.write((const Doub *)&a(0,j), PredType::NATIVE_DOUBLE, memspace, dataspace);
	}
}

inline void load(CmatComp_O a, Str_I name, H5File &file)
{
	DataSet dataset = file.openDataSet(name);
	DataSpace dataspace = dataset.getSpace();
	SLS_ASSERT(is_complex(dataset));

	hsize_t dims_out[2];
	dataspace.getSimpleExtentDims(dims_out, NULL);
	hsize_t N0 = dims_out[0];
	hsize_t N1 = dims_out[1];
	a.resize(N0/2, N1);
	hsize_t col_dims[1] = {N0};
	DataSpace memspace(1, col_dims);

	hsize_t stride[2] = {1, 1};
	hsize_t count[2] = {N0, 1};
	hsize_t block[2] = {1, 1};
	hsize_t offset_out[1] = {0};

	for (hsize_t j = 0; j < N1; ++j) {
		hsize_t start[2] = {0, j};
		dataspace.selectHyperslab(H5S_SELECT_SET, count, start, stride, block);
		memspace.selectHyperslab(H5S_SELECT_SET, col_dims, offset_out);
		dataset.read((Doub *)&a(0, j), PredType::NATIVE_DOUBLE, memspace, dataspace);
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

inline void load(Cmat3Doub_O a, Str_I name, H5File &file)
{
    DataSet dataset = file.openDataSet(name);
    DataSpace dataspace = dataset.getSpace();
    int rank = dataspace.getSimpleExtentNdims();
	SLS_ASSERT(rank == 3);
    hsize_t dims[3];
    dataspace.getSimpleExtentDims(dims, NULL);

    hsize_t N0 = dims[0], N1 = dims[1], N2 = dims[2];
	a.resize(N0, N1, N2);

    hsize_t col_dims[1] = {N0};
    hsize_t stride[3] = {1, 1, 1};
    hsize_t count[3] = {N0, 1, 1};
    hsize_t block[3] = {1, 1, 1};
    hsize_t offset_out[1] = {0};
    DataSpace memspace(1, col_dims);

    for (hsize_t k = 0; k < N2; ++k) {
        for (hsize_t j = 0; j < N1; ++j) {
            hsize_t start[3] = {0, j, k};
            dataspace.selectHyperslab(H5S_SELECT_SET, count, start, stride, block);
            memspace.selectHyperslab(H5S_SELECT_SET, col_dims, offset_out);
            dataset.read(&a(0, j, k), PredType::NATIVE_DOUBLE, memspace, dataspace);
        }
    }
}

inline void save(Scmat3Comp_I a, Str_I name, H5File &file)
{
	hsize_t N0 = 2*a.n0(), N1 = a.n1(), N2 = a.n2();
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

	DataSpace attr_dataspace(H5S_SCALAR);
	const H5std_string ATTR_NAME("SLS_Comp");
	const H5std_string ATTR_DATA("every 2 double in a column is a complex");
	H5::Attribute attribute = dataset.createAttribute(ATTR_NAME, H5::StrType(PredType::C_S1, ATTR_DATA.size()), attr_dataspace);
	attribute.write(H5::StrType(PredType::C_S1, ATTR_DATA.size()), ATTR_DATA);

	for (hsize_t k = 0; k < N2; ++k) {
		for (hsize_t j = 0; j < N1; ++j) {
			hsize_t start[3] = {0, j, k}; // start of block
			dataspace.selectHyperslab(H5S_SELECT_SET, count, start, stride, block);
			memspace.selectHyperslab(H5S_SELECT_SET, col_dims, offset_out);
			dataset.write((const Doub *)&a(0,j,k), PredType::NATIVE_DOUBLE, memspace, dataspace);
		}
	}
}

inline void load(Cmat3Comp_O a, Str_I name, H5File &file)
{
    DataSet dataset = file.openDataSet(name);
	SLS_ASSERT(is_complex(dataset));

    DataSpace dataspace = dataset.getSpace();
    int rank = dataspace.getSimpleExtentNdims();
	SLS_ASSERT(rank == 3);
    hsize_t dims[3];
    dataspace.getSimpleExtentDims(dims, NULL);

    hsize_t N0 = dims[0], N1 = dims[1], N2 = dims[2];
	a.resize(N0/2, N1, N2);

    hsize_t col_dims[1] = {N0};
    hsize_t stride[3] = {1, 1, 1};
    hsize_t count[3] = {N0, 1, 1};
    hsize_t block[3] = {1, 1, 1};
    hsize_t offset_out[1] = {0};
    DataSpace memspace(1, col_dims);

    for (hsize_t k = 0; k < N2; ++k) {
        for (hsize_t j = 0; j < N1; ++j) {
            hsize_t start[3] = {0, j, k};
            dataspace.selectHyperslab(H5S_SELECT_SET, count, start, stride, block);
            memspace.selectHyperslab(H5S_SELECT_SET, col_dims, offset_out);
            dataset.read((Doub *)&a(0, j, k), PredType::NATIVE_DOUBLE, memspace, dataspace);
        }
    }
}

// write sparse matrix as a dense matrix
// write elements one by one (including 0 elements)
inline void save(McooDoub_I a, Str_I name, H5File &file)
{
	hsize_t N0 = a.n0(), N1 = a.n1();
	hsize_t dims[2] = {N0, N1};
	DataSpace dataspace(2, dims);
	DataSet dataset = file.createDataSet(name, PredType::NATIVE_DOUBLE, dataspace);
	hsize_t stride[2] = {1, 1};  // Stride of hyperslab
	hsize_t count[2] = {1, 1};   // Block count
	hsize_t block[2] = {1, 1};   // Block sizes
	DataSpace memspace(2, block);

	for (size_t i = 0; i < N0; ++i) {
		for (size_t j = 0; j < N1; ++j) {
			Doub val = a(i, j);
			hsize_t start[2] = {i, j}; // Start of hyperslab
			dataspace.selectHyperslab(H5S_SELECT_SET, count, start, stride, block);
			dataset.write(&val, PredType::NATIVE_DOUBLE, memspace, dataspace);
		}
	}
}

// write sparse matrix as a dense matrix
inline void save(CmobdDoub_I a, Str_I name, H5File &file)
{
	hsize_t N0 = a.n0(), N1 = a.n1();
	hsize_t dims[2] = {N0, N1};
	DataSpace dataspace(2, dims);
	DataSet dataset = file.createDataSet(name, PredType::NATIVE_DOUBLE, dataspace);
	hsize_t stride[2] = {1, 1};  // Stride of hyperslab
	hsize_t count[2] = {1, 1};   // Block count
	hsize_t block[2] = {1, 1};   // Block sizes
	DataSpace memspace(2, block);

	for (size_t i = 0; i < N0; ++i) {
		for (size_t j = 0; j < N1; ++j) {
			Doub val = a(i, j);
			hsize_t start[2] = {i, j}; // Start of hyperslab
			dataspace.selectHyperslab(H5S_SELECT_SET, count, start, stride, block);
			dataset.write(&val, PredType::NATIVE_DOUBLE, memspace, dataspace);
		}
	}
}

// save a string
inline void save(Str_I str, Str_I name, H5File &file)
{
	DataSpace dataspace(H5S_SCALAR);
	H5::StrType datatype(PredType::C_S1, H5T_VARIABLE);
	DataSet dataset = file.createDataSet(name, datatype, dataspace);
	dataset.write(str, datatype);
}

inline void load(Str_O str, Str_I name, H5File &file)
{
    DataSet dataset = file.openDataSet(name);
    H5::StrType datatype(PredType::C_S1, H5T_VARIABLE);
    DataSpace dataspace = dataset.getSpace();
    dataset.read(str, datatype, dataspace);
}

} // namespace slisc
#endif
