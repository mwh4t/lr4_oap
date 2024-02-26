#include "functions.hpp"

void boardFunc() {
    // парс данных из json
    json loadedData = jsonParserFunc();
    
    // очистка терминала
    clsFunc();
    
    // вывод данных
    for (const auto& row : loadedData["board"]) {
        std::cout << row.get<std::string>() << std::endl;
    }
}
