#ifndef DATA_BASE_API_H
#define DATA_BASE_API_H

#include "..\..\lib\types.h"
#include <vector>

#define DATA_BASE_VERSION       1


void data_base_init(void);
std::vector<std::string> data_base_parse_line(string line_to_parse);

#endif 