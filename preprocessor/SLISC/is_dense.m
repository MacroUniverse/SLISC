function ret = is_dense(T)
ret = is_dense_vec(T) || is_dense_mat(T) || ...
    is_dense_mat3(T) || is_dense_mat4(T);
end
