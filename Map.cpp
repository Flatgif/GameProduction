#include "Map.h"
#include<stdio.h>
#include <stdlib.h>
#include<time.h>
#include <conio.h>
#include <ctype.h>
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

}

//更新
void Map::Update()
{
}

//描画
void Map::Draw()
{
    /*for (int i = 0; i < 32; i++)
    {
        transform_.position_.x = i;
        for (int j = 0; j < 32; j++)
        {
            int type = map_[i][j];
            transform_.position_.z = j;
            Model::SetTransform(hModel_[type], transform_);
            Model::Draw(hModel_[type]);

        }
    }*/

}

//開放
void Map::Release()
{
}

void Map::Create()
{

}

