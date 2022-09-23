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
	int progress = 0;

    unsigned char fillbits[CLUSTERSIZE];
    memset((void*)&fillbits[0], fillbit ,CLUSTERSIZE);

	for(size_t i = 0; i < space;)
	{
		if ((space - i) > CLUSTERSIZE)
		{
			fwrite(&fillbits[0], sizeof(unsigned char), CLUSTERSIZE, fp);
			i += CLUSTERSIZE;
		}
		else
		{
            unsigned char fillbitsN[space-i];
            memset((void*)&fillbitsN[0], fillbit, space-i);
			fwrite(&fillbitsN[0], sizeof(unsigned char), (space-i), fp);
			i += CLUSTERSIZE;
		}

		progress = i * 100 / space;
        printf("\rPass: %d, Progress: %d%%", curpass, progress);
	}

	fclose(fp);

	return filename;
}
