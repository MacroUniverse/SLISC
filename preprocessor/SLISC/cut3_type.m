function ret = cut3_type(T)
Ts = value_type(T);
if is_Cmat3(T) || is_Cmat4(T)
    ret = ['Dvec' Ts];
elseif is_Mat3(T)
    ret = ['Svec' Ts];
else
    error('cut3_type.m: not implemented!');
end
