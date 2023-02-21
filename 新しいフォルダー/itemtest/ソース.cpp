#include <string>
#include <iostream>
class Item
{
    //�A�C�e���̎��(�񋓑�)
    typedef enum
    {
        MATERIAL = 0,   //�f��
        TOOL = 1,       //����
        WEAPON = 2,     //����
    }ItemType;

    typedef struct
    {
        //�A�C�e�����ʗpid
        int  id_;
        //�A�C�e���̖��O
        std::string itemName_;
        //�A�C�e���̎��
        ItemType itemType_;
        //�A�C�e���̌�
        int itemCount_;

    }ItemInfo;

    ItemInfo item_;
public:
    Item() {}
    ~Item(){}

    //id���擾
    int GetId() { return item_.id_; }
    //�A�C�e�������擾
    std::string GetItemName() { return item_.itemName_; }
    //�A�C�e���̎�ނ��擾
    ItemType GetItemType() { return item_.itemType_; }

    //�������J�E���g�A�b�v
    void CountUp(int value=1)
    {
        item_.itemCount_ += value;
    }

    //�������J�E���g�_�E��
    void CountDown(int value = 1)
    {
        item_.itemCount_ -= value;
    }

    void SetId(int value)
    {
        item_.id_ = value;
    }
};

int main() {
    Item* item = new Item();
    item->SetId(1);
    std::cout << item->GetId();
    return 0;
}