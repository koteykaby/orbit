#include "logger.hpp"
#include "OrbitClient.hpp"

#include "../macro.hpp"

#include "../config.hpp"

mg::orbitclient::OrbitClient::OrbitClient()
{
    LOG_INFO("Call");
}

mg::orbitclient::OrbitClient::~OrbitClient()
{
    LOG_INFO("Call");
}

void mg::orbitclient::OrbitClient::StartProcess(unsigned short *a, unsigned short *b, unsigned short *c)
{
    LOG_INFO("Call [ a: {} b: {} c: {} ]", a, b, c);
}

void mg::orbitclient::OrbitClient::GetSavegameList(unsigned int requestId,
                                                   IGetSavegameListListener *savegameListListenerCallBack,
                                                   unsigned int productId)
{
    LOG_INFO("Call [ requestId: {} callback: {} productId: {} ]",
             requestId, savegameListListenerCallBack, productId);

    const auto callBack = reinterpret_cast<IGetSavegameListListener::CallBackPtrType>(**savegameListListenerCallBack->CallBackPtr);

    if (callBack == nullptr) {
        LOG_INFO("Callback is null");
        return;
    }

    callBack(savegameListListenerCallBack, requestId, nullptr, 0);	
}

void mg::orbitclient::OrbitClient::GetSavegameReader(unsigned int requestId,
                                                     IGetSavegameReaderListener *savegameReaderListenerCallBack,
                                                     unsigned int productId, unsigned int saveGameId)
{
    LOG_INFO("Call [ requestId: {} callback: {} productId: {} saveGameId: {} ]",
             requestId, savegameReaderListenerCallBack, productId, saveGameId);
}

void mg::orbitclient::OrbitClient::Update()
{
	// just spam.
    //LOG_INFO("Call");
}

bool mg::orbitclient::OrbitClient::StartLauncher(unsigned int a, unsigned int b, char const *langCode, char const *arguments)
{
    LOG_INFO("Call [ a: {} b: {} langCode: {} arguments: {} ]", a, b, langCode, arguments);
    return false;
}

unsigned short *mg::orbitclient::OrbitClient::GetInstallationErrorString(char const *err)
{
    LOG_INFO("Call [ err: {} ]", err);
    return nullptr;
}

unsigned int mg::orbitclient::OrbitClient::GetInstallationErrorNum()
{
    LOG_INFO("Call");
    return 0;
}

void mg::orbitclient::OrbitClient::GetSavegameWriter(unsigned int requestId,
                                                     IGetSavegameWriterListener *savegameWriterListenerCallBack,
                                                     unsigned int productId, unsigned int saveGameId, bool open)
{
    LOG_INFO("Call [ requestId: {} callback: {} productId: {} saveGameId: {} open: {} ]",
             requestId, savegameWriterListenerCallBack, productId, saveGameId, open);
}

void mg::orbitclient::OrbitClient::RemoveSavegame(unsigned int requestId,
                                                  IRemoveSavegameListener *removeSavegameListenerCallBack,
                                                  unsigned int productId, unsigned int saveGameId)
{
    LOG_INFO("Call [ requestId: {} callback: {} productId: {} saveGameId: {} ]",
             requestId, removeSavegameListenerCallBack, productId, saveGameId);
}

void mg::orbitclient::OrbitClient::GetLoginDetails(unsigned int requestId,
                                                   IGetLoginDetailsListener *loginDetailsListenerCallBack)
{
    LOG_INFO("Call [ requestId: {} callback: {} ]",
             requestId, loginDetailsListenerCallBack);

    const auto callBack = reinterpret_cast<IGetLoginDetailsListener::CallBackPtrType>(**loginDetailsListenerCallBack->CallBackPtr);

    if (callBack == nullptr)
    {
        LOG_INFO("Callback is null");
        return;
    }

    LOG_INFO("Using account credentials [ UbisoftId: {} Password: {} CdKey: {} ]",
             config.username,
             config.password,
             config.cdKey);

    callBack(loginDetailsListenerCallBack, requestId,
             config.username.c_str(),
             config.password.c_str(),
             config.cdKey.c_str());
}

void mg::orbitclient::OrbitClient::GetOrbitServer(unsigned int requestId, IGetOrbitServerListener* callback, unsigned int a, unsigned int b)
{
    LOG_INFO("Call [ requestId: {} callback: {} a: {} b: {} ]", requestId, callback, a, b);
}

unsigned int mg::orbitclient::OrbitClient::GetRequestUniqueId()
{
    LOG_INFO("Call [ RequestId: {} ]", RequestId);
    return RequestId++;
}

const unsigned short* mg::orbitclient::OrbitClient::GetLocText(const unsigned short* fallback, const char* textId)
{
    LOG_INFO("Call [ fallback: {} textId: {} ]", fallback, textId);
    return fallback;
}
