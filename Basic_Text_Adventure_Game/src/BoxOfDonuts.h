#pragma once
#include "Item.h"

class BoxOfDonuts : public Item
{
public:
    BoxOfDonuts();
    ~BoxOfDonuts();

    // Shows the description of the item
    void ShowDescription() const override;
    // Eat one donut from the box
    void Use() override;
private:
    int count = 5;
};

