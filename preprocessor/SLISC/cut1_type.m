function ret = cut1_type(T)
Ts = val_t(T);
if is_dense_mat(T) || is_Dcmat(T)
    if is_cmajor(T)
        ret = ['Dvec' Ts];
    else
        ret = ['Svec' Ts];
    end
elseif is_dense_mat3(T) || is_dense_mat4(T)
    ret = ['Dvec' Ts];
else
    error('cut2_type.m: not implemented!');
end
