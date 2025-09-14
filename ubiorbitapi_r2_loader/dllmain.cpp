#include "pch.h"

#include "console.hpp"
#include "logger.hpp"

#include "config.hpp"
#include "macro.hpp"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        init_config();

        if (config.ENABLE_DEBUG_CONSOLE == true)
        {
            shared::CreateDebugConsole();
        }

        LOG_INFO("ubiorbitapi_r2_loader.dll loaded");
        LOG_INFO("Parsed details [ username: {} password: {} productId: {} cdKey: {} ]", config.username, config.password, config.productId, config.cdKey);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}