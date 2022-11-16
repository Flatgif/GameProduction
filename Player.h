#pragma once
#include "Engine/GameObject.h"
#include "Map.h"

//◆◆◆を管理するクラス
class Player : public GameObject
{
    int hModel_;    //モデル番号
    int dig_;
    float rota_;
    bool rotaFlag_;
    bool dir_;
    Map* pMap;
    XMFLOAT3 prevPosition_;
    XMFLOAT3 nowPosition_;
    
    

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

};