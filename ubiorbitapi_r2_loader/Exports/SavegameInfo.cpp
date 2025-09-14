#include "logger.hpp"

#include "SavegameInfo.hpp"

#include "../config.hpp"

mg::orbitclient::SavegameInfo::SavegameInfo(unsigned int id, unsigned long size, const std::wstring &name) {
    LOG_INFO("Call");

    Name = name;
    Id = id;
    Size = size;
}

unsigned int mg::orbitclient::SavegameInfo::GetSavegameId() {
    LOG_INFO("Call");
    return Id;
}

unsigned int mg::orbitclient::SavegameInfo::GetProductId() {
    LOG_INFO("Call");
    return config.productId;
}

unsigned int mg::orbitclient::SavegameInfo::GetSize()
{
	LOG_INFO("Call");
	return Size;
}

unsigned short const *mg::orbitclient::SavegameInfo::GetName()
{
	LOG_INFO("Call");
	return reinterpret_cast<const unsigned short *>(&Name.c_str()[0]);
}