inline Int load(Char_O s, Str_I varname, Matt_IO matt)
{
    Long i;
    ifstream &fin = matt.m_in;
    i = matt.search(varname);
    if (i < 0)
        return -1;
    fin.seekg(matt.m_ind[i]);

    if (1 < matt.m_type[i])
        SLS_ERR("wrong type!");
    if (matt.m_size[i].size() != 0)
        SLS_ERR("wrong dimension!");

    matt_read_scalar(s, fin);
    return 0;
}

inline void load(Char_O var, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "r");
    load(var, varname, matt);
    matt.close();
}

inline Int load(Int_O s, Str_I varname, Matt_IO matt)
{
    Long i;
    ifstream &fin = matt.m_in;
    i = matt.search(varname);
    if (i < 0)
        return -1;
    fin.seekg(matt.m_ind[i]);

    if (2 < matt.m_type[i])
        SLS_ERR("wrong type!");
    if (matt.m_size[i].size() != 0)
        SLS_ERR("wrong dimension!");

    matt_read_scalar(s, fin);
    return 0;
}

inline void load(Int_O var, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "r");
    load(var, varname, matt);
    matt.close();
}

inline Int load(Llong_O s, Str_I varname, Matt_IO matt)
{
    Long i;
    ifstream &fin = matt.m_in;
    i = matt.search(varname);
    if (i < 0)
        return -1;
    fin.seekg(matt.m_ind[i]);

    if (3 < matt.m_type[i])
        SLS_ERR("wrong type!");
    if (matt.m_size[i].size() != 0)
        SLS_ERR("wrong dimension!");

    matt_read_scalar(s, fin);
    return 0;
}

inline void load(Llong_O var, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "r");
    load(var, varname, matt);
    matt.close();
}

inline Int load(Doub_O s, Str_I varname, Matt_IO matt)
{
    Long i;
    ifstream &fin = matt.m_in;
    i = matt.search(varname);
    if (i < 0)
        return -1;
    fin.seekg(matt.m_ind[i]);

    if (21 < matt.m_type[i])
        SLS_ERR("wrong type!");
    if (matt.m_size[i].size() != 0)
        SLS_ERR("wrong dimension!");

    matt_read_scalar(s, fin);
    return 0;
}

inline void load(Doub_O var, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "r");
    load(var, varname, matt);
    matt.close();
}

inline Int load(Comp_O s, Str_I varname, Matt_IO matt)
{
    Long i;
    ifstream &fin = matt.m_in;
    i = matt.search(varname);
    if (i < 0)
        return -1;
    fin.seekg(matt.m_ind[i]);

    if (41 < matt.m_type[i])
        SLS_ERR("wrong type!");
    if (matt.m_size[i].size() != 0)
        SLS_ERR("wrong dimension!");

    matt_read_scalar(s, fin);
    return 0;
}

inline void load(Comp_O var, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "r");
    load(var, varname, matt);
    matt.close();
}

inline Int load(VecChar_O v, Str_I varname, Matt_IO matt)
{
    ifstream &fin = matt.m_in;
    Long i = matt.search(varname);
    if (i < 0)
        return -1;
    fin.seekg(matt.m_ind[i]);

    if (1 < matt.m_type[i])
        SLS_ERR("wrong type!");
    if (matt.m_size[i].size() != 1)
        SLS_ERR("wrong dimension!");

    Long n = matt.m_size[i][0]; v.resize(n);
    // read var data
    for (Long i = 0; i < n; ++i)
		matt_read_scalar(v[i], fin);
    return 0;
}

inline void load(VecChar_O var, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "r");
    load(var, varname, matt);
    matt.close();
}

inline Int load(VecInt_O v, Str_I varname, Matt_IO matt)
{
    ifstream &fin = matt.m_in;
    Long i = matt.search(varname);
    if (i < 0)
        return -1;
    fin.seekg(matt.m_ind[i]);

    if (2 < matt.m_type[i])
        SLS_ERR("wrong type!");
    if (matt.m_size[i].size() != 1)
        SLS_ERR("wrong dimension!");

    Long n = matt.m_size[i][0]; v.resize(n);
    // read var data
    for (Long i = 0; i < n; ++i)
		matt_read_scalar(v[i], fin);
    return 0;
}

inline void load(VecInt_O var, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "r");
    load(var, varname, matt);
    matt.close();
}

inline Int load(VecDoub_O v, Str_I varname, Matt_IO matt)
{
    ifstream &fin = matt.m_in;
    Long i = matt.search(varname);
    if (i < 0)
        return -1;
    fin.seekg(matt.m_ind[i]);

    if (21 < matt.m_type[i])
        SLS_ERR("wrong type!");
    if (matt.m_size[i].size() != 1)
        SLS_ERR("wrong dimension!");

    Long n = matt.m_size[i][0]; v.resize(n);
    // read var data
    for (Long i = 0; i < n; ++i)
		matt_read_scalar(v[i], fin);
    return 0;
}

inline void load(VecDoub_O var, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "r");
    load(var, varname, matt);
    matt.close();
}

inline Int load(VecComp_O v, Str_I varname, Matt_IO matt)
{
    ifstream &fin = matt.m_in;
    Long i = matt.search(varname);
    if (i < 0)
        return -1;
    fin.seekg(matt.m_ind[i]);

    if (41 < matt.m_type[i])
        SLS_ERR("wrong type!");
    if (matt.m_size[i].size() != 1)
        SLS_ERR("wrong dimension!");

    Long n = matt.m_size[i][0]; v.resize(n);
    // read var data
    for (Long i = 0; i < n; ++i)
		matt_read_scalar(v[i], fin);
    return 0;
}

inline void load(VecComp_O var, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "r");
    load(var, varname, matt);
    matt.close();
}

inline Int load(MatInt_O a, Str_I varname, Matt_IO matt)
{
    Long i, j, m, n;
    ifstream &fin = matt.m_in;
    i = matt.search(varname);
    if (i < 0)
        return -1;
    fin.seekg(matt.m_ind[i]);

    if (2 < matt.m_type[i])
        SLS_ERR("wrong type!");
    if (matt.m_size[i].size() != 2)
        SLS_ERR("wrong dimension!");

    m = matt.m_size[i][0]; n = matt.m_size[i][1]; a.resize(m, n);
    // read var data
    for (j = 0; j < n; ++j)
        for (i = 0; i < m; ++i)
			matt_read_scalar(a(i, j), fin);
    return 0;
}

inline void load(MatInt_O var, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "r");
    load(var, varname, matt);
    matt.close();
}

inline Int load(MatLlong_O a, Str_I varname, Matt_IO matt)
{
    Long i, j, m, n;
    ifstream &fin = matt.m_in;
    i = matt.search(varname);
    if (i < 0)
        return -1;
    fin.seekg(matt.m_ind[i]);

    if (3 < matt.m_type[i])
        SLS_ERR("wrong type!");
    if (matt.m_size[i].size() != 2)
        SLS_ERR("wrong dimension!");

    m = matt.m_size[i][0]; n = matt.m_size[i][1]; a.resize(m, n);
    // read var data
    for (j = 0; j < n; ++j)
        for (i = 0; i < m; ++i)
			matt_read_scalar(a(i, j), fin);
    return 0;
}

inline void load(MatLlong_O var, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "r");
    load(var, varname, matt);
    matt.close();
}

inline Int load(MatDoub_O a, Str_I varname, Matt_IO matt)
{
    Long i, j, m, n;
    ifstream &fin = matt.m_in;
    i = matt.search(varname);
    if (i < 0)
        return -1;
    fin.seekg(matt.m_ind[i]);

    if (21 < matt.m_type[i])
        SLS_ERR("wrong type!");
    if (matt.m_size[i].size() != 2)
        SLS_ERR("wrong dimension!");

    m = matt.m_size[i][0]; n = matt.m_size[i][1]; a.resize(m, n);
    // read var data
    for (j = 0; j < n; ++j)
        for (i = 0; i < m; ++i)
			matt_read_scalar(a(i, j), fin);
    return 0;
}

inline void load(MatDoub_O var, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "r");
    load(var, varname, matt);
    matt.close();
}

inline Int load(MatComp_O a, Str_I varname, Matt_IO matt)
{
    Long i, j, m, n;
    ifstream &fin = matt.m_in;
    i = matt.search(varname);
    if (i < 0)
        return -1;
    fin.seekg(matt.m_ind[i]);

    if (41 < matt.m_type[i])
        SLS_ERR("wrong type!");
    if (matt.m_size[i].size() != 2)
        SLS_ERR("wrong dimension!");

    m = matt.m_size[i][0]; n = matt.m_size[i][1]; a.resize(m, n);
    // read var data
    for (j = 0; j < n; ++j)
        for (i = 0; i < m; ++i)
			matt_read_scalar(a(i, j), fin);
    return 0;
}

inline void load(MatComp_O var, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "r");
    load(var, varname, matt);
    matt.close();
}

inline Int load(CmatInt_O a, Str_I varname, Matt_IO matt)
{
    Long i, j, m, n;
    ifstream &fin = matt.m_in;
    i = matt.search(varname);
    if (i < 0)
        return -1;
    fin.seekg(matt.m_ind[i]);

    if (2 < matt.m_type[i])
        SLS_ERR("wrong type!");
    if (matt.m_size[i].size() != 2)
        SLS_ERR("wrong dimension!");

    m = matt.m_size[i][0]; n = matt.m_size[i][1]; a.resize(m, n);
    // read var data
    for (j = 0; j < n; ++j)
        for (i = 0; i < m; ++i)
			matt_read_scalar(a(i, j), fin);
    return 0;
}

inline void load(CmatInt_O var, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "r");
    load(var, varname, matt);
    matt.close();
}

inline Int load(CmatLlong_O a, Str_I varname, Matt_IO matt)
{
    Long i, j, m, n;
    ifstream &fin = matt.m_in;
    i = matt.search(varname);
    if (i < 0)
        return -1;
    fin.seekg(matt.m_ind[i]);

    if (3 < matt.m_type[i])
        SLS_ERR("wrong type!");
    if (matt.m_size[i].size() != 2)
        SLS_ERR("wrong dimension!");

    m = matt.m_size[i][0]; n = matt.m_size[i][1]; a.resize(m, n);
    // read var data
    for (j = 0; j < n; ++j)
        for (i = 0; i < m; ++i)
			matt_read_scalar(a(i, j), fin);
    return 0;
}

inline void load(CmatLlong_O var, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "r");
    load(var, varname, matt);
    matt.close();
}

inline Int load(CmatDoub_O a, Str_I varname, Matt_IO matt)
{
    Long i, j, m, n;
    ifstream &fin = matt.m_in;
    i = matt.search(varname);
    if (i < 0)
        return -1;
    fin.seekg(matt.m_ind[i]);

    if (21 < matt.m_type[i])
        SLS_ERR("wrong type!");
    if (matt.m_size[i].size() != 2)
        SLS_ERR("wrong dimension!");

    m = matt.m_size[i][0]; n = matt.m_size[i][1]; a.resize(m, n);
    // read var data
    for (j = 0; j < n; ++j)
        for (i = 0; i < m; ++i)
			matt_read_scalar(a(i, j), fin);
    return 0;
}

inline void load(CmatDoub_O var, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "r");
    load(var, varname, matt);
    matt.close();
}

inline Int load(CmatComp_O a, Str_I varname, Matt_IO matt)
{
    Long i, j, m, n;
    ifstream &fin = matt.m_in;
    i = matt.search(varname);
    if (i < 0)
        return -1;
    fin.seekg(matt.m_ind[i]);

    if (41 < matt.m_type[i])
        SLS_ERR("wrong type!");
    if (matt.m_size[i].size() != 2)
        SLS_ERR("wrong dimension!");

    m = matt.m_size[i][0]; n = matt.m_size[i][1]; a.resize(m, n);
    // read var data
    for (j = 0; j < n; ++j)
        for (i = 0; i < m; ++i)
			matt_read_scalar(a(i, j), fin);
    return 0;
}

inline void load(CmatComp_O var, Str_I varname, Str_I matt_file)
{
    Matt matt(matt_file, "r");
    load(var, varname, matt);
    matt.close();
}

