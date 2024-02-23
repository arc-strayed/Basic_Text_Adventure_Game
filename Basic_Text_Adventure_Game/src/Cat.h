#pragma once
#include "Item.h"

class Cat : public Item
{
public:
    Cat();
    ~Cat();

    // Shows the description of the item
    void ShowDescription() const override;
    // Pet the cat
    void Use() override;
private:
    bool purring = false;
};