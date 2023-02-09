#pragma once
#include "Engine/GameObject.h"

//���������Ǘ�����N���X
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
    //�R���X�g���N�^
    Map(GameObject* parent);

    //�f�X�g���N�^
    ~Map();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
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
    //���f���ԍ��擾
    int GetModelHandle(int modelNum) { return hModel_[modelNum]; }

};