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
	Instantiate<Map>(this);
	Instantiate<Player>(this);
	
}

//�X�V
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

//�`��
void PlayScene::Draw()
{
}

//�J��
void PlayScene::Release()
{
}
