#pragma once
#include "Engine/GameObject.h"

//���������Ǘ�����N���X
class Map : public GameObject
{
    int hModel_[2];
    int map_[15][15]; //�񎟌��z��

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
};