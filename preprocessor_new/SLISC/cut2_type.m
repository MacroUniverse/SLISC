function ret = cut2_type(T)
Ts = value_type(T);
if is_Cmat(T) || is_Scmat(T) || is_Dcmat(T) || is_Cmat3(T)
    ret = ['Dvec' Ts];
elseif is_Mat(T)
    ret = ['Svec' Ts];
else
    error('cut2_type.m: not implemented!');
end
