#include "functions.hpp"

std::map<std::string, std::pair<int, int>> deleteCellsFunc(const json& loadedData, const std::string& value) {
    /*
     функция, удаляющая все клетки вокруг выбранной (в т. ч. выбранную) из json-файла
     */
    std::map<std::string, std::pair<int, int>> validValues = loadedData["validValues"];
    
    // удаление элемента с севера
    auto itNorthEl = validValues.find(value);
    std::pair<int, int> northEl = {(itNorthEl->second.first)-1, itNorthEl->second.second};
    for (auto it = validValues.begin(); it != validValues.end();) {
        if (it->second == northEl) it = validValues.erase(it);
        else it++;
    }
    
    // удаление элемента с северо-востока
    auto itNorthEastEl = validValues.find(value);
    std::pair<int, int> northEastEl = {(itNorthEastEl->second.first)-1, (itNorthEastEl->second.second)+2};
    for (auto it = validValues.begin(); it != validValues.end();) {
        if (it->second == northEastEl) it = validValues.erase(it);
        else it++;
    }
    
    // удаление элемента с востока
    auto itEastEl = validValues.find(value);
    std::pair<int, int> eastEl = {itEastEl->second.first, (itEastEl->second.second)+2};
    for (auto it = validValues.begin(); it != validValues.end();) {
        if (it->second == eastEl) it = validValues.erase(it);
        else it++;
    }
    
    // удаление элемента с юго-востока
    auto itSouthEastEl = validValues.find(value);
    std::pair<int, int> southEastEl = {(itSouthEastEl->second.first)+1, (itSouthEastEl->second.second)+2};
    for (auto it = validValues.begin(); it != validValues.end();) {
        if (it->second == southEastEl) it = validValues.erase(it);
        else it++;
    }
    
    // удаление элемента с юга
    auto itSouthEl = validValues.find(value);
    std::pair<int, int> southEl = {(itSouthEl->second.first)+1, itSouthEl->second.second};
    for (auto it = validValues.begin(); it != validValues.end();) {
        if (it->second == southEl) it = validValues.erase(it);
        else it++;
    }
    
    // удаление элемента с юго-запада
    auto itSouthWestEl = validValues.find(value);
    std::pair<int, int> southWestEl = {(itSouthWestEl->second.first)+1, (itSouthWestEl->second.second)-2};
    for (auto it = validValues.begin(); it != validValues.end();) {
        if (it->second == southWestEl) it = validValues.erase(it);
        else it++;
    }
    
    // удаление элемента с запада
    auto itWestEl = validValues.find(value);
    std::pair<int, int> westEl = {itWestEl->second.first, (itWestEl->second.second)-2};
    for (auto it = validValues.begin(); it != validValues.end(); ) {
        if (it->second == westEl) it = validValues.erase(it);
        else it++;
    }
    
    // удаление элемента с северо-запада
    auto itNorthWestEl = validValues.find(value);
    std::pair<int, int> northWestEl = {(itNorthWestEl->second.first)-1, (itNorthWestEl->second.second)-2};
    for (auto it = validValues.begin(); it != validValues.end();) {
        if (it->second == northWestEl) it = validValues.erase(it);
        else it++;
    }
    
    // удаление того же элемента
    auto itSameEl = validValues.find(value);
    std::pair<int, int> SameEl = {itSameEl->second.first, itSameEl->second.second};
    for (auto it = validValues.begin(); it != validValues.end();) {
        if (it->second == SameEl) it = validValues.erase(it);
        else it++;
    }
    
    return validValues;
}
