#pragma once

#include "CoreMinimal.h"
#include "GameObjectBase.h"

#include "PlayerObject.generated.h"

/**
 * 
 */
UCLASS()
class PROTECT_API UPlayerObject : public UGameObjectBase
{
	GENERATED_BODY()

public:
	UPlayerObject();
	~UPlayerObject();

	virtual void Init() override;
	virtual void Update(float DeltaTime) override;

	// “ü—Í‚ÍGameManager‚©‚çŽó‚¯Žæ‚é
	void SetInputAxis(float Horizontal, float Vertical);

private:
	float MoveSpeed = 0.0f;
	float InputH = 0.f;
	float InputV = 0.f;
};