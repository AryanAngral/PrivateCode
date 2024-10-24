#include "SystemLog.h"
#include <fstream>
#include <ctime>

void SystemLog::log(const std::string& message) {
    std::ofstream logFile("system.log", std::ios_base::app);
    std::time_t now = std::time(0);
    logFile << std::ctime(&now) << ": " << message << std::endl;
}
