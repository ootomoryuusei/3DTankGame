#pragma once
#include "Engine/GameObject.h"

//�e�X�g�V�[�����Ǘ�����N���X
class Bullet : public GameObject
{
private:
	int hModel_;
	XMFLOAT3 moveDir_;
	float bulletSpeed_;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	Bullet(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	void SetMoveDir(XMFLOAT3 _move) { moveDir_ = _move; }
	void SetBulletSpeed(float _speed) { bulletSpeed_ = _speed; }
};