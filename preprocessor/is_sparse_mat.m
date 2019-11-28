function ret = is_sparse_mat(type)
ret = is_Diag(type) || is_Mcoo(type) ||....
    is_McooH(type) || is_CmatObd(type);
end
