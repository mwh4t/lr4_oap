#include "utils/functions.hpp"

int main() {
    clsFunc();
    
    std::cout << BOLDCYAN << "Морской Бой\n" << RESET;
    
    std::cout << CYAN << "gh: " << RESET << "github.com/mwh4t\n\n";
    
    std::string value;
    std::cout << CYAN << "enter " << RESET << "- продолжить, " << CYAN << "q " << RESET << "- выход:\n";
    std::getline(std::cin, value);
    
    if (value == "q" || value == "Q") {
        exit(0);
    } else {
        // функция для загрузки данных в json
        jsonLoaderFunc();
        
        // функция расстановки кораблей
        placementFunc();
        
        // функция очерёдных ходов
        matchFunc();
    }
    
    return 0;
}
