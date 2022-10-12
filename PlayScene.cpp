#include "PlayScene.h"
#include "Engine/Camera.h"
#include "Player.h"

//�R���X�g���N�^
PlayScene::PlayScene(GameObject* parent)
	: GameObject(parent, "PlayScene")
{
}

//������
void PlayScene::Initialize()
{
	Instantiate<Player>(this);
	Camera::SetPosition(XMFLOAT3(1, 3, -8));
	Camera::SetTarget(XMFLOAT3(0, 2, 0));
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
