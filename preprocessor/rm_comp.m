function ret = rm_comp(type)
if is_Fcomp(type)
    ret = 'Float';
elseif is_Comp(type)
    ret = 'Doub';
elseif is_Lcomp(type)
    ret = 'Ldoub';
end
end
