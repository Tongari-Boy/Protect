#include "EnemyManager.h"

void UEnemyManager::Init(UWorld* InWorld, const TArray<FEnemyPhase>& InPhases)
{
	World = InWorld;
	Phases = InPhases;
}

void UEnemyManager::Update(float DeltaTime, const FVector& PlayerPos)
{
	for (FEnemyPhase& Phase : Phases)
	{
		if (!Phase.bTriggered && PlayerPos.X >= Phase.TriggerX)
		{
			Phase.bTriggered = true;
			TriggerPhase(Phase);
		}
	}

	for (int32 i = ActiveObjects.Num() - 1; i >= 0; --i)
	{
		ActiveObjects[i]->Update(DeltaTime, PlayerPos);

		if (!ActiveObjects[i]->bIsActive)
		{
			ActiveVisuals[i]->Destroy();
			ActiveObjects.RemoveAt(i);
			ActiveVisuals.RemoveAt(i);

			continue;
		}

		ActiveVisuals[i]->ApplyTransform(ActiveObjects[i]->Transform);
	}
}

void UEnemyManager::TriggerPhase(FEnemyPhase& Phase)
{
	if (!World.IsValid())return;

	for (const FEnemySpawnInfo& Info : Phase.Enemies)
	{
		UEnemyObject* Enemy = NewObject<UEnemyObject>(this, Info.EnemyClass);
		Enemy->Init(Info.SpawnPosition, Info.Radius, Info.Hp);
		ActiveObjects.Add(Enemy);

		AEnemyVisual* Visual = World->SpawnActor<AEnemyVisual>(Info.VisualClass);
		Visual->ApplyTransform(Enemy->Transform);
		Visual->SetVisualActive(true);
		ActiveVisuals.Add(Visual);
	}
}