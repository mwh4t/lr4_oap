#include "functions.hpp"

std::map<std::string, std::pair<int, int>> deleteCellsFunc(std::map<std::string, std::pair<int, int>>& validValues, std::string& value) {
    /*
     функция, удаляющая все клетки вокруг выбранной (в т. ч. выбранную) из json-файла
     */
    // удаление элемента с севера
    std::string northValue = value;
    if (northValue.back() == '0') {
        northValue = northValue[0] + std::string("9");
    } else {
        northValue.back()--;
    }
    validValues.erase(northValue);
    
    // удаление элемента с северо-востока
    std::string northeastValue = value;
    if (northeastValue.back() == '0') {
        northeastValue.front()++;
        northeastValue = northeastValue[0] + std::string("9");
    } else {
        northeastValue.front()++;
        northeastValue.back()--;
    }
    validValues.erase(northeastValue);
    
    // удаление элемента с востока
    std::string eastValue = value;
    eastValue.front()++;
    validValues.erase(eastValue);
    
    // удаление элемента с юго-востока
    std::string southeastValue = value;
    if (southeastValue.back() == '9') {
        southeastValue.front()++;
        southeastValue = southeastValue[0] + std::string("10");
    } else {
        southeastValue.front()++;
        southeastValue.back()++;
    }
    validValues.erase(southeastValue);
    
    // удаление элемента с юга
    std::string southValue = value;
    if (southValue.back() == '9') {
        southValue = southValue[0] + std::string("10");
    } else {
        southValue.back()++;
    }
    validValues.erase(southValue);
    
    // удаление элемента с юго-запада
    std::string southwestValue = value;
    if (southwestValue.back() == '9') {
        southwestValue.front()--;
        southwestValue = southwestValue[0] + std::string("10");
    } else {
        southwestValue.front()--;
        southwestValue.back()++;
    }
    validValues.erase(southwestValue);
    
    // удаление элемента с запада
    std::string westValue = value;
    westValue.front()--;
    validValues.erase(westValue);
    
    // удаление элемента с северо-запада
    std::string northwestValue = value;
    if (northwestValue.back() == '0') {
        northwestValue.front()--;
        northwestValue = northwestValue[0] + std::string("9");
    } else {
        northwestValue.front()--;
        northwestValue.back()--;
    }
    validValues.erase(northwestValue);
    
    // удаление того же элемента
    validValues.erase(value);
    
    return validValues;
}
