#include "Logger.hpp"

#include "SavegameInfo.hpp"

#include "../Profile/Config.hpp"

mg::orbitclient::SavegameInfo::SavegameInfo(unsigned int id, unsigned long size, const std::wstring &name) {
    logger.log("call!: mg::orbitclient::SavegameInfo::SavegameInfo");

    Name = name;
    Id = id;
    Size = size;
}

unsigned int mg::orbitclient::SavegameInfo::GetSavegameId() {
    logger.log("call!: mg::orbitclient::SavegameInfo::GetSavegameId");
    return Id;
}

unsigned int mg::orbitclient::SavegameInfo::GetProductId() {
    logger.log("call!: mg::orbitclient::SavegameInfo::GetProductId");
    return Config.ProductId;
}

inline unsigned int mg::orbitclient::SavegameInfo::GetSize()
{
	logger.log("call!: mg::orbitclient::SavegameInfo::GetProductId");
	return Size;
}

inline unsigned short const *mg::orbitclient::SavegameInfo::GetName()
{
	logger.log("call!: mg::orbitclient::SavegameInfo::GetName");
	return reinterpret_cast<const unsigned short *>(&Name.c_str()[0]);
}