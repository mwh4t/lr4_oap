#include "functions.hpp"
#include <cstdlib>

//bool isValidPlacement(std::string& v1, std::string& v2, std::string& v3, std::string& v4) {
//    // парс данных из json
//    json loadedData = jsonParserFunc();
//
//    std::set<std::string> validValues = loadedData["validValues"].get<std::set<std::string>>();
//    
//    return (validValues.find(v1) != validValues.end() &&
//            validValues.find(v2) != validValues.end() &&
//            validValues.find(v3) != validValues.end() &&
//            validValues.find(v4) != validValues.end() &&
//            v1 != v2 && v1 != v3 && v1 != v4 && v2 != v3 && v2 != v4 && v3 != v4);
//}

void placementFunc() {
    std::string v1; //, v2, v3, v4;

    std::cout << "\nВведите расположение 4-ёх 1-палубных кораблей:" << std::endl;

    std::cin >> v1;
    
    system("clear");

    if (v1 == "A1") {
        json loadedData = jsonParserFunc();
        
        std::vector<std::string> loadedBoard = loadedData["board"].get<std::vector<std::string>>();
        
        loadedBoard[2][3] = '#';
        
        loadedData["board"].clear();
        
        for (const auto& row : loadedBoard) {
            loadedData["board"].push_back(row);
        }
        
        std::ofstream loadedFile("/Users/matthewkorzunov/Desktop/Учёба/Колледж/2 курс/2 семестр/ОАП/ЛР 4 ОАП/LR4_OAP/LR4_OAP/other/json/data.json");
        loadedFile << std::setw(4) << loadedData << std::endl;
        loadedFile.close();
        
        boardFunc();
    }
}
