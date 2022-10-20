#include "Player.h"
#include "Engine/Camera.h"
#include "Engine/Model.h"

//コンストラクタ
Player::Player(GameObject* parent)
    :GameObject(parent, "Player"), hModel_(-1)
{
}

//デストラクタ
Player::~Player()
{
}

//初期化
void Player::Initialize()
{
    //モデルデータのロード
    hModel_ = Model::Load("sikaku.fbx");
    assert(hModel_ >= 0);
}

//更新
void Player::Update()
{
    /*Camera::SetPosition(transform_.position_);*/
    XMFLOAT3 trans = transform_.position_;
    transform_.position_.x;
    transform_.rotate_;
}

//描画
void Player::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

//開放
void Player::Release()
{
}