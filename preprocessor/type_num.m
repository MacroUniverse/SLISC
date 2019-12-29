function ret = type_num(T)
if (is_Bool(T)), ret = 0;
elseif (is_Char(T)), ret = 1;
elseif (is_Int(T)), ret = 2;
elseif (is_Llong(T)), ret = 3;

elseif (is_Float(T)), ret = 20;
elseif (is_Doub(T)), ret = 21;
elseif (is_Ldoub(T)), ret = 22;

elseif (is_Fcomp(T)), ret = 40;
elseif (is_Comp(T)), ret = 41;
elseif (is_Lcomp(T)), ret = 42;

elseif (is_Fimag(T)), ret = 60;
elseif (is_Imag(T)), ret = 61;
elseif (is_Limag(T)), ret = 62;
else, ret = -1;
end
end
