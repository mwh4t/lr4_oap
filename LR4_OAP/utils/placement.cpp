#include "functions.hpp"

std::map<std::string, std::pair<int, int>> deleteSurroundingCells(const json& loadedData, const std::string& value) {
    std::map<std::string, std::pair<int, int>> validValues = loadedData["validValues"];
    
    // удаление элемента с севера
    auto itNorthEl = validValues.find(value);
    std::pair<int, int> northEl = {(itNorthEl->second.first)-1, itNorthEl->second.second};
    for (auto it = validValues.begin(); it != validValues.end(); ) {
        // Проверка значения элемента
        if (it->second == northEl) {
            // Удаление элемента
            it = validValues.erase(it);
        } else {
            it++;
        }
    }
    
    // удаление элемента с северо-востока
    auto itNorthEastEl = validValues.find(value);
    std::pair<int, int> northEastEl = {(itNorthEastEl->second.first)-1, (itNorthEastEl->second.second)+2};
    for (auto it = validValues.begin(); it != validValues.end(); ) {
        // Проверка значения элемента
        if (it->second == northEastEl) {
            // Удаление элемента
            it = validValues.erase(it);
        } else {
            it++;
        }
    }
    
    // удаление элемента с востока
    auto itEastEl = validValues.find(value);
    std::pair<int, int> eastEl = {itEastEl->second.first, (itEastEl->second.second)+2};
    for (auto it = validValues.begin(); it != validValues.end(); ) {
        // Проверка значения элемента
        if (it->second == eastEl) {
            // Удаление элемента
            it = validValues.erase(it);
        } else {
            it++;
        }
    }
    
    // удаление элемента с юго-востока
    auto itSouthEastEl = validValues.find(value);
    std::pair<int, int> southEastEl = {(itSouthEastEl->second.first)+1, (itSouthEastEl->second.second)+2};
    for (auto it = validValues.begin(); it != validValues.end(); ) {
        // Проверка значения элемента
        if (it->second == southEastEl) {
            // Удаление элемента
            it = validValues.erase(it);
        } else {
            it++;
        }
    }
    
    // удаление элемента с юга
    auto itSouthEl = validValues.find(value);
    std::pair<int, int> southEl = {(itSouthEl->second.first)+1, itSouthEl->second.second};
    for (auto it = validValues.begin(); it != validValues.end(); ) {
        // Проверка значения элемента
        if (it->second == southEl) {
            // Удаление элемента
            it = validValues.erase(it);
        } else {
            it++;
        }
    }
    
    // удаление элемента с юго-запада
    auto itSouthWestEl = validValues.find(value);
    std::pair<int, int> southWestEl = {(itSouthWestEl->second.first)+1, (itSouthWestEl->second.second)-2};
    for (auto it = validValues.begin(); it != validValues.end(); ) {
        // Проверка значения элемента
        if (it->second == southWestEl) {
            // Удаление элемента
            it = validValues.erase(it);
        } else {
            it++;
        }
    }
    
    // удаление элемента с запада
    auto itWestEl = validValues.find(value);
    std::pair<int, int> westEl = {itWestEl->second.first, (itWestEl->second.second)-2};
    for (auto it = validValues.begin(); it != validValues.end(); ) {
        // Проверка значения элемента
        if (it->second == westEl) {
            // Удаление элемента
            it = validValues.erase(it);
        } else {
            it++;
        }
    }
    
    // удаление элемента с северо-запада
    auto itNorthWestEl = validValues.find(value);
    std::pair<int, int> northWestEl = {(itNorthWestEl->second.first)-1, (itNorthWestEl->second.second)-2};
    for (auto it = validValues.begin(); it != validValues.end(); ) {
        // Проверка значения элемента
        if (it->second == northWestEl) {
            // Удаление элемента
            it = validValues.erase(it);
        } else {
            it++;
        }
    }
    
    // удаление того же элемента
    auto itSameEl = validValues.find(value);
    std::pair<int, int> SameEl = {itSameEl->second.first, itSameEl->second.second};
    for (auto it = validValues.begin(); it != validValues.end(); ) {
        // Проверка значения элемента
        if (it->second == SameEl) {
            // Удаление элемента
            it = validValues.erase(it);
        } else {
            it++;
        }
    }
    
    return validValues;
}

void singleDeckPlacementFunc() {
    json loadedData = jsonParserFunc();
    
    for (int i = 0; i < 4; i++) {
        std::string value;
        
        std::cout << "\nВведите расположение " << i+1 << "-го " << "1-палубного корабля:" << std::endl;
        
        std::cin >> value;
        
        // преобразование строки в верхний регистр
        for (char& c : value) {
            c = std::toupper(c);
        }
        
        if (loadedData["validValues"].contains(value)) {
            std::vector<std::string> loadedBoard = loadedData["boards"].get<std::vector<std::string>>();
            
            std::vector<int> coordinates = loadedData["validValues"][value].get<std::vector<int>>();
            int row = coordinates[0];
            int col = coordinates[1];
            
            loadedBoard[row][col] = '#';
            
            loadedData["boards"].clear();
            
            // удаление клеток вокруг выбранной из json
            std::map<std::string, std::pair<int, int>> validValues = deleteSurroundingCells(loadedData, value);
            
            loadedData["validValues"] = validValues;
            for (const auto& row : loadedBoard) {
                loadedData["boards"].push_back(row);
            }
            
            jsonSaverFunc(loadedData);
            
            boardsFunc();
        } else {
            std::cout << "Некорректное расположение!" << std::endl;
            i--;
        }
    }
}

//void twoDeckPlacementFunc() {
//    json loadedData = jsonParserFunc();
//    
//    for (int i = 0; i < 3; i++) {
//        std::string value1, value2;
//        
//        std::cout << "\nВведите расположение " << i+1 << "-го " << "2-палубного корабля:" << std::endl;
//        
//        std::cin >> value1 >> value2;
//        
//        // преобразование строк в верхний регистр
//        for (char& c : value1) {
//            c = std::toupper(c);
//        }
//        for (char& c : value2) {
//            c = std::toupper(c);
//        }
//        
//        if (loadedData["validValues"].contains(value1) &&
//            loadedData["validValues"].contains(value2) &&
//            uniqueValues.count(value1) == 0 &&
//            uniqueValues.count(value2) == 0) {
//            // добавление в контейнер
//            uniqueValues.insert(value1);
//            uniqueValues.insert(value2);
//            
//            for (const std::string& v : uniqueValues) {
//                std::cout << v << std::endl;
//            }
//        } else {
//            std::cout << "Некорректное расположение!" << std::endl;
//            i--;
//        }
//    }
//}

void placementFunc() {
    singleDeckPlacementFunc();
//    twoDeckPlacementFunc();
}
