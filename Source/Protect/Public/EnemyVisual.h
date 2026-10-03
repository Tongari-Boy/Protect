#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "EnemyVisual.generated.h"


/**
* 敵の物理クラス
*/
UCLASS()
class PROTECT_API AEnemyVisual : public AActor
{
	GENERATED_BODY()
	
public:	
	// コンストラクタ
	AEnemyVisual();
	// Transformの適用(更新処理)
	void ApplyTransform(const FTransform& WorldTransform);
	void SetVisualActive(bool isActive);

private:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* MeshComp;
};
