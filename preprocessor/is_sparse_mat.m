function ret = is_sparse_mat(T)
ret = is_Diag(T) || is_Mcoo(T) ||....
    is_Mcooh(T) || is_Cmobd(T);
end
