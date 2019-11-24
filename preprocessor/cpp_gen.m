code = '';
code = [code, cstr{1}];
[Ty, Ta, Tx] = varargin{1:3};
code = [code, cstr{3}];
Tsy = contain_type(Ty); Tsa = contain_type(Ta); Tsx = contain_type(Tx);
code = [code, cstr{5}];
if is_dense_vec(Ty)
code = [code, cstr{7}];
else
code = [code, cstr{9}];
end
code = [code, cstr{11}];
if is_dense_mat(Ta)
code = [code, cstr{13}];
else
code = [code, cstr{15}];
end
code = [code, cstr{17}];
if is_dense_vec(Tx)
code = [code, cstr{19}];
else
code = [code, cstr{21}];
end
code = [code, cstr{23}];
if is_Doub(Tsy) && is_Doub(Tsx)
code = [code, cstr{25}];
elseif (is_Comp(Tsy) && is_Comp(Tsx))
code = [code, cstr{27}];
elseif is_Comp(Ts) && is_Doub(Ts1)
code = [code, cstr{29}];
end
code = [code, cstr{31}];

