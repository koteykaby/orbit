#pragma once

#include "../macro.hpp"

#include "Interfaces/ISavegameWriteListener.hpp"

namespace mg {
    namespace orbitclient {
        class UBIORBITAPI_R2_LOADER_EXPORT SavegameWriter {
            std::string FilePath;
            std::string NamePath;
            unsigned int SaveId;

        public:
            SavegameWriter();
            void Close(bool arg);
            void Write(unsigned int requestId, ISavegameWriteListener* savegameWriteListenerCallBack, void* buff,
                unsigned int numberOfBytes);
            bool SetName(unsigned short* name);
        };
    }
} 