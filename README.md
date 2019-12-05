# SLISC0
* try to implement SLISC without template
* use Matlab to do metaprogramming

# Code generation using template file

A template file (`demo.h.in`) looks like
```c++
#include <complex>
#include <vector>
using namespace std;

//% types = {
//%     'vector<double>', 'Int', 'vector<float>';
//%     'vector<complex<double>>', 'vector<complex<double>>', 'vector<Int>';
//% };
//%----------------------------------
//% [Tz, Tx, Ty] = varargin{:};
void plus(@Tz@ &z, const @Tx@ &x, const @Ty@ &y)
{
//% if is_vector(Tz) && is_vector(Tx) && is_scalar(Ty)
	for (size_t i = 0; i < z.size(); ++i)
		z[i] = x[i] + y;
//% elseif is_vector(Tz) && is_scalar(Tx) && is_vector(Ty)
	for (size_t i = 0; i < z.size(); ++i)
		z[i] = x + y[i];
//% elseif is_vector(Tz) && is_vector(Tx) && is_vector(Ty)
	for (size_t i = 0; i < z.size(); ++i)
		z[i] = x[i] + y[i];
//% else
//%     error('not implemented!');
//% end
}
//%-----------------------------------
```

Using `$octave auto_gen.m`, the generated file `demo.h` looks like
```c++
#include <complex>
#include <vector>
using namespace std;

void plus(vector<double> &z, const Int &x, const vector<float> &y)
{
	for (size_t i = 0; i < z.size(); ++i)
		z[i] = x + y[i];
}

void plus(vector<complex<double>> &z, const vector<complex<double>> &x, const vector<Int> &y)
{
	for (size_t i = 0; i < z.size(); ++i)
		z[i] = x[i] + y[i];
}
```
