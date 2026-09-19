#include "Migration/CustomCollisionEvent.h"

#include "EnemyObject.h"
#include "Migration/StageObject.h"
#include "Migration/PlayerObject.h"

FVector FCustomCollisionEvent::GetLocation() const
{
	if (EnemyObject) return EnemyObject->Transform.GetLocation();
	if (StageObject) return StageObject->Transform.GetLocation();
	if (PlayerObject) return PlayerObject->Transform.GetLocation();
	return FVector::ZeroVector;
}