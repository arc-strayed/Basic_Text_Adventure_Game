#pragma once
#include "Item.h"

class Cat : public Item
{
public:
    Cat();
    ~Cat();

    // Shows the description of the item
    virtual void ShowDescription();
    // Pet the cat
    virtual void Use();
private:
    bool purring = false;
};