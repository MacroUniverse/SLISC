function ret = slice_type(type)
Ts = contain_type(type);
if is_Vec(type)
    ret = ['Svec' Ts];
elseif is_Cmat(type)
    ret = ['Dcmat' Ts];
else
    error('not implemented!');
end
end
