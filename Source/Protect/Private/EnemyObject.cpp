#include "EnemyObject.h"


void UEnemyObject::Init(const FVector& Pos, float InRadius, int32 Hp)
{
	bIsActive = true;
	bIsHit = false;
	Radius = InRadius;
	Transform.SetLocation(Pos);

	MaxHp = Hp;
	CurrentHp = Hp;
}

/**
*	敵のAI処理
*		継承先でそれぞれ作成する
*/
void UEnemyObject::Update(float DeltaTime,const FVector& PlayerPos,const FVector& PlayerCameraPos)
{
	if (!bIsActive) return;

	// HPが0以下になったら非アクティブにする
	if (CurrentHp <= 0)
	{
		bIsActive = false;
		return;
	}
}

void UEnemyObject::AddHp(int32 Amount)
{
	CurrentHp = FMath::Min(CurrentHp + Amount, MaxHp);
}

void UEnemyObject::SubtractHp(int Amount)
{
	CurrentHp = FMath::Max(CurrentHp - Amount, 0);	
	UE_LOG(LogTemp, Log, TEXT("Enemy's CurrentHp is  %d"), CurrentHp);
}
