#pragma once
#include "Engine/GameObject.h"

//���������Ǘ�����N���X
class Map : public GameObject
{
    int hModel_[3];
    int width_;
    int wallHeight_;
    int roomGP_;

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
    bool IsWall(int x, int z);
    bool IsFloor(int x, int z);
};