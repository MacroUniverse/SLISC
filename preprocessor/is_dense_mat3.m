function ret = is_dense_mat3(T)
ret = is_Mat3(T) || is_Cmat3(T) || is_Scmat3(T) || is_Scmat3_c(T);
end
