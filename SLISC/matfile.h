// save SLISC containers to Matlab ".mat" files.
// see README.txt for details

#pragma once
#include "arithmetic.h"
#include <mat.h>

namespace slisc {

typedef MATFile *Mat;

inline void save(Uchar_I s, Str_I varname, Mat pfile)
{
	mxArray *ps;
	ps = mxCreateNumericMatrix(1, 1, mxUINT8_CLASS, mxREAL);
	Uchar *pps = (Uchar*)mxGetPr(ps);
	pps[0] = s;
	matPutVariable(pfile, varname.c_str(), ps);
	mxDestroyArray(ps);
}

inline void save(Int_I s, Str_I varname, Mat pfile)
{
	mxArray *ps;
    ps = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
	Int *pps = (Int*)mxGetPr(ps);
	pps[0] = s;
	matPutVariable(pfile, varname.c_str(), ps);
	mxDestroyArray(ps);
}

inline void save(Llong_I s, Str_I varname, Mat pfile)
{
	mxArray *ps;
    ps = mxCreateNumericMatrix(1, 1, mxINT64_CLASS, mxREAL);
	Llong *pps = (Llong*)mxGetPr(ps);
	pps[0] = s;
	matPutVariable(pfile, varname.c_str(), ps);
	mxDestroyArray(ps);
}

inline void save(Doub_I s, Str_I varname, Mat pfile)
{
	mxArray *ps;
    ps = mxCreateDoubleMatrix(1, 1, mxREAL);
	Doub *pps = (Doub*)mxGetPr(ps);
	pps[0] = s;
	matPutVariable(pfile, varname.c_str(), ps);
	mxDestroyArray(ps);
}

inline void save(Comp_I s, Str_I varname, Mat pfile)
{
	mxArray *ps;
    ps = mxCreateDoubleMatrix(1, 1, mxCOMPLEX);
    Doub *pps = mxGetPr(ps);
	pps[0] = real(s);
	pps = mxGetPi(ps);
	pps[0] = imag(s);
	matPutVariable(pfile, varname.c_str(), ps);
	mxDestroyArray(ps);
}



inline void save(VecUchar_I v, Str_I varname, Mat pfile)
{
	Long i, n;
	mxArray *pv;
	n = v.size();
	pv = mxCreateUninitNumericMatrix(1, n, mxUINT8_CLASS, mxREAL);
	Uchar *ppv = (Uchar*)mxGetPr(pv);
	for (i = 0; i < n; ++i)
		ppv[i] = v[i];
	matPutVariable(pfile, varname.c_str(), pv);
	mxDestroyArray(pv);
}

inline void save(VecInt_I v, Str_I varname, Mat pfile)
{
	Long i, n;
	mxArray *pv;
	n = v.size();
    pv = mxCreateUninitNumericMatrix(1, n, mxINT32_CLASS, mxREAL);
	Int *ppv = (Int*)mxGetPr(pv);
	for (i = 0; i < n; ++i)
		ppv[i] = v[i];
	matPutVariable(pfile, varname.c_str(), pv);
	mxDestroyArray(pv);
}

inline void save(VecDoub_I v, Str_I varname, Mat pfile)
{
	Long i, n;
	mxArray *pv;
	n = v.size();
    pv = mxCreateUninitNumericMatrix(1, n, mxDOUBLE_CLASS, mxREAL);
	Doub *ppv = (Doub*)mxGetPr(pv);
	for (i = 0; i < n; ++i)
		ppv[i] = v[i];
	matPutVariable(pfile, varname.c_str(), pv);
	mxDestroyArray(pv);
}

inline void save(VecComp_I v, Str_I varname, Mat pfile)
{
	Long i, n;
	mxArray *pv;
	n = v.size();
    pv = mxCreateUninitNumericMatrix(1, n, mxDOUBLE_CLASS, mxCOMPLEX);
    auto ppvr = mxGetPr(pv);
	auto ppvi = mxGetPi(pv);
	for (i = 0; i < n; ++i) {
		ppvr[i] = real(v[i]);
		ppvi[i] = imag(v[i]);
	}
	matPutVariable(pfile, varname.c_str(), pv);
	mxDestroyArray(pv);
}


inline void save(MatUchar_I a, Str_I varname, Mat pfile)
{
	Long i, j, m, n;
	mxArray *pa;
	m = a.n0(); n = a.n1();
	pa = mxCreateUninitNumericMatrix(m, n, mxUINT8_CLASS, mxREAL);
    Uchar *ppa = (Uchar*)mxGetPr(pa);
        for (i = 0; i < m; ++i)
            for (j = 0; j < n; ++j)
                ppa[i + m * j] = a(i,j);
	matPutVariable(pfile, varname.c_str(), pa);
	mxDestroyArray(pa);
}

inline void save(MatInt_I a, Str_I varname, Mat pfile)
{
	Long i, j, m, n;
	mxArray *pa;
	m = a.n0(); n = a.n1();
    pa = mxCreateUninitNumericMatrix(m, n, mxINT32_CLASS, mxREAL);
    Int *ppa = (Int*)mxGetPr(pa);
        for (i = 0; i < m; ++i)
            for (j = 0; j < n; ++j)
                ppa[i + m * j] = a(i,j);
	matPutVariable(pfile, varname.c_str(), pa);
	mxDestroyArray(pa);
}

inline void save(MatDoub_I a, Str_I varname, Mat pfile)
{
	Long i, j, m, n;
	mxArray *pa;
	m = a.n0(); n = a.n1();
    pa = mxCreateUninitNumericMatrix(m, n, mxDOUBLE_CLASS, mxREAL);
    Doub *ppa = (Doub*)mxGetPr(pa);
        for (i = 0; i < m; ++i)
            for (j = 0; j < n; ++j)
                ppa[i + m * j] = a(i,j);
	matPutVariable(pfile, varname.c_str(), pa);
	mxDestroyArray(pa);
}

inline void save(MatComp_I a, Str_I varname, Mat pfile)
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
	matPutVariable(pfile, varname.c_str(), pa);
	mxDestroyArray(pa);
}

inline void save(CmatUchar_I a, Str_I varname, Mat pfile)
{
	Long i, j, m, n;
	mxArray *pa;
	m = a.n0(); n = a.n1();
	pa = mxCreateUninitNumericMatrix(m, n, mxUINT8_CLASS, mxREAL);
    Uchar *ppa = (Uchar*)mxGetPr(pa);
        for (i = 0; i < m; ++i)
            for (j = 0; j < n; ++j)
                ppa[i + m * j] = a(i,j);
	matPutVariable(pfile, varname.c_str(), pa);
	mxDestroyArray(pa);
}

inline void save(CmatInt_I a, Str_I varname, Mat pfile)
{
	Long i, j, m, n;
	mxArray *pa;
	m = a.n0(); n = a.n1();
    pa = mxCreateUninitNumericMatrix(m, n, mxINT32_CLASS, mxREAL);
    Int *ppa = (Int*)mxGetPr(pa);
        for (i = 0; i < m; ++i)
            for (j = 0; j < n; ++j)
                ppa[i + m * j] = a(i,j);
	matPutVariable(pfile, varname.c_str(), pa);
	mxDestroyArray(pa);
}

inline void save(CmatDoub_I a, Str_I varname, Mat pfile)
{
	Long i, j, m, n;
	mxArray *pa;
	m = a.n0(); n = a.n1();
    pa = mxCreateUninitNumericMatrix(m, n, mxDOUBLE_CLASS, mxREAL);
    Doub *ppa = (Doub*)mxGetPr(pa);
        for (i = 0; i < m; ++i)
            for (j = 0; j < n; ++j)
                ppa[i + m * j] = a(i,j);
	matPutVariable(pfile, varname.c_str(), pa);
	mxDestroyArray(pa);
}

inline void save(CmatComp_I a, Str_I varname, Mat pfile)
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
	matPutVariable(pfile, varname.c_str(), pa);
	mxDestroyArray(pa);
}

inline void save(ScmatUchar_I a, Str_I varname, Mat pfile)
{
	Long i, j, m, n;
	mxArray *pa;
	m = a.n0(); n = a.n1();
	pa = mxCreateUninitNumericMatrix(m, n, mxUINT8_CLASS, mxREAL);
    Uchar *ppa = (Uchar*)mxGetPr(pa);
        for (i = 0; i < m; ++i)
            for (j = 0; j < n; ++j)
                ppa[i + m * j] = a(i,j);
	matPutVariable(pfile, varname.c_str(), pa);
	mxDestroyArray(pa);
}

inline void save(ScmatInt_I a, Str_I varname, Mat pfile)
{
	Long i, j, m, n;
	mxArray *pa;
	m = a.n0(); n = a.n1();
    pa = mxCreateUninitNumericMatrix(m, n, mxINT32_CLASS, mxREAL);
    Int *ppa = (Int*)mxGetPr(pa);
        for (i = 0; i < m; ++i)
            for (j = 0; j < n; ++j)
                ppa[i + m * j] = a(i,j);
	matPutVariable(pfile, varname.c_str(), pa);
	mxDestroyArray(pa);
}

inline void save(ScmatDoub_I a, Str_I varname, Mat pfile)
{
	Long i, j, m, n;
	mxArray *pa;
	m = a.n0(); n = a.n1();
    pa = mxCreateUninitNumericMatrix(m, n, mxDOUBLE_CLASS, mxREAL);
    Doub *ppa = (Doub*)mxGetPr(pa);
        for (i = 0; i < m; ++i)
            for (j = 0; j < n; ++j)
                ppa[i + m * j] = a(i,j);
	matPutVariable(pfile, varname.c_str(), pa);
	mxDestroyArray(pa);
}

inline void save(ScmatComp_I a, Str_I varname, Mat pfile)
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
	matPutVariable(pfile, varname.c_str(), pa);
	mxDestroyArray(pa);
}


inline void save(Mat3Doub_I a, Str_I varname, Mat pfile)
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
                    ppa[i + m * j + mn * k] = a(i,j,k);
	matPutVariable(pfile, varname.c_str(), pa);
	mxDestroyArray(pa);
}

inline void save(Mat3Comp_I a, Str_I varname, Mat pfile)
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
	matPutVariable(pfile, varname.c_str(), pa);
	mxDestroyArray(pa);
}


inline void load(Uchar_O s, Str_I varname, Mat pfile)
{
	mxArray *ps;
    ps = matGetVariable(pfile, varname.c_str());
    if (!mxIsUint8(ps))
        SLS_ERR("'matfile: load(): wrong type!");
    Uchar *pps = (Uchar *)mxGetPr(ps);
	s = pps[0];
	mxDestroyArray(ps);
}

inline void load(Int_O s, Str_I varname, Mat pfile)
{
	mxArray *ps;
    ps = matGetVariable(pfile, varname.c_str());
	if (!mxIsInt32(ps))
        SLS_ERR("'matfile: load(): wrong type!");
    Int *pps = (Int *)mxGetPr(ps);
	s = pps[0];
	mxDestroyArray(ps);
}

inline void load(Doub_O s, Str_I varname, Mat pfile)
{
	mxArray *ps;
    ps = matGetVariable(pfile, varname.c_str());
    if (!mxIsDouble(ps) || mxIsComplex(ps))
        SLS_ERR("'matfile: load(): wrong type!");
    Doub *pps = (Doub *)mxGetPr(ps);
	s = pps[0];
	mxDestroyArray(ps);
}

inline void load(Comp_O s, Str_I varname, Mat pfile)
{
	mxArray *ps;
    ps = matGetVariable(pfile, varname.c_str());
    if (!mxIsDouble(ps))
        SLS_ERR("'matfile: load(): wrong type!");
    Doub *ppsr = mxGetPr(ps), *ppsi = mxGetPi(ps);
    s = ppsi ? Comp(ppsr[0], ppsi[0]) : ppsr[0];
	mxDestroyArray(ps);
}


inline void load(VecUchar_O v, Str_I varname, Mat pfile)
{
	Long i, n;
	mxArray *pv;
    pv = matGetVariable(pfile, varname.c_str());
    if (!mxIsUint8(pv))
        SLS_ERR("'matfile: load(): wrong type!");
    n = mxGetDimensions(pv)[1];
	v.resize(n);
	Uchar *ppv = (Uchar *)mxGetPr(pv);
	for (i = 0; i < n; ++i)
		v[i] = ppv[i];
	mxDestroyArray(pv);
}

inline void load(VecInt_O v, Str_I varname, Mat pfile)
{
	Long i, n;
	mxArray *pv;
    pv = matGetVariable(pfile, varname.c_str());
    if (!mxIsInt32(pv))
        SLS_ERR("'matfile: load(): wrong type!");
    n = mxGetDimensions(pv)[1];
	v.resize(n);
	Int *ppv = (Int *)mxGetPr(pv);
	for (i = 0; i < n; ++i)
		v[i] = ppv[i];
	mxDestroyArray(pv);
}

inline void load(VecDoub_O v, Str_I varname, Mat pfile)
{
	Long i, n;
	mxArray *pv;
    pv = matGetVariable(pfile, varname.c_str());
    if (!mxIsDouble(pv) || mxIsComplex(pv))
        SLS_ERR("'matfile: load(): wrong type!");
    n = mxGetDimensions(pv)[1];
	v.resize(n);
	Doub *ppv = (Doub *)mxGetPr(pv);
	for (i = 0; i < n; ++i)
		v[i] = ppv[i];
	mxDestroyArray(pv);
}

inline void load(VecComp_O v, Str_I varname, Mat pfile)
{
	Long i, n;
	mxArray *pv;
    pv = matGetVariable(pfile, varname.c_str());
    if (!mxIsDouble(pv))
        SLS_ERR("'matfile: load(): wrong type!");
    Doub *ppvr = mxGetPr(pv), *ppvi = mxGetPi(pv);
	if (ppvi)
		for (i = 0; i < n; ++i)
			v[i] = Comp(ppvr[i], ppvi[i]);
	else
		for (i = 0; i < n; ++i)
			v[i] = ppvr[i];
	mxDestroyArray(pv);
}


inline void load(MatUchar_O &a, Str_I varname, Mat pfile)
{
	Long i, j, m, n;
	mxArray *pa = matGetVariable(pfile, varname.c_str());
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

inline void load(MatInt_O &a, Str_I varname, Mat pfile)
{
	Long i, j, m, n;
	mxArray *pa = matGetVariable(pfile, varname.c_str());
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

inline void load(MatDoub_O &a, Str_I varname, Mat pfile)
{
	Long i, j, m, n;
	mxArray *pa = matGetVariable(pfile, varname.c_str());
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

inline void load(MatComp_O &a, Str_I varname, Mat pfile)
{
	Long i, j, m, n;
	mxArray *pa = matGetVariable(pfile, varname.c_str());
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


inline void load(Mat3Doub_O &a, Str_I varname, Mat pfile)
{
	Long i, j, k, m, n, q, mn;
	mxArray *pa = matGetVariable(pfile, varname.c_str());
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

inline void load(Mat3Comp_O &a, Str_I varname, Mat pfile)
{
	Long i, j, k, m, n, q, mn;
	mxArray *pa = matGetVariable(pfile, varname.c_str());
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
