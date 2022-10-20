#include "Player.h"
#include "Engine/Camera.h"
#include "Engine/Model.h"

//�R���X�g���N�^
Player::Player(GameObject* parent)
    :GameObject(parent, "Player"), hModel_(-1)
{
}

//�f�X�g���N�^
Player::~Player()
{
}

//������
void Player::Initialize()
{
    //���f���f�[�^�̃��[�h
    hModel_ = Model::Load("sikaku.fbx");
    assert(hModel_ >= 0);
}

//�X�V
void Player::Update()
{
    /*Camera::SetPosition(transform_.position_);*/
    XMFLOAT3 trans = transform_.position_;
    transform_.position_.x;
    transform_.rotate_;
}

//�`��
void Player::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

//�J��
void Player::Release()
{
}