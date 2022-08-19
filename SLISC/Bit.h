// bit operations and endian related
#pragma once
#include "global.h"

namespace slisc {

// test if system use little endian (less significant byte has smaller memory address)
// for example, shot int(1) will be 00000001 0000000 in little endian
// there is no concept of "bit endian" since they are not addressable
// Intel x86 and x64 architechture use little endian
inline Bool little_endian()
{
    short int num = 1;
    Char *b = (Char *)&num;
    return b[0];
}

// convert endianness
inline void change_endian(Char *data, Long_I elm_size, Long_I Nelm)
{
    Long half = elm_size/2;
    for (Long i = 0; i < Nelm; ++i) {
        for (Long j = 0; j < half; ++j) {
            swap(data[j], data[elm_size-j]);
        }
        data += elm_size;
    }
}

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
    return byte & Uchar(1) << i;
}

inline Bool bitR(const void *byte, Int_I i)
{
    return *(Uchar*)byte & Uchar(1) << i;
}

// extract a bit at the i-th place from the left
inline Bool bitL(Char_I byte, Int_I i)
{
    return byte & Uchar(128) >> i;
}

inline Bool bitL(const void *byte, Int_I i)
{
    return *(Uchar*)byte & Uchar(128) >> i;
}

// set i-th bit from the right
inline void set_bitR(Char_IO byte, Int_I i)
{
    byte |= Uchar(1) << i;
}

inline void set_bitR(void *byte, Int_I i)
{
    *(Uchar*)byte |= Uchar(1) << i;
}

// set i-th bit from the left
inline void set_bitL(Char_IO byte, Int_I i)
{
    byte |= Uchar(128) >> i;
}

inline void set_bitL(void *byte, Int_I i)
{
    *(Uchar*)byte |= Uchar(128) >> i;
}

// unset i-th bit from the right
inline void unset_bitR(Char_IO byte, Int_I i)
{
    byte &= ~(Uchar(1) << i);
}

inline void unset_bitR(void *byte, Int_I i)
{
    *(Uchar*)byte &= ~(Uchar(1) << i);
}

// unset i-th bit from the left
inline void unset_bitL(Char_IO byte, Int_I i)
{
    byte &= ~(Uchar(128) >> i);
}

inline void unset_bitL(void *byte, Int_I i)
{ unset_bitL(*(Char*)byte, i); }

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

// convert a byte to bit string (8 char '0' or '1')
inline Str to_bitstr(Char_I byte)
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

// convert memory to bit string
inline Str to_bitstr(const void *byte, Int_I Nbyte = 1, Bool add_space = true, Bool auto_endian = false)
{
    Char *p = (Char *)byte;
    Str str;
    if (!auto_endian || (!little_endian() && auto_endian)) {
        if (!add_space) {
            str.reserve(8*Nbyte);
            for (Int i = 0; i < Nbyte; ++i)
                str += to_bitstr(p[i]);
        }
        else {
            str.reserve(9*Nbyte);
            for (Int i = 0; i < Nbyte; ++i)
                str += to_bitstr(p[i]) + ' ';
            str.pop_back();
        }
    }
    else {
        if (!add_space) {
            str.reserve(8*Nbyte);
            for (Int i = Nbyte-1; i >= 0; --i)
                str += to_bitstr(p[i]);
        }
        else {
            str.reserve(9*Nbyte);
            for (Int i = Nbyte-1; i >= 0; --i)
                str += to_bitstr(p[i]) + ' ';
            str.pop_back();
        }
    }
    return str;
}

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
inline Char b85(Long_I i)
{
    static Str s = "!#$%&()*+,-.123456789:;<=>?@ABCDEFGHJKLMNPQRSTUVWXYZ[]^_abcdefghijkmnopqrstuvwxyz{|}~";
    return s[i];
}

// search index of b85, return -1 if not found
inline Long b85_ind(Char_I c)
{
    for (Long i = 0; i < 85; ++i)
        if (c == b85(i))
            return i;
    return -1;
}

// convert 5-digit base58 to 4-byte integer (little endian)
inline Int b852Int(const Char *p)
{
    Int n = b85_ind(p[0]), exp = 1;
    for (Int i = 1; i < 5; ++i) {
        exp *= 85;
        n += b85_ind(p[i]) * exp;
    }
    return n;
}

// convert 4-byte integer to 5-digit base58 (little endian)
inline void Int2b85(Char *p, Int_I n)
{
    Int m = n;
    p[0] = b85(m % 85);
    for (Int i = 1; i < 5; ++i) {
        m /= 85;
        p[i] = b85(m % 85);
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
// 			str85[k] = b85(n % 85);
// 			n /= 85; ++k;
// 		}
// 	}
// 	// last few digits
// 	n = 0;
// 	for (Int i = 0; i < Int(data.size() % 4); ++i)
// 		n = n*256 + data[4*iend+i];
// 	for (Int j = 0; j < 5; ++j) {
// 		str85[k] = b85(n % 85);
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
//             // str85[k] = b85(i*5+n % 85);
//             n /= 85; ++k;
//         }
// 		// n = ip[i];
// 		for (Int j = 0; j < 5; ++j) {
// 			str85[k] = b85(n % 85);
// 			n /= 85; ++k;
// 		}
// 	}
// 	// last few digits
// 	n = 0;
// 	for (Int i = 0; i < Int(data.size() % 4); ++i)
// 		n = n*256 + data[4*iend+i];
// 	for (Int j = 0; j < 5; ++j) {
// 		str85[k] = b85(n % 85);
// 		n /= 85; ++k;
// 	}
// }

} // namespace slisc
