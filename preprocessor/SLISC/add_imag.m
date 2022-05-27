function ret = add_imag(T)
if is_imag(T)
    ret = T;
elseif is_Float(T)
    ret = 'Fimag';
elseif is_Doub(T)
    ret = 'Imag';
elseif is_Ldoub(T)
    ret = 'Limag';
else
    error('add_imag.m: not implemented');
end 
end
