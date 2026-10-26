#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "RockVisual.generated.h"


/**
*	岩(ステージオブジェクト)の見た目クラス
*/
UCLASS()
class PROTECT_API ARockVisual : public AActor
{
	GENERATED_BODY()
	
public:	
	/** コンストラクタ */
	ARockVisual();

	/** 位置の適用 */
	void ApplyTransform(const FTransform& WorldTransform);
	/** 見た目・当たり判定の切り替え */
	void SetVisualActive(bool bActive);

private:
	/** 岩のメッシュ */
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* MeshComp;
};
