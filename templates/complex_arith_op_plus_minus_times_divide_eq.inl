// operator+=
constexpr void operator+=(Comp_O &z, Float_I x)
{
    z.real() += x;
}

constexpr void operator-=(Comp_O &z, Float_I x)
{
    z.real() -= x;
}

constexpr void operator*=(Comp_O &z, Float_I x)
{
    z *= (Doub)x;
}

constexpr void operator/=(Comp_O &z, Float_I x)
{
    z /= (Doub)x;
}
// operator+=
constexpr void operator+=(Lcomp_O &z, Float_I x)
{
    z.real() += x;
}

constexpr void operator-=(Lcomp_O &z, Float_I x)
{
    z.real() -= x;
}

constexpr void operator*=(Lcomp_O &z, Float_I x)
{
    z *= (Ldoub)x;
}

constexpr void operator/=(Lcomp_O &z, Float_I x)
{
    z /= (Ldoub)x;
}
// operator+=
constexpr void operator+=(Lcomp_O &z, Comp_I x)
{
    z.real() += x;
}

constexpr void operator-=(Lcomp_O &z, Comp_I x)
{
    z.real() -= x;
}

constexpr void operator*=(Lcomp_O &z, Comp_I x)
{
    z *= (Ldoub)x;
}

constexpr void operator/=(Lcomp_O &z, Comp_I x)
{
    z /= (Ldoub)x;
}
