% get a continuous block, each line starts with '//% '
% str(start) is first char of '//% '
% `ind` is the last position of the block in `str`
function [ret, ind] = get_meta_block(str, start)
ind = start;
while true
    ind = next_line(str, ind);
    if isempty(ind)
        ind = numel(str); break;
    end
    if ~strcmp(str(ind:ind+3), '//% ')
        ind = ind-1; break;
    end
    ind = ind + 3;
end
ret = strrep(str(start:ind), '//%', '');
end
