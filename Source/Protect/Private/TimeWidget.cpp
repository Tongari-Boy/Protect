#include "TimeWidget.h"

#include "GameManager.h"
#include <Kismet\GameplayStatics.h>


void UTimeWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void UTimeWidget::ApplyTime(float ElapsedTime)
{
	if (!TimeText) return;

	int32 TotalSeconds = FMath::FloorToInt(ElapsedTime);
	int32 Minutes = TotalSeconds / 60;
	int32 Seconds = TotalSeconds % 60;

	FString TimeString = FString::Printf(TEXT("%02d:%02d"), Minutes, Seconds);
	TimeText->SetText(FText::FromString(TimeString));
}