#include "Player.h"
#include "Engine/Camera.h"
#include "Engine/Model.h"
#include "Engine/Input.h"

//コンストラクタ
Player::Player(GameObject* parent)
	:GameObject(parent, "Player"), hModel_(-1), move_(0.1f), rota_(2)
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
	transform_.position_.x = 1.0f;
	transform_.position_.z = 1.0f;
	transform_.position_.y = 1;
	Camera::SetPosition(XMFLOAT3(transform_.position_));
	Camera::SetTarget(XMFLOAT3(transform_.position_.x, transform_.position_.y, 11));

}

//更新
void Player::Update()
{
	int num = 0;


	if (Input::IsKeyDown(DIK_RIGHT))
	{
		while (num != 45)
		{
		transform_.rotate_.y += rota_;
		num++;
		}
		
	}

	if (Input::IsKeyDown(DIK_LEFT))
	{
		while (num != 45)
		{
			transform_.rotate_.y -= rota_;
			num++;
		}
		
	}

	XMMATRIX mRotate = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));   //Y軸で()度回転;
	XMMATRIX mRotateX = XMMatrixRotationX(XMConvertToRadians(transform_.rotate_.x));   //Y軸で()度回転;

	XMVECTOR vPos = XMLoadFloat3(&transform_.position_);//positionもベクトルに変換

	XMFLOAT3 move = { 0, 0, 1 };
	XMFLOAT3 moveX = { 1, 0, 0 };
	
	XMVECTOR vMove = XMLoadFloat3(&move);
	XMVECTOR vMoveX = XMLoadFloat3(&moveX);

	vMove = XMVector3TransformCoord(vMove, mRotate);
	vMoveX = XMVector3TransformCoord(vMoveX, mRotate);


	if (Input::IsKeyDown(DIK_D))
	{
		vPos += vMoveX;
		XMStoreFloat3(&transform_.position_, vPos);
	}

	if (Input::IsKeyDown(DIK_A))
	{
		vPos -= vMoveX;
		XMStoreFloat3(&transform_.position_, vPos);
	}

	if (Input::IsKeyDown(DIK_W))
	{
		vPos += vMove;
		XMStoreFloat3(&transform_.position_, vPos);
	}

	if (Input::IsKeyDown(DIK_S))
	{
		vPos -= vMove;
		XMStoreFloat3(&transform_.position_, vPos);
	}

	XMVECTOR vCam = XMVectorSet(0,0, -1, 0);
	vCam = XMVector3TransformCoord(vCam, mRotateX);
	vCam = XMVector3TransformCoord(vCam, mRotate);
	XMFLOAT3 camPos;
	XMStoreFloat3(&camPos, vPos + vCam);
	XMVECTOR myself = XMLoadFloat3(&camPos);
	XMVECTOR target = XMLoadFloat3(&transform_.position_);
	if (!Input::IsKey(DIK_Q))
	{
		Camera::SetPosition(camPos);
		Camera::SetTarget(transform_.position_);

	}


}

//描画
void Player::Draw()
{
    //Model::SetTransform(hModel_, transform_);
    //Model::Draw(hModel_);
}

//開放
void Player::Release()
{
}