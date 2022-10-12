#include "Player.h"
#include "Engine/Camera.h"

//コンストラクタ
Player::Player(GameObject* parent)
    :GameObject(parent, "Player")
{
}

//デストラクタ
Player::~Player()
{
}

//初期化
void Player::Initialize()
{
}

//更新
void Player::Update()
{
    Camera::SetPosition(transform_.position_);
}

//描画
void Player::Draw()
{
}

//開放
void Player::Release()
{
}