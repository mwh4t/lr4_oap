#include "functions.hpp"

void singleDeckPlacementFunc() {
    /*
     функция, позволяющая расположить 1-палубные корабли # на доске
     */
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
            std::map<std::string, std::pair<int, int>> validValues = deleteCellsFunc(loadedData, value);
            
            loadedData["validValues"] = validValues;
            for (const auto& row : loadedBoard) {
                loadedData["boards"].push_back(row);
            }
            
            jsonSaverFunc(loadedData);
            
            boardsFunc();
        } else {
            boardsFunc();
            std::cout << "\nНекорректное расположение!" << std::endl;
            i--;
        }
    }
}

void twoDeckPlacementFunc() {
    /*
     функция, позволяющая расположить 2-палубные корабли # на доске
     */
    json loadedData = jsonParserFunc();
    
    for (int i = 0; i < 3; i++) {
        std::string value;
        
        std::cout << "\nВведите расположение " << i+1 << "-го " << "2-палубного корабля:" << std::endl;
        
        std::cin >> value;
        
        // преобразование строки в верхний регистр
        for (char& c : value) {
            c = std::toupper(c);
        }
        
        for (int j = 0; j < 2; j++) {
            if (loadedData["validValues"].contains(value)) {
                std::vector<std::string> loadedBoard = loadedData["boards"].get<std::vector<std::string>>();
                
                std::vector<int> coordinates = loadedData["validValues"][value].get<std::vector<int>>();
                int row = coordinates[0];
                int col = coordinates[1];
                
                loadedBoard[row][col] = '#';
                
                loadedData["boards"].clear();
                
                // удаление клеток вокруг выбранной из json
//                std::map<std::string, std::pair<int, int>> validValues = deleteCellsFunc(loadedData, value);
                
//                loadedData["validValues"] = validValues;
                for (const auto& row : loadedBoard) {
                    loadedData["boards"].push_back(row);
                }
                
                jsonSaverFunc(loadedData);
                
                boardsFunc();
            } else {
                boardsFunc();
                std::cout << "\nНекорректное расположение!" << std::endl;
                i--;
            }
        }
    }
}

void placementFunc() {
//    singleDeckPlacementFunc();
    twoDeckPlacementFunc();
}