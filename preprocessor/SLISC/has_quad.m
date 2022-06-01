% see if input types has anything to do with quadmath.h
function ret = has_quad(varargin)
for type = varargin
    if is_contain(type{1})
        Ts = val_t(type{1});
    elseif is_scalar(type{1})
        Ts = type{1};
    else
        continue;
    end
    if is_Qdoub(Ts) || is_Qcomp(Ts)
        ret = true; return;
    end
end
ret = false;
end
