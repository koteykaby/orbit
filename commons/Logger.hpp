#pragma once

#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <mutex>
#include <cstdarg>

class Logger {
public:
    Logger(const std::string& filename, bool logToConsole = false);
    ~Logger();
    void log(const char* format, ...);

private:
    std::ofstream logFile;
    std::mutex logMutex;
    bool logToConsole;
    std::string getCurrentTime();
};

extern Logger logger;

#endif // LOGGER_H
