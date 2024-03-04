#include "functions.hpp"

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
