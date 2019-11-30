inline Bool operator==(VecLlong_I v1, VecLlong_I v2)
{
    return shape_cmp(v1, v2) &&
        equals_to_vv(v1.ptr(), v2.ptr(), v2.size());
}

inline Bool operator!=(VecLlong_I v1, VecLlong_I v2)
{
    return !(v1 == v2);
}

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

inline Bool operator==(MatLlong_I v1, MatLlong_I v2)
{
    return shape_cmp(v1, v2) &&
        equals_to_vv(v1.ptr(), v2.ptr(), v2.size());
}

inline Bool operator!=(MatLlong_I v1, MatLlong_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(MatDoub_I v1, MatDoub_I v2)
{
    return shape_cmp(v1, v2) &&
        equals_to_vv(v1.ptr(), v2.ptr(), v2.size());
}

inline Bool operator!=(MatDoub_I v1, MatDoub_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(MatComp_I v1, MatComp_I v2)
{
    return shape_cmp(v1, v2) &&
        equals_to_vv(v1.ptr(), v2.ptr(), v2.size());
}

inline Bool operator!=(MatComp_I v1, MatComp_I v2)
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

inline Bool operator==(MatDoub_I v1, CmatDoub_I v2)
{
	if (!shape_cmp(v1, v2))
		return false;
    for (Long i = 0; i < v1.n1(); ++i)
        for (Long j = 0; j < v1.n2(); ++j)
            if (v1(i, j) != v2(i, j))
                return false;
    return true;
}

inline Bool operator!=(MatDoub_I v1, CmatDoub_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(CmatDoub_I v1, MatDoub_I v2)
{
	if (!shape_cmp(v1, v2))
		return false;
    for (Long i = 0; i < v1.n1(); ++i)
        for (Long j = 0; j < v1.n2(); ++j)
            if (v1(i, j) != v2(i, j))
                return false;
    return true;
}

inline Bool operator!=(CmatDoub_I v1, MatDoub_I v2)
{
    return !(v1 == v2);
}

