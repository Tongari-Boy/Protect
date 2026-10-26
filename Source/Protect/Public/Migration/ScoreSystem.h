#pragma once

#include "CoreMinimal.h"
#include "Migration/CustomCollisionEvent.h"

#include "ScoreSystem.generated.h"

/** UI側はこれをAddUObject / AddLambdaで購読するだけで、ScoreSystem内部を知らなくて済む */
DECLARE_MULTICAST_DELEGATE_OneParam(FOnScoreChanged, int32 /*NewScore*/);


/**
*	スコアシステム
*/
UCLASS()
class PROTECT_API UScoreSystem : public UObject
{
	GENERATED_BODY()

public:
	// 衝突イベント発火時に呼ばれる処理
	void HandleCollision(const FCustomCollisionEvent& Event);

	// UI側が購読するデリケート(スコアが変化するたびBroadcastされる)
	FOnScoreChanged OnScoreChanged;

	// 現在スコアのゲッター
	int32 GetScore() const { return Score; };
	// スコアのリセット
	void Reset();

private:
	int32 Score = 0;	// スコアの実データ

	// スコア加算
	void AddScore(int32 Amount);
};
