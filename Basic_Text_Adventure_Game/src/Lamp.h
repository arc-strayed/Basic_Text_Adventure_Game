#pragma once
#include "Item.h"

class Lamp : public Item
{
public:
    Lamp();
    ~Lamp();

    // Shows the description of the item
    void ShowDescription() const override;
    // Turns the lamp on or off
    void Use() override;
private:
    bool turned_on = false;
};