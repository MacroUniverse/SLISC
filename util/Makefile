
flags = -Wall -Wno-reorder -Wno-misleading-indentation -static -std=c++11 -fopenmp -g -fmax-errors=1 -D SLS_USE_CBLAS -D SLS_USE_LAPACKE -D SLS_USE_GSL # -D NDEBUG

matt2matb: matt2matb.cpp
	cd ..; make h; cd -;
	g++ $(flags) matt2matb.cpp -o matt2matb

matb2matt: matb2matt.cpp
	cd ..; make h; cd -;
	g++ $(flags) matb2matt.cpp -o matb2matt

matbrename: matbrename.cpp
	cd ..; make h; cd -;
	g++ $(flags) matbrename.cpp -o matbrename

matbinfo: matbinfo.cpp
	cd ..; make h; cd -;
	g++ $(flags) matbinfo.cpp -o matbinfo

cat_files: cat_files.cpp
	cd ..; make h; cd -;
	g++ $(flags) cat_files.cpp -o cat_files
