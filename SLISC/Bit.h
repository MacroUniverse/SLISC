// bit operations and endian relatedb
#pragma once
#include "global.h"

namespace slisc {

// class Bit
// {
// protected:
//     Char *m_p;
//     Long m_i;
// public:
//     Bit &operator=(Bool_I rhs)
//     {
//         set_bitL(m_p, m_i);
//     }
// }

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

inline Bool bitR(const Char *byte, Int_I i)
{ return bitR(*byte, i); }

// extract a bit at the i-th place from the left
inline Bool bitL(Char_I byte, Int_I i)
{
    return byte & Uchar(128) >> i;
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

// convert 8 char '0' or '1' to byte
// also consider to use binary literal e.g. `Char(10100101b)`
inline Char str2bit(Str_I str)
{
    Char byte;
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

} // namespace slisc
