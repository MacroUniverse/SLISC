function ret = is_sparse_mat(type)
ret = is_Diag(type) || is_MatCoo(type) ||....
    is_MatCooH(type) || is_CmatObd(type);
end
