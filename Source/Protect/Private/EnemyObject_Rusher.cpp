#include "EnemyObject_Rusher.h"

void UEnemyObject_Rusher::Update(float DeltaTime, const FVector& PlayerPos)
{
	Super::Update(DeltaTime, PlayerPos);

	if (!bIsActive) return;

	FVector CurrentPos = Transform.GetLocation();
	FVector Dir = (PlayerPos - CurrentPos).GetSafeNormal();
	Transform.SetLocation(CurrentPos + Dir * RushSpeed * DeltaTime);
}