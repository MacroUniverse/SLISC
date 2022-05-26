function ret = quad_math_if(nargin)
flag = false;
for type = nargin
    if is_quad(type{1})
        flag = true; break;
    end
end
if flag
    ret = '#ifdef SLS_USE_QUAD_MATH';
else
    ret = '';
end
end
