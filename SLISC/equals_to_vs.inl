Bool equals_to_vs(const Llong *v, Llong_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        if (v[i] != s)
            return false;
    return true;
}

Bool equals_to_vs(const Doub *v, Doub_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        if (v[i] != s)
            return false;
    return true;
}

Bool equals_to_vs(const Comp *v, Comp_I s, Long_I N)
{
    for (Long i = 0; i < N; ++i)
        if (v[i] != s)
            return false;
    return true;
}

