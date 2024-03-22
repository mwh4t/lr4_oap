#include "functions.hpp"

void playerMoveFunc() {
    /*
     функция для хода игрока
     */
    json loadedData = jsonParserFunc();
    
    for (; true; ) {
        std::string value;
        
        std::cout << "\nВаш ход: ";
        std::cin >> value;
        
        // преобразование строки в верхний регистр
        for (char& c : value) {
            c = std::toupper(c);
        }
        
        if (loadedData["values"].contains(value)) {
            std::vector<std::pair<int, int>> botMoves = loadedData["botMoves"];
            
            std::vector<std::vector<int>> coordinates = loadedData["values"][value].get<std::vector<std::vector<int>>>();
            int row = coordinates[1][0];
            int col = coordinates[1][1];
            std::pair<int, int> coordinates1 = {row, col};
            
            std::vector<std::string> loadedBoard = loadedData["boards"].get<std::vector<std::string>>();
            
            std::vector<std::vector<int>> coordinates2 = loadedData["values"][value].get<std::vector<std::vector<int>>>();
            int row1 = coordinates2[1][0];
            int col1 = coordinates2[1][1];
            
            if (std::find(botMoves.begin(), botMoves.end(), coordinates1) != botMoves.end()) {
                loadedBoard[row1][col1] = 'X';
                
                loadedData["boards"].clear();
                
                for (const auto& row : loadedBoard) {
                    loadedData["boards"].push_back(row);
                }
                
                jsonSaverFunc(loadedData);
                
                boardsFunc();
            } else {
                loadedBoard[row1][col1] = '.';
                
                loadedData["boards"].clear();
                
                for (const auto& row : loadedBoard) {
                    loadedData["boards"].push_back(row);
                }
                
                jsonSaverFunc(loadedData);
                
                boardsFunc();
            }
        } else {
            boardsFunc();
            std::cout << "\nНекорректный ход!" << std::endl;
        }
    }
}

void botMoveFunc() {
    /*
     функция для хода бота
     */
}

void matchFunc() {
    playerMoveFunc();
}
