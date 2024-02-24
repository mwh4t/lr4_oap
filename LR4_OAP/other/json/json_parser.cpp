#include "functions.hpp"

json jsonParserFunc() {
    std::ifstream readFile("/Users/matthewkorzunov/Desktop/Учёба/Колледж/2 курс/2 семестр/ОАП/ЛР 4 ОАП/LR4_OAP/LR4_OAP/other/json/data.json");
    json loadedData;
    readFile >> loadedData;
    readFile.close();
    
    return loadedData;
}
