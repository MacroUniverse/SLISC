inline Long search(Int_I elm, VecInt_I vec, Long start = 0)
{
    for (Long i = start; i < Size(vec); ++i) {
        if (elm == vec[i])
            return i;
    }
    return -1;
}

inline Long search(Llong_I elm, VecLong_I vec, Long start = 0)
{
    for (Long i = start; i < Size(vec); ++i) {
        if (elm == vec[i])
            return i;
    }
    return -1;
}

inline Long search(Str_I elm, vecStr_I vec, Long start = 0)
{
    for (Long i = start; i < Size(vec); ++i) {
        if (elm == vec[i])
            return i;
    }
    return -1;
}

