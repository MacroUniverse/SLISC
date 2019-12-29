function ret = is_fundamental(T)
ret = is_arithmetic(T) || is_void(T) || is_nullptr(T);
end
