#pragma once
#include "Engine/GameObject.h"
#include "Map.h"

//���������Ǘ�����N���X
class Player : public GameObject
{
    int hModel_;    //���f���ԍ�
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
        //�̗�
        int HP;
        //�ő�̗�
        int MAXHP;
        //���x��
        int LV; 
        //������
        int STR; 
        //�U����
        int ATK;
        //�h���
        int DEF; 
        //������
        int GOLD;
        //�o���l
        int EXP; 
    }STATUS_t;

    STATUS_t player_ = { 15 , 15 , 1 , 5 , 5 , 0, 0, 0 };

public:
    //�R���X�g���N�^
    Player(GameObject* parent);

    //�f�X�g���N�^
    ~Player();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    XMFLOAT3 movePlayer(XMFLOAT3 a, XMFLOAT3 b, float time);
};