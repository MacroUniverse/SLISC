inline void mul_cmat_diag_cmat(Doub *c, const Doub *a, const Doub *b, Long_I Nr, Long_I Nc)
{
    for (Long i = 0; i < Nc; ++i) {
        times_vvv(c, b, a, Nr);
        c += Nr; b += Nr;
    }
}

inline void mul_cmat_diag_cmat(Comp *c, const Doub *a, const Comp *b, Long_I Nr, Long_I Nc)
{
    for (Long i = 0; i < Nc; ++i) {
        times_vvv(c, b, a, Nr);
        c += Nr; b += Nr;
    }
}

inline void mul_cmat_diag_cmat(Comp *c, const Comp *a, const Comp *b, Long_I Nr, Long_I Nc)
{
    for (Long i = 0; i < Nc; ++i) {
        times_vvv(c, b, a, Nr);
        c += Nr; b += Nr;
    }
}

