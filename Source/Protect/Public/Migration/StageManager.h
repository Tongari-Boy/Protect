#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"

#include "Migration/RockVisual.h"
#include "Migration/StageObject.h"

#include "StageManager.generated.h"


/**
 *	ステージオブジェクト全体を管理するクラス
 */
UCLASS()
class PROTECT_API UStageManager : public UObject
{
	GENERATED_BODY()

public:
	/** 初期化処理　*/
	void Init(UWorld* World, TSubclassOf<ARockVisual> VisualClass, const TArray<FVector>& RockPositions);

	/** 更新処理 */
	void Update(float DeltaTime);

	/** ステージオブジェクトの論理 */
	UPROPERTY()
	TArray<UStageObject*> StageObjects;

	/** ステージオブジェクトの見た目 */
	UPROPERTY()
	TArray<ARockVisual*> StageVisuals;
};