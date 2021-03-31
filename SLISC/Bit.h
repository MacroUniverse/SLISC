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

} // namespace slisc
