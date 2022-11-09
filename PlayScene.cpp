#include "PlayScene.h"
#include "Player.h"
#include "Map.h"
#include "Engine/Camera.h"
#include "Engine/Input.h"

//コンストラクタ
PlayScene::PlayScene(GameObject* parent)
	: GameObject(parent, "PlayScene")
{
}

//初期化
void PlayScene::Initialize()
{
	Instantiate<Player>(this);
	Instantiate<Map>(this);

	
}

//更新
void PlayScene::Update()
{
	if (Input::IsKey(DIK_Q))
	{
		Camera::SetPosition(XMFLOAT3(13, 45, 10));
		Camera::SetTarget(XMFLOAT3(13, 0, 11));
	}

	
}

//描画
void PlayScene::Draw()
{
}

//開放
void PlayScene::Release()
{
}
