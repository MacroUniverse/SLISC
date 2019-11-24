function ret = is_basic_str(type)
ret = any(strfind(type, 'basic_string')) ||...
    is_Str(type);
end
