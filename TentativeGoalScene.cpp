#include "TentativeGoalScene.h"
#include "Engine/Image.h"
//�R���X�g���N�^
TentativeGoalSceneScene::TentativeGoalSceneScene(GameObject* parent)
	: GameObject(parent, "TentativeGoalSceneScene"), hPict_(-1)
{
}

//������
void TentativeGoalSceneScene::Initialize()
{//�摜�f�[�^�̃��[�h
    hPict_ = Image::Load("goal.jpg");
    assert(hPict_ >= 0);
}

//�X�V
void TentativeGoalSceneScene::Update()
{
}

//�`��
void TentativeGoalSceneScene::Draw()
{
    Image::SetTransform(hPict_, transform_);
    Image::Draw(hPict_);
}

//�J��
void TentativeGoalSceneScene::Release()
{
}