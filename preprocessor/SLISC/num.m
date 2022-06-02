% return numerical literal of specified type
function ret = num(x, type)
if is_Int(type) || is_Char(type)
    ret = num2str(round(x));
elseif is_Llong(type)
    ret = [num2str(round(x)) 'LL'];
elseif is_Float(type)
    if x == round(x)
        ret = [num2str(x) '.F'];
    else
        ret = [num2str(x) 'F'];
    end
elseif is_Doub(type)
    if x == round(x)
        ret = [num2str(x) '.'];
    else
        ret = num2str(x);
    end
elseif is_Ldoub(type)
    if x == round(x)
        ret = [num2str(x) '.L'];
    else
        ret = [num2str(x) 'L'];
    end
elseif is_Qdoub(type)
    if x == round(x)
        ret = [num2str(x) '.Q'];
    else
        ret = [num2str(x) 'Q'];
    end
else
    error(['num.m: not implemented: ' type]);
end
