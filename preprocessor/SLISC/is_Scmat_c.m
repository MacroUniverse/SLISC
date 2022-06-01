function ret = is_Scmat_c(T)
if ~ischar(T) || numel(T) < 5
    ret = false;
else
    ret = numel(regexp(T, 'Scmat.*_c?', 'once')) > 0;
end
end
