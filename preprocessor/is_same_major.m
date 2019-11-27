function ret = is_same_major(T, U)
if (is_cmajor(T) && is_cmajor(U))
    ret = true;
elseif (is_rmajor(T) && is_rmajor(U))
    ret = true;
elseif (ndim(T) == 1 && ndim(T) == 1)
    ret = true;
else
    ret = false;
end
