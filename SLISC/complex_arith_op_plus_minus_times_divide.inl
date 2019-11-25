const Comp operator+(Float_I s1, Comp_I s2)
{
	return Comp(s1 + real(s2), imag(s2));
}

const Comp operator-(Float_I s1, Comp_I s2)
{
	return Comp(s1 - real(s2), -imag(s2));
}

const Comp operator*(Float_I s1, Comp_I s2)
{
	return Comp(s1*real(s2), s1*imag(s2));
}

const Comp operator/(Float_I s1, Comp_I s2)
{
    return (Doub)s1 / s2;
}

const Comp operator+(Comp_I s1, Int_I s2)
{
	return Comp(real(s1) + s2, imag(s1));
}

const Comp operator-(Comp_I s1, Int_I s2)
{
	return Comp(real(s1) - s2, imag(s1));
}

const Comp operator*(Comp_I s1, Int_I s2)
{
	return Comp(real(s1)*s2, imag(s1)*s2);
}

const Comp operator/(Comp_I s1, Int_I s2)
{
	return s1 / (Doub)s2;
}

const Comp operator+(Int_I s1, Comp_I s2)
{
	return Comp(s1 + real(s2), imag(s2));
}

const Comp operator-(Int_I s1, Comp_I s2)
{
	return Comp(s1 - real(s2), -imag(s2));
}

const Comp operator*(Int_I s1, Comp_I s2)
{
	return Comp(s1*real(s2), s1*imag(s2));
}

const Comp operator/(Int_I s1, Comp_I s2)
{
    return (Doub)s1 / s2;
}

const Comp operator+(Llong_I s1, Comp_I s2)
{
	return Comp(s1 + real(s2), imag(s2));
}

const Comp operator-(Llong_I s1, Comp_I s2)
{
	return Comp(s1 - real(s2), -imag(s2));
}

const Comp operator*(Llong_I s1, Comp_I s2)
{
	return Comp(s1*real(s2), s1*imag(s2));
}

const Comp operator/(Llong_I s1, Comp_I s2)
{
    return (Doub)s1 / s2;
}

const Comp operator+(Comp_I s1, Llong_I s2)
{
	return Comp(real(s1) + s2, imag(s1));
}

const Comp operator-(Comp_I s1, Llong_I s2)
{
	return Comp(real(s1) - s2, imag(s1));
}

const Comp operator*(Comp_I s1, Llong_I s2)
{
	return Comp(real(s1)*s2, imag(s1)*s2);
}

const Comp operator/(Comp_I s1, Llong_I s2)
{
	return s1 / (Doub)s2;
}

const Comp operator+(Comp_I s1, Char_I s2)
{
	return Comp(real(s1) + s2, imag(s1));
}

const Comp operator-(Comp_I s1, Char_I s2)
{
	return Comp(real(s1) - s2, imag(s1));
}

const Comp operator*(Comp_I s1, Char_I s2)
{
	return Comp(real(s1)*s2, imag(s1)*s2);
}

const Comp operator/(Comp_I s1, Char_I s2)
{
	return s1 / (Doub)s2;
}

const Comp operator+(Comp_I s1, Float_I s2)
{
	return Comp(real(s1) + s2, imag(s1));
}

const Comp operator-(Comp_I s1, Float_I s2)
{
	return Comp(real(s1) - s2, imag(s1));
}

const Comp operator*(Comp_I s1, Float_I s2)
{
	return Comp(real(s1)*s2, imag(s1)*s2);
}

const Comp operator/(Comp_I s1, Float_I s2)
{
	return s1 / (Doub)s2;
}

const Comp operator+(Doub_I s1, Fcomp_I s2)
{
	return Comp(s1 + real(s2), imag(s2));
}

const Comp operator-(Doub_I s1, Fcomp_I s2)
{
	return Comp(s1 - real(s2), -imag(s2));
}

const Comp operator*(Doub_I s1, Fcomp_I s2)
{
	return Comp(s1*real(s2), s1*imag(s2));
}

const Comp operator/(Doub_I s1, Fcomp_I s2)
{
    return s1 / (Comp)s2;
}

const Comp operator+(Fcomp_I s1, Comp_I s2)
{
	return (Comp)s1 + s2;
}

const Comp operator-(Fcomp_I s1, Comp_I s2)
{
	return (Comp)s1 - s2;
}

const Comp operator*(Fcomp_I s1, Comp_I s2)
{
	return (Comp)s1 * s2;
}

const Comp operator/(Fcomp_I s1, Comp_I s2)
{
	return (Comp)s1 / s2;
}

