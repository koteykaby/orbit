#include "config.hpp"

orbit_config config;

void init_config(const std::string& filename)
{
    mINI::INIFile file(filename);
    mINI::INIStructure ini;
    
    if (file.read(ini))
    {
        config.username = ini["Account"]["UbisoftId"];
        
        std::string pass = ini["Account"]["Password"];
        config.password = std::wstring(pass.begin(), pass.end());
        
        config.productId = std::stoi(ini["Game"]["ProductId"]);
        config.cdKey = ini["Game"]["CDKey"];
        
        std::string debug = ini["Debug"]["CreateConsoleWindow"];
        config.ENABLE_DEBUG_CONSOLE = (debug == "true" || debug == "1");
    }
}