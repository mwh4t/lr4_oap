#include <iostream>

std::string r1 = " 1 □ □ □ □ □ □ □ □ □ □\n"; // ■
std::string r2 = " 2 □ □ □ □ □ □ □ □ □ □\n"; // ×
std::string r3 = " 3 □ □ □ □ □ □ □ □ □ □\n"; // •
std::string r4 = " 4 □ □ □ □ □ □ □ □ □ □\n";
std::string r5 = " 5 □ □ □ □ □ □ □ □ □ □\n";
std::string r6 = " 6 □ □ □ □ □ □ □ □ □ □\n";
std::string r7 = " 7 □ □ □ □ □ □ □ □ □ □\n";
std::string r8 = " 8 □ □ □ □ □ □ □ □ □ □\n";
std::string r9 = " 9 □ □ □ □ □ □ □ □ □ □\n";
std::string r10 = "10 □ □ □ □ □ □ □ □ □ □\n";

void displayBoard() {
    std::cout << "Ваша доска:" << std::endl;
    std::cout << "   A B C D E F G H I J\n" << r1 << r2 << r3 << r4 << r5 << r6 << r7 << r8 << r9 << r10 << std::endl;
}

bool isValidInput(const std::string& input) {
    if (input.length() != 2) {
        return false; // Длина ввода должна быть ровно 2 символа
    }

    char letter = input[0];
    char digit = input[1];

    // Проверка на букву из диапазона А-К или а-к
    if (!(std::isalpha(letter) && ((letter >= 'A' && letter <= 'K') || (letter >= 'a' && letter <= 'k')))) {
        return false;
    }

    // Проверка на цифру от 1 до 10
    if (!(std::isdigit(digit) && digit >= '1' && digit <= '9')) {
        return false;
    }

    return true;
}

void shipPlacement() {
    std::string v1, v2, v3, v4;

    std::cout << "Введите расположение 4-ёх 1-палубных кораблей:" << std::endl;

    do {
        std::cin >> v1;
    } while (!isValidInput(v1));

    do {
        std::cin >> v2;
    } while (!isValidInput(v2));

    do {
        std::cin >> v3;
    } while (!isValidInput(v3));

    do {
        std::cin >> v4;
    } while (!isValidInput(v4));
}

int main() {
    displayBoard();
    shipPlacement();
    
    return 0;
}
