#pragma once

#include "../macro.hpp"

namespace mg {
    namespace orbitclient {
        class UBIORBITAPI_R2_LOADER_EXPORT SavegameInfo {
            std::wstring Name;
            unsigned int Id;
            unsigned long Size;

        public:
            SavegameInfo(unsigned int, unsigned long, const std::wstring&);
            unsigned int GetSavegameId();
            unsigned int GetProductId(void);
            unsigned int GetSize();
            unsigned short const* GetName();
        };
    }
}
