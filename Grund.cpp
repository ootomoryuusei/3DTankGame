#include "Grund.h"
#include"Engine/Model.h"


//�R���X�g���N�^
Grund::Grund(GameObject* parent)
	: GameObject(parent, "Grund"), hModel_(-1)
{
}

//������
void Grund::Initialize()
{
	hModel_ = Model::Load("Model\\ground.fbx");
	assert(hModel_ >= 0);
	transform_.position_ = { 0,0,0 };
}

//�X�V
void Grund::Update()
{
}

//�`��
void Grund::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//�J��
void Grund::Release()
{
}