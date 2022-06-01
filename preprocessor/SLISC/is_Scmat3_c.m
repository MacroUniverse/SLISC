function ret = is_Scmat3_c(T)
if ~ischar(T) || numel(T) < 6
    ret = false;
else
    ret = strcmp(T(1:6), 'Scmat3');
end
end
