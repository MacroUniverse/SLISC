function ret = is_comp_dense(type)
ret = is_dense(type) && is_comp(contain_type(type));
end
