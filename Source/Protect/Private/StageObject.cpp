#include "StageObject.h"

void UStageObject::Init(const FVector& Pos, float InRadius)
{
	bIsActive = true;
	bIsHit = false;
	Radius = InRadius;
	Transform.SetLocation(Pos);
}