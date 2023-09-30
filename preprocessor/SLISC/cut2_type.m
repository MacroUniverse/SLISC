function ret = cut2_type(T)
Ts = val_t(T);
if is_cmajor(T) && is_dense_mat3(T) || is_dense_mat4(T)
    ret = ['Dvec' Ts];
elseif is_Mat3(T)
    ret = ['Svec' Ts];
else
    error(['cut2_type.m: not implemented: ' T]);
end
