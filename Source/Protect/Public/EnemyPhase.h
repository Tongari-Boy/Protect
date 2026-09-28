#pragma once

#include "CoreMinimal.h"
#include "EnemyPhase.generated.h"

class UEnemyObject;
class AEnemyVisual;


/**
 *	敵1体分の配置情報など
 */
USTRUCT(BlueprintType)
struct FEnemySpawnInfo
{
	GENERATED_BODY()

	/** EnemyObjectにすることで、後の派生敵を指定できるようにする */
	UPROPERTY(EditAnywhere, Category = "Enemy")
	TSubclassOf<UEnemyObject> EnemyClass;

	UPROPERTY(EditAnywhere, Category = "Enemy")
	TSubclassOf<AEnemyVisual> VisualClass;

	UPROPERTY(EditAnywhere, Category = "Enemy")
	FVector SpawnPosition = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, Category = "Enemy")
	float Radius = 10.0f;

	UPROPERTY(EditAnywhere, Category = "Enemy")
	int32 Hp = 10;
};

/**
*	1フェーズの敵のまとまり
*/
USTRUCT(BlueprintType)
struct FEnemyPhase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Phase")
	float TriggerX = 0.0f;

	UPROPERTY(EditAnywhere, Category = "Phase")
	TArray<FEnemySpawnInfo> Enemies;

	/**
	*	フェーズ開始フラグ
	*		重複防止用
	*/
	bool bTriggered = false;
};