// every program that uses SLISC should include "global.h" first

#pragma once

#include "config.h"

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

// ===== STL headers =====
// IO, string, file
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>

// math
#include <cfloat>
#include <climits>
#include <limits>
#include <cmath>
#include "prec/quad_math_declare.h" // put before <complex>
#include <complex>

// container
#include <array>
#include <algorithm>
#include <tuple>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <deque>
#include <queue>
#include <stack>

// util
#include <cstdlib>
#include <cstdint>
#include <cstdarg>
#include <functional>
#include <utility>
#include <cassert>
#include <cerrno>
#include <thread>
#include <mutex>

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
		#include "util/my_gsl_blas_types.h"
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

// use e.g. `#if SLS_CPP >= 11` to tell c++ version
#ifdef __cplusplus
	#define SLS_CPP (__cplusplus/100 - 2000)
#endif

// text styles (see also text_style() in disp.h)
#define SLS_RED_BOLD "\033[1;31m"
#define SLS_YELLOW_BOLD "\033[1;33m"
#define SLS_CYAN_BOLD "\033[1;36m"
#define SLS_NO_STYLE "\033[0m"

// SLS_TO_STR(x) converts a numeric macro to a string
#define SLS_STRINGIFY(x) #x
#define SLS_TO_STR(x) SLS_STRINGIFY(x)

// get a string literal of file and line number
#define SLS_WHERE " [file: " __FILE__ ", line: " SLS_TO_STR(__LINE__) "]"

// print a warning with file and line number
#ifndef SLS_WARN
#define SLS_WARN(str) do { \
		std::cout << SLS_YELLOW_BOLD "Warning: " << str << SLS_NO_STYLE " " SLS_WHERE << std::endl; \
		std::cout.flush(); \
	} while(0)
#endif

// print an error with file and line number
namespace slisc {
	// error type
	class sls_err : public std::exception
	{
	private:
		std::string m_msg;
	public:
		explicit sls_err() {}
		explicit sls_err(std::string msg): m_msg(std::move(msg)) {}
		const char *what() const noexcept override
		{ return m_msg.c_str(); }
	};
}

#ifndef SLS_ERR
#ifndef SLS_THROW_ERR
	#define SLS_ERR(str) do { \
		std::cerr << SLS_RED_BOLD "Error: " << std::string(str) << SLS_NO_STYLE " " SLS_WHERE << std::endl; std::exit(1); \
	} while(0)
#else
	#define SLS_ERR(str) do { \
		throw slisc::sls_err(SLS_RED_BOLD "Error: " + std::string(str) + SLS_NO_STYLE " " SLS_WHERE); \
	} while(0)
#endif
#endif

#define SLS_FAIL SLS_ERR("failed!")
#define SLS_ASSERT(condition) if (!(condition)) SLS_FAIL

// my std extension for quad_math
#include "prec/quad_math.h"

#ifdef SLS_USE_MPLAPACK
	#ifndef _Float128
typedef __float128 _Float128;
	#endif
	#include "prec/my_mplapack_utils__Float128.h"
	#include <mplapack/mpblas__Float128.h>
	#include <mplapack/mplapack__Float128.h>
#endif

namespace slisc {

// using std

using std::u16string; using std::u32string;
using std::complex; using std::tie;
using std::vector; using std::string; using std::stringstream;
using std::to_string; using std::pair; using std::tuple;
using std::make_pair; using std::make_tuple;
using std::cin; using std::cout; using std::cerr; using std::endl;
using std::setw; using std::ifstream; using std::ofstream;
using std::min; using std::max; using std::swap; using std::reverse;
using std::numeric_limits; using std::unordered_set; using std::set;
using std::unordered_map; using std::map; using std::get;
using std::deque; using std::queue; using std::stack;
using std::isinf; using std::round; using std::ceil; using std::floor;
using std::abs; using std::real; using std::imag; using std::array;
using std::conj; using std::pow; using std::priority_queue;
using std::sqrt; using std::sin; using std::cos; using std::tan;
using std::exp; using std::log; using std::log10;
using std::expm1; using std::log1p; using std::hypot;
using std::sinh; using std::cosh; using std::tanh;
using std::runtime_error; using std::move;
constexpr size_t npos = std::string::npos; // `using` doesn't work

// Scalar types

// note that `char` might be signed or unsigned, and is not a typedef
// e.g. `char *` is not `signed char*` nor `unsigned char*`

// characters
typedef char16_t Char16;
typedef const Char16 Char16_I;
typedef Char16 &Char16_O, &Char16_IO;

typedef char32_t Char32;
typedef const Char32 Char32_I;
typedef Char32 &Char32_O, &Char32_IO;

// 8 bit signed/unsigned integer
typedef signed char Char;
typedef const Char Char_I;
typedef Char &Char_O, &Char_IO;

typedef unsigned char Uchar;
typedef const Uchar Uchar_I;
typedef Uchar &Uchar_O, &Uchar_IO;

// 16 bit signed/unsigned integer
#if defined(INT16_MAX)
	typedef int16_t Short;
	typedef uint16_t Ushort;
#elif SHRT_MAX == 32767
	typedef short Short;
	typedef unsigned short Short;
#elif INT_MAX == 32767
	typedef int Short;
	typedef unsigned int Ushort;
#else
	#error "No suitable 2-byte integer type found."
#endif
typedef const Short Short_I;
typedef Short &Short_O, &Short_IO;
typedef const Ushort Ushort_I;
typedef Ushort &Ushort_O, &Ushort_IO;

// 32 bit signed/unsigned integer
#if (INT_MAX == 2147483647)
	typedef int Int;
	typedef unsigned int Uint;
#elif (LONG_MAX == 2147483647)
	typedef long Int;
	typedef unsigned long Uint;
#elif defined(INT32_MAX)
	typedef int32_t Int;
	typedef uint32_t Uint;
#else
	#error "No suitable 4-byte integer type found."
#endif
typedef const Int Int_I;
typedef Int &Int_O, &Int_IO;
typedef const Uint Uint_I;
typedef Uint &Uint_O, &Uint_IO;

// 64 bit integer
#if (LLONG_MAX == 9223372036854775807LL)
	typedef long long Llong;
	typedef unsigned long long Ullong;
#elif defined(INT64_MAX)
	typedef int64_t Llong;
	typedef uint64_t Ullong;
#else
	#error "No suitable 8-byte integer type found."
#endif
typedef const Llong Llong_I;
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
typedef const Float Float_I;
typedef Float &Float_O, &Float_IO;

typedef double Doub;
typedef const Doub Doub_I;
typedef Doub &Doub_O, &Doub_IO;

typedef long double Ldoub;
typedef const Ldoub &Ldoub_I;
typedef Ldoub &Ldoub_O, &Ldoub_IO;

typedef bool Bool;
typedef const bool Bool_I;
typedef bool &Bool_O, &Bool_IO;

// === classes ===

typedef complex<Float> Fcomp;
typedef const Fcomp &Fcomp_I;
typedef Fcomp &Fcomp_O, &Fcomp_IO;

typedef complex<Doub> Comp;
typedef const Comp &Comp_I;
typedef Comp &Comp_O, &Comp_IO;

typedef complex<Ldoub> Lcomp;
typedef const Lcomp &Lcomp_I;
typedef Lcomp &Lcomp_O, &Lcomp_IO;

// string type
typedef string Str;
typedef const Str &Str_I;
typedef Str &Str_O, &Str_IO;

typedef u16string Str16;
typedef const Str16 &Str16_I;
typedef Str16 &Str16_O, &Str16_IO;

typedef u32string Str32;
typedef const Str32 &Str32_I;
typedef Str32 &Str32_O, &Str32_IO;

typedef vector<bool> vecBool;
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

typedef vector<vector<bool>> vvecBool;
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

inline bool isnan(Comp_I s) { return s != s; }

// === print() like python ===
// print(a,b,...) is equivalent to `cout << a << b << ... << endl`
// don't worry about how it works, just use it like a magic
inline void print_imp() { cout << endl; }

template<typename T, typename... Args>
void print_imp(const T& first, const Args&... args) {
	cout << first; print_imp(args...);
}

std::mutex print_mutex; // for thread safety

template<typename T, typename... Args>
void print(const T& first, const Args&... args)
{
	std::lock_guard<std::mutex> lock(print_mutex);
	cout << first;
	print_imp(args...);
}

inline void flush() { cout.flush(); }

#define SLS_PRINT(x) do { print(#x, "=", x); } while(0);

// === constants ===
const Doub
Eps = std::numeric_limits<Doub>::epsilon(),
NaN = std::numeric_limits<Doub>::quiet_NaN(),
SNaN = std::numeric_limits<Doub>::signaling_NaN(),
Inf = numeric_limits<Doub>::infinity(),

PI = 3.14159265358979323,
E = 2.71828182845904524;

#ifdef SLS_USE_QUAD_MATH
const Qdoub
PIq = 3.14159265358979323846264338327950288Q,
Eq = 2.71828182845904523536028747135266250Q;
#endif

namespace c {
	// exact
	const Doub
	c0 = 299792458,                   // speed of light
	h = 6.62607015e-34,               // Plank constant
	hbar = h/(2*PI),                  // reduced Plank constant
	qe = 1.602176634e-19,             // elementary charge
	Na = 6.02214076e23,               // Avogadro constant
	kb = 1.380649e-23,                // Boltzmann constant
	R = Na*kb,                        // gas constant
	u = 0.9999999996530e-3/Na,        // atomic mass unit
	AU = 149597870700,                // astronomical unit
	ly = c0*3600*24*365.25,           // light-year

	// measured
	mu0 = 1.25663706212e-6,                // vacuum permeability
	epsilon0 = 1/(mu0*c0*c0),              // vacuum permittivity
	k = 1/(4*PI*epsilon0),                 // Coulomb's constant
	G = 6.67430e-11,                       // gravitational constant
	alpha = qe*qe/(4*PI*epsilon0*hbar*c0), // fine structure constant
	me = 9.1093837015e-31,                 // electron mass
	mp = 1.67262192369e-27,                // proton mass
	Rh = 1.0973731568160e7,                // Rydberg constant
	a0 = 5.29177210903e-11,                // Bohr radius

	// conversion constants
	inch = 2.54e-2,                   // length
	gauss = 1e-4,                     // electric field
	mile = 6.09e+2,                   // length
	lb = 0.454, pound=0.454,          // mass
	au_x = a0,                        // 1 a.u. distance
	au_t = me*a0*a0/hbar,             // 1 a.u. time
	au_E = hbar*hbar/(me*a0*a0),      // 1 a.u. energy
	au_Ef = qe/(4*PI*epsilon0*a0*a0); // 1 a.u. electric field
}

} // namespace slisc
