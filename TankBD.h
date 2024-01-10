#pragma once
#include "Engine/GameObject.h"

//�e�X�g�V�[�����Ǘ�����N���X
class TankBD : public GameObject
{
private:
	int hModel_;
	XMVECTOR front_;
	double speed_;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	TankBD(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};
