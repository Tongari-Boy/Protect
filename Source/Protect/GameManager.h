#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "GameObjectBase.h"
#include "PlayerObject.h"
#include "ShipVisual.h"

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

	UPlayerObject* GetPlayerObject() const { return Player; }

	AShipVisual* GetPlayerVisual() const { return PlayerVisual; }

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent);

private:
	UPROPERTY()
	UPlayerObject* Player;

	UPROPERTY()
	AShipVisual* PlayerVisual;

	UPROPERTY(EditAnywhere, Category = "Spawn")
	TSubclassOf<AShipVisual>PlayerVisualClass;
};