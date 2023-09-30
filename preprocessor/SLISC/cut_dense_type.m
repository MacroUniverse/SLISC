function ret = cut_dense_type(T)
Ts = val_t(T);
if is_dense_vec(T)
    ret = ['Svec' Ts];
elseif is_dense_mat(T)
    ret = ['Scmat' Ts];
elseif is_dense_mat3(T)
    ret = ['Scmat3' Ts];
else
    error(['cut_dense_type.m: not implemented: ' T]);
end
end
