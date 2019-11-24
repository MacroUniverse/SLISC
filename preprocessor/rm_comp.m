function ret = rm_comp(type)
if (is_comp(type))
    ret = contain_type(type);
elseif (is_Imag(type))
    ret = contain_type(type);
end
end
