// report memory usage
// tested on WSL, ut19, Beocat

#include <iostream>
#include <cstring>

long long parseLine(char* line){
    // This assumes that a digit will be found and the line ends in " Kb".
    long long i = strlen(line);
    const char* p = line;
    while (*p <'0' || *p > '9') p++;
    line[i-3] = '\0';
    i = atoi(p);
    return i;
}

long long ram_usage(){ //Note: this value is in KiB!
    FILE* file = fopen("/proc/self/status", "r");
    long long result = -1;
    char line[128];

    while (fgets(line, 128, file) != NULL){
        if (strncmp(line, "VmRSS:", 6) == 0){
            result = parseLine(line);
            break;
        }
    }
    fclose(file);
    return result;
}

int main()
{
	using namespace std;
	long long N = 1024*(long long)1024*1024*10;
	char *s = new char[N];
	s[0] = 'a';
	for (long long i = 1; i < N; ++i)
	s[i] = s[i-1] + 1;
	cout << s[N-1] << endl;
	cout << "ram usage = " << ram_usage()/1024. << "MiB" << endl;
	delete [] s;
}