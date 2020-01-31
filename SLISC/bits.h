// bit operations and endian relatedb
#pragma once
#include "global.h"

namespace slisc {

// extract a bit at the i-th place from the right
inline bool bitR(Uchar byte, int i)
{
    return (byte >> i) & Uchar(1);
}

// extract a bit at the i-th place from the left
inline bool bitL(Uchar byte, int i)
{
    return (byte << i) & Uchar(128);
}

// set i-th bit from the right
inline void set_bitR(Uchar_IO byte, int i)
{
    byte |= Uchar(1) << i;
}

// set i-th bit from the left
inline void set_bitL(Uchar_IO byte, int i)
{
    byte |= Uchar(128) >> i;
}

// unset i-th bit from the right
inline void unset_bitR(Uchar_IO byte, int i)
{
    byte &= ~(Uchar(1) << i);
}

// unset i-th bit from the left
inline void unset_bitL(Uchar_IO byte, int i)
{
    byte &= ~(Uchar(128) >> i);
}

// convert byte to 8 char '0' or '1'
inline Str bit_str(Uchar_I byte)
{
    Str str; str.resize(8);
    for (int i = 0; i < 8; ++i) {
        if (bitL(byte, i))
            str[i] = '1';
        else
            str[i] = '0';
    }
    return str;
}

// test if system use little endian (less significant byte has smaller memory address)
// for example, shot int(1) will be 00000001 0000000 in little endian
// there is no concept of "bit endian" since they are not addressable
// Intel x86 and x64 architechture use little endian
inline bool little_endian()
{
    short int num = 1;
    Uchar *b = (Uchar *)&num;
    return b[0];
}

// convert endianness
inline void change_endian(Uchar *data, Long_I elm_size, Long_I Nelm)
{
    Long half = elm_size/2;
    for (Long i = 0; i < Nelm; ++i) {
        for (Long j = 0; j < half; ++j) {
            swap(data[j], data[elm_size-j]);
        }
        data += elm_size;
    }
}

} // namespace slisc
