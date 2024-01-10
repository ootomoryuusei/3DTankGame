#include "TankHD.h"
#include"Engine/Model.h"
#include"Engine/Input.h"

TankHD::TankHD(GameObject* parent)
	: GameObject(parent, "TankHD"), hModel_(-1), speed_(0.05), front_({ 0,0,1,0 })
{
}

void TankHD::Initialize()
{
	hModel_ = Model::Load("Model\\tankhead.fbx");
	assert(hModel_ >= 0);
}

void TankHD::Update()
{
	if (Input::IsKey(DIK_LEFT))
	{
		transform_.rotate_.y -= 2.0f;
	}
	if (Input::IsKey(DIK_RIGHT))
	{
		transform_.rotate_.y += 2.0f;
	}
}

void TankHD::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void TankHD::Release()
{
}
