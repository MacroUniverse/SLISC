function ret = is_comp_dense(T)
ret = is_dense(T) && is_comp(contain_type(T));
end
