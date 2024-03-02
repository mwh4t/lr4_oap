#include "functions.hpp"

void boardsFunc() {
    // парс данных из json
    json loadedData = jsonParserFunc();
    
    // очистка терминала
    clsFunc();
    
    // вывод данных
    for (const auto& row : loadedData["boards"]) {
        std::cout << row.get<std::string>() << std::endl;
    }
}
