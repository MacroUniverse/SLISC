function ret = is_Scmat_c(type)
ret = numel(regexp(type, 'Scmat.*_c?', 'once')) > 0;
end
