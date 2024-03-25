#ifndef functions_hpp
#define functions_hpp

#include "include/json.hpp"
#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <sstream>
#include <fstream>
#include <vector>
#include <set>
#include <map>

#define RESET "\033[0m"
#define BLACK "\033[30m" // Black
#define RED "\033[31m" // Red
#define GREEN "\033[32m" // Green
#define YELLOW "\033[33m" // Yellow
#define BLUE "\033[34m" // Blue
#define MAGENTA "\033[35m" // Magenta
#define CYAN "\033[36m" // Cyan
#define WHITE "\033[37m" // White
#define BOLDBLACK "\033[1m\033[30m" // Bold Black
#define BOLDRED "\033[1m\033[31m" // Bold Red
#define BOLDGREEN "\033[1m\033[32m" // Bold Green
#define BOLDYELLOW "\033[1m\033[33m" // Bold Yellow
#define BOLDBLUE "\033[1m\033[34m" // Bold Blue
#define BOLDMAGENTA "\033[1m\033[35m" // Bold Magenta
#define BOLDCYAN "\033[1m\033[36m" // Bold Cyan
#define BOLDWHITE "\033[1m\033[37m" // Bold White

// для удобства
using json = nlohmann::ordered_json;

void jsonLoaderFunc();
void jsonSaverFunc(const json& data);
json jsonParserFunc();

void clsFunc();
void boardsFunc();
std::map<std::string, std::pair<int, int>> deleteCellsFunc(std::map<std::string, std::pair<int, int>>& validValues, std::string& value);
void placementFunc();
void invalidDirection();
std::string elementGeneration();
char directionGeneration();
void matchFunc();

#endif
