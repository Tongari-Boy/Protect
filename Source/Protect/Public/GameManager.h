#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "GameObjectBase.h"
#include "PlayerObject.h"
#include "ShipVisual.h"

#include "BulletManager.h"

#include "GameManager.generated.h"

/**
*	ゲームマネージャークラス
*/
UCLASS()
class PROTECT_API AGameManager : public AActor
{
	GENERATED_BODY()

public:
	/** コンストラクタ */
	AGameManager();

	/** ゲッター */

	UPlayerObject* GetPlayerObject() const { return Player; }

	AShipVisual* GetPlayerVisual() const { return PlayerVisual; }

	UBulletManager* GetBulletManager() const { return BulletManager; }

protected:
	/**
	*	初期化処理
	*		BeginPlayはここにしか存在しない
	*/
	virtual void BeginPlay() override;

	/**
	*	更新処理
	*		Tickはここにしか存在しない
	*/
	virtual void Tick(float DeltaTime) override;

	/**
	*	
	*/
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent);

private:
	/** Player関連 */

	UPROPERTY()
	UPlayerObject* Player;

	UPROPERTY()
	AShipVisual* PlayerVisual;

	UPROPERTY(EditAnywhere, Category = "Spawn")
	TSubclassOf<AShipVisual> PlayerVisualClass;


	/** Bullet関連 */

	UPROPERTY()
	UBulletManager* BulletManager;

	UPROPERTY(EditDefaultsOnly, Category = "Spawn")
	TSubclassOf<ABulletVisual> BulletVisualClass;
};