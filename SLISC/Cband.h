// band diagonal matrix class
#include "cmat.h"

namespace slisc {

class CbandTInt
{
public:
    Long m_N1;
    Long m_N2;
    Long m_Nup;
    Long m_Nlow;
    CmatInt m_a;

    CbandTInt(Long_I N1, Long_I N2, Long_I Nup, Long_I Nlow);

    Int * ptr();
    const Int * ptr() const;
    Long n1() const;
    Long n2() const;
    Long nup() const;
    Long nlow() const;
	CmatInt &cmat();
};

inline CbandTInt::CbandTInt(Long_I N1, Long_I N2, Long_I Nup, Long_I Nlow):
    m_N1(N1), m_N2(N2), m_Nup(Nup), m_Nlow(Nlow), m_a(Nup+Nlow+1, N2)
{}

inline Int * CbandTInt::ptr()
{
    return m_a.ptr();
}

inline const Int * CbandTInt::ptr() const
{
    return m_a.ptr();
}

inline Long CbandTInt::n1() const
{
    return m_N1;
}

inline Long CbandTInt::n2() const
{
    return m_N2;
}

inline Long CbandTInt::nup() const
{
    return m_Nup;
}

inline Long CbandTInt::nlow() const
{
    return m_Nlow;
}

inline CmatInt &cmat()
{
	return m_a;
}

typedef const CbandTInt & CbandTInt_I;
typedef CbandTInt & CbandTInt_O, & CbandTInt_IO;

class CbandTDoub
{
public:
    Long m_N1;
    Long m_N2;
    Long m_Nup;
    Long m_Nlow;
    CmatDoub m_a;

    CbandTDoub(Long_I N1, Long_I N2, Long_I Nup, Long_I Nlow);

    Doub * ptr();
    const Doub * ptr() const;
    Long n1() const;
    Long n2() const;
    Long nup() const;
    Long nlow() const;
	CmatDoub &cmat();
};

inline CbandTDoub::CbandTDoub(Long_I N1, Long_I N2, Long_I Nup, Long_I Nlow):
    m_N1(N1), m_N2(N2), m_Nup(Nup), m_Nlow(Nlow), m_a(Nup+Nlow+1, N2)
{}

inline Doub * CbandTDoub::ptr()
{
    return m_a.ptr();
}

inline const Doub * CbandTDoub::ptr() const
{
    return m_a.ptr();
}

inline Long CbandTDoub::n1() const
{
    return m_N1;
}

inline Long CbandTDoub::n2() const
{
    return m_N2;
}

inline Long CbandTDoub::nup() const
{
    return m_Nup;
}

inline Long CbandTDoub::nlow() const
{
    return m_Nlow;
}

inline CmatDoub &cmat()
{
	return m_a;
}

typedef const CbandTDoub & CbandTDoub_I;
typedef CbandTDoub & CbandTDoub_O, & CbandTDoub_IO;

class CbandTComp
{
public:
    Long m_N1;
    Long m_N2;
    Long m_Nup;
    Long m_Nlow;
    CmatComp m_a;

    CbandTComp(Long_I N1, Long_I N2, Long_I Nup, Long_I Nlow);

    Comp * ptr();
    const Comp * ptr() const;
    Long n1() const;
    Long n2() const;
    Long nup() const;
    Long nlow() const;
	CmatComp &cmat();
};

inline CbandTComp::CbandTComp(Long_I N1, Long_I N2, Long_I Nup, Long_I Nlow):
    m_N1(N1), m_N2(N2), m_Nup(Nup), m_Nlow(Nlow), m_a(Nup+Nlow+1, N2)
{}

inline Comp * CbandTComp::ptr()
{
    return m_a.ptr();
}

inline const Comp * CbandTComp::ptr() const
{
    return m_a.ptr();
}

inline Long CbandTComp::n1() const
{
    return m_N1;
}

inline Long CbandTComp::n2() const
{
    return m_N2;
}

inline Long CbandTComp::nup() const
{
    return m_Nup;
}

inline Long CbandTComp::nlow() const
{
    return m_Nlow;
}

inline CmatComp &cmat()
{
	return m_a;
}

typedef const CbandTComp & CbandTComp_I;
typedef CbandTComp & CbandTComp_O, & CbandTComp_IO;

} // namespace slisc
