#include "header.h"

using namespace std;

bool space_inquiry(const string& dir, error_code& ec, filesystem::space_info& si)
{
    if(filesystem::exists(dir,ec))
    {
        si = filesystem::space(dir, ec);
        return true;
    }
    else
    {
        return false;
    }
}
