function ret = is_dense(type)
ret = is_dense_vec(type) || is_dense_mat(type) ||...
    is_Mat3(type) || is_Cmat3(type) || is_Cmat4(type);
end
