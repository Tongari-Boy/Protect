#include "PlayerObject.h"


UPlayerObject::UPlayerObject()
{
}

UPlayerObject::~UPlayerObject()
{
}

/**
* 初期化処理
*/
void UPlayerObject::Init()
{
	/** 
	*	モデルの回転とスケールの設定
	*		[feature]ステージごとに、モデルの向きや大きさが違うので、ここで設定する形に変更
	*/
	ModelTransform.SetRotation(FRotator(0.f, -90.f, 0.f).Quaternion());
	ModelTransform.SetScale3D(FVector(0.005f));
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
	Pos.Z += InputH * MoveSpeed * DeltaTime;

	/**
	*	移動範囲の設定
	*		[feature]ステージ/場面ごとに、移動範囲は異なるため、随時範囲を受け取る形に変更
	*/
	if (InputV != 0.f && Pos.Y < 100.f && Pos.Y > -100.f)
		Pos.Y -= InputV * MoveSpeed * DeltaTime;

	
	/**
	* 移動に伴う、回転処理
	*	右入力->右に傾く
	*	左入力->左に傾く
	*	入力がない場合->元の角度に戻る
	*/
	FRotator Rot = Transform.Rotator();
	const float BankSpeed = 120.0f;
	const float MaxBank = 20.0f;

	if (InputH < 0.f)	// 左の入力
	{
		Pos.X += InputH * MoveSpeed * DeltaTime;
		Rot.Roll = FMath::Clamp(Rot.Roll + BankSpeed * DeltaTime, -MaxBank, MaxBank);
	}
	else if (InputH > 0.f)	// 右の入力
	{
		Pos.X += InputH * MoveSpeed * DeltaTime;
		Rot.Roll = FMath::Clamp(Rot.Roll - BankSpeed * DeltaTime, -MaxBank, MaxBank);
	}
	else // 入力なし
	{
		Rot.Roll += FMath::Pow(0.01f, DeltaTime);
		if (FMath::Abs(Rot.Roll) < 0.1f) Rot.Roll = 0.f;
	}

	Transform.SetLocation(Pos);
	Transform.SetRotation(Rot.Quaternion());

}