Bool shape_cmp(VecDoub_I v1, VecDoub_I v2)
{
	return v1.size() == v2.size();
}

Bool shape_cmp(VecComp_I v1, VecComp_I v2)
{
	return v1.size() == v2.size();
}

Bool shape_cmp(CmatDoub_I v1, CmatDoub_I v2)
{
    return v1.n1() == v2.n1() && v1.n2() == v2.n2();
}

Bool shape_cmp(CmatComp_I v1, CmatComp_I v2)
{
    return v1.n1() == v2.n1() && v1.n2() == v2.n2();
}

Bool shape_cmp(Cmat3Doub_I v1, Cmat3Doub_I v2)
{
    return v1.n1() == v2.n1() && v1.n2() == v2.n2();
}

Bool shape_cmp(Cmat4Doub_I v1, Cmat4Doub_I v2)
{
    return v1.n1() == v2.n1() && v1.n2() == v2.n2();
}

Bool shape_cmp(CmatInt_I v1, MatChar_I v2)
{
    return v1.n1() == v2.n1() && v1.n2() == v2.n2();
}

Bool shape_cmp(MatDoub_I v1, CmatDoub_I v2)
{
    return v1.n1() == v2.n1() && v1.n2() == v2.n2();
}

Bool shape_cmp(Mat3Doub_I v1, Mat3Comp_I v2)
{
    return v1.n1() == v2.n1() && v1.n2() == v2.n2();
}

Bool shape_cmp(MatComp_I v1, VecInt_I v2)
{
	return false;
}

Bool shape_cmp(CmatInt_I v1, CmatInt_I v2)
{
    return v1.n1() == v2.n1() && v1.n2() == v2.n2();
}

Bool shape_cmp(Mat3Doub_I v1, Mat3Doub_I v2)
{
    return v1.n1() == v2.n1() && v1.n2() == v2.n2();
}

Bool shape_cmp(DcmatInt_I v1, DcmatInt_I v2)
{
    return v1.n1() == v2.n1() && v1.n2() == v2.n2();
}

Bool shape_cmp(MatComp_I v1, MatComp_I v2)
{
    return v1.n1() == v2.n1() && v1.n2() == v2.n2();
}

Bool shape_cmp(VecComp_I v1, VecLdoub_I v2)
{
	return v1.size() == v2.size();
}

Bool shape_cmp(CmatComp_I v1, MatComp_I v2)
{
    return v1.n1() == v2.n1() && v1.n2() == v2.n2();
}

Bool shape_cmp(DvecDoub_I v1, DvecDoub_I v2)
{
	return v1.size() == v2.size();
}

Bool shape_cmp(VecLdoub_I v1, VecComp_I v2)
{
	return v1.size() == v2.size();
}

Bool shape_cmp(VecDoub_I v1, VecComp_I v2)
{
	return v1.size() == v2.size();
}

Bool shape_cmp(VecInt_I v1, VecInt_I v2)
{
	return v1.size() == v2.size();
}

Bool shape_cmp(VecLcomp_I v1, VecComp_I v2)
{
	return v1.size() == v2.size();
}

Bool shape_cmp(VecComp_I v1, VecLcomp_I v2)
{
	return v1.size() == v2.size();
}

Bool shape_cmp(DvecInt_I v1, DvecInt_I v2)
{
	return v1.size() == v2.size();
}

Bool shape_cmp(VecLlong_I v1, VecLlong_I v2)
{
	return v1.size() == v2.size();
}

Bool shape_cmp(McooInt_I v1, McooInt_I v2)
{
    return v1.n1() == v2.n1() && v1.n2() == v2.n2();
}

Bool shape_cmp(VecLcomp_I v1, VecLcomp_I v2)
{
	return v1.size() == v2.size();
}

Bool shape_cmp(CmatDoub_I v1, MatDoub_I v2)
{
    return v1.n1() == v2.n1() && v1.n2() == v2.n2();
}

Bool shape_cmp(MatInt_I v1, MatInt_I v2)
{
    return v1.n1() == v2.n1() && v1.n2() == v2.n2();
}

Bool shape_cmp(MatDoub_I v1, MatDoub_I v2)
{
    return v1.n1() == v2.n1() && v1.n2() == v2.n2();
}

Bool shape_cmp(Jcmat3Doub_I v1, Cmat3Doub_I v2)
{
    return v1.n1() == v2.n1() && v1.n2() == v2.n2();
}

Bool shape_cmp(DcmatDoub_I v1, CmatDoub_I v2)
{
    return v1.n1() == v2.n1() && v1.n2() == v2.n2();
}

