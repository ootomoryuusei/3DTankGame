#include "Enemy.h"
#include"Grund.h"
#include"PlayScene.h"
#include"Engine/Model.h"
#include"Engine/Collider.h"

Enemy::Enemy(GameObject* parent)
	:GameObject(parent, "Enemy"), hModel_(-1)
{
}

void Enemy::Initialize()
{
	hModel_ = Model::Load("Model\\kinokomove.fbx");
	assert(hModel_ >= 0);
	Model::SetAnimFrame(hModel_, 1, 60, 1);
	/*transform_.position_ = { (float)(rand() % 41 - 15),0, (float)(rand() % 40)};*/
	SphereCollider* collision = new SphereCollider({ 0,0,0 }, 1.0f);
	AddCollider(collision);
	playScene_ = (PlayScene*)GetParent();
}

void Enemy::Update()
{
	/*transform_.position_.x -= 0.01;*/
	Grund* pGrund = (Grund*)FindObject("Grund");
	int hGmodel = pGrund->GetModelHandle();
	RayCastData data;
	data.start = transform_.position_;
	data.start.y = -1;
	data.dir = XMFLOAT3({ 0,-1,0 });
	Model::RayCast(hGmodel, &data);

	if (data.hit == true)
	{
		transform_.position_.y = -data.dist + 0.5f;
	}

}

void Enemy::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Enemy::Release()
{
}

void Enemy::OnCollision(GameObject* pTarget)
{
	if (pTarget->GetObjectName() == "Bullet")
	{
		playScene_->DescEnemy();
		this->KillMe();
		pTarget->KillMe();
	}
}
