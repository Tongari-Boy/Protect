#include "GameManager.h"

// コンストラクタ
AGameManager::AGameManager()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AGameManager::BeginPlay()
{
	Super::BeginPlay();

	/**
	*	Playerの初期化
	*/
	Player = NewObject<UPlayerObject>(this);
	Player->Init();

	PlayerVisual = GetWorld()->SpawnActor<AShipVisual>(PlayerVisualClass);

	if (APlayerController* PC = GetWorld()->GetFirstPlayerController())
	{
		PC->SetViewTarget(PlayerVisual);
	}

	BulletManager = NewObject<UBulletManager>(this);
	BulletManager->Init(GetWorld(),BulletVisualClass);
}

void AGameManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Player->Update(DeltaTime);
	PlayerVisual->ApplyTransform(Player->Transform, Player->ModelTransform);

	BulletManager->Update(DeltaTime);
}

void AGameManager::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{

}