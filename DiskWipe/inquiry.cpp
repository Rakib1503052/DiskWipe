#include "header.h"

using namespace std;

map<string, size_t> space_inquiry(const string& dir)
{
	error_code ec;

	const std::filesystem::space_info si = std::filesystem::space(dir, ec);
	
	map<string, size_t> ret;

	ret["capacity"] = si.capacity;
	ret["free"] = si.free;
	ret["available"] = si.available;

	return ret;
}