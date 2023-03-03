
flags = -std=c++11 -Wall -Wno-reorder -Wno-misleading-indentation -static -std=c++11 -fopenmp -O3 -fmax-errors=1 -fext-numeric-literals -D SLS_USE_QUAD_MATH -fext-numeric-literals -D NDEBUG

bins = matt2matb matb2matt matb_q2d matbrename mattinfo matbinfo cat_files

all: $(bins)

install:
	cp $(bins) -t /usr/local/bin/

clean:
	rm -f $(bins)


matt2matb: matt2matb.cpp
	g++ $(flags) matt2matb.cpp -o matt2matb

matb2matt: matb2matt.cpp
	g++ $(flags) matb2matt.cpp -o matb2matt

matb_q2d: matb_q2d.cpp
	g++ $(flags) matb_q2d.cpp -o matb_q2d

matbrename: matbrename.cpp
	g++ $(flags) matbrename.cpp -o matbrename

mattinfo: mattinfo.cpp
	g++ $(flags) mattinfo.cpp -o mattinfo

matbinfo: matbinfo.cpp
	g++ $(flags) matbinfo.cpp -o matbinfo

cat_files: cat_files.cpp
	g++ $(flags) cat_files.cpp -o cat_files
