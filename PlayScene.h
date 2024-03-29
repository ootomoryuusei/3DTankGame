#pragma once
#include "Engine/GameObject.h"
#include"Engine/Text.h"


//■■シーンを管理するクラス
class PlayScene : public GameObject
{
private:
	int enemyNum_;
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
    PlayScene(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

	//インライン定義
	void DescEnemy() { enemyNum_--; }
	bool IsEnemyLeft() {return enemyNum_ > 0;}
	int GetEnemyNum() { return enemyNum_; }
};


