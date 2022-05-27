function [ind, ind1] = find_next(str, key, start)
[ind, ind1] = regexp(str(start:end), key, 'once');
ind = ind + start - 1;
ind1 = ind1 + start - 1;
end
