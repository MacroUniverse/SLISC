function ret = is_Svec_c(T)
if ~ischar(T) || numel(T) < 4
    ret = false;
else
    ret = numel(regexp(T, 'Svec.*_c?', 'once')) > 0;
end
end
