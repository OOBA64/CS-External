#include "localplayer.h"
#include "Utils.h"
MemMan CMemMan;

uintptr_t LocalPlayer::LocalBaseAddress = 0;

uintptr_t LocalPlayer::getLocalPlayer()
{
	
	return LocalPlayer::LocalBaseAddress;
}

void LocalPlayer::setLocalPlayer()
{
	LocalPlayer::LocalBaseAddress = CMemMan.readMem<uintptr_t>(map::GameModule() + getOffsets::LocalPlayer);
}

int LocalPlayer::getLocalFlags()
{
	return CMemMan.readMem<int>(LocalPlayer::getLocalPlayer() + getOffsets::fFlags);
}

int LocalPlayer::getLocalHealth()
{
	return CMemMan.readMem<int>(LocalPlayer::getLocalPlayer() + getOffsets::Health);
}

int LocalPlayer::getLocalTeam()
{
	return CMemMan.readMem<int>(LocalPlayer::getLocalPlayer() + getOffsets::Team);
}

int LocalPlayer::getLocalCrossID()
{
	auto temp = CMemMan.readMem<int>(LocalPlayer::getLocalPlayer() + getOffsets::CrosshairID);
	if (temp <= 0 || temp > 32)
		return -1;
	return temp;
}

Vector3 LocalPlayer::getLocalPos()
{
	return CMemMan.readMem<Vector3>(LocalPlayer::getLocalPlayer() + getOffsets::vecOrigin);
}

D3DXMATRIX	LocalPlayer::getLocalViewMatrix()
{
	return CMemMan.readMem<D3DXMATRIX>(map::GameModule() + getOffsets::viewMatrix);
}


Vector3 LocalPlayer::getLocalViewAngles()
{
	return CMemMan.readMem<Vector3>(map::ClientState() + getOffsets::ClientStateViewAng);
}

void LocalPlayer::setLocalViewAngles(Vector3 angles)
{
	//CMemMan.writeMem<Vector3>(map::ClientState + getOffsets::ClientStateViewAng, angles);
}

Vector3 LocalPlayer::getLocalPunchAngles()
{
	return CMemMan.readMem<Vector3>(LocalPlayer::getLocalPlayer() + getOffsets::aimPunchAng);
}
