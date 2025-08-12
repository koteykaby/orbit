#include "Config.hpp"
#include <Windows.h>

namespace ProfileManager {
    OrbitConfig Config;
    INIParser ConfigParser;

    void LoadDefaultConfig() {
        Config.UbisoftId = "OrbitEmu";
        Config.Password = L"OrbitEmu";
        Config.ProductId = 1000;
        Config.CdKey = "AAAA-AAAA-AAAA-AAAA";
        Config.EnableDebugConsole = false;
    }

    bool InitConfig(const std::string& configFile) {
        if (!ConfigParser.Load(configFile)) {
            MessageBoxW(NULL, 
                L"Couldn't load orbit.ini configurations!", 
                L"ubiorbitapi_r2_loader.dll", 
                MB_ICONWARNING | MB_OK);
            LoadDefaultConfig();
            return false;
        }

        try {
            // [Account]
            Config.UbisoftId = ConfigParser.GetString("Account", "UbisoftId", Config.UbisoftId);
            Config.Password = ConfigParser.GetWString("Account", "Password", Config.Password);
            
            // [Game]
            Config.ProductId = ConfigParser.GetInt("Game", "ProductId", Config.ProductId);
            Config.CdKey = ConfigParser.GetString("Game", "CdKey", Config.CdKey);
            
            // [Settings]
            Config.EnableDebugConsole = ConfigParser.GetBool("Settings", "EnableDebugConsole", Config.EnableDebugConsole);

            if (Config.UbisoftId.empty() || Config.Password.empty()) {
                MessageBoxW(NULL, 
                    L"Ubisoft ID and Password is missing!", 
                    L"ubiorbitapi_r2_loader.dll", 
                    MB_ICONERROR | MB_OK);
                LoadDefaultConfig();
                return false;
            }
        }
        catch (...) {
            MessageBoxW(NULL, 
                L"Couldn't load orbit.ini configurations! Default ones will be used!", 
                L"ubiorbitapi_r2_loader.dll", 
                MB_ICONERROR | MB_OK);
            LoadDefaultConfig();
            return false;
        }

        return true;
    }
}