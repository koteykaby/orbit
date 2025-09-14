#pragma once

#include <Windows.h>
#include <iostream>

#include "Logger.hpp"

namespace shared
{
    // Включение поддержки ANSI escape кодов (Virtual Terminal)
    inline void EnableVTMode()
    {
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        if (hOut == INVALID_HANDLE_VALUE) return;

        DWORD dwMode = 0;
        if (!GetConsoleMode(hOut, &dwMode)) return;

        // ENABLE_VIRTUAL_TERMINAL_PROCESSING = 0x0004
        dwMode |= 0x0004;
        SetConsoleMode(hOut, dwMode);
    }

    inline void CreateDebugConsole()
    {
        AllocConsole();
        SetConsoleTitleA("Orbit Debug Console");

        FILE* f;
        freopen_s(&f, "CONOUT$", "w", stdout);
        freopen_s(&f, "CONOUT$", "w", stderr);

        // Включаем поддержку ANSI-последовательностей
        EnableVTMode();

        LOG_INFO("Initialized!");
    }
}
