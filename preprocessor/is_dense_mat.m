function ret = is_dense_mat(type)
ret = is_Mat(type) || is_Cmat(type) || is_Fcmat(type)...
        || is_Scmat(type) || is_Scmat_c(type) || is_Smat(type);
end
