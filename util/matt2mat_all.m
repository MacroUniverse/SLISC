% convert all .matt files in the current folder and subfolders to .mat files
function matt2mat_all(replace)
if (nargin == 0)
    replace = false;
end
names = dir('**/*.matt');
for ii = 1:numel(names)
    fname = [names(ii).folder '\' names(ii).name];
    disp(fname);
    matt2mat(fname, replace);
end
end
