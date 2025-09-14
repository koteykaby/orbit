#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
#include <iomanip>
#include <mutex>
#include <filesystem>
#include <vector>
#include <type_traits>
#include <Windows.h>

namespace logger
{
    inline std::string logFileName = "orbit_log.log";
    inline std::ofstream logFile;
    inline std::mutex logMutex;
    inline std::size_t maxFileSize = 5 * 1024 * 1024; // 5 MB

    // ANSI colors
    namespace Colors {
        constexpr const char* Reset  = "\033[0m";
        constexpr const char* Red    = "\033[31m";
        constexpr const char* Yellow = "\033[33m";
        constexpr const char* Green  = "\033[32m";
    }

    // --- Helpers ---
    inline std::string current_time()
    {
        using namespace std::chrono;
        auto now = system_clock::now();
        auto t = system_clock::to_time_t(now);
        std::tm tm{};
    #ifdef _WIN32
        localtime_s(&tm, &t);
    #else
        localtime_r(&t, &tm);
    #endif
        std::ostringstream oss;
        oss << std::put_time(&tm, "%H:%M:%S");
        return oss.str();
    }

    inline void openLogFile()
    {
        if (!logFile.is_open())
            logFile.open(logFileName, std::ios::app);
    }

    inline void rotateLogs()
    {
        namespace fs = std::filesystem;
        if (fs::exists(logFileName) && fs::file_size(logFileName) >= maxFileSize)
        {
            logFile.close();
            fs::rename(logFileName, logFileName + ".1");
            logFile.open(logFileName, std::ios::trunc);
        }
    }

    // --- WString -> UTF8 helper ---
    inline std::string wstring_to_utf8(const std::wstring& wstr)
    {
        if (wstr.empty()) return {};
        int size_needed = WideCharToMultiByte(
            CP_UTF8, 0,
            wstr.data(), (int)wstr.size(),
            nullptr, 0,
            nullptr, nullptr
        );
        std::string str(size_needed, 0);
        WideCharToMultiByte(
            CP_UTF8, 0,
            wstr.data(), (int)wstr.size(),
            str.data(), size_needed,
            nullptr, nullptr
        );
        return str;
    }

    // --- String formatting with {} ---
    inline void replace_placeholder(std::ostringstream& oss,
                                    const std::string& fmt,
                                    std::size_t& pos,
                                    const std::string& arg)
    {
        auto ph = fmt.find("{}", pos);
        if (ph != std::string::npos)
        {
            oss << fmt.substr(pos, ph - pos) << arg;
            pos = ph + 2;
        }
        else
        {
            oss << fmt.substr(pos);
            pos = fmt.size();
        }
    }

    template<typename... Args>
    inline std::string format_message(const std::string& fmt, Args&&... args)
    {
        std::ostringstream oss;
        std::size_t pos = 0;

        auto arg_to_str = [](auto&& arg) -> std::string {
            std::ostringstream tmp;
            if constexpr (std::is_same_v<std::decay_t<decltype(arg)>, std::wstring>)
            {
                tmp << wstring_to_utf8(arg);
            }
            else
            {
                tmp << arg;
            }
            return tmp.str();
        };

        (replace_placeholder(oss, fmt, pos, arg_to_str(std::forward<Args>(args))), ...);

        oss << fmt.substr(pos);
        return oss.str();
    }

    // --- Extract just file name from full path ---
    inline std::string filename_only(const char* filepath)
    {
        std::filesystem::path p(filepath);
        return p.filename().string();
    }

    // --- Logging ---
    template<typename... Args>
    inline void log_message(const std::string& level,
                            const std::string& fmt,
                            const char* file,
                            int line,
                            const char* func,
                            Args&&... args)
    {
        std::lock_guard lock(logMutex);
        openLogFile();
        rotateLogs();

        const char* color = Colors::Reset;
        if (level == "INFO")  color = Colors::Green;
        if (level == "WARN")  color = Colors::Yellow;
        if (level == "ERROR") color = Colors::Red;

        std::string msg = format_message(fmt, std::forward<Args>(args)...);
        std::string short_file = filename_only(file);

        std::ostringstream oss;
        // Подсветка только [orbit] и уровня логирования
        oss << color << "[orbit] <" << level << ">" << Colors::Reset
            << " " << current_time()
            << " <" << short_file << ":" << line << "> "
            << "(" << func << ") "
            << msg;

        // Console
        std::cout << oss.str() << std::endl;

        // File (без цвета)
        logFile << "[orbit] <" << level << "> "
                << current_time()
                << " <" << short_file << ":" << line << "> "
                << "(" << func << ") "
                << msg << std::endl;
    }
}

// Macros
#define LOG_INFO(fmt, ...)  logger::log_message("INFO",  fmt, __FILE__, __LINE__, __func__, ##__VA_ARGS__)
#define LOG_WARN(fmt, ...)  logger::log_message("WARN",  fmt, __FILE__, __LINE__, __func__, ##__VA_ARGS__)
#define LOG_ERROR(fmt, ...) logger::log_message("ERROR", fmt, __FILE__, __LINE__, __func__, ##__VA_ARGS__)
