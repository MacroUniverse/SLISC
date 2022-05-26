function ret = is_scalar(T)
ret = type_num(T) >= 0 || is_Long(T);
end
