function ret = is_slice_mat3(T)
ret = is_cut_vec(T) || is_cut_mat(T) || is_cut_mat3(T);
end
