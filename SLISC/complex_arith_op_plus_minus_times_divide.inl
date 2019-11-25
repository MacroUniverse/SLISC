const Fcomp operator+(Char_I s1, Fcomp_I s2)
{
	return Fcomp(s1 + real(s2), imag(s2));
}

const Fcomp operator-(Char_I s1, Fcomp_I s2)
{
	return Fcomp(s1 - real(s2), -imag(s2));
}

const Fcomp operator*(Char_I s1, Fcomp_I s2)
{
	return Fcomp(s1*real(s2), s1*imag(s2));
}

const Fcomp operator/(Char_I s1, Fcomp_I s2)
{
    return (Float)s1 / s2;
}

const Comp operator+(Char_I s1, Comp_I s2)
{
	return Comp(s1 + real(s2), imag(s2));
}

const Comp operator-(Char_I s1, Comp_I s2)
{
	return Comp(s1 - real(s2), -imag(s2));
}

const Comp operator*(Char_I s1, Comp_I s2)
{
	return Comp(s1*real(s2), s1*imag(s2));
}

const Comp operator/(Char_I s1, Comp_I s2)
{
    return (Doub)s1 / s2;
}

const Lcomp operator+(Char_I s1, Lcomp_I s2)
{
	return Lcomp(s1 + real(s2), imag(s2));
}

const Lcomp operator-(Char_I s1, Lcomp_I s2)
{
	return Lcomp(s1 - real(s2), -imag(s2));
}

const Lcomp operator*(Char_I s1, Lcomp_I s2)
{
	return Lcomp(s1*real(s2), s1*imag(s2));
}

const Lcomp operator/(Char_I s1, Lcomp_I s2)
{
    return (Ldoub)s1 / s2;
}

const Fcomp operator+(Int_I s1, Fcomp_I s2)
{
	return Fcomp(s1 + real(s2), imag(s2));
}

const Fcomp operator-(Int_I s1, Fcomp_I s2)
{
	return Fcomp(s1 - real(s2), -imag(s2));
}

const Fcomp operator*(Int_I s1, Fcomp_I s2)
{
	return Fcomp(s1*real(s2), s1*imag(s2));
}

const Fcomp operator/(Int_I s1, Fcomp_I s2)
{
    return (Float)s1 / s2;
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

const Lcomp operator+(Int_I s1, Lcomp_I s2)
{
	return Lcomp(s1 + real(s2), imag(s2));
}

const Lcomp operator-(Int_I s1, Lcomp_I s2)
{
	return Lcomp(s1 - real(s2), -imag(s2));
}

const Lcomp operator*(Int_I s1, Lcomp_I s2)
{
	return Lcomp(s1*real(s2), s1*imag(s2));
}

const Lcomp operator/(Int_I s1, Lcomp_I s2)
{
    return (Ldoub)s1 / s2;
}

const Fcomp operator+(Llong_I s1, Fcomp_I s2)
{
	return Fcomp(s1 + real(s2), imag(s2));
}

const Fcomp operator-(Llong_I s1, Fcomp_I s2)
{
	return Fcomp(s1 - real(s2), -imag(s2));
}

const Fcomp operator*(Llong_I s1, Fcomp_I s2)
{
	return Fcomp(s1*real(s2), s1*imag(s2));
}

const Fcomp operator/(Llong_I s1, Fcomp_I s2)
{
    return (Float)s1 / s2;
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

const Lcomp operator+(Llong_I s1, Lcomp_I s2)
{
	return Lcomp(s1 + real(s2), imag(s2));
}

const Lcomp operator-(Llong_I s1, Lcomp_I s2)
{
	return Lcomp(s1 - real(s2), -imag(s2));
}

const Lcomp operator*(Llong_I s1, Lcomp_I s2)
{
	return Lcomp(s1*real(s2), s1*imag(s2));
}

const Lcomp operator/(Llong_I s1, Lcomp_I s2)
{
    return (Ldoub)s1 / s2;
}

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

const Lcomp operator+(Float_I s1, Lcomp_I s2)
{
	return Lcomp(s1 + real(s2), imag(s2));
}

const Lcomp operator-(Float_I s1, Lcomp_I s2)
{
	return Lcomp(s1 - real(s2), -imag(s2));
}

const Lcomp operator*(Float_I s1, Lcomp_I s2)
{
	return Lcomp(s1*real(s2), s1*imag(s2));
}

const Lcomp operator/(Float_I s1, Lcomp_I s2)
{
    return (Ldoub)s1 / s2;
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

const Lcomp operator+(Doub_I s1, Lcomp_I s2)
{
	return Lcomp(s1 + real(s2), imag(s2));
}

const Lcomp operator-(Doub_I s1, Lcomp_I s2)
{
	return Lcomp(s1 - real(s2), -imag(s2));
}

const Lcomp operator*(Doub_I s1, Lcomp_I s2)
{
	return Lcomp(s1*real(s2), s1*imag(s2));
}

const Lcomp operator/(Doub_I s1, Lcomp_I s2)
{
    return (Ldoub)s1 / s2;
}

const Lcomp operator+(Ldoub_I s1, Fcomp_I s2)
{
	return Lcomp(s1 + real(s2), imag(s2));
}

const Lcomp operator-(Ldoub_I s1, Fcomp_I s2)
{
	return Lcomp(s1 - real(s2), -imag(s2));
}

const Lcomp operator*(Ldoub_I s1, Fcomp_I s2)
{
	return Lcomp(s1*real(s2), s1*imag(s2));
}

const Lcomp operator/(Ldoub_I s1, Fcomp_I s2)
{
    return s1 / (Lcomp)s2;
}

const Lcomp operator+(Ldoub_I s1, Comp_I s2)
{
	return Lcomp(s1 + real(s2), imag(s2));
}

const Lcomp operator-(Ldoub_I s1, Comp_I s2)
{
	return Lcomp(s1 - real(s2), -imag(s2));
}

const Lcomp operator*(Ldoub_I s1, Comp_I s2)
{
	return Lcomp(s1*real(s2), s1*imag(s2));
}

const Lcomp operator/(Ldoub_I s1, Comp_I s2)
{
    return s1 / (Lcomp)s2;
}

const Fcomp operator+(Fcomp_I s1, Char_I s2)
{
	return Fcomp(real(s1) + s2, imag(s1));
}

const Fcomp operator-(Fcomp_I s1, Char_I s2)
{
	return Fcomp(real(s1) - s2, imag(s1));
}

const Fcomp operator*(Fcomp_I s1, Char_I s2)
{
	return Fcomp(real(s1)*s2, imag(s1)*s2);
}

const Fcomp operator/(Fcomp_I s1, Char_I s2)
{
	return s1 / (Float)s2;
}

const Fcomp operator+(Fcomp_I s1, Int_I s2)
{
	return Fcomp(real(s1) + s2, imag(s1));
}

const Fcomp operator-(Fcomp_I s1, Int_I s2)
{
	return Fcomp(real(s1) - s2, imag(s1));
}

const Fcomp operator*(Fcomp_I s1, Int_I s2)
{
	return Fcomp(real(s1)*s2, imag(s1)*s2);
}

const Fcomp operator/(Fcomp_I s1, Int_I s2)
{
	return s1 / (Float)s2;
}

const Fcomp operator+(Fcomp_I s1, Llong_I s2)
{
	return Fcomp(real(s1) + s2, imag(s1));
}

const Fcomp operator-(Fcomp_I s1, Llong_I s2)
{
	return Fcomp(real(s1) - s2, imag(s1));
}

const Fcomp operator*(Fcomp_I s1, Llong_I s2)
{
	return Fcomp(real(s1)*s2, imag(s1)*s2);
}

const Fcomp operator/(Fcomp_I s1, Llong_I s2)
{
	return s1 / (Float)s2;
}

const Comp operator+(Fcomp_I s1, Doub_I s2)
{
	return Comp(real(s1) + s2, imag(s1));
}

const Comp operator-(Fcomp_I s1, Doub_I s2)
{
	return Comp(real(s1) - s2, imag(s1));
}

const Comp operator*(Fcomp_I s1, Doub_I s2)
{
	return Comp(real(s1)*s2, imag(s1)*s2);
}

const Comp operator/(Fcomp_I s1, Doub_I s2)
{
    return (Comp)s1 / s2;
}

const Lcomp operator+(Fcomp_I s1, Ldoub_I s2)
{
	return Lcomp(real(s1) + s2, imag(s1));
}

const Lcomp operator-(Fcomp_I s1, Ldoub_I s2)
{
	return Lcomp(real(s1) - s2, imag(s1));
}

const Lcomp operator*(Fcomp_I s1, Ldoub_I s2)
{
	return Lcomp(real(s1)*s2, imag(s1)*s2);
}

const Lcomp operator/(Fcomp_I s1, Ldoub_I s2)
{
    return (Lcomp)s1 / s2;
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

const Lcomp operator+(Fcomp_I s1, Lcomp_I s2)
{
	return (Lcomp)s1 + s2;
}

const Lcomp operator-(Fcomp_I s1, Lcomp_I s2)
{
	return (Lcomp)s1 - s2;
}

const Lcomp operator*(Fcomp_I s1, Lcomp_I s2)
{
	return (Lcomp)s1 * s2;
}

const Lcomp operator/(Fcomp_I s1, Lcomp_I s2)
{
	return (Lcomp)s1 / s2;
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

const Lcomp operator+(Comp_I s1, Ldoub_I s2)
{
	return Lcomp(real(s1) + s2, imag(s1));
}

const Lcomp operator-(Comp_I s1, Ldoub_I s2)
{
	return Lcomp(real(s1) - s2, imag(s1));
}

const Lcomp operator*(Comp_I s1, Ldoub_I s2)
{
	return Lcomp(real(s1)*s2, imag(s1)*s2);
}

const Lcomp operator/(Comp_I s1, Ldoub_I s2)
{
    return (Lcomp)s1 / s2;
}

const Comp operator+(Comp_I s1, Fcomp_I s2)
{
	return s1 + (Comp)s2;
}

const Comp operator-(Comp_I s1, Fcomp_I s2)
{
	return s1 - (Comp)s2;
}

const Comp operator*(Comp_I s1, Fcomp_I s2)
{
	return s1 * (Comp)s2;
}

const Comp operator/(Comp_I s1, Fcomp_I s2)
{
	return s1 / (Comp)s2;
}

const Lcomp operator+(Comp_I s1, Lcomp_I s2)
{
	return (Lcomp)s1 + s2;
}

const Lcomp operator-(Comp_I s1, Lcomp_I s2)
{
	return (Lcomp)s1 - s2;
}

const Lcomp operator*(Comp_I s1, Lcomp_I s2)
{
	return (Lcomp)s1 * s2;
}

const Lcomp operator/(Comp_I s1, Lcomp_I s2)
{
	return (Lcomp)s1 / s2;
}

const Lcomp operator+(Lcomp_I s1, Char_I s2)
{
	return Lcomp(real(s1) + s2, imag(s1));
}

const Lcomp operator-(Lcomp_I s1, Char_I s2)
{
	return Lcomp(real(s1) - s2, imag(s1));
}

const Lcomp operator*(Lcomp_I s1, Char_I s2)
{
	return Lcomp(real(s1)*s2, imag(s1)*s2);
}

const Lcomp operator/(Lcomp_I s1, Char_I s2)
{
	return s1 / (Ldoub)s2;
}

const Lcomp operator+(Lcomp_I s1, Int_I s2)
{
	return Lcomp(real(s1) + s2, imag(s1));
}

const Lcomp operator-(Lcomp_I s1, Int_I s2)
{
	return Lcomp(real(s1) - s2, imag(s1));
}

const Lcomp operator*(Lcomp_I s1, Int_I s2)
{
	return Lcomp(real(s1)*s2, imag(s1)*s2);
}

const Lcomp operator/(Lcomp_I s1, Int_I s2)
{
	return s1 / (Ldoub)s2;
}

const Lcomp operator+(Lcomp_I s1, Llong_I s2)
{
	return Lcomp(real(s1) + s2, imag(s1));
}

const Lcomp operator-(Lcomp_I s1, Llong_I s2)
{
	return Lcomp(real(s1) - s2, imag(s1));
}

const Lcomp operator*(Lcomp_I s1, Llong_I s2)
{
	return Lcomp(real(s1)*s2, imag(s1)*s2);
}

const Lcomp operator/(Lcomp_I s1, Llong_I s2)
{
	return s1 / (Ldoub)s2;
}

const Lcomp operator+(Lcomp_I s1, Float_I s2)
{
	return Lcomp(real(s1) + s2, imag(s1));
}

const Lcomp operator-(Lcomp_I s1, Float_I s2)
{
	return Lcomp(real(s1) - s2, imag(s1));
}

const Lcomp operator*(Lcomp_I s1, Float_I s2)
{
	return Lcomp(real(s1)*s2, imag(s1)*s2);
}

const Lcomp operator/(Lcomp_I s1, Float_I s2)
{
	return s1 / (Ldoub)s2;
}

const Lcomp operator+(Lcomp_I s1, Doub_I s2)
{
	return Lcomp(real(s1) + s2, imag(s1));
}

const Lcomp operator-(Lcomp_I s1, Doub_I s2)
{
	return Lcomp(real(s1) - s2, imag(s1));
}

const Lcomp operator*(Lcomp_I s1, Doub_I s2)
{
	return Lcomp(real(s1)*s2, imag(s1)*s2);
}

const Lcomp operator/(Lcomp_I s1, Doub_I s2)
{
	return s1 / (Ldoub)s2;
}

const Lcomp operator+(Lcomp_I s1, Fcomp_I s2)
{
	return s1 + (Lcomp)s2;
}

const Lcomp operator-(Lcomp_I s1, Fcomp_I s2)
{
	return s1 - (Lcomp)s2;
}

const Lcomp operator*(Lcomp_I s1, Fcomp_I s2)
{
	return s1 * (Lcomp)s2;
}

const Lcomp operator/(Lcomp_I s1, Fcomp_I s2)
{
	return s1 / (Lcomp)s2;
}

const Lcomp operator+(Lcomp_I s1, Comp_I s2)
{
	return s1 + (Lcomp)s2;
}

const Lcomp operator-(Lcomp_I s1, Comp_I s2)
{
	return s1 - (Lcomp)s2;
}

const Lcomp operator*(Lcomp_I s1, Comp_I s2)
{
	return s1 * (Lcomp)s2;
}

const Lcomp operator/(Lcomp_I s1, Comp_I s2)
{
	return s1 / (Lcomp)s2;
}

