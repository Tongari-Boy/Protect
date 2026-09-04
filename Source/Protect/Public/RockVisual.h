#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "RockVisual.generated.h"

UCLASS()
class PROTECT_API ARockVisual : public AActor
{
	GENERATED_BODY()
	
public:	
	/** コンストラクタ */
	ARockVisual();

	void ApplyTransform(const FTransform& WorldTransform);
	void SetVisualActive(bool bActive);

private:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* MeshComp;
};
