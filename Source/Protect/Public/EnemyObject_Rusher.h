#pragma once

#include "CoreMinimal.h"
#include "EnemyObject.h"
#include "EnemyObject_Rusher.generated.h"

/**
 * 
 */
UCLASS()
class PROTECT_API UEnemyObject_Rusher : public UEnemyObject
{
	GENERATED_BODY()

public:
	virtual void Update(float DeltaTime, const FVector& PlayerPos) override;

private:
	float RushSpeed = 400.0f;
};
