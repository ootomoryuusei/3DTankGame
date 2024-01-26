#pragma once
#include "Engine/GameObject.h"

//テストシーンを管理するクラス
class TankHD : public GameObject
{
private:
	int hModel_;
	XMVECTOR front_;
	double speed_;
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	TankHD(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

	/// <summary>
	/// モデル番号を返す関数
	/// </summary>
	/// <returns>int hModel_:モデル番号</returns>
	int GetModelHandle() { return hModel_; }

};