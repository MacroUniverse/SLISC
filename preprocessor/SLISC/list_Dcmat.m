function ret = list_Dcmat()
ret = [ list_integral; list_ftp; list_comp ];
for i = 1:numel(ret)
    ret{i} = ['Dcmat' ret{i}];
end
end
