#pragma once
#include "Item.h"

class BoxOfDonuts : public Item
{
public:
    BoxOfDonuts();
    ~BoxOfDonuts();

    
    void ShowDescription() const override; // Shows the description of the item
    void Use() override; // Eat one donut from the box

private:
    int count = 5;

};

