#include "TankBD.h"
#include "TitleScene.h"
#include"Grund.h"
#include"TankHD.h"
#include"Engine/Image.h"
#include"Engine/Input.h"
#include"Engine/Model.h"
#include"Engine/Camera.h"
#include"Engine/SceneManager.h"

enum CAM_TYPE
{
	FIXED_TYPE,
	TPS_NOROT_TYPE,
	TPS_TYPE,
	FPS_TYPE,
	MAX_TYPE
};
//コンストラクタ
TankBD::TankBD(GameObject* parent)
	: GameObject(parent, "TankBD"), hModel_(-1), speed_(0.05), front_({ 0,0,1,0 }), camState_(CAM_TYPE::FIXED_TYPE)
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
	XMVECTOR move{0,0,0,0};
	XMMATRIX rotY = XMMatrixIdentity();
	XMVECTOR rotVec{ 0,0,0,0 };
	float dir = 0;

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
		dir = 1.0;
	}
	if(Input::IsKey(DIK_S))
	{
		dir = -1.0;
	}

	rotY = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));
	rotVec = XMVector3TransformCoord(front_, rotY);

	move = speed_ * rotVec;
	XMVECTOR pos = XMLoadFloat3(&(transform_.position_));
	pos = pos + dir *  move;
	XMStoreFloat3(&(transform_.position_), pos);

	Grund* pGrund = (Grund*)FindObject("Grund");
	int hGmodel = pGrund->GetModelHandle();
	RayCastData data;
	data.start = transform_.position_;
	data.start.y = 0;
	data.dir = XMFLOAT3({ 0,-1,0 });
	Model::RayCast(hGmodel, &data);

	if (data.hit == true)
	{
		transform_.position_.y = -data.dist + 0.5f;
	}
	if (Input::IsKeyDown(DIK_Z))
	{
		camState_++;
		if (camState_ == CAM_TYPE::MAX_TYPE)
		{
			camState_ = CAM_TYPE::FIXED_TYPE;
		}
	}
	switch (camState_)
	{
	case CAM_TYPE::FIXED_TYPE:
	{
		Camera::SetPosition(XMFLOAT3(0, 20, -20));
		Camera::SetTarget(XMFLOAT3(0, 0, 0));
		break;
	}
	case CAM_TYPE::TPS_NOROT_TYPE:
	{
		XMFLOAT3 camPos = transform_.position_;
		camPos.y = transform_.position_.y + 20.0f;
		camPos.z = transform_.position_.z - 10.0f;
		Camera::SetPosition(camPos);
		Camera::SetTarget(transform_.position_);
		break;
	}
	case CAM_TYPE::TPS_TYPE:
	{
		Camera::SetTarget(transform_.position_);
		XMVECTOR vEye{ 0,5,-10,0 };
		vEye = XMVector3TransformCoord(vEye, rotY);
		XMFLOAT3 camPos;
		XMStoreFloat3(&camPos, pos + vEye);
		Camera::SetPosition(camPos);
		break;
	}
	case CAM_TYPE::FPS_TYPE:
	{
		Camera::SetPosition(transform_.position_);
		XMFLOAT3 camTarget;
		XMStoreFloat3(&camTarget, pos + move);
		Camera::SetTarget(camTarget);
		break;
	}
	default:
		break;
	}
	if (FindObject("Enemy") == nullptr)
	{
		SceneManager* pSM = (SceneManager*)(FindObject("SceneManager"));
		/*SceneManager* pSM = static_cast<SceneManager*>(FindObject("SceneManager"));*/
		pSM->ChangeScene(SCENE_ID_CLEAR);
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