#include "PlayScene.h"
#include"Grund.h"
#include"TankBD.h"
#include"TankHD.h"
#include"Engine/Model.h"
#include"Engine/Camera.h"


//コンストラクタ
PlayScene::PlayScene(GameObject* parent)
	: GameObject(parent, "PlayScene")
{
}

//初期化
void PlayScene::Initialize()
{
	Instantiate<Grund>(this);
	Instantiate<TankBD>(this);
	Camera::SetPosition({ 0,7,-13 });
	Camera::SetTarget({ 0,3,0 });
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