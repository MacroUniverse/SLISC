function ret = slice12_type(T)
Ts = contain_type(T);
if is_cmajor(T) && is_dense(T)
    ret = ['Scmat', Ts];
else
    error('slice12_type.m: not implemented!');
end
end
