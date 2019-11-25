constexpr Bool operator==(Char_I s1, Fcomp_I s2)
{
	return real(s2) == s1 && imag(s2) == 0;
}

constexpr Bool operator!=(Char_I s1, Fcomp_I s2)
{
    return !(s1 == s2);
}

constexpr Bool operator==(Char_I s1, Comp_I s2)
{
	return real(s2) == s1 && imag(s2) == 0;
}

constexpr Bool operator!=(Char_I s1, Comp_I s2)
{
    return !(s1 == s2);
}

constexpr Bool operator==(Char_I s1, Lcomp_I s2)
{
	return real(s2) == s1 && imag(s2) == 0;
}

constexpr Bool operator!=(Char_I s1, Lcomp_I s2)
{
    return !(s1 == s2);
}

constexpr Bool operator==(Int_I s1, Fcomp_I s2)
{
	return real(s2) == s1 && imag(s2) == 0;
}

constexpr Bool operator!=(Int_I s1, Fcomp_I s2)
{
    return !(s1 == s2);
}

constexpr Bool operator==(Int_I s1, Comp_I s2)
{
	return real(s2) == s1 && imag(s2) == 0;
}

constexpr Bool operator!=(Int_I s1, Comp_I s2)
{
    return !(s1 == s2);
}

constexpr Bool operator==(Int_I s1, Lcomp_I s2)
{
	return real(s2) == s1 && imag(s2) == 0;
}

constexpr Bool operator!=(Int_I s1, Lcomp_I s2)
{
    return !(s1 == s2);
}

constexpr Bool operator==(Llong_I s1, Fcomp_I s2)
{
	return real(s2) == s1 && imag(s2) == 0;
}

constexpr Bool operator!=(Llong_I s1, Fcomp_I s2)
{
    return !(s1 == s2);
}

constexpr Bool operator==(Llong_I s1, Comp_I s2)
{
	return real(s2) == s1 && imag(s2) == 0;
}

constexpr Bool operator!=(Llong_I s1, Comp_I s2)
{
    return !(s1 == s2);
}

constexpr Bool operator==(Llong_I s1, Lcomp_I s2)
{
	return real(s2) == s1 && imag(s2) == 0;
}

constexpr Bool operator!=(Llong_I s1, Lcomp_I s2)
{
    return !(s1 == s2);
}

constexpr Bool operator==(Float_I s1, Comp_I s2)
{
	return real(s2) == s1 && imag(s2) == 0;
}

constexpr Bool operator!=(Float_I s1, Comp_I s2)
{
    return !(s1 == s2);
}

constexpr Bool operator==(Float_I s1, Lcomp_I s2)
{
	return real(s2) == s1 && imag(s2) == 0;
}

constexpr Bool operator!=(Float_I s1, Lcomp_I s2)
{
    return !(s1 == s2);
}

constexpr Bool operator==(Doub_I s1, Fcomp_I s2)
{
	return real(s2) == s1 && imag(s2) == 0;
}

constexpr Bool operator!=(Doub_I s1, Fcomp_I s2)
{
    return !(s1 == s2);
}

constexpr Bool operator==(Doub_I s1, Lcomp_I s2)
{
	return real(s2) == s1 && imag(s2) == 0;
}

constexpr Bool operator!=(Doub_I s1, Lcomp_I s2)
{
    return !(s1 == s2);
}

constexpr Bool operator==(Ldoub_I s1, Fcomp_I s2)
{
	return real(s2) == s1 && imag(s2) == 0;
}

constexpr Bool operator!=(Ldoub_I s1, Fcomp_I s2)
{
    return !(s1 == s2);
}

constexpr Bool operator==(Ldoub_I s1, Comp_I s2)
{
	return real(s2) == s1 && imag(s2) == 0;
}

constexpr Bool operator!=(Ldoub_I s1, Comp_I s2)
{
    return !(s1 == s2);
}

constexpr Bool operator==(Fcomp_I s1, Char_I s2)
{
	return real(s1) == s2 && imag(s1) == 0;
}

constexpr Bool operator!=(Fcomp_I s1, Char_I s2)
{
    return !(s1 == s2);
}

constexpr Bool operator==(Fcomp_I s1, Int_I s2)
{
	return real(s1) == s2 && imag(s1) == 0;
}

constexpr Bool operator!=(Fcomp_I s1, Int_I s2)
{
    return !(s1 == s2);
}

constexpr Bool operator==(Fcomp_I s1, Llong_I s2)
{
	return real(s1) == s2 && imag(s1) == 0;
}

constexpr Bool operator!=(Fcomp_I s1, Llong_I s2)
{
    return !(s1 == s2);
}

constexpr Bool operator==(Fcomp_I s1, Doub_I s2)
{
	return real(s1) == s2 && imag(s1) == 0;
}

constexpr Bool operator!=(Fcomp_I s1, Doub_I s2)
{
    return !(s1 == s2);
}

constexpr Bool operator==(Fcomp_I s1, Ldoub_I s2)
{
	return real(s1) == s2 && imag(s1) == 0;
}

constexpr Bool operator!=(Fcomp_I s1, Ldoub_I s2)
{
    return !(s1 == s2);
}

constexpr Bool operator==(Fcomp_I s1, Comp_I s2)
{
	return real(s1) == real(s2) && imag(s1) == imag(s2);
}

constexpr Bool operator!=(Fcomp_I s1, Comp_I s2)
{
    return !(s1 == s2);
}

constexpr Bool operator==(Fcomp_I s1, Lcomp_I s2)
{
	return real(s1) == real(s2) && imag(s1) == imag(s2);
}

constexpr Bool operator!=(Fcomp_I s1, Lcomp_I s2)
{
    return !(s1 == s2);
}

constexpr Bool operator==(Comp_I s1, Char_I s2)
{
	return real(s1) == s2 && imag(s1) == 0;
}

constexpr Bool operator!=(Comp_I s1, Char_I s2)
{
    return !(s1 == s2);
}

constexpr Bool operator==(Comp_I s1, Int_I s2)
{
	return real(s1) == s2 && imag(s1) == 0;
}

constexpr Bool operator!=(Comp_I s1, Int_I s2)
{
    return !(s1 == s2);
}

constexpr Bool operator==(Comp_I s1, Llong_I s2)
{
	return real(s1) == s2 && imag(s1) == 0;
}

constexpr Bool operator!=(Comp_I s1, Llong_I s2)
{
    return !(s1 == s2);
}

constexpr Bool operator==(Comp_I s1, Float_I s2)
{
	return real(s1) == s2 && imag(s1) == 0;
}

constexpr Bool operator!=(Comp_I s1, Float_I s2)
{
    return !(s1 == s2);
}

constexpr Bool operator==(Comp_I s1, Ldoub_I s2)
{
	return real(s1) == s2 && imag(s1) == 0;
}

constexpr Bool operator!=(Comp_I s1, Ldoub_I s2)
{
    return !(s1 == s2);
}

constexpr Bool operator==(Comp_I s1, Fcomp_I s2)
{
	return real(s1) == real(s2) && imag(s1) == imag(s2);
}

constexpr Bool operator!=(Comp_I s1, Fcomp_I s2)
{
    return !(s1 == s2);
}

constexpr Bool operator==(Comp_I s1, Lcomp_I s2)
{
	return real(s1) == real(s2) && imag(s1) == imag(s2);
}

constexpr Bool operator!=(Comp_I s1, Lcomp_I s2)
{
    return !(s1 == s2);
}

constexpr Bool operator==(Lcomp_I s1, Char_I s2)
{
	return real(s1) == s2 && imag(s1) == 0;
}

constexpr Bool operator!=(Lcomp_I s1, Char_I s2)
{
    return !(s1 == s2);
}

constexpr Bool operator==(Lcomp_I s1, Int_I s2)
{
	return real(s1) == s2 && imag(s1) == 0;
}

constexpr Bool operator!=(Lcomp_I s1, Int_I s2)
{
    return !(s1 == s2);
}

constexpr Bool operator==(Lcomp_I s1, Llong_I s2)
{
	return real(s1) == s2 && imag(s1) == 0;
}

constexpr Bool operator!=(Lcomp_I s1, Llong_I s2)
{
    return !(s1 == s2);
}

constexpr Bool operator==(Lcomp_I s1, Float_I s2)
{
	return real(s1) == s2 && imag(s1) == 0;
}

constexpr Bool operator!=(Lcomp_I s1, Float_I s2)
{
    return !(s1 == s2);
}

constexpr Bool operator==(Lcomp_I s1, Doub_I s2)
{
	return real(s1) == s2 && imag(s1) == 0;
}

constexpr Bool operator!=(Lcomp_I s1, Doub_I s2)
{
    return !(s1 == s2);
}

constexpr Bool operator==(Lcomp_I s1, Fcomp_I s2)
{
	return real(s1) == real(s2) && imag(s1) == imag(s2);
}

constexpr Bool operator!=(Lcomp_I s1, Fcomp_I s2)
{
    return !(s1 == s2);
}

constexpr Bool operator==(Lcomp_I s1, Comp_I s2)
{
	return real(s1) == real(s2) && imag(s1) == imag(s2);
}

constexpr Bool operator!=(Lcomp_I s1, Comp_I s2)
{
    return !(s1 == s2);
}

