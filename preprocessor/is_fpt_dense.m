function ret = is_fpt_dense(T)
ret = is_dense(T) && is_fpt(value_type(T));
end
