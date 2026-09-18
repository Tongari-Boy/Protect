#pragma once

#include "CoreMinimal.h"

class UBulletManager;
class UStageManager;
class UEnemyManager;
struct FCustomCollisionEvent;


/**
 * 
 */
class FCollisionSystem
{
public:
	
	/**
	*	弾とステージオブジェクトの当たり判定
	*/
	static void CheckBulletVsStage(
		UBulletManager& Bullets,
		UStageManager& Stage,
		TArray<FCustomCollisionEvent>& OutEvents
	);

	static void CheckBulletVsEnemy(
		UBulletManager& Bullets,
		UEnemyManager& Enemies,
		TArray<FCustomCollisionEvent>& OutEvents
	);
};
