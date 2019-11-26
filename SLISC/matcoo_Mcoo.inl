inline void reorder(SvecInt_O v, VecLong_I order);
inline void reorder(SvecInt_O v, VecLong_I order);

class McooInt : public Vbase<Int>
{
private:
    typedef Vbase<T> Base;
    using Base::m_p;
    using Base::m_N;
    Long m_Nr, m_Nc, m_Nnz;
    VecLong m_row, m_col;
    T m_zero = (T)0; // TODO: this could be static inline variable for c++17
    McooInt() {} // default constructor: uninitialized
public:
    using Base::ptr;
    McooInt(Long_I Nr, Long_I Nc);
    McooInt(Long_I Nr, Long_I Nc, Long_I Ncap); // reserve Ncap elements
    McooInt(const McooInt &rhs);        // Copy constructor
    Long *row_ptr();
    const Long *row_ptr() const;
    Long *col_ptr();
    const Long *col_ptr() const;
    McooInt & operator=(const McooInt &rhs);
    // inline void operator<<(McooInt &rhs); // move data and rhs.resize(0, 0); rhs.resize(0)
    void push(const T &s, Long_I i, Long_I j); // add one nonzero element
    void set(const T &s, Long_I i, Long_I j); // change existing element or push new element
    Long n1() const;
    Long n2() const;
    Long size() const; // return m_Nr * m_Nc
    Long nnz() const; // return number of non-zero elements
    Long capacity() const;
    // get single index using double index, return -1 if not found
    Long find(Long_I i, Long_I j) const;
    // reference to an element (element must exist)
    T& ref(Long_I i, Long_I j);
    // double indexing (element need not exist)
    const T& operator()(Long_I i, Long_I j) const;
    T &operator()(Long_I ind); // return element
    const T &operator()(Long_I ind) const;
    Long row(Long_I ind) const; // row index
    Long col(Long_I ind) const; // column index
    void trim(Long_I Nnz); // decrease m_Nnz to Nnz
    void resize(Long_I N); // set m_Nz
    void reserve(Long_I N); // reallocate memory, data will be lost m_Nz = 0
    void reshape(Long_I Nr, Long_I Nc); // change matrix shape
    void sort_r(); // sort to row major
};

McooInt::MatCoo(Long_I Nr, Long_I Nc)
    : m_Nr(Nr), m_Nc(Nc), m_Nnz(0), m_row(0), m_col(0)
{
    m_N = 0;
}

McooInt::MatCoo(Long_I Nr, Long_I Nc, Long_I Ncap) :
    Base(Ncap), m_Nr(Nr), m_Nc(Nc), m_Nnz(0), m_row(Ncap), m_col(Ncap) {}

McooInt::MatCoo(const McooInt &rhs)
{
    SLS_ERR("Copy constructor or move constructor is forbidden, use reference "
         "argument for function input or output, and use "=" to copy!");
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

McooInt & McooInt::operator=(const McooInt &rhs)
{
    copy(*this, rhs);
    return *this;
}

Long McooInt::find(Long_I i, Long_I j) const
{
    for (Long n = 0; n < m_Nnz; ++n) {
        if (row(n) == i && col(n) == j)
            return n;
    }
    return -1;
}

T& McooInt::ref(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("MatCoo::operator()(i,j): index out of bounds!");
#endif
    Long n = find(i, j);
    if (n < 0)
        SLS_ERR("MatCoo::operator()(i,j): element does not exist!");
    return m_p[n];
}

const T &McooInt::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("MatCoo::operator()(i,j): index out of bounds!");
#endif
    Long n = find(i, j);
    if (n < 0)
        return m_zero; // never return a (const) reference to a temporary
    return m_p[n];
}

void McooInt::push(const T &s, Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i<0 || i>=m_Nr || j<0 || j>=m_Nc)
        SLS_ERR("MatCoo::push(): index out of bounds!");
#endif
#ifdef SLS_CHECK_COO_REPEAT
    Long n;
    for (n = 0; n < m_Nnz; ++n) {
        if (row(n) == i && col(n) == j)
            SLS_ERR("MatCoo::push(s,i,j): element already exists!");
    }
#endif
    if (m_Nnz == m_N) SLS_ERR("MatCoo::add(): out of memory, please reserve!");
    m_p[m_Nnz] = s; m_row[m_Nnz] = i; m_col[m_Nnz] = j;
    ++m_Nnz;
}

void McooInt::set(const T &s, Long_I i, Long_I j)
{
    Long n;
    // change
    for (n = 0; n < m_Nnz; ++n) {
        if (row(n) == i && col(n) == j) {
            m_p[n] = s; m_row[n] = i; m_col[n] = j; return;
        }
    }
    // push
    if (m_Nnz == m_N) SLS_ERR("MatCoo::add(): out of memory, please reserve!");
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

T & McooInt::operator()(Long_I ind)
{
#ifdef SLS_CHECK_BOUNDS
    if (ind<0 || ind>=m_Nnz)
        SLS_ERR("MatCoo::operator(): subscript out of bounds!");
#endif
    return m_p[ind];
}

const T & McooInt::operator()(Long_I ind) const
{
#ifdef SLS_CHECK_BOUNDS
    if (ind<0 || ind>=m_Nnz)
        SLS_ERR("MatCoo::operator() const: subscript out of bounds!");
#endif
    return m_p[ind];
}

Long McooInt::row(Long_I ind) const
{
#ifdef SLS_CHECK_BOUNDS
    if (ind<0 || ind>=m_Nnz)
        SLS_ERR("MatCoo::row() subscript out of bounds");
#endif
    return m_row[ind];
}

Long McooInt::col(Long_I ind) const
{
#ifdef SLS_CHECK_BOUNDS
    if (ind < 0 || ind >= m_Nnz)
        SLS_ERR("MatCoo::col() subscript out of bounds");
#endif
    return m_col[ind];
}

void McooInt::trim(Long_I Nnz)
{
#ifdef SLS_CHECK_SHAPE
    if (Nnz < 0)
        SLS_ERR("MatCoo::trim() negative input!");
#endif
    if (Nnz < m_Nnz) m_Nnz = Nnz;
    else if (Nnz > m_Nnz) SLS_ERR("MatCoo::trim(): Nnz > m_Nnz!");
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
    Svector<T> sli(m_p, m_Nnz);
    reorder(sli, order);
    Svector<Long> sli1;
    sli1.set_size(m_Nnz);
    sli1.set_ptr(m_row.ptr());
    reorder(sli1, order);
    sli1.set_ptr(m_col.ptr());
    reorder(sli1, order);
}

inline void reorder(SvecDoub_O v, VecLong_I order);
inline void reorder(SvecDoub_O v, VecLong_I order);

class McooDoub : public Vbase<Doub>
{
private:
    typedef Vbase<T> Base;
    using Base::m_p;
    using Base::m_N;
    Long m_Nr, m_Nc, m_Nnz;
    VecLong m_row, m_col;
    T m_zero = (T)0; // TODO: this could be static inline variable for c++17
    McooDoub() {} // default constructor: uninitialized
public:
    using Base::ptr;
    McooDoub(Long_I Nr, Long_I Nc);
    McooDoub(Long_I Nr, Long_I Nc, Long_I Ncap); // reserve Ncap elements
    McooDoub(const McooDoub &rhs);        // Copy constructor
    Long *row_ptr();
    const Long *row_ptr() const;
    Long *col_ptr();
    const Long *col_ptr() const;
    McooDoub & operator=(const McooDoub &rhs);
    // inline void operator<<(McooDoub &rhs); // move data and rhs.resize(0, 0); rhs.resize(0)
    void push(const T &s, Long_I i, Long_I j); // add one nonzero element
    void set(const T &s, Long_I i, Long_I j); // change existing element or push new element
    Long n1() const;
    Long n2() const;
    Long size() const; // return m_Nr * m_Nc
    Long nnz() const; // return number of non-zero elements
    Long capacity() const;
    // get single index using double index, return -1 if not found
    Long find(Long_I i, Long_I j) const;
    // reference to an element (element must exist)
    T& ref(Long_I i, Long_I j);
    // double indexing (element need not exist)
    const T& operator()(Long_I i, Long_I j) const;
    T &operator()(Long_I ind); // return element
    const T &operator()(Long_I ind) const;
    Long row(Long_I ind) const; // row index
    Long col(Long_I ind) const; // column index
    void trim(Long_I Nnz); // decrease m_Nnz to Nnz
    void resize(Long_I N); // set m_Nz
    void reserve(Long_I N); // reallocate memory, data will be lost m_Nz = 0
    void reshape(Long_I Nr, Long_I Nc); // change matrix shape
    void sort_r(); // sort to row major
};

McooDoub::MatCoo(Long_I Nr, Long_I Nc)
    : m_Nr(Nr), m_Nc(Nc), m_Nnz(0), m_row(0), m_col(0)
{
    m_N = 0;
}

McooDoub::MatCoo(Long_I Nr, Long_I Nc, Long_I Ncap) :
    Base(Ncap), m_Nr(Nr), m_Nc(Nc), m_Nnz(0), m_row(Ncap), m_col(Ncap) {}

McooDoub::MatCoo(const McooDoub &rhs)
{
    SLS_ERR("Copy constructor or move constructor is forbidden, use reference "
         "argument for function input or output, and use "=" to copy!");
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

McooDoub & McooDoub::operator=(const McooDoub &rhs)
{
    copy(*this, rhs);
    return *this;
}

Long McooDoub::find(Long_I i, Long_I j) const
{
    for (Long n = 0; n < m_Nnz; ++n) {
        if (row(n) == i && col(n) == j)
            return n;
    }
    return -1;
}

T& McooDoub::ref(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("MatCoo::operator()(i,j): index out of bounds!");
#endif
    Long n = find(i, j);
    if (n < 0)
        SLS_ERR("MatCoo::operator()(i,j): element does not exist!");
    return m_p[n];
}

const T &McooDoub::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("MatCoo::operator()(i,j): index out of bounds!");
#endif
    Long n = find(i, j);
    if (n < 0)
        return m_zero; // never return a (const) reference to a temporary
    return m_p[n];
}

void McooDoub::push(const T &s, Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i<0 || i>=m_Nr || j<0 || j>=m_Nc)
        SLS_ERR("MatCoo::push(): index out of bounds!");
#endif
#ifdef SLS_CHECK_COO_REPEAT
    Long n;
    for (n = 0; n < m_Nnz; ++n) {
        if (row(n) == i && col(n) == j)
            SLS_ERR("MatCoo::push(s,i,j): element already exists!");
    }
#endif
    if (m_Nnz == m_N) SLS_ERR("MatCoo::add(): out of memory, please reserve!");
    m_p[m_Nnz] = s; m_row[m_Nnz] = i; m_col[m_Nnz] = j;
    ++m_Nnz;
}

void McooDoub::set(const T &s, Long_I i, Long_I j)
{
    Long n;
    // change
    for (n = 0; n < m_Nnz; ++n) {
        if (row(n) == i && col(n) == j) {
            m_p[n] = s; m_row[n] = i; m_col[n] = j; return;
        }
    }
    // push
    if (m_Nnz == m_N) SLS_ERR("MatCoo::add(): out of memory, please reserve!");
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

T & McooDoub::operator()(Long_I ind)
{
#ifdef SLS_CHECK_BOUNDS
    if (ind<0 || ind>=m_Nnz)
        SLS_ERR("MatCoo::operator(): subscript out of bounds!");
#endif
    return m_p[ind];
}

const T & McooDoub::operator()(Long_I ind) const
{
#ifdef SLS_CHECK_BOUNDS
    if (ind<0 || ind>=m_Nnz)
        SLS_ERR("MatCoo::operator() const: subscript out of bounds!");
#endif
    return m_p[ind];
}

Long McooDoub::row(Long_I ind) const
{
#ifdef SLS_CHECK_BOUNDS
    if (ind<0 || ind>=m_Nnz)
        SLS_ERR("MatCoo::row() subscript out of bounds");
#endif
    return m_row[ind];
}

Long McooDoub::col(Long_I ind) const
{
#ifdef SLS_CHECK_BOUNDS
    if (ind < 0 || ind >= m_Nnz)
        SLS_ERR("MatCoo::col() subscript out of bounds");
#endif
    return m_col[ind];
}

void McooDoub::trim(Long_I Nnz)
{
#ifdef SLS_CHECK_SHAPE
    if (Nnz < 0)
        SLS_ERR("MatCoo::trim() negative input!");
#endif
    if (Nnz < m_Nnz) m_Nnz = Nnz;
    else if (Nnz > m_Nnz) SLS_ERR("MatCoo::trim(): Nnz > m_Nnz!");
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
    Svector<T> sli(m_p, m_Nnz);
    reorder(sli, order);
    Svector<Long> sli1;
    sli1.set_size(m_Nnz);
    sli1.set_ptr(m_row.ptr());
    reorder(sli1, order);
    sli1.set_ptr(m_col.ptr());
    reorder(sli1, order);
}

inline void reorder(SvecComp_O v, VecLong_I order);
inline void reorder(SvecComp_O v, VecLong_I order);

class McooComp : public Vbase<Comp>
{
private:
    typedef Vbase<T> Base;
    using Base::m_p;
    using Base::m_N;
    Long m_Nr, m_Nc, m_Nnz;
    VecLong m_row, m_col;
    T m_zero = (T)0; // TODO: this could be static inline variable for c++17
    McooComp() {} // default constructor: uninitialized
public:
    using Base::ptr;
    McooComp(Long_I Nr, Long_I Nc);
    McooComp(Long_I Nr, Long_I Nc, Long_I Ncap); // reserve Ncap elements
    McooComp(const McooComp &rhs);        // Copy constructor
    Long *row_ptr();
    const Long *row_ptr() const;
    Long *col_ptr();
    const Long *col_ptr() const;
    McooComp & operator=(const McooComp &rhs);
    // inline void operator<<(McooComp &rhs); // move data and rhs.resize(0, 0); rhs.resize(0)
    void push(const T &s, Long_I i, Long_I j); // add one nonzero element
    void set(const T &s, Long_I i, Long_I j); // change existing element or push new element
    Long n1() const;
    Long n2() const;
    Long size() const; // return m_Nr * m_Nc
    Long nnz() const; // return number of non-zero elements
    Long capacity() const;
    // get single index using double index, return -1 if not found
    Long find(Long_I i, Long_I j) const;
    // reference to an element (element must exist)
    T& ref(Long_I i, Long_I j);
    // double indexing (element need not exist)
    const T& operator()(Long_I i, Long_I j) const;
    T &operator()(Long_I ind); // return element
    const T &operator()(Long_I ind) const;
    Long row(Long_I ind) const; // row index
    Long col(Long_I ind) const; // column index
    void trim(Long_I Nnz); // decrease m_Nnz to Nnz
    void resize(Long_I N); // set m_Nz
    void reserve(Long_I N); // reallocate memory, data will be lost m_Nz = 0
    void reshape(Long_I Nr, Long_I Nc); // change matrix shape
    void sort_r(); // sort to row major
};

McooComp::MatCoo(Long_I Nr, Long_I Nc)
    : m_Nr(Nr), m_Nc(Nc), m_Nnz(0), m_row(0), m_col(0)
{
    m_N = 0;
}

McooComp::MatCoo(Long_I Nr, Long_I Nc, Long_I Ncap) :
    Base(Ncap), m_Nr(Nr), m_Nc(Nc), m_Nnz(0), m_row(Ncap), m_col(Ncap) {}

McooComp::MatCoo(const McooComp &rhs)
{
    SLS_ERR("Copy constructor or move constructor is forbidden, use reference "
         "argument for function input or output, and use "=" to copy!");
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

McooComp & McooComp::operator=(const McooComp &rhs)
{
    copy(*this, rhs);
    return *this;
}

Long McooComp::find(Long_I i, Long_I j) const
{
    for (Long n = 0; n < m_Nnz; ++n) {
        if (row(n) == i && col(n) == j)
            return n;
    }
    return -1;
}

T& McooComp::ref(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("MatCoo::operator()(i,j): index out of bounds!");
#endif
    Long n = find(i, j);
    if (n < 0)
        SLS_ERR("MatCoo::operator()(i,j): element does not exist!");
    return m_p[n];
}

const T &McooComp::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_Nr || j < 0 || j >= m_Nc)
        SLS_ERR("MatCoo::operator()(i,j): index out of bounds!");
#endif
    Long n = find(i, j);
    if (n < 0)
        return m_zero; // never return a (const) reference to a temporary
    return m_p[n];
}

void McooComp::push(const T &s, Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
    if (i<0 || i>=m_Nr || j<0 || j>=m_Nc)
        SLS_ERR("MatCoo::push(): index out of bounds!");
#endif
#ifdef SLS_CHECK_COO_REPEAT
    Long n;
    for (n = 0; n < m_Nnz; ++n) {
        if (row(n) == i && col(n) == j)
            SLS_ERR("MatCoo::push(s,i,j): element already exists!");
    }
#endif
    if (m_Nnz == m_N) SLS_ERR("MatCoo::add(): out of memory, please reserve!");
    m_p[m_Nnz] = s; m_row[m_Nnz] = i; m_col[m_Nnz] = j;
    ++m_Nnz;
}

void McooComp::set(const T &s, Long_I i, Long_I j)
{
    Long n;
    // change
    for (n = 0; n < m_Nnz; ++n) {
        if (row(n) == i && col(n) == j) {
            m_p[n] = s; m_row[n] = i; m_col[n] = j; return;
        }
    }
    // push
    if (m_Nnz == m_N) SLS_ERR("MatCoo::add(): out of memory, please reserve!");
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

T & McooComp::operator()(Long_I ind)
{
#ifdef SLS_CHECK_BOUNDS
    if (ind<0 || ind>=m_Nnz)
        SLS_ERR("MatCoo::operator(): subscript out of bounds!");
#endif
    return m_p[ind];
}

const T & McooComp::operator()(Long_I ind) const
{
#ifdef SLS_CHECK_BOUNDS
    if (ind<0 || ind>=m_Nnz)
        SLS_ERR("MatCoo::operator() const: subscript out of bounds!");
#endif
    return m_p[ind];
}

Long McooComp::row(Long_I ind) const
{
#ifdef SLS_CHECK_BOUNDS
    if (ind<0 || ind>=m_Nnz)
        SLS_ERR("MatCoo::row() subscript out of bounds");
#endif
    return m_row[ind];
}

Long McooComp::col(Long_I ind) const
{
#ifdef SLS_CHECK_BOUNDS
    if (ind < 0 || ind >= m_Nnz)
        SLS_ERR("MatCoo::col() subscript out of bounds");
#endif
    return m_col[ind];
}

void McooComp::trim(Long_I Nnz)
{
#ifdef SLS_CHECK_SHAPE
    if (Nnz < 0)
        SLS_ERR("MatCoo::trim() negative input!");
#endif
    if (Nnz < m_Nnz) m_Nnz = Nnz;
    else if (Nnz > m_Nnz) SLS_ERR("MatCoo::trim(): Nnz > m_Nnz!");
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
    Svector<T> sli(m_p, m_Nnz);
    reorder(sli, order);
    Svector<Long> sli1;
    sli1.set_size(m_Nnz);
    sli1.set_ptr(m_row.ptr());
    reorder(sli1, order);
    sli1.set_ptr(m_col.ptr());
    reorder(sli1, order);
}

