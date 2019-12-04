inline Bool shape_cmp(VecChar_I v1, VecChar_I v2)
{
    return v1.size() == v2.size();
}

inline Bool shape_cmp(VecChar_I v1, VecInt_I v2)
{
    return v1.size() == v2.size();
}

inline Bool shape_cmp(VecChar_I v1, VecLlong_I v2)
{
    return v1.size() == v2.size();
}

inline Bool shape_cmp(VecInt_I v1, VecInt_I v2)
{
    return v1.size() == v2.size();
}

inline Bool shape_cmp(VecInt_I v1, VecLlong_I v2)
{
    return v1.size() == v2.size();
}

inline Bool shape_cmp(VecInt_I v1, DvecInt_I v2)
{
    return v1.size() == v2.size();
}

inline Bool shape_cmp(VecLlong_I v1, DvecLlong_I v2)
{
    return v1.size() == v2.size();
}

inline Bool shape_cmp(VecDoub_I v1, DvecDoub_I v2)
{
    return v1.size() == v2.size();
}

inline Bool shape_cmp(VecLlong_I v1, VecLlong_I v2)
{
    return v1.size() == v2.size();
}

inline Bool shape_cmp(VecDoub_I v1, VecLlong_I v2)
{
    return v1.size() == v2.size();
}

inline Bool shape_cmp(VecDoub_I v1, VecDoub_I v2)
{
    return v1.size() == v2.size();
}

inline Bool shape_cmp(VecComp_I v1, VecDoub_I v2)
{
    return v1.size() == v2.size();
}

inline Bool shape_cmp(VecDoub_I v1, VecComp_I v2)
{
    return v1.size() == v2.size();
}

inline Bool shape_cmp(VecComp_I v1, VecComp_I v2)
{
    return v1.size() == v2.size();
}

inline Bool shape_cmp(MatInt_I v1, MatInt_I v2)
{
    return v1.n1() == v2.n1() && v1.n2() == v2.n2();
}

inline Bool shape_cmp(MatLlong_I v1, MatLlong_I v2)
{
    return v1.n1() == v2.n1() && v1.n2() == v2.n2();
}

inline Bool shape_cmp(MatDoub_I v1, MatDoub_I v2)
{
    return v1.n1() == v2.n1() && v1.n2() == v2.n2();
}

inline Bool shape_cmp(MatComp_I v1, MatComp_I v2)
{
    return v1.n1() == v2.n1() && v1.n2() == v2.n2();
}

inline Bool shape_cmp(CmatInt_I v1, CmatInt_I v2)
{
    return v1.n1() == v2.n1() && v1.n2() == v2.n2();
}

inline Bool shape_cmp(CmatLlong_I v1, CmatLlong_I v2)
{
    return v1.n1() == v2.n1() && v1.n2() == v2.n2();
}

inline Bool shape_cmp(CmatDoub_I v1, CmatDoub_I v2)
{
    return v1.n1() == v2.n1() && v1.n2() == v2.n2();
}

inline Bool shape_cmp(CmatComp_I v1, CmatDoub_I v2)
{
    return v1.n1() == v2.n1() && v1.n2() == v2.n2();
}

inline Bool shape_cmp(CmatComp_I v1, CmatComp_I v2)
{
    return v1.n1() == v2.n1() && v1.n2() == v2.n2();
}

inline Bool shape_cmp(MatDoub_I v1, CmatDoub_I v2)
{
    return v1.n1() == v2.n1() && v1.n2() == v2.n2();
}

inline Bool shape_cmp(CmatDoub_I v1, MatDoub_I v2)
{
    return v1.n1() == v2.n1() && v1.n2() == v2.n2();
}

inline Bool shape_cmp(MatComp_I v1, CmatComp_I v2)
{
    return v1.n1() == v2.n1() && v1.n2() == v2.n2();
}

inline Bool shape_cmp(CmatComp_I v1, MatComp_I v2)
{
    return v1.n1() == v2.n1() && v1.n2() == v2.n2();
}

inline Bool shape_cmp(DcmatDoub_I v1, CmatDoub_I v2)
{
    return v1.n1() == v2.n1() && v1.n2() == v2.n2();
}

inline Bool shape_cmp(Cmat3Doub_I v1, Cmat3Doub_I v2)
{
    return v1.n1() == v2.n1() && v1.n2() == v2.n2()
            && v1.n3() == v2.n3();
}

inline Bool shape_cmp(Cmat3Comp_I v1, Cmat3Comp_I v2)
{
    return v1.n1() == v2.n1() && v1.n2() == v2.n2()
            && v1.n3() == v2.n3();
}

