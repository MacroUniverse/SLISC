#include "../SLISC/sparse_arith.h"
#include "../SLISC/disp.h"
#include "../SLISC/random.h"
#include "../SLISC/arith4.h"

void test_Mcoo()
{
	using namespace slisc;
	McooDoub a(3, 3, 4);
	a.push(2, 1, 2);
	if (a(1, 2) != 2)
		SLS_FAIL;

	// test sort_col_dry() and reorder() and sort_col()
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
			SLS_FAIL;

		vecLong v = {0, 4, 2, 6, 1, 5, 3, 7, 0, 4, 2, 6, 1, 5, 3, 7};
		for (Long i = 0; i < 16; ++i)
			if (v[i] != dest[i])
				SLS_FAIL;
		
		CmatInt b(4,4), c(4, 4);
		copy(b, a);
		sort_col(a);
		SLS_ASSERT(a.nnz() == new_Nnz);
		copy(c, a);
		SLS_ASSERT(b == c);

		// test reserve() and reserve_cpy()
		a.reserve_cpy(10);
		SLS_ASSERT(a.nnz() == new_Nnz);
		SLS_ASSERT(a.capacity() == 10);
		copy(c, a);
		SLS_ASSERT(b == c);
	}

	// test +=, -=
	{
		McooInt a(4, 5, 40), b(4, 5, 20);
		a.resize(20); b.resize(20);
		for (Long i = 0; i < 20; ++i) {
			a[i] = randInt(30); a.row(i) = randInt(4); a.col(i) = randInt(5);
			b[i] = randInt(30); b.row(i) = randInt(4); b.col(i) = randInt(5);
		}
		CmatInt a1(4,5), b1(4,5), a2(4,5);
		copy(a1, a); copy(b1, b); a1 += b1;
		a += b; copy(a2, a);
		SLS_ASSERT(a2 == a1);

		a1 -= b1;
		sort_col(a); sort_col(b); a.reserve_cpy(40);
		a -= b; copy(a2, a);
		SLS_ASSERT(a2 == a1);
	}

	// rm_zero
	{
		McooInt a(3, 3, 9);
		a.push(1, 1, 2); a.push(0, 2, 0); a.push(2, 2, 1); a.push(3, 0, 2);
		rm_zero(a);
		SLS_ASSERT(a.nnz() == 3 && a[0] == 1 && a[1] == 2 && a[2] == 3);
		SLS_ASSERT(a.row(0) == 1 && a.row(1) == 2 && a.row(2) == 0);
		SLS_ASSERT(a.col(0) == 2 && a.col(1) == 1 && a.col(2) == 2);
	}

	// rm_zero
	{
		McooInt a(3, 3, 9), b(3, 3, 9);
		a.push(1, 1, 2); a.push(0, 2, 0); a.push(2, 2, 1); a.push(3, 0, 2);
		b.push(3, 0, 2); b.push(100, 2, 0); b.push(1, 1, 2); b.push(2, 2, 1); b.push(-100, 2, 0);
		SLS_ASSERT(a == b);
	}
}
