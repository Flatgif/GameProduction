#include "PlayScene.h"
#include "Player.h"
#include "Map.h"
#include "Engine/Camera.h"

//コンストラクタ
PlayScene::PlayScene(GameObject* parent)
	: GameObject(parent, "PlayScene")
{
}

//初期化
void PlayScene::Initialize()
{
	//Instantiate<Player>(this);
	Instantiate<Map>(this);
	Camera::SetPosition(XMFLOAT3(13, 45, 10));
	Camera::SetTarget(XMFLOAT3(13, 0, 11));
}

//更新
void PlayScene::Update()
{
}

//描画
void PlayScene::Draw()
{
}

//開放
void PlayScene::Release()
{
}
