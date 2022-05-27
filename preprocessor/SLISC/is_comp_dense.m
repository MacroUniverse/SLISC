function ret = is_comp_dense(T)
ret = is_dense(T) && is_comp(value_type(T));
end
