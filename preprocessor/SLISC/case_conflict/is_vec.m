function ret = is_vec(T)
ret = numel(T) > 3 && strcmp(T(1:3), 'vec') && 'A' <= T(4) && T(4) <= 'Z';
end
