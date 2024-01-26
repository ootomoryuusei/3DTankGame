#include "Bullet.h"
#include"Engine/Model.h"
#include"Engine/SphereCollider.h"

Bullet::Bullet(GameObject* parent)
	: GameObject(parent, "Bullet"),hModel_(-1),bulletSpeed_(0.1)
{
}

void Bullet::Initialize()
{
	hModel_ = Model::Load("Model\\Bullet.fbx");
	assert(hModel_ >= 0);
	SphereCollider* collision = new SphereCollider({ 0,0,0 }, 0.5f);
	AddCollider(collision);
}

void Bullet::Update()
{
	transform_.position_.x = transform_.position_.x + moveDir_.x * bulletSpeed_;
	transform_.position_.y = transform_.position_.y + moveDir_.y * bulletSpeed_;
	transform_.position_.z = transform_.position_.z + moveDir_.z * bulletSpeed_;
	moveDir_ = { moveDir_.x,moveDir_.y-0.0008f,moveDir_.z };
	if (transform_.position_.y < -5.0f)
	{
		KillMe();
	}
}

void Bullet::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Bullet::Release()
{
}
