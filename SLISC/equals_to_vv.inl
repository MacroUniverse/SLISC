Bool equals_to_vv(const Doub *v1, const Doub *v2, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        if (v1[i] != v2[i])
            return false;
    return true;
}

