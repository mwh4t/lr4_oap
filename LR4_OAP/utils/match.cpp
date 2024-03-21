#include "functions.hpp"

void playerMoveFunc() {
    /*
     функция для хода игрока
     */
    json loadedData = jsonParserFunc();
    
    std::string value;
    
    std::cout << "\nВаш ход: ";
    std::cin >> value;
    
    // преобразование строки в верхний регистр
    for (char& c : value) {
        c = std::toupper(c);
    }
    
    if (!loadedData["botValidValues"].contains(value)) {
        std::vector<std::string> loadedBoard = loadedData["boards"].get<std::vector<std::string>>();
        
        std::vector<int> coordinates = loadedData["values"][value].get<std::vector<int>>();
        int row = coordinates[0];
        int col = coordinates[1];
        
        loadedBoard[row][col] = 'X';
        
        loadedData["boards"].clear();
        
        for (const auto& row : loadedBoard) {
            loadedData["boards"].push_back(row);
        }
        
        jsonSaverFunc(loadedData);
        
        boardsFunc();
    } else {
        std::cout << "esheshesh" << std::endl;
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
