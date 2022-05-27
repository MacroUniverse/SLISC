% determine if using Matlab or Octave

function ret = in_octave()
info = ver;
if strcmp(info(1).Name, 'MATLAB')
    ret = false;
else
    ret = true;
end
end
