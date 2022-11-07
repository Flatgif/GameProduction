#pragma once
#include "Engine/GameObject.h"

//���������Ǘ�����N���X
class Map : public GameObject
{
    int hModel_[2];
    int width;
    struct
    {
        int data;
        int type;
    }map_[31][31];
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
    void Make();
};