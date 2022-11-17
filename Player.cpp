#include "Player.h"
#include "Engine/Camera.h"
#include "Engine/Model.h"
#include "Engine/Input.h"

//�R���X�g���N�^
Player::Player(GameObject* parent)
	:GameObject(parent, "Player"), hModel_(-1)
	, rota_(2.0f), rotaFlag_(false), dig_(0), dir_(nullptr),move_(false)
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

	Transform trans = transform_;
	XMMATRIX mRotate = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));   //Y����()�x��];
	XMMATRIX mRotateX = XMMatrixRotationX(XMConvertToRadians(transform_.rotate_.x));   //x����()�x��];
	XMVECTOR vCam = XMVectorSet(0,	0, -0.001, 0);
	vCam = XMVector3TransformCoord(vCam, mRotateX);
	vCam = XMVector3TransformCoord(vCam, mRotate);

	XMVECTOR vPos = XMLoadFloat3(&transform_.position_);//position���x�N�g���ɕϊ�
	XMVECTOR prePos = XMLoadFloat3(&transform_.position_);

	XMFLOAT3 move = { 0, 0, 0.02f };
	XMFLOAT3 moveX = { 0.02f, 0, 0 };

	XMVECTOR vMove = XMLoadFloat3(&move);
	XMVECTOR vMoveX = XMLoadFloat3(&moveX);

	vMove = XMVector3TransformCoord(vMove, mRotate);
	vMoveX = XMVector3TransformCoord(vMoveX, mRotate);
	
	if (!rotaFlag_)
	{
		

		if (Input::IsKey(DIK_D))
		{
			move_ = true;
			prePos += vMoveX;
			XMStoreFloat3(&trans.position_, prePos);
			trans = transform_;
			if (!pMap->IsWall(trans.position_.x, trans.position_.z))
			{
				vPos += vMoveX;
			}
			XMStoreFloat3(&transform_.position_, vPos);

		}

		if (Input::IsKey(DIK_A))
		{
			move_ = true;
			prePos -= vMoveX;
			trans = transform_;
			XMStoreFloat3(&trans.position_, prePos);
			if (!pMap->IsWall(trans.position_.x, trans.position_.z))
			{
				vPos -= vMoveX;
			}
			XMStoreFloat3(&transform_.position_, vPos);

		}

		if (Input::IsKey(DIK_W))
		{
			move_ = true;
			prePos += vMove;
			trans = transform_;
			XMStoreFloat3(&trans.position_, prePos);

			if (!pMap->IsWall(trans.position_.x, trans.position_.z))
			{
				vPos += vMove;
			}
			XMStoreFloat3(&transform_.position_, vPos);

		}

		if (Input::IsKey(DIK_S))
		{
			move_ = true;
			prePos -= vMove;
			trans = transform_;
			XMStoreFloat3(&trans.position_, prePos);

			if (!pMap->IsWall(trans.position_.x, trans.position_.z))
			{
				vPos -= vMove;
			}
			XMStoreFloat3(&transform_.position_, vPos);

		}

		move_ = false;
	}
	XMFLOAT3 nowPosition = transform_.position_;
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

