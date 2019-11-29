#pragma once
#include "../SLISC/Vec.h"

void test_Vec()
{
    using namespace slisc;

    // size initialize
    VecDoub vDoub(3);
	if (vDoub.size() != 3)
		SLS_ERR("failed!");
	if (vDoub.ptr() != &vDoub[0])
		SLS_ERR("failed!");

	// resize
    vDoub.resize(0);
    if (vDoub.size() != 0)
		SLS_ERR("failed!");
    vDoub.resize(4);
    if (vDoub.size() != 4)
		SLS_ERR("failed!");
    if (vDoub.ptr() != &vDoub[0])
		SLS_ERR("failed!");
}
