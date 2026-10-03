#include "EnemyObject_Rusher.h"


// 突進してくる敵の更新処理
void UEnemyObject_Rusher::Update(float DeltaTime, const FVector& PlayerPos,const FVector& PlayerCameraPos)
{
	Super::Update(DeltaTime, PlayerPos,PlayerCameraPos);

	if (!bIsActive) return;

	FVector CurrentPos = Transform.GetLocation();

	// プレイヤーの背後でなければ
	if (Transform.GetLocation().X > PlayerPos.X)
	{
		/** プレイヤーの位置へ突進する */
		FVector Dir = (PlayerPos - CurrentPos).GetSafeNormal();
		Transform.SetLocation(CurrentPos + Dir * RushSpeed * DeltaTime);
	}
	else
	{
		// 背後にいったら、そのまま突進する
		FVector Dir = FVector(-1, 0, 0); // X軸負方向
		Transform.SetLocation(CurrentPos + Dir * RushSpeed * DeltaTime);
	}

	/** プレイヤーカメラの背後にいったら消える */
	if (Transform.GetLocation().X < PlayerCameraPos.X - 400)
	{
		bIsActive = false;
		return;
	}
}
