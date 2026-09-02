#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Camera/CameraComponent.h"

#include "ShipVisual.generated.h"

/**
*	見た目用クラス
*/
UCLASS()
class PROTECT_API AShipVisual : public AActor
{
	GENERATED_BODY()
	
public:	
	// コンストラクタ
	AShipVisual();

	void ApplyTransform(const FTransform& WorldTransform, const FTransform& ModelOffset);

private:
	UPROPERTY()
	USceneComponent* RootScene;	// スケールされない土台

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* MeshComp;	// モデルオフセットの影響を受ける

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CameraComp;	// RootScneの子とすることで、メッシュのスケールに影響されない
};
