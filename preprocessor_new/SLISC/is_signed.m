function ret = is_signed(T)
ret = is_Char(T) || is_Int(T) || is_Llong(T)....
    || is_fpt(T);
end
