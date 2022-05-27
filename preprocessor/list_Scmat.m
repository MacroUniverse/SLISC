function ret = list_Scmat()
ret = [ list_integral; list_ftp; list_comp ];
for i = 1:numel(ret)
    ret{i} = ['Scmat' ret{i}];
end
end
