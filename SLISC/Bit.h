// bit operations and endian relatedb
#pragma once
#include "global.h"

namespace slisc {

// bitwise conversion between uchar and char
inline Uchar bit2uchar(Char_I c)
{
    return reinterpret_cast<const Uchar&>(c);
}

inline Char bit2char(Uchar_I uc)
{
    return reinterpret_cast<const Char&>(uc);
}

// extract a bit at the i-th place from the right
inline Bool bitR(Char_I byte, Int_I i)
{
    return byte &Uchar(1) << i;
}

inline Bool bitR(const Char *byte, Int_I i)
{ return bitR(*byte, i); }

// extract a bit at the i-th place from the left
inline Bool bitL(Char_I byte, Int_I i)
{
    return byte &Uchar(128) >> i;
}

inline Bool bitL(const Char *byte, Int_I i)
{ return bitL(*byte, i); }

// set i-th bit from the right
inline void set_bitR(Char_IO byte, Int_I i)
{
    byte |= Uchar(1) << i;
}

inline void set_bitR(Char *byte, Int_I i)
{ set_bitR(*byte, i); }

// set i-th bit from the left
inline void set_bitL(Char_IO byte, Int_I i)
{
    byte |= Uchar(128) >> i;
}

inline void set_bitL(Char *byte, Int_I i)
{ set_bitL(*byte, i); }

// unset i-th bit from the right
inline void unset_bitR(Char_IO byte, Int_I i)
{
    byte &= ~(Uchar(1) << i);
}

inline void unset_bitR(Char *byte, Int_I i)
{ unset_bitR(*byte, i); }

// unset i-th bit from the left
inline void unset_bitL(Char_IO byte, Int_I i)
{
    byte &= ~(Uchar(128) >> i);
}

inline void unset_bitL(Char *byte, Int_I i)
{ unset_bitL(*byte, i); }

// change the i-th bit from the right
inline void toggle_bitR(Char_IO byte, Int_I i)
{
    byte ^= Uchar(1) << i;
}

inline void toggle_bitR(Char *byte, Int_I i)
{ toggle_bitR(*byte, i); }

// flip the i-th bit from the left
inline void toggle_bitL(Char_IO byte, Int_I i)
{
    byte ^= Uchar(128) >> i;
}

inline void toggle_bitL(Char *byte, Int_I i)
{ toggle_bitL(*byte, i); }

// convert byte to 8 char '0' or '1'
inline Str bit2str(Char_I byte)
{
    Str str; str.resize(8);
    for (Int i = 0; i < 8; ++i) {
        if (bitL(byte, i))
            str[i] = '1';
        else
            str[i] = '0';
    }
    return str;
}

inline Str bit2str(const Char *byte)
{ return bit2str(*byte); }

// convert each char to a bit, '0' is 'false', otherwise 'true'
// also consider to use binary literal e.g. `Char(10100101b)`
inline Char str2bit(Str_I str)
{
    Char byte = 0;
    for (Int i = 0; i < 8; ++i) {
        if (str[i] != '0')
            set_bitL(&byte, i);
    }
    return byte;
}

// convert any base (up to 256) to integer (little endian)
inline Int baseN2Int(const Uchar *p, Int_I N, Int_I base)
{
    Int n = p[0], exp = base;
    for (Int i = 1; i < N; ++i) {
        n += p[i] * exp;
        exp *= base;
    }
    return n;
}

// convert integer to any base (little endian)
inline void Int2baseN(Uchar *p, Int_I N, Int_I base, Int_I n)
{
    Int m = n;
    p[0] = m % base;
    for (Int i = 1; i < N; ++i) {
        m /= base;
        p[i] = m % base;
    }
}

// convert 4 bytes to one of the 85 character sets that can be typed by keyboard and easy to distinguish
Str b85 = "!#$%&()*+,-.123456789:;<=>?@ABCDEFGHJKLMNPQRSTUVWXYZ[]^_abcdefghijkmnopqrstuvwxyz{|}~";

// search index of b85, return -1 if not found
inline Long b85_ind(Char_I c)
{
    for (Long i = 0; i < 85; ++i)
        if (c == b85[i])
            return i;
    return -1;
}

// convert 5-digit base58 to 4-byte integer (little endian)
inline Int b852Int(const Char *p)
{
    Int n = b85_ind(p[0]), exp = 85;
    for (Int i = 1; i < 5; ++i) {
        n += b85_ind(p[i]) * exp;
        exp *= 85;
    }
    return n;
}

// convert 4-byte integer to 5-digit base58 (little endian)
inline void Int2b85(Char *p, Int_I n)
{
    Int m = n;
    p[0] = b85[m % 85];
    for (Int i = 1; i < 5; ++i) {
        m /= 85;
        p[i] = b85[m % 85];
    }
}

// assuming little endian
// not tested!
// inline void data2b85(Str_O str85, Str_I data)
// {
// 	str85.resize((data.size()+3)/4*5);
// 	Int *ip = (Int*)data.data();
// 	Int n;
// 	Long k = 0, iend = data.size()/4;
// 	for (Long i = 0; i < iend; ++i) {
// 		n = ip[i];
// 		for (Int j = 0; j < 5; ++j) {
// 			str85[k] = b85[n % 85];
// 			n /= 85; ++k;
// 		}
// 	}
// 	// last few digits
// 	n = 0;
// 	for (Int i = 0; i < Int(data.size() % 4); ++i)
// 		n = n*256 + data[4*iend+i];
// 	for (Int j = 0; j < 5; ++j) {
// 		str85[k] = b85[n % 85];
// 		n /= 85; ++k;
// 	}
// }

// assuming little endian
// not tested!
// inline void b852data(Str_O data, Str_I str85)
// {
// 	data.resize((data.size()+4)/5*4);
// 	Int n;
// 	Long k = 0, iend = str85.size()/5;
// 	for (Long i = 0; i < iend; ++i) {
//         for (Int j = 0; j < 5; ++j) {
//             // str85[k] = b85[i*5+n % 85];
//             n /= 85; ++k;
//         }
// 		// n = ip[i];
// 		for (Int j = 0; j < 5; ++j) {
// 			str85[k] = b85[n % 85];
// 			n /= 85; ++k;
// 		}
// 	}
// 	// last few digits
// 	n = 0;
// 	for (Int i = 0; i < Int(data.size() % 4); ++i)
// 		n = n*256 + data[4*iend+i];
// 	for (Int j = 0; j < 5; ++j) {
// 		str85[k] = b85[n % 85];
// 		n /= 85; ++k;
// 	}
// }

} // namespace slisc
