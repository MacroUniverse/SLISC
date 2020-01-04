function ret = is_vector(T)
ret = any(strfind(T, 'vector')) || strcmp(T(1:3), 'vec');
end
