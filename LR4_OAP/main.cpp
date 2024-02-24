#include "other/functions.hpp"
#include <cstdlib>
//#include <unistd.h>

int main() { // ■ × •
    system("clear");
    
    // функция для загрузки данных в json
    jsonLoaderFunc();
    
//    int sec = 1000000;
    
    // функция доски игрока
    boardFunc();
    
//    usleep(1 * sec);
    
    // функция хода игрока
    placementFunc();
    
    return 0;
}
