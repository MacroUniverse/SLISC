function ret = cut12_type(T)
Ts = val_t(T);
if is_cmajor(T) && is_dense(T)
    ret = ['Scmat', Ts];
else
    error('cut12_type.m: not implemented!');
end
end
