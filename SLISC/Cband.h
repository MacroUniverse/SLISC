// band diagonal matrix class
#pragma once
#include "Cmat.h"

namespace slisc {

class CbandInt
{
public:
    Long m_N1;
    Long m_N2;
    Long m_Nup;
    Long m_Nlow;
    CmatInt m_a;

    CbandInt(Long_I N1, Long_I N2, Long_I Nup, Long_I Nlow);

    Int * ptr();
    const Int * ptr() const;
	Int operator()(Long_I i, Long_I j) const;
	Int &ref(Long_I i, Long_I j);
    Long n1() const;
    Long n2() const;
    Long nup() const;
    Long nlow() const;
	CmatInt &cmat();
	const CmatInt &cmat() const;
};

inline CbandInt::CbandInt(Long_I N1, Long_I N2, Long_I Nup, Long_I Nlow):
    m_N1(N1), m_N2(N2), m_Nup(Nup), m_Nlow(Nlow), m_a(Nup+Nlow+1, N2)
{}

inline Int * CbandInt::ptr()
{
    return m_a.ptr();
}

inline const Int * CbandInt::ptr() const
{
    return m_a.ptr();
}

inline Int CbandInt::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
		SLS_ERR("index out of bound!");
#endif
	if (i - j > m_Nlow || j - i > m_Nup)
		return 0;
    return m_a(m_Nup + i - j, j);
}

inline Int &CbandInt::ref(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
		SLS_ERR("index out of bound!");
#endif
	if (i - j > m_Nlow || j - i > m_Nup)
		SLS_ERR("index out of band!");
    return m_a(m_Nup + i - j, j);
}

inline Long CbandInt::n1() const
{
    return m_N1;
}

inline Long CbandInt::n2() const
{
    return m_N2;
}

inline Long CbandInt::nup() const
{
    return m_Nup;
}

inline Long CbandInt::nlow() const
{
    return m_Nlow;
}

inline CmatInt &CbandInt::cmat()
{
	return m_a;
}

inline const CmatInt &CbandInt::cmat() const
{
	return m_a;
}

typedef const CbandInt & CbandInt_I;
typedef CbandInt & CbandInt_O, & CbandInt_IO;

class CbandDoub
{
public:
    Long m_N1;
    Long m_N2;
    Long m_Nup;
    Long m_Nlow;
    CmatDoub m_a;

    CbandDoub(Long_I N1, Long_I N2, Long_I Nup, Long_I Nlow);

    Doub * ptr();
    const Doub * ptr() const;
	Doub operator()(Long_I i, Long_I j) const;
	Doub &ref(Long_I i, Long_I j);
    Long n1() const;
    Long n2() const;
    Long nup() const;
    Long nlow() const;
	CmatDoub &cmat();
	const CmatDoub &cmat() const;
};

inline CbandDoub::CbandDoub(Long_I N1, Long_I N2, Long_I Nup, Long_I Nlow):
    m_N1(N1), m_N2(N2), m_Nup(Nup), m_Nlow(Nlow), m_a(Nup+Nlow+1, N2)
{}

inline Doub * CbandDoub::ptr()
{
    return m_a.ptr();
}

inline const Doub * CbandDoub::ptr() const
{
    return m_a.ptr();
}

inline Doub CbandDoub::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
		SLS_ERR("index out of bound!");
#endif
	if (i - j > m_Nlow || j - i > m_Nup)
		return 0;
    return m_a(m_Nup + i - j, j);
}

inline Doub &CbandDoub::ref(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
		SLS_ERR("index out of bound!");
#endif
	if (i - j > m_Nlow || j - i > m_Nup)
		SLS_ERR("index out of band!");
    return m_a(m_Nup + i - j, j);
}

inline Long CbandDoub::n1() const
{
    return m_N1;
}

inline Long CbandDoub::n2() const
{
    return m_N2;
}

inline Long CbandDoub::nup() const
{
    return m_Nup;
}

inline Long CbandDoub::nlow() const
{
    return m_Nlow;
}

inline CmatDoub &CbandDoub::cmat()
{
	return m_a;
}

inline const CmatDoub &CbandDoub::cmat() const
{
	return m_a;
}

typedef const CbandDoub & CbandDoub_I;
typedef CbandDoub & CbandDoub_O, & CbandDoub_IO;

class CbandComp
{
public:
    Long m_N1;
    Long m_N2;
    Long m_Nup;
    Long m_Nlow;
    CmatComp m_a;

    CbandComp(Long_I N1, Long_I N2, Long_I Nup, Long_I Nlow);

    Comp * ptr();
    const Comp * ptr() const;
	Comp operator()(Long_I i, Long_I j) const;
	Comp &ref(Long_I i, Long_I j);
    Long n1() const;
    Long n2() const;
    Long nup() const;
    Long nlow() const;
	CmatComp &cmat();
	const CmatComp &cmat() const;
};

inline CbandComp::CbandComp(Long_I N1, Long_I N2, Long_I Nup, Long_I Nlow):
    m_N1(N1), m_N2(N2), m_Nup(Nup), m_Nlow(Nlow), m_a(Nup+Nlow+1, N2)
{}

inline Comp * CbandComp::ptr()
{
    return m_a.ptr();
}

inline const Comp * CbandComp::ptr() const
{
    return m_a.ptr();
}

inline Comp CbandComp::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
		SLS_ERR("index out of bound!");
#endif
	if (i - j > m_Nlow || j - i > m_Nup)
		return 0;
    return m_a(m_Nup + i - j, j);
}

inline Comp &CbandComp::ref(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
		SLS_ERR("index out of bound!");
#endif
	if (i - j > m_Nlow || j - i > m_Nup)
		SLS_ERR("index out of band!");
    return m_a(m_Nup + i - j, j);
}

inline Long CbandComp::n1() const
{
    return m_N1;
}

inline Long CbandComp::n2() const
{
    return m_N2;
}

inline Long CbandComp::nup() const
{
    return m_Nup;
}

inline Long CbandComp::nlow() const
{
    return m_Nlow;
}

inline CmatComp &CbandComp::cmat()
{
	return m_a;
}

inline const CmatComp &CbandComp::cmat() const
{
	return m_a;
}

typedef const CbandComp & CbandComp_I;
typedef CbandComp & CbandComp_O, & CbandComp_IO;

} // namespace slisc
