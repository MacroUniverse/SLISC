function ret = cut01_type(T)
Ts = val_t(T);
if is_cmajor(T) && is_dense(T)
    ret = ['Dcmat', Ts];
else
    error(['cut01_type.m: not implemented:' T]);
end
end
