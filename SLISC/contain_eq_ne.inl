inline Bool operator==(VecDoub_I v1, VecDoub_I v2)
{
    return shape_cmp(v1, v2) &&
        equals_to_vv(v1.ptr(), v2.ptr(), v2.size());
}

inline Bool operator!=(VecDoub_I v1, VecDoub_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(VecComp_I v1, VecComp_I v2)
{
    return shape_cmp(v1, v2) &&
        equals_to_vv(v1.ptr(), v2.ptr(), v2.size());
}

inline Bool operator!=(VecComp_I v1, VecComp_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(CmatDoub_I v1, CmatDoub_I v2)
{
    return shape_cmp(v1, v2) &&
        equals_to_vv(v1.ptr(), v2.ptr(), v2.size());
}

inline Bool operator!=(CmatDoub_I v1, CmatDoub_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(CmatComp_I v1, CmatComp_I v2)
{
    return shape_cmp(v1, v2) &&
        equals_to_vv(v1.ptr(), v2.ptr(), v2.size());
}

inline Bool operator!=(CmatComp_I v1, CmatComp_I v2)
{
    return !(v1 == v2);
}

