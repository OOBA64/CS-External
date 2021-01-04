#include "offset.hpp"
#include "hacks.h"


static bool canHop = false;
MemMan CMem1;


void Hacks::bhop()
{
	BYTE Flag;


	//Simple Toggle
	if (GetAsyncKeyState(VK_F1) & 1)
	{
		canHop = !canHop;
	}

	uintptr_t LocalP = CMem1.readMem<uintptr_t>(map::GameModule() + getOffsets::LocalPlayer);


	Flag = CMem1.readMem<BYTE>(LocalPlayer::getLocalPlayer() + getOffsets::fFlags); 

	//If holding space, and LP on ground, then force jmp.
	if (GetAsyncKeyState(VK_SPACE) && Flag & (1 << 0))
	{
		//std::cout << "jumping" << std::endl;
		CMem1.writeMem<DWORD>(map::GameModule() + getOffsets::ForceJmp, 6);
	}
}
