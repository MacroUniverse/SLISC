% convert all .matb files in the current folder and subfolders to .mat files
function mat2matt_all(delete_mat)
if (nargin == 0)
    delete_mat = false;
end
names = dir('**/*.mat');
parfor ii = 1:numel(names)
    fname = [names(ii).folder '\' names(ii).name];
    disp(fname);
    mat2mat(fname, delete_mat);
end
end
