function ret = is_SvecC(T)
if ~ischar(T) || numel(T) < 4
    ret = false;
else
    ret = numel(regexp(T, 'Svec.*C?', 'once')) > 0;
end
end
