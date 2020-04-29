// string utilities

#pragma once
#include "global.h"

namespace slisc {

// string utilities

inline void num2str(Str_O str, Char_I s, Long_I min_len = -1)
{
    str = to_string(s);
    // erase trailing zeros
    if (str.find('.') != Str::npos)
        str.erase(str.find_last_not_of('0') + 1);
    // 0 padding on the left
    if (min_len > 0 && (Long)str.size() < min_len) {
        Str str1;
        for (Long i = 0; i < min_len - (Long)str.size(); ++i)
            str1 += '0';
        str = str1 + str;
    }
}

inline Str num2str(Char_I s, Long_I min_len = -1)
{
    Str str;
    num2str(str, s, min_len);
    return str;
}

inline void num2str(Str_O str, Int_I s, Long_I min_len = -1)
{
    str = to_string(s);
    // erase trailing zeros
    if (str.find('.') != Str::npos)
        str.erase(str.find_last_not_of('0') + 1);
    // 0 padding on the left
    if (min_len > 0 && (Long)str.size() < min_len) {
        Str str1;
        for (Long i = 0; i < min_len - (Long)str.size(); ++i)
            str1 += '0';
        str = str1 + str;
    }
}

inline Str num2str(Int_I s, Long_I min_len = -1)
{
    Str str;
    num2str(str, s, min_len);
    return str;
}

inline void num2str(Str_O str, Llong_I s, Long_I min_len = -1)
{
    str = to_string(s);
    // erase trailing zeros
    if (str.find('.') != Str::npos)
        str.erase(str.find_last_not_of('0') + 1);
    // 0 padding on the left
    if (min_len > 0 && (Long)str.size() < min_len) {
        Str str1;
        for (Long i = 0; i < min_len - (Long)str.size(); ++i)
            str1 += '0';
        str = str1 + str;
    }
}

inline Str num2str(Llong_I s, Long_I min_len = -1)
{
    Str str;
    num2str(str, s, min_len);
    return str;
}

inline void num2str(Str_O str, Doub_I s, Long_I min_len = -1)
{
    str = to_string(s);
    // erase trailing zeros
    if (str.find('.') != Str::npos)
        str.erase(str.find_last_not_of('0') + 1);
    // 0 padding on the left
    if (min_len > 0 && (Long)str.size() < min_len) {
        Str str1;
        for (Long i = 0; i < min_len - (Long)str.size(); ++i)
            str1 += '0';
        str = str1 + str;
    }
}

inline Str num2str(Doub_I s, Long_I min_len = -1)
{
    Str str;
    num2str(str, s, min_len);
    return str;
}


// trim all occurance of key on the left
// return the number of charaters trimed
// e.g. key = "\n " to trim space and '\n'
inline Long trimL(Str_IO str, Str_I key = " ")
{
    Long N;
    Long ind = str.find_first_not_of(key);
    if (ind < 0) {
        N = str.size();
        str.clear();
        return N;
    }
    N = ind;
    str.erase(0, N);
    return N;
}

// trim all occurance of key on the right
// return the number of charaters trimed
// e.g. key = "\n " to trim space and '\n'
inline Long trimR(Str_IO str, Str_I key = " ")
{
    Long N;
    Long ind = str.find_last_not_of(key);
    if (ind < 0) {
        N = str.size();
        str.clear();
        return N;
    }
    str.erase(ind + 1);
    N = str.size() - ind;
    return N;
}

// trim both sides
// e.g. key = "\n " to trim space and '\n'
inline Long trim(Str_IO str, Str_I key = " ")
{
    return trimL(str, key) + trimR(str, key);
}

// replace every "\r\n" with "\n"
inline Long CRLF_to_LF(Str_IO str)
{
    Long ind0{}, N{};
    while (true) {
        ind0 = str.find("\r\n", ind0);
        if (ind0 < 0) return N;
        str.erase(ind0, 1);
    }
}

} // namespace slisc
