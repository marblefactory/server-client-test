#include <iostream>

class Logging {
public:
    static void logError(int LINENUMBER, std::string message);
    static void logWarning(int LINENUMBER, std::string message);
    static void logDebug(int LINENUMBER, std::string message);
};
