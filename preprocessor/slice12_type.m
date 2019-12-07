function ret = slice12_type(T)
Ts = contain_type(T);
if is_cmajor(T) && is_dense(T)
    ret = ['Scmat', Ts];
else
    error('not implemented!');
end
end
