function ret = type_num(type)
if (is_Bool(type)), ret = 0;
elseif (is_Char(type)), ret = 1;
elseif (is_Int(type)), ret = 2;
elseif (is_Llong(type)), ret = 3;

elseif (is_Float(type)), ret = 20;
elseif (is_Doub(type)), ret = 21;
elseif (is_Ldoub(type)), ret = 22;

elseif (is_Fcomp(type)), ret = 40;
elseif (is_Comp(type)), ret = 41;
elseif (is_Lcomp(type)), ret = 42;

elseif (is_Fimag(type)), ret = 60;
elseif (is_Imag(type)), ret = 61;
elseif (is_Limag(type)), ret = 62;
else, ret = -1;
end
end
