#include "logger.hpp"

#include "SavegameWriter.hpp"

mg::orbitclient::SavegameWriter::SavegameWriter()
{
    LOG_INFO("Call");
}

void mg::orbitclient::SavegameWriter::Close(bool arg)
{
	LOG_INFO("Call [ arg: {} ]", arg);
}

void mg::orbitclient::SavegameWriter::Write(unsigned int requestId,
											ISavegameWriteListener *savegameWriteListenerCallBack, void *buff,
											unsigned int numberOfBytes)
{
	LOG_INFO("Call [ requestId: {} callback: {} numberOfBytes {} ] ", requestId, savegameWriteListenerCallBack, numberOfBytes);
}

bool mg::orbitclient::SavegameWriter::SetName(unsigned short *name)
{
	LOG_INFO("Call [ name: {} ]", name);
	return true;
}