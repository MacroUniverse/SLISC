void mul_v_coo_v(Doub *y, const Doub *x, const Doub *a_ij, const Long *i, const Long *j, Long_I N1, Long_I Nnz)
{
    vecset(y, 0, N1);
    for (Long k = 0; k < Nnz; ++k)
        y[i[k]] += a_ij[k] * x[j[k]];
}

void mul_v_cooh_v(Doub *y, const Doub *x, const Doub *a_ij, const Long *i, const Long *j, Long_I N1, Long_I Nnz)
{
    vecset(y, 0, N1);
    for (Long k = 0; k < Nnz; ++k) {
        Long r = i[k], c = j[k];
        if (r == c)
            y[r] += a_ij[k] * x[c];
        else {
            y[r] += a_ij[k] * x[c];
            y[c] += a_ij[k] * x[r];
        }
    }
}

void mul_v_coo_v(Comp *y, const Comp *x, const Comp *a_ij, const Long *i, const Long *j, Long_I N1, Long_I Nnz)
{
    vecset(y, 0, N1);
    for (Long k = 0; k < Nnz; ++k)
        y[i[k]] += a_ij[k] * x[j[k]];
}

void mul_v_cooh_v(Comp *y, const Comp *x, const Comp *a_ij, const Long *i, const Long *j, Long_I N1, Long_I Nnz)
{
    vecset(y, 0, N1);
    for (Long k = 0; k < Nnz; ++k) {
        Long r = i[k], c = j[k];
        if (r == c)
            y[r] += a_ij[k] * x[c];
        else {
            y[r] += a_ij[k] * x[c];
            y[c] += conj(a_ij[k]) * x[r];
        }
    }
}

