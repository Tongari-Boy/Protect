#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyVisual.generated.h"

UCLASS()
class PROTECT_API AEnemyVisual : public AActor
{
	GENERATED_BODY()
	
public:	
	/** コンストラクタ */
	AEnemyVisual();

	void ApplyTransform(const FTransform& WorldTransform);

	void SetVisualActive(bool isActive);

private:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* MeshComp;
};