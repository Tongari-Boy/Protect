#include "PlayerStaminaWidget.h"

#include "Materials/MaterialInstanceDynamic.h"


// Imageコンポーネントから動的マテリアルを作成/取得
void UPlayerStaminaWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (StaminaImage)
	{
		DynamicMaterial = StaminaImage->GetDynamicMaterial();
	}
}

// スタミナの割合を画像に適用する関数
void UPlayerStaminaWidget::SetStaminaPercent(float InPercent)
{
	if (DynamicMaterial)
	{
		float ClampedPercent = FMath::Clamp(InPercent, 0.0f, 1.0f);

		// マテリアルのパラメータ名 "Percent" にスタミナの割合を設定
		DynamicMaterial->SetScalarParameterValue(TEXT("Percent"), ClampedPercent);
	}
}
