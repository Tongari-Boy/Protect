#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputMappingContext.h"

#include "GameManager.h"

#include "SpaceGamePlayerController.generated.h"

/**
 * 
 */
UCLASS()
class PROTECT_API ASpaceGamePlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	UPROPERTY(EditDefaultsOnly,Category="Input")
	UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* MoveAction;

	void HandleMove(const FInputActionValue& Value);
	void HandleMoveCompleted(const FInputActionValue& Value);

	UPROPERTY()
	AGameManager* GameManager;
};
