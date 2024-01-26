#include "PlayScene.h"
#include"Grund.h"
#include"TankBD.h"
#include"TankHD.h"
#include"Enemy.h"
#include"HUD.h"
#include"Engine/Model.h"
#include"Engine/Camera.h"
#include"Engine/Image.h""

const int ENEMY_NUM{30};

//�R���X�g���N�^
PlayScene::PlayScene(GameObject* parent)
	: GameObject(parent, "PlayScene")
{
	
}

//������
void PlayScene::Initialize()
{
	Instantiate<Grund>(this);
	Instantiate<TankBD>(this);
	enemyNum_ = ENEMY_NUM;
	for (int i = 0; i < 3; i++)
	{
		Enemy* enemy = Instantiate<Enemy>(this);
	}
	Camera::SetPosition({ 0,7,-13 });
	Camera::SetTarget({ 0,3,0 });
	Instantiate<HUD>(this);
}

//�X�V
void PlayScene::Update()
{
}

//�`��
void PlayScene::Draw()
{
}

//�J��
void PlayScene::Release()
{
}