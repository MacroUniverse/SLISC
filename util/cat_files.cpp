// cat split files two one. name scheme:
// fname-00, fname-01, ....
// move wrong-sized files to folder "bad_size_files"
// move incomplete list of files to folder "not_complete"

#include "../SLISC/time.h"
#include "../SLISC/file.h"

using namespace slisc;

int main()
{
	// === settings ===
	Long Nfile = 22;
	Long fsize = 5000000000, fsize1 = 2000000000;
	// ================

	Str fname, fname_i;
	vecStr names;
	Bool restart;
	while (true) {
		restart = false;
		file_list(names, "./");

		// find a plot-k32*.plot-*
		for (Long i = 0; i < size(names); ++i) {
			if (names[i].substr(0, 8) != "plot-k32")
				continue;
			fname = names[i];
			fname.pop_back(); fname.pop_back(); fname.pop_back();
		}

		// check file number
		for (Long i = 0; i < Nfile; ++i) {
			fname_i = fname + "-" + num2str(i, 2);
			if (!file_exist(fname_i)) {
				ensure_dir("not_complete");
				exec_str("mv " + fname + "-* -t not_complete/");
				restart = true;
				break;
			}
		}
		if (restart)
			continue;
		
		// check file size
		for (Long i = 0; i < Nfile; ++i) {
			if ((i < Nfile-1 && file_size(fname_i) != fsize)
				|| (i == Nfile-1 && file_size(fname_i) < fsize1)) {
				ensure_dir("bad_size_files");
				cout << "wrong file size: " << fname_i << endl;
				exec_str("mv " + fname + "-* -t bad_files/");
				restart = true;
				break;
			}
		}
		if (restart)
			continue;
		
		cout << "catting: " + fname << endl;
		exec_str("cat " + fname + "-* > " + fname);
		ensure_dir("recycle");
		exec_str("mv " + fname + "-* -t recycle");
	}
}
