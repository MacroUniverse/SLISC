function ret = is_fundamental(type)
ret = is_arithmetic(type) || is_void(type) || is_nullptr(type);
end
