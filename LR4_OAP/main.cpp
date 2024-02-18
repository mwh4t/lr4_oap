#include "other/functions.hpp"
#include <unistd.h>

int main() {
    int sec = 1000000;
    
    boardFunc();
    
    usleep(1 * sec);
    placementFunc();
    
    return 0;
}
