function ret = is_promo(T1, T2)
num1 = type_num(T1);
num2 = type_num(T2);
if (is_real(T2))
    if (is_real(T1))
        if (num1 >= num2)
            ret = true; return;
        end
    elseif (is_comp(T1))
        if (num1 - num2 >= 20)
            ret = true; return;
        end
    else % is_imag(T1)
        if (num1 - num2 >= 40)
            ret = true; return;
        end
    end
elseif (is_comp(T2))
    if (is_comp(T2))
        if (num1 >= num2)
            ret = true; return;
        end
    end
elseif (is_imag(T2))
    if (is_imag(T1))
        if (num1 >= num2)
            ret = true; return;
        end
    elseif (is_comp(T1))
        if (num2 - num1 >= 20)
            ret = true; return;
        end
    end
end
ret = false;
end
