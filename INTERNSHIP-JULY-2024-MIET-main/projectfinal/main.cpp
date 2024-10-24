#include "RailwayManagementSystem.h"
#include <iostream>
#include <stdexcept>

int main() {
    try {
        RailwayManagementSystem system;
        system.mainMenu();
    } catch (const std::exception& e) {
        std::cerr << "Critical Error: " << e.what() << std::endl;
        SystemLog::log("Critical Error: " + std::string(e.what()));
        return 1;
    }
    return 0;
}
