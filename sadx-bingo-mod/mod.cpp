#include "pch.h"
#include "goal.h"

HelperFunctions HelperFunctionsGlobal;
std::string modpath;

Goal loadedGoals[25];
CharacterInPlaceGoal inplacegoals[3];

extern "C" {
	__declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions& helperFunctions)
	{
		HelperFunctionsGlobal = helperFunctions; // Save the helper pointer for external use
		modpath = path;

		//ReadConfig(path, helperFunctions);

		//loadedGoals[0] = Goal();
		//inplacegoals[0] = CharacterInPlaceGoal(NJS_POINT3{ 1940, 175, 1430 }, NJS_POINT3{ 2120, 220, 1600 }, Characters_Amy, LevelAndActIDs_MysticRuins1);

		
	}


	__declspec(dllexport) void __cdecl OnFrame()
	{
		if (Controllers[0].PressedButtons & Buttons_Y)
		{
			
		}

		if (playertwp[0] != NULL)
		{
			//inplacegoals[0].callUpdateFuncPtr();
		}
	}

	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer };
}