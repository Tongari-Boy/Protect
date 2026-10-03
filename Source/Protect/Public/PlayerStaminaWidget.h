#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"

#include "PlayerStaminaWidget.generated.h"


/**
 * プレイヤのスタミナを表示するウィジェット
 */
UCLASS()
class PROTECT_API UPlayerStaminaWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

	// スタミナの画像
	UPROPERTY(meta = (BindWidget))
	UImage* StaminaImage;

	// スタミナの画像のマテリアルインスタンスを動的に変更
	UPROPERTY()
	UMaterialInstanceDynamic* DynamicMaterial;

public:
	// スタミナの割合を画像に適用
	UFUNCTION(BlueprintCallable, Category = "UI")
	void SetStaminaPercent(float InPercent);
};
