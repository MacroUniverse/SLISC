#pragma once
#include "../SLISC/copy.h"

void test_copy()
{
    using namespace slisc;
	// scalar to container
	{
		VecDoub vDoub(3);
		VecDoub vDoub1(vDoub.size());
		copy(vDoub1, 2.);
		copy(vDoub, vDoub1);
		if (vDoub != vDoub1)
			SLS_ERR("failed!");
	}
}
