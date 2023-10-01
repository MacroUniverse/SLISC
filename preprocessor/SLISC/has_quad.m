% see if input types has anything to do with quadmath.h
function ret = has_quad(varargin)
for Tc = varargin
    T = Tc{1};
    if is_contain(T)
        Ts = val_t(T);
    elseif is_scalar(T)
        Ts = T;
    else
        continue;
    end
    if is_Qdoub(Ts) || is_Qcomp(Ts) || is_Qimag(Ts)
        ret = true; return;
    end
end
ret = false;
end
