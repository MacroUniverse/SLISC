// bit operations and endian related
// Note: negative operand for C operator >> or << are undefined!

#pragma once
#include "../global.h"

namespace slisc {

// test if system use little endian (less significant byte has smaller memory address)
// for example, shot int(1) will be 00000001 0000000 in little endian
// there is no concept of "bit endian" since they are not addressable
// Intel x86 and x64 architechture use little endian
inline bool little_endian() {
    int16_t i = 1;
    return *(char *)&i == 1;
}

// convert endianness
inline void change_endian(void *data, Long_I elm_size, Long_I Nelm)
{
	auto p = (Uchar *)data;
	Long half = elm_size/2;
	for (Long i = 0; i < Nelm; ++i) {
		for (Long j = 0; j < half; ++j)
			swap(p[j], p[elm_size-j]);
		p += elm_size;
	}
}

// get i-th bit of a byte from the right
// (due to integral promotion, `byte` will convert to signed int first)
inline bool bitR(Uchar byte, int i) {
#ifdef SLS_CHECK_BOUNDS
	SLS_ASSERT(i >= 0 && i < 8);
#endif
	return byte & (1 << i);
}

inline bool bitR(const void *byte, int i)
{ return bitR(*(Uchar*)byte, i); }

inline bool bitR(Char byte, int i)
{ return bitR(&byte, i); }

// for multiple bytes, and consider endianess
inline bool bitR(const void *data, Long_I size, Long_I i, Bool_I auto_endian = false)
{
#ifdef SLS_CHECK_BOUNDS
	SLS_ASSERT(i >= 0 && i < size*8);
#endif
	auto p = (Uchar *)data;
	if (!auto_endian || !little_endian())
		p += size - 1 - i/8;
	else
		p += i/8;
	return *p & (1 << (i % 8));
}

// get i-th bit from the left of a byte
inline bool bitL(Uchar byte, int i) {
#ifdef SLS_CHECK_BOUNDS
	SLS_ASSERT(i >= 0 && i < 8);
#endif
	return byte & (128 >> i);
}

inline bool bitL(const void *byte, int i)
{ return bitL(*(Uchar*)byte, i); }

inline bool bitL(Char byte, int i)
{ return bitL(&byte, i); }

// for multiple bytes, and consider endianess
inline bool bitL(const void *data, Long_I size, Long_I i, Bool_I auto_endian = false)
{
#ifdef SLS_CHECK_BOUNDS
	SLS_ASSERT(i >= 0 && i < size*8);
#endif
	auto p = (Uchar *)data;
	if (!auto_endian || !little_endian())
		p += i/8;
	else
		p += size - 1 - i/8;
	return *p & (128 >> (i % 8));
}

// set i-th bit from the right of a byte to 1
inline void set_bitR(Uchar_IO byte, int i) {
#ifdef SLS_CHECK_BOUNDS
	SLS_ASSERT(i >= 0 && i < 8);
#endif
	byte |= (1 << i);
}

inline void set_bitR(void *byte, int i)
{ set_bitR(*(Uchar*)byte, i); }

inline void set_bitR(Char_IO byte, int i)
{ set_bitR(&byte, i); }

inline void set_bitR(const void *data, Long_I size, Long_I i, Bool_I auto_endian = false)
{
#ifdef SLS_CHECK_BOUNDS
	SLS_ASSERT(i >= 0 && i < size*8);
#endif
	auto p = (Uchar *)data;
	if (!auto_endian || !little_endian())
		p += size - 1 - i/8;
	else
		p += i/8;
	set_bitR(p, i % 8);
}

// set i-th bit from the left to 1
inline void set_bitL(Uchar_IO byte, int i) {
#ifdef SLS_CHECK_BOUNDS
	SLS_ASSERT(i >= 0 && i < 8);
#endif
	byte |= (128 >> i);
}

inline void set_bitL(void *byte, int i)
{ set_bitL(*(Uchar*)byte, i); }

inline void set_bitL(Char_IO byte, int i)
{ set_bitL(&byte, i); }

inline void set_bitL(const void *data, Long_I size, Long_I i, Bool_I auto_endian = false)
{
#ifdef SLS_CHECK_BOUNDS
	SLS_ASSERT(i >= 0 && i < size*8);
#endif
	auto p = (Uchar *)data;
	if (!auto_endian || !little_endian())
		p += i/8;
	else
		p += size - 1 - i/8;
	set_bitL(p, i % 8);
}

// set i-th bit from the right to 0
inline void unset_bitR(Uchar_IO byte, int i) {
#ifdef SLS_CHECK_BOUNDS
	SLS_ASSERT(i >= 0 && i < 8);
#endif
	byte &= ~(1 << i);
}

inline void unset_bitR(void *byte, int i)
{ unset_bitR(*(Uchar*)byte, i); }

inline void unset_bitR(Char_IO byte, int i)
{ unset_bitR(&byte, i); }

inline void unset_bitR(const void *data, Long_I size, Long_I i, Bool_I auto_endian = false)
{
#ifdef SLS_CHECK_BOUNDS
	SLS_ASSERT(i >= 0 && i < size*8);
#endif
	auto p = (Uchar *)data;
	if (!auto_endian || !little_endian())
		p += size - 1 - i/8;
	else
		p += i/8;
	unset_bitR(p, i % 8);
}

// set i-th bit from the left to 0
inline void unset_bitL(Uchar_IO byte, int i) {
#ifdef SLS_CHECK_BOUNDS
	SLS_ASSERT(i >= 0 && i < 8);
#endif
	byte &= ~(128 >> i);
}

inline void unset_bitL(void *byte, int i)
{ unset_bitL(*(Uchar*)byte, i); }

inline void unset_bitL(Char_IO byte, int i)
{ unset_bitL(&byte, i); }

inline void unset_bitL(const void *data, Long_I size, Long_I i, Bool_I auto_endian = false)
{
#ifdef SLS_CHECK_BOUNDS
	SLS_ASSERT(i >= 0 && i < size*8);
#endif
	auto p = (Uchar *)data;
	if (!auto_endian || !little_endian())
		p += i/8;
	else
		p += size - 1 - i/8;
	unset_bitL(p, i % 8);
}

// flip the i-th bit from the right
inline void toggle_bitR(Uchar_IO byte, int i) {
#ifdef SLS_CHECK_BOUNDS
	SLS_ASSERT(i >= 0 && i < 8);
#endif
	byte ^= (1 << i);
}

inline void toggle_bitR(void *byte, int i)
{ toggle_bitR(*(Uchar*)byte, i); }

inline void toggle_bitR(Char_IO byte, int i)
{ toggle_bitR(&byte, i); }

inline void toggle_bitR(const void *data, Long_I size, Long_I i, Bool_I auto_endian = false)
{
#ifdef SLS_CHECK_BOUNDS
	SLS_ASSERT(i >= 0 && i < size*8);
#endif
	auto p = (Uchar *)data;
	if (!auto_endian || !little_endian())
		p += size - 1 - i/8;
	else
		p += i/8;
	toggle_bitR(p, i % 8);
}

// flip the i-th bit from the left
inline void toggle_bitL(Uchar_IO byte, int i) {
#ifdef SLS_CHECK_BOUNDS
	SLS_ASSERT(i >= 0 && i < 8);
#endif
	byte ^= (128 >> i);
}

inline void toggle_bitL(void *byte, int i)
{ toggle_bitL(*(Uchar*)byte, i); }

inline void toggle_bitL(Char_IO byte, int i)
{ toggle_bitL(&byte, i); }

inline void toggle_bitL(const void *data, Long_I size, Long_I i, Bool_I auto_endian = false)
{
#ifdef SLS_CHECK_BOUNDS
	SLS_ASSERT(i >= 0 && i < size*8);
#endif
	auto p = (Uchar *)data;
	if (!auto_endian || !little_endian())
		p += i/8;
	else
		p += size - 1 - i/8;
	toggle_bitL(p, i % 8);
}

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
inline Str to_bitstr(const void *byte, Long_I Nbyte = 1, bool add_space = true, bool auto_endian = false)
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

// ========== manipulate a range of bits ============

// Nbit '1' on the right
inline Uchar bitsR_mask(int Nbit) {
#ifdef SLS_CHECK_BOUNDS
	SLS_ASSERT(Nbit >= 0 && Nbit <= 8);
#endif
	return (1 << Nbit) - 1;
}

// Nbit '1' on the left
inline Uchar bitsL_mask(int Nbit) {
#ifdef SLS_CHECK_BOUNDS
	SLS_ASSERT(Nbit >= 0 && Nbit <= 8);
#endif
	return 0xFF << (8 - Nbit);
}

// Nbit '1' starting from `start`
inline Uchar bits_mask(int start, int Nbit) {
#ifdef SLS_CHECK_BOUNDS
	SLS_ASSERT(start >= 0 && start < 8 && start + Nbit <= 8);
#endif
	return ((1 << Nbit) - 1) << (8-start-Nbit);
}

// copy Nbit on the right
inline void bitsR2bitsR(Uchar& target, Uchar source, int Nbit)
{
    Uchar clear_mask = bitsR_mask(Nbit);
	source &= clear_mask;
	target &= ~clear_mask;
	target |= source;
}

// copy Nbit on the left
inline void bitsL2bitsL(Uchar& target, Uchar source, int Nbit)
{
	Uchar clear_mask = bitsL_mask(Nbit);
	source &= clear_mask;
	target &= ~clear_mask;
	target |= source;
}

// copy Nbit from the right to the left
inline void bitsR2bitsL(Uchar& target, Uchar source, int Nbit)
{
#ifdef SLS_CHECK_BOUNDS
	SLS_ASSERT(Nbit >= 0 && Nbit <= 8);
#endif
    Uchar clear_mask = 0xFF >> Nbit;
    target &= clear_mask;
    target |= (source << (8 - Nbit));
}

inline void bitsL2bitsR(Uchar& target, Uchar source, int Nbit)
{
#ifdef SLS_CHECK_BOUNDS
	SLS_ASSERT(Nbit >= 0 && Nbit <= 8);
#endif
    Uchar clear_mask = 0xFF << Nbit;
    target &= clear_mask;
    target |= (source >> (8 - Nbit));
}

inline void bitsR2bits(Uchar& target, int start, int Nbit, Uchar source)
{
#ifdef SLS_CHECK_BOUNDS
	SLS_ASSERT(start >= 0 && start < 8 && start + Nbit <= 8);
#endif
	Uchar clear_mask = bitsR_mask(Nbit);
    source &= clear_mask;
	int left_shift = 8-start-Nbit;
    clear_mask = ~(clear_mask << left_shift);
    target &= clear_mask;
    target |= (source << left_shift);
}

inline void bits2bitsR(Uchar& target, Uchar source, int start, int Nbit)
{
#ifdef SLS_CHECK_BOUNDS
	SLS_ASSERT(start >= 0 && start < 8 && start + Nbit <= 8);
#endif
	Uchar clear_mask = bits_mask(start, Nbit);
	source = (source & clear_mask) >> (8-start-Nbit);
	bitsR2bitsR(target, source, Nbit);
}

// inline void set_bit_range(Uchar* target, Long Nbyte, int target_start,
//                    Uchar* source, Long Nbyte, int source_start, int Nbit, bool auto_endian = false) {
// 	Uchar N1, N2;
// 	if (target_start < source_start) {
// 		bitsR2bits(*target, target_start, 8-source_start, *source);
// 		++source;
// 		N2 = source_start - target_start;
// 		bitsL2bitsR(*target, *source, N2);
// 		N1 = 8 - N2;
// 	}
// 	else if (source_start < target_start) {
// 		bits2bitsR(*target, *source, source_start, 8-target_start);
// 		N1 = target_start - source_start;
// 		N2 = 8 - N1;
// 	}
// 	else {
// 		...
// 	}
// 	while (1) {
// 		bitsR2bitsL(*target, *source, N1);
// 		++source;
// 		bitsL2bitsR(*target, *source, N2);
// 		++target;
// 	}
// }

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
