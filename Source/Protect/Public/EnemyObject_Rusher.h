#pragma once

#include "CoreMinimal.h"
#include "EnemyObject.h"

#include "EnemyObject_Rusher.generated.h"


/**
 * 突進してくる敵の論理クラス
 *	継承元のUEnemyObjectクラスのUpdate関数をオーバーライドして、突進する処理を実装
 */
UCLASS()
class PROTECT_API UEnemyObject_Rusher : public UEnemyObject
{
	GENERATED_BODY()

public:
	virtual void Update(float DeltaTime, const FVector& PlayerPos,const FVector& PlayerCameraPos) override;

private:
	float RushSpeed = 400.0f;
};
