#pragma once
#include "Engine/GameObject.h"

//テストシーンを管理するクラス
class Bullet : public GameObject
{
private:
	int hModel_;
	XMFLOAT3 moveDir_;
	float bulletSpeed_;
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Bullet(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

	void SetMoveDir(XMFLOAT3 _move) { moveDir_ = _move; }
	void SetBulletSpeed(float _speed) { bulletSpeed_ = _speed; }
};