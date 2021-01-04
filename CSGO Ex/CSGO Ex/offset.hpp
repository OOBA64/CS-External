#pragma once
#include "includes.h"
#include "Utils.h"

//Flags
#define FL_ON_GROUND                     257
#define FL_ON_GROUND_CROUCHED             263
#define FL_IN_AIR_STAND                    256
#define FL_IN_AIR_MOVING_TO_STAND         258
#define FL_ON_GROUND_MOVING_TO_STAND     259
#define FL_IN_AIR_MOVING_TO_CROUCH         260
#define FL_ON_GROUND_MOVING_TO_CROUCH     261
#define FL_IN_AIR_CROUCHED                 262
#define FL_IN_WATER                     1280
#define FL_IN_PUDDLE                     1281
#define FL_IN_WATER_CROUCHED             1286
#define FL_IN_PUDDLE_CROUCHED             1287
#define FL_PARTIALGROUND (1 << 18)



namespace getOffsets
{
	extern DWORD LocalPlayer;
	extern DWORD EntityList;
	extern DWORD ForceAttack;
	extern DWORD ForceAttack2; //scope 
	extern DWORD glowManager;
	extern DWORD GlowIdx;
	extern DWORD ForceJmp;
	extern DWORD CrosshairID;
	extern DWORD fFlags;
	extern DWORD bDormant;
	extern DWORD Team;
	extern DWORD Health;
	extern DWORD szCustomName;
	extern DWORD boneMatrix;
	extern DWORD vecOrigin;
	extern DWORD vecViewOffset;
	extern DWORD bSpotted;
	extern DWORD flashDur;
	extern DWORD ClientState;
	extern DWORD ClientStateViewAng;
	extern DWORD aimPunchAng;
	extern DWORD viewMatrix;
	extern DWORD IsScoped;
	extern DWORD IsDefusing;
	extern DWORD InReload;
	extern DWORD HasHelmet;
	extern DWORD HasDefuser;
	extern DWORD GunGameImmunity;
	extern DWORD hActiveWeapon;
	extern DWORD iClip;
};


namespace map
{
	DWORD Process();
	DWORD GameModule();
	DWORD ClientState();
};
