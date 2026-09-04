#include "GameManager.h"

#include "CollisionSystem.h"

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

	/** Stageの初期化 */
	StageManager = NewObject<UStageManager>(this);
	
	TArray<FVector> RockPositions =
	{
		FVector(1000,0,0),
		FVector(1500,200,0),
		FVector(2000,-200,0),
	};

	StageManager->Init(GetWorld(), RockVisualClass, RockPositions);

	/** イベント関連 */
	EventBus = NewObject<UEventBus>(this);
	
	/**
	*	イベント発火時のシステム郡
	*		[feature]スコア加算やサウンド、エフェクトシステムを追加する
	*/
	EventBus->OnCollision.AddLambda([](const FCustomCollisionEvent& Event)
	{
			UE_LOG(LogTemp, Warning, TEXT("Hit"));
	});
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

	/** ステージの更新 */
	StageManager->Update(DeltaTime);

	TArray<FCustomCollisionEvent> Events;
	FCollisionSystem::CheckBulletVsStage(*BulletManager, *StageManager, Events);

	for (const FCustomCollisionEvent& Event : Events)
	{
		EventBus->Publish(Event);
	}
}

void AGameManager::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{

}