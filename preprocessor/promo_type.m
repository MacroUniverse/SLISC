function ret = promo_type(T1, T2)
num1 = type_num(T1);
num2 = type_num(T2);
if is_real(T1) && is_real(T2)
    if num1 >= num2
        ret = T1; return;
    else
        ret = T2; return;
    end
elseif is_comp(T1) && is_comp(T2)
    if num1 >= num2
        ret = T1; return;
    else
        ret = T2; return;
    end
elseif is_real(T1) && is_comp(T2)
    if num2 - num1 >= 20
        ret = T2; return;
    elseif is_Doub(T1)
        ret = 'Comp'; return;
    elseif is_Ldoub(T1)
        ret = 'Lcomp'; return;
    end
elseif is_comp(T1) && is_real(T2)
    if num1 - num2 >= 20
        ret = T1; return;
    elseif is_Doub(T2)
        ret = 'Comp'; return;
    elseif is_Ldoub(T2)
        ret = 'Lcomp'; return;
    end
elseif is_Imat(T1) && is_comp(T2)
    if num1 - num2 <= 20
        ret = T2; return;
    elseif is_Doub(value_type(T1))
        ret = 'Comp'; return;
    elseif is_Ldoub(value_type(T1))
        ret = 'Lcomp'; return;
    end
elseif is_comp(T1) && is_Imag(T2)
    if num2 - num1 <= 20
        ret = T1; return;
    elseif is_Doub(value_type(T2))
        ret = 'Comp'; return;
    elseif is_Ldoub(value_type(T2))
        ret = 'Lcomp'; return;
    end
end
error('promo_type.m: not implemented');
end
