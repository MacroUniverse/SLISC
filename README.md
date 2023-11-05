# SLISC
* Scientific Library in Simple C++, using code generation instead of non-trivial `template`s
* Matlab/Octave is used for code generation (see `## Code generation`)
* For the original project using template see [SLISCt](https://github.com/MacroUniverse/SLISCt)
* For a Chinese introduction, see [here](https://wuli.wiki/online/SLISC.html)
* As of 2023/11/2, there are about 68500 lines of hand written code (not including 3rd party and code generation).

## Introduction

SLISC is a header-only c++11 library written in a style similar to Numerical Recipes 3ed, using simple C++ features so that it is easy to read, debug and modify while maintaining a relatively high performance. The library currently provides simple classes for vector, matrix (row-major and column-major, fixed-size and sparse), 3- and 4-D arrays (column-major), and basic arithmetics for them. Many kinds of viewing classes are supported. Code from many other projects or libraries has been incorporated (e.g. Numerical Recipes, Boost, Eigen, Intel MKL etc. , which might not be header-only), and Macros can be defined to turn them on or off. The library also provides some utilities frequently used, such as timers and IO utilities (a text based file format `.matt` similar to Matlab's `.mat`, and a corresponding binary format `.matb`).

SLISC has a comprehensive test suit, `main.cpp` will execute all the tests. Tests has been performed on Linux using g++, clang++ and Intel compiler. Note that this is a project in development, interfaces are subjected to change and not all parts are working.

A simple example:

```cpp
#include "SLISC/arithmetic.h"
#include "SLISC/disp.h"
#include "SLISC/cut.h"
#include "SLISC/matb.h"
int main()
{
	using namespace slisc;

	// === vector and matrix ===
	VecDoub u(3), v(3); // vectors with 3 elements, double precision
	linspace(u, 0, 2); // elements linearly spaced from 0 to 2
	cout << "u = \n"; disp(u); // display vector/matrix
	copy(v, 3.14); // set all elements to 3.14
	copy(u, v); // copy values from v to u
	u += v; // add vector to vector
	v += 2; // add scalar to vector
	CmatDoub a, b(2, 3); // column major matrices of double precision
	a.resize(2, 3); // resize a to 2 rows and 3 columns
	a(0, 0) = 1.1; // access element by row and column indices
	a[3] = 9.9; // access element by a single index
	a.end() = 5.5; a.end(2) = 4.4; // access last element and last but 2 element
	cout << "a has " << a.n0() << " rows and " << a.n1()
	<< " columns, and a total of " << a.size() << " elements." << endl;
	disp(a); // display

	// === view types ===
	SvecDoub bs = cut0(b, 0); // get a view of 1st column of b
	bs[0] += 1; // view can be modified, and used just like a normal vector/matrix
	Doub s2 = sum(bs); // sum of bs
	DvecDoub bd = cut1(b, 1); // get a view of 2nd row of b
	bd = cut1(b, 0, 1, 2); // get a view from b(0,1) to b(0,2)
	copy(cut1(b, 0), cut1(b, 1)); // copy 2nd row of b to 1st row

	// === file IO ===
	save_matb(b, "b", "data0.matb"); // save a matrix to a binary file
	// create a binary file to save multiple scalars/vectors/matrices
	Matb matb("data.matb", "w");
	save(u, "u", matb); save(v, "v", matb);
	save(a, "a", matb); save(b, "b", matb);
	matb.close();
}
```

SLISC has a modular design like the Standard Template Library. Just include any header file(s) in the `SLISC/` folder. All definitions have namespace `slisc`.

## Installing Optional Dependencies
Depending on the compilation options, `CBLAS`, `LAPACKE`, `MKL`, `Boost`, `GSL`, `Eigen`, `Arpack`, `Arb`, `MPLAPACK`, `Matfile` (see my `Matfile_linux` repo), `SQLite` etc. might be used.

`Octave` 4.2 (4.0 works but is slower) or higher is needed for code generation. If you don't want to install `Octave`, just `touch SLISC/*.h` before `make`, you only need to do this one time. Run `make h` to generate the header code with `octave`.

### Using precompiled binaries or dockerfiles (recommended)
* All dependent libraries for x86-64 for different linux distros are already precompiled, see, e.g. [Ubuntu22.04](https://github.com/MacroUniverse/SLISC-libs-x64-ubuntu22.04) and [CentOS7.9](https://github.com/MacroUniverse/SLISC-libs-x64-centos7.9.2009). Check your Ubuntu version with `lsb_release -a`. These binaries are compiled with docker using `docker/*-build-*.dockerfile`. Note that Ubuntu16.04 is not fully supported (missing MPLAPACK)
* Use `source setup.sh` to add header and library paths to environment variables. You can add this command to `~/.bashrc` so it will run everytime you login.
* See also `docker/ubuntu*-portable.dockerfile` to build docker images.

### Install with apt
```bash
apt -y update && apt -y upgrade
apt install -y vim git make g++ gdb gfortran libarpack++2-dev liblapacke-dev libsqlite3-dev libgmp-dev libflint-arb-dev libflint-dev libgsl-dev libboost-filesystem-dev
apt purge -y libopenblas*
```
See also `docker/ubuntu*-apt.dockerfile` to build docker images.

## Building SLISC
To build with `Makefile`:
```bash
cd SLISC
touch SLISC/*.h
make [options] [-j8]
```
* `-j8` option is to compile with 8 thread in parallel, you can choose other numbers to.
* For `[options]`, first try `opt_min=true` to compile with minimum dependency. For a full list of options and default values, see `make/all.mak`. You can also directly modify the values in the file.
* Changing options `opt_long32` and `opt_quadmath` will require header regeneration with `make h` (requires Octave). For convenience, the generated headers by `make opt_long32=false, opt_quadmath=true h` are stored in `SLISC-64q`. Use `cp SLISC-64q/*h SLISC` if you don't want to regenerate.
* Also supports CMake (not all options supported, recommend Makefile) and partially suport Visual Studio project file, tested with g++8.3, g++11.2, clang-10, in Ubuntu 16.04-22.04, CentOS 7.9 and Windows WSL, MYSYS2.
* Makefile provides multiple options, uncomment one line to enable. The future plan is to merge all of the `make/*.mak` files into one (currently called `make/all.mak`).
* To recompile just one test, use `make [options] test_xxx.o link`, where `test_xxx` is one of the file names in the `test` folder.
* Use `./main.x < input.inp` to run all tests. Use `./main.x <test>` to run 1 test.

## Recommended Programming Style
* Only very trivial templates and classes should be used for code readability. Code generation should be used in place of complex templates and classes.
* Function overloading should be preferred over class members functions.
* Avoid using unsigned integer types when possible. They are not supported by the library for now. Use `size(std::vector<>)` in `arithmetic.h` instead of `vector::size()` when needed.
* All SLISC containers types (e.g. `MatComp`, `VecDoub`) should be returned by reference as a parameter of a function.
* Generally, function output arguments can not be any of the input arguments (this is called aliasing), unless this function is element-wise.
* Intrinsic types are renamed inside the library. For example, `bool` is `bool`, `Int` is 32-bit integer, `Doub` is `double` (64-bit); `Comp` is `std::complex<Doub>`. `Llong` is `long long`.
* A type with `_I` suffix is the `const` or `reference to const` version of that type, used in function parameter declarations to indicate an input argument. Similarly, `_O` means output (reference type), `_IO` means both input and output (reference type). Note that a reference to an `_O` or `_IO` types is still a reference type.

## Headers Introduction
When using something in any header file, just including that header file will be enough. Header files can be included in any order. Here is some brief introduction for each header file:
* `global.h` has all the common macros and `typedef` etc.
* `Bit.h` defines utilities for single-bit operations, and a pointer class for bit
* `complex_arith.h` defines extra operators used by `std::complex<>`, such as  `+, -, *, /, +=, -=, *=, /=, ==, !=` for mixed complex types.
* `imag.h` defines a pure imaginary number types `Fimag` (`float`), `Imag` (`double`), and `Limag` (`ldouble`).
* `quad_math.h` C++ extension to `quadmath.h`, for 128-bit floating point numbers.
* `scalar_arith.h` defines scalar utilities such as `min()`, `max()`, `sqr()`, `isodd()`, `mod()`.
* `Vbase.h` defines a base class `Vbase*` for dense containers, do not directly use this.
* `Vec.h` defines the 1d containers `Vec*`, e.g. `VecInt`, `VecDoub`, `VecComp` etc.
* `Cmat.h` defines the col-major matrix container `Cmat*` (col-major containers are recommended).
* `Mat.h` defines the row-major matrix container `Mat*` (row-major containers are less supported).
* `Cmat3.h` defines the col-major 3D array `Cmat3`.
* `Mat3.h` defines the row-major 3D array `Mat3*`.
* `disp.h` display containers in console.
* `arithmetic.h` has utilities for dense matrices and vectors, e.g. `sum()`, `norm()`, dot product, matrix-vector multiplication.
* `compare.h` compare shape and values of containers
* `copy.h` copy and assignment for containers
* `cut.h` matrix view utilities, e.g. slicing one column of a matrix to pass into a function that accepts a vector.
* `Svec.h` contiguous vector view
* `Dvec.h` vector view with fixed step
* `Scmat.h` contiguous matrix view (col-major)
* `Dcmat.h` matrix view with leading dimension (col-major)
* `Scmat3.h` contiguous 3D matrix view
* `random.h` random number utilities
* `time.h` timing utilities, including natural time and cpu time
* `sort.h` sorting utilities
* `search.h` search elements in containers
* `string.h` string utilities
* `unicode.h` unicode utilities
* `linux.h` linux system utilities
* `sha1sum.h` SHA1 checksum
* `input.h` promp for input, can save input history and repeat input automatically.
* `file.h` file IO utilities.
* `matt.h` save/load text-based data files in `.matt` format, can save multiple named scalars and containers to a single ascii text file. Use `matload.m` to load this file to Matlab.
* `matb.h` same as `matt.h`, for binary data files.
* `lin_eq.h` solving linear equations
* `ludcmp.h` LU decomposition
* `linbcg.h` bi-conjugate solver for linear equations (supports sparse matrix)
* `svd.h` singlar value decomposition
* `eig.h` calculate matrix eigen values/vectors
* `fft.h` fourier transforms
* `interp1.h` 1 dimensional interpolation
* `interp2.h` 2 dimensional interpolation
* `sparse_arith.h` basic arithmetics for sparse matrices
* `band_arith.h` basic arithmetics for band matrices
* `tree.h` tree algorithm
* `Cband.h` column-major band matrix
* `Mcoo.h` COO sparse matrix
* `Diag.h` diagonal matrix
* `mat_fun.h` functions of square matrix
* `legendreP.h` Legendre polynomial
* `ylm.h` (generalized) spherical harmonics
* `anglib.h` has functions for Clebsch-Gordan coefficients, 3j, 6j, and 9j symbols.
* `hypergeom.h` hypergeometric functions
* `coulomb.h` calculates coulomb functions (F, G, H), and their derivatives.
* `fedvr.h` utilities for Finite Element Discrete Variable Representations, could be used to solve TDSE.
* `Cmobd.h` a special sparse matrix type for `FEDVR` algorithm
* `mparith.h` for arbitrary precision calculation
* `lanczos.h` Lanczos algorithm to calculate matrix exponential
* `expokit.h` calculate matrix exponential (translated from a Fortran lib)

## "global.h"

### Scalar Types
`bool` is `bool`, `Char` is `char`, `Int` is 32-bit integer, `Llong` is 64-bit integer; `Float` is `float`, `Doub` is `double` (64-bit); `Comp` is `std::complex<Doub>`; `Ldoub` is `long double`; `Long` `Long` is used as vector/matrix indices variables, and is `Llong` by default, define `SLS_USE_INT_AS_LONG` macro to use `Int` as `Long`.
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
* `n0(), n1()`: return number of rows or columns.
* `operator[](i), operator()(i)` : return a reference for the i-th element.
* `operator()(i,j), (i,j,k)` : return a reference for an element.
* `end()` : return a reference for the last element.
* `operator<<` : transfer data to another container.
* `step1(), step2(), etc` : step size for each dimension of vector/matrix, e.g. for dense vector, `step1()` is 1, for matrix, "leading dimension" is step2().
* TODO...

### Vector Class

Constructors: Vector() for default, Vector(Long_I n) for vector size, Vector(Long_I n, const T &a) to specify element as well, Vector(Long_I n, const T *a) to initialize from array.

`operator=` : all forbidden, use `copy()` to copy, function arguments should be passed by reference.

`operator[]` : for vector, get a reference for the i-th element; for matrix, return a pointer for the second index.

`resize(Long_I)` : resize vector, contents are not preserved. resize() does nothing if size doesn't change.

`resize_cpy(Long_I)` : resize vector, contents are preserved, new elements are set to 0.

## "Mat.h"
Methods are similar to that of vector class. Matrix is row-major only. 

TODO.

## "Mat3.h"
Methods are similar to that of vector class. Mat3d is row-major only.

TODO.

## "cut.h"
`Svector` does not have it's own allocated memory, but use a block of contiguous memory from other dense containers (this is called slicing or view). For example, if we need to calculate the sum of a column of a `Cmat`, we can create an `Svector` to represent one column of `Cmat`, then use it as input to `sum()` function.

### Vector/Matrix Types
The vector/matrix classes are (each type also comes with `_I`, `_O`, and `_IO` versions) :  VecInt, VecUint, VecLlong, VecUllong, VecChar, VecUchar, VecDoub, VecComp, VecBool, MatInt, MatUint, MatLlong, MatUllong, MatChar, MatUchar, MatDoub, MatComp, MatBool, Mat3Doub, Mat3Comp.

Note that `VbaseBool`, `VecBool`, `CmatBool` are based on `std::vector<bool>` which usually manipulates bits for memory optimization. `p()` is not implemented (underlying data might not be consecutive), non-const `operator[]` will return `xxx::ref` type, and const `operator[]` will return `bool` by value.

## arithmetics.h
* includes basic arithmatics like `==`, `+=`, `*=`, `add()`, `sub()`, etc. for containers.
* Operators `+, -, *, /, +=, -=, *=, /=` are only for container types element-wise operations.

## disp.h
includes various overloaded "disp()" functions.

## file.h
* `void file_list(vecStr_O names, Str_I path)` list all the files in a folder
* `void read(ifstream &fin, Str_O str)` reads `str.size()` characters from `ifstream`, `str` will be resized if end if file reached before finishing.
* `void write(ofstream &fout, Str_I str)` writes str into `ofstream`
* `bool file_exist(Str_I fname, Bool_I case_sens = true)` will check if file exists.
* `void file_remove(Str_I fname)` will remove a file
* `bool dir_exist(Str_I path)` will test if a directory exist
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
* `bool little_endian()` test if system use little endian (less significant byte has smaller memory address)
* `void change_endian(Char *data, Long_I elm_size, Long_I Nelm)`, convert endianness

## time.h
time utilities

```c++
// all in seconds.
void Timer::tic()
Doub Timer::toc()
void CPUTimer::tic()
Doub CPUTimer::toc()
```

## "scalar_arith.h"

```c++
Int isodd(Int n) // return 1 if n is odd, return 0 otherwise
bool ispow2(Int n) // if n is a power of 2 or 0
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

## unicode.h
* Conversion between utf-8, 16 and 32, and windows ANSI etc.
* don't mess with `locale`
* don't use `wchar_t`, use `char32_t` (`u32string`) instead as the only data type for unicode
* Use `u8"..."` for `UTF-8` literal
* Use `U"..."` for `UTF-32` literal
* for display, convert everything to `string` with `UTF-8` encoding, then use `cout`
* Visual Studio does not support `UTF-8` source file without `BOM`, `u8"..."` will fail (`compiler error: newline in literal`). Add `BOM` for files with unicode.
* TODO: `BOM` must be removed for linux compilation, this can be done automatically with Makefile.
* `UTF-32` character lookup and convertion to `UTF-8` http://tools.jb51.net/transcoding/decode_encode_tool

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
void add(out, in, in) //for scalar/vec/mat, whenever make sense.
void sub(out, in, in) // binary "-" operator
void neg(in_out) // unary "-" operator
void sub(out, in)
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
* the read in value type T2 can be different from the written value type T1, if T1 can be losslessly converted to T2
* there is a Matlab function `save()` that works similar to `load()` to read this file into Matlab workspace. This reading subroutine can be easily implemented for any other language.
* Matrices are stored in column major order. Memory access speed is negaligible comparing to hard-drive.

**implementation**
* every variable/matrix has several parts: length of name, every character of name in ascii, type number (defined in meta.h), dimension of matrix (i.e. number of idices), leng of each dimension, list of elements in column major
* at the end of file, there is a list of position (character number) of the start of every variable, and finally, the number of variables

## Related Projects
* See cuSLISC project for a GPU version of SLISC using CUDA.
* See MatFile project for saving and reading "Vector" or "Matrix" to/from Matlab data file ".mat", or text based file ".matt".

## Internal Coding Rules
* Code should be easy to understand and modify.
* Interface and implementation should separated.
* Class members variables should start with `m_` for clearity, and avoid name confliction with member function arguments.
* Use SFINAE macro `SLISC_IF(bool)` to limit template instanciation.
* Templates must work for all possible instanciations.
* Default constructors must be `protected` and empty, so that it can be most efficient, and can be used as GPU global variable. However, `new` or `std::vector` will require the default constructor. Also, the destructor will give an error when deleting an uninitialized container. I'll keep it this way for now, and think about it later.
* use `m_N` to determin if `delete[]` should be used, never set `m_p` to `nullptr`.

## TODO
* `file_move()` should use system specific method to implement instead of copy and delete
* consider replacing `error()` macro with `throw()`
* incorporate "arb" library for evaluation of some special functions, and for multi-precision arithmetic (does not work for windows yet)
* put all internal names into "slisc::internal" namespace
* test `randInt()`
* update from Go-Solver project
* pointer arith functions must support N = 0
* test "meta.h" for ImagNum<T> types
* modify "meta.h" so that `Svector` could be used as function arguments without casting to `Vector` first.
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
//% tem('add', {
//%  'vector<double>', 'Int', 'vector<float>';
//%  'vector<complex<double>>', 'vector<complex<double>>', 'vector<Int>';
//% });
//%----------------------------------
//% [Tz, Tx, Ty] = varargin{:};
void add(@Tz@ &z, const @Tx@ &x, const @Ty@ &y)
{
//% if is_vec(Tz) && is_vec(Tx) && is_scalar(Ty)
	for (size_t i = 0; i < z.size(); ++i)
		z[i] = x[i] + y;
//% elseif is_vec(Tz) && is_scalar(Tx) && is_vec(Ty)
	for (size_t i = 0; i < z.size(); ++i)
		z[i] = x + y[i];
//% elseif is_vec(Tz) && is_vec(Tx) && is_vec(Ty)
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

void add(vector<double> &z, const Int &x, const vector<float> &y)
{
	for (size_t i = 0; i < z.size(); ++i)
		z[i] = x + y[i];
}

void add(vector<complex<double>> &z, const vector<complex<double>> &x, const vector<Int> &y)
{
	for (size_t i = 0; i < z.size(); ++i)
		z[i] = x[i] + y[i];
}
```
