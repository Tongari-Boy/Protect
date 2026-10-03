#include "Migration/RockVisual.h"


/**
*	コンストラクタ
*		モデルのヒエラルキーを設定
*/
ARockVisual::ARockVisual()
{
	PrimaryActorTick.bCanEverTick = false;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	RootComponent = MeshComp;
	MeshComp->SetRelativeScale3D(FVector(1.0f));

	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
}

/**
*	位置を適用する
*		StageManager::Init()で呼ばれる
*/
void ARockVisual::ApplyTransform(const FTransform& WorldTransform)
{
	SetActorTransform(WorldTransform);
}

/**
*	アクティブ状隊によって、見た目・当たり判定のオン/オフを切り替える
*		StageManager::Init()、StageManager::Update()で呼ばれる
*/
void ARockVisual::SetVisualActive(bool bActive)
{
	SetActorHiddenInGame(!bActive);
	SetActorEnableCollision(bActive);
}