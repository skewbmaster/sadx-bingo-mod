#include "pch.h"
#include "goal.h"
#include "goalFunctions.h"

bool CubeCollision(NJS_POINT3* collboxp1, NJS_POINT3* collboxp2, NJS_POINT3* colliderObj)
{
	return (colliderObj->x > collboxp1->x &&
			colliderObj->y > collboxp1->y &&
			colliderObj->z > collboxp1->z &&
			colliderObj->x < collboxp2->x &&
			colliderObj->y < collboxp2->y &&
			colliderObj->z < collboxp2->z);
}

void characterInPlaceUpdate(CharacterInPlaceGoal* goal)
{
	if (goal->character != Characters_Any && goal->character != CurrentCharacter)
		return;

	if (GetLevelAndAct() != goal->levelAndAct)
		return;


	if (CubeCollision(&goal->CollideBoxPoint1, &goal->CollideBoxPoint2, &playertwp[0]->pos))
	{
		
		PrintDebug("Inside the square! %d\n", FrameCounter);
	}
}