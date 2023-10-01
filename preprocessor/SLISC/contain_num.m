function ret = contain_num(T)
if (is_Vec(T)), ret = 0;
elseif (is_Mat(T)), ret = 1;
elseif (is_Cmat(T)), ret = 2;
elseif (is_Mat3(T)), ret = 3;
elseif (is_Cmat3(T)), ret = 4;
% elseif (is_Mat4d(T)), ret = 5;
elseif (is_Cmat4(T)), ret = 6;

elseif (is_Fvec(T)), ret = 20;
elseif (is_Fcmat(T)), ret = 22;

elseif (is_Diag(T)), ret = 31;
elseif (is_Mcoo(T)), ret = 32;
elseif (is_Mcooh(T)), ret = 33;
elseif (is_Cmobd(T)), ret = 34;
elseif (is_Cband(T)), ret = 35;

elseif (is_Svbase(T)), ret = 40;
elseif (is_SvbaseC(T)), ret = 41;
elseif (is_Svec(T)), ret = 42;
elseif (is_SvecC(T)), ret = 43;
elseif (is_Dvec(T)), ret = 44;
% elseif (is_DvecC(T)), ret = 45;

elseif (is_Scmat(T)), ret = 60;
elseif (is_ScmatC(T)), ret = 61;
elseif (is_Dcmat(T)), ret = 62;
% elseif (is_DcmatC(T)), ret = 63;
elseif (is_Jcmat(T)), ret = 64;
% elseif (is_JcmatC(T)), ret = 65;

elseif (is_Scmat3(T)), ret = 70;
elseif (is_Scmat3C(T)), ret = 71;
elseif (is_Jcmat3(T)), ret = 72;
% elseif (is_Jcmat3C(T)), ret = 73;

elseif (is_Scmat4(T)), ret = 80;
elseif (is_Scmat4C(T)), ret = 81;

elseif (is_vec(T)), ret = 100;
else, ret = -1;
end
end
