#ifndef functions_hpp
#define functions_hpp

#include "include/json.hpp"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>

// для удобства
using json = nlohmann::ordered_json;

void jsonLoaderFunc();
void jsonSaverFunc(const json& data);
json jsonParserFunc();

void clsFunc();
void boardFunc();
void placementFunc();

#endif
