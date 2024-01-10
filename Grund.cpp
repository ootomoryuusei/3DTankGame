#include "Grund.h"
#include"Engine/Model.h"


//コンストラクタ
Grund::Grund(GameObject* parent)
	: GameObject(parent, "Grund"), hModel_(-1)
{
}

//初期化
void Grund::Initialize()
{
	hModel_ = Model::Load("Model\\ground.fbx");
	assert(hModel_ >= 0);
	transform_.position_ = { 0,0,0 };
}

//更新
void Grund::Update()
{
}

//描画
void Grund::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//開放
void Grund::Release()
{
}