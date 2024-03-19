#include "functions.hpp"

void singleDeckPlacementFunc() {
    /*
     функция, позволяющая расположить 1-палубные корабли # на доске
     */
    json loadedData = jsonParserFunc();
    
    for (int i = 0; i < 4; i++) {
        std::string value;
        
        std::cout << "\nВведите расположение " << i+1 << "-го " << "1-палубного корабля:" << std::endl;
        
        std::cin >> value;
        
        // преобразование строки в верхний регистр
        for (char& c : value) {
            c = std::toupper(c);
        }
        
        if (loadedData["playerValidValues"].contains(value)) {
            std::vector<std::string> loadedBoard = loadedData["boards"].get<std::vector<std::string>>();
            
            std::vector<int> coordinates = loadedData["playerValidValues"][value].get<std::vector<int>>();
            int row = coordinates[0];
            int col = coordinates[1];
            
            loadedBoard[row][col] = '#';
            
            loadedData["boards"].clear();
            
            // удаление клеток вокруг выбранной из json
            std::map<std::string, std::pair<int, int>> validValues = loadedData["playerValidValues"];
            std::map<std::string, std::pair<int, int>> validValues1 = deleteCellsFunc(validValues, value);
            
            loadedData["playerValidValues"] = validValues1;
            for (const auto& row : loadedBoard) {
                loadedData["boards"].push_back(row);
            }
            
            jsonSaverFunc(loadedData);
            
            boardsFunc();
        } else {
            boardsFunc();
            std::cout << "\nНекорректное расположение!" << std::endl;
            i--;
        }
    }
}

void twoDeckPlacementFunc() {
    /*
     функция, позволяющая расположить 2-палубные корабли ## на доске
     */
    json loadedData = jsonParserFunc();
    
    for (int i = 0; i < 3; i++) {
        std::string value, direction;
        
        std::cout << "\nВведите расположение " << i+1 << "-го " << "2-палубного корабля:" << std::endl;
        
        std::cout << "1-ая палуба: ";
        std::cin >> value;
        
        std::cout << "Введите направление корабля (u - верх, d - низ, r - право, l - лево): ";
        std::cin >> direction;
        
        // преобразование строки в верхний регистр
        for (char& c : value) {
            c = std::toupper(c);
        }
        
        if (loadedData["playerValidValues"].contains(value)) {
            std::vector<std::string> loadedBoard = loadedData["boards"].get<std::vector<std::string>>();
            
            std::vector<int> coordinates = loadedData["playerValidValues"][value].get<std::vector<int>>();
            int row = coordinates[0];
            int col = coordinates[1];
            
            loadedBoard[row][col] = '#';
            
            std::string value1 = value;
            switch (direction[0]) {
                case 'u':
                    value1.back()--;
                    if (loadedData["playerValidValues"].contains(value1)) {
                        row--;
                        loadedBoard[row][col] = '#';
                    } else {
                        invalidDirection();
                        i--;
                        continue;
                    }
                    break;
                case 'd':
                    value1.back()++;
                    if (loadedData["playerValidValues"].contains(value1)) {
                        row++;
                        loadedBoard[row][col] = '#';
                    } else {
                        invalidDirection();
                        i--;
                        continue;
                    }
                    break;
                case 'r':
                    value1.front()++;
                    if (loadedData["playerValidValues"].contains(value1)) {
                        col += 2;
                        loadedBoard[row][col] = '#';
                    } else {
                        invalidDirection();
                        i--;
                        continue;
                    }
                    break;
                case 'l':
                    value1.front()--;
                    std::cout << value << std::endl;
                    if (loadedData["playerValidValues"].contains(value1)) {
                        col -= 2;
                        loadedBoard[row][col] = '#';
                    } else {
                        invalidDirection();
                        i--;
                        continue;
                    }
                    break;
                default:
                    invalidDirection();
                    i--;
            }

            
            loadedData["boards"].clear();
            
            // удаление клеток вокруг выбранной из json
            std::map<std::string, std::pair<int, int>> validValues = loadedData["playerValidValues"];
            std::map<std::string, std::pair<int, int>> validValues1 = deleteCellsFunc(validValues, value);
            std::map<std::string, std::pair<int, int>> validValues2 = deleteCellsFunc(validValues1, value1);
            
            loadedData["playerValidValues"] = validValues2;
            for (const auto& row : loadedBoard) {
                loadedData["boards"].push_back(row);
            }
            
            jsonSaverFunc(loadedData);
            
            boardsFunc();
        } else {
            boardsFunc();
            std::cout << "\nНекорректное расположение!" << std::endl;
            i--;
        }
    }
}

void threeDeckPlacementFunc() {
    /*
     функция, позволяющая расположить 3-палубные корабли ### на доске
     */
    json loadedData = jsonParserFunc();
    
    for (int i = 0; i < 2; i++) {
        std::string value, direction;
        
        std::cout << "\nВведите расположение " << i+1 << "-го " << "3-палубного корабля:" << std::endl;
        
        std::cout << "1-ая палуба: ";
        std::cin >> value;
        
        std::cout << "Введите направление корабля (u - верх, d - низ, r - право, l - лево): ";
        std::cin >> direction;
        
        // преобразование строки в верхний регистр
        for (char& c : value) {
            c = std::toupper(c);
        }
        
        if (loadedData["playerValidValues"].contains(value)) {
            std::vector<std::string> loadedBoard = loadedData["boards"].get<std::vector<std::string>>();
            
            std::vector<int> coordinates = loadedData["playerValidValues"][value].get<std::vector<int>>();
            int row = coordinates[0];
            int col = coordinates[1];
            
            loadedBoard[row][col] = '#';
            
            std::string value1 = value;
            std::string value2 = value1;
            switch (direction[0]) {
                case 'u':
                    value1.back()--;
                    value2.back() -= 2;
                    if (loadedData["playerValidValues"].contains(value1) && loadedData["playerValidValues"].contains(value2)) {
                        row--;
                        loadedBoard[row][col] = '#';
                        row--;
                        loadedBoard[row][col] = '#';
                    } else {
                        invalidDirection();
                        i--;
                        continue;
                    }
                    break;
                case 'd':
                    value1.back()++;
                    value2.back() += 2;
                    if (loadedData["playerValidValues"].contains(value1) && loadedData["playerValidValues"].contains(value2)) {
                        row++;
                        loadedBoard[row][col] = '#';
                        row++;
                        loadedBoard[row][col] = '#';
                    } else {
                        invalidDirection();
                        i--;
                        continue;
                    }
                    break;
                case 'r':
                    value1.front()++;
                    value2.front() += 2;
                    if (loadedData["playerValidValues"].contains(value1) && loadedData["playerValidValues"].contains(value2)) {
                        col += 2;
                        loadedBoard[row][col] = '#';
                        col += 2;
                        loadedBoard[row][col] = '#';
                    } else {
                        invalidDirection();
                        i--;
                        continue;
                    }
                    break;
                case 'l':
                    value1.front()--;
                    value2.front() -= 2;
                    if (loadedData["playerValidValues"].contains(value1) && loadedData["playerValidValues"].contains(value2)) {
                        col -= 2;
                        loadedBoard[row][col] = '#';
                        col -= 2;
                        loadedBoard[row][col] = '#';
                    } else {
                        invalidDirection();
                        i--;
                        continue;
                    }
                    break;
                default:
                    invalidDirection();
                    i--;
            }

            
            loadedData["boards"].clear();
            
            // удаление клеток вокруг выбранной из json
            std::map<std::string, std::pair<int, int>> validValues = loadedData["playerValidValues"];
            std::map<std::string, std::pair<int, int>> validValues1 = deleteCellsFunc(validValues, value);
            std::map<std::string, std::pair<int, int>> validValues2 = deleteCellsFunc(validValues1, value1);
            std::map<std::string, std::pair<int, int>> validValues3 = deleteCellsFunc(validValues2, value2);
            
            loadedData["playerValidValues"] = validValues3;
            for (const auto& row : loadedBoard) {
                loadedData["boards"].push_back(row);
            }
            
            jsonSaverFunc(loadedData);
            
            boardsFunc();
        } else {
            boardsFunc();
            std::cout << "\nНекорректное расположение!" << std::endl;
            i--;
        }
    }
}

void fourDeckPlacementFunc() {
    /*
     функция, позволяющая расположить 4-палубные корабли #### на доске
     */
    json loadedData = jsonParserFunc();
    
    for (int i = 0; i < 1; i++) {
        std::string value, direction;
        
        std::cout << "\nВведите расположение " << i+1 << "-го " << "4-палубного корабля:" << std::endl;
        
        std::cout << "1-ая палуба: ";
        std::cin >> value;
        
        std::cout << "Введите направление корабля (u - верх, d - низ, r - право, l - лево): ";
        std::cin >> direction;
        
        // преобразование строки в верхний регистр
        for (char& c : value) {
            c = std::toupper(c);
        }
        
        if (loadedData["playerValidValues"].contains(value)) {
            std::vector<std::string> loadedBoard = loadedData["boards"].get<std::vector<std::string>>();
            
            std::vector<int> coordinates = loadedData["playerValidValues"][value].get<std::vector<int>>();
            int row = coordinates[0];
            int col = coordinates[1];
            
            loadedBoard[row][col] = '#';
            
            std::string value1 = value;
            std::string value2 = value1;
            std::string value3 = value2;
            switch (direction[0]) {
                case 'u':
                    value1.back()--;
                    value2.back() -= 2;
                    value3.back() -= 3;
                    if (loadedData["playerValidValues"].contains(value1) && loadedData["playerValidValues"].contains(value2) && loadedData["playerValidValues"].contains(value3)) {
                        row--;
                        loadedBoard[row][col] = '#';
                        row--;
                        loadedBoard[row][col] = '#';
                        row--;
                        loadedBoard[row][col] = '#';
                    } else {
                        invalidDirection();
                        i--;
                        continue;
                    }
                    break;
                case 'd':
                    value1.back()++;
                    value2.back() += 2;
                    value3.back() += 3;
                    if (loadedData["playerValidValues"].contains(value1) && loadedData["playerValidValues"].contains(value2) && loadedData["playerValidValues"].contains(value3)) {
                        row++;
                        loadedBoard[row][col] = '#';
                        row++;
                        loadedBoard[row][col] = '#';
                        row++;
                        loadedBoard[row][col] = '#';
                    } else {
                        invalidDirection();
                        i--;
                        continue;
                    }
                    break;
                case 'r':
                    value1.front()++;
                    value2.front() += 2;
                    value3.front() += 3;
                    if (loadedData["playerValidValues"].contains(value1) && loadedData["playerValidValues"].contains(value2) && loadedData["playerValidValues"].contains(value3)) {
                        col += 2;
                        loadedBoard[row][col] = '#';
                        col += 2;
                        loadedBoard[row][col] = '#';
                        col += 2;
                        loadedBoard[row][col] = '#';
                    } else {
                        invalidDirection();
                        i--;
                        continue;
                    }
                    break;
                case 'l':
                    value1.front()--;
                    value2.front() -= 2;
                    value3.front() -= 3;
                    if (loadedData["playerValidValues"].contains(value1) && loadedData["playerValidValues"].contains(value2) && loadedData["playerValidValues"].contains(value3)) {
                        col -= 2;
                        loadedBoard[row][col] = '#';
                        col -= 2;
                        loadedBoard[row][col] = '#';
                        col -= 2;
                        loadedBoard[row][col] = '#';
                    } else {
                        invalidDirection();
                        i--;
                        continue;
                    }
                    break;
                default:
                    invalidDirection();
                    i--;
            }

            
            loadedData["boards"].clear();
            
            // удаление клеток вокруг выбранной из json
            std::map<std::string, std::pair<int, int>> validValues = loadedData["playerValidValues"];
            std::map<std::string, std::pair<int, int>> validValues1 = deleteCellsFunc(validValues, value);
            std::map<std::string, std::pair<int, int>> validValues2 = deleteCellsFunc(validValues1, value1);
            std::map<std::string, std::pair<int, int>> validValues3 = deleteCellsFunc(validValues2, value2);
            std::map<std::string, std::pair<int, int>> validValues4 = deleteCellsFunc(validValues3, value3);
            
            loadedData["playerValidValues"] = validValues4;
            for (const auto& row : loadedBoard) {
                loadedData["boards"].push_back(row);
            }
            
            jsonSaverFunc(loadedData);
            
            boardsFunc();
        } else {
            boardsFunc();
            std::cout << "\nНекорректное расположение!" << std::endl;
            i--;
        }
    }
}

void botPlacementFunc() {
    /*
     функция, позволяющая рандомно расположить корабли для бота
     */
    json loadedData = jsonParserFunc();
    
    srand(static_cast<unsigned int>(time(nullptr)));
    
    for (int i = 0; i < 4; ) {
        std::string value = elementGeneration();
        
        if (loadedData["botValidValues"].contains(value)) {
            std::vector<std::string> loadedBoard = loadedData["boards"].get<std::vector<std::string>>();
            std::vector<int> coordinates = loadedData["botValidValues"][value].get<std::vector<int>>();
            
            int row = coordinates[0];
            int col = coordinates[1];
            
            loadedBoard[row][col] = '#';
            
            loadedData["boards"].clear();
            
            std::map<std::string, std::pair<int, int>> validValues = loadedData["botValidValues"];
            std::map<std::string, std::pair<int, int>> validValues1 = deleteCellsFunc(validValues, value);
            
            loadedData["botValidValues"] = validValues1;
            for (const auto& row : loadedBoard) {
                loadedData["boards"].push_back(row);
            }
            
            jsonSaverFunc(loadedData);
            
            boardsFunc();
            
            i++;
        } else continue;
    }
    
    for (int i = 0; i < 3; ) {
        std::string value = elementGeneration();
        
        if (loadedData["botValidValues"].contains(value)) {
            std::vector<std::string> loadedBoard = loadedData["boards"].get<std::vector<std::string>>();
            std::vector<int> coordinates = loadedData["botValidValues"][value].get<std::vector<int>>();
            
            
        } else continue;
    }
}

void placementFunc() {
//    singleDeckPlacementFunc();
//    twoDeckPlacementFunc();
//    threeDeckPlacementFunc();
//    fourDeckPlacementFunc();
    botPlacementFunc();
}
