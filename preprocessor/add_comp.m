function ret = add_comp(type)
if is_comp(type)
    ret = type;
elseif is_Float(type)
    ret = 'Fcomp';
elseif is_Doub(type)
    ret = 'Comp';
elseif is_Ldoub(type)
    ret = 'Lcomp';
elseif is_Char(type) || is_Int(type) || is_Llong(type)
    ret = 'Fcomp';
else
    error('not implemented');
end 
end
