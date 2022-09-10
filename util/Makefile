
flags = -Wall -Wno-reorder -Wno-misleading-indentation -static -std=c++11 -fopenmp -O3 -fmax-errors=1 -D SLS_USE_CBLAS -D SLS_USE_LAPACKE -D SLS_USE_GSL # -D NDEBUG

matt2matb: matt2matb.cpp
	cd ..; cd -;
	g++ $(flags) matt2matb.cpp -o matt2matb

matb2matt: matb2matt.cpp
	cd ..; cd -;
	g++ $(flags) matb2matt.cpp -o matb2matt

matbrename: matbrename.cpp
	cd ..; cd -;
	g++ $(flags) matbrename.cpp -o matbrename

matbinfo: matbinfo.cpp
	cd ..; cd -;
	g++ $(flags) matbinfo.cpp -o matbinfo

mattinfo: mattinfo.cpp
	cd ..; cd -;
	g++ $(flags) mattinfo.cpp -o mattinfo

cat_files: cat_files.cpp
	cd ..; cd -;
	g++ $(flags) cat_files.cpp -o cat_files
