#include "functions.hpp"

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
