#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Migration/GameObjectBase.h"
#include "Migration/PlayerObject.h"
#include "Migration/ShipVisual.h"

#include "Migration/BulletManager.h"
#include "Migration/StageManager.h"
#include "EnemyManager.h"

#include "Migration/EventBus.h"
#include "Migration/SoundSystem.h"
#include "Migration/EffectSystem.h"
#include "Migration/ScoreSystem.h"
#include "Migration/TimeWidget.h"

#include "GameManager.generated.h"

class UScoreWidget;


/**
*	ゲームマネージャークラス
*		ゲームプレイレベルで用いるクラスの全体管理を行う
*		プレイレベルでBeginPlayとTick処理を行うのはこのクラスのみ
*/
UCLASS()
class PROTECT_API AGameManager : public AActor
{
	GENERATED_BODY()

public:
	/** コンストラクタ */
	AGameManager();

	/** ゲッター群 */

	UPlayerObject* GetPlayerObject() const { return Player; }
	AShipVisual* GetPlayerVisual() const { return PlayerVisual; }
	UBulletManager* GetBulletManager() const { return BulletManager; }
	UScoreSystem* GetScoreSytem() const { return ScoreSystem; };
	float GetElapsedTime() { return ElapsedTime; };

protected:
	/**
	*	初期化処理
	*/
	virtual void BeginPlay() override;

	/**
	*	更新処理
	*/
	virtual void Tick(float DeltaTime) override;

	/**
	*	
	*/
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent);

private:
	/** ゲームフロー関連 */
	UPROPERTY(EditDefaultsOnly, Category = "GameFlow")
	float PlayTimeLimit = 30.f;

	float ElapsedTime = 0.f;
	
	UPROPERTY(EditDefaultsOnly, Category = "GameFlow")
	FName ResultLevelName = "Lvl_Result";
	
	/** Player関連 */

	UPROPERTY()
	UPlayerObject* Player;

	UPROPERTY()
	AShipVisual* PlayerVisual;

	UPROPERTY(EditAnywhere, Category = "Spawn")
	TSubclassOf<AShipVisual> PlayerVisualClass;

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<UPlayerStaminaWidget> StaminaWidgetClass;

	UPROPERTY(EditDefaultsOnly,Category="UI")
	TSubclassOf<UPlayerHPWidget> HPWidgetClass;

	/** Bullet関連 */

	UPROPERTY()
	UBulletManager* BulletManager;

	UPROPERTY(EditDefaultsOnly, Category = "Spawn")
	TSubclassOf<ABulletVisual> BulletVisualClass;

	/** Stage関連 */

	UPROPERTY()
	UStageManager* StageManager;

	UPROPERTY(EditDefaultsOnly, Category = "Spawn")
	TSubclassOf<ARockVisual> RockVisualClass;

	/** 敵関連 */
	UPROPERTY()
	UEnemyManager* EnemyManager;

	UPROPERTY(EditDefaultsOnly, Category = "Enemy")
	TArray<FEnemyPhase> EnemyPhases;

	/** イベント関連 */

	UPROPERTY()
	UEventBus* EventBus;

	UPROPERTY()
	USoundSystem* SoundSystem;	// サウンドシステム

	UPROPERTY(EditDefaultsOnly, Category = "Sound")
	USoundBase* CollisionSound_Player;

	UPROPERTY(EditDefaultsOnly, Category = "Sound")
	USoundBase* CollisionSound_Enemy;

	UPROPERTY()
	UEffectSystem* EffectSystem;	// エフェクトシステム

	UPROPERTY(EditDefaultsOnly, Category = "Effect")
	UNiagaraSystem* CollisionEffect_Player;

	UPROPERTY(EditDefaultsOnly, Category = "Effect")
	UNiagaraSystem* CollisionEffect_Enemy;

	UPROPERTY()
	UScoreSystem* ScoreSystem;	// スコアシステム

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<UScoreWidget> ScoreWidgetClass;

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	UTimeWidget* TimeWidget;	// 残り時間表示処理

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<UTimeWidget> TimeWidgetClass;

};