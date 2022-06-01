function ret = is_Vec(T)
if ~ischar(T) || numel(T) < 3
    ret = false;
else
    ret = strcmp(T(1:3), 'Vec');
end
end
