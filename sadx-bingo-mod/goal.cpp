#include "pch.h"
#include "goal.h"
#include "goalFunctions.h"

#pragma region Function Pointer Definitions
void Goal::setSetupFuncPtr(void (*func)(Goal*))
{
	setupFunc = func;
}
void Goal::setUpdateFuncPtr(void (*func)(Goal*))
{
	updateFunc = func;
}
void Goal::setResetFuncPtr(void (*func)(Goal*))
{
	restartFunc = func;
}
void Goal::callSetupFuncPtr()
{
	if (setupFunc != nullptr)
	{
		setupFunc(this);
	}
}
void Goal::callUpdateFuncPtr()
{
	if (updateFunc != nullptr)
	{
		updateFunc(this);
	}
}
void Goal::callResetFuncPtr()
{
	if (restartFunc != nullptr)
	{
		restartFunc(this);
	}
}
#pragma endregion

Goal::Goal(Characters character, LevelAndActIDs levelAndAct)
{
	this->character = character;
	this->levelAndAct = levelAndAct;
}

CharacterInPlaceGoal::CharacterInPlaceGoal(NJS_POINT3 collboxp1, NJS_POINT3 collboxp2, Characters character, LevelAndActIDs levelAndAct) : Goal(character, levelAndAct)
{
	this->CollideBoxPoint1 = collboxp1;
	this->CollideBoxPoint2 = collboxp2;

	updateFunc = (void(*)(Goal*))(&characterInPlaceUpdate);
}

RingGoal::RingGoal(int ringCount, Characters character, LevelAndActIDs levelAndAct) : Goal(character, levelAndAct)
{

}