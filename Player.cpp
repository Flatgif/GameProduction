#include "Player.h"
#include "Engine/Camera.h"
#include "Engine/Model.h"
#include "Engine/Input.h"

//コンストラクタ
Player::Player(GameObject* parent)
	:GameObject(parent, "Player"), hModel_(-1)
	, move_(0.1f), rota_(2.0f), rotaFlag_(false), dig_(0), dir_(nullptr), rotating_(true)
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
	pMap = (Map*)FindObject("Map");
	//assert(pMap != nullptr);
	transform_.position_.y = 1.5f;

	transform_.position_.x = 1.0f;
	transform_.position_.z = 1.0f;

	Camera::SetPosition(XMFLOAT3(transform_.position_));
	Camera::SetTarget(XMFLOAT3(transform_.position_.x, transform_.position_.y, 11));
}

//更新
void Player::Update()
{
	a flag[Maxnum];
	Col(flag);
	if (rotating_)
	{
		if (Input::IsKeyDown(DIK_RIGHT))
		{
			rotaFlag_ = true;
			dir_ = true;
			dig_ = 0;
			rotating_ = false;
		}
		else if (Input::IsKeyDown(DIK_LEFT))
		{
			rotaFlag_ = true;
			dir_ = false;
			dig_ = 0;
			rotating_ = false;
		}

	}


	XMMATRIX mRotate = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));   //Y軸で()度回転;
	XMMATRIX mRotateX = XMMatrixRotationX(XMConvertToRadians(transform_.rotate_.x));   //Y軸で()度回転;

	XMVECTOR vPos = XMLoadFloat3(&transform_.position_);//positionもベクトルに変換

	XMFLOAT3 move = { 0, 0, 1.0f };
	XMFLOAT3 moveX = { 1.0f, 0, 0 };

	XMVECTOR vMove = XMLoadFloat3(&move);
	XMVECTOR vMoveX = XMLoadFloat3(&moveX);

	vMove = XMVector3TransformCoord(vMove, mRotate);
	vMoveX = XMVector3TransformCoord(vMoveX, mRotate);
	XMFLOAT3 prevPosition = transform_.position_;
	
	if (rotating_)
	{
		

		if (Input::IsKeyDown(DIK_D) && flag[right].iswall == false)
		{
			vPos += vMoveX;
			XMStoreFloat3(&transform_.position_, vPos);
		}

		if (Input::IsKeyDown(DIK_A) && flag[left].iswall == false)
		{
			vPos -= vMoveX;
			XMStoreFloat3(&transform_.position_, vPos);
		}

		if (Input::IsKeyDown(DIK_W) && flag[front].iswall == false)
		{
			vPos += vMove;
			XMStoreFloat3(&transform_.position_, vPos);
		}

		if (Input::IsKeyDown(DIK_S) && flag[back].iswall == false)
		{
			vPos -= vMove;
			XMStoreFloat3(&transform_.position_, vPos);
		}


	}
	XMFLOAT3 nowPosition = transform_.position_;
	XMVECTOR vCam = XMVectorSet(0, 0, -0.001, 0);
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
	if (dig_ >= (float)(90 / rota_))
	{
		rotaFlag_ = false;
		rotating_ = true;
	}
}

//描画
void Player::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);

	if (dir_)
	{
		if (rotaFlag_)
		{
			transform_.rotate_.y += rota_;
			dig_++;
		}
	}
	else
	{
		if (rotaFlag_)
		{
			transform_.rotate_.y -= rota_;
			dig_++;
		}
	}

}

//開放
void Player::Release()
{
}

void Player::Col(a *flag)
{
	int checkX, checkZ;

	checkX = (int)(transform_.position_.x);
	checkZ = (int)(transform_.position_.z + 1.0f);
	if (pMap->IsWall(checkX, checkZ))
	{
		flag[front].iswall = true;
	}
	else
	{
		flag[front].iswall = false;
	}

	checkX = (int)(transform_.position_.x);
	checkZ = (int)(transform_.position_.z - 1.0f);
	if (pMap->IsWall(checkX, checkZ))
	{
		flag[back].iswall = true;
	}
	else
	{
		flag[back].iswall = false;
	}

	checkX = (int)(transform_.position_.x + 1.0f);
	checkZ = (int)(transform_.position_.z);
	if (pMap->IsWall(checkX, checkZ))
	{
		flag[right].iswall = true;
	}
	else
	{
		flag[right].iswall = false;
	}

	checkX = (int)(transform_.position_.x - 1.0f);
	checkZ = (int)(transform_.position_.z);
	if (pMap->IsWall(checkX, checkZ))
	{
		flag[left].iswall = true;
	}
	else
	{
		flag[left].iswall = false;
	}
}