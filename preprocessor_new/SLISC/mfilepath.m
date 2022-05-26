% return the full directory and name of the current ".m" file
% 'path' has '/' ending (works on all OS)
% 'name' does not include '.m'

function [path, name] = mfilepath
% try to use call stack, file don't have to be opened
s = dbstack(1,'-completenames');
if ~isempty(s)
    path = s(1).file;
    [path, name] = fileparts(path);
    if ~isequal(name, 'LiveEditorEvaluationHelperESectionEval')
        path = strrep(path, '\', '/');
        path = [path '/'];
        return;
    end
end

% this function called from command line (or with F9 key)
% get the current opened file
% type 'doc matlab.desktop.editor' for documentation
temp = matlab.desktop.editor.getActive();
if isempty(temp)
    warning('This function called in command line while no file is opened.');
    path = './'; name = '';
    return;
end
path = temp.Filename;
[path, name] = fileparts(path);
path = strrep(path, '\', '/');
path = [path '/'];
end
