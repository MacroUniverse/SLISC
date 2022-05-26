function ret = is_basic_str(T)
ret = any(strfind(T, 'basic_string')) ||...
    is_Str(T);
end
