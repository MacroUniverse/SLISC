function ret = quad_math_if(varargin)
if has_quad(varargin{:})
    ret = '#ifdef SLS_USE_QUAD_MATH';
else
    ret = '';
end
end
