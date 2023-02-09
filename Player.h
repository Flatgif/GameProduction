#pragma once
#include "Engine/GameObject.h"
#include "Map.h"
#include "Engine/Model.h"

//◆◆◆を管理するクラス
class Player : public GameObject
{

    int hModel_;    //モデル番号
    int hMapModel_[4];

    int dig_;
    float rota_;
    bool rotaFlag_;
    bool dir_;
    bool move_;
    Map* pMap;
    //移動量のベクトル
    XMVECTOR vPos_;
    XMVECTOR vMove_;
    XMMATRIX mRotateX_;
    XMMATRIX mRotate_;

    XMFLOAT3 prevPosition_;
    XMFLOAT3 nowPosition_;
    Transform trans;
    enum Flag
    {
    };
    typedef enum state
    {
        def = 1 << 0,
        rota = 1 << 1,
        dir = 1 << 2,
        move = 1 << 3 ,

    }playerState;
    playerState playerstate_;

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
    //プレイヤーを移動させる
    void PlayerMove();

    void PlayerSlideMove();


    /// <summary>
    /// 移動量をプレイヤーのポジションに追加していく
    /// </summary>
    /// <param name="m">移動量</param>
    void AddMove(XMVECTOR m) { playerstate_ = move; vMove_ += m; }

    /// <summary>
    /// モデルとの当たり判定
    /// </summary>
    /// <param name="h_model">当たり判定をするモデル</param>
    /// <returns></returns>
    bool IsHit(int h_model, RayCastData* data);

    //プレイヤーに追従するカメラ呼び出し
    void CallCam();

    //カメラの視点マウスにする
    void ViewRotate();

    XMVECTOR ScratchWall(XMVECTOR normal, XMVECTOR pos);


};