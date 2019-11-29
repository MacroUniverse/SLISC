function ret = is_cmajor(type)
if (is_Cmat(type) || is_Fcmat(type) || is_Cmat3(type) ||...
        is_Scmat(type) || is_Scmat_c(type) || is_Dcmat(type))
    ret = true;
else
    ret = false;
end
end
