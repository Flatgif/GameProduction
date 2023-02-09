#pragma once
#include "Engine/GameObject.h"

//◆◆◆を管理するクラス
class Map : public GameObject
{
    int hModel_[4];
    int width_;
    int wallHeight_;
    int roomGP_;
    enum createFlag
    {
        MakeOK = 0x01,
        RoomOK = 0x02,
        DigOK = 0x04,
        HeightOK = 0x08,
        MAX= 0x10,
    };
    int flag_;
    struct
    {
        int data;
        int type;
        int height;
        
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
    void Check();
    void WallHeight();
    void Stairs();
    bool IsWall(int x, int z);
    bool IsFloor(int x, int z);
    bool IsStairs(int x, int z);
    //モデル番号取得
    int GetModelHandle(int modelNum) { return hModel_[modelNum]; }

};