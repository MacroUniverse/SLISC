#pragma once
#include "Vec.h"
#include "Mat.h"
#include "Mat3.h"
#include "Cmat.h"
#include "Cmat3.h"
#include "Mcoo.h"
#include "Svec.h"
#include "Dvec.h"
#include "Scmat.h"
#include "Dcmat.h"

namespace slisc {
inline Bool equals_to_vs(const Llong *v, Llong_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        if (v[i] != s)
            return false;
    return true;
}

inline Bool equals_to_vs(const Doub *v, Doub_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        if (v[i] != s)
            return false;
    return true;
}

inline Bool equals_to_vs(const Comp *v, Comp_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        if (v[i] != s)
            return false;
    return true;
}


inline Bool equals_to_vv(const Int *v1, const Int *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        if (v1[i] != v2[i])
            return false;
    return true;
}

inline Bool equals_to_vv(const Llong *v1, const Llong *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        if (v1[i] != v2[i])
            return false;
    return true;
}

inline Bool equals_to_vv(const Doub *v1, const Llong *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        if (v1[i] != v2[i])
            return false;
    return true;
}

inline Bool equals_to_vv(const Doub *v1, const Doub *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        if (v1[i] != v2[i])
            return false;
    return true;
}

inline Bool equals_to_vv(const Comp *v1, const Doub *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        if (v1[i] != v2[i])
            return false;
    return true;
}

inline Bool equals_to_vv(const Comp *v1, const Comp *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        if (v1[i] != v2[i])
            return false;
    return true;
}


inline Bool shape_cmp(VecChar_I v1, VecChar_I v2)
{
    return v1.size() == v2.size();
}

inline Bool shape_cmp(VecChar_I v1, VecInt_I v2)
{
    return v1.size() == v2.size();
}

inline Bool shape_cmp(VecChar_I v1, VecLlong_I v2)
{
    return v1.size() == v2.size();
}

inline Bool shape_cmp(VecInt_I v1, VecInt_I v2)
{
    return v1.size() == v2.size();
}

inline Bool shape_cmp(VecInt_I v1, VecLlong_I v2)
{
    return v1.size() == v2.size();
}

inline Bool shape_cmp(VecInt_I v1, SvecInt_I v2)
{
    return v1.size() == v2.size();
}

inline Bool shape_cmp(VecInt_I v1, DvecInt_I v2)
{
    return v1.size() == v2.size();
}

inline Bool shape_cmp(VecLlong_I v1, DvecLlong_I v2)
{
    return v1.size() == v2.size();
}

inline Bool shape_cmp(VecDoub_I v1, DvecDoub_I v2)
{
    return v1.size() == v2.size();
}

inline Bool shape_cmp(VecLlong_I v1, VecLlong_I v2)
{
    return v1.size() == v2.size();
}

inline Bool shape_cmp(VecDoub_I v1, VecLlong_I v2)
{
    return v1.size() == v2.size();
}

inline Bool shape_cmp(VecDoub_I v1, VecDoub_I v2)
{
    return v1.size() == v2.size();
}

inline Bool shape_cmp(VecComp_I v1, VecDoub_I v2)
{
    return v1.size() == v2.size();
}

inline Bool shape_cmp(VecDoub_I v1, VecComp_I v2)
{
    return v1.size() == v2.size();
}

inline Bool shape_cmp(VecComp_I v1, VecComp_I v2)
{
    return v1.size() == v2.size();
}

inline Bool shape_cmp(MatInt_I v1, MatInt_I v2)
{
    return v1.n1() == v2.n1() && v1.n2() == v2.n2();
}

inline Bool shape_cmp(MatLlong_I v1, MatLlong_I v2)
{
    return v1.n1() == v2.n1() && v1.n2() == v2.n2();
}

inline Bool shape_cmp(MatDoub_I v1, MatDoub_I v2)
{
    return v1.n1() == v2.n1() && v1.n2() == v2.n2();
}

inline Bool shape_cmp(MatComp_I v1, MatComp_I v2)
{
    return v1.n1() == v2.n1() && v1.n2() == v2.n2();
}

inline Bool shape_cmp(Mat3Doub_I v1, Mat3Comp_I v2)
{
    return v1.n1() == v2.n1() && v1.n2() == v2.n2()
            && v1.n3() == v2.n3();
}

inline Bool shape_cmp(CmatInt_I v1, CmatInt_I v2)
{
    return v1.n1() == v2.n1() && v1.n2() == v2.n2();
}

inline Bool shape_cmp(CmatInt_I v1, MatChar_I v2)
{
    return v1.n1() == v2.n1() && v1.n2() == v2.n2();
}

inline Bool shape_cmp(CmatLlong_I v1, CmatLlong_I v2)
{
    return v1.n1() == v2.n1() && v1.n2() == v2.n2();
}

inline Bool shape_cmp(CmatDoub_I v1, CmatDoub_I v2)
{
    return v1.n1() == v2.n1() && v1.n2() == v2.n2();
}

inline Bool shape_cmp(CmatComp_I v1, CmatDoub_I v2)
{
    return v1.n1() == v2.n1() && v1.n2() == v2.n2();
}

inline Bool shape_cmp(CmatComp_I v1, CmatComp_I v2)
{
    return v1.n1() == v2.n1() && v1.n2() == v2.n2();
}

inline Bool shape_cmp(MatDoub_I v1, CmatDoub_I v2)
{
    return v1.n1() == v2.n1() && v1.n2() == v2.n2();
}

inline Bool shape_cmp(CmatDoub_I v1, MatDoub_I v2)
{
    return v1.n1() == v2.n1() && v1.n2() == v2.n2();
}

inline Bool shape_cmp(MatComp_I v1, CmatComp_I v2)
{
    return v1.n1() == v2.n1() && v1.n2() == v2.n2();
}

inline Bool shape_cmp(CmatComp_I v1, MatComp_I v2)
{
    return v1.n1() == v2.n1() && v1.n2() == v2.n2();
}

inline Bool shape_cmp(DcmatDoub_I v1, CmatDoub_I v2)
{
    return v1.n1() == v2.n1() && v1.n2() == v2.n2();
}

inline Bool shape_cmp(Cmat3Doub_I v1, Cmat3Doub_I v2)
{
    return v1.n1() == v2.n1() && v1.n2() == v2.n2()
            && v1.n3() == v2.n3();
}

inline Bool shape_cmp(Cmat3Comp_I v1, Cmat3Comp_I v2)
{
    return v1.n1() == v2.n1() && v1.n2() == v2.n2()
            && v1.n3() == v2.n3();
}

inline Bool shape_cmp(McooDoub_I v1, McooDoub_I v2)
{
    return v1.n1() == v2.n1() && v1.n2() == v2.n2();
}

inline Bool shape_cmp(CmatDoub_I v1, McooDoub_I v2)
{
    return v1.n1() == v2.n1() && v1.n2() == v2.n2();
}

inline Bool shape_cmp(McooDoub_I v1, CmatDoub_I v2)
{
    return v1.n1() == v2.n1() && v1.n2() == v2.n2();
}

inline Bool shape_cmp(CmatComp_I v1, McooComp_I v2)
{
    return v1.n1() == v2.n1() && v1.n2() == v2.n2();
}

inline Bool shape_cmp(McooComp_I v1, CmatComp_I v2)
{
    return v1.n1() == v2.n1() && v1.n2() == v2.n2();
}

inline Bool shape_cmp(McooComp_I v1, McooComp_I v2)
{
    return v1.n1() == v2.n1() && v1.n2() == v2.n2();
}


inline Bool operator==(VecInt_I v1, VecInt_I v2)
{
    return shape_cmp(v1, v2) &&
        equals_to_vv(v1.ptr(), v2.ptr(), v2.size());
}

inline Bool operator!=(VecInt_I v1, VecInt_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(VecInt_I v1, DvecInt_I v2)
{
	if (!shape_cmp(v1, v2))
        return false;
	for (Long i = 0; i < v1.size(); ++i) {
		if (v1[i] != v2[i])
            return false;
	}
	return true;
}

inline Bool operator!=(VecInt_I v1, DvecInt_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(VecLlong_I v1, DvecLlong_I v2)
{
	if (!shape_cmp(v1, v2))
        return false;
	for (Long i = 0; i < v1.size(); ++i) {
		if (v1[i] != v2[i])
            return false;
	}
	return true;
}

inline Bool operator!=(VecLlong_I v1, DvecLlong_I v2)
{
    return !(v1 == v2);
}

inline Bool operator==(VecDoub_I v1, DvecDoub_I v2)
{
	if (!shape_cmp(v1, v2))
        return false;
	for (Long i = 0; i < v1.size(); ++i) {
		if (v1[i] != v2[i])
            return false;
	}
	return true;
}

inline Bool operator!=(VecDoub_I v1, DvecDoub_I v2)
{
    return !(v1 == v2);
}

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

inline Bool operator==(MatInt_I v1, MatInt_I v2)
{
    return shape_cmp(v1, v2) &&
        equals_to_vv(v1.ptr(), v2.ptr(), v2.size());
}

inline Bool operator!=(MatInt_I v1, MatInt_I v2)
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

} // namespace slisc
