#include "Map.h"
#include<stdio.h>
#include <stdlib.h>
#include<time.h>
#include <conio.h>
#include <ctype.h>
#include "Engine/Model.h"




//コンストラクタ
Map::Map(GameObject* parent)
	:GameObject(parent, "Map"), width_(51), random_(0), roomGP_(99), roomSize_(0)
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
	hModel_[1] = Model::Load("sikaku.fbx");
    hModel_[2] = Model::Load("yuka.fbx");
    assert(hModel_ >= 0);
	Make();
	DigHole();
	RoomGeneration();

}

//更新
void Map::Update()
{
}

//描画
void Map::Draw()
{
    for (int i = 0; i < width_; i++)
    {
        transform_.position_.x = i;
        for (int j = 0; j < width_; j++)
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


void Map::Make()
{
	int  Init = 1;
	for (int i = 0; i < width_; i++)
	{
		for (int j = 0; j < width_; j++)
		{
			map_[i][j].data = Init;
			Init += 1;
		}
	}

	for (int i = 0; i < width_; i++)
	{
		for (int j = 0; j < width_; j++) {
			if ((map_[i][j].data < width_) || map_[i][j].data > width_ * width_ - width_ + 1)
			{
				map_[i][j].type = 0;
			}
			else if ((map_[i][j].data % width_ == 0) || ((map_[i][j].data - 1) % width_ == 0))
			{
				map_[i][j].type = 0;
			}
			else
			{
				if (width_ == 5) {
					map_[i][j].type = 2;
				}
				else {
					map_[i][j].type = 1;
				}

			}
		}
	}
}

void Map::DigHole()
{
	srand((unsigned int)time(NULL));
	int m1[1000], m2[1000], count = 1;
	int i;
	int brute[4] = { 1,2,3,4 }, ra, kp;
	int x = 1, y = width_ - 2, move = 1;
	int non = 0, co = 0;
	while (1)
	{
		switch (move)
		{

		case 1:
			move = rand() % 3 + 1;
			if (move == 3)
			{
				move = 4;
			}
			break;
		case 2:
			move = rand() % 3 + 1;
			break;
		case 3:
			move = rand() % 3 + 2;
			break;
		case 4:
			move = rand() % 3 + 1;
			if (move == 2)
			{
				move = 4;
			}
		default:
			break;
		}

		if (non >= 4)
		{
			co = co + 1;
			if (non == 4)
			{
				for (i = 0; i < 4; i++) {
					ra = rand() % 4;
					kp = brute[i];
					brute[i] = brute[ra];
					brute[ra] = kp;
				}
			}

			if (co >= 4)
			{
				count = count - 1;
				if (count == 0)
				{
					break;
				}
				y = m1[count];
				x = m2[count];
				co = 0;
			}
			else
			{
				move = brute[co];
			}
		}

		switch (move)
		{
		case 1:
			while (1)
			{
				if ((y - 1 < 1) || (y - 1 > width_ - 2))
				{
					non = non + 1;
					break;
				}
				if (map_[y - 2][x].type != 1)
				{
					non = non + 1;
					break;
				}
				for (i = 0; i < 2; i++)
				{
					y = y - 1;
					map_[y][x].type = 2;
					non = 0;
					co = 0;
				}
				if (i == 2) {
					m1[count] = y;
					m2[count] = x;
					count = count++;
				}
				break;
			}
			break;
		case 2:
			while (1)
			{
				if ((x + 1 < 1) || (x + 1 > width_ - 2))
				{
					non = non + 1;
					break;
				}
				if (map_[y][x + 2].type != 1)
				{
					non = non + 1;
					break;
				}
				for (i = 0; i < 2; i++)
				{
					x = x + 1;

					map_[y][x].type = 2;
					non = 0;
					co = 0;
				}
				if (i == 2) {
					m1[count] = y;
					m2[count] = x;
					count = count++;
				}
				break;
			}
			break;
		case 3:
			while (1) {
				if ((y + 1 < 1) || (y + 1 > width_ - 2))
				{
					non = non + 1;
					break;
				}
				if (map_[y + 2][x].type != 1)
				{
					non = non + 1;
					break;
				}
				for (i = 0; i < 2; i++)
				{
					y = y + 1;

					map_[y][x].type = 2;
					non = 0;
					co = 0;
				}
				if (i == 2)
				{
					m1[count] = y;
					m2[count] = x;
					count = count++;
				}
				break;
			}
			break;
		case 4:
			while (1)
			{
				if ((x - 1 < 1) || (x - 1 > width_ - 2))
				{
					non = non + 1;
					break;
				}
				if (map_[y][x - 2].type != 1)
				{
					non = non + 1;
					break;
				}
				for (i = 0; i < 2; i++)
				{
					x = x - 1;

					map_[y][x].type = 2;
					non = 0;
					co = 0;
				}
				if (i == 2)
				{
					m1[count] = y;
					m2[count] = x;
					count = count++;
				}
				break;
			}
			break;
		default:
			break;
		}

	}
}

void Map::RoomGeneration()
{
	srand((unsigned int)time(NULL));
	for (int i = 1; i < width_ - 5; i++)
	{
		for (int j = 1; j < width_ - 5; j++)
		{
			int genePprobability = rand() % 100 + 1;
			roomSize_ = rand() % 4 + 2;
			if (genePprobability > roomGP_)
			{
				for (int k = 0; k < roomSize_; k++)
				{
					for (int l = 0; l < roomSize_; l++)
					{
						map_[i + k][j + l].type = 2;
					}
				}
			}
		}
	}
}