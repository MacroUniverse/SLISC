function ret = add_comp(T)
if is_comp(T)
    ret = T;
elseif is_Float(T)
    ret = 'Fcomp';
elseif is_Doub(T)
    ret = 'Comp';
elseif is_Ldoub(T)
    ret = 'Lcomp';
elseif is_Qdoub(T)
    ret = 'Qcomp';
else
    error('add_comp.m: not implemented');
end 
end
