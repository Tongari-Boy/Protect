#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"

#include "PlayerStaminaWidget.generated.h"


/**
 * 
 */
UCLASS()
class PROTECT_API UPlayerStaminaWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	UImage* StaminaImage;

	UPROPERTY()
	UMaterialInstanceDynamic* DynamicMaterial;

public:
	UFUNCTION(BlueprintCallable, Category = "UI")
	void SetStaminaPercent(float InPercent);
};
