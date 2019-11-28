inline void matcpy(Int *v, Long_I lda, const Int *v1, Long_I lda1, Long_I Nr, Long_I Nc)
{
    for (Long j = 0; j < Nr; ++j) {
        veccpy(v, v1, Nc);
        v += lda; v1 += lda1;
    }
}

inline void matcpy(Doub *v, Long_I lda, const Doub *v1, Long_I lda1, Long_I Nr, Long_I Nc)
{
    for (Long j = 0; j < Nr; ++j) {
        veccpy(v, v1, Nc);
        v += lda; v1 += lda1;
    }
}

inline void matcpy(Comp *v, Long_I lda, const Comp *v1, Long_I lda1, Long_I Nr, Long_I Nc)
{
    for (Long j = 0; j < Nr; ++j) {
        veccpy(v, v1, Nc);
        v += lda; v1 += lda1;
    }
}

