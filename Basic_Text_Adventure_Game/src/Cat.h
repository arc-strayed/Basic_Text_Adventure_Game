#pragma once
#include "Item.h"

class Cat : public Item
{
public:
    Cat();
    ~Cat();
    
    void ShowDescription() const override; // Shows the description of the item
    void Use() override; // Pet the cat

private:
    bool purring = false;

};