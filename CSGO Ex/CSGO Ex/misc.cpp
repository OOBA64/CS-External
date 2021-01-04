#include "offset.hpp"
#include "hacks.h"

static bool canRadar = false;
static bool canFlash = false;

MemMan CMem;

int FlashDur = 0;

void Hacks::forceRadar()
{
	
	if (GetAsyncKeyState(VK_F3) & 1){
		canRadar = !canRadar;
	}

	//Ent loop
	for (int i = 0; i < 64; i++)
	{
		uintptr_t pEntity = Entity::getBaseEntity(i);
		if (canRadar && pEntity != NULL)
		{
			Entity::setSpotted(pEntity, true);
		}
		else if (!canRadar)
			Entity::setSpotted(pEntity, false);
	}
	
}

void Hacks::noFlash()
{
	if (GetAsyncKeyState(VK_F4) & 1) {
		canFlash = !canFlash;
	}

	uintptr_t LP = CMem.readMem<uintptr_t>(map::GameModule() + getOffsets::LocalPlayer);

	FlashDur = CMem.readMem<int>(LP + getOffsets::flashDur);

	if (LP != NULL)
	{
		CMem.writeMem<int>(LP + getOffsets::flashDur, 0);
	}
}