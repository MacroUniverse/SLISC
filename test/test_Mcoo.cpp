#include "../SLISC/sparse_arith.h"
#include "../SLISC/disp.h"

void test_Mcoo()
{
	using namespace slisc;
	McooDoub a(3, 3, 4);
	a.push(2, 1, 2);
	if (a(1, 2) != 2)
		SLS_ERR("failed!");

	// test sort_col_dry() and reorder()
	{
		McooInt a(4, 4, 16);
		a.push(1, 0, 0); a.push(2, 0, 2);
		a.push(3, 1, 1); a.push(4, 1, 3);
		a.push(5, 2, 0); a.push(6, 2, 2);
		a.push(7, 3, 1); a.push(8, 3, 3);

		a.push(1, 0, 0); a.push(2, 0, 2);
		a.push(3, 1, 1); a.push(4, 1, 3);
		a.push(5, 2, 0); a.push(6, 2, 2);
		a.push(7, 3, 1); a.push(8, 3, 3);

		VecLong dest(a.nnz());
		Long new_Nnz = sort_col_dry(dest, a);
		if (new_Nnz != 8)
			SLS_ERR("failed!");

		vecLong v = {0, 4, 2, 6, 1, 5, 3, 7, 0, 4, 2, 6, 1, 5, 3, 7};
		for (Long i = 0; i < 16; ++i)
			if (v[i] != dest[i])
				SLS_ERR("failed!");
	}
}
