function ret = is_signed(type)
ret = is_Char(type) || is_Int(type) || is_Llong(type)....
    || is_fpt(type);
end
