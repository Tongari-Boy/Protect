#include "ShipVisual.h"

// コンストラクタ
AShipVisual::AShipVisual()
{
	PrimaryActorTick.bCanEverTick = false;	// Tickは持たせないため、無効化

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	RootComponent = MeshComp;
}

void AShipVisual::ApplyTransform(const FTransform& WorldTransform, const FTransform& ModelOffset)
{
	SetActorTransform(ModelOffset * WorldTransform);
}