#include "PlayerStaminaWidget.h"
// #include "Components/Image.h"
#include "Materials/MaterialInstanceDynamic.h"


/**
*	Imageコンポーネントから動的マテリアルを作成/取得
*/
void UPlayerStaminaWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (StaminaImage)
	{
		DynamicMaterial = StaminaImage->GetDynamicMaterial();
	}
}

void UPlayerStaminaWidget::SetStaminaPercent(float InPercent)
{
	if (DynamicMaterial)
	{
		float ClampedPercent = FMath::Clamp(InPercent, 0.0f, 1.0f);

		DynamicMaterial->SetScalarParameterValue(TEXT("Percent"), ClampedPercent);
	}
}