// cat split files two one. name scheme:
// fname-00, fname-01, ....
// move wrong-sized files to folder "bad_size_files"
// move incomplete list of files to folder "not_complete"

#include "../SLISC-64/util/time.h"
#include "../SLISC-64/file/file.h"

using namespace slisc;

int main()
{
	// === settings ===
	Long Nfile = 22;
	Long fsize = 5000000000, fsize1 = 3700000000;
	Str prefix = "plot-k32", suffix = ".plot";
	// ================

	Str fname, fname_i, tmp_str;
	vecStr names;
	bool restart;
	while (true) {
		restart = false;
		file_list(names, "./");

		// find a prefix*suffix-XX
		bool found = false;
		for (Long i = 0; i < size(names); ++i) {
			if (names[i].substr(0, prefix.size()) != prefix || names[i].substr(names[i].size()-3-suffix.size(), suffix.size()) != suffix)
				continue;
			fname = names[i];
			fname.pop_back(); fname.pop_back(); fname.pop_back();
			found = true; break;
		}
		if (found == false) {
			cout << "finished!" << endl; break;
		}

		// check file number
		for (Long i = 0; i < Nfile; ++i) {
			fname_i = fname + "-" + num2str(i, 2);
			if (!file_exist(fname_i)) {
				cout << "not_complete: " << fname_i << endl;
				ensure_dir("not_complete");
				exec_str(tmp_str, "mv " + fname + "-* -t not_complete/");
				restart = true;
				break;
			}
		}
		if (restart)
			continue;
		
		// check file size
		for (Long i = 0; i < Nfile; ++i) {
			fname_i = fname + "-" + num2str(i, 2);
			Long sz = file_size(fname_i);
			if ((i < Nfile-1 && sz != fsize)
				|| (i == Nfile-1 && sz < fsize1)) {
				cout << "wrong file size: " << fname_i << endl;
				ensure_dir("bad_size_files");
				exec_str(tmp_str, "mv " + fname + "-* -t bad_size_files/");
				restart = true;
				break;
			}
		}
		if (restart)
			continue;
		
		cout << "catting: " + fname << endl;
		exec_str(tmp_str, "cat " + fname + "-* > " + fname);
		ensure_dir("recycle");
		exec_str(tmp_str, "mv " + fname + "-* -t recycle");
	}
}
