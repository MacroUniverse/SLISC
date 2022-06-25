% convert all .matt files in the current folder to .mat files
function matt2mat_all
names = ls('*.matt');
for ii = 1:size(names,1)
    disp(names(ii,:));
    matt2mat(strtrim(names(ii,:)));
end
end
