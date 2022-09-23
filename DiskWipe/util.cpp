#include "header.h"

using namespace std;

void wiper(const string& dir, const size_t& space, const int& passNo)
{
	string fname;
	for (int i = 1; i <= passNo; i++)
	{
	    printf("Starting pass %d\n", i);
		//Fill all space with 0
		fname = filemake(dir, space, 0x00, i);
		remove(fname.c_str());
		printf("\nFilled with 0\n");

		//Fill all space with 1
		fname = filemake(dir, space, 0xFF, i);
		remove(fname.c_str());
		printf("\nFilled with 1\n");
	}

    printf("Finished %d passes. Press any key to continue.\n", passNo);
	getchar();
}
