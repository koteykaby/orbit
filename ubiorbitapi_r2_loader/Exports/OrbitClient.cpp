#include "Logger.hpp"

#include "../Profile/Config.hpp"

#include "OrbitClient.hpp"

mg::orbitclient::OrbitClient::OrbitClient()
{
	logger.log("call!: mg::orbitclient::OrbitClient::OrbitClient");
}

void mg::orbitclient::OrbitClient::StartProcess(unsigned short *, unsigned short *, unsigned short *)
{
	logger.log("call!: mg::orbitclient::OrbitClient::StartProcess");
}

void mg::orbitclient::OrbitClient::GetSavegameList(unsigned int requestId,
												    IGetSavegameListListener *savegameListListenerCallBack,
													unsigned int productId)
{
	logger.log("call!: mg::orbitclient::OrbitClient::GetSavegameList RequestId: %d GetSavegameListListenerCallBack: %x ProductId: %d", requestId,
						reinterpret_cast<void *>(&savegameListListenerCallBack), productId);
}

void mg::orbitclient::OrbitClient::GetSavegameReader(unsigned int requestId,
													IGetSavegameReaderListener *savegameReaderListenerCallBack,
													unsigned int productId, unsigned int saveGameId)
{
	logger.log("call!: mg::orbitclient::OrbitClient::GetSavegameReader RequestId: %d GetSavegameReaderListenerCallBack: %x ProductId: %d SaveGameId: %d", requestId,
						reinterpret_cast<void *>(&savegameReaderListenerCallBack),
						productId, saveGameId);
}

void mg::orbitclient::OrbitClient::Update() {} // do not log it!!!!!!!!!!

bool mg::orbitclient::OrbitClient::StartLauncher(unsigned int a, unsigned int b, char const *langCode, char const *arguments)
{
    logger.log("call!: mg::orbitclient::OrbitClient::StartLauncher");
    return false;
}

unsigned short *mg::orbitclient::OrbitClient::GetInstallationErrorString(char const *err)
{
	logger.log("call!: mg::orbitclient::OrbitClient::GetInstallationErrorString");
	return nullptr;
}

unsigned int mg::orbitclient::OrbitClient::GetInstallationErrorNum()
{
	logger.log("call!: mg::orbitclient::OrbitClient::GetInstallationErrorNum");
	return 0;
}

void mg::orbitclient::OrbitClient::GetSavegameWriter(unsigned int requestId,
															IGetSavegameWriterListener *savegameWriterListenerCallBack,
															unsigned int productId, unsigned int saveGameId, bool open)
{
	logger.log("call!: mg::orbitclient::OrbitClient::GetSavegameWriter RequestId: %s GetSavegameWriterListenerCallBack: %x ProductId: %d SaveGameId: %d", requestId,
						reinterpret_cast<void *>(&savegameWriterListenerCallBack), productId, saveGameId);
}

void mg::orbitclient::OrbitClient::RemoveSavegame(unsigned int requestId,
														 IRemoveSavegameListener *removeSavegameListenerCallBack,
														 unsigned int productId, unsigned int saveGameId)
{
	logger.log("call!: mg::orbitclient::OrbitClient::RemoveSavegame RequestId: %d RemoveSavegameListenerCallBack: %x", requestId,
						reinterpret_cast<void *>(&removeSavegameListenerCallBack));
}

void mg::orbitclient::OrbitClient::GetLoginDetails(unsigned int requestId,
														  IGetLoginDetailsListener *loginDetailsListenerCallBack)
{
	logger.log("call!: mg::orbitclient::OrbitClient::GetLoginDetails RequestId: %d LoginDetailsListenerCallBack: %x", requestId,
						reinterpret_cast<void *>(&loginDetailsListenerCallBack));

	const auto callBack = reinterpret_cast<IGetLoginDetailsListener::CallBackPtrType>(**loginDetailsListenerCallBack->CallBackPtr);

	if (callBack == nullptr)
	{
		return;
	}

    logger.log("using account credentials: %s, %s, %s", Config.UbisoftId, Config.Password, Config.CdKey);

	callBack(loginDetailsListenerCallBack, requestId, Config.UbisoftId.c_str(), Config.Password.c_str(), Config.CdKey.c_str());
}


void mg::orbitclient::OrbitClient::GetOrbitServer(unsigned int requestId, IGetOrbitServerListener* callback, unsigned int, unsigned int)
{
    logger.log("call!: mg::orbitclient::OrbitClient::GetOrbitServer");
}


unsigned int mg::orbitclient::OrbitClient::GetRequestUniqueId()
{
	logger.log("call!: mg::orbitclient::OrbitClient::GetRequestUniqueId");
	return RequestId++;
}


mg::orbitclient::OrbitClient::~OrbitClient()
{
	logger.log("call!: mg::orbitclient::OrbitClient::~OrbitClient");
}
