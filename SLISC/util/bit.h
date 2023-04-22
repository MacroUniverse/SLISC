// bit operations and endian related

// Notes:
// 1. C-style conversion between char and Uchar does not change any bit.
// 2. char(-128) = char(128) = 0b10000000
// 3. negative operand for C operator >> or << are undefined!

#pragma once
#include "../global.h"

namespace slisc {

// test if system use little endian (less significant byte has smaller memory address)
// for example, shot int(1) will be 00000001 0000000 in little endian
// there is no concept of "bit endian" since they are not addressable
// Intel x86 and x64 architechture use little endian
inline Bool little_endian()
{
	short int num = 1;
	char *b = (char *)&num;
	return b[0];
}

// convert endianness
inline void change_endian(void *data, Long_I elm_size, Long_I Nelm)
{
	char *p = (char *)data;
	Long half = elm_size/2;
	for (Long i = 0; i < Nelm; ++i) {
		for (Long j = 0; j < half; ++j) {
			swap(p[j], p[elm_size-j]);
		}
		p += elm_size;
	}
}

// get i-th bit from the right
inline Bool bitR(Char_I byte, Int_I i)
{ return (Uchar)byte & Uchar(1) << i; }

inline Bool bitR(Uchar_I byte, Int_I i)
{ return byte & Uchar(1) << i; }

inline Bool bitR(const void *byte, Int_I i)
{ return *(Uchar*)byte & Uchar(1) << i; }

// get i-th bit from the left
inline Bool bitL(Char_I byte, Int_I i)
{ return (Uchar)byte & Uchar(128) >> i; }

inline Bool bitL(Uchar_I byte, Int_I i)
{ return byte & Uchar(128) >> i; }

inline Bool bitL(const void *byte, Int_I i)
{ return *(Uchar*)byte & Uchar(128) >> i; }

// set i-th bit from the right to 1
inline void set_bitR(void *byte, Int_I i)
{ *(Uchar*)byte |= Uchar(1) << i; }

inline void set_bitR(Char_IO byte, Int_I i)
{ set_bitR(&byte, i); }

inline void set_bitR(Uchar_IO byte, Int_I i)
{ set_bitR(&byte, i); }

// set i-th bit from the left to 1
inline void set_bitL(void *byte, Int_I i)
{ *(Uchar*)byte |= Uchar(128) >> i; }

inline void set_bitL(Char_IO byte, Int_I i)
{ set_bitL(&byte, i); }

inline void set_bitL(Uchar_IO byte, Int_I i)
{ set_bitL(&byte, i); }

// set i-th bit from the right to 0
inline void unset_bitR(void *byte, Int_I i)
{ *(Uchar*)byte &= Uchar(254) << i; }

inline void unset_bitR(Char_IO byte, Int_I i)
{ unset_bitR(&byte, i); }

inline void unset_bitR(Uchar_IO byte, Int_I i)
{ unset_bitR(&byte, i); }

// set i-th bit from the left to 0
inline void unset_bitL(void *byte, Int_I i)
{ *(Uchar*)byte &= Uchar(127) >> i; }

inline void unset_bitL(Char_IO byte, Int_I i)
{ unset_bitL(&byte, i); }

inline void unset_bitL(Uchar_IO byte, Int_I i)
{ unset_bitL(&byte, i); }

// flip the i-th bit from the right
inline void toggle_bitR(void *byte, Int_I i)
{ *(Uchar*)byte ^= Uchar(1) << i; }

inline void toggle_bitR(Char_IO byte, Int_I i)
{ toggle_bitR(&byte, i); }

inline void toggle_bitR(Uchar_IO byte, Int_I i)
{ toggle_bitR(&byte, i); }

// flip the i-th bit from the left
inline void toggle_bitL(void *byte, Int_I i)
{ *(Uchar*)byte ^= Uchar(128) >> i; }

inline void toggle_bitL(Char_IO byte, Int_I i)
{ toggle_bitL(&byte, i); }

inline void toggle_bitL(Uchar_IO byte, Int_I i)
{ toggle_bitL(&byte, i); }

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

// convert data to bit string
// Nbyte: bytes of data
// add_space: add a space to every byte
// auto_endian: flip the bytes for little endian
inline Str to_bitstr(const void *byte, Long_I Nbyte = 1, Bool add_space = true, Bool auto_endian = false)
{
	char *p = (char *)byte;
	Str str;
	if (!auto_endian || !little_endian()) {
		if (!add_space) {
			str.reserve(8*Nbyte);
			for (Long i = 0; i < Nbyte; ++i)
				str += to_bitstr(p[i]);
		}
		else {
			str.reserve(9*Nbyte);
			for (Long i = 0; i < Nbyte; ++i)
				str += to_bitstr(p[i]) + ' ';
			str.pop_back();
		}
	}
	else {
		if (!add_space) {
			str.reserve(8*Nbyte);
			for (Long i = Nbyte-1; i >= 0; --i)
				str += to_bitstr(p[i]);
		}
		else {
			str.reserve(9*Nbyte);
			for (Long i = Nbyte-1; i >= 0; --i)
				str += to_bitstr(p[i]) + ' ';
			str.pop_back();
		}
	}
	return str;
}

// convert each char to a bit, '0' is 'false', otherwise 'true'
// also consider to use binary literal e.g. `char(0b10100101)`
inline char str2bit(Str_I str)
{
	char byte = 0;
	for (Long i = 0; i < 8; ++i)
		if (str[i] != '0')
			set_bitL(&byte, i);
	return byte;
}

// convert `N` digits of any base (up to 256) to integer (little endian)
// i.e. p[0] + p[1]*base + p[2]*base^2 ...
inline Int baseN2Int(const Uchar *p, Int_I N, Uchar_I base)
{
	Int n = p[0], exp = base;
	for (Int i = 1; i < N; ++i) {
		n += p[i] * exp;
		exp *= base;
	}
	return n;
}

// convert integer to any base (little endian)
inline void Int2baseN(Uchar *p, Int_I N, Uchar_I base, Int_I n)
{
	Int m = n;
	p[0] = m % base;
	for (Int i = 1; i < N; ++i) {
		m /= base;
		p[i] = m % base;
	}
}

// =========== Character Sets ===============

// visible ASCII chars (in order)
// !"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~
inline char b94(Long_I i)
{
	static const Str s = "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
	return s[i];
}

// visible ASCII chars (in order) that doesn't need to escape in a C printf string （escape: "%\)
// !#$&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[]^_`abcdefghijklmnopqrstuvwxyz{|}~
inline char b91(Long_I i)
{
	static const Str s = "!#$&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[]^_`abcdefghijklmnopqrstuvwxyz{|}~";
	return s[i];
}

// b91 without 0OIl (confusing in some font)
inline char b87(Long_I i)
{
	static Str s = "!#$&'()*+,-./123456789:;<=>?@ABCDEFGHJKLMNPQRSTUVWXYZ[]^_`abcdefghijkmnopqrstuvwxyz{|}~";
	return s[i];
}

// widely used on internet
// https://en.wikipedia.org/wiki/Base64
// for a library that converts a file to Base64 string, see
// https://github.com/ReneNyffenegger/cpp-base64
inline char b64(Long_I i)
{
	static const Str s = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	return s[i];
}

// base 64 (2) : safe filename and paths
// 0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz-_
inline char b64_2(Long_I i)
{
	static const Str s = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz-_";
	return s[i];
}

// alpha numeric characters
// 0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz
inline char b62(Long_I i)
{
	static const Str s = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	return s[i];
}

// base 58: alpha numeric without 0OIl (confusing in some font)
// 123456789ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz
inline char b58(Long_I i)
{
	static const Str s = "123456789ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz";
	return s[i];
}

// visible ASCII chars that can be used in URL [path segment] literally (otherwise use percent-encoding)
// !$&'()*+-.0123456789:;=@ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghijklmnopqrstuvwxyz|~
inline char b79(Long_I i)
{
	static const Str s = "!$&'()*+-.0123456789:;=@ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghijklmnopqrstuvwxyz|~";
	return s[i];
}

// lower case alpha numeric characters
// 0123456789abcdefghijklmnopqrstuvwxyz
inline char b36(Long_I i)
{
	static const Str s = "123456789ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz";
	return s[i];
}

// search index of b87, return -1 if not found
inline Long b87_ind(Char_I c)
{
	for (Long i = 0; i < 87; ++i)
		if (c == b87(i))
			return i;
	return -1;
}

// convert 5-digit base87 to 4-byte int (little endian)
inline Int b872Int(const char *p)
{
	Int n = b87_ind(p[0]), exp = 1;
	for (Int i = 1; i < 5; ++i) {
		exp *= 87;
		n += b87_ind(p[i]) * exp;
	}
	return n;
}

// convert 4-byte int to 5-digit base87 (little endian)
inline void Int2b87(char *p, Int_I n)
{
	Int m = n;
	p[0] = b87(m % 87);
	for (Int i = 1; i < 5; ++i) {
		m /= 87;
		p[i] = b87(m % 87);
	}
}

// =========== encode data to string =============

// assuming little endian
// not tested!
// inline void data2b87(Str_O str87, Str_I data)
// {
// 	str87.resize((data.size()+3)/4*5);
// 	Int *ip = (Int*)data.data();
// 	Int n;
// 	Long k = 0, iend = data.size()/4;
// 	for (Long i = 0; i < iend; ++i) {
// 		n = ip[i];
// 		for (Int j = 0; j < 5; ++j) {
// 			str87[k] = b87(n % 87);
// 			n /= 87; ++k;
// 		}
// 	}
// 	// last few digits
// 	n = 0;
// 	for (Int i = 0; i < Int(data.size() % 4); ++i)
// 		n = n*256 + data[4*iend+i];
// 	for (Int j = 0; j < 5; ++j) {
// 		str87[k] = b87(n % 87);
// 		n /= 87; ++k;
// 	}
// }

// assuming little endian
// not tested!
// inline void b872data(Str_O data, Str_I str87)
// {
// 	data.resize((data.size()+4)/5*4);
// 	Int n;
// 	Long k = 0, iend = str87.size()/5;
// 	for (Long i = 0; i < iend; ++i) {
//         for (Int j = 0; j < 5; ++j) {
//             // str87[k] = b87(i*5+n % 87);
//             n /= 87; ++k;
//         }
// 		// n = ip[i];
// 		for (Int j = 0; j < 5; ++j) {
// 			str87[k] = b87(n % 87);
// 			n /= 87; ++k;
// 		}
// 	}
// 	// last few digits
// 	n = 0;
// 	for (Int i = 0; i < Int(data.size() % 4); ++i)
// 		n = n*256 + data[4*iend+i];
// 	for (Int j = 0; j < 5; ++j) {
// 		str87[k] = b87(n % 87);
// 		n /= 87; ++k;
// 	}
// }

} // namespace slisc
