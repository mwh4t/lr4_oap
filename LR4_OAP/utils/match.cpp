#include "functions.hpp"

bool isPlayerTurn = true;

void playerMoveFunc() {
    /*
     функция для хода игрока
     */
    json loadedData = jsonParserFunc();
    
    std::string value;
    
    std::cout << "\nВаш ход: ";
    std::cin >> value;
    
    // преобразование строки в верхний регистр
    for (char& c : value) {
        c = std::toupper(c);
    }
    
    if (loadedData["playerMovesValidValues"].contains(value)) {
        std::vector<std::pair<int, int>> botMoves = loadedData["botMoves"];
        
        std::vector<std::vector<int>> coordinates = loadedData["values"][value].get<std::vector<std::vector<int>>>();
        int row = coordinates[1][0];
        int col = coordinates[1][1];
        std::pair<int, int> coordinates1 = {row, col};
        
        std::vector<std::string> loadedBoard = loadedData["boards"].get<std::vector<std::string>>();
        
        std::vector<std::vector<int>> coordinates2 = loadedData["values"][value].get<std::vector<std::vector<int>>>();
        int row1 = coordinates2[1][0];
        int col1 = coordinates2[1][1];
        
        if (std::find(botMoves.begin(), botMoves.end(), coordinates1) != botMoves.end()) {
            loadedBoard[row1][col1] = 'X';
            
            botMoves.erase(std::remove(botMoves.begin(), botMoves.end(), coordinates1), botMoves.end());
            
            loadedData["boards"].clear();
            
            for (const auto& row : loadedBoard) {
                loadedData["boards"].push_back(row);
            }
            loadedData["botMoves"] = botMoves;
            
            loadedData["playerMovesValidValues"].erase(value);
            
            jsonSaverFunc(loadedData);
            
            boardsFunc();
        } else {
            loadedBoard[row1][col1] = '.';
            
            loadedData["boards"].clear();
            
            for (const auto& row : loadedBoard) {
                loadedData["boards"].push_back(row);
            }
            
            loadedData["playerMovesValidValues"].erase(value);
            
            jsonSaverFunc(loadedData);
            
            boardsFunc();
        }
    } else {
        boardsFunc();
        std::cout << "\nНекорректный ход!" << std::endl;
        isPlayerTurn = !isPlayerTurn;
    }
}

void botMoveFunc() {
    /*
     функция для хода бота
     */
    json loadedData = jsonParserFunc();
    
    srand(static_cast<unsigned int>(time(nullptr)));
    
    std::cout << "\nХод бота...\n";
    
    int sec = 1000000;
    usleep(1 * sec);
    
    std::string value = elementGeneration();
    
    // преобразование строки в верхний регистр
    for (char& c : value) {
        c = std::toupper(c);
    }
    
    if (loadedData["botMovesValidValues"].contains(value)) {
        std::vector<std::pair<int, int>> playerMoves = loadedData["playerMoves"];
        
        std::vector<std::vector<int>> coordinates = loadedData["values"][value].get<std::vector<std::vector<int>>>();
        int row = coordinates[0][0];
        int col = coordinates[0][1];
        std::pair<int, int> coordinates1 = {row, col};
        
        std::vector<std::string> loadedBoard = loadedData["boards"].get<std::vector<std::string>>();
        
        std::vector<std::vector<int>> coordinates2 = loadedData["values"][value].get<std::vector<std::vector<int>>>();
        int row1 = coordinates2[0][0];
        int col1 = coordinates2[0][1];
        
        if (std::find(playerMoves.begin(), playerMoves.end(), coordinates1) != playerMoves.end()) {
            loadedBoard[row1][col1] = 'X';
            
            playerMoves.erase(std::remove(playerMoves.begin(), playerMoves.end(), coordinates1), playerMoves.end());
            
            loadedData["boards"].clear();
            
            for (const auto& row : loadedBoard) {
                loadedData["boards"].push_back(row);
            }
            loadedData["playerMoves"] = playerMoves;
            
            loadedData["botMovesValidValues"].erase(value);
            
            jsonSaverFunc(loadedData);
            
            boardsFunc();
        } else {
            loadedBoard[row1][col1] = '.';
            
            loadedData["boards"].clear();
            
            for (const auto& row : loadedBoard) {
                loadedData["boards"].push_back(row);
            }
            
            loadedData["botMovesValidValues"].erase(value);
            
            jsonSaverFunc(loadedData);
            
            boardsFunc();
        }
    } else {
        boardsFunc();
        isPlayerTurn = !isPlayerTurn;
    }
}

void matchFunc() {
    for (; true; ) {
        if (isPlayerTurn) {
            playerMoveFunc();
        } else {
            botMoveFunc();
        }
        isPlayerTurn = !isPlayerTurn;
        
        json loadedData = jsonParserFunc();
        
        std::vector<std::pair<int, int>> botMoves = loadedData["botMoves"];
        std::vector<std::pair<int, int>> playerMoves = loadedData["playerMoves"];
        
        if (botMoves.size() == 0) {
            std::cout << "\nВы победили!\n";
            return;
        }
        
        if (playerMoves.size() == 0) {
            std::cout << "\nБот победил!\n";
            return;
        }
    }
}
