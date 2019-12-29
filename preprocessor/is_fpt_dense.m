function ret = is_fpt_dense(T)
ret = is_dense(T) && is_fpt(contain_type(T));
end
