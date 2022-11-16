#include "Player.h"
#include "Engine/Camera.h"
#include "Engine/Model.h"
#include "Engine/Input.h"

//�R���X�g���N�^
Player::Player(GameObject* parent)
	:GameObject(parent, "Player"), hModel_(-1)
	, rota_(2.0f), rotaFlag_(false), dig_(0), dir_(nullptr)
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
	pMap = (Map*)FindObject("Map");
	//assert(pMap != nullptr);
	transform_.position_.y = 1.5f;

	transform_.position_.x = 1.0f;
	transform_.position_.z = 1.0f;

	Camera::SetPosition(XMFLOAT3(transform_.position_));
	Camera::SetTarget(XMFLOAT3(transform_.position_.x, transform_.position_.y, 11));
}

//�X�V
void Player::Update()
{
	if (rotating_)
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


	XMMATRIX mRotate = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));   //Y����()�x��];
	XMMATRIX mRotateX = XMMatrixRotationX(XMConvertToRadians(transform_.rotate_.x));   //Y����()�x��];

	XMVECTOR vPos = XMLoadFloat3(&transform_.position_);//position���x�N�g���ɕϊ�
	XMVECTOR prePos = XMLoadFloat3(&transform_.position_);

	XMFLOAT3 move = { 0, 0, 1.0f };
	XMFLOAT3 moveX = { 1.0f, 0, 0 };

	XMVECTOR vMove = XMLoadFloat3(&move);
	XMVECTOR vMoveX = XMLoadFloat3(&moveX);

	vMove = XMVector3TransformCoord(vMove, mRotate);
	vMoveX = XMVector3TransformCoord(vMoveX, mRotate);
	
	if (!rotaFlag_)
	{
		Transform trans = transform_;

		if (Input::IsKeyDown(DIK_D))
		{
			prePos += vMoveX;
			XMStoreFloat3(&trans.position_, prePos);

			if (!pMap->IsWall(trans.position_.x, trans.position_.z))
			{
				vPos += vMoveX;
			}
		}

		if (Input::IsKeyDown(DIK_A))
		{
			prePos -= vMoveX;
			XMStoreFloat3(&trans.position_, prePos);
			if (!pMap->IsWall(trans.position_.x, trans.position_.z))
			{
				vPos -= vMoveX;
			}
		}

		if (Input::IsKeyDown(DIK_W))
		{
			prePos += vMove;
			XMStoreFloat3(&trans.position_, prePos);

			if (!pMap->IsWall(trans.position_.x, trans.position_.z))
			{
				vPos += vMove;
			}
		}

		if (Input::IsKeyDown(DIK_S))
		{
			prePos -= vMove;
			XMStoreFloat3(&trans.position_, prePos);

			if (!pMap->IsWall(trans.position_.x, trans.position_.z))
			{
				vPos -= vMove;
			}
		}

		XMStoreFloat3(&transform_.position_, vPos);
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
	}
}

//�`��
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

//�J��
void Player::Release()
{
}

