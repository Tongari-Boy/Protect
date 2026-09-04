#include "BulletVisual.h"


ABulletVisual::ABulletVisual()
{
	PrimaryActorTick.bCanEverTick = false;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	RootComponent = MeshComp;
	MeshComp->SetRelativeScale3D(FVector(0.2f));

	/** 初期設定では、全ての弾の見た目を隠す/当たり判定を無効化する */
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
}

/**
*	位置の適用
*		BulletManager::Updateで呼ばれる
*/
void ABulletVisual::ApplyTransform(const FTransform& WorldTransform)
{
	SetActorTransform(WorldTransform);
}

/**
*	見た目のオン/オフを切り替える
*		Fireでオン
*		寿命がきたらオフ
*/
void ABulletVisual::SetVisualActive(bool bActive)
{
	SetActorHiddenInGame(!bActive);
	SetActorEnableCollision(bActive);
}