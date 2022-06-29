// save SLISC containers to Matlab ".mat" files.
// see README.txt for details

#pragma once
#include "arithmetic.h"
#include "file.h"
#include "time.h"
#ifdef SLS_USE_MATFILE
#include <mat.h>

namespace slisc {

struct Mat
{
	MATFile *m_p;
	Mat(): m_p(NULL) {};
	Mat(Str_I fname, Str_I rw, Bool_I replace = false);
	void open(Str_I fname, Str_I rw, Bool_I replace = false);
	Bool isopen();
	void close();
};

inline Mat::Mat(Str_I fname, Str_I rw, Bool_I replace): m_p(NULL) {
	open(fname, rw, replace);
}

inline void Mat::open(Str_I fname, Str_I rw, Bool_I replace) {
	if (isopen()) close();
	if (rw == "w" && file_exist(fname)) {
		if (!replace) {
#ifdef SLS_MAT_REPLACE
			file_remove(fname);
#else
			while (true) {
				if (file_exist(fname)) {
					SLS_WARN("\n\nfile [" + fname + "] already exist! delete file to continue...\n"
						"  (define SLS_MAT_REPLACE to replace file by default)\n\n");
				}
				else
					break;
				pause(10);
			}
#endif
		}
		else
			file_remove(fname);
	}
	m_p = matOpen(fname.c_str(), rw.c_str());
}

inline Bool Mat::isopen() {
	return m_p != NULL;
}

inline void Mat::close() {
	if (isopen()) {
		matClose(m_p); m_p = NULL;
	}
}

inline void save(Char_I s, Str_I varname, Mat mat)
{
	mxArray *ps;
	ps = mxCreateNumericMatrix(1, 1, mxCHAR_CLASS, mxREAL);
	Char *pps = (Char*)mxGetPr(ps);
	pps[0] = s;
	matPutVariable(mat.m_p, varname.c_str(), ps);
	mxDestroyArray(ps);
}

inline void save(Uchar_I s, Str_I varname, Mat mat)
{
	mxArray *ps;
	ps = mxCreateNumericMatrix(1, 1, mxUINT8_CLASS, mxREAL);
	Uchar *pps = (Uchar*)mxGetPr(ps);
	pps[0] = s;
	matPutVariable(mat.m_p, varname.c_str(), ps);
	mxDestroyArray(ps);
}

inline void save(Int_I s, Str_I varname, Mat mat)
{
	mxArray *ps;
    ps = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
	Int *pps = (Int*)mxGetPr(ps);
	pps[0] = s;
	matPutVariable(mat.m_p, varname.c_str(), ps);
	mxDestroyArray(ps);
}

inline void save(Llong_I s, Str_I varname, Mat mat)
{
	mxArray *ps;
    ps = mxCreateNumericMatrix(1, 1, mxINT64_CLASS, mxREAL);
	Llong *pps = (Llong*)mxGetPr(ps);
	pps[0] = s;
	matPutVariable(mat.m_p, varname.c_str(), ps);
	mxDestroyArray(ps);
}

inline void save(Doub_I s, Str_I varname, Mat mat)
{
	mxArray *ps;
    ps = mxCreateDoubleMatrix(1, 1, mxREAL);
	Doub *pps = (Doub*)mxGetPr(ps);
	pps[0] = s;
	matPutVariable(mat.m_p, varname.c_str(), ps);
	mxDestroyArray(ps);
}

inline void save(Comp_I s, Str_I varname, Mat mat)
{
	mxArray *ps;
    ps = mxCreateDoubleMatrix(1, 1, mxCOMPLEX);
    Doub *pps = mxGetPr(ps);
	pps[0] = real(s);
	pps = mxGetPi(ps);
	pps[0] = imag(s);
	matPutVariable(mat.m_p, varname.c_str(), ps);
	mxDestroyArray(ps);
}



inline void save(VecChar_I v, Str_I varname, Mat mat)
{
	Long i, n = v.size();
	mxArray *pv;
	pv = mxCreateUninitNumericMatrix(1, n, mxCHAR_CLASS, mxREAL);
	Char *ppv = (Char*)mxGetPr(pv);
	for (i = 0; i < n; ++i)
		ppv[i] = v[i];
	matPutVariable(mat.m_p, varname.c_str(), pv);
	mxDestroyArray(pv);
}

inline void save(VecUchar_I v, Str_I varname, Mat mat)
{
	Long i, n = v.size();
	mxArray *pv;
	pv = mxCreateUninitNumericMatrix(1, n, mxUINT8_CLASS, mxREAL);
	Uchar *ppv = (Uchar*)mxGetPr(pv);
	for (i = 0; i < n; ++i)
		ppv[i] = v[i];
	matPutVariable(mat.m_p, varname.c_str(), pv);
	mxDestroyArray(pv);
}

inline void save(VecInt_I v, Str_I varname, Mat mat)
{
	Long i, n = v.size();
	mxArray *pv;
    pv = mxCreateUninitNumericMatrix(1, n, mxINT32_CLASS, mxREAL);
	Int *ppv = (Int*)mxGetPr(pv);
	for (i = 0; i < n; ++i)
		ppv[i] = v[i];
	matPutVariable(mat.m_p, varname.c_str(), pv);
	mxDestroyArray(pv);
}

inline void save(VecLlong_I v, Str_I varname, Mat mat)
{
	Long i, n = v.size();
	mxArray *pv;
    pv = mxCreateUninitNumericMatrix(1, n, mxINT64_CLASS, mxREAL);
	Llong *ppv = (Llong*)mxGetPr(pv);
	for (i = 0; i < n; ++i)
		ppv[i] = v[i];
	matPutVariable(mat.m_p, varname.c_str(), pv);
	mxDestroyArray(pv);
}

inline void save(VecDoub_I v, Str_I varname, Mat mat)
{
	Long i, n = v.size();
	mxArray *pv;
    pv = mxCreateUninitNumericMatrix(1, n, mxDOUBLE_CLASS, mxREAL);
	Doub *ppv = (Doub*)mxGetPr(pv);
	for (i = 0; i < n; ++i)
		ppv[i] = v[i];
	matPutVariable(mat.m_p, varname.c_str(), pv);
	mxDestroyArray(pv);
}

inline void save(VecComp_I v, Str_I varname, Mat mat)
{
	Long i, n = v.size();
	mxArray *pv;
    pv = mxCreateUninitNumericMatrix(1, n, mxDOUBLE_CLASS, mxCOMPLEX);
    auto ppvr = mxGetPr(pv);
	auto ppvi = mxGetPi(pv);
	for (i = 0; i < n; ++i) {
		ppvr[i] = real(v[i]); ppvi[i] = imag(v[i]);
	}
	matPutVariable(mat.m_p, varname.c_str(), pv);
	mxDestroyArray(pv);
}

inline void save(SvecChar_I v, Str_I varname, Mat mat)
{
	Long i, n = v.size();
	mxArray *pv;
	pv = mxCreateUninitNumericMatrix(1, n, mxCHAR_CLASS, mxREAL);
	Char *ppv = (Char*)mxGetPr(pv);
	for (i = 0; i < n; ++i)
		ppv[i] = v[i];
	matPutVariable(mat.m_p, varname.c_str(), pv);
	mxDestroyArray(pv);
}

inline void save(SvecUchar_I v, Str_I varname, Mat mat)
{
	Long i, n = v.size();
	mxArray *pv;
	pv = mxCreateUninitNumericMatrix(1, n, mxUINT8_CLASS, mxREAL);
	Uchar *ppv = (Uchar*)mxGetPr(pv);
	for (i = 0; i < n; ++i)
		ppv[i] = v[i];
	matPutVariable(mat.m_p, varname.c_str(), pv);
	mxDestroyArray(pv);
}

inline void save(SvecInt_I v, Str_I varname, Mat mat)
{
	Long i, n = v.size();
	mxArray *pv;
    pv = mxCreateUninitNumericMatrix(1, n, mxINT32_CLASS, mxREAL);
	Int *ppv = (Int*)mxGetPr(pv);
	for (i = 0; i < n; ++i)
		ppv[i] = v[i];
	matPutVariable(mat.m_p, varname.c_str(), pv);
	mxDestroyArray(pv);
}

inline void save(SvecLlong_I v, Str_I varname, Mat mat)
{
	Long i, n = v.size();
	mxArray *pv;
    pv = mxCreateUninitNumericMatrix(1, n, mxINT64_CLASS, mxREAL);
	Llong *ppv = (Llong*)mxGetPr(pv);
	for (i = 0; i < n; ++i)
		ppv[i] = v[i];
	matPutVariable(mat.m_p, varname.c_str(), pv);
	mxDestroyArray(pv);
}

inline void save(SvecDoub_I v, Str_I varname, Mat mat)
{
	Long i, n = v.size();
	mxArray *pv;
    pv = mxCreateUninitNumericMatrix(1, n, mxDOUBLE_CLASS, mxREAL);
	Doub *ppv = (Doub*)mxGetPr(pv);
	for (i = 0; i < n; ++i)
		ppv[i] = v[i];
	matPutVariable(mat.m_p, varname.c_str(), pv);
	mxDestroyArray(pv);
}

inline void save(SvecComp_I v, Str_I varname, Mat mat)
{
	Long i, n = v.size();
	mxArray *pv;
    pv = mxCreateUninitNumericMatrix(1, n, mxDOUBLE_CLASS, mxCOMPLEX);
    auto ppvr = mxGetPr(pv);
	auto ppvi = mxGetPi(pv);
	for (i = 0; i < n; ++i) {
		ppvr[i] = real(v[i]); ppvi[i] = imag(v[i]);
	}
	matPutVariable(mat.m_p, varname.c_str(), pv);
	mxDestroyArray(pv);
}

inline void save(DvecChar_I v, Str_I varname, Mat mat)
{
	Long i, n = v.size();
	mxArray *pv;
	pv = mxCreateUninitNumericMatrix(1, n, mxCHAR_CLASS, mxREAL);
	Char *ppv = (Char*)mxGetPr(pv);
	for (i = 0; i < n; ++i)
		ppv[i] = v[i];
	matPutVariable(mat.m_p, varname.c_str(), pv);
	mxDestroyArray(pv);
}

inline void save(DvecUchar_I v, Str_I varname, Mat mat)
{
	Long i, n = v.size();
	mxArray *pv;
	pv = mxCreateUninitNumericMatrix(1, n, mxUINT8_CLASS, mxREAL);
	Uchar *ppv = (Uchar*)mxGetPr(pv);
	for (i = 0; i < n; ++i)
		ppv[i] = v[i];
	matPutVariable(mat.m_p, varname.c_str(), pv);
	mxDestroyArray(pv);
}

inline void save(DvecInt_I v, Str_I varname, Mat mat)
{
	Long i, n = v.size();
	mxArray *pv;
    pv = mxCreateUninitNumericMatrix(1, n, mxINT32_CLASS, mxREAL);
	Int *ppv = (Int*)mxGetPr(pv);
	for (i = 0; i < n; ++i)
		ppv[i] = v[i];
	matPutVariable(mat.m_p, varname.c_str(), pv);
	mxDestroyArray(pv);
}

inline void save(DvecLlong_I v, Str_I varname, Mat mat)
{
	Long i, n = v.size();
	mxArray *pv;
    pv = mxCreateUninitNumericMatrix(1, n, mxINT64_CLASS, mxREAL);
	Llong *ppv = (Llong*)mxGetPr(pv);
	for (i = 0; i < n; ++i)
		ppv[i] = v[i];
	matPutVariable(mat.m_p, varname.c_str(), pv);
	mxDestroyArray(pv);
}

inline void save(DvecDoub_I v, Str_I varname, Mat mat)
{
	Long i, n = v.size();
	mxArray *pv;
    pv = mxCreateUninitNumericMatrix(1, n, mxDOUBLE_CLASS, mxREAL);
	Doub *ppv = (Doub*)mxGetPr(pv);
	for (i = 0; i < n; ++i)
		ppv[i] = v[i];
	matPutVariable(mat.m_p, varname.c_str(), pv);
	mxDestroyArray(pv);
}

inline void save(DvecComp_I v, Str_I varname, Mat mat)
{
	Long i, n = v.size();
	mxArray *pv;
    pv = mxCreateUninitNumericMatrix(1, n, mxDOUBLE_CLASS, mxCOMPLEX);
    auto ppvr = mxGetPr(pv);
	auto ppvi = mxGetPi(pv);
	for (i = 0; i < n; ++i) {
		ppvr[i] = real(v[i]); ppvi[i] = imag(v[i]);
	}
	matPutVariable(mat.m_p, varname.c_str(), pv);
	mxDestroyArray(pv);
}


inline void save(CmatChar_I a, Str_I varname, Mat mat)
{
	Long i, j, m, n;
	mxArray *pa;
	m = a.n0(); n = a.n1();
	pa = mxCreateUninitNumericMatrix(1, n, mxCHAR_CLASS, mxREAL);
    Char *ppa = (Char*)mxGetPr(pa);
        for (i = 0; i < m; ++i)
            for (j = 0; j < n; ++j)
                ppa[i + m * j] = a(i,j);
	matPutVariable(mat.m_p, varname.c_str(), pa);
	mxDestroyArray(pa);
}

inline void save(CmatUchar_I a, Str_I varname, Mat mat)
{
	Long i, j, m, n;
	mxArray *pa;
	m = a.n0(); n = a.n1();
	pa = mxCreateUninitNumericMatrix(m, n, mxUINT8_CLASS, mxREAL);
    Uchar *ppa = (Uchar*)mxGetPr(pa);
        for (i = 0; i < m; ++i)
            for (j = 0; j < n; ++j)
                ppa[i + m * j] = a(i,j);
	matPutVariable(mat.m_p, varname.c_str(), pa);
	mxDestroyArray(pa);
}

inline void save(CmatInt_I a, Str_I varname, Mat mat)
{
	Long i, j, m, n;
	mxArray *pa;
	m = a.n0(); n = a.n1();
    pa = mxCreateUninitNumericMatrix(m, n, mxINT32_CLASS, mxREAL);
    Int *ppa = (Int*)mxGetPr(pa);
        for (i = 0; i < m; ++i)
            for (j = 0; j < n; ++j)
                ppa[i + m * j] = a(i,j);
	matPutVariable(mat.m_p, varname.c_str(), pa);
	mxDestroyArray(pa);
}

inline void save(CmatLlong_I a, Str_I varname, Mat mat)
{
	Long i, j, m, n;
	mxArray *pa;
	m = a.n0(); n = a.n1();
    pa = mxCreateUninitNumericMatrix(m, n, mxINT64_CLASS, mxREAL);
    Llong *ppa = (Llong*)mxGetPr(pa);
        for (i = 0; i < m; ++i)
            for (j = 0; j < n; ++j)
                ppa[i + m * j] = a(i,j);
	matPutVariable(mat.m_p, varname.c_str(), pa);
	mxDestroyArray(pa);
}

inline void save(CmatDoub_I a, Str_I varname, Mat mat)
{
	Long i, j, m, n;
	mxArray *pa;
	m = a.n0(); n = a.n1();
    pa = mxCreateUninitNumericMatrix(m, n, mxDOUBLE_CLASS, mxREAL);
    Doub *ppa = (Doub*)mxGetPr(pa);
        for (i = 0; i < m; ++i)
            for (j = 0; j < n; ++j)
                ppa[i + m * j] = a(i,j);
	matPutVariable(mat.m_p, varname.c_str(), pa);
	mxDestroyArray(pa);
}

inline void save(CmatComp_I a, Str_I varname, Mat mat)
{
	Long i, j, m, n;
	mxArray *pa;
	m = a.n0(); n = a.n1();
    pa = mxCreateUninitNumericMatrix(m, n, mxDOUBLE_CLASS, mxCOMPLEX);
    Doub *ppar = mxGetPr(pa), *ppai = mxGetPi(pa);
    for (i = 0; i < m; ++i) {
		for (j = 0; j < n; ++j) {
			Long ind = i + m * j; const Comp &c = a(i,j);
			ppar[ind] = real(c);
			ppai[ind] = imag(c);
		}
    }
	matPutVariable(mat.m_p, varname.c_str(), pa);
	mxDestroyArray(pa);
}

inline void save(ScmatInt_I a, Str_I varname, Mat mat)
{
	Long i, j, m, n;
	mxArray *pa;
	m = a.n0(); n = a.n1();
    pa = mxCreateUninitNumericMatrix(m, n, mxINT32_CLASS, mxREAL);
    Int *ppa = (Int*)mxGetPr(pa);
        for (i = 0; i < m; ++i)
            for (j = 0; j < n; ++j)
                ppa[i + m * j] = a(i,j);
	matPutVariable(mat.m_p, varname.c_str(), pa);
	mxDestroyArray(pa);
}

inline void save(ScmatLlong_I a, Str_I varname, Mat mat)
{
	Long i, j, m, n;
	mxArray *pa;
	m = a.n0(); n = a.n1();
    pa = mxCreateUninitNumericMatrix(m, n, mxINT64_CLASS, mxREAL);
    Llong *ppa = (Llong*)mxGetPr(pa);
        for (i = 0; i < m; ++i)
            for (j = 0; j < n; ++j)
                ppa[i + m * j] = a(i,j);
	matPutVariable(mat.m_p, varname.c_str(), pa);
	mxDestroyArray(pa);
}

inline void save(ScmatDoub_I a, Str_I varname, Mat mat)
{
	Long i, j, m, n;
	mxArray *pa;
	m = a.n0(); n = a.n1();
    pa = mxCreateUninitNumericMatrix(m, n, mxDOUBLE_CLASS, mxREAL);
    Doub *ppa = (Doub*)mxGetPr(pa);
        for (i = 0; i < m; ++i)
            for (j = 0; j < n; ++j)
                ppa[i + m * j] = a(i,j);
	matPutVariable(mat.m_p, varname.c_str(), pa);
	mxDestroyArray(pa);
}

inline void save(ScmatComp_I a, Str_I varname, Mat mat)
{
	Long i, j, m, n;
	mxArray *pa;
	m = a.n0(); n = a.n1();
    pa = mxCreateUninitNumericMatrix(m, n, mxDOUBLE_CLASS, mxCOMPLEX);
    Doub *ppar = mxGetPr(pa), *ppai = mxGetPi(pa);
    for (i = 0; i < m; ++i) {
		for (j = 0; j < n; ++j) {
			Long ind = i + m * j; const Comp &c = a(i,j);
			ppar[ind] = real(c);
			ppai[ind] = imag(c);
		}
    }
	matPutVariable(mat.m_p, varname.c_str(), pa);
	mxDestroyArray(pa);
}

inline void save(DcmatInt_I a, Str_I varname, Mat mat)
{
	Long i, j, m, n;
	mxArray *pa;
	m = a.n0(); n = a.n1();
    pa = mxCreateUninitNumericMatrix(m, n, mxINT32_CLASS, mxREAL);
    Int *ppa = (Int*)mxGetPr(pa);
        for (i = 0; i < m; ++i)
            for (j = 0; j < n; ++j)
                ppa[i + m * j] = a(i,j);
	matPutVariable(mat.m_p, varname.c_str(), pa);
	mxDestroyArray(pa);
}

inline void save(DcmatLlong_I a, Str_I varname, Mat mat)
{
	Long i, j, m, n;
	mxArray *pa;
	m = a.n0(); n = a.n1();
    pa = mxCreateUninitNumericMatrix(m, n, mxINT64_CLASS, mxREAL);
    Llong *ppa = (Llong*)mxGetPr(pa);
        for (i = 0; i < m; ++i)
            for (j = 0; j < n; ++j)
                ppa[i + m * j] = a(i,j);
	matPutVariable(mat.m_p, varname.c_str(), pa);
	mxDestroyArray(pa);
}

inline void save(DcmatDoub_I a, Str_I varname, Mat mat)
{
	Long i, j, m, n;
	mxArray *pa;
	m = a.n0(); n = a.n1();
    pa = mxCreateUninitNumericMatrix(m, n, mxDOUBLE_CLASS, mxREAL);
    Doub *ppa = (Doub*)mxGetPr(pa);
        for (i = 0; i < m; ++i)
            for (j = 0; j < n; ++j)
                ppa[i + m * j] = a(i,j);
	matPutVariable(mat.m_p, varname.c_str(), pa);
	mxDestroyArray(pa);
}

inline void save(DcmatComp_I a, Str_I varname, Mat mat)
{
	Long i, j, m, n;
	mxArray *pa;
	m = a.n0(); n = a.n1();
    pa = mxCreateUninitNumericMatrix(m, n, mxDOUBLE_CLASS, mxCOMPLEX);
    Doub *ppar = mxGetPr(pa), *ppai = mxGetPi(pa);
    for (i = 0; i < m; ++i) {
		for (j = 0; j < n; ++j) {
			Long ind = i + m * j; const Comp &c = a(i,j);
			ppar[ind] = real(c);
			ppai[ind] = imag(c);
		}
    }
	matPutVariable(mat.m_p, varname.c_str(), pa);
	mxDestroyArray(pa);
}


inline void save(Cmat3Llong_I a, Str_I varname, Mat mat)
{
	Long i, j, k, m, n, q, mn;
	mxArray *pa;
	m = a.n0(); n = a.n1(); q = a.n2(); mn = m * n;
	size_t sz[3]{ size_t(m), size_t(n), size_t(q) };
	pa = mxCreateUninitNumericArray(3, sz, mxINT64_CLASS, mxREAL);
    Llong *ppa = (Llong*)mxGetPr(pa);
        for (i = 0; i < m; ++i)
            for (j = 0; j < n; ++j)
                for (k = 0; k < q; ++k)
                    ppa[i + m*j + mn*k] = a(i,j,k);
	matPutVariable(mat.m_p, varname.c_str(), pa);
	mxDestroyArray(pa);
}

inline void save(Cmat3Doub_I a, Str_I varname, Mat mat)
{
	Long i, j, k, m, n, q, mn;
	mxArray *pa;
	m = a.n0(); n = a.n1(); q = a.n2(); mn = m * n;
	size_t sz[3]{ size_t(m), size_t(n), size_t(q) };
	pa = mxCreateUninitNumericArray(3, sz, mxDOUBLE_CLASS, mxREAL);
    Doub *ppa = (Doub*)mxGetPr(pa);
        for (i = 0; i < m; ++i)
            for (j = 0; j < n; ++j)
                for (k = 0; k < q; ++k)
                    ppa[i + m*j + mn*k] = a(i,j,k);
	matPutVariable(mat.m_p, varname.c_str(), pa);
	mxDestroyArray(pa);
}

inline void save(Cmat3Comp_I a, Str_I varname, Mat mat)
{
	Long i, j, k, m, n, q, mn;
	mxArray *pa;
	m = a.n0(); n = a.n1(); q = a.n2(); mn = m * n;
	size_t sz[3]{ size_t(m), size_t(n), size_t(q) };
    pa = mxCreateUninitNumericArray(3, sz, mxDOUBLE_CLASS, mxCOMPLEX);
    Doub *ppar = mxGetPr(pa), *ppai = mxGetPi(pa);
    for (i = 0; i < m; ++i) {
        for (j = 0; j < n; ++j) {
            for (k = 0; k < q; ++k) {
                Long ind = i + m * j + mn * k;
                const Comp &c = a(i,j,k);
                ppar[ind] = real(c); ppai[ind] = imag(c);
            }
        }
    }
	matPutVariable(mat.m_p, varname.c_str(), pa);
	mxDestroyArray(pa);
}


inline void load(Char_O s, Str_I varname, Mat mat)
{
	mxArray *ps;
    ps = matGetVariable(mat.m_p, varname.c_str());
    if (!mxIsChar(ps))
        SLS_ERR("'matfile: load(): wrong type!");
    Char *pps = (Char *)mxGetPr(ps);
	s = pps[0];
	mxDestroyArray(ps);
}

inline void load(Uchar_O s, Str_I varname, Mat mat)
{
	mxArray *ps;
    ps = matGetVariable(mat.m_p, varname.c_str());
    if (!mxIsUint8(ps))
        SLS_ERR("'matfile: load(): wrong type!");
    Uchar *pps = (Uchar *)mxGetPr(ps);
	s = pps[0];
	mxDestroyArray(ps);
}

inline void load(Int_O s, Str_I varname, Mat mat)
{
	mxArray *ps;
    ps = matGetVariable(mat.m_p, varname.c_str());
	if (!mxIsInt32(ps))
        SLS_ERR("'matfile: load(): wrong type!");
    Int *pps = (Int *)mxGetPr(ps);
	s = pps[0];
	mxDestroyArray(ps);
}

inline void load(Llong_O s, Str_I varname, Mat mat)
{
	mxArray *ps;
    ps = matGetVariable(mat.m_p, varname.c_str());
	if (!mxIsInt64(ps))
        SLS_ERR("'matfile: load(): wrong type!");
    Llong *pps = (Llong *)mxGetPr(ps);
	s = pps[0];
	mxDestroyArray(ps);
}

inline void load(Doub_O s, Str_I varname, Mat mat)
{
	mxArray *ps;
    ps = matGetVariable(mat.m_p, varname.c_str());
    if (!mxIsDouble(ps) || mxIsComplex(ps))
        SLS_ERR("'matfile: load(): wrong type!");
    Doub *pps = (Doub *)mxGetPr(ps);
	s = pps[0];
	mxDestroyArray(ps);
}

inline void load(Comp_O s, Str_I varname, Mat mat)
{
	mxArray *ps;
    ps = matGetVariable(mat.m_p, varname.c_str());
    if (!mxIsDouble(ps))
        SLS_ERR("'matfile: load(): wrong type!");
    Doub *ppsr = mxGetPr(ps), *ppsi = mxGetPi(ps);
    s = ppsi ? Comp(ppsr[0], ppsi[0]) : ppsr[0];
	mxDestroyArray(ps);
}


inline void load(VecChar_O v, Str_I varname, Mat mat)
{
	Long i, n;
	mxArray *pv;
    pv = matGetVariable(mat.m_p, varname.c_str());
    if (!mxIsChar(pv))
        SLS_ERR("'matfile: load(): wrong type!");
	n = mxGetDimensions(pv)[1];
	v.resize(n);
	Char *ppv = (Char *)mxGetPr(pv);
	for (i = 0; i < n; ++i)
		v[i] = ppv[i];
	mxDestroyArray(pv);
}

inline void load(VecUchar_O v, Str_I varname, Mat mat)
{
	Long i, n;
	mxArray *pv;
    pv = matGetVariable(mat.m_p, varname.c_str());
    if (!mxIsUint8(pv))
        SLS_ERR("'matfile: load(): wrong type!");
	n = mxGetDimensions(pv)[1];
	v.resize(n);
	Uchar *ppv = (Uchar *)mxGetPr(pv);
	for (i = 0; i < n; ++i)
		v[i] = ppv[i];
	mxDestroyArray(pv);
}

inline void load(VecInt_O v, Str_I varname, Mat mat)
{
	Long i, n;
	mxArray *pv;
    pv = matGetVariable(mat.m_p, varname.c_str());
    if (!mxIsInt32(pv))
        SLS_ERR("'matfile: load(): wrong type!");
	n = mxGetDimensions(pv)[1];
	v.resize(n);
	Int *ppv = (Int *)mxGetPr(pv);
	for (i = 0; i < n; ++i)
		v[i] = ppv[i];
	mxDestroyArray(pv);
}

inline void load(VecLlong_O v, Str_I varname, Mat mat)
{
	Long i, n;
	mxArray *pv;
    pv = matGetVariable(mat.m_p, varname.c_str());
	if (!mxIsInt64(pv))
        SLS_ERR("'matfile: load(): wrong type!");
	n = mxGetDimensions(pv)[1];
	v.resize(n);
	Llong *ppv = (Llong *)mxGetPr(pv);
	for (i = 0; i < n; ++i)
		v[i] = ppv[i];
	mxDestroyArray(pv);
}

inline void load(VecDoub_O v, Str_I varname, Mat mat)
{
	Long i, n;
	mxArray *pv;
    pv = matGetVariable(mat.m_p, varname.c_str());
    if (!mxIsDouble(pv) || mxIsComplex(pv))
        SLS_ERR("'matfile: load(): wrong type!");
	n = mxGetDimensions(pv)[1];
	v.resize(n);
	Doub *ppv = (Doub *)mxGetPr(pv);
	for (i = 0; i < n; ++i)
		v[i] = ppv[i];
	mxDestroyArray(pv);
}

inline void load(VecComp_O v, Str_I varname, Mat mat)
{
	Long i, n;
	mxArray *pv;
    pv = matGetVariable(mat.m_p, varname.c_str());
    if (!mxIsDouble(pv))
        SLS_ERR("'matfile: load(): wrong type!");
	n = mxGetDimensions(pv)[1];
	v.resize(n);
    Doub *ppvr = mxGetPr(pv), *ppvi = mxGetPi(pv);
	if (ppvi)
		for (i = 0; i < n; ++i)
			v[i] = Comp(ppvr[i], ppvi[i]);
	else
		for (i = 0; i < n; ++i)
			v[i] = ppvr[i];
	mxDestroyArray(pv);
}

inline void load(SvecChar_O v, Str_I varname, Mat mat)
{
	Long i, n;
	mxArray *pv;
    pv = matGetVariable(mat.m_p, varname.c_str());
    if (!mxIsChar(pv))
        SLS_ERR("'matfile: load(): wrong type!");
	n = mxGetDimensions(pv)[1];
	if (v.size() != n) SLS_ERR("wrong size!");
	Char *ppv = (Char *)mxGetPr(pv);
	for (i = 0; i < n; ++i)
		v[i] = ppv[i];
	mxDestroyArray(pv);
}

inline void load(SvecUchar_O v, Str_I varname, Mat mat)
{
	Long i, n;
	mxArray *pv;
    pv = matGetVariable(mat.m_p, varname.c_str());
    if (!mxIsUint8(pv))
        SLS_ERR("'matfile: load(): wrong type!");
	n = mxGetDimensions(pv)[1];
	if (v.size() != n) SLS_ERR("wrong size!");
	Uchar *ppv = (Uchar *)mxGetPr(pv);
	for (i = 0; i < n; ++i)
		v[i] = ppv[i];
	mxDestroyArray(pv);
}

inline void load(SvecInt_O v, Str_I varname, Mat mat)
{
	Long i, n;
	mxArray *pv;
    pv = matGetVariable(mat.m_p, varname.c_str());
    if (!mxIsInt32(pv))
        SLS_ERR("'matfile: load(): wrong type!");
	n = mxGetDimensions(pv)[1];
	if (v.size() != n) SLS_ERR("wrong size!");
	Int *ppv = (Int *)mxGetPr(pv);
	for (i = 0; i < n; ++i)
		v[i] = ppv[i];
	mxDestroyArray(pv);
}

inline void load(SvecLlong_O v, Str_I varname, Mat mat)
{
	Long i, n;
	mxArray *pv;
    pv = matGetVariable(mat.m_p, varname.c_str());
	if (!mxIsInt64(pv))
        SLS_ERR("'matfile: load(): wrong type!");
	n = mxGetDimensions(pv)[1];
	if (v.size() != n) SLS_ERR("wrong size!");
	Llong *ppv = (Llong *)mxGetPr(pv);
	for (i = 0; i < n; ++i)
		v[i] = ppv[i];
	mxDestroyArray(pv);
}

inline void load(SvecDoub_O v, Str_I varname, Mat mat)
{
	Long i, n;
	mxArray *pv;
    pv = matGetVariable(mat.m_p, varname.c_str());
    if (!mxIsDouble(pv) || mxIsComplex(pv))
        SLS_ERR("'matfile: load(): wrong type!");
	n = mxGetDimensions(pv)[1];
	if (v.size() != n) SLS_ERR("wrong size!");
	Doub *ppv = (Doub *)mxGetPr(pv);
	for (i = 0; i < n; ++i)
		v[i] = ppv[i];
	mxDestroyArray(pv);
}

inline void load(SvecComp_O v, Str_I varname, Mat mat)
{
	Long i, n;
	mxArray *pv;
    pv = matGetVariable(mat.m_p, varname.c_str());
    if (!mxIsDouble(pv))
        SLS_ERR("'matfile: load(): wrong type!");
	n = mxGetDimensions(pv)[1];
	if (v.size() != n) SLS_ERR("wrong size!");
    Doub *ppvr = mxGetPr(pv), *ppvi = mxGetPi(pv);
	if (ppvi)
		for (i = 0; i < n; ++i)
			v[i] = Comp(ppvr[i], ppvi[i]);
	else
		for (i = 0; i < n; ++i)
			v[i] = ppvr[i];
	mxDestroyArray(pv);
}

inline void load(DvecChar_O v, Str_I varname, Mat mat)
{
	Long i, n;
	mxArray *pv;
    pv = matGetVariable(mat.m_p, varname.c_str());
    if (!mxIsChar(pv))
        SLS_ERR("'matfile: load(): wrong type!");
	n = mxGetDimensions(pv)[1];
	if (v.size() != n) SLS_ERR("wrong size!");
	Char *ppv = (Char *)mxGetPr(pv);
	for (i = 0; i < n; ++i)
		v[i] = ppv[i];
	mxDestroyArray(pv);
}

inline void load(DvecUchar_O v, Str_I varname, Mat mat)
{
	Long i, n;
	mxArray *pv;
    pv = matGetVariable(mat.m_p, varname.c_str());
    if (!mxIsUint8(pv))
        SLS_ERR("'matfile: load(): wrong type!");
	n = mxGetDimensions(pv)[1];
	if (v.size() != n) SLS_ERR("wrong size!");
	Uchar *ppv = (Uchar *)mxGetPr(pv);
	for (i = 0; i < n; ++i)
		v[i] = ppv[i];
	mxDestroyArray(pv);
}

inline void load(DvecInt_O v, Str_I varname, Mat mat)
{
	Long i, n;
	mxArray *pv;
    pv = matGetVariable(mat.m_p, varname.c_str());
    if (!mxIsInt32(pv))
        SLS_ERR("'matfile: load(): wrong type!");
	n = mxGetDimensions(pv)[1];
	if (v.size() != n) SLS_ERR("wrong size!");
	Int *ppv = (Int *)mxGetPr(pv);
	for (i = 0; i < n; ++i)
		v[i] = ppv[i];
	mxDestroyArray(pv);
}

inline void load(DvecLlong_O v, Str_I varname, Mat mat)
{
	Long i, n;
	mxArray *pv;
    pv = matGetVariable(mat.m_p, varname.c_str());
	if (!mxIsInt64(pv))
        SLS_ERR("'matfile: load(): wrong type!");
	n = mxGetDimensions(pv)[1];
	if (v.size() != n) SLS_ERR("wrong size!");
	Llong *ppv = (Llong *)mxGetPr(pv);
	for (i = 0; i < n; ++i)
		v[i] = ppv[i];
	mxDestroyArray(pv);
}

inline void load(DvecDoub_O v, Str_I varname, Mat mat)
{
	Long i, n;
	mxArray *pv;
    pv = matGetVariable(mat.m_p, varname.c_str());
    if (!mxIsDouble(pv) || mxIsComplex(pv))
        SLS_ERR("'matfile: load(): wrong type!");
	n = mxGetDimensions(pv)[1];
	if (v.size() != n) SLS_ERR("wrong size!");
	Doub *ppv = (Doub *)mxGetPr(pv);
	for (i = 0; i < n; ++i)
		v[i] = ppv[i];
	mxDestroyArray(pv);
}

inline void load(DvecComp_O v, Str_I varname, Mat mat)
{
	Long i, n;
	mxArray *pv;
    pv = matGetVariable(mat.m_p, varname.c_str());
    if (!mxIsDouble(pv))
        SLS_ERR("'matfile: load(): wrong type!");
	n = mxGetDimensions(pv)[1];
	if (v.size() != n) SLS_ERR("wrong size!");
    Doub *ppvr = mxGetPr(pv), *ppvi = mxGetPi(pv);
	if (ppvi)
		for (i = 0; i < n; ++i)
			v[i] = Comp(ppvr[i], ppvi[i]);
	else
		for (i = 0; i < n; ++i)
			v[i] = ppvr[i];
	mxDestroyArray(pv);
}


inline void load(CmatChar_O a, Str_I varname, Mat mat)
{
	Long i, j, m, n;
	mxArray *pa = matGetVariable(mat.m_p, varname.c_str());
	if (!mxIsChar(pa))
		SLS_ERR("'matfile: load(): wrong type!");
	const mwSize *sz = mxGetDimensions(pa);
	m = sz[0]; n = sz[1];
	a.resize(m, n);
    Char *ppa = (Char *)mxGetPr(pa);
    for (i = 0; i < m; ++i)
		for (j = 0; j < n; ++j)
			a(i,j) = ppa[m*j + i];
	mxDestroyArray(pa);
}

inline void load(CmatUchar_O a, Str_I varname, Mat mat)
{
	Long i, j, m, n;
	mxArray *pa = matGetVariable(mat.m_p, varname.c_str());
	if (!mxIsUint8(pa))
		SLS_ERR("'matfile: load(): wrong type!");
	const mwSize *sz = mxGetDimensions(pa);
	m = sz[0]; n = sz[1];
	a.resize(m, n);
    Uchar *ppa = (Uchar *)mxGetPr(pa);
    for (i = 0; i < m; ++i)
		for (j = 0; j < n; ++j)
			a(i,j) = ppa[m*j + i];
	mxDestroyArray(pa);
}

inline void load(CmatInt_O a, Str_I varname, Mat mat)
{
	Long i, j, m, n;
	mxArray *pa = matGetVariable(mat.m_p, varname.c_str());
    if (!mxIsInt32(pa))
		SLS_ERR("'matfile: load(): wrong type!");
	const mwSize *sz = mxGetDimensions(pa);
	m = sz[0]; n = sz[1];
	a.resize(m, n);
    Int *ppa = (Int *)mxGetPr(pa);
    for (i = 0; i < m; ++i)
		for (j = 0; j < n; ++j)
			a(i,j) = ppa[m*j + i];
	mxDestroyArray(pa);
}

inline void load(CmatLlong_O a, Str_I varname, Mat mat)
{
	Long i, j, m, n;
	mxArray *pa = matGetVariable(mat.m_p, varname.c_str());
	if (!mxIsInt64(pa))
		SLS_ERR("'matfile: load(): wrong type!");
	const mwSize *sz = mxGetDimensions(pa);
	m = sz[0]; n = sz[1];
	a.resize(m, n);
    Llong *ppa = (Llong *)mxGetPr(pa);
    for (i = 0; i < m; ++i)
		for (j = 0; j < n; ++j)
			a(i,j) = ppa[m*j + i];
	mxDestroyArray(pa);
}

inline void load(CmatDoub_O a, Str_I varname, Mat mat)
{
	Long i, j, m, n;
	mxArray *pa = matGetVariable(mat.m_p, varname.c_str());
    if (!mxIsDouble(pa) || mxIsComplex(pa))
		SLS_ERR("'matfile: load(): wrong type!");
	const mwSize *sz = mxGetDimensions(pa);
	m = sz[0]; n = sz[1];
	a.resize(m, n);
    Doub *ppa = (Doub *)mxGetPr(pa);
    for (i = 0; i < m; ++i)
		for (j = 0; j < n; ++j)
			a(i,j) = ppa[m*j + i];
	mxDestroyArray(pa);
}

inline void load(CmatComp_O a, Str_I varname, Mat mat)
{
	Long i, j, m, n;
	mxArray *pa = matGetVariable(mat.m_p, varname.c_str());
    if (!mxIsDouble(pa))
		SLS_ERR("'matfile: load(): wrong type!");
	const mwSize *sz = mxGetDimensions(pa);
	m = sz[0]; n = sz[1];
	a.resize(m, n);
	Doub *ppar = mxGetPr(pa), *ppai = mxGetPi(pa);
    if (ppai)
		for (i = 0; i < m; ++i)
            for (j = 0; j < n; ++j){
                Long ind = i + m * j;
                a(i,j) = Comp(ppar[ind], ppai[ind]);
            }
	else
		for (i = 0; i < m; ++i)
            for (j = 0; j < n; ++j)
                a(i,j) = ppar[i + m*j];
	mxDestroyArray(pa);
}

inline void load(ScmatInt_O a, Str_I varname, Mat mat)
{
	Long i, j, m, n;
	mxArray *pa = matGetVariable(mat.m_p, varname.c_str());
    if (!mxIsInt32(pa))
		SLS_ERR("'matfile: load(): wrong type!");
	const mwSize *sz = mxGetDimensions(pa);
	m = sz[0]; n = sz[1];
	if (a.n0() != m || a.n1() != n) SLS_ERR("wrong size!");
    Int *ppa = (Int *)mxGetPr(pa);
    for (i = 0; i < m; ++i)
		for (j = 0; j < n; ++j)
			a(i,j) = ppa[m*j + i];
	mxDestroyArray(pa);
}

inline void load(ScmatLlong_O a, Str_I varname, Mat mat)
{
	Long i, j, m, n;
	mxArray *pa = matGetVariable(mat.m_p, varname.c_str());
	if (!mxIsInt64(pa))
		SLS_ERR("'matfile: load(): wrong type!");
	const mwSize *sz = mxGetDimensions(pa);
	m = sz[0]; n = sz[1];
	if (a.n0() != m || a.n1() != n) SLS_ERR("wrong size!");
    Llong *ppa = (Llong *)mxGetPr(pa);
    for (i = 0; i < m; ++i)
		for (j = 0; j < n; ++j)
			a(i,j) = ppa[m*j + i];
	mxDestroyArray(pa);
}

inline void load(ScmatDoub_O a, Str_I varname, Mat mat)
{
	Long i, j, m, n;
	mxArray *pa = matGetVariable(mat.m_p, varname.c_str());
    if (!mxIsDouble(pa) || mxIsComplex(pa))
		SLS_ERR("'matfile: load(): wrong type!");
	const mwSize *sz = mxGetDimensions(pa);
	m = sz[0]; n = sz[1];
	if (a.n0() != m || a.n1() != n) SLS_ERR("wrong size!");
    Doub *ppa = (Doub *)mxGetPr(pa);
    for (i = 0; i < m; ++i)
		for (j = 0; j < n; ++j)
			a(i,j) = ppa[m*j + i];
	mxDestroyArray(pa);
}

inline void load(ScmatComp_O a, Str_I varname, Mat mat)
{
	Long i, j, m, n;
	mxArray *pa = matGetVariable(mat.m_p, varname.c_str());
    if (!mxIsDouble(pa))
		SLS_ERR("'matfile: load(): wrong type!");
	const mwSize *sz = mxGetDimensions(pa);
	m = sz[0]; n = sz[1];
	if (a.n0() != m || a.n1() != n) SLS_ERR("wrong size!");
	Doub *ppar = mxGetPr(pa), *ppai = mxGetPi(pa);
    if (ppai)
		for (i = 0; i < m; ++i)
            for (j = 0; j < n; ++j){
                Long ind = i + m * j;
                a(i,j) = Comp(ppar[ind], ppai[ind]);
            }
	else
		for (i = 0; i < m; ++i)
            for (j = 0; j < n; ++j)
                a(i,j) = ppar[i + m*j];
	mxDestroyArray(pa);
}

inline void load(DcmatInt_O a, Str_I varname, Mat mat)
{
	Long i, j, m, n;
	mxArray *pa = matGetVariable(mat.m_p, varname.c_str());
    if (!mxIsInt32(pa))
		SLS_ERR("'matfile: load(): wrong type!");
	const mwSize *sz = mxGetDimensions(pa);
	m = sz[0]; n = sz[1];
	if (a.n0() != m || a.n1() != n) SLS_ERR("wrong size!");
    Int *ppa = (Int *)mxGetPr(pa);
    for (i = 0; i < m; ++i)
		for (j = 0; j < n; ++j)
			a(i,j) = ppa[m*j + i];
	mxDestroyArray(pa);
}

inline void load(DcmatLlong_O a, Str_I varname, Mat mat)
{
	Long i, j, m, n;
	mxArray *pa = matGetVariable(mat.m_p, varname.c_str());
	if (!mxIsInt64(pa))
		SLS_ERR("'matfile: load(): wrong type!");
	const mwSize *sz = mxGetDimensions(pa);
	m = sz[0]; n = sz[1];
	if (a.n0() != m || a.n1() != n) SLS_ERR("wrong size!");
    Llong *ppa = (Llong *)mxGetPr(pa);
    for (i = 0; i < m; ++i)
		for (j = 0; j < n; ++j)
			a(i,j) = ppa[m*j + i];
	mxDestroyArray(pa);
}

inline void load(DcmatDoub_O a, Str_I varname, Mat mat)
{
	Long i, j, m, n;
	mxArray *pa = matGetVariable(mat.m_p, varname.c_str());
    if (!mxIsDouble(pa) || mxIsComplex(pa))
		SLS_ERR("'matfile: load(): wrong type!");
	const mwSize *sz = mxGetDimensions(pa);
	m = sz[0]; n = sz[1];
	if (a.n0() != m || a.n1() != n) SLS_ERR("wrong size!");
    Doub *ppa = (Doub *)mxGetPr(pa);
    for (i = 0; i < m; ++i)
		for (j = 0; j < n; ++j)
			a(i,j) = ppa[m*j + i];
	mxDestroyArray(pa);
}

inline void load(DcmatComp_O a, Str_I varname, Mat mat)
{
	Long i, j, m, n;
	mxArray *pa = matGetVariable(mat.m_p, varname.c_str());
    if (!mxIsDouble(pa))
		SLS_ERR("'matfile: load(): wrong type!");
	const mwSize *sz = mxGetDimensions(pa);
	m = sz[0]; n = sz[1];
	if (a.n0() != m || a.n1() != n) SLS_ERR("wrong size!");
	Doub *ppar = mxGetPr(pa), *ppai = mxGetPi(pa);
    if (ppai)
		for (i = 0; i < m; ++i)
            for (j = 0; j < n; ++j){
                Long ind = i + m * j;
                a(i,j) = Comp(ppar[ind], ppai[ind]);
            }
	else
		for (i = 0; i < m; ++i)
            for (j = 0; j < n; ++j)
                a(i,j) = ppar[i + m*j];
	mxDestroyArray(pa);
}


inline void load(Cmat3Llong_O a, Str_I varname, Mat mat)
{
	Long i, j, k, m, n, q, mn;
	mxArray *pa = matGetVariable(mat.m_p, varname.c_str());
	if (!mxIsInt64(pa))
		SLS_ERR("'matfile: load(): wrong type!");
	const mwSize *sz = mxGetDimensions(pa);
	m = sz[0]; n = sz[1]; q = sz[2]; mn = m*n;
	a.resize(m, n, q);
    Llong *ppa = (Llong *)mxGetPr(pa);
	for (i = 0; i < m; ++i)
	    for (j = 0; j < n; ++j)
    	    for (k = 0; k < q; ++k)
	        	a(i,j,k) = ppa[i + m*j + mn*k];
	mxDestroyArray(pa);
}

inline void load(Cmat3Doub_O a, Str_I varname, Mat mat)
{
	Long i, j, k, m, n, q, mn;
	mxArray *pa = matGetVariable(mat.m_p, varname.c_str());
	if (!mxIsDouble(pa) || mxIsComplex(pa))
		SLS_ERR("'matfile: load(): wrong type!");
	const mwSize *sz = mxGetDimensions(pa);
	m = sz[0]; n = sz[1]; q = sz[2]; mn = m*n;
	a.resize(m, n, q);
    Doub *ppa = (Doub *)mxGetPr(pa);
	for (i = 0; i < m; ++i)
	    for (j = 0; j < n; ++j)
    	    for (k = 0; k < q; ++k)
	        	a(i,j,k) = ppa[i + m*j + mn*k];
	mxDestroyArray(pa);
}

inline void load(Cmat3Comp_O a, Str_I varname, Mat mat)
{
	Long i, j, k, m, n, q, mn;
	mxArray *pa = matGetVariable(mat.m_p, varname.c_str());
    if (!mxIsDouble(pa))
		SLS_ERR("'matfile: load(): wrong type!");
	const mwSize *sz = mxGetDimensions(pa);
	m = sz[0]; n = sz[1]; q = sz[2]; mn = m*n;
	a.resize(m, n, q);
    Doub *ppar = mxGetPr(pa), *ppai = mxGetPi(pa);
	if (ppai)
		for (i = 0; i < m; ++i)
		    for (j = 0; j < n; ++j)
		        for (k = 0; k < q; ++k){
			        Long ind = i + m*j + mn*k;
			        a(i,j,k) = Comp(ppar[ind], ppai[ind]);
		}
	else
		for (i = 0; i < m; ++i)
		    for (j = 0; j < n; ++j)
		        for (k = 0; k < q; ++k)
			        a(i,j,k) = ppar[i + m*j + mn*k];
	mxDestroyArray(pa);
}


} // namespace slisc
#endif
