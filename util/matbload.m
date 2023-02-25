% read ".matb" data file
% varnames is a cell array containing the names of the variables exported
% use mattload(fname, 'var1', 'var2', ...) to load specific variables

function varnames = matbload(fname, varargin)
fid = fopen(fname, 'r');
end_mark = 'Matb_End_of_File';
fseek(fid, -numel(end_mark), 'eof');
tmp = fread(fid, [1,numel(end_mark)], '*char');
if ~strcmp(end_mark, tmp)
    warning(['matb file corrupted Matb_End_of_File not found: ' fname]);
    varnames = [];
    return;
    % error(['file corrupted: ' fname]);
end
fseek(fid, -numel(end_mark)-8, 'eof');
numvars = fread(fid, 1, 'int64');
fseek(fid, 0, 'bof');
varnames = {};
Nloaded = 0;
for ii = 1:numvars
    Nname = fread(fid, 1, 'int64');
    if (Nname > 100)
        error('var name too long!');
    end
    varname = fread(fid, [1,Nname], '*char');
    matclass = fread(fid, 1, 'int64'); % 21:double, 41:complex
    if ~(matclass >= 0 && matclass < 60)
        error('illegal class!');
    end
    ndim = fread(fid, 1, 'int64');
    if ndim > 4
        error('illegal dimension!');
    end
    if (ndim == 0) % scalar
        matsize = [1,1];
    elseif (ndim == 1)
        matsize = [1,fread(fid, 1, 'int64')];
    else % ndim > 1
        matsize = fread(fid, [1,ndim], 'int64');
    end
    matnumel = prod(matsize);
    if numel(varargin) == 0
        load_it = true;
    else
        load_it = false;
        for jj = 1:numel(varargin)
            if strcmp(varname, varargin{jj})
                load_it = true; break;
            end
        end
    end
    if (load_it)
        if matclass == 1
            data = fread(fid, matnumel, 'char');
        elseif matclass == 2
            data = fread(fid, matnumel, 'int32');
        elseif matclass == 3
            data = fread(fid, matnumel, 'int64');
        elseif matclass == 21 % double
            data = fread(fid, matnumel, 'double');
        elseif matclass == 41 % complex
            data = fread(fid, matnumel*2, 'double');
            data = data(1:2:end) + 1i*data(2:2:end);
        else
            error('not implemented!');
        end
        if feof(fid), error('wrong number of elements!'); end
        data = reshape(data, matsize);
        assignin('caller', varname, data);
        Nloaded = Nloaded + 1;
        if Nloaded == numel(varargin)
            break;
        end
    else
        if matclass == 1 % char
            fseek(fid, matnumel, 'cof');
        elseif matclass == 2 % int32
            fseek(fid, matnumel*4, 'cof');
        elseif matclass == 3 % int64
            fseek(fid, matnumel*8, 'cof');
        elseif matclass == 21 % double
            fseek(fid, matnumel*8, 'cof');
        elseif matclass == 41 % complex
            fseek(fid, matnumel*16, 'cof');
        else
            error('not implemented!');
        end
        if feof(fid), error('wrong number of elements!'); end
    end
    varnames = [varnames, {varname}];
end
fclose(fid);
end
