#pragma once
#include "Engine/GameObject.h"

//◆◆◆を管理するクラス
class Map : public GameObject
{
    int hModel_[2];
    int width;
    struct
    {
        int data;
        int type;
    }map_[31][31];
public:
    Map();
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

    void Create();
    void Make();
};