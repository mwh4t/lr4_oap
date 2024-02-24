#include "functions.hpp"

void boardFunc() {
    // парс данных из json
    json loadedData = jsonParserFunc();
    
    // вывод данных
    std::cout << loadedData["urBoard"].get<std::string>() << std::endl;
    std::cout << loadedData["letters"].get<std::string>() << std::endl;
    for (const auto& row : loadedData["rows"]) {
        std::cout << row.get<std::string>() << std::endl;
    }
}
