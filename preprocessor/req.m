function req(name, param, reset)
if nargin == 2
    reset = false;
end
global tem_db;
ind = tem_search(name);
if ind < 0
    error(['template not found: ' name]);
end
if size(tem_db(ind).param, 2) ~= size(param, 2)
    error(['template ' name ' does not take ' num2str(size(param, 2))...
        ' parameters!']);
end
N = size(param, 1);
for i = 1:N
    iparam = search_cell_row(tem_db(ind).param, param(i,:));
    if iparam < 0
        tem_db(ind).param = [tem_db(ind).param; param(i,:)];
    elseif reset
        tem_db(ind).done(iparam) = false;
        tem_db(ind).out{iparam} = '';
    end
end
Np = size(tem_db(ind).param, 1);
tem_db(ind).done(end+1:Np) = false;
tem_db(ind).out(end+1:Np) = {''};
end
