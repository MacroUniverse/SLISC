function ret = is_Scmat_c(T)
ret = numel(regexp(T, 'Scmat.*_c?', 'once')) > 0;
end
