inline void mul_cmat_cmat_diag(Doub *c, const Doub *a, Long_I Nr, Long_I Nc, const Doub *b)
{
    for (Long i = 0; i < Nc; ++i) {
        times_vvs(c, a, b[i], Nr);
        c += Nr; a += Nr;
    }
}

inline void mul_cmat_cmat_diag(Comp *c, const Comp *a, Long_I Nr, Long_I Nc, const Doub *b)
{
    for (Long i = 0; i < Nc; ++i) {
        times_vvs(c, a, b[i], Nr);
        c += Nr; a += Nr;
    }
}

inline void mul_cmat_cmat_diag(Comp *c, const Comp *a, Long_I Nr, Long_I Nc, const Comp *b)
{
    for (Long i = 0; i < Nc; ++i) {
        times_vvs(c, a, b[i], Nr);
        c += Nr; a += Nr;
    }
}

