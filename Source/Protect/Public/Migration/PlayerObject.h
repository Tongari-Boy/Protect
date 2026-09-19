#pragma once

#include "CoreMinimal.h"
#include "GameObjectBase.h"
#include "PlayerStaminaWidget.h"

#include "PlayerObject.generated.h"


/**
 * プレイヤの論理クラス
 *		入力の受け取り、入力に応じた処理を行い、見た目に反映させる
 *		また、体力、スタミナもここで管理する
 */
UCLASS()
class PROTECT_API UPlayerObject : public UGameObjectBase
{
	GENERATED_BODY()

public:
	virtual void Init() override;
	virtual void Update(float DeltaTime) override;

	/** 入力はGameManagerから受け取る */
	void SetInputAxis(float Horizontal, float Vertical);
	void SetInputSprint(float Sprint);

	void SetStaminaWidget(UPlayerStaminaWidget* Widget) { PlayerStaminaWidget = Widget; };

	void SubtractHp(int32 Amount);
	int32 GetCurrentHp() const { return CurrentHp; }
	int32 GetMaxHp() const { return MaxHp; }
	bool IsInvincible() const { return InvincibleTimer > 0.f; }
	float Radius = 200.0f;	/** プレイヤの当たり判定に用いる半径 */

private:
	float MoveSpeed = 200.0f;
	float InputH = 0.f;
	float InputV = 0.f;
	float InputSprint = 0.0f;

	const float MAXSPRINTSTAMINA = 100.f;
	float SprintStamina = 100.f;
	bool bIsSprint = true;
	UPlayerStaminaWidget* PlayerStaminaWidget;

	int32 MaxHp = 2;
	int32 CurrentHp = 2;
	float InvincibleTimer = 0.f;
	const float InvincibleDuration = 1.0f;	/** 無敵時間 */
};