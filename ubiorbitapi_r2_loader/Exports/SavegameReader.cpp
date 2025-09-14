#include "logger.hpp"

#include "SavegameReader.hpp"

mg::orbitclient::SavegameReader::SavegameReader() 
{
    LOG_INFO("Call");
}

void mg::orbitclient::SavegameReader::Close() 
{
    LOG_INFO("Call");
}

void mg::orbitclient::SavegameReader::Read(unsigned int requestId, 
    ISavegameReadListener* savegameReadListenerCallBack,
    unsigned int offset, void* buff, unsigned int numberOfBytes) 
{
    LOG_INFO("Call");
}

