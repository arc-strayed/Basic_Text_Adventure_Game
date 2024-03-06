#pragma once

#include "Item.h"

class Compass : public Item
{
public:
    Compass();
    Compass(bool* compass);
    ~Compass();

    void ShowDescription() const override; // Show description of item
    void Use() override; // Pick up compass

private:
    bool picked_up;
    bool* has_compass;
};