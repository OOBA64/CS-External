#pragma once 
#include "includes.h"
#include "math.h"
#include "offset.hpp"

#include <d3d9.h>
#include <d3dx9.h>

//Grabbed from null base, thanks for the organization.
namespace LocalPlayer
{


	uintptr_t		getLocalPlayer();												
	int				getLocalFlags();												
	int				getLocalHealth();												
	int				getLocalCrossID();												
	int				getLocalTeam();	
	Vector3			getLocalPos();													
	Vector3			getLocalViewAngles();											
	Vector3			getLocalPunchAngles();											
	D3DXMATRIX		getLocalViewMatrix();

	void				setLocalPlayer();												
	void				setLocalViewAngles(Vector3 angles);								

	extern uintptr_t			LocalBaseAddress;	
	//extern uintptr_t Process;
	//extern uintptr_t GameModule;
}