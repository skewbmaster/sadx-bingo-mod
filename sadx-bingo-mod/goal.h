#pragma once

void yeahwhat();
void shit();


class Goal
{
public:
	void (*setupFunc)(Goal*)   = nullptr;
	void (*updateFunc)(Goal*)  = nullptr;
	void (*restartFunc)(Goal*) = nullptr;

	bool finished = false;
	Characters character;
	LevelAndActIDs levelAndAct;

	void setSetupFuncPtr(void (*func)(Goal*));
	void setUpdateFuncPtr(void (*func)(Goal*));
	void setResetFuncPtr(void (*func)(Goal*));
	void callSetupFuncPtr();
	void callUpdateFuncPtr();
	void callResetFuncPtr();

	Goal(Characters character, LevelAndActIDs levelAndAct);
};

class CharacterInPlaceGoal : public Goal
{
public:
	NJS_POINT3 CollideBoxPoint1;
	NJS_POINT3 CollideBoxPoint2;

	CharacterInPlaceGoal(NJS_POINT3 collboxp1, NJS_POINT3 collboxp2, Characters character, LevelAndActIDs levelAndAct);
};

class RingGoal : public Goal
{
public:
	int ringCount;

	RingGoal(int ringCount, Characters character, LevelAndActIDs levelAndAct);
};