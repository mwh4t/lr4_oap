#include "functions.hpp"
#include <iostream>

void boardFunc() {
    std::string r1 = " 1 □ □ □ □ □ □ □ □ □ □\n"; // ■
    std::string r2 = " 2 □ □ □ □ □ □ □ □ □ □\n"; // ×
    std::string r3 = " 3 □ □ □ □ □ □ □ □ □ □\n"; // •
    std::string r4 = " 4 □ □ □ □ □ □ □ □ □ □\n";
    std::string r5 = " 5 □ □ □ □ □ □ □ □ □ □\n";
    std::string r6 = " 6 □ □ □ □ □ □ □ □ □ □\n";
    std::string r7 = " 7 □ □ □ □ □ □ □ □ □ □\n";
    std::string r8 = " 8 □ □ □ □ □ □ □ □ □ □\n";
    std::string r9 = " 9 □ □ □ □ □ □ □ □ □ □\n";
    std::string r10 = "10 □ □ □ □ □ □ □ □ □ □\n";
    
    std::cout << "Ваша доска:" << std::endl;
    std::cout << "   A B C D E F G H I J\n";
    std::cout << r1 << r2 << r3 << r4 << r5 << r6 << r7 << r8 << r9 << r10 << std::endl;

}
