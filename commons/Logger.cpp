#include "Logger.hpp"

Logger logger("ubiorbitapi_r2_loader.log", true);

Logger::Logger(const std::string& filename, bool logToConsole) 
    : logFile(filename, std::ios::app), logToConsole(logToConsole) {
    if (!logFile.is_open()) {
        std::cerr << "Unable to open log file!" << std::endl;
    }
}

Logger::~Logger() {
    if (logFile.is_open()) {
        logFile.close();
    }
}

void Logger::log(const char* format, ...) {
    std::lock_guard<std::mutex> guard(logMutex);
    
    char message[256];
    va_list args;
    va_start(args, format);
    vsnprintf(message, sizeof(message), format, args);
    va_end(args);

    if (logFile.is_open()) {
        logFile << getCurrentTime() << " - " << message << std::endl;
    }

    if (logToConsole) {
        std::cout << getCurrentTime() << " - " << message << std::endl;
    }
}

std::string Logger::getCurrentTime() {
    std::time_t now = std::time(nullptr);
    std::tm localTime;
    
    localtime_s(&localTime, &now);

    char buf[100];
    std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", &localTime);
    return buf;
}