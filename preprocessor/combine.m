% types1 and types2 are numel N1 and N2 cell arrays
% results are N1*N2-by-2 cell arrays
function types = combine(types1, types2, ~)
if nargin == 2
    N1 = numel(types1); N2 = numel(types2);
    types = cell(N1*N2, 2);
    k = 0;
    for i = 1:N1
        for j = 1:N2
            k = k + 1;
            types(k, 1) = types1(i);
            types(k, 2) = types2(j);
        end
    end
elseif nargin == 3
    error('combine.m: unfinished!');
end
end
