#include "offset.hpp"
#include "hacks.h"


void calcDelay(uintptr_t pEnt)
{
	//Vector3 pLocation = CMem.readMem<Vector3>(map.LocalPlayer + gos.vecOrigin);
	//Vector3 entLocation = CMem.readMem<Vector3>(pEnt + gos.vecOrigin);

	//Return distance in (m)
	//float distance = sqrt(pow(pLocation.x - entLocation.x, 2) + pow(pLocation.y - entLocation.y, 2)
	//+ pow(pLocation.z - entLocation.z, 2)) * 0.0254;

	//map.triggerDelay = distance * 3.3;
}

//Check if trigger can fire.
bool triggerCheck()
{
	/*
	int crosshair = CMem.readMem<int>(map.LocalPlayer + gos.CrosshairID);
	if (crosshair != 0 && crosshair < 64)
	{
		uintptr_t pEnt = CMem.readMem<uintptr_t>(map.GameModule + gos.EntityList + ((crosshair - 1) * 0x10));
		int enemyTeam = CMem.readMem<int>(pEnt + gos.Team);
		int enemyHealth = CMem.readMem<int>(pEnt + gos.Health);
		if (enemyTeam != map.myTeam && enemyHealth > 0)
		{
			calcDelay(pEnt);

			return true;
		}
	}
	else

	return false;
	*/
};

void Hacks::triggerbot()
{
	/*
	if (GetAsyncKeyState(VK_F2) & 1){
		canShoot = !canShoot;
	}

	map.myTeam = CMem.readMem<int>(map.LocalPlayer + gos.Team);
	if (canShoot && triggerCheck())
	{
		mouse_event(MOUSEEVENTF_LEFTDOWN, NULL, NULL, NULL, NULL);
		Sleep(10);
		mouse_event(MOUSEEVENTF_LEFTUP, NULL, NULL, NULL, NULL);
	}
	*/
}
