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
*	敵のAI機能
*		継承先でそれぞれ作成する
*/
void UEnemyObject::Update(float DeltaTime,const FVector& PlayerPos)
{
	if (!bIsActive) return;

	if (Transform.GetLocation().X < PlayerPos.X)
	{
		bIsActive = false;
		return;
	}

	if (CurrentHp <= 0)
	{
		bIsActive = false;
		return;
	}
}

void UEnemyObject::AddHp(int32 Amount)
{
	/*
	if (CurrentHp + Amount > MaxHp)
	{
		CurrentHp = MaxHp;
	}
	else
	{
		CurrentHp += Amount;
	}
	*/

	CurrentHp = FMath::Min(CurrentHp + Amount, MaxHp);
}

void UEnemyObject::SubtractHp(int Amount)
{
	/*
	if (CurrentHp - Amount > 0)
	{
		CurrentHp -= Amount;
	}
	else
	{
		CurrentHp = 0;
	}
	*/

	CurrentHp = FMath::Max(CurrentHp - Amount, 0);
}