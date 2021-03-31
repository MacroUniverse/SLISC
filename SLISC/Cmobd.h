// overlapping block diagonal matrix (overlap by one element)
// such as the kinetic matrix for 1D FEDVR grid
// first block and last block has one less element in each dimension
// currently, first overlapping element must be zero (e.g. matrix-vector multiplication will depend on this)

#pragma once
#include "Cmat3.h"

namespace slisc {

Llong sqr(Long);

void vecset(Int *, Int_I, Llong_I, Llong_I);
void veccpy(Int *, const Int *, Llong_I);

class CmobdInt
{
protected:
    Cmat3Int m_data;
    Long m_N1; // m_N1 = m_N2 = (blk_size - 1) * Nblk - 1
public:
    CmobdInt();
    CmobdInt(Long_I blk_size, Long_I Nblk);
    const Int &operator[](Long_I i) const;
    Int &operator[](Long_I i);
    Long find(Long_I i, Long_I j) const; // return single index to m_data, -1 if out of blocks
    const Int * p() const; // not the first element!
    Int * p();
    Long n1() const;
    Long n2() const;
    Long size() const;
    Long nnz() const;
    const Cmat3Int &cmat3() const;
    Cmat3Int &cmat3();
    void set(Cmat3Int_I a3); // set data from Cmat3
    Long n0() const; // n0() = m_data.n1() = m_data.n2()
    Long nblk() const; // m_data.n3()
    Int operator()(Long_I i, Long_I j) const;
    Int &ref(Long_I i, Long_I j);
    void resize(Long_I blk_size, Long_I Nblk);
};

typedef const CmobdInt &CmobdInt_I;
typedef CmobdInt &CmobdInt_O, &CmobdInt_IO;

inline CmobdInt::CmobdInt() : CmobdInt(0, 0) {}

inline CmobdInt::CmobdInt(Long_I blk_size, Long_I Nblk)
    : m_data(blk_size, blk_size, Nblk), m_N1((blk_size - 1) * Nblk - 1)
{
    Long step = sqr(n0());
    // set the first overlapped element to 0
    if (m_data.size() > 0)
        vecset(m_data.p() + step - 1, 0, Nblk - 1, step);
}

inline const Int &CmobdInt::operator[](Long_I i) const
{
    return m_data[i];
}

inline Int &CmobdInt::operator[](Long_I i)
{
    return m_data[i];
}

inline Long CmobdInt::find(Long_I i1, Long_I i2) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i1 < 0 || i1 >= m_N1 || i2 < 0 || i2 >= m_N1)
        SLS_ERR("out of bound!");
#endif
    Long i = i1 + 1; Long j = i2 + 1;
    Long N = n0() - 1;
    Long iblk = i / N, jblk = j / N;
    Long m = i % N;
    Long step2 = n0(), step3 = step2 * step2;
    if (iblk == jblk) {
        if (i == j && m == 0 && iblk > 0)
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
    return -1;
}

inline const Int * CmobdInt::p() const
{
    return m_data.p();
}

inline Int * CmobdInt::p()
{
    return m_data.p();
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

inline void CmobdInt::set(Cmat3Int_I a3)
{
    veccpy(m_data.p(), a3.p(), a3.size());
    // set the first overlapped element to 0
    Long step = sqr(n0());
    vecset(m_data.p() + step - 1, 0, nblk() - 1, step);
}

inline Long CmobdInt::n0() const
{
    return m_data.n1();
}

inline Long CmobdInt::nblk() const
{
    return m_data.n3();
}

inline Int CmobdInt::operator()(Long_I i1, Long_I i2) const
{
    Long ind0 = find(i1, i2);
    if (ind0 >= 0)
        return m_data[ind0];
    else
        return 0;
}

inline Int& CmobdInt::ref(Long_I i, Long_I j)
{
    Long ind = find(i, j);
#ifdef SLS_CHECK_BOUNDS
    if (ind < 0)
        SLS_ERR("Cmobd: ref out of block!");
#endif
    return m_data[ind];
}

inline void CmobdInt::resize(Long_I blk_size, Long_I Nblk)
{
    m_data.resize(blk_size, blk_size, Nblk);
    m_N1 = (blk_size - 1) * Nblk - 1;
    // set the first overlapped element to 0
    Long step = sqr(n0());
    vecset(m_data.p() + step - 1, 0, Nblk - 1, step);
}

void vecset(Doub *, Doub_I, Llong_I, Llong_I);
void veccpy(Doub *, const Doub *, Llong_I);

class CmobdDoub
{
protected:
    Cmat3Doub m_data;
    Long m_N1; // m_N1 = m_N2 = (blk_size - 1) * Nblk - 1
public:
    CmobdDoub();
    CmobdDoub(Long_I blk_size, Long_I Nblk);
    const Doub &operator[](Long_I i) const;
    Doub &operator[](Long_I i);
    Long find(Long_I i, Long_I j) const; // return single index to m_data, -1 if out of blocks
    const Doub * p() const; // not the first element!
    Doub * p();
    Long n1() const;
    Long n2() const;
    Long size() const;
    Long nnz() const;
    const Cmat3Doub &cmat3() const;
    Cmat3Doub &cmat3();
    void set(Cmat3Doub_I a3); // set data from Cmat3
    Long n0() const; // n0() = m_data.n1() = m_data.n2()
    Long nblk() const; // m_data.n3()
    Doub operator()(Long_I i, Long_I j) const;
    Doub &ref(Long_I i, Long_I j);
    void resize(Long_I blk_size, Long_I Nblk);
};

typedef const CmobdDoub &CmobdDoub_I;
typedef CmobdDoub &CmobdDoub_O, &CmobdDoub_IO;

inline CmobdDoub::CmobdDoub() : CmobdDoub(0, 0) {}

inline CmobdDoub::CmobdDoub(Long_I blk_size, Long_I Nblk)
    : m_data(blk_size, blk_size, Nblk), m_N1((blk_size - 1) * Nblk - 1)
{
    Long step = sqr(n0());
    // set the first overlapped element to 0
    if (m_data.size() > 0)
        vecset(m_data.p() + step - 1, 0, Nblk - 1, step);
}

inline const Doub &CmobdDoub::operator[](Long_I i) const
{
    return m_data[i];
}

inline Doub &CmobdDoub::operator[](Long_I i)
{
    return m_data[i];
}

inline Long CmobdDoub::find(Long_I i1, Long_I i2) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i1 < 0 || i1 >= m_N1 || i2 < 0 || i2 >= m_N1)
        SLS_ERR("out of bound!");
#endif
    Long i = i1 + 1; Long j = i2 + 1;
    Long N = n0() - 1;
    Long iblk = i / N, jblk = j / N;
    Long m = i % N;
    Long step2 = n0(), step3 = step2 * step2;
    if (iblk == jblk) {
        if (i == j && m == 0 && iblk > 0)
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
    return -1;
}

inline const Doub * CmobdDoub::p() const
{
    return m_data.p();
}

inline Doub * CmobdDoub::p()
{
    return m_data.p();
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

inline void CmobdDoub::set(Cmat3Doub_I a3)
{
    veccpy(m_data.p(), a3.p(), a3.size());
    // set the first overlapped element to 0
    Long step = sqr(n0());
    vecset(m_data.p() + step - 1, 0, nblk() - 1, step);
}

inline Long CmobdDoub::n0() const
{
    return m_data.n1();
}

inline Long CmobdDoub::nblk() const
{
    return m_data.n3();
}

inline Doub CmobdDoub::operator()(Long_I i1, Long_I i2) const
{
    Long ind0 = find(i1, i2);
    if (ind0 >= 0)
        return m_data[ind0];
    else
        return 0;
}

inline Doub& CmobdDoub::ref(Long_I i, Long_I j)
{
    Long ind = find(i, j);
#ifdef SLS_CHECK_BOUNDS
    if (ind < 0)
        SLS_ERR("Cmobd: ref out of block!");
#endif
    return m_data[ind];
}

inline void CmobdDoub::resize(Long_I blk_size, Long_I Nblk)
{
    m_data.resize(blk_size, blk_size, Nblk);
    m_N1 = (blk_size - 1) * Nblk - 1;
    // set the first overlapped element to 0
    Long step = sqr(n0());
    vecset(m_data.p() + step - 1, 0, Nblk - 1, step);
}

void vecset(Comp *, Comp_I, Llong_I, Llong_I);
void veccpy(Comp *, const Comp *, Llong_I);

class CmobdComp
{
protected:
    Cmat3Comp m_data;
    Long m_N1; // m_N1 = m_N2 = (blk_size - 1) * Nblk - 1
public:
    CmobdComp();
    CmobdComp(Long_I blk_size, Long_I Nblk);
    const Comp &operator[](Long_I i) const;
    Comp &operator[](Long_I i);
    Long find(Long_I i, Long_I j) const; // return single index to m_data, -1 if out of blocks
    const Comp * p() const; // not the first element!
    Comp * p();
    Long n1() const;
    Long n2() const;
    Long size() const;
    Long nnz() const;
    const Cmat3Comp &cmat3() const;
    Cmat3Comp &cmat3();
    void set(Cmat3Comp_I a3); // set data from Cmat3
    Long n0() const; // n0() = m_data.n1() = m_data.n2()
    Long nblk() const; // m_data.n3()
    Comp operator()(Long_I i, Long_I j) const;
    Comp &ref(Long_I i, Long_I j);
    void resize(Long_I blk_size, Long_I Nblk);
};

typedef const CmobdComp &CmobdComp_I;
typedef CmobdComp &CmobdComp_O, &CmobdComp_IO;

inline CmobdComp::CmobdComp() : CmobdComp(0, 0) {}

inline CmobdComp::CmobdComp(Long_I blk_size, Long_I Nblk)
    : m_data(blk_size, blk_size, Nblk), m_N1((blk_size - 1) * Nblk - 1)
{
    Long step = sqr(n0());
    // set the first overlapped element to 0
    if (m_data.size() > 0)
        vecset(m_data.p() + step - 1, 0, Nblk - 1, step);
}

inline const Comp &CmobdComp::operator[](Long_I i) const
{
    return m_data[i];
}

inline Comp &CmobdComp::operator[](Long_I i)
{
    return m_data[i];
}

inline Long CmobdComp::find(Long_I i1, Long_I i2) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i1 < 0 || i1 >= m_N1 || i2 < 0 || i2 >= m_N1)
        SLS_ERR("out of bound!");
#endif
    Long i = i1 + 1; Long j = i2 + 1;
    Long N = n0() - 1;
    Long iblk = i / N, jblk = j / N;
    Long m = i % N;
    Long step2 = n0(), step3 = step2 * step2;
    if (iblk == jblk) {
        if (i == j && m == 0 && iblk > 0)
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
    return -1;
}

inline const Comp * CmobdComp::p() const
{
    return m_data.p();
}

inline Comp * CmobdComp::p()
{
    return m_data.p();
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

inline void CmobdComp::set(Cmat3Comp_I a3)
{
    veccpy(m_data.p(), a3.p(), a3.size());
    // set the first overlapped element to 0
    Long step = sqr(n0());
    vecset(m_data.p() + step - 1, 0, nblk() - 1, step);
}

inline Long CmobdComp::n0() const
{
    return m_data.n1();
}

inline Long CmobdComp::nblk() const
{
    return m_data.n3();
}

inline Comp CmobdComp::operator()(Long_I i1, Long_I i2) const
{
    Long ind0 = find(i1, i2);
    if (ind0 >= 0)
        return m_data[ind0];
    else
        return 0;
}

inline Comp& CmobdComp::ref(Long_I i, Long_I j)
{
    Long ind = find(i, j);
#ifdef SLS_CHECK_BOUNDS
    if (ind < 0)
        SLS_ERR("Cmobd: ref out of block!");
#endif
    return m_data[ind];
}

inline void CmobdComp::resize(Long_I blk_size, Long_I Nblk)
{
    m_data.resize(blk_size, blk_size, Nblk);
    m_N1 = (blk_size - 1) * Nblk - 1;
    // set the first overlapped element to 0
    Long step = sqr(n0());
    vecset(m_data.p() + step - 1, 0, Nblk - 1, step);
}

} // namespace slisc
