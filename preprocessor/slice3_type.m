function ret = slice3_type(T)
Ts = contain_type(T);
if is_Cmat3(T) || is_Cmat4(T)
    ret = ['Dvec' Ts];
elseif is_Mat3(T)
    ret = ['Svec' Ts];
else
    error('slice3_type.m: not implemented!');
end
