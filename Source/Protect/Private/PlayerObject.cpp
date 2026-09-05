#include "PlayerObject.h"


UPlayerObject::UPlayerObject()
{
}

UPlayerObject::~UPlayerObject()
{
}

/** 初期化処理 */
void UPlayerObject::Init()
{
	/** 
	*	モデルの回転とスケールの設定
	*		[feature]ステージごとに、モデルの向きや大きさが違うので、ここで設定する形に変更
	*/
	ModelTransform.SetRotation(FRotator(0.f, 0.f, 0.f).Quaternion());
	ModelTransform.SetScale3D(FVector(0.1f));
}

/**
*	更新処理
*		主に入力に応じた処理を行う
*/
void UPlayerObject::Update(float DeltaTime)
{
	FVector Pos = Transform.GetLocation();

	/**
	*	常に前進
	*		[feature]ゲームモードによって操作方法を変更(スピードアップ/ダウンの実装も検討)
	*/
	Pos.X += MoveSpeed * DeltaTime;

	/**
	*	上下移動を範囲内にクランプ
	*/
	Pos.Z += InputV * MoveSpeed * DeltaTime;
	Pos.Z = FMath::Clamp(Pos.Z, -100.f, 100.f);
	
	/**
	* 移動に伴う、回転処理
	*	右入力->右に傾く
	*	左入力->左に傾く
	*	入力がない場合->元の角度に戻る
	*/
	FRotator Rot = Transform.Rotator();
	const float BankSpeed = 120.0f;
	const float MaxBank = 20.0f;

	if (InputH < 0.f)	/** 左の入力 */
	{
		Pos.Y += InputH * MoveSpeed * DeltaTime;
		Rot.Roll = FMath::Clamp(Rot.Roll - BankSpeed * DeltaTime, -MaxBank, MaxBank);
	}
	else if (InputH > 0.f)	/** 右の入力 */
	{
		Pos.Y += InputH * MoveSpeed * DeltaTime;
		Rot.Roll = FMath::Clamp(Rot.Roll + BankSpeed * DeltaTime, -MaxBank, MaxBank);
	}
	else /** 入力なし */
	{
		Rot.Roll *= FMath::Pow(0.01f, DeltaTime);
		if (FMath::Abs(Rot.Roll) < 0.1f) Rot.Roll = 0.f;
	}

	/**
	*	左右移動を範囲内にクランプ
	*/
	Pos.Y = FMath::Clamp(Pos.Y, -100.f, 100.f);

	Transform.SetLocation(Pos);
	Transform.SetRotation(Rot.Quaternion());
}

void UPlayerObject::SetInputAxis(float Horizontal, float Vertical)
{
	UE_LOG(LogTemp, Warning, TEXT("InputH=%f InputV=%f"), Horizontal, Vertical)
	InputH = Horizontal;
	InputV = Vertical;
}