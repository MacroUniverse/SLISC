function ret = is_slice_mat(T)
ret = is_Scmat(T) || is_Scmat_c(T) || is_Dcmat(T);
end
