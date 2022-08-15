% determine if using Matlab or Octave

function ret = in_octave()
    ret = exist('OCTAVE_VERSION', 'builtin');
end
