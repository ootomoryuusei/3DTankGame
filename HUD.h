#pragma once
#include<string>
#include "Engine/GameObject.h"
#include"Engine/Text.h"

using std::string;

//■■シーンを管理するクラス
class HUD : public GameObject
{
private:
	Text* pText_;
	int hHud_;
	/*std::vector<Transform> hudnumber_;*/
	Transform hudnumber_[3];
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	HUD(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};


