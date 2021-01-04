#include "Entity.h"
MemMan MMan;


uintptr_t Entity::getBaseEntity(int index)
{
	return MMan.readMem<uintptr_t>(map::GameModule() + getOffsets::EntityList + (index * 0x10));
}

int	Entity::getEntHp(uintptr_t pEnt)
{
	return MMan.readMem<int>(pEnt + getOffsets::Health);
}

bool Entity::isAlive(uintptr_t pEnt)
{
	if (getEntHp(pEnt) > 0 && getEntHp(pEnt) <= 100)
		return true;
	return false;
}

int	Entity::getEntTeam(uintptr_t pEnt)
{
	return MMan.readMem<int>(pEnt + getOffsets::Team);
}

int Entity::getGlowIndex(uintptr_t pEnt)
{
	return MMan.readMem<int>(pEnt + getOffsets::GlowIdx);
}

uintptr_t Entity::getGlowObj()
{
	return MMan.readMem<uintptr_t>(map::GameModule() + getOffsets::glowManager);
}

bool Entity::isValid(uintptr_t pEnt)
{
	auto dormant = MMan.readMem<bool>(pEnt + getOffsets::bDormant);
	if ((Entity::isAlive(pEnt) && Entity::getEntTeam(pEnt) != 0) && !dormant)
		return true;
	return false;
}

//TODO: MINIMISE WPM CALLS HERE BY USING A GLOW STRUCT 
void Entity::glowEsp(uintptr_t glowObj, int glowInd, float r, float g, float b, float a)
{
	MMan.writeMem<float>(r / 255, (glowObj + ((glowInd * 0x38) + 0x4)));
	MMan.writeMem<float>(g / 255, (glowObj + ((glowInd * 0x38) + 0x8)));
	MMan.writeMem<float>(b / 255, (glowObj + ((glowInd * 0x38) + 0xC)));
	MMan.writeMem<float>(a / 255, (glowObj + ((glowInd * 0x38) + 0x10)));
	MMan.writeMem<bool>(true, (glowObj + ((glowInd * 0x38) + 0x24)));
	MMan.writeMem<bool>(false, (glowObj + ((glowInd * 0x38) + 0x25)));
}

bool Entity::getSpotted(uintptr_t pEnt)
{
	return MMan.readMem<bool>(pEnt + getOffsets::bSpotted);
}

void Entity::setSpotted(uintptr_t pEnt, bool val)
{
	MMan.writeMem<bool>(pEnt + getOffsets::bSpotted, val);
}

D3DXVECTOR3	Entity::getEntPos(uintptr_t pEnt)
{
	return MMan.readMem<D3DXVECTOR3>(pEnt + getOffsets::vecOrigin);
}

char* Entity::getEntName(uintptr_t pEnt)
{
	return MMan.readMem<char*>(pEnt + getOffsets::szCustomName);
}

uintptr_t Entity::getEntBoneMatrix(uintptr_t pEnt)
{
	return MMan.readMem<uintptr_t>(pEnt + getOffsets::boneMatrix);
}

D3DXVECTOR3 Entity::getEntEyePos(uintptr_t pEnt)
{
	return ((Entity::getEntPos(pEnt)) + (MMan.readMem<D3DXVECTOR3>(pEnt + getOffsets::vecViewOffset)));
}

bool Entity::getEntScoped(uintptr_t pEnt)
{
	return MMan.readMem<bool>(pEnt + getOffsets::IsScoped);
}

bool Entity::getEntDefusing(uintptr_t pEnt)
{
	return MMan.readMem<bool>(pEnt + getOffsets::IsDefusing);
}

bool Entity::getEntReloading(uintptr_t pEnt)
{
	return MMan.readMem<bool>(pEnt + getOffsets::InReload);
}

bool Entity::getEntHelmet(uintptr_t pEnt)
{
	return MMan.readMem<bool>(pEnt + getOffsets::HasHelmet);
}

bool Entity::getEntDefuser(uintptr_t pEnt)
{
	return MMan.readMem<bool>(pEnt + getOffsets::HasDefuser);
}

bool Entity::getEntImmunity(uintptr_t pEnt)
{
	return MMan.readMem<bool>(pEnt + getOffsets::GunGameImmunity);
}

uintptr_t Entity::getActiveWeapon(uintptr_t pEnt)
{
	uintptr_t WeaponIndex = MMan.readMem<uintptr_t>(pEnt + getOffsets::hActiveWeapon) & 0xFFF;
	return MMan.readMem<uintptr_t>((map::GameModule() + getOffsets::EntityList + WeaponIndex * 0x10) - 0x10);
}

//Uses ClassID
bool Entity::isWeaponNonAim(int classID)
{
	if (classID == CKnife || classID == CKnifeGG || classID == CFlashbang || classID == CHEGrenade || classID == CSmokeGrenade
		|| classID == CMolotovGrenade || classID == CDecoyGrenade || classID == CIncendiaryGrenade || classID == CC4)
		return true;
	return false;
}

//Uses iItemDefinitionIndex
bool Entity::isWeaponNonAim2(int iWeaponID)
{
	if (iWeaponID == weapon_knife || iWeaponID == weapon_knifegg || iWeaponID == weapon_flashbang || iWeaponID == weapon_hegrenade || iWeaponID == weapon_smokegrenade
		|| iWeaponID == weapon_molotov || iWeaponID == weapon_decoy || iWeaponID == weapon_c4 || iWeaponID == weapon_incgrenade)
		return true;
	return false;
}

//Uses ClassID
bool Entity::isWeaponPistol(int classID)
{
	if (classID == CDEagle || classID == CWeaponElite || classID == CWeaponFiveSeven || classID == CWeaponGlock
		|| classID == CWeaponP228 || classID == CWeaponUSP || classID == CWeaponTec9 || classID == CWeaponTaser || classID == CWeaponHKP2000 || classID == CWeaponP250)
		return true;

	return false;
}

//Uses ClassID
bool Entity::isWeaponSniper(int classID)
{
	if (classID == CWeaponAWP || classID == CWeaponSSG08 || classID == CWeaponG3SG1 || classID == CWeaponSCAR20)
		return true;

	return false;
}

int	Entity::getEntClassID(uintptr_t pEnt)
{
	int one = MMan.readMem<int>(pEnt + 0x8);
	int two = MMan.readMem<int>(one + 2 * 0x4);
	int three = MMan.readMem<int>(two + 0x1);
	return MMan.readMem<int>(three + 0x14);
}

D3DXVECTOR3	Entity::getEntBonePos(uintptr_t pEnt, int boneID)
{
	Matrix3x4_t boneMatrix = MMan.readMem<Matrix3x4_t>(Entity::getEntBoneMatrix(pEnt) + boneID * 0x30);

	return{
		boneMatrix.Matrix[0][3],
		boneMatrix.Matrix[1][3],
		boneMatrix.Matrix[2][3]
	};
}

int Entity::getEntAmmo(uintptr_t pEnt)
{
	auto weapon = Entity::getActiveWeapon(pEnt);
	return MMan.readMem<int>(weapon + getOffsets::iClip);
}