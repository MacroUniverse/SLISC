inline Bool shape_cmp(VecDoub_I v1, VecDoub_I v2)
{
    return v1.size() == v2.size();
}

inline Bool shape_cmp(VecComp_I v1, VecComp_I v2)
{
    return v1.size() == v2.size();
}

inline Bool shape_cmp(CmatDoub_I v1, CmatDoub_I v2)
{
    return v1.n1() == v2.n1() && v1.n2() == v2.n2();
}

inline Bool shape_cmp(CmatComp_I v1, CmatComp_I v2)
{
    return v1.n1() == v2.n1() && v1.n2() == v2.n2();
}

