#include "BulletVisual.h"


ABulletVisual::ABulletVisual()
{
	PrimaryActorTick.bCanEverTick = false;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	RootComponent = MeshComp;
	MeshComp->SetRelativeScale3D(FVector(0.2f));

	/**
	*	初期設定では、全ての弾の見た目を隠す/当たり判定を無効化する
	*/
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
}

void ABulletVisual::ApplyTransform(const FTransform& WorldTransform)
{
	SetActorTransform(WorldTransform);
}

void ABulletVisual::SetVisualActive(bool bActive)
{
	SetActorHiddenInGame(!bActive);
	SetActorEnableCollision(bActive);
}