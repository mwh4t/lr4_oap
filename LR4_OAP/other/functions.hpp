#ifndef functions_hpp
#define functions_hpp

#include <locale.h>
#include "include/json.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <set>

// для удобства
using json = nlohmann::ordered_json;

void jsonLoaderFunc();
json jsonParserFunc();

void boardFunc();
void placementFunc();

#endif
