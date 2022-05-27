function ret = quad_math_endif(nargin)
flag = false;
for type = nargin
    if is_quad(type{1})
        flag = true; break;
    end
end
if flag
    ret = '#endif';
else
    ret = '';
end
end
