Bool operator==(VecDoub_I v1, VecDoub_I v2)
{
	return shape_cmp(v1, v2) &&
        equals_to_vv(v1.ptr(), v2.ptr(), v2.size());
}

Bool operator!=(VecDoub_I v1, VecDoub_I v2)
{
	return !(v1 == v2);
}

