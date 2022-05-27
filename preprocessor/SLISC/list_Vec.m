function ret = list_Vec
ret = [ list_integral; list_ftp; list_comp ];
for i = 1:numel(ret)
    ret{i} = ['Vec' ret{i}];
end
end
