#pragma once

struct OrbitConfig {
    std::string UbisoftId;
    std::wstring Password;
    int ProductId;
    std::string CdKey;
    bool EnableDebugConsole;
};

extern OrbitConfig Config;