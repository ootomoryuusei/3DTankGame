#include "TankHD.h"
#include"Bullet.h"
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
	if (Input::IsKeyDown(DIK_SPACE))
	{
		XMFLOAT3 cannonTopPos = Model::GetBonePosition(hModel_, "CannonPos");
		XMFLOAT3 cannonRootPos = Model::GetBonePosition(hModel_, "CannonRoot");
		XMVECTOR vtop = XMLoadFloat3(&cannonTopPos);
		XMVECTOR vroot = XMLoadFloat3(&cannonRootPos);
		XMVECTOR moveDir = vtop - vroot;
		moveDir = XMVector3Normalize(moveDir);
		XMFLOAT3 vmove;
		XMStoreFloat3(&vmove, moveDir);

		Bullet* pBullet = Instantiate<Bullet>(this->GetParent()->GetParent());
		pBullet->SetPosition(cannonTopPos);
		pBullet->SetMoveDir(vmove);
		pBullet->SetBulletSpeed(0.1);
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

