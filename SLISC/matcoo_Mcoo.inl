inline void reorder(SvecInt_O v, VecLong_I order);
inline void reorder(SvecLong_O v, VecLong_I order);

class McooInt : public Vbase<Int>
{
private:
    typedef Vbase<Int> Base;
    using Base::m_p;
    using Base::m_N;
    Long m_Nr, m_Nc, m_Nnz;
    VecLong m_row, m_col;
    // McooInt() {} // default constructor: uninitialized
public:
    using Base::ptr;
    McooInt(Long_I Nr, Long_I Nc);
    McooInt(Long_I Nr, Long_I Nc, Long_I Ncap); // reserve Ncap elements
    McooInt(const McooInt &rhs);        // Copy constructor
    Long *row_ptr();
    const Long *row_ptr() const;
    Long *col_ptr();
    const Long *col_ptr() const;
    // inline void operator<<(McooInt &rhs); // move data and rhs.resize(0, 0); rhs.resize(0)
    void push(Int_I s, Long_I i, Long_I j); // add one nonzero element
    void set(Int_I s, Long_I i, Long_I j); // change existing element or push new element
    Long n1() const;
    Long n2() const;
    Long size() const; // return m_Nr * m_Nc
    Long nnz() const; // return number of non-zero elements
    Long capacity() const;
    // get single index using double index, return -1 if not found
    Long find(Long_I i, Long_I j) const;
    // reference to an element (element must exist)
    Int & ref(Long_I i, Long_I j);
    // double indexing (element need not exist)
    const Int operator()(Long_I i, Long_I j) const;
    Int &operator()(Long_I ind); // return element
    const Int operator()(Long_I ind) const;
    Long row(Long_I ind) const; // row index
    Long col(Long_I ind) const; // column index
    void trim(Long_I Nnz); // decrease m_Nnz to Nnz
    void resize(Long_I N); // set m_Nz
    void reserve(Long_I N); // reallocate memory, data will be lost m_Nz = 0
    void reshape(Long_I Nr, Long_I Nc); // change matrix shape
    void sort_r(); // sort to row major
};

McooInt::McooInt(Long_I Nr, Long_I Nc)
    : m_Nr(Nr), m_Nc(Nc), m_Nnz(0), m_row(0), m_col(0)
{
    m_N = 0;
}

McooInt::McooInt(Long_I Nr, Long_I Nc, Long_I Ncap) :
    Base(Ncap), m_Nr(Nr), m_Nc(Nc), m_Nnz(0), m_row(Ncap), m_col(Ncap) {}

McooInt::McooInt(const McooInt &rhs)
	: m_row(0), m_col(0)
{
    SLS_ERR("Copy constructor or move constructor is forbidden!");
}

Long * McooInt::row_ptr()
{
    return m_row.ptr();
}

const Long *McooInt::row_ptr() const
{
    return m_row.ptr();
}

Long * McooInt::col_ptr()
{
    return m_col.ptr();
}

const Long *McooInt::col_ptr() const
{
    return m_col.ptr();
}

Long McooInt::find(Long_I i, Long_I j) const
{
    for (Long n = 0; n < m_Nnz; ++n) {
        if (row(n) == i && col(n) == j)
            return n;
    }
    return -1;
}

Int& McooInt::ref(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("McooInt::operator()(i,j): index out of bounds!");
#endif
    Long n = find(i, j);
    if (n < 0)
        SLS_ERR("McooInt::operator()(i,j): element does not exist!");
    return m_p[n];
}

const Int McooInt::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("McooInt::operator()(i,j): index out of bounds!");
#endif
    Long n = find(i, j);
    if (n < 0)
        return 0; // never return a (const) reference to a temporary
    return m_p[n];
}

void McooInt::push(Int_I s, Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i<0 || i>=m_Nr || j<0 || j>=m_Nc)
        SLS_ERR("McooInt::push(): index out of bounds!");
#endif
#ifdef SLS_CHECK_COO_REPEAT
    Long n;
    for (n = 0; n < m_Nnz; ++n) {
        if (row(n) == i && col(n) == j)
            SLS_ERR("McooInt::push(s,i,j): element already exists!");
    }
#endif
    if (m_Nnz == m_N) SLS_ERR("McooInt::add(): out of memory, please reserve!");
    m_p[m_Nnz] = s; m_row[m_Nnz] = i; m_col[m_Nnz] = j;
    ++m_Nnz;
}

void McooInt::set(Int_I s, Long_I i, Long_I j)
{
    Long n;
    // change
    for (n = 0; n < m_Nnz; ++n) {
        if (row(n) == i && col(n) == j) {
            m_p[n] = s; m_row[n] = i; m_col[n] = j; return;
        }
    }
    // push
    if (m_Nnz == m_N) SLS_ERR("McooInt::add(): out of memory, please reserve!");
    m_p[m_Nnz] = s; m_row[m_Nnz] = i; m_col[m_Nnz] = j;
    ++m_Nnz;
}

Long McooInt::n1() const
{
    return m_Nr;
}

Long McooInt::n2() const
{
    return m_Nc;
}

Long McooInt::size() const
{
    return m_Nr * m_Nc;
}

Long McooInt::nnz() const
{
    return m_Nnz;
}

Long McooInt::capacity() const
{
    return Base::size();
}

Int & McooInt::operator()(Long_I ind)
{
#ifdef SLS_CHECK_BOUNDS
    if (ind<0 || ind>=m_Nnz)
        SLS_ERR("McooInt::operator(): subscript out of bounds!");
#endif
    return m_p[ind];
}

const Int McooInt::operator()(Long_I ind) const
{
#ifdef SLS_CHECK_BOUNDS
    if (ind<0 || ind>=m_Nnz)
        SLS_ERR("McooInt::operator() const: subscript out of bounds!");
#endif
    return m_p[ind];
}

Long McooInt::row(Long_I ind) const
{
#ifdef SLS_CHECK_BOUNDS
    if (ind<0 || ind>=m_Nnz)
        SLS_ERR("McooInt::row() subscript out of bounds");
#endif
    return m_row[ind];
}

Long McooInt::col(Long_I ind) const
{
#ifdef SLS_CHECK_BOUNDS
    if (ind < 0 || ind >= m_Nnz)
        SLS_ERR("McooInt::col() subscript out of bounds");
#endif
    return m_col[ind];
}

void McooInt::trim(Long_I Nnz)
{
#ifdef SLS_CHECK_SHAPE
    if (Nnz < 0)
        SLS_ERR("McooInt::trim() negative input!");
#endif
    if (Nnz < m_Nnz) m_Nnz = Nnz;
    else if (Nnz > m_Nnz) SLS_ERR("McooInt::trim(): Nnz > m_Nnz!");
}

void McooInt::resize(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > m_N)
        SLS_ERR("not enough capacity!");
#endif
    m_Nnz = N;
}

void McooInt::reserve(Long_I N)
{
    Base::resize(N);
    m_row.resize(N);
    m_col.resize(N);
    m_Nnz = 0;
}

void McooInt::reshape(Long_I Nr, Long_I Nc)
{
    m_Nr = Nr; m_Nc = Nc;
}

inline void McooInt::sort_r()
{
    VecLong inds(m_Nnz), order(m_Nnz);
    linspace(order, 0, m_Nnz - 1);
    for (Long i = 0; i < m_Nnz; ++i) {
        inds[i] = m_Nc * m_row[i] + m_col[i];
    }
    sort2(inds, order);
    Svector<Int> sli(m_p, m_Nnz);
    reorder(sli, order);
    Svector<Long> sli1;
    sli1.set_size(m_Nnz);
    sli1.set_ptr(m_row.ptr());
    reorder(sli1, order);
    sli1.set_ptr(m_col.ptr());
    reorder(sli1, order);
}

inline void reorder(SvecDoub_O v, VecLong_I order);
inline void reorder(SvecLong_O v, VecLong_I order);

class McooDoub : public Vbase<Doub>
{
private:
    typedef Vbase<Doub> Base;
    using Base::m_p;
    using Base::m_N;
    Long m_Nr, m_Nc, m_Nnz;
    VecLong m_row, m_col;
    // McooDoub() {} // default constructor: uninitialized
public:
    using Base::ptr;
    McooDoub(Long_I Nr, Long_I Nc);
    McooDoub(Long_I Nr, Long_I Nc, Long_I Ncap); // reserve Ncap elements
    McooDoub(const McooDoub &rhs);        // Copy constructor
    Long *row_ptr();
    const Long *row_ptr() const;
    Long *col_ptr();
    const Long *col_ptr() const;
    // inline void operator<<(McooDoub &rhs); // move data and rhs.resize(0, 0); rhs.resize(0)
    void push(Doub_I s, Long_I i, Long_I j); // add one nonzero element
    void set(Doub_I s, Long_I i, Long_I j); // change existing element or push new element
    Long n1() const;
    Long n2() const;
    Long size() const; // return m_Nr * m_Nc
    Long nnz() const; // return number of non-zero elements
    Long capacity() const;
    // get single index using double index, return -1 if not found
    Long find(Long_I i, Long_I j) const;
    // reference to an element (element must exist)
    Doub & ref(Long_I i, Long_I j);
    // double indexing (element need not exist)
    const Doub operator()(Long_I i, Long_I j) const;
    Doub &operator()(Long_I ind); // return element
    const Doub operator()(Long_I ind) const;
    Long row(Long_I ind) const; // row index
    Long col(Long_I ind) const; // column index
    void trim(Long_I Nnz); // decrease m_Nnz to Nnz
    void resize(Long_I N); // set m_Nz
    void reserve(Long_I N); // reallocate memory, data will be lost m_Nz = 0
    void reshape(Long_I Nr, Long_I Nc); // change matrix shape
    void sort_r(); // sort to row major
};

McooDoub::McooDoub(Long_I Nr, Long_I Nc)
    : m_Nr(Nr), m_Nc(Nc), m_Nnz(0), m_row(0), m_col(0)
{
    m_N = 0;
}

McooDoub::McooDoub(Long_I Nr, Long_I Nc, Long_I Ncap) :
    Base(Ncap), m_Nr(Nr), m_Nc(Nc), m_Nnz(0), m_row(Ncap), m_col(Ncap) {}

McooDoub::McooDoub(const McooDoub &rhs)
	: m_row(0), m_col(0)
{
    SLS_ERR("Copy constructor or move constructor is forbidden!");
}

Long * McooDoub::row_ptr()
{
    return m_row.ptr();
}

const Long *McooDoub::row_ptr() const
{
    return m_row.ptr();
}

Long * McooDoub::col_ptr()
{
    return m_col.ptr();
}

const Long *McooDoub::col_ptr() const
{
    return m_col.ptr();
}

Long McooDoub::find(Long_I i, Long_I j) const
{
    for (Long n = 0; n < m_Nnz; ++n) {
        if (row(n) == i && col(n) == j)
            return n;
    }
    return -1;
}

Doub& McooDoub::ref(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("McooDoub::operator()(i,j): index out of bounds!");
#endif
    Long n = find(i, j);
    if (n < 0)
        SLS_ERR("McooDoub::operator()(i,j): element does not exist!");
    return m_p[n];
}

const Doub McooDoub::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("McooDoub::operator()(i,j): index out of bounds!");
#endif
    Long n = find(i, j);
    if (n < 0)
        return 0; // never return a (const) reference to a temporary
    return m_p[n];
}

void McooDoub::push(Doub_I s, Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i<0 || i>=m_Nr || j<0 || j>=m_Nc)
        SLS_ERR("McooDoub::push(): index out of bounds!");
#endif
#ifdef SLS_CHECK_COO_REPEAT
    Long n;
    for (n = 0; n < m_Nnz; ++n) {
        if (row(n) == i && col(n) == j)
            SLS_ERR("McooDoub::push(s,i,j): element already exists!");
    }
#endif
    if (m_Nnz == m_N) SLS_ERR("McooDoub::add(): out of memory, please reserve!");
    m_p[m_Nnz] = s; m_row[m_Nnz] = i; m_col[m_Nnz] = j;
    ++m_Nnz;
}

void McooDoub::set(Doub_I s, Long_I i, Long_I j)
{
    Long n;
    // change
    for (n = 0; n < m_Nnz; ++n) {
        if (row(n) == i && col(n) == j) {
            m_p[n] = s; m_row[n] = i; m_col[n] = j; return;
        }
    }
    // push
    if (m_Nnz == m_N) SLS_ERR("McooDoub::add(): out of memory, please reserve!");
    m_p[m_Nnz] = s; m_row[m_Nnz] = i; m_col[m_Nnz] = j;
    ++m_Nnz;
}

Long McooDoub::n1() const
{
    return m_Nr;
}

Long McooDoub::n2() const
{
    return m_Nc;
}

Long McooDoub::size() const
{
    return m_Nr * m_Nc;
}

Long McooDoub::nnz() const
{
    return m_Nnz;
}

Long McooDoub::capacity() const
{
    return Base::size();
}

Doub & McooDoub::operator()(Long_I ind)
{
#ifdef SLS_CHECK_BOUNDS
    if (ind<0 || ind>=m_Nnz)
        SLS_ERR("McooDoub::operator(): subscript out of bounds!");
#endif
    return m_p[ind];
}

const Doub McooDoub::operator()(Long_I ind) const
{
#ifdef SLS_CHECK_BOUNDS
    if (ind<0 || ind>=m_Nnz)
        SLS_ERR("McooDoub::operator() const: subscript out of bounds!");
#endif
    return m_p[ind];
}

Long McooDoub::row(Long_I ind) const
{
#ifdef SLS_CHECK_BOUNDS
    if (ind<0 || ind>=m_Nnz)
        SLS_ERR("McooDoub::row() subscript out of bounds");
#endif
    return m_row[ind];
}

Long McooDoub::col(Long_I ind) const
{
#ifdef SLS_CHECK_BOUNDS
    if (ind < 0 || ind >= m_Nnz)
        SLS_ERR("McooDoub::col() subscript out of bounds");
#endif
    return m_col[ind];
}

void McooDoub::trim(Long_I Nnz)
{
#ifdef SLS_CHECK_SHAPE
    if (Nnz < 0)
        SLS_ERR("McooDoub::trim() negative input!");
#endif
    if (Nnz < m_Nnz) m_Nnz = Nnz;
    else if (Nnz > m_Nnz) SLS_ERR("McooDoub::trim(): Nnz > m_Nnz!");
}

void McooDoub::resize(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > m_N)
        SLS_ERR("not enough capacity!");
#endif
    m_Nnz = N;
}

void McooDoub::reserve(Long_I N)
{
    Base::resize(N);
    m_row.resize(N);
    m_col.resize(N);
    m_Nnz = 0;
}

void McooDoub::reshape(Long_I Nr, Long_I Nc)
{
    m_Nr = Nr; m_Nc = Nc;
}

inline void McooDoub::sort_r()
{
    VecLong inds(m_Nnz), order(m_Nnz);
    linspace(order, 0, m_Nnz - 1);
    for (Long i = 0; i < m_Nnz; ++i) {
        inds[i] = m_Nc * m_row[i] + m_col[i];
    }
    sort2(inds, order);
    Svector<Doub> sli(m_p, m_Nnz);
    reorder(sli, order);
    Svector<Long> sli1;
    sli1.set_size(m_Nnz);
    sli1.set_ptr(m_row.ptr());
    reorder(sli1, order);
    sli1.set_ptr(m_col.ptr());
    reorder(sli1, order);
}

inline void reorder(SvecComp_O v, VecLong_I order);
inline void reorder(SvecLong_O v, VecLong_I order);

class McooComp : public Vbase<Comp>
{
private:
    typedef Vbase<Comp> Base;
    using Base::m_p;
    using Base::m_N;
    Long m_Nr, m_Nc, m_Nnz;
    VecLong m_row, m_col;
    // McooComp() {} // default constructor: uninitialized
public:
    using Base::ptr;
    McooComp(Long_I Nr, Long_I Nc);
    McooComp(Long_I Nr, Long_I Nc, Long_I Ncap); // reserve Ncap elements
    McooComp(const McooComp &rhs);        // Copy constructor
    Long *row_ptr();
    const Long *row_ptr() const;
    Long *col_ptr();
    const Long *col_ptr() const;
    // inline void operator<<(McooComp &rhs); // move data and rhs.resize(0, 0); rhs.resize(0)
    void push(Comp_I s, Long_I i, Long_I j); // add one nonzero element
    void set(Comp_I s, Long_I i, Long_I j); // change existing element or push new element
    Long n1() const;
    Long n2() const;
    Long size() const; // return m_Nr * m_Nc
    Long nnz() const; // return number of non-zero elements
    Long capacity() const;
    // get single index using double index, return -1 if not found
    Long find(Long_I i, Long_I j) const;
    // reference to an element (element must exist)
    Comp & ref(Long_I i, Long_I j);
    // double indexing (element need not exist)
    const Comp operator()(Long_I i, Long_I j) const;
    Comp &operator()(Long_I ind); // return element
    const Comp operator()(Long_I ind) const;
    Long row(Long_I ind) const; // row index
    Long col(Long_I ind) const; // column index
    void trim(Long_I Nnz); // decrease m_Nnz to Nnz
    void resize(Long_I N); // set m_Nz
    void reserve(Long_I N); // reallocate memory, data will be lost m_Nz = 0
    void reshape(Long_I Nr, Long_I Nc); // change matrix shape
    void sort_r(); // sort to row major
};

McooComp::McooComp(Long_I Nr, Long_I Nc)
    : m_Nr(Nr), m_Nc(Nc), m_Nnz(0), m_row(0), m_col(0)
{
    m_N = 0;
}

McooComp::McooComp(Long_I Nr, Long_I Nc, Long_I Ncap) :
    Base(Ncap), m_Nr(Nr), m_Nc(Nc), m_Nnz(0), m_row(Ncap), m_col(Ncap) {}

McooComp::McooComp(const McooComp &rhs)
	: m_row(0), m_col(0)
{
    SLS_ERR("Copy constructor or move constructor is forbidden!");
}

Long * McooComp::row_ptr()
{
    return m_row.ptr();
}

const Long *McooComp::row_ptr() const
{
    return m_row.ptr();
}

Long * McooComp::col_ptr()
{
    return m_col.ptr();
}

const Long *McooComp::col_ptr() const
{
    return m_col.ptr();
}

Long McooComp::find(Long_I i, Long_I j) const
{
    for (Long n = 0; n < m_Nnz; ++n) {
        if (row(n) == i && col(n) == j)
            return n;
    }
    return -1;
}

Comp& McooComp::ref(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("McooComp::operator()(i,j): index out of bounds!");
#endif
    Long n = find(i, j);
    if (n < 0)
        SLS_ERR("McooComp::operator()(i,j): element does not exist!");
    return m_p[n];
}

const Comp McooComp::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("McooComp::operator()(i,j): index out of bounds!");
#endif
    Long n = find(i, j);
    if (n < 0)
        return 0; // never return a (const) reference to a temporary
    return m_p[n];
}

void McooComp::push(Comp_I s, Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i<0 || i>=m_Nr || j<0 || j>=m_Nc)
        SLS_ERR("McooComp::push(): index out of bounds!");
#endif
#ifdef SLS_CHECK_COO_REPEAT
    Long n;
    for (n = 0; n < m_Nnz; ++n) {
        if (row(n) == i && col(n) == j)
            SLS_ERR("McooComp::push(s,i,j): element already exists!");
    }
#endif
    if (m_Nnz == m_N) SLS_ERR("McooComp::add(): out of memory, please reserve!");
    m_p[m_Nnz] = s; m_row[m_Nnz] = i; m_col[m_Nnz] = j;
    ++m_Nnz;
}

void McooComp::set(Comp_I s, Long_I i, Long_I j)
{
    Long n;
    // change
    for (n = 0; n < m_Nnz; ++n) {
        if (row(n) == i && col(n) == j) {
            m_p[n] = s; m_row[n] = i; m_col[n] = j; return;
        }
    }
    // push
    if (m_Nnz == m_N) SLS_ERR("McooComp::add(): out of memory, please reserve!");
    m_p[m_Nnz] = s; m_row[m_Nnz] = i; m_col[m_Nnz] = j;
    ++m_Nnz;
}

Long McooComp::n1() const
{
    return m_Nr;
}

Long McooComp::n2() const
{
    return m_Nc;
}

Long McooComp::size() const
{
    return m_Nr * m_Nc;
}

Long McooComp::nnz() const
{
    return m_Nnz;
}

Long McooComp::capacity() const
{
    return Base::size();
}

Comp & McooComp::operator()(Long_I ind)
{
#ifdef SLS_CHECK_BOUNDS
    if (ind<0 || ind>=m_Nnz)
        SLS_ERR("McooComp::operator(): subscript out of bounds!");
#endif
    return m_p[ind];
}

const Comp McooComp::operator()(Long_I ind) const
{
#ifdef SLS_CHECK_BOUNDS
    if (ind<0 || ind>=m_Nnz)
        SLS_ERR("McooComp::operator() const: subscript out of bounds!");
#endif
    return m_p[ind];
}

Long McooComp::row(Long_I ind) const
{
#ifdef SLS_CHECK_BOUNDS
    if (ind<0 || ind>=m_Nnz)
        SLS_ERR("McooComp::row() subscript out of bounds");
#endif
    return m_row[ind];
}

Long McooComp::col(Long_I ind) const
{
#ifdef SLS_CHECK_BOUNDS
    if (ind < 0 || ind >= m_Nnz)
        SLS_ERR("McooComp::col() subscript out of bounds");
#endif
    return m_col[ind];
}

void McooComp::trim(Long_I Nnz)
{
#ifdef SLS_CHECK_SHAPE
    if (Nnz < 0)
        SLS_ERR("McooComp::trim() negative input!");
#endif
    if (Nnz < m_Nnz) m_Nnz = Nnz;
    else if (Nnz > m_Nnz) SLS_ERR("McooComp::trim(): Nnz > m_Nnz!");
}

void McooComp::resize(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
    if (N > m_N)
        SLS_ERR("not enough capacity!");
#endif
    m_Nnz = N;
}

void McooComp::reserve(Long_I N)
{
    Base::resize(N);
    m_row.resize(N);
    m_col.resize(N);
    m_Nnz = 0;
}

void McooComp::reshape(Long_I Nr, Long_I Nc)
{
    m_Nr = Nr; m_Nc = Nc;
}

inline void McooComp::sort_r()
{
    VecLong inds(m_Nnz), order(m_Nnz);
    linspace(order, 0, m_Nnz - 1);
    for (Long i = 0; i < m_Nnz; ++i) {
        inds[i] = m_Nc * m_row[i] + m_col[i];
    }
    sort2(inds, order);
    Svector<Comp> sli(m_p, m_Nnz);
    reorder(sli, order);
    Svector<Long> sli1;
    sli1.set_size(m_Nnz);
    sli1.set_ptr(m_row.ptr());
    reorder(sli1, order);
    sli1.set_ptr(m_col.ptr());
    reorder(sli1, order);
}

