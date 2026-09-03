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

	/**
	* ’e‚ÌÅ‘å”
	*/
	static const int32 MaxBullets = 30;

	void Init(UWorld* World, TSubclassOf<ABulletVisual> VisualClass);
	void Fire(const FVector& Pos, const FVector& Dir);
	void Update(float DeltaTime);

private:
	// UE‚ÌGC‚Å‰ñû‚³‚ê‚È‚¢‚æ‚¤AUPROPRETY‚Åƒv[ƒ‹‚ğ•Û‚·‚é
	UPROPERTY()
	TArray<UBulletObject*> BulletPool;

	UPROPERTY()
	TArray<ABulletVisual*> VisualPool;
};