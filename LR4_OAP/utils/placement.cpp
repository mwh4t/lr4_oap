#include "functions.hpp"

std::set<std::string> uniqueValues;  // контейнер для уникальных значений

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
        
        if (loadedData["validValues"].contains(value) && uniqueValues.count(value) == 0) {
            uniqueValues.insert(value); // добавление в контейнер
            
            std::vector<std::string> loadedBoard = loadedData["board"].get<std::vector<std::string>>();
            
            std::vector<int> coordinates = loadedData["validValues"][value].get<std::vector<int>>();
            int row = coordinates[0];
            int col = coordinates[1];
            
            loadedBoard[row][col] = '#';
            
            loadedData["board"].clear();
            
            for (const auto& row : loadedBoard) {
                loadedData["board"].push_back(row);
            }
            
            jsonSaverFunc(loadedData);
            
            boardFunc();
        } else {
            std::cout << "Некорректное расположение!" << std::endl;
            i--;
        }
    }
}

void twoDeckPlacementFunc() {
    json loadedData = jsonParserFunc();
    
    for (int i = 0; i < 3; i++) {
        std::string value1, value2;
        
        std::cout << "\nВведите расположение " << i+1 << "-го " << "2-палубного корабля:" << std::endl;
        
        std::cin >> value1 >> value2;
        
        // преобразование строк в верхний регистр
        for (char& c : value1) {
            c = std::toupper(c);
        }
        for (char& c : value2) {
            c = std::toupper(c);
        }
        
        if (loadedData["validValues"].contains(value1) &&
            loadedData["validValues"].contains(value2) &&
            uniqueValues.count(value1) == 0 &&
            uniqueValues.count(value2) == 0) {
            // добавление в контейнер
            uniqueValues.insert(value1);
            uniqueValues.insert(value2);
            
            for (const std::string& v : uniqueValues) {
                std::cout << v << std::endl;
            }
        } else {
            std::cout << "Некорректное расположение!" << std::endl;
            i--;
        }
    }
}

void placementFunc() {
    singleDeckPlacementFunc();
//    twoDeckPlacementFunc();
}
