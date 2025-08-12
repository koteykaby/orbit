#pragma once

#include <string>
#include "INIParser.hpp"

namespace ProfileManager {
    struct OrbitConfig {
        // [Account]
        std::string UbisoftId;
        std::wstring Password;

        // [Game]
        int ProductId;
        std::string CdKey;

        // [Settings]
        bool EnableDebugConsole;

        OrbitConfig() : 
            UbisoftId(""),
            Password(L""),
            ProductId(0),
            CdKey(""),
            EnableDebugConsole(false)
        {}
    };

    bool InitConfig(const std::string& configFile);
    void LoadDefaultConfig();

    extern OrbitConfig Config;
    extern INIParser ConfigParser;
}