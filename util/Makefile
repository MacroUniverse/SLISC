
flags = -std=c++11 -Wall -Wno-reorder -Wno-misleading-indentation -static -std=c++11 -fopenmp -O3 -fmax-errors=1 -fext-numeric-literals -D SLS_USE_QUAD_MATH -fext-numeric-literals -D NDEBUG


matt2matb: matt2matb.cpp
	cd ..; cd -;
	g++ $(flags) matt2matb.cpp -o matt2matb

matb2matt: matb2matt.cpp
	cd ..; cd -;
	g++ $(flags) matb2matt.cpp -o matb2matt

matb_q2d: matb_q2d.cpp
	cd ..; cd -;
	g++ $(flags) matb_q2d.cpp -o matb_q2d

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
