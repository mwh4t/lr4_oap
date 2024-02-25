#include "functions.hpp"

void boardFunc() {
    json data;
    
    // парс данных из json
    json loadedData = jsonParserFunc();
    
    // вывод данных
    for (const auto& row : loadedData["board"]) {
        std::cout << row.get<std::string>() << std::endl;
    }
}
