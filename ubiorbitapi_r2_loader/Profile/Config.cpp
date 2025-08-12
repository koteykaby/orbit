#include "INIParser.hpp"

#include "Config.hpp"

INIParser parser;

OrbitConfig Config = {
    parser.GetString("Account", "UbisoftId"),
    parser.GetWString("Account", "Password"),
    parser.GetInt("Game", "ProductId"),
    parser.GetString("Game", "CdKey"),
    parser.GetBool("Settings", "EnableDebugConsole")
};