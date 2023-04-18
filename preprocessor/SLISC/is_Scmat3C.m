function ret = is_Scmat3C(T)
if ~ischar(T) || numel(T) < 5
    ret = false;
else
    ret = numel(regexp(T, 'Scmat3.*C?', 'once')) > 0;
end
end
