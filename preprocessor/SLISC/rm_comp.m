function ret = rm_comp(T)
if is_Fcomp(T)
    ret = 'Float';
elseif is_Comp(T)
    ret = 'Doub';
elseif is_Lcomp(T)
    ret = 'Ldoub';
elseif is_Qcomp(T)
    ret = 'Qdoub';
elseif is_real(T)
    ret = T;
else
    error('rm_comp: not implemented!');
end
end
