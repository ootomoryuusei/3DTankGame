#include "HUD.h"
#include"PlayScene.h"

HUD::HUD(GameObject* parent)
	:GameObject(parent,"HUD"), pText_(nullptr),hHud_(-1)
{
}

void HUD::Initialize()
{
	hHud_ = Image::Load("TEXT.png");
	assert(hHud_ >= 0);
	pText_ = new Text;
	pText_->Initialize();
	/*for (int i = 0; i < 3; i++)
	{
		Transform trans;
		trans.position_ = { -0.64f + 0.04f * (float)i,0.93f,0.0f };
		hudnumber_.push_back(trans);
	}*/
}

void HUD::Update()
{
}

void HUD::Draw()
{
	pText_->Draw(30, 30, "RestEnemies:");
	int enemies = ((PlayScene*)GetParent())->GetEnemyNum();
	string restenemies = std::to_string(enemies);
	string str = restenemies;
	string estr = restenemies;
	if (estr.length() < 3)
	{
		estr = string(3 - estr.length(), '0') + estr;
	}
	for (int i = 0; i < 3; i++)
	{
		int n = estr[i] - '0';
		hudnumber_[i].position_ = { -0.64f + 0.04f * (float)i,0.93f,0.0f };
		if (estr[i] - '0' < 5)
		{
			Image::SetRect(hHud_, 25.6 * n, 0, 25.6, 36);
		}
		else
		{
			Image::SetRect(hHud_, 25.6 * n, 36, 25.6, 36);
		}
		Image::SetTransform(hHud_,hudnumber_[i]);
		Image::Draw(hHud_);
	}
}

void HUD::Release()
{
}
