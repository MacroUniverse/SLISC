function ret = is_integral(type)
ret = is_Char(type) || is_Int(type) ||...
    is_Long(type) || is_Llong(type);
end
