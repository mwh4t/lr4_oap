#include "utils/functions.hpp"
//#include <unistd.h>

int main() { // ■ × •
    // функция для загрузки данных в json
    jsonLoaderFunc();
    
    // функция печати досок
    boardsFunc();
    
//    int sec = 1000000;
//    usleep(1 * sec);
    
    // функция хода игрока
    placementFunc();
    
    return 0;
}
