#include "RockVisual.h"


/** コンストラクタ */
ARockVisual::ARockVisual()
{
	PrimaryActorTick.bCanEverTick = false;
}

/** */
void ARockVisual::ApplyTransform(const FTransform& WorldTransform)
{
	SetActorTransform(WorldTransform);
}

/** */
void ARockVisual::SetVisualActive(bool bActive)
{

}