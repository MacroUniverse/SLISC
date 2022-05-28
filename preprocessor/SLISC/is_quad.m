function ret = is_quad(type)
Ts = val_t(type);
if is_Qdoub(type) || is_Qcomp(type) || ...
   is_Qdoub(Ts) || is_Qcomp(Ts)
    ret = true;
else
    ret = false;
end
end
