#include "Migration/SoundSystem.h"

#include "Kismet/GameplayStatics.h"
#include "Migration/StageObject.h"


/**
*	初期化処理
*		UObjectではデフォルトでGetWorld()を持たないため、
*		外部(GameManager)から明示的に UWorld を渡して保持させる。
*
*		また、ワールド破棄時にこのシステムが残留した場合のダングリングポインタを防ぐため、
*		TWeakObjectPtrを採用している
*/
void USoundSystem::Init(UWorld* InWorld,USoundBase* InStageSound, USoundBase* InEnemySound)
{
	World = InWorld;
	StageSound = InStageSound;
	EnemySound = InEnemySound;
}

void USoundSystem::HandleCollision(const FCustomCollisionEvent& Event)
{
	if (!World.IsValid()) return;

	USoundBase* SoundToSpawn = nullptr;

	/** 
	*	発生したイベントの種類から
	*		鳴らすサウンドを決める
	* 
	*	[feature]現在はステージオブジェクトと敵の2種類のため、
	*			 2値の判定で実装できているが、今後イベントの種類が増えることを見越した実装にする
	*/
	if (Event.StageObject == nullptr)
	{
		SoundToSpawn = EnemySound;
	}
	else
	{
		SoundToSpawn = StageSound;
	}

	/** 衝突した岩の位置でサウンドを鳴らす */
	UGameplayStatics::PlaySoundAtLocation(
		World.Get(),
		SoundToSpawn,
		Event.GetLocation()
	);

	UE_LOG(LogTemp, Warning, TEXT("Sound"));
}