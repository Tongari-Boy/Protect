#include "PlayerHPWidget.h"

#include "Migration\/PlayerObject.h"


void UPlayerHPWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void UPlayerHPWidget::SetHPPercentToBar(float InPercent)
{
	float clampedPercent = FMath::Clamp(InPercent, 0.0f, 1.0f);
	
	// UIに反映させる
	HPBar->SetPercent(clampedPercent);
}
