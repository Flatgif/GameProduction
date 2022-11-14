#pragma once
#include "Engine/GameObject.h"

//◆◆◆を管理するクラス
class Map : public GameObject
{
    int hModel_[3];
    int width_;
    int roomGP_;

    struct
    {
        int data;
        int type;
    }map_[100][100];

public:
    //コンストラクタ
    Map(GameObject* parent);

    //デストラクタ
    ~Map();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    void Make();
    void DigHole();
    void RoomGeneration();
    bool IsWall(int x, int z);

};