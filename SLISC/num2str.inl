inline void num2str(Str_O str, Char_I s)
{
    str = to_string(s);
    // erase trailing zeros
    if (str.find('.') != Str::npos)
        str.erase(str.find_last_not_of('0') + 1);
}

inline Str num2str(Char_I s)
{
    Str str;
    num2str(str, s);
    return str;
}

inline void num2str(Str_O str, Int_I s)
{
    str = to_string(s);
    // erase trailing zeros
    if (str.find('.') != Str::npos)
        str.erase(str.find_last_not_of('0') + 1);
}

inline Str num2str(Int_I s)
{
    Str str;
    num2str(str, s);
    return str;
}

inline void num2str(Str_O str, Llong_I s)
{
    str = to_string(s);
    // erase trailing zeros
    if (str.find('.') != Str::npos)
        str.erase(str.find_last_not_of('0') + 1);
}

inline Str num2str(Llong_I s)
{
    Str str;
    num2str(str, s);
    return str;
}

inline void num2str(Str_O str, Doub_I s)
{
    str = to_string(s);
    // erase trailing zeros
    if (str.find('.') != Str::npos)
        str.erase(str.find_last_not_of('0') + 1);
}

inline Str num2str(Doub_I s)
{
    Str str;
    num2str(str, s);
    return str;
}

