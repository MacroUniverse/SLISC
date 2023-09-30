#pragma once
#include "../dense/Vec.h"
// will be simpler to just use vector<tuple<Long,Long,T>>

namespace slisc {

template <class T>
void veccpy(T *, const T *, Long_I);


class McooChar : public VecChar
{
private:
	typedef VecChar Base;
	using Base::m_p;
	using Base::m_N;
	Long m_N0, m_N1, m_Nnz;
	VecLong m_row, m_col;
public:
	using Base::p;
	McooChar(): m_N0(0), m_N1(0), m_Nnz(0) {};
	McooChar(const McooChar &rhs) = default; // copy constructor
	McooChar(McooChar &&rhs); // move constructor
	McooChar(Long_I N0, Long_I N1);
	McooChar(Long_I N0, Long_I N1, Long_I Ncap); // reserve Ncap elements
	Long *row_p();
	const Long *row_p() const;
	Long *col_p();
	const Long *col_p() const;
	McooChar &operator=(const McooChar &rhs) = default; // copy assignment
	McooChar &operator=(McooChar &&rhs); // move assignment
	void push(Char_I s, Long_I i, Long_I j); // add one nonzero element
	void set(Char_I s, Long_I i, Long_I j); // change existing element or push new element
	Long n0() const;
	Long n1() const;
	Long size() const; // return m_N0 * m_N1
	Long nnz() const; // return number of non-zero elements
	Long capacity() const;
	// get single index using double index, return -1 if not found
	Long find(Long_I i, Long_I j) const;
	// reference to an element (element must exist)
	Char &ref(Long_I i, Long_I j);
	// double indexing (element need not exist)
	Char operator()(Long_I i, Long_I j) const;
	Char &operator[](Long_I ind); // return element
	Char operator[](Long_I ind) const;
	const Long &row(Long_I ind) const; // row index
	Long &row(Long_I ind);
	const Long &col(Long_I ind) const; // column index
	Long &col(Long_I ind);
	void trim(Long_I Nnz); // decrease m_Nnz to Nnz
	void resize(Long_I N); // set m_Nz
	void reserve(Long_I N); // reallocate memory, data will be lost m_Nz = 0
	void reserve_cpy(Long_I N); // reserve and conserve data
	void reshape(Long_I N0, Long_I N1); // change matrix shape
};

typedef const McooChar &McooChar_I;
typedef McooChar &McooChar_O, &McooChar_IO;

inline McooChar::McooChar(Long_I N0, Long_I N1)
	: Base(0), m_N0(N0), m_N1(N1), m_Nnz(0), m_row(0), m_col(0)
{
	m_N = 0;
}

inline McooChar::McooChar(Long_I N0, Long_I N1, Long_I Ncap) :
	Base(Ncap), m_N0(N0), m_N1(N1), m_Nnz(0), m_row(Ncap), m_col(Ncap) {}

inline McooChar::McooChar(McooChar &&rhs) :
	Base(move(Base(rhs))), m_N0(rhs.m_N0), m_N1(rhs.m_N1), m_Nnz(rhs.m_Nnz),
	m_row(move(rhs.m_row)), m_col(move(rhs.m_col))
{
	rhs.m_Nnz = 0;
}

inline Long * McooChar::row_p()
{
	return m_row.p();
}

inline const Long *McooChar::row_p() const
{
	return m_row.p();
}

inline Long * McooChar::col_p()
{
	return m_col.p();
}

inline const Long *McooChar::col_p() const
{
	return m_col.p();
}

inline Long McooChar::find(Long_I i, Long_I j) const
{
	for (Long n = 0; n < m_Nnz; ++n) {
		if (row(n) == i && col(n) == j)
			return n;
	}
	return -1;
}

inline Char& McooChar::ref(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("McooChar::operator()(i,j): index out of bounds!");
#endif
	Long n = find(i, j);
	if (n < 0)
		SLS_ERR("McooChar::operator()(i,j): element does not exist!");
	return m_p[n];
}

inline Char McooChar::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("McooChar::operator()(i,j): index out of bounds!");
#endif
	Long n = find(i, j);
	if (n < 0)
		return Char(0);
	return m_p[n];
}

inline McooChar &McooChar::operator=(McooChar &&rhs)
{
	Base::operator=(std::move(rhs));
	m_row = std::move(rhs.m_row); m_col = std::move(rhs.m_col);
	m_Nnz = rhs.m_Nnz;
	rhs.m_Nnz = 0; rhs.m_N = 0;
	return *this;
}

inline void McooChar::push(Char_I s, Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i<0 || i>=m_N0 || j<0 || j>=m_N1)
		SLS_ERR("McooChar::push(): index out of bounds!");
#endif
#ifdef SLS_CHECK_COO_REPEAT
	Long n;
	for (n = 0; n < m_Nnz; ++n) {
		if (row(n) == i && col(n) == j)
			SLS_ERR("McooChar::push(s,i,j): element already exists!");
	}
#endif
	if (m_Nnz == m_N)
		SLS_ERR("McooChar::push(): out of capacity, please reserve! m_N = " + to_string(m_N));
	m_p[m_Nnz] = s; m_row[m_Nnz] = i; m_col[m_Nnz] = j;
	++m_Nnz;
}

inline void McooChar::set(Char_I s, Long_I i, Long_I j)
{
	Long n;
	// change
	for (n = 0; n < m_Nnz; ++n) {
		if (row(n) == i && col(n) == j) {
			m_p[n] = s; m_row[n] = i; m_col[n] = j; return;
		}
	}
	// push
	if (m_Nnz == m_N)
		SLS_ERR("McooChar::set(): out of capacity, please reserve! m_N = " + to_string(m_N));
	m_p[m_Nnz] = s; m_row[m_Nnz] = i; m_col[m_Nnz] = j;
	++m_Nnz;
}

inline Long McooChar::n0() const
{
	return m_N0;
}

inline Long McooChar::n1() const
{
	return m_N1;
}

inline Long McooChar::size() const
{
	return m_N0 * m_N1;
}

inline Long McooChar::nnz() const
{
	return m_Nnz;
}

inline Long McooChar::capacity() const
{
	return Base::size();
}

inline Char &McooChar::operator[](Long_I ind)
{
#ifdef SLS_CHECK_BOUNDS
	if (ind<0 || ind>=m_Nnz)
		SLS_ERR("McooChar::operator(): subscript out of bounds!");
#endif
	return m_p[ind];
}

inline Char McooChar::operator[](Long_I ind) const
{
#ifdef SLS_CHECK_BOUNDS
	if (ind<0 || ind>=m_Nnz)
		SLS_ERR("McooChar::operator() const: subscript out of bounds!");
#endif
	return m_p[ind];
}

inline const Long &McooChar::row(Long_I ind) const
{
#ifdef SLS_CHECK_BOUNDS
	if (ind<0 || ind>=m_Nnz)
		SLS_ERR("McooChar::row() subscript out of bounds");
#endif
	return m_row[ind];
}

inline Long &McooChar::row(Long_I ind)
{
#ifdef SLS_CHECK_BOUNDS
	if (ind<0 || ind>=m_Nnz)
		SLS_ERR("McooChar::row() subscript out of bounds");
#endif
	return m_row[ind];
}

inline const Long &McooChar::col(Long_I ind) const
{
#ifdef SLS_CHECK_BOUNDS
	if (ind < 0 || ind >= m_Nnz)
		SLS_ERR("McooChar::col() subscript out of bounds");
#endif
	return m_col[ind];
}

inline Long &McooChar::col(Long_I ind)
{
#ifdef SLS_CHECK_BOUNDS
	if (ind < 0 || ind >= m_Nnz)
		SLS_ERR("McooChar::col() subscript out of bounds");
#endif
	return m_col[ind];
}

inline void McooChar::trim(Long_I Nnz)
{
#ifdef SLS_CHECK_SHAPES
	if (Nnz < 0)
		SLS_ERR("McooChar::trim() negative input!");
#endif
	if (Nnz < m_Nnz) m_Nnz = Nnz;
	else if (Nnz > m_Nnz) SLS_ERR("McooChar::trim(): Nnz > m_Nnz!");
}

inline void McooChar::resize(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (N > m_N)
		SLS_ERR("not enough capacity!");
#endif
	m_Nnz = N;
}

inline void McooChar::reserve(Long_I N)
{
	Base::resize(N);
	m_row.resize(N);
	m_col.resize(N);
	m_Nnz = 0;
}

inline void McooChar::reserve_cpy(Long_I N)
{
	VecChar data(N);
	VecLong row(N), col(N);
	veccpy(data.p(), m_p, m_Nnz);
	veccpy(row.p(), m_row.p(), m_Nnz);
	veccpy(col.p(), m_col.p(), m_Nnz);
	Base::operator=(std::move(data));
	m_row = std::move(row);
	m_col = std::move(col);
}

inline void McooChar::reshape(Long_I N0, Long_I N1)
{
	m_N0 = N0; m_N1 = N1;
}


class McooInt : public VecInt
{
private:
	typedef VecInt Base;
	using Base::m_p;
	using Base::m_N;
	Long m_N0, m_N1, m_Nnz;
	VecLong m_row, m_col;
public:
	using Base::p;
	McooInt(): m_N0(0), m_N1(0), m_Nnz(0) {};
	McooInt(const McooInt &rhs) = default; // copy constructor
	McooInt(McooInt &&rhs); // move constructor
	McooInt(Long_I N0, Long_I N1);
	McooInt(Long_I N0, Long_I N1, Long_I Ncap); // reserve Ncap elements
	Long *row_p();
	const Long *row_p() const;
	Long *col_p();
	const Long *col_p() const;
	McooInt &operator=(const McooInt &rhs) = default; // copy assignment
	McooInt &operator=(McooInt &&rhs); // move assignment
	void push(Int_I s, Long_I i, Long_I j); // add one nonzero element
	void set(Int_I s, Long_I i, Long_I j); // change existing element or push new element
	Long n0() const;
	Long n1() const;
	Long size() const; // return m_N0 * m_N1
	Long nnz() const; // return number of non-zero elements
	Long capacity() const;
	// get single index using double index, return -1 if not found
	Long find(Long_I i, Long_I j) const;
	// reference to an element (element must exist)
	Int &ref(Long_I i, Long_I j);
	// double indexing (element need not exist)
	Int operator()(Long_I i, Long_I j) const;
	Int &operator[](Long_I ind); // return element
	Int operator[](Long_I ind) const;
	const Long &row(Long_I ind) const; // row index
	Long &row(Long_I ind);
	const Long &col(Long_I ind) const; // column index
	Long &col(Long_I ind);
	void trim(Long_I Nnz); // decrease m_Nnz to Nnz
	void resize(Long_I N); // set m_Nz
	void reserve(Long_I N); // reallocate memory, data will be lost m_Nz = 0
	void reserve_cpy(Long_I N); // reserve and conserve data
	void reshape(Long_I N0, Long_I N1); // change matrix shape
};

typedef const McooInt &McooInt_I;
typedef McooInt &McooInt_O, &McooInt_IO;

inline McooInt::McooInt(Long_I N0, Long_I N1)
	: Base(0), m_N0(N0), m_N1(N1), m_Nnz(0), m_row(0), m_col(0)
{
	m_N = 0;
}

inline McooInt::McooInt(Long_I N0, Long_I N1, Long_I Ncap) :
	Base(Ncap), m_N0(N0), m_N1(N1), m_Nnz(0), m_row(Ncap), m_col(Ncap) {}

inline McooInt::McooInt(McooInt &&rhs) :
	Base(move(Base(rhs))), m_N0(rhs.m_N0), m_N1(rhs.m_N1), m_Nnz(rhs.m_Nnz),
	m_row(move(rhs.m_row)), m_col(move(rhs.m_col))
{
	rhs.m_Nnz = 0;
}

inline Long * McooInt::row_p()
{
	return m_row.p();
}

inline const Long *McooInt::row_p() const
{
	return m_row.p();
}

inline Long * McooInt::col_p()
{
	return m_col.p();
}

inline const Long *McooInt::col_p() const
{
	return m_col.p();
}

inline Long McooInt::find(Long_I i, Long_I j) const
{
	for (Long n = 0; n < m_Nnz; ++n) {
		if (row(n) == i && col(n) == j)
			return n;
	}
	return -1;
}

inline Int& McooInt::ref(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("McooInt::operator()(i,j): index out of bounds!");
#endif
	Long n = find(i, j);
	if (n < 0)
		SLS_ERR("McooInt::operator()(i,j): element does not exist!");
	return m_p[n];
}

inline Int McooInt::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("McooInt::operator()(i,j): index out of bounds!");
#endif
	Long n = find(i, j);
	if (n < 0)
		return Int(0);
	return m_p[n];
}

inline McooInt &McooInt::operator=(McooInt &&rhs)
{
	Base::operator=(std::move(rhs));
	m_row = std::move(rhs.m_row); m_col = std::move(rhs.m_col);
	m_Nnz = rhs.m_Nnz;
	rhs.m_Nnz = 0; rhs.m_N = 0;
	return *this;
}

inline void McooInt::push(Int_I s, Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i<0 || i>=m_N0 || j<0 || j>=m_N1)
		SLS_ERR("McooInt::push(): index out of bounds!");
#endif
#ifdef SLS_CHECK_COO_REPEAT
	Long n;
	for (n = 0; n < m_Nnz; ++n) {
		if (row(n) == i && col(n) == j)
			SLS_ERR("McooInt::push(s,i,j): element already exists!");
	}
#endif
	if (m_Nnz == m_N)
		SLS_ERR("McooInt::push(): out of capacity, please reserve! m_N = " + to_string(m_N));
	m_p[m_Nnz] = s; m_row[m_Nnz] = i; m_col[m_Nnz] = j;
	++m_Nnz;
}

inline void McooInt::set(Int_I s, Long_I i, Long_I j)
{
	Long n;
	// change
	for (n = 0; n < m_Nnz; ++n) {
		if (row(n) == i && col(n) == j) {
			m_p[n] = s; m_row[n] = i; m_col[n] = j; return;
		}
	}
	// push
	if (m_Nnz == m_N)
		SLS_ERR("McooInt::set(): out of capacity, please reserve! m_N = " + to_string(m_N));
	m_p[m_Nnz] = s; m_row[m_Nnz] = i; m_col[m_Nnz] = j;
	++m_Nnz;
}

inline Long McooInt::n0() const
{
	return m_N0;
}

inline Long McooInt::n1() const
{
	return m_N1;
}

inline Long McooInt::size() const
{
	return m_N0 * m_N1;
}

inline Long McooInt::nnz() const
{
	return m_Nnz;
}

inline Long McooInt::capacity() const
{
	return Base::size();
}

inline Int &McooInt::operator[](Long_I ind)
{
#ifdef SLS_CHECK_BOUNDS
	if (ind<0 || ind>=m_Nnz)
		SLS_ERR("McooInt::operator(): subscript out of bounds!");
#endif
	return m_p[ind];
}

inline Int McooInt::operator[](Long_I ind) const
{
#ifdef SLS_CHECK_BOUNDS
	if (ind<0 || ind>=m_Nnz)
		SLS_ERR("McooInt::operator() const: subscript out of bounds!");
#endif
	return m_p[ind];
}

inline const Long &McooInt::row(Long_I ind) const
{
#ifdef SLS_CHECK_BOUNDS
	if (ind<0 || ind>=m_Nnz)
		SLS_ERR("McooInt::row() subscript out of bounds");
#endif
	return m_row[ind];
}

inline Long &McooInt::row(Long_I ind)
{
#ifdef SLS_CHECK_BOUNDS
	if (ind<0 || ind>=m_Nnz)
		SLS_ERR("McooInt::row() subscript out of bounds");
#endif
	return m_row[ind];
}

inline const Long &McooInt::col(Long_I ind) const
{
#ifdef SLS_CHECK_BOUNDS
	if (ind < 0 || ind >= m_Nnz)
		SLS_ERR("McooInt::col() subscript out of bounds");
#endif
	return m_col[ind];
}

inline Long &McooInt::col(Long_I ind)
{
#ifdef SLS_CHECK_BOUNDS
	if (ind < 0 || ind >= m_Nnz)
		SLS_ERR("McooInt::col() subscript out of bounds");
#endif
	return m_col[ind];
}

inline void McooInt::trim(Long_I Nnz)
{
#ifdef SLS_CHECK_SHAPES
	if (Nnz < 0)
		SLS_ERR("McooInt::trim() negative input!");
#endif
	if (Nnz < m_Nnz) m_Nnz = Nnz;
	else if (Nnz > m_Nnz) SLS_ERR("McooInt::trim(): Nnz > m_Nnz!");
}

inline void McooInt::resize(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (N > m_N)
		SLS_ERR("not enough capacity!");
#endif
	m_Nnz = N;
}

inline void McooInt::reserve(Long_I N)
{
	Base::resize(N);
	m_row.resize(N);
	m_col.resize(N);
	m_Nnz = 0;
}

inline void McooInt::reserve_cpy(Long_I N)
{
	VecInt data(N);
	VecLong row(N), col(N);
	veccpy(data.p(), m_p, m_Nnz);
	veccpy(row.p(), m_row.p(), m_Nnz);
	veccpy(col.p(), m_col.p(), m_Nnz);
	Base::operator=(std::move(data));
	m_row = std::move(row);
	m_col = std::move(col);
}

inline void McooInt::reshape(Long_I N0, Long_I N1)
{
	m_N0 = N0; m_N1 = N1;
}


class McooLlong : public VecLlong
{
private:
	typedef VecLlong Base;
	using Base::m_p;
	using Base::m_N;
	Long m_N0, m_N1, m_Nnz;
	VecLong m_row, m_col;
public:
	using Base::p;
	McooLlong(): m_N0(0), m_N1(0), m_Nnz(0) {};
	McooLlong(const McooLlong &rhs) = default; // copy constructor
	McooLlong(McooLlong &&rhs); // move constructor
	McooLlong(Long_I N0, Long_I N1);
	McooLlong(Long_I N0, Long_I N1, Long_I Ncap); // reserve Ncap elements
	Long *row_p();
	const Long *row_p() const;
	Long *col_p();
	const Long *col_p() const;
	McooLlong &operator=(const McooLlong &rhs) = default; // copy assignment
	McooLlong &operator=(McooLlong &&rhs); // move assignment
	void push(Llong_I s, Long_I i, Long_I j); // add one nonzero element
	void set(Llong_I s, Long_I i, Long_I j); // change existing element or push new element
	Long n0() const;
	Long n1() const;
	Long size() const; // return m_N0 * m_N1
	Long nnz() const; // return number of non-zero elements
	Long capacity() const;
	// get single index using double index, return -1 if not found
	Long find(Long_I i, Long_I j) const;
	// reference to an element (element must exist)
	Llong &ref(Long_I i, Long_I j);
	// double indexing (element need not exist)
	Llong operator()(Long_I i, Long_I j) const;
	Llong &operator[](Long_I ind); // return element
	Llong operator[](Long_I ind) const;
	const Long &row(Long_I ind) const; // row index
	Long &row(Long_I ind);
	const Long &col(Long_I ind) const; // column index
	Long &col(Long_I ind);
	void trim(Long_I Nnz); // decrease m_Nnz to Nnz
	void resize(Long_I N); // set m_Nz
	void reserve(Long_I N); // reallocate memory, data will be lost m_Nz = 0
	void reserve_cpy(Long_I N); // reserve and conserve data
	void reshape(Long_I N0, Long_I N1); // change matrix shape
};

typedef const McooLlong &McooLlong_I;
typedef McooLlong &McooLlong_O, &McooLlong_IO;

inline McooLlong::McooLlong(Long_I N0, Long_I N1)
	: Base(0), m_N0(N0), m_N1(N1), m_Nnz(0), m_row(0), m_col(0)
{
	m_N = 0;
}

inline McooLlong::McooLlong(Long_I N0, Long_I N1, Long_I Ncap) :
	Base(Ncap), m_N0(N0), m_N1(N1), m_Nnz(0), m_row(Ncap), m_col(Ncap) {}

inline McooLlong::McooLlong(McooLlong &&rhs) :
	Base(move(Base(rhs))), m_N0(rhs.m_N0), m_N1(rhs.m_N1), m_Nnz(rhs.m_Nnz),
	m_row(move(rhs.m_row)), m_col(move(rhs.m_col))
{
	rhs.m_Nnz = 0;
}

inline Long * McooLlong::row_p()
{
	return m_row.p();
}

inline const Long *McooLlong::row_p() const
{
	return m_row.p();
}

inline Long * McooLlong::col_p()
{
	return m_col.p();
}

inline const Long *McooLlong::col_p() const
{
	return m_col.p();
}

inline Long McooLlong::find(Long_I i, Long_I j) const
{
	for (Long n = 0; n < m_Nnz; ++n) {
		if (row(n) == i && col(n) == j)
			return n;
	}
	return -1;
}

inline Llong& McooLlong::ref(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("McooLlong::operator()(i,j): index out of bounds!");
#endif
	Long n = find(i, j);
	if (n < 0)
		SLS_ERR("McooLlong::operator()(i,j): element does not exist!");
	return m_p[n];
}

inline Llong McooLlong::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("McooLlong::operator()(i,j): index out of bounds!");
#endif
	Long n = find(i, j);
	if (n < 0)
		return Llong(0);
	return m_p[n];
}

inline McooLlong &McooLlong::operator=(McooLlong &&rhs)
{
	Base::operator=(std::move(rhs));
	m_row = std::move(rhs.m_row); m_col = std::move(rhs.m_col);
	m_Nnz = rhs.m_Nnz;
	rhs.m_Nnz = 0; rhs.m_N = 0;
	return *this;
}

inline void McooLlong::push(Llong_I s, Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i<0 || i>=m_N0 || j<0 || j>=m_N1)
		SLS_ERR("McooLlong::push(): index out of bounds!");
#endif
#ifdef SLS_CHECK_COO_REPEAT
	Long n;
	for (n = 0; n < m_Nnz; ++n) {
		if (row(n) == i && col(n) == j)
			SLS_ERR("McooLlong::push(s,i,j): element already exists!");
	}
#endif
	if (m_Nnz == m_N)
		SLS_ERR("McooLlong::push(): out of capacity, please reserve! m_N = " + to_string(m_N));
	m_p[m_Nnz] = s; m_row[m_Nnz] = i; m_col[m_Nnz] = j;
	++m_Nnz;
}

inline void McooLlong::set(Llong_I s, Long_I i, Long_I j)
{
	Long n;
	// change
	for (n = 0; n < m_Nnz; ++n) {
		if (row(n) == i && col(n) == j) {
			m_p[n] = s; m_row[n] = i; m_col[n] = j; return;
		}
	}
	// push
	if (m_Nnz == m_N)
		SLS_ERR("McooLlong::set(): out of capacity, please reserve! m_N = " + to_string(m_N));
	m_p[m_Nnz] = s; m_row[m_Nnz] = i; m_col[m_Nnz] = j;
	++m_Nnz;
}

inline Long McooLlong::n0() const
{
	return m_N0;
}

inline Long McooLlong::n1() const
{
	return m_N1;
}

inline Long McooLlong::size() const
{
	return m_N0 * m_N1;
}

inline Long McooLlong::nnz() const
{
	return m_Nnz;
}

inline Long McooLlong::capacity() const
{
	return Base::size();
}

inline Llong &McooLlong::operator[](Long_I ind)
{
#ifdef SLS_CHECK_BOUNDS
	if (ind<0 || ind>=m_Nnz)
		SLS_ERR("McooLlong::operator(): subscript out of bounds!");
#endif
	return m_p[ind];
}

inline Llong McooLlong::operator[](Long_I ind) const
{
#ifdef SLS_CHECK_BOUNDS
	if (ind<0 || ind>=m_Nnz)
		SLS_ERR("McooLlong::operator() const: subscript out of bounds!");
#endif
	return m_p[ind];
}

inline const Long &McooLlong::row(Long_I ind) const
{
#ifdef SLS_CHECK_BOUNDS
	if (ind<0 || ind>=m_Nnz)
		SLS_ERR("McooLlong::row() subscript out of bounds");
#endif
	return m_row[ind];
}

inline Long &McooLlong::row(Long_I ind)
{
#ifdef SLS_CHECK_BOUNDS
	if (ind<0 || ind>=m_Nnz)
		SLS_ERR("McooLlong::row() subscript out of bounds");
#endif
	return m_row[ind];
}

inline const Long &McooLlong::col(Long_I ind) const
{
#ifdef SLS_CHECK_BOUNDS
	if (ind < 0 || ind >= m_Nnz)
		SLS_ERR("McooLlong::col() subscript out of bounds");
#endif
	return m_col[ind];
}

inline Long &McooLlong::col(Long_I ind)
{
#ifdef SLS_CHECK_BOUNDS
	if (ind < 0 || ind >= m_Nnz)
		SLS_ERR("McooLlong::col() subscript out of bounds");
#endif
	return m_col[ind];
}

inline void McooLlong::trim(Long_I Nnz)
{
#ifdef SLS_CHECK_SHAPES
	if (Nnz < 0)
		SLS_ERR("McooLlong::trim() negative input!");
#endif
	if (Nnz < m_Nnz) m_Nnz = Nnz;
	else if (Nnz > m_Nnz) SLS_ERR("McooLlong::trim(): Nnz > m_Nnz!");
}

inline void McooLlong::resize(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (N > m_N)
		SLS_ERR("not enough capacity!");
#endif
	m_Nnz = N;
}

inline void McooLlong::reserve(Long_I N)
{
	Base::resize(N);
	m_row.resize(N);
	m_col.resize(N);
	m_Nnz = 0;
}

inline void McooLlong::reserve_cpy(Long_I N)
{
	VecLlong data(N);
	VecLong row(N), col(N);
	veccpy(data.p(), m_p, m_Nnz);
	veccpy(row.p(), m_row.p(), m_Nnz);
	veccpy(col.p(), m_col.p(), m_Nnz);
	Base::operator=(std::move(data));
	m_row = std::move(row);
	m_col = std::move(col);
}

inline void McooLlong::reshape(Long_I N0, Long_I N1)
{
	m_N0 = N0; m_N1 = N1;
}


class McooDoub : public VecDoub
{
private:
	typedef VecDoub Base;
	using Base::m_p;
	using Base::m_N;
	Long m_N0, m_N1, m_Nnz;
	VecLong m_row, m_col;
public:
	using Base::p;
	McooDoub(): m_N0(0), m_N1(0), m_Nnz(0) {};
	McooDoub(const McooDoub &rhs) = default; // copy constructor
	McooDoub(McooDoub &&rhs); // move constructor
	McooDoub(Long_I N0, Long_I N1);
	McooDoub(Long_I N0, Long_I N1, Long_I Ncap); // reserve Ncap elements
	Long *row_p();
	const Long *row_p() const;
	Long *col_p();
	const Long *col_p() const;
	McooDoub &operator=(const McooDoub &rhs) = default; // copy assignment
	McooDoub &operator=(McooDoub &&rhs); // move assignment
	void push(Doub_I s, Long_I i, Long_I j); // add one nonzero element
	void set(Doub_I s, Long_I i, Long_I j); // change existing element or push new element
	Long n0() const;
	Long n1() const;
	Long size() const; // return m_N0 * m_N1
	Long nnz() const; // return number of non-zero elements
	Long capacity() const;
	// get single index using double index, return -1 if not found
	Long find(Long_I i, Long_I j) const;
	// reference to an element (element must exist)
	Doub &ref(Long_I i, Long_I j);
	// double indexing (element need not exist)
	Doub operator()(Long_I i, Long_I j) const;
	Doub &operator[](Long_I ind); // return element
	Doub operator[](Long_I ind) const;
	const Long &row(Long_I ind) const; // row index
	Long &row(Long_I ind);
	const Long &col(Long_I ind) const; // column index
	Long &col(Long_I ind);
	void trim(Long_I Nnz); // decrease m_Nnz to Nnz
	void resize(Long_I N); // set m_Nz
	void reserve(Long_I N); // reallocate memory, data will be lost m_Nz = 0
	void reserve_cpy(Long_I N); // reserve and conserve data
	void reshape(Long_I N0, Long_I N1); // change matrix shape
};

typedef const McooDoub &McooDoub_I;
typedef McooDoub &McooDoub_O, &McooDoub_IO;

inline McooDoub::McooDoub(Long_I N0, Long_I N1)
	: Base(0), m_N0(N0), m_N1(N1), m_Nnz(0), m_row(0), m_col(0)
{
	m_N = 0;
}

inline McooDoub::McooDoub(Long_I N0, Long_I N1, Long_I Ncap) :
	Base(Ncap), m_N0(N0), m_N1(N1), m_Nnz(0), m_row(Ncap), m_col(Ncap) {}

inline McooDoub::McooDoub(McooDoub &&rhs) :
	Base(move(Base(rhs))), m_N0(rhs.m_N0), m_N1(rhs.m_N1), m_Nnz(rhs.m_Nnz),
	m_row(move(rhs.m_row)), m_col(move(rhs.m_col))
{
	rhs.m_Nnz = 0;
}

inline Long * McooDoub::row_p()
{
	return m_row.p();
}

inline const Long *McooDoub::row_p() const
{
	return m_row.p();
}

inline Long * McooDoub::col_p()
{
	return m_col.p();
}

inline const Long *McooDoub::col_p() const
{
	return m_col.p();
}

inline Long McooDoub::find(Long_I i, Long_I j) const
{
	for (Long n = 0; n < m_Nnz; ++n) {
		if (row(n) == i && col(n) == j)
			return n;
	}
	return -1;
}

inline Doub& McooDoub::ref(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("McooDoub::operator()(i,j): index out of bounds!");
#endif
	Long n = find(i, j);
	if (n < 0)
		SLS_ERR("McooDoub::operator()(i,j): element does not exist!");
	return m_p[n];
}

inline Doub McooDoub::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("McooDoub::operator()(i,j): index out of bounds!");
#endif
	Long n = find(i, j);
	if (n < 0)
		return Doub(0);
	return m_p[n];
}

inline McooDoub &McooDoub::operator=(McooDoub &&rhs)
{
	Base::operator=(std::move(rhs));
	m_row = std::move(rhs.m_row); m_col = std::move(rhs.m_col);
	m_Nnz = rhs.m_Nnz;
	rhs.m_Nnz = 0; rhs.m_N = 0;
	return *this;
}

inline void McooDoub::push(Doub_I s, Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i<0 || i>=m_N0 || j<0 || j>=m_N1)
		SLS_ERR("McooDoub::push(): index out of bounds!");
#endif
#ifdef SLS_CHECK_COO_REPEAT
	Long n;
	for (n = 0; n < m_Nnz; ++n) {
		if (row(n) == i && col(n) == j)
			SLS_ERR("McooDoub::push(s,i,j): element already exists!");
	}
#endif
	if (m_Nnz == m_N)
		SLS_ERR("McooDoub::push(): out of capacity, please reserve! m_N = " + to_string(m_N));
	m_p[m_Nnz] = s; m_row[m_Nnz] = i; m_col[m_Nnz] = j;
	++m_Nnz;
}

inline void McooDoub::set(Doub_I s, Long_I i, Long_I j)
{
	Long n;
	// change
	for (n = 0; n < m_Nnz; ++n) {
		if (row(n) == i && col(n) == j) {
			m_p[n] = s; m_row[n] = i; m_col[n] = j; return;
		}
	}
	// push
	if (m_Nnz == m_N)
		SLS_ERR("McooDoub::set(): out of capacity, please reserve! m_N = " + to_string(m_N));
	m_p[m_Nnz] = s; m_row[m_Nnz] = i; m_col[m_Nnz] = j;
	++m_Nnz;
}

inline Long McooDoub::n0() const
{
	return m_N0;
}

inline Long McooDoub::n1() const
{
	return m_N1;
}

inline Long McooDoub::size() const
{
	return m_N0 * m_N1;
}

inline Long McooDoub::nnz() const
{
	return m_Nnz;
}

inline Long McooDoub::capacity() const
{
	return Base::size();
}

inline Doub &McooDoub::operator[](Long_I ind)
{
#ifdef SLS_CHECK_BOUNDS
	if (ind<0 || ind>=m_Nnz)
		SLS_ERR("McooDoub::operator(): subscript out of bounds!");
#endif
	return m_p[ind];
}

inline Doub McooDoub::operator[](Long_I ind) const
{
#ifdef SLS_CHECK_BOUNDS
	if (ind<0 || ind>=m_Nnz)
		SLS_ERR("McooDoub::operator() const: subscript out of bounds!");
#endif
	return m_p[ind];
}

inline const Long &McooDoub::row(Long_I ind) const
{
#ifdef SLS_CHECK_BOUNDS
	if (ind<0 || ind>=m_Nnz)
		SLS_ERR("McooDoub::row() subscript out of bounds");
#endif
	return m_row[ind];
}

inline Long &McooDoub::row(Long_I ind)
{
#ifdef SLS_CHECK_BOUNDS
	if (ind<0 || ind>=m_Nnz)
		SLS_ERR("McooDoub::row() subscript out of bounds");
#endif
	return m_row[ind];
}

inline const Long &McooDoub::col(Long_I ind) const
{
#ifdef SLS_CHECK_BOUNDS
	if (ind < 0 || ind >= m_Nnz)
		SLS_ERR("McooDoub::col() subscript out of bounds");
#endif
	return m_col[ind];
}

inline Long &McooDoub::col(Long_I ind)
{
#ifdef SLS_CHECK_BOUNDS
	if (ind < 0 || ind >= m_Nnz)
		SLS_ERR("McooDoub::col() subscript out of bounds");
#endif
	return m_col[ind];
}

inline void McooDoub::trim(Long_I Nnz)
{
#ifdef SLS_CHECK_SHAPES
	if (Nnz < 0)
		SLS_ERR("McooDoub::trim() negative input!");
#endif
	if (Nnz < m_Nnz) m_Nnz = Nnz;
	else if (Nnz > m_Nnz) SLS_ERR("McooDoub::trim(): Nnz > m_Nnz!");
}

inline void McooDoub::resize(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (N > m_N)
		SLS_ERR("not enough capacity!");
#endif
	m_Nnz = N;
}

inline void McooDoub::reserve(Long_I N)
{
	Base::resize(N);
	m_row.resize(N);
	m_col.resize(N);
	m_Nnz = 0;
}

inline void McooDoub::reserve_cpy(Long_I N)
{
	VecDoub data(N);
	VecLong row(N), col(N);
	veccpy(data.p(), m_p, m_Nnz);
	veccpy(row.p(), m_row.p(), m_Nnz);
	veccpy(col.p(), m_col.p(), m_Nnz);
	Base::operator=(std::move(data));
	m_row = std::move(row);
	m_col = std::move(col);
}

inline void McooDoub::reshape(Long_I N0, Long_I N1)
{
	m_N0 = N0; m_N1 = N1;
}


class McooComp : public VecComp
{
private:
	typedef VecComp Base;
	using Base::m_p;
	using Base::m_N;
	Long m_N0, m_N1, m_Nnz;
	VecLong m_row, m_col;
public:
	using Base::p;
	McooComp(): m_N0(0), m_N1(0), m_Nnz(0) {};
	McooComp(const McooComp &rhs) = default; // copy constructor
	McooComp(McooComp &&rhs); // move constructor
	McooComp(Long_I N0, Long_I N1);
	McooComp(Long_I N0, Long_I N1, Long_I Ncap); // reserve Ncap elements
	Long *row_p();
	const Long *row_p() const;
	Long *col_p();
	const Long *col_p() const;
	McooComp &operator=(const McooComp &rhs) = default; // copy assignment
	McooComp &operator=(McooComp &&rhs); // move assignment
	void push(Comp_I s, Long_I i, Long_I j); // add one nonzero element
	void set(Comp_I s, Long_I i, Long_I j); // change existing element or push new element
	Long n0() const;
	Long n1() const;
	Long size() const; // return m_N0 * m_N1
	Long nnz() const; // return number of non-zero elements
	Long capacity() const;
	// get single index using double index, return -1 if not found
	Long find(Long_I i, Long_I j) const;
	// reference to an element (element must exist)
	Comp &ref(Long_I i, Long_I j);
	// double indexing (element need not exist)
	Comp operator()(Long_I i, Long_I j) const;
	Comp &operator[](Long_I ind); // return element
	Comp operator[](Long_I ind) const;
	const Long &row(Long_I ind) const; // row index
	Long &row(Long_I ind);
	const Long &col(Long_I ind) const; // column index
	Long &col(Long_I ind);
	void trim(Long_I Nnz); // decrease m_Nnz to Nnz
	void resize(Long_I N); // set m_Nz
	void reserve(Long_I N); // reallocate memory, data will be lost m_Nz = 0
	void reserve_cpy(Long_I N); // reserve and conserve data
	void reshape(Long_I N0, Long_I N1); // change matrix shape
};

typedef const McooComp &McooComp_I;
typedef McooComp &McooComp_O, &McooComp_IO;

inline McooComp::McooComp(Long_I N0, Long_I N1)
	: Base(0), m_N0(N0), m_N1(N1), m_Nnz(0), m_row(0), m_col(0)
{
	m_N = 0;
}

inline McooComp::McooComp(Long_I N0, Long_I N1, Long_I Ncap) :
	Base(Ncap), m_N0(N0), m_N1(N1), m_Nnz(0), m_row(Ncap), m_col(Ncap) {}

inline McooComp::McooComp(McooComp &&rhs) :
	Base(move(Base(rhs))), m_N0(rhs.m_N0), m_N1(rhs.m_N1), m_Nnz(rhs.m_Nnz),
	m_row(move(rhs.m_row)), m_col(move(rhs.m_col))
{
	rhs.m_Nnz = 0;
}

inline Long * McooComp::row_p()
{
	return m_row.p();
}

inline const Long *McooComp::row_p() const
{
	return m_row.p();
}

inline Long * McooComp::col_p()
{
	return m_col.p();
}

inline const Long *McooComp::col_p() const
{
	return m_col.p();
}

inline Long McooComp::find(Long_I i, Long_I j) const
{
	for (Long n = 0; n < m_Nnz; ++n) {
		if (row(n) == i && col(n) == j)
			return n;
	}
	return -1;
}

inline Comp& McooComp::ref(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("McooComp::operator()(i,j): index out of bounds!");
#endif
	Long n = find(i, j);
	if (n < 0)
		SLS_ERR("McooComp::operator()(i,j): element does not exist!");
	return m_p[n];
}

inline Comp McooComp::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("McooComp::operator()(i,j): index out of bounds!");
#endif
	Long n = find(i, j);
	if (n < 0)
		return Comp(0);
	return m_p[n];
}

inline McooComp &McooComp::operator=(McooComp &&rhs)
{
	Base::operator=(std::move(rhs));
	m_row = std::move(rhs.m_row); m_col = std::move(rhs.m_col);
	m_Nnz = rhs.m_Nnz;
	rhs.m_Nnz = 0; rhs.m_N = 0;
	return *this;
}

inline void McooComp::push(Comp_I s, Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i<0 || i>=m_N0 || j<0 || j>=m_N1)
		SLS_ERR("McooComp::push(): index out of bounds!");
#endif
#ifdef SLS_CHECK_COO_REPEAT
	Long n;
	for (n = 0; n < m_Nnz; ++n) {
		if (row(n) == i && col(n) == j)
			SLS_ERR("McooComp::push(s,i,j): element already exists!");
	}
#endif
	if (m_Nnz == m_N)
		SLS_ERR("McooComp::push(): out of capacity, please reserve! m_N = " + to_string(m_N));
	m_p[m_Nnz] = s; m_row[m_Nnz] = i; m_col[m_Nnz] = j;
	++m_Nnz;
}

inline void McooComp::set(Comp_I s, Long_I i, Long_I j)
{
	Long n;
	// change
	for (n = 0; n < m_Nnz; ++n) {
		if (row(n) == i && col(n) == j) {
			m_p[n] = s; m_row[n] = i; m_col[n] = j; return;
		}
	}
	// push
	if (m_Nnz == m_N)
		SLS_ERR("McooComp::set(): out of capacity, please reserve! m_N = " + to_string(m_N));
	m_p[m_Nnz] = s; m_row[m_Nnz] = i; m_col[m_Nnz] = j;
	++m_Nnz;
}

inline Long McooComp::n0() const
{
	return m_N0;
}

inline Long McooComp::n1() const
{
	return m_N1;
}

inline Long McooComp::size() const
{
	return m_N0 * m_N1;
}

inline Long McooComp::nnz() const
{
	return m_Nnz;
}

inline Long McooComp::capacity() const
{
	return Base::size();
}

inline Comp &McooComp::operator[](Long_I ind)
{
#ifdef SLS_CHECK_BOUNDS
	if (ind<0 || ind>=m_Nnz)
		SLS_ERR("McooComp::operator(): subscript out of bounds!");
#endif
	return m_p[ind];
}

inline Comp McooComp::operator[](Long_I ind) const
{
#ifdef SLS_CHECK_BOUNDS
	if (ind<0 || ind>=m_Nnz)
		SLS_ERR("McooComp::operator() const: subscript out of bounds!");
#endif
	return m_p[ind];
}

inline const Long &McooComp::row(Long_I ind) const
{
#ifdef SLS_CHECK_BOUNDS
	if (ind<0 || ind>=m_Nnz)
		SLS_ERR("McooComp::row() subscript out of bounds");
#endif
	return m_row[ind];
}

inline Long &McooComp::row(Long_I ind)
{
#ifdef SLS_CHECK_BOUNDS
	if (ind<0 || ind>=m_Nnz)
		SLS_ERR("McooComp::row() subscript out of bounds");
#endif
	return m_row[ind];
}

inline const Long &McooComp::col(Long_I ind) const
{
#ifdef SLS_CHECK_BOUNDS
	if (ind < 0 || ind >= m_Nnz)
		SLS_ERR("McooComp::col() subscript out of bounds");
#endif
	return m_col[ind];
}

inline Long &McooComp::col(Long_I ind)
{
#ifdef SLS_CHECK_BOUNDS
	if (ind < 0 || ind >= m_Nnz)
		SLS_ERR("McooComp::col() subscript out of bounds");
#endif
	return m_col[ind];
}

inline void McooComp::trim(Long_I Nnz)
{
#ifdef SLS_CHECK_SHAPES
	if (Nnz < 0)
		SLS_ERR("McooComp::trim() negative input!");
#endif
	if (Nnz < m_Nnz) m_Nnz = Nnz;
	else if (Nnz > m_Nnz) SLS_ERR("McooComp::trim(): Nnz > m_Nnz!");
}

inline void McooComp::resize(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (N > m_N)
		SLS_ERR("not enough capacity!");
#endif
	m_Nnz = N;
}

inline void McooComp::reserve(Long_I N)
{
	Base::resize(N);
	m_row.resize(N);
	m_col.resize(N);
	m_Nnz = 0;
}

inline void McooComp::reserve_cpy(Long_I N)
{
	VecComp data(N);
	VecLong row(N), col(N);
	veccpy(data.p(), m_p, m_Nnz);
	veccpy(row.p(), m_row.p(), m_Nnz);
	veccpy(col.p(), m_col.p(), m_Nnz);
	Base::operator=(std::move(data));
	m_row = std::move(row);
	m_col = std::move(col);
}

inline void McooComp::reshape(Long_I N0, Long_I N1)
{
	m_N0 = N0; m_N1 = N1;
}


class McooQdoub : public VecQdoub
{
private:
	typedef VecQdoub Base;
	using Base::m_p;
	using Base::m_N;
	Long m_N0, m_N1, m_Nnz;
	VecLong m_row, m_col;
public:
	using Base::p;
	McooQdoub(): m_N0(0), m_N1(0), m_Nnz(0) {};
	McooQdoub(const McooQdoub &rhs) = default; // copy constructor
	McooQdoub(McooQdoub &&rhs); // move constructor
	McooQdoub(Long_I N0, Long_I N1);
	McooQdoub(Long_I N0, Long_I N1, Long_I Ncap); // reserve Ncap elements
	Long *row_p();
	const Long *row_p() const;
	Long *col_p();
	const Long *col_p() const;
	McooQdoub &operator=(const McooQdoub &rhs) = default; // copy assignment
	McooQdoub &operator=(McooQdoub &&rhs); // move assignment
	void push(Qdoub_I s, Long_I i, Long_I j); // add one nonzero element
	void set(Qdoub_I s, Long_I i, Long_I j); // change existing element or push new element
	Long n0() const;
	Long n1() const;
	Long size() const; // return m_N0 * m_N1
	Long nnz() const; // return number of non-zero elements
	Long capacity() const;
	// get single index using double index, return -1 if not found
	Long find(Long_I i, Long_I j) const;
	// reference to an element (element must exist)
	Qdoub &ref(Long_I i, Long_I j);
	// double indexing (element need not exist)
	Qdoub operator()(Long_I i, Long_I j) const;
	Qdoub &operator[](Long_I ind); // return element
	Qdoub operator[](Long_I ind) const;
	const Long &row(Long_I ind) const; // row index
	Long &row(Long_I ind);
	const Long &col(Long_I ind) const; // column index
	Long &col(Long_I ind);
	void trim(Long_I Nnz); // decrease m_Nnz to Nnz
	void resize(Long_I N); // set m_Nz
	void reserve(Long_I N); // reallocate memory, data will be lost m_Nz = 0
	void reserve_cpy(Long_I N); // reserve and conserve data
	void reshape(Long_I N0, Long_I N1); // change matrix shape
};

typedef const McooQdoub &McooQdoub_I;
typedef McooQdoub &McooQdoub_O, &McooQdoub_IO;

inline McooQdoub::McooQdoub(Long_I N0, Long_I N1)
	: Base(0), m_N0(N0), m_N1(N1), m_Nnz(0), m_row(0), m_col(0)
{
	m_N = 0;
}

inline McooQdoub::McooQdoub(Long_I N0, Long_I N1, Long_I Ncap) :
	Base(Ncap), m_N0(N0), m_N1(N1), m_Nnz(0), m_row(Ncap), m_col(Ncap) {}

inline McooQdoub::McooQdoub(McooQdoub &&rhs) :
	Base(move(Base(rhs))), m_N0(rhs.m_N0), m_N1(rhs.m_N1), m_Nnz(rhs.m_Nnz),
	m_row(move(rhs.m_row)), m_col(move(rhs.m_col))
{
	rhs.m_Nnz = 0;
}

inline Long * McooQdoub::row_p()
{
	return m_row.p();
}

inline const Long *McooQdoub::row_p() const
{
	return m_row.p();
}

inline Long * McooQdoub::col_p()
{
	return m_col.p();
}

inline const Long *McooQdoub::col_p() const
{
	return m_col.p();
}

inline Long McooQdoub::find(Long_I i, Long_I j) const
{
	for (Long n = 0; n < m_Nnz; ++n) {
		if (row(n) == i && col(n) == j)
			return n;
	}
	return -1;
}

inline Qdoub& McooQdoub::ref(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("McooQdoub::operator()(i,j): index out of bounds!");
#endif
	Long n = find(i, j);
	if (n < 0)
		SLS_ERR("McooQdoub::operator()(i,j): element does not exist!");
	return m_p[n];
}

inline Qdoub McooQdoub::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("McooQdoub::operator()(i,j): index out of bounds!");
#endif
	Long n = find(i, j);
	if (n < 0)
		return Qdoub(0);
	return m_p[n];
}

inline McooQdoub &McooQdoub::operator=(McooQdoub &&rhs)
{
	Base::operator=(std::move(rhs));
	m_row = std::move(rhs.m_row); m_col = std::move(rhs.m_col);
	m_Nnz = rhs.m_Nnz;
	rhs.m_Nnz = 0; rhs.m_N = 0;
	return *this;
}

inline void McooQdoub::push(Qdoub_I s, Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i<0 || i>=m_N0 || j<0 || j>=m_N1)
		SLS_ERR("McooQdoub::push(): index out of bounds!");
#endif
#ifdef SLS_CHECK_COO_REPEAT
	Long n;
	for (n = 0; n < m_Nnz; ++n) {
		if (row(n) == i && col(n) == j)
			SLS_ERR("McooQdoub::push(s,i,j): element already exists!");
	}
#endif
	if (m_Nnz == m_N)
		SLS_ERR("McooQdoub::push(): out of capacity, please reserve! m_N = " + to_string(m_N));
	m_p[m_Nnz] = s; m_row[m_Nnz] = i; m_col[m_Nnz] = j;
	++m_Nnz;
}

inline void McooQdoub::set(Qdoub_I s, Long_I i, Long_I j)
{
	Long n;
	// change
	for (n = 0; n < m_Nnz; ++n) {
		if (row(n) == i && col(n) == j) {
			m_p[n] = s; m_row[n] = i; m_col[n] = j; return;
		}
	}
	// push
	if (m_Nnz == m_N)
		SLS_ERR("McooQdoub::set(): out of capacity, please reserve! m_N = " + to_string(m_N));
	m_p[m_Nnz] = s; m_row[m_Nnz] = i; m_col[m_Nnz] = j;
	++m_Nnz;
}

inline Long McooQdoub::n0() const
{
	return m_N0;
}

inline Long McooQdoub::n1() const
{
	return m_N1;
}

inline Long McooQdoub::size() const
{
	return m_N0 * m_N1;
}

inline Long McooQdoub::nnz() const
{
	return m_Nnz;
}

inline Long McooQdoub::capacity() const
{
	return Base::size();
}

inline Qdoub &McooQdoub::operator[](Long_I ind)
{
#ifdef SLS_CHECK_BOUNDS
	if (ind<0 || ind>=m_Nnz)
		SLS_ERR("McooQdoub::operator(): subscript out of bounds!");
#endif
	return m_p[ind];
}

inline Qdoub McooQdoub::operator[](Long_I ind) const
{
#ifdef SLS_CHECK_BOUNDS
	if (ind<0 || ind>=m_Nnz)
		SLS_ERR("McooQdoub::operator() const: subscript out of bounds!");
#endif
	return m_p[ind];
}

inline const Long &McooQdoub::row(Long_I ind) const
{
#ifdef SLS_CHECK_BOUNDS
	if (ind<0 || ind>=m_Nnz)
		SLS_ERR("McooQdoub::row() subscript out of bounds");
#endif
	return m_row[ind];
}

inline Long &McooQdoub::row(Long_I ind)
{
#ifdef SLS_CHECK_BOUNDS
	if (ind<0 || ind>=m_Nnz)
		SLS_ERR("McooQdoub::row() subscript out of bounds");
#endif
	return m_row[ind];
}

inline const Long &McooQdoub::col(Long_I ind) const
{
#ifdef SLS_CHECK_BOUNDS
	if (ind < 0 || ind >= m_Nnz)
		SLS_ERR("McooQdoub::col() subscript out of bounds");
#endif
	return m_col[ind];
}

inline Long &McooQdoub::col(Long_I ind)
{
#ifdef SLS_CHECK_BOUNDS
	if (ind < 0 || ind >= m_Nnz)
		SLS_ERR("McooQdoub::col() subscript out of bounds");
#endif
	return m_col[ind];
}

inline void McooQdoub::trim(Long_I Nnz)
{
#ifdef SLS_CHECK_SHAPES
	if (Nnz < 0)
		SLS_ERR("McooQdoub::trim() negative input!");
#endif
	if (Nnz < m_Nnz) m_Nnz = Nnz;
	else if (Nnz > m_Nnz) SLS_ERR("McooQdoub::trim(): Nnz > m_Nnz!");
}

inline void McooQdoub::resize(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (N > m_N)
		SLS_ERR("not enough capacity!");
#endif
	m_Nnz = N;
}

inline void McooQdoub::reserve(Long_I N)
{
	Base::resize(N);
	m_row.resize(N);
	m_col.resize(N);
	m_Nnz = 0;
}

inline void McooQdoub::reserve_cpy(Long_I N)
{
	VecQdoub data(N);
	VecLong row(N), col(N);
	veccpy(data.p(), m_p, m_Nnz);
	veccpy(row.p(), m_row.p(), m_Nnz);
	veccpy(col.p(), m_col.p(), m_Nnz);
	Base::operator=(std::move(data));
	m_row = std::move(row);
	m_col = std::move(col);
}

inline void McooQdoub::reshape(Long_I N0, Long_I N1)
{
	m_N0 = N0; m_N1 = N1;
}


class McooQcomp : public VecQcomp
{
private:
	typedef VecQcomp Base;
	using Base::m_p;
	using Base::m_N;
	Long m_N0, m_N1, m_Nnz;
	VecLong m_row, m_col;
public:
	using Base::p;
	McooQcomp(): m_N0(0), m_N1(0), m_Nnz(0) {};
	McooQcomp(const McooQcomp &rhs) = default; // copy constructor
	McooQcomp(McooQcomp &&rhs); // move constructor
	McooQcomp(Long_I N0, Long_I N1);
	McooQcomp(Long_I N0, Long_I N1, Long_I Ncap); // reserve Ncap elements
	Long *row_p();
	const Long *row_p() const;
	Long *col_p();
	const Long *col_p() const;
	McooQcomp &operator=(const McooQcomp &rhs) = default; // copy assignment
	McooQcomp &operator=(McooQcomp &&rhs); // move assignment
	void push(Qcomp_I s, Long_I i, Long_I j); // add one nonzero element
	void set(Qcomp_I s, Long_I i, Long_I j); // change existing element or push new element
	Long n0() const;
	Long n1() const;
	Long size() const; // return m_N0 * m_N1
	Long nnz() const; // return number of non-zero elements
	Long capacity() const;
	// get single index using double index, return -1 if not found
	Long find(Long_I i, Long_I j) const;
	// reference to an element (element must exist)
	Qcomp &ref(Long_I i, Long_I j);
	// double indexing (element need not exist)
	Qcomp operator()(Long_I i, Long_I j) const;
	Qcomp &operator[](Long_I ind); // return element
	Qcomp operator[](Long_I ind) const;
	const Long &row(Long_I ind) const; // row index
	Long &row(Long_I ind);
	const Long &col(Long_I ind) const; // column index
	Long &col(Long_I ind);
	void trim(Long_I Nnz); // decrease m_Nnz to Nnz
	void resize(Long_I N); // set m_Nz
	void reserve(Long_I N); // reallocate memory, data will be lost m_Nz = 0
	void reserve_cpy(Long_I N); // reserve and conserve data
	void reshape(Long_I N0, Long_I N1); // change matrix shape
};

typedef const McooQcomp &McooQcomp_I;
typedef McooQcomp &McooQcomp_O, &McooQcomp_IO;

inline McooQcomp::McooQcomp(Long_I N0, Long_I N1)
	: Base(0), m_N0(N0), m_N1(N1), m_Nnz(0), m_row(0), m_col(0)
{
	m_N = 0;
}

inline McooQcomp::McooQcomp(Long_I N0, Long_I N1, Long_I Ncap) :
	Base(Ncap), m_N0(N0), m_N1(N1), m_Nnz(0), m_row(Ncap), m_col(Ncap) {}

inline McooQcomp::McooQcomp(McooQcomp &&rhs) :
	Base(move(Base(rhs))), m_N0(rhs.m_N0), m_N1(rhs.m_N1), m_Nnz(rhs.m_Nnz),
	m_row(move(rhs.m_row)), m_col(move(rhs.m_col))
{
	rhs.m_Nnz = 0;
}

inline Long * McooQcomp::row_p()
{
	return m_row.p();
}

inline const Long *McooQcomp::row_p() const
{
	return m_row.p();
}

inline Long * McooQcomp::col_p()
{
	return m_col.p();
}

inline const Long *McooQcomp::col_p() const
{
	return m_col.p();
}

inline Long McooQcomp::find(Long_I i, Long_I j) const
{
	for (Long n = 0; n < m_Nnz; ++n) {
		if (row(n) == i && col(n) == j)
			return n;
	}
	return -1;
}

inline Qcomp& McooQcomp::ref(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("McooQcomp::operator()(i,j): index out of bounds!");
#endif
	Long n = find(i, j);
	if (n < 0)
		SLS_ERR("McooQcomp::operator()(i,j): element does not exist!");
	return m_p[n];
}

inline Qcomp McooQcomp::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("McooQcomp::operator()(i,j): index out of bounds!");
#endif
	Long n = find(i, j);
	if (n < 0)
		return Qcomp(0);
	return m_p[n];
}

inline McooQcomp &McooQcomp::operator=(McooQcomp &&rhs)
{
	Base::operator=(std::move(rhs));
	m_row = std::move(rhs.m_row); m_col = std::move(rhs.m_col);
	m_Nnz = rhs.m_Nnz;
	rhs.m_Nnz = 0; rhs.m_N = 0;
	return *this;
}

inline void McooQcomp::push(Qcomp_I s, Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i<0 || i>=m_N0 || j<0 || j>=m_N1)
		SLS_ERR("McooQcomp::push(): index out of bounds!");
#endif
#ifdef SLS_CHECK_COO_REPEAT
	Long n;
	for (n = 0; n < m_Nnz; ++n) {
		if (row(n) == i && col(n) == j)
			SLS_ERR("McooQcomp::push(s,i,j): element already exists!");
	}
#endif
	if (m_Nnz == m_N)
		SLS_ERR("McooQcomp::push(): out of capacity, please reserve! m_N = " + to_string(m_N));
	m_p[m_Nnz] = s; m_row[m_Nnz] = i; m_col[m_Nnz] = j;
	++m_Nnz;
}

inline void McooQcomp::set(Qcomp_I s, Long_I i, Long_I j)
{
	Long n;
	// change
	for (n = 0; n < m_Nnz; ++n) {
		if (row(n) == i && col(n) == j) {
			m_p[n] = s; m_row[n] = i; m_col[n] = j; return;
		}
	}
	// push
	if (m_Nnz == m_N)
		SLS_ERR("McooQcomp::set(): out of capacity, please reserve! m_N = " + to_string(m_N));
	m_p[m_Nnz] = s; m_row[m_Nnz] = i; m_col[m_Nnz] = j;
	++m_Nnz;
}

inline Long McooQcomp::n0() const
{
	return m_N0;
}

inline Long McooQcomp::n1() const
{
	return m_N1;
}

inline Long McooQcomp::size() const
{
	return m_N0 * m_N1;
}

inline Long McooQcomp::nnz() const
{
	return m_Nnz;
}

inline Long McooQcomp::capacity() const
{
	return Base::size();
}

inline Qcomp &McooQcomp::operator[](Long_I ind)
{
#ifdef SLS_CHECK_BOUNDS
	if (ind<0 || ind>=m_Nnz)
		SLS_ERR("McooQcomp::operator(): subscript out of bounds!");
#endif
	return m_p[ind];
}

inline Qcomp McooQcomp::operator[](Long_I ind) const
{
#ifdef SLS_CHECK_BOUNDS
	if (ind<0 || ind>=m_Nnz)
		SLS_ERR("McooQcomp::operator() const: subscript out of bounds!");
#endif
	return m_p[ind];
}

inline const Long &McooQcomp::row(Long_I ind) const
{
#ifdef SLS_CHECK_BOUNDS
	if (ind<0 || ind>=m_Nnz)
		SLS_ERR("McooQcomp::row() subscript out of bounds");
#endif
	return m_row[ind];
}

inline Long &McooQcomp::row(Long_I ind)
{
#ifdef SLS_CHECK_BOUNDS
	if (ind<0 || ind>=m_Nnz)
		SLS_ERR("McooQcomp::row() subscript out of bounds");
#endif
	return m_row[ind];
}

inline const Long &McooQcomp::col(Long_I ind) const
{
#ifdef SLS_CHECK_BOUNDS
	if (ind < 0 || ind >= m_Nnz)
		SLS_ERR("McooQcomp::col() subscript out of bounds");
#endif
	return m_col[ind];
}

inline Long &McooQcomp::col(Long_I ind)
{
#ifdef SLS_CHECK_BOUNDS
	if (ind < 0 || ind >= m_Nnz)
		SLS_ERR("McooQcomp::col() subscript out of bounds");
#endif
	return m_col[ind];
}

inline void McooQcomp::trim(Long_I Nnz)
{
#ifdef SLS_CHECK_SHAPES
	if (Nnz < 0)
		SLS_ERR("McooQcomp::trim() negative input!");
#endif
	if (Nnz < m_Nnz) m_Nnz = Nnz;
	else if (Nnz > m_Nnz) SLS_ERR("McooQcomp::trim(): Nnz > m_Nnz!");
}

inline void McooQcomp::resize(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (N > m_N)
		SLS_ERR("not enough capacity!");
#endif
	m_Nnz = N;
}

inline void McooQcomp::reserve(Long_I N)
{
	Base::resize(N);
	m_row.resize(N);
	m_col.resize(N);
	m_Nnz = 0;
}

inline void McooQcomp::reserve_cpy(Long_I N)
{
	VecQcomp data(N);
	VecLong row(N), col(N);
	veccpy(data.p(), m_p, m_Nnz);
	veccpy(row.p(), m_row.p(), m_Nnz);
	veccpy(col.p(), m_col.p(), m_Nnz);
	Base::operator=(std::move(data));
	m_row = std::move(row);
	m_col = std::move(col);
}

inline void McooQcomp::reshape(Long_I N0, Long_I N1)
{
	m_N0 = N0; m_N1 = N1;
}


class McooImag : public VecImag
{
private:
	typedef VecImag Base;
	using Base::m_p;
	using Base::m_N;
	Long m_N0, m_N1, m_Nnz;
	VecLong m_row, m_col;
public:
	using Base::p;
	McooImag(): m_N0(0), m_N1(0), m_Nnz(0) {};
	McooImag(const McooImag &rhs) = default; // copy constructor
	McooImag(McooImag &&rhs); // move constructor
	McooImag(Long_I N0, Long_I N1);
	McooImag(Long_I N0, Long_I N1, Long_I Ncap); // reserve Ncap elements
	Long *row_p();
	const Long *row_p() const;
	Long *col_p();
	const Long *col_p() const;
	McooImag &operator=(const McooImag &rhs) = default; // copy assignment
	McooImag &operator=(McooImag &&rhs); // move assignment
	void push(Imag_I s, Long_I i, Long_I j); // add one nonzero element
	void set(Imag_I s, Long_I i, Long_I j); // change existing element or push new element
	Long n0() const;
	Long n1() const;
	Long size() const; // return m_N0 * m_N1
	Long nnz() const; // return number of non-zero elements
	Long capacity() const;
	// get single index using double index, return -1 if not found
	Long find(Long_I i, Long_I j) const;
	// reference to an element (element must exist)
	Imag &ref(Long_I i, Long_I j);
	// double indexing (element need not exist)
	Imag operator()(Long_I i, Long_I j) const;
	Imag &operator[](Long_I ind); // return element
	Imag operator[](Long_I ind) const;
	const Long &row(Long_I ind) const; // row index
	Long &row(Long_I ind);
	const Long &col(Long_I ind) const; // column index
	Long &col(Long_I ind);
	void trim(Long_I Nnz); // decrease m_Nnz to Nnz
	void resize(Long_I N); // set m_Nz
	void reserve(Long_I N); // reallocate memory, data will be lost m_Nz = 0
	void reserve_cpy(Long_I N); // reserve and conserve data
	void reshape(Long_I N0, Long_I N1); // change matrix shape
};

typedef const McooImag &McooImag_I;
typedef McooImag &McooImag_O, &McooImag_IO;

inline McooImag::McooImag(Long_I N0, Long_I N1)
	: Base(0), m_N0(N0), m_N1(N1), m_Nnz(0), m_row(0), m_col(0)
{
	m_N = 0;
}

inline McooImag::McooImag(Long_I N0, Long_I N1, Long_I Ncap) :
	Base(Ncap), m_N0(N0), m_N1(N1), m_Nnz(0), m_row(Ncap), m_col(Ncap) {}

inline McooImag::McooImag(McooImag &&rhs) :
	Base(move(Base(rhs))), m_N0(rhs.m_N0), m_N1(rhs.m_N1), m_Nnz(rhs.m_Nnz),
	m_row(move(rhs.m_row)), m_col(move(rhs.m_col))
{
	rhs.m_Nnz = 0;
}

inline Long * McooImag::row_p()
{
	return m_row.p();
}

inline const Long *McooImag::row_p() const
{
	return m_row.p();
}

inline Long * McooImag::col_p()
{
	return m_col.p();
}

inline const Long *McooImag::col_p() const
{
	return m_col.p();
}

inline Long McooImag::find(Long_I i, Long_I j) const
{
	for (Long n = 0; n < m_Nnz; ++n) {
		if (row(n) == i && col(n) == j)
			return n;
	}
	return -1;
}

inline Imag& McooImag::ref(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("McooImag::operator()(i,j): index out of bounds!");
#endif
	Long n = find(i, j);
	if (n < 0)
		SLS_ERR("McooImag::operator()(i,j): element does not exist!");
	return m_p[n];
}

inline Imag McooImag::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("McooImag::operator()(i,j): index out of bounds!");
#endif
	Long n = find(i, j);
	if (n < 0)
		return Imag(0);
	return m_p[n];
}

inline McooImag &McooImag::operator=(McooImag &&rhs)
{
	Base::operator=(std::move(rhs));
	m_row = std::move(rhs.m_row); m_col = std::move(rhs.m_col);
	m_Nnz = rhs.m_Nnz;
	rhs.m_Nnz = 0; rhs.m_N = 0;
	return *this;
}

inline void McooImag::push(Imag_I s, Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i<0 || i>=m_N0 || j<0 || j>=m_N1)
		SLS_ERR("McooImag::push(): index out of bounds!");
#endif
#ifdef SLS_CHECK_COO_REPEAT
	Long n;
	for (n = 0; n < m_Nnz; ++n) {
		if (row(n) == i && col(n) == j)
			SLS_ERR("McooImag::push(s,i,j): element already exists!");
	}
#endif
	if (m_Nnz == m_N)
		SLS_ERR("McooImag::push(): out of capacity, please reserve! m_N = " + to_string(m_N));
	m_p[m_Nnz] = s; m_row[m_Nnz] = i; m_col[m_Nnz] = j;
	++m_Nnz;
}

inline void McooImag::set(Imag_I s, Long_I i, Long_I j)
{
	Long n;
	// change
	for (n = 0; n < m_Nnz; ++n) {
		if (row(n) == i && col(n) == j) {
			m_p[n] = s; m_row[n] = i; m_col[n] = j; return;
		}
	}
	// push
	if (m_Nnz == m_N)
		SLS_ERR("McooImag::set(): out of capacity, please reserve! m_N = " + to_string(m_N));
	m_p[m_Nnz] = s; m_row[m_Nnz] = i; m_col[m_Nnz] = j;
	++m_Nnz;
}

inline Long McooImag::n0() const
{
	return m_N0;
}

inline Long McooImag::n1() const
{
	return m_N1;
}

inline Long McooImag::size() const
{
	return m_N0 * m_N1;
}

inline Long McooImag::nnz() const
{
	return m_Nnz;
}

inline Long McooImag::capacity() const
{
	return Base::size();
}

inline Imag &McooImag::operator[](Long_I ind)
{
#ifdef SLS_CHECK_BOUNDS
	if (ind<0 || ind>=m_Nnz)
		SLS_ERR("McooImag::operator(): subscript out of bounds!");
#endif
	return m_p[ind];
}

inline Imag McooImag::operator[](Long_I ind) const
{
#ifdef SLS_CHECK_BOUNDS
	if (ind<0 || ind>=m_Nnz)
		SLS_ERR("McooImag::operator() const: subscript out of bounds!");
#endif
	return m_p[ind];
}

inline const Long &McooImag::row(Long_I ind) const
{
#ifdef SLS_CHECK_BOUNDS
	if (ind<0 || ind>=m_Nnz)
		SLS_ERR("McooImag::row() subscript out of bounds");
#endif
	return m_row[ind];
}

inline Long &McooImag::row(Long_I ind)
{
#ifdef SLS_CHECK_BOUNDS
	if (ind<0 || ind>=m_Nnz)
		SLS_ERR("McooImag::row() subscript out of bounds");
#endif
	return m_row[ind];
}

inline const Long &McooImag::col(Long_I ind) const
{
#ifdef SLS_CHECK_BOUNDS
	if (ind < 0 || ind >= m_Nnz)
		SLS_ERR("McooImag::col() subscript out of bounds");
#endif
	return m_col[ind];
}

inline Long &McooImag::col(Long_I ind)
{
#ifdef SLS_CHECK_BOUNDS
	if (ind < 0 || ind >= m_Nnz)
		SLS_ERR("McooImag::col() subscript out of bounds");
#endif
	return m_col[ind];
}

inline void McooImag::trim(Long_I Nnz)
{
#ifdef SLS_CHECK_SHAPES
	if (Nnz < 0)
		SLS_ERR("McooImag::trim() negative input!");
#endif
	if (Nnz < m_Nnz) m_Nnz = Nnz;
	else if (Nnz > m_Nnz) SLS_ERR("McooImag::trim(): Nnz > m_Nnz!");
}

inline void McooImag::resize(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (N > m_N)
		SLS_ERR("not enough capacity!");
#endif
	m_Nnz = N;
}

inline void McooImag::reserve(Long_I N)
{
	Base::resize(N);
	m_row.resize(N);
	m_col.resize(N);
	m_Nnz = 0;
}

inline void McooImag::reserve_cpy(Long_I N)
{
	VecImag data(N);
	VecLong row(N), col(N);
	veccpy(data.p(), m_p, m_Nnz);
	veccpy(row.p(), m_row.p(), m_Nnz);
	veccpy(col.p(), m_col.p(), m_Nnz);
	Base::operator=(std::move(data));
	m_row = std::move(row);
	m_col = std::move(col);
}

inline void McooImag::reshape(Long_I N0, Long_I N1)
{
	m_N0 = N0; m_N1 = N1;
}


class McooQimag : public VecQimag
{
private:
	typedef VecQimag Base;
	using Base::m_p;
	using Base::m_N;
	Long m_N0, m_N1, m_Nnz;
	VecLong m_row, m_col;
public:
	using Base::p;
	McooQimag(): m_N0(0), m_N1(0), m_Nnz(0) {};
	McooQimag(const McooQimag &rhs) = default; // copy constructor
	McooQimag(McooQimag &&rhs); // move constructor
	McooQimag(Long_I N0, Long_I N1);
	McooQimag(Long_I N0, Long_I N1, Long_I Ncap); // reserve Ncap elements
	Long *row_p();
	const Long *row_p() const;
	Long *col_p();
	const Long *col_p() const;
	McooQimag &operator=(const McooQimag &rhs) = default; // copy assignment
	McooQimag &operator=(McooQimag &&rhs); // move assignment
	void push(Qimag_I s, Long_I i, Long_I j); // add one nonzero element
	void set(Qimag_I s, Long_I i, Long_I j); // change existing element or push new element
	Long n0() const;
	Long n1() const;
	Long size() const; // return m_N0 * m_N1
	Long nnz() const; // return number of non-zero elements
	Long capacity() const;
	// get single index using double index, return -1 if not found
	Long find(Long_I i, Long_I j) const;
	// reference to an element (element must exist)
	Qimag &ref(Long_I i, Long_I j);
	// double indexing (element need not exist)
	Qimag operator()(Long_I i, Long_I j) const;
	Qimag &operator[](Long_I ind); // return element
	Qimag operator[](Long_I ind) const;
	const Long &row(Long_I ind) const; // row index
	Long &row(Long_I ind);
	const Long &col(Long_I ind) const; // column index
	Long &col(Long_I ind);
	void trim(Long_I Nnz); // decrease m_Nnz to Nnz
	void resize(Long_I N); // set m_Nz
	void reserve(Long_I N); // reallocate memory, data will be lost m_Nz = 0
	void reserve_cpy(Long_I N); // reserve and conserve data
	void reshape(Long_I N0, Long_I N1); // change matrix shape
};

typedef const McooQimag &McooQimag_I;
typedef McooQimag &McooQimag_O, &McooQimag_IO;

inline McooQimag::McooQimag(Long_I N0, Long_I N1)
	: Base(0), m_N0(N0), m_N1(N1), m_Nnz(0), m_row(0), m_col(0)
{
	m_N = 0;
}

inline McooQimag::McooQimag(Long_I N0, Long_I N1, Long_I Ncap) :
	Base(Ncap), m_N0(N0), m_N1(N1), m_Nnz(0), m_row(Ncap), m_col(Ncap) {}

inline McooQimag::McooQimag(McooQimag &&rhs) :
	Base(move(Base(rhs))), m_N0(rhs.m_N0), m_N1(rhs.m_N1), m_Nnz(rhs.m_Nnz),
	m_row(move(rhs.m_row)), m_col(move(rhs.m_col))
{
	rhs.m_Nnz = 0;
}

inline Long * McooQimag::row_p()
{
	return m_row.p();
}

inline const Long *McooQimag::row_p() const
{
	return m_row.p();
}

inline Long * McooQimag::col_p()
{
	return m_col.p();
}

inline const Long *McooQimag::col_p() const
{
	return m_col.p();
}

inline Long McooQimag::find(Long_I i, Long_I j) const
{
	for (Long n = 0; n < m_Nnz; ++n) {
		if (row(n) == i && col(n) == j)
			return n;
	}
	return -1;
}

inline Qimag& McooQimag::ref(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("McooQimag::operator()(i,j): index out of bounds!");
#endif
	Long n = find(i, j);
	if (n < 0)
		SLS_ERR("McooQimag::operator()(i,j): element does not exist!");
	return m_p[n];
}

inline Qimag McooQimag::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= m_N1)
		SLS_ERR("McooQimag::operator()(i,j): index out of bounds!");
#endif
	Long n = find(i, j);
	if (n < 0)
		return Qimag(0);
	return m_p[n];
}

inline McooQimag &McooQimag::operator=(McooQimag &&rhs)
{
	Base::operator=(std::move(rhs));
	m_row = std::move(rhs.m_row); m_col = std::move(rhs.m_col);
	m_Nnz = rhs.m_Nnz;
	rhs.m_Nnz = 0; rhs.m_N = 0;
	return *this;
}

inline void McooQimag::push(Qimag_I s, Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i<0 || i>=m_N0 || j<0 || j>=m_N1)
		SLS_ERR("McooQimag::push(): index out of bounds!");
#endif
#ifdef SLS_CHECK_COO_REPEAT
	Long n;
	for (n = 0; n < m_Nnz; ++n) {
		if (row(n) == i && col(n) == j)
			SLS_ERR("McooQimag::push(s,i,j): element already exists!");
	}
#endif
	if (m_Nnz == m_N)
		SLS_ERR("McooQimag::push(): out of capacity, please reserve! m_N = " + to_string(m_N));
	m_p[m_Nnz] = s; m_row[m_Nnz] = i; m_col[m_Nnz] = j;
	++m_Nnz;
}

inline void McooQimag::set(Qimag_I s, Long_I i, Long_I j)
{
	Long n;
	// change
	for (n = 0; n < m_Nnz; ++n) {
		if (row(n) == i && col(n) == j) {
			m_p[n] = s; m_row[n] = i; m_col[n] = j; return;
		}
	}
	// push
	if (m_Nnz == m_N)
		SLS_ERR("McooQimag::set(): out of capacity, please reserve! m_N = " + to_string(m_N));
	m_p[m_Nnz] = s; m_row[m_Nnz] = i; m_col[m_Nnz] = j;
	++m_Nnz;
}

inline Long McooQimag::n0() const
{
	return m_N0;
}

inline Long McooQimag::n1() const
{
	return m_N1;
}

inline Long McooQimag::size() const
{
	return m_N0 * m_N1;
}

inline Long McooQimag::nnz() const
{
	return m_Nnz;
}

inline Long McooQimag::capacity() const
{
	return Base::size();
}

inline Qimag &McooQimag::operator[](Long_I ind)
{
#ifdef SLS_CHECK_BOUNDS
	if (ind<0 || ind>=m_Nnz)
		SLS_ERR("McooQimag::operator(): subscript out of bounds!");
#endif
	return m_p[ind];
}

inline Qimag McooQimag::operator[](Long_I ind) const
{
#ifdef SLS_CHECK_BOUNDS
	if (ind<0 || ind>=m_Nnz)
		SLS_ERR("McooQimag::operator() const: subscript out of bounds!");
#endif
	return m_p[ind];
}

inline const Long &McooQimag::row(Long_I ind) const
{
#ifdef SLS_CHECK_BOUNDS
	if (ind<0 || ind>=m_Nnz)
		SLS_ERR("McooQimag::row() subscript out of bounds");
#endif
	return m_row[ind];
}

inline Long &McooQimag::row(Long_I ind)
{
#ifdef SLS_CHECK_BOUNDS
	if (ind<0 || ind>=m_Nnz)
		SLS_ERR("McooQimag::row() subscript out of bounds");
#endif
	return m_row[ind];
}

inline const Long &McooQimag::col(Long_I ind) const
{
#ifdef SLS_CHECK_BOUNDS
	if (ind < 0 || ind >= m_Nnz)
		SLS_ERR("McooQimag::col() subscript out of bounds");
#endif
	return m_col[ind];
}

inline Long &McooQimag::col(Long_I ind)
{
#ifdef SLS_CHECK_BOUNDS
	if (ind < 0 || ind >= m_Nnz)
		SLS_ERR("McooQimag::col() subscript out of bounds");
#endif
	return m_col[ind];
}

inline void McooQimag::trim(Long_I Nnz)
{
#ifdef SLS_CHECK_SHAPES
	if (Nnz < 0)
		SLS_ERR("McooQimag::trim() negative input!");
#endif
	if (Nnz < m_Nnz) m_Nnz = Nnz;
	else if (Nnz > m_Nnz) SLS_ERR("McooQimag::trim(): Nnz > m_Nnz!");
}

inline void McooQimag::resize(Long_I N)
{
#ifdef SLS_CHECK_BOUNDS
	if (N > m_N)
		SLS_ERR("not enough capacity!");
#endif
	m_Nnz = N;
}

inline void McooQimag::reserve(Long_I N)
{
	Base::resize(N);
	m_row.resize(N);
	m_col.resize(N);
	m_Nnz = 0;
}

inline void McooQimag::reserve_cpy(Long_I N)
{
	VecQimag data(N);
	VecLong row(N), col(N);
	veccpy(data.p(), m_p, m_Nnz);
	veccpy(row.p(), m_row.p(), m_Nnz);
	veccpy(col.p(), m_col.p(), m_Nnz);
	Base::operator=(std::move(data));
	m_row = std::move(row);
	m_col = std::move(col);
}

inline void McooQimag::reshape(Long_I N0, Long_I N1)
{
	m_N0 = N0; m_N1 = N1;
}

} // namespace slisc
