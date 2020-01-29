// bit operations and endian relatedb
#pragma once
#include "global.h"

namespace slisc {

// extract a bit at the i-th place from the right
inline bool bitR(char byte, int i)
{
    return (byte >> i) & char(1);
}

// extract a bit at the i-th place from the left
inline bool bitL(char byte, int i)
{
    return (byte << i) & char(128);
}

// set i-th bit from the right
inline void set_bitR(char &byte, int i)
{
	byte |= char(1) << i;
}

// set i-th bit from the left
inline void set_bitL(char &byte, int i)
{
	byte |= char(128) >> i;
}

// print bits
inline void bits(char byte)
{
	for (int i = 0; i < 8; ++i) {
		cout << bitL(byte, i);
	}
	cout << endl;
}

// test if system use little endian (less significant byte has smaller memory address)
// for example, shot int(1) will be 00000001 0000000 in little endian
// there is no concept of "bit endian" since they are not addressable
inline bool little_endian()
{
	short int num = 1;
	char *b = (char *)&num;
	return b[0];
}

// convert endianness
inline void change_endian(Char *data, Long_I elm_size, Long_I Nelm)
{
	Long half = elm_size/2;
	for (Long i = 0; i < Nelm; ++i) {
		for (Long j = 0; j < half; ++j) {
			swap(p[j], p[elm_size-j]);
		}
		data += elm_size;
	}
}

} // namespace slisc
