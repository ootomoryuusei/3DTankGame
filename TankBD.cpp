#include "TankBD.h"
#include "TitleScene.h"
#include"Grund.h"
#include"TankHD.h"
#include"Engine/Input.h"
#include"Engine/Model.h"

//コンストラクタ
TankBD::TankBD(GameObject* parent)
	: GameObject(parent, "TankBD"), hModel_(-1),speed_(0.05),front_({0,0,1,0})
{
}

//初期化
void TankBD::Initialize()
{
	Instantiate<TankHD>(this);
	hModel_ = Model::Load("Model\\tankbody.fbx");
	assert(hModel_ >= 0);
}

//更新
void TankBD::Update()
{
	if (Input::IsKey(DIK_A))
	{
		transform_.rotate_.y -= 2.0f;
	}
	if (Input::IsKey(DIK_D))
	{
		transform_.rotate_.y += 2.0f;
	}
	if (Input::IsKey(DIK_W))
	{
		XMMATRIX rotY = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));
		XMVECTOR rotVec = XMVector3TransformCoord(front_, rotY);

		XMVECTOR move;
		move = speed_ * rotVec;
		XMVECTOR pos = XMLoadFloat3(&(transform_.position_));
		pos = pos + move;
		XMStoreFloat3(&(transform_.position_), pos);
		/*transform_.position_.z += 0.05;*/
	}
	if(Input::IsKey(DIK_S))
	{
		XMMATRIX rotY = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));
		XMVECTOR rotVec = XMVector3TransformCoord(front_, rotY);

		XMVECTOR move;
		move = speed_ * rotVec;
		XMVECTOR pos = XMLoadFloat3(&(transform_.position_));
		pos = pos - move;
		XMStoreFloat3(&(transform_.position_), pos);
		/*transform_.position_.z  -= 0.05;*/
	}
	Grund* pGrund = (Grund*)FindObject("Grund");
	int hGmodel = pGrund->GetModelHandle();
	RayCastData data;
	data.start = transform_.position_;
	data.start.y = 0;
	data.dir = XMFLOAT3({ 0,-1,0 });
	Model::RayCast(hGmodel, &data);

	if (data.hit == true)
	{
		transform_.position_.y = -data.dist;
	}
}

//描画
void TankBD::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);

}

//開放
void TankBD::Release()
{
}