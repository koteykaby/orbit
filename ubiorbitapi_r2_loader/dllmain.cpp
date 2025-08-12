#include "pch.h"

#include "Console.hpp"
#include "Logger.hpp"

#include "Macro.hpp"

#include "ProfileManager/Config.hpp"

#include "Exports/SavegameInfo.hpp"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        ProfileManager::InitConfig("orbit.ini");

        if (ProfileManager::Config.EnableDebugConsole == true) {
            DebugConsole::CreateConsole();
            logger.log("dllmain.cpp: Config.EnableDebugConsole = true");
        } else {
            logger.log("dllmain.cpp: Config.EnableDebugConsole = false | console is not initialized!");
        }
        
        logger.log("dllmain.cpp: ubiorbitapi_r2_loader.dll loaded to target application!");
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}