#include "SpaceGamePlayerController.h"
#include <EnhancedInputSubsystems.h>
#include <Kismet/GameplayStatics.h>
#include <EnhancedInputComponent.h>

void ASpaceGamePlayerController::BeginPlay()
{
	Super::BeginPlay();

	/**
	*	マッピングコンテキストの追加
	*/
	if (ULocalPlayer* LP = GetLocalPlayer())
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
			LP->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}

	/**
	*	GameManagerの取得
	*/
	GameManager = Cast<AGameManager>(
		UGameplayStatics::GetActorOfClass(GetWorld(), AGameManager::StaticClass()));
}


void ASpaceGamePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EIC->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ASpaceGamePlayerController::HandleMove);
		EIC->BindAction(MoveAction, ETriggerEvent::Completed, this, &ASpaceGamePlayerController::HandleMoveCompleted);
	}
}

void ASpaceGamePlayerController::HandleMove(const FInputActionValue& Value)
{
	FVector2D Axis = Value.Get<FVector2D>();
	if (GameManager && GameManager->GetPlayerObject())
	{
		GameManager->GetPlayerObject()->SetInputAxis(Axis.X, Axis.Y);
	}
}

void ASpaceGamePlayerController::HandleMoveCompleted(const FInputActionValue& Value)
{
	if (GameManager && GameManager->GetPlayerObject())
	{
		GameManager->GetPlayerObject()->SetInputAxis(0.f, 0.f);
	}
}