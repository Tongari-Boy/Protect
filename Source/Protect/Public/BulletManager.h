#pragma once

#include "CoreMinimal.h"

#include "BulletVisual.h"
#include "BulletObject.h"

#include "BulletManager.generated.h"

/**
 * 
 */
UCLASS()
class PROTECT_API UBulletManager : public UObject
{
	GENERATED_BODY()

public:
	UBulletManager();
	~UBulletManager();

	/** 弾の最大数 */
	static const int32 MaxBullets = 30;

	void Init(UWorld* World, TSubclassOf<ABulletVisual> VisualClass);
	void Fire(const FVector& Pos, const FVector& Dir);
	void Update(float DeltaTime);
	const TArray<UBulletObject*> GetBulletsPool() const { return BulletPool; };

private:
	/** UEのGCで回収されないよう、UPROPRETYでプールを保持する */

	UPROPERTY()
	TArray<UBulletObject*> BulletPool;

	UPROPERTY()
	TArray<ABulletVisual*> VisualPool;
};