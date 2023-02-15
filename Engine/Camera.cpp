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
//初期化（プロジェクション行列作成）
void Camera::Initialize()
{
	cameInfo._position = XMFLOAT3(0, 3, -10);	//カメラの位置
	cameInfo._target = XMFLOAT3(0, 0, 0);	//カメラの焦点
	cameInfo._fov = 105;
	cameInfo.shakePos = XMFLOAT3(0, 0, 0);
	//プロジェクション行列
	cameInfo._proj = XMMatrixPerspectiveFovLH(XMConvertToRadians(cameInfo._fov), (FLOAT)Direct3D::screenWidth_ / (FLOAT)Direct3D::screenHeight_, 0.1f, 1000.0f);
}

//更新（ビュー行列作成）
void Camera::Update()
{
	// カメラを揺らす処理を行うかどうかのフラグが立っていたらカメラを揺らす処理を行う
	if (cameInfo.Shake)
	{
		// sin を使用した揺らし座標の算出
		cameInfo.shakePos.y =sin(cameInfo.ShakeAngle) * (1.0f - (cameInfo.ShakeTimeCounter /cameInfo.ShakeTime)) * cameInfo.ShakeWidth;
		cameInfo.shakePos.x = 0.0f;
		cameInfo.shakePos.z = 0.0f;

		// 揺らし処理に使用する sin に渡す角度の変更処理
		cameInfo.ShakeAngle += cameInfo.ShakeAngleSpeed * cameInfo.StepTime;

		// 揺らす時間が経過したら揺らし処理を終了する
		cameInfo.ShakeTimeCounter += cameInfo.StepTime;
		if (cameInfo.ShakeTimeCounter >= cameInfo.ShakeTime)
		{
			cameInfo.Shake = false;
		}
	}
	else
	{
		// 揺らされていない場合は揺らし処理による加算座標を０にする
		cameInfo.shakePos = XMFLOAT3(0, 0, 0);
	}

	cameInfo._proj = XMMatrixPerspectiveFovLH(XMConvertToRadians(cameInfo._fov), (FLOAT)Direct3D::screenWidth_ / (FLOAT)Direct3D::screenHeight_, 0.1f, 1000.0f);

	//ビュー行列
	cameInfo._view = XMMatrixLookAtLH(XMVectorSet(cameInfo._position.x, cameInfo._position.y+cameInfo.shakePos.y, cameInfo._position.z, 0),
		XMVectorSet(cameInfo._target.x, cameInfo._target.y, cameInfo._target.z, 0), XMVectorSet(0, 1, 0, 0));
}

void Camera::setTime(int time) { cameInfo.StepTime = time; }

void Camera::setShakeFlag(bool shake) { cameInfo.Shake = shake; }
//焦点を設定
void Camera::SetTarget(XMFLOAT3 target) { cameInfo._target = target; }

void Camera::SetFov(int fov) { cameInfo._fov = fov; }

//位置を設定
void Camera::SetPosition(XMFLOAT3 position) { cameInfo._position = position; }

//焦点を取得
XMFLOAT3 Camera::GetTarget() { return cameInfo._target; }

int Camera::GetFov() { return cameInfo._fov; }

//位置を取得
XMFLOAT3 Camera::GetPosition() { return cameInfo._position; }

//ビュー行列を取得
XMMATRIX Camera::GetViewMatrix() { return cameInfo._view; }

//プロジェクション行列を取得
XMMATRIX Camera::GetProjectionMatrix() { return cameInfo._proj; }