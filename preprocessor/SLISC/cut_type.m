function ret = cut_type(T)
Ts = val_t(T);
if is_dense_vec(T)
    ret = ['Svec' Ts];
elseif is_Dvec(T)
    ret = ['Dvec' Ts];
elseif is_Cmat(T) || is_Scmat(T) || is_Dcmat(T)
    ret = ['Dcmat' Ts];
elseif is_Cmat3(T) || is_Scmat3(T)
    ret = ['Jcmat3' Ts];
elseif is_Mat(T)
    ret = ['Dmat', Ts];
else
    error(['cut_type.m: not implemented: ' T]);
end
end
