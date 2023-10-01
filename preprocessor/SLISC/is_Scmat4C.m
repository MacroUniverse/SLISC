function ret = is_Scmat4C(T)
if ~ischar(T) || numel(T) < 6
    ret = false;
else
    ret = strcmp(T(1:6), 'Scmat4') && T(end) == 'C';
end
end
