inline void save(Char_I s, Str_I varname, Matt_IO matt)
{
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open: " + matt.fname);
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
    // write variable name info
    Long n = varname.size();
    fout << n << Matt::dlm;
    for (Long i = 0; i < n; ++i) {
        fout << to_num(varname.at(i)) << Matt::dlm;
    }
    // write data type info
    fout << 1 << Matt::dlm;
    // write dimension info
    fout << 0 << Matt::dlm;
    // write matrix data
	matt_write_scalar(s, fout);
}

inline void save(Char_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

inline void save(Int_I s, Str_I varname, Matt_IO matt)
{
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open: " + matt.fname);
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
    // write variable name info
    Long n = varname.size();
    fout << n << Matt::dlm;
    for (Long i = 0; i < n; ++i) {
        fout << to_num(varname.at(i)) << Matt::dlm;
    }
    // write data type info
    fout << 2 << Matt::dlm;
    // write dimension info
    fout << 0 << Matt::dlm;
    // write matrix data
	matt_write_scalar(s, fout);
}

inline void save(Int_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

inline void save(Llong_I s, Str_I varname, Matt_IO matt)
{
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open: " + matt.fname);
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
    // write variable name info
    Long n = varname.size();
    fout << n << Matt::dlm;
    for (Long i = 0; i < n; ++i) {
        fout << to_num(varname.at(i)) << Matt::dlm;
    }
    // write data type info
    fout << 3 << Matt::dlm;
    // write dimension info
    fout << 0 << Matt::dlm;
    // write matrix data
	matt_write_scalar(s, fout);
}

inline void save(Llong_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

inline void save(Doub_I s, Str_I varname, Matt_IO matt)
{
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open: " + matt.fname);
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
    // write variable name info
    Long n = varname.size();
    fout << n << Matt::dlm;
    for (Long i = 0; i < n; ++i) {
        fout << to_num(varname.at(i)) << Matt::dlm;
    }
    // write data type info
    fout << 21 << Matt::dlm;
    // write dimension info
    fout << 0 << Matt::dlm;
    // write matrix data
	matt_write_scalar(s, fout);
}

inline void save(Doub_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

inline void save(Comp_I s, Str_I varname, Matt_IO matt)
{
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open: " + matt.fname);
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
    // write variable name info
    Long n = varname.size();
    fout << n << Matt::dlm;
    for (Long i = 0; i < n; ++i) {
        fout << to_num(varname.at(i)) << Matt::dlm;
    }
    // write data type info
    fout << 41 << Matt::dlm;
    // write dimension info
    fout << 0 << Matt::dlm;
    // write matrix data
	matt_write_scalar(s, fout);
}

inline void save(Comp_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

inline void save(VecChar_I v, Str_I varname, Matt_IO matt)
{
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open!");
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
    // write variable name info
    Long n = varname.size();
    fout << n << Matt::dlm;
    for (Long i = 0; i < n; ++i) {
        fout << to_num(varname.at(i)) << Matt::dlm;
    }
    // write data type info
    fout << 1 << Matt::dlm;
    // write dimension info
    n = v.size();
    fout << 1 << Matt::dlm << n << Matt::dlm;
    // write matrix data
    for (Long i = 0; i < n; ++i)
		matt_write_scalar(v[i], fout);
}

inline void save(VecChar_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

inline void save(VecInt_I v, Str_I varname, Matt_IO matt)
{
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open!");
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
    // write variable name info
    Long n = varname.size();
    fout << n << Matt::dlm;
    for (Long i = 0; i < n; ++i) {
        fout << to_num(varname.at(i)) << Matt::dlm;
    }
    // write data type info
    fout << 2 << Matt::dlm;
    // write dimension info
    n = v.size();
    fout << 1 << Matt::dlm << n << Matt::dlm;
    // write matrix data
    for (Long i = 0; i < n; ++i)
		matt_write_scalar(v[i], fout);
}

inline void save(VecInt_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

inline void save(VecDoub_I v, Str_I varname, Matt_IO matt)
{
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open!");
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
    // write variable name info
    Long n = varname.size();
    fout << n << Matt::dlm;
    for (Long i = 0; i < n; ++i) {
        fout << to_num(varname.at(i)) << Matt::dlm;
    }
    // write data type info
    fout << 21 << Matt::dlm;
    // write dimension info
    n = v.size();
    fout << 1 << Matt::dlm << n << Matt::dlm;
    // write matrix data
    for (Long i = 0; i < n; ++i)
		matt_write_scalar(v[i], fout);
}

inline void save(VecDoub_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

inline void save(VecComp_I v, Str_I varname, Matt_IO matt)
{
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open!");
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
    // write variable name info
    Long n = varname.size();
    fout << n << Matt::dlm;
    for (Long i = 0; i < n; ++i) {
        fout << to_num(varname.at(i)) << Matt::dlm;
    }
    // write data type info
    fout << 41 << Matt::dlm;
    // write dimension info
    n = v.size();
    fout << 1 << Matt::dlm << n << Matt::dlm;
    // write matrix data
    for (Long i = 0; i < n; ++i)
		matt_write_scalar(v[i], fout);
}

inline void save(VecComp_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

inline void save(SvecChar_I v, Str_I varname, Matt_IO matt)
{
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open!");
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
    // write variable name info
    Long n = varname.size();
    fout << n << Matt::dlm;
    for (Long i = 0; i < n; ++i) {
        fout << to_num(varname.at(i)) << Matt::dlm;
    }
    // write data type info
    fout << 1 << Matt::dlm;
    // write dimension info
    n = v.size();
    fout << 1 << Matt::dlm << n << Matt::dlm;
    // write matrix data
    for (Long i = 0; i < n; ++i)
		matt_write_scalar(v[i], fout);
}

inline void save(SvecChar_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

inline void save(SvecInt_I v, Str_I varname, Matt_IO matt)
{
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open!");
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
    // write variable name info
    Long n = varname.size();
    fout << n << Matt::dlm;
    for (Long i = 0; i < n; ++i) {
        fout << to_num(varname.at(i)) << Matt::dlm;
    }
    // write data type info
    fout << 2 << Matt::dlm;
    // write dimension info
    n = v.size();
    fout << 1 << Matt::dlm << n << Matt::dlm;
    // write matrix data
    for (Long i = 0; i < n; ++i)
		matt_write_scalar(v[i], fout);
}

inline void save(SvecInt_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

inline void save(SvecLlong_I v, Str_I varname, Matt_IO matt)
{
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open!");
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
    // write variable name info
    Long n = varname.size();
    fout << n << Matt::dlm;
    for (Long i = 0; i < n; ++i) {
        fout << to_num(varname.at(i)) << Matt::dlm;
    }
    // write data type info
    fout << 3 << Matt::dlm;
    // write dimension info
    n = v.size();
    fout << 1 << Matt::dlm << n << Matt::dlm;
    // write matrix data
    for (Long i = 0; i < n; ++i)
		matt_write_scalar(v[i], fout);
}

inline void save(SvecLlong_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

inline void save(SvecDoub_I v, Str_I varname, Matt_IO matt)
{
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open!");
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
    // write variable name info
    Long n = varname.size();
    fout << n << Matt::dlm;
    for (Long i = 0; i < n; ++i) {
        fout << to_num(varname.at(i)) << Matt::dlm;
    }
    // write data type info
    fout << 21 << Matt::dlm;
    // write dimension info
    n = v.size();
    fout << 1 << Matt::dlm << n << Matt::dlm;
    // write matrix data
    for (Long i = 0; i < n; ++i)
		matt_write_scalar(v[i], fout);
}

inline void save(SvecDoub_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

inline void save(SvecComp_I v, Str_I varname, Matt_IO matt)
{
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open!");
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
    // write variable name info
    Long n = varname.size();
    fout << n << Matt::dlm;
    for (Long i = 0; i < n; ++i) {
        fout << to_num(varname.at(i)) << Matt::dlm;
    }
    // write data type info
    fout << 41 << Matt::dlm;
    // write dimension info
    n = v.size();
    fout << 1 << Matt::dlm << n << Matt::dlm;
    // write matrix data
    for (Long i = 0; i < n; ++i)
		matt_write_scalar(v[i], fout);
}

inline void save(SvecComp_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

inline void save(MatInt_I a, Str_I varname, Matt_IO matt)
{
    Long N1 = a.n1(), N2 = a.n2();
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open!");
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
    // write variable name info
    Long n = varname.size();
    fout << n << Matt::dlm;
    for (Long i = 0; i < n; ++i)
        fout << to_num(varname.at(i)) << Matt::dlm;
    // write data type info
    fout << 2 << Matt::dlm;
    // write dimension info
    fout << 2 << Matt::dlm << N1 << Matt::dlm << N2 << Matt::dlm;
    // write matrix data
    for (Long j = 0; j < N2; ++j)
        for (Long i = 0; i < N1; ++i)
            matt_write_scalar(a(i, j), fout);
}

inline void save(MatInt_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

inline void save(MatLlong_I a, Str_I varname, Matt_IO matt)
{
    Long N1 = a.n1(), N2 = a.n2();
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open!");
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
    // write variable name info
    Long n = varname.size();
    fout << n << Matt::dlm;
    for (Long i = 0; i < n; ++i)
        fout << to_num(varname.at(i)) << Matt::dlm;
    // write data type info
    fout << 3 << Matt::dlm;
    // write dimension info
    fout << 2 << Matt::dlm << N1 << Matt::dlm << N2 << Matt::dlm;
    // write matrix data
    for (Long j = 0; j < N2; ++j)
        for (Long i = 0; i < N1; ++i)
            matt_write_scalar(a(i, j), fout);
}

inline void save(MatLlong_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

inline void save(MatDoub_I a, Str_I varname, Matt_IO matt)
{
    Long N1 = a.n1(), N2 = a.n2();
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open!");
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
    // write variable name info
    Long n = varname.size();
    fout << n << Matt::dlm;
    for (Long i = 0; i < n; ++i)
        fout << to_num(varname.at(i)) << Matt::dlm;
    // write data type info
    fout << 21 << Matt::dlm;
    // write dimension info
    fout << 2 << Matt::dlm << N1 << Matt::dlm << N2 << Matt::dlm;
    // write matrix data
    for (Long j = 0; j < N2; ++j)
        for (Long i = 0; i < N1; ++i)
            matt_write_scalar(a(i, j), fout);
}

inline void save(MatDoub_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

inline void save(MatComp_I a, Str_I varname, Matt_IO matt)
{
    Long N1 = a.n1(), N2 = a.n2();
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open!");
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
    // write variable name info
    Long n = varname.size();
    fout << n << Matt::dlm;
    for (Long i = 0; i < n; ++i)
        fout << to_num(varname.at(i)) << Matt::dlm;
    // write data type info
    fout << 41 << Matt::dlm;
    // write dimension info
    fout << 2 << Matt::dlm << N1 << Matt::dlm << N2 << Matt::dlm;
    // write matrix data
    for (Long j = 0; j < N2; ++j)
        for (Long i = 0; i < N1; ++i)
            matt_write_scalar(a(i, j), fout);
}

inline void save(MatComp_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

inline void save(CmatInt_I a, Str_I varname, Matt_IO matt)
{
    Long N1 = a.n1(), N2 = a.n2();
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open!");
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
    // write variable name info
    Long n = varname.size();
    fout << n << Matt::dlm;
    for (Long i = 0; i < n; ++i)
        fout << to_num(varname.at(i)) << Matt::dlm;
    // write data type info
    fout << 2 << Matt::dlm;
    // write dimension info
    fout << 2 << Matt::dlm << N1 << Matt::dlm << N2 << Matt::dlm;
    // write matrix data
    for (Long j = 0; j < N2; ++j)
        for (Long i = 0; i < N1; ++i)
            matt_write_scalar(a(i, j), fout);
}

inline void save(CmatInt_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

inline void save(CmatLlong_I a, Str_I varname, Matt_IO matt)
{
    Long N1 = a.n1(), N2 = a.n2();
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open!");
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
    // write variable name info
    Long n = varname.size();
    fout << n << Matt::dlm;
    for (Long i = 0; i < n; ++i)
        fout << to_num(varname.at(i)) << Matt::dlm;
    // write data type info
    fout << 3 << Matt::dlm;
    // write dimension info
    fout << 2 << Matt::dlm << N1 << Matt::dlm << N2 << Matt::dlm;
    // write matrix data
    for (Long j = 0; j < N2; ++j)
        for (Long i = 0; i < N1; ++i)
            matt_write_scalar(a(i, j), fout);
}

inline void save(CmatLlong_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

inline void save(CmatDoub_I a, Str_I varname, Matt_IO matt)
{
    Long N1 = a.n1(), N2 = a.n2();
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open!");
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
    // write variable name info
    Long n = varname.size();
    fout << n << Matt::dlm;
    for (Long i = 0; i < n; ++i)
        fout << to_num(varname.at(i)) << Matt::dlm;
    // write data type info
    fout << 21 << Matt::dlm;
    // write dimension info
    fout << 2 << Matt::dlm << N1 << Matt::dlm << N2 << Matt::dlm;
    // write matrix data
    for (Long j = 0; j < N2; ++j)
        for (Long i = 0; i < N1; ++i)
            matt_write_scalar(a(i, j), fout);
}

inline void save(CmatDoub_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

inline void save(CmatComp_I a, Str_I varname, Matt_IO matt)
{
    Long N1 = a.n1(), N2 = a.n2();
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open!");
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
    // write variable name info
    Long n = varname.size();
    fout << n << Matt::dlm;
    for (Long i = 0; i < n; ++i)
        fout << to_num(varname.at(i)) << Matt::dlm;
    // write data type info
    fout << 41 << Matt::dlm;
    // write dimension info
    fout << 2 << Matt::dlm << N1 << Matt::dlm << N2 << Matt::dlm;
    // write matrix data
    for (Long j = 0; j < N2; ++j)
        for (Long i = 0; i < N1; ++i)
            matt_write_scalar(a(i, j), fout);
}

inline void save(CmatComp_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

inline void save(Cmat3Int_I a, Str_I varname, Matt_IO matt)
{
    Long i, j, k, N1 = a.n1(), N2 = a.n2(), N3 = a.n3();
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open!");
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
    // write variable name info
    Long n = varname.size();
    fout << n << Matt::dlm;
    for (i = 0; i < n; ++i) {
        fout << to_num(varname.at(i)) << Matt::dlm;
    }
    // write data type info
    fout << 2 << Matt::dlm;
    // write dimension info
    fout << 3 << Matt::dlm << N1 << Matt::dlm << N2 << Matt::dlm << N3 << Matt::dlm;
    // write matrix data
    for (k = 0; k < N3; ++k)
    	for (j = 0; j < N2; ++j)
    		for (i = 0; i < N1; ++i)
        		matt_write_scalar(a(i, j, k), fout);
}

inline void save(Cmat3Int_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

inline void save(Cmat3Llong_I a, Str_I varname, Matt_IO matt)
{
    Long i, j, k, N1 = a.n1(), N2 = a.n2(), N3 = a.n3();
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open!");
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
    // write variable name info
    Long n = varname.size();
    fout << n << Matt::dlm;
    for (i = 0; i < n; ++i) {
        fout << to_num(varname.at(i)) << Matt::dlm;
    }
    // write data type info
    fout << 3 << Matt::dlm;
    // write dimension info
    fout << 3 << Matt::dlm << N1 << Matt::dlm << N2 << Matt::dlm << N3 << Matt::dlm;
    // write matrix data
    for (k = 0; k < N3; ++k)
    	for (j = 0; j < N2; ++j)
    		for (i = 0; i < N1; ++i)
        		matt_write_scalar(a(i, j, k), fout);
}

inline void save(Cmat3Llong_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

inline void save(Cmat3Doub_I a, Str_I varname, Matt_IO matt)
{
    Long i, j, k, N1 = a.n1(), N2 = a.n2(), N3 = a.n3();
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open!");
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
    // write variable name info
    Long n = varname.size();
    fout << n << Matt::dlm;
    for (i = 0; i < n; ++i) {
        fout << to_num(varname.at(i)) << Matt::dlm;
    }
    // write data type info
    fout << 21 << Matt::dlm;
    // write dimension info
    fout << 3 << Matt::dlm << N1 << Matt::dlm << N2 << Matt::dlm << N3 << Matt::dlm;
    // write matrix data
    for (k = 0; k < N3; ++k)
    	for (j = 0; j < N2; ++j)
    		for (i = 0; i < N1; ++i)
        		matt_write_scalar(a(i, j, k), fout);
}

inline void save(Cmat3Doub_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

inline void save(Cmat3Comp_I a, Str_I varname, Matt_IO matt)
{
    Long i, j, k, N1 = a.n1(), N2 = a.n2(), N3 = a.n3();
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open!");
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
    // write variable name info
    Long n = varname.size();
    fout << n << Matt::dlm;
    for (i = 0; i < n; ++i) {
        fout << to_num(varname.at(i)) << Matt::dlm;
    }
    // write data type info
    fout << 41 << Matt::dlm;
    // write dimension info
    fout << 3 << Matt::dlm << N1 << Matt::dlm << N2 << Matt::dlm << N3 << Matt::dlm;
    // write matrix data
    for (k = 0; k < N3; ++k)
    	for (j = 0; j < N2; ++j)
    		for (i = 0; i < N1; ++i)
        		matt_write_scalar(a(i, j, k), fout);
}

inline void save(Cmat3Comp_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

inline void save(ScmatInt_I a, Str_I varname, Matt_IO matt)
{
    Long N1 = a.n1(), N2 = a.n2();
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open!");
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
    // write variable name info
    Long n = varname.size();
    fout << n << Matt::dlm;
    for (Long i = 0; i < n; ++i)
        fout << to_num(varname.at(i)) << Matt::dlm;
    // write data type info
    fout << 2 << Matt::dlm;
    // write dimension info
    fout << 2 << Matt::dlm << N1 << Matt::dlm << N2 << Matt::dlm;
    // write matrix data
    for (Long j = 0; j < N2; ++j)
        for (Long i = 0; i < N1; ++i)
            matt_write_scalar(a(i, j), fout);
}

inline void save(ScmatInt_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

inline void save(ScmatLlong_I a, Str_I varname, Matt_IO matt)
{
    Long N1 = a.n1(), N2 = a.n2();
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open!");
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
    // write variable name info
    Long n = varname.size();
    fout << n << Matt::dlm;
    for (Long i = 0; i < n; ++i)
        fout << to_num(varname.at(i)) << Matt::dlm;
    // write data type info
    fout << 3 << Matt::dlm;
    // write dimension info
    fout << 2 << Matt::dlm << N1 << Matt::dlm << N2 << Matt::dlm;
    // write matrix data
    for (Long j = 0; j < N2; ++j)
        for (Long i = 0; i < N1; ++i)
            matt_write_scalar(a(i, j), fout);
}

inline void save(ScmatLlong_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

inline void save(ScmatDoub_I a, Str_I varname, Matt_IO matt)
{
    Long N1 = a.n1(), N2 = a.n2();
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open!");
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
    // write variable name info
    Long n = varname.size();
    fout << n << Matt::dlm;
    for (Long i = 0; i < n; ++i)
        fout << to_num(varname.at(i)) << Matt::dlm;
    // write data type info
    fout << 21 << Matt::dlm;
    // write dimension info
    fout << 2 << Matt::dlm << N1 << Matt::dlm << N2 << Matt::dlm;
    // write matrix data
    for (Long j = 0; j < N2; ++j)
        for (Long i = 0; i < N1; ++i)
            matt_write_scalar(a(i, j), fout);
}

inline void save(ScmatDoub_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

inline void save(ScmatComp_I a, Str_I varname, Matt_IO matt)
{
    Long N1 = a.n1(), N2 = a.n2();
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open!");
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
    // write variable name info
    Long n = varname.size();
    fout << n << Matt::dlm;
    for (Long i = 0; i < n; ++i)
        fout << to_num(varname.at(i)) << Matt::dlm;
    // write data type info
    fout << 41 << Matt::dlm;
    // write dimension info
    fout << 2 << Matt::dlm << N1 << Matt::dlm << N2 << Matt::dlm;
    // write matrix data
    for (Long j = 0; j < N2; ++j)
        for (Long i = 0; i < N1; ++i)
            matt_write_scalar(a(i, j), fout);
}

inline void save(ScmatComp_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

inline void save(DcmatInt_I a, Str_I varname, Matt_IO matt)
{
    Long N1 = a.n1(), N2 = a.n2();
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open!");
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
    // write variable name info
    Long n = varname.size();
    fout << n << Matt::dlm;
    for (Long i = 0; i < n; ++i)
        fout << to_num(varname.at(i)) << Matt::dlm;
    // write data type info
    fout << 2 << Matt::dlm;
    // write dimension info
    fout << 2 << Matt::dlm << N1 << Matt::dlm << N2 << Matt::dlm;
    // write matrix data
    for (Long j = 0; j < N2; ++j)
        for (Long i = 0; i < N1; ++i)
            matt_write_scalar(a(i, j), fout);
}

inline void save(DcmatInt_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

inline void save(DcmatLlong_I a, Str_I varname, Matt_IO matt)
{
    Long N1 = a.n1(), N2 = a.n2();
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open!");
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
    // write variable name info
    Long n = varname.size();
    fout << n << Matt::dlm;
    for (Long i = 0; i < n; ++i)
        fout << to_num(varname.at(i)) << Matt::dlm;
    // write data type info
    fout << 3 << Matt::dlm;
    // write dimension info
    fout << 2 << Matt::dlm << N1 << Matt::dlm << N2 << Matt::dlm;
    // write matrix data
    for (Long j = 0; j < N2; ++j)
        for (Long i = 0; i < N1; ++i)
            matt_write_scalar(a(i, j), fout);
}

inline void save(DcmatLlong_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

inline void save(DcmatDoub_I a, Str_I varname, Matt_IO matt)
{
    Long N1 = a.n1(), N2 = a.n2();
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open!");
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
    // write variable name info
    Long n = varname.size();
    fout << n << Matt::dlm;
    for (Long i = 0; i < n; ++i)
        fout << to_num(varname.at(i)) << Matt::dlm;
    // write data type info
    fout << 21 << Matt::dlm;
    // write dimension info
    fout << 2 << Matt::dlm << N1 << Matt::dlm << N2 << Matt::dlm;
    // write matrix data
    for (Long j = 0; j < N2; ++j)
        for (Long i = 0; i < N1; ++i)
            matt_write_scalar(a(i, j), fout);
}

inline void save(DcmatDoub_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

inline void save(DcmatComp_I a, Str_I varname, Matt_IO matt)
{
    Long N1 = a.n1(), N2 = a.n2();
    ofstream &fout = matt.m_out;
    if (!fout.is_open())
        SLS_ERR("matt file not open!");
    ++matt.m_n; matt.m_ind.push_back(fout.tellp());
    // write variable name info
    Long n = varname.size();
    fout << n << Matt::dlm;
    for (Long i = 0; i < n; ++i)
        fout << to_num(varname.at(i)) << Matt::dlm;
    // write data type info
    fout << 41 << Matt::dlm;
    // write dimension info
    fout << 2 << Matt::dlm << N1 << Matt::dlm << N2 << Matt::dlm;
    // write matrix data
    for (Long j = 0; j < N2; ++j)
        for (Long i = 0; i < N1; ++i)
            matt_write_scalar(a(i, j), fout);
}

inline void save(DcmatComp_I s, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "w");
    save(s, varname, matt);
    matt.close();
}

