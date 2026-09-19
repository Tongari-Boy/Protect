#include "EnemyObject_Rusher.h"

void UEnemyObject_Rusher::Update(float DeltaTime, const FVector& PlayerPos)
{
	Super::Update(DeltaTime, PlayerPos);

	if (!bIsActive) return;

	/** プレイヤーの位置へ突進する */
	FVector CurrentPos = Transform.GetLocation();
	FVector Dir = (PlayerPos - CurrentPos).GetSafeNormal();
	Transform.SetLocation(CurrentPos + Dir * RushSpeed * DeltaTime);

	/** プレイヤーの背後にいったら消える */
	if (Transform.GetLocation().X < PlayerPos.X)
	{
		bIsActive = false;
		return;
	}
}