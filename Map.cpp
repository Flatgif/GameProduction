#include "Map.h"
#include<stdio.h>
#include <stdlib.h>
#include<time.h>
#include <conio.h>
#include <ctype.h>
#include "Engine/Model.h"




//コンストラクタ
Map::Map(GameObject* parent)
    :GameObject(parent, "Map"),width(9)
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
    for (int i = 0; i < 31; i++)
    {
        transform_.position_.x = i;
        for (int j = 0; j < 31; j++)
        {
            int type = map_[i][j].type;
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

void Map::Create()
{

}

void Map::Make()
{
	int Nu = 1;
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < width; j++)
		{
			map_[i][j].data = Nu;
			Nu += 1;
		}
	}

	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < width; j++) {
			if ((map_[i][j].data < width) || map_[i][j].data > width * width - width + 1)
			{
				map_[i][j].type = 0;
			}
			else if ((map_[i][j].data % width == 0) || ((map_[i][j].data - 1) % width == 0))
			{
				map_[i][j].type = 0;
			}
			else
			{
				if (width == 5) {
					map_[i][j].type = 1;
				}
				else {
					map_[i][j].type = 1;
				}

			}
		}
	}
}
