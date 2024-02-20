#include "functions.hpp"
#include "include/json.hpp"
#include <vector>
#include <iostream>
#include <fstream>

// для удобства
using json = nlohmann::json;

void boardFunc() {
    std::vector<std::string> rows = {
        " 1 □ □ □ □ □ □ □ □ □ □",
        " 2 □ □ □ □ □ □ □ □ □ □",
        " 3 □ □ □ □ □ □ □ □ □ □",
        " 4 □ □ □ □ □ □ □ □ □ □",
        " 5 □ □ □ □ □ □ □ □ □ □",
        " 6 □ □ □ □ □ □ □ □ □ □",
        " 7 □ □ □ □ □ □ □ □ □ □",
        " 8 □ □ □ □ □ □ □ □ □ □",
        " 9 □ □ □ □ □ □ □ □ □ □",
        "10 □ □ □ □ □ □ □ □ □ □"
    };

    json data;

    // добавление данных
    data["urBoard"] = "Ваша доска:";
    data["letters"] = "   A B C D E F G H I J";
    for (const auto& row : rows) {
        data["rows"].push_back(row);
    }

    // записывание json в файл
    std::ofstream file("/Users/matthewkorzunov/Desktop/Учёба/Колледж/2 курс/2 семестр/ЛР 4 ОАП/LR4_OAP/LR4_OAP/other/data.json");
    file << std::setw(4) << data << std::endl;
    file.close();

    // парс json из файла
    std::ifstream readFile("/Users/matthewkorzunov/Desktop/Учёба/Колледж/2 курс/2 семестр/ЛР 4 ОАП/LR4_OAP/LR4_OAP/other/data.json");
    json loadedData;
    readFile >> loadedData;
    readFile.close();

//    std::string urBoard = loadedData["urBoard"];
//    std::string letters = loadedData["letters"];
    
    // вывод данных
    std::cout << loadedData["urBoard"].get<std::string>() << std::endl;
    std::cout << loadedData["letters"].get<std::string>() << std::endl;
    for (const auto& row : loadedData["rows"]) {
        std::cout << row.get<std::string>() << std::endl;
    }
}
