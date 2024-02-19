#include "functions.hpp"
#include "include/json.hpp"
#include <vector>
#include <iostream>
#include <fstream>

// для удобства
using json = nlohmann::json;

void boardFunc() {
    std::cout << "Ваша доска:" << std::endl;
    std::cout << "   A B C D E F G H I J" << std::endl;
    
    // открытие файла
    std::ifstream file("/Users/matthewkorzunov/Desktop/Учёба/Колледж/2 курс/2 семестр/ЛР 4 ОАП/LR4_OAP/LR4_OAP/other/data.json");

    // парс json из файла
    json loadedData;
    file >> loadedData;

    file.close();

    // вывод данных
    for (auto& row : loadedData) {
        std::string content = row["content"];
        std::cout << content << std::endl;
    }
}
