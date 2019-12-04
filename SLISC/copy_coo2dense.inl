inline void coo2dense(CmatDoub_O lhs, McooDoub_I rhs)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(lhs, rhs))
        SLS_ERR("wrong shape!");
#endif
    copy(lhs, 0);
    for (Long i = 0; i < rhs.nnz(); ++i) {
        lhs(rhs.row(i), rhs.col(i)) = rhs[i];
    }
}

// inline void cooh2dense(CmatDoub_O lhs, McoohDoub_I rhs)
// {
// #ifdef SLS_CHECK_SHAPE
//     if (!shape_cmp(lhs, rhs))
//         SLS_ERR("wrong shape!");
// #endif
//     copy(lhs, 0);
//     for (Long i = 0; i < rhs.nnz(); ++i) {
//         Long r = rhs.row(i), c = rhs.col(i);
//         if (r == c)
//             lhs(r, r) = rhs(i);
//         else {
//             lhs(r, c) = rhs(i);
//             lhs(c, r) = CONJ(rhs(i));
//         }
//     }
// }

inline void coo2dense(CmatComp_O lhs, McooComp_I rhs)
{
#ifdef SLS_CHECK_SHAPE
    if (!shape_cmp(lhs, rhs))
        SLS_ERR("wrong shape!");
#endif
    copy(lhs, 0);
    for (Long i = 0; i < rhs.nnz(); ++i) {
        lhs(rhs.row(i), rhs.col(i)) = rhs[i];
    }
}

// inline void cooh2dense(CmatComp_O lhs, McoohComp_I rhs)
// {
// #ifdef SLS_CHECK_SHAPE
//     if (!shape_cmp(lhs, rhs))
//         SLS_ERR("wrong shape!");
// #endif
//     copy(lhs, 0);
//     for (Long i = 0; i < rhs.nnz(); ++i) {
//         Long r = rhs.row(i), c = rhs.col(i);
//         if (r == c)
//             lhs(r, r) = rhs(i);
//         else {
//             lhs(r, c) = rhs(i);
//             lhs(c, r) = CONJ(rhs(i));
//         }
//     }
// }

