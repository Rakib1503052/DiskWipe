#include "header.h"
#include <fstream>
#include <bitset>

using namespace std;

string filemake(const string& dir, const size_t& space, const char& fill, const int& curpass)
{
	string filename = dir + "wipe.tmp";
	ofstream FILE;
	FILE.open(filename);
	double progress = 0.0;
	double printflag = -1.0;
	
	bitset<8> fillbit(fill);
	std::cout << std::setprecision(2) << std::fixed;

	for(size_t i = 0; i < space;)
	{
		if ((space - i) > CLUSTERSIZE)
		{
			FILE << string(CLUSTERSIZE, fill);
			i += CLUSTERSIZE;
		}
		else
		{
			FILE << string((space - i), fill);
			i += CLUSTERSIZE;
		}
		progress = double(i) / double(space) * 100;
		if (progress >= (printflag + 0.01))
		{
			system("cls");
			cout << "Pass " << curpass << ": Fill '" << fillbit << "': Progress " << progress << "%" << endl;
			printflag = progress;
		}
	}

	FILE.close();

	return filename;
}