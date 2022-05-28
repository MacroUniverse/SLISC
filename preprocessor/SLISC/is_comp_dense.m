function ret = is_comp_dense(T)
ret = is_dense(T) && is_comp(val_t(T));
end
