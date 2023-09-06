% save matlab variables to matt format
% mat2matt('my_file.matt', 'name1', var1, 'name2', var2, ...)

function mattsave(matt_file, varargin)
sep = ' ';
data = "";
prec = 17;
if mod(numel(varargin), 2) ~= 0
    error('mat2matt must have odd number of arguments');
end
Nvars = numel(varargin)/2;
start_ind = zeros(1, Nvars); % starting ind of each var, 0-based!

for i = 1 : Nvars
    varname = varargin{2*i-1};
    var = varargin{2*i};
    varname_len = numel(varname);

    % var name
    if i == 1
        data = data + varname_len;
    else
        start_ind(i) = strlength(data) + strlength(sep);
        data = data + sep + varname_len;
    end
    for c = varname
        data = data + sep + double(c);
    end

    % var type
    if isreal(var)
        type_num = 21; % double
    elseif ~isreal(var)
        type_num = 41; % complex
    else
        error('not implemented!');
    end
    data = data + sep + type_num;

    % var size
    if isscalar(var)
        Ndim = 0;
    else
        Ndim = ndims(var);
    end
    data = data + sep + Ndim;
    for j = 1:Ndim
        data = data + sep + size(var, j);
    end

    % var data
    for j = 1:numel(var)
        if isreal(var(j)) % real
            data = data + sep + num2str(var(j),prec);
        else % complex
            elm_r = real(var(j)); elm_i = imag(var(j));
            if elm_i < 0
                imag_sign = '-';
            else
                imag_sign = '+';
            end
            data = data + sep + num2str(elm_r,prec) + imag_sign ...
                 + num2str(abs(elm_i),prec) + 'i';
        end
    end
end

% write var position indices
start_ind = flip(start_ind);
for i = 1 : Nvars
    data = data + sep + start_ind(i);
end
% write # of vars
data = data + sep + Nvars + sep + sep;
    
% write to file
fileID = fopen(matt_file, 'w');
if fileID == -1
    error('Failed to open the file for writing.');
end
fprintf(fileID, '%s', data);
fclose(fileID);

end
