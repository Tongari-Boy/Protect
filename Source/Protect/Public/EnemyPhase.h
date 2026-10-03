#pragma once

#include "CoreMinimal.h"
#include "EnemyPhase.generated.h"

class UEnemyObject;
class AEnemyVisual;


/**
 *	敵1体分の情報
 *		敵の種類
 *		敵の見た目
 *		発生する場所
 *		半径
 *		体力
 *	をエディタ上で設定できるようにする
 */
USTRUCT(BlueprintType)
struct FEnemySpawnInfo
{
	GENERATED_BODY()

	// EnemyObjectにすることで、後の派生敵を指定できるようにする
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
*		発生のトリガーとなるX座標
* 		敵の配置情報の配列
*	をエディタ上で設定する
*/
USTRUCT(BlueprintType)
struct FEnemyPhase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Phase")
	float TriggerX = 0.0f;

	UPROPERTY(EditAnywhere, Category = "Phase")
	TArray<FEnemySpawnInfo> Enemies;

	// フェーズ開始フラグ(重複防止用)
	bool bTriggered = false;
};
