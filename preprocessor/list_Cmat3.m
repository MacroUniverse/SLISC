function ret = list_Cmat3()
ret = [ list_integral; list_ftp; list_comp ];
for i = 1:numel(ret)
    ret{i} = ['Cmat3' ret{i}];
end
end
