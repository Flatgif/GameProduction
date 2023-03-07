#include <string>
#include <iostream>
class Item
{
    //アイテムの種類(列挙体)
    typedef enum
    {
        MATERIAL = 0,   //素材
        TOOL = 1,       //道具
        WEAPON = 2,     //武器
        MAX,
    }ItemType;
private:
    //アイテムの種類
    ItemType itemType_;

    typedef struct
    {
        //アイテム識別用id
        int  id_;
        //アイテムの名前
        std::string itemName_;
        //アイテムの個数
        int itemCount_;

    }ItemInfo;

    ItemInfo item_[MAX];
public:
    Item() {}
    ~Item(){}

    //idを取得
    int GetId() { return item_[itemType_].id_; }
    //アイテム名を取得
    std::string GetItemName() { return item_[itemType_].itemName_; }

    //所持数カウントアップ
    void CountUp(int value=1)
    {
        item_[itemType_].itemCount_ += value;
    }

    //所持数カウントダウン
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