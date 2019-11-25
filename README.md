# SLISC0
* try to implement SLISC without template
* use Matlab to do metaprogramming

# Code generation using template file

A template file (`plus.tp`) looks like
```c++
//% [Tz, Tx, Ty] = varargin{:};
void plus(@Tz@_O, @Tx@_I x, @Ty@_I y)
{
//% if is_scalar(Tz) && is_scalar(Tx) && is_scalar(Ty)
    z = x + y;
//% elseif is_vector(Tz)
//%     if is_vector(Tx) && is_scalar(Ty)
	for (int i = 0; i < z.size(); ++i)
		z[i] = x[i] + y;
//%     elseif is_scalar(Tx) && is_vector(Ty)
	for (int i = 0; i < z.size(); ++i)
		z[i] = x + y[i];
//%		elseif is_vector(Tx) && is_vector(Ty)
	for (int i = 0; i < z.size(); ++i)
		z[i] = x[i] + y[i];
//%     end
//% end
}
```

To generate code, use e.g.
`code = preproc(plus.tp, 'VecDoub', 'CmatFloat', 'VecInt');`
and the output will be

```c++
void plus(VecDoub_O z, CmatFloat_I x, VecInt_I y)
{
	for (int i = 0; i < z.size(); ++i)
		z[i] = x + y[i];
}
```
