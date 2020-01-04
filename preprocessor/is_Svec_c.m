function ret = is_Svec_c(T)
ret = numel(regexp(T, 'Svec.*_c?', 'once')) > 0;
end
