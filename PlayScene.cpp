#include "PlayScene.h"
#include"Grund.h"
#include"TankBD.h"
#include"TankHD.h"
#include"Enemy.h"
#include"HUD.h"
#include"Engine/Model.h"
#include"Engine/Camera.h"
#include"Engine/Image.h"
#include"Engine/SceneManager.h"

const int ENEMY_NUM{15};

//コンストラクタ
PlayScene::PlayScene(GameObject* parent)
	: GameObject(parent, "PlayScene")
{
	
}

//初期化
void PlayScene::Initialize()
{
	Instantiate<Grund>(this);
	enemyNum_ = ENEMY_NUM;
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		Enemy* enemy = Instantiate<Enemy>(this);
	}
	Instantiate<TankBD>(this);
	Camera::SetPosition({ 0,7,-13 });
	Camera::SetTarget({ 0,3,0 });
	Instantiate<HUD>(this);
}

//更新
void PlayScene::Update()
{
}

//描画
void PlayScene::Draw()
{
}

//開放
void PlayScene::Release()
{
}