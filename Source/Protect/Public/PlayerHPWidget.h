#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/ProgressBar.h"

#include "PlayerHPWidget.generated.h"

/**
 *	プレイヤーの体力を表示するウィジェット 
 */
UCLASS()
class PROTECT_API UPlayerHPWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

public:
	// 体力の割合をプログレスバーに適用
	UFUNCTION(BlueprintCallable, Category = "UI")
	void SetHPPercentToBar(float InPercent);

protected:
	// プログレスバーの参照
	UPROPERTY(meta=(BindWidget))
	UProgressBar* HPBar;
};
