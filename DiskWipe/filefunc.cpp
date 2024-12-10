#include "header.h"

using namespace std;

string filemake(const string& dir, const size_t& space, const unsigned char& fillbit, const int& curpass)
{
	string filename = dir + "diskwipetempfile";

	while(filesystem::exists(filename))
    {
        filename += "1";
    }

    FILE *fp = fopen(filename.c_str(), "wb");
	size_t write_size = sizeof(unsigned char);

    unsigned char fillbits[CLUSTERSIZE];
    memset((void*)&fillbits[0], fillbit ,CLUSTERSIZE);

	for(size_t i = 0, j = 0; i < space;)
	{
		if ((space - i) > CLUSTERSIZE)
		{
			fwrite(&fillbits[0], write_size, CLUSTERSIZE, fp);
			i += CLUSTERSIZE;
		}
		else
		{
            unsigned char fillbitsN[space-i];
            memset((void*)&fillbitsN[0], fillbit, space-i);
			fwrite(&fillbitsN[0], write_size, (space-i), fp);
			i += CLUSTERSIZE;
		}
		if((j % 16) == 0)
		{
        	printf("\rCompleted %zu/%zu", i, space);
		}
		j++;
	}

	fclose(fp);

	return filename;
}
