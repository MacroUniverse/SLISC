# SLISC0
* Simple Scientific Library in Simple C++, without using `template`s
* Matlab/Octave is used to do code generation (see `## Code generation`)

## Introduction

SLISC is a header-only library written in a style similar to Numerical Recipes 3ed, using simple C++ features so that it is easy to read and modify while maintaining a relatively high performance. The library currently provides simple class templates for vector, matrix (row-major and col-major, fixed-size and sparse), 3- and 4-D matrix (row-major), and basic arithmetics for them. Codes from some other projects or libraries has been incorporated (e.g. Numerical Recipes, Eigen, Intel MKL etc.). The library also provides some utilities frequently used, such as timers and IO utilities (a text based file format `.matt` similar to Matlab's `.mat`, and a corresponding binary format `.matb`).

SLISC has a comprehensive test suit, `main.cpp` will execute all the tests. Tests has been performed in Linux using g++ and GSL and LAPACK. It can also work for Interl compiler and MKL. Note that this is a project in development, interfaces are subjected to change and not all parts are working.

A simple example :

```cpp
#include "SLISC/algorithm.h"
#include "SLISC/disp.h"
int main()
{
	using namespace slisc;
	VecDoub u(3), v(3); // vectors, double type
	linspace(u, 0, 2); // elements linearly spaced from 0 to 2
	cout << "u = \n"; disp(u); // display vector/matrix
	v = 3.14; // set all elements to 3.14
	u += v; // vector plus vector
	v += 2; // vector plus scalar
	MatDoub a(0, 0), b(2, 3); // row major matrices of double precision
	a.resize(2, 3); // resize b to 2 columns and 3 rows
	a(0, 0) = 1.1; // access element by row and column indices
	a[3] = 9.9; // access element by a single index
	a.end() = 5.5; // last element
	cout << "a has " << a.n1() << " rows and " << a.n2()
	<< " columns, and a total of " << a.size() << " elements." << endl;
	disp(a);
}
```

SLISC has a modular design like the Standard Template Library. Just include any header file(s) in the `SLISC/` folder. All definitions have namespace `slisc`.

## Compiling
* All code using C++11 standard, tested with g++8.3 (earlier version might not work), octave 4.2 (4.0 works but is slower), in Ubuntu 16.04 & 18.04
* If you don't want to use external libraries, uncomment the first `include` in `Makefile`, and comment the others. Some functions will not be available, some others will run slower.
* If you want to use everything, make sure you have `liblapacke-dev` and `liggsl-dev` installed (use `apt install`), then use the second `include` in `Makefile`.
* In the root directory, run `make` to compile
* If you don't want to install octave, just `touch SLISC/*.h` before `make`, you only need to do this one time
* Use `./main.x` to run all tests.

## Recommended Programming Style
* All SLISC containers types (e.g. `MatComp`, `VecDoub`) should be returned by reference.
* Avoid using unsigned integer types when possible. They are not supported by the library for now. Use `size(std::vector<>)` in `arithmetic.h` instead of `vector::size()` when needed.
* Generally, functions output arguments can not be any of the input arguments (this is called aliasing), unless this function is element-wise.

* Intrinsic types are aliased inside the library. For example, `Bool` is `bool`, `Int` is 32-bit integer, `Doub` is `double` (64-bit); `Comp` is `std::complex<Doub>`. `Llong` is `long long`.

* A type with `_I` suffix is the `const` or `reference to const` version of that type, used in function parameter declarations to indicate an input argument. Similarly, `_O` means output (reference type), `_IO` means both input and output (reference type). Note that a reference to an `_O` or `_IO` types is still a reference type.

## Headers Introduction
When using something in any header file, just including that header file will be enough. Header files can be included in any order. Here is some brief introduction for each header file:
* `slisc.h` includes all the header files in SLISC (except testing)
* `global.h` has all the container declaration and typedef etc.
* `Bit.h` defines utilities for single-bit operations, and a pointer for bit
* `complex_arith.h` defines extra operators used by `std::complex<>`, such as  `+, -, *, /, +=, -=, *=, /=, ==, !=` for mixed complex types.
* `imag.h` defines a pure imaginary number types `Fimag` (`float`), `Imag` (`double`), and `Limag` (`ldouble`).
* `scalar_arith.h` defines scalar utilities such as `min()`, `max()`, `sqr()`, `isodd()`, `mod()`.
* `Vbase.h` defines a base class `Vbase*` for dense containers, do not directly use this.
* `Vec.h` defines the 1d containers `Vec*`, e.g. `VecInt`, `VecDoub`, `VecComp` etc.
* `Mat.h` defines the row-major matrix container `Mat*`.
* `Cmat.h` defines the col-major matrix container `Cmat*`.
* `Mat3.h` defines the row-major 3D array `Mat3*`.
* `Cmat3.h` defines the col-major 3D array `Cmat3`.
* `disp.h` display containers in console.
* `input.h` promp for input, can save input history and repeat input automatically.
* `file.h` file IO utilities.
* `matt.h` save/load text-based data files in `.matt` format, can save multiple named scalars and containers to a single ascii text file. Use `matload.m` to load this file to Matlab.
* `matb.h` same as `matt.h`, for binary data files.
* `arithmetic.h` has utilities for dense matrices and vectors, e.g. `sum()`, `norm()`, dot product, matrix-vector multiplication.
* `slice.h` matrix slicing, e.g. slice one column of a matrix to pass into a function that accepts a vector.
* `random.h` random number utilities
* `time.h` timing utilities, including natural time and cpu time
* `sort.h` sorting utilities
* `search.h` search elements in containers
* `string.h` string utilities
* `svd.h` for singlar value decomposition
* `eig.h` calculate matrix eigen values/vectors
* `fft.h` for fourier transforms
* `interp1.h` for 1 dimensional interpolation
* `interp2.h` for 2 dimensional interpolation
* `ludcmp.h` for LU decomposition
* `sparse.h` defines the sparse square diagonal matrix `Diag<T>`, COO sparse matrix `MatCoo<T>`, COO sparse Hermitian matrix `MatCooH<T>`, and basic arithmetics.
* `mat_fun.h` functions of square matrix
* `anglib.h` has functions for Clebsch–Gordan coefficients, 3j, 6j, and 9j symbols.
* `coulomb.h` calculates coulomb functions (F, G, H), and their derivatives.
* `fedvr.h` utilities for Finite Element Discrete Variable Representations, could be used to solve TDSE.
* `mparith.h` for arbitrary precision calculation
* `expokit.h` calculate matrix exponential

* TODO...

## "global.h"

### Scalar Types
`Bool` is `bool`, `Char` is `char`, `Int` is 32-bit integer, `Llong` is 64-bit integer; `Float` is `float`, `Doub` is `double` (64-bit); `Comp` is `std::complex<Doub>`; `Ldoub` is `long double`; `Long` `Long` is used as vector/matrix indices variables, and is `Llong` by default, define `SLS_USE_INT_AS_LONG` macro to use `Int` as `Long`.
TODO...

### Constants
```cpp
const Doub PI = 3.14159265358979323;
const Doub E  = 2.71828182845904524;
const Comp I(0., 1.);
```

TODO...

## "Vec.h"

### Common Members for Vector, Matrix, Mat3d Templates
* `size()`: return total number of elements.
* `n1(), n2()`: return number of rows or columns.
* `operator[][i], operator()(i)` : return a reference for the i-th element.
* `operator()(i,j), (i,j,k)` : return a reference for an element.
* `end()` : return a reference for the last element.
* `operator<<` : transfer data to another container.
* `step1(), step2(), etc` : step size for each dimension of vector/matrix, e.g. for dense vector, `step1()` is 1, for matrix, "leading dimension" is step2().
* TODO...

### Vector Class Template

Constructors: Vector() for default, Vector(Long_I n) for vector size, Vector(Long_I n, const T &a) to specify element as well, Vector(Long_I n, const T *a) to initialize from array.

`operator=` : Copy-assignment operator, self-assignment is forbidden. The right hand side can be a scalar.

`operator[]` : for vector, get a reference for the i-th element; for matrix, return a pointer for the second index.

`resize(Long_I)` : resize vector, contents are not preserved. resize() does nothing if size doesn't change.

`resize(Vector<> v)` : resize to the same size of v

## "Mat.h"
Methods are similar to that of vector class. Matrix is row-major only. 

TODO.

## "Mat3.h"
Methods are similar to that of vector class. Mat3d is row-major only.

TODO.

## "slice.h"
`Svector<>` inherits `Vector<>` and thus can be casted to a vector when input to a function. `Svector` does not have it's own allocated memory, but use a block of contiguous memory from other dense containers (this is called slicing). For example, if we need to calculate the sum of a column of a `Cmat`, we can create an `Svector` to represent one column of `Cmat`, then use it as input to `sum()` function (need to cast to `Vector<>` first, unless `sum()` accepts `Svector` directly).

### Vector/Matrix Type Alias
The typedefs for vector/matrix classes are (each type also comes with "_I", "_O", and "_IO" versions) :  VecInt, VecUint, VecLlong, VecUllong, VecChar, VecUchar, VecDoub, VecComp, VecBool, MatInt, MatUint, MatLlong, MatUllong, MatChar, MatUchar, MatDoub, MatComp, MatBool, Mat3Doub, Mat3Comp.

Note that `VbaseBool`, `VecBool`, `CmatBool` are based on `std::vector<bool>` which usually manipulates bits for memory optimization. `ptr()` is not implemented (underlying data might not be consecutive), non-const `operator[]` will return `xxx::ref` type, and const `operator[]` will return `Bool` by value.

## arithmetics.h
* includes basic arithmatics like "==", "+=", "*=", plus(), minus(), etc.
* Operators `+, -, *, /, +=, -=, *=, /=` are only for container types element-wise operations.

## disp.h
includes various overloaded "disp()" functions.

## file.h
* `void file_list(vecStr_O names, Str_I path)` list all the files in a folder
* `void read(ifstream &fin, Str_O str)` reads `str.size()` characters from `ifstream`, `str` will be resized if end if file reached before finishing.
* `void write(ofstream &fout, Str_I str)` writes str into `ofstream`
* `Bool file_exist(Str_I fname, Bool_I case_sens = true)` will check if file exists.
* `void file_remove(Str_I fname)` will remove a file
* `Bool dir_exist(Str_I path)` will test if a directory exist
* `void mkdir(Str_I path)` will create a directory recursively
* `void rmdir(Str_I path)` will remove a directory if it's empty
* `void ensure_dir(Str_I dir_or_file)` will create a directory if it does not exist
* `void file_rm(Str_I wildcard_name)` will delete a file
* `void file_ext(vecStr_O fnames_ext, vecStr_I fnames, Str_I ext, Bool_I keep_ext = true)` choose files with a given extension from a list of files
* `file_list_ext(vecStr_O fnames, Str_I path, Str_I ext, Bool_I keep_ext = true)` list all files in current directory, with a given extension
* `void file_copy(Str_I fname_out, Str_I fname_in, Bool_I replace = false)` copy a file (read then write), use default fstream buffer, not sure about performance
* `void file_copy(Str_I fname_out, Str_I fname_in, Str_IO buffer, Bool_I replace = false)` file copy with user buffer (larger buffer is faster)
* `void file_move(Str_I fname_out, Str_I fname_in, Bool_I replace = false)` move a file (copy and delete)
* `void file_move(Str_I fname_out, Str_I fname_in, Str_IO buffer, Bool_I replace = false)` file_move() with user buffer
* `Long file_size(Str_I fname)` get number of bytes in file, return -1 if file not found
* `void open_bin(ofstream &fout, Str_I fname)` open binary file to write
* `void open_bin(ifstream &fin, Str_I fname)` open binary file to read
* `void write(const Char *data, Long_I Nbyte, Str_I fname)` write binary file (once)
* `Long read(Char *data, Long_I Nbyte, Str_I fname)` read binary file (once), return the actual bytes read
* `void write(Str_I str, Str_I fname)` write Str to file
* `void read(Str_O str, Str_I fname)` read whole file to Str
* `void write(ofstream &fout, *_I s)` and `void read(ifstream &fin, *_O s)`, where `*` is a supported scalar type. This will read/write binary data from/to a file.
* `void write(ofstream &fout, Str32_I str)` and `void read(ifstream &fin, Str32_O str)` are similar, for `utf-32` strings.
* `void read(CmatDoub_O mat, Str_I file, Long_I skip_lines = 0)` read a table from file, two numbers should be separated by space, skipt specific number of lines at the beginning, matrix will auto-resize, 0 to multiple spaces & new line at the end of file are allowed
* `void last_modified(Str_O yymmddhhmmss, Str_I fname)` last modified time fo a file
* `void set_buff(ofstream &fout, Str_IO buffer)`, set write buffer, can speed up if there are a lot of staggered short reading and writing in the same drive
* `Bool little_endian()` test if system use little endian (less significant byte has smaller memory address)
* `void change_endian(Char *data, Long_I elm_size, Long_I Nelm)`, convert endianness

## time.h
time utilities

```c++
// all times are in seconds.
void Timer::tic()
Doub Timer::toc()
void CPUTimer::tic()
Doub CPUTimer::toc()
```

## "scalar_arith.h"

```c++
Int isodd(Int n) // return 1 if n is odd, return 0 otherwise
Bool ispow2(Int n) // if n is a power of 2 or 0
operator +,-,*,/ between Complex and Int
```

## "disp.h"
```c++
void disp(av) // can also be used while debugging, because of this, default arguments are not allowed
void disp(v, start, n)
void disp(a, start1, start2, n1, n2)
void disp(a3, start1, start2, start3, n1, n2, n3)
void disp(..., precision)
```

If you want to use "disp()" in debugger, add "SLISC/print.cpp" to compiler and use "print()" with the same arguments.

## "arithmetic.h"

There is no automatic `resize()` inside functions in SLISC, for performance reason and for compatibility with fixed sized containers or container slicing. In `SLS_CHECK_SHAPES` is defined (in debug mode it's defined by default), shapes of matrix/vector will be checked.

### basic utilities
```cpp
s = sum(av) // sum of elements
s = max(av) // max of absolute values for complex mat/vec
s = max(ind, av) // also output the index
s = norm(v) // vec/mat norm
s = norm2(v) // vec/mat norm squared
```

### matrix manipulation
```cpp
void linspace(vec/mat, first, last, N = -1)
void trans(a) // matrix transpose
void her(a) // hermitian conjugate
void flip(Vector<T>)
void shift(Matrix<T> &a, const Int nshift, const Int dim = 1)
void diagonals(Matrix<T> &a) // shift the i-th line i times to the left, moving diagonals to columns
void idiagonals(Matrix<T> &a) // inverse of diagonals(), shift the i-th line i times to the right
```

## element-wise math functions

* `sin(v, v1)`, `cos(v, v1)`, `exp(v, v1)`, `tan(v, v1)`, etc.

## matrix arithmatics

```cpp
operator ==, != // compare size and each element, right hand side can also be a scalar.
operators +,-,*,/ scalar/vec/mat, whenever make sense (inefficient!).
operators +=,-=,*=,/= scalar/vec/mat, whenever make sense
void Plus(out, in, in) //for scalar/vec/mat, whenever make sense.
void Minus(out, in, in) // binary "-" operator
void Minus(in_out) // unary "-" operator
void Minus(out, in)
Times, Divide
void real(MatDoub_O &rc, MatComplex_I &c)
void imag(MatDoub_O &ic, MatComplex_I &c)
void abs(out, in), whenever make sense
void complex(VecComplex_O &y, VecDoub_I &x)
void conjugate(VecComplex_IO v)
s = v1*v2 // dot product, whenever make sense
void outprod(MatComplex_O &prod, VecComplex_I &v1, VecComplex_I &v2) // outer product
void mul(out, in, in) // mat-mat or mat-vec multiplications, whenever make sense
```

## "print.cpp"
For debug purpose only. Need to compile "print.cpp" along with the program.

"print()" are same as "disp()" except they can be called in debugger. To realize this, print() does not have any namespace, and cannot be inlined.

In gdb, things are a little more complicated, since gdb does not fully support function overloading, use "print2()" for 2 arguments, "print3()" for 3 arguments, etc.

## Calculus

```cpp
void integral(Vector<T> &F, const Vector<T> &f, Doub_I dx) // simple indefinite integration
```

## "fft.h"
```cpp
fftshift()
void dft(MatComplex_O &Y, Doub kmin, Doub kmax, Int Nk, MatComplex_I &X, Doub xmin, Doub xmax)
void idft(MatComplex_O &X, Doub xmin, Doub xmax, Int Nx, MatComplex_I &Y, Doub kmin, Doub kmax)
```

## String related
```cpp
template<typename T> inline Str num2str(T s) // mainly std::to_string(), but no trailing zeros.
```

## OpenMP functions
parallelized version of a function should always end with "_par"
```cpp
// arithmetic.h
template <class T, class T1, class T2, SLS_IF(is_dense_mat<T>() && is_Vector<T1>() && is_Vector<T2>())>
inline void outprod_par(T &v, const T1 &v1, const T2 &v2);

template <class T, class T1, class T2, SLS_IF(is_Vector<T>() && is_dense_mat<T1>() && is_Vector<T2>())>
inline void mul_par(T &y, const T1 &a, const T2 &x);

template <class T, class T1, class T2, SLS_IF(is_Vector<T>() && is_Vector<T1>() && is_dense_mat<T2>())>
inline void mul_par(T &y, const T1 &x, const T2 &a)

// arithmetic1.h
void diagonals_par(Matrix<T> &a);
void idiagonals_par(Matrix<T> &a);

// fft.h
void dft_par(MatComp_O Y, Doub kmin, Doub kmax, Long_I Nk, MatComp_I X, Doub xmin, Doub xmax);
void idft_par(MatComp_O &X, Doub xmin, Doub xmax, Long_I Nx, MatComp_I &Y, Doub kmin, Doub kmax);
```

## Matt File (.matt)
* .matt is a text based format that I designed to immitate Matlab's .mat file.
* can write many variables and matrices to a single file, with names.
* can find and read any number of stored variables/matrices from a file by name without scanning through the whole file (the overhead is negligible). Thus, reading a large file is fast.
* the read in value type T2 can be different from the written value type T1, if T1 can be losslessly converted to T2 (see `is_promo<T1,T2>()`).
* there is a Matlab function `save()` that works similar to `load()` to read this file into Matlab workspace. This reading subroutine can be easily implemented for any other language.
* Matrices are stored in column major order. Memory access speed is negaligible comparing to hard-drive.

### implementation
* every variable/matrix has several parts: length of name, every character of name in ascii, type number (defined in meta.h), dimension of matrix (i.e. number of idices), leng of each dimension, list of elements in column major
* at the end of file, there is a list of position (character number) of the start of every variable, and finally, the number of variables

## Related Projects
* See cuSLISC project for a GPU version of SLISC using CUDA.
* See MatFile project for saving and reading "Vector" or "Matrix" to/from Matlab data file ".mat", or text based file ".matt".

## Internal Coding Rules
* C++14/17 features used: `if constexpr`
* Code should be easy to understand and modify.
* Interface and implementation should separated.
* Class members variables should start with `m_` for clearity, and avoid name confliction with member function arguments.
* Use SFINAE macro `SLISC_IF(bool)` to limit template instanciation.
* Templates must work for all possible instanciations.
* Default constructors must be `protected` and empty, so that it can be most efficient, and can be used as GPU global variable. However, `new` or `std::vector` will require the default constructor. Also, the destructor will give an error when deleting an uninitialized container. I'll keep it this way for now, and think about it later.
* use `m_N` to determin if `delete[]` should be used, never set `m_p` to `nullptr`.

## TODO
* consider replacing `error()` macro with `throw()`
* incorporate "arb" library for evaluation of some special functions, and for multi-precision arithmetic (does not work for windows yet)
* put all internal names into "slisc::internal" namespace
* test `randInt()`
* update from Go-Solver project
* ptr_arith.h functions must support N = 0
* test "meta.h" for ImagNum<T> types
* modify "meta.h" so that `Svector` could be used as function arguments without casting to `Vector` first.
* change `ptr()` function to `data()` for containers, like `std::vector<>`
* `container.resize(container)` should support every possible container
* `operator=` for containers (and slice classes!) should work for any possible right hand side type
* matfile: consider storing complex array using the format of real array.

## Code generation
* Read this session if you want to read or modify the code

A template file (`demo.h.in`) looks like
```c++
#include <complex>
#include <vector>
using namespace std;

//% types = {
//%     'vector<double>', 'Int', 'vector<float>';
//%     'vector<complex<double>>', 'vector<complex<double>>', 'vector<Int>';
//% };
//%----------------------------------
//% [Tz, Tx, Ty] = varargin{:};
void plus(@Tz@ &z, const @Tx@ &x, const @Ty@ &y)
{
//% if is_vector(Tz) && is_vector(Tx) && is_scalar(Ty)
	for (size_t i = 0; i < z.size(); ++i)
		z[i] = x[i] + y;
//% elseif is_vector(Tz) && is_scalar(Tx) && is_vector(Ty)
	for (size_t i = 0; i < z.size(); ++i)
		z[i] = x + y[i];
//% elseif is_vector(Tz) && is_vector(Tx) && is_vector(Ty)
	for (size_t i = 0; i < z.size(); ++i)
		z[i] = x[i] + y[i];
//% else
//%     error('not implemented!');
//% end
}
//%-----------------------------------
```

Using `$octave auto_gen.m`, the generated file `demo.h` looks like
```c++
#include <complex>
#include <vector>
using namespace std;

void plus(vector<double> &z, const Int &x, const vector<float> &y)
{
	for (size_t i = 0; i < z.size(); ++i)
		z[i] = x + y[i];
}

void plus(vector<complex<double>> &z, const vector<complex<double>> &x, const vector<Int> &y)
{
	for (size_t i = 0; i < z.size(); ++i)
		z[i] = x[i] + y[i];
}
```

## TODO
* makefiles are not unified
* consider using selective codegen instead of removing all macros
