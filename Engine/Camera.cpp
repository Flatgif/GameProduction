#include "camera.h"
#include "Direct3D.h"

typedef struct CameraInfo_t
{

	XMFLOAT3 _position;
	XMFLOAT3 _target;
	XMMATRIX _view;
	XMMATRIX _proj;
	int _fov;
	bool   Shake;
	float  ShakeWidth;
	float  ShakeTime;
	float  ShakeTimeCounter;
	float  ShakeAngle;
	float  ShakeAngleSpeed;
	float StepTime;
	XMFLOAT3  shakePos = XMFLOAT3( 0,0,0);
}CameraInfo;


static CameraInfo cameInfo;
//�������i�v���W�F�N�V�����s��쐬�j
void Camera::Initialize()
{
	cameInfo._position = XMFLOAT3(0, 3, -10);	//�J�����̈ʒu
	cameInfo._target = XMFLOAT3(0, 0, 0);	//�J�����̏œ_
	cameInfo._fov = 105;
	cameInfo.shakePos = XMFLOAT3(0, 0, 0);
	//�v���W�F�N�V�����s��
	cameInfo._proj = XMMatrixPerspectiveFovLH(XMConvertToRadians(cameInfo._fov), (FLOAT)Direct3D::screenWidth_ / (FLOAT)Direct3D::screenHeight_, 0.1f, 1000.0f);
}

//�X�V�i�r���[�s��쐬�j
void Camera::Update()
{
	// �J������h�炷�������s�����ǂ����̃t���O�������Ă�����J������h�炷�������s��
	if (cameInfo.Shake)
	{
		// sin ���g�p�����h�炵���W�̎Z�o
		cameInfo.shakePos.y =sin(cameInfo.ShakeAngle) * (1.0f - (cameInfo.ShakeTimeCounter /cameInfo.ShakeTime)) * cameInfo.ShakeWidth;
		cameInfo.shakePos.x = 0.0f;
		cameInfo.shakePos.z = 0.0f;

		// �h�炵�����Ɏg�p���� sin �ɓn���p�x�̕ύX����
		cameInfo.ShakeAngle += cameInfo.ShakeAngleSpeed * cameInfo.StepTime;

		// �h�炷���Ԃ��o�߂�����h�炵�������I������
		cameInfo.ShakeTimeCounter += cameInfo.StepTime;
		if (cameInfo.ShakeTimeCounter >= cameInfo.ShakeTime)
		{
			cameInfo.Shake = false;
		}
	}
	else
	{
		// �h�炳��Ă��Ȃ��ꍇ�͗h�炵�����ɂ����Z���W���O�ɂ���
		cameInfo.shakePos = XMFLOAT3(0, 0, 0);
	}

	cameInfo._proj = XMMatrixPerspectiveFovLH(XMConvertToRadians(cameInfo._fov), (FLOAT)Direct3D::screenWidth_ / (FLOAT)Direct3D::screenHeight_, 0.1f, 1000.0f);

	//�r���[�s��
	cameInfo._view = XMMatrixLookAtLH(XMVectorSet(cameInfo._position.x, cameInfo._position.y+cameInfo.shakePos.y, cameInfo._position.z, 0),
		XMVectorSet(cameInfo._target.x, cameInfo._target.y, cameInfo._target.z, 0), XMVectorSet(0, 1, 0, 0));
}

void Camera::setTime(int time) { cameInfo.StepTime = time; }

void Camera::setShakeFlag(bool shake) { cameInfo.Shake = shake; }
//�œ_��ݒ�
void Camera::SetTarget(XMFLOAT3 target) { cameInfo._target = target; }

void Camera::SetFov(int fov) { cameInfo._fov = fov; }

//�ʒu��ݒ�
void Camera::SetPosition(XMFLOAT3 position) { cameInfo._position = position; }

//�œ_���擾
XMFLOAT3 Camera::GetTarget() { return cameInfo._target; }

int Camera::GetFov() { return cameInfo._fov; }

//�ʒu���擾
XMFLOAT3 Camera::GetPosition() { return cameInfo._position; }

//�r���[�s����擾
XMMATRIX Camera::GetViewMatrix() { return cameInfo._view; }

//�v���W�F�N�V�����s����擾
XMMATRIX Camera::GetProjectionMatrix() { return cameInfo._proj; }