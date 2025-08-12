#include "Logger.hpp"

#include "SavegameWriter.hpp"

mg::orbitclient::SavegameWriter::SavegameWriter()
{
    logger.log("call!: mg::orbitclient::SavegameWriter::SavegameWriter");
}

void mg::orbitclient::SavegameWriter::Close(bool arg)
{
	logger.log("call!: mg::orbitclient::SavegameWriter::Close");
}

void mg::orbitclient::SavegameWriter::Write(unsigned int requestId,
											ISavegameWriteListener *savegameWriteListenerCallBack, void *buff,
											unsigned int numberOfBytes)
{
	logger.log("call!: mg::orbitclient::SavegameWriter::Write RequestId: %d SavegameWriteListenerCallBack: %x Buff: %x NumberOfBytes: %d", requestId,
						reinterpret_cast<void *>(&savegameWriteListenerCallBack), buff, numberOfBytes);
}

bool mg::orbitclient::SavegameWriter::SetName(unsigned short *name)
{
	logger.log("call!: mg::orbitclient::SavegameWriter::SetName Name: {}", reinterpret_cast<wchar_t *>(name));
	return true;
}