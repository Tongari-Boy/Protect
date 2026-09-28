#pragma once

#include "CoreMinimal.h"

#include "CustomCollisionEvent.h"

#include "SoundSystem.generated.h"


/**
*	サウンドシステム
*/
UCLASS()
class PROTECT_API USoundSystem : public UObject
{
	GENERATED_BODY()

public:
	// 初期化とサウンドアセットの登録
	void Init(UWorld* InWorld, USoundBase* InStageSound, USoundBase* InEnemySound);

	// 衝突イベントに応じたサウンドの発生処理
	void HandleCollision(const FCustomCollisionEvent& Event);

private:

	// 各サウンドアセットの格納郡

	USoundBase* StageSound = nullptr;	// ステージ衝突用
	USoundBase* EnemySound = nullptr;	// 敵消滅用

	// ワールドが破棄時の安全性考慮し、弱参照で保持
	TWeakObjectPtr<UWorld> World;
};