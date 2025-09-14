#pragma once

#include "../macro.hpp"

#include "Interfaces/ISavegameReadListener.hpp"

namespace mg {
    namespace orbitclient {
        class UBIORBITAPI_R2_LOADER_EXPORT SavegameReader
        {
            std::string FilePath;

        public:
            SavegameReader();
            void Close();
            void Read(unsigned int requestId, ISavegameReadListener* savegameReadListenerCallBack,
                unsigned int offset, void* buff, unsigned int numberOfBytes);
        };
    }
} 