inline constexpr Bool operator==(Float_I s1, Comp_I s2)
{
    return real(s2) == s1 && imag(s2) == 0;
}

inline constexpr Bool operator!=(Float_I s1, Comp_I s2)
{
    return !(s1 == s2);
}

inline constexpr Bool operator==(Fcomp_I s1, Comp_I s2)
{
    return real(s1) == real(s2) && imag(s1) == imag(s2);
}

inline constexpr Bool operator!=(Fcomp_I s1, Comp_I s2)
{
    return !(s1 == s2);
}

inline constexpr Bool operator==(Comp_I s1, Int_I s2)
{
    return real(s1) == s2 && imag(s1) == 0;
}

inline constexpr Bool operator!=(Comp_I s1, Int_I s2)
{
    return !(s1 == s2);
}

inline constexpr Bool operator==(Int_I s1, Comp_I s2)
{
    return real(s2) == s1 && imag(s2) == 0;
}

inline constexpr Bool operator!=(Int_I s1, Comp_I s2)
{
    return !(s1 == s2);
}

inline constexpr Bool operator==(Lcomp_I s1, Comp_I s2)
{
    return real(s1) == real(s2) && imag(s1) == imag(s2);
}

inline constexpr Bool operator!=(Lcomp_I s1, Comp_I s2)
{
    return !(s1 == s2);
}

