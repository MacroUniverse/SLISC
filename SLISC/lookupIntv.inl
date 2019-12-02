inline Long lookupIntv(Long_O ind, VecInt_I v, Int_I s)
{
    Long diff;
    Long i, N = v.size(), ind1 = 0, ind2 = N - 1;
    if (N < 1) return -3;
    diff = v[0] - s;
    if (diff > 0) return -1;
    if (diff == 0) {
        ind = 0; return 0;
    }
    diff = v[ind2] - s;
    if (diff < 0) return 1;
    
    // N >= 2 from here
    if (diff == 0) {
        ind = ind2; return 0;
    }
    // N > 2 from here
    for (i = 0; i < N; ++i) {
        ind = (ind1 + ind2) / 2;
        diff = v[ind] - s;
        if (diff == 0) return 0;
        if (diff > 0) ind2 = ind;
        else ind1 = ind;
        if (ind2 - ind1 == 1) {
            ind = ind1; return -2;
        }
    }
    SLS_ERR("slisc::lookup(): unknown error!");
    return 0;
}

inline Long lookupIntv(Long_O ind, VecLlong_I v, Llong_I s)
{
    Long diff;
    Long i, N = v.size(), ind1 = 0, ind2 = N - 1;
    if (N < 1) return -3;
    diff = v[0] - s;
    if (diff > 0) return -1;
    if (diff == 0) {
        ind = 0; return 0;
    }
    diff = v[ind2] - s;
    if (diff < 0) return 1;
    
    // N >= 2 from here
    if (diff == 0) {
        ind = ind2; return 0;
    }
    // N > 2 from here
    for (i = 0; i < N; ++i) {
        ind = (ind1 + ind2) / 2;
        diff = v[ind] - s;
        if (diff == 0) return 0;
        if (diff > 0) ind2 = ind;
        else ind1 = ind;
        if (ind2 - ind1 == 1) {
            ind = ind1; return -2;
        }
    }
    SLS_ERR("slisc::lookup(): unknown error!");
    return 0;
}

inline Long lookupIntv(Long_O ind, VecDoub_I v, Doub_I s)
{
    Long diff;
    Long i, N = v.size(), ind1 = 0, ind2 = N - 1;
    if (N < 1) return -3;
    diff = v[0] - s;
    if (diff > 0) return -1;
    if (diff == 0) {
        ind = 0; return 0;
    }
    diff = v[ind2] - s;
    if (diff < 0) return 1;
    
    // N >= 2 from here
    if (diff == 0) {
        ind = ind2; return 0;
    }
    // N > 2 from here
    for (i = 0; i < N; ++i) {
        ind = (ind1 + ind2) / 2;
        diff = v[ind] - s;
        if (diff == 0) return 0;
        if (diff > 0) ind2 = ind;
        else ind1 = ind;
        if (ind2 - ind1 == 1) {
            ind = ind1; return -2;
        }
    }
    SLS_ERR("slisc::lookup(): unknown error!");
    return 0;
}

