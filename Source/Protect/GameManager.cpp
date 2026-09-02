#include "GameManager.h"

// コンストラクタ
AGameManager::AGameManager()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AGameManager::BeginPlay()
{
	Super::BeginPlay();

	/**
	*	Playerの初期化
	*/
	Player = NewObject<UPlayerObject>(this);
	Player->Init();
	GameObjects.Add(Player);
}

void AGameManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	for (UGameObjectBase* Obj : GameObjects)
	{
		Obj->Update(DeltaTime);
	}

	for (UGameObjectBase* Obj : GameObjects)
	{
		if (Obj->MeshComp)
		{
			Obj->MeshComp->SetRelativeTransform(Obj->Transform);
		}
	}
}

void AGameManager::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{

}