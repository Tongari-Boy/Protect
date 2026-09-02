#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "ShipVisual.generated.h"

/**
*	見た目用クラス
*/
UCLASS()
class PROTECT_API AShipVisual : public AActor
{
	GENERATED_BODY()
	
public:	
	// コンストラクタ
	AShipVisual();

	void ApplyTransform(const FTransform& WorldTransform, const FTransform& ModelOffset);

private:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* MeshComp;
};
