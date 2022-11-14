#pragma once
#include "Engine/GameObject.h"
#include "Map.h"

//◆◆◆を管理するクラス
class Player : public GameObject
{
    int hModel_;    //モデル番号
    int dig_;
    float move_;
    float rota_;
    bool rotaFlag_;
    bool rotating_;
    bool dir_;
    Map* pMap;

     enum bol {
        front = 0,
        right,
        left,
        back,
        Maxnum,
    };

    struct a {
        bool iswall;
    };
    
    

public:
    //コンストラクタ
    Player(GameObject* parent);

    //デストラクタ
    ~Player();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    void Col(a *flag);
};