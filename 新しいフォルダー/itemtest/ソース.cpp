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
    }ItemType;

    typedef struct
    {
        //アイテム識別用id
        int  id_;
        //アイテムの名前
        std::string itemName_;
        //アイテムの種類
        ItemType itemType_;
        //アイテムの個数
        int itemCount_;

    }ItemInfo;

    ItemInfo item_;
public:
    Item() {}
    ~Item(){}

    //idを取得
    int GetId() { return item_.id_; }
    //アイテム名を取得
    std::string GetItemName() { return item_.itemName_; }
    //アイテムの種類を取得
    ItemType GetItemType() { return item_.itemType_; }

    //所持数カウントアップ
    void CountUp(int value=1)
    {
        item_.itemCount_ += value;
    }

    //所持数カウントダウン
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