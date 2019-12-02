function ret = is_dense_vec(type)
ret = is_Vbase(type) || is_Vec(type) || is_Fvec(type) ||...
    is_Svec(type) || is_Svec_c(type);
end
