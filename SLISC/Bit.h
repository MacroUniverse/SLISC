// bit operations and endian relatedb
#pragma once
#include "global.h"

namespace slisc {

// class Bit
// {
// protected:
// 	Uchar *m_p;
// 	Long m_i;
// public:
// 	Bit &operator=(Bool_I rhs)
// 	{
// 		set_bitL(m_p, m_i);
// 	}
// }

// extract a bit at the i-th place from the right
inline bool bitR(const Uchar *byte, int i)
{
    return (*byte >> i) & Uchar(1);
}

// extract a bit at the i-th place from the left
inline bool bitL(const Uchar *byte, int i)
{
    return (*byte << i) & Uchar(128);
}

// set i-th bit from the right
inline void set_bitR(Uchar *byte, int i)
{
    *byte |= Uchar(1) << i;
}

// set i-th bit from the left
inline void set_bitL(Uchar *byte, int i)
{
    *byte |= Uchar(128) >> i;
}

// unset i-th bit from the right
inline void unset_bitR(Uchar *byte, int i)
{
    *byte &= ~(Uchar(1) << i);
}

// unset i-th bit from the left
inline void unset_bitL(Uchar *byte, int i)
{
    *byte &= ~(Uchar(128) >> i);
}

// change the i-th bit from the right
inline void toggle_bitR(Uchar *byte, int i)
{
    *byte ^= Uchar(1) << i;
}

// flip the i-th bit from the left
inline void toggle_bitL(Uchar *byte, int i)
{
    *byte ^= Uchar(128) >> i;
}

// convert byte to 8 char '0' or '1'
inline Str bit2str(const Uchar *byte)
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

// convert 8 char '0' or '1' to byte
// also consider to use binary literal e.g. `Uchar(10100101b)`
inline Uchar str2bit(Str_I str)
{
    Uchar byte;
    for (Int i = 0; i < 8; ++i) {
        if (str[i] == '1')
            set_bitL(&byte, i);
        else
            unset_bitL(&byte, i);
    }
    return byte;
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
