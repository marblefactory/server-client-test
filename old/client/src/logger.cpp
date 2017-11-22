#include "logger.h"
#include <iostream>

void Logging::logError(int LINENUMBER, std::string message){
    std::cout << "ERROR " << "line:" << LINENUMBER << " " << message << std::endl;
}

void Logging::logWarning(int LINENUMBER, std::string message){
    std::cout << "WARN " << "line:" << LINENUMBER << " " << message << std::endl;
}

void Logging::logDebug(int LINENUMBER, std::string message){
    std::cout << "DEBUG " << "line:" << LINENUMBER << " " << message << std::endl;
}
