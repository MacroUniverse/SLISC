function ret = is_integral(T)
ret = is_Char(T) || is_Int(T) ||...
    is_Long(T) || is_Llong(T);
end
