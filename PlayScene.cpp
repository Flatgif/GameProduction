#include "PlayScene.h"
#include "Player.h"
#include "Map.h"
#include "Engine/Camera.h"

//�R���X�g���N�^
PlayScene::PlayScene(GameObject* parent)
	: GameObject(parent, "PlayScene")
{
}

//������
void PlayScene::Initialize()
{
	//Instantiate<Player>(this);
	Instantiate<Map>(this);
	Camera::SetPosition(XMFLOAT3(13, 45, 10));
	Camera::SetTarget(XMFLOAT3(13, 0, 11));
}

//�X�V
void PlayScene::Update()
{
}

//�`��
void PlayScene::Draw()
{
}

//�J��
void PlayScene::Release()
{
}
