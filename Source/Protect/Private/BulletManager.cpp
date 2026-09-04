#include "BulletManager.h"


UBulletManager::UBulletManager()
{
}

UBulletManager::~UBulletManager()
{
}

void UBulletManager::Init(UWorld* World, TSubclassOf<ABulletVisual> VisualClass)
{
	BulletPool.Reserve(MaxBullets);
	VisualPool.Reserve(MaxBullets);

	for (int32 i = 0; i < MaxBullets; ++i)
	{
		BulletPool.Add(NewObject<UBulletObject>(this));
		VisualPool.Add(World->SpawnActor<ABulletVisual>(VisualClass));
	}
}

void UBulletManager::Fire(const FVector& Pos, const FVector& Dir)
{
	/** 空きスロットを線形探索 */
	for (int32 i = 0; i < MaxBullets; ++i)
	{
		if (!BulletPool[i]->bIsActive)
		{
			BulletPool[i]->FireInit(Pos, Dir);
			VisualPool[i]->SetVisualActive(true);

			return;
		}
	}
	
	/**
	*	空きがなければ何もしない
	*		[feature]プールの最大値に達したら、最初に撃った弾から消すようにしたい/論理弾の実装も検討
	*/
	
}


void UBulletManager::Update(float DeltaTime)
{
	for (int32 i = 0; i < MaxBullets; ++i)
	{
		if (!BulletPool[i]->bIsActive) continue;

		BulletPool[i]->Update(DeltaTime);
		VisualPool[i]->ApplyTransform(BulletPool[i]->Transform);

		/** このフレームで寿命がきたら、非アクティブ化 */
		if (!BulletPool[i]->bIsActive)
		{
			VisualPool[i]->SetVisualActive(false);
		}
	}
}