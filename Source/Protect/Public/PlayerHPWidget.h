#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/ProgressBar.h"

#include "PlayerHPWidget.generated.h"

/**
 *	プレイヤーの体力表示ウィジェット 
 */
UCLASS()
class PROTECT_API UPlayerHPWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

public:
	UFUNCTION(BlueprintCallable, Category = "UI")
	void SetHPPercentToBar(float InPercent);

protected:
	UPROPERTY(meta=(BindWidget))
	UProgressBar* HPBar;
};
