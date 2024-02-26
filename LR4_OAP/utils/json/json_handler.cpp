#include "functions.hpp"

void jsonSaverFunc(const json& data) {
    std::ofstream file("/Users/matthewkorzunov/Desktop/Учёба/Колледж/2 курс/2 семестр/ОАП/ЛР 4 ОАП/LR4_OAP/LR4_OAP/utils/json/data.json");
    file << std::setw(4) << data << std::endl;
    file.close();
}

json jsonParserFunc() {
    std::ifstream readFile("/Users/matthewkorzunov/Desktop/Учёба/Колледж/2 курс/2 семестр/ОАП/ЛР 4 ОАП/LR4_OAP/LR4_OAP/utils/json/data.json");
    json loadedData;
    readFile >> loadedData;
    readFile.close();
    
    return loadedData;
}
