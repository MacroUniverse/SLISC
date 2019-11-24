function ret = is_promo(type1, type2)
num1 = type_num(type1);
num2 = type_num(type2);
if (is_real(type2))
    if (is_real(type1))
        if (num1 >= num2)
            ret = true; return;
        end
    elseif (is_comp(type1))
        if (num1 - num2 >= 20)
            ret = true; return;
        end
    else % is_imag(type1)
        if (num1 - num2 >= 40)
            ret = true; return;
        end
    end
elseif (is_comp(type2))
    if (is_comp(type2))
        if (num1 >= num2)
            ret = true; return;
        end
    end
elseif (is_imag(type2))
    if (is_imag(type1))
        if (num1 >= num2)
            ret = true; return;
        end
    end
    if (is_comp(type1))
        if (num2 - num1 >= 20)
            ret = true; return;
        end
    end
end
ret = false;
end
