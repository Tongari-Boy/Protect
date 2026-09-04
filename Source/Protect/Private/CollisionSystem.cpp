#include "CollisionSystem.h"

#include "BulletManager.h"
#include "StageManager.h"
#include "CustomCollisionEvent.h"

/**
*	弾とステージオブジェクトの当たり判定
*/
void FCollisionSystem::CheckBulletVsStage(
	UBulletManager& Bullets,
	UStageManager& Stage,
	TArray<FCustomCollisionEvent>& OutEvents)
{
	/** アクティブな弾を探す */
	for (UBulletObject* Bullet : Bullets.GetBulletsPool())
	{
		if (!Bullet->bIsActive) continue;

		/** アクティブなステージオブジェクトを探す */
		for (UStageObject* Obj : Stage.StageObjects)
		{
			if (!Obj->bIsActive || Obj->bIsHit) continue;

			/** 弾とステージオブジェクトの距離計算 */
			float Dist = FVector::Dist(
				Bullet->Transform.GetLocation(),
				Obj->Transform.GetLocation()
			);

			/** 距離がステージオブジェクトの半径以下(衝突した)だったら*/
			if (Dist < Obj->Radius)
			{
				Bullet->bIsActive = false;
				Obj->bIsHit = true;
				Obj->bIsActive = false;

				FCustomCollisionEvent Event;
				Event.Bullet = Bullet;
				Event.StageObject = Obj;
				OutEvents.Add(Event);

				break;
			}


		}
	}
}