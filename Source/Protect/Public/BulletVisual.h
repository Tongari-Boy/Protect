#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "BulletVisual.generated.h"

UCLASS()
class PROTECT_API ABulletVisual : public AActor
{
	GENERATED_BODY()
	
public:	
	ABulletVisual();

	void ApplyTransform(const FTransform& WorldTransform);
	void SetVisualActive(bool bActive);

private:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* MeshComp;
};
