#pragma once

#include "Item.h"

class ExplosiveBarrel : public Item
{
public:
    ExplosiveBarrel();
    ExplosiveBarrel(bool* game_running);
    ~ExplosiveBarrel();

    void ShowDescription() const override; // Show description of item
    void Use() override; // Causes the barrel to explode
private:
    bool* is_game_running;
};