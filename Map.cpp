#include "Map.h"
#include "Engine/Model.h"

//コンストラクタ
Map::Map(GameObject* parent)
    :GameObject(parent, "Map")
{
}

//デストラクタ
Map::~Map()
{
}

//初期化
void Map::Initialize()
{   
    //モデルデータのロード
    hModel_[0] = Model::Load("sikaku.fbx");
    assert(hModel_ >= 0);
    hModel_[1] = Model::Load("yuka.fbx");
    assert(hModel_ >= 0);

   
   



    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            map_[i][j] = 0;
        }
    }

    for (int i = 1; i < 14; i++)
    {
        for (int j = 1; j < 14; j++)
        {
            map_[i][j] = 1;
        }
    }


}

//更新
void Map::Update()
{
}

//描画
void Map::Draw()
{
    for (int i = 0; i < 15; i++)
    {
        transform_.position_.x = i;
        for (int j = 0; j < 15; j++)
        {
            int type = map_[i][j];
            transform_.position_.z = j;
            Model::SetTransform(hModel_[type], transform_);
            Model::Draw(hModel_[type]);

        }
    }

}

//開放
void Map::Release()
{
}