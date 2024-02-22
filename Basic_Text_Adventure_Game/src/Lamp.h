#pragma once
#include "Item.h"

class Lamp : public Item
{
public:
    Lamp();
    ~Lamp();

    // Shows the description of the item
    virtual void ShowDescription() const;
    // Turns the lamp on or off
    virtual void Use();
private:
    bool turned_on = false;
};