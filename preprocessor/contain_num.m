function ret = contain_num(type)
if (is_Vec(type)), ret = 0;
elseif (is_Mat(type)), ret = 1;
elseif (is_Cmat(type)), ret = 2;
elseif (is_Mat3(type)), ret = 3;
elseif (is_Cmat3(type)), ret = 4;
% elseif (is_Mat4d(type)), ret = 5;
elseif (is_Cmat4(type)), ret = 6;

elseif (is_Fvec(type)), ret = 20;
elseif (is_Fcmat(type)), ret = 22;

elseif (is_Diag(type)), ret = 31;
elseif (is_Mcoo(type)), ret = 32;
elseif (is_Mcooh(type)), ret = 33;
elseif (is_Cmobd(type)), ret = 34;

elseif (is_Svec(type)), ret = 40;
elseif (is_Dvec(type)), ret = 41;
elseif (is_Smat(type)), ret = 42;
elseif (is_Scmat(type)), ret = 43;
elseif (is_Dmat(type)), ret = 44;
elseif (is_Dcmat(type)), ret = 45;
elseif (is_Jcmat(type)), ret = 46;
elseif (is_Jcmat3d(type)), ret = 47;
elseif (is_Svec_c(type)), ret = 48;
elseif (is_Scmat_c(type)), ret = 49;
else, ret = -1;
end
end
