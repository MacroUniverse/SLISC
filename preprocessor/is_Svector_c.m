function ret = is_Svector_c(type)
ret = numel(regexp(type, 'Svec.*_c?', 'once')) > 0;
end
