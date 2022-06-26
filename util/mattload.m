% read ".matt" data file
% consider using A = fscanf(fileID,formatSpec,sizeA) to read data in
% different class types. Thus saving space.
% varnames is a cell array containing the names of the variables exported
% use mattload(fname, 'var1', 'var2', ...) to load specific variables

function varargout = mattload(fname, varargin)
%fileID = fopen(fname,'r');
%if fileID == -1, error('file does not exist'); end
%data = fscanf(fileID, '%f');
data = dlmread(fname); data = data(:).';
ind = 1;
nvar = data(end);
names = cell(1,nvar);
for ii = 1:nvar
    namesize = data(ind); ind = ind + 1;
    names{ii} = char(data(ind : ind+namesize-1));
    ind = ind + namesize;
    if numel(varargin) == 0
        load_it = true;
    else
        load_it = false;
        for jj = 1:numel(varargin)
            if strcmp(names{ii}, varargin{jj})
                load_it = true; break;
            end
        end
    end
    matclass = data(ind); ind = ind + 1;
    ndim = data(ind); ind = ind + 1;
    if (ndim == 0) % scalar
        matsize = [1,1];
    elseif (ndim == 1)
        matsize = [1,data(ind)];
    else % ndim > 1
        matsize = data(ind : ind+ndim-1);
    end
    ind = ind + ndim;
    matnumel = prod(matsize);
    if (load_it)
        if matclass >= 20 && matclass < 60 % floating point types
            A = zeros(matsize);
        elseif matclass >= 0 && matclass < 20 % integral types
            A = zeros(matsize);
        else
            error('unknown data type');
        end
        A(:) = data(ind:ind+matnumel-1);
        assignin('caller', names{ii},A);
    end
    ind = ind + matnumel;
end
if nargout == 0
    varargout = {};
else
    varargout{1} = names;
end
end
