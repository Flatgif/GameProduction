#include "Player.h"
#include "Engine/Camera.h"

//�R���X�g���N�^
Player::Player(GameObject* parent)
    :GameObject(parent, "Player")
{
}

//�f�X�g���N�^
Player::~Player()
{
}

//������
void Player::Initialize()
{
}

//�X�V
void Player::Update()
{
    Camera::SetPosition(transform_.position_);
}

//�`��
void Player::Draw()
{
}

//�J��
void Player::Release()
{
}