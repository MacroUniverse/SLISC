function ret = is_comp_contain(T)
ret = is_contain(T) && is_comp(value_type(T));
end
