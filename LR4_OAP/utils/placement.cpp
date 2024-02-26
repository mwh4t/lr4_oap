#include "functions.hpp"

void placementFunc() {
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
