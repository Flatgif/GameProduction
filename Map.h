#pragma once
#include "Engine/GameObject.h"

//���������Ǘ�����N���X
class Map : public GameObject
{
    int hModel_[2];
    struct
    {
        int type;
        int height;
    }map_[15][15];
public:
    Map();
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

    void Create();
};