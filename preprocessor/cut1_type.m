function ret = cut1_type(T)
Ts = value_type(T);
if is_Cmat(T) || is_Scmat(T) || is_Dcmat(T) || is_Cmat3(T)
    ret = ['Svec' Ts];
elseif is_Mat(T)
    ret = ['Dvec' Ts];
else
    error('cut1_type.m: not implemented!');
end
