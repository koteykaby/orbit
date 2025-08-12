#pragma once

#include "../SavegameWriter.hpp"

namespace mg {
	namespace orbitclient {
		class IGetSavegameWriterListener {
		public:
			typedef void(__thiscall* CallBackPtrType)(void*, unsigned int requestId, int unk,
				SavegameWriter* saveGameWriter);
			void (**CallBackPtr)(unsigned int requestId, int unk, SavegameWriter* saveGameWriter);
		};
	}
}