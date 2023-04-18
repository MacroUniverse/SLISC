function ret = is_dense_mat(T)
ret = is_Mat(T) || is_Cmat(T) || is_Fcmat(T)...
        || is_Scmat(T) || is_ScmatC(T) || is_Smat(T);
end
