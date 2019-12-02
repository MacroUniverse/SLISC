inline Int abs2(Int_I a)
{
    return a * a;
}

inline Doub abs2(Doub_I a)
{
    return a * a;
}

inline Doub abs2(Comp_I &a)
{
    return sqr(real(a)) + sqr(imag(a));
}

