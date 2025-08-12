#include "Logger.hpp"

#include "SavegameReader.hpp"

mg::orbitclient::SavegameReader::SavegameReader() {
    logger.log("call!: mg::orbitclient::SavegameReader::SavegameReader");
}

void mg::orbitclient::SavegameReader::Close() {
    logger.log("call!: mg::orbitclient::SavegameReader::Close");
}

void mg::orbitclient::SavegameReader::Read(unsigned int requestId, 
    ISavegameReadListener* savegameReadListenerCallBack,
    unsigned int offset, void* buff, unsigned int numberOfBytes) 
{
    logger.log("call!: mg::orbitclient::SavegameReader::Read");
}

