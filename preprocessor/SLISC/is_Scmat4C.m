function ret = is_Scmat4C(T)
if ~ischar(T) || numel(T) < 7
    ret = false;
else
    ret = strcmp(T(1:7), 'Scmat4C');
end
end
