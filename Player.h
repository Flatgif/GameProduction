#pragma once
#include "Engine/GameObject.h"

//���������Ǘ�����N���X
class Player : public GameObject
{
    int hModel_;    //���f���ԍ�
    int dig_;
    float move_;
    float rota_;
    bool rotaFlag_;
    bool rotating_;
    bool dir_;

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
};