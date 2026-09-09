#include "Result/ResultWidget.h"

#include "ProtectGameInstance.h"


void UResultWidget::NativeConstruct()
{
	Super::NativeConstruct();

	/** GameInstanceのFinalScoreをTexrBlockのTextに代入 */
	if (UProtectGameInstance* GI = Cast<UProtectGameInstance>(GetGameInstance()))
	{
		if (ScoreText)
		{
			ScoreText->SetText(FText::AsNumber(GI->FinalScore));
		}
	}
}