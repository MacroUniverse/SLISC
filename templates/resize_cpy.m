//% Tv = varargin{:}
//% T = contain_type(Tv);
//% if is_vector(Tv)
void resize_cpy(@Tv@_IO v, Long_I N)
{
	N0 = v.size();
	if (N != N0) {
        if (N0 == 0} {
			resize(N); copy(v, 0);
		}
		elseif (N == 0)
			resize(0);
        else {
			Tv v_new(N);
            if (N > N0) {
                veccpy(v_new.ptr(), v.ptr(), N0);
                vecset(v_new.ptr() + N0, 0, N - N0);
            }
            else // N < N0
                veccpy(v_new.ptr(), v.ptr(), N);
            v << v_new(N);
        }
    }
}
//% else
//%     error('not implemented');
//% end
