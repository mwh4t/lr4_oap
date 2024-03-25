#include "functions.hpp"

void clsFunc() {
    /*
     функция для очистки терминала
     */
    std::cout << std::string(50, '\n');
}

void boardsFunc() {
    /*
     функция для вывода досок в терминал
     */
    // парс данных из json
    json loadedData = jsonParserFunc();
    
    // очистка терминала
    clsFunc();
    
    // вывод данных
    for (const auto& row : loadedData["boards"]) {
        std::cout << row.get<std::string>() << std::endl;
    }
}

void invalidDirection() {
    boardsFunc();
    std::cout << "\nНекорректное направление!" << std::endl;
}

std::string elementGeneration() {
    /*
     Функция для генерации случайного элемента
     */
    char letter = 'A' + rand() % 10;
    int number = 1 + rand() % 10;

    std::stringstream ss;
    ss << number;
    std::string value = std::string(1, letter) + ss.str();

    return value;
}

char directionGeneration() {
    /*
     Функция для генерации случайного нарпавления
     */
    char letters[] = {'u', 'd', 'r', 'l'};
    char direction = letters[rand() % 4];

    return direction;
}
