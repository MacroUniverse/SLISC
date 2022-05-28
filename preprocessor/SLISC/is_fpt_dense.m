function ret = is_fpt_dense(T)
ret = is_dense(T) && is_fpt(val_t(T));
end
