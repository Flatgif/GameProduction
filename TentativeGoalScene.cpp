#include "TentativeGoalScene.h"
#include "Engine/Image.h"
//コンストラクタ
TentativeGoalSceneScene::TentativeGoalSceneScene(GameObject* parent)
	: GameObject(parent, "TentativeGoalSceneScene"), hPict_(-1)
{
}

//初期化
void TentativeGoalSceneScene::Initialize()
{//画像データのロード
    hPict_ = Image::Load("goal.jpg");
    assert(hPict_ >= 0);
}

//更新
void TentativeGoalSceneScene::Update()
{
}

//描画
void TentativeGoalSceneScene::Draw()
{
    Image::SetTransform(hPict_, transform_);
    Image::Draw(hPict_);
}

//開放
void TentativeGoalSceneScene::Release()
{
}