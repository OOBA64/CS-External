#include "includes.h"
#include "stdlib.h"
#include "Utils.h"
#include "hacks.h"
#include "math.h"
#include "offset.hpp"

using namespace std;
MemMan MM;

bool canHop; 

struct gameValues
{
	DWORD process;
	DWORD GameModule;
	DWORD LocalPlayer;
}val;


//Not sure if string encryption even does anything, but better safe than sorry. ¯\_(ツ)_/¯
int main()
{

	val.process = MM.getProcess("csgo.exe");
	val.GameModule = MM.getModule(val.process, "client.dll");							// <-- Remove any of these and the cheat will break
	val.LocalPlayer = MM.readMem<DWORD>(map::GameModule() + getOffsets::LocalPlayer);	

	/*If I wanted just to call the getproc or getmodule funcs to initialize them, 
	that doesn't work either.*/

	//MM.getProcess("csgo.exe");
	//MM.getModule(map::Process(), "client.dll"); //Using these will get you to jump once or twice then stop till you hit space again (unbind space from jump to make sure its working) 

	//map::GameModule(); 
	//map::Process();    //This doesn't work either.

	LocalPlayer::setLocalPlayer(); // <-- Maybe I need to initialize getproc and getmod like this. Remove this and it breaks.

	if (!map::Process())
		cout << (XOR("Get Process ERROR! Target Process Not Found.")) << endl;
	else
		cout << (XOR("Get Process Successful: ")) << map::Process() << endl;

	if (!map::GameModule())
		cout << (XOR("Get Module ERROR!")) << endl;
	else
		cout << hex << (XOR("Get Module Successful: ")) << map::GameModule() << std::endl; 

	if (LocalPlayer::getLocalPlayer() == NULL)
	{
		cout << "Local Player is null" << endl;
	}
	
	if (true)
	{
		cout << "" << endl; //spacing
		cout << "Process" << endl;
		cout << hex << val.process << endl;
		cout << hex << map::Process() << endl;

		cout << "" << endl; //spacing
		cout << "GameModule" << endl;
		cout << hex << val.GameModule << endl;
		cout << hex << map::GameModule << endl;

	}


	if (map::Process && map::GameModule)
	{
		//Spacing
		cout << (XOR("")) << endl;

		cout << (XOR("F1: BHOP")) << endl; 
		cout << (XOR("F2: TriggerBot")) << endl;
		cout << (XOR("F3: Radar-Reveal")) << endl; 
		cout << (XOR("F4: No-Flash")) << endl; 
		cout << (XOR("F5: GlowESP")) << endl;
	}

	//Hack Loop
	while (true)
	{
		
		//Hacks::bhop(); //Same code as below in a different file. Should work, but doesn't. 
		

		BYTE Flag;

		//Simple Toggle
		if (GetAsyncKeyState(VK_F1) & 1)
		{
			canHop = !canHop;
		}

		Flag = MM.readMem<BYTE>(LocalPlayer::getLocalPlayer() + getOffsets::fFlags);

		//If holding space, and LP on ground, then force jmp.
		if (GetAsyncKeyState(VK_SPACE) && Flag & (1 << 0))
		{
			MM.writeMem<DWORD>(map::GameModule() + getOffsets::ForceJmp, 6); //Using the map::GameModule func over val.GameModule will make the hops very inconsistent. 
		}
		
		Sleep(1);
	}

	


	return 0; 
};