#include "ClearScene.h"
#include"Engine/Image.h"
#include"Engine/Input.h"
#include"Engine/SceneManager.h"

ClearScene::ClearScene(GameObject* parent)
	:GameObject(parent,"ClearScene"),hPict_(-1)
{
}

void ClearScene::Initialize()
{
	hPict_ = Image::Load("Clear.png");
	assert(hPict_ >= 0);
}

void ClearScene::Update()
{
	if (Input::IsMouseButtonUp(0))
	{
		SceneManager* tSM = (SceneManager*)(FindObject("SceneManager"));
		/*SceneManager* pSM = static_cast<SceneManager*>(FindObject("SceneManager"));*/
		tSM->ChangeScene(SCENE_ID_PLAY);
	}
}

void ClearScene::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

void ClearScene::Release()
{
}
