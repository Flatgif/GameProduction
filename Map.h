#pragma once
#include "Engine/GameObject.h"

//◆◆◆を管理するクラス
class Map : public GameObject
{
    int hModel_[2];
    int map_[15][15]; //二次元配列

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
};