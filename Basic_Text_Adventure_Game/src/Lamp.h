#pragma once
#include "Item.h"

class Lamp : public Item
{
public:
    Lamp();
    ~Lamp();
    
    void ShowDescription() const override; // Shows the description of the item
    void Use() override; // Turns the lamp on or off

private:
    bool turned_on = false;

};