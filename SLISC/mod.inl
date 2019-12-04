inline Int mod(Int_I i, Int_I n)
{
    return (i % n + n) % n;
}

inline Llong mod(Llong_I i, Llong_I n)
{
    return (i % n + n) % n;
}

inline Llong mod(Llong_I i, Int_I n)
{
    return (i % n + n) % n;
}

// s = n * d + return
inline Doub mod(Long_O n, Doub_I s, Doub_I d)
{
    n = floor(s/d);
    return s - n * d;
}

inline Doub mod(Doub_I s, Doub_I d)
{
    return s - floor(s/d) * d;
}

