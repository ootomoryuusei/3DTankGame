#pragma once
#include<string>
#include "Engine/GameObject.h"
#include"Engine/Text.h"

using std::string;

//�����V�[�����Ǘ�����N���X
class HUD : public GameObject
{
private:
	Text* pText_;
	int hHud_;
	/*std::vector<Transform> hudnumber_;*/
	Transform hudnumber_[3];
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	HUD(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};


