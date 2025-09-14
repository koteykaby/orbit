#pragma once

#include "../macro.hpp"

#include "SavegameInfo.hpp"
#include "SavegameReader.hpp"
#include "SavegameWriter.hpp"

#include "Interfaces/IRemoveSavegameListener.hpp"
#include "Interfaces/IGetLoginDetailsListener.hpp"
#include "Interfaces/IGetSavegameListListener.hpp"
#include "Interfaces/IGetSavegameWriterListener.hpp"
#include "Interfaces/IGetSavegameReaderListener.hpp"
#include "Interfaces/IGetOrbitServerListener.hpp"

#include <memory>
#include <vector>

namespace mg {
    namespace orbitclient {
        class UBIORBITAPI_R2_LOADER_EXPORT OrbitClient {
            volatile int RequestId;
        public:
            OrbitClient();

            void StartProcess(unsigned short*, unsigned short*, unsigned short*);
            bool StartLauncher(unsigned int, unsigned int, char const*, char const*);

            void GetSavegameList(unsigned int requestId, IGetSavegameListListener* savegameListListenerCallBack,
                unsigned int productId);
            void GetSavegameWriter(unsigned int requestId, IGetSavegameWriterListener* savegameWriterListenerCallBack,
                unsigned int productId, unsigned int saveGameId, bool open);
            void GetSavegameReader(unsigned int requestId, IGetSavegameReaderListener* savegameReaderListenerCallBack,
                unsigned int productId, unsigned int saveGameId);
            void RemoveSavegame(unsigned int requestId, IRemoveSavegameListener* removeSavegameListenerCallBack,
                unsigned int productId, unsigned int saveGameId);

            void GetLoginDetails(unsigned int requestId, IGetLoginDetailsListener* loginDetailsListenerCallBack);
            void GetOrbitServer(unsigned int requestId, IGetOrbitServerListener*, unsigned int, unsigned int);

            unsigned int GetRequestUniqueId();
            unsigned short* GetInstallationErrorString(char const*);
            unsigned int GetInstallationErrorNum();

            void Update();

            const unsigned short* GetLocText(const unsigned short* fallback,
                                             const char*);

            ~OrbitClient();
        };
    }
}