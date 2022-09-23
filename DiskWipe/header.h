#ifndef DW_HEADER_H
#define DW_HEADER_H

#include <filesystem>
#include <system_error>
#include <string>
#include <cstring>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define CLUSTERSIZE 65536

bool space_inquiry(const std::string&, std::error_code&, std::filesystem::space_info&);
std::string filemake(const std::string&, const size_t&, const unsigned char&, const int&);
void wiper(const std::string&, const size_t&, const int&);

#endif // DW_HEADER_H
