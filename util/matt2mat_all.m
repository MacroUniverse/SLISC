% convert all .matt files in the current folder and subfolders to .mat files
function matt2mat_all(delete_matt)
if (nargin == 0)
    delete_matt = false;
end
names = dir('**/*.matt');
parfor ii = 1:numel(names)
    fname = [names(ii).folder '\' names(ii).name];
    disp(fname);
    matt2mat(fname, delete_matt);
end
end
