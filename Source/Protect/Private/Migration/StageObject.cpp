#include "Migration/StageObject.h"


/**
*	初期化処理
*		UStageManager::Initで呼ばれる
* 
*		@param Pos 位置
*		@param InRadius 半径
*/
void UStageObject::Init(const FVector& Pos, float InRadius)
{
	bIsActive = true;
	bIsHit = false;
	Radius = InRadius;
	Transform.SetLocation(Pos);
}