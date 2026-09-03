#pragma once

#include "CoreMinimal.h"
#include "GameObjectBase.h"

#include "BulletObject.generated.h"

/**
 * 
 */
UCLASS()
class PROTECT_API UBulletObject:public UGameObjectBase
{
	GENERATED_BODY()

public:
	UBulletObject();
	~UBulletObject();

	/**
	*	使用中かどうかのフラグ
	*/
	bool bIsActive = false;

	/**
	*	1発あたりの移動量(方向*速度)
	*/
	FVector Velocity = FVector::ZeroVector;

	/**
	*	残り生存時間タイマー
	*/
	float LifeTimer = 0.f;

	/**
	*	弾の寿命(秒)
	*/
	static constexpr float BulletLifeTime = 3.0f;


	/**
	*	発散時の初期化
	*		ObjectPool::alloc()に呼ばれる
	* 
	*	@param StartPos		発射位置
	*	@param Dir			発射方向
	*/
	void FireInit(const FVector& StartPos, const FVector& Dir);

	virtual void Update(float DeltaTime) override;
};
