#include "offset.hpp"
MemMan CMM;


DWORD getOffsets::LocalPlayer = 0xD882BC;
DWORD getOffsets::EntityList = 0x4D9FBD4;
DWORD getOffsets::ForceAttack = 0x31D1134;
DWORD getOffsets::ForceAttack2 = 0x31D1140; //force scope 
DWORD getOffsets::glowManager = 0x52E81B0;
DWORD getOffsets::GlowIdx = 0xA438;
DWORD getOffsets::ForceJmp = 0x5249B34;
DWORD getOffsets::CrosshairID = 0xB3E4;
DWORD getOffsets::fFlags = 0x104;
DWORD getOffsets::Team = 0xF4;
DWORD getOffsets::Health = 0x100;
DWORD getOffsets::vecOrigin = 0x138;
DWORD getOffsets::bSpotted = 0x93D;
DWORD getOffsets::flashDur = 0xA420;
DWORD getOffsets::ClientState = 0x58EFE4;
DWORD getOffsets::ClientStateViewAng = 0x4D90;
DWORD getOffsets::aimPunchAng = 0x302C;
DWORD getOffsets::viewMatrix = 0x4D914D4;
DWORD getOffsets::bDormant = 0xED;
DWORD getOffsets::szCustomName = 0x303C;
DWORD getOffsets::boneMatrix = 0x26A8;
DWORD getOffsets::vecViewOffset = 0x108;
DWORD getOffsets::IsScoped = 0x3928;
DWORD getOffsets::HasHelmet = 0xB36C;
DWORD getOffsets::IsDefusing = 0x3930;
DWORD getOffsets::InReload = 0x32A5;
DWORD getOffsets::HasDefuser = 0xB388;
DWORD getOffsets::GunGameImmunity = 0x3944;
DWORD getOffsets::hActiveWeapon = 0x2EF8;
DWORD getOffsets::iClip = 0x3264;


DWORD map::Process()
{
	return CMM.getProcess("csgo.exe");
}

DWORD map::GameModule()
{
	return CMM.getModule(map::Process(), ("client.dll"));
}

DWORD map::ClientState()
{ 
	return CMM.getModule(getOffsets::ClientState, ("engine.dll")); 
}
