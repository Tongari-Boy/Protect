#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "GameObjectBase.h"
#include "PlayerObject.h"

#include "GameManager.generated.h"

/**
*	ゲームマネージャークラス
*/
UCLASS()
class PROTECT_API AGameManager : public AActor
{
	GENERATED_BODY()

public:
	// コンストラクタ
	AGameManager();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent);

private:
	UPROPERTY()
	TArray<UGameObjectBase*> GameObjects;

	UPROPERTY()
	UPlayerObject* Player;
};