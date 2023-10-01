function ret = base_t(T)
Ts = val_t(T);
if is_Vec(T) || is_Cmat(T) || is_Cmat3(T) || is_Cmat4(T) || ...
        is_Diag(T) || is_Mcoo(T) || is_Mcooh(T)
    ret = ['Vbase' Ts];
elseif is_Svec(T) || is_Scmat(T) || is_Scmat3(T) || is_Scmat4(T)
    ret = ['Svbase' Ts];
else
    ret = T;
end
end
