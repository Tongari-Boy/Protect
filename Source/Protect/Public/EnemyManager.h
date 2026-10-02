#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"

#include "EnemyObject.h"
#include "EnemyVisual.h"
#include "EnemyPhase.h"

#include "EnemyManager.generated.h"


/**
 * 敵全体の管理クラス
 *	フェーズ、敵の生成、更新、削除などを管理する
 */
UCLASS()
class PROTECT_API UEnemyManager : public UObject
{
	GENERATED_BODY()
	
public:
	void Init(UWorld* InWorld, const TArray<FEnemyPhase>& InPhases);
	void Update(float DeltaTime, const FVector& PlayerPos,const FVector& PlayerCameraPos);

	const TArray<UEnemyObject*>& GetActiveEnemies() const { return ActiveObjects; }

private:
	void TriggerPhase(FEnemyPhase& Phase);

	UPROPERTY()
	TArray<UEnemyObject*> ActiveObjects;

	UPROPERTY()
	TArray<AEnemyVisual*> ActiveVisuals;

	TArray<FEnemyPhase> Phases;

	TWeakObjectPtr<UWorld> World;
};
