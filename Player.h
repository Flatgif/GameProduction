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
    Map* pMap;
    XMFLOAT3 prevPosition_;
    XMFLOAT3 nowPosition_;
    
    

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