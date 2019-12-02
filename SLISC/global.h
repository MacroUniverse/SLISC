// every program that uses SLISC should include "global.h" first

#pragma once
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#define SLS_FP_EXCEPT // turn on floating point exception

#ifndef NDEBUG
#define SLS_CHECK_BOUNDS
#define SLS_CHECK_SHAPE
#endif

#include <stdlib.h>
#include <limits>
#include <cmath>
#include <algorithm>
#include <complex>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <cstring>

#ifdef SLS_USE_MKL
    #define MKL_Complex16 double _Complex
    #include <mkl.h>
    #define SLS_USE_CBLAS
    #define SLS_USE_LAPACKE
#else
    #ifdef SLS_USE_CBLAS
        #include <cblas.h>
    #endif
    #ifdef SLS_USE_LAPACKE
        #include <lapacke.h>
        #ifdef I // I is already defined in "/usr/include/complex.h"
            #undef I
        #endif
    #endif
#endif

namespace slisc {

// using std

using std::complex; using std::min; using std::max; using std::swap;
using std::vector; using std::string; using std::to_string;
using std::cin; using std::cout; using std::cerr; using std::endl;
using std::ifstream; using std::ofstream;

// Scalar types

typedef int Int;
typedef const Int Int_I; // 32 bit integer
typedef Int &Int_O, &Int_IO;

typedef const unsigned int Uint_I;
typedef unsigned int Uint;
typedef unsigned int &Uint_O, &Uint_IO;

#ifdef _MSC_VER
typedef __int64 Llong;
typedef const Llong Llong_I; // 64 bit integer
typedef Llong &Llong_O, &Llong_IO;

typedef const unsigned __int64 Ullong_I;
typedef unsigned __int64 Ullong;
typedef unsigned __int64 &Ullong_O, &Ullong_IO;
#else
typedef long long int Llong;
typedef const Llong Llong_I; // 64 bit integer
typedef Llong &Llong_O, &Llong_IO;

typedef unsigned long long int Ullong;
typedef const Ullong Ullong_I;
typedef Ullong &Ullong_O, &Ullong_IO;
#endif

#ifdef SLS_USE_INT_AS_LONG
typedef Int Long;
#else
typedef Llong Long;
#endif
typedef const Long Long_I;
typedef Long &Long_O, &Long_IO;

typedef char Char;
typedef const Char Char_I; // 8 bit integer
typedef Char &Char_O, &Char_IO;

typedef unsigned char Uchar;
typedef const Uchar Uchar_I;
typedef Uchar &Uchar_O, &Uchar_IO;

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

typedef vector<Str> vecStr;
typedef const vecStr &vecStr_I;
typedef vecStr &vecStr_O, &vecStr_IO;

// quiet NaN definition
// uncomment one of the following 3 methods of defining a global NaN
// you can test by verifying that (NaN != NaN) is true

//Uint proto_nan[2]={0xffffffff, 0x7fffffff};
//double NaN = *( double* )proto_nan;
//Doub NaN = sqrt(-1.);
static const Doub NaN = std::numeric_limits<Doub>::quiet_NaN();

// Floating Point Exceptions for Microsoft compilers
// no exception for integer overflow
#ifdef SLS_FP_EXCEPT
#ifdef _MSC_VER
struct turn_on_floating_exceptions {
    turn_on_floating_exceptions() {
        int cw = _controlfp(0, 0);
        // also: EM_INEXACT, EM_UNDERFLOW
        cw &= ~(EM_INVALID | EM_OVERFLOW | EM_ZERODIVIDE | EM_DENORMAL);
        _controlfp(cw, MCW_EM);
    }
};
// in case of ODR error, put this in main function;
// turn_on_floating_exceptions yes_turn_on_floating_exceptions;turn_on_floating_exceptions yes_turn_on_floating_exceptions;
#endif
#endif

// === constants ===

const Doub PI = 3.14159265358979323;
const Doub E = 2.71828182845904524;
const Comp I(0, 1); 

// report error and pause execution
void pause(Doub_I t);
#ifndef SLS_ERR
#define SLS_ERR(str) do{cout << "error: " << __FILE__ << ": line " << __LINE__ << ": " << str << endl; getchar();} while(0)
#endif

#define SLS_WARN(str) do{cout << "warning: " << __FILE__ << ": line " << __LINE__ << ": " << str << endl;} while(0)
} // namespace slisc
