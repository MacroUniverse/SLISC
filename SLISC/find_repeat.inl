inline Long find_repeat(vecStr_I v)
{
    for (Long i = 0; i < Size(v); ++i) {
        for (Long j = i + 1; j < Size(v); ++j) {
            if (v[i] == v[j])
                return i;
        }
    }
    return -1;
}

