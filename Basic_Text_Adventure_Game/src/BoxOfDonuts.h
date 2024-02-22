#pragma once
#include "Item.h"

class BoxOfDonuts : public Item
{
public:
    BoxOfDonuts();
    ~BoxOfDonuts();

    // Shows the description of the item
    virtual void ShowDescription();
    // Eat one donut from the box
    virtual void Use();
private:
    int count = 0;
};

