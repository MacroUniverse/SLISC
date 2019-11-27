void copy(VecDoub_O v, Doub_I s)
{
    vecset(v.ptr(), s, v.size());
}

void copy(VecInt_O v, Int_I s)
{
    vecset(v.ptr(), s, v.size());
}

void copy(SvecDoub_O v, Doub_I s)
{
    vecset(v.ptr(), s, v.size());
}

void copy(SvecComp_O v, Comp_I s)
{
    vecset(v.ptr(), s, v.size());
}

void copy(DvecDoub_O v, Doub_I s)
{
    vecset(v.ptr(), s, v.size(), v.step());
}

void copy(DvecComp_O v, Comp_I s)
{
    vecset(v.ptr(), s, v.size(), v.step());
}

void copy(CmatDoub_O v, Doub_I s)
{
    vecset(v.ptr(), s, v.size());
}

void copy(CmatComp_O v, Comp_I s)
{
    vecset(v.ptr(), s, v.size());
}

void copy(ScmatDoub_O v, Doub_I s)
{
    vecset(v.ptr(), s, v.size());
}

void copy(ScmatComp_O v, Comp_I s)
{
    vecset(v.ptr(), s, v.size());
}

void copy(DcmatDoub_O v, Doub_I s)
{
    Long N1 = v.n1(), N2 = v.n2();
    for (Long j = 0; j < N2; ++j)
        vecset(&v(0, j), s, N1);
}

void copy(DcmatComp_O v, Comp_I s)
{
    Long N1 = v.n1(), N2 = v.n2();
    for (Long j = 0; j < N2; ++j)
        vecset(&v(0, j), s, N1);
}

void copy(MatDoub_O v, Doub_I s)
{
    vecset(v.ptr(), s, v.size());
}

void copy(Mat3Doub_O v, Doub_I s)
{
    vecset(v.ptr(), s, v.size());
}

void copy(Cmat3Doub_O v, Doub_I s)
{
    vecset(v.ptr(), s, v.size());
}

