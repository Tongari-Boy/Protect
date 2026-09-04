#include "BulletObject.h"


UBulletObject::UBulletObject()
{
}

UBulletObject::~UBulletObject()
{
}

void UBulletObject::FireInit(const FVector& StartPos, const FVector& Dir)
{
	bIsActive = true;
	Transform.SetLocation(StartPos);
	Velocity = Dir * 1000.f; /** 速度を設定 */
	LifeTimer = BulletLifeTime; /** 寿命をリセット */
}

void UBulletObject::Update(float DeltaTime)
{
	if (!bIsActive) return;

	FVector Pos = Transform.GetLocation();
	Pos += Velocity * DeltaTime;
	Transform.SetLocation(Pos);

	LifeTimer -= DeltaTime;
	if (LifeTimer <= 0.f)
	{
		bIsActive = false;	/** 実際のプール返却は、BulletManager::Updateで行うが、ここでも明示的に無効化する */
		UE_LOG(LogTemp, Warning, TEXT("Bullet IsActive is false because of LifeTime"));
	}
}