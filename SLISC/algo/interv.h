// interval algorithms
// an interval is represented by two numbers e.g. Long interv[2]
// interv[0] is the left bound and interv[1] is the right bound
// an interval can represent, e.g. a sub vector of a vector,
// elements at the bounds are included.

#pragma once
#include "../algo/sort.h"

namespace slisc {

class Intvs;
typedef const Intvs &Intvs_I;
typedef Intvs &Intvs_O, &Intvs_IO;

class Intvs : public vecLong
{
public:
	typedef vecLong Base;
	void push(Long_I left, Long_I right);
	void pushL(Long_I i);
	void pushR(Long_I i);
	void push_back(Long_I i);
	void check_pair() const;
	Long size() const;
	const Long &L(Long_I i) const;
	Long &L(Long_I i);
	const Long &R(Long_I i) const;
	Long &R(Long_I i);
	const Long &operator[](Long_I i) const;
	Long &operator[](Long_I i);
	void erase(Long_I start, Long_I count = 1);
};

inline void Intvs::push(Long_I left, Long_I right)
{
#ifdef SLS_CHECK_BOUNDS
	if (left < 0 || right < 0)
		SLS_ERR("must be non-negative!");
	if (isodd((Long)Base::size()))
		SLS_ERR("last pair not finished!");
#endif
	push_back(left);
	push_back(right);
}

inline void Intvs::pushL(Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0)
		SLS_ERR("must be non-negative!");
	if (isodd((Long)Base::size()))
		SLS_ERR("last pair not finished!");
#endif
	push_back(i);
}

inline void Intvs::pushR(Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0)
		SLS_ERR("must be non-negative!");
	if (!isodd((Long)Base::size()))
		SLS_ERR("left not pushed!");
#endif
	push_back(i);
}

inline void Intvs::push_back(Long_I i)
{
	Base::push_back(i);
}

inline void Intvs::check_pair() const
{
	if (isodd((Long)Base::size()))
		SLS_ERR("side is odd!");
}

inline Long Intvs::size() const
{
	if (isodd((Long)Base::size()))
		SLS_ERR("last pair unfinished!");
	return Base::size() / 2;
}

inline const Long &Intvs::L(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i * 2 >= (Long)Base::size())
		SLS_ERR("out of bound!");
#endif
	return Base::operator[](i * 2);
}

inline Long &Intvs::L(Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i * 2 >= (Long)Base::size())
		SLS_ERR("out of bound!");
#endif
	return Base::operator[](i * 2);
}

inline const Long &Intvs::R(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i * 2 + 1 >= (Long)Base::size())
		SLS_ERR("out of bound!");
#endif
	return Base::operator[](i * 2 + 1);
}

inline Long &Intvs::R(Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i * 2 + 1 >= (Long)Base::size())
		SLS_ERR("out of bound!");
#endif
	return Base::operator[](i * 2 + 1);
}

inline const Long &Intvs::operator[](Long_I i) const
{
	SLS_ERR("use .L() or .R() instead!");
	return Base::operator[](i);
}

inline Long &Intvs::operator[](Long_I i)
{
	SLS_ERR("use .L() or .R() instead!");
	return Base::operator[](i);
}

inline void Intvs::erase(Long_I start, Long_I count)
{
	auto temp = Base::begin() + 2 * start;
	Base::erase(temp, temp + 2 * count);
}

// see if an index i falls into the scopes of intv
inline bool is_in(Long_I i, Intvs_I intv)
{
	for (Long j = 0; j < intv.size(); ++j) {
		if (intv.L(j) <= i && i <= intv.R(j))
			return true;
	}
	return false;
}

// if is_in() is true, return the number of interval
// if not true, return -1
inline Long is_in_no(Long_I i, Intvs_I intv)
{
	for (Long j = 0; j < intv.size(); ++j) {
		if (intv.L(j) <= i && i <= intv.R(j))
			return j;
	}
	return -1;
}

// invert ranges in intv0, output to intv1
// [0, N-1] is the total domain
Long invert(Intvs_O intv, Intvs_I intv0, Long_I N)
{
	intv.clear();
	if (intv0.size() == 0) {
		intv.push(0, N - 1);
		return 1;
	}

	Long count{}; // total num of ranges output
	if (intv0.L(0) > 0) {
		intv.push(0, intv0.L(0) - 1); ++count;
	}
	for (Long i = 0; i < intv0.size()-1; ++i) {
		intv.push(intv0.R(i) + 1, intv0.L(i+1) - 1);
		++count;
	}
	if (intv0.back() < N - 1) {
		intv.push(intv0.back() + 1, N - 1); ++count;
	}
	return count;
}

// combine ranges intv1 and intv2
// a range can contain another range, but not partial overlap
// return total range number
inline Long combine(Intvs_O intv, Intvs_I intv1, Intvs_I intv2)
{
	Long i, N1 = intv1.size(), N2 = intv2.size();
	intv1.check_pair(); intv2.check_pair();
	if (&intv == &intv1 || &intv == &intv2) {
		SLS_ERR("aliasing is not allowed!");
	}
	if (N1 == 0) {
		intv = intv2; return N2;
	}
	else if (N2 == 0) {
		intv = intv1; return N1;
	}

	// load start and end, and sort
	vecLong start, end;
	for (i = 0; i < N1; ++i)
		start.push_back(intv1.L(i));
	for (i = 0; i < N1; ++i)
		end.push_back(intv1.R(i));
	for (i = 0; i < N2; ++i)
		start.push_back(intv2.L(i));
	for (i = 0; i < N2; ++i)
		end.push_back(intv2.R(i));
	sort(start, end);

	// load intv
	intv.clear();
	intv.pushL(start[0]);
	i = 0;
	while (i < size(start) - 1) {
		if (end[i] > start[i + 1]) {
			if (end[i] > end[i + 1]) {
				end[i + 1] = end[i]; ++i;
			}
			else {
				throw runtime_error("error! range overlap!");
			}
		}
		else if (end[i] == start[i + 1] - 1)
			++i;
		else {
			intv.pushR(end[i]);
			intv.pushL(start[i + 1]);
			++i;
		}
	}
	intv.pushR(end.back());
	return intv.size();
}

// combine intervals intv and intv1, and assign the result to intv
inline Long combine(Intvs_IO intv, Intvs_I intv1)
{
	Intvs temp;
	Long ret = combine(temp, intv, intv1);
	intv = temp;
	return ret;
}

// exclude intervals in `intv` that's completely insize `intv1`
// throw error on partial overlapping
inline void exclude(Intvs_IO intv, Intvs_I intv1)
{
	Long N = intv.size();
	for (Long i = 0; i < N; ++i) {
		if (is_in(intv.L(i), intv1)) {
			if (is_in(intv.R(i), intv1))
				intv.erase(i), --i; // erase is not very efficient
			else
				throw runtime_error("intv[" + to_string(i) + "] partial overlap on the left!");
		}
		else if (is_in(intv.R(i), intv1))
			throw runtime_error("intv[" + to_string(i) + "] partial overlap on the right!");
	}
}

} // namespace slisc
