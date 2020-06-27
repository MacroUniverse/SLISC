function ret = is_real_dense(T)
ret = is_dense(T) && is_real(value_type(T));
end
