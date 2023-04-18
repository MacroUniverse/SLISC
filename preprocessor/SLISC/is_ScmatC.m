function ret = is_ScmatC(T)
if ~ischar(T) || numel(T) < 5
    ret = false;
else
    ret = numel(regexp(T, 'Scmat.*C?', 'once')) > 0;
end
end
