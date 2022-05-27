% list all dense containers
function ret = list_Dvec()
ret = [ list_integral; list_ftp; list_comp ];
for i = 1:numel(ret)
    ret{i} = ['Dvec' ret{i}];
end
end
