% convert all .matb files in the current folder and subfolders to .mat files
function matb2mat_all(replace)
if (nargin == 0)
    replace = false;
end
names = dir('**/*.matb');
for ii = 1:numel(names)
    fname = [names(ii).folder '\' names(ii).name];
    disp(fname);
    matb2mat(fname, replace);
end
end
