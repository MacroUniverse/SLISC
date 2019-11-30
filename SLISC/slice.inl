inline void slice(DcmatDoub_O sli, CmatDoub_I a,
    Long_I i, Long_I Nr, Long_I j, Long_I Nc)
{
    sli.set(&a(i, j), Nr, Nc, a.n1());
}

