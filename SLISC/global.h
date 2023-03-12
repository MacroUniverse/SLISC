// every program that uses SLISC should include "global.h" first
#define SLS_VER_MAJOR 0
#define SLS_VER_MINOR 1
#define SLS_VER_PATCH 0

#pragma once
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#define SLS_FP_EXCEPT // turn on floating point exception
#define SLS_USE_UTFCPP // use utfcpp lib to convert utf8, 16 and 32

#ifndef NDEBUG
#define SLS_CHECK_BOUNDS
#define SLS_CHECK_SHAPES
#endif

// STL
#include <stdlib.h>
#include <math.h>
#include <cassert>
#include <cmath>
#include <climits>
#include <limits>
#include <cfloat>
#include <algorithm>
#include <iostream>
#include "quad_math_declare.h"
#include <complex>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdarg>
#include <utility>
#include <functional>
#include <tuple>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <array>

// compilers
#ifdef _MSC_VER
	#define SLS_USE_MSVC // using Microsoft Visual C++ compiler
#elif defined (__INTEL_COMPILER)
	#define SLS_USE_ICC // using Intel compiler (NOTE: __GNUC__ is also defined)
#elif defined(__GNUC__)
	#define SLS_USE_GCC // using GNU compiler
#endif

// platform
#if defined(__MINGW32__) || defined(__MINGW64__) || defined(__CYGWIN__) || defined(__MSYS__) || defined(_MSC_VER) || defined(_WIN32) || defined(_WIN64)
	#define SLS_USE_WINDOWS
#elif defined(__APPLE__)
	#define SLS_USE_MACOS
#else
	#define SLS_USE_LINUX
#endif

#ifdef SLS_USE_MKL
	#define MKL_Complex16 double _Complex
	#ifdef __GSL_CBLAS_H__
		#error include SLISC/global.h before any GSL headers
	#else
	    #define __GSL_CBLAS_H__
	#endif
	#ifdef __GSL_BLAS_TYPES_H__
		#error include SLISC/global.h before any GSL headers
	#else
		#define __GSL_BLAS_TYPES_H__
	#endif
	#ifdef SLS_USE_INT_AS_LONG
		#define MKL_INT int
	#else
		#define MKL_INT long long
	#endif
	#ifdef SLS_USE_INT_AS_LONG
		#define lapack_int int
	#else
		#define lapack_int long long
	#endif
	#include <mkl.h>
	#ifdef SLS_USE_GSL
		#include "my_gsl_blas_types.h"
	#endif
	#define SLS_USE_CBLAS
	#define SLS_USE_LAPACKE
#else
	#ifdef SLS_USE_CBLAS
		#ifdef __GSL_CBLAS_H__
			#error include SLISC/global.h becore any GSL headers
	    #else
	        #define __GSL_CBLAS_H__
	    #endif
		#ifdef SLS_USE_INT_AS_LONG
			#define CBLAS_INT int
		#else
			#define CBLAS_INT long long
		#endif
	    #include <cblas.h>
	#endif
	#ifdef SLS_USE_LAPACKE
		#ifdef SLS_USE_INT_AS_LONG
			#define lapack_int int
		#else
			#define lapack_int long long
		#endif
	    #include <lapacke.h>
	    #ifdef I // I is already defined in "/usr/include/complex.h"
	        #undef I
	    #endif
	#endif
#endif

// error handling
#define SLS_WARN(str) do{std::cout << "\033[1;31mWarning\033[0m: " << __FILE__ << ": line " << __LINE__ << ": \033[1;31m" << str << "\033[0m" << std::endl;} while(0)
#define SLS_ERR(str) do{std::cout << "\033[1;31mError\033[0m: " << __FILE__ << ": line " << __LINE__ << ": \033[1;31m" << str << "\033[0m" << std::endl; abort();} while(0)
#define SLS_FAIL SLS_ERR("failed!")
#define SLS_ASSERT(condition) if (!(condition)) SLS_FAIL

// my std extension
#include "quad_math.h"

#ifdef SLS_USE_MPLAPACK
#include "my_mplapack_utils__Float128.h"
#include <mplapack/mpblas__Float128.h>
#include <mplapack/mplapack__Float128.h>
#endif

namespace slisc {

// using std

using std::complex;
using std::vector; using std::string; using std::stringstream;
using std::to_string; using std::pair; using std::tuple;
using std::cin; using std::cout; using std::cerr; using std::endl;
using std::setw; using std::ifstream; using std::ofstream;
using std::min; using std::max; using std::swap; using std::reverse;
using std::numeric_limits; using std::unordered_set; using std::set;
using std::unordered_map; using std::map; using std::get;
using std::isinf; using std::round; using std::ceil; using std::floor;
using std::abs; using std::real; using std::imag; using std::array;
using std::conj; using std::pow; using std::priority_queue;
using std::sqrt; using std::sin; using std::cos; using std::tan;
using std::exp; using std::log; using std::log10;
using std::expm1; using std::log1p; using std::hypot;
using std::sinh; using std::cosh; using std::tanh;
using std::unordered_map; using std::unordered_set; using std::map;
using std::set; using std::deque; using std::queue; using std::stack;

// Scalar types

typedef char Char;
typedef const Char Char_I; // 8 bit integer
typedef Char &Char_O, &Char_IO;

typedef unsigned char Uchar;
typedef const Uchar Uchar_I;
typedef Uchar &Uchar_O, &Uchar_IO;

typedef short Short;
typedef const Short Short_I; // 16 bit integer
typedef Short &Short_O, &Short_IO;

typedef int Int;
typedef const Int Int_I; // 32 bit integer
typedef Int &Int_O, &Int_IO;

typedef const unsigned int Uint_I;
typedef unsigned int Uint;
typedef unsigned int &Uint_O, &Uint_IO;

#ifdef SLS_USE_MSVC
typedef __int64 Llong;
typedef unsigned __int64 Ullong;
#else
typedef long long int Llong;
typedef unsigned long long int Ullong;
#endif
typedef const Llong Llong_I; // 64 bit integer
typedef Llong &Llong_O, &Llong_IO;

typedef const Ullong Ullong_I;
typedef Ullong &Ullong_O, &Ullong_IO;

#ifdef SLS_USE_INT_AS_LONG
typedef Int Long;
#else
typedef Llong Long;
#endif
typedef const Long Long_I;
typedef Long &Long_O, &Long_IO;

typedef float Float;
typedef const Float Float_I; // default floating type
typedef Float &Float_O, &Float_IO;

typedef double Doub;
typedef const Doub Doub_I; // default floating type
typedef Doub &Doub_O, &Doub_IO;

typedef long double Ldoub;
typedef const Ldoub &Ldoub_I;
typedef Ldoub &Ldoub_O, &Ldoub_IO;

typedef complex<Float> Fcomp;
typedef const Fcomp &Fcomp_I;
typedef Fcomp &Fcomp_O, &Fcomp_IO;

typedef complex<Doub> Comp;
typedef const Comp &Comp_I;
typedef Comp &Comp_O, &Comp_IO;

typedef complex<Ldoub> Lcomp;
typedef const Lcomp &Lcomp_I;
typedef Lcomp &Lcomp_O, &Lcomp_IO;

typedef bool Bool;
typedef const Bool Bool_I;
typedef Bool &Bool_O, &Bool_IO;

// string type
typedef string Str;
typedef const Str &Str_I;
typedef Str &Str_O, &Str_IO;

typedef char32_t Char32;
typedef const Char32 Char32_I;
typedef Char32 &Char32_O, &Char32_IO;

typedef std::u32string Str32;
typedef const Str32 &Str32_I;
typedef Str32 &Str32_O, &Str32_IO;

typedef vector<Bool> vecBool;
typedef const vecBool &vecBool_I;
typedef vecBool &vecBool_O, &vecBool_IO;

typedef vector<Char> vecChar;
typedef const vecChar &vecChar_I;
typedef vecChar &vecChar_O, &vecChar_IO;

typedef vector<Int> vecInt;
typedef const vecInt &vecInt_I;
typedef vecInt &vecInt_O, &vecInt_IO;

typedef vector<Llong> vecLlong;
typedef const vecLlong &vecLlong_I;
typedef vecLlong &vecLlong_O, &vecLlong_IO;

#ifdef SLS_USE_INT_AS_LONG
typedef vecInt vecLong;
#else
typedef vecLlong vecLong;
#endif
typedef const vecLong &vecLong_I;
typedef vecLong &vecLong_O, &vecLong_IO;

typedef vector<Doub> vecDoub;
typedef const vecDoub &vecDoub_I;
typedef vecDoub &vecDoub_O, &vecDoub_IO;

typedef vector<Ldoub> vecLdoub;
typedef const vecLdoub &vecLdoub_I;
typedef vecLdoub &vecLdoub_O, &vecLdoub_IO;

typedef vector<Comp> vecComp;
typedef const vecComp &vecComp_I;
typedef vecComp &vecComp_O, &vecComp_IO;

typedef vector<Lcomp> vecLcomp;
typedef const vecLcomp &vecLcomp_I;
typedef vecLcomp &vecLcomp_O, &vecLcomp_IO;

typedef vector<Str> vecStr;
typedef const vecStr &vecStr_I;
typedef vecStr &vecStr_O, &vecStr_IO;

typedef vector<Str32> vecStr32;
typedef const vecStr32 &vecStr32_I;
typedef vecStr32 &vecStr32_O, &vecStr32_IO;

typedef vector<vector<Bool>> vvecBool;
typedef const vvecBool &vvecBool_I;
typedef vvecBool &vvecBool_O, &vvecBool_IO;

typedef vector<vector<Char>> vvecChar;
typedef const vvecChar &vvecChar_I;
typedef vvecChar &vvecChar_O, &vvecChar_IO;

typedef vector<vector<Int>> vvecInt;
typedef const vvecInt &vvecInt_I;
typedef vvecInt &vvecInt_O, &vvecInt_IO;

typedef vector<vector<Llong>> vvecLlong;
typedef const vvecLlong &vvecLlong_I;
typedef vvecLlong &vvecLlong_O, &vvecLlong_IO;

typedef vector<vector<Doub>> vvecDoub;
typedef const vvecDoub &vvecDoub_I;
typedef vvecDoub &vvecDoub_O, &vvecDoub_IO;

#ifdef SLS_USE_INT_AS_LONG
typedef vvecInt vvecLong;
#else
typedef vvecLlong vvecLong;
#endif
typedef const vvecLong &vvecLong_I;
typedef vvecLong &vvecLong_O, &vvecLong_IO;

// quiet NaN definition
// uncomment one of the following 3 methods of defining a global NaN
// you can test by verifying that (NaN != NaN) is true

//Uint proto_nan[2]={0xffffffff, 0x7fffffff};
//double NaN = *( double* )proto_nan;
//Doub NaN = sqrt(-1.);
static const Doub NaN = std::numeric_limits<Doub>::quiet_NaN();
// inline Bool isnan(Doub s)
// { return s != s; }

inline Bool isnan(Comp s)
{ return s != s; }

// Floating Point Exceptions for Microsoft compilers
// no exception for integer overflow
#ifdef SLS_FP_EXCEPT
#ifdef SLS_USE_MSVC
struct turn_on_floating_exceptions {
	turn_on_floating_exceptions() {
	    unsigned cw; _controlfp_s(&cw, 0, 0);
	    // also: EM_INEXACT, EM_UNDERFLOW
	    cw &= ~(EM_INVALID | EM_OVERFLOW | EM_ZERODIVIDE | EM_DENORMAL);
	    unsigned cw1; _controlfp_s(&cw1, cw, MCW_EM);
	}
};
// in case of ODR error, put this in main function;
// turn_on_floating_exceptions yes_turn_on_floating_exceptions;turn_on_floating_exceptions yes_turn_on_floating_exceptions;
#endif
#endif

#if defined(SLS_USE_MPLAPACK) && !defined(_Float128)
typedef __float128 _Float128;
#endif

// === constants ===

const Doub PI = 3.14159265358979323;
const Doub E = 2.71828182845904524;
#ifdef SLS_USE_QUAD_MATH
const Qdoub PIq = 3.14159265358979323846264338327950288Q;
const Qdoub Eq = 2.71828182845904523536028747135266250Q;
#endif

} // namespace slisc
