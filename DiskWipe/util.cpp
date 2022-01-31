#include "header.h"

using namespace std;

void wiper(const string& dir, const size_t& space, const int& passNo)
{
	string fname;
	for (int i = 1; i <= passNo; i++)
	{
		//Fill all space with 0
		fname = filemake(dir, space, 0x00, i);
		const char* fn1 = fname.c_str();
		remove(fn1);

		//Fill all space with 1
		string fname = filemake(dir, space, 0xFF, i);
		const char* fn2 = fname.c_str();
		remove(fn2);
	}

	system("cls");
	cout << "Finished " << passNo << " passes. Press any key to continue.";
	getchar();
}