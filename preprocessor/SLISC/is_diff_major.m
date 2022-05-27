function ret = is_diff_major(T, U)
if (is_cmajor(T) && is_rmajor(U))
    ret = true;
elseif (is_rmajor(T) && is_cmajor(U))
    ret = true;
else
    ret = false;
end
