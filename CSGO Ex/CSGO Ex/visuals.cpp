#include "offset.hpp"
#include "hacks.h"

static bool canGlow = false;

void Hacks::glowESP()
{
	/*
	if (GetAsyncKeyState(VK_F5) & 1)
	{
		canGlow = !canGlow;
	}

	uintptr_t glowManager = CMem.readMem<uintptr_t>(map.GameModule + gos.glowManager);

	int pTeam = CMem.readMem<int>(map.LocalPlayer + gos.Team);

	//entity loop
	for (int i = 0; i < 64; i++)
	{
		uintptr_t EntityList = CMem.readMem<uintptr_t>(map.GameModule + gos.EntityList + i * 0x10);

		if (EntityList != NULL)
		{
			int glowIndex = CMem.readMem<int>(EntityList + gos.GlowIdx);
			int entTeam = CMem.readMem<int>(EntityList + gos.Team);
			//This is horrible, can easily be cleaned up. Later of course.
			if (pTeam != entTeam)
			{
				CMem.writeMem<float>(glowManager + ((glowIndex * 0x38) + 0x4), 2);
				CMem.writeMem<float>(glowManager + ((glowIndex * 0x38) + 0x8), 0);
				CMem.writeMem<float>(glowManager + ((glowIndex * 0x38) + 0xC), 0);
				CMem.writeMem<float>(glowManager + ((glowIndex * 0x38) + 0x10), 0.7);
			}
			else
			{
				CMem.writeMem<float>(glowManager + ((glowIndex * 0x38) + 0x4), 0);
				CMem.writeMem<float>(glowManager + ((glowIndex * 0x38) + 0x8), 0);
				CMem.writeMem<float>(glowManager + ((glowIndex * 0x38) + 0xC), 2);
				CMem.writeMem<float>(glowManager + ((glowIndex * 0x38) + 0x10), 0.7);
			}
			CMem.writeMem<bool>(glowManager + ((glowIndex * 0x38) + 0x24), true); //Glow Occluded
			CMem.writeMem<bool>(glowManager + ((glowIndex * 0x38) + 0x25), false); // Glow Unoccluded
		}
	}
	*/

}
