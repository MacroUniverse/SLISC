inline void veccpy(Llong *v, const Llong *v1, Long_I n)
{
    for (Long i = 0; i < n; ++i)
        v[i] = v1[i];
}

inline void veccpy(Llong *v, const Llong *v1, Long_I step1, Long_I n)
{
    for (Llong *p = v; p < v + n; ++p) {
        *p = *v1;
        v1 += step1;
    }
}

inline void veccpy(Llong *v, Long_I step, const Llong *v1, Long_I n)
{
    for (Llong *p = v; p < v + n*step; p += step) {
        *p = *v1;
        ++v1;
    }
}

inline void veccpy(Llong *v, Long_I step, const Llong *v1, Long_I step1, Long_I n)
{
    Llong *end = v + n * step;
    for (; v < end; v += step) {
        *v = *v1;
        v1 += step1;
    }
}

inline void veccpy(Doub *v, const Llong *v1, Long_I n)
{
    for (Long i = 0; i < n; ++i)
        v[i] = v1[i];
}

inline void veccpy(Doub *v, const Llong *v1, Long_I step1, Long_I n)
{
    for (Doub *p = v; p < v + n; ++p) {
        *p = *v1;
        v1 += step1;
    }
}

inline void veccpy(Doub *v, Long_I step, const Llong *v1, Long_I n)
{
    for (Doub *p = v; p < v + n*step; p += step) {
        *p = *v1;
        ++v1;
    }
}

inline void veccpy(Doub *v, Long_I step, const Llong *v1, Long_I step1, Long_I n)
{
    Doub *end = v + n * step;
    for (; v < end; v += step) {
        *v = *v1;
        v1 += step1;
    }
}

inline void veccpy(Doub *v, const Doub *v1, Long_I n)
{
    for (Long i = 0; i < n; ++i)
        v[i] = v1[i];
}

inline void veccpy(Doub *v, const Doub *v1, Long_I step1, Long_I n)
{
    for (Doub *p = v; p < v + n; ++p) {
        *p = *v1;
        v1 += step1;
    }
}

inline void veccpy(Doub *v, Long_I step, const Doub *v1, Long_I n)
{
    for (Doub *p = v; p < v + n*step; p += step) {
        *p = *v1;
        ++v1;
    }
}

inline void veccpy(Doub *v, Long_I step, const Doub *v1, Long_I step1, Long_I n)
{
    Doub *end = v + n * step;
    for (; v < end; v += step) {
        *v = *v1;
        v1 += step1;
    }
}

inline void veccpy(Comp *v, const Doub *v1, Long_I n)
{
    for (Long i = 0; i < n; ++i)
        v[i] = v1[i];
}

inline void veccpy(Comp *v, const Doub *v1, Long_I step1, Long_I n)
{
    for (Comp *p = v; p < v + n; ++p) {
        *p = *v1;
        v1 += step1;
    }
}

inline void veccpy(Comp *v, Long_I step, const Doub *v1, Long_I n)
{
    for (Comp *p = v; p < v + n*step; p += step) {
        *p = *v1;
        ++v1;
    }
}

inline void veccpy(Comp *v, Long_I step, const Doub *v1, Long_I step1, Long_I n)
{
    Comp *end = v + n * step;
    for (; v < end; v += step) {
        *v = *v1;
        v1 += step1;
    }
}

inline void veccpy(Comp *v, const Llong *v1, Long_I n)
{
    for (Long i = 0; i < n; ++i)
        v[i] = v1[i];
}

inline void veccpy(Comp *v, const Llong *v1, Long_I step1, Long_I n)
{
    for (Comp *p = v; p < v + n; ++p) {
        *p = *v1;
        v1 += step1;
    }
}

inline void veccpy(Comp *v, Long_I step, const Llong *v1, Long_I n)
{
    for (Comp *p = v; p < v + n*step; p += step) {
        *p = *v1;
        ++v1;
    }
}

inline void veccpy(Comp *v, Long_I step, const Llong *v1, Long_I step1, Long_I n)
{
    Comp *end = v + n * step;
    for (; v < end; v += step) {
        *v = *v1;
        v1 += step1;
    }
}

inline void veccpy(Comp *v, const Comp *v1, Long_I n)
{
    for (Long i = 0; i < n; ++i)
        v[i] = v1[i];
}

inline void veccpy(Comp *v, const Comp *v1, Long_I step1, Long_I n)
{
    for (Comp *p = v; p < v + n; ++p) {
        *p = *v1;
        v1 += step1;
    }
}

inline void veccpy(Comp *v, Long_I step, const Comp *v1, Long_I n)
{
    for (Comp *p = v; p < v + n*step; p += step) {
        *p = *v1;
        ++v1;
    }
}

inline void veccpy(Comp *v, Long_I step, const Comp *v1, Long_I step1, Long_I n)
{
    Comp *end = v + n * step;
    for (; v < end; v += step) {
        *v = *v1;
        v1 += step1;
    }
}

