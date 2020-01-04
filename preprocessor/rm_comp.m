function ret = rm_comp(T)
if is_Fcomp(T)
    ret = 'Float';
elseif is_Comp(T)
    ret = 'Doub';
elseif is_Lcomp(T)
    ret = 'Ldoub';
else
    ret = T;
end
end
