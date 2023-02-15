#include "Player.h"
#include "Engine/Camera.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Global.h"
#include "Engine/SceneManager.h"
//コンストラクタ
Player::Player(GameObject* parent)
	:GameObject(parent, "Player"), hModel_(-1)
	, rota_(2.0f), rotaFlag_(false), dig_(0), dir_(nullptr), move_(false)
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
	hModel_ = Model::Load("enemy.fbx");
	assert(hModel_ >= 0);
	pMap = (Map*)FindObject("Map");
	assert(pMap != nullptr);
	for (int i = 0; i < 4; i++)
	{
		hMapModel_[i] = pMap->GetModelHandle(i);
	}

	transform_.position_.y = 1.5f;
	transform_.position_.x = 1.0f;
	transform_.position_.z = 1.0f;
	transform_.scale_ = XMFLOAT3(0.5f, 0.5f, 0.5f);
	Camera::SetPosition(XMFLOAT3(transform_.position_));
	Camera::SetTarget(XMFLOAT3(transform_.position_.x, transform_.position_.y, 11));
}

//更新
void Player::Update()
{
	XMFLOAT3 prePosition = transform_.position_;
	if (!rotaFlag_)
	{
		if (!move_)
		{
			if (Input::IsKeyDown(DIK_RIGHT))
			{
				rotaFlag_ = true;
				dir_ = true;
				dig_ = 0;
			}
			else if (Input::IsKeyDown(DIK_LEFT))
			{
				rotaFlag_ = true;
				dir_ = false;
				dig_ = 0;
			}
		}
	}
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
	if (dig_ >= (float)(90 / rota_))
	{

		rotaFlag_ = false;
	}

	vPos_ = XMLoadFloat3(&transform_.position_);

	//移動量
	XMVECTOR moveX = { 1, 0, 0, 0 };
	XMVECTOR moveZ = { 0, 0, 1, 0 };
	moveX = XMVector3TransformCoord(moveX, mRotate_);
	moveZ = XMVector3TransformCoord(moveZ, mRotate_);
	//移動入力処理
	if (Input::IsKeyDown(DIK_W))
	{
		AddMove(moveZ);
		Camera::setShakeFlag(true);
	}
	if (Input::IsKeyDown(DIK_A))
	{
		AddMove(-moveX);

	}
	if (Input::IsKeyDown(DIK_S))
	{
		AddMove(-moveZ);
	}
	if (Input::IsKeyDown(DIK_D))
	{
		AddMove(moveX);

	}



	switch (playerstate_)
	{
	case move:
		PlayerSlideMove();
		break;

	default:
		break;
	}
	XMStoreFloat3(&transform_.position_, vPos_);

	//Y軸で()度回転;
	mRotate_ = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));
	//x軸で()度回転;
	mRotateX_ = XMMatrixRotationX(XMConvertToRadians(transform_.rotate_.x));

	CallCam();


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

void Player::PlayerMove()
{
	vMove_ = XMVector3Normalize(vMove_);
	vPos_ += vMove_;
	vMove_ = XMVectorSet(0, 0, 0, 0);
	playerstate_ = def;

}

void Player::PlayerSlideMove()
{
	RayCastData data;

	if (IsHit(hMapModel_[1], &data) || IsHit(hMapModel_[2], &data))
	{
		vMove_ = ScratchWall(data.normal, vMove_);
		//vMove_ *= 0;
	}
	vPos_ += vMove_;
	vMove_ = XMVectorSet(0, 0, 0, 0);
	playerstate_ = def;


}

bool Player::IsHit(int h_model, RayCastData* data)
{

	XMVECTOR length = XMVector3Length(vMove_);
	float leng = XMVectorGetX(length);
	XMStoreFloat3(&data->start, vPos_);
	XMStoreFloat3(&data->dir, vMove_);
	Model::RayCast(h_model, &*data);
	if (data->dist * leng <= 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Player::CallCam()
{
	//Cameraの処理

	XMFLOAT3 camPos;
	//Cameraの位置
	XMVECTOR vCam = XMVectorSet(0,0, -0.0001f , 0);

	vCam = XMVector3TransformCoord(vCam, mRotateX_);
	vCam = XMVector3TransformCoord(vCam, mRotate_);

	XMStoreFloat3(&camPos, vPos_ + vCam);

	XMVECTOR myself = XMLoadFloat3(&camPos);
	XMVECTOR target = XMLoadFloat3(&transform_.position_);

	Camera::SetPosition(camPos);
	Camera::SetTarget(transform_.position_);
}

void Player::ViewRotate()
{
	//マウスの移動量を正規化
	XMFLOAT3 mouseMove = Input::GetMouseMove();

	//視点の回転（マウスの移動量）
	transform_.rotate_.x += mouseMove.y;
	transform_.rotate_.y += mouseMove.x;
	if (transform_.rotate_.x >= 89)
	{
		transform_.rotate_.x = 89;
	}
	if (transform_.rotate_.x <= -89)
	{
		transform_.rotate_.x = -89;
	}

#ifdef DEBUG
	camDist_ += mouseMove.z / 10;
	if (camDist_ > 0)camDist_ = 0;
#endif // DEBUG
}

XMVECTOR Player::ScratchWall(XMVECTOR normal, XMVECTOR pos)
{
	XMVECTOR delY = XMVectorSet(1, 0, 1, 0);
	normal = XMVector3Normalize(normal);
	XMVECTOR result = pos - XMVector3Dot(pos, normal) * normal;
	result *= delY;
	return result;

}

