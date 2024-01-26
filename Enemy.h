#pragma once
#include"PlayScene.h"
#include "Engine/GameObject.h"


//テストシーンを管理するクラス
class Enemy : public GameObject
{
private:
	int hModel_;
	XMVECTOR front_;
	double speed_;
	PlayScene* playScene_;
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Enemy(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

	void OnCollision(GameObject* pTarget) override;
};
