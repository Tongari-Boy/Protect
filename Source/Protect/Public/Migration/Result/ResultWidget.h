#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include <Components/TextBlock.h>

#include "ResultWidget.generated.h"


/**
*	リザルトレベルのウィジェット
*/
UCLASS()
class PROTECT_API UResultWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	// コンストラクタ
	virtual void NativeConstruct() override;

	// スコア用のテキスト
	UPROPERTY(meta = (BindWidget))
	UTextBlock* ScoreText;
};
