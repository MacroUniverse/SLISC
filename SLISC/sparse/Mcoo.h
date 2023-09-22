#pragma once
#include "../dense/Vec.h"

namespace slisc {

template <class T>
void veccpy(T *, const T *, Long_I);


class McooChar : public VbaseChar
{
private:
	typedef VbaseChar Base;
	using Base::m_p;
	using Base::m_N;
	Long m_N0, m_N1, m_Nnz;
	VecLong m_row, m_col;
public:
	using Base::p;
	McooChar(): m_N0(0), m_N1(0), m_Nnz(0) {};
	McooChar(Long_I N0, Long_I N1);
	McooChar(Long_I N0, Long_I N1, Long_I Ncap); // reserve Ncap elements
	Long *row_p();
	const Long *row_p() const;
	Long *col_p();
	const Long *col_p() const;
	void operator<<(McooChar &rhs); // move data and rhs.resize(0)
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
		return 0; // never return a (const) reference to a temporary
	return m_p[n];
}

inline void McooChar::operator<<(McooChar &rhs)
{
	Base::operator<<(rhs);
	m_row << rhs.m_row; m_col << rhs.m_col;
	m_Nnz = rhs.m_Nnz;
	rhs.m_Nnz = 0; rhs.m_N = 0;
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
	Base::operator<<(data);
	m_row << row; m_col << col;
}

inline void McooChar::reshape(Long_I N0, Long_I N1)
{
	m_N0 = N0; m_N1 = N1;
}


class McooInt : public VbaseInt
{
private:
	typedef VbaseInt Base;
	using Base::m_p;
	using Base::m_N;
	Long m_N0, m_N1, m_Nnz;
	VecLong m_row, m_col;
public:
	using Base::p;
	McooInt(): m_N0(0), m_N1(0), m_Nnz(0) {};
	McooInt(Long_I N0, Long_I N1);
	McooInt(Long_I N0, Long_I N1, Long_I Ncap); // reserve Ncap elements
	Long *row_p();
	const Long *row_p() const;
	Long *col_p();
	const Long *col_p() const;
	void operator<<(McooInt &rhs); // move data and rhs.resize(0)
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
		return 0; // never return a (const) reference to a temporary
	return m_p[n];
}

inline void McooInt::operator<<(McooInt &rhs)
{
	Base::operator<<(rhs);
	m_row << rhs.m_row; m_col << rhs.m_col;
	m_Nnz = rhs.m_Nnz;
	rhs.m_Nnz = 0; rhs.m_N = 0;
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
	Base::operator<<(data);
	m_row << row; m_col << col;
}

inline void McooInt::reshape(Long_I N0, Long_I N1)
{
	m_N0 = N0; m_N1 = N1;
}


class McooLlong : public VbaseLlong
{
private:
	typedef VbaseLlong Base;
	using Base::m_p;
	using Base::m_N;
	Long m_N0, m_N1, m_Nnz;
	VecLong m_row, m_col;
public:
	using Base::p;
	McooLlong(): m_N0(0), m_N1(0), m_Nnz(0) {};
	McooLlong(Long_I N0, Long_I N1);
	McooLlong(Long_I N0, Long_I N1, Long_I Ncap); // reserve Ncap elements
	Long *row_p();
	const Long *row_p() const;
	Long *col_p();
	const Long *col_p() const;
	void operator<<(McooLlong &rhs); // move data and rhs.resize(0)
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
		return 0; // never return a (const) reference to a temporary
	return m_p[n];
}

inline void McooLlong::operator<<(McooLlong &rhs)
{
	Base::operator<<(rhs);
	m_row << rhs.m_row; m_col << rhs.m_col;
	m_Nnz = rhs.m_Nnz;
	rhs.m_Nnz = 0; rhs.m_N = 0;
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
	Base::operator<<(data);
	m_row << row; m_col << col;
}

inline void McooLlong::reshape(Long_I N0, Long_I N1)
{
	m_N0 = N0; m_N1 = N1;
}


class McooDoub : public VbaseDoub
{
private:
	typedef VbaseDoub Base;
	using Base::m_p;
	using Base::m_N;
	Long m_N0, m_N1, m_Nnz;
	VecLong m_row, m_col;
public:
	using Base::p;
	McooDoub(): m_N0(0), m_N1(0), m_Nnz(0) {};
	McooDoub(Long_I N0, Long_I N1);
	McooDoub(Long_I N0, Long_I N1, Long_I Ncap); // reserve Ncap elements
	Long *row_p();
	const Long *row_p() const;
	Long *col_p();
	const Long *col_p() const;
	void operator<<(McooDoub &rhs); // move data and rhs.resize(0)
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
		return 0; // never return a (const) reference to a temporary
	return m_p[n];
}

inline void McooDoub::operator<<(McooDoub &rhs)
{
	Base::operator<<(rhs);
	m_row << rhs.m_row; m_col << rhs.m_col;
	m_Nnz = rhs.m_Nnz;
	rhs.m_Nnz = 0; rhs.m_N = 0;
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
	Base::operator<<(data);
	m_row << row; m_col << col;
}

inline void McooDoub::reshape(Long_I N0, Long_I N1)
{
	m_N0 = N0; m_N1 = N1;
}


class McooComp : public VbaseComp
{
private:
	typedef VbaseComp Base;
	using Base::m_p;
	using Base::m_N;
	Long m_N0, m_N1, m_Nnz;
	VecLong m_row, m_col;
public:
	using Base::p;
	McooComp(): m_N0(0), m_N1(0), m_Nnz(0) {};
	McooComp(Long_I N0, Long_I N1);
	McooComp(Long_I N0, Long_I N1, Long_I Ncap); // reserve Ncap elements
	Long *row_p();
	const Long *row_p() const;
	Long *col_p();
	const Long *col_p() const;
	void operator<<(McooComp &rhs); // move data and rhs.resize(0)
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
		return 0; // never return a (const) reference to a temporary
	return m_p[n];
}

inline void McooComp::operator<<(McooComp &rhs)
{
	Base::operator<<(rhs);
	m_row << rhs.m_row; m_col << rhs.m_col;
	m_Nnz = rhs.m_Nnz;
	rhs.m_Nnz = 0; rhs.m_N = 0;
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
	Base::operator<<(data);
	m_row << row; m_col << col;
}

inline void McooComp::reshape(Long_I N0, Long_I N1)
{
	m_N0 = N0; m_N1 = N1;
}



} // namespace slisc
