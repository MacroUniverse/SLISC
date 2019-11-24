function ret = is_dense(type)
ret = is_dense_vec(type) || is_dense_mat(type) ||...
    is_Mat3d(type) || is_Cmat3d(type) || is_Cmat4d(type);
end
