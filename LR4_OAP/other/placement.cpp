#include "functions.hpp"

bool isValidPlacement(std::string& v1, std::string& v2, std::string& v3, std::string& v4) {
    // парс данных из json
    json loadedData = jsonParserFunc();

    std::set<std::string> validValues = loadedData["validValues"].get<std::set<std::string>>();
    
    return (validValues.find(v1) != validValues.end() &&
            validValues.find(v2) != validValues.end() &&
            validValues.find(v3) != validValues.end() &&
            validValues.find(v4) != validValues.end() &&
            v1 != v2 && v1 != v3 && v1 != v4 && v2 != v3 && v2 != v4 && v3 != v4);
}

void placementFunc() {
    std::string v1, v2, v3, v4;

    std::cout << "\nВведите расположение 4-ёх 1-палубных кораблей:" << std::endl;

    std::cin >> v1 >> v2 >> v3 >> v4;

    if (isValidPlacement(v1, v2, v3, v4)) {
        std::cout << "Расположение кораблей корректно." << std::endl;
    } else {
        std::cout << "Некорректное расположение кораблей." << std::endl;
    }
}
