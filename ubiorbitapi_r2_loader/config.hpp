#pragma once

#include "dependencies/ini.h"
#include <string>

struct orbit_config
{
    std::string username;
    std::wstring password;
    int productId;
    std::string cdKey;
    bool ENABLE_DEBUG_CONSOLE;
};

extern orbit_config config;

void init_config(const std::string& filename = "orbit.ini");