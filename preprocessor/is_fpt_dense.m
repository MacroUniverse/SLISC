function ret = is_fpt_dense(type)
ret = is_dense(type) && is_fpt(contain_type(type));
end
