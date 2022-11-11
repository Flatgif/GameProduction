#include "Map.h"
#include<stdio.h>
#include <stdlib.h>
#include<time.h>
#include <conio.h>
#include <ctype.h>
#include "Engine/Model.h"



//コンストラクタ
Map::Map(GameObject* parent)
	:GameObject(parent, "Map"), width_(61), roomGP_(99)
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
	//外郭のモデル
	hModel_[0] = Model::Load("sikaku.fbx");
	//壁のモデル
	hModel_[1] = Model::Load("sikaku.fbx");
	//床のモデル
	hModel_[2] = Model::Load("yuka.fbx");
	assert(hModel_ >= 0);
	Make();
	RoomGeneration();
	DigHole();
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

//すべて壁のダンジョン（マップ）生成
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

//穴掘り法
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

//部屋の作成
void Map::RoomGeneration()
{
	int roomS = 1;
	if (width_ > 9)
	{
		roomS = width_ / 10;
	}
	srand((unsigned int)time(NULL));
	for (int i = 1; i < width_ - (roomS + 1); i++)
	{
		for (int j = 1; j < width_ - (roomS + 1); j++)
		{
			int genePprobability = rand() % 100 + 1;
			int roomSize = rand() % roomS + 2;
			if (genePprobability > roomGP_)
			{
				for (int k = 0; k < roomSize; k++)
				{
					for (int l = 0; l < roomSize; l++)
					{
						map_[i + k][j + l].type = 2;
					}
				}
			}
		}
	}
}