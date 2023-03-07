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
        MAX,
    }ItemType;
private:
    //�A�C�e���̎��
    ItemType itemType_;

    typedef struct
    {
        //�A�C�e�����ʗpid
        int  id_;
        //�A�C�e���̖��O
        std::string itemName_;
        //�A�C�e���̌�
        int itemCount_;

    }ItemInfo;

    ItemInfo item_[MAX];
public:
    Item() {}
    ~Item(){}

    //id���擾
    int GetId() { return item_[itemType_].id_; }
    //�A�C�e�������擾
    std::string GetItemName() { return item_[itemType_].itemName_; }

    //�������J�E���g�A�b�v
    void CountUp(int value=1)
    {
        item_[itemType_].itemCount_ += value;
    }

    //�������J�E���g�_�E��
    void CountDown(int value = 1)
    {
        item_[itemType_].itemCount_ -= value;
    }

    void SetId(int value)
    {
        item_[itemType_].id_ = value;
    }
    void SetItemType_(int value)
    {
        itemType_ = static_cast<ItemType>(value);
    }
};

int main() {
    Item* item = new Item();
    item->SetItemType_(1);
    item->SetId(1);
    item->SetItemType_(0);
    std::cout << item->GetId();
    return 0;
}