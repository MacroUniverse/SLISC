function ret = is_dense_vec(T)
ret = is_vec(T) || is_Vbase(T) || is_Vec(T) || is_Fvec(T) ||...
    is_Svec(T) || is_SvecC(T);
end
