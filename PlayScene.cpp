#include "PlayScene.h"
#include "Engine/Camera.h"
#include "Player.h"

//コンストラクタ
PlayScene::PlayScene(GameObject* parent)
	: GameObject(parent, "PlayScene")
{
}

//初期化
void PlayScene::Initialize()
{
	Instantiate<Player>(this);
	Camera::SetPosition(XMFLOAT3(1, 3, -8));
	Camera::SetTarget(XMFLOAT3(0, 2, 0));
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
