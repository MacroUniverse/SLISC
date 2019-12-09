// overlapping block diagonal matrix (overlap by one element)
// such as the kinetic matrix for 1D FEDVR grid
// first block and last block has one less element in each dimension

#pragma once
#include "Cmat3.h"

namespace slisc {

Llong sqr(Long);

void vecset(Int *, Int_I, Llong_I, Llong_I);

class CmobdInt
{
protected:
    Cmat3Int m_data;
    Long m_N1; // m_N2 = m_N2 = (blk_size - 1) * Nblk - 1
public:
    CmobdInt(Long_I blk_size, Long_I Nblk);
    const Int &operator()(Long_I i) const;
    Int &operator()(Long_I i);
    Long find(Long_I i, Long_I j);
    const Int * ptr() const; // not the first element!
    Int * ptr();
    Long n1() const;
    Long n2() const;
    Long size() const;
    Long nnz() const;
    const Cmat3Int &cmat3() const;
    Cmat3Int &cmat3();
    Long n0() const; // n0() = m_data.n1() = m_data.n2()
    Long nblk() const; // m_data.n3()
    const Int operator()(Long_I i, Long_I j) const;
    void resize(Long_I blk_size, Long_I Nblk);
};

typedef const CmobdInt &CmobdInt_I;
typedef CmobdInt &CmobdInt_O, &CmobdInt_IO;

inline CmobdInt::CmobdInt(Long_I blk_size, Long_I Nblk)
    : m_data(blk_size, blk_size, Nblk), m_N1((blk_size - 1) * Nblk - 1)
{
    Long step = sqr(n0());
    // set the first overlapped element to 0
    if (m_data.size() > 0)
        vecset(m_data.ptr() + step - 1, 0, Nblk - 1, step);
}

inline const Int & CmobdInt::operator()(Long_I i) const
{
    return m_data[i];
}

inline Int & CmobdInt::operator()(Long_I i)
{
    return m_data[i];
}

inline Long CmobdInt::find(Long_I i1, Long_I i2)
{
#ifdef SLS_CHECK_BOUNDS
    if (i1 < 0 || i1 >= m_N1 || i2 < 0 || i2 >= m_N1)
        SLS_ERR("out of bound!");
#endif
    Long i = i1 + 1; Long j = i2 + 1;
    Long N = n0() - 1, Nblk = m_data.n3();
    Long iblk = i / N, jblk = j / N;
    Long m = i % N;
    Long step2 = n0(), step3 = step2 * step2;
    if (iblk == jblk) {
        if (iblk == Nblk)
            return N + step2 * N + step3 * (Nblk - 1);
        else if (i == j && m == 0 && iblk > 0)
            return step3 * iblk;
        return m + step2 * (j % N) + step3 * iblk;
    }
    else if (jblk == iblk - 1) {
        if (m == 0)
            return N + step2 * (j % N) + step3 * jblk;
    }
    else if (jblk == iblk + 1) {
        Long n = j % N;
        if (n == 0)
            return m + step2 * N + step3 * iblk;
    }
    SLS_ERR("element out of block!");
    return -1;
}

inline const Int * CmobdInt::ptr() const
{
    return m_data.ptr();
}

inline Int * CmobdInt::ptr()
{
    return m_data.ptr();
}

inline Long CmobdInt::n1() const
{
    return m_N1;
}

inline Long CmobdInt::n2() const
{
    return m_N1;
}

inline Long CmobdInt::size() const
{
    return m_N1 * m_N1;
}

inline Long CmobdInt::nnz() const
{
    Long N0 = n0(), Nblk = nblk();
    return (N0*N0 - 1)*Nblk - 4 * N0 + 3;
}

inline const Cmat3Int& CmobdInt::cmat3() const
{
    return m_data;
}

inline Cmat3Int& CmobdInt::cmat3()
{
    return m_data;
}

inline Long CmobdInt::n0() const
{
    return m_data.n1();
}

inline Long CmobdInt::nblk() const
{
    return m_data.n3();
}

inline const Int CmobdInt::operator()(Long_I i1, Long_I i2) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i1 < 0 || i1 >= m_N1 || i2 < 0 || i2 >= m_N1)
        SLS_ERR("out of bound!");
#endif
    Long i = i1 + 1, j = i2 + 1;
    Long N = n0() - 1, Nblk = m_data.n3();
    Long iblk = i / N, jblk = j / N;
    Long m = i % N;
    if (iblk == jblk) {
        if (iblk == Nblk)
            return m_data(N, N, Nblk - 1);
        else if (i == j && m == 0 && iblk > 0)
            return m_data(0, 0, iblk);
        return m_data(m, j % N, iblk);
    }
    else if (jblk == iblk - 1) {
        if (m == 0)
            return m_data(N, j % N, jblk);
    }
    else if (jblk == iblk + 1) {
        Long n = j % N;
        if (n == 0)
            return m_data(m, N, iblk);
    }
    return 0;
}

inline void CmobdInt::resize(Long_I blk_size, Long_I Nblk)
{
    m_data.resize(blk_size, blk_size, Nblk);
    m_N1 = (blk_size - 1) * Nblk - 1;
    Long step = sqr(n0());
    // set the first overlapped element to 0
    vecset(m_data.ptr() + step - 1, 0, Nblk - 1, step);
}

void vecset(Doub *, Doub_I, Llong_I, Llong_I);

class CmobdDoub
{
protected:
    Cmat3Doub m_data;
    Long m_N1; // m_N2 = m_N2 = (blk_size - 1) * Nblk - 1
public:
    CmobdDoub(Long_I blk_size, Long_I Nblk);
    const Doub &operator()(Long_I i) const;
    Doub &operator()(Long_I i);
    Long find(Long_I i, Long_I j);
    const Doub * ptr() const; // not the first element!
    Doub * ptr();
    Long n1() const;
    Long n2() const;
    Long size() const;
    Long nnz() const;
    const Cmat3Doub &cmat3() const;
    Cmat3Doub &cmat3();
    Long n0() const; // n0() = m_data.n1() = m_data.n2()
    Long nblk() const; // m_data.n3()
    const Doub operator()(Long_I i, Long_I j) const;
    void resize(Long_I blk_size, Long_I Nblk);
};

typedef const CmobdDoub &CmobdDoub_I;
typedef CmobdDoub &CmobdDoub_O, &CmobdDoub_IO;

inline CmobdDoub::CmobdDoub(Long_I blk_size, Long_I Nblk)
    : m_data(blk_size, blk_size, Nblk), m_N1((blk_size - 1) * Nblk - 1)
{
    Long step = sqr(n0());
    // set the first overlapped element to 0
    if (m_data.size() > 0)
        vecset(m_data.ptr() + step - 1, 0, Nblk - 1, step);
}

inline const Doub & CmobdDoub::operator()(Long_I i) const
{
    return m_data[i];
}

inline Doub & CmobdDoub::operator()(Long_I i)
{
    return m_data[i];
}

inline Long CmobdDoub::find(Long_I i1, Long_I i2)
{
#ifdef SLS_CHECK_BOUNDS
    if (i1 < 0 || i1 >= m_N1 || i2 < 0 || i2 >= m_N1)
        SLS_ERR("out of bound!");
#endif
    Long i = i1 + 1; Long j = i2 + 1;
    Long N = n0() - 1, Nblk = m_data.n3();
    Long iblk = i / N, jblk = j / N;
    Long m = i % N;
    Long step2 = n0(), step3 = step2 * step2;
    if (iblk == jblk) {
        if (iblk == Nblk)
            return N + step2 * N + step3 * (Nblk - 1);
        else if (i == j && m == 0 && iblk > 0)
            return step3 * iblk;
        return m + step2 * (j % N) + step3 * iblk;
    }
    else if (jblk == iblk - 1) {
        if (m == 0)
            return N + step2 * (j % N) + step3 * jblk;
    }
    else if (jblk == iblk + 1) {
        Long n = j % N;
        if (n == 0)
            return m + step2 * N + step3 * iblk;
    }
    SLS_ERR("element out of block!");
    return -1;
}

inline const Doub * CmobdDoub::ptr() const
{
    return m_data.ptr();
}

inline Doub * CmobdDoub::ptr()
{
    return m_data.ptr();
}

inline Long CmobdDoub::n1() const
{
    return m_N1;
}

inline Long CmobdDoub::n2() const
{
    return m_N1;
}

inline Long CmobdDoub::size() const
{
    return m_N1 * m_N1;
}

inline Long CmobdDoub::nnz() const
{
    Long N0 = n0(), Nblk = nblk();
    return (N0*N0 - 1)*Nblk - 4 * N0 + 3;
}

inline const Cmat3Doub& CmobdDoub::cmat3() const
{
    return m_data;
}

inline Cmat3Doub& CmobdDoub::cmat3()
{
    return m_data;
}

inline Long CmobdDoub::n0() const
{
    return m_data.n1();
}

inline Long CmobdDoub::nblk() const
{
    return m_data.n3();
}

inline const Doub CmobdDoub::operator()(Long_I i1, Long_I i2) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i1 < 0 || i1 >= m_N1 || i2 < 0 || i2 >= m_N1)
        SLS_ERR("out of bound!");
#endif
    Long i = i1 + 1, j = i2 + 1;
    Long N = n0() - 1, Nblk = m_data.n3();
    Long iblk = i / N, jblk = j / N;
    Long m = i % N;
    if (iblk == jblk) {
        if (iblk == Nblk)
            return m_data(N, N, Nblk - 1);
        else if (i == j && m == 0 && iblk > 0)
            return m_data(0, 0, iblk);
        return m_data(m, j % N, iblk);
    }
    else if (jblk == iblk - 1) {
        if (m == 0)
            return m_data(N, j % N, jblk);
    }
    else if (jblk == iblk + 1) {
        Long n = j % N;
        if (n == 0)
            return m_data(m, N, iblk);
    }
    return 0;
}

inline void CmobdDoub::resize(Long_I blk_size, Long_I Nblk)
{
    m_data.resize(blk_size, blk_size, Nblk);
    m_N1 = (blk_size - 1) * Nblk - 1;
    Long step = sqr(n0());
    // set the first overlapped element to 0
    vecset(m_data.ptr() + step - 1, 0, Nblk - 1, step);
}

void vecset(Comp *, Comp_I, Llong_I, Llong_I);

class CmobdComp
{
protected:
    Cmat3Comp m_data;
    Long m_N1; // m_N2 = m_N2 = (blk_size - 1) * Nblk - 1
public:
    CmobdComp(Long_I blk_size, Long_I Nblk);
    const Comp &operator()(Long_I i) const;
    Comp &operator()(Long_I i);
    Long find(Long_I i, Long_I j);
    const Comp * ptr() const; // not the first element!
    Comp * ptr();
    Long n1() const;
    Long n2() const;
    Long size() const;
    Long nnz() const;
    const Cmat3Comp &cmat3() const;
    Cmat3Comp &cmat3();
    Long n0() const; // n0() = m_data.n1() = m_data.n2()
    Long nblk() const; // m_data.n3()
    const Comp operator()(Long_I i, Long_I j) const;
    void resize(Long_I blk_size, Long_I Nblk);
};

typedef const CmobdComp &CmobdComp_I;
typedef CmobdComp &CmobdComp_O, &CmobdComp_IO;

inline CmobdComp::CmobdComp(Long_I blk_size, Long_I Nblk)
    : m_data(blk_size, blk_size, Nblk), m_N1((blk_size - 1) * Nblk - 1)
{
    Long step = sqr(n0());
    // set the first overlapped element to 0
    if (m_data.size() > 0)
        vecset(m_data.ptr() + step - 1, 0, Nblk - 1, step);
}

inline const Comp & CmobdComp::operator()(Long_I i) const
{
    return m_data[i];
}

inline Comp & CmobdComp::operator()(Long_I i)
{
    return m_data[i];
}

inline Long CmobdComp::find(Long_I i1, Long_I i2)
{
#ifdef SLS_CHECK_BOUNDS
    if (i1 < 0 || i1 >= m_N1 || i2 < 0 || i2 >= m_N1)
        SLS_ERR("out of bound!");
#endif
    Long i = i1 + 1; Long j = i2 + 1;
    Long N = n0() - 1, Nblk = m_data.n3();
    Long iblk = i / N, jblk = j / N;
    Long m = i % N;
    Long step2 = n0(), step3 = step2 * step2;
    if (iblk == jblk) {
        if (iblk == Nblk)
            return N + step2 * N + step3 * (Nblk - 1);
        else if (i == j && m == 0 && iblk > 0)
            return step3 * iblk;
        return m + step2 * (j % N) + step3 * iblk;
    }
    else if (jblk == iblk - 1) {
        if (m == 0)
            return N + step2 * (j % N) + step3 * jblk;
    }
    else if (jblk == iblk + 1) {
        Long n = j % N;
        if (n == 0)
            return m + step2 * N + step3 * iblk;
    }
    SLS_ERR("element out of block!");
    return -1;
}

inline const Comp * CmobdComp::ptr() const
{
    return m_data.ptr();
}

inline Comp * CmobdComp::ptr()
{
    return m_data.ptr();
}

inline Long CmobdComp::n1() const
{
    return m_N1;
}

inline Long CmobdComp::n2() const
{
    return m_N1;
}

inline Long CmobdComp::size() const
{
    return m_N1 * m_N1;
}

inline Long CmobdComp::nnz() const
{
    Long N0 = n0(), Nblk = nblk();
    return (N0*N0 - 1)*Nblk - 4 * N0 + 3;
}

inline const Cmat3Comp& CmobdComp::cmat3() const
{
    return m_data;
}

inline Cmat3Comp& CmobdComp::cmat3()
{
    return m_data;
}

inline Long CmobdComp::n0() const
{
    return m_data.n1();
}

inline Long CmobdComp::nblk() const
{
    return m_data.n3();
}

inline const Comp CmobdComp::operator()(Long_I i1, Long_I i2) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i1 < 0 || i1 >= m_N1 || i2 < 0 || i2 >= m_N1)
        SLS_ERR("out of bound!");
#endif
    Long i = i1 + 1, j = i2 + 1;
    Long N = n0() - 1, Nblk = m_data.n3();
    Long iblk = i / N, jblk = j / N;
    Long m = i % N;
    if (iblk == jblk) {
        if (iblk == Nblk)
            return m_data(N, N, Nblk - 1);
        else if (i == j && m == 0 && iblk > 0)
            return m_data(0, 0, iblk);
        return m_data(m, j % N, iblk);
    }
    else if (jblk == iblk - 1) {
        if (m == 0)
            return m_data(N, j % N, jblk);
    }
    else if (jblk == iblk + 1) {
        Long n = j % N;
        if (n == 0)
            return m_data(m, N, iblk);
    }
    return 0;
}

inline void CmobdComp::resize(Long_I blk_size, Long_I Nblk)
{
    m_data.resize(blk_size, blk_size, Nblk);
    m_N1 = (blk_size - 1) * Nblk - 1;
    Long step = sqr(n0());
    // set the first overlapped element to 0
    vecset(m_data.ptr() + step - 1, 0, Nblk - 1, step);
}

} // namespace slisc
