#include "PlayScene.h"
#include "Player.h"
#include "Map.h"
#include "Engine/Camera.h"
#include "Engine/Input.h"

//�R���X�g���N�^
PlayScene::PlayScene(GameObject* parent)
	: GameObject(parent, "PlayScene")
{
}

//������
void PlayScene::Initialize()
{
	Instantiate<Player>(this);
	Instantiate<Map>(this);

	
}

//�X�V
void PlayScene::Update()
{
	if (Input::IsKey(DIK_Q))
	{
		Camera::SetPosition(XMFLOAT3(13, 45, 10));
		Camera::SetTarget(XMFLOAT3(13, 0, 11));
	}

	
}

//�`��
void PlayScene::Draw()
{
}

//�J��
void PlayScene::Release()
{
}
