#include "other/functions.hpp"
#include <cstdlib>
//#include <unistd.h>

int main() {
    system("clear");
    
//    int sec = 1000000;
    
    boardFunc();
    
//    usleep(1 * sec);
    placementFunc();
    
    return 0;
}
