function ret = is_Scmat4(T)
if ~ischar(T) || numel(T) < 6
    ret = false;
else
    ret = strcmp(T(1:6), 'Scmat4');
end
end
