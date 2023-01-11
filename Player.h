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
    bool move_;
    Map* pMap;
    XMFLOAT3 prevPosition_;
    XMFLOAT3 nowPosition_;
    Transform trans;
    enum Flag
    {
        def = 0,
        rota,
        dir,
        move=4,
    };
    
    typedef struct {
        //体力
        int HP;
        //最大体力
        int MAXHP;
        //レベル
        int LV; 
        //ちから
        int STR; 
        //攻撃力
        int ATK;
        //防御力
        int DEF; 
        //所持金
        int GOLD;
        //経験値
        int EXP; 
    }STATUS_t;

    STATUS_t player_ = { 15 , 15 , 1 , 5 , 5 , 0, 0, 0 };

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

    XMFLOAT3 movePlayer(XMFLOAT3 a, XMFLOAT3 b, float time);
};