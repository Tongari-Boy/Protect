#include "GameManager.h"

/** コンストラクタ */
AGameManager::AGameManager()
{
	PrimaryActorTick.bCanEverTick = true;
}

/**
*	初期化処理
*		各オブジェクトの初期化を行う
*/
void AGameManager::BeginPlay()
{
	Super::BeginPlay();

	/** Playerの初期化 */
	Player = NewObject<UPlayerObject>(this);
	Player->Init();

	PlayerVisual = GetWorld()->SpawnActor<AShipVisual>(PlayerVisualClass);

	if (APlayerController* PC = GetWorld()->GetFirstPlayerController())
	{
		PC->SetViewTarget(PlayerVisual);
	}

	/** Bulletの初期化 */
	BulletManager = NewObject<UBulletManager>(this);
	BulletManager->Init(GetWorld(),BulletVisualClass);
}

/**
*	更新処理
*		各オブジェクトの更新を行う
*/
void AGameManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	/** Playerの更新 */
	Player->Update(DeltaTime);
	PlayerVisual->ApplyTransform(Player->Transform, Player->ModelTransform);

	/**
	*	Bulletの更新
	*		Bulletの位置の更新などはBulletManager側で行う
	*/
	BulletManager->Update(DeltaTime);
}

void AGameManager::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{

}