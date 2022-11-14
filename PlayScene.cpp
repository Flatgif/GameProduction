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
	Instantiate<Map>(this);
	Instantiate<Player>(this);
	
}

//更新
void PlayScene::Update()
{
	/*pos_ = new RootObject;
	XMFLOAT3 playerPosition = ((Player*)pos_->FindObject("Player"))->GetPosition();
	if (Input::IsKey(DIK_Q))
	{
		Camera::SetPosition(XMFLOAT3(playerPosition.x, 30, playerPosition.z));
		Camera::SetTarget(XMFLOAT3(playerPosition));
	}*/
	Camera::SetPosition(XMFLOAT3(11, 30, 10));
	Camera::SetTarget(XMFLOAT3(11,0,11));
	
}

//描画
void PlayScene::Draw()
{
}

//開放
void PlayScene::Release()
{
}
