#include "functions.hpp"

void playerMoveFunc() {
    /*
     функция для хода игрока
     */
    json loadedData = jsonParserFunc();
    
    std::string value;
    
    std::cout << "\nВаш ход:" << std::endl;
    std::cin >> value;
    
    // преобразование строки в верхний регистр
    for (char& c : value) {
        c = std::toupper(c);
    }
    
    
}

void botMoveFunc() {
    /*
     функция для хода бота
     */
}

void matchFunc() {
    /*
     функция для очерёдности ходов
     */
    playerMoveFunc();
}
