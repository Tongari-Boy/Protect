#include "Migration/ShipVisual.h"

/** コンストラクタ */
AShipVisual::AShipVisual()
{
	PrimaryActorTick.bCanEverTick = false;	/** Tickは持たせないため、無効化 */

	RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("RootScene"));
	RootComponent = RootScene;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetupAttachment(RootScene);
}

void AShipVisual::ApplyTransform(const FTransform& WorldTransform, const FTransform& ModelOffset)
{
	SetActorTransform(WorldTransform);				/** アクター本体 */
	MeshComp->SetRelativeTransform(ModelOffset);	/** モデルの向き・スケール */
}