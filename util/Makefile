
flags = -Wall -Wno-reorder -Wno-misleading-indentation -static -std=c++11 -fopenmp -O3 -fmax-errors=1 -D SLS_USE_CBLAS -D SLS_USE_LAPACKE -D SLS_USE_GSL

matt2matb: matt2matb.cpp
	g++ $(flags) matt2matb.cpp -o matt2matb

matb2matt: matb2matt.cpp
	g++ $(flags) matb2matt.cpp -o matb2matt
