#pragma once
#include "Engine/GameObject.h"
#include "Map.h"
#include "Engine/Model.h"

//���������Ǘ�����N���X
class Player : public GameObject
{

    int hModel_;    //���f���ԍ�
    int hMapModel_[4];

    int dig_;
    float rota_;
    bool rotaFlag_;
    bool dir_;
    bool move_;
    Map* pMap;
    //�ړ��ʂ̃x�N�g��
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
    //�v���C���[���ړ�������
    void PlayerMove();

    void PlayerSlideMove();


    /// <summary>
    /// �ړ��ʂ��v���C���[�̃|�W�V�����ɒǉ����Ă���
    /// </summary>
    /// <param name="m">�ړ���</param>
    void AddMove(XMVECTOR m) { playerstate_ = move; vMove_ += m; }

    /// <summary>
    /// ���f���Ƃ̓����蔻��
    /// </summary>
    /// <param name="h_model">�����蔻������郂�f��</param>
    /// <returns></returns>
    bool IsHit(int h_model, RayCastData* data);

    //�v���C���[�ɒǏ]����J�����Ăяo��
    void CallCam();

    //�J�����̎��_�}�E�X�ɂ���
    void ViewRotate();

    XMVECTOR ScratchWall(XMVECTOR normal, XMVECTOR pos);


};