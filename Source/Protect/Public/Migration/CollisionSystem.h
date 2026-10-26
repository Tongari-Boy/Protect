#pragma once

#include "CoreMinimal.h"

class UBulletManager;
class UStageManager;
class UEnemyManager;
class UPlayerObject;
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

	static void CheckPlayerVsEnemy(
		UPlayerObject& Player,
		UEnemyManager& Enemy,
		TArray<FCustomCollisionEvent>& OutEvents
	);
};
