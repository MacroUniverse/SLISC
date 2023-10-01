function ret = is_Scmat3(T)
if ~ischar(T) || numel(T) < 6
    ret = false;
else
    ret = strcmp(T(1:6), 'Scmat3') && T(end) ~= 'C';
end
end
