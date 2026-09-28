#include "Migration/EffectSystem.h"

#include "NiagaraFunctionLibrary.h"
#include "NiagaraSystem.h"
#include "Migration/StageObject.h"


/**
*	初期化処理
*		UObjectではデフォルトでGetWorld()を持たないため、
*		外部(GameManager)から明示的に UWorld を渡して保持させる。
*
*		また、ワールド破棄時にこのシステムが残留した場合のダングリングポインタを防ぐため、
*		TWeakObjectPtrを採用している
*/
void UEffectSystem::Init(UWorld* InWorld,UNiagaraSystem* InStageEffect, UNiagaraSystem* InEnemyEffect)
{
	World = InWorld;
	StageEffect = InStageEffect;
	EnemyEffect = InEnemyEffect;
}

void UEffectSystem::HandleCollision(const FCustomCollisionEvent& Event)
{
	if (!World.IsValid()) return;

	UNiagaraSystem* EffectToSpawn = nullptr;

	/** 
	*	発生したイベントの種類から
	*		再生するエフェクトを決める
	* 
	*	[feature]現在はステージオブジェクトと敵の2種類のため、2値の判定で実装しているが、
	*			 今後イベントの種類が増えることを見越した実装にする
	*/
	if (Event.StageObject == nullptr)
	{
		EffectToSpawn = EnemyEffect;
	}
	else
	{
		EffectToSpawn = StageEffect;
	}


	if (!EffectToSpawn) return;

	UNiagaraFunctionLibrary::SpawnSystemAtLocation(
		World.Get(),
		EffectToSpawn,
		Event.GetLocation()
	);
}