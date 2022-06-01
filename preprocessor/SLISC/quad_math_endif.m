function ret = quad_math_endif(varargin)
if has_quad(varargin{:})
    ret = '#endif // SLS_USE_QUAD_MATH';
else
    ret = '';
end
end
