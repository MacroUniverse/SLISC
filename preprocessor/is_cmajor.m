function ret = is_cmajor(T)
if (is_Cmat(T) || is_Fcmat(T) || is_Cmat3(T) ||...
        is_Cmat4(T) || is_Scmat(T) || is_Scmat_c(T) || is_Dcmat(T))
    ret = true;
else
    ret = false;
end
end
