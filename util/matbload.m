% read ".matb" data file
% varnames is a cell array containing the names of the variables exported
% use mattload(fname, 'var1', 'var2', ...) to load specific variables

function matbload(fname, varargin)
fid = fopen(fname, 'r');
for ii = 1:1e10
    Nname = fread(fid, 1, 'int64');
    if (Nname > 100)
        break;
    end
    varname = fread(fid, [1,Nname], '*char');
    matclass = fread(fid, 1, 'int64'); % 21:double, 41:complex
    if ~(matclass >= 0 && matclass < 60)
        break;
    end
    ndim = fread(fid, 1, 'int64');
    if ndim > 4
        break;
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
        if feof(fid), break; end
        data = reshape(data, matsize);
        assignin('caller', varname, data);
    else
        if matclass == 21 % double
            seekg(fid, matnumel*8, 'cof');
        elseif matclass == 41 % complex
            seekg(fid, matnumel*16, 'cof');
        else
            error('not implemented!');
        end
    end
end
end
