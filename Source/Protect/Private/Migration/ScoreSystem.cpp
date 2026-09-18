#include "Migration/ScoreSystem.h"


void UScoreSystem::HandleCollision(const FCustomCollisionEvent& Event)
{
	if (Event.EnemyObject)
	{
		if (Event.bEnemyKilled)
		{
			AddScore(100);
		}
	}
	else if (Event.StageObject)
	{
		AddScore(100);
	}
}

void UScoreSystem::AddScore(int32 Amount)
{
	Score += Amount;
	OnScoreChanged.Broadcast(Score); /** UIへの反映はここで通知する */
}

void UScoreSystem::Reset()
{
	Score = 0;
	OnScoreChanged.Broadcast(Score);
}