#pragma once

#include "CoreMinimal.h"
#include "Migration/StageObject.h"

#include "EnemyObject.generated.h"


/**
 * 
 */
UCLASS()
class PROTECT_API UEnemyObject : public UStageObject
{
	GENERATED_BODY()
	
public:
	void Init(const FVector& Pos, float InRadius, int32 Hp);

	virtual void Update(float DeltaTime,const FVector& PlaterPos);

	void AddHp(int Amount);
	void SubtractHp(int Amount);

	int32 GetCurrentHp() const { return CurrentHp; };
	int32 GetMaxHp() const { return MaxHp; };

private:
	int32 CurrentHp = 0;
	int32 MaxHp = 0;
};